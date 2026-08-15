/*
    885th Ion Disruptor - Post-Initialization
    XEH_postInit.sqf

    VERSION MARKER: v10-clientside-flee

    fn_ionDisable.sqf is compiled here via preprocessFileLineNumbers
    (not CfgFunctions/compileFinal) and called DIRECTLY wherever the
    hit is detected - no server routing, no publicVariable bridge,
    no remoteExec of custom functions. The disable commands are all
    Global Effect and sync themselves natively, so this behaves the
    same in singleplayer, hosted MP, Zeus/Virtual Arsenal, and
    dedicated servers with zero mode-specific code paths.
*/

diag_log "885th ION: === VERSION v10-clientside-flee LOADED ===";
diag_log format ["885th ION: XEH_postInit started. isServer=%1 hasInterface=%2 isDedicated=%3",
    isServer, hasInterface, isDedicated];

// --- COMPILE THE DISABLE FUNCTION FROM ITS OWN FILE ---
BPD_fnc_ionDisable = compile preprocessFileLineNumbers "885_Weapons\ion_ammo\scripts\functions\fn_ionDisable.sqf";

// --- SHARED: ADD FiredMan+HitPart TO A UNIT ---
BPD_fnc_addIonEH =
{
    params ["_unit"];
    if (isNull _unit)          exitWith {};
    if !(_unit isKindOf "Man") exitWith {};

    _unit addEventHandler ["FiredMan",
    {
        params ["_unit","_weapon","_muzzle","_mode","_ammo","_magazine","_projectile","_gunner"];
        if (_ammo != "885th_blasterbolt_ION") exitWith {};

        systemChat "[885th ION] Ion bolt fired.";
        diag_log format ["885th ION DEBUG: FiredMan triggered. ammo=%1 unit=%2", _ammo, _unit];

        _projectile addEventHandler ["HitPart",
        {
            params ["_projectile","_target","_shooter","_pos","_vel","_normal","_surfaceType","_isWater","_deflected","_hitParts"];
            systemChat format ["[885th ION] Hit detected on %1", typeOf (vehicle _target)];
            diag_log format ["885th ION DEBUG: HitPart fired. target=%1 pos=%2", vehicle _target, _pos];
            [_projectile, _target, _pos] call BPD_fnc_ionDisable;
        }];
    }];
};

// --- AI: register for all currently local units ---
if (isServer) then
{
    {
        if (!isPlayer _x && { local _x } && { !(_x getVariable ["885th_ion_firedEH_added", false]) }) then
        {
            _x setVariable ["885th_ion_firedEH_added", true];
            [_x] call BPD_fnc_addIonEH;
        };
    } forEach allUnits;

    diag_log format ["885th ION: AI FiredMan pass checked %1 units", count allUnits];

    addMissionEventHandler ["EntityCreated",
    {
        params ["_entity"];
        if !(_entity isKindOf "Man") exitWith {};
        if (isPlayer _entity) exitWith {};

        [{
            params ["_unit"];
            if (!isNull _unit && { local _unit } && { !(_unit getVariable ["885th_ion_firedEH_added", false]) }) then
            {
                _unit setVariable ["885th_ion_firedEH_added", true];
                [_unit] call BPD_fnc_addIonEH;
            };
        }, [_entity], 0.5] call CBA_fnc_waitAndExecute;
    }];

    addMissionEventHandler ["EntityKilled",
    {
        params ["_entity"];
        if (_entity getVariable ["BP_IonDisabled", false]) then
        {
            _entity setVariable ["BP_IonDisabled", false, true];
        };
    }];
};

// --- PLAYERS: each client registers on its own local player unit ---
BPD_fnc_registerPlayerIonEH =
{
    private _p = player;
    if (isNull _p) exitWith {};
    if (_p getVariable ["885th_ion_firedEH_added", false]) exitWith {};

    _p setVariable ["885th_ion_firedEH_added", true];
    [_p] call BPD_fnc_addIonEH;
    diag_log format ["885th ION: Player FiredMan registered on %1", _p];
};

if (hasInterface) then
{
    [] spawn
    {
        waitUntil { !isNull player };
        call BPD_fnc_registerPlayerIonEH;
    };

    addMissionEventHandler ["EntityRespawned",
    {
        params ["_newUnit", "_oldUnit"];
        if (_newUnit == player) then
        {
            call BPD_fnc_registerPlayerIonEH;
        };
    }];
};

diag_log "885th ION: XEH_postInit complete";
