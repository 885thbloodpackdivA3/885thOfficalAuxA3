/*
	885th Bloodpack Division - Clone HUD - EMP
	---------------------------------------------------------------
	Hooks the 885_Armor EMP detector: every player inside the blast of EMP
	ammo (JLTS_isEMPAmmo = 1 - 885th EMP grenade / launcher round, JLTS EMP)
	gets the "885th_shield_empHit" CBA event on their own machine.

	With the HUD up, a hit:
	  1. Static burst + "EMP DETECTED", then the suit goes offline for
	     EMP_TIME seconds (x EMP_RC_MULT on Republic Commando helmets,
	     x EMP_P1_MULT on Phase 1), then the fast reboot.
	  2. Everything that runs off the suit stops: radar, threat scanner /
	     targeting icons, low light, mine detector, squad list, pings /
	     intel, Tac Map, cTab link and helm cam, system messages.
	     (HUD_bootComplete is held false; the vanilla HUD stays hidden.)
	  3. Counterplay: ACE self action "Emergency Suit Reboot" (3 s) and,
	     for engineers (EMP_REBOOT_WHO), "Reboot Suit" on someone else
	     (4 s) - either cuts the outage short.
	  4. EMP_BURN_CHANCE: small chance of an electrical burn on the visor
	     (a dirt-type visor overlay: wipe / repair / dirt timer clear it).

	Test from the debug console:  [player] call BPD_CloneHUD_fnc_empHit;
*/

BPD_CloneHUD_empOffline = false;
BPD_CloneHUD_empUntil = 0;

BPD_CloneHUD_fnc_empOpt = {
	params ["_k", "_def"];
	missionNamespace getVariable [format ["BPD_CloneHUD_EMP_%1", _k], _def]
};

// ---------- electric burn on the visor ----------
BPD_CloneHUD_fnc_empBurn = {
	if (isNil "BPD_CloneHUD_crackList") exitWith {};
	if !(["ENABLED", true] call BPD_CloneHUD_fnc_crackOpt) exitWith {};
	if (!alive player || {!(call BPD_CloneHUD_fnc_crackIsClone)}) exitWith {};
	private _sx = safezoneX; private _sy = safezoneY; private _sw = safezoneW; private _sh = safezoneH;
	private _h = _sh * random [0.45, 0.6, 0.8];
	private _w = _h / pixelH * pixelW;
	private _px = _sx + _sw * (random [0.15, 0.5, 0.85]) - _w / 2;
	private _py = _sy + _sh * (random [0.15, 0.45, 0.8]) - _h / 2;
	private _tex = format ["\885th_CloneHUD\textures\emp\visor_burn_%1_ca.paa", 1 + floor random 3];
	[true, round (["DIRT_MAX", 3] call BPD_CloneHUD_fnc_crackOpt)] call BPD_CloneHUD_fnc_crackTrim;
	BPD_CloneHUD_crackList pushBack [_tex, _px, _py, _w, _h, random 360, diag_tickTime, controlNull, true];
};

// ---------- the EMP layer (static + status text) ----------
BPD_CloneHUD_fnc_empLayer = {
	private _d = uiNamespace getVariable ["BPD_CloneHUD_EMP_BASE", displayNull];
	if (isNull _d) then {
		"BPD_CloneHUD_EMP_LAYER" cutRsc ["BPD_CloneHUD_EMP_BASE", "PLAIN", -1, false];
		_d = uiNamespace getVariable ["BPD_CloneHUD_EMP_BASE", displayNull];
	};
	if (isNull _d) exitWith {[controlNull, controlNull]};
	private _pic = _d displayCtrl 27750;
	if (isNull _pic) then {
		_pic = _d ctrlCreate ["RscPicture", 27750];
		_pic ctrlSetPosition [safezoneX, safezoneY, safezoneW, safezoneH];
		_pic ctrlCommit 0;
	};
	private _txt = _d displayCtrl 27751;
	if (isNull _txt) then {
		_txt = _d ctrlCreate ["RscStructuredText", 27751];
		_txt ctrlSetPosition [safezoneX, safezoneY + safezoneH * 0.16, safezoneW, safezoneH * 0.1];
		_txt ctrlSetBackgroundColor [0, 0, 0, 0];
		_txt ctrlCommit 0;
	};
	[_pic, _txt]
};

