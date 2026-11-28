/*
    Author: 885th Bloodpack Division
    BPD_fnc_arcRepair - params: [vehicle]

    Pilot-triggered emergency repair. Starts a gradual repair that brings the
    hull and every component (engine, controls, fuel, avionics...) back up to
    the repair cap (default 60% health). Anything already healthier than the
    cap is left alone - this is a get-home fix, not a full repair.

    The actual repairing happens in the owner loop (XEH_postInit.sqf) on
    whichever machine owns the jet, so it keeps going if ownership changes.
    While it runs, reactor power goes to the repair: no shield recharge and
    no engine boost.

    ARC-170 charges (default 2) are reloaded by refueling through FIR's AMS -
    see fn_arcAMSRefuel.sqf. The V-wing uses this too (default 1 charge,
    reloaded by any refuel while landed - V-wing loop in XEH_postInit.sqf).
*/
params ["_veh"];

private _isARC = _veh getVariable ["BPD_arc_registered", false];

if !(missionNamespace getVariable ["AUX_885th_ARC_RepairEnabled", true]) exitWith {};
// the ARC owner loop that performs its repair only runs with the shield master switch on
if (_isARC && {!(missionNamespace getVariable ["AUX_885th_ARC_Enabled", true])}) exitWith {};
if (_veh getVariable ["BPD_arc_repairing", false]) exitWith { hintSilent "Emergency repair already in progress."; };

private _charges = _veh getVariable ["BPD_arc_repairCharges", 0];
if (_charges <= 0) exitWith {
    hintSilent parseText format ["<t color='#ff6040'>NO REPAIR CHARGES LEFT</t><br/><t size='0.8'>%1</t>",
        ["Refuel on the ground to reload", "Refuel through the AMS to reload"] select _isARC];
};

private _now = call BPD_fnc_arcNow;
private _readyAt = _veh getVariable ["BPD_arc_repairReadyAt", 0];
if (_now < _readyAt) exitWith {
    hintSilent format ["Repair systems cycling - ready in %1s.", ceil (_readyAt - _now)];
};

private _floor = 1 - (missionNamespace getVariable ["AUX_885th_ARC_RepairCap", 0.6]);
private _vals = (getAllHitPointsDamage _veh) param [2, []];
if (damage _veh <= _floor && {(_vals findIf { _x > _floor }) < 0}) exitWith {
    hintSilent format ["All systems above %1%2 - nothing for emergency repair to fix.", round ((1 - _floor) * 100), "%"];
};

_veh setVariable ["BPD_arc_repairCharges", _charges - 1, true];
_veh setVariable ["BPD_arc_repairReadyAt", _now + (missionNamespace getVariable ["AUX_885th_ARC_RepairCooldown", 60]), true];
_veh setVariable ["BPD_arc_repairElapsed", 0, true];
_veh setVariable ["BPD_arc_repairing", true, true];

playSound "AUX_Shield_Recharge";
hintSilent parseText format [
    "<t color='#7dff9a'>EMERGENCY REPAIR ENGAGED</t><br/><t size='0.8'>Restoring systems to %1%2 - %3 charge(s) left%4</t>",
    round ((1 - _floor) * 100), "%", _charges - 1,
    ["", "<br/>Shields and boost offline while repairing"] select _isARC
];
