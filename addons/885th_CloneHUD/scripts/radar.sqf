/*
	885th Bloodpack Division - Clone HUD - Radar
	---------------------------------------------------------------
	Radar - placed by the Layout settings (Bottom Center by default,
	see layout.sqf; HUD_radarRect holds its current rect). Shows only squad members and
	enemies - fed entirely from HUD_nearUnits (built in
	hudEventhandler.sqf's HUD_nearUnitsHandler), the SAME detection
	data the existing 3D targeting icons already use. That data is
	already filtered to alive, line-of-sight units within the
	scanner's current range (HUD_threatRange) and refreshed on the
	scanner's own throttle - so the radar is naturally "linked to the
	scan" rather than running a second, separate detection pass:
	whatever the scanner can currently see is what shows up here, and
	nothing more (no wallhack-style omniscience).

	No text or numbers are drawn on the radar anywhere - the only
	ctrlSetText call below sets a texture path for a blip, not
	readable text - matching DUI's own compass style choice of a
	clean dial with no on-face labels.

	Blips are a fixed pool of pre-created controls (HUD_radarBlips,
	created in hudInit.sqf) repositioned/recolored/shown or hidden
	each update, not created/destroyed per unit.

	Gated on BPD_CloneHUD_RADAR_ENABLED (master on/off) and, since
	it's meant to reflect the scanner, also on HUD_showIcons (the
	scanner's own toggle) - turning the scanner off blanks the radar
	too, not just the 3D world icons.
*/

HUD_RADAR_BLIP_COUNT = 20;

HUD_fnc_radarUpdate = {
	private _radarOn = (missionnamespace getVariable ["BPD_CloneHUD_RADAR_ENABLED", true]) && HUD_showIcons && (player getVariable ["HUD_bootComplete",false]);
	if (_radarOn != (missionNamespace getVariable ["HUD_radarGatePrev", !_radarOn])) then {
		missionNamespace setVariable ["HUD_radarGatePrev", _radarOn];
		diag_log format ["885th_CloneHUD: radar gate changed to %1 - RADAR_ENABLED=%2, HUD_showIcons=%3, HUD_bootComplete=%4.", _radarOn, (missionnamespace getVariable ["BPD_CloneHUD_RADAR_ENABLED", true]), HUD_showIcons, (player getVariable ["HUD_bootComplete",false])];
	};
	if (!_radarOn) exitWith {
		(HUD_radarBackground#0) ctrlSetTextColor [0,0,0,0];
		(HUD_radarBackground#0) ctrlSetBackgroundColor [0,0,0,0];
		{ _x ctrlSetTextColor [0,0,0,0]; } forEach HUD_radarBlips;
	};
	(HUD_radarBackground#0) ctrlSetTextColor [1,1,1,0.6];
	(HUD_radarBackground#0) ctrlSetBackgroundColor (if ((missionnamespace getVariable ["RADAR_BACKGROUND_TEXTURE", ""]) == "") then {[0,0,0,0.35]} else {[0,0,0,0]});

	private _sidePlayer = side player;
	private _playerGroup = group player;
	private _relevant = HUD_nearUnits select {
		(_x isKindOf "MAN") && {
			(_playerGroup isEqualTo (group _x)) || {(_sidePlayer getFriend (side _x)) < 0.6}
		}
	};
	_relevant = _relevant select [0, (HUD_RADAR_BLIP_COUNT min (count _relevant))];

	// Spin the dial opposite to player facing - matches DUI's own
	// compass behavior. Blips below are positioned using player-
	// relative bearing (getRelDir) independently of this, so this is
	// purely the visual dial rotation, not a second rotation stacked
	// on top of blip positioning.
	(HUD_radarBackground#0) ctrlSetAngle [-(getDir player), 0.5, 0.5];
	(HUD_radarBackground#0) ctrlCommit 0;

	// Radar rect comes from the Layout settings (layout.sqf). Separate X/Y
	// radii because the radar is square in real pixels, and GUI units
	// aren't the same size horizontally and vertically.
	if (isNil "HUD_radarRect") exitWith {};
	HUD_radarRect params ["_rX", "_rY", "_rW", "_rH"];
	private _radiusX = (_rW / 2) * 0.85;
	private _radiusY = (_rH / 2) * 0.85;
	private _blipW = 0.1 * _rW;
	private _blipH = 0.1 * _rH;
	private _centerX = _rX + (_rW / 2);
	private _centerY = _rY + (_rH / 2);

	{
		private _blip = HUD_radarBlips select _forEachIndex;
		if (_forEachIndex < count _relevant) then {
			private _unit = _relevant select _forEachIndex;
			private _isGroup = _playerGroup isEqualTo (group _unit);
			private _texture = if (_isGroup) then {"\885th_CloneHUD\textures\Target_Friend.paa"} else {"\885th_CloneHUD\textures\Target_Enemi.paa"};
			private _color = if (_isGroup) then {missionnamespace getVariable ["HUD_GROUP_COLOR",[0.3,1,0.3,1]]} else {missionnamespace getVariable ["HUD_ENEMY_COLOR",[1,0.2,0.2,1]]};

			private _relBearing = player getRelDir _unit;
			private _normDist = ((player distance _unit) / HUD_threatRange) min 1;
			private _dx = sin(_relBearing) * _normDist * _radiusX;
			private _dy = -1 * cos(_relBearing) * _normDist * _radiusY;

			_blip ctrlSetPosition [_centerX + _dx - (_blipW / 2), _centerY + _dy - (_blipH / 2), _blipW, _blipH];
			_blip ctrlSetText _texture;
			_blip ctrlSetTextColor _color;
			_blip ctrlCommit 0;
		} else {
			_blip ctrlSetTextColor [0,0,0,0];
		};
	} forEach HUD_radarBlips;
};

HUD_fnc_radarLoop = {
	// Same per-life spawn lifecycle as HUD_fnc_teamListLoop - see
	// that function's comment in teamList.sqf for why the outer loop
	// is required (HUD_suit_activation only spawns this once per
	// life, not once per HUD activation).
	diag_log format ["885th_CloneHUD: HUD_fnc_radarLoop starting - alive=%1, HUD_hasUniform=%2, HUD_suitDisabled=%3.", alive player, (player getvariable ["HUD_hasUniform",false]), (player getVariable "HUD_suitDisabled")];
	while {alive player && (player getvariable ["HUD_hasUniform",false]) && !(player getVariable "HUD_suitDisabled")} do {
		waitUntil {sleep 0.5; !(alive player) || {player getVariable ["HUD_bootComplete",false]}};
		while {player getVariable ["HUD_bootComplete",false]} do {
			call HUD_fnc_radarUpdate;
			sleep HUD_throttleTime;
		};
		(HUD_radarBackground#0) ctrlSetTextColor [0,0,0,0];
		(HUD_radarBackground#0) ctrlSetBackgroundColor [0,0,0,0];
		{ _x ctrlSetTextColor [0,0,0,0]; } forEach HUD_radarBlips;
	};
};
