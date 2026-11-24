/*
	885th Bloodpack Division - Clone HUD - Init
	---------------------------------------------------------------
	Client-side only. Everything in this addon only ever reads or
	writes the LOCAL player's own variables/controls, so it needs
	no server logic and behaves identically in the editor, SP,
	hosted MP, or on a dedicated server. Requires CBA (settings +
	keybinds) - no ACE dependency.
*/

// KILL SWITCH - if the HUD is disabled, nothing below this line ever runs.
// (Configure > Addon Options > 885th BPD Clone HUD - General > HUD_ENABLED)
// Read via getVariable with an explicit default so this can never throw
// "Undefined variable" even in an edge case where CBA's onChanged for
// HUD_ENABLED hasn't resolved yet by the time postInit runs.
if (!(missionNamespace getVariable ["HUD_ENABLED", true])) exitWith {
	if (hasInterface) then {
		systemChat "[885th BPD Clone HUD] HUD_ENABLED is OFF in Addon Options - the addon is doing nothing on purpose. Turn it back on to use the HUD.";
	};
};

if (!hasInterface) exitWith {}; // headless client / server safety net

// ACE Medical detection - set once. HUD_fnc_getLimbColor (in
// updateDamageIndicator.sqf) checks this before calling any ace_medical_fnc_
// function, so the ACE/KAT Medical Compact setting can be left on safely
// even on a modset without ACE Medical loaded - it just falls back to
// vanilla data instead of erroring.
HUD_aceMedicalLoaded = isClass (configFile >> "CfgPatches" >> "ace_medical");
HUD_ACE_BODYPARTS = ["head","body","leftarm","rightarm","leftleg","rightleg"];

if ((missionNamespace getVariable ["BPD_CloneHUD_ACE_COMPACT_ENABLED", false]) && !HUD_aceMedicalLoaded) then {
	systemChat "[885th BPD Clone HUD] ACE/KAT Medical Compact is enabled in Addon Options, but ACE Medical isn't loaded - falling back to vanilla damage tracking for the compact.";
};

execVM "\885th_CloneHUD\scripts\layout.sqf";
execVM "\885th_CloneHUD\scripts\hudEventhandler.sqf";
execVM "\885th_CloneHUD\scripts\hudBootUp.sqf";
execVM "\885th_CloneHUD\scripts\hudInit.sqf";
execVM "\885th_CloneHUD\scripts\systemMessages.sqf";
execVM "\885th_CloneHUD\scripts\updateDamageIndicator.sqf";
execVM "\885th_CloneHUD\scripts\squadMed.sqf";
execVM "\885th_CloneHUD\scripts\teamList.sqf";
execVM "\885th_CloneHUD\scripts\radar.sqf";
execVM "\885th_CloneHUD\scripts\system.sqf";
execVM "\885th_CloneHUD\scripts\vanillaHud.sqf";
execVM "\885th_CloneHUD\scripts\ctab.sqf";

targetingSystemSoundOn = "threat_detector";

HUD_ICON_MODIFIER = 1;
HUD_detectorRange = 300;
HUD_FOV_MOD = 1;
HUD_BOOT_OFFSET = 0.022;
HUD_SUIT_LABEL = "[UNKNOWN]";

