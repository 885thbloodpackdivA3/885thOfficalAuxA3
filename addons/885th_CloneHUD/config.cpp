class CfgPatches
{
	// Class name kept as-is on purpose: CBA versioning below and any
	// requiredAddons[] in other 885th addons key off this exact name.
	class Adcole885th_CloneHUD
	{
		name = "885th Bloodpack Division - Clone HUD";
		author = "885th Bloodpack Division";
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"cba_main"};
		requiredVersion = 0.1;
		version = 1.3;
		versionStr = "1.3.0";
		versionAr[] = {1,3,0};
	};
};

// ---------------------------------------------------------------------------
// 885th Bloodpack Division - Clone HUD
// Client-side only - every script here only ever reads or writes the LOCAL
// player's own variables/controls, so it runs identically in the editor,
// singleplayer, hosted MP, and on a dedicated server. Requires CBA (for the
// in-game settings menu and keybinds) but no ACE.
// ---------------------------------------------------------------------------

class Extended_Preinit_EventHandlers
{
	class HUD_settings_init
	{
		init = "execVM '\885th_CloneHUD\scripts\settings.sqf';";
	};
};

class Extended_PostInit_EventHandlers
{
	class HUD_script_init
	{
		init = "execVM '\885th_CloneHUD\scripts\init.sqf';";
	};
};

class CfgSettings
{
	class CBA
	{
		class Versioning
		{
			class Adcole885th_CloneHUD
			{
				main_addon = "Adcole885th_CloneHUD";
				class Dependencies
				{
					CBA[] = {"cba_main", {3,5,0}, "true"};
				};
			};
		};
	};
};

