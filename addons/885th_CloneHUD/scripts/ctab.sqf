/*
	885th Bloodpack Division - Clone HUD - cTab Link
	---------------------------------------------------------------
	Ties the Clone HUD to the 885th cTab (885_SW_cTab, CfgPatches "cTab").
	Soft dependency - everything here checks for cTab first and quietly
	falls back when it isn't loaded.

	1. Clone helmets ARE helmet cams. Every helmet in the three Clone HUD
	   helmet lists is added to cTab_helmetClass_has_HCam on every client
	   (BPD_CloneHUD_CTAB_HELMETCAMS, forced/global so everyone agrees),
	   so clones show up in the cTab Tablet's HCAM list without needing
	   an ItemcTabHCam in their pack.

	2. Tactical link panel (layout key FEED). Header line shows which
	   cTab devices you're carrying (TAB / ANDR / DAGR / HCAM) and which
	   link mode is active. In HELM CAM mode the panel body shows a live
	   picture-in-picture feed from a squadmate's helmet.

	3. Link cycling (CBA keybinds, rebindable):
	     Shift+H  Cycle Tactical Link:  cTab -> DAGR -> Helm Cam -> off
	              (skips anything you don't carry)
	     Shift+J  Next Helm Cam feed (starts Helm Cam mode if it's off)
	   cTab and DAGR open the real 885th cTab interfaces (Tablet dialog
	   or Android, MicroDAGR overlay) through cTab's own cTab_fnc_open,
	   so they behave exactly like opening them with H / Ctrl+H.

	Link mode is read back from what's actually open (cTabIfOpen / our
	camera), so closing the tablet with Esc or cTab's own keys never
	leaves the HUD out of sync.
*/

BPD_CloneHUD_ctabLoaded = isClass (configFile >> "CfgPatches" >> "cTab");
BPD_CloneHUD_hcamTarget = objNull;
BPD_CloneHUD_hcam = [];          // [camera, aim helper, host] while a feed is live
BPD_CloneHUD_hcamActive = false;  // HELM CAM link mode on
BPD_CloneHUD_hcamRT = "bpd_clonehud_rt";

// ------------------------------------------------------------
//  Gear checks
// ------------------------------------------------------------
BPD_CloneHUD_fnc_hasItem = {
	params ["_items"];
	if (!isNil "cTab_fnc_checkGear") exitWith { [player, _items] call cTab_fnc_checkGear };
	private _all = (items player) + (assignedItems player) + [goggles player];
	({_x in _all} count _items) > 0
};

BPD_CloneHUD_fnc_deviceState = {
	[
		["TAB",  [["ItemcTab"]] call BPD_CloneHUD_fnc_hasItem],
		["ANDR", [["ItemAndroid"]] call BPD_CloneHUD_fnc_hasItem],
		["DAGR", [["ItemMicroDAGR"]] call BPD_CloneHUD_fnc_hasItem],
		["HCAM", (headgear player in (missionNamespace getVariable ["HUD_helmets", []])) || {[["ItemcTabHCam"]] call BPD_CloneHUD_fnc_hasItem}]
	]
};

// ------------------------------------------------------------
//  1. Register clone helmets as cTab helmet cams
// ------------------------------------------------------------
BPD_CloneHUD_fnc_registerHelmetCams = {
	if (!BPD_CloneHUD_ctabLoaded) exitWith {};
	if (!(missionNamespace getVariable ["BPD_CloneHUD_CTAB_HELMETCAMS", true])) exitWith {};
	[] spawn {
		// cTab's player_init builds and de-duplicates its list during
		// postInit; wait for that so ours isn't overwritten.
		private _timeout = diag_tickTime + 60;
		waitUntil { sleep 0.5; (!isNil "cTab_helmetClass_has_HCam" && {!isNil "cTab_fnc_updateLists"}) || {diag_tickTime > _timeout} };
		if (isNil "cTab_helmetClass_has_HCam") exitWith {
			diag_log "885th_CloneHUD: cTab helmet cam list never appeared - clone helmets not registered as helmet cams.";
		};
		private _added = 0;
		{
			if (!(_x in cTab_helmetClass_has_HCam) && {isClass (configFile >> "CfgWeapons" >> _x)}) then {
				cTab_helmetClass_has_HCam pushBack _x;
				_added = _added + 1;
			};
		} forEach (missionNamespace getVariable ["HUD_helmets", []]);
		diag_log format ["885th_CloneHUD: registered %1 clone helmets as cTab helmet cams.", _added];
		if (_added > 0) then { call cTab_fnc_updateLists; };
	};
};

// ------------------------------------------------------------
//  Current link mode, read from reality
// ------------------------------------------------------------
BPD_CloneHUD_tacmapActive = false; // TAC MAP link mode on

BPD_CloneHUD_fnc_linkMode = {
	if (!isNil "cTabIfOpen") exitWith {
		if ((cTabIfOpen select 1) in ["cTab_microDAGR_dsp","cTab_microDAGR_dlg"]) then {"DAGR"} else {"CTAB"}
	};
	if (BPD_CloneHUD_tacmapActive) exitWith {"TACMAP"};
	if (BPD_CloneHUD_hcamActive) exitWith {"HCAM"};
	"OFF"
};

