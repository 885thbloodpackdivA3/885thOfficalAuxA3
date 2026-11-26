/*
	885th Bloodpack Division - Clone HUD - Radio comms strip (TFAR)
	---------------------------------------------------------------
	Shows who is transmitting and on which channel, but only to people
	who would actually hear it - i.e. who carry a radio set to that
	frequency (any SR radio's active or additional channel, any LR
	radio), with the same encryption code, and within the sending
	radio's range. Example rows:

	  Receiving... AN/PRC-152   Red Team 2         SR CH2 Squad (152.4)
	  Receiving... RT-1523G     Lt. Kix (Hawk 1)   LR CH1 Platoon (31)
	  Sending...   AN/PRC-152                      SR CH2 ALT (152.4)
	(radio = YOUR radio: the one you send on / the one it came in on;
	 "Sent" / "Received", dimmed, for a few seconds after release)

	The channel number is YOUR channel that frequency sits on, so you
	know which of your radios / channels it came in on. Names come from
	the "Frequency Names" server setting (e.g. "31=Platoon, 40=Air").
	Rows stay while the transmitter holds the key, then dim for a few
	seconds.

	Each trooper picks their own displays (9. Radio Comms, per player):
	  Comms List        - the rows above (2. Layout - Radio Comms), or the
	                      Grouped style: "Sending" / "Receiving" headings
	                      with the rows under them and jamming on the headings
	  One-Line Ticker   - latest transmission only (2. Layout - Radio Ticker)
	  Speaker Tag       - radio tag + channel over the transmitter's head
	  Squad List Icon   - radio icon + channel next to the name
	plus the Channel Label format and whether to show your own TX.

	How: TFAR fires its "OnTangent" event on the SENDER's machine (taken
	from TFAR's own TFAR_fnc_doSRTransmit / doLRTransmit). The sender
	works out frequency, code and range with TFAR's public getters and
	remoteExecs that small packet to friendly players; each receiver
	compares it with its own radios. Range is straight-line distance
	against the radio's tf_range - terrain isn't modeled, so a row can
	occasionally show for a transmission TFAR itself cut off.
	Without TFAR this file does nothing.
*/

BPD_CloneHUD_commsActive = createHashMap; // key -> [label, lr, myCh, myAdditional, freq, self, startTick, endTick, senderObj]
BPD_CloneHUD_commsIcon = ["", "\A3\ui_f\data\igui\cfg\simpleTasks\types\radio_ca.paa"] select (fileExists "\A3\ui_f\data\igui\cfg\simpleTasks\types\radio_ca.paa");
BPD_CloneHUD_fnc_commsOpt = { params ["_n", "_d"]; missionNamespace getVariable [format ["BPD_CloneHUD_COMMS_%1", _n], _d] };
BPD_CloneHUD_commsMyCache = [-1, []];
BPD_CloneHUD_commsNamesCache = ["", createHashMap];

BPD_CloneHUD_fnc_commsFreqNames = {
	private _raw = missionNamespace getVariable ["BPD_CloneHUD_COMMS_FREQNAMES", ""];
	if (_raw isEqualTo (BPD_CloneHUD_commsNamesCache select 0)) exitWith { BPD_CloneHUD_commsNamesCache select 1 };
	private _map = createHashMap;
	{
		private _pair = _x splitString "=";
		if (count _pair == 2) then {
			private _f = parseNumber (_pair select 0);
			private _n = ((_pair select 1) splitString " ") joinString " "; // trims + collapses spaces
			if (_f > 0 && {_n != ""}) then { _map set [str (round (_f * 1000)), _n]; };
		};
	} forEach (_raw splitString ",;");
	BPD_CloneHUD_commsNamesCache = [_raw, _map];
	_map
};

BPD_CloneHUD_fnc_commsFreqKey = { str (round ((parseNumber _this) * 1000)) };

