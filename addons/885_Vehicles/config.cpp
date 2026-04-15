class Cfgpatches
{
	class 885th_Vehicles
	{
		author = "885th Bloodpack Div";
		requiredAddons[] = {"A3_Data_F", "A3_Weapons_F", "A3_Characters_F", "3AS_LAAT", "3AS_ARC_170", "3AS_ITT", "ls_core"};
		requiredVersion = 0.1;
		units[] = {
			"885th_LSV_base_F",
			"885th_LSV_EWeb",
			"885th_LAAT_Gunship",
			"885th_Smith_LAAT_Gunship",
			"885th_ITT_Base",
			"885th_ITT",
			"885th_ATTE_base",
			"885th_ATTE",
			"885th_Saber_Base",
			"885th_Saber",
			"885th_ARC170_Base",
			"885th_ARC170",
			"885th_VWING",
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
	class Sub885thAir
	{
		displayName = "Nightsingers";
	};
	class Sub885thTransports
	{
		displayName = "Ground Transport";
	};
	class Sub885thArmor
	{
		displayName = "Tanks";
	};
	class Sub885thRecon
	{
		displayName = "Recon"
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
		editorSubcategory = "Sub885thAir";
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
	class 885th_Smith_LAAT_Gunship : 3AS_LAAT_Mk1
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
		displayname = "[885th] Smith's LAAT/I Mk.1";
		driverAction = "LAAT_Pilot";
		driverCompartments = "Compartment1";
		editorpreview = "\3AS\3AS_Laat\LAATI\data\editorpreview\3AS_laat.jpg";
		enableGPS = 1;
		enableManualFire = 1;
		enableRadio = 1;
		side = 1;
		faction = "885th_Faction";
		editorSubcategory = "Sub885thAir";
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
		hiddenSelectionsTextures[] = {"885_Vehicles\textures\laat\Smith\Hull_CO.paa", "885_Vehicles\textures\laat\Smith\Wings_CO.paa", "885_Vehicles\textures\laat\Smith\Weapons_CO.paa", "885_Vehicles\textures\laat\Smith\Weapon_Details_CO.paa", "885_Vehicles\textures\laat\Smith\Interior_CO.paa"};
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
		weapons[] = {"3as_LAAT_Medium_Canon", "3AS_LAAT_Missile_AGM", "3AS_LAAT_Missile_AA", "CMFlareLauncher", "Laserdesignator_pilotCamera"};
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
		editorSubcategory = "Sub885thAir";
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
		editorSubcategory = "Sub885thAir";
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
		editorSubcategory = "Sub885thTransports";
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
		editorSubcategory = "Sub885thAir";
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
		editorSubcategory = "Sub885thTransports";
		crew = "885th_Pilot";
		cost = 800;
		hiddenSelections[] = {"camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7"};
		hiddenSelectionsTextures[] = {"885_Vehicles\textures\ITT\885_ITT_CO.paa", "3as\3as_itt\data\glass_co.paa", "3as\3as_itt\data\itt_int_back_co.paa", "3as\3as_itt\data\itt_door_co.paa", "3as\3as_itt\data\itt_int_front_co.paa", "3as\3as_itt\data\itt_emiss_co.paa", "3as\3as_itt\data\itt_turret_co.paa"};
		editorPreview = "3AS\3as_ITT\data\ui\ITT_Side_ca.paa";
	};
};