/*
    Author: 885th Bloodpack Division
    Description: 885th Post-Init Bridge
*/
if (!hasInterface) exitWith {};
call compile preprocessFileLineNumbers "\885_Armor\scripts\fn_shieldHUD.sqf";

// NOTE: these two are assigned via "compile" (not "call compile") because
// they're plain function bodies, not self-assigning scripts like
// fn_shieldHUD.sqf - "call compile" would execute them once immediately
// with no unit passed in and error out. "compile" alone just turns the
// file into a Code value and stores it under these exact global names,
// which is what lets ACE call BPD_fnc_shieldWoundHandler by name later.
BPD_fnc_shieldHitFX = compile preprocessFileLineNumbers "\885_Armor\scripts\fn_shieldHitFX.sqf";
BPD_fnc_shieldWoundHandler = compile preprocessFileLineNumbers "\885_Armor\scripts\fn_shieldACEHandler.sqf";

[] execVM "\885_Armor\scripts\fn_energyShield.sqf";
