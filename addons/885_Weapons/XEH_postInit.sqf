// XEH_postInit.sqf
//
// Registers the DC17M reconfigure scroll-wheel actions for the local
// player. This replaces an earlier CAManBase/InitPost class-event-handler
// approach that registered actions successfully (confirmed repeatedly in
// diag_log output) but never reliably rendered them in the actual scroll
// wheel on the dedicated server. This mechanism instead waits directly for
// player validity and re-registers on the specific events that can change
// which unit the player controls, rather than reacting to a general
// per-unit creation event.
//
// Structure:
// - hasInterface guard so this only runs on machines with a UI at all
// - CBA_fnc_waitUntilAndExecute polling for player validity before the
//   first registration
// - a mission-level addMissionEventHandler ["PlayerRespawn", ...] for
//   re-registration after death
// - CBA_fnc_addPlayerEventHandler ["unit", ...] for re-registration when
//   the player takes control of a different unit (Zeus, slot-switching)
// - a single global action-ID array, refreshed in place, rather than a
//   per-unit stored variable

diag_log "[885th DC17M] postInit OK";

if (!hasInterface) exitWith {};

// Tracks added action IDs so we can remove and re-add cleanly
BPD_DC17M_ConversionActionIDs = [];

// Removes all previously added conversion actions
BPD_fnc_removeDC17MConversionActions = {
    params [["_unit", player, [objNull]]];
    {
        _unit removeAction _x;
    } forEach BPD_DC17M_ConversionActionIDs;
    BPD_DC17M_ConversionActionIDs = [];
};

// Re-adds all actions fresh (safe to call multiple times)
BPD_fnc_refreshDC17MConversionActions = {
    params [["_unit", player, [objNull]]];
    if (isNull _unit) exitWith {};

    [_unit] call BPD_fnc_removeDC17MConversionActions;
    BPD_DC17M_ConversionActionIDs =
        [_unit] call BPD_fnc_addDC17MConversionActions;

    diag_log format ["[885th DC17M] Actions refreshed for %1: %2", _unit, BPD_DC17M_ConversionActionIDs];
};

// Wait for player to be valid before first add
[{
    !isNull player && { local player }
}, {
    [player] call BPD_fnc_refreshDC17MConversionActions;
}] call CBA_fnc_waitUntilAndExecute;

// Re-add when player respawns
addMissionEventHandler ["PlayerRespawn", {
    [{
        !isNull player && { local player }
    }, {
        [player] call BPD_fnc_refreshDC17MConversionActions;
    }] call CBA_fnc_waitUntilAndExecute;
}];

// Re-add if player takes control of a different unit
["unit", {
    params ["_unit"];
    [_unit] call BPD_fnc_refreshDC17MConversionActions;
}] call CBA_fnc_addPlayerEventHandler;
