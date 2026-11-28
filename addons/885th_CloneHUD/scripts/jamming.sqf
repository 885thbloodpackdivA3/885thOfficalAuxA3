/*
	885th Bloodpack Division - Clone HUD - Jamming
	---------------------------------------------------------------
	Works out how jammed the player is (0..1) every 0.5 s from:
	  1. Crows Electronic Warfare jammers (crowsew_main_jamMap:
	     [netId -> [obj, radFalloff, radEffective, enabled, caps]]).
	  2. 885th HUD jammers - any object with
	     setVariable ["BPD_CloneHUD_jammer", [radFalloff, radEffective], true]
	     listed in BPD_CloneHUD_jammers. Zeus places / removes them with
	     the ZEN modules "885th Clone HUD > Add / Remove HUD Jammer".
	     These also jam TFAR the same way Crows EW does (server setting).
	  3. Anything else that jams TFAR the usual way - read back from the
	     player's tf_sendingDistanceMultiplicator / tf_receivingDistance-
	     Multiplicator, so other jammer scripts trigger "COMMS LOST" too
	     (they just can't drive the distance-based tiers).
	  Distance model (same as Crows EW): inside the effective radius =
	  fully jammed, between effective and falloff radius it fades out.

	Tiers (BPD_CloneHUD_jamTier):
	  0  clear
	  1  >= 20 %  COMMS DEGRADED - warning only
	  2  >= 50 %  COMMS LOST     - datalink down: radio comms rows,
	              squad list medical/distances, pings + intel, medic
	              pings, helm cam feed
	  3  >= 85 %  SENSORS JAMMED - also scanner markers + radar, visor
	              static
	Every hook elsewhere just reads BPD_CloneHUD_jamTier.
*/

BPD_CloneHUD_jamLevel = 0;
BPD_CloneHUD_jamTier = 0;
BPD_CloneHUD_jamTfarOwned = false;
if (isNil "BPD_CloneHUD_jammers") then { BPD_CloneHUD_jammers = []; };
BPD_CloneHUD_jamEden = []; // Eden-placed devices, found locally on each client (see jamDeviceScan)

BPD_CloneHUD_fnc_jamFromDist = {
	params ["_d", "_falloff", "_eff"];
	if (_d <= _eff) exitWith {1};
	if (_d >= _falloff || {_falloff <= _eff}) exitWith {0};
	1 - ((_d - _eff) / (_falloff - _eff))
};

// [level from known sources, level from our own jammers only]
BPD_CloneHUD_fnc_jamSources = {
	private _lvl = 0;
	private _own = 0;
	private _pos = getPosASL player;
	if (!isNil "crowsew_main_jamMap" && {crowsew_main_jamMap isEqualType createHashMap}) then {
		{
			_y params [["_obj", objNull], ["_fall", 0], ["_eff", 0], ["_on", true]];
			if (_on && {!isNull _obj} && {alive _obj}) then {
				_lvl = _lvl max ([_pos distance (getPosASL _obj), _fall, _eff] call BPD_CloneHUD_fnc_jamFromDist);
			};
		} forEach crowsew_main_jamMap;
	};
	{
		if (!isNull _x && {!(_x getVariable ["BPD_CloneHUD_jamDead", false])} && {alive _x || {_x isKindOf "Logic"} || {_x isKindOf "HeliH"}}) then {
			(_x getVariable ["BPD_CloneHUD_jammer", []]) params [["_fall", 0], ["_eff", 0]];
			if (_fall > 0) then {
				_own = _own max ([_pos distance (getPosASL _x), _fall, _eff] call BPD_CloneHUD_fnc_jamFromDist);
			};
		};
	} forEach (BPD_CloneHUD_jammers + BPD_CloneHUD_jamEden);
	[_lvl max _own, _own]
};

// Level implied by TFAR's own range variables (any jammer script).
BPD_CloneHUD_fnc_jamFromTfar = {
	private _tx = player getVariable ["tf_sendingDistanceMultiplicator", 1];
	private _rx = player getVariable ["tf_receivingDistanceMultiplicator", 1];
	if (_tx > 1) exitWith {0}; // boosted (satcom etc.), not jammed
	(0 max (1 - _tx) min 1) max (0 max ((_rx - 1) / 99) min 1)
};

