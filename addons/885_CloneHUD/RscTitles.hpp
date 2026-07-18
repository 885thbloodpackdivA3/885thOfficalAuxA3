class RscText;
class RscPicture;
class RscTitles
{
    // ---------------------------------------------------------------
    // Boot sequence overlay
    // ---------------------------------------------------------------
    class BPD_CloneHUD_Boot
    {
        idd = -1;
        onLoad = "uiNamespace setVariable ['BPD_HUD_bootDisplay', (_this select 0)]";
        duration = 1e+007;
        fadein = 0;
        fadeout = 0.3;
        name = "BPD_CloneHUD_Boot";
        controlsBackground[] = {};
        objects[] = {};
        controls[] = { "BPD_bootText" };

        class BPD_bootText: RscText
        {
            idc = 9001;
            x = "safezoneX + safezoneW * 0.3";
            y = "safezoneY + safezoneH * 0.42";
            w = "safezoneW * 0.4";
            h = "safezoneH * 0.16";
            colorBackground[] = {0,0,0,0};
            colorText[] = {0.3,0.9,1,1};
            font = "PuristaBold";
            sizeEx = 0.04;
            style = 2; // center
            text = "";
        };
    };

    // ---------------------------------------------------------------
    // Persistent HUD
    // ---------------------------------------------------------------
    class BPD_CloneHUD_Main
    {
        idd = -1;
        onLoad = "uiNamespace setVariable ['BPD_HUD_display', (_this select 0)]";
        duration = 1e+007;
        fadein = 0;
        fadeout = 0;
        name = "BPD_CloneHUD_Main";
        controlsBackground[] = {};
        objects[] = {};
        controls[] = {
            "BPD_hud_overlay","BPD_hud_crack",
            "BPD_hud_callsign","BPD_hud_link",
            "BPD_hud_time","BPD_hud_missionTimer",
            "BPD_hud_bodyLabel","BPD_hud_bleedLabel","BPD_hud_painLabel",
            "BPD_hud_weaponName","BPD_hud_weaponMode","BPD_hud_weaponMag","BPD_hud_weaponTemp",
            "BPD_hud_heading","BPD_hud_objDist",
            "BPD_hud_cornerTL","BPD_hud_cornerTR","BPD_hud_cornerBR","BPD_hud_cornerBL"
        };

        class BPD_HUDBase: RscText
        {
            colorBackground[] = {0,0,0,0};
            font = "PuristaBold";
        };

        // --- Full-screen visor overlay + crack (behind everything else) ---
        // Both are hidden until a texture path is set via CBA settings -
        // no art is bundled with this addon, so nothing draws until you
        // point these at your own PAA files (visor_ca.paa style assets).
        class BPD_hud_overlay: RscPicture
        {
            idc = 9070;
            x = "safezoneX";
            y = "safezoneY";
            w = "safezoneW";
            h = "safezoneH";
            colorText[] = {1,1,1,1};
            text = "";
        };
        class BPD_hud_crack: RscPicture
        {
            idc = 9071;
            x = "safezoneX";
            y = "safezoneY";
            w = "safezoneW";
            h = "safezoneH";
            colorText[] = {1,1,1,1};
            text = "";
        };

        // --- Top left: unit / link status ---
        class BPD_hud_callsign: BPD_HUDBase
        {
            idc = 9010;
            x = "safezoneX + 0.02 * safezoneW";
            y = "safezoneY + 0.02 * safezoneH";
            w = "0.24 * safezoneW";
            h = "0.028 * safezoneH";
            colorText[] = {0.3,0.9,1,0.9};
            sizeEx = 0.022;
            text = "885TH BLOODPACK";
        };
        class BPD_hud_link: BPD_HUDBase
        {
            idc = 9011;
            x = "safezoneX + 0.02 * safezoneW";
            y = "safezoneY + 0.048 * safezoneH";
            w = "0.24 * safezoneW";
            h = "0.024 * safezoneH";
            colorText[] = {0.3,0.9,1,0.75};
            sizeEx = 0.018;
            text = "CT-0000 | LINK: STABLE";
        };

        // --- Top right: time / mission timer ---
        class BPD_hud_time: BPD_HUDBase
        {
            idc = 9020;
            x = "safezoneX + safezoneW * 0.76";
            y = "safezoneY + 0.02 * safezoneH";
            w = "0.22 * safezoneW";
            h = "0.024 * safezoneH";
            colorText[] = {0.3,0.9,1,0.9};
            sizeEx = 0.02;
            style = 1;
            text = "00:00";
        };
        class BPD_hud_missionTimer: BPD_HUDBase
        {
            idc = 9021;
            x = "safezoneX + safezoneW * 0.76";
            y = "safezoneY + 0.044 * safezoneH";
            w = "0.22 * safezoneW";
            h = "0.022 * safezoneH";
            colorText[] = {0.3,0.9,1,0.7};
            sizeEx = 0.017;
            style = 1;
            text = "T+00:00:00";
        };

