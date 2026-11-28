/*
    Author: 885th Bloodpack Division
    ARC-170 deflector shields + power routing - preInit.

    Compiles the functions and registers the CBA settings. Every gameplay
    setting here is isGlobal = 1 (server value is pushed to every client),
    because the shield pool lives on whichever machine owns the aircraft and
    that ownership moves around in MP - every machine must agree on the numbers.
*/

#define ARC_PATH "\885_Vehicles\scripts\arc170\"

BPD_fnc_arcInit         = compile preprocessFileLineNumbers (ARC_PATH + "fn_arcInit.sqf");
BPD_fnc_arcHandleDamage = compile preprocessFileLineNumbers (ARC_PATH + "fn_arcHandleDamage.sqf");
BPD_fnc_arcSetPower     = compile preprocessFileLineNumbers (ARC_PATH + "fn_arcSetPower.sqf");
BPD_fnc_arcHitFX        = compile preprocessFileLineNumbers (ARC_PATH + "fn_arcHitFX.sqf");
BPD_fnc_arcRepair       = compile preprocessFileLineNumbers (ARC_PATH + "fn_arcRepair.sqf");
BPD_fnc_repairTick      = compile preprocessFileLineNumbers (ARC_PATH + "fn_repairTick.sqf");
BPD_fnc_vwingInit       = compile preprocessFileLineNumbers (ARC_PATH + "fn_vwingInit.sqf");

// mission clock that's the same on every machine (time alone differs for JIP)
BPD_fnc_arcNow = { [time, serverTime] select isMultiplayer };
call compile preprocessFileLineNumbers (ARC_PATH + "fn_arcHUD.sqf");
call compile preprocessFileLineNumbers (ARC_PATH + "fn_arcMFD.sqf");
call compile preprocessFileLineNumbers (ARC_PATH + "fn_arcStrain.sqf");

// every ARC-170 created on this machine registers itself here (see fn_arcInit)
BPD_arc_vehicles = [];
// every V-wing likewise (fn_vwingInit) - emergency repair only
BPD_vwing_vehicles = [];

private _cat = "885th ARC-170";

[
    "AUX_885th_ARC_Enabled", "CHECKBOX",
    ["Enable Deflector Shields", "Master switch for the ARC-170 shield, power routing and engine boost. Off = stock aircraft."],
    _cat, true, 1
] call CBA_fnc_addSetting;

// Shield capacity is measured in "hulls": 1.0 soaks up as much damage as it
// takes to destroy the airframe from full health.
[
    "AUX_885th_ARC_ShieldMax", "SLIDER",
    ["Shield Capacity", "How much damage a full shield absorbs, in hulls. 1.0 = one full airframe's worth of damage."],
    _cat, [0.1, 5, 1, 2], 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_RegenRate", "SLIDER",
    ["Shield Recharge Rate", "Fraction of max shield restored per second in Balanced mode (doubled in Shields mode, zero in Engines mode)."],
    _cat, [0.01, 0.5, 0.05, 2], 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_RegenDelay", "SLIDER",
    ["Shield Recharge Delay", "Seconds after the last hit before the shield starts recharging."],
    _cat, [0, 20, 5, 1], 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_BreakPenalty", "SLIDER",
    ["Shield Collapse Penalty", "Extra seconds added to the recharge delay when the shield is knocked down to zero."],
    _cat, [0, 30, 6, 1], 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_HitpointWeight", "SLIDER",
    ["Component Hit Weight", "How much a hit on a component (engine, controls, fuel) costs the shield compared to a hull hit. Component armor is thinner, so its raw numbers run high."],
    _cat, [0, 1, 0.25, 2], 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_BoostAccel", "SLIDER",
    ["Engine Boost Thrust", "Extra forward acceleration (m/s per second) while boosting in Engines mode at full throttle."],
    _cat, [1, 40, 12, 0], 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_BoostMaxSpeed", "SLIDER",
    ["Engine Boost Speed Cap", "Boost stops adding thrust above this speed (km/h)."],
    _cat, [600, 1400, 950, 0], 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_BoostDrain", "SLIDER",
    ["Engine Boost Drain", "Fraction of max shield the boost burns per second."],
    _cat, [0.01, 0.5, 0.08, 2], 1
] call CBA_fnc_addSetting;

