#include "BIS_AddonInfo.hpp"
class CfgPatches
{
	class deployable_Prowler
	{
		name="Deployable Prowler";
		author="Conway";
		units[]={"Rev_Prowler_b"};
		weapons[]={"Rev_Prowler_item"};
		requiredVersion=1;
		requiredAddons[]=
		{
			"A3_Drones_F",
			"cba_main",
			"ace_interaction",
			"JLTS_drones"
		};
	};
};
class CfgFactionClasses {
    class Fac612th {
        displayName = "612th Assault Battalion Delta Company";
        side = 1;
        priority = 0;
    };
};

class CFgEditorSubcategories
{
	class Sub612thDrone
	{
		side = 1;
        scope = 2;
        scopeCurator = 2;
		displayName = "Drones";
	};
};

class CfgVehicles
{
	class Weapon_Bag_Base;
	class B_UAV_01_backpack_F;
	class Air;
	class Helicopter: Air
	{
		class Turrets;
		class HitPoints;
	};
	class Helicopter_Base_F: Helicopter
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	
	class UAV_01_base_F: Helicopter_Base_F {
		class Turrets: Turrets {
		class MainTurret;
		};
	};
	class JLTS_UAV_prowler_base: UAV_01_base_F
	{
	class Turrets: Turrets
	{
		class MainTurret;
	};
	};
  class Rev_Prowler_b: JLTS_UAV_prowler_base
{
	author = "Gooze";
	displayName = "Deployable Prowler";
	scope = 2;
	camouflage=.2;
	armor = 15;
	side = 1;
	faction = "Fac612th";
    editorSubcategory = "Sub612thDrone";
	isUav=1;
	crew = "B_UAV_AI";
	weapons[] = {"Laserdesignator_mounted"};
	magazines[] = { "Laserbatteries" };
	driverOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
	
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			class OpticsIn {
				class Wide {
					opticsDisplayName = "W";
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.5;
					minFov = 0.01;
					maxFov = 0.5;
					directionStabilized = 1;
					visionMode[] = {"Normal", "NVG", "Ti"};
					thermalMode[] = {0, 1};
					gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Gunner_F.p3d";
				};
			};
			
			gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Gunner_F.p3d";
			turretInfoType = "RscOptics_UAV_gunner";
		};
	};
	
	class assembleInfo {
		assembleTo = "";
		base = "";
		displayName = "";
		dissasembleTo[] = {};
		primary = 1;
	};
};	
};


class CfgWeapons
{
	class ToolKit;
	class Rev_Prowler_item: ToolKit
	{
		author = "Conway";
		picture = "\deployable_Prowler\img\Rev_uav_img_3.paa";
		displayName = "Deployable Prowler";
		descriptionShort = "Field deployable Prowler";
		class ItemInfo
		{
			mass = 50;
			uniformModel = "\A3\Weapons_F\Items\Toolkit";
			type = 620;
			allowedSlots[] = {801,701,901};
			scope = 0;
		};
	};
};


class CfgFunctions
{
	class Rev
	{
		class UAV
		{
			file="\deployable_Prowler\functions";
			class uav_init {postInit=1;};
			class deploy_uav {};
		};
	};
};