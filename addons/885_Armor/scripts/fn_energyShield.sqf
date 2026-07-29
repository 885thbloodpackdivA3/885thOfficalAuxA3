/*
    Author: 885th Bloodpack Division Client-Side Katarn Shield Engine
*/
if (!hasInterface) exitWith {};

waitUntil { !isNull (findDisplay 46) };
waitUntil { !isNull player }; // player can still be objNull for a moment after the display exists

// FIX: ACE Medical's own docs explicitly warn that adding a HandleDamage
// handler "is virtually guaranteed to break ACE's handling" - which is
// exactly what was happening here (menu/HUD/sounds all worked, but the
// shield never actually stopped any damage, because ACE's own damage
// engine was processing hits independently of whatever we returned).
// KAT Advanced Medical runs ON TOP of ACE's same engine rather than
// replacing it, so detecting ACE alone covers both. When neither is
// loaded, we fall back to the original HandleDamage approach, which is
// the correct mechanism when nothing else owns damage processing.
BPD_shield_medicalMode = if (isClass (configFile >> "CfgPatches" >> "ace_medical")) then { "ace" } else { "vanilla" };
private _compatLoaded = isClass (configFile >> "CfgPatches" >> "885_Armor_ACE_Compat");
systemChat format ["[885th Shield] Medical mode: %1 | ACE Compat PBO loaded: %2", BPD_shield_medicalMode, _compatLoaded];
if (BPD_shield_medicalMode == "ace" && {!_compatLoaded}) then {
    systemChat "[885th Shield] WARNING: ACE detected but 885_Armor_ACE_Compat is NOT loaded - shield will not intercept any damage until that PBO is built and added to your mod line.";
};

// --- CORE MENU ATTACHMENT FUNCTION ---
// FIX: there is no "actionIDs" command in Arma - the original loop tried to
// enumerate every addAction ID on the unit, which doesn't compile (that's
// the "Missing ;" error at line 10 that was killing this entire script
// before it ever reached the damage handler or HUD). There's no vanilla way
// to list a unit's existing action IDs, so instead we just remember the IDs
// WE added last time and remove exactly those.
BPD_fnc_injectShieldMenus = {
    private _oldIDs = player getVariable ["AUX_Shield_ActionIDs", []];
    { player removeAction _x; } forEach _oldIDs;

    private _activateId = player addAction [
        "<t color='#00FFFF'>[885th] Activate Energy Shields</t>",
        {
            player setVariable ["AUX_Shield_Active", true];
            playSound "AUX_Shield_Boot";
            hint "Katarn Armor Systems: SHIELDS UP.";
        },
        [], 1.5, false, true, "",
        "!(player getVariable ['AUX_Shield_Active', false]) && {headgear player == '885th_Kusak_Katarn_Helmet'} && {uniform player == '885th_Kusak_Katarn_Uniform'}"
    ];

    private _deactivateId = player addAction [
        "<t color='#FF0000'>[885th] Disable Energy Shields</t>",
        {
            player setVariable ["AUX_Shield_Active", false];
            playSound "AUX_Shield_Shutdown";
            hint "Katarn Armor Systems: SHIELDS DISENGAGED.";
        },
        [], 1.5, false, true, "",
        "player getVariable ['AUX_Shield_Active', false]"
    ];

    player setVariable ["AUX_Shield_ActionIDs", [_activateId, _deactivateId]];
};

["ace_arsenal_displayClosed", {
    [] spawn {
        uiSleep 0.2;
        if (alive player) then { [] call BPD_fnc_injectShieldMenus; };
    };
}] call CBA_fnc_addEventHandler;

[] call BPD_fnc_injectShieldMenus;

// --- DAMAGE INTERCEPTOR REGISTER ---
// FIX: only remove OUR OWN previous handler, never nuke every HandleDamage
// handler on the unit - the old "removeAllEventHandlers" call was also
// stripping ACE's medical damage handling every time this script ran.
BPD_fnc_shieldAttachDamageEH = {
    params ["_unit"];

    private _oldId = _unit getVariable ["AUX_Shield_EHId", -1];
    if (_oldId != -1) then { _unit removeEventHandler ["HandleDamage", _oldId]; };

    private _id = _unit addEventHandler ["HandleDamage", {
        params ["_unit", "_selection", "_damage", "_source", "_projectile", "_hitIndex", "_instigator", "_hitPoint"];

        private _active = _unit getVariable ["AUX_Shield_Active", false];
        private _currentShield = _unit getVariable ["AUX_Shield_Current", 0];

        if (!_active || {_currentShield <= 0}) exitWith { _damage };

        // FIX: pull the OLD damage for the same selection we're comparing
        // against. Previously this always read whole-body `damage _unit`
        // even for limb/head hitpoints, which threw off the delta on
        // anything but a torso hit. "" (whole-body/explosive) hits are now
        // handled too instead of silently skipped.
        private _oldDamage = if (_selection == "") then {
            damage _unit
        } else {
            _unit getHitPointDamage _selection
        };

        private _damageDealt = _damage - _oldDamage;
        if (_damageDealt <= 0) exitWith { _damage }; // healing / no real increase

        _unit setVariable ["AUX_Shield_LastHit", diag_tickTime];

        private _scale = missionNamespace getVariable ["AUX_885th_Shield_DamageScale", 120];
        private _shieldDamage = _damageDealt * _scale;

        [_unit] call BPD_fnc_shieldHitFX;

        if (_currentShield >= _shieldDamage) then {
            _unit setVariable ["AUX_Shield_Current", (_currentShield - _shieldDamage)];
            playSound "AUX_Shield_Hit";
            _damage = _oldDamage; // fully absorbed, nothing gets through
        } else {
            // shield can't fully cover this hit - it still absorbs everything
            // it has, breaks doing it, and only a small mitigated fraction of
            // the EXCESS (not the whole leftover) punches through as light damage
            _unit setVariable ["AUX_Shield_Current", 0];
            _unit setVariable ["AUX_Shield_Broken", true];
            private _breakPenalty = missionNamespace getVariable ["AUX_885th_Shield_BreakPenalty", 5];
            _unit setVariable ["AUX_Shield_LastHit", diag_tickTime + _breakPenalty];
            playSound "reed";

            private _leftoverShieldDamage = _shieldDamage - _currentShield;
            private _leftoverRawDamage = _leftoverShieldDamage / _scale;
            private _mitigation = missionNamespace getVariable ["AUX_885th_Shield_OverflowMitigation", 0.2];
            _damage = _oldDamage + (_leftoverRawDamage * _mitigation);
        };

        _damage
    }];

    _unit setVariable ["AUX_Shield_EHId", _id];
};

