/*
    885th Ion Disruptor - Disable Function
    fn_ionDisable.sqf

    Called directly wherever the hit is detected (any client, host,
    or AI-owning machine) - no server routing needed. setFuel,
    engineOn, setHitPointDamage, setVelocity, and setVehicleAmmo are
    all Global Effect commands: the engine syncs them to everyone
    automatically regardless of which machine calls them. Only
    disableAI is local-effect-only, so it's a bonus when it lands on
    the owning machine and harmless when it doesn't.

    Params:
        _projectile : Object - the ion bolt
        _target     : Object - whatever HitPart resolved to
        _pos        : Array  - impact position, used as a fallback
                                search point if _target doesn't
                                resolve cleanly to a vehicle
*/

params ["_projectile", "_target", ["_pos", [0,0,0]]];

diag_log format ["885th ION: ionDisable called. target=%1 pos=%2", _target, _pos];

// --- RESOLVE THE ACTUAL VEHICLE ---
private _veh = vehicle _target;

if !(_veh isKindOf "LandVehicle" || _veh isKindOf "Air" || _veh isKindOf "Ship") then
{
    private _nearVehicles = (nearestObjects [_pos, ["LandVehicle","Air","Ship"], 5])
        select { !(_x isKindOf "Man") };

    if (count _nearVehicles > 0) then
    {
        _veh = _nearVehicles select 0;
        diag_log format ["885th ION: Fallback search found vehicle %1 near impact", _veh];
    };
};

if (isNull _veh) exitWith
{
    diag_log "885th ION: exit - null target after fallback search";
};
if !(_veh isKindOf "LandVehicle" || _veh isKindOf "Air" || _veh isKindOf "Ship") exitWith
{
    diag_log format ["885th ION: exit - not a vehicle typeOf=%1", typeOf _veh];
    systemChat "[885th ION] Target was not a vehicle.";
};
if (_veh getVariable ["BP_IonDisabled", false]) exitWith
{
    diag_log "885th ION: exit - already disabled";
};
if ({ isPlayer _x } count (crew _veh) > 0) exitWith
{
    diag_log "885th ION: exit - player in crew";
};
if ({ isPlayer _x } count (assignedCargo _veh) > 0) exitWith
{
    diag_log "885th ION: exit - player in cargo";
};

diag_log format ["885th ION: Disabling %1 (%2)", _veh, typeOf _veh];
systemChat format ["[885th ION] Disabling %1", typeOf _veh];

_veh setVariable ["BP_IonDisabled", true, true];
private _engineDamage = damage _veh;

_veh engineOn false;
_veh setFuel 0;
_veh setHitPointDamage ["HitEngine", 0.95];
if (_veh isKindOf "Air") then { _veh setHitPointDamage ["HitAvionics", 0.95]; };
_veh setVehicleAmmo 0.15;

{
    _x disableAI "TARGET";
    _x disableAI "AUTOTARGET";
    _x disableAI "MOVE";
} forEach (crew _veh);

// --- FLEE BEHAVIOR ---
// Watch for crew dismounting the disabled vehicle and send them
// running away on foot instead of standing still.
{
    private _crewMan = _x;
    [_veh, _crewMan] spawn
    {
        params ["_v", "_unit"];

        waitUntil
        {
            sleep 0.5;
            isNull _unit
            || !alive _unit
            || (vehicle _unit) != _v
            || !(_v getVariable ["BP_IonDisabled", false])
        };

        if (!isNull _unit && { alive _unit } && { vehicle _unit == _unit }) then
        {
            diag_log format ["885th ION: %1 dismounted disabled vehicle - fleeing", _unit];

            _unit enableAI "MOVE";
            _unit enableAI "PATH";
            _unit enableAI "ANIM";
            _unit disableAI "TARGET";
            _unit disableAI "AUTOTARGET";

            private _fleeDir = random 360;
            private _fleePos = (getPosATL _v) getPos [80 + random 60, _fleeDir];

            _unit setUnitPos "UP";
            _unit doMove _fleePos;
            _unit setSpeedMode "FULL";
            _unit setBehaviour "AWARE";

            [_unit, _fleePos] spawn
            {
                params ["_u", "_p"];
                private _tries = 0;
                waitUntil
                {
                    sleep 1;
                    _tries = _tries + 1;
                    isNull _u
                    || !alive _u
                    || (_u distance _p < 10)
                    || _tries > 30
                };

                if (!isNull _u && { alive _u } && { !(_u getVariable ["885th_ion_fleeing_done", false]) }) then
                {
                    _u setVariable ["885th_ion_fleeing_done", true];
                    _u enableAI "TARGET";
                    _u enableAI "AUTOTARGET";
                    diag_log format ["885th ION: %1 finished fleeing, AI restored", _u];
                };
            };
        };
    };
} forEach (crew _veh);

[_veh, _engineDamage] spawn
{
    params ["_v", "_oldDmg"];
    private _startTime = time;
    private _duration  = 30;

    while {
        time - _startTime < _duration
        && { !isNull _v }
        && { alive _v }
        && { ({ isPlayer _x } count (crew _v)) == 0 }
    } do
    {
        _v engineOn false;
        _v setVelocity [0, 0, 0];
        _v setVelocityModelSpace [0, 0, 0];
        if (_v isKindOf "Air") then { _v setVelocity [0, 0, -0.1]; };
        sleep 0.1;
    };

    if (!isNull _v && { alive _v }) then
    {
        _v setFuel 1;
        _v setHitPointDamage ["HitEngine", _oldDmg];
        if (_v isKindOf "Air") then { _v setHitPointDamage ["HitAvionics", 0]; };
        _v engineOn true;

        {
            _x enableAI "TARGET";
            _x enableAI "AUTOTARGET";
            _x enableAI "MOVE";
        } forEach (crew _v);

        _v setVariable ["BP_IonDisabled", false, true];
        diag_log format ["885th ION: %1 recovered", _v];
        systemChat format ["[885th ION] %1 recovered.", typeOf _v];
    };
};
