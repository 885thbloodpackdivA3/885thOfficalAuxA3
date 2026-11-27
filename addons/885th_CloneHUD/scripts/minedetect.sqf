/*
	885th Bloodpack Division - Clone HUD - Built-in mine detector
	-------------------------------------------------------------
	Like the medic pings: a role function. Only a trooper who is an
	ENGINEER (ACE engineer / EOD, or the vanilla engineer / explosive
	specialist trait) AND carries a MINE DETECTOR (vanilla MineDetector,
	ACE VMM3 / VMH3, or anything in "Extra Detector Classes") gets it -
	the "Who Gets It" server setting can loosen that.

	While it's on, the helmet scans around the trooper (no need to hold
	the detector):
	  - each newly found mine: HUD message "MINE DETECTED - 8m NE"
	    plus a warning tone, and it's revealed (vanilla map / AI marker)
	  - a marker over every mine in range: "MINE 6m", orange, red when
	    you're inside the Danger Distance
	  - proximity beeps that speed up as you close on the nearest mine
	  - optionally shares found mines with the squad, so everyone in it
	    sees the markers too (needs the datalink)

	Jamming (jamming.sqf): SENSORS JAMMED (tier 3) knocks the detector
	out; COMMS LOST (tier 2+) stops sharing with the squad.
	Toggle per player: 10. Mine Detector > Mine Detector, or the
	"Toggle Mine Detector" keybind (unbound by default).
*/

BPD_CloneHUD_mdFound = [];   // [[mine, foundTick], ...] found by this player's own detector
BPD_CloneHUD_mdShared = [];  // [[mine, finderName, tick], ...] from the squad's engineers
BPD_CloneHUD_mdState = "";   // "", "ON", "JAMMED" - last state, for the on/off messages
BPD_CloneHUD_mdNextBeep = 0;
BPD_CloneHUD_mdIcon = ["", "\A3\ui_f\data\map\markers\military\warning_ca.paa"] select (fileExists "\A3\ui_f\data\map\markers\military\warning_ca.paa");
BPD_CloneHUD_mdBeep = call {
	private _s = ["ace_minedetector_beep", "Beep_Target", "FD_CP_Clear_F"] select { isClass (configFile >> "CfgSounds" >> _x) };
	if (_s isEqualTo []) then {"click"} else {_s select 0}
};
BPD_CloneHUD_fnc_mdOpt = { params ["_n", "_d"]; missionNamespace getVariable [format ["BPD_CloneHUD_MINE_%1", _n], _d] };

BPD_CloneHUD_fnc_isEngineer = {
	// ACE stores these as number or bool depending on who set them
	private _num = { if (_this isEqualType true) then { [0, 1] select _this } else { _this } };
	private _eng = (player getVariable ["ACE_IsEngineer", getNumber (configOf player >> "engineer")]) call _num;
	private _eod = (player getVariable ["ACE_isEOD", getNumber (configOf player >> "canDeactivateMines")]) call _num;
	_eng >= 1 || {_eod >= 1} || {player getUnitTrait "engineer"} || {player getUnitTrait "explosiveSpecialist"}
};

BPD_CloneHUD_fnc_hasMineDetector = {
	private _extra = (["DETECTORS", ""] call BPD_CloneHUD_fnc_mdOpt) splitString ", ;";
	private _known = ["MineDetector", "ACE_VMM3", "ACE_VMH3"] + _extra;
	((items player) + (weapons player) + (assignedItems player)) findIf {
		private _c = _x;
		(_known findIf { _x == _c }) >= 0 // == is case-insensitive
		|| {getText (configFile >> "CfgWeapons" >> _c >> "simulation") == "ItemMineDetector"}
		|| {isText (configFile >> "CfgWeapons" >> _c >> "ace_minedetector_detectorConfig")}
	} >= 0
};

// 0 engineer + detector (default), 1 detector only, 2 engineer only, 3 everyone
BPD_CloneHUD_fnc_mdQualified = {
	switch (["REQUIRE", 0] call BPD_CloneHUD_fnc_mdOpt) do {
		case 1: { call BPD_CloneHUD_fnc_hasMineDetector };
		case 2: { call BPD_CloneHUD_fnc_isEngineer };
		case 3: { true };
		default { (call BPD_CloneHUD_fnc_isEngineer) && {call BPD_CloneHUD_fnc_hasMineDetector} };
	}
};

