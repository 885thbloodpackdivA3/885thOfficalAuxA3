/*
    Author: 885th Bloodpack Division
    885_Armor_ACE_Compat - Post-Init

    Wraps ace_medical_damage_fnc_getTypeOfDamage - the function ACE itself
    uses to resolve an ammo's ACE_damageType into the config class it'll use
    for wound handling. We let ACE's own logic run first (so ammo using
    real, already-registered types like "bullet" behave exactly as normal),
    then check whether the resolved type actually exists as a registered
    class under ACE_Medical_Injuries >> damageTypes. If it doesn't - any
    custom ACE_damageType from 885_weapons that we haven't explicitly
    patched, now or in the future - we substitute "unknown" instead, which
    IS already patched with BPD_fnc_shieldWoundHandler in this same config.

    This is what makes the shield future-proof: new blaster ammo added to
    885_weapons later, with any ACE_damageType string, will route through
    "unknown" automatically without needing another class added here.

    Function reassignment like this is safe specifically because ACE's own
    documented convention is to look up handler/type functions BY GLOBAL
    VARIABLE NAME at call time (see the wound handler string values in
    config.cpp), not by a cached reference captured once - so overriding
    the global after ACE's own PreInit has already defined it (which always
    happens before any addon's PostInit runs) reliably intercepts every
    future call.
*/
if (!hasInterface) exitWith {};

private _originalFnc = ace_medical_damage_fnc_getTypeOfDamage;

ace_medical_damage_fnc_getTypeOfDamage = {
    private _resolvedType = _this call _originalFnc;

    if !(isClass (configFile >> "ACE_Medical_Injuries" >> "damageTypes" >> _resolvedType)) then {
        _resolvedType = "unknown";
    };

    _resolvedType
};
