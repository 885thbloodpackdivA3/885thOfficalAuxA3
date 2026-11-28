/*
	885th Bloodpack Division - Clone HUD - Kill Counter
	---------------------------------------------------------------
	Counts the enemies YOU kill this mission, per enemy type, and shows
	the top 4 on the HUD when you press "Show / Hide Kill Counter":

	  > READING COMBAT LOG...
	  > CONFIRMED KILLS
	  B1 BATTLE DROID           12
	  B2 SUPER BATTLE DROID      4
	  ...

	It types in line by line in Orbitron (BPD_Orbitron, config.cpp), then
	fades after "Kill Counter Time" seconds (0 = stays until you press the
	key again). Pressing the key while it's up hides it.

	What counts: the EntityKilled event, when you are the instigator (so
	shots from a vehicle turret you crew count) and the victim's side was
	hostile to yours. Friendlies, civilians and your own death don't count.
	Totals live in missionNamespace, so they carry over respawns and reset
	with a new mission. Placed with "2. Layout - Kill Counter".

	Rejoin: the totals are also saved as a public mission variable named
	BPD_CloneHUD_kills_<player UID> (at most every 5 s, only after a new
	kill). Public variables are re-sent to players who join in progress,
	so leaving and rejoining the same mission picks the totals back up.
	No server script needed, and they still clear when the mission ends.
*/

BPD_CloneHUD_killCounts = createHashMap; // displayName -> count
BPD_CloneHUD_killInf = 0; // confirmed infantry (CAManBase) kills
BPD_CloneHUD_killVeh = 0; // confirmed vehicle kills (crew count as infantry)
BPD_CloneHUD_killShown = false;
BPD_CloneHUD_killUntil = -1;
BPD_CloneHUD_killTyper = scriptNull;

// Side the victim fought for: its group's side, or (no group) its config side.
BPD_CloneHUD_fnc_killSide = {
	params ["_unit"];
	private _s = side group _unit;
	if (_s in [west, east, resistance]) exitWith {_s};
	[east, west, resistance, civilian] param [getNumber (configOf _unit >> "side"), civilian]
};

BPD_CloneHUD_fnc_killAdd = {
	params ["_unit", "_killer", "_instigator"];
	if (!hasInterface || {isNull player}) exitWith {};
	private _who = [_instigator, _killer] select (isNull _instigator);
	if (_who != player || {_unit == player}) exitWith {};
	if !(_unit isKindOf "AllVehicles") exitWith {};
	private _side = [_unit] call BPD_CloneHUD_fnc_killSide;
	if (_side == civilian || {((side group player) getFriend _side) >= 0.6}) exitWith {};
	private _name = getText (configOf _unit >> "displayName");
	if (_name isEqualTo "") then { _name = typeOf _unit; };
	BPD_CloneHUD_killCounts set [_name, (BPD_CloneHUD_killCounts getOrDefault [_name, 0]) + 1];
	if (_unit isKindOf "CAManBase") then {
		BPD_CloneHUD_killInf = BPD_CloneHUD_killInf + 1;
	} else {
		BPD_CloneHUD_killVeh = BPD_CloneHUD_killVeh + 1;
	};
	BPD_CloneHUD_killDirty = true;
};

// ---- Rejoin save / restore ----
BPD_CloneHUD_killDirty = false;
BPD_CloneHUD_fnc_killSaveKey = {
	private _uid = getPlayerUID player;
	if (_uid isEqualTo "") then { _uid = "SP"; };
	"BPD_CloneHUD_kills_" + _uid
};

BPD_CloneHUD_fnc_killSave = {
	private _pairs = [];
	{ _pairs pushBack [_x, _y]; } forEach BPD_CloneHUD_killCounts;
	missionNamespace setVariable [call BPD_CloneHUD_fnc_killSaveKey, [BPD_CloneHUD_killInf, BPD_CloneHUD_killVeh, _pairs], isMultiplayer];
	BPD_CloneHUD_killDirty = false;
};

