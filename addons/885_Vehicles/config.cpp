class Cfgpatches
{
	class 885th_Vehicles
	{
		author = "885th Bloodpack Div";
		requiredAddons[] = {"A3_Data_F", "A3_Weapons_F", "A3_Characters_F", "3AS_LAAT", "3AS_ARC_170", "3AS_Republic_Heli_LAS", "3AS_ITT", "TKE_Ext_Core_V", "ls_core"};
		requiredVersion = 0.1;
		units[] = {
			"885th_LSV_base_F",
			"885th_LSV_EWeb",
			"885th_LAAT_Gunship",
			"885th_Smith_LAAT_Gunship",
			"885th_ITT_Base",
			"885th_ITT",
			"885th_Draco_Base",
			"885th_Draco_Unarmed",
			"885th_Draco_Autocannon",
			"885th_ATTE_base",
			"885th_ATTE",
			"885th_Saber_Base",
			"885th_Saber",
			"885th_ARC170_Base",
			"885th_ARC170",
			"885th_VWING",
			"885th_LAS_Base",
			"885th_LAS_F",
        	"885th_LAS_Z6_F",
			"885th_LAAT_C"};
		weapons[] = {
			"885th_Main_Turret",
			"885th_Commander_Turret"};
	};
};
class ls_impulsor_base;
class WeaponCloudsGun;

class cfgFactionClasses
{
	class 885th_Faction;
};
class CFgEditorSubcategories
{
	class Sub885thNS
	{
		displayName = "Nightsingers - Multi-Role";
	};
	class Sub885thKraytLogi
	{
		displayName = "Krayt - Logistics";
	};
	class Sub885thKraytArmor
	{
		displayName = "Krayt - Armored";
	};
	class Sub885thLWFighters
	{
		displayName = "LothWulf - Fighters";
	};
	class Sub885thRecon
	{
		displayName = "Najax Recon Assets"
	};
};
class CfgAmmo
{
	class 3AS_FF4_20mm;
	class 885th_vehicleshell : 3AS_FF4_20mm
	{
		ACE_damageType = "plasmashell";
		ace_vehicle_damage_incendiary = 0.8;
		warheadName = "HEAT";
		aiAmmoUsageFlags = "64 + 128 + 256";
		brightness = 1000;
		craterEffects = "ExploAmmoCrater";
		model = "\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly = "IDA_BlasterBoltGlow_Large_Blue_Fly";
		effectflare = "FlareShell";
		effectsFire = "CannonFire";
		effectsSmoke = "SmokeShellWhite";
		explosionAngle = 60;
		explosionDir = "explosionDir";
		explosionEffects = "ExploAmmoExplosion";
		explosionEffectsDir = "explosionDir";
		explosionForceCoef = 1;
		explosionPos = "explosionPos";
		explosionType = "explosive";
		hit = 200;
		initSpeed = 100;
		indirectHit = 15;
		explosive = 1;
		flaresize = 5;
		indirectHitRange = 2.5;
		caliber = 20;
		coefGravity = 0.8;
	};
};

class CfgMagazines
{
	class 885th_cell;
	class 885th_vehicleshell_cell : 885th_cell
	{
		count = 200;
		displayName = "[885th] Vehicle Plasma Cell";
		displayNameShort = "Std. Cell";
		descriptionShort = "200 round capacity, 20mm Plasma Shell.";
		ammo = "885th_vehicleshell";
		tracersEvery = 1;
		nameSound = "cannon";
	};

	class 885th_vehicle_battery : 885th_cell
	{
		count = 500;
		displayName = "[885th] High Power Vechicle Battery";
		displayNameShort = "HP Battery";
		descriptionShort = "500 round capacity, high power blaster bolts.";
		model = "\MRC\JLTS\weapons\z6\z6_mag.p3d";
		picture = "\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		ammo = "885th_blasterbolt_bHigh";
		tracersEvery = 1;
	};
};

class CfgWeapons
{
	class Mode_FullAuto;
	class HMG_127;
	class 3AS_ITT_Turret_MG;
	class 3AS_FF4_Blaster_20mm;
	class 885th_HRB_127 : HMG_127 {
		displayName = "[885th] Heavy Repeating Blaster";
		magazines[] = {885th_vehicle_battery};
	};
	class 885th_Main_Turret : 3AS_ITT_Turret_MG
	{
		scope = 2;
		scopeArsenal = 1;
		displayName = "[885th] ITT Heavy Laser Turret";
		magazines[] = {
			"885th_vehicleshell_cell"
		};
		class GunClouds
		{
			cloudletGrowUp = 0.200000;
			cloudletFadeIn = 0;
			cloudletFadeOut = 0.400000;
			cloudletDuration = 0.200000;
			cloudletAlpha = 1;
			cloudletAccY = 2;
			cloudletMinYSpeed = -10;
			cloudletMaxYSpeed = 10;
			interval = 0.020000;
			size = 0.300000;
			sourceSize = 0.015000;
		};
		class GunParticles
		{
			class FirstEffect
			{
				effectName="CannonFired";
				positionName="Usti_hlavne_r_1";
				directionName="Konec_hlavne_r_1";
			};
			class SecondEffect
			{
				effectName="CannonFired";
				positionName="Usti_hlavne_r_2";
				directionName="Konec_hlavne_r_2";
			};
		};
	};
	class 885th_Commander_Turret : 3AS_FF4_Blaster_20mm
	{
		scope = 2;
		scopeArsenal = 1;
		displayName = "[885th] ITT Anti-Personnel Turret";
		magazines[] = {
			"885th_vehicle_battery"
		};
		class GunClouds
		{
			cloudletGrowUp = 0.200000;
			cloudletFadeIn = 0;
			cloudletFadeOut = 0.400000;
			cloudletDuration = 0.200000;
			cloudletAlpha = 1;
			cloudletAccY = 2;
			cloudletMinYSpeed = -10;
			cloudletMaxYSpeed = 10;
			interval = 0.020000;
			size = 0.300000;
			sourceSize = 0.015000;
		};
		class GunParticles
		{
			class FirstEffect
			{
				effectName="CannonFired";
				positionName="Usti_hlavne_r_1";
				directionName="Konec_hlavne_r_1";
			};
			class SecondEffect
			{
				effectName="CannonFired";
				positionName="Usti_hlavne_r_2";
				directionName="Konec_hlavne_r_2";
			};
		};
	};
};

class CfgVehicles
{
	class Turrets;
	class MainTurret;
	class Components;
	class RCWSOptics;
	class OpticsIn;
	class UserActions;
	class HitTurret;
	class HitGun;
	class GunParticles;
	class AnimationSources;
	class Eventhandlers;
	class HitPoints;
	class HitHull;
	class MarkerLights;
	class ViewPilot;

	// Sensor Template classes
	class SensorTemplatePassiveRadar;
	class SensorTemplateAntiRadiation;
	class SensorTemplateActiveRadar;
	class SensorTemplateIR;
	class SensorTemplateVisual;
	class SensorTemplateMan;
	class SensorTemplateLaser;
	class SensorTemplateNV;
	class SensorTemplateDataLink;

	class VehicleSystemsTemplateLeftDriver;
	class VehicleSystemsTemplateRightDriver;
	class VehicleSystemsTemplateLeftCommander;
	class VehicleSystemsTemplateRightCommander;
	class VehicleSystemsTemplateLeftGunner;
	class VehicleSystemsTemplateRightGunner;
	
