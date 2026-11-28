/*
	885th Bloodpack Division - Clone HUD - Ammo counter styles
	---------------------------------------------------------------
	BPD_CloneHUD_AMMO_STYLE (per player, "1. What's On Screen"):
	  0 Default  - the helmet's own info box (ammo / mags beside heading
	               and range), unchanged.
	  1 Style A  - "BF2 Classic": wide panel with health + stamina bars
	               over a tray holding the weapon icon, rounds in the mag,
	               spare mags, and the grenade icon + count.
	  2 Style B  - "Classic Inspired": compact panel - grenade badge,
	               weapon plate with rounds / mags, health + stamina bars.

	With Style A or B the helmet's info box loses its ammo column
	(textures\ammo\*_ammoDisplay_noAmmo.paa) and keeps heading / range.
	The panel is placed like every other element, through the "Ammo
	Counter" Layout settings (default Bottom Right).

	Panel art is drawn on its own canvas; every element's spot on it is
	listed below in canvas pixels, so the script can lay the live
	controls (bars, icons, numbers) exactly over the art at any scale.
*/

// [style][vitals on] -> [texture, canvasW, canvasH, widthOnScreen (x safezoneW), rects]
// rects: [x, y, w, h] in canvas pixels. "vit" = vitals bar fill,
// "stat" = status text (its own strip in A, written over the bar in B).
BPD_CloneHUD_ammoArt = [
	[],
	[
		["\885th_CloneHUD\textures\ammo\styleA_panel_noBars.paa", 1024, 256, 0.19, createHashMapFromArray [
			["weap",  [80, 44, 350, 170]],
			["ammo",  [420, 36, 180, 104]],
			["mags",  [420, 134, 180, 80]],
			["gren",  [664, 80, 100, 100]],
			["grenN", [764, 36, 130, 180]]
		]],
		["\885th_CloneHUD\textures\ammo\styleA_panel.paa", 1024, 512, 0.19, createHashMapFromArray [
			["vit",   [44, 44, 800, 52]],
			["stat",  [52, 130, 740, 52]],
			["weap",  [80, 250, 350, 190]],
			["ammo",  [420, 252, 180, 108]],
			["mags",  [420, 352, 180, 88]],
			["gren",  [664, 296, 100, 100]],
			["grenN", [764, 252, 130, 190]]
		]]
	],
	[
		["\885th_CloneHUD\textures\ammo\styleB_panel_noBars.paa", 512, 128, 0.17, createHashMapFromArray [
			["weap",  [150, 26, 220, 85]],
			["ammo",  [350, 20, 135, 64]],
			["mags",  [350, 80, 135, 34]],
			["gren",  [38, 30, 58, 58]],
			["grenN", [80, 76, 44, 38]]
		]],
		["\885th_CloneHUD\textures\ammo\styleB_panel.paa", 512, 256, 0.17, createHashMapFromArray [
			["vit",   [22, 166, 468, 40]],
			["stat",  [32, 166, 450, 40]],
			["weap",  [150, 26, 220, 85]],
			["ammo",  [350, 20, 135, 64]],
			["mags",  [350, 80, 135, 34]],
			["gren",  [38, 30, 58, 58]],
			["grenN", [80, 76, 44, 38]]
		]]
	]
];

// "mode" = fire mode on Style A / B (shares the mags box, left-aligned);
// "dmode" = fire mode on the Default info box (placed per helmet tier).
BPD_CloneHUD_ammoKeys = ["panel", "vit", "stat", "weap", "ammo", "mags", "gren", "grenN", "mode", "dmode", "zero"];

// Current zeroing in metres for the weapon in hand (0 = none / unknown).
BPD_CloneHUD_fnc_zeroing = {
	// on foot (or firing from a vehicle seat with your own weapon) only
	private _z = if (vehicle player != player && {(weaponState player) select 0 == ""}) then {0} else {
		if (currentWeapon player == "") then {0} else { currentZeroing player }
	};
	if (_z isEqualType []) then { _z = _z param [0, 0]; };
	round _z
};

// Default info box: fire mode spot per tier, in safezone fractions -
// just under the box (P1 / P2) or inside the big ring under the rounds (RC).
BPD_CloneHUD_modeDefaultRects = createHashMapFromArray [
	["P1", [0.855781, 0.943, 0.04125, 0.026]],
	["P2", [0.878646, 0.906, 0.04125, 0.026]],
	["RC", [0.855781, 0.821, 0.04125, 0.026]]
];

