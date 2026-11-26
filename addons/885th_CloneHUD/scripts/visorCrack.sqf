/*
	885th Bloodpack Division - Clone HUD - Cracked visor (Republic Commando style)
	-----------------------------------------------------------------------------
	A critical headshot, or an explosion that hits your body hard enough,
	cracks the visor of your clone helmet. Cracks are picked at random from
	a set of 19 textures (bullet spiderwebs, small chips, long stress
	fractures, rim impacts, star bursts, full shatters, blaster-volley
	clusters, glancing grazes, edge-to-edge splits) with random spot, size
	and rotation, and they stack up to "Max Cracks" (the oldest drops off).

	Only REPUBLIC COMMANDO helmets (the RC helmet list) can wipe the visor
	clean - "Wipe Visor" keybind, ACE self-interaction > Equipment, or the
	scroll action - and they also wipe on their own "RC Auto Wipe After"
	seconds (default 20) after the last crack. A wiper sweeps across the
	visor and clears it; "Wipe Cooldown" (default 5 s) spaces wipes out.
	Phase 1 / Phase 2 helmets keep their cracks until they swap helmets or
	respawn (or after "Non-RC Cracks Last", if the server sets it).
	ENGINEERS can repair any tier's visor: ACE interact > Repair Visor
	(progress bar), or a hold action without ACE. See "Who Can Repair".

	Damage source:
	  - ACE medical: the "ace_medical_woundReceived" event (fires on the
	    hit trooper's machine). Supports both the 3.16+ format
	    [unit, [[damage, bodyPart, real], ...], shooter, ammo] and the
	    older [unit, bodyPart, damage, shooter, ammo].
	  - No ACE medical: a "Dammaged" handler on the player.
	  "Explosion" = the ammo has indirectHit > 0 and indirectHitRange >= 1.

	Cover: blasts are checked for what sits between your eyes and where
	they went off. Walls, floors or terrain in the way = no crack, so a
	mortar landing outside the building you're in no longer cracks it.
	If the blast spot isn't known, being under a building roof doubles
	the blast threshold instead. "Cover Blocks Blast Cracks" turns this off.

	Dirt: every explosive that goes off near you in the open (within
	2x its blast radius, max 35 m, no cover in between) throws 1-2 random
	dirt overlays on the visor - hurt or not. 10 textures: mud splatter,
	dust, smear, water spots, corner grime, sand spray, mud drip, soot,
	clumps, dust film. Dirt stacks to "Max Dirt", clears after "Dirt
	Lasts" (any helmet), and goes with the cracks when an RC helmet wipes
	or an engineer repairs. Repair Visor plays the same wiper sweep.
	Detection: the ProjectileCreated mission event adds an "Explode"
	handler to explosive projectiles; the player's "Explosion" handler
	(blasts that hurt you) is the fallback.

	Test from the debug console:  ["head"] call BPD_CloneHUD_fnc_crackAdd;
	                              ["blast"] call BPD_CloneHUD_fnc_crackAdd;
*/

BPD_CloneHUD_fnc_crackTex = { format ["\885th_CloneHUD\textures\crack\visor_crack_%1_ca.paa", _this] };
BPD_CloneHUD_fnc_dirtTex = { format ["\885th_CloneHUD\textures\dirt\visor_dirt_%1_ca.paa", _this] };

BPD_CloneHUD_crackList = [];      // [[tex, x, y, w, h, angle, bornTick, ctrl, isDirt], ...]
BPD_CloneHUD_crackBlastPos = [];  // ASL position of the last explosion near the player
BPD_CloneHUD_crackBlastTick = -10;
BPD_CloneHUD_dirtLastAdd = -10;
BPD_CloneHUD_blastAmmo = createHashMap; // ammo class -> blast radius (0 = not explosive)
BPD_CloneHUD_crackHelmet = "";
BPD_CloneHUD_crackUnit = objNull;
BPD_CloneHUD_crackLastAdd = -10;
BPD_CloneHUD_crackNextWipe = 0;
BPD_CloneHUD_crackWiping = false;
BPD_CloneHUD_crackShown = false;

BPD_CloneHUD_fnc_crackOpt = { params ["_n", "_d"]; missionNamespace getVariable [format ["BPD_CloneHUD_CRACK_%1", _n], _d] };
BPD_CloneHUD_fnc_crackIsClone = { headgear player in (missionNamespace getVariable ["HUD_helmets", []]) };
BPD_CloneHUD_fnc_crackIsRC = { headgear player in (missionNamespace getVariable ["BPD_CloneHUD_RC_helmets", []]) };

