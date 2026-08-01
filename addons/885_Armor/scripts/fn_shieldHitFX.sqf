/*
    Author: 885th Bloodpack Division
    BPD_fnc_shieldHitFX

    Params: [unit]
    Shared particle burst used on every absorbed hit, regardless of which
    medical framework (vanilla / ACE / KAT-on-ACE) actually processed the
    damage. Pulled out so both damage paths stay visually/audibly identical.
*/
params ["_unit"];

private _pos = _unit modelToWorld [0, 0.2, 1.2];
private _shieldEffect = "#particlesource" createVehicleLocal _pos;
_shieldEffect setParticleParams [
    ["\A3\data_f\VolumeLight", 1, 0, 1], "", "SpaceObject",
    1, 0.15, [0, 0, 0], [0, 0, 0], 0, 10, 7.9, 0, [0.4, 0.8, 0],
    [[0, 0.6, 1, 0.6], [0, 0.3, 1, 0.3]], [1], 0, 0, "", "", _unit
];
_shieldEffect setDropInterval 0.002;
[_shieldEffect] spawn { params ["_fx"]; uiSleep 0.1; deleteVehicle _fx; };