BPD_CloneHUD_fnc_availableModes = {
	private _modes = [];
	// Tac Map first - it's the one that lives in the HUD itself
	if (BPD_CloneHUD_ctabLoaded && {!isNil "cTab_fnc_drawBftMarkers"}
		&& {!(missionNamespace getVariable ["BPD_CloneHUD_TACMAP_REQUIRE_DEVICE", true]) || {[["ItemcTab","ItemAndroid","ItemMicroDAGR"]] call BPD_CloneHUD_fnc_hasItem}}) then {
		_modes pushBack "TACMAP";
	};
	if (BPD_CloneHUD_ctabLoaded && {[["ItemcTab","ItemAndroid"]] call BPD_CloneHUD_fnc_hasItem}) then { _modes pushBack "CTAB"; };
	if (BPD_CloneHUD_ctabLoaded && {[["ItemMicroDAGR"]] call BPD_CloneHUD_fnc_hasItem}) then { _modes pushBack "DAGR"; };
	private _needDevice = missionNamespace getVariable ["BPD_CloneHUD_HCAM_REQUIRE_DEVICE", false];
	if (!_needDevice || {[["ItemcTab","ItemAndroid","ItemMicroDAGR"]] call BPD_CloneHUD_fnc_hasItem}) then { _modes pushBack "HCAM"; };
	_modes
};

// ------------------------------------------------------------
//  cTab interfaces
// ------------------------------------------------------------
// Opens a cTab interface the same way cTab's own key handlers do:
// close whatever's open, then queue the open until cTab has finished
// tearing the old one down.
BPD_CloneHUD_fnc_openCtab = {
	params ["_ifType", "_displayName"];
	if (isNil "cTab_fnc_open") exitWith {false};
	if (!isNil "cTabIfOpen") then { call cTab_fnc_close; };
	if (_displayName find "microDAGR" > -1) then {
		cTabMicroDAGRmode = if ([["ItemcTab"]] call BPD_CloneHUD_fnc_hasItem) then {0} else {2};
	};
	private _unit = if (isNil "cTab_player" || {isNull cTab_player}) then {player} else {cTab_player};
	diag_log format ["885th_CloneHUD: cTab link - opening %1 (interface %2) for %3. cTabIfOpen nil=%4, cTabIfOpenStart=%5.", _displayName, _ifType, _unit, isNil "cTabIfOpen", missionNamespace getVariable ["cTabIfOpenStart", "nil"]];
	// each request gets a token; a newer request (cycling on, closing)
	// cancels the pending open and the "didn't open" warning for this one
	BPD_CloneHUD_ctabReq = (missionNamespace getVariable ["BPD_CloneHUD_ctabReq", 0]) + 1;
	private _req = BPD_CloneHUD_ctabReq;
	[{
		params ["_args", "_pfh"];
		_args params ["_open", "_deadline", "_req", "_notBefore"];
		if (_req != BPD_CloneHUD_ctabReq) exitWith { [_pfh] call CBA_fnc_removePerFrameHandler; };
		// short delay so the ACE menu (or key) that asked for it has fully
		// closed first - opening a dialog in the same frame gets it closed
		if (diag_tickTime < _notBefore) exitWith {};
		if (diag_tickTime > _deadline) exitWith {
			[_pfh] call CBA_fnc_removePerFrameHandler;
			diag_log format ["885th_CloneHUD: cTab link - gave up opening %1: cTab still busy after 3s (cTabIfOpen nil=%2, cTabIfOpenStart=%3).", _open select 1, isNil "cTabIfOpen", cTabIfOpenStart];
		};
		if (isNil "cTabIfOpen" && {!cTabIfOpenStart}) then {
			[_pfh] call CBA_fnc_removePerFrameHandler;
			private _ok = _open call cTab_fnc_open;
			diag_log format ["885th_CloneHUD: cTab link - cTab_fnc_open %1 returned %2.", _open select 1, _ok];
		};
	}, 0, [[_ifType, _displayName, _unit, vehicle _unit], diag_tickTime + 3, _req, diag_tickTime + 0.2]] call CBA_fnc_addPerFrameHandler;

	// Tell the player if it didn't come up, instead of failing silently -
	// unless they've already moved on to another mode.
	[_displayName, _req] spawn {
		params ["_displayName", "_req"];
		sleep 2.5;
		if (_req != BPD_CloneHUD_ctabReq) exitWith {};
		if (isNil "cTabIfOpen" || {(cTabIfOpen select 1) != _displayName}) then {
			private _msg = format ["cTab did not open (%1) - see RPT", _displayName];
			[_msg, "bpdLinkErr", 6] call HUD_fnc_addSystemMessage;
			if (!(missionNamespace getVariable ["HUD_systemMessageAllowed", false])) then { systemChat ("[Clone HUD] " + _msg); };
			diag_log format ["885th_CloneHUD: cTab link - %1 not open 2s after request. cTabIfOpen=%2.", _displayName, missionNamespace getVariable ["cTabIfOpen", "nil"]];
		};
	};
	true
};

BPD_CloneHUD_fnc_enterMode = {
	params ["_mode"];
	switch (_mode) do {
		case "CTAB": {
			// Tablet if carried (full dialog with BFT / UAV / HCAM / messages),
			// otherwise the Android as a hands-free overlay.
			if ([["ItemcTab"]] call BPD_CloneHUD_fnc_hasItem) then {
				[1, "cTab_Tablet_dlg"] call BPD_CloneHUD_fnc_openCtab;
			} else {
				[0, "cTab_Android_dsp"] call BPD_CloneHUD_fnc_openCtab;
			};
			["Tactical link: cTab"] call BPD_CloneHUD_fnc_linkNotice;
		};
		case "DAGR": {
			[0, "cTab_microDAGR_dsp"] call BPD_CloneHUD_fnc_openCtab;
			["Tactical link: MicroDAGR"] call BPD_CloneHUD_fnc_linkNotice;
		};
		case "HCAM": {
			[objNull] call BPD_CloneHUD_fnc_startHcam;
		};
		case "TACMAP": {
			BPD_CloneHUD_tacmapActive = true;
			["Tactical link: Tac Map"] call BPD_CloneHUD_fnc_linkNotice;
			call BPD_CloneHUD_fnc_updateFeedPanel;
		};
		default {
			["Tactical link: standby"] call BPD_CloneHUD_fnc_linkNotice;
		};
	};
};