BPD_CloneHUD_fnc_crackMsg = {
	params ["_msg", "_id", ["_time", 4]];
	if ((missionNamespace getVariable ["HUD_hasHelmet", false]) && {missionNamespace getVariable ["HUD_systemMessageAllowed", false]} && {missionNamespace getVariable ["SYSTEM_MESSAGES", true]}) then {
		[_msg, _id, _time] call HUD_fnc_addSystemMessage;
	};
};

BPD_CloneHUD_fnc_crackDisplay = {
	private _d = uiNamespace getVariable ["BPD_CloneHUD_CRACK_BASE", displayNull];
	if (isNull _d) then {
		"BPD_CloneHUD_CRACK_LAYER" cutRsc ["BPD_CloneHUD_CRACK_BASE", "PLAIN", -1, false];
		_d = uiNamespace getVariable ["BPD_CloneHUD_CRACK_BASE", displayNull];
	};
	_d
};

// Remove every crack (no animation).
BPD_CloneHUD_fnc_crackClear = {
	{ ctrlDelete (_x select 7) } forEach BPD_CloneHUD_crackList;
	BPD_CloneHUD_crackList = [];
};

// Add one or two random cracks. _kind: "head" or "blast".
BPD_CloneHUD_fnc_crackAdd = {
	params [["_kind", "head"]];
	if !(["ENABLED", true] call BPD_CloneHUD_fnc_crackOpt) exitWith {};
	if (!alive player || {!(call BPD_CloneHUD_fnc_crackIsClone)}) exitWith {};
	if (diag_tickTime - BPD_CloneHUD_crackLastAdd < 0.4) exitWith {}; // one blast = one event
	BPD_CloneHUD_crackLastAdd = diag_tickTime;

	private _max = round (["MAX", 4] call BPD_CloneHUD_fnc_crackOpt);
	private _n = if (_kind == "blast") then { [1, 2] select (random 1 < 0.5) } else { 1 };

	for "_i" from 1 to _n do {
		// pick a crack style: headshots are mostly bullet webs, blasts mostly rim impacts / fractures
		private _style = if (_kind == "blast") then {
			selectRandomWeighted ["edge", 0.25, "fracture", 0.15, "chip", 0.1, "cluster", 0.2, "shatter", 0.15, "split", 0.15]
		} else {
			selectRandomWeighted ["web", 0.35, "chip", 0.15, "fracture", 0.1, "star", 0.15, "graze", 0.12, "shatter", 0.05, "cluster", 0.08]
		};
		private _sx = safezoneX; private _sy = safezoneY; private _sw = safezoneW; private _sh = safezoneH;
		private _num = 1; private _h = 0; private _px = 0; private _py = 0; private _ang = 0;
		switch (_style) do {
			case "web":      { _num = selectRandom [1, 2, 3]; _h = _sh * random [0.5, 0.62, 0.8]; };
			case "chip":     { _num = selectRandom [4, 5];    _h = _sh * random [0.25, 0.32, 0.42]; };
			case "fracture": { _num = selectRandom [6, 7];    _h = _sh * random [0.75, 0.9, 1.1]; };
			case "star":     { _num = selectRandom [10, 11];  _h = _sh * random [0.45, 0.6, 0.75]; };
			case "shatter":  { _num = selectRandom [12, 13];  _h = _sh * random [0.7, 0.85, 1.0]; };
			case "cluster":  { _num = selectRandom [14, 15];  _h = _sh * random [0.6, 0.75, 0.9]; };
			case "graze":    { _num = selectRandom [16, 17];  _h = _sh * random [0.8, 0.95, 1.1]; };
			case "split":    { _num = selectRandom [18, 19];  _h = _sh * random [1.0, 1.15, 1.3]; };
			default          { _num = selectRandom [8, 9];    _h = _sh * random [0.8, 0.95, 1.1]; };
		};
		private _tex = _num call BPD_CloneHUD_fnc_crackTex;
		private _w = _h / pixelH * pixelW; // square on screen

		if (_style == "edge") then {
			// texture 8 starts top-right, 9 top-left; 180 deg flips to the opposite corner
			private _flip = random 1 < 0.5;
			private _right = (_num == 8) isEqualTo !_flip; // impact on the right side of the screen?
			private _top = !_flip;
			_px = if (_right) then { _sx + _sw - _w * 0.97 } else { _sx - _w * 0.03 };
			_py = if (_top) then { _sy - _h * 0.03 } else { _sy + _sh - _h * 0.97 };
			_ang = ([0, 180] select _flip) + random [-6, 0, 6];
		} else {
			// headshot cracks sit near the middle of the visor, others anywhere
			// big ones (split / shatter) stay near the middle so they fill the visor
			private _big = _style in ["split", "shatter"];
			private _cx = if (_big) then { random [0.38, 0.5, 0.62] } else { if (_kind == "head") then { random [0.25, 0.5, 0.75] } else { random [0.1, 0.5, 0.9] } };
			private _cy = if (_big) then { random [0.35, 0.45, 0.6] } else { if (_kind == "head") then { random [0.2, 0.42, 0.7] } else { random [0.1, 0.5, 0.9] } };
			_px = _sx + _sw * _cx - _w / 2;
			_py = _sy + _sh * _cy - _h / 2;
			_ang = random 360;
		};

		[false, _max] call BPD_CloneHUD_fnc_crackTrim;
		BPD_CloneHUD_crackList pushBack [_tex, _px, _py, _w, _h, _ang, diag_tickTime, controlNull, false];
	};

	playSound3D [format ["A3\Sounds_F\arsenal\sfx\bullet_hits\glass_arm_0%1.wss", 1 + floor random 8], player, false, getPosASL player, 3, 1, 15];
	if (call BPD_CloneHUD_fnc_crackIsRC) then {
		["<t color='#ff9a3c'>VISOR CRACKED</t> - wipe it clean", "visorCrack", 4] call BPD_CloneHUD_fnc_crackMsg;
	} else {
		["<t color='#ff9a3c'>VISOR CRACKED</t>", "visorCrack", 4] call BPD_CloneHUD_fnc_crackMsg;
	};
	call BPD_CloneHUD_fnc_crackTick;
};

