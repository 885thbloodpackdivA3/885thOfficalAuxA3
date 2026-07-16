/*
    Function: BPD_HUD_fnc_toggleHUD
    Description: Shows/hides the HUD controls without tearing down the PFH.
*/
private _display = uiNamespace getVariable ["BPD_HUD_display", displayNull];
if (isNull _display) exitWith {};

private _visible = !(missionNamespace getVariable ["BPD_HUD_visible", true]);
missionNamespace setVariable ["BPD_HUD_visible", _visible];

private _idcs = [
    9010,9011,9020,9021,
    9030,9031,9032,9033,9034,
    9040,9041,9042,9043,
    9050,9051,
    9060,9061
];

{
    (_display displayCtrl _x) ctrlShow _visible;
} forEach _idcs;
