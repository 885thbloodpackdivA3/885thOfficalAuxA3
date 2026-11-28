/*
    Author: 885th Bloodpack Division
    BPD_fnc_arcSetPower - params: [vehicle, mode]

    0 = BALANCED  normal shield recharge, no boost
    1 = SHIELDS   recharge x2, hits cost the shield 25% less
    2 = ENGINES   no recharge, hits cost 25% more; at full throttle the
                  engines burn shield power for extra thrust

    Called from the pilot's UserActions. The variable is broadcast so the
    rear gunner's HUD and whichever machine owns the jet all agree.
*/
params ["_veh", "_mode"];

if (_mode == 2 && {(_veh getVariable ["BPD_arc_shield", 0]) <= 0}) exitWith {
    hintSilent "No reserve power to route to engines.";
};

_veh setVariable ["BPD_arc_power", _mode, true];

playSound (["AUX_Shield_Recharge", "AUX_Shield_Boot", "AUX_Shield_Shutdown"] select _mode);
hintSilent parseText ([
    "<t color='#9fdcff'>POWER: BALANCED</t>",
    "<t color='#40c8ff'>POWER: MAX SHIELDS</t>",
    "<t color='#ffb030'>POWER: MAX ENGINES</t><br/><t size='0.8'>Full throttle to boost</t>"
] select _mode);
