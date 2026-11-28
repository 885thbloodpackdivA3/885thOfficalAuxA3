/*
	885th Bloodpack Division - Clone HUD - Squad Medical
	---------------------------------------------------------------
	Reads each squadmate's real medical state for the squad list
	(teamList.sqf) and raises HUD alerts when someone gets worse.

	Data sources - every variable name below was taken from the mods
	themselves (ACE ace_medical_engine script_macros_medical.hpp, KAT
	kat_airway / kat_breathing / kat_circulation), not guessed, and only
	variables those mods BROADCAST (setVariable [..., true]) are used, so
	it works for other players and AI, not just yourself:

	  ACE Medical (synced as soon as they change)
	    ACE_isUnconscious, ace_medical_inCardiacArrest,
	    ace_medical_woundBleeding (blood loss rate), ace_medical_openWounds,
	    ace_medical_tourniquets, ace_medical_fractures
	  ACE Medical (synced every 10-20 s for other people, so a squadmate's
	  number lags a little - yours is live)
	    ace_medical_bloodVolume (6.0 L = full), ace_medical_pain,
	    ace_medical_painSuppress, ace_medical_spo2
	  KAT Advanced Medical (optional, synced on change)
	    kat_airway_obstruction, kat_airway_occluded,
	    kat_breathing_pneumothorax (0-4), kat_breathing_tensionpneumothorax,
	    kat_breathing_hemopneumothorax, kat_breathing_airwayStatus (SpO2 %),
	    kat_circulation_cardiacArrestType (1 asystole, 2 PEA, 3 VF, 4 VT),
	    kat_circulation_internalBleeding
	  No ACE: vanilla damage / incapacitated state.

	BPD_CloneHUD_fnc_medStatus returns
	  [_level, _label, _color, _flags]
	  _level  4 critical (KIA / arrest), 3 down, 2 serious (bleeding,
	          airway, tension pneumo...), 1 minor, 0 OK
	  _label  main status word for the list
	  _color  "#RRGGBB" for that word
	  _flags  array of [text, color] detail tags
*/

BPD_CloneHUD_aceMedLoaded = isClass (configFile >> "CfgPatches" >> "ace_medical");
BPD_CloneHUD_katLoaded = isClass (configFile >> "CfgPatches" >> "kat_main");

BPD_CloneHUD_MED_RED = "#ff3b30";
BPD_CloneHUD_MED_ORANGE = "#ff8c1a";
BPD_CloneHUD_MED_YELLOW = "#ffd23f";
BPD_CloneHUD_MED_GREEN = "#3cb371";
BPD_CloneHUD_MED_BLUE = "#6ec6ff";

