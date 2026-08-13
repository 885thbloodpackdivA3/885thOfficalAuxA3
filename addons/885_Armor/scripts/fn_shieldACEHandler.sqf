/*
    Author: 885th Bloodpack Division
    BPD_fnc_shieldWoundHandler

    ACE Medical wound handler function - conforms to ACE's documented spec
    (ace_medical_damage_fnc_woundsHandlerBase pattern):

        params: [unit, damagePerBodyPart, typeOfDamage, ammo]
        damagePerBodyPart: [[damageAfterArmor, selectionName, damageBeforeArmor], ...]
        return: _this (unmodified, pass through), a MODIFIED copy of _this
                (reduced damage - passed to the next/base handler, which still
                creates a smaller wound), or [] to block all further wound
                creation for this event entirely.

    This is registered per damage-type in config.cpp under
    ACE_Medical_Injuries >> damageTypes >> <type> >> woundHandlers, and is
    ONLY ever called when ACE Medical's own damage engine is already running
    the show - we never touch HandleDamage ourselves in this mode. This is
    the same underlying pipeline KAT Advanced Medical runs on top of, since
    KAT extends ACE's medical engine rather than replacing it, so this
    covers both without separate KAT-specific code.
*/
params ["_unit", "_damageArray", "_typeOfDamage", "_ammo"];

if !(missionNamespace getVariable ["AUX_885th_Shield_MasterEnabled", true]) exitWith { _this };
if !(missionNamespace getVariable ["AUX_885th_Shield_ACE_Enabled", true]) exitWith { _this };

private _active = _unit getVariable ["AUX_Shield_Active", false];
private _currentShield = _unit getVariable ["AUX_Shield_Current", 0];

// DIAGNOSTIC - gated to the local player only, since this handler fires for
// every unit's damage in the mission (AI included), not just the player.
// Remove this block once we've confirmed the handler is actually being
// reached and what state it sees.
if (_unit == player) then {
    diag_log format ["[885th Shield DEBUG] handler reached | unit=%1 active=%2 currentShield=%3 type=%4", _unit, _active, _currentShield, _typeOfDamage];
};

if (!_active || {_currentShield <= 0}) exitWith { _this };

// sum post-armor damage across every body part this single event touched -
// treated as one absorbable chunk, same as one shield deduction per hit
private _totalRaw = 0;
{ _totalRaw = _totalRaw + (_x select 0); } forEach _damageArray;

if (_unit == player) then {
    diag_log format ["[885th Shield DEBUG] shield is active, past the gate | rawDamageArray=%1 totalRaw=%2", _damageArray, _totalRaw];
};

if (_totalRaw <= 0) exitWith { _this };

private _scale = missionNamespace getVariable ["AUX_885th_Shield_ACE_DamageScale", 120];
private _shieldDamage = _totalRaw * _scale;

_unit setVariable ["AUX_Shield_LastHit", diag_tickTime];
[_unit] call BPD_fnc_shieldHitFX;

if (_currentShield >= _shieldDamage) then {
    _unit setVariable ["AUX_Shield_Current", (_currentShield - _shieldDamage)];
    playSound "AUX_Shield_Hit";
    [_unit, [], _typeOfDamage, _ammo] // fully absorbed - valid shape, but nothing left in the damage list for the base handler to turn into a wound
} else {
    _unit setVariable ["AUX_Shield_Current", 0];
    _unit setVariable ["AUX_Shield_Broken", true];
    private _breakPenalty = missionNamespace getVariable ["AUX_885th_Shield_BreakPenalty", 5];
    _unit setVariable ["AUX_Shield_LastHit", diag_tickTime + _breakPenalty];
    playSound "reed";

    // same "light punch-through" logic as vanilla mode - only a mitigated
    // fraction of the OVERAGE gets through, scaled proportionally across
    // every body part in the array, then handed to the next/base handler
    private _leftoverShieldDamage = _shieldDamage - _currentShield;
    private _mitigation = missionNamespace getVariable ["AUX_885th_Shield_ACE_OverflowMitigation", 0.2];
    private _passThroughFraction = (_leftoverShieldDamage / _shieldDamage) * _mitigation;

    private _scaledArray = _damageArray apply {
        [(_x select 0) * _passThroughFraction, _x select 1, _x select 2]
    };
    [_unit, _scaledArray, _typeOfDamage, _ammo]
};