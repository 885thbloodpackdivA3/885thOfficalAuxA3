/*
	885th - LAAT AT-RT rack: model-space positions the racked AT-RTs are clamped at.

	Uses the LAAT/i troop bay box (memory points Limit1 / limit2 - the same points
	3AS uses for the bay's vehicle-in-vehicle cargoBayDimensions). The bay is split
	front-to-back into one slot per AT-RT, centred side-to-side, feet on the floor.

	Arguments:
		0: OBJECT - the LAAT
		1: NUMBER - how many slots
	Returns: ARRAY of [x,y,z] model offsets, front slot first
*/
params ["_laat", ["_count", 2]];

// --- Tunables ---------------------------------------------------------------
private _zAdjust  = 0;		// m - raise/lower the AT-RTs if they float or sink into the floor
private _fallback = [[0, 1.5, -1.6], [0, -1.5, -1.6]];	// used if the model lacks the bay points
// ----------------------------------------------------------------------------

private _a = _laat selectionPosition ["Limit1", "Memory"];
private _b = _laat selectionPosition ["limit2", "Memory"];
if (_a isEqualTo [0, 0, 0] || {_b isEqualTo [0, 0, 0]}) exitWith {
	_fallback select [0, _count]
};

private _x0   = ((_a select 0) + (_b select 0)) / 2;
private _yMin = (_a select 1) min (_b select 1);
private _yMax = (_a select 1) max (_b select 1);
private _z    = ((_a select 2) min (_b select 2)) + _zAdjust;
private _len  = _yMax - _yMin;

private _slots = [];
for "_i" from 0 to (_count - 1) do {
	_slots pushBack [_x0, _yMax - _len * (_i + 0.5) / _count, _z];
};
_slots
