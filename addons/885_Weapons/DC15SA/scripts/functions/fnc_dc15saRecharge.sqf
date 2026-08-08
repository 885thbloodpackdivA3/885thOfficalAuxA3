/*
    Function: BPD_fnc_dc15saRecharge
    Description:
        Per-frame handler body. Recharges the DC-15 SA power cell at a fixed
        rate (rounds/second) up to its max capacity, as long as the weapon
        is currently equipped. Recharge continues ticking on real elapsed
        time regardless of firing, matching a "wait one round's worth of
        recharge" cooldown when depleted.

        Plays a "cell fully charged" sound once, on the transition into a
        full magazine — not every frame while it sits full — and resets so
        it can fire again the next time the cell tops off.

    Params:
        0: OBJECT - unit (player or AI)

    Called from: BPD_fnc_startDC15SARecharge (CBA per-frame handler), via XEH_postInit.sqf

    Author: 885th BPD
*/

params ["_unit"];

if (isNull _unit || {!alive _unit}) exitWith {};

// --- CONFIG: matches CfgWeapons/CfgMagazines in config_dc15sa_recharge_snippet.hpp ---
private _weaponClass  = "885th_DC15SA_F";
private _magClass     = "885th_dc15sa_pistol_mag_blue";
private _maxAmmo      = 7;      // consecutive shots on full charge
private _rechargeRate = 1;      // seconds per round recharged
private _fullSoundClass = "BPD_DC15SA_ChargeFull"; // CfgSounds classname, see config_dc15sa_recharge_snippet.hpp
// ---------------------------------------------------------------------

if (currentWeapon _unit != _weaponClass) exitWith {};

private _currentAmmo = 0;
{
    if ((_x select 0) == _magClass) exitWith { _currentAmmo = _x select 1; };
} forEach magazinesAmmoFull _unit;

private _lastRecharge = _unit getVariable ["BPD_DC15SA_LastRecharge", time];
private _wasFull      = _unit getVariable ["BPD_DC15SA_WasFull", false];

// Already full — keep the clock from building up unused credit.
// Only fire the "full" sound once, on the transition into this state.
if (_currentAmmo >= _maxAmmo) exitWith {
    _unit setVariable ["BPD_DC15SA_LastRecharge", time, false];

    if (!_wasFull) then {
        _unit setVariable ["BPD_DC15SA_WasFull", true, false];
        _unit say3D _fullSoundClass;
    };
};

// Dropped below max — clear the flag so the next time it tops off, it plays again
if (_wasFull) then {
    _unit setVariable ["BPD_DC15SA_WasFull", false, false];
};

if ((time - _lastRecharge) >= _rechargeRate) then {
    _unit setAmmo [_weaponClass, (_currentAmmo + 1)];
    _unit setVariable ["BPD_DC15SA_LastRecharge", time, false];
};
