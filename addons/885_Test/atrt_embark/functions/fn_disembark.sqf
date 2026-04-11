/*
  ATRT_fnc_disembark
  - Must be called on the client currently controlling the ATRT (player == atrt)
*/

params ["_atrt"];
if (isNull _atrt) exitWith {};
if (!(player == _atrt)) exitWith {};   // only the controlling client should run this

private _pilot = _atrt getVariable ["ATRT_pilot", objNull];
if (isNull _pilot) exitWith {
  _atrt setVariable ["ATRT_inUse", false, true];
};
_atrt setunitPos "MIDDLE";

// Switch control back
selectPlayer _pilot;

// Unseat pilot
[_pilot, ""] remoteExec ["switchMove", 0];
detach _pilot;

// Place pilot near ATRT
private _offset = getArray (configFile >> "ATRT_Embark" >> "dismountOffset");
if (_offset isEqualTo []) then { _offset = [0, 2.0, 0]; };

private _pos = _atrt modelToWorld _offset;
_pos set [2, 0];
_pilot setPosATL _pos;
_pilot setDir (getDir _atrt);

// Shield cleanup (if used)
private _shield = _atrt getVariable ["ATRT_shield", objNull];
if (!isNull _shield) then { deleteVehicle _shield; };
_atrt setVariable ["ATRT_shield", objNull, true];

// Restore pilot
_pilot enableAI "MOVE";
_pilot enableAI "PATH";
_pilot enableAI "ANIM";
_pilot allowDamage true;

// Unlock ATRT
_atrt setVariable ["ATRT_pilot", objNull, true];
_atrt setVariable ["ATRT_inUse", false, true];