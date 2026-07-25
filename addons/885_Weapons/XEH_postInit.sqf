/*
    885th Bloodpack Division - DC17M Reconfiguration System
    XEH_postInit.sqf - Mod-Side Instance Initialization Pipeline
*/

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
};

// Initial spawn pass
[{
    !isNull player && { local player }
}, {
    [player] call BPD_fnc_refreshDC17MConversionActions;
}] call CBA_fnc_waitUntilAndExecute;

// MP Respawn safety re-injection path
addMissionEventHandler ["PlayerRespawn", {
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