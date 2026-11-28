/*
    Author: 885th Bloodpack Division
    ARC-170 engine strain - running Max Engines on a damaged jet.

      BPD_fnc_arcStrainCheck - params: [vehicle]
          returns [strained (bool), damaged hitpoint indices (array)]

    Strained = power on MAX ENGINES, engine running, no emergency repair in
    progress, and the hull or any system (glass / lights don't count) is past
    the strain threshold (default 30% damaged).

    Called by the owner loop (XEH_postInit.sqf), which applies the drain
    (shield, fuel, slow wear on the damaged systems) and publishes one flag,
    BPD_arc_strain, that every crew member's HUD reads for the warning and
    alarm. Wear is capped (default 90%) so strain alone never destroys a system.
*/

BPD_fnc_arcStrainCheck = {
    params ["_veh"];

    if !(missionNamespace getVariable ["AUX_885th_ARC_StrainEnabled", true]) exitWith { [false, []] };
    if ((_veh getVariable ["BPD_arc_power", 0]) != 2
        || {!isEngineOn _veh}
        || {_veh getVariable ["BPD_arc_repairing", false]}) exitWith { [false, []] };

    private _thr = missionNamespace getVariable ["AUX_885th_ARC_StrainThreshold", 0.3];
    (getAllHitPointsDamage _veh) params [["_names", []], ["_sels", []], ["_vals", []]];

    private _damaged = [];
    {
        if (_x > _thr) then {
            private _name = toLower (_names param [_forEachIndex, ""]);
            if !("glass" in _name || {"light" in _name}) then { _damaged pushBack _forEachIndex; };
        };
    } forEach _vals;

    [(_damaged isNotEqualTo []) || {damage _veh > _thr}, _damaged]
};