// Every channel this player can hear on: [lr, freqKey, code, ch, additional, freq]
BPD_CloneHUD_fnc_commsMyChannels = {
	if (diag_tickTime - (BPD_CloneHUD_commsMyCache select 0) < 1) exitWith { BPD_CloneHUD_commsMyCache select 1 };
	private _out = [];
	{
		private _r = _x;
		private _code = _r call TFAR_fnc_getSwRadioCode;
		private _ch = _r call TFAR_fnc_getSwChannel;
		private _f = [_r, _ch + 1] call TFAR_fnc_getChannelFrequency;
		private _rName = getText (configFile >> "CfgWeapons" >> _r >> "displayName");
		_out pushBack [false, _f call BPD_CloneHUD_fnc_commsFreqKey, _code, _ch, false, _f, _rName];
		private _a = _r call TFAR_fnc_getAdditionalSwChannel;
		if (_a >= 0) then {
			private _fa = [_r, _a + 1] call TFAR_fnc_getChannelFrequency;
			_out pushBack [false, _fa call BPD_CloneHUD_fnc_commsFreqKey, _code, _a, true, _fa, _rName];
		};
	} forEach (player call TFAR_fnc_radiosList);
	{
		if (_x isEqualType [] && {count _x == 2} && {!isNull (_x select 0)}) then {
			private _r = _x;
			private _code = _r call TFAR_fnc_getLrRadioCode;
			private _ch = _r call TFAR_fnc_getLrChannel;
			private _f = [_r, _ch + 1] call TFAR_fnc_getChannelFrequency;
			private _rName = [_r select 0, "displayName"] call TFAR_fnc_getLrRadioProperty;
			_out pushBack [true, _f call BPD_CloneHUD_fnc_commsFreqKey, _code, _ch, false, _f, _rName];
			private _a = _r call TFAR_fnc_getAdditionalLrChannel;
			if (_a >= 0) then {
				private _fa = [_r, _a + 1] call TFAR_fnc_getChannelFrequency;
				_out pushBack [true, _fa call BPD_CloneHUD_fnc_commsFreqKey, _code, _a, true, _fa, _rName];
			};
		};
	} forEach (player call TFAR_fnc_lrRadiosList);
	BPD_CloneHUD_commsMyCache = [diag_tickTime, _out];
	_out
};

// Sender side - TFAR "OnTangent" (local to the transmitting player).
BPD_CloneHUD_fnc_commsTangent = {
	params ["_unit", "_radio", "_radioType", "_additional", "_down"];
	if (_unit != player) exitWith {};
	// Always announce, even if this trooper hides comms on their own HUD -
	// that's a display preference and must not hide them from others.
	if (_radioType > 1) exitWith {}; // underwater / other
	private _lr = _radioType == 1;
	private _ch = if (_additional) then {
		_radio call ([TFAR_fnc_getAdditionalSwChannel, TFAR_fnc_getAdditionalLrChannel] select _lr)
	} else {
		_radio call ([TFAR_fnc_getSwChannel, TFAR_fnc_getLrChannel] select _lr)
	};
	private _freq = [_radio, _ch + 1] call TFAR_fnc_getChannelFrequency;
	private _code = _radio call ([TFAR_fnc_getSwRadioCode, TFAR_fnc_getLrRadioCode] select _lr);
	private _range = if (_lr) then {
		[_radio select 0, "tf_range", 0] call TFAR_fnc_getLrRadioProperty
	} else {
		getNumber (configFile >> "CfgWeapons" >> _radio >> "tf_range")
	};
	if (!isNil "TFAR_fnc_getTransmittingDistanceMultiplicator") then { _range = _range * (call TFAR_fnc_getTransmittingDistanceMultiplicator); };
	private _rName = if (_lr) then { [_radio select 0, "displayName"] call TFAR_fnc_getLrRadioProperty } else { getText (configFile >> "CfgWeapons" >> _radio >> "displayName") };
	[[player, name player, groupId group player, _lr, _freq, _code, _range, _down, _ch, _additional, _rName]] remoteExec ["BPD_CloneHUD_fnc_commsReceive", side group player];
};

