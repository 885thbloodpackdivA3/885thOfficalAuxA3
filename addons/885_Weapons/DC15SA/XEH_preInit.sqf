/*
    885th Bloodpack Division - DC-15 SA Recharge System
    XEH_preInit.sqf - Hardened Pre-Compile Hub
*/

diag_log "[885th DC15SA] preInit: Compiling recharge function into core memory...";

// Pre-compile the recharge tick into global space to prevent execution lag spikes on first spawn
BPD_fnc_dc15saRecharge = compile preprocessFileLineNumbers "885_Weapons\DC15SA\scripts\functions\fnc_dc15saRecharge.sqf";

BPD_DC15SA_SystemStatus = "INITIALIZED_MP_SAFE";

diag_log "[885th DC15SA] preInit: Compilation complete.";
