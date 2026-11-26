/*
	885th Bloodpack Division - Clone HUD - Layout
	---------------------------------------------------------------
	Places every movable HUD element from the per-player CBA settings
	under "885th BPD Clone HUD - Layout". Each element has:

	  BPD_CloneHUD_LAYOUT_<KEY>_POS    preset (0-7) or 8 = Custom
	  BPD_CloneHUD_LAYOUT_<KEY>_X/_Y   0..1, only used by Custom
	                                   (0 = flush left/top, 1 = flush right/bottom,
	                                   so a custom spot can never leave the screen)
	  BPD_CloneHUD_LAYOUT_<KEY>_SCALE  size multiplier

	Keys: TROOPER (limb damage indicator), SQUAD (team list),
	      RADAR, FEED (tactical link / helm cam panel).

	The limb indicator textures are full-canvas (2048x1024) images with
	the trooper drawn in one small spot, so they can't be positioned by
	their control rect directly. BPD_CloneHUD_fnc_artBox holds the
	measured bounds of the visible art per tier (fractions of the canvas,
	measured from the shipped .paa files), and the trooper is placed so
	that ART box - not the invisible canvas - lands on the chosen spot.
	If you swap the limb textures in Addon Options for art drawn somewhere
	else on the canvas, update these numbers to match.

	BPD_CloneHUD_fnc_applyLayout is safe to call at any time: it does
	nothing until hudInit.sqf has created the controls, and every layout
	setting calls it from onChanged, so moving things in Addon Options
	updates the HUD live.
*/

// Visible trooper art bounds per tier: [x, y, w, h] as canvas fractions.
BPD_CloneHUD_fnc_artBox = {
	params ["_tier"];
	switch (_tier) do {
		case "RC": { [0.4775, 0.7754, 0.0449, 0.1895] };
		case "P2": { [0.0518, 0.6582, 0.0752, 0.2773] };
		default    { [0.0518, 0.6602, 0.0752, 0.2754] };
	};
};

