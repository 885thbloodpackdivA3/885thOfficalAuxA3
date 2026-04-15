/*
  Returns nearest usable AT-RT near the player within a radius.
*/

params [["_radius", 4]];

if (!hasInterface) exitWith { objNull };
if (isNull player) exitWith { objNull };
if (!alive player) exitWith { objNull };
if (vehicle player != player) exitWith { objNull };

private _candidates = (nearestObjects [player, ["CAManBase"], _radius, true]) select {
  alive _x
  && { [_x] call ATRT_fnc_isATRT }
  && { !(_x getVariable ["ATRT_inUse", false]) }
};

if (_candidates isEqualTo []) exitWith { objNull };

// Sort by distance
_candidates sort true; // not enough by itself for distance sorting in SQF arrays of objects

private _nearest = objNull;
private _best = 1e10;
{
  private _d = player distance _x;
  if (_d < _best) then {
    _best = _d;
    _nearest = _x;
  };
} forEach _candidates;

_nearest