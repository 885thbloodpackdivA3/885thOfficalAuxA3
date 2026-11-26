/*
	885th Bloodpack Division - Clone HUD - Intel (spotting pings + broadcasts)
	---------------------------------------------------------------
	SPOTTING PINGS (keybind "Spot / Ping Target", default Shift+T)
	  Aim at something and press the key. Whoever is in scope (own squad,
	  or friendlies in range - "8. Intel" settings) gets:
	    - a HUD line, e.g. "CONTACT  3x Infantry - 320m NE - Red Team 2"
	      (distance / bearing worked out from EACH receiver's position)
	    - a 3D marker where it was spotted, fading after a few seconds.
	  The marker stays where the target WAS - it doesn't follow it, so it
	  is a callout, not a wallhack. Aim at ground/structures for a plain
	  "MARK" ping. One active ping per sender; pinging again replaces it.
	  Sender needs a booted Clone HUD; receivers see pings on their HUD.

	INTEL BROADCASTS (ACE self-interaction "Clone HUD > Send Intel",
	  ZEN Zeus module "885th Clone HUD > Send HUD Intel")
	  A short typed message (INTEL / PRIORITY / OBJECTIVE) to your squad
	  or all friendlies - from Zeus: a side, everyone, or one unit's
	  squad - with an optional marker (your aim point, or where the Zeus
	  module was placed). Shown as a priority HUD line; players without a
	  booted HUD get it in chat + a hint instead. Who may send: squad
	  leaders + Zeus (or everyone - server setting).

	  "Clone HUD > Intel Log" lists the last 10 pings / intel received.

	Everything is sent with remoteExec to the clients in scope only and
	carries plain data (no code). Receivers filter by range themselves.
*/

BPD_CloneHUD_intelMarkers = createHashMap; // key -> [posASL, icon, rgba, label, expiry(diag_tickTime)]
BPD_CloneHUD_intelLog = [];
BPD_CloneHUD_pingNext = 0;

BPD_CloneHUD_intelTypes = [
	// label, color hex, rgba, icon, sound
	["INTEL",     "#6ec6ff", [0.43, 0.78, 1, 0.95],   "\A3\ui_f\data\map\markers\military\unknown_CA.paa",   "typing_1"],
	["PRIORITY",  "#ff8c1a", [1, 0.55, 0.1, 0.95],    "\A3\ui_f\data\map\markers\military\warning_CA.paa",   "threat_detector"],
	["OBJECTIVE", "#3cb371", [0.24, 0.7, 0.44, 0.95], "\A3\ui_f\data\map\markers\military\objective_CA.paa", "typing_1"]
];

BPD_CloneHUD_fnc_hudUp = {
	(missionNamespace getVariable ["HUD_hasHelmet", false])
	&& {player getVariable ["HUD_bootComplete", false]}
	&& {missionNamespace getVariable ["HUD_systemMessageAllowed", false]}
};

// Make user text safe for structured text.
BPD_CloneHUD_fnc_intelEscape = {
	params ["_t"];
	((((_t select [0, 160]) regexReplace ["&", "&amp;"]) regexReplace ["<", "&lt;"]) regexReplace [">", "&gt;"])
};

BPD_CloneHUD_fnc_bearingText = {
	params ["_posASL"];
	private _d = round ((getPosASL player) distance2D _posASL);
	private _card = ["N","NE","E","SE","S","SW","W","NW"] select (round ((player getDir (ASLToAGL _posASL)) / 45) mod 8);
	format ["%1m %2", _d, _card]
};

BPD_CloneHUD_fnc_intelLogAdd = {
	params ["_line"];
	BPD_CloneHUD_intelLog pushBack [daytime, _line];
	if (count BPD_CloneHUD_intelLog > 10) then { BPD_CloneHUD_intelLog deleteAt 0; };
	if (!isNil "BPD_CloneHUD_fnc_intelLogRender") then { call BPD_CloneHUD_fnc_intelLogRender; };
};

// ---- Intel Log panel (HUD element, layout key INTEL) ----
// Opened from the ACE menu or its keybind; stays up for "Intel Log Time"
// seconds (0 = until opened again), refreshes when new intel arrives.
BPD_CloneHUD_intelLogUntil = -1;