// Short fire mode label for whatever the player is firing:
// AUTO (autoFire), BURST (burst > 1), SEMI, or "" for no weapon /
// binoculars / throwables.
BPD_CloneHUD_fnc_fireMode = {
	private _veh = vehicle player;
	private _ws = if (_veh != player) then {
		weaponState [_veh, (assignedVehicleRole player) param [1, [-1]]]
	} else {
		weaponState player
	};
	_ws params [["_weap", ""], ["_muzzle", ""], ["_mode", ""]];
	if (_weap == "") exitWith {""};
	private _cfg = configFile >> "CfgWeapons" >> _weap;
	if (getNumber (_cfg >> "type") == 4096) exitWith {""}; // binoculars / designators
	if (_muzzle != "" && {_muzzle != _weap} && {_muzzle != "this"}) then { _cfg = _cfg >> _muzzle; };
	if (_mode != "" && {_mode != "this"} && {_mode != _muzzle} && {isClass (_cfg >> _mode)}) then { _cfg = _cfg >> _mode; };
	if (getNumber (_cfg >> "autoFire") == 1) exitWith {"AUTO"};
	if (getNumber (_cfg >> "burst") > 1) exitWith {"BURST"};
	"SEMI"
};

BPD_CloneHUD_fnc_ammoVitalsOn = {
	(missionNamespace getVariable ["BPD_CloneHUD_AMMO_VITALS", 1]) > 0
};

// Called from hudInit once the indicator display exists.
BPD_CloneHUD_fnc_ammoCreate = {
	private _disp = uiNamespace getVariable ["BPD_CloneHUD_INDICATOR_BASE", displayNull];
	if (isNull _disp) exitWith {};
	private _ctrls = createHashMap;
	{
		private _type = switch (_x) do {
			case "panel"; case "weap"; case "gren": { "RscPicture" };
			case "vit": { "RscText" };
			default { "RscStructuredText" };
		};
		private _c = _disp ctrlCreate [_type, 27690 + _forEachIndex];
		_c ctrlSetText "";
		if (_type != "RscPicture") then { _c ctrlSetBackgroundColor [0,0,0,0]; };
		_c ctrlShow false;
		_c ctrlCommit 0;
		_ctrls set [_x, _c];
	} forEach BPD_CloneHUD_ammoKeys;
	uiNamespace setVariable ["BPD_CloneHUD_ammoCtrls", _ctrls];
	BPD_CloneHUD_ammoShownStyle = -1;
	BPD_CloneHUD_ammoArtState = "";
	call BPD_CloneHUD_fnc_ammoLayout;
};

// Positions the panel and every live element over its art.
BPD_CloneHUD_fnc_ammoLayout = {
	private _ctrls = uiNamespace getVariable ["BPD_CloneHUD_ammoCtrls", createHashMap];
	if (count _ctrls == 0) exitWith {};
	private _style = missionNamespace getVariable ["BPD_CloneHUD_AMMO_STYLE", 0];
	if (_style < 1 || {_style > 2}) exitWith {};
	private _vitals = call BPD_CloneHUD_fnc_ammoVitalsOn;
	((BPD_CloneHUD_ammoArt select _style) select ([0, 1] select _vitals)) params ["_tex", "_cw", "_ch", "_wFrac", "_rects"];
	private _w = _wFrac * safezoneW * (["AMMO"] call BPD_CloneHUD_fnc_layoutScale);
	private _h = _w * (_ch / _cw) * (pixelH / pixelW);
	(["AMMO", _w, _h] call BPD_CloneHUD_fnc_layoutPos) params ["_px", "_py"];
	private _toScreen = {
		params ["_rx", "_ry", "_rw", "_rh"];
		[_px + (_rx / _cw) * _w, _py + (_ry / _ch) * _h, (_rw / _cw) * _w, (_rh / _ch) * _h]
	};
	private _panel = _ctrls get "panel";
	_panel ctrlSetText _tex;
	_panel ctrlSetPosition [_px, _py, _w, _h];
	_panel ctrlCommit 0;
	{
		private _c = _ctrls get _x;
		// fire mode sits in the empty strip under the weapon picture
		// ...and zeroing in the strip above it
		private _rect = if (_x in ["mode", "zero"]) then {
			(_rects getOrDefault ["weap", []]) params [["_wx", 0], ["_wy", 0], ["_ww", 0], ["_wh", 0]];
			if (_ww == 0) then { [] } else {
				if (_x == "mode") then { [_wx, _wy + _wh * 0.74, _ww, _wh * 0.26] } else { [_wx, _wy, _ww, _wh * 0.26] }
			}
		} else {
			_rects getOrDefault [_x, []]
		};
		if (_rect isEqualTo []) then {
			_c ctrlShow false; // not part of this variant (vitals off)
		} else {
			private _r = _rect call _toScreen;
			_c ctrlSetPosition _r;
			if (_x in ["ammo", "mags"]) then { _c ctrlSetFontHeight ((_r select 3) * 0.85); };
			if (_x in ["mode", "zero"]) then { _c ctrlSetFontHeight ((_r select 3) * 0.9); };
			// grenade count matches the rounds number, but never outgrows its own box
			if (_x == "grenN") then {
				_c ctrlSetFontHeight (((_r select 3) min ((((_rects get "ammo") call _toScreen) select 3))) * 0.85);
			};
			if (_x == "stat") then { _c ctrlSetFontHeight ((_r select 3) * ([0.7, 0.62] select (_style == 2))); };
			// layout can run (settings / layout change) before ammoCreate set this
			_c ctrlShow ((missionNamespace getVariable ["BPD_CloneHUD_ammoShownStyle", 0]) > 0);
		};
		_c ctrlCommit 0;
	} forEach ["vit", "stat", "weap", "ammo", "mags", "gren", "grenN", "mode", "zero"];
	// full vitals bar width, used by the update to size the fill
	BPD_CloneHUD_ammoBarFull = if (_vitals) then { ((_rects get "vit") call _toScreen) select 2 } else { 0 };
	BPD_CloneHUD_ammoLayoutVitals = _vitals;
};

