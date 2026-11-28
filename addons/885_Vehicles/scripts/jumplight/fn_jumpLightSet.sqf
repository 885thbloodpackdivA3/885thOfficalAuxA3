/*
	885th - LAAT jump light: set the light state on a vehicle.

	Arguments:
		0: OBJECT - the LAAT
		1: NUMBER - 0 = off, 1 = RED (stand by), 2 = GREEN (dismount)

	The state is a public object variable, so every client (and JIP players)
	sees it. Each client's BPD_fnc_jumpLightClient loop draws the cabin
	lights and the on-screen indicator from that variable - no remoteExec.
*/
params [["_veh", objNull, [objNull]], ["_state", 0, [0]]];

if (isNull _veh) exitWith {};
_state = (0 max (round _state)) min 2;

_veh setVariable ["BPD_jumpLight", _state, true];