// Drop the oldest cracks (_dirt false) or dirt (_dirt true) until there's
// room for one more under _max.
BPD_CloneHUD_fnc_crackTrim = {
	params ["_dirt", "_max"];
	if (_max <= 0) exitWith {};
	while { ({ (_x param [8, false]) isEqualTo _dirt } count BPD_CloneHUD_crackList) >= _max } do {
		private _i = BPD_CloneHUD_crackList findIf { (_x param [8, false]) isEqualTo _dirt };
		if (_i < 0) exitWith {};
		ctrlDelete ((BPD_CloneHUD_crackList deleteAt _i) select 7);
	};
};

// Add _n random dirt overlays.
BPD_CloneHUD_fnc_dirtAdd = {
	params [["_n", 1]];
	if !(["ENABLED", true] call BPD_CloneHUD_fnc_crackOpt) exitWith {};
	if !(["DIRT", true] call BPD_CloneHUD_fnc_crackOpt) exitWith {};
	if (!alive player || {!(call BPD_CloneHUD_fnc_crackIsClone)}) exitWith {};
	if (diag_tickTime - BPD_CloneHUD_dirtLastAdd < 0.4) exitWith {}; // one blast = one event
	BPD_CloneHUD_dirtLastAdd = diag_tickTime;
	private _max = round (["DIRT_MAX", 3] call BPD_CloneHUD_fnc_crackOpt);
	private _sx = safezoneX; private _sy = safezoneY; private _sw = safezoneW; private _sh = safezoneH;

	for "_i" from 1 to _n do {
		// 1 splatter 2 dust 3 smear 4 water spots 5 corner grime
		// 6 sand spray 7 mud drip 8 soot 9 clumps 10 dust film
		private _num = 1 + floor random 10;
		private _h = 0; private _w = 0; private _px = 0; private _py = 0; private _ang = 0;
		switch (true) do {
			case (_num == 5): {
				// grime is drawn in the texture's top-left corner; 180 deg puts it bottom-right
				_h = _sh * random [0.55, 0.7, 0.85]; _w = _h / pixelH * pixelW;
				private _flip = random 1 < 0.5;
				_px = if (_flip) then { _sx + _sw - _w * 0.97 } else { _sx - _w * 0.03 };
				_py = if (_flip) then { _sy + _sh - _h * 0.97 } else { _sy - _h * 0.03 };
				_ang = [0, 180] select _flip;
			};
			case (_num == 10): {
				// dust film along the bottom (or, flipped, the top) edge
				_w = _sw; _h = _sh * random [0.4, 0.5, 0.6];
				private _flip = random 1 < 0.3;
				_px = _sx;
				_py = if (_flip) then { _sy } else { _sy + _sh - _h };
				_ang = [0, 180] select _flip;
			};
			case (_num in [2, 4, 6]): {
				// spread over the whole visor
				_h = _sh * random [0.8, 1, 1.2]; _w = _h / pixelH * pixelW;
				_px = _sx + _sw * (random [0.3, 0.5, 0.7]) - _w / 2;
				_py = _sy + _sh * (random [0.35, 0.5, 0.65]) - _h / 2;
				_ang = random 360;
			};
			default {
				_h = _sh * random [0.35, 0.5, 0.7]; _w = _h / pixelH * pixelW;
				_px = _sx + _sw * (random [0.08, 0.5, 0.92]) - _w / 2;
				_py = _sy + _sh * (random [0.08, 0.5, 0.92]) - _h / 2;
				// drips always run down the visor
				_ang = if (_num == 7) then { random [-10, 0, 10] } else { random 360 };
			};
		};
		[true, _max] call BPD_CloneHUD_fnc_crackTrim;
		BPD_CloneHUD_crackList pushBack [_num call BPD_CloneHUD_fnc_dirtTex, _px, _py, _w, _h, _ang, diag_tickTime, controlNull, true];
	};
	call BPD_CloneHUD_fnc_crackTick;
};

