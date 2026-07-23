// XEH_preInit.sqf
// Runs once, early, before missions/units exist.
// Nothing here is strictly required (switchDC17M is registered via
// CfgFunctions and lazy-compiled on first call regardless), this file just
// confirms CBA is finding and running this addon's init files at all.

diag_log "[885th DC17M] preInit OK";

// A global flag tracking whether this addon's reconfigure actions have
// been added at least once. Declared here in preInit so it exists before
// anything else runs.
BPD_DC17M_ConversionActionsAdded = false;