BPD_CloneHUD_fnc_medStatus = {
	params ["_unit"];
	private _R = BPD_CloneHUD_MED_RED;
	private _O = BPD_CloneHUD_MED_ORANGE;
	private _Y = BPD_CloneHUD_MED_YELLOW;
	private _G = BPD_CloneHUD_MED_GREEN;
	private _B = BPD_CloneHUD_MED_BLUE;

	if (!alive _unit) exitWith { [4, "KIA", _R, []] };

	// ---------- no ACE: vanilla only ----------
	if (!BPD_CloneHUD_aceMedLoaded) exitWith {
		if (lifeState _unit == "INCAPACITATED") exitWith { [3, "DOWN", _R, []] };
		private _d = damage _unit;
		if (_d > 0.5) exitWith { [2, "WOUNDED", _O, []] };
		if (_d > 0) exitWith { [1, "WOUNDED", _Y, []] };
		[0, "OK", _G, []]
	};

	// ---------- ACE / KAT ----------
	private _flags = [];
	private _level = 0;
	private _label = "OK";
	private _color = _G;

	private _uncon = _unit getVariable ["ACE_isUnconscious", false];
	private _arrest = _unit getVariable ["ace_medical_inCardiacArrest", false];
	private _bleedRate = _unit getVariable ["ace_medical_woundBleeding", 0];
	private _bloodL = _unit getVariable ["ace_medical_bloodVolume", 6];
	private _pain = 0 max ((_unit getVariable ["ace_medical_pain", 0]) - (_unit getVariable ["ace_medical_painSuppress", 0])) min 1;
	private _tq = _unit getVariable ["ace_medical_tourniquets", [0,0,0,0,0,0]];
	private _fx = _unit getVariable ["ace_medical_fractures", [0,0,0,0,0,0]];
	private _wounds = _unit getVariable ["ace_medical_openWounds", createHashMap];
	private _hasOpenWounds = false;
	if (_wounds isEqualType createHashMap) then {
		{ if (count _y > 0) exitWith { _hasOpenWounds = true; }; } forEach _wounds;
	};

	// main status, worst first
	switch (true) do {
		case (_arrest): {
			_level = 4; _label = "ARREST"; _color = _R;
			if (BPD_CloneHUD_katLoaded) then {
				private _rhythm = ["", "ASYS", "PEA", "VF", "VT"] param [_unit getVariable ["kat_circulation_cardiacArrestType", 0], ""];
				if (_rhythm != "") then { _label = "ARREST " + _rhythm; };
			};
		};
		case (_uncon): { _level = 3; _label = "DOWN"; _color = _R; };
		case (_bleedRate > 0): { _level = 2; _label = "BLEEDING"; _color = _O; };
		case (_hasOpenWounds || {_bloodL < 5.1}): { _level = 1; _label = "WOUNDED"; _color = _Y; };
	};

	// ---------- detail flags ----------
	// Blood volume, using ACE's own hemorrhage class thresholds
	// (5.1 / 4.2 / 3.6 L of 6.0).
	if (_bloodL < 5.9) then {
		private _pct = round ((_bloodL / 6) * 100);
		private _c = call { if (_bloodL < 3.6) exitWith {_R}; if (_bloodL < 4.2) exitWith {_O}; if (_bloodL < 5.1) exitWith {_Y}; _B };
		_flags pushBack [format ["BLD %1%%", _pct], _c];
		if (_bloodL < 4.2) then { _level = _level max 2; };
	};

	if (BPD_CloneHUD_katLoaded) then {
		if ((_unit getVariable ["kat_airway_obstruction", false]) || {_unit getVariable ["kat_airway_occluded", false]}) then {
			_flags pushBack ["AIRWAY", _R];
			_level = _level max 2;
		};
		switch (true) do {
			case (_unit getVariable ["kat_breathing_tensionpneumothorax", false]): { _flags pushBack ["TENSION PTX", _R]; _level = _level max 2; };
			case (_unit getVariable ["kat_breathing_hemopneumothorax", false]): { _flags pushBack ["HEMO PTX", _R]; _level = _level max 2; };
			case ((_unit getVariable ["kat_breathing_pneumothorax", 0]) > 0): { _flags pushBack ["PTX", _O]; _level = _level max 1; };
		};
		if ((_unit getVariable ["kat_circulation_internalBleeding", 0]) > 0) then {
			_flags pushBack ["INT BLEED", _O];
			_level = _level max 2;
		};
	};

	// SpO2: KAT's own value when loaded, otherwise ACE's (newer ACE has one).
	private _spo2 = if (BPD_CloneHUD_katLoaded) then {
		_unit getVariable ["kat_breathing_airwayStatus", 100]
	} else {
		_unit getVariable ["ace_medical_spo2", 100]
	};
	if (_spo2 < 92) then {
		_flags pushBack [format ["SpO2 %1", round _spo2], [_Y, _R] select (_spo2 < 85)];
		if (_spo2 < 85) then { _level = _level max 2; };
	};

	private _hasTQ = (_tq findIf { _x > 0 }) > -1;
	private _splinted = (_fx findIf { _x == -1 }) > -1;
	if (_hasTQ) then { _flags pushBack ["TQ", _Y]; };
	if ((_fx findIf { _x == 1 }) > -1) then { _flags pushBack ["FRACTURE", _Y]; _level = _level max 1; };
	if (_pain > 0.2) then { _flags pushBack ["PAIN", _Y]; };
	if (_pain > 0.4) then { _level = _level max 1; }; // strong pain still needs a medic

	// Raise the main word if only a flag made it serious
	// (e.g. tension pneumo with no external bleeding).
	if (_label == "OK" && {_level >= 1}) then {
		_label = if (_level >= 2) then {"CRITICAL"} else {"WOUNDED"};
		_color = [_Y, _O] select (_level >= 2);
	};

	// TREATED (green): nothing above needs a medic any more, but they've
	// clearly been patched up - bandaged (not yet stitched) wounds, a
	// tourniquet or splint still on, some blood loss or mild pain left.
	// Stitched wounds alone count as fully recovered -> plain OK.
	if (_level == 0) then {
		private _bandaged = _unit getVariable ["ace_medical_bandagedWounds", createHashMap];
		private _hasBandaged = false;
		if (_bandaged isEqualType createHashMap) then {
			{ if (count _y > 0) exitWith { _hasBandaged = true; }; } forEach _bandaged;
		};
		if (_hasBandaged || {_hasTQ} || {_splinted} || {_bloodL < 5.9} || {_pain > 0}) then {
			_label = "TREATED";
			_color = _G;
		};
	};

	[_level, _label, _color, _flags]
};

