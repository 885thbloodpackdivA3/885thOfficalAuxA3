/*
    Author: 885th Bloodpack Division
    BPD_fnc_vwingInit - params: [vehicle]

    Called from the CBA Init XEH on every machine (JIP included) for every
    885th V-wing. The V-wing only gets the emergency repair (no shields):
    the owner loop in XEH_postInit.sqf runs the repair and reloads the
    charges when the jet is refueled on the ground.
*/
params ["_veh"];

if (_veh getVariable ["BPD_vwing_registered", false]) exitWith {};
_veh setVariable ["BPD_vwing_registered", true];

BPD_vwing_vehicles pushBackUnique _veh;

// Only the creating machine seeds the shared state - everyone else receives it.
if (local _veh && {isNil { _veh getVariable "BPD_arc_repairCharges" }}) then {
    _veh setVariable ["BPD_arc_repairCharges", round (missionNamespace getVariable ["AUX_885th_VWING_RepairCharges", 1]), true];
    _veh setVariable ["BPD_arc_repairing", false, true];
};