// ============================================================
//  Keybinds (CBA)
// ============================================================
["885th BPD Clone HUD","HUD_toggleIconsKey", "Toggle Scanner Icons", {
	if (headgear player in HUD_helmets && player getvariable ["HUD_TARGETING_ALLOWED", false]) then {
		if (HUD_showIcons) then {
			[] spawn {
				_targetingEffect = ppEffectCreate ["ColorCorrections",2593];
				_targetingEffect ppEffectForceInNVG true;
				_targetingEffect ppEffectEnable true;
				_targetingEffect ppEffectAdjust [0,1,0,[0.105,0.105,0.105,0.5],[1,1,1,0],[1,1,1,0],[1,1,0,0,0,0,10]];
				_targetingEffect ppEffectCommit 0.3;
				playsound targetingSystemSoundOn;
				["Scanner offline", "auspexToggle",2] call HUD_fnc_addSystemMessage;
				sleep 0.2;
				HUD_showIcons = false;
				sleep 0.5;
				ppEffectDestroy _targetingEffect;
			};
		} else {
			[] spawn {
				_targetingEffect = ppEffectCreate ["ColorCorrections",2593];
				_targetingEffect ppEffectForceInNVG true;
				_targetingEffect ppEffectEnable true;
				_targetingEffect ppEffectAdjust [0,1,0,[0.105,0.105,0.105,0.5],[1,1,1,0],[1,1,1,0],[1,1,0,0,0,0,10]];
				_targetingEffect ppEffectCommit 0.3;
				playsound targetingSystemSoundOn;
				["Scanner online", "auspexToggle",2] call HUD_fnc_addSystemMessage;
				sleep 0.2;
				HUD_showIcons = true;
				sleep 0.5;
				ppEffectDestroy _targetingEffect;
			};
		};
	};
}, "", [0x14, [false, false, true]]] call CBA_fnc_addKeybind;

["885th BPD Clone HUD","HUD_threatRangeUpKey", "Increase Scanner Range", {
	if (headgear player in HUD_helmets && player getvariable ["HUD_TARGETING_ALLOWED", false]) then {
		if (HUD_threatRange < SCANNER_MAX_RANGE) then {
			HUD_threatRange = HUD_threatRange + SCANNER_INTERVAL;
			playsound "click";
			["Scanner range: " + str HUD_threatRange + "m", "auspexRange",2] call HUD_fnc_addSystemMessage;

			terminate HUD_nearUnitsHandlerHandle;
			HUD_nearUnitsHandlerHandle = [] spawn {
				while {HUD_targetingHandlerAdded} do {
					while {HUD_showIcons} do {
						call HUD_nearUnitsHandler;
						sleep HUD_throttleTime;
					};
					sleep 1;
				};
			};
		};
	};
}, "", [0xC8, [true, false, false]]] call CBA_fnc_addKeybind;

["885th BPD Clone HUD","HUD_threatRangeDownKey", "Decrease Scanner Range", {
	if (headgear player in HUD_helmets && player getvariable ["HUD_TARGETING_ALLOWED", false]) then {
		if (HUD_threatRange > SCANNER_INTERVAL) then {
			HUD_threatRange = HUD_threatRange - SCANNER_INTERVAL;
			playsound "click";
			["Scanner range: " + str HUD_threatRange + "m", "auspexRange",2] call HUD_fnc_addSystemMessage;

			terminate HUD_nearUnitsHandlerHandle;
			HUD_nearUnitsHandlerHandle = [] spawn {
				while {HUD_targetingHandlerAdded} do {
					while {HUD_showIcons} do {
						call HUD_nearUnitsHandler;
						sleep HUD_throttleTime;
					};
					sleep 1;
				};
			};
		};
	};
}, "", [0xD0, [true, false, false]]] call CBA_fnc_addKeybind;

["885th BPD Clone HUD","HUD_toggleLowLightKey", "Toggle Low Light Vision", {
	if (headgear player in HUD_helmets && player getvariable ["HUD_TARGETING_ALLOWED", false] && ALLOW_LOWLIGHT) then {
		if (HUD_lowLight) then {
			playSound "RscDisplayCurator_visionMode";
			setAperture -1;
			HUD_lowLight = false;
			["Low light vision disabled", "lowlightToggled",2] call HUD_fnc_addSystemMessage;
		} else {
			playSound "RscDisplayCurator_visionMode";
			setAperture HUD_lowLightAperture;
			HUD_lowLight = true;
			["Low light vision enabled", "lowlightToggled",2] call HUD_fnc_addSystemMessage;
		};
	};
}, "", [0x26, [true, false, false]]] call CBA_fnc_addKeybind;