BPD_CloneHUD_fnc_empLayerClose = {
	"BPD_CloneHUD_EMP_LAYER" cutText ["", "PLAIN", 0, false];
};

// ---------- hit ----------
BPD_CloneHUD_fnc_empHit = {
	params [["_unit", player]];
	if (!hasInterface || {_unit != player} || {!alive player}) exitWith {};
	if !(["ENABLED", true] call BPD_CloneHUD_fnc_empOpt) exitWith {};
	if !(headgear player in (missionNamespace getVariable ["HUD_helmets", []])) exitWith {};

	// outage length by helmet tier
	private _t = ["TIME", 10] call BPD_CloneHUD_fnc_empOpt;
	if (player getVariable ["RC_INHELMET", false]) then { _t = _t * (["RC_MULT", 0.5] call BPD_CloneHUD_fnc_empOpt); };
	if (player getVariable ["P1_INHELMET", false]) then { _t = _t * (["P1_MULT", 1.25] call BPD_CloneHUD_fnc_empOpt); };

	// small chance of an electrical burn on the visor (HUD up or not)
	if (random 1 < (["BURN_CHANCE", 0.1] call BPD_CloneHUD_fnc_empOpt)) then { call BPD_CloneHUD_fnc_empBurn; };

	// already offline: a second EMP extends it
	if (BPD_CloneHUD_empOffline) exitWith {
		BPD_CloneHUD_empUntil = BPD_CloneHUD_empUntil max (diag_tickTime + _t);
		playSound "glitch_short";
	};
	// only a running HUD can be knocked offline
	if !(player getVariable ["HUD_bootComplete", false]) exitWith {};

	BPD_CloneHUD_empOffline = true;
	BPD_CloneHUD_empUntil = diag_tickTime + _t;
	player setVariable ["BPD_CloneHUD_empOffline", true, true];
	[] spawn BPD_CloneHUD_fnc_empRun;
};

// cut the remaining outage short (reboot actions)
BPD_CloneHUD_fnc_empRebootNow = {
	if (!BPD_CloneHUD_empOffline) exitWith {};
	BPD_CloneHUD_empUntil = BPD_CloneHUD_empUntil min (diag_tickTime + 0.5);
};

