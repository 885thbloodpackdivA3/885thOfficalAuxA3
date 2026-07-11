// Runs the heal-tick loop for a thrown grenade. Always on the server,
// regardless of which client threw it or who owns which nearby units.
["bacta_startLoop", {
  params ["_proj"];
  [_proj] spawn bacta_fnc_bactaProjectileLoop;
}] call CBA_fnc_addEventHandler;

// Applies treatment to a single unit. Fired via targetEvent so it always
// runs on the machine that actually owns that unit (required for setDamage
// and ACE medical treatment calls to be network-safe).
["bacta_healUnit", {
  params ["_u"];
  [_u] call bacta_fnc_bactaHealUnit;
}] call CBA_fnc_addEventHandler;

["CAManBase", "FiredMan", {
  params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_mag", "_proj"];

  if (!isPlayer _unit) exitWith {};
  if (isNull _proj) exitWith {};
  if !([_mag, _ammo] call bacta_fnc_isAllowedGrenade) exitWith {};

  // Hand off to the server so the heal loop has an authoritative view of
  // every unit in the blast radius, not just ones local to the thrower.
  ["bacta_startLoop", [_proj]] call CBA_fnc_serverEvent;

}] call CBA_fnc_addClassEventHandler;
