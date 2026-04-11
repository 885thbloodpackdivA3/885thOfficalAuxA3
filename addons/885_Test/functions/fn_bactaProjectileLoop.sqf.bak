params ["_proj"];
if (isNull _proj) exitWith {};

// SINGLE SOURCE OF TRUTH — prevents ALL duplicates
if (_proj getVariable ["bacta_loopRunning", false]) exitWith {};
_proj setVariable ["bacta_loopRunning", true, true];

while { !isNull _proj } do {
  [_proj] call bacta_fnc_bactaHealArea;
  sleep (missionNamespace getVariable ["bacta_tick", 3]);
};
