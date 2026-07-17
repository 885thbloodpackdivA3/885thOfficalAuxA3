/*
    Function: BPD_HUD_fnc_updateHUD
    Description: Per-frame HUD refresh. Reads local player state only - no network chatter.
*/
if (!hasInterface) exitWith {};
if (missionNamespace getVariable ["BPD_HUD_visible", true] isEqualTo false) exitWith {};

private _display = uiNamespace getVariable ["BPD_HUD_display", displayNull];
if (isNull _display) exitWith {};

private _unit = player;
if (isNull _unit || {!alive _unit}) exitWith {};

// --- Callsign / link ---
private _callsign = _unit getVariable ["BPD_callsign", vehicleVarName _unit];
if (_callsign == "") then { _callsign = "CT-0000"; };
(_display displayCtrl 9011) ctrlSetText format ["%1 | LINK: STABLE", _callsign];

// --- Time / mission timer ---
(_display displayCtrl 9020) ctrlSetText ([daytime] call BIS_fnc_timeToString);
(_display displayCtrl 9021) ctrlSetText format ["T+%1", [missionTime] call BIS_fnc_timeToString];

// --- Health monitor (armor removed) ---
private _damage = damage _unit;
private _bodyPct = round ((1 - _damage) * 100);

private _bodyColor = [0.2,1,0.2,1]; // green
if (_bodyPct <= 70) then { _bodyColor = [1,0.8,0.2,1]; }; // yellow
if (_bodyPct <= 35) then { _bodyColor = [1,0.2,0.2,1]; }; // red

private _bodyCtrl = _display displayCtrl 9032;
_bodyCtrl ctrlSetText format ["BODY: %1%%", _bodyPct];
_bodyCtrl ctrlSetTextColor _bodyColor;

private _bleedText = "BLEED: NONE";
private _painText = "PAIN: LOW";
if (isClass (configFile >> "CfgPatches" >> "ace_medical")) then {
    private _bloodLoss = _unit getVariable ["ace_medical_bloodLoss", 0];
    _bleedText = if (_bloodLoss > 0) then {"BLEED: ACTIVE"} else {"BLEED: NONE"};

    private _pain = _unit getVariable ["ace_medical_pain", 0];
    _painText = "PAIN: LOW";
    if (_pain > 0.2) then { _painText = "PAIN: MED"; };
    if (_pain > 0.6) then { _painText = "PAIN: HIGH"; };
};
(_display displayCtrl 9033) ctrlSetText _bleedText;
(_display displayCtrl 9034) ctrlSetText _painText;

// --- Weapon data ---
private _weapon = currentWeapon _unit;
private _weaponDisplayName = "UNARMED";
if (_weapon != "") then {
    _weaponDisplayName = getText (configFile >> "CfgWeapons" >> _weapon >> "displayName");
};
(_display displayCtrl 9040) ctrlSetText _weaponDisplayName;

(_display displayCtrl 9041) ctrlSetText format ["MODE: %1", toUpper (currentWeaponMode _unit)];

private _magCount = 0;
private _magMax = 0;
private _currentMag = currentMagazine _unit;
if (_weapon != "" && {_currentMag != ""}) then {
    _magCount = _unit ammo _weapon;
    _magMax = getNumber (configFile >> "CfgMagazines" >> _currentMag >> "count");
};
(_display displayCtrl 9042) ctrlSetText format ["MAG: %1/%2", _magCount, _magMax];

private _temp = _unit getVariable ["BPD_weaponTemp", 0];
(_display displayCtrl 9043) ctrlSetText format ["TEMP: %1%%", round _temp];

// --- Squad tracker ---
private _group = group _unit;
private _lines = [];
{
    private _tag = _x getVariable ["BPD_callsign", vehicleVarName _x];
    if (_tag == "") then { _tag = format ["A%1", _forEachIndex + 1]; };
    private _status = "[OK]";
    if (!alive _x) then {
        _status = "[X]";
    } else {
        if (damage _x > 0.5) then { _status = "[!]"; };
    };
    _lines pushBack format ["%1 %2", _tag, _status];
} forEach (units _group);
(_display displayCtrl 9051) ctrlSetText (_lines joinString "\n");

// --- Compass ---
(_display displayCtrl 9060) ctrlSetText format ["%1°", round (getDir _unit)];

// --- Visor overlay (gos_hud-style, disabled until a texture path is set) ---
private _overlayCtrl = _display displayCtrl 9070;
private _overlayTexture = missionNamespace getVariable ["BPD_HUD_OverlayTexture", ""];
if (_overlayTexture == "") then {
    _overlayCtrl ctrlShow false;
} else {
    private _overlayOpacity = missionNamespace getVariable ["BPD_HUD_OverlayOpacity", 0.5];
    _overlayCtrl ctrlShow true;
    _overlayCtrl ctrlSetText _overlayTexture;
    _overlayCtrl ctrlSetFade (1 - _overlayOpacity);
    _overlayCtrl ctrlCommit 0;
};

// --- Crack overlay (shown once damage crosses the CBA threshold) ---
private _crackCtrl = _display displayCtrl 9071;
private _crackTexture = missionNamespace getVariable ["BPD_HUD_CrackTexture", ""];
private _crackThreshold = missionNamespace getVariable ["BPD_HUD_CrackThreshold", 0.5];
if (_crackTexture == "" || {_damage < _crackThreshold}) then {
    _crackCtrl ctrlShow false;
} else {
    private _crackAlpha = ((_damage - _crackThreshold) / (1 - _crackThreshold)) max 0.3 min 1;
    _crackCtrl ctrlShow true;
    _crackCtrl ctrlSetText _crackTexture;
    _crackCtrl ctrlSetFade (1 - _crackAlpha);
    _crackCtrl ctrlCommit 0;
};

// --- Directional damage corners ---
{
    (_display displayCtrl _x) ctrlSetTextColor [1, 0.08, 0.08, 0];
} forEach [9080, 9081, 9082, 9083];

private _damageEndTime = missionNamespace getVariable ["BPD_HUD_damageIndicatorEndTime", -1];
if (_damageEndTime > time) then {
    private _damageDuration = missionNamespace getVariable ["BPD_HUD_DamageIndicatorDuration", 1.2];
    private _remaining = _damageEndTime - time;
    private _fade = (_remaining / _damageDuration) max 0 min 1;
    private _dir = missionNamespace getVariable ["BPD_HUD_damageDirection", "all"];

    private _showTL = _dir in ["front", "left", "all"];
    private _showTR = _dir in ["front", "right", "all"];
    private _showBR = _dir in ["back", "right", "all"];
    private _showBL = _dir in ["back", "left", "all"];

    if (_showTL) then { (_display displayCtrl 9080) ctrlSetTextColor [1, 0.08, 0.08, _fade]; };
    if (_showTR) then { (_display displayCtrl 9081) ctrlSetTextColor [1, 0.08, 0.08, _fade]; };
    if (_showBR) then { (_display displayCtrl 9082) ctrlSetTextColor [1, 0.08, 0.08, _fade]; };
    if (_showBL) then { (_display displayCtrl 9083) ctrlSetTextColor [1, 0.08, 0.08, _fade]; };
};
