/*
    885th Ion Disruptor - Post-Initialization
    XEH_postInit.sqf
    Runs on all machines after the mission has started.
*/

diag_log format ["885th ION: XEH_postInit started. isServer=%1 hasInterface=%2", isServer, hasInterface];

// Server-side: detect ion bolt hits using a fired EH on all units
// This bypasses ACE overriding the ammo hit EventHandler
if (isServer) then
{
    // Watch for any unit firing the ion ammo and add a hit EH to the projectile
    addMissionEventHandler ["EachFrame",
    {
        // Lightweight check - only scan when needed
    }];

    // Use CBA's projectile EH approach - add fired EH to all existing and new units
    [
        {
            // Runs for every entity on server
            {
                if (!(_x getVariable ["885th_ion_firedEH_added", false])) then
                {
                    _x setVariable ["885th_ion_firedEH_added", true];
                    _x addEventHandler ["FiredMan",
                    {
                        params ["_unit","_weapon","_muzzle","_mode","_ammo","_magazine","_projectile","_gunner"];
                        if (_ammo == "885th_blasterbolt_r_b_ION") then
                        {
                            _projectile addEventHandler ["HitPart",
                            {
                                params ["_projectile","_target","_shooter","_pos","_vel","_normal","_surfaceType","_isWater","_deflected","_hitParts"];
                                diag_log format ["885th ION DEBUG: HitPart fired. Target=%1 typeOf=%2", _target, typeOf _target];
                                [_projectile, vehicle _target] execVM "885th_ion_ammo\scripts\fn_ionDisable.sqf";
                            }];
                        };
                    }];
                };
            } forEach allUnits;
        },
        [],
        5,
        0,
        false,
        true
    ] call CBA_fnc_waitAndExecute;

    // EntityKilled cleanup
    addMissionEventHandler ["EntityKilled",
    {
        params ["_entity"];
        if (_entity getVariable ["BP_IonDisabled", false]) then
        {
            diag_log format ["885th ION: Disabled vehicle killed - cleaning vars on %1", _entity];
            _entity setVariable ["BP_IonDisabled", false, true];
        };
    }];

    diag_log "885th ION: FiredMan EH registration scheduled";
};

// Client HUD hint for nearby disabled vehicles
if (hasInterface) then
{
    [] spawn
    {
        private _lastNotified = [];
        while { true } do
        {
            sleep 1;
            private _nearDisabled = vehicles select
            {
                _x getVariable ["BP_IonDisabled", false] &&
                { _x distance player < 50 }
            };
            if (count _nearDisabled > 0 && { !(_nearDisabled isEqualTo _lastNotified) }) then
            {
                hint parseText "<t color='#00aaff' size='1.2'>ION STRIKE</t><br/>Vehicle systems disabled";
                _lastNotified = _nearDisabled;
            };
        };
    };

    diag_log "885th ION: Client hint loop started";
};

diag_log "885th ION: XEH_postInit complete";