["885th BPD Clone HUD","HUD_lowLightUpKey", "Increase Low Light Sensitivity", {
	if (headgear player in HUD_helmets && player getvariable ["HUD_TARGETING_ALLOWED", false] && ALLOW_LOWLIGHT) then {
		if (HUD_lowLightAperture > (2 - LOWLIGHT_MAXIMUM)) then {
			HUD_lowLightAperture = (HUD_lowLightAperture - 0.1) max 0;
			playsound "click";
			if (HUD_lowLight) then { setAperture HUD_lowLightAperture; };
			["Low Light Sensitivity: " + str round(abs(HUD_lowLightAperture - 2) * 100) + "%", "lowlightSensitivitiy",2] call HUD_fnc_addSystemMessage;
		};
	};
}, "", [0xCD, [true, false, false]]] call CBA_fnc_addKeybind;

["885th BPD Clone HUD","HUD_lowLightDownKey", "Decrease Low Light Sensitivity", {
	if (headgear player in HUD_helmets && player getvariable ["HUD_TARGETING_ALLOWED", false] && ALLOW_LOWLIGHT) then {
		if (HUD_lowLightAperture < (2 - LOWLIGHT_MINIMUM)) then {
			HUD_lowLightAperture = HUD_lowLightAperture + 0.1;
			playsound "click";
			if (HUD_lowLight) then { setAperture HUD_lowLightAperture; };
			["Low Light Sensitivity: " + str round(abs(HUD_lowLightAperture - 2) * 100) + "%", "lowlightSensitivitiy",2] call HUD_fnc_addSystemMessage;
		};
	};
}, "", [0xCB, [true, false, false]]] call CBA_fnc_addKeybind;

// cTab link (see ctab.sqf). Shift+H / Shift+J - cTab's own keys are
// H / Ctrl+H / Alt+H, so these don't collide with it.
["885th BPD Clone HUD","BPD_CloneHUD_cycleLinkKey", "Cycle Tactical Link (cTab / DAGR / Helm Cam)", {
	if (isNil "BPD_CloneHUD_fnc_cycleLink") exitWith {false};
	call BPD_CloneHUD_fnc_cycleLink
}, "", [0x23, [true, false, false]]] call CBA_fnc_addKeybind;

["885th BPD Clone HUD","BPD_CloneHUD_nextHcamKey", "Next Helm Cam Feed", {
	if (isNil "BPD_CloneHUD_fnc_nextHcam") exitWith {false};
	call BPD_CloneHUD_fnc_nextHcam
}, "", [0x24, [true, false, false]]] call CBA_fnc_addKeybind;

// ============================================================
//  Damage Indicator hit hook (real health, no armor pool)
//  "Dammaged" fires AFTER the engine applies damage, so this
//  never touches or overrides how much damage is taken - it
//  only reads the result to drive the flash/sound/message.
//  The light COLORS themselves are polled independently in
//  system.sqf, so this is a cosmetic enhancer, not the source
//  of truth - if it never fires for some reason, the lights
//  still update correctly within one loop tick.
// ============================================================
HUD_fnc_addDammagedHook = {
	player addEventHandler ["Dammaged", {
		params ["_unit","_hitSelection"];
		if (!HUD_ENABLED || {isNull _unit} || {_unit != player}) exitWith {};
		if (!(player getVariable ["HUD_hasUniform",false])) exitWith {};

		if (_hitSelection != "") then {
			_hitsound = selectRandom[
				"A3\Sounds_F\weapons\hits\metal_1.wss",
				"A3\Sounds_F\weapons\hits\metal_2.wss",
				"A3\Sounds_F\weapons\hits\metal_3.wss",
				"A3\Sounds_F\weapons\hits\metal_4.wss",
				"A3\Sounds_F\weapons\hits\metal_5.wss",
				"A3\Sounds_F\weapons\hits\metal_6.wss"
			];
			playsound3d [_hitsound, _unit];
			[_hitSelection] call HUD_fnc_updateDamageIndicatorHit;
		};
	}];
};
call HUD_fnc_addDammagedHook;

