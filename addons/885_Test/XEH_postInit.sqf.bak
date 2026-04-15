["CAManBase", "FiredMan", {
  params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_mag", "_proj"];

  if (!isPlayer _unit) exitWith {};
  if (isNull _proj) exitWith {};
  if !([_mag, _ammo] call bacta_fnc_isAllowedGrenade) exitWith {};

  [_proj] spawn bacta_fnc_bactaProjectileLoop;

}] call CBA_fnc_addClassEventHandler;
