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

    // Adding actions the INSTANT InitPost fires can register them in the
    // engine's bookkeeping (valid ID returned, stored fine) without them
    // actually rendering in the scroll wheel. A delay fixes that, but
    // spawn/sleep runs the delayed code in the SCHEDULED environment,
    // which Bohemia/CBA/ACE3 all document as unreliable - subject to the
    // engine's per-frame time budget, which gets more contested the
    // heavier the server's actual load is. That's almost certainly why
    // this worked reliably in singleplayer/editor (light load, scheduler
    // has spare time every frame) but not on a real dedicated server
    // (heavier load, many more scripts competing for the same budget).
    // CBA_fnc_waitAndExecute runs its callback UNSCHEDULED after the
    // delay instead - the same execution category XEHs themselves run in.
    [{
        params ["_unit"];

        diag_log format ["[885th DC17M] waitAndExecute fired for %1", _unit];

        // remove any stale actions from a previous pass on this unit
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
                        "(primaryWeapon _target == '%1') && !(_target getVariable ['BPD_DC17M_switching', false])",
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
    }, [_unit], 1] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addClassEventHandler;
