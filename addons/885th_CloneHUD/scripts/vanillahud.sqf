/*
	885th Bloodpack Division - Clone HUD - Vanilla HUD Replacement
	---------------------------------------------------------------
	Hides the vanilla Arma HUD (and optionally DUI Squad Radar) while the
	Clone HUD is up, and puts it all back the moment it isn't.

	WHY THE OLD VERSION DIDN'T STICK: it called showHUD once and then
	assumed it stayed applied. ACE keeps its own stack of showHUD masks
	and re-runs showHUD with only ITS masks whenever anything calls
	ace_common_fnc_showHud (interaction menu, arsenal, spectator, other
	mods...), which silently wiped ours - and since our "applied" flag
	was still true we never re-hid. Now:
	  - With ACE loaded, our mask goes INTO ACE's stack (reason
	    "bpd_clonehud"), so ACE itself keeps it applied.
	  - Every tick we also compare the live shownHUD against what we
	    want hidden and re-apply if anything (ACE or not) turned an
	    element back on.

	Which vanilla elements get hidden is chosen per element in Addon
	Options > 885th BPD Clone HUD - General > IV. Vanilla HUD:
	  showHUD index  element                    setting
	  1  info        weapon / ammo / stance     BPD_CloneHUD_HIDE_INFO
	  2  radar       vehicle radar              BPD_CloneHUD_HIDE_RADAR
	  3,4 compass    compass + direction        BPD_CloneHUD_HIDE_COMPASS
	  6  group       squad bar                  BPD_CloneHUD_HIDE_GROUP
	  8  panels      vehicle panels / GPS       BPD_CloneHUD_HIDE_PANELS
	  9  kills       "x killed by y" messages   BPD_CloneHUD_HIDE_KILLS
	Never touched: 0 (scripted HUD - would hide the Clone HUD's own
	3D icons), 5 (scroll/action menu - "Activate HUD" lives there),
	7 (weapon cursors).

	DUI Squad Radar isn't part of showHUD - BPD_CloneHUD_HIDE_DUI flips
	DUI's own toggle (diwako_dui_main_toggled_off) and restores whatever
	it was before.

	Applies while ALL of these are true:
	  - BPD_CloneHUD_REPLACE_VANILLA_HUD is on
	  - player alive, wearing a Clone HUD helmet, boot-up finished
	  - Zeus not open
	  - first person, OR BPD_CloneHUD_REPLACE_VANILLA_HUD_3RD is on
	  - on foot, OR BPD_CloneHUD_REPLACE_VANILLA_HUD_VEHICLES is on

	Public functions (mission makers can call these too):
	  call BPD_CloneHUD_fnc_hideVanillaHud;
	  call BPD_CloneHUD_fnc_restoreVanillaHud;
*/

BPD_CloneHUD_vanillaHudApplied = false;
BPD_CloneHUD_vanillaHudSaved = [];
BPD_CloneHUD_vanillaHudMask = [];
BPD_CloneHUD_duiSaved = nil;
BPD_CloneHUD_aceShowHud = isClass (configFile >> "CfgPatches" >> "ace_common");

// 10-element showHUD mask: [hud, info, radar, compass, direction, menu, group, cursors, panels, kills]
BPD_CloneHUD_fnc_vanillaMask = {
	private _m = [true,true,true,true,true,true,true,true,true,true];
	// With ACE UI loaded the weapon/ammo/stance panel is hidden per-control
	// (BPD_CloneHUD_fnc_aceUiHide), so leave showHUD "info" alone: mods
	// like Shadow Legion Armory force showHUD on EVERY frame, and toggling
	// "info" against that rebuilds the vanilla info displays = flicker.
	if ((missionNamespace getVariable ["BPD_CloneHUD_HIDE_INFO", true]) && {isNil "ace_ui_fnc_setElementVisibility"}) then { _m set [1, false]; };
	if (missionNamespace getVariable ["BPD_CloneHUD_HIDE_RADAR", true]) then { _m set [2, false]; };
	if (missionNamespace getVariable ["BPD_CloneHUD_HIDE_COMPASS", true]) then { _m set [3, false]; _m set [4, false]; };
	if (missionNamespace getVariable ["BPD_CloneHUD_HIDE_GROUP", true]) then { _m set [6, false]; };
	if (missionNamespace getVariable ["BPD_CloneHUD_HIDE_PANELS", false]) then { _m set [8, false]; };
	if (missionNamespace getVariable ["BPD_CloneHUD_HIDE_KILLS", false]) then { _m set [9, false]; };
	_m
};

// Pushes the mask to the engine (via ACE's stack when ACE is loaded).
BPD_CloneHUD_fnc_pushVanillaMask = {
	params ["_mask"];
	if (BPD_CloneHUD_aceShowHud && {!isNil "ace_common_fnc_showHud"}) then {
		["bpd_clonehud", +_mask] call ace_common_fnc_showHud;
	} else {
		// Only ever switch things OFF - anything the mission already hid stays hidden.
		private _new = +BPD_CloneHUD_vanillaHudSaved;
		{ if (!_x) then { _new set [_forEachIndex, false]; }; } forEach _mask;
		showHUD _new;
	};
};