BPD_CloneHUD_fnc_intelLogCreate = {
	private _disp = uiNamespace getVariable ["BPD_CloneHUD_INDICATOR_BASE", displayNull];
	if (isNull _disp) exitWith {};
	private _c = _disp ctrlCreate ["RscStructuredText", 27710];
	_c ctrlSetBackgroundColor [0.02, 0.05, 0.07, 0.55];
	_c ctrlShow false;
	_c ctrlCommit 0;
	uiNamespace setVariable ["BPD_CloneHUD_intelLogCtrl", _c];
	call BPD_CloneHUD_fnc_intelLogLayout;
};

BPD_CloneHUD_fnc_intelLogLayout = {
	private _c = uiNamespace getVariable ["BPD_CloneHUD_intelLogCtrl", controlNull];
	if (isNull _c) exitWith {};
	private _s = ["INTEL"] call BPD_CloneHUD_fnc_layoutScale;
	private _w = 0.3 * safezoneW * _s;
	private _h = 0.26 * safezoneH * _s;
	(["INTEL", _w, _h] call BPD_CloneHUD_fnc_layoutPos) params ["_px", "_py"];
	_c ctrlSetPosition [_px, _py, _w, _h];
	_c ctrlSetFontHeight (0.022 * safezoneH * _s);
	_c ctrlCommit 0;
};

BPD_CloneHUD_fnc_intelLogRender = {
	private _c = uiNamespace getVariable ["BPD_CloneHUD_intelLogCtrl", controlNull];
	if (isNull _c) exitWith {};
	private _open = BPD_CloneHUD_intelLogUntil > diag_tickTime && {call BPD_CloneHUD_fnc_hudUp};
	if (!_open) exitWith { _c ctrlShow false; };
	private _lines = BPD_CloneHUD_intelLog apply {
		format ["<t color='#8aa0a8'>%1</t>  %2", [_x select 0, "HH:MM"] call BIS_fnc_timeToString, _x select 1]
	};
	reverse _lines;
	if (count _lines == 0) then { _lines = ["<t color='#8aa0a8'>No intel received yet.</t>"]; };
	_c ctrlSetStructuredText parseText format [
		"<t font='PuristaBold' color='#6ec6ff'>INTEL LOG</t><br/><t align='left' font='PuristaMedium'>%1</t>",
		_lines joinString "<br/>"
	];
	_c ctrlShow true;
};

// ACE "Intel Log" / keybind: open, or close if it's already open.
BPD_CloneHUD_fnc_intelShowLog = {
	if (BPD_CloneHUD_intelLogUntil > diag_tickTime) then {
		BPD_CloneHUD_intelLogUntil = -1;
	} else {
		private _t = missionNamespace getVariable ["BPD_CloneHUD_INTEL_LOG_TIME", 15];
		BPD_CloneHUD_intelLogUntil = diag_tickTime + ([_t, 1e9] select (_t <= 0));
		if !(call BPD_CloneHUD_fnc_hudUp) then { systemChat "[Clone HUD] Intel Log needs the HUD up."; };
	};
	call BPD_CloneHUD_fnc_intelLogRender;
	true
};

// Label the receiver uses for the sender: fireteam label for own squad
// ("Red Team 2"), otherwise "Name (Group)".
BPD_CloneHUD_fnc_senderLabel = {
	params ["_sender", "_name", "_groupId"];
	if (!isNull _sender && {group _sender == group player}) then {
		private _tl = _sender getVariable ["BPD_CloneHUD_teamLabel", []];
		if (count _tl == 2) exitWith { _tl select 0 };
		_name
	} else {
		format ["%1 (%2)", _name, _groupId]
	};
};

