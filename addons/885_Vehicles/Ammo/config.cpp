CfgPatches
{
    class 885th_VehiclesWeapons
    {
		author="$STR_3as_Studio";
		requiredAddons[]=
		{
			"A3_Data_F_Tank_Loadorder",
			"3AS_Weapons",
			"3AS_Main"
		};
		requiredVersion=0.1;
		units[]=
		{
			"Tank_885th_AP_Round",
            "Air_885th_AP_Round",
            "Tank_885th_HEAT",
			"Tank_885th_AT",
            "Tank_885th_HE",
            "Air_885th_Light"
            "Air_885th_Med",
            "Air_885th_Heavy",
            "Air_885th_Concussion_Missile",
            "Air_885th_Discord_Missile"
		};
        weapons[]=
		{
			"885th_SaberCannons_Base",
            "885th_SaberCannons",
            "885th_Saber_HE_Rocketpods",
            "885th_Saber_HEAT_Missiles",
            "885th_Saber_AP_Turret",
            "885th_Saber_Laser_Turret",
            "885th_Fighter_20mm_Cannon",
            "885th_Fighter_30mm_Cannon",
            "885th_Fighter_AMRAAM",
            "885th_Fighter_AGM",
            "885th_ATRT_Cannon",
            "885th_ATRT_Launcher",
		};
        magazines=[]
        {
            "885th_100rd_Saber_Mag",
            "885th_500rd_SaberOC_Mag",
            "885th_2500rd_Saber_Laser_Mag",
            "885th_20rd_Saber_Rocket_Mag",
            "885th_6rd_Saber_Missiles_Mag",
            "885th_500rd_Saber_APMG_Mag",
            "885th_10rd_SAM_AMRAAM",
            "885th_10rd_AGM",
            "885th_1000rd_LowEnergy_Cannons",
            "885th_750rd_HighEnergy_Cannons",
            "885th_5000rd_MedEnergy_Battery",
            "885th_6rd_ATRT_HE_Launcher"
        };
        ammo[]=
        {
            "885th_PlasmaBase",
            "885th_RocketBase",
            "885th_MissileBase",
            "885th_Saber_HE",
            "885th_Saber_HEAT",
            "885th_Saber_OC",
            "885th_Saber_AP",
            "885th_Saber_OGMG",
            "885th_Ammo_AMRAAM",
            "885th_Ammo_AGM",
            "885th_Fighter_LowEnergy_Shell",
            "885th_Fighter_HighEnergy_Shell",
            "885th_Interceptor_LowEnergy_Shell",
            "885th_Interceptor_HighEnergy_Shell",
            "885th_Recon_MEnergy_Shell",
            "885th_Recon_HE_Launcher"
        };
    };
};
class Mode_SemiAuto;
class Mode_FullAuto;
class Mode_Burst;
class SlotInfo;
class MuzzleSlot;
class CowsSlot;
class PointerSlot;
class UnderBarrelSlot;
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
class CfgAmmo
{
	class ShellBase;
	class BulletBase;
    class RocketBase;
	class SubmunitionBase;
	class B_40MM_GPR;
	class Sh_120mm_HEAT_MP;
	class Sh_120mm_APFSDS;
	class G_40mm_HEDP;
	class B_30mm_HE;
	class B_35mm_AA;
	class B_20mm;
	class Sh_155mm_AMOS;
    class 885th_PlasmaBase: BulletBase
    {
        class HitEffects;
    };
    class 3AS_EC60_RedPlasma;
	class 3AS_EG20_GreenPlasma;
	class 3AS_EM20_RedPlasma;
	class R_230mm_fly;
	class R_80mm_HE;
	class ammo_Missile_AMRAAM_D;
	class M_PG_AT;
	class M_AT;
	class ammo_Penetrator_Base;
	class M_Scalpel_AT;
	class Cannon_30mm_HE_Plane_CAS_02_F;
	class Bomb_04_F;
	class MissileCore;
	class MissileBase: MissileCore
	{
		class Components;
	};
	class FlareCore;
	class ShotDeployBase;
	class Missile_AGM_01_F;
	class M_Air_AA;
	class Bo_Mk82;
    class 885th_Recon_HE_Launcher: G_40mm_HEDP
    {
		hit=85;
		indirectHit=35;
		indirectHitRange=7;
		explosive=1
		warheadName="HEAT";
		effectFly="3AS_PlasmaBolt_Yellow_Fly";
        typicalSpeed= 400;
	};
    class 885th_Saber_HE: 885th_PlasmaBase
    {
		soundFly[]=
		{
			"",
			1,
			1,
			50
		};
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_01",
			1.7782794,
			1,
			1600
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_02",
			1.7782794,
			1,
			1600
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_03",
			1.7782794,
			1,
			1600
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_04",
			1.7782794,
			1,
			1600
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
		explosionSoundEffect="DefaultExplosion";
		hit=305;
		indirectHit=25;
		indirectHitRange=7;
		warheadName="HEAT";
		submunitionAmmo="ammo_Penetrator_120mm";
		submunitionDirectionType="SubmunitionModelDirection";
		caliber=20;
		explosive=0.80000001;
		explosionEffects="ExploAmmoExplosion";
		craterEffects="ExploAmmoCrater";
		cartridge="";
		visibleFire=32;
		audibleFire=200;
		visibleFireTime=3;
		dangerRadiusBulletClose=20;
		dangerRadiusHit=60;
		suppressionRadiusBulletClose=10;
		suppressionRadiusHit=14;
		model="3as\3as_weapons\data\tracer_shell_blue.p3d";
		cost=40;
		fuseDistance=3;
		typicalSpeed=990;
		tracerStartTime=9.9999997e-005;
		tracerScale=2;
		tracerEndTime=10;
		aiAmmoUsageFlags="64 + 128 + 512";
		effectFly="3AS_PlasmaBolt_Medium_Blue_Fly";
		class CamShakeExplode
		{
			power=3.8;
			duration=0.80000001;
			frequency=20;
			distance=50.871201;
		};
		class CamShakeHit
		{
			power=19;
			duration=0.40000001;
			frequency=20;
			distance=1;
		};
		class CamShakeFire
		{
			power=2.0878;
			duration=0.80000001;
			frequency=20;
			distance=34.871201;
		};
		class CamShakePlayerFire
		{
			power=0.0099999998;
			duration=0.1;
			frequency=20;
			distance=1;
		};
		ace_frag_enabled=1;
		ace_frag_metal=450;
		ace_frag_charge=18;
		ace_frag_gurney_c=2377;
		ace_frag_gurney_k="1/2";
		ace_frag_classes[]=
		{
			"ACE_frag_tiny_HD",
			"ACE_frag_tiny"
		};
		ace_frag_skip=0;
		ace_frag_force=1;
	};
    class 885th_Saber_HEAT: 885th_Saber_HE
    {
		hit=605;
		indirecthit=5;
		indirecthitrange=1;
		warheadName="AT";
		submunitionAmmo="ammo_Penetrator_120mm";
		submunitionDirectionType="SubmunitionModelDirection";
		caliber=35;
		explosive=0.2;
		effectFly="3AS_PlasmaBolt_Medium_Blue_Fly";
	};
    class 885th_Saber_OC: 885th_Saber_HE
    {
		hit=800;
		indirecthit=5;
		indirecthitrange=1;
		warheadName="AT";
		submunitionAmmo="ammo_Penetrator_120mm";
		submunitionDirectionType="SubmunitionModelDirection";
		caliber=35;
		explosive=0.4;
		effectFly="3AS_PlasmaBolt_Medium_Blue_Fly";
	};
    class B_127x99_Ball;
    class 885th_Saber_AP: B_127x99_Ball
     {
		hit=50;
		indirecthit=5;
		indirecthitrange=1;
		warheadName="AP";
		caliber=3.5;
		explosive=0.1;
		effectFly="3AS_PlasmaBolt_Medium_Blue_Fly";
	};
    class 885th_Saber_OGMG: BulletBase
    {
		hit=65;
		indirectHit=16;
		indirectHitRange=3.3;
		weaponType="cannon";
		warheadName="HE";
		explosive=0.40000001;
		caliber=3.4000001;
		cost=30;
		model="3as\3as_weapons\data\tracer_shell_blue.p3d";
		tracerScale=1;
		tracerStartTime=0.050000001;
		tracerEndTime=1;
		nvgOnly=0;
		deflecting=0;
		typicalSpeed=1030;
		visibleFire=32;
		audibleFire=200;
		visibleFireTime=4;
		dangerRadiusBulletClose=16;
		dangerRadiusHit=40;
		suppressionRadiusBulletClose=10;
		suppressionRadiusHit=14;
		aiAmmoUsageFlags="64 + 128 + 512";
		effectFly="3AS_PlasmaBolt_Medium_Blue_Fly";
		soundSetSonicCrack[]=
		{
			"3AS_HeavyPlasma_Flyby_SoundSet"
		};
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\grenades\Explosion_mini_grenade_01",
			1.7782794,
			1,
			1300
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\grenades\Explosion_mini_grenade_02",
			1.7782794,
			1,
			1300
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\grenades\Explosion_mini_grenade_03",
			1.7782794,
			1,
			1300
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\grenades\Explosion_mini_grenade_04",
			1.7782794,
			1,
			1300
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
		explosionSoundEffect="DefaultExplosion";
		airLock=1;
		CraterEffects="ExploAmmoCrater";
		explosionEffects="ExploAmmoExplosion";
		airFriction=-0.00078;
		muzzleEffect="";
		class CamShakeExplode
		{
			power=4;
			duration=0.80000001;
			frequency=20;
			distance=43.7771;
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
			power=2.1147399;
			duration=0.80000001;
			frequency=20;
			distance=35.7771;
		};
		class CamShakePlayerFire
		{
			power=0.0099999998;
			duration=0.1;
			frequency=20;
			distance=1;
		};
	};
    class 885th_Ammo_AMRAAM: ammo_Missile_AMRAAM_D
    {
		initTime=0.40000001;
		cost=10;
		proxyShape="\A3\Weapons_F\Ammo\Missile_AA_02_F.p3d";
		model="\A3\Weapons_F\Ammo\Missile_AT_02_fly_F";
		effectsMissile="3AS_Rocket_effect_Purple_fly";
        proxyShape = "\A3\Weapons_F\Ammo\Missile_AA_04_F";
        airLock = 2;              
        irLock = 0;               
        activeRadarLock = 1;   
        maxSpeed = 1360;          
        maneuverability = 25;
        sideAirFriction = 0.1;
        allowAgainstInertialTarget = 1;
        mineDetectionDistance = 500;
	};
    class 885th_Ammo_AGM: M_Scalpel_AT
    {
		displayname="High Explosive AT";
		warheadName="AT";
		hit=1000;
		model="3AS\3as_Laat\LAATI\model\proton_torpedo.p3d";
		indirecthit=500;
		indirecthitrange=3;
		caliber=50;
        simulation = "shotMissile"; 
        irLock = 1;                 
        laserLock = 1;            
        maneuverability = 15;
	};
    class 885th_Saber_HEAT_Missiles: Sh_120mm_HEAT_MP
    {
		hit=400;
		warheadName="TandemHEAT";
		submunitionAmmo="ammo_Penetrator_120mm";
		submunitionDirectionType="SubmunitionModelDirection";
		simulation="shotbullet";
		submunitionInitSpeed=100;
		submunitionParentSpeedCoef=0;
		submunitionInitialOffset[]={0,0,-0.2};
		indirectHit=30;
		indirectHitRange=5;
		typicalSpeed=100;
		deflecting=0;
		explosive=1;
		cost=50;
		airFriction=0.000275;
		airlock=0;
		model="3AS\3AS_Weapons\Data\tracer_purple.p3d";
		tracerScale=2;
		tracerStartTime=0.0099999998;
		timeToLive=3;
		tracerEndTime=3;
		effectFly="3AS_PlasmaBolt_Medium_Blue_Fly";
		soundFly[]=
		{
			"3AS\3AS_Main\Sounds\Impact\Large_blaster_flyby_1.ogg",
			0.56234133,
			1,
			1500
		};
		muzzleEffect="";
		CraterEffects="ATRocketCrater";
		explosionEffects="MortarExplosion";
		explosionSoundEffect="DefaultExplosion";
		aiAmmoUsageFlags="64 + 128 + 256 + 512";
		class CamShakeExplode
		{
			power=3.6055501;
			duration=0.80000001;
			frequency=20;
			distance=10.8167;
		};
		class CamShakeHit
		{
			power=13;
			duration=0.40000001;
			frequency=20;
			distance=1;
		};
	};
    class 885th_Saber_HE_Rocketpods: RocketBase
    {
        model = "\A3\Weapons_F\Ammo\Rocket_04_HE_F";
        hit = 100;                                  
        indirectHit = 50;                           
        indirectHitRange = 10;                      
        cost = 200;
        maxSpeed = 600;                             
        thrustTime = 1.5;                           
        thrust = 400;
        sideAirFriction = 0.05;
        effectsRocket = "missile4";                 
        explosive = 0.8;                            
        simulation = "shotRocket";
    };
    class 885th_Fighter_LowEnergy_Shell: BulletBase
    {
        model = "\A3\Weapons_f\Data\bullet_tracer\tracer_blue";
        hit = 60;                           
        indirectHit = 8;                    
        indirectHitRange = 2;               
        explosive = 0.6;                    
        caliber = 3.2;                      
        typicalSpeed = 1050;                
        airFriction = -0.0006;
        effectFly = "3AS_PlasmaBolt_Medium_green_Fly"; 
        craterEffects = "ExploAmmoCrater";
        explosionEffects = "ExploAmmoExplosion";
    };
    class 885th_Fighter_HighEnergy_Shell: Cannon_30mm_HE_Plane_CAS_02_F
    {
		displayname="Heavy Energy";
		warheadName="HEnergy";
		hit=450;
		indirecthit=95;
		indirecthitrange=5;
		caliber=30;
		airlock=1;
		model="3as\3as_weapons\data\tracer_red.p3d";
		effectFly="3AS_PlasmaBolt_Large_Red_Fly";
		aiAmmoUsageFlags="128 + 512";
		soundSetSonicCrack[]=
		{
			"3AS_HeavyPlasma_Flyby_SoundSet"
		};
	};
    class 885th_Interceptor_LowEnergy_Shell: 885th_Fighter_LowEnergy_Shell
    {
		hit=325;
		indirecthit=15;
		indirecthitrange=1;
		caliber=22;
		airFriction=-0.00030000001;
		model="3as\3as_weapons\data\tracer_green.p3d";
		effectFly="3AS_PlasmaBolt_Medium_Green_Fly";
	};
    class 885th_Interceptor_HighEnergy_Shell: 885th_Fighter_LowEnergy_Shell
   {
		displayname="Heavy Energy";
		warheadName="High Energy";
		hit=340;
		indirecthit=75;
		indirecthitrange=2;
		caliber=30;
		airlock=1;
		model="3as\3as_weapons\data\tracer_red.p3d";
		effectFly="3AS_PlasmaBolt_Medium_Red_Fly";
		soundSetSonicCrack[]=
		{
			"3AS_HeavyPlasma_Flyby_SoundSet"
		};
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class VehicleMagazine;
	class 200Rnd_40mm_G_belt: VehicleMagazine
	{
	};
	class 60RND_40MM_GPR_shells: VehicleMagazine
	{
	};
	class 32Rnd_155mm_Mo_shells: VehicleMagazine
	{
	};
	class 20Rnd_120mm_HEAT_MP: VehicleMagazine
	{
	};
	class 20Rnd_125mm_APFSDS: VehicleMagazine
	{
	};
	class magazine_Missile_AMRAAM_D_x1: VehicleMagazine
	{
	};
	class PylonMissile_Missile_BIM9X_x1;
	class PylonMissile_Bomb_GBU12_x1;
	class PylonRack_Missile_AGM_02_x2;
	class PylonMissile_1Rnd_Missile_AA_03_F;
	class 500Rnd_Cannon_30mm_Plane_CAS_02_F;
    class 885th_100rd_Saber_Mag: VehicleMagazine
    {
		author="885th Bloodpack Division";
		scope=2;
		displayName="100Rnd Saber Magazine";
		displayNameShort="HEAT";
		ammo="885th_Saber_HE";
		count=100;
		initSpeed=990;
		maxLeadSpeed=83.333298;
		nameSound="mg";
		tracersEvery=1;
		muzzleImpulseFactor[]={0.5,0.5};
	};
    class 885th_500rd_SaberOC_Mag: VehicleMagazine
     {
		author="885th Bloodpack Division";
		scope=2;
		displayName="500Rnd Saber Battery";
		displayNameShort="OC";
		ammo="885th_Saber_OC";
		count=500;
		initSpeed=1000;
		maxLeadSpeed=83.333298;
		nameSound="mg";
		tracersEvery=1;
		muzzleImpulseFactor[]={0.5,0.5};
	};
    class 885th_2500rd_Saber_Laser_Mag: VehicleMagazine
    {
        author="885th Bloodpack Division";
		scope=2;
		displayName="2500Rnd Saber Laser";
		displayNameShort="OG";
		ammo="885th_Saber_OGMG";
		count=2500;
		initSpeed=1000;
		maxLeadSpeed=83.333298;
		tracersEvery=5;
		nameSound="cannon";
		muzzleImpulseFactor[]={0.1,0.80000001};
    };
    class 885th_500rd_Saber_APMG_Mag: VehicleMagazine
     {
        author="885th Bloodpack Division";
		scope=2;
		displayName="500Rnd MG Anti- Personnel Mag";
		displayNameShort="APMG";
		ammo="885th_Saber_AP";
		count=500;
		initSpeed=1000;
		maxLeadSpeed=83.333298;
		tracersEvery=5;
		nameSound="cannon";
		muzzleImpulseFactor[]={0.1,0.80000001};
    };
    class 885th_20rd_Saber_Rocket_Mag: VehicleMagazine
     {
        author="885th Bloodpack Division";
		scope=2;
        displayName="20Rnd HE Saber Rocket Pods";
		displayNameShort="HE-RP";
		ammo="885th_Saber_HE_Rocketpods";
		count=20;
		initSpeed=50;
		maxLeadSpeed=83.333298;
		tracersEvery=1;
		nameSound="missiles";
		muzzleImpulseFactor[]={0.1,0.80000001};
    };
    class 885th_6rd_Saber_Missiles_Mag: VehicleMagazine
     {
        author="885th Bloodpack Division";
		scope=2;
        displayName="6Rnd HE Saber Rocket Pods";
		displayNameShort="Saber AGM";
		ammo="885th_Ammo_AGM";
		count=6;
		initSpeed=0;
		maxLeadSpeed=150;
		tracersEvery=1;
		nameSound="missiles";
		muzzleImpulseFactor[] = {0.5, 1.2};
    };
    class 885th_6rd_ATRT_HE_Launcher: VehicleMagazine
    {
        author = "885th Bloodpack Division";
        scope = 2;
        displayName = "6rd ATRT HE Launcher";
        displayNameShort = "40mm GL";
        ammo = "885th_Recon_HE_Launcher";
        count = 6;
        initSpeed = 120; 
        maxLeadSpeed = 25;
        tracersEvery = 1;
        nameSound = "grenadelauncher";
        muzzleImpulseFactor[] = {0.4, 0.6};
    };
    class 885th_10rd_SAM_AMRAAM: magazine_Missile_AMRAAM_D_x1
    {
        author="885th Bloodpack Division";
		scope=2;
        displayName="10Rnd AMRAAM AIM-120A";
		displayNameShort="F-BVR";
		ammo="885th_Ammo_AMRAAM";
		count=10;
		initSpeed=50;
    };
    class 885th_10rd_AGM: VehicleMagazine
    {
        author="885th Bloodpack Division";
		scope=2;
        displayName="10Rnd High-Yield AGM";
		displayNameShort="F-AGM";
		ammo="885th_Ammo_AGM";
		count=10;
		initSpeed=50;
        maxLeadSpeed = 100;
        tracersEvery = 1;
        nameSound = "missiles";
        muzzleImpulseFactor[] = {0.1, 0.5};
    };
    class 885th_1000rd_LowEnergy_Cannons: VehicleMagazine
    {
        author="885th Bloodpack Division";
		scope=2;
        displayName="1000rd LowEnergy HEI Cannons";
		displayNameShort="LE-HEI";
		ammo="885th_Fighter_LowEnergy_Shell";
		count=1000;
		initSpeed=1050;
        maxLeadSpeed = 100;
        tracersEvery = 1;
        nameSound="cannon";
        muzzleImpulseFactor[] = {0.2, 0.4};
    };
};
class CfgWeapons
{
	class CannonCore;
	class autocannon_Base_F: CannonCore
	{
		class player;
	};
	class mortar_155mm_AMOS: CannonCore
	{
	};
	class cannon_120mm: CannonCore
	{
		class player;
	};
	class MGun;
	class GMG_20mm;
	class GMG_F: MGun
	{
	};
	class GMG_40mm: GMG_F
	{
		class manual;
	};
	class missiles_DAGR;
	class weapon_AMRAAMLauncher;
	class LMG_RCWS: MGun
	{
		class manual: MGun
		{
		};
		class close: manual
		{
		};
		class short: close
		{
		};
		class medium: close
		{
		};
		class far: close
		{
		};
	};
	class LMG_M200: LMG_RCWS
	{
	};
	class weapon_GBU12Launcher;
	class weapon_AGM_65Launcher;
	class weapon_BIM9xLauncher;
	class missiles_ASRAAM;
	class weapon_AGM_KH25Launcher;
	class rockets_Skyfire;
	class RocketPods;
	class Mk82BombLauncher;
	class Cannon_30mm_Plane_CAS_02_F: CannonCore
	{
		class LowROF;
	};
    class 885th_SaberCannons: MGun
    {
		class GunClouds
		{
		};
		bullet1[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_01",
			0.2818383,
			1,
			10
		};
		bullet2[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_02",
			0.2818383,
			1,
			10
		};
		bullet3[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_03",
			0.2818383,
			1,
			10
		};
		bullet4[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_04",
			0.2818383,
			1,
			10
		};
		bullet5[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_01",
			0.2818383,
			1,
			10
		};
		bullet6[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_02",
			0.2818383,
			1,
			10
		};
		bullet7[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_03",
			0.2818383,
			1,
			10
		};
		bullet8[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Dirt_04",
			0.2818383,
			1,
			10
		};
		bullet9[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_01",
			0.2818383,
			1,
			10
		};
		bullet10[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_02",
			0.2818383,
			1,
			10
		};
		bullet11[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_03",
			0.2818383,
			1,
			10
		};
		bullet12[]=
		{
			"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Grass_04",
			0.2818383,
			1,
			10
		};
		soundBullet[]=
		{
			"bullet1",
			0.079999998,
			"bullet2",
			0.083999999,
			"bullet3",
			0.083999999,
			"bullet4",
			0.083999999,
			"bullet5",
			0.093000002,
			"bullet6",
			0.093000002,
			"bullet7",
			0.074000001,
			"bullet8",
			0.074000001,
			"bullet9",
			0.083999999,
			"bullet10",
			0.085000001,
			"bullet11",
			0.082999997,
			"bullet12",
			0.082999997
		};
		class GunParticles
		{
		};
		scope=1;
		displayName="Sabre Cannons";
		magazines[]=
		{
			"885th_100rd_Saber_Mag"
		};
        magazineReloadTime=3;
		modes[]=
		{
			"manual",
			"close",
			"short",
			"medium",
			"far"
		};
		canLock=0;
		ballisticsComputer="2 + 16";
		FCSMaxLeadSpeed=0;
		FCSZeroingDelay=1;
		maxZeroing=1500;
		aiDispersionCoefY=3;
		aiDispersionCoefX=3;
		ace_overpressure_angle=90;
		ace_overpressure_range=10;
		ace_overpressure_damage=0.85000002;
		displayNameShort="HEAT";
		class manual: MGun
		{
			displayName="$STR_A3_LMG_RCWS0";
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_saber30_Shot_SoundSet"
				};
			};
			soundContinuous=0;
			soundBurst=0;
			reloadTime=0.5;
			dispersion=0.0016;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
		class close: manual
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=8;
			burstRangeMax=16;
			aiRateOfFire=0.5;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=50;
			minRange=0;
			minRangeProbab=0.80000001;
			midRange=20;
			midRangeProbab=0.69999999;
			maxRange=50;
			maxRangeProbab=0.2;
		};
		class short: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=6;
			burstRangeMax=12;
			aiRateOfFire=1;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=150;
			minRange=20;
			minRangeProbab=0.69999999;
			midRange=150;
			midRangeProbab=0.69999999;
			maxRange=300;
			maxRangeProbab=0.2;
		};
		class medium: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=3;
			burstRangeMax=12;
			aiRateOfFire=2;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=250;
			minRange=150;
			minRangeProbab=0.69999999;
			midRange=600;
			midRangeProbab=0.64999998;
			maxRange=800;
			maxRangeProbab=0.1;
		};
		class far: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=3;
			burstRangeMax=8;
			aiRateOfFire=4;
			aiRateOfFireDispersion=4;
			aiRateOfFireDistance=600;
			minRange=600;
			minRangeProbab=0.64999998;
			midRange=800;
			midRangeProbab=0.40000001;
			maxRange=1200;
			maxRangeProbab=0.1;
		};
	};
    class 885th_ATRT_Launcher: GMG_20mm
    {
		displayName="[885th]ATRT HE GL";
		Magazines[]=
		{
			"885th_6rd_ATRT_HE_Launcher"
		};
		magazineReloadTime=4;
        modes[]=
        {
            "manual";
            "close",
            "short",
            "medium",
            "far"
        };
        class manual: GMG_20mm
        {
            displayName = "Semi";
            reloadTime = 0.3;
            sounds[] = {"StandardSound"};
        };
        class StandardSound
		{
			"StandardSound"
		};
		class BaseSoundModeType;
		class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"885_Sounds\885th_UGL_Sound.ogg",
					3.1622777,
					1,
					400
				};
				soundBegin[]=
				{
					"begin1",
					0.1
				};
			};
		};
    };
    class 885th_Saber_AP_Turret: CannonCore
    {
        scope = 2;
        displayName = "[885th]Saber Battle Tank MG";
        magazines[]=
        {
            "885th_500rd_Saber_APMG_Mag"
        };
        ballisticsComputer = 1;      
        canLock = 2;                 
        weaponLockSystem = "2 + 4";
        modes[] = {"FullAuto", "Close"};

        class FullAuto: CannonCore {
            displayName = "Rapid Pulse";
            reloadTime = 0.08;       
            dispersion = 0.0015;
            sounds[] = {"StandardSound"};
            class StandardSound {
                begin1[] = {"A3\Sounds_F\weapons\Cannons\cannon_20mm", 1.8, 1.1, 1500};
                soundBegin[] = {"begin1", 1};
            };
        };
        class Close: FullAuto {
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            showToPlayer = 0;
        };
    };
    class 885th_Saber_Laser_Turret: CannonCore {
    scope = 2;
    displayName = "[885th]Saber Battle Tank Laser";
    magazines[] =
    {
        "885th_500rd_Saber_APMG_Mag"
    };
    ballisticsComputer = 1;      
    canLock = 2;                 
    weaponLockSystem = "2 + 4";
    modes[] = 
    {
        "FullAuto", 
        "Close"
    };
    class FullAuto: CannonCore {
        displayName = "Rapid Pulse";
        reloadTime = 0.1;        
        dispersion = 0.0012;
        sounds[] = {"StandardSound"};
        class StandardSound 
        {
            begin1[] = {"A3\Sounds_F\weapons\Cannons\cannon_20mm", 1.8, 1.5, 1500};
            soundBegin[] = {"begin1", 1};
        };
    };
    class Close: FullAuto 
    {
        aiRateOfFire = 0.2;
        aiRateOfFireDistance = 100;
        showToPlayer = 0;
    };
    class 885th_Saber_HE_Rocketpods: RocketPods
    {
		class gunClouds
		{
		};
		displayName="";
		magazines[]=
		{
			"885th_20rd_Saber_Rocket_Mag"
		};
		sounds[]=
		{
			"StandardSound"
		};
		class BaseSoundModeType;
		class StandardSound: BaseSoundModeType
		{
			soundSetShot[]=
			{
				"3AS_missle_SoundSet"
			};
		};
		modes[]=
		{
			"Close",
			"Medium",
			"Far",
			"Full"
		};
		class GunParticles
		{
			class FirstEffect
			{
				effectName="";
				positionName="efecto_2_pos";
				directionName="efecto_2_dir";
			};
		};
	};
};

    



