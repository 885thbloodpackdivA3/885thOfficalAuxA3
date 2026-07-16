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

// --- Health monitor ---
private _bodyPct = round ((1 - (damage _unit)) * 100);
private _armorBars = floor (_bodyPct / 10);

private _barString = "";
for "_i" from 1 to 10 do {
    _barString = _barString + (if (_i <= _armorBars) then ["█"] else ["░"]);
};
(_display displayCtrl 9031) ctrlSetText _barString;

private _bodyColor = [0.2,1,0.2,1]; // green
if (_bodyPct <= 70) then { _bodyColor = [1,0.8,0.2,1]; }; // yellow
if (_bodyPct <= 35) then { _bodyColor = [1,0.2,0.2,1]; }; // red

private _bodyCtrl = _display displayCtrl 9032;
_bodyCtrl ctrlSetText format ["BODY: %1%%", _bodyPct];
_bodyCtrl ctrlSetTextColor _bodyColor;

private _armorCtrl = _display displayCtrl 9031;
_armorCtrl ctrlSetTextColor _bodyColor;

// Bleeding / pain: pulls from ACE Medical if present, otherwise falls back to vanilla damage
private _bleedText = "BLEED: NONE";
private _painText = "PAIN: LOW";
if (isClass (configFile >> "CfgPatches" >> "ace_medical")) then {
    private _bloodLoss = _unit getVariable ["ace_medical_bloodLoss", 0];
    _bleedText = if (_bloodLoss > 0) then ["BLEED: ACTIVE"] else ["BLEED: NONE"];

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

// Placeholder - wire this up to your custom blaster heat variable if/when you add one
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