// ------------------------------------------------------------
//  Spotting pings
// ------------------------------------------------------------
BPD_CloneHUD_fnc_pingSend = {
	if !(missionNamespace getVariable ["BPD_CloneHUD_PING_ENABLED", true]) exitWith {false};
	if !(call BPD_CloneHUD_fnc_hudUp) exitWith {false};
	if (diag_tickTime < BPD_CloneHUD_pingNext) exitWith {true};
	if ((missionNamespace getVariable ["BPD_CloneHUD_jamTier", 0]) >= 2) exitWith {
		["<t color='#ff3b30'>DATALINK JAMMED</t> - ping not sent", "bpdPingFail", 3] call HUD_fnc_addSystemMessage;
		playSound "glitch_short";
		true
	};
	BPD_CloneHUD_pingNext = diag_tickTime + 1.5;

	private _start = AGLToASL (positionCameraToWorld [0, 0, 0]);
	private _end = AGLToASL (positionCameraToWorld [0, 0, 2000]);
	private _hits = lineIntersectsSurfaces [_start, _end, vehicle player, objNull, true, 1, "VIEW", "FIRE"];
	private _obj = objNull;
	private _pos = [];
	if (count _hits > 0) then {
		(_hits select 0) params ["_hPos", "", "_hObj", "_hParent"];
		_pos = _hPos;
		_obj = [_hObj, _hParent] select (!isNull _hParent);
	};
	// aiming close to a unit counts even if the ray slipped past it
	private _ct = cursorTarget;
	if (!isNull _ct && {alive _ct} && {_ct isKindOf "AllVehicles"} && {(isNull _obj) || {!(_obj isKindOf "AllVehicles")}} && {player distance _ct < 2000}) then {
		_obj = _ct;
		_pos = AGLToASL (_ct modelToWorld [0, 0, 1]);
	};
	if (_pos isEqualTo []) exitWith { ["Nothing to ping (out of range).", "bpdPingFail", 2] call HUD_fnc_addSystemMessage; true };

	private _kind = "MARK";
	private _desc = "Position";
	if (!isNull _obj && {alive _obj} && {_obj isKindOf "AllVehicles"}) then {
		_obj = vehicle _obj;
		private _sideObj = side group _obj;
		if (_obj isKindOf "CAManBase") then {
			private _n = { alive _x && {side group _x == _sideObj} } count (_obj nearEntities ["CAManBase", 20]);
			_desc = if (_n > 1) then { format ["%1x Infantry", _n] } else { "Infantry" };
		} else {
			_desc = getText (configOf _obj >> "displayName");
			if (count crew _obj == 0) then { _sideObj = civilian; _desc = _desc + " (empty)"; };
		};
		_kind = switch (true) do {
			case (_sideObj == civilian): { "CIVILIAN" };
			case ((side group player) getFriend _sideObj < 0.6): { "CONTACT" };
			default { "FRIENDLY" };
		};
		_pos = AGLToASL (_obj modelToWorld [0, 0, [1.2, 2] select !(_obj isKindOf "CAManBase")]);
	};

	private _scope = missionNamespace getVariable ["BPD_CloneHUD_PING_SCOPE", 0];
	private _target = [group player, side group player] select (_scope == 1);
	[[player, name player, groupId group player, _kind, _desc, _pos]] remoteExec ["BPD_CloneHUD_fnc_pingReceive", _target];
	true
};

