params ["_center"];

private _radius   = missionNamespace getVariable ["bacta_radius", 10];
private _dStep    = (missionNamespace getVariable ["bacta_damageStep", 0.05]) min 0.15;
private _bandage  = missionNamespace getVariable ["bacta_bandageType", "ACE_fieldDressing"];
private _doStitch = missionNamespace getVariable ["bacta_doStitch", true];
private _doSplint = missionNamespace getVariable ["bacta_doSplint", true];
private _mode     = missionNamespace getVariable ["bacta_mode", 0];

private _hasACE = isClass (configFile >> "CfgPatches" >> "ace_medical");

private _useACE = switch (_mode) do {
  case 1: { false };
  case 2: { _hasACE };
  default { _hasACE };
};

// ACE body parts (lowercase is the most compatible)
private _bps = ["head","body","rightarm","leftarm","rightleg","leftleg"];

// Resolve splint function safely (varies by ACE version)
private _fnSplint = missionNamespace getVariable ["ace_medical_treatment_fnc_splint", nil];

{
  private _u = _x;

  if (!isPlayer _u) then { continue; };
  if (!alive _u) then { continue; };
  if (!local _u) then { continue; };

  _u setDamage (((damage _u) - _dStep) max 0);

  if (_useACE) then {

    [_u, -0.1] call ace_medical_fnc_adjustPainLevel;

    // BANDAGE: exactly one body part per tick
    private _bandagedOne = false;
    {
      if (_bandagedOne) exitWith {};

      if ((count ([_u, _x] call ace_medical_fnc_getOpenWounds)) > 0) then {
        [objNull, _u, _x, _bandage] call ace_medical_treatment_fnc_bandage;
        _bandagedOne = true;
      };
    } forEach _bps;

    // STITCH: exactly one body part per tick
    if (_doStitch) then {
      private _fnStitch = missionNamespace getVariable ["ace_medical_treatment_fnc_stitchWounds", nil];
      if (isNil "_fnStitch") then { _fnStitch = missionNamespace getVariable ["ace_medical_treatment_fnc_stitch", nil]; };

      if (!isNil "_fnStitch") then {
        private _stitchedOne = false;

        {
          if (_stitchedOne) exitWith {};

          private _open      = [_u, _x] call ace_medical_fnc_getOpenWounds;
          private _bandagedW = [_u, _x] call ace_medical_fnc_getBandagedWounds;

          if ((count _open) == 0 && (count _bandagedW) > 0) then {
            [objNull, _u, _x] call _fnStitch;
            _stitchedOne = true;
          };
        } forEach _bps;
      };
    };

    // SPLINT: heal fractured limbs (ONE per tick)
    if (_doSplint && {!isNil "_fnSplint"}) then {
      private _fractures = _u getVariable ["ace_medical_fractures", []];

      if (_fractures isEqualType [] && {(count _fractures) >= 6}) then {
        private _splintedOne = false;

        private _fractureParts = [
          ["LeftArm", 2],
          ["RightArm", 3],
          ["LeftLeg", 4],
          ["RightLeg", 5]
        ];

        {
          if (_splintedOne) exitWith {};

          private _partName = _x select 0;
          private _idx      = _x select 1;

          if ((_fractures select _idx) > 0) then {
            [objNull, _u, _partName] call _fnSplint;
            _splintedOne = true;
          };
        } forEach _fractureParts;
      };
    };

    if ((damage _u) < 0.3 && {_u getVariable ["ACE_isUnconscious", false]}) then {
      [_u, false] call ace_medical_fnc_setUnconscious;
    };
  };

} forEach (_center nearEntities ["CAManBase", _radius]);
