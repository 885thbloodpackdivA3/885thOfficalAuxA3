/*
	885th - LAAT jump light: may the local player work the jump light switch?

	True for the pilot and for a co-pilot seat (turret with isCopilot = 1).
	Respects Zeus remote control (uses the controlled unit, like ls_player).

	Arguments:
		0: OBJECT - the LAAT
	Returns: BOOL
*/
params [["_veh", objNull, [objNull]]];

if (isNull _veh || {!alive _veh}) exitWith {false};

private _unit = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];
if (isNull _unit) then {_unit = player};
if (objectParent _unit != _veh) exitWith {false};
if (_unit == driver _veh) exitWith {true};

private _turret = _veh unitTurret _unit;
if (_turret isEqualTo [] || {_turret isEqualTo [-1]}) exitWith {false};

getNumber (([_veh, _turret] call BIS_fnc_turretConfig) >> "isCopilot") == 1
