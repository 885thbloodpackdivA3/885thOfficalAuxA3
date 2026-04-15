params ["_atrt"];
if (isNull _atrt) exitWith {};

if (_atrt getVariable ["ATRT_hasActions", false]) exitWith {};
_atrt setVariable ["ATRT_hasActions", true];

_atrt setVariable ["ATRT_inUse", false, true];
_atrt setVariable ["ATRT_pilot", objNull, true];

// Embark
_atrt addAction [
  "Embark AT-RT",
  {
    params ["_target", "_caller"];
    [_target, _caller] call ATRT_fnc_embark;
  },
  nil,
  1.5,
  true,
  true,
  "",
  "alive _target && alive _this && !(_target getVariable ['ATRT_inUse', false]) && vehicle _this == _this && (_this distance _target) < 3"
];


// Disembark (only shown when you are controlling the AT-RT unit)
_atrt addAction [
  "Disembark AT-RT",
  {
    params ["_target", "_caller"];
    [_target] call ATRT_fnc_disembark;
  },
  nil,
  1.5,
  true,
  true,
  "",
  "alive _target && (player == _target) && (_target getVariable ['ATRT_inUse', false])"
];