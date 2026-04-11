params ["_unit"];

if (isNull _unit) exitWith {};
if (!local _unit) exitWith {};   // only run where unit is local

// Spawn crouched (use the HOLD state, not the transition)
_unit switchMove "Walker_crouched_deadpose";

// Optional: also set stance so engine thinks it's crouched
_unit setUnitPos "MIDDLE";