// Sets the interior overlay's color and keeps the trooper's stand
// (split out of that overlay art) in step with it.
BPD_CloneHUD_fnc_interiorColor = {
	private _c = _this;
	(HUD_interiorOverlay#0) ctrlSetTextColor _c;
	if (!isNil "HUD_trooperBase") then { (HUD_trooperBase#0) ctrlSetTextColor _c; };
};

BPD_CloneHUD_fnc_currentTier = {
	if (player getVariable ["RC_INHELMET", false]) exitWith {"RC"};
	if (player getVariable ["P2_INHELMET", false]) exitWith {"P2"};
	"P1"
};

// Converts an element's position setting into a top-left screen point
// for a box of size [_w, _h].
BPD_CloneHUD_fnc_layoutPos = {
	params ["_key", "_w", "_h"];
	private _preset = missionNamespace getVariable [format ["BPD_CloneHUD_LAYOUT_%1_POS", _key], 0];
	private _mx = 0.012 * safezoneW;
	// Edge presets keep clear of the blue visor bands drawn into the
	// interior overlay art (top arc ~5% of the screen, bottom bands ~9%).
	// Measured off an in-game 2000x1125 screenshot.
	private _topClear = 0.05 * safezoneH;
	private _bottomClear = 0.095 * safezoneH;
	// The center column keeps clear of the P2 heading/range readouts
	// that are baked into the info display art (top and bottom center).
	private _centerClear = 0.14 * safezoneH;

	private _left   = safezoneX + _mx;
	private _right  = safezoneX + safezoneW - _w - _mx;
	private _cx     = safezoneX + ((safezoneW - _w) / 2);
	private _top    = safezoneY + _topClear;
	private _bottom = safezoneY + safezoneH - _h - _bottomClear;
	private _mid    = safezoneY + ((safezoneH - _h) / 2);

	switch (_preset) do {
		case 0: { [_left,  _top] };                                 // Top Left
		case 1: { [_cx,    safezoneY + _centerClear] };             // Top Center
		case 2: { [_right, _top] };                                 // Top Right
		case 3: { [_left,  _mid] };                                 // Middle Left
		case 4: { [_right, _mid] };                                 // Middle Right
		case 5: { [_left,  _bottom] };                              // Bottom Left
		case 6: { [_cx,    safezoneY + safezoneH - _h - _centerClear] }; // Bottom Center
		case 7: { [_right, _bottom] };                              // Bottom Right
		default {                                                   // Custom
			private _fx = 0 max (1 min (missionNamespace getVariable [format ["BPD_CloneHUD_LAYOUT_%1_X", _key], 0]));
			private _fy = 0 max (1 min (missionNamespace getVariable [format ["BPD_CloneHUD_LAYOUT_%1_Y", _key], 0]));
			[safezoneX + (_fx * (safezoneW - _w)), safezoneY + (_fy * (safezoneH - _h))]
		};
	};
};

BPD_CloneHUD_fnc_layoutScale = {
	params ["_key"];
	0.3 max (missionNamespace getVariable [format ["BPD_CloneHUD_LAYOUT_%1_SCALE", _key], 1])
};

BPD_CloneHUD_fnc_applyLayout = {
	if (isNil "HUD_pa_head" || {isNil "HUD_teamList"}) exitWith {};
	if (isNull (HUD_pa_head#0)) exitWith {};
	if (isNil "HUD_TEXTURE_IND_HEAD") exitWith {}; // no helmet tier resolved yet

	// ---- Trooper (limb damage indicator) ----
	// Every tier is fitted into the SAME on-screen box: the Phase 1 trooper
	// at 0.22 safezoneH tall sets both the width and the height. Width and
	// height are scaled separately, so the slimmer RC art is widened to
	// match the P1 / P2 troopers' build instead of coming out narrower or
	// taller. Role figures (ARF / Scout / BARC / Pilot) are drawn on the P2
	// figure, so the tier's box fits them too.
	([call BPD_CloneHUD_fnc_currentTier] call BPD_CloneHUD_fnc_artBox) params ["_ax", "_ay", "_aw", "_ah"];
	(["P1"] call BPD_CloneHUD_fnc_artBox) params ["", "", "_refW", "_refH"];
	private _artH = 0.22 * safezoneH * (["TROOPER"] call BPD_CloneHUD_fnc_layoutScale);
	private _artW = _artH * (_refW * safezoneW) / (_refH * safezoneH);
	private _kx = _artW / (_aw * safezoneW);
	private _ky = _artH / (_ah * safezoneH);
	(["TROOPER", _artW, _artH] call BPD_CloneHUD_fnc_layoutPos) params ["_tx", "_ty"];
	// RC gets an extra 5% width, kept centred on the same spot
	private _wide = [1, 1.05] select ((call BPD_CloneHUD_fnc_currentTier) == "RC");
	_kx = _kx * _wide;
	_tx = _tx - (_artW * (_wide - 1) / 2);
	private _limbRect = [_tx - (_kx * _ax * safezoneW), _ty - (_ky * _ay * safezoneH), _kx * safezoneW, _ky * safezoneH];
	{
		(_x#0) ctrlSetText (_x#1);
		(_x#0) ctrlSetPosition _limbRect;
		(_x#0) ctrlCommit 0;
	} forEach [
		[HUD_pa_head#0,  HUD_TEXTURE_IND_HEAD],
		[HUD_pa_torso#0, HUD_TEXTURE_IND_TORSO],
		[HUD_pa_armR#0,  HUD_TEXTURE_IND_ARM_R],
		[HUD_pa_armL#0,  HUD_TEXTURE_IND_ARM_L],
		[HUD_pa_legR#0,  HUD_TEXTURE_IND_LEG_R],
		[HUD_pa_legL#0,  HUD_TEXTURE_IND_LEG_L]
	];
	// The trooper's stand is drawn on the same canvas as the limb art, so
	// the same rect keeps it lined up under the trooper wherever it goes.
	if (!isNil "HUD_trooperBase") then {
		(HUD_trooperBase#0) ctrlSetText (missionNamespace getVariable ["HUD_TEXTURE_TROOPER_BASE", ""]);
		(HUD_trooperBase#0) ctrlSetPosition _limbRect;
		(HUD_trooperBase#0) ctrlCommit 0;
	};
	BPD_CloneHUD_trooperRect = [_tx, _ty, _artW * _wide, _artH];

	// ---- Squad list ----
	private _sqScale = ["SQUAD"] call BPD_CloneHUD_fnc_layoutScale;
	private _sqW = 0.24 * safezoneW * _sqScale;
	private _sqH = 0.30 * safezoneH * _sqScale;
	(["SQUAD", _sqW, _sqH] call BPD_CloneHUD_fnc_layoutPos) params ["_sx", "_sy"];
	(HUD_teamList#0) ctrlSetPosition [_sx, _sy, _sqW, _sqH];
	(HUD_teamList#0) ctrlCommit 0;
	BPD_CloneHUD_teamListTextScale = _sqScale;

	// ---- Radar (square in real pixels, not just in GUI units) ----
	private _rW = (missionNamespace getVariable ["RADAR_SIZE", 0.12]) * safezoneW * (["RADAR"] call BPD_CloneHUD_fnc_layoutScale);
	private _rH = _rW * (pixelH / pixelW);
	(["RADAR", _rW, _rH] call BPD_CloneHUD_fnc_layoutPos) params ["_rx", "_ry"];
	HUD_radarRect = [_rx, _ry, _rW, _rH];
	(HUD_radarBackground#0) ctrlSetPosition HUD_radarRect;
	(HUD_radarBackground#0) ctrlCommit 0;
	if (!isNil "HUD_radarDisc") then {
		(HUD_radarDisc#0) ctrlSetPosition HUD_radarRect;
		private _sW = 0.09 * _rW;
		private _sH = 0.09 * _rH;
		(HUD_radarSelf#0) ctrlSetPosition [_rx + (_rW / 2) - (_sW / 2), _ry + (_rH / 2) - (_sH / 2), _sW, _sH];
		(HUD_radarRange#0) ctrlSetPosition [_rx, _ry + _rH, _rW, 0.16 * _rH];
		{ (_x#0) ctrlCommit 0; } forEach [HUD_radarDisc, HUD_radarSelf, HUD_radarRange];
	};

	// ---- Tactical link / helm cam panel ----
	if (!isNil "HUD_feedPicture") then {
		private _fScale = ["FEED"] call BPD_CloneHUD_fnc_layoutScale;
		private _fW = 0.2 * safezoneW * _fScale;
		private _headerH = 0.03 * safezoneH * _fScale;
		private _picH = _fW * (pixelH / pixelW) * (9 / 16);
		private _fH = _headerH + _picH;
		(["FEED", _fW, _fH] call BPD_CloneHUD_fnc_layoutPos) params ["_fx", "_fy"];
		(HUD_feedBack#0) ctrlSetPosition [_fx, _fy, _fW, _fH];
		(HUD_feedHeader#0) ctrlSetPosition [_fx, _fy, _fW, _headerH];
		(HUD_feedPicture#0) ctrlSetPosition [_fx, _fy + _headerH, _fW, _picH];
		(HUD_feedLabel#0) ctrlSetPosition [_fx, _fy + _headerH + _picH - (0.03 * safezoneH * _fScale), _fW, 0.03 * safezoneH * _fScale];
		{ (_x#0) ctrlCommit 0; } forEach [HUD_feedBack, HUD_feedHeader, HUD_feedPicture, HUD_feedLabel];
		BPD_CloneHUD_feedTextScale = _fScale;
		// Tac Map: square (in real pixels) under the header
		if (!isNil "HUD_feedMap" && {!isNull (HUD_feedMap#0)}) then {
			private _mapH = _fW * (pixelH / pixelW) * (missionNamespace getVariable ["BPD_CloneHUD_TACMAP_ASPECT", 1]);
			(HUD_feedMap#0) ctrlSetPosition [_fx, _fy + _headerH, _fW, _mapH];
			(HUD_feedMap#0) ctrlCommit 0;
			BPD_CloneHUD_feedMapH = _mapH;
		};
	};

	// ---- Ammo counter (Style A / B) ----
	if (!isNil "BPD_CloneHUD_fnc_ammoLayout") then { call BPD_CloneHUD_fnc_ammoLayout; };
	if (!isNil "BPD_CloneHUD_fnc_commsLayout") then { call BPD_CloneHUD_fnc_commsLayout; };
	if (!isNil "BPD_CloneHUD_fnc_intelLogLayout") then { call BPD_CloneHUD_fnc_intelLogLayout; };
	if (!isNil "BPD_CloneHUD_fnc_killLayout") then { call BPD_CloneHUD_fnc_killLayout; };
};
