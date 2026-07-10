/*
    885th Ion Disruptor - Pre-Initialization
    XEH_preInit.sqf

    Runs on all machines before the mission starts.
    Handles CBA settings registration and variable defaults.
*/

diag_log "885th ION: XEH_preInit started";

// Register all CBA settings
call compile preprocessFileLineNumbers "885th_ion_ammo\scripts\fn_settings.sqf";

// Set global defaults in case CBA isn't present
if (isNil "885th_ion_disableVehicles")    then { missionNamespace setVariable ["885th_ion_disableVehicles",    true];  };
if (isNil "885th_ion_affectAir")          then { missionNamespace setVariable ["885th_ion_affectAir",          true];  };
if (isNil "885th_ion_affectLand")         then { missionNamespace setVariable ["885th_ion_affectLand",         true];  };
if (isNil "885th_ion_affectShips")        then { missionNamespace setVariable ["885th_ion_affectShips",        true];  };
if (isNil "885th_ion_minDamageThreshold") then { missionNamespace setVariable ["885th_ion_minDamageThreshold", 0.75];  };
if (isNil "885th_ion_fxEnabled")          then { missionNamespace setVariable ["885th_ion_fxEnabled",          true];  };
if (isNil "885th_ion_typicalSpeed")       then { missionNamespace setVariable ["885th_ion_typicalSpeed",       420];   };

diag_log "885th ION: XEH_preInit complete";