// Is the player covered from the last explosion?
//   0 = open, 1 = blast spot unknown but under a building roof, 2 = blocked
// _pos: ASL blast position to test; default = the last one logged.
BPD_CloneHUD_fnc_crackCover = {
	params [["_pos", []]];
	if !(["COVER", true] call BPD_CloneHUD_fnc_crackOpt) exitWith {0};
	private _eye = eyePos player;
	private _ignore = vehicle player;
	if (_pos isEqualTo [] && {diag_tickTime - BPD_CloneHUD_crackBlastTick < 1.5}) then { _pos = BPD_CloneHUD_crackBlastPos; };
	if (_pos isNotEqualTo []) exitWith {
		private _to = _pos vectorAdd [0, 0, 0.4];
		if (_eye distance _to < 1.5) exitWith {0}; // right on top of you: nothing to hide behind
		private _hits = lineIntersectsSurfaces [_eye, _to, player, _ignore, true, 1, "GEOM", "FIRE"];
		[0, 2] select (count _hits > 0 && {((_hits select 0) select 0) distance _to > 0.6})
	};
	private _roof = lineIntersectsSurfaces [_eye, _eye vectorAdd [0, 0, 25], player, _ignore, true, 1, "GEOM", "NONE"];
	if (count _roof == 0) exitWith {0};
	(_roof select 0) params ["", "", "_obj", "_parent"];
	[0, 1] select ((!isNull _obj && {_obj isKindOf "House"}) || {!isNull _parent && {_parent isKindOf "House"}})
};

// Blast radius of an ammo class, cached (0 = not an explosive).
BPD_CloneHUD_fnc_blastRadius = {
	params ["_ammo"];
	private _r = BPD_CloneHUD_blastAmmo get _ammo;
	if (isNil "_r") then {
		private _c = configFile >> "CfgAmmo" >> _ammo;
		_r = 0;
		if (isClass _c && {getNumber (_c >> "indirectHit") > 0}) then {
			private _rng = getNumber (_c >> "indirectHitRange");
			if (_rng >= 1) then { _r = _rng; };
		};
		BPD_CloneHUD_blastAmmo set [_ammo, _r];
	};
	_r
};

// An explosive went off at _pos (ASL). Logs it for the crack cover check
// and throws dirt on the visor if it was close and in the open.
BPD_CloneHUD_fnc_blastNear = {
	params ["_pos", "_radius"];
	if (!hasInterface || {isNull player} || {!alive player}) exitWith {};
	private _d = (eyePos player) distance _pos;
	private _reach = 35 min ((_radius * 2) max 6);
	if (_d > _reach) exitWith {};
	BPD_CloneHUD_crackBlastPos = _pos;
	BPD_CloneHUD_crackBlastTick = diag_tickTime;
	if (vehicle player != player) exitWith {};          // buttoned up in a vehicle
	if (([_pos] call BPD_CloneHUD_fnc_crackCover) > 0) exitWith {}; // behind cover
	[[1, 2] select (_d < _reach * 0.5)] call BPD_CloneHUD_fnc_dirtAdd;
};

// Damage check from either source. _parts = [[bodyPart, damage], ...]
BPD_CloneHUD_fnc_crackCheck = {
	params ["_parts", "_ammo"];
	if !(["ENABLED", true] call BPD_CloneHUD_fnc_crackOpt) exitWith {};
	if (_ammo isEqualType objNull) then { _ammo = typeOf _ammo };
	private _blast = false;
	if (_ammo isEqualType "" && {_ammo != ""}) then {
		private _c = configFile >> "CfgAmmo" >> _ammo;
		_blast = isClass _c && {getNumber (_c >> "indirectHit") > 0} && {getNumber (_c >> "indirectHitRange") >= 1};
	};
	private _head = 0; private _total = 0;
	{
		_x params [["_p", ""], ["_d", 0]];
		if (_d isEqualType 0 && {_p isEqualType ""}) then {
			_total = _total + _d;
			if ((toLower _p) in ["head", "face", "neck", "hithead", "hitface", "hitneck", "face_hub"]) then { _head = _head max _d };
		};
	} forEach _parts;

	if (_blast) exitWith {
		// wait a moment so the Explosion handler has logged where it went off
		[_total] spawn {
			params ["_total"];
			sleep 0.05;
			private _cover = [] call BPD_CloneHUD_fnc_crackCover;
			if (_cover == 2) exitWith {};
			private _thr = (["BLAST", 0.3] call BPD_CloneHUD_fnc_crackOpt) * ([1, 2] select (_cover == 1));
			if (_total >= _thr) then { ["blast"] call BPD_CloneHUD_fnc_crackAdd };
		};
	};
	if (_head >= (["HEAD", 0.5] call BPD_CloneHUD_fnc_crackOpt)) then { ["head"] call BPD_CloneHUD_fnc_crackAdd };
};