// Our own jammers push TFAR like Crows EW: rx up to 100, tx down to 1/20.
BPD_CloneHUD_fnc_jamApplyTfar = {
	params ["_own"];
	if !(missionNamespace getVariable ["BPD_CloneHUD_JAM_TFAR", true]) then { _own = 0; }; // off: just hand back anything we set
	if (_own > 0) then {
		player setVariable ["tf_receivingDistanceMultiplicator", 1 + 99 * _own];
		player setVariable ["tf_sendingDistanceMultiplicator", 1 - 0.95 * _own];
		BPD_CloneHUD_jamTfarOwned = true;
	} else {
		if (BPD_CloneHUD_jamTfarOwned) then {
			player setVariable ["tf_receivingDistanceMultiplicator", 1];
			player setVariable ["tf_sendingDistanceMultiplicator", 1];
			BPD_CloneHUD_jamTfarOwned = false;
		};
	};
};

BPD_CloneHUD_fnc_jamTick = {
	if !(missionNamespace getVariable ["BPD_CloneHUD_JAM_ENABLED", true]) exitWith {
		[0] call BPD_CloneHUD_fnc_jamApplyTfar; // hand TFAR range back if we had cut it
		if (BPD_CloneHUD_jamTier != 0) then { [BPD_CloneHUD_jamTier, 0] call BPD_CloneHUD_fnc_jamTierChanged; };
		BPD_CloneHUD_jamLevel = 0; BPD_CloneHUD_jamTier = 0;
		call BPD_CloneHUD_fnc_jamVisor;
	};
	(call BPD_CloneHUD_fnc_jamSources) params ["_srcLvl", "_own"];
	[_own] call BPD_CloneHUD_fnc_jamApplyTfar;
	// TFAR read-back after our own push, so it also covers other scripts
	private _lvl = _srcLvl max (call BPD_CloneHUD_fnc_jamFromTfar);
	if (!alive player) then { _lvl = 0; };
	BPD_CloneHUD_jamLevel = _lvl;
	private _degrade = missionNamespace getVariable ["BPD_CloneHUD_JAM_DEGRADE", true];
	private _tier = call {
		if (_lvl >= 0.85 && {_degrade}) exitWith {3};
		if (_lvl >= 0.5) exitWith {[1, 2] select _degrade};
		if (_lvl >= 0.2) exitWith {1};
		0
	};
	if (_tier != BPD_CloneHUD_jamTier) then {
		private _old = BPD_CloneHUD_jamTier;
		BPD_CloneHUD_jamTier = _tier;
		[_old, _tier] call BPD_CloneHUD_fnc_jamTierChanged;
	};
	call BPD_CloneHUD_fnc_jamVisor;
};

BPD_CloneHUD_fnc_jamTierChanged = {
	params ["_old", "_new"];
	private _msg = switch (_new) do {
		case 3: { "<t color='#ff3b30'>SENSORS JAMMED</t> - scanner and radar offline" };
		case 2: { "<t color='#ff3b30'>COMMS LOST</t> - datalink down" };
		case 1: { ["<t color='#ffd23f'>COMMS DEGRADED</t> - jamming detected", "<t color='#ffd23f'>COMMS DEGRADED</t> - datalink restored"] select (_old > 1) };
		default { "<t color='#3cb371'>COMMS RESTORED</t>" };
	};
	if (!isNil "HUD_fnc_addSystemMessage") then { [_msg, "bpdJam", 6] call HUD_fnc_addSystemMessage; };
	if (_new > _old) then { playSound "glitch_short"; } else { playSound "click"; };
	// datalink drop takes the helm cam feed with it
	if (_new >= 2 && {!isNil "BPD_CloneHUD_fnc_linkMode"} && {(call BPD_CloneHUD_fnc_linkMode) == "HCAM"}) then {
		["OFF"] call BPD_CloneHUD_fnc_setLink;
	};
	if (_new >= 3 && {!isNil "HUD_fnc_radarHide"}) then { call HUD_fnc_radarHide; };
	if (!isNil "HUD_fnc_updateTeamList" && {player getVariable ["HUD_bootComplete", false]}) then { call HUD_fnc_updateTeamList; };
};