        // --- Left side: health monitor (armor removed) ---
        class BPD_hud_bodyLabel: BPD_HUDBase
        {
            idc = 9032;
            x = "safezoneX + 0.02 * safezoneW";
            y = "safezoneY + safezoneH * 0.7";
            w = "0.18 * safezoneW";
            h = "0.022 * safezoneH";
            colorText[] = {0.2,1,0.2,1};
            sizeEx = 0.018;
            text = "BODY: 100%";
        };
        class BPD_hud_bleedLabel: BPD_HUDBase
        {
            idc = 9033;
            x = "safezoneX + 0.02 * safezoneW";
            y = "safezoneY + safezoneH * 0.727";
            w = "0.18 * safezoneW";
            h = "0.02 * safezoneH";
            colorText[] = {0.6,0.6,0.6,1};
            sizeEx = 0.016;
            text = "BLEED: NONE";
        };
        class BPD_hud_painLabel: BPD_HUDBase
        {
            idc = 9034;
            x = "safezoneX + 0.02 * safezoneW";
            y = "safezoneY + safezoneH * 0.751";
            w = "0.18 * safezoneW";
            h = "0.02 * safezoneH";
            colorText[] = {0.6,0.6,0.6,1};
            sizeEx = 0.016;
            text = "PAIN: LOW";
        };

        // --- Right side: weapon data ---
        class BPD_hud_weaponName: BPD_HUDBase
        {
            idc = 9040;
            x = "safezoneX + safezoneW * 0.8";
            y = "safezoneY + safezoneH * 0.7";
            w = "0.18 * safezoneW";
            h = "0.022 * safezoneH";
            colorText[] = {1,0.8,0.2,1};
            sizeEx = 0.02;
            style = 1;
            text = "DC-15A";
        };
        class BPD_hud_weaponMode: BPD_HUDBase
        {
            idc = 9041;
            x = "safezoneX + safezoneW * 0.8";
            y = "safezoneY + safezoneH * 0.726";
            w = "0.18 * safezoneW";
            h = "0.02 * safezoneH";
            colorText[] = {0.8,0.8,0.8,1};
            sizeEx = 0.016;
            style = 1;
            text = "MODE: AUTO";
        };
        class BPD_hud_weaponMag: BPD_HUDBase
        {
            idc = 9042;
            x = "safezoneX + safezoneW * 0.8";
            y = "safezoneY + safezoneH * 0.752";
            w = "0.18 * safezoneW";
            h = "0.022 * safezoneH";
            colorText[] = {1,1,1,1};
            sizeEx = 0.018;
            style = 1;
            text = "MAG: 38/40";
        };
        class BPD_hud_weaponTemp: BPD_HUDBase
        {
            idc = 9043;
            x = "safezoneX + safezoneW * 0.8";
            y = "safezoneY + safezoneH * 0.778";
            w = "0.18 * safezoneW";
            h = "0.02 * safezoneH";
            colorText[] = {0.3,0.9,1,1};
            sizeEx = 0.016;
            style = 1;
            text = "TEMP: 24%";
        };

        // --- Bottom center: compass ---
        class BPD_hud_heading: BPD_HUDBase
        {
            idc = 9060;
            x = "safezoneX + safezoneW * 0.42";
            y = "safezoneY + safezoneH * 0.9";
            w = "0.16 * safezoneW";
            h = "0.026 * safezoneH";
            colorText[] = {0.3,0.9,1,1};
            sizeEx = 0.022;
            style = 2;
            text = "000°";
        };
        class BPD_hud_objDist: BPD_HUDBase
        {
            idc = 9061;
            x = "safezoneX + safezoneW * 0.42";
            y = "safezoneY + safezoneH * 0.93";
            w = "0.16 * safezoneW";
            h = "0.02 * safezoneH";
            colorText[] = {0.3,0.9,1,0.75};
            sizeEx = 0.016;
            style = 2;
            text = "OBJ: ---m";
        };

        // --- Damage direction corners (flash red on hit, gos_hud-style) ---
        class BPD_hud_cornerTL: BPD_HUDBase
        {
            idc = 9080;
            x = "safezoneX";
            y = "safezoneY";
            w = "safezoneW * 0.18";
            h = "safezoneH * 0.14";
            colorText[] = {1,0.08,0.08,0};
            sizeEx = 0.05;
            text = "◤";
        };
        class BPD_hud_cornerTR: BPD_HUDBase
        {
            idc = 9081;
            x = "safezoneX + safezoneW * 0.82";
            y = "safezoneY";
            w = "safezoneW * 0.18";
            h = "safezoneH * 0.14";
            colorText[] = {1,0.08,0.08,0};
            sizeEx = 0.05;
            style = 1;
            text = "◥";
        };
        class BPD_hud_cornerBR: BPD_HUDBase
        {
            idc = 9082;
            x = "safezoneX + safezoneW * 0.82";
            y = "safezoneY + safezoneH * 0.86";
            w = "safezoneW * 0.18";
            h = "safezoneH * 0.14";
            colorText[] = {1,0.08,0.08,0};
            sizeEx = 0.05;
            style = 1;
            text = "◢";
        };
        class BPD_hud_cornerBL: BPD_HUDBase
        {
            idc = 9083;
            x = "safezoneX";
            y = "safezoneY + safezoneH * 0.86";
            w = "safezoneW * 0.18";
            h = "safezoneH * 0.14";
            colorText[] = {1,0.08,0.08,0};
            sizeEx = 0.05;
            text = "◣";
        };
    };
};
