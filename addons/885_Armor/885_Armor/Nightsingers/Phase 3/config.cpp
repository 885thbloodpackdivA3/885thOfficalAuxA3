class CfgPatches
{
	class Wes_PilotHelmet_aux
	{
		author="Antauri";
		requiredAddons[]=
		{
			"A3_data_F",
			"A3_anims_F",
			"A3_weapons_F",
			"A3_characters_F"
		};
		skipWhenMissingDependencies=1;
		requiredVersion=1;
		units[]={};
		weapons[]=
		{
			"Wes_ClonePilot_helmet"
		};
	};
};
class CfgWeapons
{
	class ItemInfo;
	class ItemCore;
	class Uniform_Base;
	class Vest_Camo_Base;
	class U_I_CombatUniform;
	class HeadgearItem;
	class H_HelmetB;
	class H_HelmetO_ViperSP_hex_F;
	class Wes_ClonePilot_helmet: H_HelmetO_ViperSP_hex_F
	{
		scope=2;
		author="Antauri";
		displayName="[Wes] P3 Clone Pilot Helmet";
		hiddenSelections[]=
		{
			"Helmet",
			"visor",
			"LifeSupport",
			"Ligths"
		};
		hiddenSelectionsTextures[]=
		{
			"\WesClonePilotHelmet\Data\ClonePilot\Textures\Standard\Helmet_co.paa",
			"\WesClonePilotHelmet\Data\ClonePilot\Textures\Standard\Helmet_co.paa",
			"\WesClonePilotHelmet\Data\ClonePilot\Textures\Standard\LifeSupport_co.paa",
			"\WesClonePilotHelmet\Data\ClonePilot\Textures\Standard\LifeSupport_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"\WesClonePilotHelmet\Data\ClonePilot\Textures\Standard\Helmet.rvmat",
			"\WesClonePilotHelmet\Data\ClonePilot\Textures\Standard\Visor.rvmat",
			"\WesClonePilotHelmet\Data\ClonePilot\Textures\Standard\LifeSupport.rvmat",
			"\WesClonePilotHelmet\Data\ClonePilot\Textures\Standard\Lights.rvmat"
		};
		picture="\WesClonePilotHelmet\Data\ClonePilot\P3ClonePilotHelmet_UI.paa";
		model="\WesClonePilotHelmet\Data\ClonePilot\model\ClonePilotHelmet.p3d";
		subItems[]={};
		ace_hearing_lowerVolume=0.60000002;
		ace_hearing_protection=0.85000002;
		class ItemInfo: HeadgearItem
		{
			mass=10;
			uniformModel="\WesClonePilotHelmet\Data\ClonePilot\model\ClonePilotHelmet.p3d";
			hiddenSelections[]=
			{
				"Helmet",
				"visor",
				"LifeSupport",
				"Ligths"
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName="HitHead";
					armor=6;
					passThrough=0.5;
				};
			};
		};
	};
};
class cfgMods
{
	author="Antauri";
	timepacked="1777924957";
};
