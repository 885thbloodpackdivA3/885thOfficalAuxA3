/*
	885th - LAAT AT-RT rack: release one AT-RT (runs where the AT-RT is local).
	Short damage immunity so the drop out of a low hover doesn't hurt.

	Arguments:
		0: OBJECT - the AT-RT unit
*/
params ["_unit"];

if (isNull _unit || {!local _unit}) exitWith {};

_unit allowDamage false;
detach _unit;
_unit setVelocity [0, 0, -1];
_unit setVariable ["BPD_atrtRack_laat", objNull, true];

[_unit] spawn {
	params ["_unit"];
	sleep 3;
	if (!isNull _unit) then {_unit allowDamage true};
};
