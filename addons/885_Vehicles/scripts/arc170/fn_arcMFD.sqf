/*
    Author: 885th Bloodpack Division
    ARC-170 cockpit HUD driver - feeds arc170_hud.hpp.

      BPD_fnc_arcMFD_update - params: [vehicle, shield, max, broken, mode, boosting, repairing, charges]

    Called every frame from the client loop for whoever is aboard. MFD user
    values are set on this machine for this crew member's own HUD, and only
    when they change, so this costs next to nothing once the HUD is up.

    Engine start (off -> on, or climbing into a running jet) triggers the boot:
    colour applied, HUD fades in over ~1.2s and "ARC-170 SYSTEMS ONLINE" shows
    for 2.5s. The stock 3AS HUD is already gated on the engine running, so it
    disappears on its own when the engine goes off.
*/

BPD_arcMFD_veh = objNull;
BPD_arcMFD_engine = false;
BPD_arcMFD_bootStart = -100;
BPD_arcMFD_next = 0;
BPD_arcMFD_cache = createHashMap;

// [r, g, b] per AUX_885th_ARC_HUD_Color entry; index 6 = leave colour alone
BPD_arcMFD_colors = [
    [0.35, 0.85, 1],   // Republic cyan
    [0.30, 0.55, 1],   // blue
    [0.30, 1, 0.40],   // green
    [1, 0.75, 0.25],   // amber
    [1, 1, 1],         // white
    [1, 0.30, 0.30]    // red
];

BPD_fnc_arcMFD_setVal = {
    params ["_veh", "_idx", "_val"];
    private _key = format ["v%1", _idx];
    if ((BPD_arcMFD_cache getOrDefault [_key, -999]) != _val) then {
        BPD_arcMFD_cache set [_key, _val];
        _veh setUserMFDValue [_idx, _val];
    };
};

BPD_fnc_arcMFD_setText = {
    params ["_veh", "_idx", "_text"];
    private _key = format ["t%1", _idx];
    if ((BPD_arcMFD_cache getOrDefault [_key, ""]) != _text) then {
        BPD_arcMFD_cache set [_key, _text];
        _veh setUserMFDText [_idx, _text];
    };
};

BPD_fnc_arcMFD_update = {
    params ["_veh", "_shield", "_max", "_broken", "_mode", "_boosting", "_repairing", "_charges", ["_strain", false]];

    if (_veh != BPD_arcMFD_veh) then {
        BPD_arcMFD_veh = _veh;
        BPD_arcMFD_engine = false;     // entering a running jet boots the HUD too
        BPD_arcMFD_cache = createHashMap;
    };

    private _engine = isEngineOn _veh;
    if (_engine && {!BPD_arcMFD_engine}) then {
        BPD_arcMFD_bootStart = diag_tickTime;
        BPD_arcMFD_cache = createHashMap;
        private _choice = missionNamespace getVariable ["AUX_885th_ARC_HUD_Color", 0];
        if (_choice < count BPD_arcMFD_colors) then {
            { [_veh, _forEachIndex, _x] call BPD_fnc_arcMFD_setVal; } forEach (BPD_arcMFD_colors select _choice);
        };
        playSound "AUX_Shield_Boot";
    };
    BPD_arcMFD_engine = _engine;
    if (!_engine) exitWith {};

    private _sinceBoot = diag_tickTime - BPD_arcMFD_bootStart;
    private _booting = _sinceBoot < 1.3;

    // smooth every frame while fading in, 10 Hz after that
    if (!_booting && {diag_tickTime < BPD_arcMFD_next}) exitWith {};
    BPD_arcMFD_next = diag_tickTime + 0.1;

    [_veh, 3, (_sinceBoot / 1.2) min 1] call BPD_fnc_arcMFD_setVal;
    [_veh, 6, [0, 1] select (_sinceBoot < 2.5)] call BPD_fnc_arcMFD_setVal;

    private _pct = if (_max > 0) then { (_shield / _max) min 1 max 0 } else { 0 };
    [_veh, 4, (round (_pct * 20)) / 20] call BPD_fnc_arcMFD_setVal; // 5% steps - arc has 10 segments
    [_veh, 5, [0, 1] select _broken] call BPD_fnc_arcMFD_setVal;
    [_veh, 7, [0, 1] select _repairing] call BPD_fnc_arcMFD_setVal;
    [_veh, 8, [0, 1] select _boosting] call BPD_fnc_arcMFD_setVal;
    [_veh, 9, [0, 1] select _strain] call BPD_fnc_arcMFD_setVal;

    [_veh, 0, if (_strain) then { "PWR ENGINES !" } else { ["PWR BALANCED", "PWR SHIELDS", "PWR ENGINES"] select _mode }] call BPD_fnc_arcMFD_setText;
    [_veh, 1, if (_broken) then { "DEF --" } else { format ["DEF %1%2", round (_pct * 100), "%"] }] call BPD_fnc_arcMFD_setText;
    [_veh, 2, format ["REP %1", _charges]] call BPD_fnc_arcMFD_setText;
    [_veh, 3, format ["FUEL %1%2", round ((fuel _veh) * 100), "%"]] call BPD_fnc_arcMFD_setText;
    [_veh, 4, format ["THR %1%2", round ((airplaneThrottle _veh) * 100), "%"]] call BPD_fnc_arcMFD_setText;
};