BPD_CloneHUD_fnc_mdMessage = {
	params ["_msg", "_id", ["_time", 6]];
	// HUD messages only - no side-chat fallback (it fired whenever the HUD
	// went down, e.g. "MINE DETECTOR OFFLINE" with raw <t> tags in chat)
	if ((missionNamespace getVariable ["HUD_hasHelmet", false]) && {missionNamespace getVariable ["HUD_systemMessageAllowed", false]} && {missionNamespace getVariable ["SYSTEM_MESSAGES", true]}) then {
		[_msg, _id, _time] call HUD_fnc_addSystemMessage;
	};
};

BPD_CloneHUD_fnc_mdCard = {
	params ["_pos"];
	["N","NE","E","SE","S","SW","W","NW"] select (round ((player getDir _pos) / 45) mod 8)
};

// Squad side: mines another engineer found.
BPD_CloneHUD_fnc_mdShare = {
	params ["_mines", "_finder"];
	if (!hasInterface || {isNull player}) exitWith {};
	if ((missionNamespace getVariable ["BPD_CloneHUD_jamTier", 0]) >= 2) exitWith {}; // datalink down
	private _new = 0;
	{
		private _m = _x;
		if (!isNull _m && {mineActive _m} && {(BPD_CloneHUD_mdShared findIf { (_x select 0) isEqualTo _m }) < 0}) then {
			BPD_CloneHUD_mdShared pushBack [_m, _finder, diag_tickTime];
			playerSide revealMine _m;
			_new = _new + 1;
		};
	} forEach _mines;
	if (_new > 0 && {call BPD_CloneHUD_fnc_hudUp}) then {
		private _near = selectMin (_mines apply { if (isNull _x) then {1e6} else { player distance _x } });
		[format ["<t color='#ff8c1a'>MINES MARKED</t> by %1 - %2 found, nearest %3m", _finder, _new, round _near], "bpdMineShare", 6] call BPD_CloneHUD_fnc_mdMessage;
		playSound "click";
	};
};

BPD_CloneHUD_fnc_mdTick = {
	// drop cleared / defused / detonated mines
	BPD_CloneHUD_mdFound = BPD_CloneHUD_mdFound select { !isNull (_x select 0) && {mineActive (_x select 0)} };
	BPD_CloneHUD_mdShared = BPD_CloneHUD_mdShared select {
		!isNull (_x select 0) && {mineActive (_x select 0)} && {diag_tickTime - (_x select 2) < 900}
	};

	private _on = (["ENABLED", true] call BPD_CloneHUD_fnc_mdOpt) && {alive player} && {call BPD_CloneHUD_fnc_hudUp} && {call BPD_CloneHUD_fnc_mdQualified};
	private _jammed = (missionNamespace getVariable ["BPD_CloneHUD_jamTier", 0]) >= 3;
	private _state = if (!_on) then {""} else { ["ON", "JAMMED"] select _jammed };
	if (_state != BPD_CloneHUD_mdState) then {
		switch (_state) do {
			case "ON": { ["<t color='#3cb371'>MINE DETECTOR ONLINE</t>", "bpdMineState", 4] call BPD_CloneHUD_fnc_mdMessage; };
			case "JAMMED": { ["<t color='#ff3b30'>MINE DETECTOR JAMMED</t>", "bpdMineState", 5] call BPD_CloneHUD_fnc_mdMessage; playSound "glitch_short"; };
			default { if (BPD_CloneHUD_mdState == "ON") then { ["<t color='#8aa0a8'>MINE DETECTOR OFFLINE</t>", "bpdMineState", 4] call BPD_CloneHUD_fnc_mdMessage; }; };
		};
		BPD_CloneHUD_mdState = _state;
	};
	if (_state != "ON") exitWith {};

	private _range = ["RANGE", 15] call BPD_CloneHUD_fnc_mdOpt;
	private _inRange = allMines select { mineActive _x && {_x distance player <= _range} };
	private _new = _inRange select { private _m = _x; (BPD_CloneHUD_mdFound findIf { (_x select 0) isEqualTo _m }) < 0 };
	if (count _new > 0) then {
		{ BPD_CloneHUD_mdFound pushBack [_x, diag_tickTime]; playerSide revealMine _x; } forEach _new;
		private _closest = [_new, [], { player distance _x }, "ASCEND"] call BIS_fnc_sortBy;
		private _m = _closest select 0;
		private _txt = format ["<t color='#ff8c1a' font='PuristaBold'>MINE DETECTED</t> - %1m %2%3",
			round (player distance _m), [getPosATL _m] call BPD_CloneHUD_fnc_mdCard,
			["", format [" (+%1 more)", count _new - 1]] select (count _new > 1)];
		[_txt, "bpdMineFound", 6] call BPD_CloneHUD_fnc_mdMessage;
		playSound "threat_detector";
		// share with the squad (needs the datalink)
		if ((["SHARE", true] call BPD_CloneHUD_fnc_mdOpt) && {(missionNamespace getVariable ["BPD_CloneHUD_jamTier", 0]) < 2}) then {
			private _to = (units group player) select { isPlayer _x && {_x != player} };
			if (count _to > 0) then { [_new, name player] remoteExec ["BPD_CloneHUD_fnc_mdShare", _to]; };
		};
	};

	// proximity beep: faster as you close on the nearest mine
	if ((["BEEP", true] call BPD_CloneHUD_fnc_mdOpt) && {count _inRange > 0}) then {
		private _d = selectMin (_inRange apply { player distance _x });
		if (diag_tickTime >= BPD_CloneHUD_mdNextBeep) then {
			playSound BPD_CloneHUD_mdBeep;
			BPD_CloneHUD_mdNextBeep = diag_tickTime + linearConversion [2, _range max 3, _d, 0.2, 1.6, true];
		};
	};
};

