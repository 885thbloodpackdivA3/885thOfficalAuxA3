/*
    Function: BPD_HUD_fnc_destroyRadar
    Description: Cleans up dynamically created radar/panel controls (respawn safety,
                 and used when the master HUD toggle is switched off).
*/
if (!hasInterface) exitWith {};
disableSerialization;

private _frameControls = missionNamespace getVariable ["BPD_HUD_radarFrameControls", []];
private _contactControls = missionNamespace getVariable ["BPD_HUD_radarContactControls", []];
private _panelControls = missionNamespace getVariable ["BPD_HUD_radarPanelControls", []];

{ if (!isNull _x) then { ctrlDelete _x; }; } forEach _frameControls;
{
    { if (!isNull _x) then { ctrlDelete _x; }; } forEach _x;
} forEach _contactControls;
{ if (!isNull _x) then { ctrlDelete _x; }; } forEach _panelControls;

missionNamespace setVariable ["BPD_HUD_radarFrameControls", []];
missionNamespace setVariable ["BPD_HUD_radarContactControls", []];
missionNamespace setVariable ["BPD_HUD_radarPanelControls", []];
missionNamespace setVariable ["BPD_HUD_radarPanelRows", []];
missionNamespace setVariable ["BPD_HUD_radarCreated", false];