// ============================================================
//  Core state / helmet handling
// ============================================================
// HUD_merge_helmet_arrays is defined once in settings.sqf (the
// type-safe version, guarded against CBA's placeholder-array timing) -
// do not redefine it here. An earlier duplicate definition in this
// file was overwriting that safe version on every load and reintroducing
// the exact crash the settings.sqf fix was meant to prevent.

HUD_fnc_getHelmetOverlay = {
	switch (true) do {
		case (headgear player in BPD_CloneHUD_P1_helmets): {
			player setvariable ["P1_INHELMET", true]; player setvariable ["P2_INHELMET", false]; player setVariable ["RC_INHELMET", false];
			player setvariable ["P1_INHELMETS", true]; player setvariable ["P2_INHELMETS", false]; player setVariable ["RC_INHELMETS", false];

			HUD_hudOverlayTexture = P1_HELMET_OVERLAY;
			HUD_hudOverlayBrokenTexture = P1_HELMET_BROKEN_OVERLAY;
			TEXTURE_DATAOUTPUT = P1_HUD_INFO_DISPLAY_TEXTURE;
			HUD_TEXTURE_INTERIOR_OVERLAY = P1_HUD_INTERIOR_OVERLAY;
			HUD_TEXTURE_IND_HEAD = P1_IND_HEAD;
			HUD_TEXTURE_IND_TORSO = P1_IND_TORSO;
			HUD_TEXTURE_IND_ARM_R = P1_IND_ARM_R;
			HUD_TEXTURE_IND_ARM_L = P1_IND_ARM_L;
			HUD_TEXTURE_IND_LEG_R = P1_IND_LEG_R;
			HUD_TEXTURE_IND_LEG_L = P1_IND_LEG_L;
			HUD_SUIT_LABEL = "Phase 1 Armor";
		};
		case (headgear player in BPD_CloneHUD_P2_helmets): {
			player setvariable ["P1_INHELMET", false]; player setvariable ["P2_INHELMET", true]; player setVariable ["RC_INHELMET", false];
			player setvariable ["P1_INHELMETS", false]; player setvariable ["P2_INHELMETS", true]; player setVariable ["RC_INHELMETS", false];

			HUD_hudOverlayTexture = P1_HELMET_OVERLAY;
			HUD_hudOverlayBrokenTexture = P1_HELMET_BROKEN_OVERLAY;
			TEXTURE_DATAOUTPUT = P2_HUD_INFO_DISPLAY_TEXTURE;
			HUD_TEXTURE_INTERIOR_OVERLAY = P2_HUD_INTERIOR_OVERLAY;
			HUD_TEXTURE_IND_HEAD = P2_IND_HEAD;
			HUD_TEXTURE_IND_TORSO = P2_IND_TORSO;
			HUD_TEXTURE_IND_ARM_R = P2_IND_ARM_R;
			HUD_TEXTURE_IND_ARM_L = P2_IND_ARM_L;
			HUD_TEXTURE_IND_LEG_R = P2_IND_LEG_R;
			HUD_TEXTURE_IND_LEG_L = P2_IND_LEG_L;
			HUD_SUIT_LABEL = "Phase 2 Armor";
		};
		case (headgear player in BPD_CloneHUD_RC_helmets): {
			player setvariable ["P1_INHELMET", false]; player setvariable ["P2_INHELMET", false]; player setVariable ["RC_INHELMET", true];
			player setvariable ["P1_INHELMETS", false]; player setvariable ["P2_INHELMETS", false]; player setVariable ["RC_INHELMETS", true];

			HUD_hudOverlayTexture = P1_HELMET_OVERLAY;
			HUD_hudOverlayBrokenTexture = P1_HELMET_BROKEN_OVERLAY;
			TEXTURE_DATAOUTPUT = RC_HUD_INFO_DISPLAY_TEXTURE;
			HUD_TEXTURE_INTERIOR_OVERLAY = RC_HUD_INTERIOR_OVERLAY;
			HUD_TEXTURE_IND_HEAD = RC_IND_HEAD;
			HUD_TEXTURE_IND_TORSO = RC_IND_TORSO;
			HUD_TEXTURE_IND_ARM_R = RC_IND_ARM_R;
			HUD_TEXTURE_IND_ARM_L = RC_IND_ARM_L;
			HUD_TEXTURE_IND_LEG_R = RC_IND_LEG_R;
			HUD_TEXTURE_IND_LEG_L = RC_IND_LEG_L;
			HUD_SUIT_LABEL = "Republic Commando Armor";
		};
	};
};