// --- CONTINUOUS RUNTIME ENGINE ---
// FIX: was a `while {alive player} do {...uiSleep 0.25}` loop that only
// ever ran once from XEH_postInit - after the first death/respawn it never
// came back. Rebuilt as a CBA per-frame poll (same fix pattern used for the
// CloneHUD PlayerChanged issue) so it re-attaches on every respawn/JIP and
// tears the HUD down cleanly when there's no valid unit to drive it.
// FIX: guard against Eden "restart preview" sometimes not fully clearing
// scripting state between quick restarts within the same editor session -
// without this, a stale handler from the previous preview run can keep
// executing alongside the new one, which is what was causing the shield
// HUD to stay stuck on screen after a restart even with no Katarn gear on.
if (!isNil "BPD_shieldEngine_pfhId") then {
    [BPD_shieldEngine_pfhId] call CBA_fnc_removePerFrameHandler;
};

BPD_shieldEngine_currentUnit = objNull;

BPD_shieldEngine_pfhId = [{
    private _unit = player;

    if (_unit != BPD_shieldEngine_currentUnit) then {
        BPD_shieldEngine_currentUnit = _unit;
        if (!isNull _unit && {alive _unit}) then {
            if (isNil { _unit getVariable "AUX_Shield_Current" }) then {
                private _maxShieldSetting = missionNamespace getVariable ["AUX_885th_Shield_Max", 150];
                _unit setVariable ["AUX_Shield_Current", _maxShieldSetting];
                _unit setVariable ["AUX_Shield_Active", false];
                _unit setVariable ["AUX_Shield_LastHit", 0];
                _unit setVariable ["AUX_Shield_Broken", false];
            };
            if (BPD_shield_medicalMode == "vanilla") then {
                [_unit] call BPD_fnc_shieldAttachDamageEH;
            };
            [] call BPD_fnc_shieldHUD_build;
            [] call BPD_fnc_injectShieldMenus;
        } else {
            [] call BPD_fnc_shieldHUD_destroy;
        };
    };

    if (isNull _unit || {!alive _unit}) exitWith {};

    private _active = _unit getVariable ["AUX_Shield_Active", false];
    if (!_active) exitWith { [0, 1, false, false] call BPD_fnc_shieldHUD_update; };

    private _hasHelmet = (headgear _unit == "885th_Kusak_Katarn_Helmet");
    private _hasArmor  = (uniform _unit == "885th_Kusak_Katarn_Uniform");

    if (!_hasHelmet || !_hasArmor) exitWith {
        _unit setVariable ["AUX_Shield_Active", false];
        playSound "AUX_Shield_Shutdown";
        hintSilent "Shield Offline: Katarn hardware signature dropped.";
        [0, 1, false, false] call BPD_fnc_shieldHUD_update;
    };

    private _maxShieldLoop = missionNamespace getVariable ["AUX_885th_Shield_Max", 150];
    private _chargeRate    = missionNamespace getVariable ["AUX_885th_Shield_RegenRate", 8];
    private _regenDelay    = missionNamespace getVariable ["AUX_885th_Shield_RegenDelay", 4];

    private _currentShield = _unit getVariable ["AUX_Shield_Current", 0];
    private _lastHitTime = _unit getVariable ["AUX_Shield_LastHit", 0];
    private _broken = _unit getVariable ["AUX_Shield_Broken", false];

    // regen tick runs at the poll rate (~20Hz); scale the per-second rate down accordingly
    private _canRegen = (_currentShield < _maxShieldLoop) && {diag_tickTime - _lastHitTime > _regenDelay};
    private _wasRegenerating = _unit getVariable ["AUX_Shield_Regenerating", false];

    if (_canRegen && !_wasRegenerating) then {
        playSound "AUX_Shield_Recharge"; // fires once at the start of a recharge, not every tick
    };
    _unit setVariable ["AUX_Shield_Regenerating", _canRegen];

    if (_canRegen) then {
        _currentShield = (_currentShield + (_chargeRate * 0.05)) min _maxShieldLoop;
        _unit setVariable ["AUX_Shield_Current", _currentShield];
        if (_currentShield >= _maxShieldLoop * 0.05) then {
            _unit setVariable ["AUX_Shield_Broken", false];
            _broken = false;
        };
    };

    [_currentShield, _maxShieldLoop, true, _broken] call BPD_fnc_shieldHUD_update;
}, 0.05, []] call CBA_fnc_addPerFrameHandler;