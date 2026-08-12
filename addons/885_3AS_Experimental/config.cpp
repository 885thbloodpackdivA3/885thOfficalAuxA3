class CfgPatches
{
	class 885th_EX_Weapons
	{
		author = "885th Bloodpack Division";
		name = "885th Republic Weapons";
		requiredVersion = 1.62;
		units[] = {};
		weapons[] = {
			"885th_DC15C_F",
			"885th_DC15C_GL",
			"885th_DC15L_F",
			"885th_DC15X_F",
			"885th_DLT19",
			"885th_RPS6",
			"885th_Chaingun",
			"885th_RPS6_Dispo_Base",
			"885th_RPS6_Dispo",
			"885th_RPS6_Dispo_Used",
			"885th_RPS6_G_Dispo_Base",
			"885th_RPS6_G_Dispo",
			"885th_RPS6_G_Dispo_Used",
			"885th_DC15SA_F"
		};
		ammo[] = {
			"885th_Chaingun_Ammo_Y",
			"885th_ammo_40mm_HE_Base"
		};
		magazines[] = {
			"885th_Chaingun_Drum_Mag",
			"885th_mag_40mm_HE",
		};
		requiredAddons[] = {
			"3AS_Weapons_Republic",
			"3AS_Weapons_Republic_DC15C"
		};
	};
};

class CBA_DisposableLaunchers
{
	885th_RPS6_Dispo_Base[]=
	{
		"885th_RPS6_Dispo",
		"885th_RPS6_Dispo_Used"
	};
	885th_RPS6_G_Dispo_Base[]=
	{
		"885th_RPS6_G_Dispo",
		"885th_RPS6_G_Dispo_Used"
	};
};

class CfgAmmo {
	class 3AS_Chaingun_Ammo {
		class CamShakeExplode;
		class CamShakeHit;
		class CamShakeFire;
		class CamShakePlayerFire;
	};
	class 885th_blasterbolt;
	class 885th_blasterbolt_blue;
	class GrenadeBase;
	
	class 885th_Chaingun_Ammo_Y: 3AS_Chaingun_Ammo
	{
		hit=105;
		ace_vehicle_damage_incendiary = 1.5;
		warheadName = "AP";
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Yellow_Fly";
		indirectHit=0;
		indirectHitRange=0;
		caliber=7.62;
		ACE_caliber=7.62;
		ExplosionEffects="IDA_ImpactEffect";
		cratereffects="ls_plasma_impact";
		explosive=0.50000001;
		cartridge = "";
		effectsFire="";
		proxyShape="";
		craterShape="";
		class CamShakeExplode: CamShakeExplode
		{
			power=0.1;
			duration=0.1;
			frequency=20;
			distance=74.596397;
		};
		class CamShakeHit: CamShakeHit
		{
			power = 0.01;
			duration = 0.40001;
			frequency = 20;
			distance=1;
		};
		class CamShakeFire: CamShakeFire
		{
			power=0.01;
			duration=0.1;
			frequency=20;
			distance=0;
		};
		class CamShakePlayerFire: CamShakePlayerFire
		{
			power = 0;
			duration = 0.1;
			frequency = 20;
			distance=0;
		};
	};
	
	class 885th_dc15sa_blasterbolt_blue : 885th_blasterbolt
	{
		model = "3AS\3AS_Weapons\Data\tracer_blue.p3d";
		effectfly = "3AS_PlasmaBolt_Blue_Fly";
		hit = 30;
		caliber = 5.7;
		coefGravity = 0;
	};
	// GL Ammo
	class G_40mm_HE;
	