// Visor static (film grain), client option, scales with jamming.
BPD_CloneHUD_fnc_jamVisor = {
	private _want = (missionNamespace getVariable ["BPD_CloneHUD_JAM_STATIC", true])
		&& {BPD_CloneHUD_jamLevel >= 0.5}
		&& {!isNil "BPD_CloneHUD_fnc_hudUp"} && {call BPD_CloneHUD_fnc_hudUp}
		&& {missionNamespace getVariable ["HUD_firstPersonCheck", true]};
	if (_want) then {
		if (isNil "BPD_CloneHUD_jamGrain") then {
			BPD_CloneHUD_jamGrain = ppEffectCreate ["FilmGrain", 2051];
		};
		BPD_CloneHUD_jamGrain ppEffectEnable true;
		private _i = 0.1 + 0.5 * ((BPD_CloneHUD_jamLevel - 0.5) / 0.5);
		BPD_CloneHUD_jamGrain ppEffectAdjust [_i, 1.25, 2.5, 0.5, 0.5, true];
		BPD_CloneHUD_jamGrain ppEffectCommit 0.4;
		if (BPD_CloneHUD_jamTier >= 3 && {random 1 < 0.12}) then { playSound "glitch_short"; };
	} else {
		if (!isNil "BPD_CloneHUD_jamGrain") then {
			BPD_CloneHUD_jamGrain ppEffectEnable false;
		};
	};
};

// Text for the comms list / ticker while jammed ("" when clear).
BPD_CloneHUD_fnc_jamBanner = {
	switch (BPD_CloneHUD_jamTier) do {
		case 3; case 2: {
			private _blink = ["#ff3b30", "#7a1d18"] select ((floor (diag_tickTime * 2)) mod 2 == 1);
			format ["<t color='%1' font='PuristaBold'>COMMS LOST</t> <t color='#8aa0a8'>(%2%% jamming)</t>", _blink, round (BPD_CloneHUD_jamLevel * 100)]
		};
		case 1: { format ["<t color='#ffd23f' font='PuristaBold'>COMMS DEGRADED</t> <t color='#8aa0a8'>(%1%% jamming)</t>", round (BPD_CloneHUD_jamLevel * 100)] };
		default { "" };
	};
};

// ---- Zeus: add / remove 885th HUD jammers (ZEN) ----
BPD_CloneHUD_fnc_jamAdd = {
	params ["_obj", "_fall", "_eff"];
	_obj setVariable ["BPD_CloneHUD_jammer", [_fall, _eff min _fall], true];
	BPD_CloneHUD_jammers = (BPD_CloneHUD_jammers select { !isNull _x }) + [_obj];
	BPD_CloneHUD_jammers = BPD_CloneHUD_jammers arrayIntersect BPD_CloneHUD_jammers;
	publicVariable "BPD_CloneHUD_jammers";
};
BPD_CloneHUD_fnc_jamRemove = {
	params ["_obj"];
	_obj setVariable ["BPD_CloneHUD_jammer", nil, true];
	BPD_CloneHUD_jammers = BPD_CloneHUD_jammers select { !isNull _x && {_x != _obj} };
	publicVariable "BPD_CloneHUD_jammers";
	if (_obj isKindOf "HeliH" && {_obj getVariable ["BPD_CloneHUD_jamPad", false]}) then { deleteVehicle _obj; };
};

