/*
    Author: 885th Bloodpack Division
    BPD_fnc_repairTick - params: [vehicle, dt]

    One step of an emergency repair in progress (BPD_arc_repairing = true).
    Shared by the ARC-170 owner loop and the V-wing owner loop
    (XEH_postInit.sqf). Run only where the vehicle is local.

    Brings the hull and every component up to the repair cap (CBA
    AUX_885th_ARC_RepairCap). A fully destroyed part reaches the cap in
    AUX_885th_ARC_RepairTime seconds. Clears BPD_arc_repairing when done.
*/
params ["_veh", "_dt"];

private _floor    = 1 - (missionNamespace getVariable ["AUX_885th_ARC_RepairCap", 0.6]);
private _duration = (missionNamespace getVariable ["AUX_885th_ARC_RepairTime", 10]) max 1;
private _step     = ((1 - _floor) / _duration) * _dt;
private _elapsed  = (_veh getVariable ["BPD_arc_repairElapsed", 0]) + _dt;
_veh setVariable ["BPD_arc_repairElapsed", _elapsed];

private _vals = (getAllHitPointsDamage _veh) param [2, []];
private _hull = damage _veh;
private _done = true;

// setDamage touches the component hitpoints too, so when the
// hull moves every component is written back afterwards
private _hullMoved = _hull > _floor;
if (_hullMoved) then {
    private _newHull = (_hull - _step) max _floor;
    _veh setDamage [_newHull, false];
    if (_newHull > _floor) then { _done = false; };
};
{
    private _new = if (_x > _floor) then { (_x - _step) max _floor } else { _x };
    if (_hullMoved || {_new != _x}) then { _veh setHitIndex [_forEachIndex, _new, false]; };
    if (_new > _floor) then { _done = false; };
} forEach _vals;

if (_done || {_elapsed > (_duration * 1.5) + 2}) then {
    _veh setVariable ["BPD_arc_repairing", false, true];
    private _targets = (crew _veh) select { isPlayer _x };
    if (_targets isNotEqualTo []) then {
        [parseText format ["<t color='#7dff9a'>EMERGENCY REPAIR COMPLETE</t><br/><t size='0.8'>Systems restored to %1%2 - power returned</t>", round ((1 - _floor) * 100), "%"]]
            remoteExecCall ["hintSilent", _targets];
    };
};
