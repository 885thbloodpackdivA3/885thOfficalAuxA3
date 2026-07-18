/*
    Function: BPD_HUD_fnc_updateRadar
    Description: Positions the radar ring, squad contact dots, and status panel
                 each tick. Adapted from a reference "Squad Radar Health" HUD,
                 simplified to health-based coloring (no team/buddy color modes).
*/
if (!hasInterface) exitWith {};
disableSerialization;

if !(missionNamespace getVariable ["BPD_HUD_radarEnabled", true]) exitWith {};
if !(missionNamespace getVariable ["BPD_HUD_enabled", true]) exitWith {};
if (missionNamespace getVariable ["BPD_HUD_visible", true] isEqualTo false) exitWith {};
if (isNull player || {!alive player}) exitWith {};

if !(missionNamespace getVariable ["BPD_HUD_radarCreated", false]) then {
    call BPD_HUD_fnc_createRadar;
};

private _frameControls = missionNamespace getVariable ["BPD_HUD_radarFrameControls", []];
private _contactControls = missionNamespace getVariable ["BPD_HUD_radarContactControls", []];
private _panelControls = missionNamespace getVariable ["BPD_HUD_radarPanelControls", []];
private _panelRows = missionNamespace getVariable ["BPD_HUD_radarPanelRows", []];
if (_frameControls isEqualTo []) exitWith {};

private _fnc_healthColor = {
    params ["_unit"];
    private _pct = round ((1 - (damage _unit)) * 100);
    if (_pct <= 35) exitWith { [1,0.2,0.2,1] };
    if (_pct <= 70) exitWith { [1,0.8,0.2,1] };
    [0.2,1,0.2,1]
};

// --- Layout: bottom-left circular radar, panel to its right ---
private _size = missionNamespace getVariable ["BPD_HUD_radarSize", 0.16];
private _range = missionNamespace getVariable ["BPD_HUD_radarRange", 200];
private _showNames = missionNamespace getVariable ["BPD_HUD_radarShowNames", true];
private _showDistance = missionNamespace getVariable ["BPD_HUD_radarShowDistance", true];
private _panelEnabled = missionNamespace getVariable ["BPD_HUD_radarPanelEnabled", true];
private _accent = [0.3,0.9,1]; // matches the rest of the 885th HUD palette

private _centerX = safezoneX + (safezoneW * 0.12);
private _centerY = safezoneY + (safezoneH * 0.80);
private _radius = _size * 0.5;
private _outerCount = 48;
private _innerCount = 24;
private _tick = _size * 0.016;
private _outerStep = 360 / _outerCount;
private _innerStep = 360 / _innerCount;
private _idx = 0;

for "_i" from 0 to (_outerCount - 1) do {
    private _ctrl = _frameControls select _idx;
    private _angle = _i * _outerStep;
    private _x = _centerX + ((sin _angle) * _radius) - (_tick * 0.5);
    private _y = _centerY - ((cos _angle) * _radius) - (_tick * 0.5);
    private _major = (_i mod 6) isEqualTo 0;
    private _dim = [_tick, _tick * 1.7] select _major;
    _ctrl ctrlSetPosition [_x, _y, _dim, _dim];
    _ctrl ctrlSetBackgroundColor [_accent select 0, _accent select 1, _accent select 2, [0.4, 0.75] select _major];
    _ctrl ctrlShow true;
    _ctrl ctrlCommit 0;
    _idx = _idx + 1;
};

for "_i" from 0 to (_innerCount - 1) do {
    private _ctrl = _frameControls select _idx;
    private _angle = _i * _innerStep;
    private _x = _centerX + ((sin _angle) * (_radius * 0.58)) - (_tick * 0.35);
    private _y = _centerY - ((cos _angle) * (_radius * 0.58)) - (_tick * 0.35);
    _ctrl ctrlSetPosition [_x, _y, _tick * 0.7, _tick * 0.7];
    _ctrl ctrlSetBackgroundColor [_accent select 0, _accent select 1, _accent select 2, 0.18];
    _ctrl ctrlShow true;
    _ctrl ctrlCommit 0;
    _idx = _idx + 1;
};

private _crossLen = _radius * 0.72;
private _line = _size * 0.007;
private _crossA = _frameControls select _idx; _idx = _idx + 1;
private _crossB = _frameControls select _idx; _idx = _idx + 1;
private _crossC = _frameControls select _idx; _idx = _idx + 1;
private _crossD = _frameControls select _idx; _idx = _idx + 1;

