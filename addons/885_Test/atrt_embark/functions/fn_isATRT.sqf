/*
  Returns true if the unit is considered an AT-RT walker.
  - If unit config has atrt_isWalker = 1, returns true.
  - Else checks ATRT_Embark >> atrtClasses[] list.
*/

params ["_unit"];
if (isNull _unit) exitWith { false };

private _cfg = configOf _unit;
if (getNumber (_cfg >> "atrt_isWalker") == 1) exitWith { true };

private _list = getArray (configFile >> "ATRT_Embark" >> "atrtClasses");
(typeOf _unit) in _list