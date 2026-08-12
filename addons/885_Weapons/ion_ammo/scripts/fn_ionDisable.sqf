/*
    885th Ion Disruptor - Vehicle Disable Script
    fn_ionDisable.sqf

    Called via HitPart EH on the ion projectile.
    Runs on server only (FiredMan EH only registered server-side).
    AI vehicles only — skips anything with a player inside.

    Parameters:
        _projectile : Object - the ion bolt
        _target     : Object - the vehicle that was hit
*/

params ["_projectile", "_target"];

// --- SAFETY CHECKS ---
if (isNull _target)  exitWith { diag_log "885th ION: exit - null target"; };
if (!isServer)       exitWith { diag_log "885th ION: exit - not server"; };

// Vehicle type check
if !(_target isKindOf "LandVehicle"
  || _target isKindOf "Air"
  || _target isKindOf "Ship") exitWith
{
    diag_log format ["885th ION: exit - not a vehicle typeOf=%1", typeOf _target];
};

// Skip if already disabled — prevents stacking from burst fire
if (_target getVariable ["BP_IonDisabled", false]) exitWith
{
    diag_log "885th ION: exit - already disabled";
};

// AI only — skip if any player is crew or cargo
if ({ isPlayer _x } count (crew _target) > 0)           exitWith { diag_log "885th ION: exit - player in crew"; };
if ({ isPlayer _x } count (assignedCargo _target) > 0)  exitWith { diag_log "885th ION: exit - player in cargo"; };

diag_log format ["885th ION: Disabling %1 (%2)", _target, typeOf _target];

// --- APPLY DISABLE ---
_target setVariable ["BP_IonDisabled", true, true];

private _engineDamage = damage _target;

_target engineOn false;
_target setFuel 0;
_target setHitPointDamage ["HitEngine", 0.95];

if (_target isKindOf "Air") then
{
    _target setHitPointDamage ["HitAvionics", 0.95];
};

_target setVehicleAmmo 0.15;

{
    _x disableAI "TARGET";
    _x disableAI "AUTOTARGET";
    _x disableAI "MOVE";
} forEach (crew _target);

// --- HOLD LOOP + RECOVERY ---
[_target, _engineDamage] spawn
{
    params ["_veh", "_oldDamage"];

    private _startTime = time;
    private _duration  = 30;

    // Continuous velocity lock for the disable duration
    while {
        time - _startTime < _duration
        && !isNull _veh
        && alive _veh
        // Mid-disable safety — release immediately if a player boards
        && { isPlayer _x } count (crew _veh) == 0
    } do
    {
        _veh engineOn false;
        _veh setVelocity [0, 0, 0];
        _veh setVelocityModelSpace [0, 0, 0];

        if (_veh isKindOf "Air") then
        {
            _veh setVelocity [0, 0, -0.1];
        };

        sleep 0.1;
    };

    // --- RECOVERY ---
    if (!isNull _veh && { alive _veh }) then
    {
        _veh setFuel 1;
        _veh setHitPointDamage ["HitEngine", _oldDamage];

        if (_veh isKindOf "Air") then
        {
            _veh setHitPointDamage ["HitAvionics", 0];
        };

        _veh engineOn true;

        {
            _x enableAI "TARGET";
            _x enableAI "AUTOTARGET";
            _x enableAI "MOVE";
        } forEach (crew _veh);

        _veh setVariable ["BP_IonDisabled", false, true];

        diag_log format ["885th ION: %1 recovered after %2s", _veh, _duration];
    };
};