	class All
	{
		class ViewCargo;
		class ViewOptics;
	};
	class AllVehicles: All
	{
		class NewTurret
		{
			class ViewGunner;
			class ViewOptics;
			class HitPoints
			{
				class HitTurret;
				class HitGun;
			};
		};
		class ViewPilot;
		class ViewCargo;
		class ViewOptics;
		class CargoTurret: NewTurret
		{
			class ViewGunner: ViewCargo
			{
			};
		};
	};
	class Land: AllVehicles
	{
	};
	class LandVehicle: Land
	{
		class CommanderOptics: NewTurret
		{
			class ViewOptics: ViewOptics
			{
			};
			class ViewGunner: ViewCargo
			{
			};
		};
	};
	class Car: LandVehicle
	{
		class HitPoints
		{
			class HitEngine;
			class HitRGlass;
			class HitLGlass;
			class HitBody;
			class HitFuel;
			class HitLFWheel;
			class HitRFWheel;
			class HitLF2Wheel;
			class HitRF2Wheel;
			class HitLMWheel;
			class HitRMWheel;
			class HitLBWheel;
			class HitRBWheel;
		};
		class ViewPilot: ViewPilot
		{
		};
		class DestructionEffects
		{
			class Light1;
		};
		class EventHandlers;
	};
	class Car_F: Car
	{
		class HitPoints
		{
			class HitRGlass;
			class HitLGlass;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
			class HitBody;
			class HitFuel;
			class HitLFWheel;
			class HitLBWheel;
			class HitLMWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRBWheel;
			class HitRMWheel;
			class HitRF2Wheel;
			class HitEngine;
			class HitHull;
		};
		class ViewPilot: ViewPilot
		{
		};
		class NewTurret: NewTurret
		{
		};
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class HitPoints
				{
					class HitTurret;
					class HitGun;
				};
				class ViewOptics: ViewOptics
				{
				};
				class ViewGunner: ViewGunner
				{
				};
			};
		};
		class AnimationSources
		{
			class HitLFWheel;
			class HitRFWheel: HitLFWheel
			{
			};
			class HitLBWheel: HitLFWheel
			{
			};
			class HitRBWheel: HitLFWheel
			{
			};
			class HitLF2Wheel: HitLFWheel
			{
			};
			class HitRF2Wheel: HitLFWheel
			{
			};
			class HitLMWheel: HitLFWheel
			{
			};
			class HitRMWheel: HitLFWheel
			{
			};
			class HitGlass1;
			class HitGlass2: HitGlass1
			{
			};
			class HitGlass3: HitGlass1
			{
			};
			class HitGlass4: HitGlass1
			{
			};
			class HitGlass5: HitGlass1
			{
			};
			class HitGlass6: HitGlass1
			{
			};
		};
		class Exhausts
		{
			class Exhaust1;
		};
		class Reflectors
		{
			class Left;
			class Right: Left
			{
			};
			class Right2: Right
			{
			};
			class Left2: Left
			{
			};
		};
	};
	class Wheeled_Apc_F: Car_F
	{
		class ViewPilot;
		class HitPoints: HitPoints
		{
		};
		class Exhausts
		{
		};
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewOptics;
				class Components;
				class Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						class Components;
						class ViewGunner;
					};
				};
			};
		};
	};
	class APC_Wheeled_01_base_F: Wheeled_Apc_F
	{
		class ViewPilot;
		class HitPoints: HitPoints
		{
		};
		class Exhausts
		{
		};
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewOptics;
				class Components;
				class Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						class Components;
						class ViewGunner;
					};
				};
			};
		};
	};

	class 3AS_laat_Base;
	class 3AS_LAAT_Mk1 : 3AS_laat_Base
	{
		class UserActions
		{
		};
	};
	class 885th_LAAT_Gunship : 3AS_LAAT_Mk1
	{
		class EventHandlers
		{
			postInit = "[(_this select 0),""yes""] execVM '\FIR_AirWeaponSystem_US\Script\init\init.sqf';";
		};
		class UserActions : UserActions
		{
			class AMS_LiteOpen
			{
				displayName = "<t color='#739eff'>Open AMS Lite</t>";
				position = "pos cano";
				radius = 15;
				shortcut = "User3";
				condition = "player in this and (speed this < 1)";
				statement = "this execVM '\FIR_AirWeaponSystem_US\Script\AMS\AMS_Lite\AMS_Lite_GUI_Open.sqf';";
				onlyforplayer = "false";
				priority = 6;
				hideOnUse = 1;
			};
			class ls_impulsor_impulse
			{
				displayName="Impulse";
				position="pilotview";
				radius=5;
				onlyForPlayer=0;
				condition="ls_player == currentPilot this and {this call ls_impulsor_fnc_canImpulse}";
				statement="[this, 1] call ls_impulsor_fnc_impulse";
			};
			class ls_impulsor_repulse: ls_impulsor_impulse
			{
				displayName="Repulse";
				statement="[this, -1] call ls_impulsor_fnc_impulse";
			};
		};
		class ls_impulsor: ls_impulsor_base
		{
		};
		ls_hasImpulse = 1;
		_mainBladeCenter = "rotor_center";
		author = "3rd Army Studios + 885th BPD";
		acceleration = 450;
		ace_cargo_hasCargo = 1;
		ace_cargo_space = 16;
		ace_fastroping_enabled = 1;
		ace_interaction_bodyWidth = 3;
		ace_refuel_canReceive = 1;
		ace_refuel_flowRate = 8;
		ace_tagging_canTag = 1;
		attendant = 1;
		airBrakeFrictionCoef = 3;
		airCapacity = 10;
		armor = 180;
		armorLights = 0.4;
		armorStructural = 1.5;
		armorFuel = 2.0;
		armorEngine = 1.5;
		armorAvionics = 2.0;
		audible = 50;
		availableforsupporttypes[] = {"CAS_Heli", "Transport", "Drop"};
		commanderCanSee = 31;					// default
		gunnerCanSee = 1 + 2 + 4 + 8 + 16 + 32; // default
		driverCanSee = 2 + 8 + 16 + 32;			// default
		cost = 3000;
		camouflage = 10.0;
		canFloat = 1;
		crew = "885th_Pilot";
		crewCrashProtection = 0;
		crewVulnerable = 1;
		displayname = "[885th] LAAT/I Mk.1";
		driverAction = "LAAT_Pilot";
		driverCompartments = "Compartment1";
		editorpreview = "\3AS\3AS_Laat\LAATI\data\editorpreview\3AS_laat.jpg";
		enableGPS = 1;
		enableManualFire = 1;
		enableRadio = 1;
		side = 1;
		faction = "885th_Faction";
		editorSubcategory = "Sub885thNS";
		gearDown[] = {"gearDownInt", "gearDownExt"};
		gearDownExt[] = {"3AS\3as_Laat\sounds\LaatdoorOPEN.ogg", 1, 1, 1000};
		gearDownInt[] = {"3AS\3as_Laat\sounds\LaatdoorOPEN.ogg", 1, 1, 100};
		gearUp[] = {"gearUpInt", "gearUpExt"};
		gearUpExt[] = {"3AS\3as_Laat\sounds\LaatdoorOPEN.ogg", 1, 0.8, 1000};
		gearUpInt[] = {"3AS\3as_Laat\sounds\LaatdoorOPEN.ogg", 1, 1, 100};
		getOutAction = "GetOutLow";
		getInRadius = 10;
		hiddenSelections[] = {"camo", "camo1", "camo2", "camo3", "camo4"};
		hiddenSelectionsMaterials[] = {};
		hiddenSelectionsTextures[] = {"885_Vehicles\textures\laat\Hull_CO.paa", "885_Vehicles\textures\laat\Wings_CO.paa", "885_Vehicles\textures\laat\Weapons_CO.paa", "885_Vehicles\textures\laat\Weapon_Details_CO.paa", "885_Vehicles\textures\laat\Interior_CO.paa"};
		hiddenUnderwaterSelections[] = {};
		hiddenUnderwaterSelectionsTextures[] = {};
		icon = "\3AS\3AS_Laat\LAATI\data\ui\Map_laat_CA.paa";
		mainBladeCenter = "rotor_center";
		LockDetectionSystem = "1 + 2 + 4 + 8 + 16 + 32";
		magazines[] = {"1000Rnd_20mm_shells", "Laserbatteries", "3AS_PylonMissile_LAAT_8Rnd_Missile_AA", "3AS_LAAT_8Rnd_Missile_AGM", "240Rnd_CMFlare_Chaff_Magazine", "240Rnd_CMFlare_Chaff_Magazine", "240Rnd_CMFlare_Chaff_Magazine", "240Rnd_CMFlare_Chaff_Magazine", "3as_LAAT_1000Rnd_Medium_shells", "3as_LAAT_1000Rnd_Medium_shells", "3as_LAAT_1000Rnd_Medium_shells", "3as_LAAT_1000Rnd_Medium_shells"};
		model = "3as\3AS_laat\LAATi\model\tcw_laat.p3d";
		nameSound = "veh_helicopter_s";
		picture = "3AS\3AS_Laat\LAATI\data\ui\LAAT_Profile_ca.paa";
		receiveRemoteTargets = true;
		reportRemoteTargets = true;
		reportOwnPosition = true;
		showAllTargets = 2;
		showCrewAim = 4;
		scope = 2;
		slingLoadMaxCargoMass = 50000;
		slingLoadMemoryPoint = "sling";
		slingLoadMinCargoMass = 0;
		typicalcargo[] = {"885th_Pilot"};
		weapons[] = {"3as_LAAT_Medium_Canon", "3AS_LAAT_Missile_AGM", "3AS_LAAT_Missile_AA", "CMFlareLauncher","Laserdesignator_pilotCamera"};
		weaponsGroup1 = "1 + 2";
		weaponsGroup2 = 4;
		weaponsGroup3 = "8 + 	16 + 	32";
		weaponsGroup4 = "64 + 		128";
		weaponSlots = 0;
	};

	class 3AS_LAATC;
	class 885th_LAATC_base_F : 3AS_LAATC
	{
		scope = 0;
		class textureSources
		{
			class 885th_LC
			{
				displayName = "885th Livery";
				author = "AifeSupport";
				textures[] = {
					"885_Vehicles\textures\LAATC\885_LAAT_C_Hull_co.paa",
					"885_Vehicles\textures\LAATC\885_LAAT_C_Wings_co.paa",
					"885_Vehicles\textures\LAATC\885_LAAT_C_Top_co.paa",
					"885_Vehicles\textures\LAATC\LAAT_C_Detail_Front_co.paa"};
				factions[] = {
					"885th_Faction"};
			};
		};
		class UserActions {};
	};
	class 885th_LAAT_C : 885th_LAATC_base_F
	{
		class EventHandlers
		{
			postInit = "[(_this select 0)] spawn ls_vehicle_fnc_ImpulsorMonitor; [(_this select 0),""yes""] execVM '\FIR_AirWeaponSystem_US\Script\init\init.sqf';";
		};
		class UserActions : UserActions
		{
			class AMS_LiteOpen
			{
				displayName = "<t color='#739eff'>Open AMS Lite</t>";
				position = "pos cano";
				radius = 15;
				shortcut = "User3";
				condition = "player in this and (speed this < 1)";
				statement = "this execVM '\FIR_AirWeaponSystem_US\Script\AMS\AMS_Lite\AMS_Lite_GUI_Open.sqf';";
				onlyforplayer = "false";
				priority = 6;
				hideOnUse = 1;
			};
		};
		ls_impulsor_fuelDrain_1 = 0.0001;
		ls_impulsor_fuelDrain_2 = 0.0003;
		ls_impulsor_boostSpeed_1 = 400;
		ls_impulsor_boostSpeed_2 = 600;
		ls_hasImpulse = 1;
		ace_cargo_hasCargo = 0;
		ace_cargo_space = 0;
		author = "AifeSupport";
		scope = 2;
		scopeCurator = 2;
		displayname = "[885th] LAAT/C";
		side = 1;
		faction = "885th_Faction";
		editorSubcategory = "Sub885thKraytLogi";
		camouflage = 6.0;
		armor = 180;
		armorLights = 0.4;
		armorStructural = 1.5;
		armorFuel = 2.0;
		armorEngine = 1.5;
		armorAvionics = 2.0;
		crew = "885th_Pilot";
		cost = 1000;
		textureList[] = {
			"885th_LC",
			1,
		};
		hiddenselections[] = {"camo", "camo1", "camo2", "camo3"};
		hiddenSelectionsTextures[] = {
			"885_Vehicles\textures\LAATC\885_LAAT_C_Hull_co.paa",
			"885_Vehicles\textures\LAATC\885_LAAT_C_Wings_co.paa",
			"885_Vehicles\textures\LAATC\885_LAAT_C_Top_co.paa",
			"885_Vehicles\textures\LAATC\LAAT_C_Detail_Front_co.paa",
		};
	};
	class 3AS_Rep_LAS_F;
	class 885th_LAS_Base_F: 3AS_Rep_LAS_F
	{
		scope = 0;
		class TextureSources
		{
			class 885th_LC
			{
				displayName="";
				author="885th Bloodpack Division";
				textures[]=
				{
					"\885_Vehicles\texture\LAS\885th_LAS_Exterior_co.paa",
			        "\3AS\3AS_Republic_Heli\LAS\data\3AS_LAS_Interior_co.paa",
			        "\885_Vehicles\texture\LAS\885th_LAS_Wings_co.paa"
				};
				factions[] = {
					"885th_Faction"};
			};
		};
		class UserActions {};
	};

	class 885th_LAS_F: 885th_LAS_Base_F
	{
		class EventHandlers
		{
			postInit = "[(_this select 0),""yes""] execVM '\FIR_AirWeaponSystem_US\Script\init\init.sqf';";
		};
		class UserActions : UserActions
		{
			class ls_impulsor_impulse
			{
				displayName="Impulse";
				position="pilotview";
				radius=5;
				onlyForPlayer=0;
				condition="ls_player == currentPilot this and {this call ls_impulsor_fnc_canImpulse}";
				statement="[this, 1] call ls_impulsor_fnc_impulse";
			};
			class ls_impulsor_repulse: ls_impulsor_impulse
			{
				displayName="Repulse";
				statement="[this, -1] call ls_impulsor_fnc_impulse";
			};
		};
		class ls_impulsor: ls_impulsor_base
		{
		};
		ls_hasImpulse = 1;
		ls_impulsor_impulseSpeed = 60;
        ls_impulsor_impulseCooldown = 3;
		author = "ONIBushido";
		scope = 2;
		scopeCurator = 2;
		ace_cargo_hasCargo = 1;
		ace_cargo_space = 10;
		displayname = "[885th] LAS QRF Mk 1";
		side = 1;
		faction = "885th_Faction";
		crew = "885th_Pilot";
		editorSubcategory = "Sub885thKraytLogi";
		camouflage = 4.5;
		armor = 155;
		armorLights = 0.6;
		armorStructural = 1.6;
		armorFuel = 2.0;
		armorEngine = 2.5;
		armorAvionics = 2.2;
		hiddenSelections[] = 
		{
			"camo0",
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[] = 
		{
			"885_Vehicles\textures\LAS\885th_LAS_Exterior_co.paa",
			"\3AS\3AS_Republic_Heli\LAS\data\3AS_LAS_Interior_co.paa",
			"885_Vehicles\textures\LAS\885th_LAS_Wings_co.paa"
		};
		typicalcargo[]=
		{
			"885th_Pilot"
		};
		weapons[]=
		{
			"3AS_LAS_Energy_Cannons",
			"CMFlareLauncher"
		};
		magazines[]=
		{
			"3AS_LAS_30mm_MP_shells",
			"3AS_LAS_30mm_MP_shells",
			"3AS_LAS_30mm_MP_shells",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine"
		};
	};

	class 3AS_Rep_LAS_Z6_F;
	class 885th_LAS_Z6_Base_F: 3AS_Rep_LAS_Z6_F
	{
		scope = 0;
		class TextureSources
		{
			class 885th_LC
			{
				displayName="";
				author="885th Bloodpack Division";
				textures[]=
				{
					"\885_Vehicles\texture\LAS\885th_LAS_Exterior2_co.paa",
			        "\3AS\3AS_Republic_Heli\LAS\data\3AS_LAS_Interior_co.paa",
			        "\885_Vehicles\texture\LAS\885th_LAS_Wings2_co.paa"
				};
				factions[] = {
					"885th_Faction"};
			};
		};
		class UserActions {};
	};

	class 885th_LAS_Z6_F: 885th_LAS_Z6_Base_F
	{
		class EventHandlers
		{
			postInit = "[(_this select 0),""yes""] execVM '\FIR_AirWeaponSystem_US\Script\init\init.sqf';";
		};
		class UserActions : UserActions
		{
			class ls_impulsor_impulse
			{
				displayName="Impulse";
				position="pilotview";
				radius=5;
				onlyForPlayer=0;
				condition="ls_player == currentPilot this and {this call ls_impulsor_fnc_canImpulse}";
				statement="[this, 1] call ls_impulsor_fnc_impulse";
			};
			class ls_impulsor_repulse: ls_impulsor_impulse
			{
				displayName="Repulse";
				statement="[this, -1] call ls_impulsor_fnc_impulse";
			};
		};
		class ls_impulsor: ls_impulsor_base
		{
		};
		ls_hasImpulse = 1;
		ls_impulsor_impulseSpeed = 60;
        ls_impulsor_impulseCooldown = 3;
		author = "ONIBushido";
		scope = 2;
		scopeCurator = 2;
		ace_cargo_hasCargo = 1;
		ace_cargo_space = 10;
		incomingMissileDetectionSystem="1 + 2 + 4 + 8 + 16";
		LockDetectionSystem="1 + 2 + 4 + 8 + 16";
		weaponLockSystem="1 + 2 + 4 + 8 + 16";
		displayname = "[885th] LAS QRF Mk 2";
		side = 1;
		faction = "885th_Faction";
		crew = "885th_Pilot";
		editorSubcategory = "Sub885thKraytLogi";
		camouflage = 4.5;
		armor = 165;
		armorLights = 0.6;
		armorStructural = 1.8;
		armorFuel = 2.5;
		armorEngine = 2.5;
		armorAvionics = 2.2;
		hiddenSelections[] = 
		{
			"camo0",
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[] = 
		{
			"885_Vehicles\textures\LAS\885th_LAS_Exterior2_co.paa",
			"\3AS\3AS_Republic_Heli\LAS\data\3AS_LAS_Interior_co.paa",
			"885_Vehicles\textures\LAS\885th_LAS_Wings2_co.paa"
		};
		typicalcargo[]=
		{
			"885th_Pilot"
		};
		weapons[]=
		{
			"3AS_LAS_Energy_Cannons",
			"CMFlareLauncher"
		};
		magazines[]=
		{
			"3AS_LAS_30mm_MP_shells",
			"3AS_LAS_30mm_MP_shells",
			"3AS_LAS_30mm_MP_shells",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine"
		};
	};

	class 3AS_ARC_170_Base;
	class 885th_ARC170_Base: 3AS_ARC_170_Base
	{
		scope = 0;
		class textureSources
		{
			class 885th_LC
			{
				displayName = "885th Livery";
				author = "AifeSupport";
				textures[]=
				{
					"885_Vehicles\textures\ARC170\885th_Main_Frame_co.paa",
					"885_Vehicles\textures\ARC170\885th_Wings_Engines_co.paa",
					"3as\3AS_ARC170\Data\Guns_CO.paa"
				};
				factions[] = {
					"885th_Faction"};
			};
		};
		class UserActions {};
	};
	class 885th_ARC170: 885th_ARC170_Base
	{
		class EventHandlers
		{
			postInit = "[(_this select 0),""yes""] execVM '\FIR_AirWeaponSystem_US\Script\init\init.sqf';";
		};
		class UserActions : UserActions
		{
			class AMS_LiteOpen
			{
				displayName = "<t color='#739eff'>Open AMS Lite</t>";
				position = "pos cano";
				radius = 15;
				shortcut = "User3";
				condition = "player in this and (speed this < 1)";
				statement = "this execVM '\FIR_AirWeaponSystem_US\Script\AMS\AMS_Lite\AMS_Lite_GUI_Open.sqf';";
				onlyforplayer = "false";
				priority = 6;
				hideOnUse = 1;
			};
			class deploySfoils
			{
				displayName="Fold S-Foils";
				position="action";
				radius=10;
				onlyForPlayer=0;
				condition="(this animationSourcePhase ""SFoil"" == 0) AND (currentPilot this isEqualTo player) AND (alive this)";
				statement="this animateSource [""SFoil"",1]";
			};
			class undeploySfoils: deploySfoils
			{
				displayName="Deploy S-Foils";
				condition="(this animationSourcePhase ""SFoil"" == 1) AND (currentPilot this isEqualTo player) AND (alive this)";
				statement="this animateSource [""SFoil"",0]";
			};
		};
		author = "ONIBushido";
		scope = 2;
		scopeCurator = 2;
		displayname = "[885th] ARC-170 Mk.1";
		side = 1;
		faction = "885th_Faction";
		editorSubcategory = "Sub885thLWFighters";
		camouflage = 6.0;
		ejectSpeed[] = { 0, 60, 0 };
		magazines[] ={"3as_Z95_1000Rnd_Light_shells","3as_Z95_1000Rnd_Light_shells","3AS_PylonWeapon_Z95_240Rnd_Heavy_Shells","3AS_PylonWeapon_Z95_240Rnd_Heavy_Shells","3AS_PylonWeapon_Z95_240Rnd_Heavy_Shells","120Rnd_CMFlare_Chaff_Magazine","Laserbatteries","120Rnd_CMFlare_Chaff_Magazine","120Rnd_CMFlare_Chaff_Magazine","120Rnd_CMFlare_Chaff_Magazine","120Rnd_CMFlare_Chaff_Magazine"};
		armor = 180;
		armorLights = 0.5;
		armorStructural = 2.0;
		armorFuel = 2.0;
		armorEngine = 2.0;
		armorAvionics = 2.0;
		crew = "885th_Pilot";
		cost = 1000;
		weapons[] = {"3AS_Z95_Light_Cannon", "3as_Z95_Heavy_Cannon", "CMFlareLauncher", "Laserdesignator_pilotCamera"};
		textureList[] = {
			"885th_LC",
			1,
		};
		hiddenselections[] = {"camo1", "camo2", "guns"};
		hiddenSelectionsTextures[] = {
			"885_Vehicles\textures\ARC170\885th_Main_Frame_co.paa",
			"885_Vehicles\textures\ARC170\885th_Wings_Engines_co.paa",
			"3as\3AS_ARC170\Data\Guns_CO.paa"
		};
	};
	class 3AS_ATTE_Base;
	class 885th_ATTE_base: 3AS_ATTE_Base
	{
		scope = 0;
		class textureSources
		{
			class 885th_LC
			{
				displayName = "885th Livery";
				author = "AifeSupport";
				textures[]=
				{	"885_Vehicles\textures\ATTE\885th_ATTE_Shell_co.paa",
					"3as\3AS_ATTE\data\Textures\3AS_ATTE_Cockpit_co.paa",
					"3as\3AS_ATTE\data\Textures\3AS_ATTE_Detail_co.paa",
					"885_Vehicles\textures\ATTE\885th_ATTE_Legs_co.paa",
					"3as\3AS_ATTE\data\Textures\3AS_ATTE_Glass_ca.paa",
					"3as\3as_atte\data\textures\3as_atte_armor_co.paa"
				};
				factions[] = {
					"885th_Faction"};
			};
		};
		class UserActions {};
	};
	class 885th_ATTE: 885th_ATTE_base
	{
		author = "AifeSupport";
		scope = 2;
		scopeCurator = 2;
		displayname = "[885th] AT-TE Mk.1";
		side = 1;
		faction = "885th_Faction";
		editorSubcategory = "Sub885thKraytArmor";
		camouflage = 8.0;
		ace_cargo_hasCargo = 1;
		ace_cargo_space = 20;
		magazines[] ={"3AS_250Rnd_ATTE_30mm_MP_shells","3AS_250Rnd_ATTE_30mm_MP_shells","3AS_250Rnd_ATTE_30mm_MP_shells","3AS_250Rnd_ATTE_30mm_MP_shells","3AS_250Rnd_ATTE_30mm_MP_shells","3AS_250Rnd_ATTE_30mm_MP_shells"};
		armor = 525;
		armorStructural = 11.0;
		armorFuel = 6.0;
		armorEngine = 6.0;
		crew = "885th_Pilot";
		cost = 1000;
		weapons[] = {"3AS_ATTE_Turret"};
		textureList[] = {
			"885th_LC",
			1,
		};
		hiddenselections[] = {"camo1", "camo2", "camo3", "camo4", "camo5", "camo11"};
		hiddenSelectionsTextures[] = {
			"885_Vehicles\textures\ATTE\885th_ATTE_Shell_co.paa",
			"3as\3AS_ATTE\data\Textures\3AS_ATTE_Cockpit_co.paa",
			"3as\3AS_ATTE\data\Textures\3AS_ATTE_Detail_co.paa",
			"885_Vehicles\textures\ATTE\885th_ATTE_Legs_co.paa",
			"3as\3AS_ATTE\data\Textures\3AS_ATTE_Glass_ca.paa",
			"3as\3as_atte\data\textures\3as_atte_armor_co.paa"

		};
	};

	class 3AS_Vwing_base;
	class 885th_VWING_Base: 3AS_Vwing_base
	{
		scope = 0;
		class textureSources
		{
			class 885th_LC
			{
				displayName = "885th Livery";
				author = "AifeSupport";
				textures[]=
				{
					"885_Vehicles\textures\VWING\Vwing_Main_co.paa",
					"3AS\3AS_Vwing\data\Vwing_AstromechDroid_co.paa",
					"885_Vehicles\textures\VWING\Vwing_Wings_co.paa"
				};
				factions[] = {
					"885th_Faction"};
			};
		};
		class UserActions {};
	};
	class 885th_VWING: 885th_VWING_Base
	{
		author = "ONIBushido";
		scope = 2;
		scopeCurator = 2;
		displayname = "[885th] V-WING Mk.1";
		side = 1;
		faction = "885th_Faction";
		editorSubcategory = "Sub885thLWFighters";
		camouflage = 6.0;
		ejectSpeed[] = { 0, 60, 0 };
		magazines[] ={"3AS_Vwing_700Rnd_Medium_shells","3AS_Vwing_700Rnd_Medium_shells","3as_Z95_1000Rnd_Light_shells","3as_Z95_1000Rnd_Light_shells","3AS_LAAT_8Rnd_Missile_AGM","120Rnd_CMFlare_Chaff_Magazine","3AS_PylonMissile_ARC_2Rnd_Missile_AA","3AS_PylonMissile_ARC_2Rnd_Missile_AA","3AS_PylonMissile_ARC_2Rnd_Missile_AA","3AS_PylonMissile_ARC_2Rnd_Missile_AA","3AS_PylonMissile_ARC_2Rnd_Missile_AA","3AS_PylonMissile_ARC_2Rnd_Missile_AA","PylonRack_Missile_AMRAAM_C_x2","PylonRack_Missile_AMRAAM_C_x2","PylonRack_Missile_AMRAAM_C_x2","PylonRack_Missile_AMRAAM_C_x2","120Rnd_CMFlare_Chaff_Magazine","120Rnd_CMFlare_Chaff_Magazine","120Rnd_CMFlare_Chaff_Magazine","120Rnd_CMFlare_Chaff_Magazine"};
		armor = 125;
		armorStructural = 1.0;
		armorFuel = 1.5;
		armorEngine = 1.5;
		armorAvionics = 1.0;
		crew = "885th_Pilot";
		cost = 1000;
		weapons[] = {"3AS_Vwing_Medium_Cannon", "3AS_Z95_Light_Cannon", "CMFlareLauncher", "3AS_ARC_Missile_AA", "3AS_LAAT_Missile_AGM", "weapon_AMRAAMLauncher"};
		textureList[] = {
			"885th_LC",
			1,
		};
		hiddenselections[] = {"camo1", "camo4", "camo5"};
		hiddenSelectionsTextures[] = {
			"885_Vehicles\textures\VWING\Vwing_Main_co.paa",
			"3AS\3AS_Vwing\data\Vwing_AstromechDroid_co.paa",
			"885_Vehicles\textures\VWING\Vwing_Wings_co.paa"
		};
	};

	class LSV_02_armed_base_F;
	class 885th_LSV_base_F : LSV_02_armed_base_F
	{
		scope = 0;
		class textureSources
		{
			class 885th_L
			{
				displayName = "885th Livery";
				author = "AifeSupport";
				textures[] = {"885_Vehicles\textures\LSV\885_LSV_01_black_CO.paa"};
				factions[] = {
					"885th_Faction"};
			};
		};
		class Turrets : Turrets
		{
			class MainTurret : MainTurret
			{
			};
		};
	};
	class 885th_LSV_EWeb : 885th_LSV_base_F
	{
		tas_canBlift = 1;
		tas_liftVars = "[[[[0,-4,-6.5]]], [-0.001], [-0.4]]";
		author = "AifeSupport";
		displayname = "[885th] Light Support Vehicle";
		side = 1;
		faction = "885th_Faction";
		editorSubcategory = "Sub885thRecon";
		armor = 100;
		armorStructural = 5;
		accuracy = 0.25;
		ace_cargo_hasCargo = 1;
		ace_cargo_space = 2;
		ace_refuel_canReceive = 1;
		ace_refuel_flowRate = 1;
		ace_refuel_fuelCapacity = 60;
		ace_tagging_canTag = 1;
		ace_vehicles_engineStartDelay = 1.0;
		cost = 500;
		crew = "885th_Pilot";
		camouflage = 1.0;
		driverAction = "driver_lsv_02";
		driverCanSee = "1 + 2 + 4 + 8 + 32";
		driverCompartments = "Compartment1";
		driverLeftHandAnimName = "drivewheel";
		editorPreview = "\A3\EditorPreviews_F_Exp\Data\CfgVehicles\O_LSV_02_armed_F.jpg";
		enginePower = 350;
		engineStartSpeed = 1.5;
		getInAction = "GetInLow";
		getInRadius = 2.5;
		getOutAction = "GetOutLow";
		gunnerCanSee = "1 + 2 + 4 + 8 + 32";
		hasDriver = 1;
		hasGunner = 1;
		gunnerName = "Gunner";
		hiddenSelections[] = {"Camo1", "Camo2", "Camo3"};
		hiddenSelectionsMaterials[] = {};
		hiddenSelectionsTextures[] = {"885_Vehicles\textures\LSV\885_LSV_01_black_CO.paa", "885_Vehicles\textures\LSV\885_LSV_02_black_CO.paa", "885_Vehicles\textures\LSV\885_LSV_03_black_CO.paa"};
		hiddenUnderwaterSelections[] = {};
		hiddenUnderwaterSelectionsTextures[] = {};
		textureList[] = {
			"885th_L",
			1,
		};
		icon = "\A3\Soft_F_Exp\LSV_02\Data\UI\map_LSV_02_base_CA.paa";
		idleRpm = 400;
		incomingMissileDetectionSystem = 1;
		model = "\A3\Soft_F_Exp\LSV_02\LSV_02_F.p3d";
		nameSound = "veh_vehicle_armedcar_s";
		overviewPicture = "\A3\Data_F_Exp\Images\VehicleQilin_ca.paa";
		picture = "\A3\Soft_F_Exp\LSV_02\Data\UI\LSV_02_base_CA.paa";
		receiveRemoteTargets = true;
		reportRemoteTargets = true;
		reportOwnPosition = true;
		showAllTargets = 2;
		showCrewAim = 4;
		scope = 2;
		scopeCurator = 2;
		transportSoldier = 4;
		vehicleClass = "Light Recon";
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1", "SlingLoadCargo2", "SlingLoadCargo3", "SlingLoadCargo4"};
		slingLoadCargoMemoryPointsDir[] = {};
		soundEngineOffExt[] = {"3AS\3AS_LightVics\3AS_BARC\sounds\eng_barcSpeeder_shutdown.ogg", 1, 1, 200};
		soundEngineOffInt[] = {"3AS\3AS_LightVics\3AS_BARC\sounds\eng_barcSpeeder_shutdown.ogg", 1, 1, 200};
		soundEngineOnExt[] = {"3AS\3AS_LightVics\3AS_BARC\sounds\eng_barcSpeeder_startup.ogg", 1, 1};
		soundEngineOnInt[] = {"3AS\3AS_LightVics\3AS_BARC\sounds\eng_barcSpeeder_startup.ogg", 1, 1};
		tf_hasLRradio = 1;
		tf_isolatedAmount = 0.1;
		tf_range = 30000;
		weapons[] = {"SportCarHorn"};
		weaponsGroup1 = 1;
		weaponsGroup2 = "2 + 4";
		weaponsGroup3 = "8 + 16 + 32";
		weaponsGroup4 = "64 + 128";
		wheelMask = "wheel_X_X";
		class Turrets : Turrets
		{
			class MainTurret : MainTurret
			{
				gunnerType = "885th_Pilot";
				weapons[] = {"885th_HRB_127"};
				magazines[] = {
					"885th_vehicle_battery", 
					"885th_vehicle_battery", 
					"885th_vehicle_battery", 
					"885th_vehicle_battery", 
					"885th_vehicle_battery", 
					"885th_vehicle_battery"
				};
				maxTurn = 360;
				minElev = -10;
				maxElev = 90;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner",
					0.56234133,
					1,
					50
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner_vertical",
					0.56234133,
					1,
					50
				};
			};
		};
	};
	class 885th_Draco_BASE: APC_Wheeled_01_base_F
	{
		scope=1;
		scopeCurator=1;
		author="885th Bloodpack Division + LUCA";
		displayName="[885th] APC BASE";
		side=1;
		faction = "885th_Faction";
		crew = "885th_Pilot";
		hiddenSelections[]=
		{
			"camo_body"
		};
		hiddenSelectionsTextures[]=
		{
			"885_Vehicles\textures\APC-IFV\885th_apc_white_co.paa"
		};
		model="\TKE_Ext_APC\data\apc.p3d";
		picture="TKE_Ext_Core_V\data\ui\apc_pic_ca.paa";
		icon="TKE_Ext_Core_V\data\ui\apc_map_icon_ca.paa";
		terrainCoef=1.5;
		turnCoef=2;
		precision=15;
		brakeDistance=1;
		acceleration=17;
		enableRadio=1;
		enableGPS=1;
		crewCrashProtection=1.35;
		crewExplosionProtection=0.99000001;
		crewVulnerable=0;
		damageResistance=0.0040000002;
		armorGlass=0.5;
		armorWheels=0.33000001;
		armor=300;
		armorStructural=5;
		cost=600000;
		transportMaxBackpacks=4;
		transportSoldier=8;
		hideWeaponsCargo=1;
		canFloat=1;
		waterLinearDampingCoefY=7;
		waterLinearDampingCoefX=2;
		waterAngularDampingCoef=5;
		waterResistanceCoef=0.60000002;
		waterPPInVehicle=0;
		memoryPointsLeftWaterEffect="waterEffectL";
		memoryPointsRightWaterEffect="waterEffectR";
		memoryPointsLeftEngineEffect="EngineEffectL";
		memoryPointsRightEngineEffect="EngineEffectR";
		wheelDamageThreshold=0.69999999;
		wheelDestroyThreshold=0.99000001;
		wheelDamageRadiusCoef=0.94999999;
		wheelDestroyRadiusCoef=0.44999999;
		driverLeftHandAnimName="steering_wheel";
		driverRightHandAnimName="steering_wheel";
		driverAction="driver_hemtt";
		driverInAction="Driver_APC_Wheeled_03_cannon_F_in";
		viewDriverInExternal=1;
		cargoAction[]=
		{
			"passenger_generic01_leanleft",
			"passenger_apc_narrow_generic01",
			"passenger_apc_narrow_generic01",
			"passenger_apc_narrow_generic03",
			"passenger_apc_generic03",
			"passenger_apc_narrow_generic02",
			"passenger_generic01_foldhands",
			"passenger_generic01_foldhands"
		};
		getInAction="GetInLow";
		getOutAction="GetOutLow";
		cargoGetInAction[]=
		{
			"GetInLow"
		};
		cargoGetOutAction[]=
		{
			"GetOutLow"
		};
		memoryPointsGetInDriver="pos driver";
		memoryPointsGetInDriverDir="pos driver dir";
		memoryPointsGetInGunner="pos gunner";
		memoryPointsGetInGunnerDir="pos gunner dir";
		memoryPointsGetInCommander="pos commander";
		memoryPointsGetInCommanderDir="pos commander dir";
		driverForceOptics=1;
		driverOpticsModel="\a3\weapons_f\reticle\Optics_Driver_01_F";
		memoryPointDriverOptics="driverview";
		forceHideDriver=1;
		lockDetectionSystem="2+4";
		soundLocked[]=
		{
			"\A3\Sounds_F\weapons\Rockets\opfor_lock_1",
			1,
			1
		};
		soundIncommingMissile[]=
		{
			"\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1",
			1,
			1
		};
		radarType=2;
		reportRemoteTargets=1;
		reportOwnPosition=1;
		receiveRemoteTargets=1;
		class TransportItems
		{
		};
		class TransportWeapons
		{
		};
		class TransportMagazines
		{
		};
		class TransportBackpacks
		{
		};
		weapons[]=
		{
			"TruckHorn2"
		};
		magazines[]={};
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				name="hull";
				visual="body";
				armor=1;
				material=-1;
				passThrough=0.5;
				minimalHit=0.2;
				explosionShielding=0.60000002;
				radius=0.25;
			};
			class HitEngine: HitEngine
			{
				class DestructionEffects
				{
					ammoExplosionEffect="";
					class Engine_Smoke
					{
						simulation="particles";
						type="SmallWreckSmoke";
						position="engine_fire";
						intensity=0.5;
						interval=1;
						lifeTime=60;
					};
					class Engine_Fire: Engine_Smoke
					{
						type="SmallFireFPlace";
					};
				};
				name="engine";
				visual="";
			};
			class HitFuel: HitFuel
			{
				name="palivo";
				visual="";
			};
			class HitLFWheel: HitLFWheel
			{
				armor=0.5;
				explosionShielding=4;
				radius=0.33000001;
				passThrough=0;
				material=-1;
				minimalHit=-0.016000001;
				armorComponent="wheel_1_1_hide";
				name="wheel_1_1_steering";
				visual="wheel_1_1_hide";
			};
			class HitLF2Wheel: HitLF2Wheel
			{
				armor=0.5;
				explosionShielding=4;
				radius=0.33000001;
				passThrough=0;
				material=-1;
				minimalHit=-0.016000001;
				armorComponent="wheel_1_2_hide";
				name="wheel_1_2_steering";
				visual="wheel_1_2_hide";
			};
			class HitLF3Wheel: HitLF2Wheel
			{
				armor=0.5;
				explosionShielding=4;
				radius=0.33000001;
				passThrough=0;
				material=-1;
				minimalHit=-0.016000001;
				armorComponent="wheel_1_3_hide";
				name="wheel_1_3_steering";
				visual="wheel_1_3_hide";
			};
			class HitRFWheel: HitRFWheel
			{
				armor=0.5;
				explosionShielding=4;
				radius=0.33000001;
				passThrough=0;
				material=-1;
				minimalHit=-0.016000001;
				armorComponent="wheel_2_1_hide";
				name="wheel_2_1_steering";
				visual="wheel_2_1_hide";
			};
			class HitRF2Wheel: HitRF2Wheel
			{
				armor=0.5;
				explosionShielding=4;
				radius=0.33000001;
				passThrough=0;
				material=-1;
				minimalHit=-0.016000001;
				armorComponent="wheel_2_2_hide";
				name="wheel_2_2_steering";
				visual="wheel_2_2_hide";
			};
			class HitRF3Wheel: HitRF2Wheel
			{
				armor=0.5;
				explosionShielding=4;
				radius=0.33000001;
				passThrough=0;
				material=-1;
				minimalHit=-0.016000001;
				armorComponent="wheel_2_3_hide";
				name="wheel_2_3_steering";
				visual="wheel_2_3_hide";
			};
		};
		soundGetIn[]=
		{
			"A3\Sounds_F_EPC\Truck_03\int\getin",
			0.56234133,
			1
		};
		soundGetOut[]=
		{
			"A3\Sounds_F_EPC\Truck_03\int\getout",
			0.56234133,
			1,
			20
		};
		soundDammage[]=
		{
			"",
			0.56234133,
			1
		};
		soundEngineOnInt[]=
		{
			"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_int_start",
			0.3548134,
			1
		};
		soundEngineOnExt[]=
		{
			"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_ext_start",
			0.70794576,
			1,
			200
		};
		soundEngineOffInt[]=
		{
			"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_int_stop",
			0.3548134,
			1
		};
		soundEngineOffExt[]=
		{
			"A3\Sounds_F\vehicles\soft\MRAP_01\MRAP_01_ext_stop",
			0.70794576,
			1,
			200
		};
		buildCrash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",
			1,
			1,
			200
		};
		buildCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
			1,
			1,
			200
		};
		buildCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
			1,
			1,
			200
		};
		buildCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
			1,
			1,
			200
		};
		soundBuildingCrash[]=
		{
			"buildCrash0",
			0.25,
			"buildCrash1",
			0.25,
			"buildCrash2",
			0.25,
			"buildCrash3",
			0.25
		};
		WoodCrash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",
			1,
			1,
			200
		};
		WoodCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",
			1,
			1,
			200
		};
		WoodCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",
			1,
			1,
			200
		};
		WoodCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",
			1,
			1,
			200
		};
		soundWoodCrash[]=
		{
			"woodCrash0",
			0.25,
			"woodCrash1",
			0.25,
			"woodCrash2",
			0.25,
			"woodCrash3",
			0.25
		};
		armorCrash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",
			1,
			1,
			200
		};
		armorCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
			1,
			1,
			200
		};
		armorCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
			1,
			1,
			200
		};
		armorCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
			1,
			1,
			200
		};
		soundArmorCrash[]=
		{
			"ArmorCrash0",
			0.25,
			"ArmorCrash1",
			0.25,
			"ArmorCrash2",
			0.25,
			"ArmorCrash3",
			0.25
		};
		Crash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",
			1,
			1,
			200
		};
		Crash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
			1,
			1,
			200
		};
		Crash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
			1,
			1,
			200
		};
		Crash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
			1,
			1,
			200
		};
		soundCrashes[]=
		{
			"Crash0",
			0.25,
			"Crash1",
			0.25,
			"Crash2",
			0.25,
			"Crash3",
			0.25
		};
		class Sounds
		{
			soundSetsExt[]=
			{
				"APC_Wheeled_02_Engine_RPM0_EXT_SoundSet",
				"APC_Wheeled_02_Engine_RPM1_EXT_SoundSet",
				"APC_Wheeled_02_Engine_RPM2_EXT_SoundSet",
				"APC_Wheeled_02_Engine_RPM3_EXT_SoundSet",
				"APC_Wheeled_02_Engine_RPM4_EXT_SoundSet",
				"APC_Wheeled_02_Rattling_EXT_SoundSet",
				"APC_Wheeled_02_Stress_EXT_SoundSet",
				"APC_Wheeled_02_Rain_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Rock_Fast_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Grass_Fast_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Sand_Fast_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Gravel_Fast_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Mud_Fast_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Asphalt_Fast_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Water_Fast_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Rock_Slow_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Grass_Slow_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Sand_Slow_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Gravel_Slow_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Mud_Slow_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Asphalt_Slow_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Water_Slow_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Turn_Hard_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Turn_Soft_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Brake_Hard_EXT_SoundSet",
				"APC_Wheeled_02_Tires_Brake_Soft_EXT_SoundSet"
			};
			soundSetsInt[]=
			{
				"APC_Wheeled_02_Engine_RPM0_INT_SoundSet",
				"APC_Wheeled_02_Engine_RPM1_INT_SoundSet",
				"APC_Wheeled_02_Engine_RPM2_INT_SoundSet",
				"APC_Wheeled_02_Engine_RPM3_INT_SoundSet",
				"APC_Wheeled_02_Engine_RPM4_INT_SoundSet",
				"APC_Wheeled_02_Interior_Tone_Engine_Off_SoundSet",
				"APC_Wheeled_02_Interior_Tone_Engine_On_SoundSet",
				"APC_Wheeled_02_Rattling_INT_SoundSet",
				"APC_Wheeled_02_Stress_INT_SoundSet",
				"APC_Wheeled_02_Rain_INT_SoundSet",
				"APC_Wheeled_02_Tires_Rock_Fast_INT_SoundSet",
				"APC_Wheeled_02_Tires_Grass_Fast_INT_SoundSet",
				"APC_Wheeled_02_Tires_Sand_Fast_INT_SoundSet",
				"APC_Wheeled_02_Tires_Gravel_Fast_INT_SoundSet",
				"APC_Wheeled_02_Tires_Mud_Fast_INT_SoundSet",
				"APC_Wheeled_02_Tires_Asphalt_Fast_INT_SoundSet",
				"APC_Wheeled_02_Tires_Water_Fast_INT_SoundSet",
				"APC_Wheeled_02_Tires_Rock_Slow_INT_SoundSet",
				"APC_Wheeled_02_Tires_Grass_Slow_INT_SoundSet",
				"APC_Wheeled_02_Tires_Sand_Slow_INT_SoundSet",
				"APC_Wheeled_02_Tires_Gravel_Slow_INT_SoundSet",
				"APC_Wheeled_02_Tires_Mud_Slow_INT_SoundSet",
				"APC_Wheeled_02_Tires_Asphalt_Slow_INT_SoundSet",
				"APC_Wheeled_02_Tires_Water_Slow_INT_SoundSet",
				"APC_Wheeled_02_Tires_Turn_Hard_INT_SoundSet",
				"APC_Wheeled_02_Tires_Turn_Soft_INT_SoundSet",
				"APC_Wheeled_02_Tires_Brake_Hard_INT_SoundSet",
				"APC_Wheeled_02_Tires_Brake_Soft_INT_SoundSet"
			};
		};
		thrustDelay=0.25;
		brakeIdleSpeed=1.78;
		maxSpeed=105;
		fuelCapacity=45;
		wheelCircumference=3.8050001;
		waterLeakiness=2.5;
		normalSpeedForwardCoef=0.54000002;
		accelAidForceYOffset=-2.3;
		antiRollbarForceCoef=24;
		antiRollbarForceLimit=30;
		antiRollbarSpeedMin=15;
		antiRollbarSpeedMax=65;
		idleRpm=500;
		redRpm=2200;
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-4.8400002,
				"N",
				0,
				"D1",
				3.4300001,
				"D2",
				2.01,
				"D3",
				1.42,
				"D4",
				1,
				"D5",
				0.82999998,
				"D6",
				0.58999997
			};
			TransmissionRatios[]=
			{
				"High",
				8
			};
			AmphibiousRatios[]=
			{
				"R1",
				-10,
				"N",
				0,
				"D1",
				25
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		simulation="carx";
		dampersBumpCoef=3.3;
		differentialType="all_limited";
		frontRearSplit=0.5;
		frontBias=1.3;
		rearBias=1.3;
		centreBias=1.3;
		clutchStrength=35;
		enginePower=420;
		maxOmega=230;
		minOmega=50;
		peakTorque=2037.5;
		dampingRateFullThrottle=0.079999998;
		dampingRateZeroThrottleClutchEngaged=2;
		dampingRateZeroThrottleClutchDisengaged=0.34999999;
		torqueCurve[]=
		{
			
			{
				"(0/2200)",
				"(0/1630)"
			},
			
			{
				"(900/2200)",
				"(1200/1630)"
			},
			
			{
				"(1250/2200)",
				"(1500/1630)"
			},
			
			{
				"(1300/2200)",
				"(1630/1630)"
			},
			
			{
				"(1350/2200)",
				"(1600/1630)"
			},
			
			{
				"(1600/2200)",
				"(1400/1630)"
			},
			
			{
				"(2200/2200)",
				"(1200/1630)"
			},
			
			{
				"(5800/2200)",
				"(0/1630)"
			}
		};
		changeGearMinEffectivity[]={0.5,0.15000001,0.97000003,0.97000003,0.97000003,0.97000003,0.97000003,0.98500001};
		switchTime=0.1;
		latency=1.4;
		class Wheels
		{
			class L1
			{
				side="left";
				suspTravelDirection[]={-0.125,-1,0};
				boneName="wheel_1_1_damper";
				steering=1;
				center="wheel_1_1_center";
				boundary="wheel_1_1_bound";
				width="0.36";
				mass=187.5;
				MOI=60;
				dampingRate=0.1;
				dampingRateDamaged=1;
				dampingRateDestroyed=1000;
				maxBrakeTorque=45000;
				maxHandBrakeTorque=0;
				suspForceAppPointOffset="wheel_1_1_center";
				tireForceAppPointOffset="wheel_1_1_center";
				maxCompression=0.15000001;
				maxDroop=0.050000008;
				sprungMass=3100;
				springStrength=111090;
				springDamperRate=21275;
				longitudinalStiffnessPerUnitGravity=10000;
				latStiffX=25;
				latStiffY=180;
				frictionVsSlipGraph[]=
				{
					{0,1},
					{0.5,1},
					{1,1}
				};
			};
			class L2: L1
			{
				boneName="wheel_1_2_damper";
				steering=1;
				center="wheel_1_2_center";
				boundary="wheel_1_2_bound";
				suspForceAppPointOffset="wheel_1_2_center";
				tireForceAppPointOffset="wheel_1_2_center";
			};
			class L3: L1
			{
				boneName="wheel_1_3_damper";
				steering=0;
				center="wheel_1_3_center";
				boundary="wheel_1_3_bound";
				suspForceAppPointOffset="wheel_1_3_center";
				tireForceAppPointOffset="wheel_1_3_center";
				maxHandBrakeTorque=300000;
			};
			class R1: L1
			{
				side="right";
				suspTravelDirection[]={0.125,-1,0};
				boneName="wheel_2_1_damper";
				center="wheel_2_1_center";
				boundary="wheel_2_1_bound";
				suspForceAppPointOffset="wheel_2_1_center";
				tireForceAppPointOffset="wheel_2_1_center";
			};
			class R2: R1
			{
				boneName="wheel_2_2_damper";
				steering=1;
				center="wheel_2_2_center";
				boundary="wheel_2_2_bound";
				suspForceAppPointOffset="wheel_2_2_center";
				tireForceAppPointOffset="wheel_2_2_center";
			};
			class R3: R1
			{
				boneName="wheel_2_3_damper";
				steering=0;
				center="wheel_2_3_center";
				boundary="wheel_2_3_bound";
				suspForceAppPointOffset="wheel_2_3_center";
				tireForceAppPointOffset="wheel_2_3_center";
				maxHandBrakeTorque=300000;
			};
		};
		maxFordingDepth=2.3;
		class Exhausts
		{
			class Exhaust1
			{
				position="exhaust1_pos";
				direction="exhaust1_dir";
				effect="ExhaustsEffectAMV";
			};
			class Exhaust2
			{
				position="exhaust2_pos";
				direction="exhaust2_dir";
				effect="ExhaustsEffectAMV";
			};
		};
		class Reflectors
		{
			class LightCarHeadL01
			{
				color[]={1900,1800,1700};
				ambient[]={5,5,5};
				position="LightCarHeadL01";
				direction="LightCarHeadL01_end";
				hitpoint="Light_L";
				selection="Light_L";
				size=1;
				innerAngle=100;
				outerAngle=179;
				coneFadeCoef=10;
				intensity=1;
				useFlare=1;
				dayLight=0;
				flareSize=1;
				class Attenuation
				{
					start=0;
					constant=0;
					linear=1;
					quadratic=1;
					hardLimitStart=100;
					hardLimitEnd=200;
				};
			};
			class LightCarHeadR01: LightCarHeadL01
			{
				position="LightCarHeadR01";
				direction="LightCarHeadR01_end";
				hitpoint="Light_R";
				selection="Light_R";
			};
		};
		aggregateReflectors[]=
		{
			
			{
				"LightCarHeadL01",
				"LightCarHeadR01"
			}
		};
		driveOnComponent[]=
		{
			"wheel_1_1_damper_land",
			"wheel_1_2_damper_land",
			"wheel_1_3_damper_land",
			"wheel_2_1_damper_land",
			"wheel_2_2_damper_land",
			"wheel_2_3_damper_land"
		};
		maximumLoad=2000;
		attenuationEffectType="TankAttenuation";
		class RenderTargets
		{
		};
		slingLoadCargoMemoryPoints[]={};
		enableManualFire=0;
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"TKE_Ext_APC\data\apc.rvmat",
				"TKE_Ext_Core_V\data\textures\damage.rvmat",
				"A3\Air_F_Gamma\Plane_Fighter_03\Data\Plane_Fighter_03_body_1_destruct.rvmat"
			};
		};
		class TextureSources
		{
			class Camo
			{
				displayName="885th-Camo";
				author="885TH Bloodpack Division";
				textures[]=
				{
					"885_Vehicles\textures\APC-IFV\885th_apc_white_co.paa"
				};
				factions[]={};
			};
		};
		textureList[]=
		{
			"885th-Camo",
			1
		};
		class AnimationSources: AnimationSources
		{
			class HitLFWheel
			{
				hitpoint="HitLFWheel";
				raw=1;
				source="Hit";
			};
			class HitLF2Wheel: HitLFWheel
			{
				hitpoint="HitLF2Wheel";
			};
			class HitLF3Wheel: HitLFWheel
			{
				hitpoint="HitLF3Wheel";
			};
			class HitRFWheel: HitLFWheel
			{
				hitpoint="HitRFWheel";
			};
			class HitRF2Wheel: HitLFWheel
			{
				hitpoint="HitRF2Wheel";
			};
			class HitRF3Wheel: HitLFWheel
			{
				hitpoint="HitRF3Wheel";
			};
		};
		animationList[]={};
		class UserActions: UserActions
		{
		};
		class EventHandlers: EventHandlers
		{
			init="if (local (_this select 0)) then { [(_this select 0), """", [], false] call BIS_fnc_initVehicle; };";
			fired="_this call (uinamespace getvariable 'BIS_fnc_effectFired');";
			killed="_this call (uinamespace getvariable 'BIS_fnc_effectKilled');";
		};
		ace_vehicle_damage_hullDetonationProb=0.2;
		ace_vehicle_damage_turretDetonationProb=0.2;
		ace_vehicle_damage_engineDetonationProb=0.2;
		ace_vehicle_damage_hullFireProb=0.30000001;
		ace_vehicle_damage_turretFireProb=0.2;
		ace_vehicle_damage_engineFireProb=0.5;
		ace_vehicle_damage_detonationDuringFireProb=0.30000001;
		ace_vehicle_damage_canHaveFireRing=0;
		ace_vehicle_damage_slatHitpoints[]={};
		ace_vehicle_damage_eraHitpoints[]={};
		ace_vehicle_damage_turret="";
		tf_RadioType="TFAR_anprc155";
		tf_hasLRradio=1;
		tf_isolatedAmount=0.80000001;
	};
	class 885th_Draco_Unarmed: 885th_Draco_BASE
	{
		scope=2;
		scopeCurator=2;
		author="885th Bloodpack Division + Luca";
		displayName="[885th] Draco APC";
		editorPreview="";
		faction = "885th_Faction";
		crew = "885th_Pilot";
		weapons[]=
		{
			"TruckHorn2",
			"SmokeLauncher"
		};
		magazines[]=
		{
			"SmokeLauncherMag"
		};
		smokeLauncherGrenadeCount=8;
		smokeLauncherVelocity=13;
		smokeLauncherOnTurret=0;
		smokeLauncherAngle=105;
		class Turrets
		{
			class CommanderOptics: CommanderOptics
			{
				body="obsTurret";
				gun="CommanderPeriscope";
				memoryPointGunnerOutOptics="commanderview";
				memoryPointGunnerOptics="commanderview";
				minElev=-10;
				maxElev=20;
				initElev=0;
				minTurn=-360;
				maxTurn=360;
				initTurn=0;
				minCamElev=-90;
				maxCamElev=90;
				weapons[]={};
				magazines[]={};
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP01",
					0.17782794,
					1,
					10
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP01",
					0.17782794,
					1,
					10
				};
				forceHideGunner=1;
				gunnerAction="driver_hemtt";
				gunnerInAction="Driver_APC_Wheeled_03_cannon_F_in";
				gunnerGetInAction="GetInLow";
				gunnerGetOutAction="GetOutLow";
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
				gunnerOutOpticsModel="";
				gunnerOpticsEffect[]={};
				isPersonTurret=0;
				outGunnerMayFire=0;
				inGunnerMayFire=1;
				personTurretAction="vehicle_turnout_2";
				minOutElev=-45;
				maxOutElev=65;
				initOutElev=0;
				minOutTurn=-90;
				maxOutTurn=90;
				initOutTurn=0;
				gunnerForceOptics=1;
				class ViewGunner: ViewGunner
				{
				};
				class ViewOptics: ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.60000002;
					minFov=0.60000002;
					maxFov=0.60000002;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"TI"
					};
					thermalMode[]={0,1};
				};
				class OpticsIn
				{
					class Wide: ViewOptics
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.60000002;
						minFov=0.60000002;
						maxFov=0.60000002;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"TI"
						};
						thermalMode[]={0,1};
						gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_w_F.p3d";
						gunnerOpticsEffect[]={};
					};
					class Medium: Wide
					{
						gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_m_F.p3d";
						initFov=0.07;
						minFov=0.07;
						maxFov=0.07;
					};
					class Narrow: Wide
					{
						gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_n_F.p3d";
						initFov=0.028000001;
						minFov=0.028000001;
						maxFov=0.028000001;
					};
				};
				turretInfoType="RscOptics_MBT_01_commander";
				usePip=1;
				showCrewAim=1;
				startEngine=0;
				class HitPoints
				{
				};
				stabilizedInAxes=3;
				maxHorizontalRotSpeed=4;
				maxVerticalRotSpeed=4;
				gunnerHasFlares=0;
				viewGunnerInExternal=1;
			};
		};
	};
	class 885th_Draco_Autocannon: 885th_Draco_BASE
	{
		scope=2;
		scopeCurator=2;
		author="885th Bloodpack Division + Luca";
		displayName="[885th] Draco IFV";
		editorPreview="";
		faction = "885th_Faction";
		crew = "885th_Pilot";
		model="\TKE_Ext_APC\data\apc_a.p3d";
		class Reflectors
		{
			class LightCarHeadL01
			{
				color[]={1900,1800,1700};
				ambient[]={5,5,5};
				position="LightCarHeadL01";
				direction="LightCarHeadL01_end";
				hitpoint="Light_L";
				selection="Light_L";
				size=1;
				innerAngle=100;
				outerAngle=179;
				coneFadeCoef=10;
				intensity=1;
				useFlare=1;
				dayLight=0;
				flareSize=1;
				class Attenuation
				{
					start=0;
					constant=0;
					linear=1;
					quadratic=1;
					hardLimitStart=100;
					hardLimitEnd=200;
				};
			};
			class LightCarHeadR01: LightCarHeadL01
			{
				position="LightCarHeadR01";
				direction="LightCarHeadR01_end";
				hitpoint="Light_R";
				selection="Light_R";
			};
			class LightCarHeadL01_T: LightCarHeadL01
			{
				position="LightCarHeadL01_T";
				direction="LightCarHeadL01_end_T";
				hitpoint="Light_L_T";
				selection="Light_L_T";
				innerAngle=60;
				outerAngle=100;
				class Attenuation
				{
					start=0;
					constant=0;
					linear=1;
					quadratic=1;
					hardLimitStart=150;
					hardLimitEnd=300;
				};
			};
			class LightCarHeadR01_T: LightCarHeadL01_T
			{
				position="LightCarHeadR01_T";
				direction="LightCarHeadR01_end_T";
				hitpoint="Light_R_T";
				selection="Light_R_T";
			};
		};
		smokeLauncherGrenadeCount=8;
		smokeLauncherVelocity=13;
		smokeLauncherOnTurret=1;
		smokeLauncherAngle=125;
		enableManualFire=1;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						body="obsTurret";
						gun="CommanderPeriscope";
						memoryPointGunnerOutOptics="commanderview";
						memoryPointGunnerOptics="commanderview";
						minElev=-10;
						maxElev=20;
						initElev=0;
						minTurn=-360;
						maxTurn=360;
						initTurn=0;
						minCamElev=-90;
						maxCamElev=90;
						weapons[]=
						{
							"SmokeLauncher"
						};
						magazines[]=
						{
							"SmokeLauncherMag"
						};
						soundServo[]=
						{
							"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP01",
							0.17782794,
							1,
							10
						};
						soundServoVertical[]=
						{
							"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP01",
							0.17782794,
							1,
							10
						};
						forceHideGunner=1;
						gunnerAction="driver_hemtt";
						gunnerInAction="Driver_APC_Wheeled_03_cannon_F_in";
						gunnerGetInAction="GetInLow";
						gunnerGetOutAction="GetOutLow";
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
						gunnerOutOpticsModel="";
						gunnerOpticsEffect[]={};
						isPersonTurret=0;
						outGunnerMayFire=0;
						inGunnerMayFire=1;
						personTurretAction="vehicle_turnout_2";
						minOutElev=-45;
						maxOutElev=65;
						initOutElev=0;
						minOutTurn=-90;
						maxOutTurn=90;
						initOutTurn=0;
						gunnerForceOptics=1;
						class ViewGunner: ViewGunner
						{
						};
						class ViewOptics: ViewOptics
						{
							initAngleX=0;
							minAngleX=-30;
							maxAngleX=30;
							initAngleY=0;
							minAngleY=-100;
							maxAngleY=100;
							initFov=0.60000002;
							minFov=0.60000002;
							maxFov=0.60000002;
							visionMode[]=
							{
								"Normal",
								"NVG",
								"TI"
							};
							thermalMode[]={0,1};
						};
						class OpticsIn
						{
							class Wide: ViewOptics
							{
								initAngleX=0;
								minAngleX=-30;
								maxAngleX=30;
								initAngleY=0;
								minAngleY=-100;
								maxAngleY=100;
								initFov=0.60000002;
								minFov=0.60000002;
								maxFov=0.60000002;
								visionMode[]=
								{
									"Normal",
									"NVG",
									"TI"
								};
								thermalMode[]={0,1};
								gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_w_F.p3d";
								gunnerOpticsEffect[]={};
							};
							class Medium: Wide
							{
								gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_m_F.p3d";
								initFov=0.07;
								minFov=0.07;
								maxFov=0.07;
							};
							class Narrow: Wide
							{
								gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Commander_01_n_F.p3d";
								initFov=0.028000001;
								minFov=0.028000001;
								maxFov=0.028000001;
							};
						};
						turretInfoType="RscOptics_MBT_01_commander";
						usePip=1;
						showCrewAim=1;
						startEngine=0;
						class HitPoints
						{
						};
						stabilizedInAxes=3;
						maxHorizontalRotSpeed=4;
						maxVerticalRotSpeed=4;
						gunnerHasFlares=0;
						viewGunnerInExternal=1;
					};
				};
				body="mainTurret";
				gun="mainGun";
				gunBeg="usti hlavne";
				gunEnd="konec hlavne";
				weapons[]=
				{
					"TKE_Ext_Autocannon_30mm",
					"TKE_Ext_MG_Coax"
				};
				magazines[]=
				{
					"TKE_Ext_30mm_AP_200Rnd",
					"TKE_Ext_30mm_HE_250Rnd",
					"200Rnd_762x51_Belt_Yellow",
					"200Rnd_762x51_Belt_Yellow",
					"200Rnd_762x51_Belt_Yellow",
					"200Rnd_762x51_Belt_Yellow",
					"200Rnd_762x51_Belt_Yellow"
				};
				gunnerForceOptics=1;
				memoryPointGun="usti hlavne1";
				selectionFireAnim="zasleh";
				maxHorizontalRotSpeed=1;
				maxVerticalRotSpeed=1.2;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\noises\servo_APC_gunner",
					0.39810699,
					1,
					30
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\noises\servo_APC_gunner_vertical",
					0.39810699,
					1,
					30
				};
				gunnerAction="driver_hemtt";
				gunnerInAction="Driver_APC_Wheeled_03_cannon_F_in";
				forceHideGunner=1;
				gunnerGetInAction="GetInLow";
				gunnerGetOutAction="GetOutLow";
				viewGunnerInExternal=1;
				castGunnerShadow=1;
				stabilizedInAxes=3;
				memoryPointGunnerOptics="gunnerview";
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000};
				discreteDistanceInitIndex=2;
				turretInfoType="RscOptics_APC_Wheeled_01_gunner";
				usePip=0;
				minElev=-10;
				maxElev=55;
				initElev=0;
				minTurn=-360;
				maxTurn=360;
				initTurn=0;
				isPersonTurret=0;
				personTurretAction="vehicle_turnout_1";
				class OpticsIn
				{
					class Wide: ViewOptics
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.5;
						minFov=0.5;
						maxFov=0.5;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"TI"
						};
						thermalMode[]={0,1};
						gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_APC_01_w_F.p3d";
						gunnerOpticsEffect[]={};
					};
					class Medium: Wide
					{
						gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_APC_01_m_F.p3d";
						initFov=0.07;
						minFov=0.07;
						maxFov=0.07;
					};
					class Narrow: Wide
					{
						gunnerOpticsModel="\A3\Weapons_F\Reticle\Optics_Gunner_APC_01_n_F.p3d";
						initFov=0.028000001;
						minFov=0.028000001;
						maxFov=0.028000001;
					};
				};
				class ViewOptics: ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.5;
					minFov=0.5;
					maxFov=0.5;
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					thermalMode[]={0,1};
				};
				class ViewGunner: ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=15;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					minFov=0.25;
					maxFov=1.25;
					initFov=0.75;
					visionMode[]={};
				};
				class HitPoints: HitPoints
				{
					class HitTurret: HitTurret
					{
						armor="2*(19+2*19+19)/((18+2*9+9) + (19+2*19+19))";
						name="vez";
						visual="OtocVez";
					};
					class HitGun: HitGun
					{
						armor="4*100/((18+2*9+9) + (19+2*19+19))";
						name="zbranVelitele";
						visual="OtocHlaven";
					};
				};
				gunnerDoor="";
			};
		};
		class AnimationSources: AnimationSources
		{
			class muzzle_rot1
			{
				source="ammorandom";
				weapon="TKE_Ext_MG_Coax";
			};
			class recoil_source
			{
				source="reload";
				weapon="TKE_Ext_Autocannon_30mm";
			};
		};
	};

	class NewTurret;
	class Optics_Armored;
	class Optics_Gunner_APC_01 : Optics_Armored
	{
		class Wide;
		class Medium;
		class Narrow;
	};
	class 3AS_ITT_Base;
	class 885th_ITT_Base : 3AS_ITT_Base
	{
		scope = 1;
		scopeCurator = 1;
	};
	class 885th_ITT : 885th_ITT_Base
	{
		ace_cargo_hasCargo = 1;
		ace_cargo_space = 8;
		attendant = 1;
		scope = 2;
		scopeCurator = 2;
		displayname = "[885th] ITT";
		author = "3rd Army Studios + 885th Bloodpack Div";
		side = 1;
		faction = "885th_Faction";
		editorSubcategory = "Sub885thKraytLogi";
		crew = "885th_Pilot";
		cost = 800;
		hiddenSelections[] = {"camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7"};
		hiddenSelectionsTextures[] = {"885_Vehicles\textures\ITT\885_ITT_CO.paa", "3as\3as_itt\data\glass_co.paa", "3as\3as_itt\data\itt_int_back_co.paa", "3as\3as_itt\data\itt_door_co.paa", "3as\3as_itt\data\itt_int_front_co.paa", "3as\3as_itt\data\itt_emiss_co.paa", "3as\3as_itt\data\itt_turret_co.paa"};
		editorPreview = "3AS\3as_ITT\data\ui\ITT_Side_ca.paa";
	};
};