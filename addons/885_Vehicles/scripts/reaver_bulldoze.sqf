/*
 * [885th] Reaver Technical: knock down trees and bushes in front of the vehicle while it drives forward.
 * Started from the Reaver's postInit on every machine; only the machine where the Reaver is local acts,
 * so it keeps working when the driver (and locality) changes.
 *
 * Arguments:
 * 0: Reaver <OBJECT>
 */
params [["_veh", objNull, [objNull]]];
if (isNull _veh) exitWith {};

private _minSpeed = 5;		// km/h, forward only (speed is negative in reverse)
private _types = ["TREE", "SMALL TREE", "BUSH"];

// Front edge and half width of the hull, measured once
private _bb = boundingBoxReal _veh;
private _frontY = (_bb select 1) select 1;
private _radius = (((_bb select 1) select 0) - ((_bb select 0) select 0)) / 2 + 1;

while {alive _veh} do {
	if (local _veh && {speed _veh > _minSpeed}) then {
		private _pos = _veh modelToWorld [0, _frontY + 1.5, 0];
		{
			if (damage _x < 1) then { _x setDamage 1 };	// tree falls over
		} forEach (nearestTerrainObjects [_pos, _types, _radius, false, true]);
	};
	sleep 0.2;
};
