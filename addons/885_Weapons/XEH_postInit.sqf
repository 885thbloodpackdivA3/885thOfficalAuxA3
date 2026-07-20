// XEH_postInit.sqf
// Adds scroll-wheel actions to the local player for reconfiguring the
// DC17M. Every OTHER config (not just "next in cycle") is shown at once -
// e.g. holding the Rifle shows both "Switch to Sniper Configuration" and
// "Switch to Launcher Configuration" simultaneously - so you can jump
// straight to whichever one you want. All entries hide themselves while
// BPD_fnc_switchDC17M has a swap in progress (see BPD_DC17M_switching).
// Hooks CAManBase's InitPost via CBA so it re-attaches on every spawn,
// respawn, and JIP - addon-safe, does not rely on mission-only hooks.

diag_log "[885th DC17M] postInit OK";

["CAManBase", "InitPost", {
    params ["_unit"];

    if (isPlayer _unit) then {
        diag_log format ["[885th DC17M] InitPost fired for %1 | local: %2", _unit, local _unit];
    };

    if !(local _unit) exitWith {};
    if !(isPlayer _unit) exitWith {};

    // remove any stale actions from a previous InitPost pass on this unit
    private _existingIDs = _unit getVariable ["885th_DC17M_actionIDs", []];
    {
        _unit removeAction _x;
    } forEach _existingIDs;

    private _configs = [
        "885th_DC17M_F",
        "885th_DC17M_Sniper_F",
        "885th_DC17M_Launcher_F"
    ];
    private _displayNames = [
        "Rifle Configuration",
        "Sniper Configuration",
        "Launcher Configuration"
    ];

    private _newActionIDs = [];

    for "_i" from 0 to (count _configs - 1) do {
        private _currentConfig = _configs select _i;

        for "_j" from 0 to (count _configs - 1) do {
            if (_i != _j) then {
                private _targetConfig = _configs select _j;
                private _targetDisplay = _displayNames select _j;

                private _condition = format [
                    "(currentWeapon _target == '%1') && !(_target getVariable ['BPD_DC17M_switching', false])",
                    _currentConfig
                ];

                private _actionID = _unit addAction [
                    format ["Switch to %1", _targetDisplay],
                    {
                        params ["_target", "_caller", "_actionId", "_targetConfig"];
                        [_target, _targetConfig] call BPD_fnc_switchDC17M;
                    },
                    _targetConfig,
                    6,
                    false,
                    true,
                    "",
                    _condition,
                    5
                ];

                _newActionIDs pushBack _actionID;
            };
        };
    };

    _unit setVariable ["885th_DC17M_actionIDs", _newActionIDs];

    diag_log format ["[885th DC17M] Actions added to %1: %2", _unit, _newActionIDs];

    // TEMPORARY DIAGNOSTIC - always visible regardless of weapon, reports
    // the exact currentWeapon classname via systemChat so we can confirm
    // whether it actually matches "885th_DC17M_F" etc. on the server. Not
    // conditioned on anything, safe to remove once we've confirmed this.
    _unit addAction [
        "<t color='#FFAA00'>[DEBUG] Check my weapon classname</t>",
        {
            params ["_target"];
            systemChat format ["currentWeapon: '%1'", currentWeapon _target];
        },
        nil,
        1,
        false,
        true,
        "",
        "true",
        5
    ];
}] call CBA_fnc_addClassEventHandler;