BPD_CloneHUD_fnc_exitMode = {
	params ["_mode"];
	switch (_mode) do {
		case "CTAB";
		case "DAGR": {
			BPD_CloneHUD_ctabReq = (missionNamespace getVariable ["BPD_CloneHUD_ctabReq", 0]) + 1; // cancel a pending open
			if (!isNil "cTab_fnc_close") then { call cTab_fnc_close; };
		};
		case "HCAM": { call BPD_CloneHUD_fnc_stopHcam; };
		case "TACMAP": { BPD_CloneHUD_tacmapActive = false; call BPD_CloneHUD_fnc_updateFeedPanel; };
	};
};

// ------------------------------------------------------------
//  Tac Map (BFT mini-map in the HUD panel)
// ------------------------------------------------------------
// Map control "Draw" handler (hooked in hudInit). Keeps the map centered
// on the player at the chosen zoom and draws cTab's own BFT + user
// markers with cTab's own functions, so it matches the tablet; plus the
// HUD's pings / intel markers. Datalink jammed: own position only.
BPD_CloneHUD_fnc_tacmapDraw = {
	params ["_map"];
	if (!BPD_CloneHUD_tacmapActive) exitWith {};
	private _zoom = missionNamespace getVariable ["BPD_CloneHUD_TACMAP_ZOOM", 0.06];
	_map ctrlMapAnimAdd [0, _zoom, getPosASL (vehicle player)];
	ctrlMapAnimCommit _map;
	private _jammed = (missionNamespace getVariable ["BPD_CloneHUD_jamTier", 0]) >= 2;
	if (!_jammed && {!isNil "cTabIconSize"} && {!isNil "cTabBFTmembers"}) then {
		[_map, 0] call cTab_fnc_drawBftMarkers;
		if (!isNil "cTabUserMarkerList") then { [_map, false] call cTab_fnc_drawUserMarkers; };
	};
	if (!_jammed && {!isNil "BPD_CloneHUD_intelMarkers"}) then {
		{
			_y params ["_pos", "_icon", "_rgba", "_label"];
			_map drawIcon [_icon, _rgba, _pos, 20, 20, 0, "", 0, 0.03, "RobotoCondensedBold", "right"];
		} forEach BPD_CloneHUD_intelMarkers;
	};
	// self
	_map drawIcon ["\A3\ui_f\data\map\VehicleIcons\iconmanvirtual_ca.paa", [1, 0.85, 0.2, 1], getPosASL (vehicle player), 22, 22, getDirVisual (vehicle player), "", 0, 0.03, "RobotoCondensedBold", "right"];
};

// Feedback that reaches the player even before the HUD has booted
// (system messages only show once boot-up is complete).
BPD_CloneHUD_fnc_linkNotice = {
	params ["_msg"];
	if (missionNamespace getVariable ["HUD_systemMessageAllowed", false]) then {
		[_msg, "bpdLinkMode", 4] call HUD_fnc_addSystemMessage;
	} else {
		systemChat ("[Clone HUD] " + _msg);
	};
};

// Switch straight to a given link mode (used by the ACE menu).
BPD_CloneHUD_fnc_setLink = {
	params ["_mode"];
	private _current = call BPD_CloneHUD_fnc_linkMode;
	if (_mode == _current) exitWith {};
	if (_mode == "HCAM" && {(missionNamespace getVariable ["BPD_CloneHUD_jamTier", 0]) >= 2}) exitWith {
		["<t color='#ff3b30'>NO SIGNAL</t> - helm cam feed jammed", "bpdJamHcam", 4] call HUD_fnc_addSystemMessage;
		playSound "glitch_short";
	};
	[_current] call BPD_CloneHUD_fnc_exitMode;
	[_mode] call BPD_CloneHUD_fnc_enterMode;
	playSound "click";
};

// Shift+H
BPD_CloneHUD_fnc_cycleLink = {
	if (!(headgear player in (missionNamespace getVariable ["HUD_helmets", []]))) exitWith {
		["Tactical link needs a Clone HUD helmet"] call BPD_CloneHUD_fnc_linkNotice;
		false
	};
	if (!alive player || {!isNull (findDisplay 312)}) exitWith {false};
	if (!isNil "cTabIfOpenStart" && {cTabIfOpenStart}) exitWith {
		diag_log "885th_CloneHUD: cTab link - cycle ignored, cTab is mid-open.";
		true
	};

	private _modes = call BPD_CloneHUD_fnc_availableModes;
	private _cycle = _modes + ["OFF"];
	private _current = call BPD_CloneHUD_fnc_linkMode;
	private _idx = _cycle find _current;
	private _next = _cycle select ((_idx + 1) mod (count _cycle));
	diag_log format ["885th_CloneHUD: cTab link - cycle %1 -> %2 (available %3, cTab loaded %4).", _current, _next, _modes, BPD_CloneHUD_ctabLoaded];
	if (!BPD_CloneHUD_ctabLoaded) then {
		["cTab not loaded - only Helm Cam is available"] call BPD_CloneHUD_fnc_linkNotice;
	};

	[_current] call BPD_CloneHUD_fnc_exitMode;
	[_next] call BPD_CloneHUD_fnc_enterMode;
	playSound "click";
	true
};

