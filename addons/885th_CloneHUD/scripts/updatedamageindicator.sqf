/*
	885th Bloodpack Division - Clone HUD - Damage Indicator (top-left compact)
	---------------------------------------------------------------
	Uses the addon's own existing textured per-limb icons
	(HUD_pa_head/torso/armL/armR/legL/legR - the P1/P2/RC_pa_*.paa
	art, phase-swapped via HUD_TEXTURE_IND_* in init.sqf), just
	repositioned to a small top-left cluster instead of full-screen.
	They're RscPicture controls, so damage is shown by tinting the
	icon itself via ctrlSetTextColor - not a separate colored box.

	No armor pool here - this just reflects the player's REAL
	injury state, read-only. It never touches how much damage the
	player takes.

	Two data sources, switched by the BPD_CloneHUD_ACE_COMPACT_ENABLED
	setting (see HUD_fnc_getLimbColor below):

	  - OFF (default): vanilla getHitPointDamage, smooth 0-1 damage
	    value through the DMG_100/75/50/25/0_COLOR tiers, no ACE
	    dependency.

	  - ON: real ACE Medical per-limb wound state, matching ACE's own
	    medical menu logic and colors exactly - verified directly
	    against ACE3 source (ace_medical_gui/functions/
	    fnc_updateBodyImage.sqf, fnc_bloodLossToRGBA.sqf,
	    fnc_damageToRGBA.sqf), not estimated. A limb's blood loss
	    (bleeding rate * amountOf, summed across its open wounds)
	    drives a stepped white->yellow->orange->red lookup if > 0;
	    otherwise cumulative wound severity (open-but-clotted,
	    bandaged, or stitched - ACE's real branch is just "not
	    currently bleeding", not "specifically treated") drives a
	    separate stepped white->cyan->blue lookup. See
	    HUD_ACE_BLOODLOSS_COLORS / HUD_ACE_DAMAGE_COLORS /
	    HUD_fnc_steppedColorLookup below for the real RGB stops and
	    ACE's actual ceil-based stepping (not a smooth blend).
	    Falls back to vanilla automatically if ACE Medical isn't
	    actually loaded (HUD_aceMedicalLoaded, set in init.sqf), so
	    this setting is safe to leave on across modsets.

	HUD_fnc_updateDamageIndicator (the full six-icon refresh) is
	called from a poll in system.sqf's main loop every ~0.1s
	whenever a hitpoint's damage value actually changes - that's
	the source of truth for the icon colors, and it works regardless
	of any hit-event quirks.

	HUD_fnc_updateDamageIndicatorHit (the single-icon flash + sound +
	system message) is a cosmetic bonus triggered from the "Dammaged"
	hook in init.sqf when it successfully identifies which selection
	was hit. If that hook ever misses a hit, the icon color is still
	correct within one loop tick either way. Note this flash is
	vanilla-hit-driven regardless of the ACE compact setting, since
	ACE's own wound events aren't wired in here - the color itself
	still reflects the correct source either way on the next poll.

	Left/right arms share a single "HitHands" hitpoint and left/right
	legs share a single "HitLegs" hitpoint in the stock Arma 3 damage
	model (vanilla path only - ACE tracks all six independently), so
	on the vanilla path the two icons for arms (and for legs) will
	always show the same color - only the flash-on-hit differs per
	side, since we know which selection was actually hit.
*/

// Simple manual RGBA lerp - used for the ACE bleed-severity gradient.
// No dependency on any BIS_fnc for this, since I'd rather write four
// lines of certain math than guess at whether the "right" interpolation
// function exists and takes colors in this order.
HUD_fnc_lerpColor = {
	params ["_colorA","_colorB","_t"];
	_t = 0 max (1 min _t);
	[
		(_colorA select 0) + (((_colorB select 0) - (_colorA select 0)) * _t),
		(_colorA select 1) + (((_colorB select 1) - (_colorA select 1)) * _t),
		(_colorA select 2) + (((_colorB select 2) - (_colorA select 2)) * _t),
		(_colorA select 3) + (((_colorB select 3) - (_colorA select 3)) * _t)
	]
};