	class 885th_ammo_40mm_HE_Base: G_40mm_HE
	{
		explosionSoundEffect="DefaultExplosion";
		simulation="shotShell";
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		hit=1000;
		indirectHit=2;
		indirectHitRange=3;
		warheadName="HE";
		visibleFire=1;
		audibleFire=30;
		visibleFireTime=3;
		dangerRadiusHit=5;
		suppressionRadiusHit=10;
		explosive=1;
		cost=10;
		deflecting=5;
		airFriction=-0.0049999999;
		fuseDistance=0.1;
		whistleDist=16;
		typicalSpeed=170;
		caliber=2;
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\Grenades\Explosion_gng_grenades_01",
			3.1622777,
			1,
			1500
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\Grenades\Explosion_gng_grenades_02",
			3.1622777,
			1,
			1500
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\Grenades\Explosion_gng_grenades_03",
			3.1622777,
			1,
			1500
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\Grenades\Explosion_gng_grenades_04",
			3.1622777,
			1,
			1500
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.25,
			"soundHit2",
			0.25,
			"soundHit3",
			0.25,
			"soundHit4",
			0.25
		};
		class CamShakeExplode
		{
			power=8;
			duration=1.2;
			frequency=20;
			distance=74.596397;
		};
		class CamShakeHit
		{
			power=20;
			duration=0.40000001;
			frequency=20;
			distance=1;
		};
		class CamShakeFire
		{
			power=0;
			duration=0.2;
			frequency=20;
			distance=0;
		};
		class CamShakePlayerFire
		{
			power=0;
			duration=0.1;
			frequency=20;
			distance=1;
		};
	};
};
class CfgMagazines {
	class 3AS_Chaingun_Drum_Mag;
	class 885th_Chaingun_Drum_Mag: 3AS_Chaingun_Drum_Mag
	{
		author="885th + 3AS Dev Team";
		displayName="[885th] 500 Rnd Chaingun Drum";
		model="\A3\weapons_f\launchers\RPG32\pg32v_rocket_item.p3d";
		picture="\3AS\3AS_Weapons\Data\UI\3as_ammo_chain.paa";
		initSpeed=1060;
		ammo="885th_Chaingun_Ammo_Y";
		mass=50;
		count=500;
	};
};
class WeaponSlotsInfo;
class SlotInfo;
class InventoryOpticsItem_Base_F;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class MuzzleSlot_65;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{	
	class arifle_MX_Base_F;
	class 885th_Stun_rifle;
	class 885th_Stun_pistol;
	
	class 3AS_DC15C_F;
	class 885th_DC15C_F : 3AS_DC15C_F
	{
		baseWeapon = "885th_DC15C_F";
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 610;
		ace_barrelTwist = 0;
		scope = 2;
		displayName = "[885th] DC-15C Rifle";
		magazines[] = {"885th_dc15c_cell"};
		magazineWell[] = {};
		muzzles[] = {"this", "Stun"};
		fireLightDiffuse[]={0.1,0.25,1};
		class Stun : 885th_Stun_rifle {};
		class WeaponSlotsInfo : WeaponSlotsInfo {
			mass = 65;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"3AS_optic_DC15C_F","3AS_Imp_Optic_E11","3AS_optic_DC15L_F"};
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {"acc_flashlight"};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};

	class GL_3GL_F;
	class 3AS_DC15C_GL;
	class 885th_DC15C_GL : 3AS_DC15C_GL 
	{
		baseWeapon = "885th_DC15C_GL";
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 610;
		ace_barrelTwist = 0;
		scope = 2;
		displayName = "[885th] DC-15C Rifle (GL)";
		magazines[] = {"885th_dc15c_cell"};
		magazineWell[]={};
		fireLightDiffuse[]={0.1,0.25,1};
		muzzles[] = {"this","GL_3GL_F"};
		class GL_3GL_F : GL_3GL_F {};
		class WeaponSlotsInfo : WeaponSlotsInfo {
			mass = 65;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"3AS_optic_DC15C_F","3AS_Imp_Optic_E11","3AS_optic_DC15L_F","885th_Optic_Scope_WestarM5"};
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {"acc_flashlight"};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};
	
	class 3AS_DC15L_F;
	class 885th_DC15L_F : 3AS_DC15L_F 
	{
		baseWeapon = "885th_DC15L_F";
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 450;
		ace_barrelTwist = 0;
		scope = 2;
		displayName = "[885th] DC-15L LMG";
		magazines[] = {
			"885th_dc15l_cell"};
		magazineWell[] = {};
		muzzles[] = {"this"};
		fireLightDiffuse[]={0.1,0.25,1};
	};