[] spawn {
	waitUntil { sleep 0.5; !isNull player && {!isMultiplayer || {getPlayerUID player != ""}} };
	// restore what this player had before leaving (only if nothing counted yet)
	private _saved = missionNamespace getVariable [call BPD_CloneHUD_fnc_killSaveKey, []];
	if (_saved isEqualType [] && {count _saved == 3} && {count BPD_CloneHUD_killCounts == 0}) then {
		_saved params [["_inf", 0, [0]], ["_veh", 0, [0]], ["_pairs", [], [[]]]];
		BPD_CloneHUD_killInf = _inf;
		BPD_CloneHUD_killVeh = _veh;
		{
			if (_x isEqualTypeArray ["", 0]) then { BPD_CloneHUD_killCounts set [_x select 0, _x select 1]; };
		} forEach _pairs;
		if (_inf + _veh > 0) then { diag_log format ["885th_CloneHUD: kill counter restored after rejoin - %1 infantry, %2 vehicles.", _inf, _veh]; };
	};
	// throttled save: at most every 5 s, only after a new kill
	while {true} do {
		sleep 5;
		if (BPD_CloneHUD_killDirty) then { call BPD_CloneHUD_fnc_killSave; };
	};
};

// ---- HUD panel (layout key KILLS) ----
BPD_CloneHUD_fnc_killCreate = {
	private _disp = uiNamespace getVariable ["BPD_CloneHUD_INDICATOR_BASE", displayNull];
	if (isNull _disp) exitWith {};
	private _old = uiNamespace getVariable ["BPD_CloneHUD_killCtrl", controlNull];
	if (!isNull _old) then { ctrlDelete _old; };
	private _c = _disp ctrlCreate ["RscStructuredText", 27720];
	_c ctrlSetBackgroundColor [0, 0, 0, 0];
	_c ctrlShow false;
	_c ctrlCommit 0;
	uiNamespace setVariable ["BPD_CloneHUD_killCtrl", _c];
	BPD_CloneHUD_killShown = false;
	call BPD_CloneHUD_fnc_killLayout;
};

BPD_CloneHUD_fnc_killLayout = {
	private _c = uiNamespace getVariable ["BPD_CloneHUD_killCtrl", controlNull];
	if (isNull _c) exitWith {};
	private _s = ["KILLS"] call BPD_CloneHUD_fnc_layoutScale;
	// 7 lines: 2 headings, infantry / vehicle totals, top 4 rows
	private _w = 0.15 * safezoneW * _s;
	private _h = 0.16 * safezoneH * _s;
	(["KILLS", _w, _h] call BPD_CloneHUD_fnc_layoutPos) params ["_px", "_py"];
	_c ctrlSetPosition [_px, _py, _w, _h];
	_c ctrlSetFontHeight (0.017 * safezoneH * _s);
	_c ctrlCommit 0;
};

// Top 4, highest first: [[name, count], ...]
BPD_CloneHUD_fnc_killTop = {
	private _rows = [];
	{ _rows pushBack [_y, _x]; } forEach BPD_CloneHUD_killCounts;
	_rows sort false;
	(_rows select [0, 4]) apply { [_x select 1, _x select 0] }
};

BPD_CloneHUD_fnc_killHide = {
	if (!isNull BPD_CloneHUD_killTyper) then { terminate BPD_CloneHUD_killTyper; };
	BPD_CloneHUD_killShown = false;
	BPD_CloneHUD_killUntil = -1;
	private _c = uiNamespace getVariable ["BPD_CloneHUD_killCtrl", controlNull];
	if (isNull _c) exitWith {};
	_c ctrlSetFade 1;
	_c ctrlCommit 0.3;
};