// Receiver side.
BPD_CloneHUD_fnc_commsReceive = {
	params ["_d"];
	if (!hasInterface || {isNil "TFAR_fnc_radiosList"}) exitWith {};
	_d params ["_sender", "_name", "_groupId", "_lr", "_freq", "_code", "_range", "_down", "_txCh", "_txAdd", ["_txRadio", ""]];
	private _self = _sender == player;
	// COMMS LOST (jamming.sqf tier 2+): nothing comes in
	if (!_self && {(missionNamespace getVariable ["BPD_CloneHUD_jamTier", 0]) >= 2}) exitWith {};
	private _myCh = _txCh;
	private _myAdd = _txAdd;
	private _myRadio = _txRadio; // own TX: the radio you're sending on
	if (!_self) then {
		private _key = _freq call BPD_CloneHUD_fnc_commsFreqKey;
		private _i = (call BPD_CloneHUD_fnc_commsMyChannels) findIf { (_x select 0) == _lr && {(_x select 1) == _key} && {(_x select 2) == _code} };
		if (_i < 0) then { _myCh = -1; } else {
			private _m = (call BPD_CloneHUD_fnc_commsMyChannels) select _i;
			_myCh = _m select 3; _myAdd = _m select 4;
			_myRadio = _m param [6, ""]; // RX: YOUR radio it came in on
		};
		if (_range > 0 && {!isNull _sender} && {_sender distance player > _range}) then { _myCh = -1; };
	};
	if (_myCh < 0) exitWith {};
	private _key = _name + (["SR", "LR"] select _lr);
	if (_down) then {
		private _label = if (_self) then {"You"} else { [_sender, _name, _groupId] call BPD_CloneHUD_fnc_senderLabel };
		BPD_CloneHUD_commsActive set [_key, [_label, _lr, _myCh, _myAdd, _freq, _self, diag_tickTime, -1, _sender, _myRadio]];
	} else {
		private _e = BPD_CloneHUD_commsActive getOrDefault [_key, []];
		if (count _e > 0) then { _e set [7, diag_tickTime]; };
	};
	// squad list icon: refresh now instead of waiting for its 1 s tick
	if (["SHOW_SQUAD", false] call BPD_CloneHUD_fnc_commsOpt
		&& {!_self} && {group _sender == group player}
		&& {!isNil "HUD_fnc_updateTeamList"} && {player getVariable ["HUD_bootComplete", false]}) then {
		call HUD_fnc_updateTeamList;
	};
};

// Channel text per the trooper's Channel Label choice.
BPD_CloneHUD_fnc_commsChanText = {
	params ["_lr", "_ch", "_add", "_freq", ["_html", true]];
	private _base = format ["%1 CH%2%3", ["SR", "LR"] select _lr, _ch + 1, ["", " ALT"] select _add];
	private _name = (call BPD_CloneHUD_fnc_commsFreqNames) getOrDefault [_freq call BPD_CloneHUD_fnc_commsFreqKey, ""];
	private _nameTxt = if (_name == "") then {""} else { [_name, format ["<t color='#b4dcff'>%1</t>", _name]] select _html };
	switch (["LABEL", 0] call BPD_CloneHUD_fnc_commsOpt) do {
		case 1: { [_nameTxt, _base] select (_name == "") };
		case 2: { format ["%1 (%2)", _base, _freq] };
		default { format ["%1 %2(%3)", _base, [_nameTxt + " ", ""] select (_name == ""), _freq] };
	};
};

// Live / lingering entries, newest first: [[start, entry], ...]
BPD_CloneHUD_fnc_commsEntries = {
	private _now = diag_tickTime;
	private _linger = ["LINGER", 4] call BPD_CloneHUD_fnc_commsOpt;
	private _dead = [];
	private _rows = [];
	{
		private _end = _y select 7;
		if ((_end > 0 && {_now - _end > _linger}) || {_now - (_y select 6) > 120}) then { _dead pushBack _x; } else {
			_rows pushBack [_y select 6, _y];
		};
	} forEach BPD_CloneHUD_commsActive;
	{ BPD_CloneHUD_commsActive deleteAt _x; } forEach _dead;
	[_rows, [], { _x select 0 }, "DESCEND"] call BIS_fnc_sortBy
};

