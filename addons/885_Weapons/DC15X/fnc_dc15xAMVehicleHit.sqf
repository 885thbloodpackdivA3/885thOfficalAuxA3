/*
 * BPD_fnc_dc15xAMVehicleHit
 * A DC-15X anti-materiel round hit this vehicle. Each hit adds 50% damage to every engine, turret and gun
 * hitpoint, so two good hits take them to 100%: the vehicle can't drive and its weapons can't fire, but it
 * isn't blown up. The round's own damage still applies on top. Repairing the vehicle clears it as usual.
 *
 * Runs where the vehicle is local (sent by BPD_fnc_dc15xAMFired via the CBA "BPD_dc15xAMVehicleHit" event).
 * Aircraft lose their engines too, so a flying one will come down.
 *
 * Arguments: 0: Vehicle <OBJECT>
 */
params [["_vehicle", objNull, [objNull]]];

if (!alive _vehicle || {!local _vehicle}) exitWith {};

private _perHit = 0.5;   // 2 hits = disabled

(getAllHitPointsDamage _vehicle) params [["_names", []], "", ["_damage", []]];
{
    private _name = toLower _x;
    if (_name find "engine" >= 0 || {_name find "turret" >= 0} || {_name find "gun" >= 0}) then {
        _vehicle setHitIndex [_forEachIndex, ((_damage select _forEachIndex) + _perHit) min 1];
    };
} forEach _names;