BPD_CloneHUD_fnc_hexToRGBA = {
	params ["_hex", ["_a", 0.9]];
	private _digits = "0123456789abcdef";
	private _s = toLower (_hex select [1, 6]);
	private _byte = { ((_digits find (_s select [_this, 1])) * 16 + (_digits find (_s select [_this + 1, 1]))) / 255 };
	[0 call _byte, 2 call _byte, 4 call _byte, _a]
};

// Vitals from the same ACE / KAT reading the squad list uses
// (BPD_CloneHUD_fnc_medStatus, squadMed.sqf). Bar fill = the worst of
// blood volume (full 6.0 L, empty 3.0 L) and SpO2 (full 100 %, empty
// 70 %; KAT's value when loaded, else ACE's). Bar color and the status
// line come from medStatus, so unconscious / arrest / bleeding / airway /
// pneumothorax / internal bleeding / TQ / fracture / pain all show.
// Without ACE: 1 - damage.
BPD_CloneHUD_fnc_ammoVitals = {
	if (isNil "BPD_CloneHUD_fnc_medStatus") exitWith { [1 - damage player, "", [0.27, 0.78, 0.84, 0.9]] };
	private _st = [player] call BPD_CloneHUD_fnc_medStatus;
	_st params ["_level", "_label", "_color", "_flags"];
	private _frac = if (!alive player) then {0} else {
		if (!BPD_CloneHUD_aceMedLoaded) then { 1 - damage player } else {
			private _blood = 0 max (((player getVariable ["ace_medical_bloodVolume", 6]) - 3) / 3) min 1;
			private _spo2 = if (BPD_CloneHUD_katLoaded) then {
				player getVariable ["kat_breathing_airwayStatus", 100]
			} else {
				player getVariable ["ace_medical_spo2", 100]
			};
			_blood min (0 max ((_spo2 - 70) / 30) min 1)
		};
	};
	// healthy = the style's own accent instead of the list's green
	private _rgba = if (_level == 0 && {_label == "OK"}) then {
		[[0.27, 0.78, 0.84, 0.9], [0.16, 0.51, 0.86, 0.9]] select ((missionNamespace getVariable ["BPD_CloneHUD_AMMO_STYLE", 1]) == 2)
	} else {
		[_color, 0.9] call BPD_CloneHUD_fnc_hexToRGBA
	};
	private _parts = [format ["<t color='%1'>%2</t>", _color, _label]];
	{ _parts pushBack format ["<t color='%1'>%2</t>", _x select 1, _x select 0]; } forEach (_flags select [0, 3]);
	[_frac, _parts joinString "<t color='#8aa0a8'>  ·  </t>", _rgba]
};

