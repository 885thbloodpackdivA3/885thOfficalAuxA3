/*
    Author: 885th Bloodpack Division
    Katarn shield - EMP knockout

    Any player wearing a qualifying Katarn gear set who is caught inside the
    blast radius of EMP ammo (any CfgAmmo with JLTS_isEMPAmmo = 1 - the 885th
    EMP hand grenade, the 885th EMP launcher round, JLTS EMP ammo, etc.) has
    their shield drained to 0 and locked out of recharging for
    AUX_885th_Shield_EMP_Lockout seconds (plus the normal recharge delay).

    Two halves, because shield state only exists on the wearer's own machine
    while the explosion is only observable on the thrower's machine:
      1. Detector  - runs where the EMP projectile is local (the thrower,
                     player or AI/server). On detonation it finds players in
                     the radius and sends each one an event.
      2. Receiver  - runs on the wearer's machine and knocks the shield out.

    Must be called on every machine (not gated behind hasInterface), so that
    AI/server-fired EMPs are detected too.
*/

// --- RECEIVER ---
["885th_shield_empHit", {
    params ["_unit"];

    if (!hasInterface || {_unit != player} || {!alive _unit}) exitWith {};
    if !(missionNamespace getVariable ["AUX_885th_Shield_MasterEnabled", true]) exitWith {};
    if !(missionNamespace getVariable ["AUX_885th_Shield_EMP_Enabled", true]) exitWith {};
    if (isNil "BPD_fnc_shieldGearValid" || {!([_unit] call BPD_fnc_shieldGearValid)}) exitWith {};

    private _wasActive = _unit getVariable ["AUX_Shield_Active", false];
    private _lockout = missionNamespace getVariable ["AUX_885th_Shield_EMP_Lockout", 10];

    // Drain even when the shield is switched off - the emitter is fried either
    // way, so toggling it off can't be used to dodge the EMP.
    _unit setVariable ["AUX_Shield_Current", 0];
    _unit setVariable ["AUX_Shield_Broken", true];
    _unit setVariable ["AUX_Shield_Regenerating", false];
    // The regen loop waits until (now - LastHit) > RegenDelay, so pushing
    // LastHit into the future adds the lockout on top of the normal delay.
    _unit setVariable ["AUX_Shield_LastHit", diag_tickTime + _lockout];

    if (_wasActive) then {
        [_unit] call BPD_fnc_shieldHitFX;
    };
    playSound "AUX_Shield_Shutdown";
    hintSilent "Katarn Armor Systems: EMP DETECTED - SHIELDS OFFLINE.";
}] call CBA_fnc_addEventHandler;

// --- DETECTOR ---
["CAManBase", "FiredMan", {
    params ["_unit", "", "", "", "_ammo", "", "_projectile"];

    // FiredMan can fire on more than one machine; only the machine that owns
    // the projectile will see it explode, so only that one tracks it.
    if (!local _unit || {isNull _projectile}) exitWith {};

    private _ammoCfg = configFile >> "CfgAmmo" >> _ammo;
    if (getNumber (_ammoCfg >> "JLTS_isEMPAmmo") != 1) exitWith {};

    private _radius = getNumber (_ammoCfg >> "indirectHitRange");
    if (_radius <= 0) exitWith {}; // direct-fire EMP bolts have no blast to catch anyone in

    _projectile setVariable ["885th_empRadius", _radius];
    _projectile addEventHandler ["Explode", {
        params ["_projectile", "_posASL"];
        private _radius = _projectile getVariable ["885th_empRadius", 0];
        {
            if (isPlayer _x && {alive _x}) then {
                ["885th_shield_empHit", [_x], _x] call CBA_fnc_targetEvent;
            };
        } forEach ((ASLToAGL _posASL) nearEntities ["CAManBase", _radius]);
    }];
}] call CBA_fnc_addClassEventHandler;