// ACE self-interaction menu - a second way in that doesn't depend on
// the keybinds (in case Shift+H / Shift+J collide with another mod).
BPD_CloneHUD_fnc_addAceMenu = {
	if (isNil "ace_interact_menu_fnc_createAction" || {!isNil "BPD_CloneHUD_aceMenuAdded"}) exitWith {};
	BPD_CloneHUD_aceMenuAdded = true;
	private _isClone = { headgear player in (missionNamespace getVariable ["HUD_helmets", []]) };
	private _root = ["BPD_CloneHUD", "Clone HUD", "", {}, _isClone] call ace_interact_menu_fnc_createAction;
	["CAManBase", 1, ["ACE_SelfActions"], _root, true] call ace_interact_menu_fnc_addActionToClass;
	{
		_x params ["_id", "_name", "_statement", "_condition"];
		private _a = [_id, _name, "", _statement, _condition] call ace_interact_menu_fnc_createAction;
		["CAManBase", 1, ["ACE_SelfActions", "BPD_CloneHUD"], _a, true] call ace_interact_menu_fnc_addActionToClass;
	} forEach [
		["BPD_CloneHUD_tacmap", "Tac Map",        { ["TACMAP"] call BPD_CloneHUD_fnc_setLink; }, { "TACMAP" in (call BPD_CloneHUD_fnc_availableModes) && {(call BPD_CloneHUD_fnc_linkMode) != "TACMAP"} }],
		["BPD_CloneHUD_ctab", "Open cTab",        { ["CTAB"] call BPD_CloneHUD_fnc_setLink; }, { "CTAB" in (call BPD_CloneHUD_fnc_availableModes) && {(call BPD_CloneHUD_fnc_linkMode) != "CTAB"} }],
		["BPD_CloneHUD_dagr", "Open MicroDAGR",   { ["DAGR"] call BPD_CloneHUD_fnc_setLink; }, { "DAGR" in (call BPD_CloneHUD_fnc_availableModes) && {(call BPD_CloneHUD_fnc_linkMode) != "DAGR"} }],
		["BPD_CloneHUD_hcam", "Helm Cam",         { ["HCAM"] call BPD_CloneHUD_fnc_setLink; }, { "HCAM" in (call BPD_CloneHUD_fnc_availableModes) && {(call BPD_CloneHUD_fnc_linkMode) != "HCAM"} }],
		["BPD_CloneHUD_next", "Next Helm Cam",    { call BPD_CloneHUD_fnc_nextHcam; },         { (call BPD_CloneHUD_fnc_linkMode) == "HCAM" }],
		["BPD_CloneHUD_off",  "Close Link",       { ["OFF"] call BPD_CloneHUD_fnc_setLink; },  { (call BPD_CloneHUD_fnc_linkMode) != "OFF" }],
		["BPD_CloneHUD_sendIntel", "Send Intel...", { call BPD_CloneHUD_fnc_intelDialogPlayer; }, { !isNil "BPD_CloneHUD_fnc_canSendIntel" && {call BPD_CloneHUD_fnc_canSendIntel} }],
		["BPD_CloneHUD_intelLog",  "Intel Log",     { call BPD_CloneHUD_fnc_intelShowLog; },     { !isNil "BPD_CloneHUD_fnc_intelShowLog" }],
		["BPD_CloneHUD_kills",     "Kill Counter",  { call BPD_CloneHUD_fnc_killToggle; },       { !isNil "BPD_CloneHUD_fnc_killToggle" && {missionNamespace getVariable ["BPD_CloneHUD_KILLS_ENABLED", true]} }]
	];
	diag_log "885th_CloneHUD: ACE self-interaction 'Clone HUD' menu added.";
};
call BPD_CloneHUD_fnc_addAceMenu;

// ------------------------------------------------------------
//  Helm cam feed (picture-in-picture on the HUD)
// ------------------------------------------------------------
// Who you can view. Built by the HUD itself instead of relying only on
// cTab's list: friendly units wearing a Clone HUD helmet (when "Clone
// Helmets Are Helmet Cams" is on), plus anyone cTab knows has a helmet
// cam (ItemcTabHCam / cTab's own helmet classes). The old version used
// ONLY cTab's list, so whenever cTab's scripts weren't running - e.g. the
// local 885_SW_cTab.pbo built without its "cTab" prefix - nobody showed up.
// Wearer can't send a feed: dead, ACE unconscious or vanilla incapacitated.
BPD_CloneHUD_fnc_hcamDown = {
	params ["_u"];
	isNull _u || {!alive _u} || {lifeState _u == "INCAPACITATED"} || {_u getVariable ["ACE_isUnconscious", false]}
};

BPD_CloneHUD_fnc_hcamCandidates = {
	private _helmets = missionNamespace getVariable ["HUD_helmets", []];
	private _mySide = side group player;
	private _list = [];
	if (missionNamespace getVariable ["BPD_CloneHUD_CTAB_HELMETCAMS", true]) then {
		_list = allUnits select { (headgear _x in _helmets) && {(_mySide getFriend (side group _x)) >= 0.6} };
	};
	if (!isNil "cTabHcamlist") then { _list = _list arrayIntersect _list; { _list pushBackUnique _x; } forEach cTabHcamlist; };
	private _grp = group player;
	_list = _list select { _x != player && {!([_x] call BPD_CloneHUD_fnc_hcamDown)} };
	if (missionNamespace getVariable ["BPD_CloneHUD_HCAM_SQUAD_ONLY", false]) then {
		_list = _list select { group _x isEqualTo _grp };
	};
	// own squad first, then nearest
	private _own = _list select { group _x isEqualTo _grp };
	private _other = _list - _own;
	_own = [_own, [], { player distance _x }, "ASCEND"] call BIS_fnc_sortBy;
	_other = [_other, [], { player distance _x }, "ASCEND"] call BIS_fnc_sortBy;
	_own + _other
};

