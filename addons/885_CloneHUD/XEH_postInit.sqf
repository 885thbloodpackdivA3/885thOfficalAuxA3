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
