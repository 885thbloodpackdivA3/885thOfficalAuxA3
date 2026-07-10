/*
    885th Ion Disruptor - Client FX Script
    fn_ionFx.sqf
    Broadcast to all clients via BIS_fnc_MP.
    Plays ion arc and zap particle effects on the disabled vehicle.
*/

params ["_vehicle"];

private _disableDuration = missionNamespace getVariable ["885th_ion_disableDuration", 30];
private _startTime       = time;
private _particles       = [];

// --- ZAP EFFECT ---
private _zapEffect = "#particlesource" createVehicleLocal (getPosATL _vehicle);
_zapEffect setParticleCircle [0, [0, 0, 0]];
_zapEffect setParticleRandom [0, [0.25, 0.25, 0], [0.175, 0.175, 0], 0, 0.25, [0, 0, 0, 0.1], 0, 0];
_zapEffect setParticleParams [["\A3\data_f\blesk1", 1, 0, 1], "", "SpaceObject", 1, 0.5, [0, 0, 0], [0, 0, 0.1], 0, 10, 7, 0.075, [0.005, 0.005], [[0.1, 0.1, 0.1, 1], [0.25, 0.25, 0.25, 0.5], [0.5, 0.5, 0.5, 0]], [0.5], 0, 0, "", "", _vehicle];
_zapEffect setDropInterval 0.05;
_zapEffect attachTo [_vehicle, (getCenterOfMass _vehicle)];
_particles pushBack _zapEffect;

// --- ION ARC LOOP ---
while {
    !isNull _vehicle
    && {alive _vehicle}
    && {_vehicle getVariable ["BP_IonDisabled", false]}
    && {time - _startTime < _disableDuration + 1}
} do
{
    private _pos = getPosASL _vehicle;
    "IonDisruptorArc" createVehicle _pos;
    sleep 0.6;
};

// --- CLEANUP ---
{
    deleteVehicle _x;
} forEach _particles;
