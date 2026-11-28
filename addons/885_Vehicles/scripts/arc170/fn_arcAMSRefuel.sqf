/*
    Author: 885th Bloodpack Division
    ARC-170 AMS refuel hook.

    FIR's AMS (Lite "Refuel", full AMS "Refuel" and "Maintenance") checks the
    aircraft's AMSData for CustomFuelEnabled = 1 and, if set, execVMs
    CustomFuelScript INSTEAD of its own "setFuel 1". 885th_ARC170's AMSData
    points here, so an AMS refuel tops up the tank AND reloads the emergency
    repair charge(s).

    FIR passes no arguments, so the aircraft is found the same way FIR finds
    it: the player's vehicle, or their connected UAV. FIR has already waited
    out its 5s "Refueling.." delay before calling this, and only runs on the
    player's machine - the pilot, who owns the jet, so setFuel works here.
*/
private _plane = getConnectedUAV player;
if (isNull _plane) then { _plane = vehicle player; };
if (_plane == player) exitWith {};

_plane setFuel 1;

if (_plane getVariable ["BPD_arc_registered", false]) then {
    private _max = round (missionNamespace getVariable ["AUX_885th_ARC_RepairCharges", 2]);
    private _had = _plane getVariable ["BPD_arc_repairCharges", 0];
    _plane setVariable ["BPD_arc_repairCharges", _max, true];
    if (_had < _max) then {
        systemChat format ["Emergency repair reloaded (%1/%1).", _max];
    };
};
