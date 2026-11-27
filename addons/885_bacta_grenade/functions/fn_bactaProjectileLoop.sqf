// Runs on the thrower's machine (spawned from the FiredMan handler in
// XEH_postInit.sqf) for that machine's local copy of the projectile.
params ["_proj"];
if (isNull _proj) exitWith {};

// Guard against the same projectile being handed in twice
if (_proj getVariable ["bacta_loopRunning", false]) exitWith {};
_proj setVariable ["bacta_loopRunning", true];

// Don't heal while the grenade is still in the air: wait for the fuse
// (explosionTime = 2 in CfgAmmo) before the first tick.
private _fuse = getNumber (configFile >> "CfgAmmo" >> typeOf _proj >> "explosionTime");
sleep (_fuse max 0);

while { !isNull _proj } do {
  [_proj] call bacta_fnc_bactaHealArea;
  sleep (missionNamespace getVariable ["bacta_tick", 3]);
};
