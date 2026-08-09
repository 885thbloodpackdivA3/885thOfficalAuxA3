/*
    Author: 885th Bloodpack Division
    Description: 885th Post-Init Bridge
*/

// FIX: these two MUST be defined regardless of hasInterface. AI units are
// simulated on the dedicated server itself, not on any client, so when an
// AI takes damage, ACE calls our wound handler wrapper ON THE SERVER. With
// the old "if (!hasInterface) exitWith {}" sitting above these two lines,
// BPD_fnc_shieldWoundHandler was never defined there at all - the wrapper's
// "_this call BPD_fnc_shieldWoundHandler" silently called a nil variable,
// ACE logged it as an invalid return ('BPD_shieldMitigation' invalid -
// 'any'), and skipped wound handling entirely for that hit - which is what
// was making AI invincible whenever they were server-simulated (Eden-placed
// from mission start) rather than possibly client-local (some Zeus-spawned
// units).
BPD_fnc_shieldHitFX = compile preprocessFileLineNumbers "\885_Armor\scripts\fn_shieldHitFX.sqf";
BPD_fnc_shieldWoundHandler = compile preprocessFileLineNumbers "\885_Armor\scripts\fn_shieldACEHandler.sqf";

// Everything below this point is player-facing only (HUD, menu, the
// per-frame engine that drives the player's own shield) - correctly stays
// gated to machines with an actual interface.
if (!hasInterface) exitWith {};

call compile preprocessFileLineNumbers "\885_Armor\scripts\fn_shieldHUD.sqf";
[] execVM "\885_Armor\scripts\fn_energyShield.sqf";