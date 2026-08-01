/*
    885_Armor_ACE_Compat

    Standalone compatibility PBO. Requires BOTH 885_Armor and ace_medical, so
    Arma will simply skip loading this entire addon whenever ACE isn't
    present - 885_Armor itself has no ACE dependency and keeps working fine
    on its own (vanilla HandleDamage path) either way.

    This patches ACE's wound handler chain (the officially documented
    extension point - see https://ace3.acemod.org/wiki/framework/medical-framework)
    to route damage through BPD_fnc_shieldWoundHandler (defined in
    885_Armor's own XEH_postInit.sqf) BEFORE ACE's default handler creates
    any wounds. We deliberately do NOT touch HandleDamage here - ACE's own
    docs are explicit that another addon doing so "is virtually guaranteed
    to break ACE's handling."

    KAT Advanced Medical is not patched separately here because KAT runs on
    top of ACE's same wound/damage engine rather than replacing it, so this
    same hook covers both. If a future KAT version changes that, this file
    is the one to revisit.

    Damage types patched: bullet, grenade, explosive, shell, vehiclehit,
    vehiclecrash, collision, falling, backblast, stab, punch, unknown, and
    plasma (885_weapons' blaster ammo - a brand new custom type, not one of
    ACE's built-ins, registered fresh rather than extending an existing class).
    Deliberately NOT patched: drowning, fire, burn, ropeburn - a personal
    deflector shield blocking asphyxiation or rope friction doesn't make
    thematic sense. Remove any class below if you want it excluded too.

    IMPORTANT: each entry's value is "{ _this call BPD_fnc_shieldWoundHandler }"
    rather than just "BPD_fnc_shieldWoundHandler" directly. ACE resolves/caches
    these config values early, and per ACE issue #8927, if the referenced
    global function doesn't exist YET at that exact moment (cross-addon
    PostInit ordering isn't guaranteed, and BPD_fnc_shieldWoundHandler is
    defined in 885_Armor's own PostInit), ACE silently caches nil and never
    calls it again - no error, it just does nothing forever. Wrapping it in
    an inline anonymous function makes the compiled value valid immediately;
    the actual lookup of BPD_fnc_shieldWoundHandler only happens later, at
    the moment of a real hit, by which point it's guaranteed to be defined.
*/

class CfgPatches
{
    class 885_Armor_ACE_Compat
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 2.10;
        requiredAddons[] = {"885th_Armor", "ace_medical"};
        author = "885th Bloodpack Division";
        version = "1.1";
    };
};

class Extended_PostInit_EventHandlers
{
    class 885_Armor_ACE_Compat_PostInit
    {
        init = "call compile preprocessFileLineNumbers '\885_Armor_Ace_Compat\scripts\XEH_postInit.sqf'";
    };
};

class ACE_Medical_Injuries
{
    class damageTypes
    {
        // Forward declaration - required here specifically because this
        // patch lives in a SEPARATE PBO from ACE. Even though the real
        // "woundHandlers" class is already defined by ace_medical, this
        // file's own parser needs an explicit visible declaration of it
        // before "class woundHandlers : woundHandlers" below can resolve
        // as a valid parent to inherit from. Without this line you get
        // "Undefined base class 'woundHandlers'" on every damage type below.
        class woundHandlers;

        class bullet
        {
            class woundHandlers : woundHandlers
            {
                BPD_shieldMitigation = "{ _this call BPD_fnc_shieldWoundHandler }";
            };
        };
        class grenade
        {
            class woundHandlers : woundHandlers
            {
                BPD_shieldMitigation = "{ _this call BPD_fnc_shieldWoundHandler }";
            };
        };
        class explosive
        {
            class woundHandlers : woundHandlers
            {
                BPD_shieldMitigation = "{ _this call BPD_fnc_shieldWoundHandler }";
            };
        };
        class shell
        {
            class woundHandlers : woundHandlers
            {
                BPD_shieldMitigation = "{ _this call BPD_fnc_shieldWoundHandler }";
            };
        };
        class vehiclehit
        {
            class woundHandlers : woundHandlers
            {
                BPD_shieldMitigation = "{ _this call BPD_fnc_shieldWoundHandler }";
            };
        };
        class vehiclecrash
        {
            class woundHandlers : woundHandlers
            {
                BPD_shieldMitigation = "{ _this call BPD_fnc_shieldWoundHandler }";
            };
        };
        class collision
        {
            class woundHandlers : woundHandlers
            {
                BPD_shieldMitigation = "{ _this call BPD_fnc_shieldWoundHandler }";
            };
        };
        class falling
        {
            class woundHandlers : woundHandlers
            {
                BPD_shieldMitigation = "{ _this call BPD_fnc_shieldWoundHandler }";
            };
        };
        class backblast
        {
            class woundHandlers : woundHandlers
            {
                BPD_shieldMitigation = "{ _this call BPD_fnc_shieldWoundHandler }";
            };
        };
        class stab
        {
            class woundHandlers : woundHandlers
            {
                BPD_shieldMitigation = "{ _this call BPD_fnc_shieldWoundHandler }";
            };
        };
        class punch
        {
            class woundHandlers : woundHandlers
            {
                BPD_shieldMitigation = "{ _this call BPD_fnc_shieldWoundHandler }";
            };
        };
        class unknown
        {
            class woundHandlers : woundHandlers
            {
                BPD_shieldMitigation = "{ _this call BPD_fnc_shieldWoundHandler }";
            };
        };

        // NEW - "plasma" is the ACE_damageType declared by 885_weapons' blaster
        // bolt ammo (885th_blasterbolt). This is NOT one of ACE's built-in
        // damage types (bullet/grenade/explosive/etc) - it doesn't exist
        // anywhere in ACE's own config at all, so it was never falling back
        // to "unknown" or anything else we'd already patched. ACE's lookup
        // for a damage type is an exact class-name match; if the class
        // doesn't exist, ACE just uses hardcoded internal defaults with NO
        // wound handler chain, meaning our hook was structurally unreachable
        // for every hit from this weapon regardless of shield state. This
        // follows ACE's own documented pattern for registering a brand new
        // damage type (see "Adding new damage types" in the medical
        // framework docs) rather than extending an existing one.
        //
        // If other custom ammo in 885_weapons declares a DIFFERENT
        // ACE_damageType value (check each ammo class's ACE_damageType
        // property), each one needs its own class here the same way.
        class plasma
        {
            thresholds[] = {{0.1, 1}};
            selectionSpecific = 1;
            class woundHandlers : woundHandlers
            {
                BPD_shieldMitigation = "{ _this call BPD_fnc_shieldWoundHandler }";
            };
        };
    };
};