// [weaponClass, roundsInMag, spareMags] for whatever the player is firing
BPD_CloneHUD_fnc_ammoState = {
	private _veh = vehicle player;
	if (_veh != player) exitWith {
		private _turret = (assignedVehicleRole player) param [1, [-1]];
		private _ws = weaponState [_veh, _turret];
		if ((_ws select 0) == "") exitWith { ["", "---", "--"] };
		private _mags = { _x in (_ws select 3) } count (_veh magazinesTurret [_turret, false]);
		[_ws select 0, _ws select 4, 0 max (_mags - 1)]
	};
	private _ws = weaponState player;
	if ((_ws select 0) == "") exitWith { ["", "---", "--"] };
	private _compat = if ((_ws select 0) == (_ws select 1)) then {
		compatibleMagazines (currentWeapon player)
	} else {
		compatibleMagazines (_ws select 1)
	};
	[_ws select 0, _ws select 4, { _x in _compat } count magazines player]
};

BPD_CloneHUD_fnc_ammoHide = {
	private _ctrls = uiNamespace getVariable ["BPD_CloneHUD_ammoCtrls", createHashMap];
	{ if (_x != "dmode") then { _y ctrlShow false; }; } forEach _ctrls; // dmode is managed by ammoUpdate
};

// Fire mode on the Default info box (Ammo Counter Style = Default).
BPD_CloneHUD_fnc_modeDefault = {
	params ["_ctrls", "_on", "_label"];
	private _c = _ctrls getOrDefault ["dmode", controlNull];
	if (isNull _c) exitWith {};
	if (!_on || {_label == ""}) exitWith { if (ctrlShown _c) then { _c ctrlShow false; }; };
	private _tier = call BPD_CloneHUD_fnc_currentTier;
	if (_tier != (_c getVariable ["bpdTier", ""])) then {
		_c setVariable ["bpdTier", _tier];
		(BPD_CloneHUD_modeDefaultRects get _tier) params ["_rx", "_ry", "_w", "_h"];
		_c ctrlSetPosition [safezoneX + _rx * safezoneW, safezoneY + _ry * safezoneH, _w * safezoneW, _h * safezoneH];
		_c ctrlSetFontHeight (_h * safezoneH * 0.8);
		_c ctrlCommit 0;
	};
	private _col = missionNamespace getVariable ["INFO_TEXT_COLOR", [1,1,1,1]];
	_c ctrlSetStructuredText parseText format ["<t align='center' valign='middle' font='PuristaBold'>%1</t>", _label];
	_c ctrlSetTextColor _col;
	if (!ctrlShown _c) then { _c ctrlShow true; };
};

// Swaps the helmet info box between the full art and the version with
// the ammo column removed, so the two counters never show together.
BPD_CloneHUD_fnc_ammoInfoArt = {
	params ["_styled"];
	private _tier = call BPD_CloneHUD_fnc_currentTier;
	private _state = format ["%1|%2|%3", _styled, _tier, missionNamespace getVariable ["TEXTURE_DATAOUTPUT", ""]];
	if (_state == BPD_CloneHUD_ammoArtState) exitWith {};
	BPD_CloneHUD_ammoArtState = _state;
	private _tex = if (_styled) then {
		format ["\885th_CloneHUD\textures\ammo\%1_ammoDisplay_noAmmo.paa", _tier]
	} else {
		missionNamespace getVariable ["TEXTURE_DATAOUTPUT", ""]
	};
	{ if (!isNil _x) then { ((missionNamespace getVariable _x) select 0) ctrlSetText _tex; }; } forEach ["HUD_infoDisplay", "P2_infoDisplay", "RC_infoDisplay"];
};