// Squad list tag for a unit currently transmitting ("" if not).
BPD_CloneHUD_fnc_commsUnitTag = {
	params ["_unit"];
	if !(["ENABLED", true] call BPD_CloneHUD_fnc_commsOpt && {["SHOW_SQUAD", false] call BPD_CloneHUD_fnc_commsOpt}) exitWith {""};
	private _hit = [];
	{ if ((_y select 8) isEqualTo _unit && {(_y select 7) < 0}) exitWith { _hit = _y; }; } forEach BPD_CloneHUD_commsActive;
	if (_hit isEqualTo []) exitWith {""};
	_hit params ["", "_lr", "_ch", "_add", "_freq"];
	private _ico = if (BPD_CloneHUD_commsIcon == "") then {"((o))"} else { format ["<img image='%1'/>", BPD_CloneHUD_commsIcon] };
	format [" <t color='#3cb371'>%1 %2</t>", _ico, [_lr, _ch, _add, _freq] call BPD_CloneHUD_fnc_commsChanText]
};

// ---- HUD strip ----
BPD_CloneHUD_fnc_commsCreate = {
	private _disp = uiNamespace getVariable ["BPD_CloneHUD_INDICATOR_BASE", displayNull];
	if (isNull _disp) exitWith {};
	private _ctrls = [];
	{
		private _c = _disp ctrlCreate ["RscStructuredText", 27700 + _forEachIndex];
		_c ctrlSetBackgroundColor [0, 0, 0, 0];
		_c ctrlShow false;
		_c ctrlCommit 0;
		_ctrls pushBack _c;
	} forEach ["list", "ticker"];
	uiNamespace setVariable ["BPD_CloneHUD_commsCtrl", _ctrls select 0];
	uiNamespace setVariable ["BPD_CloneHUD_commsTicker", _ctrls select 1];
	call BPD_CloneHUD_fnc_commsLayout;
};

BPD_CloneHUD_fnc_commsLayout = {
	{
		_x params ["_var", "_key", "_wf", "_hf"];
		private _c = uiNamespace getVariable [_var, controlNull];
		if (!isNull _c) then {
			private _s = [_key] call BPD_CloneHUD_fnc_layoutScale;
			private _w = _wf * safezoneW * _s;
			private _h = _hf * safezoneH * _s;
			([_key, _w, _h] call BPD_CloneHUD_fnc_layoutPos) params ["_px", "_py"];
			_c ctrlSetPosition [_px, _py, _w, _h];
			_c ctrlSetFontHeight (0.024 * safezoneH * _s);
			_c ctrlCommit 0;
		};
	} forEach [
		// Grouped style needs room for the two headings
		["BPD_CloneHUD_commsCtrl", "COMMS", 0.24, [0.15, 0.22] select ((["LIST_STYLE", 0] call BPD_CloneHUD_fnc_commsOpt) == 1)],
		["BPD_CloneHUD_commsTicker", "TICKER", 0.34, 0.035]
	];
};

