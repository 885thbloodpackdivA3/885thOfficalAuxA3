/*
    Author: 885th Bloodpack Division
    ARC-170 deflector / power HUD. Same flat-controls-on-display-46 approach as
    the Katarn HUD (885_Armor\scripts\fn_shieldHUD.sqf), but its own controls
    and globals so the two never fight - and placed at the bottom by default
    so it doesn't stack on the Katarn bar (top center).

      BPD_fnc_arcHUD_build
      BPD_fnc_arcHUD_update  - params: [current, max, broken, mode, boosting]
      BPD_fnc_arcHUD_destroy
*/

#define SEGMENT_COUNT 16
// sizes are 80% of the previous pass (0.56 / 0.028 / 0.034...) - whole HUD scaled down 20%
#define BAR_WIDTH 0.448
#define LEFT_SHARE 0.58
#define SEGMENT_GAP 0.0024
#define BAR_HEIGHT 0.0224
#define TEXT_HEIGHT 0.0288
#define FONT_SIZE 0.0272
#define PAD 0.0064

BPD_arcHUD_ctrls = [];
BPD_arcHUD_visible = true;

BPD_fnc_arcHUD_destroy = {
    { if (!isNull _x) then { ctrlDelete _x; }; } forEach BPD_arcHUD_ctrls;
    BPD_arcHUD_ctrls = [];
    BPD_arcHUD_lastShieldText = ""; // new controls start blank, force a redraw
    BPD_arcHUD_lastModeText = "";
    BPD_arcHUD_visible = true;      // freshly built controls are shown
};

BPD_fnc_arcHUD_build = {
    [] call BPD_fnc_arcHUD_destroy;
    private _display = findDisplay 46;
    if (isNull _display) exitWith {};

    private _preset = missionNamespace getVariable ["AUX_885th_ARC_HUD_Position", 0];
    private _x0 = switch (_preset) do {
        case 1: { safezoneX + 0.02 };
        case 2: { safezoneX + safezoneW - BAR_WIDTH - 0.02 };
        default { safezoneX + (safezoneW * 0.5) - (BAR_WIDTH * 0.5) };
    };
    private _y0 = if (_preset == 3) then { safezoneY + (safezoneH * 0.10) } else { safezoneY + (safezoneH * 0.84) };

    // darker backing plate so the bar and text read against bright sky
    private _bg = _display ctrlCreate ["RscText", -1];
    _bg ctrlSetPosition [_x0 - PAD, _y0 - TEXT_HEIGHT - PAD, BAR_WIDTH + (PAD * 2), BAR_HEIGHT + TEXT_HEIGHT + (PAD * 2)];
    _bg ctrlSetBackgroundColor [0, 0, 0, 0.6];
    _bg ctrlCommit 0;
    BPD_arcHUD_ctrls pushBack _bg;

    // left label: shield %, right label: power mode (right-aligned)
    private _label = _display ctrlCreate ["RscStructuredText", -1];
    _label ctrlSetPosition [_x0, _y0 - TEXT_HEIGHT, BAR_WIDTH * LEFT_SHARE, TEXT_HEIGHT];
    _label ctrlSetFontHeight FONT_SIZE;
    _label ctrlCommit 0;
    BPD_arcHUD_ctrls pushBack _label;

    private _mode = _display ctrlCreate ["RscStructuredText", -1];
    _mode ctrlSetPosition [_x0 + BAR_WIDTH * LEFT_SHARE, _y0 - TEXT_HEIGHT, BAR_WIDTH * (1 - LEFT_SHARE), TEXT_HEIGHT];
    _mode ctrlSetFontHeight FONT_SIZE;
    _mode ctrlCommit 0;
    BPD_arcHUD_ctrls pushBack _mode;

    private _segW = (BAR_WIDTH - (SEGMENT_GAP * (SEGMENT_COUNT - 1))) / SEGMENT_COUNT;
    for "_i" from 0 to (SEGMENT_COUNT - 1) do {
        private _seg = _display ctrlCreate ["RscText", -1];
        _seg ctrlSetPosition [_x0 + (_i * (_segW + SEGMENT_GAP)), _y0, _segW, BAR_HEIGHT];
        _seg ctrlSetBackgroundColor [0.1, 0.3, 0.35, 0.6];
        _seg ctrlCommit 0;
        BPD_arcHUD_ctrls pushBack _seg;
    };
};