BPD_CloneHUD_fnc_pingReceive = {
	params ["_data"];
	if (!hasInterface) exitWith {};
	_data params ["_sender", "_name", "_groupId", "_kind", "_desc", "_pos"];
	if !(call BPD_CloneHUD_fnc_hudUp) exitWith {};
	if ((missionNamespace getVariable ["BPD_CloneHUD_jamTier", 0]) >= 2) exitWith {}; // datalink jammed
	if ((missionNamespace getVariable ["BPD_CloneHUD_PING_SCOPE", 0]) == 1
		&& {_sender != player}
		&& {(getPosASL player) distance _pos > (missionNamespace getVariable ["BPD_CloneHUD_PING_RANGE", 800])}) exitWith {};

	private _style = switch (_kind) do {
		case "CONTACT":  { ["#ff5a4a", [1, 0.35, 0.29, 0.95], "\A3\ui_f\data\map\markers\military\destroy_CA.paa"] };
		case "FRIENDLY": { ["#6ec6ff", [0.43, 0.78, 1, 0.95],  "\A3\ui_f\data\map\markers\military\dot_CA.paa"] };
		case "CIVILIAN": { ["#ffd23f", [1, 0.82, 0.25, 0.95],  "\A3\ui_f\data\map\markers\military\dot_CA.paa"] };
		default          { ["#ebf0f2", [0.92, 0.94, 0.95, 0.95], "\A3\ui_f\data\map\markers\military\flag_CA.paa"] };
	};
	_style params ["_hex", "_rgba", "_icon"];
	private _who = [_sender, _name, _groupId] call BPD_CloneHUD_fnc_senderLabel;
	private _line = format ["<t color='%1'>%2</t>  %3 - %4 - %5", _hex, _kind, _desc, [_pos] call BPD_CloneHUD_fnc_bearingText, _who];
	[_line, "bpdPing_" + _name, 8] call HUD_fnc_addSystemMessage;
	[_line] call BPD_CloneHUD_fnc_intelLogAdd;
	playSound (["click", "threat_detector"] select (_kind == "CONTACT"));

	private _dur = missionNamespace getVariable ["BPD_CloneHUD_PING_DURATION", 20];
	BPD_CloneHUD_intelMarkers set ["ping_" + _name, [_pos, _icon, _rgba, format ["%1 %2", _kind, _desc], diag_tickTime + _dur]];
};

// ------------------------------------------------------------
//  Intel broadcasts
// ------------------------------------------------------------
BPD_CloneHUD_fnc_canSendIntel = {
	if ((missionNamespace getVariable ["BPD_CloneHUD_INTEL_SENDERS", 0]) == 1) exitWith {true};
	(leader group player == player) || {!isNull (getAssignedCuratorLogic player)}
};

BPD_CloneHUD_fnc_intelSend = {
	params ["_type", "_text", "_target", "_markPos", "_fromName", "_fromGroup"];
	if (_text isEqualTo "") exitWith { hint "Type a message first."; };
	private _id = format ["%1_%2", _fromName, round (diag_tickTime * 100)];
	[[_type, _text select [0, 160], _fromName, _fromGroup, _markPos, _id]] remoteExec ["BPD_CloneHUD_fnc_intelReceive", _target];
};

BPD_CloneHUD_fnc_intelReceive = {
	params ["_data"];
	if (!hasInterface) exitWith {};
	_data params ["_type", "_text", "_fromName", "_fromGroup", "_markPos", "_id"];
	// datalink jammed: the broadcast never arrives (a short note says so)
	if ((missionNamespace getVariable ["BPD_CloneHUD_jamTier", 0]) >= 2) exitWith {
		if (call BPD_CloneHUD_fnc_hudUp) then {
			["<t color='#ff3b30'>INCOMING INTEL LOST</t> - jamming", "bpdIntelLost", 5] call HUD_fnc_addSystemMessage;
		};
	};
	(BPD_CloneHUD_intelTypes param [_type, BPD_CloneHUD_intelTypes select 0]) params ["_label", "_hex", "_rgba", "_icon", "_sound"];
	private _safe = [_text] call BPD_CloneHUD_fnc_intelEscape;
	private _from = if (_fromGroup isEqualTo "") then {_fromName} else { format ["%1 (%2)", _fromName, _fromGroup] };
	private _where = if (_markPos isEqualTo []) then {""} else {
		format [" - grid %1, %2", mapGridPosition (ASLToAGL _markPos), [_markPos] call BPD_CloneHUD_fnc_bearingText]
	};
	private _line = format ["<t color='%1' font='PuristaBold'>%2</t>  %3<t color='#8aa0a8'>%4 - %5</t>", _hex, _label, _safe, _where, _from];
	[_line] call BPD_CloneHUD_fnc_intelLogAdd;
	playSound _sound;

	if (call BPD_CloneHUD_fnc_hudUp) then {
		[_line, "bpdIntel_" + _id, missionNamespace getVariable ["BPD_CloneHUD_INTEL_MSG_TIME", 20]] call HUD_fnc_addSystemMessage;
		if !(_markPos isEqualTo []) then {
			BPD_CloneHUD_intelMarkers set ["intel_" + _id, [_markPos, _icon, _rgba, _label, diag_tickTime + (missionNamespace getVariable ["BPD_CloneHUD_INTEL_MARKER_TIME", 120])]];
		};
	} else {
		// no visor HUD: still get the intel
		systemChat format ["[%1] %2%3 - %4", _label, _text, _where, _from];
		hint parseText _line;
	};
};