// Whether this player gets the detail flags, per the settings.
BPD_CloneHUD_fnc_medShowDetail = {
	private _mode = missionNamespace getVariable ["BPD_CloneHUD_SQUAD_MEDICAL", 2];
	if (_mode < 2) exitWith {false};
	if (!(missionNamespace getVariable ["BPD_CloneHUD_SQUAD_MEDICAL_MEDIC_ONLY", false])) exitWith {true};
	private _medicClass = player getVariable ["ace_medical_medicClass", parseNumber (player getUnitTrait "medic")];
	_medicClass >= 1
};

// Alerts: a system message when a squadmate moves to a worse state.
// Only on escalation, and once per new problem, so a long bleed doesn't
// spam the log.
BPD_CloneHUD_fnc_medAlert = {
	params ["_unit", "_status"];
	if (!(missionNamespace getVariable ["BPD_CloneHUD_SQUAD_MEDICAL_ALERTS", true])) exitWith {};
	if (_unit == player) exitWith {};
	_status params ["_level", "_label", "", "_flags"];
	private _key = _label + "|" + ((_flags apply {_x select 0}) select {_x in ["AIRWAY","TENSION PTX","HEMO PTX","INT BLEED"]} joinString ",");
	private _prev = _unit getVariable ["BPD_CloneHUD_medPrev", [0, "OK|"]];
	_unit setVariable ["BPD_CloneHUD_medPrev", [_level, _key]];
	if (_key == (_prev select 1)) exitWith {};

	private _newFlags = ((_flags apply {_x select 0}) select {_x in ["AIRWAY","TENSION PTX","HEMO PTX","INT BLEED"]}) - (((_prev select 1) splitString "|,") );
	private _msg = "";
	if (_level > (_prev select 0) && {_level >= 2}) then {
		_msg = format ["%1: %2", name _unit, _label];
	};
	// Recovered: was hurt, a medic has dealt with it.
	if (_level == 0 && {(_prev select 0) >= 1} && {_label in ["TREATED", "OK"]}) then {
		_msg = format ["%1: treated - no longer needs a medic", name _unit];
	};
	if (count _newFlags > 0) then {
		_msg = format ["%1: %2", name _unit, (if (_msg == "") then {""} else {_label + " / "}) + (_newFlags joinString ", ")];
	};
	if (_msg != "") then {
		[_msg, "bpdMed_" + (netId _unit), 8] call HUD_fnc_addSystemMessage;
		if (_level >= 3) then { playSound "glitch_short"; };
	};
};

// ------------------------------------------------------------
//  Medic pings
// ------------------------------------------------------------
// Runs on every client but only does anything while the player is a
// medic (ACE medic class / vanilla medic trait, or Green Team if that
// option is on). When a trooper in scope drops to the ping threshold
// the medic gets a "MEDIC NEEDED" message with distance and bearing,
// a sound, and a marker over the casualty that stays until they're
// back above the threshold. Every client reads the broadcast ACE/KAT
// variables itself, so nothing is sent over the network.

BPD_CloneHUD_fnc_isMedic = {
	// Same fallback ACE uses: the unit's config "attendant" value, plus
	// the vanilla medic trait for non-ACE games.
	private _cls = player getVariable ["ace_medical_medicClass", getNumber (configOf player >> "attendant")];
	if (_cls isEqualType true) then { _cls = parseNumber _cls; };
	if (_cls >= 1 || {player getUnitTrait "medic"}) exitWith {true};
	(missionNamespace getVariable ["BPD_CloneHUD_MEDIC_PING_GREEN", true]) && {assignedTeam player == "GREEN"}
};

BPD_CloneHUD_fnc_medicPingCandidates = {
	private _scope = missionNamespace getVariable ["BPD_CloneHUD_MEDIC_PING_SCOPE", 1];
	private _range = missionNamespace getVariable ["BPD_CloneHUD_MEDIC_PING_RANGE", 1000];
	private _pool = switch (_scope) do {
		case 0: { units group player };
		case 1: { (allPlayers - entities "HeadlessClient_F") + (units group player) };
		default { allUnits };
	};
	private _side = side group player;
	(_pool arrayIntersect _pool) select {
		_x != player && {alive _x} && {_x isKindOf "CAManBase"}
		&& {(side group _x) getFriend _side >= 0.6 || {group _x == group player}}
		&& {_scope == 0 || {_x distance player <= _range}}
	}
};

