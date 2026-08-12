/*
    885th Bloodpack Division - DC-15 SA Recharge System
    XEH_postInit.sqf
*/

diag_log "[885th DC15SA] postInit OK";

// SERVER PROTECTION GATE: Exit out immediately if running on a dedicated server box or headless shell
if (!hasInterface) exitWith {};

BPD_fnc_startDC15SARecharge = {
    params [["_unit", player, [objNull]]];
    if (isNull _unit || {!local _unit}) exitWith {};

    // Kill any prior handler before adding a new one (avoids stacking on respawn/unit switch)
    private _oldPFH = _unit getVariable ["BPD_DC15SA_PFH", -1];
    if (_oldPFH != -1) then {
        [_oldPFH] call CBA_fnc_removePerFrameHandler;
    };

    _unit setVariable ["BPD_DC15SA_LastRecharge", time, false];

    private _pfh = [
        { [(_this select 0) select 0] call BPD_fnc_dc15saRecharge },
        0.1,
        [_unit]
    ] call CBA_fnc_addPerFrameHandler;

    _unit setVariable ["BPD_DC15SA_PFH", _pfh, false];

    diag_log format ["[885th DC15SA] Recharge PFH started for %1", _unit];
};

// Initial spawn pass
[{
    !isNull player && { local player }
}, {
    [player] call BPD_fnc_startDC15SARecharge;
}] call CBA_fnc_waitUntilAndExecute;

// MP Respawn safety re-injection path
// Uses "EntityRespawned" - NOT "PlayerRespawn", which is not a valid mission
// event handler (see DC17M XEH_postInit.sqf for the same fix already applied there).
addMissionEventHandler ["EntityRespawned", {
    params ["_newEntity", "_oldEntity"];

    [{
        !isNull player && { local player }
    }, {
        [player] call BPD_fnc_startDC15SARecharge;
    }] call CBA_fnc_waitUntilAndExecute;
}];

// Team switching/Zeus control tracking loop
["unit", {
    params ["_unit"];
    if (!isNull _unit && {local _unit}) then {
        [_unit] call BPD_fnc_startDC15SARecharge;
    };
}] call CBA_fnc_addPlayerEventHandler;