BPD_fnc_arcHUD_update = {
    params ["_current", "_max", "_broken", "_mode", "_boosting", ["_repairing", false], ["_charges", 0], ["_strain", false]];
    if (count BPD_arcHUD_ctrls < (SEGMENT_COUNT + 3)) exitWith {};

    private _pct = if (_max > 0) then { (_current / _max) min 1 } else { 0 };
    private _filled = ceil (_pct * SEGMENT_COUNT);

    private _color = [[0.35, 0.85, 1, 0.9], [0.25, 0.65, 1, 0.95], [1, 0.7, 0.2, 0.9]] select _mode;
    if (_pct < 0.3) then { _color = [1, 0.55, 0.15, 0.9]; };
    if (_broken) then {
        private _pulse = 0.5 + (0.5 * sin (diag_tickTime * 360));
        _color = [1, 0.15, 0.15, 0.4 + (_pulse * 0.5)];
    };

    for "_i" from 0 to (SEGMENT_COUNT - 1) do {
        (BPD_arcHUD_ctrls select (_i + 3)) ctrlSetBackgroundColor (
            if (_i < _filled && {!_broken}) then { _color } else { [0.1, 0.3, 0.35, 0.35] }
        );
    };

    // Only redraw the text when it actually changes - structured text is
    // re-parsed on every set, and this runs every frame.
    private _shieldText = format [
        "%1 <t font='PuristaBold' size='0.8' color='%2' shadow='2'>REP %3</t>",
        if (_broken) then {
            "<t font='PuristaBold' color='#ff4040' shadow='2'>DEFLECTORS DOWN</t>"
        } else {
            format ["<t font='PuristaBold' color='#8cf2ff' shadow='2'>DEFLECTORS %1%2</t>", round (_pct * 100), "%"]
        },
        ["#7dff9a", "#806060"] select (_charges <= 0),
        _charges
    ];
    private _modeText = if (_repairing) then {
        // pulsing green while the repair has the power
        format ["<t align='right' font='PuristaBold' color='%1' shadow='2'>REPAIRING...</t>",
            ["#7dff9a", "#3fae58"] select ((floor (diag_tickTime * 2)) mod 2 == 1)]
    } else {
      if (_strain) then {
        // fast red flash: Max Engines on a damaged jet
        format ["<t align='right' font='PuristaBold' color='%1' shadow='2'>ENGINE STRAIN</t>",
            ["#ff4040", "#801818"] select ((floor (diag_tickTime * 4)) mod 2 == 1)]
      } else {
        format [
            "<t align='right' font='PuristaBold' color='%1' shadow='2'>%2</t>",
            ["#8cf2ff", "#66ccff", "#ffbf4d"] select _mode,
            if (_boosting) then { "BOOST &gt;&gt;" } else { ["BALANCED", "MAX SHIELDS", "MAX ENGINES"] select _mode }
        ]
      }
    };

    if (_shieldText != (missionNamespace getVariable ["BPD_arcHUD_lastShieldText", ""])) then {
        BPD_arcHUD_lastShieldText = _shieldText;
        (BPD_arcHUD_ctrls select 1) ctrlSetStructuredText parseText _shieldText;
    };
    if (_modeText != (missionNamespace getVariable ["BPD_arcHUD_lastModeText", ""])) then {
        BPD_arcHUD_lastModeText = _modeText;
        (BPD_arcHUD_ctrls select 2) ctrlSetStructuredText parseText _modeText;
    };
};
