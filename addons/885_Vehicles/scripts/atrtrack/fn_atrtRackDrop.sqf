/*
	885th - LAAT AT-RT rack: release every racked AT-RT (pilot action).

	Arguments:
		0: OBJECT - the LAAT
*/
params ["_laat"];

private _rack = (_laat getVariable ["BPD_atrtRack", []]) select {!isNull _x};
{
	[_x] remoteExec ["BPD_fnc_atrtRackRelease", _x];
} forEach _rack;

_laat setVariable ["BPD_atrtRack", [], true];
if (isClass (configFile >> "CfgSounds" >> "TAS_Clamps")) then {playSound "TAS_Clamps"};
hint format ["AT-RT rack: %1 released", count _rack];