// Keeps the crack controls alive and shown / hidden. Runs every 0.1 s.
BPD_CloneHUD_fnc_crackTick = {
	// respawned / new unit / swapped helmet / died: clean visor
	private _h = headgear player;
	if (player != BPD_CloneHUD_crackUnit || {!alive player} || {_h != BPD_CloneHUD_crackHelmet} || {!(["ENABLED", true] call BPD_CloneHUD_fnc_crackOpt)}) then {
		if (BPD_CloneHUD_crackList isNotEqualTo [] && {!BPD_CloneHUD_crackWiping}) then { call BPD_CloneHUD_fnc_crackClear };
		BPD_CloneHUD_crackHelmet = _h;
		if (player != BPD_CloneHUD_crackUnit && {alive player}) then {
			BPD_CloneHUD_crackUnit = player;
			call BPD_CloneHUD_fnc_crackHookUnit;
		};
	};
	// let engineers see who needs a repair
	private _cracked = (BPD_CloneHUD_crackList findIf { !(_x param [8, false]) }) >= 0; // dirt alone isn't a repair job
	if (alive player && {(player getVariable ["BPD_CloneHUD_cracked", false]) isNotEqualTo _cracked}) then {
		player setVariable ["BPD_CloneHUD_cracked", _cracked, true];
	};
	if (BPD_CloneHUD_crackWiping) exitWith {};

	// non-RC cracks wear off after a while, if the server wants that
	// dirt clears after DIRT_LAST on every helmet tier
	private _last = ["LAST", 0] call BPD_CloneHUD_fnc_crackOpt;
	private _isRC = call BPD_CloneHUD_fnc_crackIsRC;
	private _dirtLast = ["DIRT_LAST", 90] call BPD_CloneHUD_fnc_crackOpt;
	if ((_last > 0 && {!_isRC}) || {_dirtLast > 0}) then {
		private _keep = [];
		{
			private _age = diag_tickTime - (_x select 6);
			private _gone = if (_x param [8, false]) then { _dirtLast > 0 && {_age > _dirtLast} } else { _last > 0 && {!_isRC} && {_age > _last} };
			if (_gone) then { ctrlDelete (_x select 7) } else { _keep pushBack _x };
		} forEach BPD_CloneHUD_crackList;
		BPD_CloneHUD_crackList = _keep;
	};
	if (BPD_CloneHUD_crackList isEqualTo []) exitWith {};

	// RC helmets wipe on their own once the newest crack is AUTO_WIPE old
	private _auto = ["AUTO_WIPE", 20] call BPD_CloneHUD_fnc_crackOpt;
	if (_auto > 0 && {alive player} && {call BPD_CloneHUD_fnc_crackIsRC}) then {
		private _newest = 0;
		{ _newest = _newest max (_x select 6) } forEach BPD_CloneHUD_crackList;
		if (diag_tickTime - _newest >= _auto) then { call BPD_CloneHUD_fnc_crackWipe; };
	};
	if (BPD_CloneHUD_crackWiping) exitWith {};

	private _show = alive player && {call BPD_CloneHUD_fnc_crackIsClone} && {cameraView in ["INTERNAL", "GUNNER"]} && {!visibleMap} && {isNull curatorCamera};
	private _d = call BPD_CloneHUD_fnc_crackDisplay;
	if (isNull _d) exitWith {};
	private _alphaCrack = ["OPACITY", 0.85] call BPD_CloneHUD_fnc_crackOpt;
	private _alphaDirt = ["DIRT_OPACITY", 0.8] call BPD_CloneHUD_fnc_crackOpt;
	{
		_x params ["_tex", "_x0", "_y0", "_w", "_h", "_ang", "_born", "_c", ["_isDirt", false]];
		private _alpha = [_alphaCrack, _alphaDirt] select _isDirt;
		if (isNull _c) then {
			_c = _d ctrlCreate ["RscPicture", -1];
			_c ctrlSetText _tex;
			_c ctrlSetPosition [_x0, _y0, _w, _h];
			_c ctrlCommit 0;
			_c ctrlSetAngle [_ang, 0.5, 0.5, true];
			_x set [7, _c];
		};
		_c ctrlSetTextColor [1, 1, 1, _alpha];
		_c ctrlShow _show;
	} forEach BPD_CloneHUD_crackList;
};

