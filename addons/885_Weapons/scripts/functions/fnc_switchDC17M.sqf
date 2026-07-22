/*
    Function: BPD_fnc_switchDC17M

    Description:
        Reconfigures the DC17M held by _unit into _targetConfig (Rifle,
        Sniper, or Launcher). Plays a hand gesture immediately, then swaps
        the weapon 4.5 seconds later (synced to the gesture length).

        Uses removePrimaryWeaponItem / addPrimaryWeaponItem to unload and
        chamber magazines DIRECTLY on the weapon slot, rather than fighting
        over which magazine addWeapon's auto-chamber picks. Both commands
        are officially documented by Bohemia as working "including
        magazine" on the primaryWeapon specifically - this sidesteps the
        root cause of every earlier bug in one move: all three DC17M
        configs share one magazine well (885th_DC17M_MagWell), which made
        the engine treat every config's magazine class as valid for any of
        them, so addWeapon's auto-chamber (and setUnitLoadout, which has
        its own separately-documented ammo-count bugs) could never be
        trusted to pick the right one when other spare magazines were
        present. Targeting the weapon's chamber slot directly removes the
        ambiguity instead of working around it.

        The old weapon's chambered magazine is identified precisely via
        magazinesAmmoFull (matched on isLoaded=true AND muzzle==old weapon,
        so there's no ambiguity about which physical instance it is), then
        unloaded off the weapon and stashed directly into vest/backpack
        cargo (or dropped in a ground weapon holder if neither exists) -
        bypassing the normal per-item capacity check that addMagazine
        would otherwise apply.

        The new weapon is only loaded if you already have at least one
        spare magazine of that config's class - that spare gets consumed
        (removed from your inventory) to become the chambered magazine.
        No ammo is ever created for free: if you have zero spares of the
        target class, the weapon comes up unloaded and stays that way
        until you resupply some other way.

        If you carry MULTIPLE spares of the target class, all of them are
        temporarily pulled out before the weapon is added and one is
        chambered, then every remaining spare (all but the one consumed)
        is restored by its exact [classname, ammo] pair. This works around
        a documented Arma inventory-stacking quirk where introducing a new
        instance of a magazine class while other loose spares of that same
        class already exist can corrupt the ammo count of some of those
        existing spares. Every OTHER spare magazine (any other config's
        class) is never touched at all.

        While the swap is pending, the unit is locked (BPD_DC17M_switching)
        so the action can't be re-triggered mid-transition - XEH_postInit.sqf
        checks this same variable to hide the action menu entries during
        that window.

    Parameter(s):
        0: OBJECT - the unit holding the weapon (usually player)
        1: STRING - the target config classname to switch to, one of:
           "885th_DC17M_F", "885th_DC17M_Sniper_F", "885th_DC17M_Launcher_F"

    Returns:
        BOOL - true if the swap was accepted and is now pending/playing

    Example:
        [player, "885th_DC17M_Sniper_F"] call BPD_fnc_switchDC17M;
*/

params ["_unit", "_targetConfig"];

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

// lock immediately so the action menu can't be spammed mid-transition
_unit setVariable ["BPD_DC17M_switching", true];

// snapshot attachments now, while still holding the old weapon
private _items = primaryWeaponItems _unit;

private _newMagClass = _primaryMag select _targetIndex;

private _gestureClass = if (_targetConfig == "885th_DC17M_Launcher_F") then {
    "BPD_GestureReconfigure_DC17M_AT"
} else {
    "BPD_GestureReconfigure_DC17M"
};
// remoteExec target 0 = broadcast to all clients (including JIP), so
// nearby players see the gesture too, not just you
[_unit, _gestureClass] remoteExec ["playActionNow", 0];

[_unit, _currentWeapon, _targetConfig, _newMagClass, _items] spawn {
    params ["_unit", "_currentWeapon", "_targetConfig", "_newMagClass", "_items"];

    // MUST match the gesture's duration (speed = -2 in CfgGesturesMale)
    sleep 2;

    if (!alive _unit || {!local _unit} || {primaryWeapon _unit != _currentWeapon}) exitWith {
        // unit died, is no longer local (e.g. disconnected mid-animation),
        // or manually swapped their primary weapon away from the DC17M
        // entirely mid-animation - cancel the pending swap rather than
        // force it. Briefly having a sidearm/binoculars raised does NOT
        // cancel this, since we check primaryWeapon, not currentWeapon.
        _unit setVariable ["BPD_DC17M_switching", false];
    };

    // 1. Capture Mag Data - precisely identify the CHAMBERED magazine via
    // magazinesAmmoFull (isLoaded = true, muzzle/location == old weapon)
    private _magData = (magazinesAmmoFull _unit) select {(_x select 2) && (_x select 4 == _currentWeapon)};
    private _magClass = "";
    private _ammoCount = 0;
    if !(_magData isEqualTo []) then {
        _magClass = (_magData select 0) select 0;
        _ammoCount = (_magData select 0) select 1;
    };

    // 3. The Unload Logic (Bypass Mass Limits) - unload it off the weapon,
    // then stash it directly into vest/backpack cargo (bypassing the
    // normal per-item capacity check that addMagazine would apply), or
    // drop it in a ground weapon holder if neither container exists
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

    // Snapshot every LOOSE spare magazine of the class we're switching
    // into. Pulled out entirely first (not just counted) for the same
    // reason as before: Arma's inventory stacking has a documented quirk
    // where introducing a new instance of a class alongside existing loose
    // spares of that class can corrupt the ammo count of some of them.
    // Pulling them all out first means nothing else of that class exists
    // while we add the weapon and chamber one.
    private _sameClassRestoreList = [];
    {
        if ((_x select 0) == _newMagClass && !(_x select 2)) then {
            _sameClassRestoreList pushBack [(_x select 0), (_x select 1)];
        };
    } forEach (magazinesAmmoFull _unit);

    { _unit removeMagazine (_x select 0) } forEach _sameClassRestoreList;

    _unit addWeapon _targetConfig;

    // Only chamber a magazine if you actually had at least one spare of
    // this class - consuming one from your own stock rather than ever
    // conjuring free ammo. If you had zero spares, the weapon comes up
    // empty and stays that way until you resupply some other way.
    if (count _sameClassRestoreList > 0) then {
        _unit addPrimaryWeaponItem _newMagClass;

        // that's one spare "spent" on chambering - drop the last entry
        // from the restore list so it doesn't get given back below
        _sameClassRestoreList deleteAt (count _sameClassRestoreList - 1);
    } else {
        systemChat "No spare magazines for that configuration - weapon will be unloaded.";
    };

    // restore whatever spares are LEFT (i.e. everything except the one
    // consumed above, if any), bypassing the normal per-item capacity
    // check the same way the old weapon's magazine gets stashed above
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

    {
        if (_x != "") then {
            _unit addPrimaryWeaponItem _x;
        };
    } forEach _items;

    systemChat format ["DC17M reconfigured: %1", getText (configFile >> "CfgWeapons" >> _targetConfig >> "displayName")];

    _unit setVariable ["BPD_DC17M_switching", false];
};

true
