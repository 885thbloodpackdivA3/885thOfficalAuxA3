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
};

// ============================================================
//  0. Kill Switch
// ============================================================
[
	"HUD_ENABLED",
	"CHECKBOX",
	["Enable 885th Clone HUD","Master kill switch. Disable to fully turn off the HUD - no controls created, no event handlers added, zero performance cost. Needs a mission restart to take effect."],
	["885th BPD Clone HUD - General","I. General Settings"],
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
	["Chapter Name","The chapter name that is displayed during system start up."],
	["885th BPD Clone HUD - General","I. General Settings"],
	"885th Bloodpack Division",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"START_ON_INIT",
	"CHECKBOX",
	"Start Scripts on Mission Init",
	["885th BPD Clone HUD - General","I. General Settings"],
	True,
	True,
	{}
] call CBA_fnc_addSetting;

[
	"SHOW_HUD_OVERLAY",
	"CHECKBOX",
	["Show Hud Overlay","If this is turned off the HUD wont be displayed."],
	["885th BPD Clone HUD - General","I. General Settings"],
	True,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"DISPLAY_INFO",
	"CHECKBOX",
	"Show Info Display",
	["885th BPD Clone HUD - General","I. General Settings"],
	True,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"SYSTEM_MESSAGES",
	"CHECKBOX",
	["Display System Messages","Allows the HUD to display system messages."],
	["885th BPD Clone HUD - General","I. General Settings"],
	True,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"ALLOW_LOWLIGHT",
	"CHECKBOX",
	"Allow Low Light Mode",
	["885th BPD Clone HUD - General","I. General Settings"],
	True,
	true,
	{}
] call CBA_fnc_addSetting;

[
	"LOWLIGHT_DEFAULT",
	"SLIDER",
	"Low Light default amplification",
	["885th BPD Clone HUD - General","I. General Settings"],
	[0.5,1.5,1,1],
	true,
	{}
] call CBA_fnc_addSetting;

[
	"LOWLIGHT_MAXIMUM",
	"SLIDER",
	"Low Light max amplification",
	["885th BPD Clone HUD - General","I. General Settings"],
	[0.5,1.5,1.5,1],
	true,
	{}
] call CBA_fnc_addSetting;

[
	"LOWLIGHT_MINIMUM",
	"SLIDER",
	"Low Light min amplification",
	["885th BPD Clone HUD - General","I. General Settings"],
	[0.5,1.5,0.5,1],
	true,
	{}
] call CBA_fnc_addSetting;

[
	"SCANNER_MAX_RANGE",
	"SLIDER",
	"Auspex maximum detection range",
	["885th BPD Clone HUD - General","I. General Settings"],
	[10,1000,1000,0],
	true,
	{}
] call CBA_fnc_addSetting;

