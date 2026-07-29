/*
    Author: 885th Bloodpack Division
    Description: Katarn Shield Integrity HUD - segmented bar, RC-style.

    Two entry points, both global so fn_energyShield.sqf can drive them:
      BPD_fnc_shieldHUD_build   - creates the controls once (safe to call again, it cleans up first)
      BPD_fnc_shieldHUD_update  - params: [current, max, active, broken] - called every tick
      BPD_fnc_shieldHUD_destroy - tears the controls down (called on death/unit change)

    Not a resource-defined dialog on purpose - this only needs a handful of
    flat controls, so it's built directly on RscDisplayInGame (46) the same
    lightweight way BPD_fnc_injectShieldMenus builds its addAction menu,
    rather than adding a full dialog resource to config.cpp for something
    this small.
*/

#define SEGMENT_COUNT 14
#define BAR_WIDTH 0.26
#define SEGMENT_GAP 0.0015
#define BAR_HEIGHT 0.014
#define BAR_Y 0.815

BPD_shieldHUD_ctrls = [];

BPD_fnc_shieldHUD_destroy = {
    {
        if (!isNull _x) then { ctrlDelete _x; };
    } forEach BPD_shieldHUD_ctrls;
    BPD_shieldHUD_ctrls = [];
};

BPD_fnc_shieldHUD_build = {
    [] call BPD_fnc_shieldHUD_destroy;

    private _display = findDisplay 46;
    if (isNull _display) exitWith {};

    private _segW = (BAR_WIDTH - (SEGMENT_GAP * (SEGMENT_COUNT - 1))) / SEGMENT_COUNT;
    private _barX = safezoneX + (safezoneW * 0.5) - (BAR_WIDTH * 0.5);
    private _barY = safezoneY + (safezoneH * BAR_Y);

    // backing plate, slightly larger than the segment row
    private _bg = _display ctrlCreate ["RscText", -1];
    _bg ctrlSetPosition [_barX - 0.004, _barY - 0.004, BAR_WIDTH + 0.008, BAR_HEIGHT + 0.008];
    _bg ctrlSetBackgroundColor [0, 0, 0, 0.35];
    _bg ctrlCommit 0;
    BPD_shieldHUD_ctrls pushBack _bg;

    // label above the bar - shows numeric readout / status text
    private _label = _display ctrlCreate ["RscText", -1];
    _label ctrlSetPosition [_barX, _barY - 0.022, BAR_WIDTH, 0.016];
    _label ctrlSetTextColor [0.55, 0.95, 1, 1];
    _label ctrlSetBackgroundColor [0, 0, 0, 0];
    _label ctrlSetText "";
    _label ctrlCommit 0;
    BPD_shieldHUD_ctrls pushBack _label;

    // the segments themselves
    for "_i" from 0 to (SEGMENT_COUNT - 1) do {
        private _segX = _barX + (_i * (_segW + SEGMENT_GAP));
        private _seg = _display ctrlCreate ["RscText", -1];
        _seg ctrlSetPosition [_segX, _barY, _segW, BAR_HEIGHT];
        _seg ctrlSetBackgroundColor [0.1, 0.3, 0.35, 0.6];
        _seg ctrlCommit 0;
        BPD_shieldHUD_ctrls pushBack _seg;
    };

    // whole assembly starts hidden - update call reveals it once shields are active
    { _x ctrlShow false; } forEach BPD_shieldHUD_ctrls;
};

/*
    params: [_current, _max, _active, _broken]
    Colors: cyan when healthy, amber under 30%, red-flash while broken/recharging.
*/
BPD_fnc_shieldHUD_update = {
    params ["_current", "_max", "_active", "_broken"];
    if (count BPD_shieldHUD_ctrls < (SEGMENT_COUNT + 2)) exitWith {};

    private _bg = BPD_shieldHUD_ctrls select 0;
    private _label = BPD_shieldHUD_ctrls select 1;

    if (!_active) exitWith {
        { _x ctrlShow false; } forEach BPD_shieldHUD_ctrls;
    };
    { _x ctrlShow true; } forEach BPD_shieldHUD_ctrls;

    private _pct = if (_max > 0) then { _current / _max } else { 0 };
    private _filledSegs = ceil (_pct * SEGMENT_COUNT);

    private _color = [0.35, 0.85, 1, 0.9]; // healthy cyan
    if (_pct < 0.3) then { _color = [1, 0.55, 0.15, 0.9]; }; // amber, low
    if (_broken) then {
        // pulses red/dark while waiting out the collapse penalty
        private _pulse = 0.5 + (0.5 * sin (diag_tickTime * 6));
        _color = [1, 0.15, 0.15, 0.4 + (_pulse * 0.5)];
    };

    for "_i" from 0 to (SEGMENT_COUNT - 1) do {
        private _seg = BPD_shieldHUD_ctrls select (_i + 2);
        if (_i < _filledSegs && {!_broken}) then {
            _seg ctrlSetBackgroundColor _color;
        } else {
            _seg ctrlSetBackgroundColor [0.1, 0.3, 0.35, 0.35];
        };
    };

    _label ctrlSetText (
        if (_broken) then {
            "SHIELDS OFFLINE - RECHARGING"
        } else {
            format ["SHIELD INTEGRITY  %1%%", round (_pct * 100)]
        }
    );
};