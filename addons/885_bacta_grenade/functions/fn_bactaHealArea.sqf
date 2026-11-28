// Runs on the thrower's machine (called from fn_bactaProjectileLoop.sqf).
// Finds every player in radius, then hands each unit off to its own owning
// machine to actually be treated.
params ["_center"];

private _radius = missionNamespace getVariable ["bacta_radius", 10];

{
  private _u = _x;
  if (isPlayer _u && {alive _u}) then {
    ["bacta_healUnit", [_u], _u] call CBA_fnc_targetEvent;
  };
} forEach (_center nearEntities ["CAManBase", _radius]);
