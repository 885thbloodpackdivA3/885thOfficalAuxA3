/*
	885th Bloodpack Division - Clone HUD - Downed haywire / fast restore
	---------------------------------------------------------------
	While the player is down (ACE unconscious or vanilla incapacitated)
	with the HUD up, the HUD glitches: random elements drop out and
	flicker back, the odd full blackout frame, glitch sounds, and a
	"SUIT SYSTEMS FAILING" message. When they come back up the HUD does a
	fast reboot - everything blanks, then the layers come back one after
	another in about a second with a short system check message.

	BPD_CloneHUD_DOWN_FX (per player, "1. What's On Screen") turns it off.
	Each control's own fade is saved first and put back afterwards, so
	panels that were faded out (kill counter, intel log...) stay that way.
*/

BPD_CloneHUD_downDisplays = ["BPD_CloneHUD_OVERLAY_BASE", "BPD_CloneHUD_INDICATOR_BASE", "HUD_INFO"];

BPD_CloneHUD_fnc_downIsDown = {
	alive player && {(player getVariable ["ACE_isUnconscious", false]) || {lifeState player == "INCAPACITATED"}}
};

BPD_CloneHUD_fnc_downHudUp = {
	alive player && {player getVariable ["HUD_bootComplete", false]} && {missionNamespace getVariable ["HUD_hasHelmet", false]}
};

// every control on the HUD layers, grouped by layer (draw order)
BPD_CloneHUD_fnc_downCtrls = {
	BPD_CloneHUD_downDisplays apply {
		private _d = uiNamespace getVariable [_x, displayNull];
		if (isNull _d) then { [] } else { allControls _d }
	}
};

BPD_CloneHUD_fnc_downSave = {
	{ { _x setVariable ["bpdFade0", ctrlFade _x]; } forEach _x; } forEach (call BPD_CloneHUD_fnc_downCtrls);
};

BPD_CloneHUD_fnc_downRestoreNow = {
	BPD_CloneHUD_downDimmed = false;
	{
		{
			_x ctrlSetFade (_x getVariable ["bpdFade0", 0]);
			_x ctrlCommit 0;
		} forEach _x;
	} forEach (call BPD_CloneHUD_fnc_downCtrls);
};

// one haywire frame
// Flashing Effects setting: 0 off (no flicker), 1 reduced, 2 full
BPD_CloneHUD_fnc_flashMode = {
	(missionNamespace getVariable ["BPD_CloneHUD_FLASH", 1]) min 2 max 0
};

BPD_CloneHUD_fnc_downGlitch = {
	private _mode = call BPD_CloneHUD_fnc_flashMode;
	private _layers = call BPD_CloneHUD_fnc_downCtrls;
	// Off: one steady dim, no changes after that
	if (_mode == 0) exitWith {
		if (missionNamespace getVariable ["BPD_CloneHUD_downDimmed", false]) exitWith {};
		BPD_CloneHUD_downDimmed = true;
		{ { _x ctrlSetFade ((_x getVariable ["bpdFade0", 0]) max 0.55); _x ctrlCommit 0.6; } forEach _x; } forEach _layers;
	};
	private _blackout = _mode == 2 && {random 1 < 0.06};
	private _drop = [0, 0.05, 0.12] select _mode;
	private _dim = [0, 0.2, 0.30] select _mode;
	private _commit = [0, 0.35, 0] select _mode;   // reduced: smooth fades, no hard cuts
	{
		{
			private _base = _x getVariable ["bpdFade0", 0];
			private _f = call {
				if (_blackout) exitWith {1};
				private _r = random 1;
				if (_r < _drop) exitWith {[1, _base max 0.8] select (_mode == 1)}; // drops out
				if (_r < _dim) exitWith {_base max (0.4 + random 0.4)};          // dims
				_base
			};
			_x ctrlSetFade _f;
			_x ctrlCommit _commit;
		} forEach _x;
	} forEach _layers;
	if (random 1 < ([0, 0.02, 0.035] select _mode)) then { playSound "glitch_short"; };
};

