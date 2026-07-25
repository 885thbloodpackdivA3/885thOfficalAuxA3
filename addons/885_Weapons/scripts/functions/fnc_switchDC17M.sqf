/*
    Function: BPD_fnc_switchDC17M
    Description: Reconfigures the DC17M held by _unit into _targetConfig,
    playing a hand gesture and a servo-click sound in sync with the swap.
    Works in singleplayer, hosted, and dedicated server environments.
*/

params ["_unit", "_targetConfig"];

// Enforce execution space isolation directly to the owning machine
if (!hasInterface || {!local _unit}) exitWith { false };

private _configs = [
    "885th_DC17M_F",
    "885th_DC17M_Sniper_F",
    "885th_DC17M_Launcher_F"
];

private _primaryMag = [
    "885th_60Rnd_mag_DC17M",
    "885th_5Rnd_mag_DC17M_Sniper",
    "885th_AAD_DC17M"
];

if (_unit getVariable ["BPD_DC17M_switching", false]) exitWith {
    systemChat "Already reconfiguring the DC17M.";
    false
};

private _currentWeapon = primaryWeapon _unit;
private _currentIndex = _configs find _currentWeapon;
private _targetIndex = _configs find _targetConfig;

if (_currentIndex == -1 || {_targetIndex == -1} || {_currentIndex == _targetIndex}) exitWith {
    systemChat "DC17M reconfigure: invalid current or target config.";
    false
};

// Immediate lock to hide actions while mid-transition
_unit setVariable ["BPD_DC17M_switching", true];

private _attachments = primaryWeaponItems _unit;
private _newMagClass = _primaryMag select _targetIndex;

// Identify chambered mag instance data now, while still holding the old weapon
private _magData = (magazinesAmmoFull _unit) select {(_x select 2) && (_x select 4 == _currentWeapon)};
private _magClass = "";
private _ammoCount = 0;
if !(_magData isEqualTo []) then {
    _magClass = (_magData select 0) select 0;
    _ammoCount = (_magData select 0) select 1;
};

private _gestureClass = if (_targetConfig == "885th_DC17M_Launcher_F") then {
    "BPD_GestureReconfigure_DC17M_AT"
} else {
    "BPD_GestureReconfigure_DC17M"
};

// playActionNow is the correct command for this - playGesture exists in
// name only and has been documented "Not implemented" by Bohemia since
// 2010; it silently does nothing.
[_unit, _gestureClass] remoteExec ["playActionNow", 0];

[_unit, _currentWeapon, _targetConfig, _newMagClass, _attachments, _magClass, _ammoCount] spawn {
    params ["_unit", "_currentWeapon", "_targetConfig", "_newMagClass", "_attachments", "_magClass", "_ammoCount"];

    // MUST match the gesture's duration (speed = -2 in CfgGesturesMale) -
    // single delay only, matching the animation exactly
    sleep 2;

    if (!alive _unit || {!local _unit} || {primaryWeapon _unit != _currentWeapon}) exitWith {
        _unit setVariable ["BPD_DC17M_switching", false];
    };

    // servo-click sound, timed to land exactly as the mechanical swap begins
    [_unit, "BPD_DC17M_ServoClick"] remoteExec ["say3D", 0];

    // Unload chambered instance and stash it (bypassing capacity checks)
    if (_magClass != "") then {
        _unit removePrimaryWeaponItem _magClass;

        private _container = if (vest _unit != "") then {vestContainer _unit} else {backpackContainer _unit};
        if (!isNull _container) then {
            _container addMagazineAmmoCargo [_magClass, 1, _ammoCount];
        } else {
            private _wh = createVehicle ["GroundWeaponHolder", getPosATL _unit, [], 0, "CAN_COLLIDE"];
            _wh addMagazineAmmoCargo [_magClass, 1, _ammoCount];
        };
    };

    _unit removeWeapon _currentWeapon;

    // Isolate loose spares of the target class so nothing else of that
    // class exists in inventory while we add the weapon and chamber one
    private _sameClassRestoreList = [];
    {
        if ((_x select 0) == _newMagClass && !(_x select 2)) then {
            _sameClassRestoreList pushBack [(_x select 0), (_x select 1)];
        };
    } forEach (magazinesAmmoFull _unit);

    { _unit removeMagazine (_x select 0) } forEach _sameClassRestoreList;

    _unit addWeapon _targetConfig;

    // Only chamber a magazine if you actually had at least one spare of
    // this class - never conjures free ammo
    if (count _sameClassRestoreList > 0) then {
        _unit addPrimaryWeaponItem _newMagClass;
        _sameClassRestoreList deleteAt (count _sameClassRestoreList - 1);
    } else {
        systemChat "No spare magazines for that configuration - weapon will be unloaded.";
    };

    // Restore whatever spares are left, bypassing capacity checks
    {
        private _container = if (vest _unit != "") then {vestContainer _unit} else {backpackContainer _unit};
        if (!isNull _container) then {
            _container addMagazineAmmoCargo [(_x select 0), 1, (_x select 1)];
        } else {
            private _wh = createVehicle ["GroundWeaponHolder", getPosATL _unit, [], 0, "CAN_COLLIDE"];
            _wh addMagazineAmmoCargo [(_x select 0), 1, (_x select 1)];
        };
    } forEach _sameClassRestoreList;

    _unit selectWeapon _targetConfig;

    { if (_x != "") then { _unit addPrimaryWeaponItem _x; }; } forEach _attachments;

    systemChat format ["DC17M reconfigured: %1", getText (configFile >> "CfgWeapons" >> _targetConfig >> "displayName")];

    _unit setVariable ["BPD_DC17M_switching", false];
};

true