// ACE UI per-control hiding for the weapon / ammo / stance panel.
// This fades the individual IGUI controls (ace_ui_fnc_setElementVisibility,
// ACE's public API), which a showHUD call from any other mod can NOT undo -
// so this part can't flicker no matter who else is calling showHUD. ACE UI
// also re-applies it itself whenever the IGUI displays get rebuilt.
BPD_CloneHUD_ACEUI_ELEMENTS = [
	"weaponName","weaponNameBackground","firingMode","ammoType","ammoCount","magCount",
	"throwableName","throwableCount","zeroing","weaponLowerInfoBackground","stance"
];
BPD_CloneHUD_aceUiApplied = false;
BPD_CloneHUD_aceUiOwned = []; // only the elements WE set - never unset another mod's

BPD_CloneHUD_fnc_aceUiHide = {
	if (BPD_CloneHUD_aceUiApplied || {isNil "ace_ui_fnc_setElementVisibility"}) exitWith {};
	BPD_CloneHUD_aceUiApplied = true;
	private _failed = [];
	{
		if (["bpd_clonehud", true, _x, false] call ace_ui_fnc_setElementVisibility) then {
			BPD_CloneHUD_aceUiOwned pushBack _x;
		} else {
			_failed pushBack _x;
		};
	} forEach BPD_CloneHUD_ACEUI_ELEMENTS;
	if (count _failed > 0) then {
		diag_log format ["885th_CloneHUD: ACE UI refused to hide %1 (already set by another mod, or not on screen yet).", _failed];
	};
};

BPD_CloneHUD_fnc_aceUiRestore = {
	if (!BPD_CloneHUD_aceUiApplied || {isNil "ace_ui_fnc_setElementVisibility"}) exitWith {};
	BPD_CloneHUD_aceUiApplied = false;
	{
		// hand the element back at whatever the player's own ACE UI setting says
		["bpd_clonehud", false, _x, missionNamespace getVariable ["ace_ui_" + _x, true]] call ace_ui_fnc_setElementVisibility;
	} forEach BPD_CloneHUD_aceUiOwned;
	BPD_CloneHUD_aceUiOwned = [];
};

BPD_CloneHUD_vanillaLastPush = 0;
BPD_CloneHUD_vanillaStomps = 0;
BPD_CloneHUD_vanillaStompTimes = [];
BPD_CloneHUD_vanillaBackedOff = false;

BPD_CloneHUD_fnc_hideVanillaHud = {
	private _mask = call BPD_CloneHUD_fnc_vanillaMask;

	if (!BPD_CloneHUD_vanillaHudApplied) then {
		BPD_CloneHUD_vanillaHudSaved = (+shownHUD) select [0, 10];
		BPD_CloneHUD_vanillaHudApplied = true;
		[_mask] call BPD_CloneHUD_fnc_pushVanillaMask;
		BPD_CloneHUD_vanillaHudMask = _mask;
		BPD_CloneHUD_vanillaLastPush = diag_tickTime;
		diag_log format ["885th_CloneHUD: vanilla HUD hidden - mask %1 (ACE stack: %2).", _mask, BPD_CloneHUD_aceShowHud];
	} else {
		// Already applied: re-push if the settings changed, or if anything
		// turned a hidden element back on behind our back. Throttled to
		// once every 2s so a mod that forces showHUD on every frame can't
		// turn this into a visible on/off strobe.
		private _live = shownHUD;
		private _stomped = false;
		{ if (!_x && {_live param [_forEachIndex, false]}) exitWith { _stomped = true; }; } forEach _mask;
		private _changed = !(_mask isEqualTo BPD_CloneHUD_vanillaHudMask);
		// Back off if another mod is re-forcing showHUD constantly (e.g. Shadow
		// Legion Armory does it every frame): 3 stomps inside 15s = give up on
		// the showHUD part until the HUD is next re-applied, instead of strobing.
		if (_stomped && {!_changed} && {BPD_CloneHUD_vanillaBackedOff}) exitWith {};
		if (_changed || {_stomped && {diag_tickTime - BPD_CloneHUD_vanillaLastPush > 2}}) then {
			if (_stomped) then {
				BPD_CloneHUD_vanillaStomps = BPD_CloneHUD_vanillaStomps + 1;
				BPD_CloneHUD_vanillaStompTimes = (BPD_CloneHUD_vanillaStompTimes select {diag_tickTime - _x < 15}) + [diag_tickTime];
				if (BPD_CloneHUD_vanillaStomps in [1, 10, 100]) then {
					diag_log format ["885th_CloneHUD: another script turned the vanilla HUD back on (%1 times so far) - live %2, wanted %3.", BPD_CloneHUD_vanillaStomps, _live, _mask];
				};
				if (count BPD_CloneHUD_vanillaStompTimes >= 3) exitWith {
					BPD_CloneHUD_vanillaBackedOff = true;
					private _fought = [];
					{ if (!_x && {_live param [_forEachIndex, false]}) then { _fought pushBack (["hud","info","radar","compass","direction","menu","group","cursors","panels","kills"] select _forEachIndex); }; } forEach _mask;
					diag_log format ["885th_CloneHUD: another mod keeps forcing showHUD %1 back on - backing off so it doesn't flicker. Known cause: Shadow Legion Armory (ShadowLegion_fnc_updateHUD re-applies showHUD every frame).", _fought];
				};
			};
			if (BPD_CloneHUD_vanillaBackedOff && {!_changed}) exitWith {};
			[_mask] call BPD_CloneHUD_fnc_pushVanillaMask;
			BPD_CloneHUD_vanillaHudMask = _mask;
			BPD_CloneHUD_vanillaLastPush = diag_tickTime;
		};
	};

	if (missionNamespace getVariable ["BPD_CloneHUD_HIDE_INFO", true]) then {
		call BPD_CloneHUD_fnc_aceUiHide;
	} else {
		call BPD_CloneHUD_fnc_aceUiRestore;
	};

	// DUI Squad Radar
	if ((missionNamespace getVariable ["BPD_CloneHUD_HIDE_DUI", true]) && {!isNil "diwako_dui_main_toggled_off"}) then {
		if (isNil "BPD_CloneHUD_duiSaved") then {
			BPD_CloneHUD_duiSaved = diwako_dui_main_toggled_off;
		};
		if (!diwako_dui_main_toggled_off) then {
			diwako_dui_main_toggled_off = true;
			["diwako_dui_main_hudToggled", [true]] call CBA_fnc_localEvent;
		};
	} else {
		call BPD_CloneHUD_fnc_restoreDui;
	};
};