[
	"SCANNER_INTERVAL",
	"SLIDER",
	"Scanner increase/decrease value",
	["885th BPD Clone HUD - General","I. General Settings"],
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
	"Helmet Overlay Transparency",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[0,1,1,2],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_COLOR_NVG",
	"COLOR",
	"Helmet Overlay Tint/Transparency in NV",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[0.6,0.8,0.6,1],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_COLOR_THERMAL",
	"COLOR",
	"Helmet Overlay Tint/Transparency in Thermal",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[1,1,1,1],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"INTERIOR_OVERLAY_COLOR",
	"COLOR",
	"Interior Overlay Tint/Transparency",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[0.000, 0.600, 1.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"INFO_DISPLAY_COLOR",
	"COLOR",
	"Info Display Color",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[1.000, 1.000, 1.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"INFO_TEXT_COLOR",
	"COLOR",
	"Info Display Text Color",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[1.000, 1.000, 1.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"INDICATOR_UNDER_ATTACK_COLOR",
	"COLOR",
	"Under Attack Color",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[1.000, 0.000, 0.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

// Damage indicator colors - driven by the unit's REAL health per
// limb (getHitPointDamage), not by any custom armor pool.

[
	"DMG_100_COLOR",
	"COLOR",
	"Indicator Color - Healthy (100%)",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[1.000, 1.000, 1.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"DMG_75_COLOR",
	"COLOR",
	"Indicator Color - Minor Damage (75%)",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[1.000, 0.57, 0.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"DMG_50_COLOR",
	"COLOR",
	"Indicator Color - Significant Damage (50%)",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[1.000, 0.250, 0.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"DMG_25_COLOR",
	"COLOR",
	"Indicator Color - Critical (25%)",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[0.700, 0.000, 0.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"DMG_0_COLOR",
	"COLOR",
	"Indicator Color - Function Lost (0%)",
	["885th BPD Clone HUD - General","II. HUD Settings"],
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
	["ACE/KAT Medical Compact","When enabled, the compact damage indicator (trooper) pulls real per-limb injury data from ACE Medical (works with KAT - Advanced Medical too). Requires ACE Medical to actually be running - leave this off for vanilla-only games, the indicator still works either way."],
	["885th BPD Clone HUD - General","II. HUD Settings"],
	false,
	nil,
	{ BPD_CloneHUD_ACE_COMPACT_ENABLED = _this; },
	False
] call CBA_fnc_addSetting;
BPD_CloneHUD_ACE_COMPACT_ENABLED = false; // safe default in case onChanged hasn't resolved yet

[
	"HUD_HUMAN_ICON",
	"EDITBOX",
	"HUD Human Icon",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	"\885th_CloneHUD\textures\Target_Human.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_HUMAN_SIZE",
	"SLIDER",
	"HUD Human Icon Size",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[0.01,10.00,0.30,3],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_VEHICLE_ICON",
	"EDITBOX",
	"HUD Vehicle Icon",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	"\885th_CloneHUD\textures\Target_Armor.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_VEHICLE_SIZE",
	"SLIDER",
	"HUD Vehicle Icon Size",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[0.01,10.00,0.6,3],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_STATIC_ICON",
	"EDITBOX",
	"HUD Emplacement Icon",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	"\885th_CloneHUD\textures\Target_Emplacement.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_STATIC_SIZE",
	"SLIDER",
	"HUD Emplacement Icon Size",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[0.01,10.00,0.40,3],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_FRIENDLY_COLOR",
	"COLOR",
	"HUD Friendly Icon Color",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[0.100, 1.000, 0.500, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_GROUP_COLOR",
	"COLOR",
	"HUD Group Icon Color",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[0.150, 0.500, 1.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_ENEMY_COLOR",
	"COLOR",
	"HUD Enemy Icon Color",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[1.000, 0.000, 0.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_NEUTRAL_COLOR",
	"COLOR",
	"HUD Neutral Icon Color",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[1.000, 1.000, 0.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_WARNING_ICON",
	"EDITBOX",
	"HUD Warning Icon",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	"\885th_CloneHUD\textures\HUD_grenade_icon.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_WARNING_SIZE",
	"SLIDER",
	"HUD Warning Icon Size",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[0.01,200.00,2.20,2],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_WARNING_COLOR",
	"COLOR",
	"HUD Warning Icon Color",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[1.000, 0.000, 0.000, 1.000],
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BOOTUP_OVERWRITE_TEXT",
	"CHECKBOX",
	["Overwrite BootUp Text","The variable you need to define is called HUD_bootText - an array of entries, each needing exactly 6 elements: [prefix, delayAfterPrefix, suffix, delayAfterSuffix, input1, input2]. A malformed entry (wrong element count) is now skipped safely instead of crashing the boot sequence, but matching this format avoids losing that line's text."],
	["885th BPD Clone HUD - General","II. HUD Settings"],
	False,
	True,
	{}
] call CBA_fnc_addSetting;

[
	"BOOTUP_INDICATOR_LINE",
	"EDITBOX",
	["Bootup Indicators Line","Defines the line when the indicators show up. NEEDS TO BE A NUMBER!"],
	["885th BPD Clone HUD - General","II. HUD Settings"],
	"5",
	True,
	{}
] call CBA_fnc_addSetting;

[
	"BOOTUP_SCANNER_LINE",
	"EDITBOX",
	["Bootup Scanner Line","Defines the line when the auspex system starts (this is what unlocks all the keybinds - scanner toggle, range, low-light). NEEDS TO BE A NUMBER, and must be less than the number of lines in your boot-up text (36 by default) or the scanner/keybinds will never activate."],
	["885th BPD Clone HUD - General","II. HUD Settings"],
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
	"Start Image",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\HUD_startUp_normal.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_START_IMAGE_GLITCHED",
	"EDITBOX",
	"Start Image Glitched",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\HUD_startUp_glitched.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"HUD_VISOR_EFFECT",
	"EDITBOX",
	"Visor Effect Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\HUD_visorEffect.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_HUD_INTERIOR_OVERLAY",
	"EDITBOX",
	"Interior Overlay Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_interiorOverlay.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_HUD_INFO_DISPLAY_TEXTURE",
	"EDITBOX",
	"Info Display Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_ammoDisplay.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_IND_HEAD",
	"EDITBOX",
	"Head Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_pa_head.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_IND_TORSO",
	"EDITBOX",
	"Torso Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_pa_torso.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_IND_ARM_R",
	"EDITBOX",
	"Right Arm Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_pa_armR.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_IND_ARM_L",
	"EDITBOX",
	"Left Arm Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_pa_armL.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_IND_LEG_R",
	"EDITBOX",
	"Right Leg Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_pa_legR.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_IND_LEG_L",
	"EDITBOX",
	"Left Leg Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase1\P1_pa_legL.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_HUD_INTERIOR_OVERLAY",
	"EDITBOX",
	"Interior Overlay Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_interiorOverlay.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_HUD_INFO_DISPLAY_TEXTURE",
	"EDITBOX",
	"Info Display Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_ammoDisplay.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_IND_HEAD",
	"EDITBOX",
	"Head Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_pa_head.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_IND_TORSO",
	"EDITBOX",
	"Torso Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_pa_torso.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_IND_ARM_R",
	"EDITBOX",
	"Right Arm Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_pa_armR.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_IND_ARM_L",
	"EDITBOX",
	"Left Arm Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_pa_armL.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_IND_LEG_R",
	"EDITBOX",
	"Right Leg Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_pa_legR.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P2_IND_LEG_L",
	"EDITBOX",
	"Left Leg Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\Phase2\P2_pa_legL.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_HUD_INTERIOR_OVERLAY",
	"EDITBOX",
	"Interior Overlay Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\RC\RC_Display.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_HUD_INFO_DISPLAY_TEXTURE",
	"EDITBOX",
	"Info Display Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\RC\RC_Ammodisplay.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_IND_HEAD",
	"EDITBOX",
	"Head Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\RC\RC_Head.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_IND_TORSO",
	"EDITBOX",
	"Torso Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\RC\RC_Torso.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_IND_ARM_R",
	"EDITBOX",
	"Right Arm Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\RC\RC_R_hand.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_IND_ARM_L",
	"EDITBOX",
	"Left Arm Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\RC\RC_L_hand.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_IND_LEG_R",
	"EDITBOX",
	"Right Leg Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\RC\RC_R_leg.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RC_IND_LEG_L",
	"EDITBOX",
	"Left Leg Indicator Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\RC\RC_L_leg.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

// Helmet overlay art (shared "scratched visor" look across all three tiers)
[
	"P1_HELMET_OVERLAY",
	"EDITBOX",
	"Helmet Overlay Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
	"\885th_CloneHUD\textures\HUD_backgroundScratched.paa",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"P1_HELMET_BROKEN_OVERLAY",
	"EDITBOX",
	"Helmet Broken Overlay Texture",
	["885th BPD Clone HUD - General","III. HUD Textures"],
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
	["885th BPD Clone HUD - Helmets","Helmet Classes"],
	// 3AS stock helmets, then every wearable 885th Phase 1 helmet from 885_Armor.
	"3as_P1_Base,3as_P1_Sgt,3as_P1_LT,3as_P1_CPT,3as_P1_CC,3as_P1_Pilot_helmet,885th_Nightsingers_P1_Pilot_Helm,885th_Nightsingers_Senior_Pilot_Helm,885th_Nightsingers_Officer_Pilot_Helm,885th_Owl_Pilot_Helm,885th_Najax_P1_ARF_Helm,885th_Najax_Recruit_ARF_Helm",
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
	["885th BPD Clone HUD - Helmets","Helmet Classes"],
	// 3AS stock helmet, then every wearable 885th Phase 2 helmet from 885_Armor
	// (also ARF/BARC/Airborne/Scout/Engineer/Hazard/Spec-Ops/pilot and the
	// P3 pilot helm, which have no overlay of their own and share the P2 one).
	"3as_Engineer_Helmet,885th_P2_V2_Helmet,885th_P2_VCT_Helmet,885th_P2_Officer_Helmet,885th_Vornskr_Engineer_Helm,885th_Vornskr_EngineerV2_Helm,885th_ONI_MC_Helmet,885th_Stormer_P2_Helmet,885th_Wrath_P2_Helmet,885th_Bright_P2_Helmet,885th_Sytha_P2_Helm,885th_Smith_EngineerV2_Helm,885th_Sunshine_P2_Helm,885th_Rios_P2_Helmet,885th_Bullets_P2_Helmet,885th_Nightfall_P2_Helm,885th_Recruit_P2_Helm,885th_Crusader_P2_Helm,885th_Cypher_P2_Helm,885th_Vulkan_P2_Helm,885th_Oxlong_P2_Helm,885th_Charge_P2_Helm,885th_Drip_P2_Helm,885th_Bandit_P2_Helm,885th_EOD_Helm,885th_Medic_P2_Helm,885th_Nexu_Medic_P2_Helm,885th_Nexu_QRF_P2_Helm,885th_Nightsingers_Armor_Crew_Helmet,885th_Nightsingers_P2_Pilot_Helm,885th_Nightsingers_P2_Pilot_Senior_Helm,885th_Nightsingers_P2_Pilot_Officer_Helm,885th_Kings_Pilot_Helm,885th_Cerberus_P3_Pilot_Helm,885th_Kit_phase2SpecOp_helmet,885th_Titan_phase2SpecOp_helmet,885th_Najax_Scout_P2_Helm,885th_Crimz_Scout_Helm,885th_Gooner_Scout_Helm,885th_Najax_ARF_P2_Recruit_Helm,885th_Najax_ARF_P2_Helm,885th_Screwball_P2_ARF_Helm,885th_Ares_P2_ARF_Helm,885th_Sushi_P2_ARF_Helm,885th_BARC_Helm,885th_Maverick_BARC_Helm,885th_Thunder_P2_BARC_Helm,885th_AB_Helm,885th_Fyrnock_QRF_Air_Helm,885th_Nexu_QRF_Air_Helm,885th_Vornskr_Hazard_Helm_Base,885th_Vornskr_Hazard_Helm_Vet,885th_Vornskr_Hazard_Helm_COM,885th_P2_MG_Helmet,885th_Fyrnock_P2_Helm,885th_Fyrnock_VCT_P2_Helm,885th_Fyrnock_Officer_P2_Helm,885th_Fyrnock_Medic_P2_Helm,885th_Fyrnock_QRF_P2_Helm,885th_Nexu_P2_Helm,885th_Nexu_Vct_P2_Helm,885th_Nexu_Officer_P2_Helm",
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
	["885th BPD Clone HUD - Helmets","Helmet Classes"],
	// 3AS stock helmet, then every wearable 885th Katarn (RC) helmet from 885_Armor.
	"3AS_H_Katarn_Helmet,885th_Kusak_Katarn_Helmet,Crow_Kusak_Katarn_Helm,Phantom_Kusak_Katarn_Helm,Scorch_Kusak_Katarn_Helm",
	True,
	{
		call HUD_merge_helmet_arrays;
	},
	True
] call CBA_fnc_addSetting;

// Team member list - sits under the damage indicator, shows squad name,
// distance, and role (vanilla rank) for each squad member. Team color
// and wound status are gated on the SAME BPD_CloneHUD_ACE_COMPACT_ENABLED
// setting as the personal damage indicator's ACE data source, rather
// than a second separate toggle, since both are "optional ACE
// enhancements" turned on together.
[
	"BPD_CloneHUD_TEAM_LIST_ENABLED",
	"CHECKBOX",
	"Enable Team Member List",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

// Top-center radar, fed from the SAME scanner data (HUD_nearUnits) the
// existing 3D targeting icons already use - see scripts/radar.sqf.
[
	"BPD_CloneHUD_RADAR_ENABLED",
	"CHECKBOX",
	"Enable Radar",
	["885th BPD Clone HUD - General","II. HUD Settings"],
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
	["885th BPD Clone HUD - General","IV. Vanilla HUD"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_REPLACE_VANILLA_HUD_3RD",
	"CHECKBOX",
	["Also Hide in Third Person","Keep the vanilla HUD hidden in third person too (the Clone HUD's indicator, squad list, radar and readouts stay up in third person)."],
	["885th BPD Clone HUD - General","IV. Vanilla HUD"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_REPLACE_VANILLA_HUD_VEHICLES",
	"CHECKBOX",
	["Also Hide in Vehicles","Also hide the vanilla HUD while in a vehicle. Off by default - the vanilla vehicle panel shows speed, fuel and altitude that the Clone HUD doesn't."],
	["885th BPD Clone HUD - General","IV. Vanilla HUD"],
	false,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HIDE_INFO",
	"CHECKBOX",
	["Hide Weapon / Ammo / Stance Info","Vanilla top-right weapon, ammo, fire mode and stance panel."],
	["885th BPD Clone HUD - General","IV. Vanilla HUD"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HIDE_COMPASS",
	"CHECKBOX",
	["Hide Compass / Direction","Vanilla compass and direction indicator."],
	["885th BPD Clone HUD - General","IV. Vanilla HUD"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HIDE_RADAR",
	"CHECKBOX",
	["Hide Vanilla Radar","Vanilla sensor radar."],
	["885th BPD Clone HUD - General","IV. Vanilla HUD"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HIDE_GROUP",
	"CHECKBOX",
	["Hide Squad Bar","Vanilla squad member bar along the bottom of the screen."],
	["885th BPD Clone HUD - General","IV. Vanilla HUD"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HIDE_PANELS",
	"CHECKBOX",
	["Hide Vehicle Panels / GPS","Vanilla side panels (GPS, sensors). Off by default."],
	["885th BPD Clone HUD - General","IV. Vanilla HUD"],
	false,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HIDE_KILLS",
	"CHECKBOX",
	["Hide Kill Messages","Vanilla 'x was killed by y' messages."],
	["885th BPD Clone HUD - General","IV. Vanilla HUD"],
	false,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HIDE_DUI",
	"CHECKBOX",
	["Hide DUI Squad Radar","If DUI - Squad Radar is loaded, hide its compass and name list while the Clone HUD is up (the Clone HUD has its own squad list and radar). Restored to however you had it afterwards. Does nothing without DUI."],
	["885th BPD Clone HUD - General","IV. Vanilla HUD"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;
[
	"RADAR_BACKGROUND_TEXTURE",
	"EDITBOX",
	"Radar Background Texture (leave blank for a plain panel - the built-in default here used to be a vanilla texture, but it turned out to actually be a targeting-lock reticle rather than a radar dial, so there's no default graphic anymore. Put your own .paa path here to use a proper radar face)",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	"",
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"RADAR_SIZE",
	"SLIDER",
	"Radar Size",
	["885th BPD Clone HUD - General","II. HUD Settings"],
	[0.05,0.30,0.12,3],
	nil,
	{ call BPD_CloneHUD_fnc_relayout; }
] call CBA_fnc_addSetting;

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
		["885th BPD Clone HUD - Layout", _sub],
		[[0,1,2,3,4,5,6,7,8], ["Top Left","Top Center","Top Right","Middle Left","Middle Right","Bottom Left","Bottom Center","Bottom Right","Custom (X / Y sliders)"], _defPreset],
		nil,
		{ call BPD_CloneHUD_fnc_relayout; }
	] call CBA_fnc_addSetting;
	[
		format ["BPD_CloneHUD_LAYOUT_%1_X", _key],
		"SLIDER",
		[format ["%1 - Custom X", _label], "Only used when Position is Custom. 0 = left edge, 1 = right edge. It always stays fully on screen."],
		["885th BPD Clone HUD - Layout", _sub],
		[0, 1, _defX, 2],
		nil,
		{ call BPD_CloneHUD_fnc_relayout; }
	] call CBA_fnc_addSetting;
	[
		format ["BPD_CloneHUD_LAYOUT_%1_Y", _key],
		"SLIDER",
		[format ["%1 - Custom Y", _label], "Only used when Position is Custom. 0 = top edge, 1 = bottom edge. It always stays fully on screen."],
		["885th BPD Clone HUD - Layout", _sub],
		[0, 1, _defY, 2],
		nil,
		{ call BPD_CloneHUD_fnc_relayout; }
	] call CBA_fnc_addSetting;
	[
		format ["BPD_CloneHUD_LAYOUT_%1_SCALE", _key],
		"SLIDER",
		[format ["%1 - Scale", _label], "Size multiplier."],
		["885th BPD Clone HUD - Layout", _sub],
		[0.4, 2, _defScale, 2],
		nil,
		{ call BPD_CloneHUD_fnc_relayout; }
	] call CBA_fnc_addSetting;
} forEach [
	// key       label                    tooltip name                          preset X     Y    scale
	["TROOPER", "Trooper Status",        "limb damage indicator (clone trooper)", 5,   0,    1,   1],
	["SQUAD",   "Squad List",            "squad member list",                     3,   0,    0.5, 1],
	["RADAR",   "Radar",                 "scanner radar",                         6,   0.5,  1,   1],
	["FEED",    "Tactical Link Panel",   "cTab device strip / helm cam panel",    2,   1,    0,   1]
];

//////////////
// cTab Link //
//////////////
// See scripts/ctab.sqf. Only does anything when the 885th cTab is loaded
// (helm cam feed also works from squadmates' clone helmets without it).

[
	"BPD_CloneHUD_CTAB_HELMETCAMS",
	"CHECKBOX",
	["Clone Helmets Are Helmet Cams","Every helmet in the Clone HUD helmet lists counts as a cTab helmet camera, so clones show up in the cTab Tablet's helmet cam list and in the HUD helm cam feed without carrying an ItemcTabHCam. Forced for everyone so all clients agree."],
	["885th BPD Clone HUD - cTab Link","Link"],
	true,
	true,
	{},
	true
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HCAM_REQUIRE_DEVICE",
	"CHECKBOX",
	["Helm Cam Feed Needs a cTab Device","When on, viewing helm cams on the HUD needs a Tablet, Android or MicroDAGR in your inventory. When off, the clone helmet itself is enough."],
	["885th BPD Clone HUD - cTab Link","Link"],
	false,
	true,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_FEED_ENABLED",
	"CHECKBOX",
	["Show Tactical Link Panel","Show the panel with your cTab devices, current link mode (cTab / DAGR / Helm Cam) and the helm cam feed. Shift+H cycles the link, Shift+J cycles helm cams (rebind under Controls > Configure Addons > 885th BPD Clone HUD)."],
	["885th BPD Clone HUD - cTab Link","Link"],
	true,
	nil,
	{}
] call CBA_fnc_addSetting;

[
	"BPD_CloneHUD_HCAM_SQUAD_ONLY",
	"CHECKBOX",
	["Helm Cams: Own Squad Only","Only cycle through helm cams worn by your own squad. Off = every friendly helm cam cTab knows about (your squad first, then nearest)."],
	["885th BPD Clone HUD - cTab Link","Link"],
	false,
	nil,
	{}
] call CBA_fnc_addSetting;

call HUD_merge_helmet_arrays;