// Grouped list style - one block, vertical:
//   Sending   [jam tag]
//     AN/PRC-152   SR CH2 ALT (152.4)
//   Receiving [jam tag]
//     AN/PRC-152   Red Team 2   SR CH2 Squad (152.4)
// Jamming rides on the headings: tier 1 = RANGE REDUCED / DEGRADED,
// tier 2+ = JAMMED / COMMS LOST (nothing is received, so the Receiving
// block shows "No signal"). While jammed both headings stay up even with
// nothing on the air, so the trooper always sees the state.
BPD_CloneHUD_fnc_commsGroupedLines = {
	params ["_rows", "_n", "_showRows"];
	private _tier = missionNamespace getVariable ["BPD_CloneHUD_jamTier", 0];
	private _pct = round ((missionNamespace getVariable ["BPD_CloneHUD_jamLevel", 0]) * 100);
	private _red = ["#ff3b30", "#7a1d18"] select ((floor (diag_tickTime * 2)) mod 2 == 1);
	private _tx = [];
	private _rx = [];
	if (_showRows) then {
		{ if ((_x select 1) select 5) then { _tx pushBack (_x select 1); } else { _rx pushBack (_x select 1); }; } forEach _rows;
	};
	if (_tier >= 2) then { _rx = []; }; // COMMS LOST: nothing comes in
	_tx = _tx select [0, _n];
	_rx = _rx select [0, _n];

	private _row = {
		params ["_e"];
		_e params ["_label", "_lr", "_ch", "_add", "_freq", "_self", "_start", "_end", "", ["_radio", ""]];
		private _txt = ["#ebf0f2", "#7d8b90"] select (_end >= 0); // dim once released
		if (_radio == "") then { _radio = ["SR radio", "LR radio"] select _lr; };
		private _who = if (_self) then {""} else { format ["   <t color='%1'>%2</t>", _txt, _label] };
		format ["<t color='%1'>%2</t>%3   <t color='#8aa0a8'>%4</t>", _txt, _radio, _who,
			[_lr, _ch, _add, _freq] call BPD_CloneHUD_fnc_commsChanText]
	};

	private _lines = [];
	if (count _tx > 0 || {_tier > 0}) then {
		private _tag = switch (true) do {
			case (_tier >= 2): { format ["  <t color='%1' font='PuristaBold'>JAMMED</t>", _red] };
			case (_tier == 1): { "  <t color='#ffd23f' font='PuristaBold'>RANGE REDUCED</t>" };
			default { "" };
		};
		_lines pushBack format ["<t color='#ff8c1a' font='PuristaBold'>Sending</t>%1", _tag];
		{ _lines pushBack ([_x] call _row); } forEach _tx;
	};
	if (count _rx > 0 || {_tier > 0}) then {
		private _tag = switch (true) do {
			case (_tier >= 2): { format ["  <t color='%1' font='PuristaBold'>COMMS LOST</t> <t color='#8aa0a8'>(%2%% jamming)</t>", _red, _pct] };
			case (_tier == 1): { format ["  <t color='#ffd23f' font='PuristaBold'>DEGRADED</t> <t color='#8aa0a8'>(%1%% jamming)</t>", _pct] };
			default { "" };
		};
		_lines pushBack format ["<t color='#3cb371' font='PuristaBold'>Receiving</t>%1", _tag];
		if (_tier >= 2) then { _lines pushBack "<t color='#7d8b90'>No signal</t>"; };
		{ _lines pushBack ([_x] call _row); } forEach _rx;
	};
	_lines
};

BPD_CloneHUD_fnc_commsRowText = {
	params ["_e", "_withTag"];
	_e params ["_label", "_lr", "_ch", "_add", "_freq", "_self", "_start", "_end", "", ["_radio", ""]];
	private _live = _end < 0;
	// "Sending... <your radio>" / "Receiving... <the radio it came in on>",
	// "Sent" / "Received" once the key is released (dimmed)
	private _verb = if (_self) then {
		["<t color='#ff8c1a'>Sending...</t>", "<t color='#8a6a4a'>Sent</t>"] select !_live
	} else {
		["<t color='#3cb371'>Receiving...</t>", "<t color='#4a6a58'>Received</t>"] select !_live
	};
	if (_radio == "") then { _radio = ["SR radio", "LR radio"] select _lr; };
	private _txt = ["#ebf0f2", "#7d8b90"] select !_live;
	private _who = if (_self) then {""} else { format ["   <t color='%1'>%2</t>", _txt, _label] };
	format ["%1 <t color='%2'>%3</t>%4   <t color='#8aa0a8'>%5</t>",
		_verb, _txt, _radio, _who,
		[_lr, _ch, _add, _freq] call BPD_CloneHUD_fnc_commsChanText]
};

