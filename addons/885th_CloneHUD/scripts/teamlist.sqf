/*
	885th Bloodpack Division - Clone HUD - Team Member List
	---------------------------------------------------------------
	Placed by the Layout settings (SQUAD, see layout.sqf) - its own
	element, no longer tied to the damage indicator. Shows the player's
	squad name, then one line per squad member: name, role, status,
	and distance - capped at 12 members (a full vanilla Arma squad)
	so a larger custom group can't overflow the box. The squad leader
	is sorted to the top of the list and tagged "(Leader)" in gold,
	and the player's own row is tagged "(You)", rather than either
	being shown separately.

	Role is LEAD for the squad leader; otherwise inferred from
	loadout (see HUD_fnc_roleFor) since there's no built-in "role"
	concept in vanilla Arma. Status is OK (green) or KIA (red) - dead
	members now stay in the list instead of disappearing, matching
	how a real squad roster would show a casualty rather than just
	silently shrinking the list.

	Gated on BPD_CloneHUD_TEAM_LIST_ENABLED (master on/off for the
	whole widget).

	Optional ACE enhancements, gated on the SAME
	BPD_CloneHUD_ACE_COMPACT_ENABLED toggle the personal damage
	indicator's ACE data source uses (one switch for "ACE stuff is
	on" rather than a second toggle) - and only applied to living
	members, since a dead member's wound state isn't meaningful
	anymore:
	  - Team color: each member's name is colored by their vanilla
	    assignedTeam (RED/GREEN/BLUE/YELLOW/MAIN) - this is actually
	    a vanilla Arma concept, not ACE-specific, but it's bundled
	    under the same switch since both are "nice to have when
	    running the full ACE setup".
	  - Wound status: each member's distance is colored using the
	    same ACE-matched blood-loss/damage gradient logic as the
	    personal indicator (HUD_fnc_getUnitWoundColor below, mirrors
	    HUD_fnc_getLimbColor in updateDamageIndicator.sqf, loaded
	    before this file).

	Updates on its own slow loop (HUD_fnc_teamListLoop, ~1s) rather
	than the tight ~0.1s poll in system.sqf - a roster list doesn't
	need sub-second precision, and structured text is a heavier
	operation than a color tint.
*/

// [r,g,b,a] 0-1 floats -> "#RRGGBB" hex string for structured text tags.
// Written by hand with toArray/toString on a character-code lookup
// rather than assuming a BIS_fnc_ hex helper exists - didn't want to
// guess at another function name this session.
HUD_fnc_byteToHex = {
	params ["_byte"];
	private _hexChars = toArray "0123456789ABCDEF";
	private _hi = floor (_byte / 16);
	private _lo = _byte mod 16;
	toString [(_hexChars select _hi), (_hexChars select _lo)]
};

HUD_fnc_colorToHex = {
	params ["_color"];
	private _r = round ((_color select 0) * 255);
	private _g = round ((_color select 1) * 255);
	private _b = round ((_color select 2) * 255);
	format ["#%1%2%3", [_r] call HUD_fnc_byteToHex, [_g] call HUD_fnc_byteToHex, [_b] call HUD_fnc_byteToHex]
};

