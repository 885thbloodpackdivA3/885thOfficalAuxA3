params ["_projectile", "_target"];
if (isNull _target) exitWith {};
if !(_target isKindOf "LandVehicle"
    || _target isKindOf "Air"
    || _target isKindOf "Ship") exitWith {};
if (_target getVariable ["BP_IonDisabled",false]) exitWith {};
_target setVariable ["BP_IonDisabled",true,true];
private _engineDamage = damage _target;
_target engineOn false;
_target setFuel 0;
_target setHitPointDamage ["HitEngine",0.95];
if (_target isKindOf "Air") then
{
    _target setHitPointDamage ["HitAvionics",0.95];
};
_target setVehicleAmmo 0.15;
{
    _x disableAI "TARGET";
    _x disableAI "AUTOTARGET";
} forEach crew _target;
[
    _target,
    _engineDamage
] spawn
{
    params ["_veh","_oldDamage"];
    sleep 30;
    if (alive _veh) then
    {
        _veh setFuel 1;
        _veh setHitPointDamage ["HitEngine",_oldDamage];
        if (_veh isKindOf "Air") then
        {
            _veh setHitPointDamage ["HitAvionics",0];
        };
        {
            _x enableAI "TARGET";
            _x enableAI "AUTOTARGET";
        } forEach crew _veh;
        _veh setVariable ["BP_IonDisabled",false,true];
    };
};