BPD_CloneHUD_fnc_restoreDui = {
	if (isNil "BPD_CloneHUD_duiSaved") exitWith {};
	if (!isNil "diwako_dui_main_toggled_off" && {diwako_dui_main_toggled_off isNotEqualTo BPD_CloneHUD_duiSaved}) then {
		diwako_dui_main_toggled_off = BPD_CloneHUD_duiSaved;
		["diwako_dui_main_hudToggled", [BPD_CloneHUD_duiSaved]] call CBA_fnc_localEvent;
	};
	BPD_CloneHUD_duiSaved = nil;
};

BPD_CloneHUD_fnc_restoreVanillaHud = {
	call BPD_CloneHUD_fnc_restoreDui;
	call BPD_CloneHUD_fnc_aceUiRestore;
	if (!BPD_CloneHUD_vanillaHudApplied) exitWith {};
	BPD_CloneHUD_vanillaHudApplied = false;
	BPD_CloneHUD_vanillaHudMask = [];
	BPD_CloneHUD_vanillaStompTimes = [];
	BPD_CloneHUD_vanillaBackedOff = false;
	if (BPD_CloneHUD_aceShowHud && {!isNil "ace_common_fnc_showHud"}) then {
		["bpd_clonehud", []] call ace_common_fnc_showHud;
	} else {
		if (count BPD_CloneHUD_vanillaHudSaved > 0) then {
			showHUD BPD_CloneHUD_vanillaHudSaved;
		};
	};
	diag_log format ["885th_CloneHUD: vanilla HUD restored (saved %1, ACE stack: %2).", BPD_CloneHUD_vanillaHudSaved, BPD_CloneHUD_aceShowHud];
};

BPD_CloneHUD_fnc_shouldReplaceVanillaHud = {
	if (!(missionNamespace getVariable ["BPD_CloneHUD_REPLACE_VANILLA_HUD", true])) exitWith {false};
	if (!alive player) exitWith {false};
	if (!(headgear player in (missionNamespace getVariable ["HUD_helmets", []]))) exitWith {false};
	if (!(player getVariable ["HUD_bootComplete", false])) exitWith {false};
	if (!isNull (findDisplay 312)) exitWith {false}; // Zeus
	if (!(cameraView in ["INTERNAL","GUNNER"]) && {!(missionNamespace getVariable ["BPD_CloneHUD_REPLACE_VANILLA_HUD_3RD", true])}) exitWith {false};
	if ((vehicle player != player) && {!(missionNamespace getVariable ["BPD_CloneHUD_REPLACE_VANILLA_HUD_VEHICLES", false])}) exitWith {false};
	true
};

// One loop for the whole session (survives respawn - it just reads the
// current state every tick). Guarded so it can never be started twice.
if (isNil "BPD_CloneHUD_vanillaHudLoop") then {
	BPD_CloneHUD_vanillaHudLoop = [] spawn {
		waitUntil { sleep 1; !isNull player };
		while {true} do {
			if (call BPD_CloneHUD_fnc_shouldReplaceVanillaHud) then {
				call BPD_CloneHUD_fnc_hideVanillaHud;
			} else {
				call BPD_CloneHUD_fnc_restoreVanillaHud;
			};
			sleep 0.25;
		};
	};
};
