HUD_fnc_system =
{	
	diag_log "885th_CloneHUD: HUD_fnc_system entered.";
	_hudAmmo = (HUD_infoAmmo#0);
	_hudMags = (HUD_infoMags#0);
	_hudDir = (HUD_infoDir#0);
	_hudRange = (HUD_infoRange#0);
	
	_P2hudAmmo = (P2_infoAmmo#0);
	_P2hudMags = (P2_infoMags#0);
	_P2hudDir = (P2_infoDir#0);
	_P2hudRange = (P2_infoRange#0);
	
	_RChudAmmo = (RC_infoAmmo#0);
	_RChudMags = (RC_infoMags#0);
	_RChudDir = (RC_infoDir#0);
	_RChudRange = (RC_infoRange#0);

	_compatibleMagazines = compatibleMagazines (currentWeapon (vehicle player));
	_availableMagCount = {_x in _compatibleMagazines} count magazines (vehicle player);
	_currentAmmo = (vehicle player) ammo currentWeapon (vehicle player);

	(_this select 0) params ["_target"];
	_HelmetVisionModeChanged = false;
	_lastvisionmode = currentVisionMode player;
	_visionmodechanged = false;

	oldRandomAngle = 1;

	// Damage-indicator polling state. This is the SOURCE OF TRUTH for
	// the six light colors - it just compares real getHitPointDamage
	// values tick to tick and repaints when something changed. This
	// doesn't depend on any hit-event firing or on any selection-name
	// matching, so it can't silently stop working. The "Dammaged" hook
	// in init.sqf still gives the nicer per-hit flash/sound/message
	// when it identifies the correct selection, but even if it never
	// fires (respawn, a quirky hit, whatever) the lights themselves
	// will still be correct within one loop tick (~0.1s).
	private _prevHeadDmg = "";
	private _prevBodyDmg = "";
	private _prevHandsDmg = "";
	private _prevLegsDmg = "";

	if (isNil "HUD_systemLoopLogged") then {
		HUD_systemLoopLogged = true;
		diag_log format ["885th_CloneHUD: HUD_fnc_system outer loop entered - alive=%1, HUD_hasUniform=%2, HUD_suitDisabled=%3.", alive player, (player getvariable ["HUD_hasUniform",false]), (player getVariable "HUD_suitDisabled")];
	};
	diag_log format ["885th_CloneHUD: HUD_fnc_system about to enter its while loop - alive player=%1, HUD_hasUniform=%2, HUD_suitDisabled=%3.", alive player, (player getvariable ["HUD_hasUniform",false]), (player getVariable "HUD_suitDisabled")];
	private _hudFncSystemFirstLoop = true;
	while {alive player && (player getvariable ["HUD_hasUniform",false]) && !(player getVariable "HUD_suitDisabled")} do {
		if (_hudFncSystemFirstLoop) then {
			_hudFncSystemFirstLoop = false;
			diag_log "885th_CloneHUD: HUD_fnc_system while loop body running (first iteration).";
		};
		HUD_firstPersonCheck = (((cameraView == "INTERNAL") OR (cameraView == "GUNNER")) && isNull(findDisplay 312));
		private _hudActive = player getvariable ["HUD_ACTIVE",false];
		private _hudCheck = HUD_helmetOverlayShown;
		
		private _p1_inhelmet = player getVariable ["P1_INHELMET",false];
		private _p2_inhelmet = player getVariable ["P2_INHELMET",false];
		private _rc_inhelmet = player getVariable ["RC_INHELMET",false];

		private _indicatorGateNow = HUD_hasHelmet && (player getVariable ["HUD_bootComplete",false]);
		if (_indicatorGateNow != (missionNamespace getVariable ["HUD_indicatorGatePrev", !_indicatorGateNow])) then {
			missionNamespace setVariable ["HUD_indicatorGatePrev", _indicatorGateNow];
			diag_log format ["885th_CloneHUD: indicator polling gate changed to %1 - HUD_hasHelmet=%2, HUD_bootComplete=%3.", _indicatorGateNow, HUD_hasHelmet, (player getVariable ["HUD_bootComplete",false])];
		};
		if (HUD_hasHelmet && (player getVariable ["HUD_bootComplete",false])) then {
			// Single source of truth for "what state is this limb in" -
			// HUD_fnc_getLimbColor already handles the vanilla/ACE
			// branch and the ACE-not-loaded fallback, so this just
			// reuses it for change detection instead of re-reading
			// ACE data a second, separate way. Compare the state label
			// (index 1) rather than the color itself, since the ACE
			// bleed color is a continuous gradient that can shift by
			// tiny amounts without representing a meaningful change.
			private _headDmg = (["HitHead", 0] call HUD_fnc_getLimbColor) select 1;
			private _bodyDmg = (["HitBody", 1] call HUD_fnc_getLimbColor) select 1;
			private _handsDmg = [(["HitHands", 2] call HUD_fnc_getLimbColor) select 1, (["HitHands", 3] call HUD_fnc_getLimbColor) select 1] joinString ",";
			private _legsDmg = [(["HitLegs", 4] call HUD_fnc_getLimbColor) select 1, (["HitLegs", 5] call HUD_fnc_getLimbColor) select 1] joinString ",";
			if (_headDmg != _prevHeadDmg || {_bodyDmg != _prevBodyDmg} || {_handsDmg != _prevHandsDmg} || {_legsDmg != _prevLegsDmg}) then {
				[] call HUD_fnc_updateDamageIndicator;
				_prevHeadDmg = _headDmg;
				_prevBodyDmg = _bodyDmg;
				_prevHandsDmg = _handsDmg;
				_prevLegsDmg = _legsDmg;
			};
		};

		if (HUD_hasHelmet && _hudCheck) then {
			if (_HelmetVisionModeChanged) then {
				_HelmetVisionModeChanged = false;
			};

			_visionmodechanged = !((currentVisionMode player) isEqualTo _lastvisionmode);
			_HelmetVisionModeChanged = _visionModeChanged && (vehicle player == player);
				
			if (_HelmetVisionModeChanged) then {
				if (_lastvisionmode != 2) then {
					playSound "RscDisplayCurator_visionMode";
				};
				_lastvisionmode = (currentVisionMode player);
			};
		};
		
		//HUD OVERLAY
		if (_hudActive) then {
			if (HUD_hasHelmet && !(_hudCheck) && missionnamespace getvariable "SHOW_HUD_OVERLAY" && HUD_firstPersonCheck) then {
				player setvariable ["HUD_ALLOWED", true];
				HUD_helmetOverlayShown = true;
				(HUD_interiorOverlay#0) ctrlSetTextColor INTERIOR_OVERLAY_COLOR;
				(HUD_visorEffect#0) ctrlSetTextColor [1,1,1,0.3];
				call HUD_fnc_addHudEventhandler;
				call HUD_fnc_addTargetingEventhandler;
				[] call HUD_fnc_updateDamageIndicator;
			};

			if (HUD_hasHelmet && missionnamespace getvariable "SHOW_HUD_OVERLAY" && (player getVariable ["HUD_bootComplete",false])) then {
			
				if (DISPLAY_INFO && _p1_inhelmet) then {
					_infoColor = INFO_TEXT_COLOR;
					if ((vehicle player) != player) then {
						if ((weaponState [(vehicle player),((assignedVehicleRole player) select 1)] select 0) != "") then {
							_compatibleMagazines = (weaponState [(vehicle player),((assignedVehicleRole player) select 1)] select 3);
							_availableMagCount = {_x in _compatibleMagazines} count ((vehicle player) magazinesTurret [((assignedVehicleRole player) select 1),false]);
							_currentAmmo = (weaponState [(vehicle player),((assignedVehicleRole player) select 1)] select 4);
							if (_availableMagCount > 0) then {
								_availableMagCount = _availableMagCount - 1;
							};
						} else {
							_availableMagCount = "--";
							_currentAmmo = "---";
						};
					} else {
						if (((weaponState (vehicle player)) select 0) == ((weaponState (vehicle player)) select 1)) then {
							_compatibleMagazines = compatibleMagazines (currentWeapon (vehicle player));
						} else {
							_compatibleMagazines = compatibleMagazines ((weaponState (vehicle player)) select 1);
						};
						
						_availableMagCount = {_x in _compatibleMagazines} count magazines (vehicle player);
						_currentAmmo = (weaponState (vehicle player)) select 4;
					};

					_ins = lineIntersectsSurfaces [AGLToASL positionCameraToWorld [0,0,0],AGLToASL positionCameraToWorld [0,0,5000],vehicle player,objNull,true,1,"FIRE","NONE"];
					_cursor_distance = if (count _ins > 0) then [{(_ins select 0 select 0) vectorDistance (eyepos player)},{5000}];
					_aim_dist_txt = if (count _ins > 0) then [{str(round _cursor_distance)},{"---"}];

					_hudAmmo ctrlSetText format ["%1", _currentAmmo];
					_hudAmmo ctrlSetTextColor _infoColor;
					_hudAmmo ctrlCommit 0;

					_hudMags ctrlSetText format ["%1", _availableMagCount];
					_hudMags ctrlSetTextColor _infoColor;
					_hudMags ctrlCommit 0;

					_hudDir ctrlSetText format["%1°", round(getDir player)];
					_hudDir ctrlSetTextColor _infoColor;
					_hudDir ctrlCommit 0;
					
					_hudRange ctrlSetText format["%1m", _aim_dist_txt];
					_hudRange ctrlSetTextColor _infoColor;
					_hudRange ctrlCommit 0;
				} else {
					_infoColor = [0,0,0,0];

					_hudAmmo ctrlSetText "";
					_hudAmmo ctrlSetTextColor _infoColor;
					_hudAmmo ctrlCommit 0;

					_hudMags ctrlSetText "";
					_hudMags ctrlSetTextColor _infoColor;
					_hudMags ctrlCommit 0;

					_hudDir ctrlSetText "";
					_hudDir ctrlSetTextColor _infoColor;
					_hudDir ctrlCommit 0;
					
					_hudRange ctrlSetText "";
					_hudRange ctrlSetTextColor _infoColor;
					_hudRange ctrlCommit 0;
				};
				
				if (DISPLAY_INFO && _p2_inhelmet) then {
					_infoColor = INFO_TEXT_COLOR;
					if ((vehicle player) != player) then {
						if ((weaponState [(vehicle player),((assignedVehicleRole player) select 1)] select 0) != "") then {
							_compatibleMagazines = (weaponState [(vehicle player),((assignedVehicleRole player) select 1)] select 3);
							_availableMagCount = {_x in _compatibleMagazines} count ((vehicle player) magazinesTurret [((assignedVehicleRole player) select 1),false]);
							_currentAmmo = (weaponState [(vehicle player),((assignedVehicleRole player) select 1)] select 4);
							if (_availableMagCount > 0) then {
								_availableMagCount = _availableMagCount - 1;
							};
						} else {
							_availableMagCount = "--";
							_currentAmmo = "---";
						};
					} else {
						if (((weaponState (vehicle player)) select 0) == ((weaponState (vehicle player)) select 1)) then {
							_compatibleMagazines = compatibleMagazines (currentWeapon (vehicle player));
						} else {
							_compatibleMagazines = compatibleMagazines ((weaponState (vehicle player)) select 1);
						};
						
						_availableMagCount = {_x in _compatibleMagazines} count magazines (vehicle player);
						_currentAmmo = (weaponState (vehicle player)) select 4;
					};

					_ins = lineIntersectsSurfaces [AGLToASL positionCameraToWorld [0,0,0],AGLToASL positionCameraToWorld [0,0,5000],vehicle player,objNull,true,1,"FIRE","NONE"];
					_cursor_distance = if (count _ins > 0) then [{(_ins select 0 select 0) vectorDistance (eyepos player)},{5000}];
					_aim_dist_txt = if (count _ins > 0) then [{str(round _cursor_distance)},{"---"}];

					_P2hudAmmo ctrlSetText format ["%1", _currentAmmo];
					_P2hudAmmo ctrlSetTextColor _infoColor;
					_P2hudAmmo ctrlCommit 0;

					_P2hudMags ctrlSetText format ["%1", _availableMagCount];
					_P2hudMags ctrlSetTextColor _infoColor;
					_P2hudMags ctrlCommit 0;

					_P2hudDir ctrlSetText format["%1°", round(getDir player)];
					_P2hudDir ctrlSetTextColor _infoColor;
					_P2hudDir ctrlCommit 0;
					
					_P2hudRange ctrlSetText format["%1m", _aim_dist_txt];
					_P2hudRange ctrlSetTextColor _infoColor;
					_P2hudRange ctrlCommit 0;
				} else {
					_infoColor = [0,0,0,0];

					_P2hudAmmo ctrlSetText "";
					_P2hudAmmo ctrlSetTextColor _infoColor;
					_P2hudAmmo ctrlCommit 0;

					_P2hudMags ctrlSetText "";
					_P2hudMags ctrlSetTextColor _infoColor;
					_P2hudMags ctrlCommit 0;

					_P2hudDir ctrlSetText "";
					_P2hudDir ctrlSetTextColor _infoColor;
					_P2hudDir ctrlCommit 0;
					
					_P2hudRange ctrlSetText "";
					_P2hudRange ctrlSetTextColor _infoColor;
					_P2hudRange ctrlCommit 0;
				};
				
				if (DISPLAY_INFO && _rc_inhelmet) then {
					_infoColor = INFO_TEXT_COLOR;
					if ((vehicle player) != player) then {
						if ((weaponState [(vehicle player),((assignedVehicleRole player) select 1)] select 0) != "") then {
							_compatibleMagazines = (weaponState [(vehicle player),((assignedVehicleRole player) select 1)] select 3);
							_availableMagCount = {_x in _compatibleMagazines} count ((vehicle player) magazinesTurret [((assignedVehicleRole player) select 1),false]);
							_currentAmmo = (weaponState [(vehicle player),((assignedVehicleRole player) select 1)] select 4);
							if (_availableMagCount > 0) then {
								_availableMagCount = _availableMagCount - 1;
							};
						} else {
							_availableMagCount = "--";
							_currentAmmo = "---";
						};
					} else {
						if (((weaponState (vehicle player)) select 0) == ((weaponState (vehicle player)) select 1)) then {
							_compatibleMagazines = compatibleMagazines (currentWeapon (vehicle player));
						} else {
							_compatibleMagazines = compatibleMagazines ((weaponState (vehicle player)) select 1);
						};
						
						_availableMagCount = {_x in _compatibleMagazines} count magazines (vehicle player);
						_currentAmmo = (weaponState (vehicle player)) select 4;
					};

					_ins = lineIntersectsSurfaces [AGLToASL positionCameraToWorld [0,0,0],AGLToASL positionCameraToWorld [0,0,5000],vehicle player,objNull,true,1,"FIRE","NONE"];
					_cursor_distance = if (count _ins > 0) then [{(_ins select 0 select 0) vectorDistance (eyepos player)},{5000}];
					_aim_dist_txt = if (count _ins > 0) then [{str(round _cursor_distance)},{"---"}];

					_RChudAmmo ctrlSetText format ["%1", _currentAmmo];
					_RChudAmmo ctrlSetTextColor _infoColor;
					_RChudAmmo ctrlCommit 0;

					_RChudMags ctrlSetText format ["%1", _availableMagCount];
					_RChudMags ctrlSetTextColor _infoColor;
					_RChudMags ctrlCommit 0;

					_RChudDir ctrlSetText format["%1°", round(getDir player)];
					_RChudDir ctrlSetTextColor _infoColor;
					_RChudDir ctrlCommit 0;
					
					_RChudRange ctrlSetText format["%1m", _aim_dist_txt];
					_RChudRange ctrlSetTextColor _infoColor;
					_RChudRange ctrlCommit 0;
				} else {
					_infoColor = [0,0,0,0];

					_RChudAmmo ctrlSetText "";
					_RChudAmmo ctrlSetTextColor _infoColor;
					_RChudAmmo ctrlCommit 0;

					_RChudMags ctrlSetText "";
					_RChudMags ctrlSetTextColor _infoColor;
					_RChudMags ctrlCommit 0;

					_RChudDir ctrlSetText "";
					_RChudDir ctrlSetTextColor _infoColor;
					_RChudDir ctrlCommit 0;
					
					_RChudRange ctrlSetText "";
					_RChudRange ctrlSetTextColor _infoColor;
					_RChudRange ctrlCommit 0;
				};
			};
			if ((!(missionnamespace getvariable "SHOW_HUD_OVERLAY") && (_hudCheck)) OR (HUD_hasHelmet && _hudCheck && !HUD_firstPersonCheck)) then {
				HUD_helmetOverlayShown = false;
				call HUD_fnc_removeHudEventhandler;
				(HUD_hudOverlay#0) ctrlSetTextColor [0,0,0,0];
				(HUD_interiorOverlay#0) ctrlSetTextColor [0,0,0,0];
				(HUD_visorEffect#0) ctrlSetTextColor [0,0,0,0];
			};
			
		};

		if (!(HUD_hasHelmet) && _hudActive) then {
			HUD_helmetOverlayShown = false;
			call HUD_fnc_clearHud;
			(HUD_hudOverlay#0) ctrlSetTextColor [0,0,0,0];
			//systemchat "helmet";
		};

	
		sleep 0.1;
	};
	
	player setVariable ["HUD_suitActive",false,true];
	player setVariable ["HUD_active_mode", "none"];
	player setUnitRecoilCoefficient  1;
	player setCustomAimCoef 1;
	
	player setvariable ["HUD_ACTIVE", false];
	player setvariable ["HUD_ALLOWED", false];
	player setVariable ["HUD_hudInitiated", false];
	player setvariable ["HUD_TARGETING_ALLOWED", false];
	player setVariable ["HUD_bootComplete", false];

	HUD_systemMessageAllowed = false;
	HUD_lowLight = false;
	HUD_threatRange = 200;
	HUD_nearUnits = [];

	call HUD_fnc_clearHud;

	setAperture -1;

	"HUD_OVERLAY_LAYER" cutText ["","PLAIN", 1, false];
	"HUD_INDICATOR_LAYER" cutText ["","PLAIN", 1, false];
	"HUD_INFO_LAYER" cutText ["","PLAIN", 1, false];
	"HUD_BOOTUP" cutText ["","PLAIN", 1, false];
};