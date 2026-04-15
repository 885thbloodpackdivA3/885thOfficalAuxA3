params ["_unit", "_killer", "_instigator", "_useEffects"];

if (isNull _unit) exitWith {};

// run sparks on all clients so everyone sees them
[_unit] remoteExec ["ATRT_fnc_atrtStartDeathSparks", 0, true];