class RscTitles
{
	// Namespaced so these never collide with the engine's own RscTitles
	// base classes (or another addon's same-named local copies) -
	// "RscText"/"RscStructuredText"/"RscControlsGroup"/"Default" are
	// also the names of Bohemia's OWN built-in GUI base classes, and
	// config merging in Arma 3 is global and name-based: a bare
	// redefinition of those names here silently overwrites the
	// engine's versions for the entire game session, not just this
	// mission - main menu and other mods' GUI included. That's almost
	// certainly what was causing the frame drop.
	class BPD_CloneHUD_RscStructuredText
	{
		deletable = 0;
		fade = 0;
		access = 0;
		type = 13;
		idc = -1;
		style = 0;
		colorText[] = {1,1,1,1};
		class Attributes
		{
			font = "RobotoCondensed";
			color = "#ffffff";
			colorLink = "#D09B43";
			align = "left";
			shadow = 1;
		};
		x = 0;
		y = 0;
		h = 0.035;
		w = 0.1;
		text = "";
		size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		shadow = 1;
	};
	class BPD_CloneHUD_RscControlsGroup
	{
		deletable = 0;
		fade = 0;
		class VScrollbar
		{
			color[] = {0,0,0,0};
			width = 0.021;
			autoScrollEnabled = 0;
		};
		class HScrollbar
		{
			color[] = {0,0,0,0};
			height = 0.028000001;
		};
		class Controls {};
		type = 15;
		idc = -1;
		x = 0;
		y = 0;
		w = 1;
		h = 1;
		shadow = 0;
		style = 16;
	};
	class BPD_CloneHUD_RscText
	{
		deletable = 0;
		fade = 0;
		access = 0;
		type = 0;
		idc = -1;
		colorBackground[] = {0,0,0,0};
		colorText[] = {1,1,1,1};
		text = "";
		fixedWidth = 0;
		x = 0;
		y = 0;
		h = 0.037;
		w = 0.30000001;
		style = 2;
		shadow = 0;
		colorShadow[] = {0,0,0,0};
		font = "RobotoCondensed";
		SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		linespacing = 1;
		tooltipColorText[] = {1,1,1,1};
		tooltipColorBox[] = {1,1,1,1};
		tooltipColorShade[] = {0,0,0,0.64999998};
	};
	class BPD_CloneHUD_OVERLAY_BASE
	{
		idd = 2077004;
		fadeIn = 0;
		fadeOut = 0;
		duration = 9.9999998e+010;
		x = "safeZoneX";
		y = "safeZoneY";
		w = "safeZoneW";
		h = "safeZoneH";
		onLoad = "uiNamespace setVariable ['BPD_CloneHUD_OVERLAY_BASE',_this select 0]";
	};
	class BPD_CloneHUD_INDICATOR_BASE
	{
		idd = 2077005;
		fadeIn = 0;
		fadeOut = 0;
		duration = 9.9999998e+010;
		x = "safeZoneX";
		y = "safeZoneY";
		w = "safeZoneW";
		h = "safeZoneH";
		onLoad = "uiNamespace setVariable ['BPD_CloneHUD_INDICATOR_BASE',_this select 0]";
	};
	class HUD_BOOTUP
	{
		idd = 9999;
		name = "HUD_gui";
		onLoad = "uiNamespace setVariable ['HUD_BOOTUP', _this select 0];";
		unload = "uiNamespace setVariable ['HUD_BOOTUP', nil];";
		movingEnable = 1;
		fadein = 0;
		fadeout = 0;
		duration = 100000;
		class Controls
		{
			class HUD_BOOTUP_CONTROLGROUP: BPD_CloneHUD_RscControlsGroup
			{
				idc = 110863;
				x = "0.0101562 * safezoneW + safezoneX";
				y = "0.049 * safezoneH + safezoneY";
				w = "0.599062 * safezoneW";
				h = "1.374 * safezoneH";
				class Controls
				{
					class HUD_BOOTUP_TEXTFIELD: BPD_CloneHUD_RscStructuredText
					{
						idc = 10863;
						text = "";
						x = "-5.40912e-007 * safezoneW";
						y = "0 * safezoneH";
						w = "1 * safezoneW";
						h = "3 * safezoneH";
						colorText[] = {0,0,0,1};
						style = 2;
						colorBackground[] = {0,0,0,0};
						shadow = 0;
						class Attributes
						{
							font = "RobotoCondensed";
							SizeEx = "0.158 * safezoneH";
							color = "#000000";
							colorLink = "#D09B43";
							align = "left";
							valign = "bottom";
							shadow = "false";
							shadowColor = "#ffffff";
						};
					};
				};
			};
		};
	};
	class HUD_INFO
	{
		idd = 9999;
		name = "HUD_gui";
		onLoad = "uiNamespace setVariable ['HUD_INFO', _this select 0];";
		unload = "uiNamespace setVariable ['HUD_INFO', nil];";
		movingEnable = 1;
		fadein = 0;
		fadeout = 0;
		duration = 100000;
		class Controls
		{
			class P1_INFO_AMMO: BPD_CloneHUD_RscText { idc=40860; text="---"; x="0.855781 * safezoneW + safezoneX"; y="0.8365 * safezoneH + safezoneY"; w="0.04125 * safezoneW"; h="0.044 * safezoneH"; SizeEx="0.06 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
			class P1_INFO_MAGS: BPD_CloneHUD_RscText { idc=40861; text="---"; x="0.855781 * safezoneW + safezoneX"; y="0.882 * safezoneH + safezoneY"; w="0.04125 * safezoneW"; h="0.044 * safezoneH"; SizeEx="0.06 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
			class P1_INFO_DIR: BPD_CloneHUD_RscText { idc=40862; text="---"; x="0.904766 * safezoneW + safezoneX"; y="0.8355 * safezoneH + safezoneY"; w="0.0696094 * safezoneW"; h="0.044 * safezoneH"; SizeEx="0.04 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
			class P1_INFO_RANGE: BPD_CloneHUD_RscText { idc=40863; text="---"; x="0.904766 * safezoneW + safezoneX"; y="0.885 * safezoneH + safezoneY"; w="0.0696094 * safezoneW"; h="0.044 * safezoneH"; SizeEx="0.04 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
			class P2_INFO_AMMO: BPD_CloneHUD_RscText { idc=40864; text="---"; x="0.878646 * safezoneW + safezoneX"; y="0.789817 * safezoneH + safezoneY"; w="0.04125 * safezoneW"; h="0.044 * safezoneH"; SizeEx="0.06 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
			class P2_INFO_MAGS: BPD_CloneHUD_RscText { idc=40865; text="---"; x="0.879646 * safezoneW + safezoneX"; y="0.84722 * safezoneH + safezoneY"; w="0.04125 * safezoneW"; h="0.044 * safezoneH"; SizeEx="0.06 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
			class P2_INFO_DIR: BPD_CloneHUD_RscText { idc=40866; text="---"; x="0.479375 * safezoneW + safezoneX"; y="0.093 * safezoneH + safezoneY"; w="0.04125 * safezoneW"; h="0.044 * safezoneH"; SizeEx="0.04 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
			class P2_INFO_RANGE: BPD_CloneHUD_RscText { idc=40867; text="---"; x="0.479375 * safezoneW + safezoneX"; y="0.929 * safezoneH + safezoneY"; w="0.04125 * safezoneW"; h="0.044 * safezoneH"; SizeEx="0.04 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
			class RC_INFO_AMMO: BPD_CloneHUD_RscText { idc=40868; text="---"; x="0.855781 * safezoneW + safezoneX"; y="0.775 * safezoneH + safezoneY"; w="0.04125 * safezoneW"; h="0.044 * safezoneH"; SizeEx="0.06 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
			class RC_INFO_MAGS: BPD_CloneHUD_RscText { idc=40869; text="---"; x="0.793906 * safezoneW + safezoneX"; y="0.819 * safezoneH + safezoneY"; w="0.03 * safezoneW"; h="0.033 * safezoneH"; SizeEx="0.06 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
			class RC_INFO_DIR: BPD_CloneHUD_RscText { idc=40870; text="---"; x="0.108125 * safezoneW + safezoneX"; y="0.797 * safezoneH + safezoneY"; w="0.04125 * safezoneW"; h="0.044 * safezoneH"; SizeEx="0.04 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
			class RC_INFO_RANGE: BPD_CloneHUD_RscText { idc=40871; text="---"; x="0.015315 * safezoneW + safezoneX"; y="0.4867 * safezoneH + safezoneY"; w="0.06 * safezoneW"; h="0.03 * safezoneH"; SizeEx="0.04 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
			class RC_INFO_LR: BPD_CloneHUD_RscText { idc=40872; text="---"; x="0.427812 * safezoneW + safezoneX"; y="0.112 * safezoneH + safezoneY"; w="0.045 * safezoneW"; h="0.03 * safezoneH"; SizeEx="0.04 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
			class RC_INFO_SR: BPD_CloneHUD_RscText { idc=40873; text="---"; x="0.520625 * safezoneW + safezoneX"; y="0.112 * safezoneH + safezoneY"; w="0.048 * safezoneW"; h="0.033 * safezoneH"; SizeEx="0.04 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
			class RC_INFO_ALT: BPD_CloneHUD_RscText { idc=40874; text="---"; x="0.922813 * safezoneW + safezoneX"; y="0.485 * safezoneH + safezoneY"; w="0.065 * safezoneW"; h="0.032 * safezoneH"; SizeEx="0.04 * safezoneH"; style=2; colorText[]={1,1,1,0}; colorBackground[]={0,0,0,0}; };
		};
	};
};

class CfgSounds
{
	class typing_1
	{
		sound[] = { "\885th_CloneHUD\sounds\typing_1.ogg", 0.30000001, 1 };
		titles[] = {};
	};
	class threat_detector
	{
		sound[] = { "\885th_CloneHUD\sounds\threat_detector.ogg", 0.30000001, 1 };
		titles[] = {};
	};
	class glitch
	{
		sound[] = { "\885th_CloneHUD\sounds\hud_glitch.ogg", 0.5, 1 };
		titles[] = {};
	};
	class glitch_short
	{
		sound[] = { "\885th_CloneHUD\sounds\hud_glitch_short_2.ogg", 0.5, 1 };
		titles[] = {};
	};
};