// Plain-language reason there's nobody to view.
BPD_CloneHUD_fnc_hcamWhyNone = {
	private _helmets = missionNamespace getVariable ["HUD_helmets", []];
	private _mySide = side group player;
	private _clones = allUnits select { alive _x && {_x != player} && {headgear _x in _helmets} && {(_mySide getFriend (side group _x)) >= 0.6} };
	if (count _clones > 0 && {!(missionNamespace getVariable ["BPD_CloneHUD_CTAB_HELMETCAMS", true])}) exitWith {
		format ["Helm cam: %1 clone(s) nearby, but 'Clone Helmets Are Helmet Cams' is off on this server", count _clones]
	};
	if ((missionNamespace getVariable ["BPD_CloneHUD_HCAM_SQUAD_ONLY", false]) && {count _clones > 0}) exitWith {
		"Helm cam: nobody in YOUR squad has a helm cam ('Own Squad Only' is on)"
	};
	"Helm cam: no other friendly clone helmets or helmet cams in the mission"
};

BPD_CloneHUD_fnc_destroyHcamCamera = {
	if (count BPD_CloneHUD_hcam > 0) then {
		BPD_CloneHUD_hcam params ["_cam", "_helper"];
		if (!isNull _cam) then {
			_cam cameraEffect ["TERMINATE", "BACK", BPD_CloneHUD_hcamRT];
			camDestroy _cam;
		};
		if (!isNull _helper) then { deleteVehicle _helper; };
	};
	BPD_CloneHUD_hcam = [];
};

// Builds the camera on _unit, same mounting cTab uses for its own
// helmet cams (head-mounted on foot; chase cam on a vehicle only when
// 3rd person is allowed, otherwise no signal).
BPD_CloneHUD_fnc_attachHcam = {
	params ["_unit"];
	call BPD_CloneHUD_fnc_destroyHcamCamera;
	BPD_CloneHUD_hcamTarget = _unit;
	if (isNull _unit) exitWith {false};

	private _host = _unit;
	private _camOffset = [0.12, 0, 0.15];
	private _targetOffset = [0, 8, 1];
	if !(vehicle _unit isKindOf "CAManBase") then {
		if (difficultyEnabled "3rdPersonView") then {
			_host = vehicle _unit;
			_camOffset = [0, -8, 4];
			_targetOffset = [0, 8, 2];
		} else {
			_host = objNull;
		};
	};
	if (isNull _host) exitWith {false};

	private _helper = "Sign_Sphere10cm_F" createVehicleLocal (getPosATL _host);
	hideObject _helper;
	_helper attachTo [_host, _targetOffset];

	private _cam = "camera" camCreate (getPosATL _host);
	_cam camPrepareFov 0.7;
	_cam camPrepareTarget _helper;
	_cam camCommitPrepared 0;
	if (_host == _unit) then {
		_cam attachTo [_host, _camOffset, "Head"];
	} else {
		_cam attachTo [_host, _camOffset];
	};
	_cam cameraEffect ["INTERNAL", "BACK", BPD_CloneHUD_hcamRT];
	BPD_CloneHUD_hcam = [_cam, _helper, _host];
	true
};

BPD_CloneHUD_fnc_startHcam = {
	params [["_preferred", objNull]];
	private _candidates = call BPD_CloneHUD_fnc_hcamCandidates;
	if (count _candidates == 0) exitWith {
		BPD_CloneHUD_hcamActive = false;
		[call BPD_CloneHUD_fnc_hcamWhyNone] call BPD_CloneHUD_fnc_linkNotice;
		false
	};
	if (!isPiPEnabled) then {
		["Helm cam: turn on Picture-in-Picture in Options > Video to see the feed"] call BPD_CloneHUD_fnc_linkNotice;
	};
	private _target = if (!isNull _preferred && {_preferred in _candidates}) then {_preferred} else {
		if (BPD_CloneHUD_hcamTarget in _candidates) then {BPD_CloneHUD_hcamTarget} else {_candidates select 0}
	};
	BPD_CloneHUD_hcamActive = true;
	[_target] call BPD_CloneHUD_fnc_attachHcam;
	[format ["Helm cam: %1", name _target]] call BPD_CloneHUD_fnc_linkNotice;
	call BPD_CloneHUD_fnc_updateFeedPanel;
	true
};

// ------------------------------------------------------------
//  Signal loss: static -> SIGNAL LOST -> next trooper
// ------------------------------------------------------------
// Static overlay over the feed picture (created on first use).
BPD_CloneHUD_fnc_hcamStaticCtrl = {
	private _c = uiNamespace getVariable ["BPD_CloneHUD_hcamStatic", controlNull];
	if (isNil "HUD_feedPicture") exitWith {controlNull};
	private _pic = HUD_feedPicture#0;
	if (isNull _pic) exitWith {controlNull};
	if (isNull _c || {ctrlParent _c != ctrlParent _pic}) then {
		_c = (ctrlParent _pic) ctrlCreate ["RscPicture", 27730];
		uiNamespace setVariable ["BPD_CloneHUD_hcamStatic", _c];
	};
	_c ctrlSetPosition (ctrlPosition _pic);
	_c ctrlCommit 0;
	_c
};

// Static at strength _a (0..1); 0 hides it. Swaps the noise frame each call.
BPD_CloneHUD_fnc_hcamStaticShow = {
	params ["_a"];
	private _c = call BPD_CloneHUD_fnc_hcamStaticCtrl;
	if (isNull _c) exitWith {};
	if (_a <= 0) exitWith { _c ctrlShow false; };
	// Flashing Effects: full = new noise frame every call, reduced ~2.5/s, off = one still frame
	private _mode = (missionNamespace getVariable ["BPD_CloneHUD_FLASH", 1]) min 2 max 0;
	private _every = [1e9, 0.4, 0] select _mode;
	if (ctrlText _c == "" || {diag_tickTime - (_c getVariable ["bpdSwap", -1e9]) >= _every}) then {
		_c setVariable ["bpdSwap", diag_tickTime];
		_c ctrlSetText format ["\885th_CloneHUD\textures\hcam\hcam_static_%1_ca.paa", 1 + floor random 4];
	};
	_c ctrlSetTextColor [1, 1, 1, _a];
	_c ctrlShow true;
};