// Called every tick of the HUD system loop.
BPD_CloneHUD_fnc_ammoUpdate = {
	params ["_show"];
	private _ctrls = uiNamespace getVariable ["BPD_CloneHUD_ammoCtrls", createHashMap];
	if (count _ctrls == 0) exitWith {};
	private _style = missionNamespace getVariable ["BPD_CloneHUD_AMMO_STYLE", 0];
	[_style > 0] call BPD_CloneHUD_fnc_ammoInfoArt;
	private _modeOn = missionNamespace getVariable ["BPD_CloneHUD_AMMO_FIREMODE", true];
	private _modeLabel = if (_show && {_modeOn}) then { call BPD_CloneHUD_fnc_fireMode } else { "" };
	[_ctrls, _show && {_modeOn} && {_style == 0}, _modeLabel] call BPD_CloneHUD_fnc_modeDefault;
	if (!_show || {_style < 1}) exitWith {
		if (BPD_CloneHUD_ammoShownStyle != 0) then {
			call BPD_CloneHUD_fnc_ammoHide;
			BPD_CloneHUD_ammoShownStyle = 0;
		};
	};
	private _vitals = call BPD_CloneHUD_fnc_ammoVitalsOn;
	if (_style != BPD_CloneHUD_ammoShownStyle || {_vitals isNotEqualTo (missionNamespace getVariable ["BPD_CloneHUD_ammoLayoutVitals", !_vitals])}) then {
		BPD_CloneHUD_ammoShownStyle = _style;
		(_ctrls get "panel") ctrlShow true;
		call BPD_CloneHUD_fnc_ammoLayout; // shows the parts this variant uses
	};

	private _alpha = (missionNamespace getVariable ["INFO_TEXT_COLOR", [1,1,1,1]]) param [3, 1];
	(_ctrls get "panel") ctrlSetTextColor [1, 1, 1, 0.9 * _alpha];

	// vitals bar + status line (ACE / KAT)
	if (_vitals) then {
		(call BPD_CloneHUD_fnc_ammoVitals) params ["_frac", "_statText", "_rgba"];
		private _c = _ctrls get "vit";
		private _p = ctrlPosition _c;
		_c ctrlSetBackgroundColor _rgba;
		_c ctrlSetPosition [_p select 0, _p select 1, (BPD_CloneHUD_ammoBarFull * _frac) max 0.0001, _p select 3];
		_c ctrlCommit 0;
		(_ctrls get "stat") ctrlSetStructuredText parseText format [
			"<t align='%2' valign='middle' font='PuristaBold' shadow='2'>%1</t>", _statText, ["left", "right"] select (_style == 2)
		];
	};

	// weapon + ammo
	(call BPD_CloneHUD_fnc_ammoState) params ["_weap", "_rounds", "_mags"];
	private _pic = if (_weap == "") then {""} else { getText (configFile >> "CfgWeapons" >> _weap >> "picture") };
	if (_pic != (_ctrls get "weap") getVariable ["bpdPic", "?"]) then {
		(_ctrls get "weap") ctrlSetText _pic;
		(_ctrls get "weap") setVariable ["bpdPic", _pic];
	};
	(_ctrls get "weap") ctrlSetTextColor [1, 1, 1, _alpha];
	private _lowAmmo = (_rounds isEqualType 0) && {_weap != ""} && {_rounds <= 0};
	(_ctrls get "ammo") ctrlSetStructuredText parseText format ["<t align='right' valign='middle' font='PuristaBold' color='%2'>%1</t>", _rounds, ["#ebf0f2", "#ff5a4a"] select _lowAmmo];
	(_ctrls get "mags") ctrlSetStructuredText parseText format ["<t align='right' valign='middle' font='PuristaMedium' color='#b4c8cd'>x %1</t>", _mags];
	(_ctrls get "mode") ctrlSetStructuredText parseText format ["<t align='center' valign='middle' font='PuristaBold' color='#7fb8e6'>%1</t>", _modeLabel];
	private _zero = if (_weap != "" && {missionNamespace getVariable ["BPD_CloneHUD_AMMO_ZEROING", true]}) then { call BPD_CloneHUD_fnc_zeroing } else { 0 };
	(_ctrls get "zero") ctrlSetStructuredText parseText (if (_zero > 0) then {
		format ["<t align='center' valign='middle' font='PuristaBold' color='#7fb8e6'>%1 m</t>", _zero]
	} else { "" });

	// grenades / throwables: icon and count of the SELECTED throwable only
	// (e.g. 3 blue smokes -> 3), not every throwable you carry
	private _cur = currentThrowable player;
	private _cls = _cur param [0, ""];
	private _gCount = if (_cls == "") then { 0 } else { { _x == _cls } count (magazines player) };
	private _gPic = if (_cls != "") then { getText (configFile >> "CfgMagazines" >> _cls >> "picture") } else { "" };
	if (_gPic != (_ctrls get "gren") getVariable ["bpdPic", "?"]) then {
		(_ctrls get "gren") ctrlSetText _gPic;
		(_ctrls get "gren") setVariable ["bpdPic", _gPic];
	};
	(_ctrls get "gren") ctrlSetTextColor [1, 1, 1, [_alpha, 0.35 * _alpha] select (_gCount == 0)];
	(_ctrls get "grenN") ctrlSetStructuredText parseText format ["<t align='right' valign='middle' font='PuristaBold' color='#ebf0f2'>%1</t>", _gCount];
};
