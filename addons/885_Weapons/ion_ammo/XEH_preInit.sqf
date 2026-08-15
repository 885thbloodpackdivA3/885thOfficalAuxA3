/*
    885th Ion Disruptor - Pre-Initialization
    XEH_preInit.sqf
*/

diag_log "885th ION: XEH_preInit started";

if (isNil "885th_ion_disableVehicles")    then { missionNamespace setVariable ["885th_ion_disableVehicles",    true];  };
if (isNil "885th_ion_affectAir")          then { missionNamespace setVariable ["885th_ion_affectAir",          true];  };
if (isNil "885th_ion_affectLand")         then { missionNamespace setVariable ["885th_ion_affectLand",         true];  };
if (isNil "885th_ion_affectShips")        then { missionNamespace setVariable ["885th_ion_affectShips",        true];  };
if (isNil "885th_ion_minDamageThreshold") then { missionNamespace setVariable ["885th_ion_minDamageThreshold", 0.75];  };

diag_log "885th ION: XEH_preInit complete";
