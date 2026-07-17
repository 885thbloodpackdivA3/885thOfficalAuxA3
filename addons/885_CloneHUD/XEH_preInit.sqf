/*
    885th Clone HUD - CBA Settings
    All settings are client-side (isGlobal = false) - each player configures
    their own HUD via Configure > Addon Options > "885th Clone HUD".
*/

// --- Existing settings (unchanged) ---
[
    "BPD_HUD_enabled",
    "CHECKBOX",
    ["Enable Clone HUD", "Master on/off switch for the 885th Clone HUD"],
    ["885th Clone HUD", "General"],
    true,
    false,
    {
        params ["_value"];
        if (!hasInterface) exitWith {};
        if (isNull player) exitWith {};

        if (_value) then {
            [player] call BPD_HUD_fnc_initHUD;
        } else {
            if (!isNil "BPD_HUD_updatePFH") then {
                [BPD_HUD_updatePFH] call CBA_fnc_removePerFrameHandler;
                BPD_HUD_updatePFH = nil;
            };
            "BPD_CloneHUD_Main" cutText ["", "PLAIN"];
            private _oldAction = player getVariable ["BPD_HUD_actionID", -1];
            if (_oldAction != -1) then {
                player removeAction _oldAction;
                player setVariable ["BPD_HUD_actionID", -1];
            };
        };
    }
] call CBA_fnc_addSetting;

[
    "BPD_HUD_updateInterval",
    "SLIDER",
    ["HUD Refresh Rate (s)", "How often the HUD redraws. Lower = smoother, slightly higher cost"],
    ["885th Clone HUD", "General"],
    [0.1, 1, 0.2, 1],
    false,
    {
        params ["_value"];
        if (!hasInterface) exitWith {};
        if (isNil "BPD_HUD_updatePFH") exitWith {};
        [BPD_HUD_updatePFH] call CBA_fnc_removePerFrameHandler;
        BPD_HUD_updatePFH = [{ call BPD_HUD_fnc_updateHUD; }, _value] call CBA_fnc_addPerFrameHandler;
    }
] call CBA_fnc_addSetting;

[
    "BPD_HUD_scrollAction",
    "CHECKBOX",
    ["Scroll-Wheel Toggle", "Adds a 'Toggle Clone HUD' scroll-wheel action"],
    ["885th Clone HUD", "General"],
    true,
    false,
    {
        params ["_value"];
        if (!hasInterface) exitWith {};
        if (isNull player) exitWith {};

        private _oldAction = player getVariable ["BPD_HUD_actionID", -1];
        if (_oldAction != -1) then {
            player removeAction _oldAction;
            player setVariable ["BPD_HUD_actionID", -1];
        };

        if (_value) then {
            private _actionID = player addAction [
                "<t color='#4DE6FF'>Toggle Clone HUD</t>",
                { call BPD_HUD_fnc_toggleHUD; },
                nil, 1.5, false, true, "", "true", 5
            ];
            player setVariable ["BPD_HUD_actionID", _actionID];
        };
    }
] call CBA_fnc_addSetting;

[
    "BPD_HUD_bootAnimation",
    "CHECKBOX",
    ["Boot Sequence Animation", "Play the helmet boot-up text sequence on spawn"],
    ["885th Clone HUD", "General"],
    true,
    false,
    {}
] call CBA_fnc_addSetting;

// --- New settings (gos_hud-inspired visor/crack/damage/target features) ---
[
    "BPD_HUD_OverlayTexture",
    "EDITBOX",
    ["Visor overlay texture", "Texture path for the full-screen visor overlay. Leave blank to disable - no art is bundled with this addon."],
    ["885th Clone HUD", "Visor"],
    "",
    false
] call CBA_fnc_addSetting;

[
    "BPD_HUD_OverlayOpacity",
    "SLIDER",
    ["Visor overlay opacity", "How visible the visor overlay texture is"],
    ["885th Clone HUD", "Visor"],
    [0, 1, 0.5, 2],
    false
] call CBA_fnc_addSetting;

[
    "BPD_HUD_CrackTexture",
    "EDITBOX",
    ["Crack overlay texture", "Texture path for the visor crack overlay shown at low health. Leave blank to disable."],
    ["885th Clone HUD", "Visor"],
    "",
    false
] call CBA_fnc_addSetting;

[
    "BPD_HUD_CrackThreshold",
    "SLIDER",
    ["Crack damage threshold", "Damage level (0-1) at which the visor crack overlay appears"],
    ["885th Clone HUD", "Visor"],
    [0, 1, 0.5, 2],
    false
] call CBA_fnc_addSetting;

[
    "BPD_HUD_DamageIndicatorDuration",
    "SLIDER",
    ["Damage indicator duration (s)", "How long the directional damage corners stay lit after being hit"],
    ["885th Clone HUD", "Damage"],
    [0.2, 3, 1.2, 2],
    false
] call CBA_fnc_addSetting;

[
    "BPD_HUD_TargetRecognition",
    "CHECKBOX",
    ["Target Recognition", "Shows friendly/hostile name tags over nearby units you're looking at"],
    ["885th Clone HUD", "Target Recognition"],
    true,
    false
] call CBA_fnc_addSetting;

[
    "BPD_HUD_TargetMaxDistance",
    "SLIDER",
    ["Target Recognition max distance (m)", "Maximum distance at which target name tags appear"],
    ["885th Clone HUD", "Target Recognition"],
    [20, 500, 150, 0],
    false
] call CBA_fnc_addSetting;
