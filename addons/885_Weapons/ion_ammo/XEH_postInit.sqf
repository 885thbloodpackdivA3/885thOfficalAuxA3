/*
    885th Ion Disruptor - Post-Initialization
    XEH_postInit.sqf

    Handles SP, hosted MP, and dedicated server.
    FiredMan EH added to all units to catch ion bolt hits.
    Lightweight — no per-frame loops, no polling.
*/

diag_log format ["885th ION: XEH_postInit started. isServer=%1 hasInterface=%2 isDedicated=%3", isServer, hasInterface, isDedicated];

// Only run the detection system on the server (covers SP and dedic)
if (!isServer) exitWith
{
    diag_log "885th ION: Not server - exiting postInit";
};

// --- FUNCTION: Add FiredMan EH to a single unit ---
private _fnc_addIonEH =
{
    params ["_unit"];
    if (_unit getVariable ["885th_ion_firedEH_added", false]) exitWith {};
    _unit setVariable ["885th_ion_firedEH_added", true];

    _unit addEventHandler ["FiredMan",
    {
        params ["_unit","_weapon","_muzzle","_mode","_ammo","_magazine","_projectile","_gunner"];
        if (_ammo != "885th_blasterbolt_ION") exitWith {};

        _projectile addEventHandler ["HitPart",
        {
            params ["_projectile","_target","_shooter","_pos","_vel","_normal","_surfaceType","_isWater","_deflected","_hitParts"];
            private _veh = vehicle _target;
            diag_log format ["885th ION DEBUG: HitPart fired. Target=%1 typeOf=%2", _veh, typeOf _veh];
            [_projectile, _veh] execVM "885_Weapons\ion_ammo\scripts\fn_ionDisable.sqf";
        }];
    }];
};

// --- STEP 1: Add EH to all units already on the map ---
{
    [_x] call _fnc_addIonEH;
} forEach allUnits;

diag_log format ["885th ION: FiredMan EH added to %1 existing units", count allUnits];

// --- STEP 2: Watch for new units joining mid-mission ---
// EntityCreated fires for every new object — filter to Man only
addMissionEventHandler ["EntityCreated",
{
    params ["_entity"];
    // Only care about infantry units, not vehicles or objects
    if !(_entity isKindOf "Man") exitWith {};

    // Slight delay so the unit is fully initialised before we touch it
    [{
        params ["_unit"];
        if (isNull _unit) exitWith {};
        if (!(_unit getVariable ["885th_ion_firedEH_added", false])) then
        {
            _unit setVariable ["885th_ion_firedEH_added", true];
            _unit addEventHandler ["FiredMan",
            {
                params ["_unit","_weapon","_muzzle","_mode","_ammo","_magazine","_projectile","_gunner"];
                if (_ammo != "885th_blasterbolt_ION") exitWith {};

                _projectile addEventHandler ["HitPart",
                {
                    params ["_projectile","_target","_shooter","_pos","_vel","_normal","_surfaceType","_isWater","_deflected","_hitParts"];
                    private _veh = vehicle _target;
                    diag_log format ["885th ION DEBUG: HitPart fired. Target=%1 typeOf=%2", _veh, typeOf _veh];
                    [_projectile, _veh] execVM "885_Weapons\ion_ammo\scripts\fn_ionDisable.sqf";
                }];
            }];
        };
    }, [_entity], 0.5] call CBA_fnc_waitAndExecute;
}];

// --- STEP 3: Clean up BP_IonDisabled on vehicle death ---
// Prevents stale state on respawned vehicles
addMissionEventHandler ["EntityKilled",
{
    params ["_entity"];
    if (_entity getVariable ["BP_IonDisabled", false]) then
    {
        _entity setVariable ["BP_IonDisabled", false, true];
        diag_log format ["885th ION: Cleaned up ion state on killed entity %1", _entity];
    };
}];

diag_log "885th ION: XEH_postInit complete";