// RC helmets only: sweep a wiper across the visor and clear it.
BPD_CloneHUD_fnc_crackWipe = {
	if (BPD_CloneHUD_crackWiping || {!alive player}) exitWith { true };
	if !(call BPD_CloneHUD_fnc_crackIsClone) exitWith { false };
	if !(call BPD_CloneHUD_fnc_crackIsRC) exitWith {
		if (BPD_CloneHUD_crackList isNotEqualTo []) then {
			["Visor wipe needs a Republic Commando helmet", "visorWipe", 3] call BPD_CloneHUD_fnc_crackMsg;
		};
		true
	};
	if (diag_tickTime < BPD_CloneHUD_crackNextWipe) exitWith { true };
	BPD_CloneHUD_crackNextWipe = diag_tickTime + (["WIPE_TIME", 5] call BPD_CloneHUD_fnc_crackOpt);
	BPD_CloneHUD_crackWiping = true;
	["Visor clear", 2] spawn BPD_CloneHUD_fnc_crackSweep;
	true
};

// Wiper sweep across the visor; clears every crack and dirt as it passes,
// then shows _msg. Used by the RC wipe and by Repair Visor. Caller sets
// BPD_CloneHUD_crackWiping = true first (spawn this).
BPD_CloneHUD_fnc_crackSweep = {
	params ["_msg", ["_msgTime", 2]];
	if (true) then {
		private _d = call BPD_CloneHUD_fnc_crackDisplay;
		private _show = cameraView in ["INTERNAL", "GUNNER"] && {!visibleMap};
		private _bw = safezoneW * 0.035;
		private _bh = safezoneH * 1.4;
		private _blade = _d ctrlCreate ["RscPicture", -1];
		private _trail = _d ctrlCreate ["RscPicture", -1];
		_blade ctrlSetText "#(argb,8,8,3)color(0.85,0.93,1,0.55)";
		_trail ctrlSetText "#(argb,8,8,3)color(0.75,0.88,1,0.12)";
		{ _x ctrlShow _show } forEach [_blade, _trail];
		private _by = safezoneY - safezoneH * 0.2;
		private _x0 = safezoneX - _bw * 3;
		private _x1 = safezoneX + safezoneW + _bw;
		private _speed = 0.8;              // 1.0 = original speed; 0.8 = a little slower, like RC
		private _dur = 0.55 / _speed;
		private _t0 = diag_tickTime;
		playSound3D ["A3\Sounds_F\structures\doors\GlassServoDoors\GlassServoDoorsSqueak_1.wss", player, false, getPosASL player, 2, 1.6 * _speed, 10];
		private _cleared = [];
		while { diag_tickTime - _t0 < _dur } do {
			private _p = (diag_tickTime - _t0) / _dur;
			_p = 1 - (1 - _p) ^ 2; // ease out
			private _bx = _x0 + (_x1 - _x0) * _p;
			_blade ctrlSetPosition [_bx, _by, _bw, _bh];
			_trail ctrlSetPosition [_bx - _bw * 4, _by, _bw * 4, _bh];
			{ _x ctrlCommit 0; _x ctrlSetAngle [8, 0.5, 0.5, true] } forEach [_blade, _trail];
			{
				// a crack is wiped once the blade passes its middle
				if (!(_forEachIndex in _cleared) && {_bx > (_x select 1) + (_x select 3) / 2}) then {
					_cleared pushBack _forEachIndex;
					private _c = _x select 7;
					if (!isNull _c) then { _c ctrlSetFade 1; _c ctrlCommit (0.15 / _speed) };
				};
			} forEach BPD_CloneHUD_crackList;
			uiSleep 0.01;
		};
		uiSleep (0.15 / _speed);
		ctrlDelete _blade; ctrlDelete _trail;
		call BPD_CloneHUD_fnc_crackClear;
		BPD_CloneHUD_crackWiping = false;
		[_msg, "visorWipe", _msgTime] call BPD_CloneHUD_fnc_crackMsg;
	};
};