BPD_CloneHUD_fnc_commsRender = {
	private _list = uiNamespace getVariable ["BPD_CloneHUD_commsCtrl", controlNull];
	private _tick = uiNamespace getVariable ["BPD_CloneHUD_commsTicker", controlNull];
	if (isNull _list) exitWith {};
	if !(call BPD_CloneHUD_fnc_hudUp) exitWith { _list ctrlShow false; _tick ctrlShow false; };
	private _rows = call BPD_CloneHUD_fnc_commsEntries;
	// comms display off: no rows, but the jamming warning still shows
	if !(["ENABLED", true] call BPD_CloneHUD_fnc_commsOpt) then { _rows = []; };
	if !(["SHOW_OWN", true] call BPD_CloneHUD_fnc_commsOpt) then { _rows = _rows select { !((_x select 1) select 5) }; };
	// jamming banner (COMMS DEGRADED / COMMS LOST) - always shown in the
	// list area while jammed, even if the list itself is turned off
	private _banner = if (isNil "BPD_CloneHUD_fnc_jamBanner") then {""} else {call BPD_CloneHUD_fnc_jamBanner};

	// list
	private _showList = ["SHOW_LIST", true] call BPD_CloneHUD_fnc_commsOpt;
	private _grouped = (["LIST_STYLE", 0] call BPD_CloneHUD_fnc_commsOpt) == 1;
	if ((count _rows > 0 && {_showList}) || {_banner != ""}) then {
		private _n = round (["LIST_ROWS", 4] call BPD_CloneHUD_fnc_commsOpt);
		private _lines = if (_grouped) then {
			// jam state is carried by the Sending / Receiving headings
			[_rows, _n, _showList] call BPD_CloneHUD_fnc_commsGroupedLines
		} else {
			private _l = if (_showList) then { (_rows select [0, _n]) apply { [_x select 1, true] call BPD_CloneHUD_fnc_commsRowText } } else { [] };
			if (_banner != "") then { _l = [_banner] + _l; };
			_l
		};
		_list ctrlSetStructuredText parseText format ["<t align='right' font='PuristaMedium' shadow='2'>%1</t>", _lines joinString "<br/>"];
		_list ctrlShow true;
	} else { _list ctrlShow false; };

	// ticker
	if ((count _rows > 0 || {_banner != ""}) && {["SHOW_TICKER", false] call BPD_CloneHUD_fnc_commsOpt}) then {
		private _ico = if (BPD_CloneHUD_commsIcon == "") then {""} else { format ["<img image='%1'/> ", BPD_CloneHUD_commsIcon] };
		private _txt = if (_banner != "" && {(missionNamespace getVariable ["BPD_CloneHUD_jamTier", 0]) >= 2 || {count _rows == 0}}) then { _banner } else { [(_rows select 0) select 1, true] call BPD_CloneHUD_fnc_commsRowText };
		_tick ctrlSetStructuredText parseText format ["<t align='center' font='PuristaMedium' shadow='2'>%1%2</t>", _ico, _txt];
		_tick ctrlShow true;
	} else { _tick ctrlShow false; };
};

// Speaker tags over transmitters' heads.
BPD_CloneHUD_fnc_commsDraw3D = {
	if (count BPD_CloneHUD_commsActive == 0) exitWith {};
	if !(["ENABLED", true] call BPD_CloneHUD_fnc_commsOpt && {["SHOW_3D", false] call BPD_CloneHUD_fnc_commsOpt}) exitWith {};
	if !(call BPD_CloneHUD_fnc_hudUp) exitWith {};
	private _range = ["3D_RANGE", 300] call BPD_CloneHUD_fnc_commsOpt;
	{
		_y params ["_label", "_lr", "_ch", "_add", "_freq", "_self", "_start", "_end", "_unit"];
		if (!_self && {_end < 0} && {!isNull _unit} && {alive _unit} && {_unit distance player < _range}) then {
			private _pos = _unit modelToWorldVisual ((_unit selectionPosition "head") vectorAdd [0, 0, 0.8]);
			drawIcon3D [BPD_CloneHUD_commsIcon, [0.24, 0.8, 0.45, 0.95], _pos, 0.7, 0.7, 0,
				format ["%1  %2", _label, [_lr, _ch, _add, _freq, false] call BPD_CloneHUD_fnc_commsChanText],
				2, 0.03, "RobotoCondensedBold", "center", false];
		};
	} forEach BPD_CloneHUD_commsActive;
};

// ---- hook up (TFAR loads its functions at preInit) ----
if (hasInterface) then {
	[] spawn {
		waitUntil { sleep 1; !isNull player };
		if (isNil "TFAR_fnc_addEventHandler") exitWith { diag_log "885th_CloneHUD: TFAR not loaded - radio comms strip disabled."; };
		["BPD_CloneHUD_comms", "OnTangent", { _this call BPD_CloneHUD_fnc_commsTangent; }, objNull] call TFAR_fnc_addEventHandler;
		addMissionEventHandler ["Draw3D", { call BPD_CloneHUD_fnc_commsDraw3D; }];
		diag_log "885th_CloneHUD: radio comms hooked to TFAR OnTangent.";
		while {true} do {
			call BPD_CloneHUD_fnc_commsRender;
			sleep 0.2;
		};
	};
};