HUD_updateGearVariables = {
	HUD_hasHelmet = headgear player in HUD_helmets;
	player setvariable ["HUD_hasUniform", HUD_hasHelmet, true];
	HUD_firstPersonCheck = ((cameraView == "INTERNAL") OR (cameraView == "GUNNER"));

	if (HUD_hasHelmet) then {
		call HUD_fnc_addHudEventhandler;
		call HUD_fnc_getHelmetOverlay;
		// swapped to a different armor tier - re-skin and re-place the
		// trooper (each tier's art sits in a different spot on its canvas)
		if (!isNil "BPD_CloneHUD_fnc_applyLayout") then { call BPD_CloneHUD_fnc_applyLayout; };
	};
	if (HUD_hasHelmet && !(player getVariable ["HUD_suitActive",false]) && START_ON_INIT) then {
		call HUD_suit_activation;
	};
};

HUD_suit_ready = {
	newViewAngle = 0;
	oldViewAngle = 0;
	hudAngle = 0;
	HUD_threatRange = SCANNER_MAX_RANGE min 200;
	HUD_nearUnits = [];
	HUD_lowLightAperture = LOWLIGHT_DEFAULT;

	call HUD_merge_helmet_arrays;

	HUD_hasHelmet = headgear player in HUD_helmets;
	HUD_eventHandlerAdded = false;
	HUD_targetingHandlerAdded = false;
	HUD_helmetOverlayShown = false;
	HUD_systemMessages = [];
	HUD_systemMessageAllowed = false;

	HUD_head_prevColor = DMG_100_COLOR;
	HUD_body_prevColor = DMG_100_COLOR;
	HUD_armR_prevColor = DMG_100_COLOR;
	HUD_armL_prevColor = DMG_100_COLOR;
	HUD_legR_prevColor = DMG_100_COLOR;
	HUD_legL_prevColor = DMG_100_COLOR;

	HUD_showIcons = true;
	HUD_lowLight = false;

	player setVariable ["HUD_suitActive",false, true];

	// Selection-name groupings, used purely to decide which limb
	// icon flashes and which real hitpoint feeds its color.
	HUD_head = ["head","face","neck","bt_head"];
	HUD_body = ["spine1","spine2","spine3","pelvis","bt_pelvis","bt_spine"];
	HUD_leftArm = ["leftshoulder","leftarm","leftarmroll","leftforearm","leftforearmroll","lefthand","hit_lefthand","bt_l_upperarm","bt_l_forearm","bt_l_hand"];
	HUD_rightArm = ["rightshoulder","rightarm","rightarmroll","rightforearm","rightforearmroll","righthand","hit_righthand","bt_r_upperarm","bt_r_forearm","bt_r_hand"];
	HUD_leftLeg = ["leftupleg","leftuplegroll","leftleg","leftfoot","bt_l_thigh","bt_l_calf","bt_l_foot"];
	HUD_rightLeg = ["rightupleg","rightuplegroll","rightleg","rightfoot","bt_r_thigh","bt_r_calf","bt_r_foot"];

	player setvariable ["HUD_active_mode", "none"];

	ActivateHUDAction = player addAction ["Activate HUD",
		{ call HUD_fnc_hudBootUp },
	[],1.5,false,true,"","(alive _originalTarget) && !(player getvariable ['HUD_hudInitiated', false]) && (headgear player in HUD_helmets)"];

	DisctivateHUDAction = player addAction ["Deactivate HUD",
		{ call HUD_fnc_clearHud },
	[],1.5,false,true,"","(alive _originalTarget) && (player getvariable ['HUD_hudInitiated', false]) && (player getVariable ['HUD_bootComplete', false]) && (headgear player in HUD_helmets)"];

	HUD_suit_activate_action = player addAction ["Start HUD Scripts", {
		call HUD_suit_activation
	}, [], 6, false, true,"","(alive _originalTarget) && (headgear player in HUD_helmets) && !(player getVariable 'HUD_suitActive') && !START_ON_INIT"];
};

