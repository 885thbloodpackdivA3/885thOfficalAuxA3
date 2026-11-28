/*
    Author: 885th Bloodpack Division
    BPD_fnc_arcHitFX - params: [vehicle, broken(false), play(false)]

    Two modes:
      play = false  (called by the damage handler on the aircraft's owner)
          Throttles to one burst per 0.15s - cannon fire can land dozens of
          hits a second - then sends a play = true call to the player crew
          (pilot AND rear gunner). A collapse (broken = true) always goes out.
      play = true   (runs on each crew player's machine)
          Local blue flash + shield sound, only for whoever is aboard.
*/
params ["_veh", ["_broken", false], ["_play", false]];

if (!_play) exitWith {
    private _now = diag_tickTime;
    if (!_broken && {_now - (_veh getVariable ["BPD_arc_lastFX", 0]) < 0.15}) exitWith {};
    _veh setVariable ["BPD_arc_lastFX", _now];

    private _targets = (crew _veh) select { isPlayer _x };
    if (_targets isEqualTo []) exitWith {};
    [_veh, _broken, true] remoteExecCall ["BPD_fnc_arcHitFX", _targets];
};

if (!hasInterface || {vehicle player != _veh}) exitWith {};

if (_broken) then {
    playSound "AUX_Shield_Shutdown";
    hintSilent parseText "<t color='#ff4040' size='1.2'>DEFLECTORS DOWN</t>";
} else {
    playSound "AUX_Shield_Hit";
};

// brief blue shimmer around the airframe
private _light = "#lightpoint" createVehicleLocal (getPosATL _veh);
_light attachTo [_veh, [0, 0, 0]];
_light setLightColor [0.2, 0.55, 1];
_light setLightAmbient [0.1, 0.3, 0.8];
_light setLightBrightness ([4, 10] select _broken);
_light setLightAttenuation [2, 4, 4, 0, 6, 12];

private _fx = "#particlesource" createVehicleLocal (getPosATL _veh);
_fx setParticleParams [
    ["\A3\data_f\VolumeLight", 1, 0, 1], "", "SpaceObject",
    1, 0.12, [0, 0, 0], [0, 0, 0], 0, 10, 7.9, 0, [5, 7, 0],
    [[0.2, 0.6, 1, 0.35], [0.1, 0.3, 1, 0]], [1], 0, 0, "", "", _veh
];
_fx setDropInterval 0.01;

[{ { deleteVehicle _x } forEach _this; }, [_light, _fx], 0.12] call CBA_fnc_waitAndExecute;
