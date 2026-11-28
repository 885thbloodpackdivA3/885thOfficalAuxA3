/*
	885th - LAAT AT-RT rack: clamp nearby AT-RTs into the troop bay (pilot action).

	The Legion Studios AT-RT is a soldier (Man) class, not a vehicle, so the
	engine's vehicle-in-vehicle system (used by boxloader) can't carry it. It is
	attached to the LAAT instead, like the 3AS LAAT/C mag-lift does for vehicles.

	Arguments:
		0: OBJECT - the LAAT
*/
params ["_laat"];

private _max   = getNumber (configOf _laat >> "BPD_atrtRackMax");
private _range = 15;	// m from the middle of the bay

// Forget anything that died or got detached some other way
private _rack = (_laat getVariable ["BPD_atrtRack", []]) select {alive _x && {attachedTo _x == _laat}};
if (count _rack >= _max) exitWith {hint format ["AT-RT rack is full (%1/%1)", _max]};

private _slots = [_laat, _max] call BPD_fnc_atrtRackSlots;
private _mid = [0, 0, 0];
{_mid = _mid vectorAdd _x} forEach _slots;
_mid = _laat modelToWorld (_mid vectorMultiply (1 / count _slots));

private _candidates = (nearestObjects [_mid, ["ls_vehicle_atrt_base"], _range]) select {
	alive _x
	&& {isNull objectParent _x}
	&& {isNull attachedTo _x}
	&& {!(_x in _rack)}
};
if (_candidates isEqualTo []) exitWith {hint format ["No AT-RTs within %1 m of the troop bay", _range]};

{
	if (count _rack >= _max) then {break};
	[_x, _laat, _slots select (count _rack)] remoteExec ["BPD_fnc_atrtRackAttach", _x];
	_rack pushBack _x;
} forEach _candidates;

_laat setVariable ["BPD_atrtRack", _rack, true];
if (isClass (configFile >> "CfgSounds" >> "TAS_Clamps")) then {playSound "TAS_Clamps"};
hint format ["AT-RT rack: %1/%2 clamped", count _rack, _max];
