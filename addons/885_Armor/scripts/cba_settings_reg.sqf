/*
    Author: 885th Bloodpack Division
    Description: 885th Bloodpack Division - Addon Menu Configuration
*/

// [Setting Name, Type, [Title, Tooltip], Category, [Min, Max, Default, Decimals]]
[
    "AUX_885th_Shield_Max", "SLIDER",
    ["Maximum Katarn Protection Capacity", "Total shield capacity metrics assigned to Katarn structural sets."],
    "885th Katarn Shield",
    [50, 500, 150, 0]
] call CBA_fnc_addSetting;

[
    "AUX_885th_Shield_RegenRate", "SLIDER",
    ["Recharge Scale Velocity", "Shield capacity unit recovery points generated every loop clock cycle."],
    "885th Katarn Shield",
    [1, 50, 8, 0]
] call CBA_fnc_addSetting;

[
    "AUX_885th_Shield_RegenDelay", "SLIDER",
    ["Recharge Safety Delay Clock", "Seconds to pause engine recycling after taking armor hit penalties."],
    "885th Katarn Shield",
    [1, 15, 4, 1]
] call CBA_fnc_addSetting;

// NEW - was a bare "* 120" literal buried in the damage handler. Pulled out
// so it's tunable/documented instead of a magic number: this is how many
// shield points one full point of Arma damage (0..1 scale) costs.
[
    "AUX_885th_Shield_DamageScale", "SLIDER",
    ["Damage Conversion Scale", "Shield points consumed per 1.0 unit of raw incoming damage."],
    "885th Katarn Shield",
    [10, 300, 120, 0]
] call CBA_fnc_addSetting;

// NEW - extra recharge delay tacked on after the shield hits 0, so a full
// collapse costs more than a partial hit (mirrors Republic Commando's
// shield-down vulnerability window instead of just resuming on the same timer).
[
    "AUX_885th_Shield_BreakPenalty", "SLIDER",
    ["Shield Collapse Penalty", "Additional seconds added to the recharge delay after the shield fully depletes."],
    "885th Katarn Shield",
    [0, 20, 5, 1]
] call CBA_fnc_addSetting;

// NEW - when a single hit's damage exceeds remaining shield capacity, this is
// the fraction of the EXCESS that still punches through as light damage
// instead of being fully blocked. 0 = fully invulnerable while shield has any
// charge (old behavior), 1 = full leftover bleeds through at full strength.
[
    "AUX_885th_Shield_OverflowMitigation", "SLIDER",
    ["Overflow Punch-Through", "Fraction (0-1) of damage exceeding shield capacity that still gets through, lightly, on a shield-breaking hit."],
    "885th Katarn Shield",
    [0, 1, 0.2, 2]
] call CBA_fnc_addSetting;

// --- ACE Medical / KAT Advanced Medical specific settings ---
// These only ever get read by BPD_fnc_shieldWoundHandler, which only ever
// runs at all when ace_medical is loaded (via the separate ACE compat PBO).
// Kept separate from the vanilla settings above because ACE hands us
// summed, post-armor, per-bodypart damage rather than a single HandleDamage
// delta - the numbers involved don't necessarily feel the same, so they're
// independently tunable rather than forced to share one scale.

[
    "AUX_885th_Shield_ACE_Enabled", "CHECKBOX",
    ["Enable ACE/KAT Shield Mitigation", "Master on/off switch for shield damage mitigation when ACE Medical (or KAT, which runs on ACE) is loaded. Turning this off lets ACE/KAT process damage completely normally, shield or not."],
    "885th Katarn Shield",
    true,
    true
] call CBA_fnc_addSetting;

[
    "AUX_885th_Shield_ACE_DamageScale", "SLIDER",
    ["ACE/KAT Damage Conversion Scale", "Shield points consumed per 1.0 unit of summed, post-armor ACE damage for a single wound event. Separate from the vanilla scale."],
    "885th Katarn Shield",
    [10, 300, 120, 0]
] call CBA_fnc_addSetting;

[
    "AUX_885th_Shield_ACE_OverflowMitigation", "SLIDER",
    ["ACE/KAT Overflow Punch-Through", "Fraction (0-1) of ACE wound damage exceeding shield capacity that still gets through, lightly, on a shield-breaking hit. Separate from the vanilla setting."],
    "885th Katarn Shield",
    [0, 1, 0.2, 2]
] call CBA_fnc_addSetting;
