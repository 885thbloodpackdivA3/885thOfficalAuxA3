/*
 * 885th - Seismic Charge effects
 *
 * Lore: a seismic charge (baradium + collapsium) pulls in all sound around it for a moment,
 * then releases a blue concussive shockwave that throws people off their feet.
 *
 * 1. Sound drain: every ACE trigger path (clacker, timer, explode-on-defuse) ends in the
 *    server-side "ace_explosives_detonate" event, which carries the fuse time. The server
 *    tells every client; players nearby have their game sound drained over the fuse, then
 *    snapped back just before the blast so the explosion itself is heard at full volume.
 * 2. Shockwave: ACE's unified explosion event fires on the machine that owns the charge.
 *    That machine broadcasts the blast; every machine throws its own local units (ragdoll
 *    via addForce), and every player near it gets the flash, camera shake and blur.
 *
 * The blast damage itself is plain config (885th_explosive_seismic_ammo), so the charge
 * still works if any of this fails.
 */

#define SEISMIC_AMMO "885th_explosive_seismic_ammo"
#define DRAIN_RADIUS 150
#define KNOCK_RADIUS 30
#define FX_RADIUS 200

if (!isNil "BPD_seismic_initDone") exitWith {};
BPD_seismic_initDone = true;

// Restore game sound after a drain. Safe to call when nothing is drained.
BPD_fnc_seismicRestore = {
    if !(missionNamespace getVariable ["BPD_seismic_draining", false]) exitWith {};
    BPD_seismic_draining = false;
    0.1 fadeSound (missionNamespace getVariable ["BPD_seismic_prevVolume", 1]);
    ace_hearing_disableVolumeUpdate = missionNamespace getVariable ["BPD_seismic_prevAceLock", false];
};

// ------------------------------------------------------------------ 1. detonation requested
if (isServer) then {
    ["ace_explosives_detonate", {
        params ["", "_explosive", ["_delay", 0]];
        if (isNull _explosive || {typeOf _explosive != SEISMIC_AMMO}) exitWith {};
        ["885th_seismic_precharge", [getPosASL _explosive, _delay]] call CBA_fnc_globalEvent;
    }] call CBA_fnc_addEventHandler;
};

["885th_seismic_precharge", {
    params ["_posASL", "_delay"];
    if (!hasInterface || {isNull player}) exitWith {};
    if (_delay < 0.5) exitWith {};
    if ((getPosASL player) distance _posASL > DRAIN_RADIUS) exitWith {};
    if (missionNamespace getVariable ["BPD_seismic_draining", false]) exitWith {};

    BPD_seismic_draining = true;
    BPD_seismic_prevVolume = soundVolume;
    // ACE Hearing re-applies its own volume every second; hold it off during the drain.
    BPD_seismic_prevAceLock = missionNamespace getVariable ["ace_hearing_disableVolumeUpdate", false];
    ace_hearing_disableVolumeUpdate = true;

    ((_delay - 0.4) max 0.2) fadeSound 0.05;

    // Snap back just before the charge goes off; also a safety net if it never does.
    [BPD_fnc_seismicRestore, [], (_delay - 0.15) max 0.1] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;

// ------------------------------------------------------------------ 2. charge exploded
{
    params ["_projectile", "_posASL"];
    if (typeOf _projectile != SEISMIC_AMMO) exitWith {};
    ["885th_seismic_blast", [_posASL]] call CBA_fnc_globalEvent;
} call ace_common_fnc_addExplosionEventHandler;

["885th_seismic_blast", {
    params ["_posASL"];

    // Throw this machine's own units off their feet, away from the charge.
    {
        private _dist = (getPosASL _x) distance _posASL;
        if (_dist < KNOCK_RADIUS && {alive _x} && {isNull objectParent _x}) then {
            private _dir = _posASL vectorFromTo (getPosASL _x);
            _dir = vectorNormalized [_dir select 0, _dir select 1, 0];
            private _power = linearConversion [0, KNOCK_RADIUS, _dist, 900, 150, true];
            private _force = (_dir vectorMultiply _power) vectorAdd [0, 0, _power * 0.6];
            _x addForce [_force, _x selectionPosition "spine3"];
        };
    } forEach (allUnits select {local _x});

    if (!hasInterface || {isNull player}) exitWith {};
    call BPD_fnc_seismicRestore;

    private _dist = (getPosASL player) distance _posASL;
    if (_dist > FX_RADIUS) exitWith {};
    private _k = linearConversion [0, FX_RADIUS, _dist, 1, 0, true];

    addCamShake [4 + 16 * _k, 1.5 + 2 * _k, 18];

    // Blue flash
    private _light = "#lightpoint" createVehicleLocal (ASLToAGL _posASL);
    _light setLightColor [0.35, 0.6, 1];
    _light setLightAmbient [0.2, 0.4, 1];
    _light setLightBrightness 40;
    _light setLightAttenuation [2, 4, 4, 0, 10, FX_RADIUS];
    _light setLightDayLight true;
    [{ (_this select 0) setLightBrightness 8 }, [_light], 0.15] call CBA_fnc_waitAndExecute;
    [{ deleteVehicle (_this select 0) }, [_light], 0.6] call CBA_fnc_waitAndExecute;

    // Concussion blur when close
    if (_k > 0.3) then {
        private _pp = ppEffectCreate ["DynamicBlur", 471];
        if (_pp != -1) then {
            _pp ppEffectEnable true;
            _pp ppEffectAdjust [3 * _k];
            _pp ppEffectCommit 0;
            [{
                params ["_pp"];
                _pp ppEffectAdjust [0];
                _pp ppEffectCommit 2;
                [{ ppEffectDestroy (_this select 0) }, [_pp], 2.1] call CBA_fnc_waitAndExecute;
            }, [_pp], 0.2] call CBA_fnc_waitAndExecute;
        };
    };
}] call CBA_fnc_addEventHandler;