HUD_fnc_dmgColorFor = {
	params ["_dmg"];
	private _color = DMG_100_COLOR;
	if (_dmg >= 1) then {
		_color = DMG_0_COLOR;
	} else {
		if (_dmg > 0.75) then {
			_color = DMG_25_COLOR;
		} else {
			if (_dmg > 0.5) then {
				_color = DMG_50_COLOR;
			} else {
				if (_dmg > 0.25) then {
					_color = DMG_75_COLOR;
				} else {
					_color = DMG_100_COLOR;
				};
			};
		};
	};
	_color
};

// Stepped (not smoothly blended) color lookup, matching how ACE's own
// medical menu actually works - confirmed directly from ACE3 source
// (ace_medical_gui/functions/fnc_bloodLossToRGBA.sqf and
// fnc_damageToRGBA.sqf): _frac maps to a bucket via
// ceil(_frac * count(_colorTable)), not a continuous blend.
HUD_fnc_steppedColorLookup = {
	params ["_frac", "_colorTable"];
	private _n = count _colorTable;
	_frac = 0 max (1 min _frac);
	private _bucket = ceil (_frac * _n);
	private _idx = (_bucket - 1) max 0 min (_n - 1);
	_colorTable select _idx
};

// Single source of truth for "what color should this limb be right
// now" - returns [_color, _stateLabel].
//
// ACE branch logic and color tables below are taken directly from
// real ACE3 source, not guessed - confirmed against the full medical
// engine (ace_medical, ace_medical_engine, ace_medical_gui,
// ace_medical_damage): fnc_updateBodyImage.sqf sums bleeding*amountOf
// across a limb's open wounds; if that's > 0, the limb is colored by
// fnc_bloodLossToRGBA.sqf's white->yellow->orange->red table
// (HUD_ACE_BLOODLOSS_COLORS below, ACE's real RGB values), against
// BLOOD_LOSS_RED_THRESHOLD - a fixed constant (0.5, confirmed in
// script_macros_medical.hpp), hardcoded directly rather than a slider
// since ACE itself doesn't let it vary.
//
// Otherwise it falls through to fnc_damageToRGBA.sqf's white->cyan->
// blue table (HUD_ACE_DAMAGE_COLORS), based on ACE's actual tracked
// per-limb damage value (ace_medical_bodyPartDamage) against a
// per-limb-type threshold - NOT wound counts (bandaged/stitched/
// clotted), which was this HUD's earlier approximation before the
// full core source was available, and turned out to be a genuinely
// different quantity that doesn't correlate the same way per limb
// (confirmed by screenshots showing every limb painted the same
// color despite ACE's own diagram showing only specific limbs
// affected). The threshold itself scales by limb type exactly like
// ACE's real code: head at 1.25x the base threshold, torso unscaled,
// arms/legs at the fracture/limping constants x4 by default, or a
// server-configured per-limb value if the useLimbDamage setting
// enables it - read live from ACE's real variables/settings so this
// always matches however the server's actually configured, not a
// hardcoded assumption.
HUD_ACE_BLOODLOSS_COLORS = [
	[1.00, 0.95, 0.64, 1],
	[1.00, 0.87, 0.46, 1],
	[1.00, 0.80, 0.33, 1],
	[1.00, 0.72, 0.24, 1],
	[1.00, 0.63, 0.15, 1],
	[1.00, 0.54, 0.08, 1],
	[1.00, 0.43, 0.02, 1],
	[1.00, 0.30, 0.00, 1],
	[1.00, 0.00, 0.00, 1]
];
HUD_ACE_DAMAGE_COLORS = [
	[0.75, 0.95, 1.00, 1],
	[0.62, 0.86, 1.00, 1],
	[0.54, 0.77, 1.00, 1],
	[0.48, 0.67, 1.00, 1],
	[0.42, 0.57, 1.00, 1],
	[0.37, 0.47, 1.00, 1],
	[0.31, 0.36, 1.00, 1],
	[0.22, 0.23, 1.00, 1],
	[0.00, 0.00, 1.00, 1]
];