// --- Emergency repair ---
[
    "AUX_885th_ARC_RepairEnabled", "CHECKBOX",
    ["Enable Emergency Repair", "Pilot action that patches the hull and components back up to the repair cap mid-flight."],
    _cat, true, 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_RepairCap", "SLIDER",
    ["Emergency Repair Cap", "Health the emergency repair restores systems up to (0.6 = 60%). Anything already healthier is left alone."],
    _cat, [0.2, 1, 0.6, 2], 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_RepairTime", "SLIDER",
    ["Emergency Repair Duration", "Seconds for a fully destroyed system to be brought up to the cap. Less damaged systems finish sooner."],
    _cat, [1, 60, 10, 0], 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_RepairCharges", "SLIDER",
    ["Emergency Repair Charges", "Repairs available per ARC-170. Reloaded by refueling through the AMS (Refuel or Maintenance)."],
    _cat, [1, 10, 2, 0], 1
] call CBA_fnc_addSetting;

// V-wing shares the enable / cap / duration / cooldown settings above
[
    "AUX_885th_VWING_RepairCharges", "SLIDER",
    ["V-Wing Emergency Repair Charges", "Repairs available per V-wing. Reloaded by any refuel while landed (fuel truck, ACE refuel...). Enable, cap, duration and cooldown are the ARC-170 settings above."],
    _cat, [1, 10, 1, 0], 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_RepairCooldown", "SLIDER",
    ["Emergency Repair Cooldown", "Seconds after starting a repair before another can be started."],
    _cat, [0, 600, 60, 0], 1
] call CBA_fnc_addSetting;

// --- Engine strain (Max Engines while damaged) ---
[
    "AUX_885th_ARC_StrainEnabled", "CHECKBOX",
    ["Enable Engine Strain", "Running power on Max Engines while systems are damaged flashes a warning, sounds an alarm and drains shields, fuel and the damaged systems."],
    _cat, true, 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_StrainThreshold", "SLIDER",
    ["Strain Damage Threshold", "How damaged a system (or the hull) must be before Max Engines strains it (0.3 = 30% damaged)."],
    _cat, [0.05, 0.9, 0.3, 2], 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_StrainShieldDrain", "SLIDER",
    ["Strain Shield Drain", "Fraction of max shield lost per second while strained (on top of any boost drain)."],
    _cat, [0, 0.5, 0.05, 2], 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_StrainFuelDrain", "SLIDER",
    ["Strain Fuel Drain", "Fraction of a full tank lost per second while strained (0.005 = empty in ~3.3 min)."],
    _cat, [0, 0.05, 0.005, 3], 1
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_StrainWear", "SLIDER",
    ["Strain System Wear", "Extra damage per second on each already-damaged system while strained. Never pushes a system past 90%."],
    _cat, [0, 0.1, 0.01, 3], 1
] call CBA_fnc_addSetting;

// --- personal preferences, client-side only ---
[
    "AUX_885th_ARC_StrainAlarmVolume", "SLIDER",
    ["Strain Alarm Volume", "Volume of the engine strain alarm (0 = off)."],
    _cat, [0, 1, 0.35, 2], 0
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_HUD_Color", "LIST",
    ["Cockpit HUD Colour", "Colour of the ARC-170 cockpit HUD, applied at engine start. 'Leave as is' lets another HUD colour picker (e.g. Legion Studios') decide."],
    _cat,
    [[0, 1, 2, 3, 4, 5, 6], ["Republic Cyan", "Blue", "Green", "Amber", "White", "Red", "Leave as is"], 0],
    0
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_ScreenHUD", "LIST",
    ["Screen Deflector Bar", "When to show the on-screen deflector bar. The cockpit HUD already shows deflectors, power and repair in first person."],
    _cat,
    [[0, 1, 2], ["Always", "Third person only", "Never"], 1],
    0
] call CBA_fnc_addSetting;

[
    "AUX_885th_ARC_HUD_Position", "LIST",
    ["ARC-170 HUD Position", "Where the deflector / power HUD sits on screen."],
    _cat,
    [[0, 1, 2, 3], ["Bottom Center", "Bottom Left", "Bottom Right", "Top Center"], 0],
    0
] call CBA_fnc_addSetting;
