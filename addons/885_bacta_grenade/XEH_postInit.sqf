// Applies treatment to a single unit. Fired via targetEvent so it always
// runs on the machine that actually owns that unit (required for setDamage
// and ACE medical treatment calls to be network-safe).
["bacta_healUnit", {
  params ["_u"];
  [_u] call bacta_fnc_bactaHealUnit;
}] call CBA_fnc_addEventHandler;

// FiredMan fires on every machine that simulates the throw, and each machine
// gets its OWN local copy of the grenade projectile (projectiles aren't
// networked objects). Only the thrower's machine runs the heal loop, using
// its own projectile, so there is exactly one loop per grenade.
["CAManBase", "FiredMan", {
  params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_mag", "_proj"];

  if (!local _unit) exitWith {};
  if (!isPlayer _unit) exitWith {};
  if (isNull _proj) exitWith {};
  if !([_mag, _ammo] call bacta_fnc_isAllowedGrenade) exitWith {};

  [_proj] spawn bacta_fnc_bactaProjectileLoop;
}] call CBA_fnc_addClassEventHandler;