BPD_CloneHUD_fnc_medicPingNotify = {
	params ["_unit", "_label", "_reminder"];
	private _dist = round (player distance _unit);
	private _dir = player getDir _unit;
	private _card = ["N","NE","E","SE","S","SW","W","NW"] select (round (_dir / 45) mod 8);
	private _who = name _unit;
	if (group _unit != group player) then { _who = format ["%1 (%2)", _who, groupId group _unit]; };
	private _msg = format ["%1MEDIC NEEDED: %2 - %3 - %4m %5", ["", "STILL "] select _reminder, _who, _label, _dist, _card];
	if ((missionNamespace getVariable ["HUD_hasHelmet", false]) && {missionNamespace getVariable ["HUD_systemMessageAllowed", false]} && {missionNamespace getVariable ["SYSTEM_MESSAGES", true]}) then {
		[_msg, "bpdMedic_" + (netId _unit), 10] call HUD_fnc_addSystemMessage;
	} else {
		systemChat _msg;
	};
	playSound "glitch_short";
	if (!_reminder) then { playSound "threat_detector"; };
};

BPD_CloneHUD_medicPatients = createHashMap; // netId -> [unit, label, lastPingTime]

BPD_CloneHUD_fnc_medicPingTick = {
	if (!(missionNamespace getVariable ["BPD_CloneHUD_MEDIC_PING", true]) || {!(call BPD_CloneHUD_fnc_isMedic)} || {!alive player}
		|| {(missionNamespace getVariable ["BPD_CloneHUD_jamTier", 0]) >= 2}) exitWith { // datalink jammed

		BPD_CloneHUD_medicPatients = createHashMap;
	};
	private _threshold = missionNamespace getVariable ["BPD_CloneHUD_MEDIC_PING_THRESHOLD", 3];
	private _repeat = missionNamespace getVariable ["BPD_CloneHUD_MEDIC_PING_REPEAT", 60];
	private _now = diag_tickTime;
	private _seen = [];
	{
		private _status = [_x] call BPD_CloneHUD_fnc_medStatus;
		_status params ["_level", "_label"];
		if (_level >= _threshold) then {
			private _id = netId _x;
			_seen pushBack _id;
			private _entry = BPD_CloneHUD_medicPatients getOrDefault [_id, []];
			if (_entry isEqualTo []) then {
				[_x, _label, false] call BPD_CloneHUD_fnc_medicPingNotify;
				BPD_CloneHUD_medicPatients set [_id, [_x, _label, _now]];
			} else {
				_entry params ["", "", "_last"];
				if (_repeat > 0 && {_now - _last >= _repeat}) then {
					[_x, _label, true] call BPD_CloneHUD_fnc_medicPingNotify;
					_last = _now;
				};
				BPD_CloneHUD_medicPatients set [_id, [_x, _label, _last]];
			};
		};
	} forEach (call BPD_CloneHUD_fnc_medicPingCandidates);
	// anyone no longer at the threshold (treated, out of range, died) drops off
	{ if !(_x in _seen) then { BPD_CloneHUD_medicPatients deleteAt _x; }; } forEach (keys BPD_CloneHUD_medicPatients);
};

[] spawn {
	waitUntil { sleep 1; !isNull player };
	addMissionEventHandler ["Draw3D", {
		if (count BPD_CloneHUD_medicPatients == 0) exitWith {};
		if !(missionNamespace getVariable ["BPD_CloneHUD_MEDIC_PING_MARKER", true]) exitWith {};
		{
			_y params ["_unit", "_label"];
			if (!isNull _unit && {alive _unit}) then {
				private _pos = _unit modelToWorldVisual ((_unit selectionPosition "spine3") vectorAdd [0, 0, 0.6]);
				private _pulse = 0.6 + 0.4 * abs (sin (diag_tickTime * 240));
				[
					"\A3\ui_f\data\IGUI\Cfg\Actions\heal_ca.paa",
					[1, 0.23, 0.19, _pulse], _pos, 1, 1, 0,
					format ["%1 - %2 (%3m)", name _unit, _label, round (player distance _unit)],
					2, 0.035, "RobotoCondensedBold", "center", true
				] call BPD_CloneHUD_fnc_drawIcon;
			};
		} forEach BPD_CloneHUD_medicPatients;
	}];
	while {true} do {
		call BPD_CloneHUD_fnc_medicPingTick;
		sleep 1;
	};
};
