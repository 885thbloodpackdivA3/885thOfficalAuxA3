if (!hasInterface) exitWith {};

// Boot + init whenever the local player unit changes (covers first spawn,
// respawn, and JIP slotting). "PlayerChanged" is not a real mission event
// handler in this Arma version, so this is done with a lightweight poll
// instead of addMissionEventHandler.
missionNamespace setVariable ["BPD_HUD_lastPlayer", objNull];

[{
    private _current = player;
    private _last = missionNamespace getVariable ["BPD_HUD_lastPlayer", objNull];
    if (!isNull _current && {_current != _last}) then {
        missionNamespace setVariable ["BPD_HUD_lastPlayer", _current];
        _current spawn BPD_HUD_fnc_bootSequence;
        [_current] call BPD_HUD_fnc_initHUD;
    };
}, 1] call CBA_fnc_addPerFrameHandler;

// Toggle keybind (default: Shift + H) - change to taste
["BPD_HUD", "ToggleHUD", "885th Clone HUD: Toggle Display",
    { call BPD_HUD_fnc_toggleHUD; true },
    { false },
    [35, [false, true, false]] // H key, shift held
] call CBA_fnc_addKeybind;

// Squad radar zoom (Page Up = zoom in / reduce range, Page Down = zoom out)
["BPD_HUD", "RadarZoomIn", "885th Clone HUD: Radar Zoom In",
    {
        private _range = missionNamespace getVariable ["BPD_HUD_radarRange", 200];
        _range = (_range - 25) max 20;
        missionNamespace setVariable ["BPD_HUD_radarRange", _range];
        true
    },
    { false },
    [201, [false, false, false]] // Page Up
] call CBA_fnc_addKeybind;

["BPD_HUD", "RadarZoomOut", "885th Clone HUD: Radar Zoom Out",
    {
        private _range = missionNamespace getVariable ["BPD_HUD_radarRange", 200];
        _range = (_range + 25) min 500;
        missionNamespace setVariable ["BPD_HUD_radarRange", _range];
        true
    },
    { false },
    [209, [false, false, false]] // Page Down
] call CBA_fnc_addKeybind;
