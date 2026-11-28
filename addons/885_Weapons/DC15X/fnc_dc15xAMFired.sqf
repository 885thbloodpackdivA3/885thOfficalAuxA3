/*
 * BPD_fnc_dc15xAMFired
 * Runs for each shot from the 5-round anti-materiel cell (885th_dc15x_am_cell) on the DC-15X:
 *  - on the shooter's machine: watches the round so a vehicle hit applies the 2-shot disable
 *    (BPD_fnc_dc15xAMVehicleHit, run where the vehicle is local)
 *  - on every player's machine: the overcharge crack on top of the rifle's normal shot, and a blue
 *    muzzle burst (flash, sparks, light pulse; see 885th_AM_* in CfgCloudlets)
 *
 * Called from the CAManBase FiredBIS XEH in 885_Weapons\config.cpp, which only calls this for the AM cell.
 * FiredBIS runs on every machine for every unit, so the sound and particles are local (no network traffic).
 *
 * Arguments: FiredBIS params [unit, weapon, muzzle, mode, ammo, magazine, projectile, gunner]
 */
params ["_unit", "", "", "", "", "", "_projectile"];

// --- Vehicle disable: only the shooter's machine (player, server or headless client) tracks the hit ---
if (local _unit && {!isNull _projectile}) then {
    _projectile addEventHandler ["HitPart", {
        params ["_projectile", "_hitEntity"];
        if (isNull _hitEntity) exitWith {};
        if !(_hitEntity isKindOf "LandVehicle" || {_hitEntity isKindOf "Air"} || {_hitEntity isKindOf "Ship"}) exitWith {};
        // One round can report several parts; count it once
        _projectile removeEventHandler [_thisEvent, _thisEventHandler];
        ["BPD_dc15xAMVehicleHit", [_hitEntity], _hitEntity] call CBA_fnc_targetEvent;
    }];
};

if (!hasInterface) exitWith {};

// The projectile is still at the muzzle on this frame; fall back to shoulder height if it's already gone
private _muzzlePos = if (isNull _projectile) then {
    AGLToASL (_unit modelToWorldVisual [0, 0.8, 1.4])
} else {
    getPosASL _projectile
};

// [file, source, isInside, position, volume (0-5), pitch, max distance, offset, local only]
playSound3D ["885_Sounds\TX130OC.ogg", _unit, false, _muzzlePos, 4, 0.9, 2500, 0, true];

// Skip the particles when the shot is too far away to see
if ((positionCameraToWorld [0, 0, 0]) distance (ASLToAGL _muzzlePos) > 1500) exitWith {};

private _flash = "#particlesource" createVehicleLocal [0, 0, 0];
_flash setPosASL _muzzlePos;
_flash setParticleClass "885th_AM_MuzzleFlash";

private _sparks = "#particlesource" createVehicleLocal [0, 0, 0];
_sparks setPosASL _muzzlePos;
_sparks setParticleClass "885th_AM_MuzzleSparks";

private _light = "#lightpoint" createVehicleLocal [0, 0, 0];
_light setPosASL _muzzlePos;
_light setLightColor [0.3, 0.6, 1];
_light setLightAmbient [0.1, 0.25, 0.6];
_light setLightIntensity 4000;
_light setLightAttenuation [0, 0, 0, 2.2, 200, 400];
_light setLightDayLight true;

[{
    { deleteVehicle _x } forEach _this;
}, [_flash, _sparks, _light], 0.12] call CBA_fnc_waitAndExecute;
