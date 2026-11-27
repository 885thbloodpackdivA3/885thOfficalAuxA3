params ["_magClass", "_ammoClass"];

private _raw = missionNamespace getVariable ["bacta_allowedGrenades", ""];
private _list = (_raw splitString ",;") apply { toLower (trim _x) };
_list = _list select { _x != "" };

// Empty list => allow nothing (safe default)
if ((count _list) == 0) exitWith { false };

private _magL  = toLower _magClass;
private _ammoL = toLower _ammoClass;

if (_magL in _list) exitWith { true };
if (_ammoL in _list) exitWith { true };

// Inheritance match (works for base classes like SmokeShell).
// exitWith inside forEach only leaves the loop, so the result is the
// findIf index rather than a value returned from inside the loop.
private _cfgMags = configFile >> "CfgMagazines";
private _cfgAmmo = configFile >> "CfgAmmo";

(_list findIf {
  (_magClass isKindOf [_x, _cfgMags]) || {_ammoClass isKindOf [_x, _cfgAmmo]}
}) != -1
