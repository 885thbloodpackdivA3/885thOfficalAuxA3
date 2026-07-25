/*
    885th Bloodpack Division - DC17M Reconfiguration System
    XEH_preInit.sqf - Hardened Pre-Compile Hub
*/

diag_log "[885th DC17M] preInit: Compiling primary function strings into core memory...";

// Pre-compile the swap function into global space to prevent execution lag spikes on first scroll
BPD_fnc_switchDC17M = compile preprocessFileLineNumbers "885_Weapons\scripts\functions\fnc_switchDC17M.sqf";

BPD_DC17M_SystemStatus = "INITIALIZED_MP_SAFE";

diag_log "[885th DC17M] preInit: Compilation complete.";