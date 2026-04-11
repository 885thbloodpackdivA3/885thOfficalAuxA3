/*
  ATRT_fnc_embark
  - Player remains normal (NOT UAV)
  - Player CONTROL swaps via selectPlayer to the ATRT unit (man)
  - Original player unit is attached to ATRT "seat" as the visible rider
*/

params ["_atrt", "_pilot"];

if (isNull _atrt || isNull _pilot) exitWith {};
if (!alive _atrt || !alive _pilot) exitWith {};
if (_atrt getVariable ["ATRT_inUse", false]) exitWith {};
if (vehicle _pilot != _pilot) exitWith {};
if (_pilot distance _atrt > 3) exitWith {};

_atrt setVariable ["ATRT_inUse", true, true];
_atrt setVariable ["ATRT_pilot", _pilot, true];

// Seat point (model has "seat" per 3AS script)
private _seatPoint = getText (configFile >> "ATRT_Embark" >> "seatMemoryPoint");
if (_seatPoint isEqualTo "") then { _seatPoint = "seat"; };

// (Recommended MP) transfer ownership so ATRT is local to embarking client
if (isMultiplayer) then {
  [_atrt, clientOwner] remoteExecCall ["ATRT_fnc_serverTransferOwner", 2];
};

[_atrt, _pilot, _seatPoint] spawn {
  params ["_atrt", "_pilot", "_seatPoint"];

  // wait a moment for locality transfer
  private _t0 = time;
  waitUntil { uiSleep 0.01; local _atrt || (time - _t0) > 2 };

  // Freeze pilot (the visible seated rider)
  _pilot allowDamage false;
  _pilot disableAI "MOVE";
  _pilot disableAI "PATH";
  _pilot disableAI "ANIM";

  [_atrt, "Walker_Idle"] remoteExec ["SwitchMove", 0];

  // Snap + seat
  _pilot setPosATL (getPosATL _atrt);
  [_pilot, "driver_Quadbike"] remoteExec ["switchMove", 0];
  _pilot attachTo [_atrt, [0,0,0], _seatPoint];

  // Optional collision shield like 3AS (remove if you don't want it)
  private _shield = "3AS_ATRT_Collision" createVehicle (getPosATL _atrt);
  _shield attachTo [_atrt, [0.0, 0.3, -2.3], _seatPoint];
  _atrt setVariable ["ATRT_shield", _shield, true];

  // Now swap control: player becomes the ATRT character
  if (local _atrt) then {
    selectPlayer _atrt;
  };

  // Safety: if ATRT dies, disembark pilot back
  if (isNil {_atrt getVariable "ATRT_killedEH"}) then {
    private _ehId = _atrt addEventHandler ["Killed", {
      params ["_dead"];
      private _pilot = _dead getVariable ["ATRT_pilot", objNull];
      if (!isNull _pilot) then {
        [_dead] remoteExec ["ATRT_fnc_disembark", owner _pilot];
      };
    }];
    _atrt setVariable ["ATRT_killedEH", _ehId];
  };
};