/*
	885th - LAAT AT-RT rack: action conditions (kept cheap - runs every frame).

	Arguments:
		0: OBJECT - the LAAT
		1: STRING - "load" (pilot/co-pilot, rack not full, near stopped)
		            "drop" (pilot/co-pilot, something racked, low and slow)
		            "self" (the local AT-RT is racked in this LAAT, LAAT low and slow)
	Returns: BOOL
*/
params ["_laat", ["_mode", "load"]];

if (!alive _laat) exitWith {false};

private _lowSlow = {((getPos _laat) select 2) < 6 && {speed _laat < 15}};

switch (_mode) do {
	case "load": {
		speed _laat < 10
		&& {count (_laat getVariable ["BPD_atrtRack", []]) < getNumber (configOf _laat >> "BPD_atrtRackMax")}
		&& {[_laat] call BPD_fnc_jumpLightCanUse}
	};
	case "drop": {
		!((_laat getVariable ["BPD_atrtRack", []]) isEqualTo [])
		&& {[_laat] call BPD_fnc_jumpLightCanUse}
		&& _lowSlow
	};
	case "self": {
		private _unit = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];
		if (isNull _unit) then {_unit = player};
		attachedTo _unit == _laat
		&& {(_unit getVariable ["BPD_atrtRack_laat", objNull]) == _laat}
		&& _lowSlow
	};
	default {false};
};
