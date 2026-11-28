/*
	885th Bloodpack Division - Clone HUD - 2D world icons
	---------------------------------------------------------------
	The engine stops drawing drawIcon3D while showHUD "cursors" is off,
	and the HUD switches "cursors" off to hide Arma's weapon crosshair.
	So every world icon the HUD draws (scanner targets, labels, last
	known, grenades, mines, comms, medic, pings) goes through
	BPD_CloneHUD_fnc_drawIcon instead: same arguments as drawIcon3D,
	drawn as controls on the indicator layer (projected with
	worldToScreen), which showHUD can't touch.

	Call it every frame like drawIcon3D. Controls come from a pool;
	anything not drawn in a frame is hidden on the next one.
*/

BPD_CloneHUD_icon2dFrame = -1;
BPD_CloneHUD_icon2dUsed = 0;
BPD_CloneHUD_icon2dLastCall = -1;

// [texture, color, posAGL, width, height, angle, text, shadow, textSize, font, align, sideArrows]
BPD_CloneHUD_fnc_drawIcon = {
	params ["_tex", "_col", "_posAGL", ["_w", 1], ["_h", 1], ["_ang", 0], ["_text", ""], ["_shadow", 0],
		["_tSize", 0.04], ["_font", "RobotoCondensed"], ["_align", "center"], ["_arrows", false]];
	private _disp = uiNamespace getVariable ["BPD_CloneHUD_INDICATOR_BASE", displayNull];
	if (isNull _disp) exitWith {};
	private _pool = uiNamespace getVariable ["BPD_CloneHUD_icon2dPool", []];
	if (count _pool > 0 && {isNull ((_pool select 0) select 0)}) then { _pool = []; uiNamespace setVariable ["BPD_CloneHUD_icon2dPool", _pool]; };

	// new frame: hide whatever wasn't drawn last frame, restart the pool
	if (diag_frameNo != BPD_CloneHUD_icon2dFrame) then {
		private _prev = BPD_CloneHUD_icon2dFrame;
		{
			_x params ["_p", "_t", "_f"];
			if (_f < _prev && {ctrlShown _p || {ctrlShown _t}}) then { _p ctrlShow false; _t ctrlShow false; };
		} forEach _pool;
		BPD_CloneHUD_icon2dFrame = diag_frameNo;
		BPD_CloneHUD_icon2dUsed = 0;
	};
	BPD_CloneHUD_icon2dLastCall = diag_frameNo;

	// screen position (side arrows: pin off-screen icons to the screen edge)
	private _scr = worldToScreen _posAGL;
	private _onScreen = _scr isNotEqualTo [] && {(_scr select 0) > safezoneX} && {(_scr select 0) < safezoneX + safezoneW}
		&& {(_scr select 1) > safezoneY} && {(_scr select 1) < safezoneY + safezoneH};
	if (!_onScreen) then {
		if (!_arrows) exitWith { _scr = []; };
		private _cam = positionCameraToWorld [0, 0, 0];
		private _v = _posAGL vectorDiff _cam;
		private _rx = _v vectorDotProduct ((positionCameraToWorld [1, 0, 0]) vectorDiff _cam);
		private _ry = _v vectorDotProduct ((positionCameraToWorld [0, 1, 0]) vectorDiff _cam);
		private _a = _rx atan2 _ry;
		_scr = [0.5 + (sin _a) * 0.45 * safezoneW, 0.5 - (cos _a) * 0.42 * safezoneH];
	};
	if (_scr isEqualTo []) exitWith {};
	_scr params ["_sx", "_sy"];

	private _i = BPD_CloneHUD_icon2dUsed;
	BPD_CloneHUD_icon2dUsed = _i + 1;
	if (_i >= count _pool) then {
		private _p = _disp ctrlCreate ["RscPicture", -1];
		private _t = _disp ctrlCreate ["RscStructuredText", -1];
		_p ctrlShow false; _t ctrlShow false;
		_pool pushBack [_p, _t, -1];
		uiNamespace setVariable ["BPD_CloneHUD_icon2dPool", _pool];
	};
	private _e = _pool select _i;
	_e set [2, diag_frameNo];
	_e params ["_p", "_t"];

	// drawIcon3D size 1 ~ 0.04 of screen height
	private _ih = _h * 0.04 * safezoneH;
	private _iw = (_w * 0.04 * safezoneH) / pixelH * pixelW;
	if (_tex != "" && {_ih > 0}) then {
		if (ctrlText _p != _tex) then { _p ctrlSetText _tex; };
		_p ctrlSetTextColor _col;
		_p ctrlSetAngle [_ang, 0.5, 0.5];
		_p ctrlSetPosition [_sx - _iw / 2, _sy - _ih / 2, _iw, _ih];
		_p ctrlCommit 0;
		if (!ctrlShown _p) then { _p ctrlShow true; };
	} else {
		if (ctrlShown _p) then { _p ctrlShow false; };
	};
	if (_text != "") then {
		private _safe = ((_text regexReplace ["&", "&amp;"]) regexReplace ["<", "&lt;"]) regexReplace [">", "&gt;"];
		private _hex = (_col select [0, 3]) call BIS_fnc_colorRGBtoHTML;
		private _key = [_safe, _hex, _font, _shadow];
		if (_key isNotEqualTo (_t getVariable ["bpdKey", []])) then {
			_t setVariable ["bpdKey", _key];
			_t ctrlSetStructuredText parseText format ["<t align='center' valign='top' font='%1' color='%2' shadow='%3'>%4</t>", _font, _hex, _shadow, _safe];
		};
		private _fh = _tSize * safezoneH * 0.9;
		_t ctrlSetFontHeight _fh;
		_t ctrlSetFade (1 - (_col param [3, 1]));
		private _tw = 0.3 * safezoneW;
		private _ty = if (_ih > 0) then { _sy + _ih / 2 } else { _sy - _fh / 2 };
		_t ctrlSetPosition [_sx - _tw / 2, _ty, _tw, _fh * 1.4];
		_t ctrlCommit 0;
		if (!ctrlShown _t) then { _t ctrlShow true; };
	} else {
		if (ctrlShown _t) then { _t ctrlShow false; };
	};
};

// Nothing drawn for a couple of frames (HUD off, scanner off...): hide all.
if (hasInterface && {isNil "BPD_CloneHUD_icon2dPFH"}) then {
	BPD_CloneHUD_icon2dPFH = [{
		if (diag_frameNo - BPD_CloneHUD_icon2dLastCall < 2) exitWith {};
		{
			_x params ["_p", "_t"];
			if (ctrlShown _p || {ctrlShown _t}) then { _p ctrlShow false; _t ctrlShow false; };
		} forEach (uiNamespace getVariable ["BPD_CloneHUD_icon2dPool", []]);
	}, 0] call CBA_fnc_addPerFrameHandler;
};
