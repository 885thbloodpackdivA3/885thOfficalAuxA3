/*
	885th - LAAT AT-RT rack: attach one AT-RT (runs where the AT-RT is local).

	Arguments:
		0: OBJECT - the AT-RT unit
		1: OBJECT - the LAAT
		2: ARRAY  - model-space offset in the LAAT
*/
params ["_unit", "_laat", "_offset"];

if (!local _unit || {!alive _unit} || {!alive _laat}) exitWith {};

_unit attachTo [_laat, _offset];
_unit setDir 0;		// relative to the LAAT: face forward
_unit setVariable ["BPD_atrtRack_laat", _laat, true];

// Watch for the LAAT dying / being deleted, or the AT-RT being released
[_unit, _laat] spawn {
	params ["_unit", "_laat"];
	waitUntil {
		sleep 0.5;
		isNull _unit || {!alive _unit} || {!alive _laat} || {attachedTo _unit != _laat}
	};
	if (!isNull _unit) then {
		if (!isNull attachedTo _unit && {attachedTo _unit == _laat}) then {
			[_unit] call BPD_fnc_atrtRackRelease;	// LAAT destroyed with us aboard
		};
		_unit setVariable ["BPD_atrtRack_laat", objNull, true];
	};
	if (!isNull _laat) then {
		_laat setVariable ["BPD_atrtRack", (_laat getVariable ["BPD_atrtRack", []]) - [_unit, objNull], true];
	};
};
