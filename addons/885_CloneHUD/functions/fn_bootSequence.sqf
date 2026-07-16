/*
    Function: BPD_HUD_fnc_bootSequence
    Description: Plays the helmet boot-up text sequence for a unit.
    Called with: [] spawn BPD_HUD_fnc_bootSequence  (must be spawned, not called - uses sleep)
*/
params [["_unit", player]];

if (!hasInterface) exitWith {};
if (_unit != player) exitWith {}; // only ever run this for the local player

"BPD_CloneHUD_Boot" cutRsc ["BPD_CloneHUD_Boot", "PLAIN"];
private _display = uiNamespace getVariable ["BPD_HUD_bootDisplay", displayNull];
if (isNull _display) exitWith {};
private _ctrl = _display displayCtrl 9001;

private _lines = [
    "INITIALIZING...",
    "",
    "885TH BLOODPACK",
    "REPUBLIC TACTICAL NETWORK",
    "",
    "COMMS... ONLINE",
    "IFF... ONLINE",
    "WEAPONS... ONLINE",
    "",
    "READY"
];

{
    if (isNull _display) exitWith {};
    _ctrl ctrlSetText _x;
    sleep 0.18;
} forEach _lines;

sleep 0.6;
if (!isNull _display) then {
    "BPD_CloneHUD_Boot" cutFadeOut 0.3;
};
