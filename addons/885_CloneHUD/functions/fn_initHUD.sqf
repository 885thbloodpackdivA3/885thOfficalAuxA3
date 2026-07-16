/*
    Function: BPD_HUD_fnc_initHUD
    Description: Displays the persistent HUD and starts its per-frame updater.
                 Safe to call multiple times (e.g. on respawn) - clears the old PFH first.
*/
params [["_unit", player]];

if (!hasInterface) exitWith {};
if (_unit != player) exitWith {};

if (!isNil "BPD_HUD_updatePFH") then {
    [BPD_HUD_updatePFH] call CBA_fnc_removePerFrameHandler;
    BPD_HUD_updatePFH = nil;
};

"BPD_CloneHUD_Main" cutRsc ["BPD_CloneHUD_Main", "PLAIN"];

missionNamespace setVariable ["BPD_HUD_visible", true];

BPD_HUD_updatePFH = [{ call BPD_HUD_fnc_updateHUD; }, 0.2] call CBA_fnc_addPerFrameHandler;

// --- Scroll-wheel action ---
// Remove any previous action first (respawn safety - avoids stacking duplicates)
private _oldAction = _unit getVariable ["BPD_HUD_actionID", -1];
if (_oldAction != -1) then {
    _unit removeAction _oldAction;
};

private _actionID = _unit addAction [
    "<t color='#4DE6FF'>Toggle Clone HUD</t>",
    { call BPD_HUD_fnc_toggleHUD; },
    nil,
    1.5,
    false,
    true,
    "",
    "true",
    5
];
_unit setVariable ["BPD_HUD_actionID", _actionID];