// Send-intel window. _markPos: ASL position for the optional marker
// (aim point for players, module position for Zeus). _zeusObj: the
// unit the Zeus module was placed on, if any.
BPD_CloneHUD_fnc_intelDialog = {
	params [["_markPos", []], ["_zeus", false], ["_zeusObj", objNull]];
	private _parent = findDisplay ([46, 312] select (!isNull findDisplay 312));
	private _d = _parent createDisplay "RscDisplayEmpty";
	if (isNull _d) exitWith {};

	private _mk = {
		params ["_cls", "_pos", ["_text", ""]];
		private _c = _d ctrlCreate [_cls, -1];
		_c ctrlSetPosition _pos;
		if (_text != "") then { _c ctrlSetText _text; };
		_c ctrlCommit 0;
		_c
	};
	private _x0 = 0.18; private _w = 0.64;
	private _bg = ["RscText", [_x0, 0.22, _w, 0.56]] call _mk;
	_bg ctrlSetBackgroundColor [0.04, 0.07, 0.09, 0.94];
	private _title = ["RscText", [_x0, 0.22, _w, 0.06], (["SEND INTEL", "SEND INTEL (ZEUS)"] select _zeus)] call _mk;
	_title ctrlSetBackgroundColor [0.1, 0.32, 0.4, 1];
	["RscText", [_x0 + 0.02, 0.3, 0.3, 0.04], "Message"] call _mk;
	private _edit = ["RscEdit", [_x0 + 0.02, 0.34, _w - 0.04, 0.05]] call _mk;
	["RscText", [_x0 + 0.02, 0.41, 0.3, 0.04], "Send to"] call _mk;
	private _toCombo = ["RscCombo", [_x0 + 0.02, 0.45, 0.29, 0.045]] call _mk;
	["RscText", [_x0 + 0.33, 0.41, 0.3, 0.04], "Type"] call _mk;
	private _typeCombo = ["RscCombo", [_x0 + 0.33, 0.45, 0.29, 0.045]] call _mk;
	private _cb = ["RscCheckBox", [_x0 + 0.02, 0.52, 0.04, 0.05]] call _mk;
	["RscText", [_x0 + 0.07, 0.52, 0.55, 0.05], (if (_markPos isEqualTo []) then {"No marker position available"} else {
		format ["Place a marker at %1 (grid %2)", ["my aim point", "the module position"] select _zeus, mapGridPosition (ASLToAGL _markPos)]
	})] call _mk;
	private _send = ["RscButton", [_x0 + _w - 0.32, 0.7, 0.14, 0.05], "SEND"] call _mk;
	private _cancel = ["RscButton", [_x0 + _w - 0.16, 0.7, 0.14, 0.05], "CANCEL"] call _mk;

	private _targets = [];
	if (_zeus) then {
		{ _x params ["_n", "_t"]; _toCombo lbAdd _n; _targets pushBack _t; } forEach [["BLUFOR", west], ["OPFOR", east], ["Independent", resistance], ["Everyone", 0]];
		if (!isNull _zeusObj && {_zeusObj isKindOf "CAManBase"}) then {
			_toCombo lbAdd format ["%1's squad (%2)", name _zeusObj, groupId group _zeusObj];
			_targets pushBack (group _zeusObj);
			_toCombo lbSetCurSel (count _targets - 1);
		} else {
			_toCombo lbSetCurSel 0;
		};
	} else {
		_toCombo lbAdd format ["My squad (%1)", groupId group player]; _targets pushBack (group player);
		_toCombo lbAdd "All friendlies"; _targets pushBack (side group player);
		_toCombo lbSetCurSel 0;
	};
	{ _typeCombo lbAdd (_x select 0); } forEach BPD_CloneHUD_intelTypes;
	_typeCombo lbSetCurSel 0;
	_cb cbSetChecked !(_markPos isEqualTo []);
	if (_markPos isEqualTo []) then { _cb ctrlEnable false; };

	_d setVariable ["bpd", [_edit, _toCombo, _typeCombo, _cb, _targets, _markPos, _zeus]];
	_send ctrlAddEventHandler ["ButtonClick", {
		params ["_btn"];
		private _d = ctrlParent _btn;
		(_d getVariable "bpd") params ["_edit", "_toCombo", "_typeCombo", "_cb", "_targets", "_markPos", "_zeus"];
		private _text = ctrlText _edit;
		if (_text isEqualTo "") exitWith { hint "Type a message first."; };
		private _from = if (_zeus) then {["COMMAND", ""]} else {[name player, groupId group player]};
		[
			0 max lbCurSel _typeCombo,
			_text,
			_targets select (0 max lbCurSel _toCombo),
			[[], _markPos] select (cbChecked _cb),
			_from select 0,
			_from select 1
		] call BPD_CloneHUD_fnc_intelSend;
		_d closeDisplay 1;
	}];
	_cancel ctrlAddEventHandler ["ButtonClick", { (ctrlParent (_this select 0)) closeDisplay 2; }];
	ctrlSetFocus _edit;
};

