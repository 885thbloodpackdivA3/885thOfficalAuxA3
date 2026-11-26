/*
	885th Bloodpack Division - Clone HUD - HUD & Targeting Event Handlers
	---------------------------------------------------------------
	Uses BIS_fnc_addStackedEventHandler (vanilla, no CBA needed).
*/

HUD_fnc_addHudEventhandler = {
	if (HUD_eventHandlerAdded) exitWith {};
	HUD_eventHandlerAdded = true;
	HUD_notMovingTimer = 0;
	["MOVING_HUD", "onEachFrame",{

		private _cameraview = getCameraViewDirection player;
		private _overlay = (HUD_hudOverlay#0);
		private _overlayColor = (HUD_hudOverlayColor#0);
		private _speed = abs(speed player) / 40;

		private _newViewAngle = (_cameraview select 0) atan2 (_cameraview select 1);
		_newViewAngle = (_newViewAngle + 360) % 360;

		private _viewAngleDifference = abs(oldViewAngle - _newViewAngle);
		if (_viewAngleDifference > 0.02 && _viewAngleDifference < 100 && _speed <= 12) then {
			private _angleDelta = _newViewAngle - oldViewAngle;
			if (_angleDelta > 180) then {_angleDelta = _angleDelta - 360};
			if (_angleDelta < -180) then {_angleDelta = _angleDelta + 360};

			private _angleChange = _angleDelta / 5;

			if (_angleChange > 0) then {
				if (hudAngle - _angleChange >= -25) then {
					hudAngle = hudAngle - _angleChange;
				};
			} else {
				if (hudAngle - _angleChange <= 25) then {
					hudAngle = hudAngle - _angleChange;
				};
			};
			HUD_notMovingTimer = 0;
		} else {
			HUD_notMovingTimer = HUD_notMovingTimer + diag_deltaTime;
			if (HUD_notMovingTimer >= 0.5) then {
				private _angleChange = hudAngle / 50;
				if (abs(_angleChange) < 0.0001) then {
					hudAngle = 0;
				} else {
					hudAngle = hudAngle - (2 * _angleChange * HUD_notMovingTimer);
				};
			};
		};

		if (speed player != 0 && hudAngle != 0) then {
			private _angleChange = _speed;
			if (hudAngle > 0) then {
				hudAngle = hudAngle - _angleChange;
			};
			if (hudAngle < 0) then {
				hudAngle = hudAngle + _angleChange;
			};
		};

		oldViewAngle = _newViewAngle;

		private _hudX = -0.1259 * safezoneW + safezoneX + abs(safezoneX) * hudAngle / 80;
		private _hudY = -0.61 * safezoneH + safezoneY + (_cameraview select 2) / 5;
		private _hudW = 1.25 * safezoneW;
		private _hudH = 2.18 * safezoneH;

		private _hudPosition = [_hudX, _hudY, _hudW, _hudH];

		_overlay ctrlSetPosition _hudPosition;
		_overlayColor ctrlSetPosition _hudPosition;

		// Cosmetic "cracked visor" swap - now driven by real head-hitpoint
		// damage instead of a custom armor pool.
		if ((player getHitPointDamage "HitHead") > 0.5) then {
			_overlay ctrlSetText HUD_hudOverlayBrokenTexture;
			_overlayColor ctrlSetText HUD_hudOverlayBrokenTexture;
		} else {
			_overlay ctrlSetText HUD_hudOverlayTexture;
			_overlayColor ctrlSetText HUD_hudOverlayTexture;
		};

		if (HUD_hasHelmet && HUD_firstPersonCheck) then {
			private _color = [1, 1, 1, 1];
			private _visionMode = currentVisionMode player;

			switch (_visionMode) do {
				case 0: {
					private _light = getLightingAt player;
					private _ambient = (_light select 1) / 50;
					private _dynamic = (_light select 3) / 50;

					if (_dynamic < _ambient) then {HUD_lighting = "AMBIENT";} else {HUD_lighting = "DYNAMIC";};
					if (HUD_lowLight) then {
						private _colorR = (if (_dynamic < _ambient) then {((_light select 2) select 0)} else {(_light select 2) select 0});
						private _colorG = (if (_dynamic < _ambient) then {((_light select 2) select 0)} else {(_light select 2) select 1});
						private _colorB = (if (_dynamic < _ambient) then {((_light select 2) select 0)} else {(_light select 2) select 2});
						private _colorA = HUD_ALPHA;

						private _lowLightFactor = 0.8 * abs(HUD_lowLightAperture - 1.5);
						private _lowLightColor = 0.3 * abs(HUD_lowLightAperture - 1.5);
						_color = [_colorR + _lowLightColor, _colorG + _lowLightColor, _colorB + _lowLightColor, (_lowLightFactor + _colorA * _ambient) max (_lowLightFactor + _colorA * _dynamic)];

					} else {
						private _colorR = (if (_dynamic < _ambient) then {1} else {(_light select 2) select 0});
						private _colorG = (if (_dynamic < _ambient) then {1} else {(_light select 2) select 1});
						private _colorB = (if (_dynamic < _ambient) then {1} else {(_light select 2) select 2});
						private _colorA = HUD_ALPHA;

						_color = [_colorR, _colorG, _colorB, (_colorA * _ambient) max (_colorA * _dynamic)];

					};
				};
				case 1: {
					private _light = getLightingAt player;
					private _ambient = ((_light select 1) / 3000);
					private _dynamic = ((_light select 3) / 50);
					private _colorNVG = HUD_COLOR_NVG;
					private _colorR = _colorNVG select 0;
					private _colorG = _colorNVG select 1;
					private _colorB = _colorNVG select 2;
					private _colorA = _colorNVG select 3;
					_color = [_colorR, _colorG, _colorB, (0.3 + _colorA * _ambient) max (0.3 + _colorA * _dynamic)];
				};
				case 2: {_color = HUD_COLOR_THERMAL};
			};

			_overlay ctrlSetTextColor [0, 0, 0, HUD_ALPHA];
			_overlayColor ctrlSetTextColor _color;
		} else {
			_overlay ctrlSetTextColor [0, 0, 0, 0];
			_overlayColor ctrlSetTextColor [0, 0, 0, 0];
		};

		_overlay ctrlCommit 0;
		_overlayColor ctrlCommit 0;
	}] call BIS_fnc_addStackedEventHandler;
};

HUD_throttleTime = 0.3;

// Builds HUD_nearUnits (drawn live) and HUD_lastKnown (drawn as faded
// "last known" ghosts). With BPD_CloneHUD_SCAN_LOS on, a unit only shows
// while the trooper can actually see it - checkVisibility counts smoke,
// foliage and buildings, so a B1 inside a smoke cloud drops off. For
// BPD_CloneHUD_SCAN_LKP_TIME seconds after losing sight, a faded marker
// stays where it was last seen (it does NOT follow the unit).
HUD_lastKnown = [];
HUD_nearUnitsHandler = {
	private _nearUnits = nearestObjects [player, ["MAN","CAR","TANK","AIR","StaticWeapon"], HUD_threatRange, true];
	private _veh = vehicle player;
	private _eye = eyePos player;

	if !(missionNamespace getVariable ["BPD_CloneHUD_SCAN_LOS", true]) exitWith {
		// old behavior: only hard cover (walls, terrain) blocks the scanner
		HUD_nearUnits = _nearUnits select {
			private _unitBlocked = lineIntersects [_eye, eyePos _x, player, _x] OR terrainIntersectASL [_eye, eyepos _x];
			alive _x && vehicle _x != _veh && !_unitBlocked;
		};
		HUD_lastKnown = [];
	};

	private _lkpTime = missionNamespace getVariable ["BPD_CloneHUD_SCAN_LKP_TIME", 10];
	private _need = missionNamespace getVariable ["BPD_CloneHUD_SCAN_LOS_MIN", 0.3];
	private _now = diag_tickTime;
	private _seen = [];
	private _lost = [];
	{
		private _u = _x;
		if (alive _u && {vehicle _u != _veh}) then {
			private _aim = aimPos _u;
			// head OR body visible counts (someone peeking over cover)
			private _terrain = terrainIntersectASL [_eye, _aim] && {!(_u isKindOf "MAN") || {terrainIntersectASL [_eye, eyePos _u]}};
			private _vis = if (_terrain) then {0} else {
				private _v = [_veh, "VIEW", _u] checkVisibility [_eye, _aim];
				if (_v < _need && {_u isKindOf "MAN"}) then { _v = _v max ([_veh, "VIEW", _u] checkVisibility [_eye, eyePos _u]); };
				_v
			};
			if (_vis >= _need) then {
				_seen pushBack _u;
				_u setVariable ["BPD_CloneHUD_lastSeen", [ASLToAGL _aim, _now]]; // local only
			} else {
				if (_lkpTime > 0) then {
					private _lk = _u getVariable ["BPD_CloneHUD_lastSeen", []];
					if (count _lk == 2 && {_now - (_lk select 1) <= _lkpTime}) then {
						_lost pushBack [_u, _lk select 0, _lk select 1];
					};
				};
			};
		};
	} forEach _nearUnits;
	HUD_nearUnits = _seen;
	HUD_lastKnown = _lost;
};

HUD_fnc_addTargetingEventhandler = {
	if (HUD_targetingHandlerAdded) exitWith {};
	HUD_targetingHandlerAdded = true;

	HUD_nearUnitsHandlerHandle = [] spawn {
		while {HUD_targetingHandlerAdded} do {
			while {HUD_showIcons} do {
				call HUD_nearUnitsHandler;
				sleep HUD_throttleTime;
			};
			sleep 1;
		};
	};

	["TARGETING_HUD", "onEachFrame",{
		// tier 3 jamming (jamming.sqf) knocks the scanner out
		if (HUD_showIcons && {isNull (findDisplay 312)} && {(missionNamespace getVariable ["BPD_CloneHUD_jamTier", 0]) < 3}) then {
			private _drawLabels = (missionNamespace getVariable ["BPD_CloneHUD_TEAM_LABELS", true]) && {!isNil "BPD_CloneHUD_fnc_buildTeamLabels"};
			private _myGroup = group player;
			if (_drawLabels && {diag_tickTime > BPD_CloneHUD_teamLabelsNext}) then { call BPD_CloneHUD_fnc_buildTeamLabels; };
			{
				private _unit = _x;
				private _distance = positionCameraToWorld [0,0,0] distance _unit;
				private _icon = "";
				private _size = 0;
				private _color = [0,0,0,0];
				private _sideUnit = side _unit;
				private _sidePlayer = side player;
				private _hostileCheck = _sidePlayer getFriend _sideUnit;
				private _fov = getObjectFOV vehicle player;
				private _pos = [0,0,0];

				if (_unit isKindof "MAN") then {
					_pos = _unit modelToWorldVisual (_unit selectionPosition "spine3");
					if (_sideUnit == civilian OR lifeState _unit == "INCAPACITATED") then {
						_color = HUD_NEUTRAL_COLOR;
					} else {
						if (_hostileCheck < 0.6) then {
							_color = HUD_ENEMY_COLOR;
						} else {
							if (group player isEqualTo group _unit) then {
								_color = HUD_GROUP_COLOR;
							} else {
								_color = HUD_FRIENDLY_COLOR;
							};
						};
					};
					_icon = HUD_HUMAN_ICON;
					_size = (HUD_HUMAN_SIZE / tan(_fov /2) / _distance) max 0.5;
				} else {
					if (_sideUnit == civilian OR lifeState _unit == "INCAPACITATED") then {
						_color = HUD_NEUTRAL_COLOR;
					} else {
						if (_hostileCheck < 0.6) then {
							_color = HUD_ENEMY_COLOR;
						} else {
							if (group player isEqualTo group _unit) then {
								_color = HUD_GROUP_COLOR;
							} else {
								_color = HUD_FRIENDLY_COLOR;
							};
						};
					};
					if (_unit isKindof "StaticWeapon") then {
						_pos = _unit modelToWorldVisual (_unit selectionPosition ["osahlavne", "Memory"]);
						_icon = HUD_STATIC_ICON;
						_size = (HUD_STATIC_SIZE / tan(_fov /2) / _distance) max 0.5;
					} else {
						_pos = _unit modelToWorldVisual (_unit selectionPosition ["zamerny", "Memory"]);
						_icon = HUD_VEHICLE_ICON;
						_size = (HUD_VEHICLE_SIZE / tan(_fov /2) / _distance) max 0.5;
					};
				};
				drawIcon3D [_icon,_color,_pos,_size,_size,0,"",0,0.04,"RobotoCondensed","center",false];

				// Fireteam label above own squadmates' heads ("Red Team 1",
				// "Medic 2"...), in the team's color. Labels themselves are
				// rebuilt once a second, not every frame.
				if (_drawLabels && {_unit isKindOf "MAN"} && {group _unit isEqualTo _myGroup}) then {
					private _tl = _unit getVariable ["BPD_CloneHUD_teamLabel", []];
					if (count _tl == 2) then {
						private _headPos = _unit modelToWorldVisual ((_unit selectionPosition "head") vectorAdd [0, 0, 0.45]);
						drawIcon3D ["", _tl select 1, _headPos, 0, 0, 0, _tl select 0, 2, 0.032, "RobotoCondensedBold", "center", false];
					};
				};
			} forEach HUD_nearUnits;

			// Last known positions: faded icon frozen where the unit was last
			// seen, fading out over the Last Known time, with a "?" tag.
			private _lkpTime = (missionNamespace getVariable ["BPD_CloneHUD_SCAN_LKP_TIME", 10]) max 1;
			private _fovLk = getObjectFOV vehicle player;
			private _camPos = positionCameraToWorld [0,0,0];
			{
				_x params ["_unit", "_lkPos", "_lkTick"];
				if (alive _unit) then {
					private _side = side _unit;
					private _col = +(call {
						if (_side == civilian || {lifeState _unit == "INCAPACITATED"}) exitWith {HUD_NEUTRAL_COLOR};
						if ((side player getFriend _side) < 0.6) exitWith {HUD_ENEMY_COLOR};
						if (group player isEqualTo group _unit) exitWith {HUD_GROUP_COLOR};
						HUD_FRIENDLY_COLOR
					});
					private _fade = 1 - ((diag_tickTime - _lkTick) / _lkpTime);
					_col set [3, ((_col select 3) * (0.15 + 0.4 * _fade)) max 0.1];
					private _d = (_camPos distance _lkPos) max 1;
					private _iconSize = call {
						if (_unit isKindOf "MAN") exitWith {[HUD_HUMAN_ICON, HUD_HUMAN_SIZE]};
						if (_unit isKindOf "StaticWeapon") exitWith {[HUD_STATIC_ICON, HUD_STATIC_SIZE]};
						[HUD_VEHICLE_ICON, HUD_VEHICLE_SIZE]
					};
					private _sz = ((_iconSize select 1) / tan (_fovLk / 2) / _d) max 0.5;
					drawIcon3D [_iconSize select 0, _col, _lkPos, _sz, _sz, 0, "?", 2, 0.03, "RobotoCondensedBold", "center", false];
				};
			} forEach HUD_lastKnown;

			private _grenades = nearestObjects [player,["Grenade"], 30];
			{
				drawIcon3D [HUD_WARNING_ICON,HUD_WARNING_COLOR,getPosATLVisual _x,HUD_WARNING_SIZE,HUD_WARNING_SIZE,0,"",0,0.04,"RobotoCondensed","center",true];
			} forEach _grenades;
		};
	}] call BIS_fnc_addStackedEventHandler;
};

HUD_fnc_removeHudEventhandler = {
	if (!HUD_eventHandlerAdded) exitWith {};
	HUD_eventHandlerAdded = false;
	(HUD_hudOverlay#0) ctrlSetTextColor [0,0,0,0];
	(HUD_hudOverlayColor#0) ctrlSetTextColor [0,0,0,0];
	["MOVING_HUD", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
};

HUD_fnc_removeTargetingEventhandler = {
	if (!HUD_targetingHandlerAdded) exitWith {};
	HUD_targetingHandlerAdded = false;
	["TARGETING_HUD", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
};
