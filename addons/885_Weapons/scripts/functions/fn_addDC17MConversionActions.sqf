/*
    Function: BPD_fnc_addDC17MConversionActions

    Description:
        Adds DC17M weapon conversion scroll wheel actions to a unit.
        Returns all action IDs so they can be cleanly removed later.

        Condition strings use _this rather than _target - both are
        documented as available in addAction's condition context, but
        _this refers to the caller directly and has proven more reliable
        for this addon's dedicated-server behavior.

    Parameters:
        _unit - The unit to add actions to [Object, default: player]

    Returns:
        Array of action IDs [Array]

    Examples:
        [player] call BPD_fnc_addDC17MConversionActions;
        private _ids = [player] call BPD_fnc_addDC17MConversionActions;
*/

params [["_unit", player, [objNull]]];

if (isNull _unit) exitWith {
    diag_log "[885th DC17M] fn_addDC17MConversionActions: Null unit passed, exiting.";
    []
};

private _ids = [];

// =============================================================================
// DC17M BASE (Rifle)
// Classname: 885th_DC17M_F
// Can convert to: Sniper, Launcher
// =============================================================================

_ids pushBack (_unit addAction [
    "Switch to Sniper Configuration",
    {
        params ["_unit"];
        [_unit, "885th_DC17M_Sniper_F"] call BPD_fnc_switchDC17M;
    },
    nil, 1.5, false, true, "",
    "primaryWeapon _this == '885th_DC17M_F'",
    5
]);

_ids pushBack (_unit addAction [
    "Switch to Launcher Configuration",
    {
        params ["_unit"];
        [_unit, "885th_DC17M_Launcher_F"] call BPD_fnc_switchDC17M;
    },
    nil, 1.5, false, true, "",
    "primaryWeapon _this == '885th_DC17M_F'",
    5
]);

// =============================================================================
// DC17M SNIPER
// Classname: 885th_DC17M_Sniper_F
// Can convert to: Rifle (Base), Launcher
// =============================================================================

_ids pushBack (_unit addAction [
    "Switch to Rifle Configuration",
    {
        params ["_unit"];
        [_unit, "885th_DC17M_F"] call BPD_fnc_switchDC17M;
    },
    nil, 1.5, false, true, "",
    "primaryWeapon _this == '885th_DC17M_Sniper_F'",
    5
]);

_ids pushBack (_unit addAction [
    "Switch to Launcher Configuration",
    {
        params ["_unit"];
        [_unit, "885th_DC17M_Launcher_F"] call BPD_fnc_switchDC17M;
    },
    nil, 1.5, false, true, "",
    "primaryWeapon _this == '885th_DC17M_Sniper_F'",
    5
]);

// =============================================================================
// DC17M LAUNCHER
// Classname: 885th_DC17M_Launcher_F
// Can convert to: Rifle (Base), Sniper
// =============================================================================

_ids pushBack (_unit addAction [
    "Switch to Rifle Configuration",
    {
        params ["_unit"];
        [_unit, "885th_DC17M_F"] call BPD_fnc_switchDC17M;
    },
    nil, 1.5, false, true, "",
    "primaryWeapon _this == '885th_DC17M_Launcher_F'",
    5
]);

_ids pushBack (_unit addAction [
    "Switch to Sniper Configuration",
    {
        params ["_unit"];
        [_unit, "885th_DC17M_Sniper_F"] call BPD_fnc_switchDC17M;
    },
    nil, 1.5, false, true, "",
    "primaryWeapon _this == '885th_DC17M_Launcher_F'",
    5
]);

// =============================================================================

_ids // Return all action IDs to caller