// Opened from the ACE menu: marker defaults to where you're aiming.
BPD_CloneHUD_fnc_intelDialogPlayer = {
	private _hits = lineIntersectsSurfaces [AGLToASL (positionCameraToWorld [0,0,0]), AGLToASL (positionCameraToWorld [0,0,3000]), vehicle player, objNull, true, 1, "VIEW", "FIRE"];
	private _pos = if (count _hits > 0) then { (_hits select 0) select 0 } else { [] };
	[_pos, false] call BPD_CloneHUD_fnc_intelDialog;
};

// ------------------------------------------------------------
//  3D markers (pings + intel), drawn for anyone with a booted HUD
// ------------------------------------------------------------
// Intel Log panel timeout / HUD-down hide
[] spawn {
	while {true} do {
		sleep 0.5;
		private _c = uiNamespace getVariable ["BPD_CloneHUD_intelLogCtrl", controlNull];
		if (!isNull _c && {ctrlShown _c} && {BPD_CloneHUD_intelLogUntil <= diag_tickTime || {!(call BPD_CloneHUD_fnc_hudUp)}}) then {
			_c ctrlShow false;
		};
	};
};

[] spawn {
	waitUntil { sleep 1; !isNull player };
	addMissionEventHandler ["Draw3D", {
		if (count BPD_CloneHUD_intelMarkers == 0) exitWith {};
		if !(call BPD_CloneHUD_fnc_hudUp) exitWith {};
		private _now = diag_tickTime;
		private _dead = [];
		{
			_y params ["_pos", "_icon", "_rgba", "_label", "_expiry"];
			if (_now > _expiry) then { _dead pushBack _x; } else {
				private _left = _expiry - _now;
				private _col = +_rgba;
				if (_left < 3) then { _col set [3, (_col select 3) * (_left / 3)]; }; // fade out
				drawIcon3D [_icon, _col, ASLToAGL _pos, 0.9, 0.9, 0,
					format ["%1  %2m", _label, round ((getPosASL player) distance _pos)],
					2, 0.032, "RobotoCondensedBold", "center", true];
			};
		} forEach BPD_CloneHUD_intelMarkers;
		{ BPD_CloneHUD_intelMarkers deleteAt _x; } forEach _dead;
	}];
};

// ZEN (Zeus Enhanced) module, when ZEN is loaded.
if (hasInterface && {!isNil "zen_custom_modules_fnc_register"} && {isNil "BPD_CloneHUD_zenIntelAdded"}) then {
	BPD_CloneHUD_zenIntelAdded = true;
	["885th Clone HUD", "Send HUD Intel", {
		params ["_posASL", "_obj"]; // ZEN passes the module position as ASL
		[_posASL, true, _obj] call BPD_CloneHUD_fnc_intelDialog;
	}] call zen_custom_modules_fnc_register;
};