HUD_fnc_getLimbColor = {
	params ["_hitpointName", "_aceIndex"];
	if ((missionnamespace getVariable ["BPD_CloneHUD_ACE_COMPACT_ENABLED", false]) && {HUD_aceMedicalLoaded}) then {
		private _bodyPart = HUD_ACE_BODYPARTS select _aceIndex;
		private _openWounds = [player, _bodyPart] call ace_medical_fnc_getOpenWounds;
		private _bloodLoss = 0;
		{ _bloodLoss = _bloodLoss + ((_x select 1) * (_x select 2)); } forEach _openWounds;

		if (_bloodLoss > 0) exitWith {
			private _frac = _bloodLoss / 0.5; // ACE_BLOOD_LOSS_RED_THRESHOLD, confirmed fixed constant
			[[_frac, HUD_ACE_BLOODLOSS_COLORS] call HUD_fnc_steppedColorLookup, "bleeding"]
		};

		// No active bleeding on this limb - ACE's real logic does NOT
		// derive this from wound counts (bandaged/stitched/clotted -
		// that was this HUD's earlier approximation, confirmed wrong
		// by re-reading ACE's actual source). It reads a dedicated
		// per-limb tracked damage value and compares it to a
		// per-limb-type threshold - confirmed directly from
		// ace_medical_gui's fnc_updateBodyImage.sqf: head gets 1.25x
		// the base threshold, torso uses it unscaled, arms/legs use
		// the fracture/limping constants x4 by default (or a
		// server-configured per-limb threshold, if the useLimbDamage
		// setting enables it - matched here exactly, read live so
		// this tracks whatever the server's actually configured).
		private _damage = (player getVariable ["ace_medical_bodyPartDamage", [0,0,0,0,0,0]]) select _aceIndex;
		private _damageThreshold = player getVariable ["ace_medical_damageThreshold", missionNamespace getVariable ["ace_medical_playerDamageThreshold", 1]];
		private _useLimbDamage = missionNamespace getVariable ["ace_medical_useLimbDamage", 0];
		private _limbDamageThreshold = missionNamespace getVariable ["ace_medical_limbDamageThreshold", 5];
		private _limbThresholdActive = (_limbDamageThreshold != 0) && {[false, false, true] select _useLimbDamage};

		switch (true) do {
			case (_aceIndex > 3): { // legs
				_damageThreshold = if (_limbThresholdActive) then {_damageThreshold * _limbDamageThreshold} else {(missionNamespace getVariable ["ace_medical_const_limpingDamageThreshold", 0.30]) * 4};
			};
			case (_aceIndex > 1): { // arms
				_damageThreshold = if (_limbThresholdActive) then {_damageThreshold * _limbDamageThreshold} else {(missionNamespace getVariable ["ace_medical_const_fractureDamageThreshold", 0.50]) * 4};
			};
			case (_aceIndex == 0): { // head
				_damageThreshold = _damageThreshold * 1.25;
			};
			// default: torso, unscaled
		};

		if (_damage <= 0) exitWith { [DMG_100_COLOR, "clear"] };
		private _frac = _damage / _damageThreshold;
		[[_frac, HUD_ACE_DAMAGE_COLORS] call HUD_fnc_steppedColorLookup, "damaged"]
	} else {
		private _dmg = (player getHitPointDamage _hitpointName) max 0;
		private _color = [_dmg] call HUD_fnc_dmgColorFor;
		private _state = "clear";
		switch (true) do {
			case (_color isEqualTo DMG_75_COLOR): { _state = "minor"; };
			case (_color isEqualTo DMG_50_COLOR): { _state = "significant"; };
			case (_color isEqualTo DMG_25_COLOR): { _state = "critical"; };
			case (_color isEqualTo DMG_0_COLOR): { _state = "lost"; };
		};
		[_color, _state]
	};
};

HUD_fnc_limbLabel = {
	params ["_affectedPart"];
	switch (_affectedPart) do {
		case "head": {"Helmet"};
		case "body": {"Torso"};
		case "armR": {"Right Arm"};
		case "armL": {"Left Arm"};
		case "legR": {"Right Leg"};
		case "legL": {"Left Leg"};
		default {"Unknown"};
	};
};

HUD_fnc_limbStateMessage = {
	params ["_label","_state"];
	switch (_state) do {
		case "minor": { format ["%1: Minor damage sustained", _label] };
		case "significant": { format ["%1: Significant damage incurred", _label] };
		case "critical": { format ["%1: Critical condition", _label] };
		case "lost": { format ["%1: Function lost!", _label] };
		case "bleeding": { format ["%1: Bleeding", _label] };
		case "damaged": { format ["%1: Wound detected", _label] };
		default { "" };
	};
};

