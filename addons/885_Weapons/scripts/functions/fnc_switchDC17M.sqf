/*
    Function: BPD_fnc_switchDC17M

    Description:
        Reconfigures the DC17M held by _unit into _targetConfig (Rifle,
        Sniper, or Launcher). Plays a hand gesture immediately, then swaps
        the weapon 4.5 seconds later (synced to the gesture length).

        Deliberately does NOT use setUnitLoadout - Bohemia's own forums
        document known, longstanding quirks with it around magazine ammo
        counts not behaving as specified. Instead this works directly with
        addWeapon/addMagazine/removeMagazine, and solves the ambiguous
        auto-chamber problem (all three configs share one magazine well,
        885th_DC17M_MagWell, so the engine treats their magazine classes as
        interchangeable) by making the fresh target magazine the ONLY
        DC17M-compatible magazine in your inventory at the exact moment the
        new weapon is added - every other spare magazine (any class, any
        ammo count) is temporarily pulled first, then restored afterward
        by its exact [classname, ammoCount] pair. This guarantees the
        correct magazine is what gets chambered, and that nothing you were
        carrying is lost or duplicated - not even the leftover partial mag
        from the OLD weapon, which gets identified and discarded (not
        restored) since it only appears as loose inventory AFTER the old
        weapon is removed, distinguishing it cleanly from your pre-existing
        spares.

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

private _currentWeapon = currentWeapon _unit;
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

private _oldMagClass = _primaryMag select _currentIndex;

private _gestureClass = if (_targetConfig == "885th_DC17M_Launcher_F") then {
    "BPD_GestureReconfigure_DC17M_AT"
} else {
    "BPD_GestureReconfigure_DC17M"
};
_unit playActionNow _gestureClass;

[_unit, _currentWeapon, _targetConfig, _targetIndex, _primaryMag, _oldMagClass, _items] spawn {
    params ["_unit", "_currentWeapon", "_targetConfig", "_targetIndex", "_primaryMag", "_oldMagClass", "_items"];

    // MUST match the gesture's duration (speed = -2 in CfgGesturesMale)
    sleep 2;

    if (!alive _unit || {currentWeapon _unit != _currentWeapon}) exitWith {
        // unit died, or manually swapped away from the DC17M mid-animation -
        // cancel the pending swap rather than force it
        _unit setVariable ["BPD_DC17M_switching", false];
    };

    private _newMagClass = _primaryMag select _targetIndex;
    private _newMagCapacity = getNumber (configFile >> "CfgMagazines" >> _newMagClass >> "count");

    // every DC17M magazine class EXCEPT the one we're switching to
    private _otherClasses = _primaryMag - [_newMagClass];

    // pull every spare of those other classes out of inventory first,
    // remembering their exact [classname, ammoCount] so we can restore
    // them precisely afterward. This leaves the fresh magazine we're
    // about to add as the ONLY DC17M-compatible magazine in inventory,
    // so addWeapon's auto-chamber has nothing ambiguous left to pick from.
    private _restoreList = [];
    {
        _x params ["_magClass", "_ammoCount"];
        if (_magClass in _otherClasses) then {
            _restoreList pushBack [_magClass, _ammoCount];
        };
    } forEach (magazinesAmmo _unit);

    { _unit removeMagazine (_x select 0) } forEach _restoreList;

    _unit removeWeapon _currentWeapon;

    // the old weapon's chambered magazine just became a new loose spare of
    // _oldMagClass. Since every PRE-EXISTING spare of that class was
    // already stripped above (it's one of the "other classes"), any
    // instance found now is definitely this fresh leftover - safe to
    // discard without ambiguity, and NOT added to _restoreList so it
    // never comes back.
    {
        _x params ["_magClass", "_ammoCount"];
        if (_magClass == _oldMagClass) then {
            _unit removeMagazine _magClass;
        };
    } forEach (magazinesAmmo _unit);

    _unit addMagazine [_newMagClass, _newMagCapacity];
    _unit addWeapon _targetConfig;
    _unit selectWeapon _targetConfig;

    // restore every other-class spare exactly as it was
    { _unit addMagazine _x } forEach _restoreList;

    {
        if (_x != "") then {
            _unit addPrimaryWeaponItem _x;
        };
    } forEach _items;

    systemChat format ["DC17M reconfigured: %1", getText (configFile >> "CfgWeapons" >> _targetConfig >> "displayName")];

    _unit setVariable ["BPD_DC17M_switching", false];
};

true