// fast restore: blank, then each layer back in turn
BPD_CloneHUD_fnc_downReboot = {
	[] spawn {
		private _layers = call BPD_CloneHUD_fnc_downCtrls;
		private _mode = call BPD_CloneHUD_fnc_flashMode;
		BPD_CloneHUD_downDimmed = false;
		// full: hard blank; reduced / off: quick fade down instead of a cut
		{ { _x ctrlSetFade 1; _x ctrlCommit ([0.3, 0.2, 0] select _mode); } forEach _x; } forEach _layers;
		["<t color='#ffb347'>REBOOTING SUIT SYSTEMS...</t>", "bpdDownFx", 6] call HUD_fnc_addSystemMessage;
		playSound "glitch_short";
		sleep 0.35;
		private _steps = ["VISOR DISPLAY", "VITALS MONITOR", "TACTICAL DATA"];
		{
			private _layer = _x;
			{
				_x ctrlSetFade (_x getVariable ["bpdFade0", 0]);
				_x ctrlCommit ([0.35, 0.25, 0.15] select _mode);
			} forEach _layer;
			[format ["<t color='#ffb347'>REBOOT</t> %1 ... <t color='#3cb371'>OK</t>", _steps param [_forEachIndex, "SYSTEMS"]], "bpdDownFx", 6] call HUD_fnc_addSystemMessage;
			playSound "click";
			sleep 0.28;
		} forEach _layers;
		["<t color='#3cb371' font='PuristaBold'>SUIT SYSTEMS RESTORED</t>", "bpdDownFx", 6] call HUD_fnc_addSystemMessage;
		BPD_CloneHUD_downRebooting = false;
	};
};

// ------------------------------------------------------------
//  KIA: helm-cam style signal loss over the whole visor
// ------------------------------------------------------------
// Killed with the HUD up: static builds over the screen ("VITAL SIGNS
// LOST"), holds as full static ("SIGNAL LOST"), then fades out. Same noise
// frames as the helm cam feed. Aborts if you respawn first.
BPD_CloneHUD_fnc_kiaStatic = {
	params ["_unit"];
	if (missionNamespace getVariable ["BPD_CloneHUD_kiaRunning", false]) exitWith {};
	BPD_CloneHUD_kiaRunning = true;
	[_unit] spawn {
		params ["_unit"];
		"BPD_CloneHUD_KIA_LAYER" cutRsc ["BPD_CloneHUD_KIA_BASE", "PLAIN", -1, false];
		private _d = uiNamespace getVariable ["BPD_CloneHUD_KIA_BASE", displayNull];
		if (isNull _d) exitWith { BPD_CloneHUD_kiaRunning = false; };
		private _pic = _d ctrlCreate ["RscPicture", 27740];
		_pic ctrlSetPosition [safezoneX, safezoneY, safezoneW, safezoneH];
		_pic ctrlCommit 0;
		private _txt = _d ctrlCreate ["RscStructuredText", 27741];
		_txt ctrlSetPosition [safezoneX, safezoneY + safezoneH * 0.46, safezoneW, safezoneH * 0.08];
		_txt ctrlSetBackgroundColor [0, 0, 0, 0];
		_txt ctrlCommit 0;
		private _size = safezoneH / 0.75;
		// Flashing Effects: full swaps noise frames every tick with alpha
		// jitter and flickering text; reduced swaps ~2.5x a second, steady
		// text; off keeps one still frame and only ramps it smoothly.
		private _mode = call BPD_CloneHUD_fnc_flashMode;
		private _swapEvery = [1e9, 0.4, 0] select _mode;
		private _lastSwap = -1e9;
		private _frame = {
			params ["_a"];
			if (diag_tickTime - _lastSwap >= _swapEvery || {ctrlText _pic == ""}) then {
				_lastSwap = diag_tickTime;
				_pic ctrlSetText format ["\885th_CloneHUD\textures\hcam\kia_static_%1_ca.paa", 1 + floor random 4];
			};
			_pic ctrlSetTextColor [1, 1, 1, _a];
		};
		private _jit = { if (_mode == 2) then { 0.7 + random 0.3 } else { 1 } };
		private _say = {
			params ["_t", "_col", "_a"];
			if (_mode < 2) then { _a = [_a, 1] select (_a > 0); };   // no text flicker
			_txt ctrlSetStructuredText parseText format ["<t align='center' size='%1' font='PuristaBold' color='%2'>%3</t>", _size, _col, _t];
			_txt ctrlSetTextColor [1, 1, 1, _a];
		};
		private _gone = { player != _unit };   // respawned
		playSound "glitch_short";
		private _flat = playSound "BPD_CloneHUD_flatline"; // low flatline under the static (3.4 s, fades itself)
		// 1) breaking up
		private _end = diag_tickTime + 1.0;
		while { diag_tickTime < _end && {!(call _gone)} } do {
			private _k = 1 - ((_end - diag_tickTime) / 1.0);
			[(0.2 + 0.65 * _k) * (call _jit)] call _frame;
			["VITAL SIGNS LOST", "#ffb347", [1, 0.3] select (random 1 < 0.25)] call _say;
			sleep 0.06;
		};
		// 2) signal lost
		if (!(call _gone) && {_mode > 0}) then { playSound "glitch_short"; };
		_end = diag_tickTime + 1.4;
		while { diag_tickTime < _end && {!(call _gone)} } do {
			[0.92] call _frame;
			["SIGNAL LOST", "#ff3b30", [1, 0.5] select (random 1 < 0.15)] call _say;
			sleep 0.06;
		};
		// 3) fade out
		["", "#ffffff", 0] call _say;
		_end = diag_tickTime + 0.8;
		while { diag_tickTime < _end && {!(call _gone)} } do {
			[0.92 * ((_end - diag_tickTime) / 0.8)] call _frame;
			sleep 0.06;
		};
		"BPD_CloneHUD_KIA_LAYER" cutText ["", "PLAIN", 0, false];
		if (call _gone && {!isNil "_flat"} && {_flat isEqualType objNull} && {!isNull _flat}) then { deleteVehicle _flat; }; // respawned mid-way: cut it
		BPD_CloneHUD_kiaRunning = false;
	};
};