BPD_CloneHUD_fnc_mdDraw3D = {
	if (count BPD_CloneHUD_mdFound == 0 && {count BPD_CloneHUD_mdShared == 0}) exitWith {};
	if !(["MARKERS", true] call BPD_CloneHUD_fnc_mdOpt) exitWith {};
	if !(call BPD_CloneHUD_fnc_hudUp) exitWith {};
	private _danger = ["DANGER", 5] call BPD_CloneHUD_fnc_mdOpt;
	private _show = ["MARKER_RANGE", 75] call BPD_CloneHUD_fnc_mdOpt;
	private _pulse = 0.65 + 0.35 * abs (sin (diag_tickTime * 200));
	private _drawn = [];
	{
		_x params ["_m"];
		if (!isNull _m && {!(_m in _drawn)}) then {
			_drawn pushBack _m;
			private _d = player distance _m;
			if (_d <= _show) then {
				private _col = if (_d <= _danger) then { [1, 0.23, 0.19, _pulse] } else { [1, 0.55, 0.1, 0.9] };
				private _pos = (getPosATLVisual _m) vectorAdd [0, 0, 0.35];
				drawIcon3D [BPD_CloneHUD_mdIcon, _col, _pos, 0.7, 0.7, 0, format ["MINE %1m", round _d], 2, 0.03, "RobotoCondensedBold", "center", _d <= _danger];
			};
		};
	} forEach (BPD_CloneHUD_mdFound + BPD_CloneHUD_mdShared);
};

BPD_CloneHUD_fnc_mdToggle = {
	private _v = !(["ENABLED", true] call BPD_CloneHUD_fnc_mdOpt);
	BPD_CloneHUD_MINE_ENABLED = _v;
	if (_v && {!(call BPD_CloneHUD_fnc_mdQualified)}) then {
		private _need = ["an engineer with a mine detector", "a mine detector", "the engineer role", "an engineer with a mine detector"] select (["REQUIRE", 0] call BPD_CloneHUD_fnc_mdOpt);
		[format ["<t color='#8aa0a8'>Mine detector on - needs %1</t>", _need], "bpdMineState", 4] call BPD_CloneHUD_fnc_mdMessage;
	};
	playSound "click";
	true
};

if (hasInterface) then {
	[] spawn {
		waitUntil { sleep 1; !isNull player && {!isNil "BPD_CloneHUD_fnc_hudUp"} };
		addMissionEventHandler ["Draw3D", { call BPD_CloneHUD_fnc_mdDraw3D; }];
		while {true} do {
			call BPD_CloneHUD_fnc_mdTick;
			sleep 0.25;
		};
	};
};
