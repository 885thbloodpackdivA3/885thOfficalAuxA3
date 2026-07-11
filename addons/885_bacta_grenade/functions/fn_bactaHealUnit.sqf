// Runs LOCALLY on whichever machine owns _u (dispatched via CBA_fnc_targetEvent).
// This is the only place damage/ACE treatment is actually applied.
params ["_u"];

if (isNull _u) exitWith {};
if (!alive _u) exitWith {};
if (!local _u) exitWith {}; // safety net — should always be true given how this is dispatched

private _dStep    = (missionNamespace getVariable ["bacta_damageStep", 0.05]) min 0.15;
private _bandage  = missionNamespace getVariable ["bacta_bandageType", "ACE_fieldDressing"];
private _doStitch = missionNamespace getVariable ["bacta_doStitch", true];
private _doSplint = missionNamespace getVariable ["bacta_doSplint", true];
private _mode     = missionNamespace getVariable ["bacta_mode", 0];
private _perTick  = missionNamespace getVariable ["bacta_partsPerTick", 0]; // 0 = unlimited

private _hasACE = isClass (configFile >> "CfgPatches" >> "ace_medical");

private _useACE = switch (_mode) do {
  case 1: { false };
  case 2: { _hasACE };
  default { _hasACE };
};

private _bps = ["head","body","rightarm","leftarm","rightleg","leftleg"];
private _fnSplint = missionNamespace getVariable ["ace_medical_treatment_fnc_splint", nil];

_u setDamage (((damage _u) - _dStep) max 0);

if (_useACE) then {

  [_u, -0.1] call ace_medical_fnc_adjustPainLevel;

  // BANDAGE: up to _perTick wounded body parts this tick (0 = all of them)
  private _bandageLimit = if (_perTick <= 0) then { count _bps } else { _perTick };
  private _bandagedN = 0;
  {
    if (_bandagedN >= _bandageLimit) exitWith {};
    if ((count ([_u, _x] call ace_medical_fnc_getOpenWounds)) > 0) then {
      [objNull, _u, _x, _bandage] call ace_medical_treatment_fnc_bandage;
      _bandagedN = _bandagedN + 1;
    };
  } forEach _bps;

  // STITCH: up to _perTick bandaged-but-not-yet-closed body parts this tick (0 = all of them)
  if (_doStitch) then {
    private _fnStitch = missionNamespace getVariable ["ace_medical_treatment_fnc_stitchWounds", nil];
    if (isNil "_fnStitch") then { _fnStitch = missionNamespace getVariable ["ace_medical_treatment_fnc_stitch", nil]; };

    if (!isNil "_fnStitch") then {
      private _stitchLimit = if (_perTick <= 0) then { count _bps } else { _perTick };
      private _stitchedN = 0;
      {
        if (_stitchedN >= _stitchLimit) exitWith {};

        private _open      = [_u, _x] call ace_medical_fnc_getOpenWounds;
        private _bandagedW = [_u, _x] call ace_medical_fnc_getBandagedWounds;

        if ((count _open) == 0 && (count _bandagedW) > 0) then {
          [objNull, _u, _x] call _fnStitch;
          _stitchedN = _stitchedN + 1;
        };
      } forEach _bps;
    };
  };

  // SPLINT: up to _perTick fractured limbs this tick (0 = all of them)
  if (_doSplint && {!isNil "_fnSplint"}) then {
    private _fractures = _u getVariable ["ace_medical_fractures", []];

    if (_fractures isEqualType [] && {(count _fractures) >= 6}) then {
      private _fractureParts = [
        ["LeftArm", 2],
        ["RightArm", 3],
        ["LeftLeg", 4],
        ["RightLeg", 5]
      ];

      private _splintLimit = if (_perTick <= 0) then { count _fractureParts } else { _perTick };
      private _splintedN = 0;
      {
        if (_splintedN >= _splintLimit) exitWith {};

        private _partName = _x select 0;
        private _idx      = _x select 1;

        if ((_fractures select _idx) > 0) then {
          [objNull, _u, _partName] call _fnSplint;
          _splintedN = _splintedN + 1;
        };
      } forEach _fractureParts;
    };
  };

  if ((damage _u) < 0.3 && {_u getVariable ["ACE_isUnconscious", false]}) then {
    [_u, false] call ace_medical_fnc_setUnconscious;
  };
};
