/*
	885th Bloodpack Division - Clone HUD - Settings
	---------------------------------------------------------------
	CBA settings menu. Everything below shows up under
	Configure > Addon Options > 885th BPD Clone HUD in-game.
*/

HUD_helmets = [];
BPD_CloneHUD_P1_helmets = [];
BPD_CloneHUD_P2_helmets = [];
BPD_CloneHUD_RC_helmets = [];

// Rebuilds HUD_helmets from the three helmet-list settings. Type-guarded
// against each one so this is safe to call at ANY time, including before
// CBA has finished resolving the EDITBOX value from its own internal
// placeholder into the real string - confirmed via RPT that calling this
// synchronously right after addSetting (see the bottom of this file) hits
// exactly that race: the setting variable already exists at that point,
// but its value can still be CBA's placeholder (an array), not yet the
// resolved string, causing splitString to throw "Type Array, expected
// String". Skipping a not-yet-a-string setting here just means this tier
// stays empty until the value resolves and calls this again via its own
// onChanged - which happens well before anything actually checks
// HUD_helmets in practice (that's gated behind boot-up completing).
//
// NOTE: these are namespaced with a BPD_CloneHUD_ prefix so they can't
// collide with a same-named global from another addon in the same repo.
HUD_merge_helmet_arrays = {
	if (BPD_CloneHUD_P1_HELMETS isEqualType "") then {
		BPD_CloneHUD_P1_helmets = BPD_CloneHUD_P1_HELMETS splitString ",";
	};
	if (BPD_CloneHUD_P2_HELMETS isEqualType "") then {
		BPD_CloneHUD_P2_helmets = BPD_CloneHUD_P2_HELMETS splitString ",";
	};
	if (BPD_CloneHUD_RC_HELMETS isEqualType "") then {
		BPD_CloneHUD_RC_helmets = BPD_CloneHUD_RC_HELMETS splitString ",";
	};
	HUD_helmets = BPD_CloneHUD_P1_helmets + BPD_CloneHUD_P2_helmets + BPD_CloneHUD_RC_helmets;
	// Role life indicators (ARF / Scout / BARC) only swap the trooper art;
	// the helmet still needs to be in a P1 / P2 list to get the HUD at all.
	// SQF variable names are case-insensitive, so the parsed arrays live
	// under their own name (BPD_CloneHUD_roleList_<Role>) - writing them to
	// BPD_CloneHUD_<Role>_helmets would overwrite the CBA setting itself.
	{
		private _raw = missionNamespace getVariable [format ["BPD_CloneHUD_%1_HELMETS", toUpper _x], ""];
		private _list = switch (true) do {
			case (_raw isEqualType ""): { _raw splitString ", " };
			case (_raw isEqualType []): { _raw };
			default { [] };
		};
		missionNamespace setVariable [format ["BPD_CloneHUD_roleList_%1", _x], _list];
	} forEach ["ARF", "Scout", "BARC", "Pilot", "Airborne", "Engineer"];
};

// ============================================================
//  0. Kill Switch
// ============================================================
[
	"HUD_ENABLED",
	"CHECKBOX",
	["Enable Clone HUD (kill switch)","Master kill switch. Disable to fully turn off the HUD - no controls created, no event handlers added, zero performance cost. Needs a mission restart to take effect."],
	["885th Clone HUD (Server & Advanced)","1. Server"],
	True,
	True,
	{ HUD_ENABLED = _this; },
	True
] call CBA_fnc_addSetting;
HUD_ENABLED = true; // safe default in case onChanged hasn't resolved yet by the time init.sqf reads it

////////////////////
//General Settings//
////////////////////

[
	"CHAPTER_NAME",
	"EDITBOX",
	["Unit Name Shown at Boot-up","The chapter name that is displayed during system start up."],
	["885th Clone HUD (Server & Advanced)","6. Boot-up Sequence"],
	"885th Bloodpack Division",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"START_ON_INIT",
	"CHECKBOX",
	"Start HUD Scripts Automatically",
	["885th Clone HUD (Server & Advanced)","1. Server"],
	True,
	True,
	{}
] call CBA_fnc_addSetting;

[
	"SHOW_HUD_OVERLAY",
	"CHECKBOX",
	["Show Visor Overlay","If this is turned off the HUD wont be displayed."],
	["885th Clone HUD","1. What's On Screen"],
	True,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"DISPLAY_INFO",
	"CHECKBOX",
	"Show Ammo / Heading / Range Readout",
	["885th Clone HUD","1. What's On Screen"],
	True,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_AMMO_STYLE",
	"LIST",
	["Ammo Counter Style","Default: the helmet's own info box. Style A (BF2 Classic): wide panel with health / stamina bars, weapon icon, rounds, spare mags and grenades. Style B (Classic Inspired): compact version of the same. Styles A/B are placed with 2. Layout - Ammo Counter."],
	["885th Clone HUD","1. What's On Screen"],
	[[0,1,2],["Default","Style A (BF2 Classic)","Style B (Classic Inspired)"],0],
	nil,
	{ if (!isNil "BPD_CloneHUD_fnc_ammoLayout") then { BPD_CloneHUD_ammoShownStyle = -1; call BPD_CloneHUD_fnc_ammoLayout; }; }
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_AMMO_VITALS",
	"LIST",
	["Ammo Counter Vitals","Style A / B only. Vitals: a bar + status line read from ACE / KAT medical - blood volume and SpO2 fill the bar; unconscious, cardiac arrest, bleeding, airway, pneumothorax, internal bleeding, tourniquets, fractures and pain show as status (same reading as the squad list). Off: weapon / ammo / grenades only, smaller panel."],
	["885th Clone HUD","1. What's On Screen"],
	[[1,0],["Vitals (ACE / KAT medical)","Off"],0],
	nil,
	{ if (!isNil "BPD_CloneHUD_fnc_ammoLayout") then { BPD_CloneHUD_ammoShownStyle = -1; call BPD_CloneHUD_fnc_ammoLayout; }; }
] call CBA_fnc_addSetting;

[
	"SYSTEM_MESSAGES",
	"CHECKBOX",
	["Show System Messages","Allows the HUD to display system messages."],
	["885th Clone HUD","1. What's On Screen"],
	True,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"ALLOW_LOWLIGHT",
	"CHECKBOX",
	"Allow Low Light Vision",
	["885th Clone HUD (Server & Advanced)","2. Scanner & Low Light"],
	True,
	true,
	{}
] call CBA_fnc_addSetting;

[
	"LOWLIGHT_DEFAULT",
	"SLIDER",
	"Low Light - Default Amplification",
	["885th Clone HUD (Server & Advanced)","2. Scanner & Low Light"],
	[0.5,1.5,1,1],
	true,
	{}
] call CBA_fnc_addSetting;

[
	"LOWLIGHT_MAXIMUM",
	"SLIDER",
	"Low Light - Max Amplification",
	["885th Clone HUD (Server & Advanced)","2. Scanner & Low Light"],
	[0.5,1.5,1.5,1],
	true,
	{}
] call CBA_fnc_addSetting;

[
	"LOWLIGHT_MINIMUM",
	"SLIDER",
	"Low Light - Min Amplification",
	["885th Clone HUD (Server & Advanced)","2. Scanner & Low Light"],
	[0.5,1.5,0.5,1],
	true,
	{}
] call CBA_fnc_addSetting;

[
	"SCANNER_MAX_RANGE",
	"SLIDER",
	"Scanner - Max Range (m)",
	["885th Clone HUD (Server & Advanced)","2. Scanner & Low Light"],
	[10,1000,1000,0],
	true,
	{}
] call CBA_fnc_addSetting;

