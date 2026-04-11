// Mode: 0 Auto, 1 Vanilla only, 2 ACE/KAT only (if ACE present)
[
  "bacta_mode",
  "LIST",
  ["Bacta Mode", "0=Auto, 1=Vanilla, 2=ACE/KAT"],
  ["Bacta", "General"],
  [[0,1,2], ["Auto", "Vanilla", "ACE/KAT"], 0],
  1
] call CBA_fnc_addSetting;

[
  "bacta_allowedGrenades",
  "EDITBOX",
  ["Allowed grenade classnames", "Comma-separated magazine and/or ammo classnames. Example: SmokeShell, SmokeShellBlue, my_bacta_grenade_mag, my_bacta_grenade_ammo"],
  ["Bacta", "General"],
  "bacta_nade",
  1
] call CBA_fnc_addSetting;

[
  "bacta_radius",
  "SLIDER",
  ["Heal Radius (m)", "Units within this radius of the projectile are treated."],
  ["Bacta", "Healing"],
  [1, 50, 10, 0],
  1
] call CBA_fnc_addSetting;

[
  "bacta_tick",
  "SLIDER",
  ["Heal Tick (sec)", "Seconds between heal ticks."],
  ["Bacta", "Healing"],
  [0.5, 10, 3, 1],
  1
] call CBA_fnc_addSetting;

[
  "bacta_damageStep",
  "SLIDER",
  ["Damage Step", "Vanilla/overall damage reduced per tick."],
  ["Bacta", "Healing"],
  [0.01, 0.25, 0.05, 2],
  1
] call CBA_fnc_addSetting;

[
  "bacta_bandageType",
  "LIST",
  ["Bandage Type (ACE)", "Used in ACE/KAT mode."],
  ["Bacta", "ACE/KAT"],
  [["FieldDressing","ElasticBandage","PackingBandage","QuickClot"], ["Field Dressing","Elastic","Packing","QuickClot"], 0],
  1
] call CBA_fnc_addSetting;

[
  "bacta_doStitch",
  "CHECKBOX",
  ["Enable Stitching (ACE)", "Stitch bandaged wounds if supported."],
  ["Bacta", "ACE/KAT"],
  true,
  1
] call CBA_fnc_addSetting;

[
  "bacta_doSplint",
  "CHECKBOX",
  ["Enable Splinting (ACE)", "If enabled, the bacta effect will apply splints to fractured limbs (ACE/KAT)."],
  ["Bacta", "ACE/KAT"],
  true,
  1
] call CBA_fnc_addSetting;
