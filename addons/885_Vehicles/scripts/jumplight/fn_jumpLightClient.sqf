/*
	885th - LAAT jump light: client loop (CfgFunctions postInit).

	Every 0.25 s, on machines with an interface:
	  1. Cabin lights - for every aircraft near the camera whose public
	     "BPD_jumpLight" variable is 1 (red) or 2 (green), keep a pair of
	     local #lightpoints attached at the troop doors (GetIn_Cargo /
	     GetIn_Cargo2 memory points, found on both the LAAT/i and LAAT/C).
	     Lights are removed when the state goes off, the aircraft dies or is
	     deleted, or it leaves draw range.
	  2. HUD - if the player sits in an aircraft with the light on, show the
	     RED / GREEN banner (RscTitles BPD_JumpLight_Indicator), and play a
	     cue when the light changes while they are aboard.

	Everything here is local-effect only, so it works the same in SP,
	hosted and dedicated MP, and for JIP players.
*/
if (!hasInterface) exitWith {};

BPD_jumpLight_handle = [] spawn {
	// --- Tunables -----------------------------------------------------------
	private _drawRange   = 1000;	// m - lights only drawn for aircraft this close to the camera
	private _doorPoints  = ["GetIn_Cargo", "GetIn_Cargo2"];
	private _inboard     = 0.6;		// pull the door point this far toward the centreline (x multiplier)
	private _raise       = 1.4;		// m - lift from the get-in point (ground level) to door-top height
	private _brightness  = 0.5;
	private _colours     = [[0, 0, 0], [1, 0.05, 0.03], [0.05, 1, 0.1]];
	// ------------------------------------------------------------------------

	private _fnc_makeLights = {
		params ["_veh", "_state"];
		private _colour = _colours select _state;
		private _lights = [];
		private _offsets = [];
		{
			private _p = _veh selectionPosition [_x, "Memory"];
			if !(_p isEqualTo [0, 0, 0]) then {
				_offsets pushBack [(_p select 0) * _inboard, _p select 1, (_p select 2) + _raise];
			};
		} forEach _doorPoints;
		if (_offsets isEqualTo []) then {_offsets = [[0, 0, 0.5]]};	// model without the door points

		{
			private _l = "#lightpoint" createVehicleLocal [0, 0, 0];
			_l setLightColor _colour;
			_l setLightAmbient _colour;
			_l setLightBrightness _brightness;
			_l setLightDayLight true;
			_l setLightUseFlare true;
			_l setLightFlareSize 0.4;
			_l setLightFlareMaxDistance 400;
			_l lightAttachObject [_veh, _x];
			_lights pushBack _l;
		} forEach _offsets;
		_lights
	};

	private _active  = [];	// [[veh, state, [lights]], ...]
	private _hudVeh   = objNull;
	private _hudState = 0;
	private _layer    = "BPD_JumpLight" call BIS_fnc_rscLayer;

	while {true} do {
		// ---------------- Cabin lights ----------------
		private _near = (positionCameraToWorld [0, 0, 0]) nearEntities ["Air", _drawRange];

		// Drop lights that are stale (off, changed, dead, deleted or out of range)
		_active = _active select {
			_x params ["_veh", "_state", "_lights"];
			private _keep = !isNull _veh
				&& {alive _veh}
				&& {_veh in _near}
				&& {(_veh getVariable ["BPD_jumpLight", 0]) == _state};
			if (!_keep) then {{deleteVehicle _x} forEach _lights};
			_keep
		};

		// Create lights for aircraft that need them
		private _lit = _active apply {_x select 0};
		{
			private _state = _x getVariable ["BPD_jumpLight", 0];
			if (_state > 0 && {alive _x} && {!(_x in _lit)}) then {
				_active pushBack [_x, _state, [_x, _state] call _fnc_makeLights];
			};
		} forEach _near;

		// ---------------- HUD banner ----------------
		private _unit = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];
		if (isNull _unit) then {_unit = player};
		private _veh = objectParent _unit;
		if (isNull _veh) then {_veh = attachedTo _unit};	// AT-RT clamped in the bay rack
		private _state = 0;
		if (!isNull _veh && {alive _veh} && {alive _unit}) then {
			_state = _veh getVariable ["BPD_jumpLight", 0];
		};

		if (_state != _hudState || {_veh != _hudVeh}) then {
			// Audible cue only for a change while staying in the same aircraft
			if (_veh == _hudVeh && {_state != _hudState} && {_state > 0}) then {
				private _snd = ["", "FD_CP_Not_Clear_F", "FD_Start_F"] select _state;
				if (isClass (configFile >> "CfgSounds" >> _snd)) then {playSound _snd};
			};

			if (_state == 0) then {
				_layer cutRsc ["Default", "PLAIN"];
			} else {
				_layer cutRsc ["BPD_JumpLight_Indicator", "PLAIN", 0, false];
				private _disp = uiNamespace getVariable ["BPD_JumpLight_Indicator", displayNull];
				private _ctrl = _disp displayCtrl 77010;
				if (!isNull _ctrl) then {
					if (_state == 1) then {
						_ctrl ctrlSetText "RED LIGHT  -  STAND BY";
						_ctrl ctrlSetBackgroundColor [0.75, 0.05, 0.03, 0.85];
					} else {
						_ctrl ctrlSetText "GREEN LIGHT  -  DISMOUNT";
						_ctrl ctrlSetBackgroundColor [0.05, 0.6, 0.12, 0.85];
					};
				};
			};
			_hudVeh = _veh;
			_hudState = _state;
		};

		sleep 0.25;
	};
};
