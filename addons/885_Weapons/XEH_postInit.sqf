/*
    885th Bloodpack Division - DC17M Reconfiguration System
    XEH_postInit.sqf
*/

diag_log "[885th DC17M] postInit OK";

// SERVER PROTECTION GATE: Exit out immediately if running on a dedicated server box or headless shell
if (!hasInterface) exitWith {};

BPD_fnc_addDC17MConversionActionsInline = {
    params [["_unit", player, [objNull]]];

    if (isNull _unit || {!local _unit}) exitWith { [] };

    private _ids = [];

    // --- DC17M BASE (Rifle) - Classname: 885th_DC17M_F ---
    _ids pushBack (_unit addAction [
        "Switch to Sniper Configuration",
        {
            params ["", "_caller"];
            [_caller, "885th_DC17M_Sniper_F"] call BPD_fnc_switchDC17M;
        },
        nil, 1.5, false, true, "",
        "(primaryWeapon _this == '885th_DC17M_F') && !(_this getVariable ['BPD_DC17M_switching', false])",
        5
    ]);

    _ids pushBack (_unit addAction [
        "Switch to Launcher Configuration",
        {
            params ["", "_caller"];
            [_caller, "885th_DC17M_Launcher_F"] call BPD_fnc_switchDC17M;
        },
        nil, 1.5, false, true, "",
        "(primaryWeapon _this == '885th_DC17M_F') && !(_this getVariable ['BPD_DC17M_switching', false])",
        5
    ]);

    // --- DC17M SNIPER - Classname: 885th_DC17M_Sniper_F ---
    _ids pushBack (_unit addAction [
        "Switch to Rifle Configuration",
        {
            params ["", "_caller"];
            [_caller, "885th_DC17M_F"] call BPD_fnc_switchDC17M;
        },
        nil, 1.5, false, true, "",
        "(primaryWeapon _this == '885th_DC17M_Sniper_F') && !(_this getVariable ['BPD_DC17M_switching', false])",
        5
    ]);

    _ids pushBack (_unit addAction [
        "Switch to Launcher Configuration",
        {
            params ["", "_caller"];
            [_caller, "885th_DC17M_Launcher_F"] call BPD_fnc_switchDC17M;
        },
        nil, 1.5, false, true, "",
        "(primaryWeapon _this == '885th_DC17M_Sniper_F') && !(_this getVariable ['BPD_DC17M_switching', false])",
        5
    ]);

    // --- DC17M LAUNCHER - Classname: 885th_DC17M_Launcher_F ---
    _ids pushBack (_unit addAction [
        "Switch to Rifle Configuration",
        {
            params ["", "_caller"];
            [_caller, "885th_DC17M_F"] call BPD_fnc_switchDC17M;
        },
        nil, 1.5, false, true, "",
        "(primaryWeapon _this == '885th_DC17M_Launcher_F') && !(_this getVariable ['BPD_DC17M_switching', false])",
        5
    ]);

    _ids pushBack (_unit addAction [
        "Switch to Sniper Configuration",
        {
            params ["", "_caller"];
            [_caller, "885th_DC17M_Sniper_F"] call BPD_fnc_switchDC17M;
        },
        nil, 1.5, false, true, "",
        "(primaryWeapon _this == '885th_DC17M_Launcher_F') && !(_this getVariable ['BPD_DC17M_switching', false])",
        5
    ]);

    diag_log format ["[885th DC17M] addDC17MConversionActionsInline built %1 actions for %2", count _ids, _unit];

    _ids
};

BPD_fnc_removeDC17MConversionActions = {
    params [["_unit", player, [objNull]]];
    if (isNull _unit) exitWith {};

    private _localIDs = _unit getVariable ["BPD_DC17M_ActiveActionIDs", []];
    {
        _unit removeAction _x;
    } forEach _localIDs;

    _unit setVariable ["BPD_DC17M_ActiveActionIDs", [], false];
};

BPD_fnc_refreshDC17MConversionActions = {
    params [["_unit", player, [objNull]]];
    if (isNull _unit || {!local _unit}) exitWith {};

    [_unit] call BPD_fnc_removeDC17MConversionActions;

    private _compiledIDs = [_unit] call BPD_fnc_addDC17MConversionActionsInline;
    _unit setVariable ["BPD_DC17M_ActiveActionIDs", _compiledIDs, false];

    diag_log format ["[885th DC17M] Actions refreshed for %1: %2", _unit, _compiledIDs];
};

// Initial spawn pass
[{
    !isNull player && { local player }
}, {
    [player] call BPD_fnc_refreshDC17MConversionActions;
}] call CBA_fnc_waitUntilAndExecute;

// MP Respawn safety re-injection path
// NOTE: the mission event handler for a player respawning is
// "EntityRespawned" - NOT "PlayerRespawn", which is not a valid mission
// event handler at all and was throwing "Unknown enum value: PlayerRespawn"
// on every single load, silently, since this used to strip diag_log
// output. That error halts remaining script execution at that point,
// which was very likely preventing the "unit"-change handler below from
// ever being registered at all.
addMissionEventHandler ["EntityRespawned", {
    params ["_newEntity", "_oldEntity"];

    [{
        !isNull player && { local player }
    }, {
        [player] call BPD_fnc_refreshDC17MConversionActions;
    }] call CBA_fnc_waitUntilAndExecute;
}];

// Team switching/Zeus control tracking loop
["unit", {
    params ["_unit"];
    if (!isNull _unit && {local _unit}) then {
        [_unit] call BPD_fnc_refreshDC17MConversionActions;
    };
}] call CBA_fnc_addPlayerEventHandler;