[
	"SCANNER_INTERVAL",
	"SLIDER",
	"Scanner - Range Step (m)",
	["885th Clone HUD (Server & Advanced)","2. Scanner & Low Light"],
	[1,500,100,0],
	true,
	{}
] call CBA_fnc_addSetting;

////////////////
//HUD Settings//
////////////////

[
	"HUD_ALPHA",
	"Slider",
	"Visor Overlay Opacity",
	["885th Clone HUD","4. Look & Colors"],
	[0,1,1,2],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_COLOR_NVG",
	"COLOR",
	"Visor Tint - Night Vision",
	["885th Clone HUD","4. Look & Colors"],
	[0.6,0.8,0.6,1],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_COLOR_THERMAL",
	"COLOR",
	"Visor Tint - Thermal",
	["885th Clone HUD","4. Look & Colors"],
	[1,1,1,1],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"INTERIOR_OVERLAY_COLOR",
	"COLOR",
	"HUD Color",
	["885th Clone HUD","4. Look & Colors"],
	[0.000, 0.600, 1.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"INFO_DISPLAY_COLOR",
	"COLOR",
	"Readout Frame Color",
	["885th Clone HUD","4. Look & Colors"],
	[1.000, 1.000, 1.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"INFO_TEXT_COLOR",
	"COLOR",
	"Readout Text Color",
	["885th Clone HUD","4. Look & Colors"],
	[1.000, 1.000, 1.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"INDICATOR_UNDER_ATTACK_COLOR",
	"COLOR",
	"Trooper - Hit Flash",
	["885th Clone HUD (Server & Advanced)","3. Trooper & Scanner Colors"],
	[1.000, 0.000, 0.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

// Damage indicator colors - driven by the unit's REAL health per
// limb (getHitPointDamage), not by any custom armor pool.

[
	"DMG_100_COLOR",
	"COLOR",
	"Trooper - Healthy (100%)",
	["885th Clone HUD (Server & Advanced)","3. Trooper & Scanner Colors"],
	[1.000, 1.000, 1.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"DMG_75_COLOR",
	"COLOR",
	"Trooper - Minor Damage (75%)",
	["885th Clone HUD (Server & Advanced)","3. Trooper & Scanner Colors"],
	[1.000, 0.57, 0.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"DMG_50_COLOR",
	"COLOR",
	"Trooper - Significant Damage (50%)",
	["885th Clone HUD (Server & Advanced)","3. Trooper & Scanner Colors"],
	[1.000, 0.250, 0.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"DMG_25_COLOR",
	"COLOR",
	"Trooper - Critical (25%)",
	["885th Clone HUD (Server & Advanced)","3. Trooper & Scanner Colors"],
	[0.700, 0.000, 0.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"DMG_0_COLOR",
	"COLOR",
	"Trooper - Function Lost (0%)",
	["885th Clone HUD (Server & Advanced)","3. Trooper & Scanner Colors"],
	[0.250, 0.250, 0.250, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

// ACE/KAT wound coloring (see HUD_fnc_getLimbColor in
// updateDamageIndicator.sqf) uses color tables taken directly from
// ACE3 source (ace_medical_gui/functions/fnc_bloodLossToRGBA.sqf and
// fnc_damageToRGBA.sqf), not settings - those are ACE's own real
// values and shouldn't need retuning. Neither threshold is a slider
// here anymore: bleeding uses BLOOD_LOSS_RED_THRESHOLD, confirmed a
// fixed constant (0.5) in ace_medical_engine/script_macros_medical.hpp,
// hardcoded directly rather than exposed for tuning since ACE itself
// doesn't let it vary. The "damage" (non-bleeding) threshold is read
// live from ACE's real per-unit/per-limb variables and settings at
// runtime (ace_medical_bodyPartDamage, ace_medical_damageThreshold,
// ace_medical_playerDamageThreshold, ace_medical_useLimbDamage,
// ace_medical_limbDamageThreshold), so it always matches whatever the
// server's actually configured instead of needing a manual guess.

// ACE/KAT Medical Compact - the top-left damage indicator always shows;
// this setting only controls where its data comes from. Off (default):
// the compact reads the same real getHitPointDamage values every other
// part of this HUD already uses, no ACE dependency required. On: the
// compact instead reads ACE Medical's real per-limb wound state via
// ACE's own public functions (getOpenWounds/getBandagedWounds/
// getStitchedWounds). Falls back to vanilla automatically if ACE
// Medical isn't actually loaded.
[
	"BPD_CloneHUD_ACE_COMPACT_ENABLED",
	"CHECKBOX",
	["Trooper Uses ACE/KAT Limb Data","When enabled, the compact damage indicator (trooper) pulls real per-limb injury data from ACE Medical (works with KAT - Advanced Medical too). Requires ACE Medical to actually be running - leave this off for vanilla-only games, the indicator still works either way."],
	["885th Clone HUD","1. What's On Screen"],
	false,
	nil,
	{ BPD_CloneHUD_ACE_COMPACT_ENABLED = _this; },
	False
] call CBA_fnc_addSetting;
BPD_CloneHUD_ACE_COMPACT_ENABLED = false; // safe default in case onChanged hasn't resolved yet

[
	"HUD_HUMAN_ICON",
	"EDITBOX",
	"Infantry Icon",
	["885th Clone HUD (Server & Advanced)","4. Scanner Icons"],
	"\885th_CloneHUD\textures\Target_Human.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_HUMAN_SIZE",
	"SLIDER",
	"Infantry Icon Size",
	["885th Clone HUD (Server & Advanced)","4. Scanner Icons"],
	[0.01,10.00,0.30,3],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_VEHICLE_ICON",
	"EDITBOX",
	"Vehicle Icon",
	["885th Clone HUD (Server & Advanced)","4. Scanner Icons"],
	"\885th_CloneHUD\textures\Target_Armor.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_VEHICLE_SIZE",
	"SLIDER",
	"Vehicle Icon Size",
	["885th Clone HUD (Server & Advanced)","4. Scanner Icons"],
	[0.01,10.00,0.6,3],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_STATIC_ICON",
	"EDITBOX",
	"Emplacement Icon",
	["885th Clone HUD (Server & Advanced)","4. Scanner Icons"],
	"\885th_CloneHUD\textures\Target_Emplacement.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_STATIC_SIZE",
	"SLIDER",
	"Emplacement Icon Size",
	["885th Clone HUD (Server & Advanced)","4. Scanner Icons"],
	[0.01,10.00,0.40,3],
	nil,
	{}
] call CBA_fnc_addSetting;

["BPD_CloneHUD_SCAN_LOS","CHECKBOX",["Scanner Needs Line of Sight","Scanner icons only show while you can actually see the unit - smoke, foliage and buildings hide it (a B1 inside a smoke cloud drops off the scanner). Off = only walls and terrain block it, smoke doesn't. Server setting."],["885th Clone HUD (Server & Advanced)","4. Scanner Icons"],true,true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_SCAN_LKP_TIME","SLIDER",["Last Known Position Time (s)","After losing sight, a faded '?' icon stays where the unit was last seen for this long (it does not follow them). 0 = icon just disappears. Server setting."],["885th Clone HUD (Server & Advanced)","4. Scanner Icons"],[0,60,10,0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_SCAN_LOS_MIN","SLIDER",["Visibility Needed","How visible a unit has to be to show (0-1). Lower = thin smoke / light brush still lets it through; higher = any haze hides it. Server setting."],["885th Clone HUD (Server & Advanced)","4. Scanner Icons"],[0.05,0.9,0.3,2],true,{}] call CBA_fnc_addSetting;

[
	"HUD_FRIENDLY_COLOR",
	"COLOR",
	"Scanner - Friendly",
	["885th Clone HUD (Server & Advanced)","3. Trooper & Scanner Colors"],
	[0.100, 1.000, 0.500, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_GROUP_COLOR",
	"COLOR",
	"Scanner - Own Squad",
	["885th Clone HUD (Server & Advanced)","3. Trooper & Scanner Colors"],
	[0.150, 0.500, 1.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_ENEMY_COLOR",
	"COLOR",
	"Scanner - Enemy",
	["885th Clone HUD (Server & Advanced)","3. Trooper & Scanner Colors"],
	[1.000, 0.000, 0.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_NEUTRAL_COLOR",
	"COLOR",
	"Scanner - Neutral / Downed",
	["885th Clone HUD (Server & Advanced)","3. Trooper & Scanner Colors"],
	[1.000, 1.000, 0.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_WARNING_ICON",
	"EDITBOX",
	"Grenade Warning Icon",
	["885th Clone HUD (Server & Advanced)","4. Scanner Icons"],
	"\885th_CloneHUD\textures\HUD_grenade_icon.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_WARNING_SIZE",
	"SLIDER",
	"Grenade Warning Icon Size",
	["885th Clone HUD (Server & Advanced)","4. Scanner Icons"],
	[0.01,200.00,2.20,2],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_WARNING_COLOR",
	"COLOR",
	"Scanner - Grenade Warning",
	["885th Clone HUD (Server & Advanced)","3. Trooper & Scanner Colors"],
	[1.000, 0.000, 0.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BOOTUP_OVERWRITE_TEXT",
	"CHECKBOX",
	["Overwrite BootUp Text","The variable you need to define is called HUD_bootText - an array of entries, each needing exactly 6 elements: [prefix, delayAfterPrefix, suffix, delayAfterSuffix, input1, input2]. A malformed entry (wrong element count) is now skipped safely instead of crashing the boot sequence, but matching this format avoids losing that line's text."],
	["885th Clone HUD (Server & Advanced)","6. Boot-up Sequence"],
	False,
	True,
	{}
] call CBA_fnc_addSetting;

[
	"BOOTUP_INDICATOR_LINE",
	"EDITBOX",
	["Bootup Indicators Line","Defines the line when the indicators show up. NEEDS TO BE A NUMBER!"],
	["885th Clone HUD (Server & Advanced)","6. Boot-up Sequence"],
	"5",
	True,
	{}
] call CBA_fnc_addSetting;

[
	"BOOTUP_SCANNER_LINE",
	"EDITBOX",
	["Bootup Scanner Line","Defines the line when the auspex system starts (this is what unlocks all the keybinds - scanner toggle, range, low-light). NEEDS TO BE A NUMBER, and must be less than the number of lines in your boot-up text (36 by default) or the scanner/keybinds will never activate."],
	["885th Clone HUD (Server & Advanced)","6. Boot-up Sequence"],
	"30",
	True,
	{}
] call CBA_fnc_addSetting;

//////////////
// Textures //
//////////////

[
	"HUD_START_IMAGE",
	"EDITBOX",
	"Boot-up - Start Image",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\HUD_startUp_normal.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_START_IMAGE_GLITCHED",
	"EDITBOX",
	"Boot-up - Start Image (Glitched)",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\HUD_startUp_glitched.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_VISOR_EFFECT",
	"EDITBOX",
	"Visor Effect",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\HUD_visorEffect.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_HUD_INTERIOR_OVERLAY",
	"EDITBOX",
	"Phase 1 - Interior Overlay Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_interiorOverlay.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_HUD_INFO_DISPLAY_TEXTURE",
	"EDITBOX",
	"Phase 1 - Info Display Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_ammoDisplay.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

{
	_x params ["_var", "_title", "_path"];
	[_var, "EDITBOX", [_title, "The stand/silhouette under the trooper. Full 2048x1024 canvas, same layout as the limb textures, so it moves with the trooper."], ["885th Clone HUD (Server & Advanced)","7. Textures"], _path, nil, {}] call CBA_fnc_addSetting;
} forEach [
	["P1_TROOPER_BASE", "Phase 1 - Trooper Stand Texture", "\885th_CloneHUD\textures\Phase1\P1_trooperBase.paa"],
	["P2_TROOPER_BASE", "Phase 2 - Trooper Stand Texture", "\885th_CloneHUD\textures\Phase2\P2_trooperBase.paa"],
	["RC_TROOPER_BASE", "RC - Trooper Stand Texture",      "\885th_CloneHUD\textures\RC\RC_trooperBase.paa"]
];

[
	"P1_IND_HEAD",
	"EDITBOX",
	"Phase 1 - Head Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_pa_head.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_IND_TORSO",
	"EDITBOX",
	"Phase 1 - Torso Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_pa_torso.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_IND_ARM_R",
	"EDITBOX",
	"Phase 1 - Right Arm Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_pa_armR.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_IND_ARM_L",
	"EDITBOX",
	"Phase 1 - Left Arm Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_pa_armL.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_IND_LEG_R",
	"EDITBOX",
	"Phase 1 - Right Leg Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_pa_legR.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_IND_LEG_L",
	"EDITBOX",
	"Phase 1 - Left Leg Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_pa_legL.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_HUD_INTERIOR_OVERLAY",
	"EDITBOX",
	"Phase 2 - Interior Overlay Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_interiorOverlay.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_HUD_INFO_DISPLAY_TEXTURE",
	"EDITBOX",
	"Phase 2 - Info Display Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_ammoDisplay.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_IND_HEAD",
	"EDITBOX",
	"Phase 2 - Head Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_pa_head.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_IND_TORSO",
	"EDITBOX",
	"Phase 2 - Torso Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_pa_torso.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_IND_ARM_R",
	"EDITBOX",
	"Phase 2 - Right Arm Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_pa_armR.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_IND_ARM_L",
	"EDITBOX",
	"Phase 2 - Left Arm Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_pa_armL.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_IND_LEG_R",
	"EDITBOX",
	"Phase 2 - Right Leg Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_pa_legR.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_IND_LEG_L",
	"EDITBOX",
	"Phase 2 - Left Leg Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_pa_legL.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_HUD_INTERIOR_OVERLAY",
	"EDITBOX",
	"RC - Interior Overlay Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\RC\RC_Display.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_HUD_INFO_DISPLAY_TEXTURE",
	"EDITBOX",
	"RC - Info Display Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\RC\RC_Ammodisplay.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_IND_HEAD",
	"EDITBOX",
	"RC - Head Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\RC\RC_Head.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_IND_TORSO",
	"EDITBOX",
	"RC - Torso Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\RC\RC_Torso.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_IND_ARM_R",
	"EDITBOX",
	"RC - Right Arm Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\RC\RC_R_hand.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_IND_ARM_L",
	"EDITBOX",
	"RC - Left Arm Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\RC\RC_L_hand.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_IND_LEG_R",
	"EDITBOX",
	"RC - Right Leg Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\RC\RC_R_leg.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_IND_LEG_L",
	"EDITBOX",
	"RC - Left Leg Indicator Texture",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\RC\RC_L_leg.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

// Helmet overlay art (shared "scratched visor" look across all three tiers)
[
	"P1_HELMET_OVERLAY",
	"EDITBOX",
	"All Tiers - Helmet Overlay",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\HUD_backgroundScratched.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_HELMET_BROKEN_OVERLAY",
	"EDITBOX",
	"All Tiers - Cracked Helmet Overlay",
	["885th Clone HUD (Server & Advanced)","7. Textures"],
	"\885th_CloneHUD\textures\HUD_backgroundScratchedBroken.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

/////////////////////
//Helmet Class Lists//
/////////////////////

[
	"BPD_CloneHUD_P1_HELMETS",
	"EDITBOX",
	"Phase 1 helmets | comma-separated classnames",
	["885th Clone HUD (Server & Advanced)","8. Helmet Lists"],
	// 885th helmets only (no 3AS stock): every wearable 885th Phase 1 helmet
	// from 885_Armor.
	"885th_Nightsingers_P1_Pilot_Helm,885th_Nightsingers_Senior_Pilot_Helm,885th_Nightsingers_Officer_Pilot_Helm,885th_Owl_Pilot_Helm,885th_Najax_P1_ARF_Helm,885th_Najax_Recruit_ARF_Helm",
	True,
	{
		call HUD_merge_helmet_arrays;
	},
	True
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_P2_HELMETS",
	"EDITBOX",
	"Phase 2 helmets | comma-separated classnames",
	["885th Clone HUD (Server & Advanced)","8. Helmet Lists"],
	// 885th helmets only (no 3AS stock): every wearable 885th Phase 2 helmet
	// from 885_Armor (also ARF/BARC/Airborne/Scout/Engineer/Hazard/Spec-Ops/
	// pilot and the P3 pilot helms, which have no overlay of their own and
	// share the P2 one). P1 pilots are in the Phase 1 list.
	"885th_P2_V2_Helmet,885th_P2_VCT_Helmet,885th_P2_Officer_Helmet,885th_Vornskr_Engineer_Helm,885th_Vornskr_EngineerV2_Helm,885th_ONI_MC_Helmet,885th_Stormer_P2_Helmet,885th_Wrath_P2_Helmet,885th_Bright_P2_Helmet,885th_Sytha_P2_Helm,885th_Smith_EngineerV2_Helm,885th_Sunshine_P2_Helm,885th_Rios_P2_Helmet,885th_Bullets_P2_Helmet,885th_Nightfall_P2_Helm,885th_Recruit_P2_Helm,885th_Crusader_P2_Helm,885th_Cypher_P2_Helm,885th_Vulkan_P2_Helm,885th_Oxlong_P2_Helm,885th_Charge_P2_Helm,885th_Drip_P2_Helm,885th_Bandit_P2_Helm,885th_EOD_Helm,885th_Medic_P2_Helm,885th_Nexu_Medic_P2_Helm,885th_Nexu_QRF_P2_Helm,885th_Nightsingers_Armor_Crew_Helmet,885th_Nightsingers_P2_Pilot_Helm,885th_Nightsingers_P2_Pilot_Senior_Helm,885th_Nightsingers_P2_Pilot_Officer_Helm,885th_Kings_Pilot_Helm,885th_Cerberus_P3_Pilot_Helm,885th_Nightsingers_P3_Pilot_Helm,885th_Nightsingers_P3_Senior_Pilot_Helm,885th_Nightsingers_P3_Officer_Pilot_Helm,885th_Kit_phase2SpecOp_helmet,885th_Titan_phase2SpecOp_helmet,885th_Najax_Scout_P2_Helm,885th_Gooner_Scout_Helm,885th_Najax_ARF_P2_Recruit_Helm,885th_Najax_ARF_P2_Helm,885th_Screwball_P2_ARF_Helm,885th_Ares_P2_ARF_Helm,885th_BARC_Helm,885th_Maverick_BARC_Helm,885th_Crimz_BARC_Helm,885th_Thunder_P2_BARC_Helm,885th_AB_Helm,885th_Fyrnock_QRF_Air_Helm,885th_Nexu_QRF_Air_Helm,885th_Vornskr_Hazard_Helm_Base,885th_Vornskr_Hazard_Helm_Vet,885th_Vornskr_Hazard_Helm_COM,885th_P2_MG_Helmet,885th_Fyrnock_P2_Helm,885th_Fyrnock_VCT_P2_Helm,885th_Fyrnock_Officer_P2_Helm,885th_Fyrnock_Medic_P2_Helm,885th_Fyrnock_QRF_P2_Helm,885th_Nexu_P2_Helm,885th_Nexu_Vct_P2_Helm,885th_Nexu_Officer_P2_Helm",
	True,
	{
		call HUD_merge_helmet_arrays;
	},
	True
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_RC_HELMETS",
	"EDITBOX",
	"Republic Commando helmets | comma-separated classnames",
	["885th Clone HUD (Server & Advanced)","8. Helmet Lists"],
	// 885th helmets only (no 3AS stock): every wearable 885th Katarn (RC)
	// helmet from 885_Armor (Kusak base plus the Crow / Phantom / Scorch kits).
	"885th_Kusak_Katarn_Helmet,Crow_Kusak_Katarn_Helm,Phantom_Kusak_Katarn_Helm,Scorch_Kusak_Katarn_Helm",
	True,
	{
		call HUD_merge_helmet_arrays;
	},
	True
] call CBA_fnc_addSetting;

// Role life indicators: these helmets keep their Phase 1 / Phase 2 HUD and
// visor frame, but the trooper figure is swapped for the ARF / Scout / BARC
// art (textures\ARF, textures\Scout, textures\BARC). Leave a list empty to
// turn that role's figure off.
{
	_x params ["_var", "_title", "_tip", "_default"];
	[
		_var,
		"EDITBOX",
		[_title, _tip],
		["885th Clone HUD (Server & Advanced)","8. Helmet Lists"],
		_default,
		True,
		{ call HUD_merge_helmet_arrays; },
		True
	] call CBA_fnc_addSetting;
} forEach [
	["BPD_CloneHUD_ARF_HELMETS", "ARF life indicator helmets | comma-separated classnames",
		"Troopers in these helmets get the ARF figure (ARF helmet on Phase 2 armor) as their life indicator. The helmet must also be in the Phase 1 or Phase 2 list.",
		"885th_Najax_P1_ARF_Helm,885th_Najax_Recruit_ARF_Helm,885th_Najax_ARF_P2_Recruit_Helm,885th_Najax_ARF_P2_Helm,885th_Screwball_P2_ARF_Helm,885th_Ares_P2_ARF_Helm"],
	["BPD_CloneHUD_SCOUT_HELMETS", "Scout life indicator helmets | comma-separated classnames",
		"Troopers in these helmets get the Scout figure (scout helmet on Phase 2 armor) as their life indicator. The helmet must also be in the Phase 1 or Phase 2 list.",
		"885th_Najax_Scout_P2_Helm,885th_Gooner_Scout_Helm"],
	["BPD_CloneHUD_BARC_HELMETS", "BARC life indicator helmets | comma-separated classnames",
		"Troopers in these helmets get the BARC figure (BARC helmet on Phase 2 armor) as their life indicator. The helmet must also be in the Phase 1 or Phase 2 list.",
		"885th_BARC_Helm,885th_Maverick_BARC_Helm,885th_Thunder_P2_BARC_Helm,885th_Crimz_BARC_Helm"],
	["BPD_CloneHUD_PILOT_HELMETS", "Pilot life indicator helmets | comma-separated classnames",
		"Troopers in these helmets get the Pilot figure (pilot helmet and chest life-support box on Phase 2 armor) as their life indicator. The helmet must also be in the Phase 1 or Phase 2 list.",
		"885th_Nightsingers_P1_Pilot_Helm,885th_Nightsingers_Senior_Pilot_Helm,885th_Nightsingers_Officer_Pilot_Helm,885th_Owl_Pilot_Helm,885th_Nightsingers_P2_Pilot_Helm,885th_Nightsingers_P2_Pilot_Senior_Helm,885th_Nightsingers_P2_Pilot_Officer_Helm,885th_Kings_Pilot_Helm,885th_Cerberus_P3_Pilot_Helm,885th_Nightsingers_P3_Pilot_Helm,885th_Nightsingers_P3_Senior_Pilot_Helm,885th_Nightsingers_P3_Officer_Pilot_Helm"],
	["BPD_CloneHUD_AIRBORNE_HELMETS", "Airborne life indicator helmets | comma-separated classnames",
		"Troopers in these helmets get the Airborne figure (airborne helmet on Phase 2 armor) as their life indicator. The helmet must also be in the Phase 1 or Phase 2 list.",
		"885th_AB_Helm"],
	["BPD_CloneHUD_ENGINEER_HELMETS", "Engineer life indicator helmets | comma-separated classnames",
		"Troopers in these helmets get the Engineer figure (engineer helmet on Phase 2 armor) as their life indicator. The helmet must also be in the Phase 1 or Phase 2 list.",
		"885th_Vornskr_Engineer_Helm,885th_Vornskr_EngineerV2_Helm,885th_Smith_EngineerV2_Helm"]
];

// Team member list - sits under the damage indicator, shows squad name,
// distance, and role (vanilla rank) for each squad member. Team color
// and wound status are gated on the SAME BPD_CloneHUD_ACE_COMPACT_ENABLED
// setting as the personal damage indicator's ACE data source, rather
// than a second separate toggle, since both are "optional ACE
// enhancements" turned on together.
[
	"BPD_CloneHUD_TEAM_LIST_ENABLED",
	"CHECKBOX",
	"Show Squad List",
	["885th Clone HUD","1. What's On Screen"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

// Top-center radar, fed from the SAME scanner data (HUD_nearUnits) the
// existing 3D targeting icons already use - see scripts/radar.sqf.
[
	"BPD_CloneHUD_RADAR_ENABLED",
	"CHECKBOX",
	"Show Radar",
	["885th Clone HUD","1. What's On Screen"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

// Vanilla HUD replacement - see scripts/vanillaHud.sqf. Client-side
// preferences (not forced), so each player can keep vanilla if they want.
[
	"BPD_CloneHUD_REPLACE_VANILLA_HUD",
	"CHECKBOX",
	["Replace Vanilla HUD","Master switch. While the Clone HUD is booted, hide the vanilla HUD elements ticked below. Everything comes back the moment the Clone HUD isn't up (death, helmet off, Deactivate HUD, Zeus). Works with ACE - the hide goes through ACE's own showHud stack so ACE can't undo it."],
	["885th Clone HUD","3. Vanilla HUD"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_REPLACE_VANILLA_HUD_3RD",
	"CHECKBOX",
	["Also Hide in Third Person","Keep the vanilla HUD hidden in third person too (the Clone HUD's indicator, squad list, radar and readouts stay up in third person)."],
	["885th Clone HUD","3. Vanilla HUD"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_REPLACE_VANILLA_HUD_VEHICLES",
	"CHECKBOX",
	["Also Hide in Vehicles","Also hide the vanilla HUD while in a vehicle. Off by default - the vanilla vehicle panel shows speed, fuel and altitude that the Clone HUD doesn't."],
	["885th Clone HUD","3. Vanilla HUD"],
	false,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HIDE_INFO",
	"CHECKBOX",
	["Hide Weapon / Ammo / Stance Info","Vanilla top-right weapon, ammo, fire mode and stance panel."],
	["885th Clone HUD","3. Vanilla HUD"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HIDE_COMPASS",
	"CHECKBOX",
	["Hide Compass / Direction","Vanilla compass and direction indicator."],
	["885th Clone HUD","3. Vanilla HUD"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HIDE_RADAR",
	"CHECKBOX",
	["Hide Vanilla Radar","Vanilla sensor radar."],
	["885th Clone HUD","3. Vanilla HUD"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HIDE_GROUP",
	"CHECKBOX",
	["Hide Squad Bar","Vanilla squad member bar along the bottom of the screen."],
	["885th Clone HUD","3. Vanilla HUD"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HIDE_PANELS",
	"CHECKBOX",
	["Hide Vehicle Panels / GPS","Vanilla side panels (GPS, sensors). Off by default."],
	["885th Clone HUD","3. Vanilla HUD"],
	false,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HIDE_KILLS",
	"CHECKBOX",
	["Hide Kill Messages","Vanilla 'x was killed by y' messages."],
	["885th Clone HUD","3. Vanilla HUD"],
	false,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HIDE_DUI",
	"CHECKBOX",
	["Hide DUI Squad Radar","If DUI - Squad Radar is loaded, hide its compass and name list while the Clone HUD is up (the Clone HUD has its own squad list and radar). Restored to however you had it afterwards. Does nothing without DUI."],
	["885th Clone HUD","3. Vanilla HUD"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;
[
	"RADAR_BACKGROUND_TEXTURE",
	"EDITBOX",
	["Radar Ring Texture","Leave blank for the built-in rings. Put a .paa path here to use your own radar face."],
	["885th Clone HUD (Server & Advanced)","5. Radar"],
	"",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RADAR_SIZE",
	"SLIDER",
	"Radar Base Size",
	["885th Clone HUD (Server & Advanced)","5. Radar"],
	[0.05,0.30,0.12,3],
	nil,
	{ call BPD_CloneHUD_fnc_relayout; }
] call CBA_fnc_addSetting;

///////////////////
// Squad Medical //
///////////////////
// See scripts/squadMed.sqf. Reads ACE Medical and, when loaded, KAT
// Advanced Medical for every squad member. Falls back to vanilla damage
// without ACE.

[
	"BPD_CloneHUD_SQUAD_MEDICAL",
	"LIST",
	["Squad Medical Status","What the squad list shows for each member's health. Status: KIA / ARREST / DOWN / BLEEDING / WOUNDED / OK. Details adds blood %, airway, pneumothorax, internal bleeding, tourniquets, fractures, SpO2 and pain (KAT items need KAT loaded)."],
	["885th Clone HUD","1. What's On Screen"],
	[[0, 1, 2], ["Off", "Status only", "Status + details"], 1],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_SQUAD_MEDICAL_NAMECOLOR",
	"CHECKBOX",
	["Color Names by Medical Status","Squadmates' names turn red / orange / yellow while they need a medic, and GREEN once they've been treated (bandaged, tourniquet / splint on, recovering). Healthy members keep their normal color."],
	["885th Clone HUD","1. What's On Screen"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_SQUAD_MEDICAL_MEDIC_ONLY",
	"CHECKBOX",
	["Squad Medical Details for Medics Only","Only players who are medics (ACE medic class, or the vanilla medic trait) see the detail flags. Everyone still sees the status word. Server setting."],
	["885th Clone HUD (Server & Advanced)","1. Server"],
	false,
	true,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_SQUAD_MEDICAL_ALERTS",
	"CHECKBOX",
	["Squad Medical Alerts","Post a HUD message when a squadmate gets worse: goes down, goes into cardiac arrest, starts bleeding, or develops an airway, tension / hemo pneumothorax or internal bleeding problem."],
	["885th Clone HUD","1. What's On Screen"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

///////////////////
// Squad Markers //
///////////////////
// Team labels on the 3D scanner markers over YOUR squadmates
// ("Red Team 1", "Blue Team 2", "Medic 1"...). Numbered within each
// fireteam (ACE / vanilla team colors). See BPD_CloneHUD_fnc_buildTeamLabels
// in teamList.sqf. The names are server settings so the whole unit uses
// the same callsigns.

[
	"BPD_CloneHUD_TEAM_LABELS",
	"CHECKBOX",
	["Show Team Labels on Squad Markers","Show your squadmates' fireteam label (e.g. Red Team 1, Medic 2) above their scanner markers. Only your own squad gets labels; other friendlies keep a plain marker."],
	["885th Clone HUD","6. Squad Markers"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

{
	_x params ["_team", "_title", "_default"];
	[
		format ["BPD_CloneHUD_TEAMNAME_%1", _team],
		"EDITBOX",
		[_title, format ["Label for squadmates assigned to this fireteam color. They're numbered in squad order: '%1 1', '%1 2'... Server setting.", _default]],
		["885th Clone HUD","6. Squad Markers"],
		_default,
		true,
		{}
	] call CBA_fnc_addSetting;
} forEach [
	["RED",    "Red Team Name",           "Red Team"],
	["BLUE",   "Blue Team Name",          "Blue Team"],
	["GREEN",  "Green Team Name",         "Medic"],
	["YELLOW", "Yellow Team Name",        "Yellow Team"],
	["MAIN",   "Unassigned (White) Name", "Squad"]
];

[
	"BPD_CloneHUD_TEAMNAME_LEAD",
	"EDITBOX",
	["Squad Leader Label","Label for the squad leader, whatever team they're in. Leave blank to number the leader inside their team like everyone else. Server setting."],
	["885th Clone HUD","6. Squad Markers"],
	"Lead",
	true,
	{}
] call CBA_fnc_addSetting;

///////////
// Intel //
///////////
["BPD_CloneHUD_PING_ENABLED","CHECKBOX",["Spotting Pings","Allow the Spot / Ping Target key (default Shift+T): marks what you aim at on your squad's HUD with a short callout. Server setting."],["885th Clone HUD","8. Intel & Jamming"],true,true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_PING_SCOPE","LIST",["Who Sees Pings","Server setting."],["885th Clone HUD","8. Intel & Jamming"],[[0,1],["Own squad","All friendlies in range"],0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_PING_RANGE","SLIDER",["Ping Range (m)","For 'All friendlies in range': how far from the pinged spot you can be and still get it. Server setting."],["885th Clone HUD","8. Intel & Jamming"],[100,3000,800,0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_PING_DURATION","SLIDER",["Ping Marker Time (s)","How long a ping marker stays up. Server setting."],["885th Clone HUD","8. Intel & Jamming"],[5,60,20,0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_INTEL_SENDERS","LIST",["Who Can Send Intel","Who gets 'Send Intel' in the Clone HUD ACE menu (Zeus can always use the ZEN module). Server setting."],["885th Clone HUD","8. Intel & Jamming"],[[0,1],["Squad leaders + Zeus","Everyone"],0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_INTEL_MSG_TIME","SLIDER",["Intel Message Time (s)","How long an intel broadcast stays in the HUD message feed."],["885th Clone HUD","8. Intel & Jamming"],[5,60,20,0],nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_INTEL_MARKER_TIME","SLIDER",["Intel Marker Time (s)","How long an intel marker stays up. Server setting."],["885th Clone HUD","8. Intel & Jamming"],[10,900,120,0],true,{}] call CBA_fnc_addSetting;

["BPD_CloneHUD_INTEL_LOG_TIME","SLIDER",["Intel Log Time (s)","How long the Intel Log panel stays up after you open it. 0 = until you open it again (it toggles). Placed with 2. Layout - Intel Log."],["885th Clone HUD","8. Intel & Jamming"],[0,120,15,0],nil,{}] call CBA_fnc_addSetting;

// Tac Map (feed panel link mode, ctab.sqf)
["BPD_CloneHUD_TACMAP_ZOOM","SLIDER",["Tac Map Zoom","Map scale of the Tac Map in the tactical link panel - lower = closer in."],["885th Clone HUD","5. Helm Cam & cTab"],[0.01,0.4,0.06,2],nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_TACMAP_FRAME","LIST",["Tac Map Device Frame","Show the Tac Map inside an 885th cTab device, like the real cTab screen. Auto uses the device you carry (Tablet > Holo-pad > DAGR). The frame sets the map's shape, so Tac Map Height only applies with no frame."],["885th Clone HUD","5. Helm Cam & cTab"],[[0,1,2,3,4],["Auto (device carried)","DAGR","Holo-pad (Android)","Tablet","None (plain panel)"],0],nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_TACMAP_ASPECT","SLIDER",["Tac Map Height","Tac Map height relative to its width (1 = square)."],["885th Clone HUD","5. Helm Cam & cTab"],[0.5,1.5,1,2],nil,{ if (!isNil "BPD_CloneHUD_fnc_applyLayout") then { call BPD_CloneHUD_fnc_applyLayout; }; }] call CBA_fnc_addSetting;
["BPD_CloneHUD_TACMAP_REQUIRE_DEVICE","CHECKBOX",["Tac Map Needs a cTab Device","ON: the Tac Map link mode needs a Tablet, Android or MicroDAGR. OFF: any Clone HUD helmet. Server setting."],["885th Clone HUD","5. Helm Cam & cTab"],true,true,{}] call CBA_fnc_addSetting;

/////////////
// Jamming //
/////////////
// See scripts/jamming.sqf.
["BPD_CloneHUD_JAM_ENABLED","CHECKBOX",["Jamming Affects the HUD","Crows EW jammers, 885th HUD jammers (Zeus) and any TFAR jamming show COMMS DEGRADED / COMMS LOST, and the HUD loses functions closer to the source. Server setting."],["885th Clone HUD","8. Intel & Jamming"],true,true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_JAM_DEGRADE","CHECKBOX",["Jamming Knocks Out HUD Functions","ON: 50%+ jamming = datalink down (radio rows, squad data, pings / intel, medic pings, helm cam); 85%+ = scanner and radar too. OFF: warnings only. Server setting."],["885th Clone HUD","8. Intel & Jamming"],true,true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_JAM_TFAR","CHECKBOX",["HUD Jammers Also Jam TFAR","885th HUD jammers placed by Zeus also cut TFAR range (like Crows EW does). Server setting."],["885th Clone HUD","8. Intel & Jamming"],true,true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_JAM_STATIC","CHECKBOX",["Visor Static When Jammed","Film-grain static on the visor at 50%+ jamming, stronger closer in."],["885th Clone HUD","8. Intel & Jamming"],true,nil,{}] call CBA_fnc_addSetting;

/////////////////
// Radio Comms //
/////////////////
// Per-trooper choices (except Frequency Names) - each player picks
// which displays they want. See scripts/comms.sqf. Needs TFAR.
private _rc = ["885th Clone HUD","9. Radio Comms"];
["BPD_CloneHUD_COMMS_ENABLED","CHECKBOX",["Radio Comms (TFAR)","Master switch: show who is transmitting on a channel you can hear. The displays below pick HOW it's shown."],_rc,true,nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_COMMS_SHOW_LIST","CHECKBOX",["Comms List","Rows like 'Sending... AN/PRC-152  SR CH2' / 'Receiving... AN/PRC-152  Red Team 2  SR CH2'. Placed with 2. Layout - Radio Comms."],_rc,true,nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_COMMS_LIST_STYLE","LIST",["Comms List Style","Default: one row per transmission, newest first.\nGrouped: one block - a 'Sending' heading over your transmissions and a 'Receiving' heading over what's coming in. Jamming shows on the headings (DEGRADED / COMMS LOST)."],_rc,[[0,1],["Default (one row each)","Grouped (Sending / Receiving)"],0],nil,{ if (!isNil "BPD_CloneHUD_fnc_commsLayout") then { call BPD_CloneHUD_fnc_commsLayout; }; }] call CBA_fnc_addSetting;
["BPD_CloneHUD_COMMS_LIST_ROWS","SLIDER",["Comms List Rows","How many transmissions the list shows at once (Grouped: per heading)."],_rc,[1,6,4,0],nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_COMMS_SHOW_TICKER","CHECKBOX",["One-Line Ticker","A single line with only the latest transmission. Placed with 2. Layout - Radio Ticker."],_rc,false,nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_COMMS_SHOW_3D","CHECKBOX",["Speaker Tag Over Head","While someone you can see transmits, a radio tag with the channel floats above their head."],_rc,false,nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_COMMS_3D_RANGE","SLIDER",["Speaker Tag Range (m)","Speaker tags only for transmitters closer than this."],_rc,[25,1000,300,0],nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_COMMS_SHOW_SQUAD","CHECKBOX",["Radio Icon in Squad List","A radio icon + channel next to a squadmate's name in the squad list while they transmit."],_rc,false,nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_COMMS_LABEL","LIST",["Channel Label","How the channel is written in every display."],_rc,[[0,1,2],["Name + channel + frequency  (SR CH2 Squad (152.4))","Name only  (Squad - falls back to SR CH2)","Channel + frequency  (SR CH2 (152.4))"],0],nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_COMMS_SHOW_OWN","CHECKBOX",["Show My Own Transmissions","Include your own 'Sending...' rows in the list and ticker."],_rc,true,nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_COMMS_LINGER","SLIDER",["Linger After Release (s)","How long a transmission stays (dimmed) after the key is released."],_rc,[0,15,4,0],nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_COMMS_FREQNAMES","EDITBOX",["Frequency Names","Names for frequencies, e.g. '31=Platoon, 40=Air, 152.4=Hawk Squad'. Server setting - the same names for everyone."],_rc,"",true,{}] call CBA_fnc_addSetting;

/////////////////
// Medic Pings //
/////////////////
["BPD_CloneHUD_MEDIC_PING","CHECKBOX",["Medic Pings","If you're a medic, get a MEDIC NEEDED alert (message, sound and a marker over them) when a trooper goes critical. Does nothing for non-medics."],["885th Clone HUD","7. Medic Pings"],true,nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_MEDIC_PING_THRESHOLD","LIST",["Ping When","How bad a trooper has to be before medics are pinged. Server setting."],["885th Clone HUD","7. Medic Pings"],[[3,2],["Down / cardiac arrest","Serious or worse (also heavy bleeding, airway, tension pneumo...)"],0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_MEDIC_PING_SCOPE","LIST",["Who Medics Watch","Whose injuries ping medics. Server setting."],["885th Clone HUD","7. Medic Pings"],[[0,1,2],["Own squad only","All friendly players in range","All friendlies in range (players and AI)"],1],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_MEDIC_PING_RANGE","SLIDER",["Ping Range (m)","Casualties farther than this don't ping (not used for Own squad only). Server setting."],["885th Clone HUD","7. Medic Pings"],[100,5000,1000,0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_MEDIC_PING_REPEAT","SLIDER",["Reminder Every (s)","Ping again while the trooper is still critical. 0 = only once."],["885th Clone HUD","7. Medic Pings"],[0,300,60,0],nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_MEDIC_PING_MARKER","CHECKBOX",["Marker Over Casualty","Pulsing medical marker with name, state and distance over the casualty until they're stabilized."],["885th Clone HUD","7. Medic Pings"],true,nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_MEDIC_PING_GREEN","CHECKBOX",["Green Team Counts as Medic","Anyone on Green Team gets pings too, even without the ACE medic role. Server setting."],["885th Clone HUD","7. Medic Pings"],true,true,{}] call CBA_fnc_addSetting;

// Mine detector (minedetect.sqf) - engineer role function, like medic pings
private _md = ["885th Clone HUD","10. Mine Detector"];
["BPD_CloneHUD_MINE_ENABLED","CHECKBOX",["Mine Detector","Built-in helmet mine detector. Only works for troopers who meet 'Who Gets It' (default: engineer carrying a mine detector) - does nothing for anyone else. Also toggled with the 'Toggle Mine Detector' keybind."],_md,true,nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_MINE_REQUIRE","LIST",["Who Gets It","Server setting."],_md,[[0,1,2,3],["Engineer / EOD carrying a mine detector","Anyone carrying a mine detector","Any engineer / EOD (no detector needed)","Everyone"],0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_MINE_RANGE","SLIDER",["Detection Range (m)","How close a mine has to be to get picked up. Server setting."],_md,[5,50,15,0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_MINE_SHARE","CHECKBOX",["Share With Squad","Mines you find are marked on your squad's HUDs too (needs the datalink - not while COMMS LOST). Server setting."],_md,true,true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_MINE_DETECTORS","EDITBOX",["Extra Detector Classes","Comma-separated item / weapon classnames that also count as a mine detector (vanilla MineDetector and ACE VMM3 / VMH3 always count). Server setting."],_md,"",true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_MINE_MARKERS","CHECKBOX",["Markers Over Mines","'MINE 6m' marker over each found mine."],_md,true,nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_MINE_MARKER_RANGE","SLIDER",["Marker Range (m)","Markers only for found mines closer than this."],_md,[10,300,75,0],nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_MINE_DANGER","SLIDER",["Danger Distance (m)","Inside this the marker turns red and pulses."],_md,[1,15,5,0],nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_MINE_BEEP","CHECKBOX",["Proximity Beep","Beeps while a mine is in detection range, faster as you get closer."],_md,true,nil,{}] call CBA_fnc_addSetting;

// Cracked visor (visorcrack.sqf) - Republic Commando style
private _vc = ["885th Clone HUD","11. Cracked Visor"];
["BPD_CloneHUD_CRACK_ENABLED","CHECKBOX",["Cracked Visor","A critical headshot or a blast on your body cracks your clone helmet's visor. Only Republic Commando helmets can wipe it clean. Server setting."],_vc,true,true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_HEAD","SLIDER",["Headshot Threshold","How hard a single head hit has to be to crack the visor (ACE wound damage; without ACE, head hitpoint damage 0-1). Lower = cracks more easily. Server setting."],_vc,[0.05,2,0.5,2],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_BLAST","SLIDER",["Blast Threshold","Total damage one explosion has to do to you to crack the visor. Lower = cracks more easily. Server setting."],_vc,[0.05,3,0.3,2],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_MAX","SLIDER",["Max Cracks","Cracks stack up to this many."],_vc,[1,6,4,0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_WIPE_TIME","SLIDER",["Wipe Cooldown (s)","RC helmets: time between wipes (manual or automatic)."],_vc,[0,30,5,0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_AUTO_WIPE","SLIDER",["RC Auto Wipe After (s)","RC helmets wipe the visor on their own this long after the last crack. A new crack restarts the timer. 0 = manual wipe only. Server setting."],_vc,[0,120,20,0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_LAST","SLIDER",["Non-RC Cracks Last (s)","Phase 1 / Phase 2 helmets can't wipe. Their cracks stay until they swap helmets or respawn, or clear on their own after this long. 0 = until swap / respawn. Server setting."],_vc,[0,1800,0,0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_REPAIR","LIST",["Who Can Repair","Repair Visor interaction (ACE: interact with the trooper, or self > Equipment; no ACE: hold action while looking at them). Works on every helmet tier. Server setting."],_vc,[[0,1,2],["Nobody","Engineers / EOD","Anyone"],1],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_REPAIR_TIME","SLIDER",["Repair Time (s)","How long an engineer takes to repair a visor. Server setting."],_vc,[1,60,8,0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_REPAIR_KIT","CHECKBOX",["Repair Needs Toolkit","The repairer must carry a ToolKit (vanilla or ACE). Server setting."],_vc,false,true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_OPACITY","SLIDER",["Crack Opacity","How strongly the cracks show (per player)."],_vc,[0.2,1,0.85,2],nil,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_COVER","CHECKBOX",["Cover Blocks Blast Cracks","ON: a blast with walls, floors or terrain between your eyes and where it went off doesn't crack or dirty the visor (a mortar outside your building won't). If the blast spot isn't known, being under a building roof doubles the Blast Threshold instead. Server setting."],_vc,true,true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_DIRT","CHECKBOX",["Visor Dirt","Explosives going off near you in the open (within 2x their blast radius, max 35 m) throw dirt on your visor, hurt or not. RC wipes and engineer repairs clear it too. Server setting."],_vc,true,true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_DIRT_MAX","SLIDER",["Max Dirt","Dirt overlays stack up to this many (the oldest drops off)."],_vc,[1,6,3,0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_DIRT_LAST","SLIDER",["Dirt Lasts (s)","Dirt clears on its own after this long, on every helmet. 0 = until wiped, repaired, helmet swap or respawn. Server setting."],_vc,[0,600,90,0],true,{}] call CBA_fnc_addSetting;
["BPD_CloneHUD_CRACK_DIRT_OPACITY","SLIDER",["Dirt Opacity","How strongly the dirt shows (per player)."],_vc,[0.2,1,0.8,2],nil,{}] call CBA_fnc_addSetting;

////////////
// Layout //
////////////
// Per-player placement of every movable HUD element - see
// scripts/layout.sqf. All client-side (not forced) and all live: change
// them from Addon Options mid-mission and the HUD moves immediately.

BPD_CloneHUD_fnc_relayout = {
	if (!isNil "BPD_CloneHUD_fnc_applyLayout") then { call BPD_CloneHUD_fnc_applyLayout; };
};

{
	_x params ["_key", "_label", "_tip", "_defPreset", "_defX", "_defY", "_defScale"];
	private _sub = _label;
	[
		format ["BPD_CloneHUD_LAYOUT_%1_POS", _key],
		"LIST",
		[format ["%1 - Position", _label], format ["Where the %1 sits on screen. Pick Custom to place it with the X / Y sliders below.", _tip]],
		["885th Clone HUD", "2. Layout - " + _sub],
		[[0,1,2,3,4,5,6,7,8], ["Top Left","Top Center","Top Right","Middle Left","Middle Right","Bottom Left","Bottom Center","Bottom Right","Custom (X / Y sliders)"], _defPreset],
		nil,
		{ call BPD_CloneHUD_fnc_relayout; }
	] call CBA_fnc_addSetting;
	[
		format ["BPD_CloneHUD_LAYOUT_%1_X", _key],
		"SLIDER",
		[format ["%1 - Custom X", _label], "Only used when Position is Custom. 0 = left edge, 1 = right edge. It always stays fully on screen."],
		["885th Clone HUD", "2. Layout - " + _sub],
		[0, 1, _defX, 2],
		nil,
		{ call BPD_CloneHUD_fnc_relayout; }
	] call CBA_fnc_addSetting;
	[
		format ["BPD_CloneHUD_LAYOUT_%1_Y", _key],
		"SLIDER",
		[format ["%1 - Custom Y", _label], "Only used when Position is Custom. 0 = top edge, 1 = bottom edge. It always stays fully on screen."],
		["885th Clone HUD", "2. Layout - " + _sub],
		[0, 1, _defY, 2],
		nil,
		{ call BPD_CloneHUD_fnc_relayout; }
	] call CBA_fnc_addSetting;
	[
		format ["BPD_CloneHUD_LAYOUT_%1_SCALE", _key],
		"SLIDER",
		[format ["%1 - Scale", _label], "Size multiplier."],
		["885th Clone HUD", "2. Layout - " + _sub],
		[0.4, 2, _defScale, 2],
		nil,
		{ call BPD_CloneHUD_fnc_relayout; }
	] call CBA_fnc_addSetting;
} forEach [
	// key       label                    tooltip name                          preset X     Y    scale
	// Clean defaults: everything a bit smaller, hugging the edges.
	["TROOPER", "Trooper Status",        "limb damage indicator (clone trooper)", 5,   0,    1,   0.8],
	["SQUAD",   "Squad List",            "squad member list",                     3,   0,    0.5, 0.85],
	["RADAR",   "Radar",                 "scanner radar",                         6,   0.5,  1,   0.8],
	["FEED",    "Tactical Link Panel",   "cTab device strip / helm cam panel",    2,   1,    0,   0.9],
	["AMMO",    "Ammo Counter",          "Style A / B ammo counter",              7,   1,    1,   1],
	["COMMS",   "Radio Comms",           "radio comms list (who's talking)",      4,   1,    0.5, 1],
	["TICKER",  "Radio Ticker",          "one-line radio ticker",                 1,   0.5,  0,   1],
	["INTEL",   "Intel Log",             "intel log panel",                       1,   0.5,  0.2, 1],
	["KILLS",   "Kill Counter",          "kill counter panel",                    8,   1,    0.25, 0.85]
];

["BPD_CloneHUD_KILLS_ENABLED","CHECKBOX",["Kill Counter","Counts the enemies you kill this mission, per enemy type. Press 'Show / Hide Kill Counter' (Controls > Configure Addons > 885th BPD Clone HUD) to see your top 4. Position / size are on this same page."],["885th Clone HUD","2. Layout - Kill Counter"],true,nil,{ if (!_this && {!isNil "BPD_CloneHUD_fnc_killHide"}) then { call BPD_CloneHUD_fnc_killHide; }; }] call CBA_fnc_addSetting;
["BPD_CloneHUD_KILLS_TIME","SLIDER",["Kill Counter Time (s)","How long the Kill Counter stays up after it finishes typing, then it fades. 0 = until you press the key again."],["885th Clone HUD","2. Layout - Kill Counter"],[0,60,15,0],nil,{}] call CBA_fnc_addSetting;

//////////////
// cTab Link //
//////////////
// See scripts/ctab.sqf. Only does anything when the 885th cTab is loaded
// (helm cam feed also works from squadmates' clone helmets without it).

[
	"BPD_CloneHUD_CTAB_HELMETCAMS",
	"CHECKBOX",
	["Clone Helmets Are Helmet Cams","ON (default): every clone wearing a Clone HUD helmet can be viewed - on the HUD with Shift+J, and in the cTab Tablet's helmet cam list - no ItemcTabHCam needed. OFF: only people carrying an ItemcTabHCam (or cTab's own camera helmets) can be viewed. Server setting."],
	["885th Clone HUD","5. Helm Cam & cTab"],
	true,
	true,
	{},
	true
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HCAM_REQUIRE_DEVICE",
	"CHECKBOX",
	["Viewing Helm Cams Needs a cTab Device","OFF (default): your clone helmet is enough to view helm cams on the HUD. ON: you also need a Tablet, Android or MicroDAGR in your inventory. Server setting."],
	["885th Clone HUD","5. Helm Cam & cTab"],
	false,
	true,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_FEED_MODE",
	"LIST",
	["Show Tactical Link Panel","The panel with your cTab devices, link mode (cTab / DAGR / Helm Cam) and the helm cam feed. 'When in use' keeps it off screen until you press Shift+H / Shift+J or use the ACE Clone HUD menu (rebind keys under Controls > Configure Addons > 885th BPD Clone HUD)."],
	["885th Clone HUD","1. What's On Screen"],
	[[0, 1, 2], ["Off", "When in use", "Always"], 1],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HCAM_SQUAD_ONLY",
	"CHECKBOX",
	["Helm Cams: Own Squad Only","ON: Shift+J only cycles your own squad. OFF (default): every friendly helm cam, your squad first, then nearest. Needs Picture-in-Picture enabled in Options > Video."],
	["885th Clone HUD","5. Helm Cam & cTab"],
	false,
	nil,
	{}
] call CBA_fnc_addSetting;

call HUD_merge_helmet_arrays;