// ---------------------------------------------------------------
//  Engineer repair - any helmet tier. ACE: interact with the trooper >
//  Repair Visor (or self-interaction > Equipment for your own).
//  No ACE: hold-action while looking at the trooper (or your own).
// ---------------------------------------------------------------
// Can the local player repair _t's visor right now?
BPD_CloneHUD_fnc_crackCanRepair = {
	params ["_t"];
	private _who = ["REPAIR", 1] call BPD_CloneHUD_fnc_crackOpt; // 0 off, 1 engineers, 2 anyone
	if (_who == 0 || {!alive player} || {isNull _t} || {!alive _t}) exitWith { false };
	if !(_t getVariable ["BPD_CloneHUD_cracked", false]) exitWith { false };
	if (_t != player && {player distance _t > 4}) exitWith { false };
	if (_who == 1 && {isNil "BPD_CloneHUD_fnc_isEngineer" || {!(call BPD_CloneHUD_fnc_isEngineer)}}) exitWith { false };
	if ((["REPAIR_KIT", false] call BPD_CloneHUD_fnc_crackOpt) && {(items player) findIf { _x == "ToolKit" || {_x == "ACE_ToolKit"} } < 0}) exitWith { false };
	true
};

BPD_CloneHUD_fnc_crackRepairDone = {
	params ["_t"];
	if !([_t] call BPD_CloneHUD_fnc_crackCanRepair) exitWith {};
	if (_t == player) then {
		[name player] call BPD_CloneHUD_fnc_crackRepaired;
	} else {
		[name player] remoteExecCall ["BPD_CloneHUD_fnc_crackRepaired", _t];
		systemChat format ["Repaired %1's visor", name _t];
	};
};

// Runs on the trooper whose visor was repaired.
BPD_CloneHUD_fnc_crackRepaired = {
	params [["_by", ""]];
	if (BPD_CloneHUD_crackList isEqualTo [] || {BPD_CloneHUD_crackWiping}) exitWith {};
	BPD_CloneHUD_crackWiping = true; // hold the tick off while the wiper runs
	playSound3D ["A3\Sounds_F\structures\doors\GlassServoDoors\GlassServoDoorsKnob_1.wss", player, false, getPosASL player, 2, 1, 10];
	private _msg = if (_by == "" || {_by == name player}) then { "VISOR REPAIRED" } else { format ["VISOR REPAIRED by %1", _by] };
	// same wiper sweep as the RC wipe
	[format ["<t color='#7dff9a'>%1</t>", _msg], 3] spawn BPD_CloneHUD_fnc_crackSweep;
};

BPD_CloneHUD_fnc_crackRepairStart = {
	params ["_t"];
	if !([_t] call BPD_CloneHUD_fnc_crackCanRepair) exitWith {};
	private _time = ["REPAIR_TIME", 8] call BPD_CloneHUD_fnc_crackOpt;
	private _title = if (_t == player) then { "Repairing visor..." } else { format ["Repairing %1's visor...", name _t] };
	[_time, [_t], {
		params ["_args"];
		[_args select 0] call BPD_CloneHUD_fnc_crackRepairDone;
	}, {}, _title, {
		params ["_args"];
		[_args select 0] call BPD_CloneHUD_fnc_crackCanRepair
	}] call ace_common_fnc_progressBar;
};

// No-ACE hold action: the trooper you're looking at within 3 m, else yourself.
BPD_CloneHUD_fnc_crackRepairTarget = {
	private _t = cursorObject;
	if (!(_t isKindOf "CAManBase") || {player distance _t > 3}) then { _t = player };
	if ([_t] call BPD_CloneHUD_fnc_crackCanRepair) then { BPD_CloneHUD_crackRepairT = _t; true } else { false }
};

