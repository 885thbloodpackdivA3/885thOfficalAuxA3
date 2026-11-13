/*
 * 885th - EMP droid compatibility
 *
 * JLTS EMP ammo (JLTS_isEMPAmmo = 1, used by 885th_grenade_emp_ammo and
 * 885th_ammo_Grenade_EMP) only kills a unit when JLTS_fnc_onHitEMP decides it
 * is a droid. That check looks at the unit's UNIFORM:
 *   getNumber (CfgWeapons >> uniform >> "JLTS_isDroid") == 1
 *   OR uniform is in missionNamespace "JLTS_emp_affectedUniforms"
 *
 * Several droid mods never set JLTS_isDroid on their uniforms, so EMPs only
 * "fry" their weapons instead of shutting them down. A config patch would hard-
 * require every one of those mods, so instead we register their uniforms
 * (and every subclass of them) in JLTS_emp_affectedUniforms at runtime.
 * Bases from mods that aren't loaded are skipped.
 *
 * Runs on every machine: JLTS evaluates EMP hits through the HitPart XEH,
 * which fires on whichever machine fired the projectile.
 */

// Droid uniform classes (or bases) that lack JLTS_isDroid = 1.
private _droidUniformBases = [
    // 212th Auxiliary - Arcus CIS BX droids
    "212_Arcus_BX_Base_U",
    "212_Arcus_BX_Commando_U",
    "212_Arcus_BX_Diplomat_U",
    "212_Arcus_BX_Captain_U",
    "212_Arcus_BX_Citadel_U",
    "212th_BX_DROID_SNIPER_U",
    "212th_BX_DROID_SPOTTER_U",
    "Aux212_Fake_Clone_Trooper_Armor_CT", // BX droid disguised in clone armor

    // 3AS-style CIS droid bases (defined via MRC / 212th; covers Aux212_3AS_U_CIS_B2)
    "3AS_U_CIS_B2",
    "3AS_U_CIS_TS",

    // MRC CIS - B2 / BX / Tactical droids
    "MRC_cis_uniform_B2",
    "MRC_cis_uniform_B2_Grenadier",
    "MRC_cis_uniform_BX",
    "MRC_cis_uniform_TD",

    // Legion Base (legacy build) droids
    "ls_cis_b1Droid_uniform",
    "ls_cis_b1Hologram_uniform",
    "ls_cis_b1Simulation_uniform",
    "ls_cis_b1Saboteur_uniform",
    "ls_cis_b1Training_uniform",
    "ls_cis_b1Geonosis_uniform",
    "ls_cis_bxTraining_uniform",
    "ls_cis_bxSecurityDroid_uniform",
    "ls_cis_bxDiplomatDroid_uniform",
    "ls_cis_bxCaptainDroid_uniform",
    "lsd_cis_b2Droid_uniform",
    "lsd_cis_tSeries_uniform",
    "lsd_cis_b1Saboteur_uniform",
    "lsd_cis_b1Training_uniform",
    "lsd_cis_b1Geonosis_uniform",
    "lsd_cis_bxDroid_uniform",
    "lsd_cis_bxTraining_uniform",
    "lsd_cis_bxSecurityDroid_uniform",
    "lsd_cis_bxDiplomatDroid_uniform",
    "lsd_cis_bxScout_uniform",
    "lsd_cis_bxP1Trooper_uniform",       // BX droid disguised in clone armor
    "lsd_cis_bxP2Trooper_uniform",       // BX droid disguised in clone armor
    "lsd_hologram_bxDroid_uniform",
    "lsd_activeCamo_bxDroid_uniform",

    // SFA assault droids
    "SFA_MKI_UniBase",
    "SFA_MkIV_UniBase",

    // Droid_Unit (LF) B1s
    "LF_B1_LP",

    // G1 Android
    "SC_Uniform_Androids_Base"
];

private _cfgWeapons = configFile >> "CfgWeapons";
private _bases = (_droidUniformBases select {isClass (_cfgWeapons >> _x)}) apply {toLower _x};
if (_bases isEqualTo []) exitWith {};

// Keep anything a mission (or another mod) already registered.
private _affected = +(missionNamespace getVariable ["JLTS_emp_affectedUniforms", []]);
private _affectedLower = _affected apply {toLower _x};

private _uniforms = "isClass (_x >> 'ItemInfo') && {getText (_x >> 'ItemInfo' >> 'uniformClass') != ''}" configClasses _cfgWeapons;

{
    private _cls = configName _x;
    if (getNumber (_x >> "JLTS_isDroid") != 1 && {!(toLower _cls in _affectedLower)}) then {
        private _lineage = ([_x, true] call BIS_fnc_returnParents) apply {toLower _x};
        if (_bases findIf {_x in _lineage} > -1) then {
            _affected pushBack _cls;
            _affectedLower pushBack toLower _cls;
        };
    };
} forEach _uniforms;

missionNamespace setVariable ["JLTS_emp_affectedUniforms", _affected];