_crossA ctrlSetPosition [_centerX - _crossLen, _centerY - (_line * 0.5), _crossLen * 0.72, _line];
_crossB ctrlSetPosition [_centerX + (_crossLen * 0.28), _centerY - (_line * 0.5), _crossLen * 0.72, _line];
_crossC ctrlSetPosition [_centerX - (_line * 0.5), _centerY - _crossLen, _line, _crossLen * 0.72];
_crossD ctrlSetPosition [_centerX - (_line * 0.5), _centerY + (_crossLen * 0.28), _line, _crossLen * 0.72];
{
    _x ctrlSetBackgroundColor [_accent select 0, _accent select 1, _accent select 2, 0.22];
    _x ctrlShow true;
    _x ctrlCommit 0;
} forEach [_crossA, _crossB, _crossC, _crossD];

private _centerDot = _frameControls select _idx; _idx = _idx + 1;
_centerDot ctrlSetPosition [_centerX - (_tick * 0.9), _centerY - (_tick * 0.9), _tick * 1.8, _tick * 1.8];
_centerDot ctrlSetBackgroundColor [_accent select 0, _accent select 1, _accent select 2, 0.95];
_centerDot ctrlShow true;
_centerDot ctrlCommit 0;

private _rangeText = _frameControls select _idx; _idx = _idx + 1;
_rangeText ctrlSetPosition [_centerX - (_size * 0.5), _centerY - (_radius * 1.22), _size, _size * 0.11];
_rangeText ctrlSetText format ["SQUAD RADAR  %1m", round _range];
_rangeText ctrlSetTextColor [_accent select 0, _accent select 1, _accent select 2, 0.9];
_rangeText ctrlShow true;
_rangeText ctrlCommit 0;

// --- Contact dots ---
private _units = (units group player) select {_x != player && alive _x};
_units = _units select {(_x distance2D player) <= _range};
_units = [_units, [], {_x distance2D player}, "ASCEND"] call BIS_fnc_sortBy;

private _playerPos = getPosASLVisual player;
private _dir = getDirVisual player;
private _scale = (_radius * 0.82) / _range;
private _contactCount = count _contactControls;

for "_i" from 0 to (_contactCount - 1) do {
    private _set = _contactControls select _i;
    private _dot = _set select 0;
    private _nameCtrl = _set select 1;
    private _stem = _set select 2;

    if (_i >= count _units) then {
        { _x ctrlShow false; } forEach [_dot, _nameCtrl, _stem];
    } else {
        private _unit = _units select _i;
        private _unitPos = getPosASLVisual _unit;
        private _dx = (_unitPos select 0) - (_playerPos select 0);
        private _dy = (_unitPos select 1) - (_playerPos select 1);
        private _rx = (_dx * cos _dir) - (_dy * sin _dir);
        private _ry = (_dx * sin _dir) + (_dy * cos _dir);
        private _sx = _centerX + (_rx * _scale);
        private _sy = _centerY - (_ry * _scale);
        private _dist = _unit distance2D player;
        private _color = [_unit] call _fnc_healthColor;

        private _dotSize = _size * 0.045;
        _dot ctrlSetPosition [_sx - (_dotSize * 0.5), _sy - (_dotSize * 0.5), _dotSize, _dotSize];
        _dot ctrlSetBackgroundColor _color;
        _dot ctrlShow true;
        _dot ctrlCommit 0;

        _stem ctrlSetPosition [_sx + (_dotSize * 0.45), _sy - (_size * 0.004), _size * 0.03, _size * 0.008];
        _stem ctrlSetBackgroundColor [(_color select 0), (_color select 1), (_color select 2), 0.45];
        _stem ctrlShow true;
        _stem ctrlCommit 0;

        if (_showNames || _showDistance) then {
            private _label = "";
            if (_showNames) then {
                private _tag = _unit getVariable ["BPD_callsign", name _unit];
                _label = _tag;
            };
            if (_showDistance) then {
                _label = format ["%1 %2m", _label, round _dist];
            };
            _nameCtrl ctrlSetPosition [_sx + (_dotSize * 0.8), _sy - (_size * 0.027), _size * 0.5, _size * 0.05];
            _nameCtrl ctrlSetText _label;
            _nameCtrl ctrlSetTextColor _color;
            _nameCtrl ctrlShow true;
            _nameCtrl ctrlCommit 0;
        } else {
            _nameCtrl ctrlShow false;
        };
    };
};

// --- Status panel ---
if (!_panelEnabled || {_panelControls isEqualTo []}) exitWith {
    { if (!isNull _x) then { _x ctrlShow false; }; } forEach _panelControls;
};

