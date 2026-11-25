HUD_fnc_clearHud = {
	private _hudElements = [
		(HUD_interiorOverlay#0),
		(HUD_trooperBase#0),
		(HUD_pa_head#0),
		(HUD_pa_torso#0),
		(HUD_pa_armR#0),
		(HUD_pa_armL#0),
		(HUD_pa_legR#0),
		(HUD_pa_legL#0),
		(HUD_infoDisplay#0),
		(HUD_infoAmmo#0),
		(HUD_infoMags#0),
		(HUD_infoDir#0),
		(HUD_infoRange#0),
		(HUD_visorEffect#0)
	];
	[_hudElements] spawn {
		private _hudElements = _this select 0;
		{_x ctrlSetTextColor [0,0,0,0]} forEach _hudElements;
	};
	
	private _P2hudElements = [
		(HUD_interiorOverlay#0),
		(HUD_trooperBase#0),
		(HUD_pa_head#0),
		(HUD_pa_torso#0),
		(HUD_pa_armR#0),
		(HUD_pa_armL#0),
		(HUD_pa_legR#0),
		(HUD_pa_legL#0),
		(P2_infoDisplay#0),
		(P2_infoAmmo#0),
		(P2_infoMags#0),
		(P2_infoDir#0),
		(P2_infoRange#0),
		(HUD_visorEffect#0)
	];
	
	[_P2hudElements] spawn {
		private _P2hudElements = _this select 0;
		{_x ctrlSetTextColor [0,0,0,0]} forEach _P2hudElements;
	};
	
	private _RChudElements = [
		(HUD_interiorOverlay#0),
		(HUD_trooperBase#0),
		(HUD_pa_head#0),
		(HUD_pa_torso#0),
		(HUD_pa_armR#0),
		(HUD_pa_armL#0),
		(HUD_pa_legR#0),
		(HUD_pa_legL#0),
		(RC_infoDisplay#0),
		(RC_infoAmmo#0),
		(RC_infoMags#0),
		(RC_infoDir#0),
		(RC_infoRange#0),
		(HUD_visorEffect#0)
	];
	
	[_RChudElements] spawn {
		private _RChudElements = _this select 0;
		{_x ctrlSetTextColor [0,0,0,0]} forEach _RChudElements;
	};
	
	player setvariable ["HUD_ACTIVE", false];
	player setvariable ["HUD_ALLOWED", false];
	player setVariable ["HUD_hudInitiated",false];
	player setVariable ["HUD_indicatorsActive",false];
	player setvariable ["HUD_TARGETING_ALLOWED", false];
	player setVariable ["HUD_bootComplete", false];
	HUD_systemMessageAllowed = false;
	(HUD_bootUpTextField#0) ctrlSetStructuredText parseText "";
	(HUD_teamList#0) ctrlSetStructuredText parseText "";
	(HUD_radarBackground#0) ctrlSetTextColor [0,0,0,0];
	(HUD_radarBackground#0) ctrlSetBackgroundColor [0,0,0,0];
	if (!isNil "BPD_CloneHUD_fnc_ammoHide") then { call BPD_CloneHUD_fnc_ammoHide; BPD_CloneHUD_ammoShownStyle = 0; };
	{ _x ctrlSetTextColor [0,0,0,0]; } forEach HUD_radarBlips;
	HUD_lowLight = false;
	HUD_threatRange = 200;
	HUD_nearUnits = [];
	if (!(headgear player in HUD_helmets)) then {
		call HUD_fnc_removeHudEventhandler;
	};
	call HUD_fnc_removeTargetingEventhandler;
	setAperture -1;
};

HUD_fnc_hudBootUp = {
	//if (!(HUD_hasHelmet && HUD_firstPersonCheck)) exitWith {};

	// Every control handle this function touches (HUD_interiorOverlay,
	// HUD_startUpImage, HUD_bootUpTextField, etc.) only exists after
	// HUD_fnc_hudInit has actually run. Under normal auto-start that's
	// guaranteed by HUD_suit_activation running first - but the
	// "Activate HUD" action can also call this directly, and its
	// visibility condition doesn't check whether hudInit has finished.
	// A player who opens the scroll menu quickly (very easy to do in
	// Eden preview) can win that race and call this against controls
	// that don't exist yet, which throws exactly this "Undefined
	// variable" cascade. Make hudInit idempotent-guaranteed here instead
	// of trusting the caller to have sequenced it correctly.
	if (isNil "HUD_interiorOverlay") then {
		call HUD_fnc_hudInit;
	};

	player setvariable ["HUD_ACTIVE", false];
	player setvariable ["HUD_ALLOWED", true];
	player setVariable ["HUD_hudInitiated",true];
	HUD_systemMessageAllowed = false;

	call HUD_fnc_removeTargetingEventhandler;

	private _hudElements = [
		(HUD_interiorOverlay#0),
		(HUD_trooperBase#0),
		(HUD_pa_head#0),
		(HUD_pa_torso#0),
		(HUD_pa_armR#0),
		(HUD_pa_armL#0),
		(HUD_pa_legR#0),
		(HUD_pa_legL#0),
		(HUD_infoDisplay#0),
		(HUD_infoAmmo#0),
		(HUD_infoMags#0),
		(HUD_infoDir#0),
		(HUD_infoRange#0),
		(HUD_visorEffect#0)
	];
	{_x ctrlSetTextColor [0,0,0,0]} forEach _hudElements;
	
	private _P2hudElements = [
		(HUD_interiorOverlay#0),
		(HUD_trooperBase#0),
		(HUD_pa_head#0),
		(HUD_pa_torso#0),
		(HUD_pa_armR#0),
		(HUD_pa_armL#0),
		(HUD_pa_legR#0),
		(HUD_pa_legL#0),
		(P2_infoDisplay#0),
		(P2_infoAmmo#0),
		(P2_infoMags#0),
		(P2_infoDir#0),
		(P2_infoRange#0),
		(HUD_visorEffect#0)
	];
	{_x ctrlSetTextColor [0,0,0,0]} forEach _P2hudElements;

	_chapterID = CHAPTER_NAME;
	if (_chapterID == "") then {
		_chapterID = "[REDACTED]";
	};

	private _RChudElements = [
		(HUD_interiorOverlay#0),
		(HUD_trooperBase#0),
		(HUD_pa_head#0),
		(HUD_pa_torso#0),
		(HUD_pa_armR#0),
		(HUD_pa_armL#0),
		(HUD_pa_legR#0),
		(HUD_pa_legL#0),
		(RC_infoDisplay#0),
		(RC_infoAmmo#0),
		(RC_infoMags#0),
		(RC_infoDir#0),
		(RC_infoRange#0),
		(HUD_visorEffect#0)
	];
	
	[_RChudElements] spawn {
		private _RChudElements = _this select 0;
		{_x ctrlSetTextColor [0,0,0,0]} forEach _RChudElements;
	};

	///////////////////////////////////
	/*
		To input an empty line, put "&#160;" in the first string.
	*/
	///////////////////////////////////

	_iteration = 0;
	private _input = "";
	private _bootupText = [];

	if (BOOTUP_OVERWRITE_TEXT && !isnil "HUD_bootText") then {
		_bootupText = HUD_bootText;
	} else {
		_bootupText = [
			["",0.0,"",0.3, _input, _input],
			["GALACTIC REPUBLIC MILITARY ",0.1,"",0.3, _input, _input],
			// Unit line - driven by the CHAPTER_NAME CBA setting
			// (default "885th Bloodpack Division"). _chapterID was already
			// read above but never shown before; this line used to be a
			// hardcoded "CLONE INTELLIGENCE DIVISION".
			["%1 ",0.1,"",0.5, toUpper _chapterID, _input],
			["&#160;",0.1,"",0.2, _input, _input],
			["Tactical HUD interface initializing",0.05,"... ",0.4, _input, _input],
			["Visor calibration",0.05," nominal. ",0.3, _input, _input],
			["Biometric scan",0.05," complete. ",0.3, _input, _input],
			["Comm-link",0.05," synced. ",0.3, _input, _input],
			["Threat scanner",0.05," online. ",0.4, _input, _input],
			["&#160;",0.1,"",0.2, _input, _input],
			["Trooper",0.05," [%1] ",0.3, _input, name player],
			["Armor class",0.05," [%1] ",0.3, _input, HUD_SUIT_LABEL],
			["&#160;",0.1,"",0.2, _input, _input],
			["All systems nominal. ",0.05,"",0.5, _input, _input],
			["&#160;",0.1,"",0.3, _input, _input],
			["For the Republic.",0.1,"",2.1, _input, _input]
		];
	};

	private _textField = (HUD_bootUpTextField#0);
	private _startUpImage = (HUD_startUpImage#0);
	private _accumulatedText = "";
	private _offset = -HUD_BOOT_OFFSET * safezoneH;
	private _textPos = [0.15 * safezoneW,0.30 * safezoneH,0.70 * safezoneW,0.6 * safezoneH];
	private _textScale = safezoneH / 1.81818;
	private _letterDelay = 0.0001;
	private _hexChars = "0123456789ABCDEF";
	private _colorToHexByte = {
		params ["_byte"];
		private _hi = floor (_byte / 16);
		private _lo = _byte mod 16;
		(_hexChars select [_hi,1]) + (_hexChars select [_lo,1])
	};
	private _structuredTextColorHex = "#" + ([round ((INTERIOR_OVERLAY_COLOR select 0) * 255)] call _colorToHexByte) + ([round ((INTERIOR_OVERLAY_COLOR select 1) * 255)] call _colorToHexByte) + ([round ((INTERIOR_OVERLAY_COLOR select 2) * 255)] call _colorToHexByte);
	private _structuredText = "<t align='left' color='" + _structuredTextColorHex + "'" + format [" size='%1'>",_textScale] + "%1</t>";
	
	private _color1R = INTERIOR_OVERLAY_COLOR select 0;
	private _color1G = INTERIOR_OVERLAY_COLOR select 1;
	private _color1B = INTERIOR_OVERLAY_COLOR select 2;
	private _color1A = INTERIOR_OVERLAY_COLOR select 3;
	private _removeAlpha = _color1A / 10;

	private _startImage = HUD_START_IMAGE;
	private _startImageGlitched = HUD_START_IMAGE_GLITCHED;

	private _effectColor = [_color1R,_color1G,_color1B,_color1A];
	_textField ctrlSetTextColor INTERIOR_OVERLAY_COLOR;
	(HUD_visorEffect#0) ctrlSetTextColor [1,1,1,0.3];

	_iterations = 0;
	_indicatorLine = parseNumber BOOTUP_INDICATOR_LINE;
	_auspexLine = parseNumber BOOTUP_SCANNER_LINE;
	playsound "typing_1";
	_startUpImage ctrlSetTextColor _effectColor;
	sleep 1;
	playsound "glitch";
	_startUpImage ctrlSetText _startImageGlitched;
	sleep 0.5;
	_startUpImage ctrlSetText _startImage;
	sleep 0.3;
	playsound "glitch_short";
	_startUpImage ctrlSetText _startImageGlitched;
	sleep 0.2;
	_startUpImage ctrlSetText _startImage;
	sleep 1;
	for "_i" from 0 to 9 do {
		_effectColor set[3,(_effectColor select 3) - _removeAlpha];
		if (HUD_hasHelmet && HUD_firstPersonCheck) then {
			_startUpImage ctrlSetTextColor _effectColor;
		} else {
			_startUpImage ctrlSetTextColor [0,0,0,0];
		};
		sleep 0.1;
	};
	_startUpImage ctrlSetTextColor [0,0,0,0];
	//};
	
	sleep 0.5;
	_textField ctrlCommit 0;
	diag_log format ["885th_CloneHUD: typing loop starting, %1 entries (BOOTUP_OVERWRITE_TEXT=%2).", count _bootupText, BOOTUP_OVERWRITE_TEXT];
	{
		scopeName "textLoop";
		if (!HUD_hasHelmet OR !(player getVariable ["HUD_hudInitiated",false])) exitWith {
			diag_log format ["885th_CloneHUD: typing loop breaking out early at iteration %1 - HUD_hasHelmet=%2, HUD_hudInitiated=%3.", _iterations, HUD_hasHelmet, (player getVariable ["HUD_hudInitiated",false])];
			breakOut "textLoop";
		};

		if (count _x < 6) exitWith {
			diag_log format ["885th_CloneHUD: HUD_bootText entry %1 has %2 elements (need 6: [prefix, delay, suffix, delay, input1, input2]) - skipping it instead of crashing the boot sequence.", _iterations, count _x];
			_iterations = _iterations + 1;
		};

		_string1 = format [(_x select 0), (_x select 4)] splitstring "";
		_string2 = format [(_x select 2), (_x select 5)] splitstring "";

		// One list item per entry - added whole, not typed character by
		// character (typing "<br/>" one letter at a time would show
		// broken literal tags like "<b" mid-type).
		if (_iterations > 0) then {
			_accumulatedText = _accumulatedText + "<br/>";
		};

		{
			_accumulatedText = _accumulatedText + _x;
			_textField ctrlSetStructuredText parseText format [_structuredText, _accumulatedText];
			if (_x != "") then { playSound "typing_1"; };
			sleep _letterDelay;
		} forEach _string1;

		sleep (_x select 1);

		{
			// Suffix characters actually get appended now - previously
			// this loop just re-rendered the same (unchanged)
			// _accumulatedText repeatedly without ever adding _x, so
			// every suffix (status text, name/armor substitutions)
			// silently never appeared.
			_accumulatedText = _accumulatedText + _x;
			_textField ctrlSetStructuredText parseText format [_structuredText, _accumulatedText];
			if (_x != "") then { playSound "typing_1"; };
			sleep _letterDelay;
		} forEach _string2;
		sleep (_x select 3);
		

		

		if (_iterations > 15) then {
			_textPos set [1, (_textPos select 1) + _offset];
			_textField ctrlSetPosition _textPos;
			_textField ctrlCommit 0;
		};

		if (_iterations == _indicatorLine) then {
			sleep (_x select 1);
			
			[] spawn {
				_hudEffect = ppEffectCreate ["ColorCorrections",2593]; 
				_hudEffect ppEffectForceInNVG true; 
				_hudEffect ppEffectEnable true; 
				_hudEffect ppEffectAdjust [0,1,0,INTERIOR_OVERLAY_COLOR,[1,1,1,0],[1,1,1,0],[1,1,0,0,0,0,10]]; 
				_hudEffect ppEffectCommit 0.3;
				playSound "Simulation_Restart";

				private _colorR = INTERIOR_OVERLAY_COLOR select 0;
				private _colorG = INTERIOR_OVERLAY_COLOR select 1;
				private _colorB = INTERIOR_OVERLAY_COLOR select 2;
				private _colorA = 0;
				private _maxAlpha = INTERIOR_OVERLAY_COLOR select 3;

				private _effectColor = [_colorR,_colorG,_colorB,_colorA];
				_effectColor call BPD_CloneHUD_fnc_interiorColor;
				while {((_effectColor select 3) < _maxAlpha)} do {
					
					_effectColor set[3,(_effectColor select 3) + 0.1];
					if (HUD_hasHelmet && HUD_firstPersonCheck) then {
						_effectColor call BPD_CloneHUD_fnc_interiorColor;
					} else {
						[0,0,0,0] call BPD_CloneHUD_fnc_interiorColor;
					};
					sleep 0.1;
				};
				if (HUD_hasHelmet && HUD_firstPersonCheck) then {
					INTERIOR_OVERLAY_COLOR call BPD_CloneHUD_fnc_interiorColor;
				} else {
					[0,0,0,0] call BPD_CloneHUD_fnc_interiorColor;
				};
				player setvariable ["HUD_ACTIVE", true];
				ppEffectDestroy _hudEffect;
			};

			private _indicators = [
				(HUD_pa_head#0),
				(HUD_pa_torso#0),
				(HUD_pa_armR#0),
				(HUD_pa_armL#0),
				(HUD_pa_legR#0),
				(HUD_pa_legL#0)
			];
			private _infoText = [
				(HUD_infoAmmo#0),
				(HUD_infoMags#0),
				(HUD_infoDir#0),
				(HUD_infoRange#0)
			];
			private _P2infoText = [
				(P2_infoAmmo#0),
				(P2_infoMags#0),
				(P2_infoDir#0),
				(P2_infoRange#0)
			];
			private _RCinfoText = [
				(RC_infoAmmo#0),
				(RC_infoMags#0),
				(RC_infoDir#0),
				(RC_infoRange#0)
			];
			[_indicators] spawn {
				player setVariable ["HUD_indicatorsActive",true];
				private _indicators = _this select 0;
				// [true] call, not bare call - a bare call here would
				// inherit this spawned block's own _this ([_indicators],
				// an array) as the function's _duringBoot parameter
				// instead of getting its own argument, which crashed
				// every one of these four calls (confirmed via RPT:
				// "Error !: Type Array, expected Bool"). true is also
				// the actually-intended value here, not just a safe
				// default - bootComplete is still false at this exact
				// point in boot, so without this the guard would just
				// exit early and this whole choreography would no-op.
				[true] call HUD_fnc_updateDamageIndicator;
				sleep 0.3;
				{_x ctrlSetTextColor [0,0,0,0]} forEach _indicators;
				sleep 0.1;
				[true] call HUD_fnc_updateDamageIndicator;
				sleep 0.1;
				{_x ctrlSetTextColor [0,0,0,0]} forEach _indicators;
				sleep 0.1;
				[true] call HUD_fnc_updateDamageIndicator;
				sleep 0.1;
				{_x ctrlSetTextColor [0,0,0,0]} forEach _indicators;
				sleep 0.1;
				[true] call HUD_fnc_updateDamageIndicator;
			};
			
			private _p1_inhelmets = player getVariable ["P1_INHELMETS",false];
			private _p2_inhelmets = player getVariable ["P2_INHELMETS",false];
			private _rc_inhelmets = player getVariable ["RC_INHELMETS",false];
			
			if(_p1_inhelmets) then {
				[_infoText] spawn {
					if (!DISPLAY_INFO) exitWith {};
					private _infoText = _this select 0;
					(HUD_infoDisplay#0) ctrlSetTextColor INFO_DISPLAY_COLOR;
					{
						_x ctrlSetTextColor INFO_TEXT_COLOR;
						_x ctrlSetText format ["%1", round(random 999)];
					} forEach _infoText;
					sleep 0.3;
					(HUD_infoDisplay#0) ctrlSetTextColor [0,0,0,0];
					{
						_x ctrlSetTextColor [0,0,0,0]
					} forEach _infoText;
					sleep 0.1;
					(HUD_infoDisplay#0) ctrlSetTextColor INFO_DISPLAY_COLOR;
					{
						_x ctrlSetTextColor INFO_TEXT_COLOR;
						_x ctrlSetText format ["%1", round(random 999)];
					} forEach _infoText;
					sleep 0.1;
					(HUD_infoDisplay#0) ctrlSetTextColor [0,0,0,0];
					{
						_x ctrlSetTextColor [0,0,0,0]
					} forEach _infoText;
					sleep 0.1;
					(HUD_infoDisplay#0) ctrlSetTextColor INFO_DISPLAY_COLOR;
					{
						_x ctrlSetTextColor INFO_TEXT_COLOR;
						_x ctrlSetText format ["%1", round(random 999)];
					} forEach _infoText;
					sleep 0.1;
					(HUD_infoDisplay#0) ctrlSetTextColor [0,0,0,0];
					{
						_x ctrlSetTextColor [0,0,0,0]
					} forEach _infoText;
					sleep 0.1;
					(HUD_infoDisplay#0) ctrlSetTextColor INFO_DISPLAY_COLOR;
					{
						_x ctrlSetTextColor INFO_TEXT_COLOR;
						_x ctrlSetText format ["%1", round(random 999)];
					} forEach _infoText;
				};
			};
			if(_p2_inhelmets) then {
				[_P2infoText] spawn {
					if (!DISPLAY_INFO) exitWith {};
					private _infoText = _this select 0;
					(P2_infoDisplay#0) ctrlSetTextColor INFO_DISPLAY_COLOR;
					{
						_x ctrlSetTextColor INFO_TEXT_COLOR;
						_x ctrlSetText format ["%1", round(random 999)];
					
					} forEach _infoText;
					sleep 0.3;
					(P2_infoDisplay#0) ctrlSetTextColor [0,0,0,0];
					{
						_x ctrlSetTextColor [0,0,0,0]
					} forEach _infoText;
					sleep 0.1;
					(P2_infoDisplay#0) ctrlSetTextColor INFO_DISPLAY_COLOR;
					{
						_x ctrlSetTextColor INFO_TEXT_COLOR;
						_x ctrlSetText format ["%1", round(random 999)];
					} forEach _infoText;
					sleep 0.1;
					(P2_infoDisplay#0) ctrlSetTextColor [0,0,0,0];
					{
						_x ctrlSetTextColor [0,0,0,0]
					} forEach _infoText;
					sleep 0.1;
					(P2_infoDisplay#0) ctrlSetTextColor INFO_DISPLAY_COLOR;
					{
						_x ctrlSetTextColor INFO_TEXT_COLOR;
						_x ctrlSetText format ["%1", round(random 999)];
					} forEach _infoText;
					sleep 0.1;
					(P2_infoDisplay#0) ctrlSetTextColor [0,0,0,0];
					{
						_x ctrlSetTextColor [0,0,0,0]
					} forEach _infoText;
					sleep 0.1;
					(P2_infoDisplay#0) ctrlSetTextColor INFO_DISPLAY_COLOR;
					{
						_x ctrlSetTextColor INFO_TEXT_COLOR;
						_x ctrlSetText format ["%1", round(random 999)];
					} forEach _infoText;
				};
			};
			if(_rc_inhelmets) then {
				[_RCinfoText] spawn {
					if (!DISPLAY_INFO) exitWith {};
					private _infoText = _this select 0;
					(RC_infoDisplay#0) ctrlSetTextColor INFO_DISPLAY_COLOR;
					{
						_x ctrlSetTextColor INFO_TEXT_COLOR;
						_x ctrlSetText format ["%1", round(random 999)];
					
					} forEach _infoText;
					sleep 0.3;
					(RC_infoDisplay#0) ctrlSetTextColor [0,0,0,0];
					{
						_x ctrlSetTextColor [0,0,0,0]
					} forEach _infoText;
					sleep 0.1;
					(RC_infoDisplay#0) ctrlSetTextColor INFO_DISPLAY_COLOR;
					{
						_x ctrlSetTextColor INFO_TEXT_COLOR;
						_x ctrlSetText format ["%1", round(random 999)];
					} forEach _infoText;
					sleep 0.1;
					(RC_infoDisplay#0) ctrlSetTextColor [0,0,0,0];
					{
						_x ctrlSetTextColor [0,0,0,0]
					} forEach _infoText;
					sleep 0.1;
					(RC_infoDisplay#0) ctrlSetTextColor INFO_DISPLAY_COLOR;
					{
						_x ctrlSetTextColor INFO_TEXT_COLOR;
						_x ctrlSetText format ["%1", round(random 999)];
					} forEach _infoText;
					sleep 0.1;
					(RC_infoDisplay#0) ctrlSetTextColor [0,0,0,0];
					{
						_x ctrlSetTextColor [0,0,0,0]
					} forEach _infoText;
					sleep 0.1;
					(RC_infoDisplay#0) ctrlSetTextColor INFO_DISPLAY_COLOR;
					{
						_x ctrlSetTextColor INFO_TEXT_COLOR;
						_x ctrlSetText format ["%1", round(random 999)];
					} forEach _infoText;
				};
			};
		};

		if (_iterations == _auspexLine) then {
			//sleep (_x select 1);
			[] spawn {
				_targetingEffect = ppEffectCreate ["ColorCorrections",2593]; 
				_targetingEffect ppEffectForceInNVG true; 
				_targetingEffect ppEffectEnable true; 
				_targetingEffect ppEffectAdjust [0,1,0,[0.105,0.105,0.105,0.5],[1,1,1,0],[1,1,1,0],[1,1,0,0,0,0,10]]; 
				_targetingEffect ppEffectCommit 0.3;
				playsound targetingSystemSoundOn;
				sleep 0.1;
				player setvariable ["HUD_TARGETING_ALLOWED", true];
				HUD_showIcons = true;
				call HUD_fnc_addTargetingEventhandler;
				sleep 0.5;
				ppEffectDestroy _targetingEffect;
			};
		};

		_iterations = _iterations + 1;
	} forEach _bootupText;
	diag_log format ["885th_CloneHUD: typing loop finished, reached iteration %1 of %2.", _iterations, count _bootupText];

	_accumulatedText = "";
	_textField ctrlSetStructuredText parseText "";

	_textField ctrlSetPosition [-5.40912e-007 * safezoneW,0 * safezoneH,0.984844 * safezoneW,1.946 * safezoneH];
	_textField ctrlcommit 0;

	// Safety net: if BOOTUP_SCANNER_LINE (or a customized HUD_bootText)
	// is longer/shorter than expected, the loop above may finish
	// without ever reaching _auspexLine - which would otherwise leave
	// HUD_TARGETING_ALLOWED false forever and permanently lock out
	// every keybind (scanner toggle, range, low-light). Make sure
	// targeting always gets activated once boot completes, regardless.
	if (HUD_hasHelmet && (player getVariable ["HUD_hudInitiated",false]) && !(player getVariable ["HUD_TARGETING_ALLOWED", false])) then {
		player setvariable ["HUD_TARGETING_ALLOWED", true];
		HUD_showIcons = true;
		call HUD_fnc_addTargetingEventhandler;
	};

	if (!HUD_hasHelmet OR !(player getVariable ["HUD_hudInitiated",false])) exitWith {
		diag_log format ["885th_CloneHUD: hudBootUp exiting early instead of completing - HUD_hasHelmet=%1, HUD_hudInitiated=%2. HUD_bootComplete will stay false, so the indicator/radar/team list won't appear.", HUD_hasHelmet, (player getVariable ["HUD_hudInitiated",false])];
		call HUD_fnc_clearHud;
	};
	HUD_systemMessageAllowed = true;
	// HUD_bootComplete is the one flag that's only ever true once the
	// ENTIRE boot sequence (including its own internal flicker/reveal
	// choreography) has actually finished - HUD_ALLOWED and
	// HUD_indicatorsActive both get set true much earlier, partway
	// through boot, as part of that choreography itself, so gating
	// the damage indicator / team list on those made them start
	// updating and appearing before boot visually finished.
	player setVariable ["HUD_bootComplete", true];
	diag_log "885th_CloneHUD: hudBootUp completed normally, HUD_bootComplete is now true.";
	// Not spawning HUD_fnc_SystemMessageLoop here - HUD_suit_activation
	// already spawned it once, waiting on HUD_systemMessageAllowed via
	// waitUntil; spawning a second copy here would run two concurrently
	// from this point on.
};