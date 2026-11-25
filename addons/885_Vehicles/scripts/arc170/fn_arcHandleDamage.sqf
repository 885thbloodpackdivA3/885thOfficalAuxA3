/*
    Author: 885th Bloodpack Division
    BPD_fnc_arcHandleDamage - ARC-170 HandleDamage EH body.

    Runs only where the aircraft is local. Returning nil = "not my business",
    which leaves the engine's (or another mod's) damage untouched.

    One projectile fires this EH several times in the same frame: once for
    the overall hull ("" / hitIndex -1) and once per component hitpoint hit.
    Charging the shield on every call would bill one shot several times, so
    calls are grouped into one "event" per frame + ammo type, and the shield
    is charged the LARGEST weighted cost seen in that event, not the sum.

    Collisions, crashes, fire and fall damage arrive with an empty projectile
    and are deliberately NOT absorbed - otherwise the shield makes the jet
    crash-proof.
*/
params ["_veh", "_selection", "_damage", "_source", "_projectile", "_hitIndex", "_instigator", "_hitPoint"];

if !(missionNamespace getVariable ["AUX_885th_ARC_Enabled", true]) exitWith { nil };
if (_projectile isEqualTo "" || {!alive _veh}) exitWith { nil };

private _old = if (_hitIndex < 0) then { damage _veh } else { _veh getHitIndex _hitIndex };
private _delta = _damage - _old;
if (_delta <= 0) exitWith { nil };

private _key = format ["%1|%2", diag_frameNo, _projectile];
private _evt = _veh getVariable ["BPD_arc_evt", ["", 0, 0]];

if ((_evt select 0) != _key) then {
    // first call for this projectile: decide whether the shield is up for it
    private _up = (_veh getVariable ["BPD_arc_shield", 0]) > 0 && {!(_veh getVariable ["BPD_arc_broken", false])};
    _evt = [_key, 0, [0, 1] select _up];
};
_evt params ["", "_charged", "_absorb"];

if (_absorb <= 0) exitWith {
    _veh setVariable ["BPD_arc_evt", _evt];
    nil
};

private _weight = if (_hitIndex < 0) then { 1 } else { missionNamespace getVariable ["AUX_885th_ARC_HitpointWeight", 0.25] };
// Shields mode hardens the shield, Engines mode leaves it thin
private _modeMult = [1, 0.75, 1.25] select ((_veh getVariable ["BPD_arc_power", 0]) min 2 max 0);
private _cost = _delta * _weight * _modeMult;

if (_cost > _charged) then {
    private _extra = _cost - _charged;
    private _shield = _veh getVariable ["BPD_arc_shield", 0];

    if (_charged == 0) then { [_veh] call BPD_fnc_arcHitFX; };

    if (_shield >= _extra) then {
        _veh setVariable ["BPD_arc_shield", _shield - _extra];
        _veh setVariable ["BPD_arc_lastHit", diag_tickTime];
    } else {
        // shield collapses: it covers what it can, the rest of this hit goes through
        _absorb = (_charged + _shield) / _cost;
        _veh setVariable ["BPD_arc_shield", 0];
        _veh setVariable ["BPD_arc_broken", true, true];
        _veh setVariable ["BPD_arc_lastHit", diag_tickTime + (missionNamespace getVariable ["AUX_885th_ARC_BreakPenalty", 6])];
        [_veh, true] call BPD_fnc_arcHitFX;
    };
    _charged = _cost;
};

_veh setVariable ["BPD_arc_evt", [_key, _charged, _absorb]];

_old + (_delta * (1 - _absorb))
