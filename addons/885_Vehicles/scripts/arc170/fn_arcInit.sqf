/*
    Author: 885th Bloodpack Division
    BPD_fnc_arcInit - params: [vehicle]

    Called from the CBA Init XEH, which runs on EVERY machine (JIP included)
    for every 885th ARC-170. HandleDamage only ever fires on the machine where
    the vehicle is local, and the aircraft's owner changes whenever a new pilot
    takes it - so the handler goes on everywhere and the owning machine is the
    one that actually uses it.
*/
params ["_veh"];

if (_veh getVariable ["BPD_arc_registered", false]) exitWith {};
_veh setVariable ["BPD_arc_registered", true];

BPD_arc_vehicles pushBackUnique _veh;

_veh addEventHandler ["HandleDamage", { _this call BPD_fnc_arcHandleDamage }];

// Only the creating machine seeds the shared state - everyone else receives it.
if (local _veh && {isNil { _veh getVariable "BPD_arc_shield" }}) then {
    private _max = missionNamespace getVariable ["AUX_885th_ARC_ShieldMax", 1];
    _veh setVariable ["BPD_arc_shield", _max, true];
    _veh setVariable ["BPD_arc_power", 0, true];   // 0 balanced, 1 shields, 2 engines
    _veh setVariable ["BPD_arc_broken", false, true];
    _veh setVariable ["BPD_arc_repairCharges", round (missionNamespace getVariable ["AUX_885th_ARC_RepairCharges", 2]), true];
    _veh setVariable ["BPD_arc_repairing", false, true];
};