// ---------- the outage ----------
BPD_CloneHUD_fnc_empRun = {
	private _unit = player;
	private _mode = if (isNil "BPD_CloneHUD_fnc_flashMode") then {1} else { call BPD_CloneHUD_fnc_flashMode };
	private _layers = if (isNil "BPD_CloneHUD_fnc_downCtrls") then {[]} else { call BPD_CloneHUD_fnc_downCtrls };

	// save each control's own fade (the down-haywire's saved base if that's running)
	private _haywire = (missionNamespace getVariable ["BPD_CloneHUD_downState", 0]) == 1;
	{ { _x setVariable ["bpdFadeE", [ctrlFade _x, _x getVariable ["bpdFade0", 0]] select _haywire]; } forEach _x; } forEach _layers;

	// --- subsystems off ---
	private _icons = missionNamespace getVariable ["HUD_showIcons", true];
	private _lowLight = missionNamespace getVariable ["HUD_lowLight", false];
	HUD_showIcons = false;                                   // scanner / targeting icons
	if (_lowLight) then { HUD_lowLight = false; setAperture -1; };
	if (!isNil "BPD_CloneHUD_fnc_stopHcam" && {missionNamespace getVariable ["BPD_CloneHUD_hcamActive", false]}) then { call BPD_CloneHUD_fnc_stopHcam; };
	BPD_CloneHUD_tacmapActive = false;
	if (!isNil "cTabIfOpen" && {!isNil "cTab_fnc_close"}) then { call cTab_fnc_close; };
	player setVariable ["HUD_bootComplete", false];          // radar, squad list, mine detector, pings, intel...
	HUD_systemMessageAllowed = false;

	(call BPD_CloneHUD_fnc_empLayer) params ["_pic", "_txt"];
	private _size = safezoneH / 0.9;
	private _frame = { params ["_a"];
		_pic ctrlSetText format ["\885th_CloneHUD\textures\hcam\kia_static_%1_ca.paa", 1 + floor random 4];
		_pic ctrlSetTextColor [1, 1, 1, _a];
	};
	private _say = { params ["_t", "_col"];
		_txt ctrlSetStructuredText parseText format ["<t align='center' size='%1' font='PuristaBold' color='%2'>%3</t>", _size, _col, _t];
	};
	private _abort = { !alive _unit || {player != _unit} || {!(player getVariable ["HUD_hudInitiated", false])} || {!(headgear player in (missionNamespace getVariable ["HUD_helmets", []]))} };

	// 1) static burst, HUD drops out
	playSound "glitch_short";
	{ { _x ctrlSetFade 1; _x ctrlCommit ([0.25, 0.12, 0] select _mode); } forEach _x; } forEach _layers;
	["EMP DETECTED", "#5fb8ff"] call _say;
	private _end = diag_tickTime + 0.8;
	private _swap = -1e9;
	while { diag_tickTime < _end && {!(call _abort)} } do {
		private _k = (_end - diag_tickTime) / 0.8;
		if (diag_tickTime - _swap >= ([1e9, 0.4, 0] select _mode) || {ctrlText _pic == ""}) then { _swap = diag_tickTime; [0.85 * _k + 0.1] call _frame; } else { _pic ctrlSetTextColor [1, 1, 1, 0.85 * _k + 0.1]; };
		sleep 0.06;
	};
	_pic ctrlSetTextColor [1, 1, 1, 0.08];

	// 2) offline - the HUD goes haywire like being downed (Flashing Effects
	// respected: full ~7 changes/s with drop-outs + blackout frames,
	// reduced ~2/s smooth fades, off = one steady dim), with a countdown
	private _glitch = {
		if (_mode == 0) exitWith {
			{ { _x ctrlSetFade ((_x getVariable ["bpdFadeE", 0]) max 0.55); _x ctrlCommit 0.6; } forEach _x; } forEach _layers;
		};
		private _blackout = _mode == 2 && {random 1 < 0.06};
		private _drop = [0, 0.05, 0.12] select _mode;
		private _dim = [0, 0.2, 0.30] select _mode;
		private _commit = [0, 0.35, 0] select _mode;
		{
			{
				private _base = _x getVariable ["bpdFadeE", 0];
				private _f = call {
					if (_blackout) exitWith {1};
					private _r = random 1;
					if (_r < _drop) exitWith {[1, _base max 0.8] select (_mode == 1)};
					if (_r < _dim) exitWith {_base max (0.4 + random 0.4)};
					_base
				};
				_x ctrlSetFade _f;
				_x ctrlCommit _commit;
			} forEach _x;
		} forEach _layers;
		if (random 1 < ([0, 0.02, 0.035] select _mode)) then { playSound "glitch_short"; };
	};
	private _dimmed = false;
	while { diag_tickTime < BPD_CloneHUD_empUntil && {!(call _abort)} } do {
		private _left = ceil (BPD_CloneHUD_empUntil - diag_tickTime);
		[format ["EMP - SUIT SYSTEMS OFFLINE<br/><t size='0.6' color='#9fb3bb'>restarting in %1 s</t>", _left], "#ff3b30"] call _say;
		if (_mode > 0 || {!_dimmed}) then { call _glitch; _dimmed = true; };
		if (_mode == 2 && {random 1 < 0.08}) then { [0.08 + random 0.1] call _frame; };
		sleep ([0.5, 0.45 + random 0.2, 0.09 + random 0.08] select _mode);
	};

	// aborted (died / helmet off / HUD turned off): put things back quietly
	if (call _abort) exitWith {
		call BPD_CloneHUD_fnc_empLayerClose;
		{ { _x ctrlSetFade (_x getVariable ["bpdFadeE", 0]); _x ctrlCommit 0; } forEach _x; } forEach _layers;
		if (alive _unit && {player == _unit}) then { HUD_showIcons = _icons; };
		BPD_CloneHUD_empOffline = false;
		_unit setVariable ["BPD_CloneHUD_empOffline", false, true];
	};

	// 3) fast reboot
	["REBOOTING SUIT SYSTEMS...", "#ffb347"] call _say;
	_pic ctrlSetTextColor [1, 1, 1, 0];
	playSound "glitch_short";
	sleep 0.35;
	player setVariable ["HUD_bootComplete", true];
	HUD_systemMessageAllowed = true;
	private _steps = ["VISOR DISPLAY", "VITALS MONITOR", "TACTICAL DATA"];
	{
		{ _x ctrlSetFade (_x getVariable ["bpdFadeE", 0]); _x ctrlCommit ([0.35, 0.25, 0.15] select _mode); } forEach _x;
		[format ["REBOOT %1 ... <t color='#3cb371'>OK</t>", _steps param [_forEachIndex, "SYSTEMS"]], "#ffb347"] call _say;
		playSound "click";
		sleep 0.28;
	} forEach _layers;
	HUD_showIcons = _icons;
	if (_lowLight && {missionNamespace getVariable ["ALLOW_LOWLIGHT", true]}) then { HUD_lowLight = true; setAperture HUD_lowLightAperture; };
	["SUIT SYSTEMS RESTORED", "#3cb371"] call _say;
	["<t color='#3cb371' font='PuristaBold'>SUIT SYSTEMS RESTORED</t> - EMP cleared", "bpdEmp", 6] call HUD_fnc_addSystemMessage;
	BPD_CloneHUD_empOffline = false;
	player setVariable ["BPD_CloneHUD_empOffline", false, true];
	sleep 1;
	if (!BPD_CloneHUD_empOffline) then { call BPD_CloneHUD_fnc_empLayerClose; };
};

