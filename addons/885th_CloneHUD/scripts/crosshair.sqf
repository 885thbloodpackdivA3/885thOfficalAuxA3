/*
	885th Bloodpack Division - Clone HUD - Crosshair
	---------------------------------------------------------------
	A HUD crosshair in the screen centre while the HUD is up.
	BPD_CloneHUD_CROSSHAIR (per player): 0 off, 1 segmented ring,
	2 broken ring, 3 plain ring. Size / opacity settings beside it.

	Shown on foot (or firing your own weapon from a vehicle seat) with a
	weapon up - first person at the screen centre, third person (option
	BPD_CloneHUD_CROSSHAIR_3RD) where the weapon is aimed. Style 4
	"Vanilla Crosshair" = no HUD crosshair, Arma's own stays on. Hidden when aiming down sights / optics, on
	the map, in Zeus, and whenever the HUD isn't booted (so an EMP or
	turning the HUD off takes it away too). It lives on the indicator
	layer, so the down / EMP haywire glitches it with the rest of the HUD.
	Arma's own weapon crosshair is hidden on foot while the HUD is up by
	vanillaHud.sqf (BPD_CloneHUD_HIDE_CURSORS, 3. Vanilla HUD).
*/

BPD_CloneHUD_fnc_crosshairCtrl = {
	private _d = uiNamespace getVariable ["BPD_CloneHUD_INDICATOR_BASE", displayNull];
	if (isNull _d) exitWith {controlNull};
	private _c = _d displayCtrl 27760;
	if (isNull _c) then {
		_c = _d ctrlCreate ["RscPicture", 27760];
		_c ctrlShow false;
		_c ctrlCommit 0;
	};
	_c
};

BPD_CloneHUD_fnc_crosshairTick = {
	private _c = call BPD_CloneHUD_fnc_crosshairCtrl;
	if (isNull _c) exitWith {};
	private _style = missionNamespace getVariable ["BPD_CloneHUD_CROSSHAIR", 1];
	if (_style == 4) then { _style = 0; };   // "Vanilla Crosshair": Arma's own stays on, no HUD one
	private _onFoot = vehicle player == player || {((weaponState player) select 0) != ""};
	private _third = cameraView == "EXTERNAL" && {missionNamespace getVariable ["BPD_CloneHUD_CROSSHAIR_3RD", true]};
	private _show = _style > 0
		&& {alive player}
		&& {player getVariable ["HUD_bootComplete", false]}
		&& {missionNamespace getVariable ["HUD_hasHelmet", false]}
		&& {cameraView == "INTERNAL" || _third}
		&& {_onFoot}
		&& {currentWeapon player != ""}
		&& {!visibleMap}
		&& {isNull (findDisplay 312)}
		&& {isNull curatorCamera};
	if (!_show) exitWith { if (ctrlShown _c) then { _c ctrlShow false; }; };

	private _tex = format ["\885th_CloneHUD\textures\crosshair\crosshair_%1_ca.paa", _style];
	private _size = missionNamespace getVariable ["BPD_CloneHUD_CROSSHAIR_SIZE", 0.06];
	// where it sits: screen centre in first person; in third person the
	// point the weapon is aimed at, projected to the screen
	private _centre = [0.5, 0.5];
	if (cameraView == "EXTERNAL") then {
		private _dir = player weaponDirection currentWeapon player;
		private _from = eyePos player;
		private _to = _from vectorAdd (_dir vectorMultiply 1000);
		private _hit = lineIntersectsSurfaces [_from, _to, player, vehicle player, true, 1, "FIRE", "GEOM"];
		private _aim = if (_hit isEqualTo []) then { _to } else { (_hit select 0) select 0 };
		private _scr = worldToScreen (ASLToAGL _aim);
		_centre = if (_scr isEqualTo []) then { [-1, -1] } else { _scr };
	};
	if (_centre isEqualTo [-1, -1]) exitWith { if (ctrlShown _c) then { _c ctrlShow false; }; };
	private _key = [_tex, _size, getResolution, _centre];
	if (_key isNotEqualTo (_c getVariable ["bpdKey", []])) then {
		_c setVariable ["bpdKey", _key];
		if (ctrlText _c != _tex) then { _c ctrlSetText _tex; };
		private _h = _size * safezoneH;
		private _w = _h / pixelH * pixelW;        // square on screen
		_c ctrlSetPosition [(_centre select 0) - _w / 2, (_centre select 1) - _h / 2, _w, _h];
		_c ctrlCommit 0;
	};
	// colour: the HUD's own colour or the crosshair's own (opacity slider on top)
	private _rgb = if ((missionNamespace getVariable ["BPD_CloneHUD_CROSSHAIR_COLOR_MODE", 0]) == 0) then {
		missionNamespace getVariable ["INTERIOR_OVERLAY_COLOR", [0, 0.6, 1, 1]]
	} else {
		missionNamespace getVariable ["BPD_CloneHUD_CROSSHAIR_COLOR", [1, 1, 1]]
	};
	_c ctrlSetTextColor [_rgb param [0, 1], _rgb param [1, 1], _rgb param [2, 1], missionNamespace getVariable ["BPD_CloneHUD_CROSSHAIR_OPACITY", 0.8]];
	if (!ctrlShown _c) then { _c ctrlShow true; };
};

if (hasInterface && {isNil "BPD_CloneHUD_crosshairLoop"}) then {
	// every frame, so the third-person crosshair follows the weapon smoothly
	// (the aim ray cast only runs in third person)
	BPD_CloneHUD_crosshairLoop = [{
		if (isNull player) exitWith {};
		call BPD_CloneHUD_fnc_crosshairTick;
	}, 0] call CBA_fnc_addPerFrameHandler;
};