	class 3AS_DC15X_F;
	class 885th_DC15X_F : 3AS_DC15X_F 
	{
		baseWeapon = "885th_DC15X_F";
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 0;
		ace_barrelTwist = 0;
		scope = 2;
		displayName = "[885th] DC-15X Sniper Rifle";
		magazines[] = {"885th_dc15xsniper_ap_cell","885th_dc15xsniper_over_cell"};
		magazineWell[] = {};
		muzzles[] = {"this"};
		fireLightDiffuse[]={0.1,0.25,1};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			reloadTime=1.3;
			dispersion = 0.0004;
			minRange=200;
			minRangeProbab=0.5;
			midRange=500;
			midRangeProbab=0.69999999;
			maxRange=800;
			maxRangeProbab=0.30000001;
			soundContinuous=0;
			soundBurst=0;
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				begin1[]=
				{
					"\ShadowLegion_Weapons\data\DC15\DC15X\DC15X_1.ogg",
					2,
					1,
					900
				};
				begin2[]=
				{
					"\ShadowLegion_Weapons\data\DC15\DC15X\DC15X_2.ogg",
					2,
					1,
					900
				};
				begin3[]=
				{
					"\ShadowLegion_Weapons\data\DC15\DC15X\DC15X_3.ogg",
					2,
					1,
					900
				};
				soundBegin[]=
				{
					"begin1",
					0.33000001,
					"begin2",
					0.33000001,
					"begin3",
					0.34
				};
				beginwater1[]=
				{
					"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",
					1,
					1,
					200
				};
				soundBeginWater[]=
				{
					"beginwater1",
					0.5
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]=
				{
					"ShadowLegion_Weapons\data\surpressed_1.ogg",
					2,
					1,
					200
				};
				begin2[]=
				{
					"ShadowLegion_Weapons\data\surpressed_2.ogg",
					2,
					1,
					200
				};
				begin3[]=
				{
					"ShadowLegion_Weapons\data\surpressed_3.ogg",
					2,
					1,
					200
				};
				begin4[]=
				{
					"ShadowLegion_Weapons\data\surpressed_4.ogg",
					2,
					1,
					200
				};
				begin5[]=
				{
					"ShadowLegion_Weapons\data\surpressed_5.ogg",
					2,
					1,
					200
				};
				begin6[]=
				{
					"ShadowLegion_Weapons\data\surpressed_6.ogg",
					2,
					1,
					200
				};
				soundBegin[]=
				{
					"begin1",
					0.5,
					"begin2",
					0.5,
					"begin3",
					0.5,
					"begin4",
					0.5,
					"begin5",
					0.5,
					"begin6",
					0.5
				};
				beginwater1[]=
				{
					"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",
					1,
					1,
					200
				};
				soundBeginWater[]=
				{
					"beginwater1",
					0.5
				};
			};
		};
		class WeaponSlotsInfo : WeaponSlotsInfo {
			mass = 65;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"3AS_optic_DC15X_F","JLTS_DC15X_scope","optic_KHS_blk"};
			};
			class MuzzleSlot : MuzzleSlot
			{	
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[] = {"ShadwCmpany_Suppresor_Module_DC15"};
			};
			class PointerSlot : PointerSlot
			{	
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[] = {"acc_flashlight","acc_pointer_IR","ace_acc_pointer_red","ace_acc_pointer_green"};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {"3AS_Bipod_VK38X_f","ShdwCmpny_Bipod_Valken"};
			};
		};
	};
	// Launchers
	
	class 3AS_RPS6_HP;
	class 885th_RPS6 : 3AS_RPS6_HP {
		baseWeapon = "885th_RPS6";
		author="885th + 3AS DEV Team";
		scope=2;
		displayName="[885th] RPS6";
		model="\3AS\3AS_Weapons\RPS6\3AS_RPS6_F.p3d";
		picture="\3AS\3AS_Weapons\RPS6\Data\UI\3as_rps6d.paa";
		UiPicture="\3AS\3AS_Weapons\RPS6\Data\UI\3as_rps6d.paa";
		handAnim[]={"OFP2_ManSkeleton","3as\3AS_Weapons\Imperial\anims\HH12hand.rtm"};
		reloadAction="ReloadRPG";
		recoil="recoil_rpg";
		maxZeroing=600;
		modelOptics="\A3\Weapons_F\acc\reticle_RPG_F";
		weaponInfoType="RscWeaponEmpty";
		opticsZoomMin=0.1083;
		opticsZoomMax=0.1083;
		opticsZoomInit=0.1083;
		cameraDir="look";
		class GunParticles
		{
			class effect1
			{
				positionName="konec hlavne";
				directionName="usti hlavne";
				effectName="RocketBackEffectsRPGNT";
			};
		};
		class OpticsModes
		{
			class optic
			{
				opticsID=1;
				useModelOptics=1;
				opticsZoomMin=0.1083;
				opticsZoomMax=0.1083;
				opticsZoomInit=0.1083;
				distanceZoomMin=300;
				distanceZoomMax=300;
				memoryPointCamera="eye";
				opticsFlare=1;
				opticsDisablePeripherialVision=1;
				cameraDir="look";
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				opticsPPEffects[]=
				{
					"OpticsCHAbera1",
					"OpticsBlur1"
				};
			};
		};
	};
	
	class 3AS_RPS6_F;
	class 885th_RPS6_Dispo_Base: 3AS_RPS6_F
	{
		displayName="[885th] Disposable RPS6";
		baseWeapon="885th_RPS6_Dispo";
		magazines[]=
		{
			"3AS_MK40_AT"
		};
	};
	
	class 885th_RPS6_Dispo: 885th_RPS6_Dispo_Base
	{
		scope=2;
		baseWeapon="885th_RPS6_Dispo";
		magazines[]=
		{
			"CBA_FakeLauncherMagazine"
		};
		class WeaponSlotsInfo
		{
			mass=100;
		};
	};
	
	class 885th_RPS6_Dispo_Used: 885th_RPS6_Dispo_Base
	{
		scope=1;
		displayName="[885th] Used Disposable RPS-6";
		baseWeapon="885th_RPS6_Dispo_Used";
		magazines[]=
		{
			"CBA_FakeLauncherMagazine"
		};
	};
	
	class 3AS_RPS6_G;
	class 885th_RPS6_G_Dispo_Base: 3AS_RPS6_G
	{
		displayName="[885th] Disposable RPS6 Guided";
		baseWeapon="885th_RPS6_G_Dispo";
		magazines[]=
		{
			"3AS_MK40_AT_Guided"
		};
	};
	class 885th_RPS6_G_Dispo: 885th_RPS6_G_Dispo_Base
	{
		scope=2;
		baseWeapon="885th_RPS6_G_Dispo";
		magazines[]=
		{
			"CBA_FakeLauncherMagazine"
		};
		class WeaponSlotsInfo
		{
			mass=100;
		};
	};
	class 885th_RPS6_G_Dispo_Used: 885th_RPS6_G_Dispo_Base
	{
		scope=1;
		displayName="[885th] Used Disposable RPS-6";
		baseWeapon="885th_RPS6_G_Dispo_Used";
		magazines[]=
		{
			"CBA_FakeLauncherMagazine"
		};
	};
	
	class 3AS_Chaingun;
	class 885th_Chaingun : 3AS_Chaingun {
		scope=0;
		baseWeapon = "885th_Chaingun";
		displayName = "[885th] Z7 Chaingun";
		magazines[] = {"885th_Chaingun_Drum_Mag"};
		recoil="885_recoil_DC17M";//"885_recoil_Z6";
		modes[]={"FullAuto"};
		swayCoef = 0.0;
		class FullAuto: Mode_FullAuto
		{
			sounds[]={"StandardSound"};
			class BaseSoundModeType
			{
				closure1[]={"A3\sounds_f\weapons\gatling\gatling_rotation_short_2",0.316228,1,20};
				soundClosure[]={"closure1",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]={"3AS\3AS_Main\Sounds\Z6\Z61.ogg",0.94999999,1,2000};
				soundBegin[]={"begin1",0.1};
			};
			reloadTime=0.055;
			dispersion=0.00174;
			minRange=2;
			minRangeProbab=0.30000001;
			midRange=300;
			midRangeProbab=0.69999999;
			maxRange=600;
			maxRangeProbab=0.050000001;
			soundBurst=0;
			burst=1;
			displayName="Full";
			textureType="fullAuto";
		};
		ace_overpressure_angle=0;
		ace_overpressure_range=0;
		ace_overpressure_damage=0;
	};	
};
