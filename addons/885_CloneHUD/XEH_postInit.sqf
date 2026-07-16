if (!hasInterface) exitWith {};

// Boot + init on first spawn
[{ !isNull player && {player == player} }, {
    player spawn BPD_HUD_fnc_bootSequence;
    [player] call BPD_HUD_fnc_initHUD;
}] call CBA_fnc_waitUntilAndExecute;

// Re-run on respawn / player change (unit reassignment, JIP slotting, etc.)
addMissionEventHandler ["PlayerChanged", {
    params ["_newPlayer", "_oldPlayer"];
    if (isNull _newPlayer) exitWith {};
    _newPlayer spawn BPD_HUD_fnc_bootSequence;
    [_newPlayer] call BPD_HUD_fnc_initHUD;
}];

// Toggle keybind (default: Shift + H) - change to taste
["BPD_HUD", "ToggleHUD", "885th Clone HUD: Toggle Display",
    { call BPD_HUD_fnc_toggleHUD; true },
    { false },
    [35, [false, true, false]] // H key, shift held
] call CBA_fnc_addKeybind;