// Worst current wound state across all six ACE body parts for _unit.
// Same tiering as the personal indicator: any open wound beats
// bandaged beats stitched beats clear. Returns [_color, _stateLabel].
HUD_fnc_getUnitWoundColor = {
	params ["_unit"];
	private _worstBloodLoss = 0;

	{
		private _openWounds = [_unit, _x] call ace_medical_fnc_getOpenWounds;
		private _bloodLoss = 0;
		{ _bloodLoss = _bloodLoss + ((_x select 1) * (_x select 2)); } forEach _openWounds;
		_worstBloodLoss = _worstBloodLoss max _bloodLoss;
	} forEach HUD_ACE_BODYPARTS;

	if (_worstBloodLoss > 0) exitWith {
		private _frac = _worstBloodLoss / 0.5; // ACE_BLOOD_LOSS_RED_THRESHOLD, confirmed fixed constant
		[[_frac, HUD_ACE_BLOODLOSS_COLORS] call HUD_fnc_steppedColorLookup, "bleeding"]
	};

	// No active bleeding anywhere - ACE's real logic reads a
	// dedicated per-limb tracked damage value against a per-limb-type
	// threshold (see updateDamageIndicator.sqf's HUD_fnc_getLimbColor
	// for the full explanation and source reference), not wound
	// counts. Compare fractions (not raw damage) across limbs since
	// each limb type has a different threshold.
	private _bodyPartDamage = _unit getVariable ["ace_medical_bodyPartDamage", [0,0,0,0,0,0]];
	private _damageThresholdBase = _unit getVariable ["ace_medical_damageThreshold", missionNamespace getVariable ["ace_medical_playerDamageThreshold", 1]];
	private _useLimbDamage = missionNamespace getVariable ["ace_medical_useLimbDamage", 0];
	private _limbDamageThreshold = missionNamespace getVariable ["ace_medical_limbDamageThreshold", 5];
	private _limbThresholdActive = (_limbDamageThreshold != 0) && {[false, !isPlayer _unit, true] select _useLimbDamage};

	private _worstFrac = 0;
	{
		private _damage = _bodyPartDamage select _forEachIndex;
		private _damageThreshold = _damageThresholdBase;
		switch (true) do {
			case (_forEachIndex > 3): { // legs
				_damageThreshold = if (_limbThresholdActive) then {_damageThreshold * _limbDamageThreshold} else {(missionNamespace getVariable ["ace_medical_const_limpingDamageThreshold", 0.30]) * 4};
			};
			case (_forEachIndex > 1): { // arms
				_damageThreshold = if (_limbThresholdActive) then {_damageThreshold * _limbDamageThreshold} else {(missionNamespace getVariable ["ace_medical_const_fractureDamageThreshold", 0.50]) * 4};
			};
			case (_forEachIndex == 0): { // head
				_damageThreshold = _damageThreshold * 1.25;
			};
			// default: torso, unscaled
		};
		_worstFrac = _worstFrac max (_damage / _damageThreshold);
	} forEach HUD_ACE_BODYPARTS;
	if (_worstFrac <= 0) exitWith { [DMG_100_COLOR, "clear"] };
	[[_worstFrac, HUD_ACE_DAMAGE_COLORS] call HUD_fnc_steppedColorLookup, "damaged"]
};

// assignedTeam -> color. Vanilla concept (assignedTeam/assignTeam), not
// ACE-specific, but only shown when the ACE compact toggle is on.
HUD_fnc_teamColorFor = {
	params ["_unit"];
	switch (assignedTeam _unit) do {
		case "RED": { [1,0.2,0.2,1] };
		case "GREEN": { [0.3,1,0.3,1] };
		case "BLUE": { [0.3,0.6,1,1] };
		case "YELLOW": { [1,0.9,0.2,1] };
		default { [1,1,1,1] };
	};
};

// Loadout-based role, since there's no built-in "this unit's role is
// AT/medic/rifleman" concept in vanilla Arma - inferred instead:
// medic status first (checking ACE's own per-unit medic class
// variable, falling back to the base-game unit trait that ACE's own
// medic check itself falls back to - real logic, not guessed, from
// ace_medical_treatment_fnc_isMedic), then launcher presence for AT,
// defaulting to rifleman. The squad leader's row overrides this with
// "LEAD" instead, handled where this is called.
HUD_fnc_roleFor = {
	params ["_unit"];
	private _medicClass = _unit getVariable ["ace_medical_medicClass", parseNumber (_unit getUnitTrait "medic")];
	if (_medicClass >= 1) exitWith {"MED"};
	if (secondaryWeapon _unit != "") exitWith {"AT"};
	"RFL"
};

