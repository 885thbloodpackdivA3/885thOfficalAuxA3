/*
    Function: BPD_HUD_fnc_createRadar
    Description: Dynamically builds the squad radar ring + contact dots + status
                 panel controls (adapted from a reference "Squad Radar Health" HUD).
                 Safe to call multiple times - exits early if already built.
*/
if (!hasInterface) exitWith {};
disableSerialization;

private _display = uiNamespace getVariable ["BPD_HUD_display", displayNull];
if (isNull _display) exitWith {};
if (missionNamespace getVariable ["BPD_HUD_radarCreated", false]) exitWith {};

private _frameControls = [];
private _outerCount = 48;
private _innerCount = 24;

for "_i" from 0 to (_outerCount - 1) do {
    private _ctrl = _display ctrlCreate ["RscText", -1];
    _frameControls pushBack _ctrl;
};
for "_i" from 0 to (_innerCount - 1) do {
    private _ctrl = _display ctrlCreate ["RscText", -1];
    _frameControls pushBack _ctrl;
};

// Crosshair (4 tick marks) + center dot + range label
private _crossA = _display ctrlCreate ["RscText", -1];
private _crossB = _display ctrlCreate ["RscText", -1];
private _crossC = _display ctrlCreate ["RscText", -1];
private _crossD = _display ctrlCreate ["RscText", -1];
{ _frameControls pushBack _x; } forEach [_crossA, _crossB, _crossC, _crossD];

private _centerDot = _display ctrlCreate ["RscText", -1];
_frameControls pushBack _centerDot;

private _rangeText = _display ctrlCreate ["RscText", -1];
_rangeText ctrlSetFontHeight 0.02;
_frameControls pushBack _rangeText;

// Contact dots (one set per potential squad member)
private _contacts = [];
private _maxContacts = missionNamespace getVariable ["BPD_HUD_radarMaxContacts", 12];

for "_i" from 0 to (_maxContacts - 1) do {
    private _dot = _display ctrlCreate ["RscText", -1];
    private _nameCtrl = _display ctrlCreate ["RscText", -1];
    private _stem = _display ctrlCreate ["RscText", -1];

    _nameCtrl ctrlSetFontHeight 0.017;
    { _x ctrlShow false; } forEach [_dot, _nameCtrl, _stem];

    _contacts pushBack [_dot, _nameCtrl, _stem];
};

// Status panel (role-free version: name / distance / hp%/ bar per row)
private _panelControls = [];
private _panelRows = [];
private _maxRows = missionNamespace getVariable ["BPD_HUD_radarMaxPanelRows", 12];

private _panelBg = _display ctrlCreate ["RscText", -1];
private _panelHeader = _display ctrlCreate ["RscText", -1];
private _panelTopLine = _display ctrlCreate ["RscText", -1];

_panelHeader ctrlSetFontHeight 0.02;
_panelHeader ctrlSetText "SQUAD";
_panelControls append [_panelBg, _panelHeader, _panelTopLine];

for "_i" from 0 to (_maxRows - 1) do {
    private _rowBg = _display ctrlCreate ["RscText", -1];
    private _name = _display ctrlCreate ["RscText", -1];
    private _dist = _display ctrlCreate ["RscText", -1];
    private _hpText = _display ctrlCreate ["RscText", -1];
    private _barBg = _display ctrlCreate ["RscText", -1];
    private _barFill = _display ctrlCreate ["RscText", -1];

    _name ctrlSetFontHeight 0.018;
    _dist ctrlSetFontHeight 0.015;
    _hpText ctrlSetFontHeight 0.016;

    { _x ctrlShow false; } forEach [_rowBg, _name, _dist, _hpText, _barBg, _barFill];

    _panelControls append [_rowBg, _name, _dist, _hpText, _barBg, _barFill];
    _panelRows pushBack [_rowBg, _name, _dist, _hpText, _barBg, _barFill];
};

missionNamespace setVariable ["BPD_HUD_radarFrameControls", _frameControls];
missionNamespace setVariable ["BPD_HUD_radarContactControls", _contacts];
missionNamespace setVariable ["BPD_HUD_radarPanelControls", _panelControls];
missionNamespace setVariable ["BPD_HUD_radarPanelRows", _panelRows];
missionNamespace setVariable ["BPD_HUD_radarCreated", true];