// ---------- events ----------
["885th_shield_empHit", { params ["_unit"]; [_unit] call BPD_CloneHUD_fnc_empHit; }] call CBA_fnc_addEventHandler;
// someone rebooted my suit for me
["BPD_CloneHUD_empReboot", { params ["_unit"]; if (_unit == player) then { call BPD_CloneHUD_fnc_empRebootNow; }; }] call CBA_fnc_addEventHandler;

// ---------- reboot actions (ACE) ----------
BPD_CloneHUD_fnc_empCanRebootOther = {
	params ["_t"];
	private _who = ["REBOOT_WHO", 1] call BPD_CloneHUD_fnc_empOpt; // 0 nobody, 1 engineers / EOD, 2 anyone
	if (_who == 0 || {isNull _t} || {!alive _t} || {_t == player}) exitWith {false};
	if !(_t getVariable ["BPD_CloneHUD_empOffline", false]) exitWith {false};
	if (player distance _t > 4) exitWith {false};
	if (_who == 1 && {isNil "BPD_CloneHUD_fnc_isEngineer" || {!(call BPD_CloneHUD_fnc_isEngineer)}}) exitWith {false};
	true
};

if (isClass (configFile >> "CfgPatches" >> "ace_interact_menu")) then {
	private _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\reammo_ca.paa";
	private _self = ["BPD_CloneHUD_empRebootSelf", "Emergency Suit Reboot", _icon, {
		[3, [], { call BPD_CloneHUD_fnc_empRebootNow; }, {}, "Emergency suit reboot...",
			{ BPD_CloneHUD_empOffline }] call ace_common_fnc_progressBar;
	}, {
		_player == _target && {BPD_CloneHUD_empOffline} && {["SELF_REBOOT", true] call BPD_CloneHUD_fnc_empOpt}
		&& {BPD_CloneHUD_empUntil - diag_tickTime > 2}
	}] call ace_interact_menu_fnc_createAction;
	["CAManBase", 1, ["ACE_SelfActions", "ACE_Equipment"], _self, true] call ace_interact_menu_fnc_addActionToClass;

	private _other = ["BPD_CloneHUD_empRebootOther", "Reboot Suit", _icon, {
		[4, [_target], {
			params ["_args"];
			["BPD_CloneHUD_empReboot", [_args select 0], _args select 0] call CBA_fnc_targetEvent;
		}, {}, format ["Rebooting %1's suit...", name _target], {
			params ["_args"];
			[_args select 0] call BPD_CloneHUD_fnc_empCanRebootOther
		}] call ace_common_fnc_progressBar;
	}, { [_target] call BPD_CloneHUD_fnc_empCanRebootOther }] call ace_interact_menu_fnc_createAction;
	["CAManBase", 0, ["ACE_MainActions"], _other, true] call ace_interact_menu_fnc_addActionToClass;
};