// ---- Jammer DEVICES: a jammer troopers have to find and kill ----
// An object with BPD_CloneHUD_jamDevice = [hitsToDestroy, disableSeconds, whoCanDisable(0 anyone / 1 engineers)]
// on top of the usual BPD_CloneHUD_jammer [falloff, effective].
// Killed by any of:
//   - direct hits (HitPart, on the shooter's machine): 1 per hit, an
//     explosive round counts as a kill outright
//   - grenades / launcher rounds / placed charges exploding within a few m
//   - the object itself being destroyed (destructible props)
//   - "Disable Jammer" (ACE interaction or hold action, progress bar)
// Killing sets BPD_CloneHUD_jamDead (public) - every client stops counting
// it, so the HUD comes back on its next jam tick ("COMMS RESTORED").
// Zeus: ZEN "Place Jammer Device". Eden: put in the object's init:
//   this setVariable ["BPD_CloneHUD_jammer", [600, 200]];
//   this setVariable ["BPD_CloneHUD_jamDevice", [10, 8, 0]];

BPD_CloneHUD_fnc_jamDeviceKill = {
	params ["_obj", "_how"];
	if (isNull _obj || {_obj getVariable ["BPD_CloneHUD_jamDead", false]}) exitWith {};
	private _fall = (_obj getVariable ["BPD_CloneHUD_jammer", [600, 200]]) param [0, 600];
	_obj setVariable ["BPD_CloneHUD_jamDead", true, true];
	if (_how == "destroyed" && {alive _obj}) then { _obj setDamage 1; };
	[_obj, _how, name player, _fall] remoteExec ["BPD_CloneHUD_fnc_jamDeviceKilled", allPlayers - entities "HeadlessClient_F"];
	if (_obj in BPD_CloneHUD_jammers) then {
		BPD_CloneHUD_jammers = BPD_CloneHUD_jammers select { !isNull _x && {_x != _obj} };
		publicVariable "BPD_CloneHUD_jammers";
	};
};

// Every client: effects + message for anyone it was jamming (or close by).
BPD_CloneHUD_fnc_jamDeviceKilled = {
	params ["_obj", "_how", "_by", "_fall"];
	if (!hasInterface || {isNull _obj}) exitWith {};
	private _pos = getPosATL _obj;
	if (player distance _obj < 1500) then {
		// smoke + flash, local only
		private _smoke = "#particlesource" createVehicleLocal _pos;
		_smoke setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 7, 48, 1], "", "Billboard", 1, 6, [0, 0, 0.4], [0, 0, 1.2], 0, 10, 7.9, 0.075, [0.8, 2.5, 5], [[0.12, 0.12, 0.12, 0.7], [0.25, 0.25, 0.25, 0.4], [0.35, 0.35, 0.35, 0]], [0.125], 1, 0, "", "", _obj];
		_smoke setDropInterval 0.12;
		private _light = "#lightpoint" createVehicleLocal (_pos vectorAdd [0, 0, 1]);
		_light setLightColor [0.4, 0.7, 1];
		_light setLightAmbient [0.2, 0.4, 0.8];
		_light setLightBrightness 6;
		private _snd = "A3\Sounds_F\sfx\special_sfx\sparkles_wreck_1.wss";
		if (fileExists _snd) then { playSound3D [_snd, objNull, false, AGLToASL _pos, 2, 1, 200, 0, true]; };
		[_smoke, _light] spawn {
			params ["_smoke", "_light"];
			sleep 0.25; deleteVehicle _light;
			sleep 10; deleteVehicle _smoke;
		};
	};
	if (player distance _obj <= _fall + 300 && {!isNil "HUD_fnc_addSystemMessage"}) then {
		private _verb = ["DISABLED", "DESTROYED"] select (_how == "destroyed");
		[format ["<t color='#3cb371' font='PuristaBold'>JAMMER %1</t> by %2", _verb, _by], "bpdJamKill", 8] call HUD_fnc_addSystemMessage;
	};
};

BPD_CloneHUD_fnc_jamCanDisable = {
	params ["_obj"];
	private _who = (_obj getVariable ["BPD_CloneHUD_jamDevice", [10, 8, 0]]) param [2, 0];
	_who == 0 || {isNil "BPD_CloneHUD_fnc_isEngineer"} || {call BPD_CloneHUD_fnc_isEngineer}
};

BPD_CloneHUD_fnc_jamDisableDone = {
	params ["_obj"];
	[_obj, "disabled"] call BPD_CloneHUD_fnc_jamDeviceKill;
	if (_obj isKindOf "Land_DataTerminal_01_F" && {!isNil "BIS_fnc_dataTerminalAnimate"}) then { [_obj, 0] call BIS_fnc_dataTerminalAnimate; };
};