// Feed wearer went down / dropped off: ~1.2 s of rising static on the
// live feed, ~1 s of full static + SIGNAL LOST, then the next trooper
// with the static clearing. Nobody left: helm cam closes.
BPD_CloneHUD_fnc_hcamSignalLoss = {
	if (missionNamespace getVariable ["BPD_CloneHUD_hcamLosing", false]) exitWith {};
	BPD_CloneHUD_hcamLosing = true;
	[] spawn {
		private _t = BPD_CloneHUD_hcamTarget;
		private _name = if (isNull _t) then {"FEED"} else {toUpper name _t};
		playSound "glitch_short";
		// 1) feed breaking up
		BPD_CloneHUD_hcamStatus = format ["<t color='#ffb347'>%1 - SIGNAL DEGRADED</t>", _name];
		call BPD_CloneHUD_fnc_updateFeedPanel;
		private _end = diag_tickTime + 1.2;
		while { diag_tickTime < _end && {BPD_CloneHUD_hcamActive} } do {
			private _k = 1 - ((_end - diag_tickTime) / 1.2);
			private _jit = if ((missionNamespace getVariable ["BPD_CloneHUD_FLASH", 1]) >= 2) then { 0.7 + random 0.3 } else { 1 };
			[(0.25 + 0.6 * _k) * _jit] call BPD_CloneHUD_fnc_hcamStaticShow;
			sleep 0.06;
		};
		// 2) signal lost
		if (BPD_CloneHUD_hcamActive) then {
			call BPD_CloneHUD_fnc_destroyHcamCamera;
			playSound "glitch_short";
			["Helm cam: " + _name + " - signal lost", "bpdLinkMode", 3] call HUD_fnc_addSystemMessage;
			BPD_CloneHUD_hcamStatus = "<t color='#ff3b30'>SIGNAL LOST</t>";
			call BPD_CloneHUD_fnc_updateFeedPanel;
			_end = diag_tickTime + 1;
			while { diag_tickTime < _end && {BPD_CloneHUD_hcamActive} } do {
				[0.95] call BPD_CloneHUD_fnc_hcamStaticShow;
				sleep 0.06;
			};
		};
		// 3) next trooper, static clearing
		BPD_CloneHUD_hcamStatus = "";
		if (BPD_CloneHUD_hcamActive) then {
			if ([objNull] call BPD_CloneHUD_fnc_startHcam) then {
				_end = diag_tickTime + 0.5;
				while { diag_tickTime < _end && {BPD_CloneHUD_hcamActive} } do {
					[0.8 * ((_end - diag_tickTime) / 0.5)] call BPD_CloneHUD_fnc_hcamStaticShow;
					sleep 0.06;
				};
			} else {
				call BPD_CloneHUD_fnc_stopHcam;
			};
		};
		[0] call BPD_CloneHUD_fnc_hcamStaticShow;
		BPD_CloneHUD_hcamLosing = false;
	};
};

BPD_CloneHUD_fnc_stopHcam = {
	[0] call BPD_CloneHUD_fnc_hcamStaticShow;
	BPD_CloneHUD_hcamStatus = "";
	BPD_CloneHUD_hcamActive = false;
	call BPD_CloneHUD_fnc_destroyHcamCamera;
	call BPD_CloneHUD_fnc_updateFeedPanel;
};

// Shift+J
BPD_CloneHUD_fnc_nextHcam = {
	if (!(headgear player in (missionNamespace getVariable ["HUD_helmets", []]))) exitWith {false};
	if (!alive player || {!isNull (findDisplay 312)}) exitWith {false};
	if (!("HCAM" in (call BPD_CloneHUD_fnc_availableModes))) exitWith {
		["Helm cam: this server requires a cTab Tablet, Android or MicroDAGR to view helm cams"] call BPD_CloneHUD_fnc_linkNotice;
		false
	};
	if (!BPD_CloneHUD_hcamActive) exitWith {
		[call BPD_CloneHUD_fnc_linkMode] call BPD_CloneHUD_fnc_exitMode;
		[objNull] call BPD_CloneHUD_fnc_startHcam;
		playSound "click";
		true
	};
	private _candidates = call BPD_CloneHUD_fnc_hcamCandidates;
	if (count _candidates == 0) exitWith { call BPD_CloneHUD_fnc_stopHcam; false };
	private _idx = _candidates find BPD_CloneHUD_hcamTarget;
	private _next = _candidates select ((_idx + 1) mod (count _candidates));
	[_next] call BPD_CloneHUD_fnc_startHcam;
	playSound "click";
	true
};

