/*
    Function: BPD_HUD_fnc_initHUD
    Description: Displays the persistent HUD and starts its per-frame updater.
                 Safe to call multiple times (e.g. on respawn) - clears the old PFH first.
*/
params [["_unit", player]];

if (!hasInterface) exitWith {};
if (_unit != player) exitWith {};
if !(missionNamespace getVariable ["BPD_HUD_enabled", true]) exitWith {};

if (!isNil "BPD_HUD_updatePFH") then {
    [BPD_HUD_updatePFH] call CBA_fnc_removePerFrameHandler;
    BPD_HUD_updatePFH = nil;
};

"BPD_CloneHUD_Main" cutRsc ["BPD_CloneHUD_Main", "PLAIN"];

missionNamespace setVariable ["BPD_HUD_visible", true];

private _interval = missionNamespace getVariable ["BPD_HUD_updateInterval", 0.2];
BPD_HUD_updatePFH = [{ call BPD_HUD_fnc_updateHUD; }, _interval] call CBA_fnc_addPerFrameHandler;

// --- Scroll-wheel action (only if enabled in settings) ---
private _oldAction = _unit getVariable ["BPD_HUD_actionID", -1];
if (_oldAction != -1) then {
    _unit removeAction _oldAction;
    _unit setVariable ["BPD_HUD_actionID", -1];
};

if (missionNamespace getVariable ["BPD_HUD_scrollAction", true]) then {
    private _actionID = _unit addAction [
        "<t color='#4DE6FF'>Toggle Clone HUD</t>",
        { call BPD_HUD_fnc_toggleHUD; },
        nil,
        1.5,
        false,
        true,
        "",
        "true",
        5
    ];
    _unit setVariable ["BPD_HUD_actionID", _actionID];
};

if !(isNil "BPD_HUD_radarPFH") then {
    [BPD_HUD_radarPFH] call CBA_fnc_removePerFrameHandler;
    BPD_HUD_radarPFH = nil;
};
call BPD_HUD_fnc_destroyRadar;
call BPD_HUD_fnc_createRadar;
BPD_HUD_radarPFH = [{ call BPD_HUD_fnc_updateRadar; }, 0.05] call CBA_fnc_addPerFrameHandler;

// --- Damage direction tracking (drives the corner flash indicators) ---
if (isNil { _unit getVariable "BPD_HUD_damageEH" }) then {
    private _dmgEH = _unit addEventHandler ["HandleDamage", {
        params ["_dmgUnit", "_selection", "_damage", "_source"];

        private _dir = "all";
        if (!isNull _source && {_source != _dmgUnit}) then {
            private _incomingDir = (getPosATL _dmgUnit) getDir (getPosATL _source);
            private _relativeDir = _incomingDir - (getDirVisual _dmgUnit);
            _relativeDir = _relativeDir - (360 * floor (_relativeDir / 360));

            if (_relativeDir >= 315 || _relativeDir < 45) then { _dir = "front"; };
            if (_relativeDir >= 45 && _relativeDir < 135) then { _dir = "right"; };
            if (_relativeDir >= 135 && _relativeDir < 225) then { _dir = "back"; };
            if (_relativeDir >= 225 && _relativeDir < 315) then { _dir = "left"; };
        };

        private _duration = missionNamespace getVariable ["BPD_HUD_DamageIndicatorDuration", 1.2];
        missionNamespace setVariable ["BPD_HUD_damageDirection", _dir];
        missionNamespace setVariable ["BPD_HUD_damageIndicatorEndTime", time + _duration];

        _damage
    }];
    _unit setVariable ["BPD_HUD_damageEH", _dmgEH];
};

// --- Target recognition (text-only 3D name tags, no art required) ---
if (isNil { _unit getVariable "BPD_HUD_draw3DEH" }) then {
    private _drawEH = addMissionEventHandler ["Draw3D", {
        if !(missionNamespace getVariable ["BPD_HUD_TargetRecognition", true]) exitWith {};
        if !(missionNamespace getVariable ["BPD_HUD_enabled", true]) exitWith {};

        private _target = cursorTarget;
        if (isNull _target || {!alive _target}) exitWith {};

        private _validKind = false;
        {
            if (_target isKindOf _x) exitWith { _validKind = true; };
        } forEach ["CAManBase", "LandVehicle", "Air", "Ship", "StaticWeapon"];
        if (!_validKind) exitWith {};

        if (side _target == civilian) exitWith {};

        private _maxDist = missionNamespace getVariable ["BPD_HUD_TargetMaxDistance", 150];
        if ((player distance _target) > _maxDist) exitWith {};

        private _relation = (side group player) getFriend (side _target);
        private _color = [0.2, 1, 0.2, 0.95];
        private _label = "";

        if (_relation < 0.6) then {
            _color = [1, 0.15, 0.15, 0.95];
            private _typeName = if (_target isKindOf "CAManBase") then {
                "HOSTILE"
            } else {
                getText (configFile >> "CfgVehicles" >> typeOf _target >> "displayName")
            };
            _label = format ["HOSTILE\n%1\n%2m", _typeName, round (player distance _target)];
        } else {
            private _name = if (_target isKindOf "CAManBase") then { name _target } else {
                getText (configFile >> "CfgVehicles" >> typeOf _target >> "displayName")
            };
            _label = format ["▲ %1\n%2m", _name, round (player distance _target)];
        };

        private _pos = if (_target isKindOf "CAManBase") then {
            ASLToAGL eyePos _target
        } else {
            ASLToAGL visiblePositionASL _target
        };
        _pos set [2, (_pos select 2) + 0.4];

        // Transparent 1x1 procedural texture - lets drawIcon3D render text
        // only, with no bundled art required.
        drawIcon3D ["#(argb,8,8,3)color(1,1,1,0)", _color, _pos, 0, 0, 0, _label, 1, 0.035, "PuristaBold", "center", false];
    }];
    _unit setVariable ["BPD_HUD_draw3DEH", _drawEH];
};