// Keybind: show (typing in), or hide if it's already up.
BPD_CloneHUD_fnc_killToggle = {
	if !(missionNamespace getVariable ["BPD_CloneHUD_KILLS_ENABLED", true]) exitWith {false};
	if (BPD_CloneHUD_killShown) exitWith { call BPD_CloneHUD_fnc_killHide; true };
	if !(call BPD_CloneHUD_fnc_hudUp) exitWith { systemChat "[Clone HUD] Kill Counter needs the HUD up."; true };
	private _c = uiNamespace getVariable ["BPD_CloneHUD_killCtrl", controlNull];
	if (isNull _c) then { call BPD_CloneHUD_fnc_killCreate; _c = uiNamespace getVariable ["BPD_CloneHUD_killCtrl", controlNull]; };
	if (isNull _c) exitWith {false};

	BPD_CloneHUD_killShown = true;
	private _t = missionNamespace getVariable ["BPD_CloneHUD_KILLS_TIME", 15];
	BPD_CloneHUD_killUntil = if (_t <= 0) then {1e9} else {-1}; // timer starts once typing ends
	if (!isNull BPD_CloneHUD_killTyper) then { terminate BPD_CloneHUD_killTyper; };
	BPD_CloneHUD_killTyper = [_c, _t] spawn {
		params ["_c", "_t"];
		private _f = "font='BPD_Orbitron'";
		private _head = "<t color='#7fb8e6' size='0.8' %1>%2</t>";
		private _row = "<t align='left' color='#e6f2ff' %1>%2</t><t align='right' color='#5fd0ff' %1>%3</t>";
		private _rows = call BPD_CloneHUD_fnc_killTop;
		private _lines = [];
		private _render = {
			params ["_extra"];
			_c ctrlSetStructuredText parseText ((_lines + [_extra]) joinString "<br/>");
		};
		_c ctrlSetStructuredText parseText "";
		_c ctrlSetFade 0;
		_c ctrlShow true;
		_c ctrlCommit 0;
		playSound "typing_1";

		// type a heading out character by character
		private _typeHead = {
			params ["_txt"];
			for "_i" from 1 to count _txt do {
				[format [_head, _f, _txt select [0, _i]]] call _render;
				sleep 0.025;
			};
			_lines pushBack format [_head, _f, _txt];
		};
		["> READING COMBAT LOG..."] call _typeHead;
		sleep 0.3;
		["> CONFIRMED KILLS"] call _typeHead;

		// Infantry / vehicle totals: labels type in, numbers land after
		sleep 0.15;
		playSound "typing_1";
		private _split = "<t align='left' color='#7fb8e6' size='0.85' %1>INFANTRY <t color='#5fd0ff'>%2</t></t><t align='right' color='#7fb8e6' size='0.85' %1>VEHICLES <t color='#5fd0ff'>%3</t></t>";
		for "_i" from 1 to 9 do {
			[format ["<t align='left' color='#7fb8e6' size='0.85' %1>%2</t>", _f, "INFANTRY " select [0, _i]]] call _render;
			sleep 0.02;
		};
		_lines pushBack format [_split, _f, BPD_CloneHUD_killInf, BPD_CloneHUD_killVeh];
		[""] call _render;

		if (count _rows == 0) then {
			sleep 0.15;
			_lines pushBack format ["<t color='#8aa0a8' %1>NO CONFIRMED KILLS</t>", _f];
			[""] call _render;
		} else {
			{
				_x params ["_name", "_n"];
				private _up = toUpper (([_name] call BPD_CloneHUD_fnc_intelEscape) select [0, 22]);
				sleep 0.15;
				playSound "typing_1";
				for "_i" from 1 to count _up step 2 do {
					[format [_row, _f, _up select [0, _i], ""]] call _render;
					sleep 0.02;
				};
				_lines pushBack format [_row, _f, _up, _n];
				[""] call _render;
			} forEach _rows;
		};
		_c ctrlSetStructuredText parseText (_lines joinString "<br/>");
		if (_t > 0) then { BPD_CloneHUD_killUntil = diag_tickTime + _t; };
	};
	true
};

// Fade after the timer, hide when the HUD goes down or the feature is off.
[] spawn {
	while {true} do {
		sleep 0.5;
		if (BPD_CloneHUD_killShown && {
			(BPD_CloneHUD_killUntil > 0 && {diag_tickTime > BPD_CloneHUD_killUntil})
			|| {!(call BPD_CloneHUD_fnc_hudUp)}
			|| {!(missionNamespace getVariable ["BPD_CloneHUD_KILLS_ENABLED", true])}
		}) then {
			BPD_CloneHUD_killShown = false;
			BPD_CloneHUD_killUntil = -1;
			private _c = uiNamespace getVariable ["BPD_CloneHUD_killCtrl", controlNull];
			if (!isNull _c) then { _c ctrlSetFade 1; _c ctrlCommit 1.2; };
		};
	};
};

if (hasInterface && {isNil "BPD_CloneHUD_killEH"}) then {
	BPD_CloneHUD_killEH = addMissionEventHandler ["EntityKilled", {
		params ["_unit", "_killer", "_instigator"];
		[_unit, _killer, _instigator] call BPD_CloneHUD_fnc_killAdd;
	}];
};