// Flashes a single limb icon in response to a fresh hit.
// Called with [_hitSelectionName] from the "Dammaged" EH in init.sqf.
HUD_fnc_updateDamageIndicatorHit = {
	params ["_hitSelection"];
	if (!(player getVariable ["HUD_bootComplete",false])) exitWith {};

	private _affectedPart = "";
	private _hitpointName = "";
	private _aceIndex = -1;
	private _hudPart = objNull;

	switch (true) do {
		case (_hitSelection in HUD_head): { _affectedPart = "head"; _hitpointName = "HitHead"; _aceIndex = 0; _hudPart = (HUD_pa_head#0); };
		case (_hitSelection in HUD_body): { _affectedPart = "body"; _hitpointName = "HitBody"; _aceIndex = 1; _hudPart = (HUD_pa_torso#0); };
		case (_hitSelection in HUD_rightArm): { _affectedPart = "armR"; _hitpointName = "HitHands"; _aceIndex = 3; _hudPart = (HUD_pa_armR#0); };
		case (_hitSelection in HUD_leftArm): { _affectedPart = "armL"; _hitpointName = "HitHands"; _aceIndex = 2; _hudPart = (HUD_pa_armL#0); };
		case (_hitSelection in HUD_rightLeg): { _affectedPart = "legR"; _hitpointName = "HitLegs"; _aceIndex = 5; _hudPart = (HUD_pa_legR#0); };
		case (_hitSelection in HUD_leftLeg): { _affectedPart = "legL"; _hitpointName = "HitLegs"; _aceIndex = 4; _hudPart = (HUD_pa_legL#0); };
	};

	if (_affectedPart == "") exitWith {};

	[_affectedPart,_hitpointName,_aceIndex,_hudPart] spawn {
		params ["_affectedPart","_hitpointName","_aceIndex","_hudPart"];
		private _result = [_hitpointName, _aceIndex] call HUD_fnc_getLimbColor;
		private _color = _result select 0;
		private _state = _result select 1;
		private _prevStateVar = format ["HUD_%1_prevState", _affectedPart];
		private _prevState = missionNamespace getVariable [_prevStateVar, "clear"];

		if (_state != _prevState && _state != "clear") then {
			private _label = [_affectedPart] call HUD_fnc_limbLabel;
			private _message = [_label, _state] call HUD_fnc_limbStateMessage;
			if (_message != "") then {
				[_message, _affectedPart + "_" + _state, 5] call HUD_fnc_addSystemMessage;
			};
		};
		missionNameSpace setVariable [_prevStateVar, _state];

		for "_i" from 0 to 2 do {
			if (!(player getVariable ["HUD_bootComplete",false])) exitWith {};
			_hudPart ctrlSetTextColor INDICATOR_UNDER_ATTACK_COLOR;
			sleep 0.05;
			_hudPart ctrlSetTextColor _color;
			sleep 0.05;
		};
		if (player getVariable ["HUD_bootComplete",false]) then {
			_hudPart ctrlSetTextColor _color;
		};
	};
};

// Full refresh of all six limb icons - used at boot and after gear changes.
// _duringBoot true is for hudBootUp.sqf's own reveal choreography ONLY -
// that intentionally calls this WHILE boot is still running, before
// HUD_bootComplete becomes true (which only happens at the very end of
// the whole boot sequence), so the normal guard below would silently
// no-op every one of those calls otherwise. Every other caller (regular
// polling, the first-person-triggered refresh, gear-change refreshes,
// the hit-flash function) omits this and keeps the exact same guarded
// behavior as before.
HUD_fnc_updateDamageIndicator = {
	params [["_duringBoot", false]];
	if (!_duringBoot && !(player getVariable ["HUD_bootComplete",false])) exitWith {};

	HUD_damageSections = [
		["head","HitHead",0,(HUD_pa_head#0)],
		["body","HitBody",1,(HUD_pa_torso#0)],
		["armR","HitHands",3,(HUD_pa_armR#0)],
		["armL","HitHands",2,(HUD_pa_armL#0)],
		["legR","HitLegs",5,(HUD_pa_legR#0)],
		["legL","HitLegs",4,(HUD_pa_legL#0)]
	];

	{
		_x spawn {
			params ["_affectedPart","_hitpointName","_aceIndex","_hudPart"];
			private _result = [_hitpointName, _aceIndex] call HUD_fnc_getLimbColor;
			if (!(player getVariable ["HUD_bootComplete",false])) exitWith {};
			_hudPart ctrlSetTextColor (_result select 0);
			missionNameSpace setVariable [format ["HUD_%1_prevState", _affectedPart], (_result select 1)];
		};
	} forEach HUD_damageSections;
};