// Local, once per device per client: hit tracking + disable action.
BPD_CloneHUD_fnc_jamDeviceSetup = {
	params ["_obj"];
	if (_obj getVariable ["BPD_CloneHUD_jdSetup", false]) exitWith {};
	_obj setVariable ["BPD_CloneHUD_jdSetup", true]; // local flag

	_obj addEventHandler ["HitPart", {
		(_this select 0) params ["_target", "_shooter", "_proj", "_pos", "_vel", "_sel", "_ammo"];
		if (_target getVariable ["BPD_CloneHUD_jamDead", false]) exitWith {};
		_ammo params [["_hit", 0], ["_ind", 0], ["_indR", 0], ["_expl", 0]];
		private _max = (_target getVariable ["BPD_CloneHUD_jamDevice", [10]]) param [0, 10];
		private _add = if (_expl > 0.5 && {_ind > 0}) then {_max} else {1};
		private _hits = (_target getVariable ["BPD_CloneHUD_jamHits", 0]) + _add;
		_target setVariable ["BPD_CloneHUD_jamHits", _hits, true];
		if (_hits >= _max) then { [_target, "destroyed"] call BPD_CloneHUD_fnc_jamDeviceKill; };
	}];

	private _time = (_obj getVariable ["BPD_CloneHUD_jamDevice", [10, 8, 0]]) param [1, 8];
	if (!isNil "ace_interact_menu_fnc_createAction") then {
		private _act = ["BPD_jamDisable", "Disable Jammer", "\A3\ui_f\data\IGUI\Cfg\Actions\repair_ca.paa", {
			params ["_target"];
			private _t = (_target getVariable ["BPD_CloneHUD_jamDevice", [10, 8, 0]]) param [1, 8];
			[_t, [_target], { [(_this select 0) select 0] call BPD_CloneHUD_fnc_jamDisableDone; }, {}, "Disabling jammer..."] call ace_common_fnc_progressBar;
		}, {
			params ["_target"];
			!(_target getVariable ["BPD_CloneHUD_jamDead", false]) && {[_target] call BPD_CloneHUD_fnc_jamCanDisable}
		}, {}, [], [0, 0, 0], 3] call ace_interact_menu_fnc_createAction;
		[_obj, 0, [], _act] call ace_interact_menu_fnc_addActionToObject;
	} else {
		[_obj, "Disable Jammer", "\A3\ui_f\data\IGUI\Cfg\holdactions\holdAction_hack_ca.paa", "\A3\ui_f\data\IGUI\Cfg\holdactions\holdAction_hack_ca.paa",
			"_this distance _target < 3 && {!(_target getVariable ['BPD_CloneHUD_jamDead', false])} && {[_target] call BPD_CloneHUD_fnc_jamCanDisable}",
			"true", {}, {}, { [_this select 0] call BPD_CloneHUD_fnc_jamDisableDone; }, {}, [], _time, 10, true, false] call BIS_fnc_holdActionAdd;
	};
	if (_obj isKindOf "Land_DataTerminal_01_F" && {!isNil "BIS_fnc_dataTerminalAnimate"}) then { [_obj, 3] call BIS_fnc_dataTerminalAnimate; };
};

// Every jam tick: set up new devices, catch destroyed objects, and arm
// placed charges next to a device so their explosion kills it.
BPD_CloneHUD_fnc_jamDeviceTick = {
	{
		private _o = _x;
		if (!isNull _o && {count (_o getVariable ["BPD_CloneHUD_jamDevice", []]) > 0} && {!(_o getVariable ["BPD_CloneHUD_jamDead", false])}) then {
			[_o] call BPD_CloneHUD_fnc_jamDeviceSetup;
			if (!(_o isKindOf "HeliH") && {!alive _o || {damage _o >= 0.9}}) exitWith { [_o, "destroyed"] call BPD_CloneHUD_fnc_jamDeviceKill; };
			{
				if !(_x getVariable ["BPD_CloneHUD_jdArmed", false]) then {
					_x setVariable ["BPD_CloneHUD_jdArmed", true];
					_x addEventHandler ["Explode", { call BPD_CloneHUD_fnc_jamExplode; }];
				};
			} forEach (allMines select { _x distance _o < 6 });
		};
	} forEach (BPD_CloneHUD_jammers + BPD_CloneHUD_jamEden);
};

