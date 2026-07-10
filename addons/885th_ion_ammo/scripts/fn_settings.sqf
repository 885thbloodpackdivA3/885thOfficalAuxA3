/*
    885th Ion Disruptor - CBA Settings
    fn_settings.sqf
    Registered via addMissionEventHandler in init.sqf
*/

[
    "885th_ion_hit",
    "SLIDER",
    ["Direct Hit Damage", "Raw damage dealt on direct impact."],
    "885th Ion Disruptor",
    [1, 50, 10, 0],
    true
] call CBA_fnc_addSetting;

[
    "885th_ion_indirectHit",
    "SLIDER",
    ["Indirect Hit Damage", "Area pulse damage on impact."],
    "885th Ion Disruptor",
    [0, 50, 18, 0],
    true
] call CBA_fnc_addSetting;

[
    "885th_ion_indirectHitRange",
    "SLIDER",
    ["Indirect Hit Range (m)", "Radius of the ion pulse area effect."],
    "885th Ion Disruptor",
    [0.5, 10, 4.0, 1],
    true
] call CBA_fnc_addSetting;

[
    "885th_ion_disableVehicles",
    "CHECKBOX",
    ["Disable Vehicles", "Whether ion hits disable vehicle engines."],
    "885th Ion Disruptor",
    true,
    true
] call CBA_fnc_addSetting;

[
    "885th_ion_affectAir",
    "CHECKBOX",
    ["Affect Aircraft", "Whether ion hits disable aircraft."],
    "885th Ion Disruptor",
    true,
    true
] call CBA_fnc_addSetting;

[
    "885th_ion_affectLand",
    "CHECKBOX",
    ["Affect Land Vehicles", "Whether ion hits disable land vehicles."],
    "885th Ion Disruptor",
    true,
    true
] call CBA_fnc_addSetting;

[
    "885th_ion_affectShips",
    "CHECKBOX",
    ["Affect Ships", "Whether ion hits disable sea vehicles."],
    "885th Ion Disruptor",
    true,
    true
] call CBA_fnc_addSetting;

[
    "885th_ion_minDamageThreshold",
    "SLIDER",
    ["Min Damage State on Hit", "Minimum damage level forced on vehicle after ion hit (0.0 - 1.0)."],
    "885th Ion Disruptor",
    [0.0, 1.0, 0.75, 2],
    true
] call CBA_fnc_addSetting;

[
    "885th_ion_fxEnabled",
    "CHECKBOX",
    ["Enable Visual FX", "Toggle the ion arc particle effects on disabled vehicles."],
    "885th Ion Disruptor",
    true,
    true
] call CBA_fnc_addSetting;

[
    "885th_ion_typicalSpeed",
    "SLIDER",
    ["Bolt Speed (m/s)", "Muzzle velocity of the ion bolt."],
    "885th Ion Disruptor",
    [100, 800, 420, 0],
    true
] call CBA_fnc_addSetting;