if (isNil "BPD_CloneHUD_kiaEH") then {
	BPD_CloneHUD_kiaEH = addMissionEventHandler ["EntityKilled", {
		params ["_unit"];
		if (_unit != player || {!hasInterface}) exitWith {};
		if !(missionNamespace getVariable ["BPD_CloneHUD_KIA_FX", true]) exitWith {};
		// only if the HUD was actually up when they died
		if !((_unit getVariable ["HUD_bootComplete", false]) && {missionNamespace getVariable ["HUD_hasHelmet", false]}) exitWith {};
		[_unit] call BPD_CloneHUD_fnc_kiaStatic;
	}];
};

// Session loop (survives respawn).
if (isNil "BPD_CloneHUD_downLoop") then {
	BPD_CloneHUD_downState = 0;          // 0 normal, 1 haywire
	BPD_CloneHUD_downRebooting = false;
	BPD_CloneHUD_downLoop = [] spawn {
		waitUntil { sleep 1; !isNull player };
		while {true} do {
			private _on = missionNamespace getVariable ["BPD_CloneHUD_DOWN_FX", true];
			private _down = call BPD_CloneHUD_fnc_downIsDown;
			private _hud = call BPD_CloneHUD_fnc_downHudUp;
			switch (BPD_CloneHUD_downState) do {
				case 0: {
					if (_on && {_down} && {_hud} && {!BPD_CloneHUD_downRebooting}) then {
						BPD_CloneHUD_downState = 1;
						call BPD_CloneHUD_fnc_downSave;
						playSound "glitch_short";
						["<t color='#ff3b30' font='PuristaBold'>SUIT SYSTEMS FAILING</t> - vitals critical", "bpdDownFx", 30] call HUD_fnc_addSystemMessage;
					};
				};
				case 1: {
					if (!alive player || {!_hud} || {!_on}) then {
						// died / HUD went down / turned off - just put it back
						// (an EMP outage owns the HUD fades itself - leave them)
						if !(missionNamespace getVariable ["BPD_CloneHUD_empOffline", false]) then { call BPD_CloneHUD_fnc_downRestoreNow; };
						BPD_CloneHUD_downState = 0;
					} else {
						if (_down) then {
							call BPD_CloneHUD_fnc_downGlitch;
						} else {
							BPD_CloneHUD_downState = 0;
							BPD_CloneHUD_downRebooting = true;
							call BPD_CloneHUD_fnc_downReboot;
						};
					};
				};
			};
			// haywire tick: full ~7/s, reduced ~2/s, off just polls
			sleep (if (BPD_CloneHUD_downState == 1) then {
				[0.5, 0.45 + random 0.2, 0.09 + random 0.08] select (call BPD_CloneHUD_fnc_flashMode)
			} else {0.5});
		};
	};
};