HUD_suit_activation = {
	player setVariable ["HUD_suitActive",true, true];
	player setVariable ["HUD_suitDisabled",false];

	HUD_hasHelmet = headgear player in HUD_helmets;
	HUD_firstPersonCheck = ((cameraView == "INTERNAL") OR (cameraView == "GUNNER"));

	player setvariable ["HUD_hasUniform",true, true];
	player setvariable ["HUD_ACTIVE", false];
	player setvariable ["HUD_ALLOWED", false];
	player setvariable ["HUD_HUD_BOOTING", false];
	player setvariable ["HUD_active_mode", "hud"];

	call HUD_fnc_getHelmetOverlay;
	call HUD_fnc_hudInit;
	diag_log format ["885th_CloneHUD: about to spawn HUD_fnc_system - isNil check: %1.", isNil "HUD_fnc_system"];
	[player] spawn HUD_fnc_system;
	[] spawn HUD_fnc_SystemMessageLoop;
	[] spawn HUD_fnc_teamListLoop;
	[] spawn HUD_fnc_radarLoop;
};

// ============================================================
//  Bring the HUD up for the local player
// ============================================================
[] spawn {
	waitUntil { sleep 1; (!(isNull player) && (time > 0)) };
	call HUD_suit_ready;
	// once per session - HUD_helmets is resolved by now
	waitUntil { sleep 0.1; !isNil "BPD_CloneHUD_fnc_registerHelmetCams" };
	call BPD_CloneHUD_fnc_registerHelmetCams;
	if ((headgear player in HUD_helmets) && !(player getVariable 'HUD_suitActive') && START_ON_INIT) then {
		sleep 1;
		player setvariable ["HUD_hasUniform",headgear player in HUD_helmets,true];
		call HUD_suit_activation;
	};
};

player addEventHandler ["respawn", {
	[] spawn {
		waitUntil { sleep 1; (!(isNull player) && (time > 0)) };
		call HUD_suit_ready;
		call HUD_fnc_addDammagedHook;
		if ((headgear player in HUD_helmets) && !(player getVariable 'HUD_suitActive') && START_ON_INIT) then {
			player setvariable ["HUD_hasUniform",headgear player in HUD_helmets,true];
			call HUD_suit_activation;
		} else {
			player setvariable ["HUD_hasUniform",headgear player in HUD_helmets,true];
		};
	};
}];

player addEventHandler ["Take", { call HUD_updateGearVariables; }];
player addEventHandler ["Put", { call HUD_updateGearVariables; }];
player addEventHandler ["InventoryOpened", { call HUD_updateGearVariables; }];
player addEventHandler ["InventoryClosed", { call HUD_updateGearVariables; }];

// Note: the reference mod also hooked ACE's "ace_arsenal_displayClosed"
// event here. That's an ACE-specific event (this build has no ACE
// dependency), so it's left out - the vanilla arsenal hook below still
// covers gear updates after closing Arsenal in the base game and in
// most ACE Arsenal setups. Add it back with CBA_fnc_addEventHandler
// if you do run ACE and want that extra coverage.
[missionNamespace, "arsenalClosed", {
	call HUD_updateGearVariables;
}] call BIS_fnc_addScriptedEventHandler;