// ------------------------------------------------------------
//  Panel drawing
// ------------------------------------------------------------
BPD_CloneHUD_fnc_updateFeedPanel = {
	if (isNil "HUD_feedPicture") exitWith {};
	private _ctrls = [HUD_feedBack#0, HUD_feedHeader#0, HUD_feedPicture#0, HUD_feedLabel#0];
	if (isNull (_ctrls select 0)) exitWith {};

	// BPD_CloneHUD_FEED_MODE: 0 off, 1 only while a link is active (default), 2 always
	private _feedMode = missionNamespace getVariable ["BPD_CloneHUD_FEED_MODE", 1];
	private _visible = (_feedMode == 2 || {_feedMode == 1 && {(call BPD_CloneHUD_fnc_linkMode) != "OFF"}})
		&& {alive player}
		&& {player getVariable ["HUD_bootComplete", false]}
		&& {HUD_hasHelmet}
		&& {isNull (findDisplay 312)};

	private _mapCtrl = if (isNil "HUD_feedMap") then {controlNull} else {HUD_feedMap#0};
	private _frameCtrl = if (isNil "HUD_feedFrame") then {controlNull} else {HUD_feedFrame#0};
	if (!_visible) exitWith {
		{ _x ctrlShow false; } forEach _ctrls;
		_mapCtrl ctrlShow false;
		_frameCtrl ctrlShow false;
	};

	private _s = missionNamespace getVariable ["BPD_CloneHUD_feedTextScale", 1];
	private _onHex = [INTERIOR_OVERLAY_COLOR] call HUD_fnc_colorToHex;
	private _mode = call BPD_CloneHUD_fnc_linkMode;

	private _strip = "";
	{
		_x params ["_label", "_has"];
		_strip = _strip + format ["<t color='%1'>%2</t>  ", if (_has) then {_onHex} else {"#4d4d4d"}, _label];
	} forEach (call BPD_CloneHUD_fnc_deviceState);
	private _modeText = switch (_mode) do {
		case "CTAB": {"CTAB"};
		case "DAGR": {"DAGR"};
		case "HCAM": {"HELM CAM"};
		case "TACMAP": {"TAC MAP"};
		default {"STANDBY"};
	};
	(HUD_feedHeader#0) ctrlSetStructuredText parseText format [
		"<t size='%1' align='left' font='RobotoCondensed'>%2</t><t size='%1' align='right' color='#ffffff' font='RobotoCondensedBold'>%3</t>",
		0.85 * _s, _strip, _modeText
	];

	private _hcamOn = _mode == "HCAM";
	private _mapOn = _mode == "TACMAP" && {!isNull _mapCtrl};
	(HUD_feedBack#0) ctrlShow true;
	(HUD_feedHeader#0) ctrlShow true;
	(HUD_feedPicture#0) ctrlShow (_hcamOn && {count BPD_CloneHUD_hcam > 0} && {isPiPEnabled});
	(HUD_feedLabel#0) ctrlShow (_hcamOn || _mapOn);
	_mapCtrl ctrlShow _mapOn;

	// 885th cTab device frame around the Tac Map (TACMAP_FRAME).
	// Each entry, as fractions of the square 2048 texture:
	// [texture, device left, right, top, bottom, screen left, right, top, bottom]
	// The device is scaled so its width matches the panel; the map fills
	// the frame's screen opening.
	private _frameSel = missionNamespace getVariable ["BPD_CloneHUD_TACMAP_FRAME", 0];
	if (_frameSel == 0) then {
		private _dev = call BPD_CloneHUD_fnc_deviceState;
		_frameSel = call {
			if ((_dev select 0) select 1) exitWith {3};
			if ((_dev select 1) select 1) exitWith {2};
			if ((_dev select 2) select 1) exitWith {1};
			1 // Tac Map without a device (Require Device off): DAGR look
		};
	};
	private _frame = [
		[],
		["\cTab\img\microdagr_background_ca.paa", 0.034, 0.841, 0.0, 1.0, 0.282, 0.738, 0.155, 0.785],
		["\cTab\img\android_background_ca.paa", 0.14, 0.845, 0.30, 0.93, 0.205, 0.745, 0.36, 0.655],
		["\cTab\img\tablet_background_ca.paa", 0.023, 0.877, 0.008, 0.792, 0.1475, 0.753, 0.259, 0.704],
		[]
	] param [_frameSel, []];
	private _framed = _mapOn && {count _frame > 0} && {!isNull _frameCtrl};
	if (_mapOn) then {
		private _hp = ctrlPosition (HUD_feedHeader#0);
		private _top = (_hp select 1) + (_hp select 3);
		private _w = _hp select 2;
		private _sq = pixelH / pixelW; // width -> height for a square on screen
		if (_framed) then {
			_frame params ["_tex", "_dx0", "_dx1", "_dy0", "_dy1", "_sx0", "_sx1", "_sy0", "_sy1"];
			private _iw = _w / (_dx1 - _dx0);
			private _ih = _iw * _sq;
			private _ix = (_hp select 0) - _dx0 * _iw;
			private _iy = _top - _dy0 * _ih;
			if (ctrlText _frameCtrl != _tex) then { _frameCtrl ctrlSetText _tex; };
			_frameCtrl ctrlSetPosition [_ix, _iy, _iw, _ih];
			_mapCtrl ctrlSetPosition [_ix + _sx0 * _iw, _iy + _sy0 * _ih, (_sx1 - _sx0) * _iw, (_sy1 - _sy0) * _ih];
			BPD_CloneHUD_feedMapH = (_dy1 - _dy0) * _ih;
		} else {
			private _mh = _w * _sq * (missionNamespace getVariable ["BPD_CloneHUD_TACMAP_ASPECT", 1]);
			_mapCtrl ctrlSetPosition [_hp select 0, _top, _w, _mh];
			BPD_CloneHUD_feedMapH = _mh;
		};
		_frameCtrl ctrlCommit 0;
		_mapCtrl ctrlCommit 0;
	};
	_frameCtrl ctrlShow _framed;

	if (_mapOn) then {
		private _jammed = (missionNamespace getVariable ["BPD_CloneHUD_jamTier", 0]) >= 2;
		private _label = if (_jammed) then {"<t color='#ff3b30'>DATALINK LOST</t>"} else {
			format ["GRID %1  %2°", mapGridPosition player, round getDir (vehicle player)]
		};
		private _mp = ctrlPosition _mapCtrl;
		(HUD_feedLabel#0) ctrlSetPosition [_mp select 0, (_mp select 1) + (_mp select 3) - (0.03 * safezoneH * _s), _mp select 2, 0.03 * safezoneH * _s];
		(HUD_feedLabel#0) ctrlSetStructuredText parseText format ["<t size='%1' align='center'>%2</t>", 0.8 * _s, _label];
	};

	if (_hcamOn) then {
		private _t = BPD_CloneHUD_hcamTarget;
		private _label = call {
			private _st = missionNamespace getVariable ["BPD_CloneHUD_hcamStatus", ""];
			if (_st != "") exitWith {_st};
			if (!isPiPEnabled) exitWith {"ENABLE PIP IN VIDEO OPTIONS"};
			if (isNull _t) exitWith {"NO SIGNAL"};
			if (count BPD_CloneHUD_hcam == 0) exitWith {format ["%1 - NO SIGNAL", toUpper name _t]};
			format ["%1  %2m", toUpper name _t, round (player distance _t)]
		};
		(HUD_feedLabel#0) ctrlSetStructuredText parseText format ["<t size='%1' align='center'>%2</t>", 0.8 * _s, _label];
	};

	// Collapse the panel to just the header strip when there's no feed.
	private _back = ctrlPosition (HUD_feedBack#0);
	private _hdr = ctrlPosition (HUD_feedHeader#0);
	private _pic = ctrlPosition (HUD_feedPicture#0);
	_back set [3, call {
		if (_hcamOn) exitWith {(_hdr select 3) + (_pic select 3)};
		if (_framed) exitWith {_hdr select 3}; // the device is the panel - no dark box behind it
		if (_mapOn) exitWith {(_hdr select 3) + (missionNamespace getVariable ["BPD_CloneHUD_feedMapH", _pic select 3])};
		_hdr select 3
	}];
	(HUD_feedBack#0) ctrlSetPosition _back;
	{ _x ctrlCommit 0; } forEach _ctrls;
};

// Startup sanity check: cTab's CONFIG loaded but its SCRIPTS didn't.
// That's what happens when 885_SW_cTab.pbo is packed without its "cTab"
// prefix (Addon Builder ignores pbo.json - the source folder now has a
// $PBOPREFIX$ file for this): the config points at \cTab\..., so the
// game either runs ANOTHER mod's cTab scripts or none at all.
if (isNil "BPD_CloneHUD_ctabCheck" && {BPD_CloneHUD_ctabLoaded}) then {
	BPD_CloneHUD_ctabCheck = [] spawn {
		waitUntil { sleep 1; time > 10 };
		private _missing = [];
		if (isNil "cTab_fnc_open") then { _missing pushBack "cTab_fnc_open (functions)"; };
		if (isNil "cTabIfOpenStart") then { _missing pushBack "player_init.sqf"; };
		if (count _missing > 0) then {
			private _msg = "885th cTab is loaded but its scripts are not running - the 885_SW_cTab.pbo was probably packed without the 'cTab' prefix. cTab and the Clone HUD cTab link won't work.";
			systemChat ("[Clone HUD] " + _msg);
			diag_log format ["885th_CloneHUD: %1 Missing: %2.", _msg, _missing];
		} else {
			// More than one mod defining cTab means one shadows the other.
			private _mods = configSourceModList (configFile >> "CfgPatches" >> "cTab");
			diag_log format ["885th_CloneHUD: cTab scripts running. Mods defining CfgPatches cTab: %1.", _mods];
			if (count _mods > 1) then {
				systemChat format ["[Clone HUD] More than one cTab mod is loaded (%1) - only one of them is actually in use. Load just the 885th one.", _mods joinString ", "];
			};
			// The 885th cTab and the original Steam @cTab share the "cTab"
			// prefix and CfgPatches class, so with both in the mod list only
			// one PBO loads - usually the original, which then shows up here
			// as the ONLY source. Catch that case too.
			if ((_mods findIf { "885" in toLower _x }) < 0) then {
				private _msg = format ["cTab is coming from %1, not the 885th cTab. Remove the original @cTab from your mod list - the 885th Aux mod already includes cTab.", _mods joinString ", "];
				systemChat ("[Clone HUD] " + _msg);
				diag_log ("885th_CloneHUD: " + _msg);
			};
		};
	};
};

// Session-wide loop (survives respawn). Keeps the panel current, drops
// a feed whose wearer died / left, and tears the camera down whenever
// the HUD isn't up so it never renders in the background.
if (isNil "BPD_CloneHUD_feedLoop") then {
	BPD_CloneHUD_feedLoop = [] spawn {
		waitUntil { sleep 1; !isNull player && {!isNil "HUD_hasHelmet"} };
		while {true} do {
			private _hudUp = alive player && {player getVariable ["HUD_bootComplete", false]} && {HUD_hasHelmet};
			if (BPD_CloneHUD_hcamActive) then {
				if (!_hudUp) then {
					call BPD_CloneHUD_fnc_stopHcam;
				} else {
					private _t = BPD_CloneHUD_hcamTarget;
					if (missionNamespace getVariable ["BPD_CloneHUD_hcamLosing", false]) then {
						// signal-loss sequence is running - leave the feed alone
					} else { if ([_t] call BPD_CloneHUD_fnc_hcamDown || {!(_t in (call BPD_CloneHUD_fnc_hcamCandidates))}) then {
						call BPD_CloneHUD_fnc_hcamSignalLoss;
					} else {
						// wearer got in/out of a vehicle - remount the camera
						private _wantHost = if (vehicle _t isKindOf "CAManBase") then {_t} else {vehicle _t};
						if (count BPD_CloneHUD_hcam == 0 || {(BPD_CloneHUD_hcam select 2) != _wantHost}) then {
							[_t] call BPD_CloneHUD_fnc_attachHcam;
						};
					}; };
				};
			};
			call BPD_CloneHUD_fnc_updateFeedPanel;
			sleep 0.5;
		};
	};
};