HUD_fnc_updateTeamList = {
	if (!(BPD_CloneHUD_TEAM_LIST_ENABLED)) exitWith {
		(HUD_teamList#0) ctrlSetStructuredText parseText "";
	};
	if (!(player getVariable ["HUD_bootComplete",false])) exitWith {};

	private _aceEnhanced = (missionnamespace getVariable ["BPD_CloneHUD_ACE_COMPACT_ENABLED", false]) && {HUD_aceMedicalLoaded};
	private _grp = group player;
	private _squadLeader = leader _grp;
	private _squadName = groupId _grp;
	// Text scales with the squad list's Layout scale setting.
	private _s = missionNamespace getVariable ["BPD_CloneHUD_teamListTextScale", 1];
	private _lines = format ["<t size='%2' align='left'>%1</t><br/>", _squadName, 1.1 * _s];

	// Cap at 12 - a full vanilla Arma squad - so a larger custom group
	// can't overflow the list box. Squad leader goes first regardless
	// of their position in the group's own internal member order.
	//
	// Includes the player themselves now, tagged "(You)" - excluding
	// self meant that whenever the player IS the squad leader, the
	// leader could never appear in their own list at all, and the
	// roster would always be exactly one member short.
	private _members = units _grp;
	if (_squadLeader in _members) then {
		_members = [_squadLeader] + (_members - [_squadLeader]);
	};
	_members = _members select [0, (12 min (count _members))];

	{
		private _distance = round (player distance _x);
		private _isAlive = alive _x;
		private _nameColor = "#ffffff";
		private _distColor = "#ffffff";
		private _woundState = "clear";

		if (_aceEnhanced && _isAlive) then {
			private _woundResult = [_x] call HUD_fnc_getUnitWoundColor;
			_nameColor = [[_x] call HUD_fnc_teamColorFor] call HUD_fnc_colorToHex;
			_distColor = [(_woundResult select 0)] call HUD_fnc_colorToHex;
			_woundState = _woundResult select 1;
		};

		private _statusText = "OK";
		private _statusColor = "#3cb371";
		if (!_isAlive) then {
			_statusText = "KIA";
			_statusColor = "#ff3b30";
		} else {
			// WOUNDED covers both the ACE-tracked bleeding/damaged
			// states and, when ACE isn't enabled, a plain vanilla
			// damage check - so the status still means something
			// either way rather than just being OK/KIA with nothing
			// in between.
			private _isWounded = if (_aceEnhanced) then {_woundState != "clear"} else {(damage _x) > 0};
			if (_isWounded) then {
				_statusText = "WOUNDED";
				_statusColor = "#ffa500";
			};
		};

		private _role = if (_x == _squadLeader) then {"LEAD"} else {[_x] call HUD_fnc_roleFor};

		private _leaderTag = "";
		if (_x == _squadLeader) then {
			_leaderTag = " <t align='left' color='#ffd700'>(Leader)</t>";
		};
		if (_x == player) then {
			_leaderTag = _leaderTag + " <t align='left' color='#00bfff'>(You)</t>";
		};

		_lines = _lines + format [
			"<t size='%9' align='left' color='%1'>%2</t>%3 <t size='%10' align='left' color='#cccccc'>%4</t> <t size='%10' align='left' color='%5'>%6</t> <t size='%9' align='left' color='%7'>%8m</t><br/>",
			_nameColor, name _x, _leaderTag, _role, _statusColor, _statusText, _distColor, _distance, _s, 0.9 * _s
		];
	} forEach _members;

	(HUD_teamList#0) ctrlSetStructuredText parseText _lines;
};

HUD_fnc_teamListLoop = {
	// HUD_suit_activation spawns this once per life, not once per
	// HUD activation - so this needs its own outer loop (matching
	// HUD_fnc_system's lifecycle: alive, still has the uniform, suit
	// not disabled) to survive multiple deactivate/reactivate cycles
	// within the same life. Without it, the inner while below would
	// run once, exit for good the first time the player deactivates,
	// and never resume on a later reactivation - it's a one-shot
	// spawn, not something that gets spawned fresh each activation.
	diag_log format ["885th_CloneHUD: HUD_fnc_teamListLoop starting - alive=%1, HUD_hasUniform=%2, HUD_suitDisabled=%3.", alive player, (player getvariable ["HUD_hasUniform",false]), (player getVariable "HUD_suitDisabled")];
	while {alive player && (player getvariable ["HUD_hasUniform",false]) && !(player getVariable "HUD_suitDisabled")} do {
		// Wait for boot to actually finish (HUD_bootComplete, not
		// HUD_ALLOWED/HUD_indicatorsActive - those flip true partway
		// through boot's own reveal choreography, not when it's
		// actually done).
		waitUntil {sleep 0.5; !(alive player) || {player getVariable ["HUD_bootComplete",false]}};
		while {player getVariable ["HUD_bootComplete",false]} do {
			call HUD_fnc_updateTeamList;
			sleep 1;
		};
	};
};
