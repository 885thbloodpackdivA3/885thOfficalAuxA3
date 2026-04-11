/*
  Runs on every client after mission start.
  Adds embark/disembark actions to qualifying AT-RT man units, including ones created later.
*/

if (!hasInterface) exitWith {};

private _applyIfWalker = {
  params ["_ent"];
  if (isNull _ent) exitWith {};
  if (!alive _ent) exitWith {};
  if !(_ent isKindOf "CAManBase") exitWith {};
  if ([_ent] call ATRT_fnc_isATRT) then {
    [_ent] call ATRT_fnc_addActions;
  };
};

// Apply to already-existing entities
{
  _x call _applyIfWalker;
} forEach (entities [["CAManBase"], [], true, true]);

// Apply to new entities created later
addMissionEventHandler ["EntityCreated", {
  params ["_entity"];
  _entity spawn {
    // slight delay so configOf/typeOf is stable
    uiSleep 0.1;
    [_this] call (missionNamespace getVariable ["ATRT_applyIfWalker", {}]);
  };
}];

// Store closure so EH can call it
missionNamespace setVariable ["ATRT_applyIfWalker", _applyIfWalker];