// Explode EH on projectiles / charges: kill any device in the blast.
BPD_CloneHUD_fnc_jamExplode = {
	params ["_proj", "_posASL"];
	private _r = (getNumber (configOf _proj >> "indirectHitRange")) max 2.5;
	{
		if (!isNull _x && {count (_x getVariable ["BPD_CloneHUD_jamDevice", []]) > 0} && {(getPosASL _x) distance _posASL <= _r + 1}) then {
			[_x, "destroyed"] call BPD_CloneHUD_fnc_jamDeviceKill;
		};
	} forEach (BPD_CloneHUD_jammers + BPD_CloneHUD_jamEden);
};

// Eden devices: object init sets the variables locally on every machine;
// pick them up once after mission start.
BPD_CloneHUD_fnc_jamDeviceScan = {
	{
		if (count (_x getVariable ["BPD_CloneHUD_jammer", []]) > 0) then { BPD_CloneHUD_jamEden pushBackUnique _x; };
	} forEach (allMissionObjects "All");
};

if (hasInterface && {!isNil "zen_custom_modules_fnc_register"} && {isNil "BPD_CloneHUD_zenJamAdded"}) then {
	BPD_CloneHUD_zenJamAdded = true;
	["885th Clone HUD", "Add HUD Jammer", {
		params ["_posASL", "_obj"];
		["Add HUD Jammer", [
			["SLIDER", ["Falloff radius (m)", "Jamming starts here and gets stronger inward."], [50, 3000, 600, 0]],
			["SLIDER", ["Effective radius (m)", "Fully jammed inside this radius."], [0, 2000, 200, 0]]
		], {
			params ["_values", "_args"];
			_values params ["_fall", "_eff"];
			_args params ["_posASL", "_obj"];
			if (isNull _obj) then {
				_obj = createVehicle ["Land_HelipadEmpty_F", ASLToAGL _posASL, [], 0, "CAN_COLLIDE"];
				_obj setVariable ["BPD_CloneHUD_jamPad", true, true];
			};
			[_obj, _fall, _eff] call BPD_CloneHUD_fnc_jamAdd;
			["Jammer added: %1 m falloff, %2 m full", round _fall, round _eff] call zen_common_fnc_showMessage;
		}, {}, [_posASL, _obj]] call zen_dialog_fnc_create;
	}] call zen_custom_modules_fnc_register;
	// A physical jammer troopers have to find and kill to get their HUD back.
	["885th Clone HUD", "Place Jammer Device", {
		params ["_posASL", "_obj"];
		private _types = [
			["Land_DataTerminal_01_F", "Data terminal (opens up)"],
			["Land_Device_assembled_F", "Assembled device"],
			["Land_SatelliteAntenna_01_F", "Satellite antenna"],
			["Land_PortableServer_01_black_F", "Portable server"],
			["Land_MultiScreenComputer_01_black_F", "Computer stack"],
			["Land_Portable_generator_F", "Generator"],
			["Land_TTowerSmall_1_F", "Small radio mast"]
		] select { isClass (configFile >> "CfgVehicles" >> (_x select 0)) };
		private _vals = _types apply { _x select 0 };
		private _names = _types apply { _x select 1 };
		if (!isNull _obj) then { _vals = ["<selected>"] + _vals; _names = [format ["This object (%1)", getText (configOf _obj >> "displayName")]] + _names; };
		["Place Jammer Device", [
			["COMBO", ["Device", "What the jammer looks like."], [_vals, _names, 0]],
			["EDIT", ["Custom classname", "Optional - any CfgVehicles class (e.g. a SW prop). Overrides Device."], [""]],
			["SLIDER", ["Falloff radius (m)", "Jamming starts here and gets stronger inward."], [50, 3000, 600, 0]],
			["SLIDER", ["Effective radius (m)", "Fully jammed inside this radius."], [0, 2000, 200, 0]],
			["SLIDER", ["Hits to destroy", "Direct hits it takes. Any explosive (grenade, rocket, charge) kills it outright."], [1, 50, 10, 0]],
			["SLIDER", ["Disable time (s)", "How long 'Disable Jammer' takes at the device."], [2, 60, 8, 0]],
			["COMBO", ["Who can disable it", ""], [[0, 1], ["Anyone", "Engineers / EOD only"], 0]]
		], {
			params ["_values", "_args"];
			_values params ["_type", "_custom", "_fall", "_eff", "_hits", "_time", "_who"];
			_args params ["_posASL", "_obj"];
			_custom = (_custom splitString " ") joinString "";
			private _dev = if (_type == "<selected>" && {_custom == ""}) then {_obj} else {
				private _cls = [_type, _custom] select (_custom != "");
				if (!isClass (configFile >> "CfgVehicles" >> _cls)) exitWith { [format ["Unknown class: %1", _cls]] call zen_common_fnc_showMessage; objNull };
				private _o = createVehicle [_cls, ASLToAGL _posASL, [], 0, "CAN_COLLIDE"];
				_o setPosASL _posASL;
				["zen_common_addObjects", [[_o]]] call CBA_fnc_serverEvent; // Zeus-editable
				_o
			};
			if (isNull _dev) exitWith {};
			_dev setVariable ["BPD_CloneHUD_jamDevice", [round _hits, round _time, _who], true];
			_dev setVariable ["BPD_CloneHUD_jamHits", 0, true];
			_dev setVariable ["BPD_CloneHUD_jamDead", false, true];
			[_dev, _fall, _eff] call BPD_CloneHUD_fnc_jamAdd;
			["Jammer device placed: %1 m falloff, %2 hits", round _fall, round _hits] call zen_common_fnc_showMessage;
		}, {}, [_posASL, _obj]] call zen_dialog_fnc_create;
	}] call zen_custom_modules_fnc_register;

	["885th Clone HUD", "Remove HUD Jammer", {
		params ["_posASL", "_obj"];
		private _target = _obj;
		if (isNull _target || {(_target getVariable ["BPD_CloneHUD_jammer", []]) isEqualTo []}) then {
			// nearest jammer to where the module was dropped
			private _list = BPD_CloneHUD_jammers select { !isNull _x };
			_list = [_list, [], { _x distance (ASLToAGL _posASL) }, "ASCEND"] call BIS_fnc_sortBy;
			_target = _list param [0, objNull];
		};
		if (isNull _target) exitWith { ["No HUD jammer found"] call zen_common_fnc_showMessage; };
		[_target] call BPD_CloneHUD_fnc_jamRemove;
		["HUD jammer removed"] call zen_common_fnc_showMessage;
	}] call zen_custom_modules_fnc_register;
};

if (hasInterface) then {
	[] spawn {
		waitUntil { sleep 1; !isNull player };
		// grenades / launcher rounds fired here: arm an Explode check when a
		// jammer device is anywhere nearby
		addMissionEventHandler ["ProjectileCreated", {
			params ["_proj"];
			if (!local _proj) exitWith {}; // only the shooter's machine reports it
			if (count (BPD_CloneHUD_jammers + BPD_CloneHUD_jamEden) == 0) exitWith {};
			if (getNumber (configOf _proj >> "indirectHit") <= 0) exitWith {};
			if ((BPD_CloneHUD_jammers + BPD_CloneHUD_jamEden) findIf { !isNull _x && {_x distance _proj < 600} } < 0) exitWith {};
			_proj addEventHandler ["Explode", { call BPD_CloneHUD_fnc_jamExplode; }];
		}];
		[] spawn { sleep 5; call BPD_CloneHUD_fnc_jamDeviceScan; };
		while {true} do {
			call BPD_CloneHUD_fnc_jamTick;
			call BPD_CloneHUD_fnc_jamDeviceTick;
			sleep 0.5;
		};
	};
};