// Damage hook on the current player unit (only without ACE medical) and
// the scroll-menu wipe action (only without ACE interaction).
BPD_CloneHUD_fnc_crackHookUnit = {
	// blasts that hurt you: fallback for explosives the Explode hook missed
	// (placed charges, mines). Logs the spot for the crack cover check.
	player addEventHandler ["Explosion", {
		params ["_unit", "_dmg", ["_src", objNull]];
		if (_unit != player) exitWith {};
		if (diag_tickTime - BPD_CloneHUD_crackBlastTick < 0.5) exitWith {}; // the Explode hook already had it
		if (!isNull _src) then {
			[getPosASL _src, 5] call BPD_CloneHUD_fnc_blastNear;
		} else {
			if (vehicle player == player && {([] call BPD_CloneHUD_fnc_crackCover) == 0}) then { [1] call BPD_CloneHUD_fnc_dirtAdd; };
		};
	}];
	if (!BPD_CloneHUD_crackACE) then {
		player addEventHandler ["Dammaged", {
			params ["_unit", "_sel", "_dmg", "_hi", "_hp", "_shooter", ["_proj", ""]];
			if (_unit != player) exitWith {};
			[[[_sel, _dmg]], _proj] call BPD_CloneHUD_fnc_crackCheck;
		}];
	};
	if (!BPD_CloneHUD_crackACEInteract) then {
		player addAction ["<t color='#9fd4ff'>Wipe Visor</t>", { call BPD_CloneHUD_fnc_crackWipe }, [], 6, false, true, "",
			"_this == _target && {BPD_CloneHUD_crackList isNotEqualTo []} && {call BPD_CloneHUD_fnc_crackIsRC}"];
		[player, "Repair Visor", "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_repair_ca.paa", "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_repair_ca.paa",
			"call BPD_CloneHUD_fnc_crackRepairTarget", "[BPD_CloneHUD_crackRepairT] call BPD_CloneHUD_fnc_crackCanRepair",
			{}, {}, { [BPD_CloneHUD_crackRepairT] call BPD_CloneHUD_fnc_crackRepairDone }, {}, [],
			["REPAIR_TIME", 8] call BPD_CloneHUD_fnc_crackOpt, 5, false] call BIS_fnc_holdActionAdd;
	};
};

// Every explosive projectile (grenades, shells, rockets, mortars) - local
// or remote - reports where it went off.
if (hasInterface && {isNil "BPD_CloneHUD_blastEH"}) then {
	BPD_CloneHUD_blastEH = addMissionEventHandler ["ProjectileCreated", {
		params ["_proj"];
		private _r = [typeOf _proj] call BPD_CloneHUD_fnc_blastRadius;
		if (_r <= 0) exitWith {};
		_proj setVariable ["BPD_CloneHUD_blastR", _r];
		_proj addEventHandler ["Explode", {
			params ["_p", "_pos"];
			[_pos, _p getVariable ["BPD_CloneHUD_blastR", 5]] call BPD_CloneHUD_fnc_blastNear;
		}];
	}];
};

BPD_CloneHUD_crackACE = isClass (configFile >> "CfgPatches" >> "ace_medical_engine");
BPD_CloneHUD_crackACEInteract = isClass (configFile >> "CfgPatches" >> "ace_interact_menu");

if (BPD_CloneHUD_crackACE) then {
	["ace_medical_woundReceived", {
		params ["_unit", "_a1", "_a2", "_a3", "_a4"];
		if (_unit != player) exitWith {};
		if (_a1 isEqualType []) then {
			// ACE 3.16+: [unit, [[damage, bodyPart, realDamage], ...], shooter, ammo]
			private _parts = _a1 apply { [_x param [1, ""], _x param [0, 0]] };
			[_parts, _a3] call BPD_CloneHUD_fnc_crackCheck;
		} else {
			// older ACE: [unit, bodyPart, damage, shooter, ammo]
			[[[_a1, _a2]], _a4] call BPD_CloneHUD_fnc_crackCheck;
		};
	}] call CBA_fnc_addEventHandler;
};

if (BPD_CloneHUD_crackACEInteract) then {
	private _act = ["BPD_CloneHUD_wipeVisor", "Wipe Visor", "", { call BPD_CloneHUD_fnc_crackWipe },
		{ _player == _target && {BPD_CloneHUD_crackList isNotEqualTo []} && {call BPD_CloneHUD_fnc_crackIsRC} }] call ace_interact_menu_fnc_createAction;
	["CAManBase", 1, ["ACE_SelfActions", "ACE_Equipment"], _act, true] call ace_interact_menu_fnc_addActionToClass;

	private _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\repair_ca.paa";
	private _rep = ["BPD_CloneHUD_repairVisor", "Repair Visor", _icon, { [_target] call BPD_CloneHUD_fnc_crackRepairStart },
		{ _target != _player && {[_target] call BPD_CloneHUD_fnc_crackCanRepair} }] call ace_interact_menu_fnc_createAction;
	["CAManBase", 0, ["ACE_MainActions"], _rep, true] call ace_interact_menu_fnc_addActionToClass;
	private _repSelf = ["BPD_CloneHUD_repairVisorSelf", "Repair Visor", _icon, { [_player] call BPD_CloneHUD_fnc_crackRepairStart },
		{ _player == _target && {[_player] call BPD_CloneHUD_fnc_crackCanRepair} }] call ace_interact_menu_fnc_createAction;
	["CAManBase", 1, ["ACE_SelfActions", "ACE_Equipment"], _repSelf, true] call ace_interact_menu_fnc_addActionToClass;
};

[] spawn {
	waitUntil { sleep 1; !isNull player };
	while { true } do {
		call BPD_CloneHUD_fnc_crackTick;
		uiSleep 0.1;
	};
};