private _panelUnits = [player] + _units;
private _rowH = safezoneH * 0.028;
private _gap = safezoneH * 0.003;
private _headerH = safezoneH * 0.026;
private _panelW = safezoneW * 0.16;
private _panelX = _centerX + _radius + (safezoneW * 0.02);
private _panelY = _centerY - _radius;
private _rowCount = (count _panelRows) min (count _panelUnits);
private _panelH = _headerH + ((_rowH + _gap) * _rowCount) + (_gap * 2);

private _panelBg = _panelControls select 0;
private _panelHeader = _panelControls select 1;
private _panelTopLine = _panelControls select 2;

_panelBg ctrlSetPosition [_panelX, _panelY, _panelW, _panelH];
_panelBg ctrlSetBackgroundColor [0,0,0,0.35];
_panelBg ctrlShow true;
_panelBg ctrlCommit 0;

_panelHeader ctrlSetPosition [_panelX, _panelY, _panelW, _headerH];
_panelHeader ctrlSetText "SQUAD STATUS";
_panelHeader ctrlSetTextColor [_accent select 0, _accent select 1, _accent select 2, 0.95];
_panelHeader ctrlSetBackgroundColor [_accent select 0, _accent select 1, _accent select 2, 0.15];
_panelHeader ctrlShow true;
_panelHeader ctrlCommit 0;

_panelTopLine ctrlSetPosition [_panelX, _panelY, _panelW, safezoneH * 0.0016];
_panelTopLine ctrlSetBackgroundColor [_accent select 0, _accent select 1, _accent select 2, 0.7];
_panelTopLine ctrlShow true;
_panelTopLine ctrlCommit 0;

for "_i" from 0 to ((count _panelRows) - 1) do {
    private _row = _panelRows select _i;
    _row params ["_rowBg", "_name", "_dist", "_hpText", "_barBg", "_barFill"];

    if (_i >= _rowCount) then {
        { _x ctrlShow false; } forEach _row;
    } else {
        private _unit = _panelUnits select _i;
        private _health = (1 - (damage _unit)) max 0 min 1;
        private _healthPct = round (_health * 100);
        private _color = [_unit] call _fnc_healthColor;
        private _rowY = _panelY + _headerH + (_gap * 2) + (_i * (_rowH + _gap));
        private _tag = _unit getVariable ["BPD_callsign", name _unit];
        if (_unit isEqualTo player) then { _tag = format ["%1  (YOU)", _tag]; };

        _rowBg ctrlSetPosition [_panelX, _rowY, _panelW, _rowH];
        _rowBg ctrlSetBackgroundColor [(_color select 0), (_color select 1), (_color select 2), 0.12];
        _rowBg ctrlShow true;
        _rowBg ctrlCommit 0;

        _name ctrlSetPosition [_panelX + (safezoneW * 0.006), _rowY + (_rowH * 0.05), _panelW * 0.6, _rowH * 0.5];
        _name ctrlSetText _tag;
        _name ctrlSetTextColor [0.9,0.98,1,0.98];
        _name ctrlShow true;
        _name ctrlCommit 0;

        _dist ctrlSetPosition [_panelX + (safezoneW * 0.006), _rowY + (_rowH * 0.52), _panelW * 0.4, _rowH * 0.4];
        _dist ctrlSetText (if (_unit isEqualTo player) then {""} else {format ["%1m", round (_unit distance2D player)]});
        _dist ctrlSetTextColor [0.7,0.9,1,0.75];
        _dist ctrlShow true;
        _dist ctrlCommit 0;

        _hpText ctrlSetPosition [_panelX + _panelW - (safezoneW * 0.03), _rowY + (_rowH * 0.05), _panelW * 0.2, _rowH * 0.4];
        _hpText ctrlSetText format ["%1%%", _healthPct];
        _hpText ctrlSetTextColor _color;
        _hpText ctrlShow true;
        _hpText ctrlCommit 0;

        _barBg ctrlSetPosition [_panelX + (_panelW * 0.42), _rowY + (_rowH * 0.62), _panelW * 0.52, _rowH * 0.18];
        _barBg ctrlSetBackgroundColor [0,0,0,0.5];
        _barBg ctrlShow true;
        _barBg ctrlCommit 0;

        _barFill ctrlSetPosition [_panelX + (_panelW * 0.42), _rowY + (_rowH * 0.62), (_panelW * 0.52) * _health, _rowH * 0.18];
        _barFill ctrlSetBackgroundColor _color;
        _barFill ctrlShow true;
        _barFill ctrlCommit 0;
    };
};
