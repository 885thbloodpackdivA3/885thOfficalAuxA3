class CfgPatches
{
	class 885th_Weapons
	{
		author = "885th Bloodpack Division + Indecisive Armoury Team";
		name = "885th REP Weapons";
		requiredAddons[] = {"A3_data_F", "A3_anims_F", "A3_weapons_F", "A3_characters_F", "A3_Characters_F_Proxies"};
		units[] = {};
		weapons[] = {
			"885th_A180", 
			"885th_Burn", 
			"885th_DC15A",
			"885th_DC15BR",
			"885th_DC15AMKII_F",
			"885th_DC15AMKII_GL",
			"885th_DC15A_LE",
			"885th_DC15C", 
			"885th_DC15LMKII_F",
			"885th_DCP90",
			"885th_DC15LE",
			"885th_DC15LEMKII",
			"885th_DC15LEMKII_HE",
			"885th_DW32S",
			"885th_DC15S",
			"885th_DC15SE",
			"885th_DC15SE_GL",
			"885th_DC15SMKII_F",
			"885th_DC15SMKII_GL",
			"885th_DC15_Vintage", 
			"885th_DC17",
			"885th_DC17A",
			"885th_DC21", 
			"885th_DC15HR",
			"885th_DC19",
			"885th_DC19FS",
			"885th_DX23_F",
			"885th_DC23",
			"885th_M41",
			"885th_T15LIR",
			"885th_E5", 
			"885th_E5C", 
			"885th_E5S", 
			"885th_FA11", 
			"885th_Galaar15", 
			"885th_Galaar90", 
			"885th_S5Security", 
			"885th_Stun_pistol", 
			"885th_Stun_rifle", 
			"885th_SPAK15", 
			"885th_T15",
			"885th_WestarM5_F",
			"885th_WestarM5_GL",
			"885th_WestarM5MKII_F",
			"885th_Westar35", 
			"885th_DC17M",
			"885th_DC15CMK2",
			"885th_Valken38XMKII",
			"885th_Valken38A_F",
			"885th_T15LIR",
			"885th_DC15XS",
			"885th_Command_DC15AUGL",
			"885th_DX36C",
			"885TH_DX36C_HE",
			"885th_Z6",
			"885th_Z6Para_F",
			"885th_Z8_Experimental_F",
			"885th_EPL2",
			"885th_MPL_F",
			"885th_WristBlaster",
			"885th_773_BR",
			"885th_773_Firepuncher",
			"885th_773_Firepuncher_MKII",
			"885th_773_FireSpitter",
			"885th_773_FireSpitter_MKII"
		};
		magazines[] = {
			"885th_dc_cell_blue",
			"885th_dc_cell_blue_pistol",
			"885th_dc_cell_blue_pistol_extended",
			"885th_dc_cell_green",
			"885th_dc_cell_blue_low",
			"885th_dc_cell_blue_high",
			"885th_dc_cell_blue_amp",
			"885th_dc_cell_blue_over",
			"885th_dc_cell_blue_apex",
			"885th_battery_low_blue",
			"885th_battery_high_blue",
			"885th_battery_amp_blue",
			"885th_battery_ampHR_blue",
			"885th_battery_ampAR_blue",
			"885th_battery_ampm41_green",
			"885th_coil_blue",
			"885th_coil_blue_high",
			"885th_e_cell_red",
			"885th_e_cell_red_pistol",
			"885th_e_battery_red_high",
			"885th_e_cell_red_amp",
			"885th_mando_cell_yellow",
			"885th_mando_cell_yellow_pistol",
			"885th_mando_cell_yellow_high",
			"885_dc_cell_AP",
			"885_dc_cell_sniper",
			"885th_RC_AAD",
			"885th_DX36C_battery_yellow_high",
			"885th_DX36C_he_battery_yellow",
			"885th_mando_cell_yellow_amp",
			"885th_mando_battery_yellow_high",
			"885th_cell_green_pistol",
			"885th_cell_green_high",
			"885th_DW32S_cell",
			"885th_MPL_3rnd_HE_Grenade",
			"885th_MPL_3rnd_Cluster_Grenade",
			"885th_MPL_3rnd_AP_Micro_Rocket",
			"885th_MPL_3Rnd_Smoke_White_shell",
			"885th_MPL_3Rnd_Smoke_Red_shell",
			"885th_MPL_3Rnd_Smoke_Green_shell",
			"885th_MPL_3Rnd_Smoke_Yellow_shell",
			"885th_MPL_3Rnd_Smoke_Purple_shell",
			"885th_MPL_3Rnd_Smoke_Blue_shell",
			"885th_MPL_3Rnd_Smoke_Orange_shell",
			"IDA_Stun_cell"
		};
	};
};
class CfgRecoils
{
	class recoil_default;
	class 885_recoil_DC15A : recoil_default
	{
		muzzleOuter[] = {0, 0.6, 0.2, 0.2};
		kickBack[] = {0.04, 0.05};
		temporary = 0.0025;
	};
	class 885_recoil_DC15S : recoil_default
	{
		muzzleOuter[] = {0, 0.3, 0.3, 0.3};
		kickBack[] = {0.02, 0.03};
		temporary = 0.0095;
	};
	class 885_recoil_DC15X : recoil_default
	{
		muzzleOuter[] = {0, 3, 0.2, 0.2};
		kickBack[] = {0.06, 0.06};
		permanent = 0;
		temporary = 0.005;
	};
	class 885_recoil_DC17 : recoil_default
	{
		muzzleOuter[] = {0, 0.5, 0.2, 0.075};
		kickBack[] = {0.02, 0.035};
		permanent = 0;
		temporary = 0.06;
	};
	class 885_recoil_DC17M : recoil_default
	{
		muzzleOuter[] = {0, 0.62, 0.3, 0.3};
		kickBack[] = {0.03, 0.04};
		temporary = 0.005;
	};
	class 885_recoil_DC23 : recoil_default
	{
		muzzleOuter[] = {0, 6, 0.8, 0.4};
		kickBack[] = {0.04, 0.06};
		temporary = 0.008;
	};
	class 885_recoil_T15 : recoil_default
	{
		muzzleOuter[] = {0, 2, 0.8, 0.8};
		kickBack[] = {0.01, 0.12};
		temporary = 0.03;
	};
	class 885_recoil_DLT15 : recoil_default
	{
		muzzleOuter[] = {0, 0.35, 0.6, 0.6};
		kickBack[] = {0.03, 0.04};
		temporary = 0.006;
	};
	class 885_recoil_Z6 : recoil_default
	{
		muzzleOuter[] = {0, 0.05, 0.060000002, 0.060000002};
		kickBack[] = {0.06, 0.09};
		temporary = 0.006;
	};
};
class CfgCloudlets
{
	class ExploAmmoSmoke;
	class flamesExplosion: ExploAmmoSmoke
	{
		interval="0.015";
		circleRadius=0.1;
		circleVelocity[]={0,0,0};
		particleShape="\a3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth=16;
		particleFSIndex=10;
		particleFSFrameCount=32;
		particleFSLoop=1;
		angleVar=1;
		animationName="";
		particleType="Billboard";
		timerPeriod=3;
		lifeTime=3;
		moveVelocity[]={0,0.050000001,0};
		rotationVelocity=0;
		weight=0.075000003;
		volume=0.050000001;
		rubbing=0.050000001;
		size[]={0.5,0.5,0.5,0.5};
		sizeCoef=2.5;
		color[]=
		{
			{0.69999999,1,0.60000002,0.60000002},
			{0.69999999,1,0.60000002,0.40000001},
			{0.69999999,1,0.60000002,0.22},
			{0.69999999,1,0.60000002,0.1},
			{0.69999999,1,0.60000002,0}
		};
		colorCoef[]={0.69999999,1,0.60000002,1};
		animationSpeed[]={1.7,0.60000002,0.40000001,0.30000001,0.30000001};
		randomDirectionPeriod=0.2;
		randomDirectionIntensity=0.050000001;
		onTimerScript="";
		lifeTimeVar=1.7;
		positionVar[]=
		{
			"1 + 1.1 * intensity",
			0.30000001,
			"1 + 1.1 * intensity"
		};
		moveVelocityVar[]={0.1,0.1,0.1};
		rotationVelocityVar=0;
		sizeVar=0.050000001;
		colorVar[]={0.1,0.1,0.1,0};
		randomDirectionPeriodVar=0;
		randomDirectionIntensityVar=0;
		damageTime=0.25;
		constantDistance=1.6;
		damageType="Fire";
	};
};
class Flame_Explosion
{
	class flame_Light
	{
		simulation="light";
		type="FiredLightMed";
		position="destructionEffect1";
		intensity=1;
		interval=1;
		lifeTime=10;
	};
	class Flame_sound
	{
		simulation="sound";
		type="Fire";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=10;
	};
	class flamesExplosion
	{
		simulation="particles";
		type="BigDestructionFire";
		position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=20;
	};
};
class CfgAmmo
{
	class B_762x51_Ball;
	class G_40mm_HE;
	class RocketBase;
	class BulletBase;
	class GrenadeCore;
	class GrenadeHand_stone;
	class GrenadeHand;
	class GrenadeBase;
	class SmokeShell;
	class SmokeLauncherAmmo;
	class FlameRound;
	class FlameRound_sub;
	class R_PG32V_F;
	class M_Titan_AT;
	class 442_nlaw_AT;
	class B_40mm_APFSDS;
	class B_12Gauge_Pellets_Submunition;
	class SatchelCharge_Remote_Ammo;
	class 885th_blasterbolt: BulletBase
	{	
		ACE_damageType="plasma";
		visibleFire=5;
		audibleFire=20;
		visibleFireTime=2;
		dangerRadiusBulletClose=4;
		dangerRadiusHit=-1;
		suppressionRadiusBulletClose=2;
		suppressionRadiusHit=4;
		hit=1;
		indirectHit=0;
		indirectHitRange=0;
		model="3AS\3AS_Weapons\Data\tracer_blue.p3d";
		caliber=1;
		coefGravity=0.34999999;
		cartridge="";
		cost=1;
		timeToLive=10;
		deflecting=0;
		ExplosionEffects="IDA_ImpactEffect";
		craterEffects="";
		explosive=0.1;
		tracerscale=1;
		tracerstarttime=0.0049999999;
		tracerendtime=10;
		airFriction=0;
		muzzleEffect="";
		waterFriction=-0.00095999998;
		waterEffectOffset=0.80000001;
		effectFly="3AS_PlasmaBolt_Blue_Fly";
		effectflare="FlareShell";
		aiAmmoUsageFlags="64 + 128 + 256";
		soundHitBody1[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_1.ogg",
			3,
			1,
			200
		};
		soundHitBody2[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_2.ogg",
			3,
			1,
			200
		};
		soundHitBody3[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_3.ogg",
			3,
			1,
			200
		};
		soundHitBody4[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_4.ogg",
			3,
			1,
			200
		};
		soundHitBody5[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_5.ogg",
			3,
			1,
			200
		};
		soundHitBody6[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_1.ogg",
			3,
			1.5,
			200
		};
		soundHitBody7[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_2.ogg",
			3,
			1.5,
			200
		};
		soundHitBody8[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_3.ogg",
			3,
			1.5,
			200
		};
		soundHitBody9[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_4.ogg",
			3,
			1.5,
			200
		};
		soundHitBody10[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\Body_Impact_5.ogg",
			3,
			1.5,
			200
		};
		hitMan[]=
		{
			"soundHitBody1",
			0.1,
			"soundHitBody2",
			0.1,
			"soundHitBody3",
			0.1,
			"soundHitBody4",
			0.1,
			"soundHitBody5",
			0.1,
			"soundHitBody6",
			0.1,
			"soundHitBody7",
			0.1,
			"soundHitBody8",
			0.1,
			"soundHitBody9",
			0.1,
			"soundHitBody10",
			0.1
		};
		soundDefault1[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_1.ogg",
			2,
			1,
			165
		};
		soundDefault2[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_2.ogg",
			2,
			1,
			165
		};
		soundDefault3[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_3.ogg",
			2,
			1,
			165
		};
		soundDefault4[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_4.ogg",
			2,
			1,
			165
		};
		soundDefault5[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_5.ogg",
			2,
			1,
			165
		};
		soundDefault6[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_6.ogg",
			2,
			1,
			165
		};
		soundDefault7[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_7.ogg",
			2,
			1,
			165
		};
		soundDefault8[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_8.ogg",
			2,
			1,
			165
		};
		soundDefault9[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_9.ogg",
			2,
			1,
			165
		};
		soundDefault10[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_10.ogg",
			2,
			1,
			165
		};
		soundDefault11[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_11.ogg",
			2,
			1,
			165
		};
		soundDefault12[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_12.ogg",
			2,
			1,
			165
		};
		soundDefault13[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_13.ogg",
			2,
			1,
			165
		};
		soundDefault14[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_14.ogg",
			2,
			1,
			165
		};
		soundDefault15[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_15.ogg",
			2,
			1,
			165
		};
		soundDefault16[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_16.ogg",
			2,
			1,
			165
		};
		soundDefault17[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_17.ogg",
			2,
			1,
			165
		};
		soundDefault18[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_18.ogg",
			2,
			1,
			165
		};
		soundDefault19[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_19.ogg",
			2,
			1,
			165
		};
		soundDefault20[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_20.ogg",
			2,
			1,
			165
		};
		soundDefault21[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_21.ogg",
			2,
			1,
			165
		};
		soundDefault22[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_22.ogg",
			2,
			1,
			165
		};
		soundDefault23[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_23.ogg",
			2,
			1,
			165
		};
		soundDefault24[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_24.ogg",
			2,
			1,
			165
		};
		soundDefault25[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_25.ogg",
			2,
			1,
			165
		};
		soundDefault26[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_26.ogg",
			2,
			1,
			165
		};
		soundDefault27[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_27.ogg",
			2,
			1,
			165
		};
		soundDefault28[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_28.ogg",
			2,
			1,
			165
		};
		soundDefault29[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_29.ogg",
			2,
			1,
			165
		};
		soundDefault30[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_30.ogg",
			2,
			1,
			165
		};
		soundDefault31[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_31.ogg",
			2,
			1,
			165
		};
		soundDefault32[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_32.ogg",
			2,
			1,
			165
		};
		soundDefault33[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_33.ogg",
			2,
			1,
			165
		};
		soundDefault34[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_34.ogg",
			2,
			1,
			165
		};
		soundDefault35[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_35.ogg",
			2,
			1,
			165
		};
		soundDefault36[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_36.ogg",
			2,
			1,
			165
		};
		soundDefault37[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Default_Impact_37.ogg",
			2,
			1,
			165
		};
		hitDefault[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
			"soundDefault6",
			0.027000001,
			"soundDefault7",
			0.027000001,
			"soundDefault8",
			0.027000001,
			"soundDefault9",
			0.027000001,
			"soundDefault10",
			0.027000001,
			"soundDefault11",
			0.027000001,
			"soundDefault12",
			0.027000001,
			"soundDefault13",
			0.027000001,
			"soundDefault14",
			0.027000001,
			"soundDefault15",
			0.027000001,
			"soundDefault16",
			0.027000001,
			"soundDefault17",
			0.027000001,
			"soundDefault18",
			0.027000001,
			"soundDefault19",
			0.027000001,
			"soundDefault20",
			0.027000001,
			"soundDefault21",
			0.027000001,
			"soundDefault22",
			0.027000001,
			"soundDefault23",
			0.027000001,
			"soundDefault24",
			0.027000001,
			"soundDefault25",
			0.027000001,
			"soundDefault26",
			0.027000001,
			"soundDefault37",
			0.027000001,
			"soundDefault27",
			0.027000001,
			"soundDefault28",
			0.027000001,
			"soundDefault29",
			0.027000001,
			"soundDefault30",
			0.027000001,
			"soundDefault31",
			0.027000001,
			"soundDefault32",
			0.027000001,
			"soundDefault33",
			0.027000001,
			"soundDefault34",
			0.027000001,
			"soundDefault35",
			0.027000001,
			"soundDefault36",
			0.027000001
		};
		hitFoliage[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
			"soundDefault6",
			0.027000001,
			"soundDefault7",
			0.027000001,
			"soundDefault8",
			0.027000001,
			"soundDefault9",
			0.027000001,
			"soundDefault10",
			0.027000001,
			"soundDefault11",
			0.027000001,
			"soundDefault12",
			0.027000001,
			"soundDefault13",
			0.027000001,
			"soundDefault14",
			0.027000001,
			"soundDefault15",
			0.027000001,
			"soundDefault16",
			0.027000001,
			"soundDefault17",
			0.027000001,
			"soundDefault18",
			0.027000001,
			"soundDefault19",
			0.027000001,
			"soundDefault20",
			0.027000001,
			"soundDefault21",
			0.027000001,
			"soundDefault22",
			0.027000001,
			"soundDefault23",
			0.027000001,
			"soundDefault24",
			0.027000001,
			"soundDefault25",
			0.027000001,
			"soundDefault26",
			0.027000001,
			"soundDefault37",
			0.027000001,
			"soundDefault27",
			0.027000001,
			"soundDefault28",
			0.027000001,
			"soundDefault29",
			0.027000001,
			"soundDefault30",
			0.027000001,
			"soundDefault31",
			0.027000001,
			"soundDefault32",
			0.027000001,
			"soundDefault33",
			0.027000001,
			"soundDefault34",
			0.027000001,
			"soundDefault35",
			0.027000001,
			"soundDefault36",
			0.027000001
		};
		hitPlastic[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
			"soundDefault6",
			0.027000001,
			"soundDefault7",
			0.027000001,
			"soundDefault8",
			0.027000001,
			"soundDefault9",
			0.027000001,
			"soundDefault10",
			0.027000001,
			"soundDefault11",
			0.027000001,
			"soundDefault12",
			0.027000001,
			"soundDefault13",
			0.027000001,
			"soundDefault14",
			0.027000001,
			"soundDefault15",
			0.027000001,
			"soundDefault16",
			0.027000001,
			"soundDefault17",
			0.027000001,
			"soundDefault18",
			0.027000001,
			"soundDefault19",
			0.027000001,
			"soundDefault20",
			0.027000001,
			"soundDefault21",
			0.027000001,
			"soundDefault22",
			0.027000001,
			"soundDefault23",
			0.027000001,
			"soundDefault24",
			0.027000001,
			"soundDefault25",
			0.027000001,
			"soundDefault26",
			0.027000001,
			"soundDefault37",
			0.027000001,
			"soundDefault27",
			0.027000001,
			"soundDefault28",
			0.027000001,
			"soundDefault29",
			0.027000001,
			"soundDefault30",
			0.027000001,
			"soundDefault31",
			0.027000001,
			"soundDefault32",
			0.027000001,
			"soundDefault33",
			0.027000001,
			"soundDefault34",
			0.027000001,
			"soundDefault35",
			0.027000001,
			"soundDefault36",
			0.027000001
		};
		hitRubber[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
			"soundDefault6",
			0.027000001,
			"soundDefault7",
			0.027000001,
			"soundDefault8",
			0.027000001,
			"soundDefault9",
			0.027000001,
			"soundDefault10",
			0.027000001,
			"soundDefault11",
			0.027000001,
			"soundDefault12",
			0.027000001,
			"soundDefault13",
			0.027000001,
			"soundDefault14",
			0.027000001,
			"soundDefault15",
			0.027000001,
			"soundDefault16",
			0.027000001,
			"soundDefault17",
			0.027000001,
			"soundDefault18",
			0.027000001,
			"soundDefault19",
			0.027000001,
			"soundDefault20",
			0.027000001,
			"soundDefault21",
			0.027000001,
			"soundDefault22",
			0.027000001,
			"soundDefault23",
			0.027000001,
			"soundDefault24",
			0.027000001,
			"soundDefault25",
			0.027000001,
			"soundDefault26",
			0.027000001,
			"soundDefault37",
			0.027000001,
			"soundDefault27",
			0.027000001,
			"soundDefault28",
			0.027000001,
			"soundDefault29",
			0.027000001,
			"soundDefault30",
			0.027000001,
			"soundDefault31",
			0.027000001,
			"soundDefault32",
			0.027000001,
			"soundDefault33",
			0.027000001,
			"soundDefault34",
			0.027000001,
			"soundDefault35",
			0.027000001,
			"soundDefault36",
			0.027000001
		};
		hitTyre[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
			"soundDefault6",
			0.027000001,
			"soundDefault7",
			0.027000001,
			"soundDefault8",
			0.027000001,
			"soundDefault9",
			0.027000001,
			"soundDefault10",
			0.027000001,
			"soundDefault11",
			0.027000001,
			"soundDefault12",
			0.027000001,
			"soundDefault13",
			0.027000001,
			"soundDefault14",
			0.027000001,
			"soundDefault15",
			0.027000001,
			"soundDefault16",
			0.027000001,
			"soundDefault17",
			0.027000001,
			"soundDefault18",
			0.027000001,
			"soundDefault19",
			0.027000001,
			"soundDefault20",
			0.027000001,
			"soundDefault21",
			0.027000001,
			"soundDefault22",
			0.027000001,
			"soundDefault23",
			0.027000001,
			"soundDefault24",
			0.027000001,
			"soundDefault25",
			0.027000001,
			"soundDefault26",
			0.027000001,
			"soundDefault37",
			0.027000001,
			"soundDefault27",
			0.027000001,
			"soundDefault28",
			0.027000001,
			"soundDefault29",
			0.027000001,
			"soundDefault30",
			0.027000001,
			"soundDefault31",
			0.027000001,
			"soundDefault32",
			0.027000001,
			"soundDefault33",
			0.027000001,
			"soundDefault34",
			0.027000001,
			"soundDefault35",
			0.027000001,
			"soundDefault36",
			0.027000001
		};
		hitWood[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
			"soundDefault6",
			0.027000001,
			"soundDefault7",
			0.027000001,
			"soundDefault8",
			0.027000001,
			"soundDefault9",
			0.027000001,
			"soundDefault10",
			0.027000001,
			"soundDefault11",
			0.027000001,
			"soundDefault12",
			0.027000001,
			"soundDefault13",
			0.027000001,
			"soundDefault14",
			0.027000001,
			"soundDefault15",
			0.027000001,
			"soundDefault16",
			0.027000001,
			"soundDefault17",
			0.027000001,
			"soundDefault18",
			0.027000001,
			"soundDefault19",
			0.027000001,
			"soundDefault20",
			0.027000001,
			"soundDefault21",
			0.027000001,
			"soundDefault22",
			0.027000001,
			"soundDefault23",
			0.027000001,
			"soundDefault24",
			0.027000001,
			"soundDefault25",
			0.027000001,
			"soundDefault26",
			0.027000001,
			"soundDefault37",
			0.027000001,
			"soundDefault27",
			0.027000001,
			"soundDefault28",
			0.027000001,
			"soundDefault29",
			0.027000001,
			"soundDefault30",
			0.027000001,
			"soundDefault31",
			0.027000001,
			"soundDefault32",
			0.027000001,
			"soundDefault33",
			0.027000001,
			"soundDefault34",
			0.027000001,
			"soundDefault35",
			0.027000001,
			"soundDefault36",
			0.027000001
		};
		hitBuilding[]=
		{
			"soundDefault1",
			0.027000001,
			"soundDefault2",
			0.027000001,
			"soundDefault3",
			0.027000001,
			"soundDefault4",
			0.027000001,
			"soundDefault5",
			0.027000001,
			"soundDefault6",
			0.027000001,
			"soundDefault7",
			0.027000001,
			"soundDefault8",
			0.027000001,
			"soundDefault9",
			0.027000001,
			"soundDefault10",
			0.027000001,
			"soundDefault11",
			0.027000001,
			"soundDefault12",
			0.027000001,
			"soundDefault13",
			0.027000001,
			"soundDefault14",
			0.027000001,
			"soundDefault15",
			0.027000001,
			"soundDefault16",
			0.027000001,
			"soundDefault17",
			0.027000001,
			"soundDefault18",
			0.027000001,
			"soundDefault19",
			0.027000001,
			"soundDefault20",
			0.027000001,
			"soundDefault21",
			0.027000001,
			"soundDefault22",
			0.027000001,
			"soundDefault23",
			0.027000001,
			"soundDefault24",
			0.027000001,
			"soundDefault25",
			0.027000001,
			"soundDefault26",
			0.027000001,
			"soundDefault37",
			0.027000001,
			"soundDefault27",
			0.027000001,
			"soundDefault28",
			0.027000001,
			"soundDefault29",
			0.027000001,
			"soundDefault30",
			0.027000001,
			"soundDefault31",
			0.027000001,
			"soundDefault32",
			0.027000001,
			"soundDefault33",
			0.027000001,
			"soundDefault34",
			0.027000001,
			"soundDefault35",
			0.027000001,
			"soundDefault36",
			0.027000001
		};
		soundHit1[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_1.ogg",
			2,
			1,
			165
		};
		soundHit2[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_2.ogg",
			2,
			1,
			165
		};
		soundHit3[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_3.ogg",
			2,
			1,
			165
		};
		soundHit4[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_4.ogg",
			2,
			1,
			165
		};
		soundHit5[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_5.ogg",
			2,
			1,
			165
		};
		soundHit6[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_6.ogg",
			2,
			1,
			165
		};
		soundHit7[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_7.ogg",
			2,
			1,
			165
		};
		soundHit8[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_8.ogg",
			2,
			1,
			165
		};
		soundHit9[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_9.ogg",
			2,
			1,
			165
		};
		soundHit10[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_10.ogg",
			2,
			1,
			165
		};
		soundHit11[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Dirt_Impact_11.ogg",
			2,
			1,
			165
		};
		hitGround[]=
		{
			"soundHit1",
			0.090899996,
			"soundHit2",
			0.090899996,
			"soundHit3",
			0.090899996,
			"soundHit4",
			0.090899996,
			"soundHit5",
			0.090899996,
			"soundHit6",
			0.090899996,
			"soundHit7",
			0.090899996,
			"soundHit8",
			0.090899996,
			"soundHit9",
			0.090899996,
			"soundHit10",
			0.090899996,
			"soundHit11",
			0.090899996
		};
		hitGroundHard[]=
		{
			"soundHit1",
			0.090899996,
			"soundHit2",
			0.090899996,
			"soundHit3",
			0.090899996,
			"soundHit4",
			0.090899996,
			"soundHit5",
			0.090899996,
			"soundHit6",
			0.090899996,
			"soundHit7",
			0.090899996,
			"soundHit8",
			0.090899996,
			"soundHit9",
			0.090899996,
			"soundHit10",
			0.090899996,
			"soundHit11",
			0.090899996
		};
		hitGroundSoft[]=
		{
			"soundHit1",
			0.090899996,
			"soundHit2",
			0.090899996,
			"soundHit3",
			0.090899996,
			"soundHit4",
			0.090899996,
			"soundHit5",
			0.090899996,
			"soundHit6",
			0.090899996,
			"soundHit7",
			0.090899996,
			"soundHit8",
			0.090899996,
			"soundHit9",
			0.090899996,
			"soundHit10",
			0.090899996,
			"soundHit11",
			0.090899996
		};
		hitConcrete[]=
		{
			"soundHit1",
			0.090899996,
			"soundHit2",
			0.090899996,
			"soundHit3",
			0.090899996,
			"soundHit4",
			0.090899996,
			"soundHit5",
			0.090899996,
			"soundHit6",
			0.090899996,
			"soundHit7",
			0.090899996,
			"soundHit8",
			0.090899996,
			"soundHit9",
			0.090899996,
			"soundHit10",
			0.090899996,
			"soundHit11",
			0.090899996
		};
		soundMetal1[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_1.ogg",
			2,
			1,
			165
		};
		soundMetal2[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_2.ogg",
			2,
			1,
			165
		};
		soundMetal3[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_3.ogg",
			2,
			1,
			165
		};
		soundMetal4[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_4.ogg",
			2,
			1,
			165
		};
		soundMetal5[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_5.ogg",
			2,
			1,
			165
		};
		soundMetal6[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_6.ogg",
			2,
			1,
			165
		};
		soundMetal7[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_7.ogg",
			2,
			1,
			165
		};
		soundMetal8[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_8.ogg",
			2,
			1,
			165
		};
		soundMetal9[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_9.ogg",
			2,
			1,
			165
		};
		soundMetal10[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_10.ogg",
			2,
			1,
			165
		};
		soundMetal11[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_11.ogg",
			2,
			1,
			165
		};
		soundMetal12[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_12.ogg",
			2,
			1,
			165
		};
		soundMetal13[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_13.ogg",
			2,
			1,
			165
		};
		soundMetal14[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_14.ogg",
			2,
			1,
			165
		};
		soundMetal15[]=
		{
			"\3AS\3AS_Weapons\Data\Impacts\3AS_Metal_Impact_15.ogg",
			2,
			1,
			165
		};
		hitMetal[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
			"soundMetal6",
			0.066600002,
			"soundMetal7",
			0.066600002,
			"soundMetal8",
			0.066600002,
			"soundMetal9",
			0.066600002,
			"soundMetal10",
			0.066600002,
			"soundMetal11",
			0.066600002,
			"soundMetal12",
			0.066600002,
			"soundMetal13",
			0.066600002,
			"soundMetal14",
			0.066600002,
			"soundMetal15",
			0.066600002
		};
		hitIron[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
			"soundMetal6",
			0.066600002,
			"soundMetal7",
			0.066600002,
			"soundMetal8",
			0.066600002,
			"soundMetal9",
			0.066600002,
			"soundMetal10",
			0.066600002,
			"soundMetal11",
			0.066600002,
			"soundMetal12",
			0.066600002,
			"soundMetal13",
			0.066600002,
			"soundMetal14",
			0.066600002,
			"soundMetal15",
			0.066600002
		};
		hitMetalInt[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
			"soundMetal6",
			0.066600002,
			"soundMetal7",
			0.066600002,
			"soundMetal8",
			0.066600002,
			"soundMetal9",
			0.066600002,
			"soundMetal10",
			0.066600002,
			"soundMetal11",
			0.066600002,
			"soundMetal12",
			0.066600002,
			"soundMetal13",
			0.066600002,
			"soundMetal14",
			0.066600002,
			"soundMetal15",
			0.066600002
		};
		hitMetalPlate[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
			"soundMetal6",
			0.066600002,
			"soundMetal7",
			0.066600002,
			"soundMetal8",
			0.066600002,
			"soundMetal9",
			0.066600002,
			"soundMetal10",
			0.066600002,
			"soundMetal11",
			0.066600002,
			"soundMetal12",
			0.066600002,
			"soundMetal13",
			0.066600002,
			"soundMetal14",
			0.066600002,
			"soundMetal15",
			0.066600002
		};
		hitArmor[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
			"soundMetal6",
			0.066600002,
			"soundMetal7",
			0.066600002,
			"soundMetal8",
			0.066600002,
			"soundMetal9",
			0.066600002,
			"soundMetal10",
			0.066600002,
			"soundMetal11",
			0.066600002,
			"soundMetal12",
			0.066600002,
			"soundMetal13",
			0.066600002,
			"soundMetal14",
			0.066600002,
			"soundMetal15",
			0.066600002
		};
		hitArmorInt[]=
		{
			"soundMetal1",
			0.066600002,
			"soundMetal2",
			0.066600002,
			"soundMetal3",
			0.066600002,
			"soundMetal4",
			0.066600002,
			"soundMetal5",
			0.066600002,
			"soundMetal6",
			0.066600002,
			"soundMetal7",
			0.066600002,
			"soundMetal8",
			0.066600002,
			"soundMetal9",
			0.066600002,
			"soundMetal10",
			0.066600002,
			"soundMetal11",
			0.066600002,
			"soundMetal12",
			0.066600002,
			"soundMetal13",
			0.066600002,
			"soundMetal14",
			0.066600002,
			"soundMetal15",
			0.066600002
		};
		soundFly[]=
		{
			"",
			0.25118899,
			0.69999999
		};
		soundSetSonicCrack[]=
		{
			"3AS_Plasma_Flyby_SoundSet"
		};
		class HitEffects
		{
			Hit_Foliage_Green="IDA_ImpactEffect";
			Hit_Foliage_Dead="IDA_ImpactEffect";
			Hit_Foliage_Green_big="IDA_ImpactEffect";
			Hit_Foliage_Palm="IDA_ImpactEffect";
			Hit_Foliage_Pine="IDA_ImpactEffect";
			hitFoliage="IDA_ImpactEffect";
			hitGlass="IDA_ImpactEffect";
			hitGlassArmoRed="IDA_ImpactEffect";
			hitWood="IDA_ImpactEffect";
			hitMetal="IDA_ImpactEffect";
			hitMetalPlate="IDA_ImpactEffect";
			hitBuilding="IDA_ImpactEffect";
			hitPlastic="IDA_ImpactEffect";
			hitRubber="IDA_ImpactEffect";
			hitTyre="IDA_ImpactEffect";
			hitConcrete="IDA_ImpactEffect";
			hitMan="IDA_ImpactEffect";
			hitGroundSoft="IDA_ImpactEffect";
			hitGroundRed="IDA_ImpactEffect";
			hitGroundHard="IDA_ImpactEffect";
			hitWater="IDA_ImpactEffect";
			hitVirtual="IDA_ImpactEffect";
			default_mat="IDA_ImpactEffect";
		};
	};
	class 885th_PlasmaBase_Explosive: GrenadeCore
	{
		visibleFire=5;
		audibleFire=20;
		visibleFireTime=2;
		dangerRadiusBulletClose=4;
		dangerRadiusHit=-1;
		suppressionRadiusBulletClose=2;
		suppressionRadiusHit=4;
		hit=1;
		indirectHit=0;
		indirectHitRange=0;
		model="3AS\3AS_Weapons\Data\tracer_blue.p3d";
		caliber=1;
		coefGravity=0.34999999;
		cartridge="";
		cost=1;
		timeToLive=10;
		deflecting=0;
		explosive=0.1;
		tracerscale=1;
		tracerstarttime=0.0049999999;
		tracerendtime=10;
		airFriction=0;
		waterFriction=-0.00095999998;
		waterEffectOffset=0.80000001;
		effectFly="3AS_PlasmaBolt_Blue_Fly";
		effectflare="FlareShell";
		aiAmmoUsageFlags="64 + 128 + 256";
		soundHit1[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_1",
			3.1622777,
			1,
			1400
		};
		soundHit2[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_2",
			3.1622777,
			1,
			1400
		};
		soundHit3[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_3",
			3.1622777,
			1,
			1400
		};
		soundHit4[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_4",
			3.1622777,
			1,
			1400
		};
		soundHit5[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_5",
			3.1622777,
			1,
			1400
		};
		soundHit6[]=
		{
			"A3\Sounds_F\weapons\Explosion\gr_explosion_6",
			3.1622777,
			1,
			1400
		};
		multiSoundHit[]=
		{
			"soundHit1",
			0.2,
			"soundHit2",
			0.2,
			"soundHit3",
			0.2,
			"soundHit4",
			0.1,
			"soundHit5",
			0.15000001,
			"soundHit6",
			0.15000001
		};
		soundImpactSoft1[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grass_1",
			1.4125376,
			1,
			45
		};
		soundImpactSoft2[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grass_2",
			1.4125376,
			1,
			45
		};
		soundImpactSoft3[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grass_3",
			1.4125376,
			1,
			45
		};
		soundImpactSoft4[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grass_4",
			1.4125376,
			1,
			45
		};
		soundImpactSoft5[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grass_5",
			1.4125376,
			1,
			45
		};
		soundImpactSoft6[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grass_6",
			1.4125376,
			1,
			45
		};
		soundImpactSoft7[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grass_7",
			1.4125376,
			1,
			45
		};
		soundImpactHard1[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_concrete_1",
			1.4125376,
			1,
			65
		};
		soundImpactHard2[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_concrete_2",
			1.4125376,
			1,
			65
		};
		soundImpactHard3[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_concrete_3",
			1.4125376,
			1,
			65
		};
		soundImpactHard4[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_concrete_4",
			1.4125376,
			1,
			65
		};
		soundImpactHard5[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_concrete_5",
			1.4125376,
			1,
			65
		};
		soundImpactHard6[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_concrete_6",
			1.4125376,
			1,
			65
		};
		soundImpactHard7[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_concrete_7",
			1.4125376,
			1,
			65
		};
		soundImpactIron1[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_Metal_1",
			1.2589254,
			1,
			95
		};
		soundImpactIron2[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_Metal_2",
			1.2589254,
			1,
			95
		};
		soundImpactIron3[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_Metal_3",
			1.2589254,
			1,
			95
		};
		soundImpactIron4[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_Metal_4",
			1.2589254,
			1,
			95
		};
		soundImpactIron5[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_Metal_5",
			1.2589254,
			1,
			95
		};
		soundImpactWoodExt1[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_wood_ext_1",
			1.4125376,
			1,
			75
		};
		soundImpactWoodExt2[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_wood_ext_2",
			1.4125376,
			1,
			75
		};
		soundImpactWoodExt3[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_wood_ext_3",
			1.4125376,
			1,
			75
		};
		soundImpactWoodExt4[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_wood_ext_4",
			1.4125376,
			1,
			75
		};
		soundImpactWater1[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_water_1",
			1.4125376,
			1,
			55
		};
		soundImpactWater2[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_water_2",
			1.4125376,
			1,
			55
		};
		soundImpactWater3[]=
		{
			"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_water_3",
			1.4125376,
			1,
			55
		};
		impactGroundSoft[]=
		{
			"soundImpactSoft1",
			0.2,
			"soundImpactSoft2",
			0.2,
			"soundImpactSoft3",
			0.2,
			"soundImpactSoft4",
			0.1,
			"soundImpactSoft5",
			0.1,
			"soundImpactSoft6",
			0.1,
			"soundImpactSoft7",
			0.1
		};
		impactGroundHard[]=
		{
			"soundImpactHard1",
			0.2,
			"soundImpactHard2",
			0.2,
			"soundImpactHard3",
			0.2,
			"soundImpactHard4",
			0.1,
			"soundImpactHard5",
			0.1,
			"soundImpactHard6",
			0.1,
			"soundImpactHard7",
			0.1
		};
		impactIron[]=
		{
			"soundImpactIron1",
			0.2,
			"soundImpactIron2",
			0.2,
			"soundImpactIron3",
			0.2,
			"soundImpactIron4",
			0.2,
			"soundImpactIron5",
			0.2
		};
		impactArmor[]=
		{
			"soundImpactIron1",
			0.2,
			"soundImpactIron2",
			0.2,
			"soundImpactIron3",
			0.2,
			"soundImpactIron4",
			0.2,
			"soundImpactIron5",
			0.2
		};
		impactBuilding[]=
		{
			"soundImpactHard1",
			0.2,
			"soundImpactHard2",
			0.2,
			"soundImpactHard3",
			0.2,
			"soundImpactHard4",
			0.1,
			"soundImpactHard5",
			0.1,
			"soundImpactHard6",
			0.1,
			"soundImpactHard7",
			0.1
		};
		impactFoliage[]=
		{
			"soundImpactSoft1",
			0.2,
			"soundImpactSoft2",
			0.2,
			"soundImpactSoft3",
			0.2,
			"soundImpactSoft4",
			0.1,
			"soundImpactSoft5",
			0.1,
			"soundImpactSoft6",
			0.1,
			"soundImpactSoft7",
			0.1
		};
		impactWood[]=
		{
			"soundImpactWoodExt1",
			0.25,
			"soundImpactWoodExt2",
			0.25,
			"soundImpactWoodExt3",
			0.25,
			"soundImpactWoodExt4",
			0.25
		};
		impactGlass[]=
		{
			"soundImpactHard1",
			0.2,
			"soundImpactHard2",
			0.2,
			"soundImpactHard3",
			0.2,
			"soundImpactHard4",
			0.1,
			"soundImpactHard5",
			0.1,
			"soundImpactHard6",
			0.1,
			"soundImpactHard7",
			0.1
		};
		impactGlassArmored[]=
		{
			"soundImpactHard1",
			0.2,
			"soundImpactHard2",
			0.2,
			"soundImpactHard3",
			0.2,
			"soundImpactHard4",
			0.1,
			"soundImpactHard5",
			0.1,
			"soundImpactHard6",
			0.1,
			"soundImpactHard7",
			0.1
		};
		impactConcrete[]=
		{
			"soundImpactHard1",
			0.2,
			"soundImpactHard2",
			0.2,
			"soundImpactHard3",
			0.2,
			"soundImpactHard4",
			0.1,
			"soundImpactHard5",
			0.1,
			"soundImpactHard6",
			0.1,
			"soundImpactHard7",
			0.1
		};
		impactTyre[]=
		{
			"soundImpactSoft1",
			0.2,
			"soundImpactSoft2",
			0.2,
			"soundImpactSoft3",
			0.2,
			"soundImpactSoft4",
			0.1,
			"soundImpactSoft5",
			0.1,
			"soundImpactSoft6",
			0.1,
			"soundImpactSoft7",
			0.1
		};
		impactRubber[]=
		{
			"soundImpactSoft1",
			0.2,
			"soundImpactSoft2",
			0.2,
			"soundImpactSoft3",
			0.2,
			"soundImpactSoft4",
			0.1,
			"soundImpactSoft5",
			0.1,
			"soundImpactSoft6",
			0.1,
			"soundImpactSoft7",
			0.1
		};
		impactPlastic[]=
		{
			"soundImpactSoft1",
			0.2,
			"soundImpactSoft2",
			0.2,
			"soundImpactSoft3",
			0.2,
			"soundImpactSoft4",
			0.1,
			"soundImpactSoft5",
			0.1,
			"soundImpactSoft6",
			0.1,
			"soundImpactSoft7",
			0.1
		};
		impactDefault[]=
		{
			"soundImpactHard1",
			0.2,
			"soundImpactHard2",
			0.2,
			"soundImpactHard3",
			0.2,
			"soundImpactHard4",
			0.1,
			"soundImpactHard5",
			0.1,
			"soundImpactHard6",
			0.1,
			"soundImpactHard7",
			0.1
		};
		impactMetal[]=
		{
			"soundImpactIron1",
			0.2,
			"soundImpactIron2",
			0.2,
			"soundImpactIron3",
			0.2,
			"soundImpactIron4",
			0.2,
			"soundImpactIron5",
			0.2
		};
		impactMetalplate[]=
		{
			"soundImpactIron1",
			0.2,
			"soundImpactIron2",
			0.2,
			"soundImpactIron3",
			0.2,
			"soundImpactIron4",
			0.2,
			"soundImpactIron5",
			0.2
		};
		impactWater[]=
		{
			"soundImpactWater1",
			0.34999999,
			"soundImpactWater2",
			0.34999999,
			"soundImpactWater3",
			0.30000001
		};
		soundGlass1[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_01",
			1.7782794,
			1,
			100
		};
		soundGlass2[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_02",
			1.7782794,
			1,
			100
		};
		soundGlass3[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_03",
			1.7782794,
			1,
			100
		};
		soundGlass4[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_04",
			1.7782794,
			1,
			100
		};
		soundGlass5[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_05",
			1.7782794,
			1,
			100
		};
		soundGlass6[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_06",
			1.7782794,
			1,
			100
		};
		soundGlass7[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_07",
			1.7782794,
			1,
			100
		};
		soundGlass8[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_08",
			1.7782794,
			1,
			100
		};
		hitGlassBreak[]=
		{
			"soundGlass1",
			0.125,
			"soundGlass2",
			0.125,
			"soundGlass3",
			0.125,
			"soundGlass4",
			0.125,
			"soundGlass5",
			0.125,
			"soundGlass6",
			0.125,
			"soundGlass7",
			0.125,
			"soundGlass8",
			0.125
		};
		soundHitBody3[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\body_03",
			2.2387211,
			1,
			100
		};
		soundHitBody4[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\body_04",
			2.2387211,
			1,
			100
		};
		soundHitBody5[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\body_05",
			2.2387211,
			1,
			100
		};
		soundHitBody6[]=
		{
			"A3\Sounds_F\arsenal\sfx\bullet_hits\body_06",
			2.2387211,
			1,
			100
		};
		impactMan[]=
		{
			"soundHitBody3",
			0.25,
			"soundHitBody4",
			0.25,
			"soundHitBody5",
			0.25,
			"soundHitBody6",
			0.25
		};
		supersonicCrackNear[]=
		{
			"A3\Sounds_F\weapons\Explosion\supersonic_crack_close",
			0.31622776,
			1,
			50
		};
		supersonicCrackFar[]=
		{
			"A3\Sounds_F\weapons\Explosion\supersonic_crack_50meters",
			0.22387211,
			1,
			75
		};
		explosionSoundEffect="DefaultExplosion";
		CraterEffects="GrenadeCrater";
		explosionEffects="GrenadeExplosion";
		muzzleEffect="";
		explosionForceCoef=4;
		shadow=1;
		class HitEffects
		{
			hitWater="ImpactEffectsWater";
		};
	}
	class 885th_thermalshell : B_40mm_APFSDS
	{
		ACE_damageType = "plasmashell";
		ace_vehicle_damage_incendiary = 0.8;
		warheadName = "HEAT";
		aiAmmoUsageFlags = "64 + 128 + 256 + 512";
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
		hit = 400;
		initSpeed = 100;
		indirectHit = 15;
		explosive = 1;
		flaresize = 5;
		indirectHitRange = 2.5;
		caliber = 20;
		coefGravity = 0;
	};
	class 885th_thermalshell_high : 885th_thermalshell
	{
		ACE_damageType = "plasmashell";
		ace_caliber = 120.0;
		ace_vehicle_damage_incendiary = 1.5;
		warheadName = "TandemHEAT";
		aiAmmoUsageFlags = "64 + 128 + 256 + 512";
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
		hit = 700;
		initSpeed = 100;
		indirectHit = 200;
		explosive = 1.5;
		flaresize = 5;
		indirectHitRange = 2.5;
		caliber = 45;
		coefGravity = 0;
	};
	//885th MPL AMMO
	class 885th_MPL_25mm_HE: GrenadeBase
	{
		explosionSoundEffect="DefaultExplosion";
		simulation="shotShell";
		model="Indecisive_Armoury_Ammos\Data\40mm_Grenade\IDA_40mm_Grenade.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		ExplosionEffects="GrenadeExplosion";
		CraterEffects="GrenadeCrater";
		hit=80;
		indirectHit=8;
		indirectHitRange=6;
		warheadName="HE";
		visibleFire=1;
		audibleFire=30;
		visibleFireTime=3;
		dangerRadiusHit=60;
		suppressionRadiusHit=24;
		explosive=1;
		cost=10;
		deflecting=5;
		airFriction=-0.001;
		fuseDistance=15;
		whistleDist=16;
		typicalSpeed=185;
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
	class 885th_MPL_25mm_HEAT: GrenadeBase
	{
		explosionSoundEffect="DefaultExplosion";
		simulation="shotShell";
		model="Indecisive_Armoury_Ammos\Data\40mm_Grenade\IDA_40mm_Grenade.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		hit=98;
		indirectHit=6;
		indirectHitRange=2;
		warheadName="HEAT";
		visibleFire=1;
		audibleFire=30;
		visibleFireTime=3;
		dangerRadiusHit=60;
		suppressionRadiusHit=24;
		explosive=0.40000001;
		cost=10;
		deflecting=5;
		airFriction=-0.001;
		fuseDistance=15;
		whistleDist=20;
		typicalSpeed=185;
		caliber=5;
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
			power=4;
			duration=0.80000001;
			frequency=20;
			distance=75.7771;
		};
		class CamShakeHit
		{
			power=25;
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
	class 885th_MPL_25mm_Cluster_Deploy: G_40mm_HE
	{
		author="885th";
		hit=15;
		indirectHit=4;
		indirectHitRange=1.75;
		explosive=1;
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Blue_Fly";
		lightcolor[]={0.5,0.25,0.25};
		flaresize=5;
		tracerscale=0.80000001;
		tracerstarttime=0.050000001;
		tracerendtime=120;
		brightness=1000;
		airFriction=-0.001;
		typicalSpeed=185;
		coefgravity=1;
		CraterEffects="GrenadeCrater";
		dangerRadiusHit=20;
		explosionEffects="";
		minDamageForCamShakeHit=0.25;
		explosionForceCoef=1.5;
		explosionTime=0;
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
		soundHit1[]=
		{
			"A3\Sounds_F\arsenal\explosives\grenades\Explosion_mini_grenade_01",
			3.1622801,
			1,
			1300
		};
		soundHit2[]=
		{
			"A3\Sounds_F\arsenal\explosives\grenades\Explosion_mini_grenade_02",
			3.1622801,
			1,
			1300
		};
		soundHit3[]=
		{
			"A3\Sounds_F\arsenal\explosives\grenades\Explosion_mini_grenade_03",
			3.1622801,
			1,
			1300
		};
		soundHit4[]=
		{
			"A3\Sounds_F\arsenal\explosives\grenades\Explosion_mini_grenade_04",
			3.1622801,
			1,
			1300
		};
		SoundSetExplosion[]=
		{
			"MiniGrenade_Exp_SoundSet",
			"MiniGrenade_Tail_SoundSet",
			"Explosion_Debris_SoundSet"
		};
		class CamShakeExplode
		{
			distance=5;
			duration=1.2;
			frequency=20;
			power=8;
		};
		class CamShakeFire
		{
			distance=0;
			duration=0.2;
			frequency=20;
			power=0;
		};
		class CamShakeHit
		{
			distance=1;
			duration=0.40000001;
			frequency=20;
			power=20;
		};
		class CamShakePlayerFire
		{
			distance=1;
			duration=0.1;
			frequency=20;
			power=0;
		};
	};
	class 885th_MPL_25mm_Submunition_Base: B_12Gauge_Pellets_Submunition
	{
		author="885th";
		allowAgainstInfantry=1;
		aiAmmoUsageFlags=64;
		model = "3AS\3AS_Weapons\Data\tracer_blue.p3d";
		effectfly = "3AS_PlasmaBolt_Blue_Fly";
		lightcolor[]={0.25,0.5,0.25};
		flaresize=5;
		tracerscale=0.80000001;
		tracerstarttime=0.050000001;
		tracerendtime=120;
		brightness=1000;
		submunitionAmmo[]=
		{
			"",
			1
		};
		submunitionConeType[]=
		{
			"poissondisc",
			16
		};
		submunitionCount=16;
		submunitionDirectionType="SubmunitionModelDirection";
		thrust=210;
		triggerSpeedCoef[]={0.69,0.85000002};
		airFriction=-0.001;
		typicalSpeed=80;
		coefgravity=1;
	};
	class 885th_MPL_25mm_cluster: 885th_MPL_25mm_Submunition_Base
	{
		submunitionAmmo[]=
		{
			"885th_MPL_25mm_Cluster_Deploy",
			12
		};
		submunitionConeAngle=3;
		submunitionConeType[]=
		{
			"poissondisccenter",
			12
		};
		submunitionCount=12;
		submunitionInitSpeed=77.5;
		submunitionParentSpeedCoef=0;
		aiAmmoUsageFlags="64 + 128";
		allowAgainstInfantry=1;
		triggerSpeedCoef[]={0.99000001,1};
	};
	class 885th_MPL_25mm_AP_Micro_Rocket: 885th_MPL_25mm_HEAT
	{
		hit=900;
		indirectHit=25;
		indirectHitRange=2;
		warheadName="AP";
		airfriction=0;
		coefgravity=0;
		deflecting=0;
		model="\ls\core\addons\data\effects\ls_laser_yellow.p3d";
		effectFly="ls_plasma_yellow";
		triggerOnImpact=1;
		soundFly[]=
		{
			"885_Sounds\MicroRocket.ogg",
			6,
			1.5,
			700
		};
	};
	class 885th_MPL_25mm_Smoke_White: SmokeShell
	{
		model="\A3\weapons_f\Ammo\UGL_slug";
	};
	class 885th_MPL_25mm_Smoke_Red: 885th_MPL_25mm_Smoke_White
	{
		smokeColor[]={0.84380001,0.1383,0.1353,1};
		effectsSmoke="SmokeShellRedEffect";
	};
	class 885th_MPL_25mm_Smoke_Green: 885th_MPL_25mm_Smoke_White
	{
		smokeColor[]={0.21250001,0.62580001,0.48909998,1};
		effectsSmoke="SmokeShellGreenEffect";
	};
	class 885th_MPL_25mm_Smoke_Yellow: 885th_MPL_25mm_Smoke_White
	{
		smokeColor[]={0.98830003,0.86059999,0.071900003,1};
		effectsSmoke="SmokeShellYellowEffect";
	};
	class 885th_MPL_25mm_Smoke_Purple: 885th_MPL_25mm_Smoke_White
	{
		smokeColor[]={0.4341,0.1388,0.41439998,1};
		effectsSmoke="SmokeShellPurpleEffect";
	};
	class 885th_MPL_25mm_Smoke_Blue: 885th_MPL_25mm_Smoke_White
	{
		smokeColor[]={0.1183,0.1867,1,1};
		effectsSmoke="SmokeShellBlueEffect";
	};
	class 885th_MPL_25mm_Smoke_Orange: 885th_MPL_25mm_Smoke_White
	{
		smokeColor[]={0.66970003,0.22750001,0.10053,1};
		effectsSmoke="SmokeShellOrangeEffect";
	};
	// Republic
	class 885th_blasterbolt_blue : 885th_blasterbolt
	{
		hit = 20;
		caliber = 5.7;
		coefGravity = 0;
	};
	class 885th_blasterbolt_bLow : 885th_blasterbolt_blue
	{
		hit = 10;
		caliber = 3.5;
		coefGravity = 0;
	};
	class 885th_blasterbolt_bHigh : 885th_blasterbolt_blue
	{
		hit = 25;
		ACE_caliber = 7.823;
		caliber = 7.62;
		coefGravity = 0;
	};
	class 885th_blasterbolt_bAmp : 885th_blasterbolt_blue
	{
		ACE_muzzlevelocities[] = {335, 620, 1200, 730, 800, 780, 850, 880};
		ACE_barrellengths[] = 	{228, 450, 457, 609, 650, 620, 655, 750};
		hit = 70;
		caliber = 10.0;
		ACE_caliber = 10.0;
		coefGravity = 0;
	};
	class 885th_blasterbolt_bOver : 885th_blasterbolt_blue
	{
		ace_vehicle_damage_incendiary = 1.5;
		warheadName = "AP";
		aiAmmoUsageFlags = "64 + 128 + 512";
		ACE_muzzlevelocities[] = {335, 620, 1200, 730, 820, 800, 840, 853};
		ACE_barrellengths[] = {228, 450, 457, 609, 650, 620, 655, 750};
		hit = 100;
		explosive = 0.1;
		caliber = 25.0;
		ACE_caliber = 20.0;
		coefGravity = 0;
	};
	class 885th_blasterbolt_bApex: 885th_blasterbolt_blue
	{
		warheadName = "AP";
		aiAmmoUsageFlags = "64 + 128 + 512";
		ACE_muzzlevelocities[] = {335, 620, 1200, 730, 820, 800, 840, 853};
		ACE_barrellengths[] = {228, 450, 457, 609, 650, 620, 655, 750};
		hit = 55;
		ACE_caliber = 7.823;
		caliber = 7.62;
		coefGravity = 0;
	};
	class 885th_blasterbolt_DC17MSnip : 885th_blasterbolt_blue
	{
		hit = 75;
		caliber = 10.0;
		ACE_caliber = 10.0;
		coefGravity = 0;
	};
	// Republic Extras
	class 885th_blasterbolt_Amp_m41_green: 885th_blasterbolt
	{
		ace_vehicle_damage_incendiary = 3.5;
		warheadName = "AP";
		hit=80;
		indirectHit=0;
		indirectHitRange=0;
		cartridge="";
		aiAmmoUsageFlags=64;
		dangerRadiusBulletClose=8;
		dangerRadiusHit=12;
		suppressionRadiusBulletClose=6;
		suppressionRadiusHit=8;
		cost=1.2;
		airLock=1;
		typicalSpeed=417;
		caliber=20.0;
		coefGravity = 0;
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		tracerScale=0.82499999;
		airFriction=-0.00019999999;
		effectfly="IDA_BlasterBoltGlow_Green_Fly";
	};
	class 885th_ammo_Grenade_EMP: G_40mm_HE
	{
		JLTS_isEMPAmmo=1;
		ace_frag_enabled=0;
		explosionForceCoef=1;
		hit=0.0099999998;
		indirectHit=0.0099999998;
		indirectHitRange=7;
		author="885th Bloodapack Division";
		effectFly="JLTS_plasma_blue";
		model="\MRC\JLTS\weapons\Core\effects\emp_blue.p3d";
		lightcolor[]={0.25,0.25,0.5};
		airfriction=0;
		coefgravity=0.5;
		explosionEffects="JLTS_fx_exp_EMP";
		deflecting=0;
		fuseDistance=1;
		explosive=0.1;
		aiAmmoUsageFlags=0;
		SoundSetExplosion[]=
		{
			"JLTS_GrenadeEMP_Exp_SoundSet",
			"JLTS_GrenadeEMP_Tail_SoundSet",
			"Explosion_Debris_SoundSet"
		};
	};
	class 885th_Z8_STD: 885th_blasterbolt
	{	
		ace_vehicle_damage_incendiary = 3.5;
		warheadName = "AP";
		allowAgainstInfantry=1;
		explosive=0.1;
		deflecting=0;
		cartridge="";
		timeToLive=40;
		initSpeed=660;
		cost=7;
		brightness=10000;
		muzzleEffect="";
		typicalSpeed=639;
		submunitionInitSpeed=1000;
		submunitionParentSpeedCoef=0;
		submunitionInitialOffset[]={0,0,-0.1};
		coefGravity=0;
		waterFriction=0;
		triggerOnImpact=1;
		deleteParentWhenTriggered=0;
		airFriction=0;
		maxSpeed=10000;
		indirecthit=0.5;
		indirectHitRange=1.2;
		hit=75;
		caliber=15.0;
		tracerScale=2;
		tracerStartTime=0.050000001;
		tracerEndTime=10;
		explosionEffects="IDA_ImpactEffect";
		craterEffects="";
		effectFly="IDA_BlasterBoltGlow_Medium_Blue_Fly";
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
	};
	class 885th_blasterbolt_yellow_DX36: 885th_blasterbolt
	{
		ace_vehicle_damage_incendiary = 1.5;
		warheadName = "AP";
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Yellow_Fly";
		Lightcolor[]={1,1,0};
		hit=45;
		caliber = 7.62;
		coefGravity=0;
		ExplosionEffects="IDA_ImpactEffect";
		cratereffects="ls_plasma_impact";
		explosive=0.30000001;
	};
	class 885th_HE_blasterbolt_yellow_DX36: GrenadeBase
	{
		SoundFly[]=
		{
			"",
			1,
			1,
			50
		};
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
		allowAgainstInfantry=1;
		indirectHit=3;
		hit=100;
		indirectHitRange=2;
		explosive=0.80000001;
		warheadName="HE";
		caliber=25;
		deflecting=0;
		airFriction=0;
		timeToLive=40;
		initSpeed=660;
		cost=7;
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Yellow_Fly";
		tracerScale=2;
		tracerStartTime=0.050000001;
		tracerEndTime=10;
		brightness=10000;
		cartridge="";
		muzzleEffect="";
		typicalSpeed=350;
		submunitionInitSpeed=1000;
		submunitionParentSpeedCoef=0;
		submunitionInitialOffset[]={0,0,-0.1};
		coefGravity=0;
		waterFriction=0;
		triggerOnImpact=1;
		deleteParentWhenTriggered=0;
		explosionEffects="ExploAmmoExplosion";
		CraterEffects = "GrenadeCrater";
		explosionSoundEffect="DefaultExplosion";
	};
	class 885th_HE_blasterbolt_Blue_Z6: GrenadeBase
	{
		SoundFly[]=
		{
			"",
			1,
			1,
			50
		};
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
		allowAgainstInfantry=1;
		indirectHit=4;
		hit=100;
		indirectHitRange=3.4;
		explosive=0.80000001;
		warheadName="HE";
		caliber=25;
		deflecting=0;
		airFriction=0;
		timeToLive=40;
		initSpeed=660;
		cost=7;
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Medium_Blue_Fly";
		tracerScale=2;
		tracerStartTime=0.050000001;
		tracerEndTime=10;
		brightness=10000;
		cartridge="";
		muzzleEffect="";
		typicalSpeed=350;
		submunitionInitSpeed=1000;
		submunitionParentSpeedCoef=0;
		submunitionInitialOffset[]={0,0,-0.1};
		coefGravity=0;
		waterFriction=0;
		triggerOnImpact=1;
		deleteParentWhenTriggered=0;
		explosionEffects="ExploAmmoExplosion";
		CraterEffects = "GrenadeCrater";
		explosionSoundEffect="DefaultExplosion";
	};
	class 885th_HE_blasterbolt_blue_DC15LEMKII: 885th_PlasmaBase_Explosive
	{
		SoundFly[]=
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
		allowAgainstInfantry=1;
		indirectHit=3.5;
		hit=100;
		indirectHitRange=1.5;
		explosive=0.80000001;
		warheadName="AP";
		caliber=15;
		deflecting=0;
		airFriction=0;
		timeToLive=40;
		initSpeed=660;
		cost=7;
		effectfly="3AS_PlasmaBolt_Blue_Fly";
		model="3AS\3AS_Weapons\Data\tracer_blue.p3d";
		tracerScale=2;
		tracerStartTime=0.050000001;
		tracerEndTime=10;
		brightness=10000;
		muzzleEffect="";
		typicalSpeed=350;
		submunitionInitSpeed=1000;
		submunitionParentSpeedCoef=0;
		submunitionInitialOffset[]={0,0,-0.1};
		coefGravity=0;
		waterFriction=0;
		triggerOnImpact=1;
		deleteParentWhenTriggered=0;
		explosionEffects="ExploAmmoExplosion";
		explosionSoundEffect="DefaultExplosion";
	};
	class 885th_FlameRound: BulletBase
	{
		submunitionAmmo="885th_FlameRound_sub";
		submunitionConeType[]=
		{
			"poissondisc",
			4
		};
		submunitionConeAngle=4;
		triggerTime=0.050000001;
		hit=10;
		indirectHit=6.5;
		indirectHitRange=2.5;
		cartridge="";
		cost=2;
		visibleFire=32;
		audibleFire=12;
		visibleFireTime=20;
		airFriction=0.1;
		timetolive=2;
		maxSpeed=25;
		typicalSpeed=0.12;
		coefGravity=0;
		deflecting=0;
		explosive=1;
		fuseDistance=1;
		caliber=0.5;
		tracerScale=0.001;
		tracerStartTime=0.0099999998;
		tracerEndTime=0.1;
		craterEffects="";
		effectFly="SmallFire";
		explosionEffects="Flame_Explosion";
		model="\A3\Weapons_f\Data\bullettracer\tracer_red";
	};
	class 885th_FlameRound_sub: BulletBase
	{
		hit=50;
		indirectHit=5;
		indirectHitRange=1;
		cartridge="";
		cost=2;
		visibleFire=32;
		audibleFire=12;
		visibleFireTime=20;
		airFriction=0;
		timetolive=3.5;
		maxSpeed=25;
		typicalSpeed=0.12;
		coefGravity=0.25;
		deflecting=0;
		explosive=1;
		fuseDistance=1;
		caliber=0.5;
		tracerScale=0.0099999998;
		tracerStartTime=0.0099999998;
		tracerEndTime=0.1;
		craterEffects="";
		effectFly="SmallFire";
		explosionEffects="Flame_Explosion";
	};
	class 885th_Traceless_Subsonic_Blue: 885th_blasterbolt
	{
		airLock=1;
		hit=30;
		indirectHit=0;
		indirectHitRange=0;
		cost=1;
		nvgOnly=1;
		typicalSpeed=361;
		airFriction=0;
		waterFriction=-0.30000001;
		caliber=1.4;
		coefGravity=0.050000001;
		model="\A3\Weapons_f\Data\bullettracer\tracer_red";
		tracerScale=0.69999999;
		visibleFire=3;
		audibleFire=2;
		visibleFireTime=3;
		audibleFireTime=3;
		dangerRadiusBulletClose=8;
		dangerRadiusHit=12;
		suppressionRadiusBulletClose=6;
		suppressionRadiusHit=8;
		effectFly="AmmoClassic";
		aiAmmoUsageFlags=64;
		class CamShakeExplode
		{
			power=2.2360699;
			duration=0.40000001;
			frequency=20;
			distance=6.7082;
		};
		class CamShakeHit
		{
			power=5;
			duration=0.2;
			frequency=20;
			distance=1;
		};
	};
	class 885th_Breaching_Scattershot_blue: 885th_blasterbolt
	{	
		hit=20;
		simulationStep=9.9999997e-005;
		model="\3AS\3AS_Weapons\Data\tracer_blue.p3d";
		effectFly="3AS_PlasmaBolt_blue_Fly";
		submunitionAmmo="885th_blasterbolt_blue";
		submunitionConeType[]=
		{
			"poissondisc",
			6
		};
		submunitionConeAngle=5;
		triggerSpeedCoef[]={0.85000002,1};
		triggerTime=0.001;
	};
	// Economy
	class 885th_blasterbolt_red : 885th_blasterbolt
	{
		model = "\3AS\3AS_Weapons\Data\tracer_red.p3d";
		effectfly = "3AS_PlasmaBolt_Red_Fly";
		hit = 16;
		caliber = 3.8;
		coefGravity = 0;
	};
	class 885th_blasterbolt_rHigh : 885th_blasterbolt_red
	{
		hit = 10;
		caliber = 5.7;
		coefGravity = 0;
	};
	class 885th_blasterbolt_rAmp : 885th_blasterbolt_red
	{
		hit = 30;
		caliber = 7.62;
		coefGravity = 0;
	};
	// Militia
	class 885th_blasterbolt_green : 885th_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Green.p3d";
		effectfly="IDA_BlasterBoltGlow_Green_Fly";
		Lightcolor[]={0,1,0};
		hit = 18;
		caliber = 5.7;
		coefGravity = 0;
	};
	class 885th_blasterbolt_gHigh : 885th_blasterbolt_green
	{
		model = "\3AS\3AS_Weapons\Data\tracer_green.p3d";
		effectfly = "3AS_PlasmaBolt_Green_Fly";
		hit = 24;
		caliber = 5.7;
		coefGravity = 0;
	};
	// Mandolorian
	class 885th_blasterbolt_yellow : 885th_blasterbolt
	{
		model="\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectfly="IDA_BlasterBoltGlow_Yellow_Fly";
		Lightcolor[]={1,1,0};
		hit = 25;
		caliber = 7.62;
		coefGravity = 0;
	};
	class 885th_blasterbolt_yHigh : 885th_blasterbolt_yellow
	{
		hit = 40;
		caliber = 7.62;
		coefGravity = 0;
	};
	class 885th_blasterbolt_yAmp : 885th_blasterbolt_yellow
	{
		ACE_muzzlevelocities[] = {820, 800, 840, 853};
		ACE_barrellengths[] = {650, 620, 655, 750};
		hit = 50;
		caliber = 20.0;
		coefGravity = 0;
	};
	class 885th_blasterbolt_Overcharged_VEHICLE : G_40mm_HE
	{
		model = "\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectFly = "IDA_BlasterBoltGlow_Medium_Yellow_Fly";
		ACE_damageType = "plasmashell";
		hit = 800;
		indirectHit = 150;
		explosive = 1;
		indirectHitRange = 2.5;
		caliber = 2;
	};
};
class CfgMagazines
{
	class 100Rnd_65x39_caseless_mag;
	class 3Rnd_Smoke_Grenade_shell;
	class 1Rnd_HE_Grenade_shell;
	class CA_LauncherMagazine;
	class CA_Magazine;
	class IDA_FuelTank;
	class RPG32_F;
	class Titan_AT;
	class 885th_cell : 100Rnd_65x39_caseless_mag
	{
		author = "885th Bloodpack Division + IDA Dev Team";
		scope = 2;
		modelSpecial = "";
		modelSpecialIsProxy = 0;
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		tracersEvery = 1;
		displayName = "[885th] Standard Energy Cell";
		displayNameShort = "Energy Cell";
		descriptionShort = "50 round capacity, standard blaster bolts.";
		count = 50;
		ammo = "885th_blasterbolt";
		mass = 8;
	};
	// DC Series
	class 885th_dc_cell_blue : 885th_cell
	{
		count = 50;
		displayName = "[885th] Standard Energy Cell";
		displayNameShort = "Std. Cell";
		descriptionShort = "50 round capacity, standard blaster bolts.";
		ammo = "885th_blasterbolt_blue";
		tracersEvery = 1;
		mass = 10;
	};
	class 885th_dc_cell_blue_pistol : 885th_dc_cell_blue
	{
		count = 10;
		displayName = "[885th] Standard Pistol Energy Cell";
		displayNameShort = "Std. Pistol Cell";
		descriptionShort = "10 round capacity, standard blaster bolts.";
		ammo = "885th_blasterbolt_blue";
		tracersEvery = 1;
		mass = 3;
	};
	class 885th_dc_cell_blue_pistol_extended : 885th_dc_cell_blue
	{
		count = 30;
		displayName = "[885th] Standard Pistol Energy Cell Extended";
		displayNameShort = "Std. Pistol Cell";
		descriptionShort = "30 round capacity, standard blaster bolts.";
		ammo = "885th_blasterbolt_blue";
		tracersEvery = 1;
		mass = 3;
	};
	class 885th_dc_cell_green : 885th_cell
	{
		count = 50;
		displayName = "[885th] Militia Energy Cell";
		displayNameShort = "Militia Cell";
		descriptionShort = "50 round capacity, green blaster bolts.";
		ammo = "885th_blasterbolt_green";
		tracersEvery = 1;
		mass = 10;
	};
	class 885th_dc_cell_blue_low : 885th_dc_cell_blue
	{
		count = 100;
		displayName = "[885th] Low-Power Energy Cell";
		displayNameShort = "LP Cell";
		descriptionShort = "100 round capacity, low energy blaster bolts.";
		ammo = "885th_blasterbolt_bLow";
		tracersEvery = 1;
		mass = 10;
	};
	class 885th_dc_cell_blue_high : 885th_dc_cell_blue
	{
		count = 25;
		displayName = "[885th] High-Power Energy Cell";
		displayNameShort = "HP Cell";
		descriptionShort = "25 round capacity, high energy blaster bolts.";
		ammo = "885th_blasterbolt_bHigh";
		tracersEvery = 1;
		initSpeed = 900;
		mass = 10;
	};
	class 885th_dc_cell_blue_amp : 885th_dc_cell_blue
	{
		count = 15;
		displayName = "[885th] Amplified Energy Cell";
		displayNameShort = "Amp Cell";
		descriptionShort = "15 round capacity, Amplified blaster bolts.";
		ammo = "885th_blasterbolt_bAmp";
		tracersEvery = 1;
		initSpeed = 1100;
		mass = 15;
	};
	class 885th_dc_cell_blue_over : 885th_dc_cell_blue
	{
		count = 10;
		displayName = "[885th] Overcharged Energy Cell";
		displayNameShort = "OC Cell";
		descriptionShort = "10 round capacity, overcharged energy blaster bolts.";
		ammo = "885th_blasterbolt_bOver";
		tracersEvery = 1;
		initSpeed = 2000;
		mass = 20;
	};
	// GL Mags
	class 885th_mag_40mm_Base: CA_Magazine
	{
		author="885th";
		displayName="[885th] 40mm 1rnd base Grenade";
		displayNameShort="HE";
		descriptionShort="High-explosive grenade used by various Grenade Launchers";
		ammo="885th_ammo_40mm_HE_Base";
		count=1;
		initspeed=80;
	};
	// MPL Mags
	class 885th_MPL_3rnd_HE_Grenade: 885th_mag_40mm_Base
	{
		scope=2;
		author="885th";
		displayName="[885th] MPL 3Rnd Grenades";
		displayNameShort="HE Grenades";
		descriptionShort="High-explosive grenades used by the MPL Grenade Launcher";
		ammo="885th_MPL_25mm_HE";
		count=3;
		initspeed=80;
		mass=15;
	};
	class 885th_MPL_3rnd_Cluster_Grenade: 885th_mag_40mm_Base
	{
		scope=2;
		author="885th";
		displayName="[885th] MPL 3Rnd HE Cluster Grenades";
		displayNameShort="HE Cluster Grenades";
		descriptionShort="Grenade containing several smaller bomblets equipped with high-explosive warheads , Used by the MPL Grenade Launcher.";
		ammo="885th_MPL_25mm_cluster";
		count=3;
		mass=15;
	};
	class 885th_MPL_3rnd_AP_Micro_Rocket: 885th_mag_40mm_Base
	{
		scope=2;
		author="885th";
		displayName="[885th] MPL 3Rnd AP Micro Rockets";
		displayNameShort="AP Micro Rockets";
		descriptionShort="Armor-piercing Micro Rockets capable of dealing large amounts of damage to armored targets , Used by the MPL Grenade Launcher.";
		ammo="885th_MPL_25mm_AP_Micro_Rocket";
		count=3;
		initspeed=300;
		mass=15;
	};
	class 885th_MPL_3Rnd_Smoke_White_shell: CA_Magazine
	{
		author="885th";
		scope=2;
		type=16;
		displayName="[885th] MPL 3Rnd White Smoke";
		displayNameShort="White Smoke";
		picture="";
		ammo="885th_MPL_25mm_Smoke_White";
		initSpeed=80;
		count=3;
		nameSound="";
		descriptionShort="$STR_A3_CfgMagazines_1Rnd_Smoke_Grenade_shell1";
		mass=9;
		modelSpecial="\a3\Weapons_F\MagazineProxies\mag_40x36_HE_1rnd.p3d";
		modelSpecialIsProxy=1;
		deleteIfEmpty=0;
	};
	class 885th_MPL_3Rnd_Smoke_Red_shell: 885th_MPL_3Rnd_Smoke_White_shell
	{
		displayName="[885th] MPL 3Rnd Red Smoke";
		displayNameShort="Red Smoke";
		picture="";
		ammo="885th_MPL_25mm_Smoke_Red";
		author="885th";
	};
	class 885th_MPL_3Rnd_Smoke_Green_shell: 885th_MPL_3Rnd_Smoke_White_shell
	{
		displayName="[885th] MPL 3Rnd Green Smoke";
		displayNameShort="Green Smoke";
		picture="";
		ammo="885th_MPL_25mm_Smoke_Green";
		author="885th";
	};
	class 885th_MPL_3Rnd_Smoke_Yellow_shell: 885th_MPL_3Rnd_Smoke_White_shell
	{
		displayName="[885th] MPL 3Rnd Yellow Smoke";
		displayNameShort="Yellow Smoke";
		picture="";
		ammo="885th_MPL_25mm_Smoke_Yellow";
		author="885th";
	};
	class 885th_MPL_3Rnd_Smoke_Purple_shell: 885th_MPL_3Rnd_Smoke_White_shell
	{
		displayName="[885th] MPL 3Rnd Purple Smoke";
		displayNameShort="Purple Smoke";
		picture="";
		ammo="885th_MPL_25mm_Smoke_Purple";
		author="885th";
	};
	class 885th_MPL_3Rnd_Smoke_Blue_shell: 885th_MPL_3Rnd_Smoke_White_shell
	{
		displayName="[885th] MPL 3Rnd Blue Smoke";
		displayNameShort="Blue Smoke";
		picture="";
		ammo="885th_MPL_25mm_Smoke_Blue";
		author="885th";
	};
	class 885th_MPL_3Rnd_Smoke_Orange_shell: 885th_MPL_3Rnd_Smoke_White_shell
	{
		displayName="[885th] MPL 3Rnd Orange Smoke";
		displayNameShort="Orange Smoke";
		picture="";
		ammo="885th_MPL_25mm_Smoke_Orange";
		author="885th";
	};
	// Republic Extras
	class 885th_battery_low_blue : 885th_cell
	{
		count = 500;
		displayName = "[885th] Low Power Blaster Battery";
		displayNameShort = "LP Battery";
		descriptionShort = "500 round capacity, Standard power blaster bolts.";
		model = "\MRC\JLTS\weapons\z6\z6_mag.p3d";
		picture = "\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		ammo = "885th_blasterbolt_blue";
		tracersEvery = 1;
		mass = 25;
	};
	class 885th_battery_high_blue : 885th_cell
	{
		count = 300;
		displayName = "[885th] High Power Blaster Battery";
		displayNameShort = "HP Battery";
		descriptionShort = "300 round capacity, high power blaster bolts.";
		model = "\MRC\JLTS\weapons\z6\z6_mag.p3d";
		picture = "\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		ammo = "885th_blasterbolt_bHigh";
		tracersEvery = 1;
		mass = 30;
	};
	class 885th_battery_amp_blue : 885th_cell
	{
		count = 250;
		displayName = "[885th] Amplified Blaster Battery";
		displayNameShort = "Amp. Battery";
		descriptionShort = "250 round capacity, amplified blaster bolts.";
		model = "\MRC\JLTS\weapons\z6\z6_mag.p3d";
		picture = "\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		ammo = "885th_blasterbolt_bAmp";
		tracersEvery = 1;
		mass = 35;
	};
	class 885th_battery_ampHR_blue : 885th_cell
	{
		count = 150;
		displayName = "[885th] Heavy Amplified Blaster Battery";
		displayNameShort = "Hvy Amp. Battery";
		descriptionShort = "150 round capacity, amplified blaster bolts.";
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		ammo = "885th_blasterbolt_bAmp";
		tracersEvery = 1;
		mass = 40;
	};
	class 885th_battery_ampAR_blue : 885th_cell
	{
		count = 25;
		displayName = "[885th] Heavy Amplified Blaster Battery Short";
		displayNameShort = "Hvy Amp. Battery";
		descriptionShort = "25 round capacity, amplified blaster bolts.";
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		ammo = "885th_blasterbolt_bAmp";
		initSpeed=885;
		tracersEvery = 1;
		mass = 15;
	};
	class 885th_dc_cell_blue_apex: 885th_cell
	{
		count = 60;
		displayName = "[885th] Heavy Apex Blaster Cell";
		displayNameShort = "Apex Blaster Cell";
		descriptionShort = "60 round capacity, modified blaster bolts.";
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		ammo = "885th_blasterbolt_bApex";
		tracersEvery = 1;
		mass = 10;
	};
	class 885th_dc_cell_blue_Omega: 885th_dc_cell_blue_apex
	{
		count = 5;
		displayName = "[885th] Omega AP Blaster Cell";
		displayNameShort = "Omega Blaster Cell";
		descriptionShort = "5 round capacity, Apex Sniper Bolt.";
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		initSpeed=3000;
		ammo = "885th_blasterbolt_bApex";
		tracersEvery = 1;
		mass = 15;
	};
	class 885th_battery_ampm41_green : 885th_cell
	{
		count = 200;
		displayName = "[885th] M41 Heavy Amplified Blaster Battery";
		displayNameShort = "M41 Api Hvy Amp. Battery";
		descriptionShort = "200 round capacity, Api Heavy amplified blaster bolts.";
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		initSpeed=550;
		ammo = "885th_blasterbolt_Amp_m41_green";
		tracersEvery = 1;
		mass = 50;
	};
	class 885th_Z8_Experimental_200rnd_battery_blue: 885th_cell
	{
		scope=2;
		displayName="[885th] Z8 High Powered Battery";
		ammo="885th_Z8_STD";
		tracersEvery=1;
		type=16;
		count=200;
		lastRoundsTracer=200;
		descriptionShort="Z8 Experimental Blaster Cannon High Powered Battery";
		mass=40;
		initSpeed=1800;
	};
	class 885th_Z8_Experimental_50rnd_HE_battery_blue: 885th_cell
	{
		scope=2;
		displayName="[885th] Z8 High Powered HE Battery";
		ammo="885th_HE_blasterbolt_blue_DC15LEMKII";
		tracersEvery=1;
		count=50;
		lastRoundsTracer=200;
		descriptionShort="Z8 Experimental Blaster Cannon High Powered Battery";
		mass=40;
		initSpeed=1800;
	};
	class 885th_DX36C_battery_yellow_high : 885th_cell
	{
		count = 55;
		displayName = "[885th] DX36C High-Powered Armor-Piercing Battery";
		displayNameShort = "DX36C HP AP Battery";
		descriptionShort = "55 round capacity, AP blaster bolts.";
		model = "\MRC\JLTS\weapons\z6\z6_mag.p3d";
		picture = "\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		initSpeed=1035;
		ammo = "885th_blasterbolt_yellow_DX36";
		tracersEvery = 1;
		mass = 15;
	};
	class 885th_DX36C_he_battery_yellow: 885th_cell
	{
		author="Chief33";
		scope=2;
		displayName="[885th]DX36C High Explosive Battery";
		displayNameShort = "DX36C HE Battery";
		descriptionShort="High Explosive battery used by the DX36 Experimental Blaster.";
		model = "\MRC\JLTS\weapons\z6\z6_mag.p3d";
		picture = "\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		ammo="885th_HE_blasterbolt_yellow_DX36";
		count=3;
		mass=15;
		initSpeed=911;
		tracersEvery=1;
		lastRoundsTracer=2;
	};
	class 885th_Z6_he_battery_Blue: 885th_cell
	{
		author="Chief33";
		scope=2;
		displayName="[885th]Z6 High Explosive Battery";
		displayNameShort = "Z6 HE Battery";
		descriptionShort="High Explosive battery used by the Z6 Rotary Cannon.";
		model = "\MRC\JLTS\weapons\z6\z6_mag.p3d";
		picture = "\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		ammo="885th_HE_blasterbolt_Blue_Z6";
		count=3;
		mass=15;
		initSpeed=911;
		tracersEvery=1;
		lastRoundsTracer=2;
	};
	class 885th_DC15CMKII_cell_blue_apex: CA_Magazine
	{
		author="885th Bloodpack Division + SL Mod Dev Team";
		scope=2;
		displayName="[885th] DC15C MK II 65rnd Apex Cell";
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		modelSpecial="\ShadowLegion_Weapons\data\Magazines\DC15\Models\DC15_Mag.p3d";
		modelSpecialIsProxy=1;
		ammo="885th_blasterbolt_bApex";
		count=60;
		mass=8;
		tracersEvery=1;
		descriptionShort="60 round capacity, modified blaster bolts used by the DC15C MK II.";
	};
	class 885th_DC15LEMKII_battery_high_blue: CA_Magazine
	{
		author="885th Bloodpack Division + SL Mod Dev Team";
		scope=2;
		displayName="[885th] DC15LE MKII 50rnd High-Power Energy Cell";
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		modelSpecial="\ShadowLegion_Weapons\data\Magazines\DC15\Models\DC15_Mag.p3d";
		modelSpecialIsProxy=1;
		ammo="885th_blasterbolt_bHigh";
		count=50;
		mass=10;
		initSpeed=1000;
		tracersEvery=1;
		lastRoundsTracer=25;
		descriptionShort="High-Power Energy Cell Used Only For The DC15LE MKII.";
	};
	class 885th_DC15LEMKII_He_Battery_Blue: 885th_cell
	{
		author="885th Bloodpack Division + SL Mod Dev Team";
		scope=2;
		displayName="[885th]DC15LE MK II High Explosive Battery";
		ammo="885th_HE_blasterbolt_blue_DC15LEMKII";
		count=2;
		mass=15;
		initSpeed=1055;
		tracersEvery=1;
		lastRoundsTracer=2;
		descriptionShort="High Explosive Battery used by the DC15LE MK II Heavy Blaster.";
	};
	class 885th_DC15BR_battery_blue: CA_Magazine
	{
		author="885th Bloodpack Division + SL Mod Dev Team";
		scope=2;
		displayName="[885th] DC15BR 45rnd High-Power Energy Cell";
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		modelSpecial="\ShadowLegion_Weapons\data\Magazines\DC15\Models\DC15_Mag.p3d";
		modelSpecialIsProxy=1;
		ammo="885th_blasterbolt_blue";
		count=45;
		mass=10;
		initSpeed=900;
		tracersEvery=1;
		lastRoundsTracer=25;
		descriptionShort="Standard Energy Cell Used Only For The DC15BR.";
	};
	class 885th_Breaching_Scatter_Cell_5Rnd_Blue: CA_Magazine
	{
		author="885th Bloodpack Division + Indecisive Armoury Team";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count=5;
		displayName="[885th] 5Rnd Breaching Scatter Cell";
		displayNameShort="Breaching Scatter Cell";
		descriptionShort="5 round capacity";
		ammo="885th_Breaching_Scattershot_blue";
		tracersEvery=1;
		initSpeed=350;
		mass=8;
	};
	class 885th_DX23_scattershot_mag: CA_Magazine
	{
		author="885th Bloodpack Division + SL Mod Dev Team";
		scope=2;
		displayName="[885th] DX-23 25rnd Scattershot Battery";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		modelSpecial="\ShadowLegion_Weapons\data\Magazines\DC15\Models\DC15_Mag.p3d";
		modelSpecialIsProxy=1;
		initSpeed=400;
		ammo="885th_scattershot_blasterbolt_blue";
		count=25;
		mass=6;
		descriptionShort="DX-23 Scattershot Mag.";
	};
	class 885th_DX23_Doomsday_slug_Mag: CA_Magazine
	{
		author="885th Bloodpack Division + SL Mod Dev Team";
		scope=2;
		displayName="[885th] DX-23 Doomsday Slug Cell";
		picture="\3AS\3AS_Weapons\Data\UI\3as_doomsday_r.paa";
		modelSpecial="\ShadowLegion_Weapons\data\Magazines\DC15\Models\DC15_Mag.p3d";
		modelSpecialIsProxy=1;
		initSpeed=1500;
		ammo="885th_Doomsday_slug_blasterbolt_blue";
		count=1;
		mass=25;
		tracerEvery=1;
		lastRoundsTracer=1;
		descriptionShort="DX-23 Doomsday Slug Mag.";
	};
	class 885th_DC15LMKII_Extended_Cell_blue: CA_Magazine
	{
		author="Antauri + 885th Bloodpack Division";
		scope=2;
		displayName="[885th] DC15L MK II 200rnd Extended Cell";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		modelSpecial="\ShadowLegion_Weapons\data\DC15\DC15L\model\dc15L_Drummag.p3d";
		modelSpecialIsProxy=1;
		ammo="885th_blasterbolt_blue";
		count=200;
		mass=32;
		initSpeed=490;
		tracersEvery=1;
		lastRoundsTracer=200;
		descriptionShort="DC-15L MKII Extended Cell.";
	};
	class 885th_DW32S_cell: CA_Magazine
	{
		JLTS_hasElectronics=1;
		JLTS_hasEMPProtection=1;
		author="885th Bloodpack Division + MrClock";
		scope=2;
		modelSpecial="";
		modelSpecialIsProxy=0;
		picture="\MRC\JLTS\weapons\DW32S\data\ui\DW32S_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\DW32S\DW32S_mag.p3d";
		count=55;
		mass=20;
		initSpeed=839;
		displayName="[885th] DW32S Low-Power Cell";
		descriptionShort="DW-32S Low Power Cell.";
		ammo="885th_blasterbolt_bLow";
		tracersEvery=1;
	};
	class 885th_Valken38A_HighPower_Cell: 885th_cell
	{
		scope=2;
		displayName="[885th] Valken38A 20rnd HighPower Cell";
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		ammo="885th_blasterbolt_bHigh";
		count=20;
		mass=10;
		initSpeed=872;
		tracersEvery=1;
		lastRoundsTracer=10;
		descriptionShort="High Powered charge cell used by the Valken 38X.";
	};
	class 885th_Westarm5mkii_Ap_cell_blue : 885th_cell
	{
		count = 40;
		displayName = "[885th] Westar-M5 MKII Armor-Piercing Energy Cell";
		displayNameShort = "AP Cell";
		descriptionShort = "40 round capacity, AP blaster bolts.";
		ammo = "885th_blasterbolt_bHigh";
		initSpeed=800;
		tracersEvery = 1;
		mass = 10;
	};
	class 885th_coil_blue : 885th_cell
	{
		count = 5;
		displayName = "[885th] Standard Thermal Coil";
		displayNameShort = "Thermal Coil";
		descriptionShort = "5 round capacity, thermal shells.";
		model = "\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		picture = "\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		ammo = "885th_thermalshell";
		initSpeed = 320;
		tracersEvery = 1;
		mass = 70;
		type = 16;
	};
	class 885th_coil_blue_high : 885th_cell
	{
		count = 3;
		displayName = "[885th] High-Power Thermal Coil";
		displayNameShort = "HP Thermal Coil";
		descriptionShort = "3 round capacity, High-Powered thermal shells.";
		model = "\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		picture = "\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		ammo = "885th_thermalshell_high";
		initSpeed = 120;
		tracersEvery = 1;
		mass = 70;
		type = 16;
	};
	class 885th_773_Flame_Cell : 885th_cell
	{
		author="885th Bloodpack Division";
		scope=2;
		count=2;
		displayName="[885th] 773 Flame Cell";
		displayNameShort="Flame Cell";
		descriptionShort="Liquid destruction.";
		model = "\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		picture = "\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		ammo="885th_FlameRound";
		initSpeed=50;
		tracersEvery=1;
		lastRoundsTracer=999;
		mass=15;
	};
	class 885th_25Rnd_Tracerless_Cell: 885th_cell
	{
		author="Antauri + 885th Bloodpack Division";
		scope=2;
		displayName="[885th] 25 Round Tracerless Cell";
		ammo="885th_Traceless_Subsonic_Blue";
		count=25;
		mass=8;
		initSpeed=417;
		tracersEvery=1;
		lastRoundsTracer=10;
		descriptionShort="mixture of tibanna plasma ammunition, invisible to the naked eye, subsonic, yet its capacity per power cell left much to be desired.";
	};
	class 30Rnd_65x39_caseless_mag;
	class 885th_EPL2_mag: 30Rnd_65x39_caseless_mag
	{
		JLTS_hasElectronics=1;
		JLTS_hasEMPProtection=1;
		author="885th Bloodapack Division";
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		count=2;
		displayName="$STR_JLTS_names_EPL2_mag";
		displayNameShort="$STR_JLTS_snames_EnergyCellEMP";
		descriptionShort="$STR_JLTS_descs_EPL2_mag";
		ammo="885th_ammo_Grenade_EMP";
		modelSpecialIsProxy=0;
		modelSpecial="";
		initSpeed=250;
		mass=13;
	};
	// E-Series
	class 885th_e_cell_red : 885th_cell
	{
		count = 50;
		displayName = "[885th] Economy Energy Cell";
		displayNameShort = "Eco. Cell";
		descriptionShort = "50 round capacity, red blaster bolts.";
		ammo = "885th_blasterbolt_red";
		tracersEvery = 1;
		mass = 10;
	};
	class 885th_e_cell_red_pistol : 885th_e_cell_red
	{
		count = 15;
		displayName = "[885th] Economy Pistol Energy Cell";
		displayNameShort = "Eco. Pistol Cell";
		descriptionShort = "15 round capacity, red blaster bolts.";
		ammo = "885th_blasterbolt_red";
		tracersEvery = 1;
		mass = 3;
	};
	class 885th_e_battery_red_high : 885th_e_cell_red
	{
		count = 300;
		displayName = "[885th] Economy High-Power Battery";
		displayNameShort = "Eco. HP Battery";
		descriptionShort = "300 round capacity, red high power blaster bolts.";
		model = "\MRC\JLTS\weapons\z6\z6_mag.p3d";
		picture = "\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		ammo = "885th_blasterbolt_rAmp";
		tracersEvery = 1;
		mass = 25;
	};
	class 885th_e_cell_red_amp : 885th_e_cell_red
	{
		count = 10;
		displayName = "[885th] Economy Amplified Energy Cell";
		displayNameShort = "Eco. Amp. Cell";
		descriptionShort = "10 round capacity, red blaster bolts.";
		ammo = "885th_blasterbolt_rAmp";
		tracersEvery = 1;
		mass = 10;
	};
	class IDA_wrist_rocket;
	class 885th_wrist_rocket : IDA_wrist_rocket {
		count = 3;
	};
	// Mando Series
	class 885th_mando_cell_yellow : 885th_cell
	{
		count = 40;
		displayName = "[885th] Armor-Piercing Energy Cell";
		displayNameShort = "AP Cell";
		descriptionShort = "40 round capacity, AP blaster bolts.";
		ammo = "885th_blasterbolt_yellow";
		tracersEvery = 1;
		mass = 10;
	};
	class 885th_mando_cell_yellow_pistol : 885th_mando_cell_yellow
	{
		count = 10;
		displayName = "[885th] Armor-Piercing Pistol Energy Cell";
		displayNameShort = "AP Pistol Cell";
		descriptionShort = "10 round capacity, AP blaster bolts.";
		ammo = "885th_blasterbolt_yellow";
		tracersEvery = 1;
		mass = 4;
	};
	class 885th_mando_cell_yellow_high : 885th_mando_cell_yellow
	{
		count = 20;
		displayName = "[885th] High-Powered Armor-Piercing Energy Cell";
		displayNameShort = "HP AP Cell";
		descriptionShort = "20 round capacity, AP blaster bolts.";
		ammo = "885th_blasterbolt_yHigh";
		tracersEvery = 1;
		mass = 10;
	};
	class IDA_Blaster_Clip_Power2_60Rnd_Blue;
	class 885_dc_cell_AP : IDA_Blaster_Clip_Power2_60Rnd_Blue
	{
		count = 60;
		displayName = "[885th] 60-Round Armor-Piercing Energy Cell";
		displayNameShort = "HP AP Cell";
		descriptionShort = "60 round capacity, AP blaster bolts.";
		ammo = "885th_blasterbolt_bApex";
		tracersEvery = 1;
		mass = 10;
	};
	class IDA_Blaster_Clip_Power4_5Rnd_Blue;
	class 885_dc_cell_sniper : IDA_Blaster_Clip_Power4_5Rnd_Blue
	{
		count = 5;
		displayName = "[885th] 5-Round Armor-Piercing Energy Cell";
		displayNameShort = "HP AP Cell";
		descriptionShort = "5 round capacity, AP blaster bolts.";
		ammo = "885th_blasterbolt_DC17MSnip";
		initSpeed =2000;
		tracersEvery = 1;
		mass = 10;
	};
	class IDA_Blaster_Clip_Grenade;
	class 885th_RC_AAD: IDA_Blaster_Clip_Grenade
	{
		count = 1;
		displayName = "[885th] T-31 Anti-Armor Det";
		displayNameShort = " T-31 AAD";
		descriptionShort = "1 round capacity, High-Powered thermal detonator.";
		model = "\MRC\JLTS\weapons\EPL2\EPL2_mag.p3d";
		picture = "\MRC\JLTS\weapons\EPL2\data\ui\EPL2_mag_ui_ca.paa";
		ammo = "885th_thermalshell_high";
		initSpeed = 450;
		tracersEvery = 1;
		mass = 30;
		type = 16;
	};
	class 885th_mando_cell_yellow_amp : 885th_mando_cell_yellow
	{
		count = 20;
		displayName = "[885th] Amplified AP Energy Cell";
		displayNameShort = "Amp. AP Cell";
		descriptionShort = "20 round capacity, AP blaster bolts.";
		ammo = "885th_blasterbolt_yAmp";
		tracersEvery = 1;
		mass = 10;
	};
	class 885th_mando_battery_yellow_high : 885th_mando_cell_yellow
	{
		count = 100;
		displayName = "[885th] High-Powered Armor-Piercing Energy Battery";
		displayNameShort = "HP AP Battery";
		descriptionShort = "100 round capacity, AP blaster bolts.";
		model = "\MRC\JLTS\weapons\z6\z6_mag.p3d";
		picture = "\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		ammo = "885th_blasterbolt_yHigh";
		tracersEvery = 1;
		mass = 100;
	};
	// BlackSun Series
	class 885th_cell_green_pistol : 885th_dc_cell_green
	{
		count = 10;
		displayName = "[885th] Militia Pistol Energy Cell";
		displayNameShort = "Militia Pistol Cell";
		descriptionShort = "10 round capacity, green blaster bolts.";
		ammo = "885th_blasterbolt_gHigh";
		tracersEvery = 1;
		mass = 4;
	};
	class 885th_cell_green_high : 885th_dc_cell_green
	{
		count = 25;
		displayName = "[885th] Militia High-Powered Energy Cell";
		displayNameShort = "Militia HP Cell";
		descriptionShort = "25 round capacity, green HP blaster bolts.";
		ammo = "885th_blasterbolt_gHigh";
		tracersEvery = 1;
		mass = 10;
	};
};
class CfgMagazineWells
{
	class DC_energycells
	{
		885th_Magazines[] =
		{
			"885th_dc_cell_blue_low",
			"885th_dc_cell_blue",
			"885th_dc_cell_green",
			"885th_dc_cell_blue_high"
		};
		BI_Magazines[] = {};
	};
	class DC_Marksman_energycells
	{
		885th_Magazines[] =
		{
			"885th_dc_cell_blue",
			"885th_dc_cell_green",
			"885th_dc_cell_blue_high",
			"885th_dc_cell_blue_amp"
		};
		BI_Magazines[] = {};
	};
	class DC_Sniper_energycells
	{
		885th_Magazines[] =
		{
			"885th_dc_cell_blue_high",
			"885th_dc_cell_blue_amp",
			"885th_dc_cell_blue_over"
		};
		BI_Magazines[] = {};
	};
	class 885th_MPL_MagWell
	{
		885th_Magazines[]=
		{
			"885th_MPL_3rnd_HE_Grenade",
			"885th_MPL_3rnd_Cluster_Grenade",
			"885th_MPL_3rnd_AP_Micro_Rocket",
			"885th_MPL_3Rnd_Smoke_White_shell",
			"885th_MPL_3Rnd_Smoke_Red_shell",
			"885th_MPL_3Rnd_Smoke_Green_shell",
			"885th_MPL_3Rnd_Smoke_Yellow_shell",
			"885th_MPL_3Rnd_Smoke_Purple_shell",
			"885th_MPL_3Rnd_Smoke_Blue_shell",
			"885th_MPL_3Rnd_Smoke_Orange_shell"
		};
	};
};
class WeaponSlotsInfo;
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CowsSlot_Rail;
class MuzzleSlot_65;
class UnderBarrelSlot_rail;
class PointerSlot_Rail;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class FullAuto;
class GunParticles;
class CBA_DisposableLaunchers
{
	IDA_RPS6_Base[] = {"IDA_RPS6_Disposable", "IDA_RPS6_Used"};
};
class CfgWeapons
{
	class NVGoggles;
	class InventoryOpticsItem_Base_F;
	class optic_lrps;
	class UGL_F;
	class GrenadeLauncher;
	class ItemCore;
	class WeaponSlotsInfo;
	class Launcher_Base_F;
	class launch_B_Titan_Short_F;
	class Pistol_Base_F;
	class Rifle_Base_F;
	class Rifle_Long_Base_F;
	class UGL_40x36;
	class SMG_03C_TR_Khaki
	{
		class WeaponSlotsInfo;
	};
	class 3as_Valken38x_F;
	class 3AS_DC15A_Base_F;
	class 3as_DC15C_Base_F;
	class 3AS_A180_F;
	class 3AS_S5_F;
	class 3AS_MuzzleSlot_DC15S;
	class 3AS_CowsSlot_DC15S;
	class 3AS_MuzzleSlot_DC15A;
	class 3AS_CowsSlot_DC15A; 
	class 3AS_UnderBarrelSlot_DC15A;
	class 3AS_1UGL_MK54_HE_shell;
	class 3AS_1UGL_Magwell;
	class JLTS_DC15A_ugl;
	class IDA_DC15S;
	class IDA_DC15A;
	class IDA_DC17;
	class IDA_E5;
	class IDA_Westar35;
	class IDA_Galaar15;
	class IDA_Galaar90;
	class ShdwCmpny_DC15C_F;
	class IDA_RPS6_Base;
	class ls_weapons_firepuncher;
	class WeaponCloudGun;
	class launch_RPG32_F : Launcher_Base_F
	{
		class WeaponSlotsInfo;
	};
	class arifle_MX_Base_F : Rifle_Base_F
	{
		access = 0;
		scope = 0;
		author = "885th Bloodpack Division";
		ace_overheating_mrbs = 5000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ACE_twistDirection = 0;
		modes[] = {"Single"};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 15;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
		class GunClouds : WeaponCloudGun
		{
			cloudletAnimPeriod = 0.1;
			cloudletSize = 0.01;
			cloudletGrowUp = 0.200000;
			cloudletFadeIn = 0.01;
			cloudletFadeOut = 0.400000;
			cloudletDuration = 0.002;
			cloudletAlpha = 0.2;
			cloudletColor[] = {1,1,1,0};
			cloudletShape = "\ca\data\cl_basic";
			cloudletAccY = 0.0;
			cloudletMinYSpeed = -0.0;
			cloudletMaxYSpeed = 0.0;
			density = 0.1;
			deltaT = -0.5;
			in = 0.0;
			out = 0.0;
			initT = 1.0;
			interval = 0.020000;
			size = 0.03;
			sourceSize = 0.015000;
			class Table
			{
				class T1
				{
					maxT = 0;
					color[] = { 0.8, 0.8, 0.8, 1 };
				};
				class T2
				{
					maxT = 900;
					color[] = { 0.3, 0.3, 0.3, 1 };
				};
				class T3
				{
					maxT = 1000;
					color[] = { 1, 0.5, 0, 0.5 };
				};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
		class OpticsModes
		{
			class Iron
			{
				opticsID = 1;
				useModelOptics = 0;
				opticsPPEffects[] = {"", ""};
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.25;
				opticsZoomInit = 0.75;
				discreteDistance[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
				discreteDistanceInitIndex = 1;
				distanceZoomMin = 200;
				distanceZoomMax = 200;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
			};
			class DC15S_Scope
			{
				opticsID = 2;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsRadialBlur1", "OpticsBlur1"};
				opticsZoomMin = 0.125;
				opticsZoomMax = 0.125;
				opticsZoomInit = 0.125;
				discreteDistance[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
				discreteDistanceInitIndex = 1;
				distanceZoomMin = 100;
				distanceZoomMax = 1000;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				cameraDir = "";
			};
		};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.2;
			dispersion = 0.00200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 500;
			midRangeProbab = 1.0;
			maxRange = 1500;
			maxRangeProbab = 0.8;
		};
	};
	class launcher_MX_Base_F : Launcher_Base_F
	{
		access = 0;
		scope = 0;
		author = "885th Bloodpack Division";
		ace_overheating_mrbs = 5000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_twistDirection = 0;
		modes[] = {"Single"};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 15;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
		class GunClouds : WeaponCloudGun
		{
			cloudletAnimPeriod = 0.1;
			cloudletSize = 0.01;
			cloudletGrowUp = 0.200000;
			cloudletFadeIn = 0.01;
			cloudletFadeOut = 0.400000;
			cloudletDuration = 0.002;
			cloudletAlpha = 0.2;
			cloudletColor[] = {1,1,1,0};
			cloudletShape = "\ca\data\cl_basic";
			cloudletAccY = 0.0;
			cloudletMinYSpeed = -0.0;
			cloudletMaxYSpeed = 0.0;
			density = 0.1;
			deltaT = -0.5;
			in = 0.0;
			out = 0.0;
			initT = 1.0;
			interval = 0.020000;
			size = 0.03;
			sourceSize = 0.015000;
			class Table
			{
				class T1
				{
					maxT = 0;
					color[] = { 0.8, 0.8, 0.8, 1 };
				};
				class T2
				{
					maxT = 900;
					color[] = { 0.3, 0.3, 0.3, 1 };
				};
				class T3
				{
					maxT = 1000;
					color[] = { 1, 0.5, 0, 0.5 };
				};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
		class OpticsModes
		{
			class Iron
			{
				opticsID = 1;
				useModelOptics = 0;
				opticsPPEffects[] = {"", ""};
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.25;
				opticsZoomInit = 0.75;
				discreteDistance[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
				discreteDistanceInitIndex = 1;
				distanceZoomMin = 200;
				distanceZoomMax = 200;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
			};
			class DC15S_Scope
			{
				opticsID = 2;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsRadialBlur1", "OpticsBlur1"};
				opticsZoomMin = 0.125;
				opticsZoomMax = 0.125;
				opticsZoomInit = 0.125;
				discreteDistance[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
				discreteDistanceInitIndex = 1;
				distanceZoomMin = 100;
				distanceZoomMax = 1000;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				cameraDir = "";
			};
		};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.2;
			dispersion = 0.00200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 500;
			midRangeProbab = 1.0;
			maxRange = 1500;
			maxRangeProbab = 0.8;
		};
	};
	class 885th_Stun_pistol : Pistol_Base_F
	{
		displayName = "Stun Mode";
		magazines[] = {"IDA_Stun_cell"};
		sounds[] = {"StandardSound"};
		class BaseSoundModeType
		{
			weaponSoundEffect = "";
			closure1[] = {};
			closure2[] = {};
			soundClosure[] = {};
		};
		class StandardSound : BaseSoundModeType
		{
			weaponSoundEffect = "";
			begin1[] = {"\Indecisive_Armoury_Sounds\Stun_Fire.ogg", 1.25, 1, 1800};
			soundBegin[] = {"begin1", 0.2};
		};
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\Blaster_reload_1.ogg", 1.5, 1, 100};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		magazineReloadTime = 0;
		reloadTime = 0.4;
		optics = 1;
		modelOptics = "";
		cameraDir = "GL look";
		memoryPointCamera = "eye";
		opticsZoomMin = 0.375;
		opticsZoomMax = 1.1;
		opticsZoomInit = 0.75;
		weaponInfoType = "RscWeaponZeroing";
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
		dispersion = 0.0;
		minRange = 0;
		minRangeProbab = 0.0;
		midRange = 100;
		midRangeProbab = 0.0;
		maxRange = 200;
		maxRangeProbab = 0.0;
	};
	class 885th_Stun_rifle : Rifle_Base_F
	{
		displayName = "Stun Mode";
		magazines[] = {"IDA_Stun_cell"};
		sounds[] = {"StandardSound"};
		class BaseSoundModeType
		{
			weaponSoundEffect = "";
			closure1[] = {};
			closure2[] = {};
			soundClosure[] = {};
		};
		class StandardSound : BaseSoundModeType
		{
			weaponSoundEffect = "";
			begin1[] = {"\Indecisive_Armoury_Sounds\Stun_Fire.ogg", 1.25, 1, 1800};
			soundBegin[] = {"begin1", 0.2};
		};
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\Blaster_reload_1.ogg", 1.5, 1, 100};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		magazineReloadTime = 0;
		reloadTime = 0.4;
		optics = 1;
		modelOptics = "";
		cameraDir = "GL look";
		memoryPointCamera = "eye";
		opticsZoomMin = 0.375;
		opticsZoomMax = 1.1;
		opticsZoomInit = 0.75;
		weaponInfoType = "RscWeaponZeroing";
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
		dispersion = 0.0;
		minRange = 0;
		minRangeProbab = 0.0;
		midRange = 100;
		midRangeProbab = 0.0;
		maxRange = 200;
		maxRangeProbab = 0.0;
	};
	// Republic
	
	class 885th_DC17 : Pistol_Base_F
	{
		author = "885th Bloodpack Division";
		ace_overheating_mrbs = 5000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 114.3;
		access = 0;
		scope = 2;
		scopeArsenal = 2;
		picture = "\Indecisive_Armoury_Weapons_REPUBLIC\Data\DC17\DC17_ui.paa";
		model = "Indecisive_Armoury_Weapons_REPUBLIC\Data\DC17\Model\IDA_DC17.p3d";
		displayName = "[885th] DC-17 Blaster Pistol";
		descriptionShort = "Standard Issue Pistol.";
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		magazines[] = {"885th_dc_cell_blue_pistol"};
		magazineWell[] = {};
		muzzles[] = {"this", "Stun"};
		nameSound = "Pistol";
		optics = 1;
		primary = 10;
		recoil = "885_recoil_DC17";
		reloadAction = "GestureReload_IDA_Reload_BlasterPistol";
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\Blaster_reload_Vent.ogg", 1.5, 1, 100};
		reloadSound[] = {"", 1, 1};
		reloadTime = 1;
		modes[] = {"Single"};
		fireLightDiffuse[]={0.1,0.25,1};
		class Stun : 885th_Stun_pistol
		{
		};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.1;
			dispersion = 0.00040;
			minRange = 0;
			minRangeProbab = 0.6;
			midRange = 100;
			midRangeProbab = 0.4;
			maxRange = 500;
			maxRangeProbab = 0.2;
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 35;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
	};
	class 885th_DC17A : Pistol_Base_F
	{
		author = "885th Bloodpack Division";
		ace_overheating_mrbs = 5000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 114.3;
		access = 0;
		scope = 2;
		scopeArsenal = 2;
		picture = "\Indecisive_Armoury_Weapons_REPUBLIC\Data\DC17\DC17_ui.paa";
		model = "Indecisive_Armoury_Weapons_REPUBLIC\Data\DC17\Model\IDA_DC17.p3d";
		displayName = "[885th] DC-17A Blaster Pistol";
		descriptionShort = "Standard Full Auto Pistol.";
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		magazines[] = {"885th_dc_cell_blue_pistol_extended"};
		magazineWell[] = {};
		muzzles[] = {"this"};
		nameSound = "Pistol";
		optics = 1;
		primary = 10;
		recoil = "885_recoil_DC17";
		reloadAction = "GestureReload_IDA_Reload_BlasterPistol";
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\Blaster_reload_Vent.ogg", 1.5, 1, 100};
		reloadSound[] = {"", 1, 1};
		reloadTime = 1;
		caseless[]={"",1,1,1};
		soundBullet[]={"caseless",1};
		modes[] = {"Single", "FullAuto"};
		fireLightDiffuse[]={0.1,0.25,1};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.1;
			dispersion = 0.00040;
			minRange = 0;
			minRangeProbab = 0.6;
			midRange = 100;
			midRangeProbab = 0.4;
			maxRange = 500;
			maxRangeProbab = 0.2;
		};
		class FullAuto: Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC17.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime=0.050000001;
			dispersion=0.0053500001;
			minRange=5;
			minRangeProbab=0.89999998;
			midRange=25;
			midRangeProbab=0.69999999;
			maxRange=50;
			maxRangeProbab=0.1;
			aiRateOfFire=1e-006;
			aiRateOfFireDistance=50;
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 35;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
	};
	class 885th_DC21 : Pistol_Base_F
	{
		author = "885th Bloodpack Division";
		ace_overheating_mrbs = 5000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 114.3;
		access = 0;
		scope = 2;
		scopeArsenal = 2;
		canShootInWater=1;
		model="\ShadowLegion_Weapons\data\DC21\Model\DC21.p3d";
		picture="\ShadowLegion_Weapons\data\DC21\UI\DC21_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\DC21\UI\DC21_UI.paa";
		displayName = "[885th] DC-21 Blaster Pistol";
		descriptionShort = "Modular and Compact Pistol.";
		drySound[] = {"885_Weapons\DX36C\drysound.ogg", 5, 1, 20};
		magazines[] = {"885th_dc_cell_blue_pistol_extended","885th_25Rnd_Tracerless_Cell"};
		magazineWell[] = {};
		muzzles[] = {"this", "Stun"};
		nameSound = "Pistol";
		recoil = "885_recoil_DC17";
		reloadMagazineSound[] = {"\ShadowLegion_Weapons\data\reloads\sounds\Reload_1.ogg", 2, 1,30};
		reloadSound[] = {"", 1, 1};
		caseless[]={"",1,1,1};
		soundBullet[]={"caseless",1};
		modes[] = {"Single"};
		fireLightDiffuse[]={0.1,0.25,1};
		class Stun : 885th_Stun_pistol
		{
		};
		class Single: Mode_SemiAuto
		{
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
					"\ShadowLegion_Weapons\data\DC21\DC21_1.ogg",
					1.9952624,
					1,
					600
				};
				begin2[]=
				{
					"\ShadowLegion_Weapons\data\DC21\DC21_2.ogg",
					1.9952624,
					1,
					600
				};
				begin3[]=
				{
					"\ShadowLegion_Weapons\data\DC21\DC21_3.ogg",
					1.9952624,
					1,
					600
				};
				begin4[]=
				{
					"\ShadowLegion_Weapons\data\DC21\DC21_4.ogg",
					1.9952624,
					1,
					600
				};
				soundBegin[]=
				{
					"begin1",
					0.30000001,
					"begin2",
					0.30000001,
					"begin3",
					0.30000001,
					"begin4",
					0.30000001
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
			};
			reloadTime=0.12;
			dispersion=0.0029500001;
			minRange=1;
			minRangeProbab=0.30000001;
			midRange=80;
			midRangeProbab=0.57999998;
			maxRange=150;
			maxRangeProbab=0.039999999;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: MuzzleSlot_65
			{
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]=
				{
					"ShadwCmpany_Suppresor_Module_DC21",
					"885th_Barrel_Module_DC21"
				};
			};
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]=
				{
					"acc_flashlight_pistol"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]={};
			};
		}
	};
	class 885th_DC15S : arifle_MX_Base_F
	{
		ace_overheating_mrbs = 5000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 228;
		author = "885th Bloodpack Division";
		scope = 2;
		inertia = 0.25;
		primary = 10;
		canShootInWater = 1;
		displayName = "[885th] DC-15S Carbine";
		descriptionShort = "Standard Issue Carbine.";
		picture = "Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15S\DC15S_ui.paa";
		model = "Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15S\Model\IDA_DC15S.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "Indecisive_Armoury_Anims\REPUBLIC\DC15S.rtm"};
		ace_clearJamAction = "";
		reloadAction = "GestureReload_JLTS_DC15S";
		reloadTime = 1.0;
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\Blaster_reload_Vent.ogg", 1.5, 1, 100};
		recoil = "885_recoil_dc15s";
		magazines[] = {"885th_dc_cell_blue"};
		magazineWell[] = {"DC_energycells"};
		modes[] = {"Single", "FullAuto"};
		fireLightDiffuse[] = {0.1, 0.25, 1};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.2;
			dispersion = 0.00200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 500;
			midRangeProbab = 1.0;
			maxRange = 1500;
			maxRangeProbab = 0.8;
		};
		class FullAuto : Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.15;
			dispersion = 0.00300;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 100;
			midRangeProbab = 1.0;
			maxRange = 300;
			maxRangeProbab = 0.4;
		};
		modelOptics = "3AS\3AS_Weapons\Data\3AS_2D_Optic.p3d";
		weaponInfoType = "RscWeaponZeroing";
		class OpticsModes
		{
			class Ironsights
			{
				opticsID = 1;
				useModelOptics = 0;
				opticsFlare = "false";
				opticsPPEffects[] = {"OpticsCHAbera5", "OpticsBlur5"};
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.4;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.75;
				memoryPointCamera = "eye";
				visionMode[] = {};
				discreteDistance[]={50,100};
				discreteDistanceInitIndex=0;
				distanceZoomMin = 100;
				distanceZoomMax = 100;
			};
			class Scope : Ironsights
			{
				opticsID = 2;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera5", "OpticsBlur5"};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.015;
				opticsZoomMax = 0.1;
				opticsZoomInit = 0.1;
				memoryPointCamera = "opticView";
				visionMode[] = {};
				discreteDistance[]={100,200,300,400,500};
				discreteDistanceInitIndex=0;
				distanceZoomMin = 100;
				distanceZoomMax = 500;
			};
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 65;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
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
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
	};
	class 885th_DC15SE: Rifle_Base_F
	{	
		ace_overheating_mrbs = 5000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 300;
		scope=2;
		author="Antauri & 885th";
		displayName="[885th] DC-15SE";
		descriptionShort = "Modified DC-15S.";
		model="\ShadowLegion_Weapons\data\DC15\DC15S\model\DC15_S_Folded2.p3d";
		picture="\ShadowLegion_Weapons\data\DC15\DC15S\UI\DC15S_Folded_Stock_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\DC15\DC15S\UI\DC15S_Folded_Stock_UI.paa";
		weaponInfoType="RscWeaponZeroing";
		recoil = "885_recoil_dc15s";
		magazines[] = {"885th_dc_cell_blue"};
		magazineWell[] = {"DC_energycells"};
		fireLightDiffuse[] = {0.1, 0.25, 1};
		drySound[] = {"885_Weapons\DX36C\drysound.ogg", 5, 1, 20};
		ace_clearJamAction = "";
		reloadAction="3AS_GestureReloadDC15S";
		reloadMagazineSound[] = {"\ShadowLegion_Weapons\data\reloads\sounds\Reload_1.ogg", 1, 1, 30};
		magazineReloadSwitchPhase=0.40000001;
		discreteDistanceInitIndex=0;
		canShootInWater=1;
		inertia=0.40000001;
		dexterity=1.6;
		initSpeed=-1;
		handAnim[]={"OFP2_ManSkeleton","ShadowLegion_Weapons\data\DC15\DC15S\anim\ReloadBASE_DC15S_Unfolded.rtm"};
		selectionFireAnim="zasleh";
		flash="gunfire";
		flashSize=3;
		modes[]={"Burst"};
		muzzles[]={"this","Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		class Burst: Mode_Burst
		{
			reloadTime=0.09;
			dispersion=0.00056000001;
			minRange=2;
			minRangeProbab=0.89999998;
			midRange=500;
			midRangeProbab=0.69999999;
			maxRange=1000;
			maxRangeProbab=0.1;
			soundContinuous=0;
			soundBurst=0;
			sounds[] = {"StandardSound","SilencedSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 0.5};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			}
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]=
				{
					"ShadwCmpany_optic_Reflex_Mk1",
					"ShadwCmpany_optic_Acog",
					"ShadwCmpany_optic_e11",
					"ShdwCmpny_Optic_Valken",
					"optic_mrco",
					"ShadwCmpany_773_Hybrid_Magnifier_Holo",
					"ShadwCmpany_773_Hybrid_Magnifier_Magnified",
					"ShdwCmpny_Optic_LEScope_DC15A_mk2",
					"ShdwCmpny_Optic_LEScope_DC15A",
					"ShadwCmpany_Hybrid_Magnifier_Holo",
					"ShadwCmpany_Hybrid_Magnifier_Magnified"
					
				};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR",
					"ace_acc_pointer_red",
					"ace_acc_pointer_green",
					"ShdwCmpny_Light_MPD",
					"ShdwCmpny_IR_MPD"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]={};
			};
			class MuzzleSlot: MuzzleSlot_65
			{
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]={"ShadwCmpany_Suppresor_Module_DC19"};
			};
		};
		opticsZoomMin=0.25;
		opticsZoomMax=1.25;
		opticsZoomInit=0.75;
		distanceZoomMin=200;
		distanceZoomMax=200;
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
	};
	class 885th_DC15SE_GL: 885th_DC15SE
	{
		scope=2;
		displayName="[885th] DC-15SE GL";
		model="\ShadowLegion_Weapons\data\DC15\DC15S\model\DC15_S_GL_2.p3d";
		picture="\ShadowLegion_Weapons\data\DC15\DC15S\UI\DC15S_GL_2_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\DC15\DC15S\UI\DC15S_GL_UI.paa";
		weaponInfoType="RscWeaponZeroing";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"ShadowLegion_Weapons\data\DC15\DC15S\anim\ReloadBASE_DC15S_GL.rtm"
		};
		muzzles[]=
		{
			"this",
			"885th_15SEGL"
		};
		class 885th_15SEGL: UGL_F
		{
			displayName="[885th] DC-15SE Underbarrel";
			descriptionShort="DC15SEGL";
			useModelOptics=0;
			useExternalOptic=0;
			modes[]=
			{
				"Fire"
			};
			class Fire: Mode_SemiAuto
			{
				sounds[]=
				{
					"StandardSound"
				};
				class BaseSoundModeType
				{
					weaponSoundEffect="";
					closure1[]={};
					closure2[]={};
					soundClosure[]={};
				};
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
			magazines[]=
			{
				"3AS_1UGL_MK54_HE_shell"
			};
			magazineWell[]=
			{
				"UGL_40x36",
				"3AS_1UGL_Magwell"
			};
			cameraDir="OP_look";
			discreteDistance[]={50,75,100,150,200,250,300,350,400};
			discreteDistanceCameraPoint[]=
			{
				"OP_eye_50",
				"OP_eye_75",
				"OP_eye_100",
				"OP_eye_150",
				"OP_eye_200",
				"OP_eye_250",
				"OP_eye_300",
				"OP_eye_350",
				"OP_eye_400"
			};
			discreteDistanceInitIndex=1;
			reloadAction="GestureReloadMXUGL";
			reloadMagazineSound[]=
			{
				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Mx_UGL_reload",
				1,
				1,
				10
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=60;
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]=
				{
					"ShadwCmpany_optic_Reflex_Mk1",
					"ShadwCmpany_optic_Acog",
					"ShadwCmpany_optic_e11",
					"ShdwCmpny_Optic_Valken",
					"optic_mrco",
					"ShadwCmpany_773_Hybrid_Magnifier_Holo",
					"ShadwCmpany_773_Hybrid_Magnifier_Magnified",
					"ShdwCmpny_Optic_LEScope_DC15A_mk2",
					"ShdwCmpny_Optic_LEScope_DC15A",
					"ShadwCmpany_Hybrid_Magnifier_Holo",
					"ShadwCmpany_Hybrid_Magnifier_Magnified"
					
				};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR",
					"ace_acc_pointer_red",
					"ace_acc_pointer_green",
					"ShdwCmpny_Light_MPD",
					"ShdwCmpny_IR_MPD"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]={};
			};
			class MuzzleSlot: MuzzleSlot_65
			{
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]={"ShadwCmpany_Suppresor_Module_DC19"};
			};
		};
		ace_overheating_mrbs=3000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=0.75;
	};
	class 885th_DC15SMKII_Base_F: Rifle_Base_F
	{
		author="885th Bloodpack Division";
		magazines[]={"885th_dc_cell_blue"};
		magazineWell[]={"DC_energycells"};
		magazineReloadSwitchPhase=0.5;
		reloadAction="GestureReload_JLTS_DC15S";
		recoil="3AS_recoil_DC15S";
		maxZeroing=600;
		discreteDistanceInitIndex=0;
		maxRecoilSway=0.0125;
		swayDecaySpeed=1.25;
		inertia=0.40000001;
		aimTransitionSpeed=0.80000001;
		dexterity=1.6;
		initSpeed=-1;
		class GunParticles: GunParticles
		{
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=50;
			class MuzzleSlot: 3AS_MuzzleSlot_DC15S
			{
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
			};
			class CowsSlot: 3AS_CowsSlot_DC15S
			{
				iconPosition[]={0.5,0.34999999};
				iconScale=0.2;
			};
		};
		distanceZoomMin=300;
		distanceZoomMax=300;
		descriptionShort="";
		handAnim[]={"OFP2_ManSkeleton","3as\3AS_Weapons\Republic\DC15S\Data\Anim\New_DC15S_Handanim.rtm"};
		modes[]=
		{
			"FullAuto",
			"Single",
			"single_medium_optics1",
			"single_far_optics2"
		};
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_DC15S_Shot_SoundSet"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin2[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin3[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin4[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin5[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin6[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			}
			reloadTime=0.085000001;
			dispersion=0.00092999998;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=50;
			maxRangeProbab=0.050000001;
			aiRateOfFire=1e-006;
		};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.1;
			dispersion=0.00066000002;
			minRange=2;
			minRangeProbab=0.5;
			midRange=150;
			midRangeProbab=0.69999999;
			maxRange=350;
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
				soundSetShot[]=
				{
					"3AS_DC15S_Shot_SoundSet"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin2[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin3[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin4[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin5[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin6[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			}
		};
		class single_medium_optics1: Single
		{
			requiredOpticType=1;
			showToPlayer=0;
			minRange=5;
			minRangeProbab=0.2;
			midRange=300;
			midRangeProbab=0.69999999;
			maxRange=450;
			maxRangeProbab=0.2;
			aiRateOfFire=6;
			aiRateOfFireDistance=500;
		};
		class single_far_optics2: Single
		{
			requiredOpticType=2;
			showToPlayer=0;
			minRange=100;
			minRangeProbab=0.2;
			midRange=400;
			midRangeProbab=0.69999999;
			maxRange=600;
			maxRangeProbab=0.050000001;
			aiRateOfFire=8;
			aiRateOfFireDistance=800;
		};
		class GL_1GL_F: UGL_F
		{
			displayName="$STR_A3_cfgweapons_3gl0";
			descriptionShort="$STR_A3_cfgweapons_3gl1";
			useModelOptics=0;
			useExternalOptic=0;
			magazines[]=
			{
				"3AS_1UGL_MK54_HE_shell"
			};
			magazineWell[]=
			{
				"UGL_40x36",
				"3AS_1UGL_Magwell"
			};
			modes[]=
			{
				"Fire"
			};
			class Fire: Mode_SemiAuto
			{
				sounds[]=
				{
					"StandardSound"
				};
				class BaseSoundModeType
				{
					weaponSoundEffect="";
					closure1[]={};
					closure2[]={};
					soundClosure[]={};
				};
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
			cameraDir="OP_look";
			discreteDistance[]={50,75,100,150,200,250,300,350,400};
			discreteDistanceCameraPoint[]=
			{
				"OP_eye_50",
				"OP_eye_75",
				"OP_eye_100",
				"OP_eye_150",
				"OP_eye_200",
				"OP_eye_250",
				"OP_eye_300",
				"OP_eye_350",
				"OP_eye_400"
			};
			discreteDistanceInitIndex=1;
			reloadAction="GestureReloadMXUGL";
			reloadMagazineSound[]=
			{
				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Mx_UGL_reload",
				1,
				1,
				10
			};
		};
		aiDispersionCoefY=6;
		aiDispersionCoefX=4;
		class OpticsModes
		{
			class Ironsights
			{
				opticsID=1;
				useModelOptics=0;
				opticsFlare=0;
				opticsPPEffects[]=
				{
					"Default"
				};
				opticsDisablePeripherialVision=0;
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=100;
				distanceZoomMax=100;
			};
		};
		caseless[]={"",1,1,1};
		soundBullet[]={"caseless",1};
		drySound[]={"\3AS\3AS_Main\Sounds\Blaster_empty",2,1,20};
		reloadMagazineSound[]={"\3AS\3AS_Main\Sounds\Old\Blaster_reload.wss",1,1,30};
		hiddenSelections[]={"holo_reticle"};
		hiddenSelectionsTextures[]={"\3AS\3AS_Weapons\Republic\DC15S\Data\reticle_DC15S_ca.paa"};
		ace_overheating_mrbs=3000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=0.75;
	};
	class 885th_DC15SMKII_F: 885th_DC15SMKII_Base_F
	{
		author="885th Bloodpack Division";
		baseWeapon="885th_DC15S_F";
		scope=2;
		displayName="[885th] DC-15S MKII";
		model="\3AS\3AS_Weapons\Republic\DC15S\3AS_DC15S_F.p3d";
		picture="\3AS\3AS_Weapons\Republic\DC15S\Data\UI\3as_dc15s.paa";
		UiPicture="\A3\weapons_f\data\UI\icon_regular_CA.paa";
		fireLightDiffuse[]={0.1,0.25,1};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 75;
			class CowsSlot: CowsSlot
			{	
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]={"ShadwCmpany_optic_Acog","3AS_Imp_Optic_1", "3AS_Imp_Optic_2", "3AS_Imp_Optic_3","3AS_optic_DC15C_F","3AS_Imp_Optic_E11",};
			};
			class MuzzleSlot : MuzzleSlot
			{	
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[] = {"ShadwCmpany_Suppresor_Module_DC19"};
			};
			class PointerSlot : PointerSlot
			{	
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};
	class 885th_DC15SMKII_GL: 885th_DC15SMKII_Base_F
	{
		author="885th Bloodpack Division";
		baseWeapon="885th_DC15S_GL";
		scope=2;
		displayName="[885th] DC-15S MKII GL";
		model="\3AS\3AS_Weapons\Republic\DC15S\3AS_DC15S_GL.p3d";
		picture="\3AS\3AS_Weapons\Republic\DC15S\Data\UI\3as_dc15sgl.paa";
		UiPicture="\A3\weapons_f\data\UI\icon_regular_CA.paa";
		fireLightDiffuse[]={0.1,0.25,1};
		handAnim[]={"OFP2_ManSkeleton","3as\3AS_Weapons\Republic\DC15S\Data\Anim\New_DC15SGL_Handanim.rtm"};
		muzzles[]={"this","GL_1GL_F"};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 75;
			class CowsSlot: CowsSlot
			{	
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]={"ShadwCmpany_optic_Acog","3AS_Imp_Optic_1", "3AS_Imp_Optic_2", "3AS_Imp_Optic_3","3AS_optic_DC15C_F","3AS_Imp_Optic_E11",};
			};
			class MuzzleSlot : MuzzleSlot
			{	
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[] = {"ShadwCmpany_Suppresor_Module_DC19"};
			};
			class PointerSlot : PointerSlot
			{	
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};
	class 885th_DC15A : arifle_MX_Base_F
	{
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 610;
		author = "885th Bloodpack Division + IDA Dev Team";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[885th] DC-15A Rifle";
		descriptionShort = "Long range, slow rate of fire.";
		picture = "Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15A\DC15A_ui.paa";
		model = "Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15A\Model\IDA_DC15A.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "Indecisive_Armoury_Anims\REPUBLIC\DC15A.rtm"};
		ace_clearJamAction = "";
		reloadAction = "GestureReload_JLTS_DC15A";
		reloadTime = 1.0;
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\Blaster_reload_Vent.ogg", 1.5, 1, 100};
		recoil = "885_recoil_dc15a";
		magazines[] = {"885th_dc_cell_blue"};
		magazineWell[] = {"DC_energycells"};
		modes[] = {"Single", "FullAuto"};
		fireLightDiffuse[] = {0.1, 0.25, 1};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.13333334;
			dispersion = 0.00145;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 1.0;
			maxRange = 500;
			maxRangeProbab = 0.5;
		};
		class FullAuto : Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.10;
			dispersion = 0.00155;
			minRange = 0;
			minRangeProbab = 1.0;
			midRange = 500;
			midRangeProbab = 0.8;
			maxRange = 1000;
			maxRangeProbab = 0.6;
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"3AS_optic_reflex_DC15C", "885th_Optic_Scope_WestarM5", "ACE_optic_Hamr_2D", "3AS_Optic_DC15L"};
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
				compatibleItems[] = {"3AS_Bipod_VK38X_f"};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
	};
	class 885th_DC15BR : arifle_MX_Base_F
	{	
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 610;
		author = "885th Bloodpack Division + IDA Dev Team";
		scope = 2;
		inertia=0.80000001;
		dexterity=0.89999998;
		canShootInWater = 1;
		displayName = "[885th] DC-15BR";
		descriptionShort = "Modified DC-15A With Burst Fire, Mid to Long range.";
		picture="\ShadowLegion_Weapons\data\DC15\DC15A\UI\DC15A_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\DC15\DC15A\UI\DC15A_UI.paa";
		model="\ShadowLegion_Weapons\data\DC15\DC15A\Model\DC15_A.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "\ShadowLegion_Weapons\data\DC15\DC15A\Anim\ReloadBASE_DC15A.rtm"};
		ace_clearJamAction = "";
		reloadAction = "GestureReload_JLTS_DC15A";
		reloadTime = 1.0;
		reloadMagazineSound[] = {"\ShadowLegion_Weapons\data\reloads\sounds\Reload_1.ogg", 2, 1, 30};
		recoil = "885_recoil_dc15a";
		magazines[] = {"885th_DC15BR_battery_blue"};
		magazineWell[] = {};
		modes[] = {"Burst"};
		fireLightDiffuse[]={0,0,1};
		drySound[] = {"\ShadowLegion_Weapons\data\reloads\sounds\Empty_1.ogg", 5, 1, 10};
		muzzles[] = {"this","Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		class Burst: Mode_Burst
		{	
			burst = 4;
			reloadTime = 0.050000001;
			recoilProne = "recoil_single_prone_mx";
			dispersion = 0.00026000003;
			flash = "gunfire";
			flashSize = 0.1;
			soundBurst = 0;
			soundContinuous = 0;
			maxRange = 1000;
			maxRangeProbab = 0.00026000003;
			midRange = 500;
			midRangeProbab = 0.00026000003;
			minRange = 1;
			minRangeProbab = 0.5;
			sounds[] = {"StandardSound","SilencedSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		optics=1;
		useModelOptics=1;
		class OpticsModes
		{
			class DC15A_IronSights
			{
				opticsID=1;
				useModelOptics=0;
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				memoryPointCamera="eye";
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
				distanceZoomMin=200;
				distanceZoomMax=200;
				cameraDir="";
				visionMode[]={};
				opticsPPEffects[]=
				{
					"Default"
				};
			};
			class DC15A_Scope
			{
				opticsID=2;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsFlare=1;
				opticsDisablePeripherialVision=0;
				opticsZoomMin=0.22499999;
				opticsZoomMax=0.22499999;
				opticsZoomInit=0.22499999;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=200;
				distanceZoomMax=200;
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=97;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"ShadwCmpany_optic_Acog",
					"ShadwCmpany_Electroscope",
					"ShdwCmpny_Optic_A280Scope",
					"ShdwCmpny_Optic_LEScope_DC15A_mk2",
					"ShdwCmpny_Optic_LEScope_DC15A",
					"ShadwCmpany_Hybrid_Magnifier_Holo",
					
					"ShadwCmpany_773_Hybrid_Magnifier_Holo",
					"ShadwCmpany_773_Hybrid_Magnifier_Magnified"
					
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]=
				{
					"ShadwCmpany_Suppresor_Module_DC15"
				};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR",
					"ace_acc_pointer_red",
					"ace_acc_pointer_green"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				iconPosition[]={0.2,0.80000001};
				iconScale=0.30000001;
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]=
				{
					"ShdwCmpny_Bipod_Valken"
				};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName="Konec hlavne";
				effectName="RifleAssaultCloud";
				positionName="Usti hlavne";
			};
		};
	};
	class 885th_DC15AMKII_Base_F: Rifle_Base_F
	{
		author="885th Bloodpack Division";
		magazines[]={"885th_dc_cell_blue"};
		magazineWell[]={"DC_energycells"};
		magazineReloadSwitchPhase=0.5;
		reloadAction="GestureReloadMX";
		recoil="3AS_recoil_dc15a";
		maxZeroing=1000;
		discreteDistanceInitIndex=0;
		maxRecoilSway=0.0125;
		swayDecaySpeed=1.25;
		inertia=0.60000002;
		aimTransitionSpeed=0.80000001;
		dexterity=1.4;
		initSpeed=-1;
		class GunParticles: GunParticles
		{
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=90;
			class MuzzleSlot: 3AS_MuzzleSlot_DC15A
			{
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
			};
			class CowsSlot: 3AS_CowsSlot_DC15A
			{
				iconPosition[]={0.5,0.34999999};
				iconScale=0.2;
			};
			class UnderBarrelSlot: 3AS_UnderBarrelSlot_DC15A
			{
				iconPosition[]={0.23999999,0.69999999};
				iconScale=0.30000001;
			};
		};
		distanceZoomMin=300;
		distanceZoomMax=300;
		descriptionShort="";
		handAnim[]={"OFP2_ManSkeleton","3as\3AS_Weapons\Republic\DC15A\Data\Anim\New_DC15a_Handanim.rtm"};
		modes[]={"Single","single_medium_optics1","single_far_optics2"};
		class Burst: Mode_Burst
		{
			burst=3;
			reloadTime=0.050000001;
			dispersion=0.00066000002;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=50;
			midRangeProbab=0.69999999;
			maxRange=100;
			maxRangeProbab=0.1;
			soundContinuous=0;
			soundBurst=0;
			sounds[]={"StandardSound","SilencedSound"};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_DC15A_Shot_SoundSet"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.13330001;
			dispersion=0.00066000002;
			minRange=2;
			minRangeProbab=0.5;
			midRange=250;
			midRangeProbab=0.69999999;
			maxRange=450;
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
				soundSetShot[]=
				{
					"3AS_DC15A_Shot_SoundSet"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class Burst_medium: Burst
		{
			showToPlayer=0;
			minRange=2;
			minRangeProbab=0.5;
			midRange=75;
			midRangeProbab=0.69999999;
			maxRange=100;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
		};
		class single_medium_optics1: Single
		{
			showToPlayer=0;
			requiredOpticType=1;
			minRange=2;
			minRangeProbab=0.2;
			midRange=450;
			midRangeProbab=0.69999999;
			maxRange=650;
			maxRangeProbab=0.2;
			aiRateOfFire=6;
			aiRateOfFireDistance=600;
		};
		class single_far_optics2: Single
		{
			showToPlayer=0;
			requiredOpticType=2;
			minRange=100;
			minRangeProbab=0.2;
			midRange=550;
			midRangeProbab=0.69999999;
			maxRange=800;
			maxRangeProbab=0.050000001;
			aiRateOfFire=8;
			aiRateOfFireDistance=800;
		};
		class GL_3GL_F: UGL_F
		{
			displayName="$STR_A3_cfgweapons_3gl0";
			descriptionShort="$STR_A3_cfgweapons_3gl1";
			useModelOptics=0;
			useExternalOptic=0;
			modes[]=
			{
				"Fire"
			};
			class Fire: Mode_SemiAuto
			{
				sounds[]=
				{
					"StandardSound"
				};
				class BaseSoundModeType
				{
					weaponSoundEffect="";
					closure1[]={};
					closure2[]={};
					soundClosure[]={};
				};
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
			magazines[]=
			{
				"3AS_3UGL_MK54_HE_shell"
			};
			magazineWell[]=
			{
				"UGL_40x36",
				"3UGL_40x36",
				"3AS_3UGL_Magwell"
			};
			cameraDir="OP_look";
			discreteDistance[]={50,75,100,150,200,250,300,350,400};
			discreteDistanceCameraPoint[]=
			{
				"OP_eye_50",
				"OP_eye_75",
				"OP_eye_100",
				"OP_eye_150",
				"OP_eye_200",
				"OP_eye_250",
				"OP_eye_300",
				"OP_eye_350",
				"OP_eye_400"
			};
			discreteDistanceInitIndex=1;
			reloadAction="GestureReloadMXUGL";
			reloadMagazineSound[]=
			{
				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Mx_UGL_reload",
				1,
				1,
				10
			};
		};
		aiDispersionCoefY=6;
		aiDispersionCoefX=4;
		modelOptics="3AS\3AS_Weapons\Data\3AS_2D_Optic.p3d";
		class OpticsModes
		{
			class Ironsights
			{
				opticsID=1;
				useModelOptics=0;
				opticsFlare=0;
				opticsPPEffects[]=
				{
					"Default"
				};
				opticsDisablePeripherialVision=0;
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=100;
				distanceZoomMax=100;
			};
		};
		caseless[]=
		{
			"",
			1,
			1,
			1
		};
		soundBullet[]=
		{
			"caseless",
			1
		};
		drySound[]=
		{
			"\3AS\3AS_Main\Sounds\Blaster_empty",
			2,
			1,
			20
		};
		reloadMagazineSound[]=
		{
			"\3AS\3AS_Main\Sounds\DC15A\DC15aReload",
			1,
			1,
			30
		};
		hiddenSelections[]=
		{
			"holo_reticle"
		};
		hiddenSelectionsTextures[]=
		{
			"\3AS\3AS_Weapons\Republic\DC15A\Data\reticle_DC15A_ca.paa"
		};
		ace_overheating_mrbs=3000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=0.75;
	};
	class 885th_DC15AMKII_F: 885th_DC15AMKII_Base_F
	{
		author="885th Bloodpack Division";
		baseWeapon="885th_DC15AMKII_F";
		scope=2;
		displayName="[885th] DC-15A MkII";
		model="\3AS\3AS_Weapons\Republic\DC15A\3AS_DC15A_F.p3d";
		picture="\3AS\3AS_Weapons\Republic\DC15A\Data\UI\3as_dc15a.paa";
		UiPicture="\A3\weapons_f\data\UI\icon_regular_CA.paa";
		muzzles[] = {"this","Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		class OpticsModes: OpticsModes
		{
			class Ironsights: Ironsights
			{
			};
			class Scope: Ironsights
			{
				opticsID=2;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticsBlur5"
				};
				opticsDisablePeripherialVision=0.67000002;
				opticsZoomMin="0.25 / 2";
				opticsZoomMax="0.25 / 2";
				opticsZoomInit="0.25 / 2";
				memoryPointCamera="opticView";
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				opticsFlare="true";
				distanceZoomMin=100;
				distanceZoomMax=100;
				cameraDir="";
			};
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 75;
			class CowsSlot: CowsSlot
			{	
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]={"ShadwCmpany_optic_Acog","3AS_optic_DC15LE_F", "ShdwCmpny_Optic_LEScope_DC15A"};
			};
			class MuzzleSlot : MuzzleSlot
			{	
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[] = {"ShadwCmpany_Suppresor_Module_DC15","3AS_muzzle_DC15LE_F"};
			};
			class PointerSlot : PointerSlot
			{	
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};
	class 885th_DC15A_LE: 885th_DC15AMKII_F
	{
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="3AS_optic_DC15LE_F";
			};
			class LinkedItemsMuzzle
			{
				slot="MuzzleSlot";
				item="3AS_muzzle_DC15LE_F";
			};
		};
	};
	class 885th_DC15AMKII_GL: 885th_DC15AMKII_Base_F
	{
		author="885th Bloodpack Division";
		baseWeapon="885th_DC15AMKII_GL";
		scope=2;
		displayName="[885th] DC-15A MkII GL";
		model="\3AS\3AS_Weapons\Republic\DC15A\3AS_DC15A_GL.p3d";
		picture="\3AS\3AS_Weapons\Republic\DC15A\Data\UI\3as_dc15agl.paa";
		UiPicture="\A3\weapons_f\data\UI\icon_regular_CA.paa";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"3as\3AS_Weapons\Republic\DC15A\Data\Anim\New_DC15aGL_Handanim.rtm"
		};
		muzzles[]=
		{
			"this",
			"GL_3GL_F"
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 75;
			class CowsSlot: CowsSlot
			{	
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]={"ShadwCmpany_optic_Acog","3AS_optic_DC15LE_F", "ShdwCmpny_Optic_LEScope_DC15A"};
			};
			class MuzzleSlot : MuzzleSlot
			{	
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[] = {"ShadwCmpany_Suppresor_Module_DC15","3AS_muzzle_DC15LE_F"};
			};
			class PointerSlot : PointerSlot
			{	
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};
	class 885th_DCP90 : SMG_03C_TR_Khaki
	{
		access = 3;
		author = "AifeSupport";
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 264;
		scope = 0;
		displayName = "[885th] DC-P90 Carbine";
		descriptionShort = "If lost please return to 2901 Lotho";
		magazines[] = {"885th_dc_cell_blue"};
		magazineWell[] = {"DC_energycells"};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\885_Weapons\textures\body_pink_co.paa"};
		muzzles[] = {"this", "Stun"};
		fireLightDiffuse[]={0.1,0.25,1};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		class Stun : 885th_Stun_rifle
		{
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 5;
			class CowsSlot : CowsSlot{};
			class MuzzleSlot : MuzzleSlot{};
			class PointerSlot : PointerSlot{};
			class UnderBarrelSlot : UnderBarrelSlot{};
		};
	};
	class 885th_Command_DC15AUGL: JLTS_DC15A_ugl
	{
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 610;
		author = "885th Bloodpack Division";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[885th] DC15A-X Heavy Blaster Rifle";
		descriptionShort = "Mid to Longe, slow rate of fire. Command Variant";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_ugl_ui_ca.paa";
		model="\MRC\JLTS\weapons\DC15A\DC15A_ugl.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "\MRC\JLTS\weapons\DC15A\anims\DC15A_handanim.rtm"};
		ace_clearJamAction = "";
		reloadAction = "GestureReload_JLTS_DC15A";
		reloadTime = 1.0;
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\Blaster_reload_Vent.ogg", 1.5, 1, 100};
		recoil = "recoil_akm";
		magazines[] = {"885th_dc_cell_blue_apex"};
		magazineWell[] = {};
		modes[] = {"Single", "FullAuto"};
		fireLightDiffuse[] = {0.1, 0.25, 1};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		muzzles[] = {"this","UGL"};
		class UGL: UGL_F
		{
			displayName="Amplified High Explosive Launcher";
			descriptionShort="Amp. HEL";
			magazines[] = {"885th_coil_blue_high","885th_MPL_3rnd_HE_Grenade"};
			magazineWell[] = {};
			useModelOptics=0;
			useExternalOptic=0;
			modes[]=
			{
				"Fire"
			};
			class Fire: Mode_SemiAuto
			{
				sounds[]=
				{
					"StandardSound"
				};
				class BaseSoundModeType
				{
					weaponSoundEffect="";
					closure1[]={};
					closure2[]={};
					soundClosure[]={};
				};
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
			cameraDir="OP_look";
			discreteDistance[]={75,100,200,300,400};
			discreteDistanceInitIndex=1;
			discreteDistanceCameraPoint[]=
			{
				"OP_eye"
			};
		};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				begin1[]=
				{
					"885_Sounds\Command DC15.ogg",
					1.9952624,
					1,
					900
				};
				soundBegin[] = {"begin1", 0.2};
			};
			reloadTime = 0.14;
			dispersion = 0.00195;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 1.0;
			maxRange = 600;
			maxRangeProbab = 0.5;
		};
		class FullAuto : Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				begin1[]=
				{
					"885_Sounds\Command DC15.ogg",
					1.9952624,
					1,
					900
				};
				soundBegin[] = {"begin1", 0.2};
			};
			reloadTime = 0.12;
			dispersion = 0.00205;
			minRange = 0;
			minRangeProbab = 1.0;
			midRange = 500;
			midRangeProbab = 0.8;
			maxRange = 1000;
			maxRangeProbab = 0.6;
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot : MuzzleSlot
			{	
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[] = {"ShdwCmpny_Muzzle_LE_DC15A_Unsur"};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {"acc_flashlight","ShdwCmpny_Light_MPD","ShdwCmpny_IR_MPD"};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
	};
	class 885th_DX36C_Base_F: Rifle_Base_F
	{
		scope=0;
		canShootInWater=1;
		author="Antauri + ONI & Chief33";
		_generalMacro="885th_DX36C_Base_F";
		descriptionShort="Mid to Long Range. Heavy Hitting Experimental Rifle";
		magazines[]= {"885th_DX36C_battery_yellow_high"};
		recoil="recoil_akm";
		maxZeroing=1000;
		handAnim[]= {"OFP2_ManSkeleton","885_Weapons\DX36C\anim\ReloadBASE_DX36C.rtm"};
		reloadAction="GestureReloadSPAR_01";
		fireLightDuration=0.050000001;
		fireLightIntensity=0.40000001;
		fireLightDiffuse[]={1,1,0};
		fireLightAmbient[]={0,0,0};
		muzzles[] = {"this", "885TH_DX36C_HE"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: MuzzleSlot_65
			{
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]={"ACE_muzzle_mzls_L","ShadwCmpany_Suppresor_Module_DC19"};
			};
			class CowsSlot: CowsSlot_Rail
			{
				iconPosition[]={0.44999999,0.28};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]={"ShadwCmpany_optic_Acog","ShdwCmpny_Optic_LEScope_DC15A","3AS_optic_DC15L_F","optic_MRCO","ShdwCmpny_Optic_Valken","ShadwCmpany_optic_Reflex_Mk1_Alt2","ShadwCmpany_Hybrid_Magnifier_Holo","ShadwCmpany_773_Hybrid_Magnifier_Holo"};
			};
			class PointerSlot: PointerSlot_Rail
			{
				iconPosition[]={0.34999999,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR",
					"ace_acc_pointer_red",
					"ace_acc_pointer_green"
				};
			};
		};
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
		distanceZoomMin=300;
		distanceZoomMax=300;
		selectionFireAnim="zasleh";
		flash="gunfire";
		flashSize=3;
		modes[]=
		{
			"Single",
			"Burst",
			"FullAuto",
			"single_medium_optics1",
			"single_far_optics2",
			"fullauto_medium"
		};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.1;
			dispersion=0.00085000001;
			minRange=2;
			minRangeProbab=0.5;
			midRange=500;
			midRangeProbab=0.69999999;
			maxRange=1000;
			maxRangeProbab=0.2;
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				begin1[]={"885_Weapons\DX36C\DX36C.V2.ogg",1.25, 1, 1800};
				begin2[] = {"885_Weapons\DX36C\DX36C.V2.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Weapons\DX36C\DX36C.V2.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Weapons\DX36C\DX36C.V2.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Weapons\DX36C\DX36C.V2.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"\ShadowLegion_Weapons\data\A300\A300_Silenced_Auto_1.ogg",1.9952624,1,200};
				soundBegin[]={"begin1",0.1};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class Burst: Mode_Burst
		{
			reloadTime=0.08;
			dispersion=0.00106;
			minRange=2;
			minRangeProbab=0.89999998;
			midRange=500;
			midRangeProbab=0.69999999;
			maxRange=1000;
			maxRangeProbab=0.1;
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
				begin1[]={"885_Weapons\DX36C\DX36C.V2.ogg",1.25, 1, 1800};
				begin2[] = {"885_Weapons\DX36C\DX36C.V2.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Weapons\DX36C\DX36C.V2.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Weapons\DX36C\DX36C.V2.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Weapons\DX36C\DX36C.V2.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"\ShadowLegion_Weapons\data\A300\A300_Silenced_Auto_1.ogg",1.9952624,1,200};
				soundBegin[]={"begin1",0.1};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class FullAuto: Mode_FullAuto
		{
			reloadTime=0.11;
			dispersion=0.00145;
			minRange=2;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.050000001;
			aiRateOfFire=1e-006;
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				begin1[]={"885_Weapons\DX36C\DX36C.V2.ogg",1.25, 1, 1800};
				begin2[] = {"885_Weapons\DX36C\DX36C.V2.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Weapons\DX36C\DX36C.V2.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Weapons\DX36C\DX36C.V2.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Weapons\DX36C\DX36C.V2.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"\ShadowLegion_Weapons\data\A300\A300_Silenced_Auto_1.ogg",1.9952624,1,200};
				soundBegin[]={"begin1",0.1};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class fullauto_medium: FullAuto
		{
			showToPlayer=0;
			burst=3;
			minRange=2;
			minRangeProbab=0.5;
			midRange=75;
			midRangeProbab=0.69999999;
			maxRange=150;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=200;
		};
		class single_medium_optics1: Single
		{
			requiredOpticType=1;
			showToPlayer=0;
			minRange=2;
			minRangeProbab=0.2;
			midRange=450;
			midRangeProbab=0.69999999;
			maxRange=600;
			maxRangeProbab=0.2;
			aiRateOfFire=6;
			aiRateOfFireDistance=600;
		};
		class single_far_optics2: single_medium_optics1
		{
			requiredOpticType=2;
			minRange=100;
			minRangeProbab=0.1;
			midRange=450;
			midRangeProbab=0.60000002;
			maxRange=800;
			maxRangeProbab=0.050000001;
			aiRateOfFire=8;
			aiRateOfFireDistance=800;
		};
		class 885TH_DX36C_HE: Rifle_Long_Base_F
		{
			displayName="Explosive Battery";
			descriptionShort="DX36 Explosive Battery";
			useModelOptics=1;
			useExternalOptic=1;
			maxZeroing=1800;
			maxRecoilSway=0.029999999;
			swayDecaySpeed=1.25;
			discreteDistance[]={200,300,400,500,600};
			discreteDistanceInitIndex=1;
			distanceZoomMin=100;
			distanceZoomMax=350;
			cursor="srifle";
			inertia=1.2;
			aimTransitionSpeed=0.5;
			dexterity=1;
			magazines[]=
			{
				"885th_DX36C_he_battery_yellow"
			};
			magazineWell[]={};
			class GunParticles: GunParticles
			{
				class SecondEffect
				{
					positionName="Nabojnicestart";
					directionName="Nabojniceend";
					effectName="CaselessAmmoCloud";
				};
			};
			selectionFireAnim="zasleh";
			flash="gunfire";
			flashSize=3;
			modes[]=
			{
				"Single"
			};
			reloadMagazineSound[]=
			{
				"885_Weapons\DX36C\reload.ogg",
				2,
				1,
				30
			};
			drySound[]=
			{
				"885_Weapons\DX36C\drysound.ogg",
				5,
				1,
				20
			};
			class Single: Mode_SemiAuto
			{
				sounds[]=
				{
					"StandardSound"
				};
				class BaseSoundModeType
				{
					begin1[]=
					{
					"\Indecisive_Armoury_Sounds\Imperial\E11D.ogg",
					1.25,
					1,
					1800
					};
					begin2[]=
					{
					"\Indecisive_Armoury_Sounds\Imperial\E11D.ogg",
					1.25,
					1.025,
					1800
					};
					begin3[]=
					{	
					"\Indecisive_Armoury_Sounds\Imperial\E11D.ogg",
					1.25,
					0.94999999,
					1800
					};
					begin4[]=
					{
					"\Indecisive_Armoury_Sounds\Imperial\E11D.ogg",
					1.25,
					1.05,
					1800
					};
					begin5[]=
					{
					"\Indecisive_Armoury_Sounds\Imperial\E11D.ogg",
					1.25,
					0.89999998,
					1800
					};
					soundBegin[]=
					{
					"begin1",
					0.2,
					"begin2",
					0.2,
					"begin3",
					0.2,
					"begin4",
					0.2,
					"begin5",
					0.2
					};
				};
				class StandardSound: BaseSoundModeType
				{
					closure1[]=
					{
						"885_Weapons\DX36C\DX36C_Cooldown_beep.ogg",
						2.2,
						1,
						40
					};
					soundClosure[]=
					{
						"closure1",
						0.1
					};
				};
				drySound[]=
				{
					"885_Weapons\DX36C\drysound.ogg",
					5,
					1,
					20
				};
				class SoundTails
				{
					class TailInterior
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_interior",
							1,
							1,
							300
						};
						frequency=1;
						volume="interior";
					};
					class TailTrees
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_trees",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_forest",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*forest";
					};
					class TailMeadows
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_meadows",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_houses",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*houses";
					};
				};
				reloadTime=1.5;
				dispersion=0.00015000001;
				recoil="recoil_single_gm6";
				recoilProne="recoil_single_prone_gm6";
				minRange=2;
				minRangeProbab=0.5;
				midRange=150;
				midRangeProbab=0.69999999;
				maxRange=450;
				maxRangeProbab=0.30000001;
				aiRateOfFire=3;
				aiRateOfFireDistance=500;
			};
		};
		aiDispersionCoefY=6;
		aiDispersionCoefX=4;
		caseless[]=
		{
			"",
			1,
			1,
			1
		};
		soundBullet[]=
		{
			"caseless",
			1
		};
		drySound[]=
		{
			"885_Weapons\DX36C\drysound.ogg",
			5,
			1,
			20
		};
		reloadMagazineSound[]=
		{
			"885_Weapons\DX36C\reload.ogg",
			2,
			1,
			30
		};
		ace_overheating_mrbs=3000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=0.75;
	};
	class 885th_DX36C_F: 885th_DX36C_Base_F
	{
		author="Antauri + ONI & Chief33__(nEw)";
		_generalMacro="885th_DX36C_F";
		scope=2;
		displayName="[885th] DX36C";
		model="885_Weapons\DX36C\Model\DX36C.p3d";
		picture="885_Weapons\UI\885_dX36.paa";
		UiPicture="";
		inertia=0.40000001;
		aimTransitionSpeed=1;
		dexterity=1.6;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=100;
			class UnderBarrelSlot: UnderBarrelSlot_rail
			{
				iconPosition[]={0.2,0.80000001};
				iconScale=0.30000001;
			};
		};
	};	
	class 885th_WestarM5_F: Rifle_Base_F
	{	
		scope=2;
		displayName="[885th] Westar-M5";
		model="3AS\3AS_Weapons\WestarM5\3AS_Westar_M5_F.p3d";
		picture="\3AS\3AS_Weapons\WestarM5\Data\UI\3as_westar.paa";
		UiPicture="\ShadowLegion_Weapons\data\WestarM5\UI\WestarM5_UI.paa";
		weaponInfoType="RscWeaponZeroing";
		author="885th Bloodpack Division";
		magazines[]=
		{
			"885th_dc_cell_blue",
			"885th_dc_cell_blue_high",
			"885th_dc_cell_blue_amp"
		};
		reloadAction="GestureReloadMX";
		magazineReloadSwitchPhase=0.40000001;
		discreteDistanceInitIndex=0;
		recoil="recoil_mx";
		maxRecoilSway=0.0125;
		swayDecaySpeed=1.25;
		inertia=0.5;
		dexterity=1.5;
		initSpeed=-1;
		maxZeroing=100;
		canShootInWater=1;
		class OpticsModes
		{
			class Ironsights
			{
				opticsID=1;
				useModelOptics=0;
				opticsFlare="true";
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticsBlur5"
				};
				opticsDisablePeripherialVision=0;
				opticsZoomMin=0.375;
				opticsZoomMax=1.1;
				opticsZoomInit=0.75;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=100;
				distanceZoomMax=100;
			};
			class Scope: Ironsights
			{
				opticsID=2;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsFlare=1;
				opticsDisablePeripherialVision=0;
				opticsZoomMin=0.22499999;
				opticsZoomMax=0.22499999;
				opticsZoomInit=0.22499999;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=200;
				distanceZoomMax=200;
			};
		};
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]=
				{
					"885th_Optic_Scope_WestarM5",
					"ShadwCmpany_optic_Reflex_Mk1_Alt1",
					"ShadwCmpany_optic_e11",
					"3AS_Imp_Optic_2",
					"3AS_Imp_Optic_3",
					"ShadwCmpany_Hybrid_Magnifier_Holo",
					"ShadwCmpany_Hybrid_Magnifier_Magnified"
				};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR",
					"ace_acc_pointer_red",
					"ace_acc_pointer_green"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]={};
			};
			class MuzzleSlot: MuzzleSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]=
				{
					"ShadwCmpany_Suppresor_Module_DC15"
				};
			};
			mass=65;
		};
		opticsZoomMin=0.25;
		opticsZoomMax=1.25;
		opticsZoomInit=0.75;
		distanceZoomMin=400;
		distanceZoomMax=400;
		descriptionShort="WestarM5";
		muzzles[] = {"this","Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\3AS\3AS_Weapons\WestarM5\Data\Anim\WestarM5_handanim.rtm"
		};
		selectionFireAnim="zasleh";
		flash="gunfire";
		flashSize=3;
		modes[]=
		{
			"Single",
			"Burst",
			"FullAuto",
			"fullauto_medium",
			"single_medium_optics1",
			"single_far_optics2"
		};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.0705;
			dispersion=0.00026000003;
			minRange=2;
			minRangeProbab=0.5;
			midRange=200;
			midRangeProbab=0.69999999;
			maxRange=400;
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
				begin1[] = {"885_Sounds\WestarM5.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\WestarM5.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\WestarM5.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\WestarM5.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\WestarM5.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\WestarM5.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class Burst: Mode_Burst
		{
			reloadTime=0.0705;
			dispersion=0.00026000003;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
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
				begin1[] = {"885_Sounds\WestarM5.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\WestarM5.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\WestarM5.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\WestarM5.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\WestarM5.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\WestarM5.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class FullAuto: Mode_FullAuto
		{
			reloadTime=0.0705;
			dispersion=0.00036000001;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
			aiRateOfFire=1e-006;
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"885_Sounds\WestarM5.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\WestarM5.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\WestarM5.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\WestarM5.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\WestarM5.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\WestarM5.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class fullauto_medium: FullAuto
		{
			showToPlayer=0;
			burst=3;
			aiBurstTerminable=1;
			minRange=2;
			minRangeProbab=0.5;
			midRange=75;
			midRangeProbab=0.69999999;
			maxRange=150;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=200;
		};
		class single_medium_optics1: Single
		{
			requiredOpticType=1;
			showToPlayer=0;
			minRange=2;
			minRangeProbab=0.2;
			midRange=450;
			midRangeProbab=0.69999999;
			maxRange=600;
			maxRangeProbab=0.2;
			aiRateOfFire=6;
			aiRateOfFireDistance=600;
		};
		class single_far_optics2: single_medium_optics1
		{
			requiredOpticType=2;
			showToPlayer=0;
			minRange=100;
			minRangeProbab=0.1;
			midRange=500;
			midRangeProbab=0.60000002;
			maxRange=700;
			maxRangeProbab=0.050000001;
			aiRateOfFire=8;
			aiRateOfFireDistance=700;
		};
		aiDispersionCoefY=6;
		aiDispersionCoefX=4;
		caseless[]=
		{
			"",
			1,
			1,
			1
		};
		soundBullet[]=
		{
			"caseless",
			1
		};
		drySound[]=
		{
			"\3AS\3AS_Main\Sounds\Blaster_empty",
			2,
			1,
			20
		};
		reloadMagazineSound[]=
		{
			"\3AS\3AS_Main\Sounds\Old\Blaster_reload.wss",
			1,
			1,
			30
		};
		ace_overheating_mrbs=3000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=0.75;
	};
	class 885th_WestarM5_GL: Rifle_Base_F
	{	
		scope=2;
		displayName="[885th] Westar-M5 GL";
		model="3AS\3AS_Weapons\WestarM5\3AS_Westar_M5_GL.p3d";
		picture="\3AS\3AS_Weapons\WestarM5\Data\UI\3as_westargl.paa";
		weaponInfoType="RscWeaponZeroing";
		author="885th Bloodpack Division";
		magazines[]=
		{
			"885th_dc_cell_blue",
			"885th_dc_cell_blue_high",
			"885th_dc_cell_blue_amp"
		};
		muzzles[] = {"this","885th_WestarM5_underbarrel"};
		reloadAction="GestureReloadMX";
		magazineReloadSwitchPhase=0.40000001;
		discreteDistanceInitIndex=0;
		recoil="recoil_mx";
		maxRecoilSway=0.0125;
		swayDecaySpeed=1.25;
		inertia=0.5;
		dexterity=1.5;
		initSpeed=-1;
		maxZeroing=100;
		canShootInWater=1;
		class OpticsModes
		{
			class Ironsights
			{
				opticsID=1;
				useModelOptics=0;
				opticsFlare="true";
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticsBlur5"
				};
				opticsDisablePeripherialVision=0;
				opticsZoomMin=0.375;
				opticsZoomMax=1.1;
				opticsZoomInit=0.75;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=100;
				distanceZoomMax=100;
			};
			class Scope: Ironsights
			{
				opticsID=2;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsFlare=1;
				opticsDisablePeripherialVision=0;
				opticsZoomMin=0.22499999;
				opticsZoomMax=0.22499999;
				opticsZoomInit=0.22499999;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=200;
				distanceZoomMax=200;
			};
		};
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]=
				{
					"885th_Optic_Scope_WestarM5",
					"ShadwCmpany_optic_Reflex_Mk1_Alt1",
					"ShadwCmpany_optic_e11",
					"3AS_Imp_Optic_2",
					"3AS_Imp_Optic_3",
					"ShadwCmpany_Hybrid_Magnifier_Holo",
					"ShadwCmpany_Hybrid_Magnifier_Magnified"
				};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR",
					"ace_acc_pointer_red",
					"ace_acc_pointer_green"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]={};
			};
			class MuzzleSlot: MuzzleSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]=
				{
					"ShadwCmpany_Suppresor_Module_DC15"
				};
			};
			mass=65;
		};
		opticsZoomMin=0.25;
		opticsZoomMax=1.25;
		opticsZoomInit=0.75;
		distanceZoomMin=400;
		distanceZoomMax=400;
		descriptionShort="WestarM5";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\3AS\3AS_Weapons\WestarM5\Data\Anim\WestarM5_handanim.rtm"
		};
		selectionFireAnim="zasleh";
		flash="gunfire";
		flashSize=3;
		modes[]=
		{
			"Single",
			"Burst",
			"FullAuto",
			"fullauto_medium",
			"single_medium_optics1",
			"single_far_optics2"
		};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.0705;
			dispersion=0.00026000003;
			minRange=2;
			minRangeProbab=0.5;
			midRange=200;
			midRangeProbab=0.69999999;
			maxRange=400;
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
				begin1[] = {"885_Sounds\WestarM5.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\WestarM5.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\WestarM5.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\WestarM5.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\WestarM5.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\WestarM5.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class Burst: Mode_Burst
		{
			reloadTime=0.0705;
			dispersion=0.00026000003;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
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
				begin1[] = {"885_Sounds\WestarM5.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\WestarM5.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\WestarM5.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\WestarM5.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\WestarM5.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\WestarM5.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class FullAuto: Mode_FullAuto
		{
			reloadTime=0.0705;
			dispersion=0.00036000001;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
			aiRateOfFire=1e-006;
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"885_Sounds\WestarM5.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\WestarM5.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\WestarM5.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\WestarM5.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\WestarM5.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\WestarM5.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class fullauto_medium: FullAuto
		{
			showToPlayer=0;
			burst=3;
			aiBurstTerminable=1;
			minRange=2;
			minRangeProbab=0.5;
			midRange=75;
			midRangeProbab=0.69999999;
			maxRange=150;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=200;
		};
		class single_medium_optics1: Single
		{
			requiredOpticType=1;
			showToPlayer=0;
			minRange=2;
			minRangeProbab=0.2;
			midRange=450;
			midRangeProbab=0.69999999;
			maxRange=600;
			maxRangeProbab=0.2;
			aiRateOfFire=6;
			aiRateOfFireDistance=600;
		};
		class single_far_optics2: single_medium_optics1
		{
			requiredOpticType=2;
			showToPlayer=0;
			minRange=100;
			minRangeProbab=0.1;
			midRange=500;
			midRangeProbab=0.60000002;
			maxRange=700;
			maxRangeProbab=0.050000001;
			aiRateOfFire=8;
			aiRateOfFireDistance=700;
		};
		class 885th_WestarM5_underbarrel: UGL_F
		{
			displayName="[885th] Underbarrel";
			descriptionShort="GL for the WestarM5 Platform";
			useModelOptics=0;
			useExternalOptic=0;
			magazines[]=
			{
				"3AS_6Rnd_HE_Grenade_shell"
			};
			magazineWell[]=
			{
				"3AS_3UGL_Magwell"
			};
			modes[]=
			{
				"Fire"
			};
			class Fire: Mode_SemiAuto
			{
				sounds[]=
				{
					"StandardSound"
				};
				class BaseSoundModeType
				{
					weaponSoundEffect="";
					closure1[]={};
					closure2[]={};
					soundClosure[]={};
				};
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
			cameraDir="OP_look";
			discreteDistance[]={50,75,100,150,200,250,300,350,400};
			discreteDistanceCameraPoint[]=
			{
				"OP_eye_50",
				"OP_eye_75",
				"OP_eye_100",
				"OP_eye_150",
				"OP_eye_200",
				"OP_eye_250",
				"OP_eye_300",
				"OP_eye_350",
				"OP_eye_400"
			};
			discreteDistanceInitIndex=1;
			reloadAction="GestureReloadTrgUGL";
			reloadMagazineSound[]=
			{
				"A3\Sounds_F\arsenal\weapons\Rifles\TRG20\TRG20_UGL_reload",
				0.79432821,
				1,
				10
			};
		};
		aiDispersionCoefY=6;
		aiDispersionCoefX=4;
		caseless[]=
		{
			"",
			1,
			1,
			1
		};
		soundBullet[]=
		{
			"caseless",
			1
		};
		drySound[]=
		{
			"\3AS\3AS_Main\Sounds\Blaster_empty",
			2,
			1,
			20
		};
		reloadMagazineSound[]=
		{
			"\3AS\3AS_Main\Sounds\Old\Blaster_reload.wss",
			1,
			1,
			30
		};
		ace_overheating_mrbs=3000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=0.75;
	};
	class 885th_WestarM5MKII_Base_F: Rifle_Base_F
	{
		author="885th Bloodpack Division + SL Mod Dev Team";
		magazines[] = {"885th_Westarm5mkii_Ap_cell_blue","885th_dc_cell_blue_low","885th_dc_cell_blue"};
		reloadAction="GestureReloadMX";
		magazineReloadSwitchPhase=0.40000001;
		discreteDistanceInitIndex=0;
		recoil="885_recoil_dc15a";
		maxRecoilSway=0.0125;
		swayDecaySpeed=1.25;
		inertia=0.5;
		dexterity=1.5;
		initSpeed=-1;
		maxZeroing=100;
		canShootInWater=1;
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]=
				{
					"ShadwCmpany_optic_Reflex_Mk1_Alt2",
					"ShadwCmpany_optic_Acog",
					"ShdwCmpny_Optic_Scope_WestarM5",
					"ShadwCmpany_Hybrid_Magnifier_Holo",
					
					"ShadwCmpany_773_Hybrid_Magnifier_Holo",
					"ShadwCmpany_773_Hybrid_Magnifier_Magnified"
				};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR",
					"ace_acc_pointer_red",
					"ace_acc_pointer_green"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]={};
			};
			class MuzzleSlot: MuzzleSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]=
				{
					"ShadwCmpany_Suppresor_WestarM5",
					"885th_Muzzle_Module_Westarm5MKII"
				};
			};
		};
		opticsZoomMin=0.25;
		opticsZoomMax=1.25;
		opticsZoomInit=0.75;
		distanceZoomMin=400;
		distanceZoomMax=400;
		descriptionShort="WestarM5";
		selectionFireAnim="zasleh";
		flash="gunfire";
		flashSize=3;
		modes[]=
		{
			"Single",
			"FullAuto",
			"fullauto_medium",
			"single_medium_optics1",
			"single_far_optics2"
		};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.06;
			dispersion=0.00026000003;
			minRange=2;
			minRangeProbab=0.5;
			midRange=200;
			midRangeProbab=0.69999999;
			maxRange=400;
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
				begin1[] = {"885_Sounds\WestarM5MKII.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\WestarM5MKII.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\WestarM5MKII.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\WestarM5MKII.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\WestarM5MKII.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\WestarM5MKII.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class FullAuto: Mode_FullAuto
		{
			reloadTime=0.06;
			dispersion=0.00036000001;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
			aiRateOfFire=1e-006;
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"885_Sounds\WestarM5MKII.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\WestarM5MKII.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\WestarM5MKII.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\WestarM5MKII.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\WestarM5MKII.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\WestarM5MKII.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class fullauto_medium: FullAuto
		{
			showToPlayer=0;
			burst=3;
			aiBurstTerminable=1;
			minRange=2;
			minRangeProbab=0.5;
			midRange=75;
			midRangeProbab=0.69999999;
			maxRange=150;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=200;
		};
		class single_medium_optics1: Single
		{
			requiredOpticType=1;
			showToPlayer=0;
			minRange=2;
			minRangeProbab=0.2;
			midRange=450;
			midRangeProbab=0.69999999;
			maxRange=600;
			maxRangeProbab=0.2;
			aiRateOfFire=6;
			aiRateOfFireDistance=600;
		};
		class single_far_optics2: single_medium_optics1
		{
			requiredOpticType=2;
			showToPlayer=0;
			minRange=100;
			minRangeProbab=0.1;
			midRange=500;
			midRangeProbab=0.60000002;
			maxRange=700;
			maxRangeProbab=0.050000001;
			aiRateOfFire=8;
			aiRateOfFireDistance=700;
		};
		aiDispersionCoefY=6;
		aiDispersionCoefX=4;
		caseless[]={"",1,1,1};
		soundBullet[]={"caseless",1};
		drySound[]={"\ShadowLegion_Weapons\data\reloads\sounds\Empty_1.ogg",5,1,20};
		reloadMagazineSound[]={"\ShadowLegion_Weapons\data\reloads\sounds\Reload_1.ogg",2,1,30};
	};
	class 885th_WestarM5MKII_F: 885th_WestarM5MKII_Base_F
	{
		scope=2;
		displayName="[885th] Westar-M5 MKII";
		model="\ShadowLegion_Weapons\data\WestarM5\model\WestarM5_F.p3d";
		picture="\ShadowLegion_Weapons\data\WestarM5\UI\WestarM5_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\WestarM5\UI\WestarM5_UI.paa";
		muzzles[] = {"this","Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		weaponInfoType="RscWeaponZeroing";
		modelOptics="3AS\3AS_Weapons\Data\3AS_2D_Optic.p3d";
		handAnim[]={"OFP2_ManSkeleton","\A3\Weapons_F_Exp\Rifles\SPAR_01\Data\Anim\SPAR_01.rtm"};
		class OpticsModes
		{
			class Ironsights
			{
				opticsID=1;
				useModelOptics=0;
				opticsFlare="true";
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticsBlur5"
				};
				opticsDisablePeripherialVision=0;
				opticsZoomMin=0.375;
				opticsZoomMax=1.1;
				opticsZoomInit=0.75;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=100;
				distanceZoomMax=100;
			};
			class Scope: Ironsights
			{
				opticsID=2;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsFlare=1;
				opticsDisablePeripherialVision=0;
				opticsZoomMin=0.22499999;
				opticsZoomMax=0.22499999;
				opticsZoomInit=0.22499999;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=200;
				distanceZoomMax=200;
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=60;
		};
		ace_overheating_mrbs=3000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=0.75;
	};
	class 885th_DC15LE : IDA_DC15A
	{
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 609;
		author = "885th Bloodpack Division + IDA Dev Team";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[885th] DC-15 LE Rifle";
		descriptionShort = "Long Range Precision Modified Rifle. Semi Auto";
		picture = "Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15A\DC15A_ui.paa";
		model = "Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15LE\Model\IDA_DC15LE.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "Indecisive_Armoury_Anims\Republic\DC15A.rtm"};
		ace_clearJamAction = "";
		reloadAction = "GestureReload_JLTS_DC15A";
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\Blaster_reload_Vent.ogg", 1.5, 1, 100};
		recoil = "885_recoil_dc15a";
		magazines[] = {"885th_dc_cell_blue"};
		magazineWell[] = {};
		modes[] = {"Single"};
		fireLightDiffuse[] = {0.1, 0.25, 1};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.27;
			dispersion = 0.00050;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 1000;
			midRangeProbab = 1.0;
			maxRange = 1500;
			maxRangeProbab = 0.8;
		};
		modelOptics = "3AS\3AS_Weapons\Data\3AS_2D_Optic.p3d";
		weaponInfoType = "RscWeaponZeroing";
		class OpticsModes
		{
			class Ironsights
			{
				opticsID = 1;
				useModelOptics = 0;
				opticsFlare = "false";
				opticsPPEffects[] = {"OpticsCHAbera5", "OpticsBlur5"};
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.4;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.75;
				memoryPointCamera = "eye";
				visionMode[] = {};
				distanceZoomMin = 300;
				distanceZoomMax = 300;
			};
			class Scope : Ironsights
			{
				opticsID = 2;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera5", "OpticsBlur5"};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.015;
				opticsZoomMax = 0.1;
				opticsZoomInit = 0.1;
				memoryPointCamera = "opticView";
				visionMode[] = {};
				distanceZoomMin = 300;
				distanceZoomMax = 300;
			};
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
				iconPicture = "";
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {
					"3AS_Muzzle_LE_DC15A",
				};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {"acc_flashlight"};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {"3AS_Bipod_VK38X_f"};
			};
		};
	};
	class 885th_DC15LEMKII : Rifle_Base_F
	{
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 609;
		author = "885th Bloodpack Division + SL Mod Dev Team";
		scope = 2;
		displayName = "[885th] DC-15 LE MK II";
		descriptionShort = "Long Range Precision Modified Rifle. With Multiple Fire Modes";
		model = "\ShadowLegion_Weapons\data\DC15\DC15LE\Model\DC15_LE.p3d";
		picture = "\ShadowLegion_Weapons\data\DC15\DC15A\UI\DC15A_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\DC15\DC15A\UI\DC15A_UI.paa";
		handAnim[] = {"OFP2_ManSkeleton","\ShadowLegion_Weapons\data\DC15\DC15A\Anim\ReloadBASE_DC15A.rtm"};
		ace_clearJamAction = "";
		reloadAction = "GestureReload_JLTS_DC15A";
		reloadMagazineSound[] = {"\ShadowLegion_Weapons\data\reloads\sounds\Reload_1.ogg", 5, 1, 30};
		magazines[] = {"885th_DC15LEMKII_battery_high_blue"};
		magazineWell[] = {};
		muzzles[] = {"this","885th_DC15LEMKII_HE"};
		fireLightDiffuse[] = {0.1, 0.25, 1};
		canShootInWater = 1;
		magazineReloadSwitchPhase=0.40000001;
		discreteDistanceInitIndex=0;
		recoil="recoil_dmr_01";
		inertia=0.69999999;
		dexterity=1.5;
		initSpeed=-1;
		maxZeroing=100;
		selectionFireAnim="zasleh";
		flash="gunfire";
		flashSize=3;
		modes[]=
		{
			"Single",
			"FullAuto",
			"single_close_optics1",
			"single_medium_optics1",
			"single_far_optics1",
			"fullauto_medium"
		};
		class Single: Mode_SemiAuto
		{
			recoil="recoil_single_dmr";
			recoilProne="recoil_single_prone_dmr";
			reloadTime=0.30000001;
			dispersion=0.00030;
			minRange=2;
			minRangeProbab=0.5;
			midRange=500;
			midRangeProbab=0.69999999;
			maxRange=1500;
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
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class FullAuto: Mode_FullAuto
		{
			recoil="recoil_auto_dmr";
			recoilProne="recoil_auto_prone_dmr";
			reloadTime=0.19599999;
			dispersion=0.00073000003;
			minRange=2;
			minRangeProbab=0.5;
			midRange=250;
			midRangeProbab=0.69999999;
			maxRange=500;
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
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15LE.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class single_close_optics1: Single
		{
			requiredOpticType=1;
			showToPlayer=0;
			minRange=2;
			minRangeProbab=0.050000001;
			midRange=2  00;
			midRangeProbab=0.80000001;
			maxRange=500;
			maxRangeProbab=0.0099999998;
			aiRateOfFire=2;
			aiRateOfFireDistance=300;
		};
		class single_medium_optics1: single_close_optics1
		{
			minRange=300;
			minRangeProbab=0.050000001;
			midRange=250;
			midRangeProbab=0.69999999;
			maxRange=1000;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=500;
		};
		class single_far_optics1: single_medium_optics1
		{
			requiredOpticType=2;
			minRange=300;
			minRangeProbab=0.050000001;
			midRange=550;
			midRangeProbab=0.5;
			maxRange=1500;
			maxRangeProbab=0.050000001;
			aiRateOfFire=4;
			aiRateOfFireDistance=600;
		};
		class fullauto_medium: FullAuto
		{
			showToPlayer=0;
			burst=3;
			minRange=2;
			minRangeProbab=0.5;
			midRange=50;
			midRangeProbab=0.69999999;
			maxRange=100;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
		};
		class 885th_DC15LEMKII_HE: Rifle_Long_Base_F
		{
			displayName="Explosive Charge";
			descriptionShort="DC-15LE MKII Explosive Charge";
			useModelOptics=1;
			useExternalOptic=1;
			maxZeroing=1800;
			maxRecoilSway=0.029999999;
			swayDecaySpeed=1.25;
			discreteDistance[]={200,300,400,500,600};
			discreteDistanceInitIndex=1;
			distanceZoomMin=100;
			distanceZoomMax=350;
			cursor="srifle";
			inertia=1.2;
			aimTransitionSpeed=0.5;
			dexterity=1;
			magazines[]={"885th_DC15LEMKII_He_Battery_Blue"};
			magazineWell[]={};
			class GunParticles: GunParticles
			{
				class SecondEffect
				{
					positionName="Nabojnicestart";
					directionName="Nabojniceend";
					effectName="CaselessAmmoCloud";
				};
			};
			selectionFireAnim="zasleh";
			flash="gunfire";
			flashSize=3;
			modes[]=
			{
				"Single"
			};
			reloadMagazineSound[] = {"\ShadowLegion_Weapons\data\reloads\sounds\Reload_1.ogg", 5, 1, 30};
			class Single: Mode_SemiAuto
			{
				sounds[]=
				{
					"StandardSound"
				};
				class BaseSoundModeType
				{
					closure1[]=
					{
						"\ShadowLegion_Weapons\data\NT241\Cooldown_beep.ogg",
						2.2,
						1,
						40
					};
					soundClosure[]=
					{
						"closure1",
						0.1
					};
				};
				class StandardSound: BaseSoundModeType
				{
					begin1[]=
					{
						"ShadowLegion_Weapons\data\DC15_1.ogg",
						1,
						1,
						900
					};
					soundBegin[]=
					{
						"begin1",
						1.33
					};
				};
				class SoundTails
				{
					class TailInterior
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_interior",
							1,
							1,
							300
						};
						frequency=1;
						volume="interior";
					};
					class TailTrees
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_trees",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_forest",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*forest";
					};
					class TailMeadows
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_meadows",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_houses",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*houses";
					};
				};
				reloadTime=3.5;
				dispersion=0.00015000001;
				recoil="recoil_single_gm6";
				recoilProne="recoil_single_prone_gm6";
				minRange=2;
				minRangeProbab=0.5;
				midRange=150;
				midRangeProbab=0.69999999;
				maxRange=450;
				maxRangeProbab=0.30000001;
				aiRateOfFire=3;
				aiRateOfFireDistance=500;
			};
		};
		aiDispersionCoefY=6;
		aiDispersionCoefX=4;
		caseless[]=
		{
			"",
			1,
			1,
			1
		};
		soundBullet[]=
		{
			"caseless",
			1
		};
		drySound[]=
		{
			"\ShadowLegion_Weapons\data\reloads\sounds\Empty_1.ogg",
			5,
			1,
			20
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: MuzzleSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]=
				{
					"ShadwCmpany_Suppresor_Module_DC15",
					"ShdwCmpny_Muzzle_LE_DC15A",
					"ShdwCmpny_Muzzle_LE_DC15A_Unsur",
				};
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
			};
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]=
				{
					"ShdwCmpny_Optic_LEScope_DC15A",
					"ShdwCmpny_Optic_LEScope_DC15A_mk2",
					"ShadwCmpany_optic_Acog"
				};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR",
					"ace_acc_pointer_red",
					"ace_acc_pointer_green"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
			};
		};
		optics=1;
		useModelOptics=1;
		class OpticsModes
		{
			class DC15A_IronSights
			{
				opticsID=1;
				useModelOptics=0;
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				memoryPointCamera="eye";
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
				distanceZoomMin=200;
				distanceZoomMax=200;
				cameraDir="";
				visionMode[]={};
				opticsPPEffects[]=
				{
					"Default"
				};
			};
			class DC15A_Scope
			{
				opticsID=2;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsFlare=1;
				opticsDisablePeripherialVision=0;
				opticsZoomMin=0.22499999;
				opticsZoomMax=0.22499999;
				opticsZoomInit=0.22499999;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=200;
				distanceZoomMax=200;
			};
		};
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
	};
	class 885th_DW32S : arifle_MX_Base_F
	{
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 0;
		author = "885th Bloodpack Division + JLTS Dev Team";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[885th] DW-32S";
		descriptionShort = "Mid Range Battle Rifle. Tier 1";
		picture="885_Weapons\UI\DW32S_ui_ca.paa";
		model="\MRC\JLTS\weapons\DW32S\DW32S.p3d";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\885_Weapons\textures\DW32S_co.paa"};
		handAnim[] = {"OFP2_ManSkeleton", "\MRC\JLTS\weapons\DW32S\anims\DW32S_handanim.rtm"};
		ace_clearJamAction = "";
		reloadMagazineSound[] = {"885_Sounds\DW32SReload.ogg", 1.5, 1, 100};
		recoil = "885_recoil_DC15A";
		magazines[] = {"885th_DW32S_cell"};
		magazineWell[] = {};
		modes[] = {"Single","Burst"};
		fireLightDiffuse[] = {0.1, 0.25, 1};
		drySound[] = {"MRC\JLTS\weapons\Core\sounds\weapon_dry.wss", 5, 1, 10};
		muzzles[] = {"this"};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[]={"885_Sounds\DW32S.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\DW32S.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\DW32S.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\DW32S.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\DW32S.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\DW32S.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.45;
			dispersion = 0.00060;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 1000;
			midRangeProbab = 1.0;
			maxRange = 1500;
			maxRangeProbab = 0.8;
		};
		class Burst: Mode_Burst
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[]={"885_Sounds\DW32S.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\DW32S.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\DW32S.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\DW32S.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\DW32S.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\DW32S.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			burst = 3;
			rate = 0.10;
			textureType = "burst";
			reloadTime = 0.15;
			dispersion = 0.00025;
			flash = "gunfire";
			flashSize = 0.1;
			soundBurst = 0;
			soundContinuous = 0;
			maxRange = 2000;
			maxRangeProbab = 0.3;
			midRange = 1000;
			midRangeProbab = 0.7;
			minRange = 200;
			minRangeProbab = 0.5;
			aiDispersionCoefX = 1.4;
			aiDispersionCoefY = 1.7;
			aiRateOfFire = 2;
			aiRateOfFireDispersion = 1;
			aiRateOfFireDistance = 500;
		};
		modelOptics = "\ShadowLegion_Weapons\data\Acc\Reticles\model\Scope_Blue_1";
		weaponInfoType = "RscWeaponZeroing";
		class OpticsModes
		{
			class Ironsights
			{
				opticsID = 1;
				useModelOptics = 0;
				opticsFlare = "false";
				opticsPPEffects[] = {"OpticsCHAbera5", "OpticsBlur5"};
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.4;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.75;
				memoryPointCamera = "eye";
				visionMode[] = {};
				distanceZoomMin = 300;
				distanceZoomMax = 300;
			};
			class Scope : Ironsights
			{
				opticsID = 2;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera5", "OpticsBlur5"};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.015;
				opticsZoomMax = 0.1;
				opticsZoomInit = 0.1;
				memoryPointCamera = "opticView";
				visionMode[] = {};
				distanceZoomMin = 300;
				distanceZoomMax = 300;
			};
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
				iconPicture = "";
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
	class 885th_DC15LMKII_Base_F: Rifle_Base_F
	{
		author="885th Bloodpack Division + SL Mod Dev Team";
		canShootInWater=1;
		magazines[]=
		{
			"885th_DC15LMKII_Extended_Cell_blue",
			"885th_DC15BR_battery_blue"
		};
		reloadAction="3AS_GestureReloadDC15S";
		recoil="885_recoil_dc15a";
		recoilProne="assaultRifleBase";
		fireLightDiffuse[] = {0.1, 0.25, 1};
		magazineReloadSwitchPhase=0.40000001;
		discreteDistanceInitIndex=0;
		maxRecoilSway=0.0125;
		swayDecaySpeed=1.25;
		inertia=1.1;
		dexterity=1.5;
		initSpeed=-1;
		maxZeroing=100;
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: MuzzleSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]=
				{
					"ShadwCmpany_Suppresor_Module_DC15"
				};
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
			};
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]=
				{
					"ShadwCmpany_optic_Reflex_Mk1",
					"ShadwCmpany_optic_Reflex_Mk1_Alt1",
					"ShadwCmpany_optic_Reflex_Mk1_Alt2",
					"ShadwCmpany_optic_Acog",
					"ShdwCmpny_Optic_LEScope_DC15A_mk2",
					"ShdwCmpny_Optic_LEScope_DC15A"
				};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR",
					"ace_acc_pointer_red",
					"ace_acc_pointer_green"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]=
				{
					"ShdwCmpny_Bipod_Valken"
				};
			};
		};
		opticsZoomMin=0.25;
		opticsZoomMax=1.25;
		opticsZoomInit=0.75;
		distanceZoomMin=400;
		distanceZoomMax=400;
		descriptionShort="A Modified DC-15L";
		handAnim[]={"OFP2_ManSkeleton","\A3\Weapons_F_Mark\Machineguns\MMG_02\Data\Anim\mmg_02.rtm"};
		selectionFireAnim="zasleh";
		flash="gunfire";
		flashSize=3;
		modes[]=
		{
			"FullAuto_1",
			"FullAuto_2",
			"close",
			"midclose",
			"medium",
			"far_optic1",
			"far_optic2"
		};
		class FullAuto_1: Mode_FullAuto
		{
			reloadTime=0.12;
			dispersion=0.00056000001;
			minRange=100;
			minRangeProbab=0.89999998;
			midRange=700;
			midRangeProbab=0.69999999;
			maxRange=1000;
			maxRangeProbab=0.1;
			soundContinuous=0;
			soundBurst=0;
			sounds[]={"StandardSound","SilencedSound"};
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\IMPERIAL\DLT19.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\IMPERIAL\DLT19.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\IMPERIAL\DLT19.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\IMPERIAL\DLT19.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\IMPERIAL\DLT19.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\IMPERIAL\DLT19.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class FullAuto_2: Mode_FullAuto
		{
			reloadTime=0.067000002;
			dispersion=0.00056000001;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=700;
			midRangeProbab=0.69999999;
			maxRange=1000;
			maxRangeProbab=0.1;
			soundContinuous=0;
			soundBurst=0;
			sounds[]={"StandardSound","SilencedSound"};
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\IMPERIAL\DLT19.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\IMPERIAL\DLT19.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\IMPERIAL\DLT19.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\IMPERIAL\DLT19.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\IMPERIAL\DLT19.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\IMPERIAL\DLT19.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class close: FullAuto_2
		{
			burst=10;
			aiRateOfFire=0.5;
			aiRateOfFireDistance=50;
			minRange=10;
			minRangeProbab=0.050000001;
			midRange=20;
			midRangeProbab=0.69999999;
			maxRange=50;
			maxRangeProbab=0.039999999;
			showToPlayer=0;
		};
		class midclose: close
		{
			burst=8;
			aiRateOfFire=2;
			aiRateOfFireDistance=300;
			minRange=50;
			minRangeProbab=0.050000001;
			midRange=150;
			midRangeProbab=0.69999999;
			maxRange=300;
			maxRangeProbab=0.039999999;
		};
		class medium: close
		{
			burst=7;
			aiRateOfFire=4;
			aiRateOfFireDistance=600;
			minRange=200;
			minRangeProbab=0.050000001;
			midRange=300;
			midRangeProbab=0.69999999;
			maxRange=500;
			maxRangeProbab=0.1;
		};
		class far_optic1: medium
		{
			requiredOpticType=1;
			showToPlayer=0;
			burst=3;
			aiRateOfFire=10;
			aiRateOfFireDistance=1000;
			minRange=300;
			minRangeProbab=0.050000001;
			midRange=500;
			midRangeProbab=0.40000001;
			maxRange=650;
			maxRangeProbab=0.0099999998;
		};
		class far_optic2: far_optic1
		{
			burst=3;
			requiredOpticType=2;
			minRange=400;
			minRangeProbab=0.050000001;
			midRange=750;
			midRangeProbab=0.69999999;
			maxRange=1000;
			maxRangeProbab=0.0099999998;
			aiRateOfFire=10;
			aiRateOfFireDistance=900;
		};
		aiDispersionCoefY=24;
		aiDispersionCoefX=21;
		caseless[]={"",1,1,1};
		soundBullet[]={"caseless",1};
		drySound[]={"\ShadowLegion_Weapons\data\reloads\sounds\Empty_1.ogg",5,1,20};
		reloadMagazineSound[]={"\ShadowLegion_Weapons\data\reloads\sounds\Reload_1.ogg",2,1,30};
	};
	class 885th_DC15LMKII_F: 885th_DC15LMKII_Base_F
	{
		scope=2;
		displayName="[885th] DC-15L MKII";
		model="\ShadowLegion_Weapons\data\DC15\DC15L\model\DC15_L.p3d";
		picture="\ShadowLegion_Weapons\data\DC15\DC15L\UI\DC15L_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\DC15\DC15L\UI\DC15L_UI.paa";
		weaponInfoType="RscWeaponZeroing";
		class OpticsModes
		{
			class Ironsights
			{
				opticsID=1;
				useModelOptics=0;
				opticsFlare="true";
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticsBlur5"
				};
				opticsDisablePeripherialVision=0.67000002;
				opticsZoomMin=0.375;
				opticsZoomMax=1.1;
				opticsZoomInit=0.75;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=100;
				distanceZoomMax=100;
			};
			class Scope: Ironsights
			{
				opticsID=2;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsFlare=1;
				opticsDisablePeripherialVision=0;
				opticsZoomMin=0.22499999;
				opticsZoomMax=0.22499999;
				opticsZoomInit=0.22499999;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=200;
				distanceZoomMax=200;
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=60;
		};
		ace_overheating_mrbs=3000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=1;
		ace_overheating_dispersion=0.75;
	};
	class 885th_DC15HR : arifle_MX_Base_F
	{
		access = 0;
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 650;
		author = "885th Bloodapack Divison + 3AS Dev Team";
		scope = 2;
		inertia = 0.4;
		canShootInWater = 1;
		displayName = "[885th] DC-15 Heavy Infantry Repeater";
		descriptionShort = "Heavy Precision Repeater, Mid to Long Range";
		model="3AS\3AS_Weapons\Republic\DC15L\3AS_DC15L_f.p3d";
		picture="\3AS\3AS_Weapons\Republic\DC15L\Data\UI\3as_dc15l.paa";
		handAnim[] = {"OFP2_ManSkeleton", "\3AS\3AS_Weapons\Republic\DC15L\Data\Anims\New_DC15L_Handanim.rtm"};
		ace_clearJamAction = "";
		reloadAction = "3AS_GestureReloadOverHeat";
		reloadMagazineSound[] = {"\3AS\3AS_Main\Sounds\Old\Blaster_reload.wss",1,1,30};
		recoil = "3AS_recoil_DC15L";
		magazines[] = {"885th_battery_ampHR_blue"};
		magazineWell[] = {};
		magazineReloadTime = 0.55;
		fireLightDiffuse[] = {0.1, 0.25, 1};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		muzzles[] = {"this"};
		modes[] = {"FullAuto"};
		class FullAuto : Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_DLT19_Shot_SoundSet"
				};
			};
			reloadTime = 0.15;
			dispersion = 0.0015;
			burst = 1;
			soundContinuous = "false";
			soundBurst = "true";
			minRange = 0;
			minRangeProbab = 1.0;
			midRange = 700;
			midRangeProbab = 1.0;
			maxRange = 1000;
			maxRangeProbab = 0.9;
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 75;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"885th_Optic_Scope_WestarM5","ShdwCmpny_Optic_LEScope_DC15A_mk2","ShadwCmpany_773_Hybrid_Magnifier_Holo"};
			};
			class MuzzleSlot : MuzzleSlot
			{	
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[] = {"ShdwCmpny_Muzzle_LE_DC15A_Unsur"};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {"acc_flashlight"};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {"3AS_Bipod_VK38X_f"};
			};
		};
	};
	class 885th_Valken38XMKII : arifle_MX_Base_F
	{
		access = 0;
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 650;
		scope = 2;
		inertia = 0.5;
		canShootInWater = 1;
		dexterity=1.5;
		maxZeroing=2200;
		discreteDistance[]={200,300,400,500,600};
		discreteDistanceInitIndex=1;
		opticsPPEffects[]={};
		opticsFlare=1;
		opticsDisablePeripherialVision=1;
		author = "Antauri + 885th Bloodapack Divison";
		displayName = "[885th] Valken-38R";
		descriptionShort = "Modified Valken38X, Mid to Long Range";
		model="\ShadowLegion_Weapons\data\Valken38R\models\Valken38R.p3d";
		picture="\ShadowLegion_Weapons\data\Valken38R\UI\Valken_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\Valken38R\UI\Valken_UI.paa";
		handAnim[] = {"OFP2_ManSkeleton", "\ShadowLegion_Weapons\data\Valken38X\anim\ReloadBASE_Valken38X.rtm"};
		ace_clearJamAction = "";
		reloadAction = "GestureReloadDMR07";
		magazineReloadSwitchPhase=0.40000001;
		reloadMagazineSound[] = {"\ShadowLegion_Weapons\data\reloads\sounds\Reload_1.ogg", 2, 1, 30};
		recoil = "recoil_spar_dmr";
		magazines[] = {"885th_battery_ampAR_blue"};
		magazineWell[] = {};
		fireLightDiffuse[] = {0.1, 0.25, 1};
		drySound[] = {"\ShadowLegion_Weapons\data\reloads\sounds\Empty_1.ogg", 5, 1, 20};
		muzzles[] = {"this"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.1;
			dispersion=0.00052;
			minRange=2;
			minRangeProbab=0.5;
			midRange=300;
			midRangeProbab=0.69999999;
			maxRange=600;
			maxRangeProbab=0.30000001;
			soundContinuous=0;
			soundBurst=0;
			sounds[]={"StandardSound","SilencedSound"};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_Sniper_SoundSet"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		soundBipodDeploy[]=
		{
			"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_deploy",
			0.70794576,
			1,
			20
		};
		soundBipodFold[]=
		{
			"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_fold",
			0.70794576,
			1,
			20
		};
		soundBipodDown[]=
		{
			"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_down",
			0.70794576,
			1,
			20
		};
		soundBipodUp[]=
		{
			"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_up",
			0.70794576,
			1,
			20
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]=
				{
					"ShadwCmpany_optic_Reflex_Mk1",
					"ShadwCmpany_optic_Reflex_Mk1_Alt1",
					"ShadwCmpany_optic_Reflex_Mk1_Alt2",
					"ShadwCmpany_optic_Acog",
					"ShdwCmpny_Optic_Valken",
					"optic_mrco",
					"ShdwCmpny_Optic_LEScope_DC15A_mk2",
					"ShdwCmpny_Optic_LEScope_DC15A",
					"ShdwCmpny_Optic_Scope_WestarM5"
				};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR",
					"ace_acc_pointer_red",
					"ace_acc_pointer_green"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]=
				{
					"ShdwCmpny_Bipod_Valken"
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]=
				{
					"ShadwCmpany_Suppresor_Module_DC19"
				};
			};
		};
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
	};
	class 885th_Valken38A_Base_F: Rifle_Base_F
	{
		author="885th Bloodpack Division";
		canShootInWater=1;
		magazines[]={"885th_Valken38A_HighPower_Cell"};
		reloadAction="GestureReloadDMR07";
		magazineReloadSwitchPhase=0.40000001;
		recoil="recoil_spar_dmr";
		maxRecoilSway=0.0125;
		swayDecaySpeed=1.25;
		inertia=0.5;
		dexterity=1.5;
		maxZeroing=2200;
		discreteDistance[]={200,300,400,500,600};
		discreteDistanceInitIndex=1;
		opticsPPEffects[]={};
		opticsFlare=1;
		opticsDisablePeripherialVision=1;
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
		soundBipodDeploy[]=
		{
			"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_deploy",
			0.70794576,
			1,
			20
		};
		soundBipodFold[]=
		{
			"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_fold",
			0.70794576,
			1,
			20
		};
		soundBipodDown[]=
		{
			"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_down",
			0.70794576,
			1,
			20
		};
		soundBipodUp[]=
		{
			"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_up",
			0.70794576,
			1,
			20
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]=
				{
					"ShadwCmpany_optic_Reflex_Mk1",
					"ShadwCmpany_optic_Acog",
					"ShadwCmpany_optic_e11",
					"ShdwCmpny_Optic_Valken",
					"ShdwCmpny_Optic_LEScope_DC15A_mk2",
					"ShdwCmpny_Optic_LEScope_DC15A"
				};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR",
					"ace_acc_pointer_red",
					"ace_acc_pointer_green"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]=
				{
					"ShdwCmpny_Bipod_Valken",
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]=
				{
					"ShadwCmpany_Suppresor_Module_DC15"
				};
			};
		};
		descriptionShort="Valken-38A";
		handAnim[]={"OFP2_ManSkeleton","\ShadowLegion_Weapons\data\Valken38X\anim\ReloadBASE_Valken38X.rtm"};
		selectionFireAnim="zasleh";
		flash="gunfire";
		flashSize=3;
		muzzles[] = {"this"};
		modes[]={"FullAuto"};
		class FullAuto: Mode_FullAuto
		{
			sounds[]={"StandardSound","SilencedSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[]={"885_Sounds\Valken38a.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\Valken38a.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\Valken38a.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\Valken38a.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\Valken38a.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\Valken38a.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin2[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin3[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin4[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin5[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin6[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			}
			reloadTime=0.2;
			dispersion=0.00025000001;
			minRange=5;
			minRangeProbab=0.5;
			midRange=150;
			midRangeProbab=0.69999999;
			maxRange=450;
			maxRangeProbab=0.30000001;
			soundContinuous=0;
			soundBurst=0;
		};
		aiDispersionCoefY=6;
		aiDispersionCoefX=4;
		caseless[]={"",1,1,1};
		soundBullet[]={"caseless",1};
		drySound[]={"\ShadowLegion_Weapons\data\reloads\sounds\Empty_1.ogg",5,1,20};
		reloadMagazineSound[]={"\ShadowLegion_Weapons\data\reloads\sounds\Reload_1.ogg",2,1,30};
	};
	class 885th_Valken38A_F: 885th_Valken38A_Base_F
	{
		scope=2;
		displayName="[885th] Valken-38A";
		model="\ShadowLegion_Weapons\data\Valken38X\Models\Valken38X.p3d";
		picture="\ShadowLegion_Weapons\data\Valken38X\Valken38x.paa";
		UiPicture="ShadowLegion_Weapons\data\Valken38X\Valken38x.paa";
		weaponInfoType="RscWeaponZeroing";
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=60;
		};
		ace_overheating_mrbs=3000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=0.75;
	};
	class 885th_DC19 : arifle_MX_Base_F
	{
		access = 0;
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		author = "885th Bloodpack Divison";
		scope = 2;
		displayName = "[885th] DC-19";
		descriptionShort = "Short Carbine, Short to Mid Range";
		model="\ShadowLegion_Weapons\data\DC15\DC19\models\DC19_S.p3d";
		picture="\ShadowLegion_Weapons\data\DC15\DC19\UI\DC19_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\DC15\DC19\UI\DC19_UI.paa";
		handAnim[] = {"OFP2_ManSkeleton","\A3\Weapons_F\Rifles\MX\data\Anim\MX_dmr.rtm"};
		ace_clearJamAction = "";
		reloadAction = "3AS_GestureReloadDC15S";
		magazineReloadSwitchPhase=0.40000001;
		discreteDistanceInitIndex=0;
		canShootInWater=1;
		maxRecoilSway=0.0125;
		swayDecaySpeed=1.25;
		inertia=0.40000001;
		dexterity=1.6;
		initSpeed=-1;
		reloadMagazineSound[] = {"\ShadowLegion_Weapons\data\reloads\sounds\Reload_1.ogg", 2, 1,30};
		recoil = "885_recoil_DC17";
		magazines[] = {"885th_dc_cell_blue_low","885th_dc_cell_blue","885th_25Rnd_Tracerless_Cell"};
		magazineWell[] = {};
		magazineReloadTime = 0;
		fireLightDiffuse[] = {0.1, 0.25, 1};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		selectionFireAnim="zasleh";
		flash="gunfire";
		flashSize=3;
		modes[] = {"Single","Burst","FullAuto"};
		muzzles[] = {"this","Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		class Single: Mode_SemiAuto
		{
			sounds[]={"StandardSound","SilencedSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin2[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin3[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin4[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin5[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin6[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			}
			reloadTime=0.050000001;
			dispersion=0.00131;
			minRange=2;
			minRangeProbab=0.30000001;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=450;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=300;
		};
		class Burst: Mode_Burst
		{
			sounds[]={"StandardSound","SilencedSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin2[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin3[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin4[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin5[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin6[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			}
			soundBurst=0;
			textureType="dual";
			burst=2;
			reloadTime=0.050000001;
			dispersion=0.00131;
			minRange=2;
			minRangeProbab=0.30000001;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=350;
			maxRangeProbab=0.050000001;
			aiRateOfFire=1;
			aiRateOfFireDistance=250;
		};
		class FullAuto: Mode_FullAuto
		{
			sounds[]={"StandardSound","SilencedSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15S.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin2[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin3[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin4[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin5[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				begin6[]={"ShadowLegion_Weapons\data\DC19Surpressed.ogg",2,1,300};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			}
			reloadTime=0.050000001;
			dispersion=0.00131;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
			aiRateOfFire=1e-006;
			aiRateOfFireDistance=50;
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 75;
			class CowsSlot: CowsSlot
			{	
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]={"ShdwCmpny_Optic_LEScope_DC15A","ShadwCmpany_optic_Acog","ShadwCmpany_optic_Reflex_Mk1","ShadwCmpany_optic_Reflex_Mk1_Alt1","ShadwCmpany_optic_Reflex_Mk1_Alt2","optic_mrco","ShadwCmpany_optic_e11","ShadwCmpany_Hybrid_Magnifier_Holo","ShadwCmpany_Hybrid_Magnifier_Magnified"};
			};
			class MuzzleSlot : MuzzleSlot
			{	
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[] = {"ShadwCmpany_Suppresor_Module_DC19"};
			};
			class PointerSlot : PointerSlot
			{	
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[] = {"acc_flashlight","acc_pointer_IR","ace_acc_pointer_red","ace_acc_pointer_green","3AS_Imp_Laser_E11"};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
	};
	class 885th_DC19FS : 885th_DC19
	{
		scope = 2;
		model="\ShadowLegion_Weapons\data\DC15\DC19\models\DC19_S_Folded.p3d";
		displayName = "[885th] DC-19 FS";
		magazines[] = {"885th_dc_cell_blue_low","885th_dc_cell_blue","885th_25Rnd_Tracerless_Cell"};
		magazineWell[] = {};
		modes[] = {"Single","FullAuto"};
		muzzles[] = {"this","Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
	};
	class 885th_DC15CMK2 : arifle_MX_Base_F
	{
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		scope=2;
		displayName= "[885th] DC-15C MkII";
		author="885th Bloodpack Division + SL Mod Dev Team";
		descriptionShort = "Modified Infantry Assualt Rifle, Mid to Long Stable Platform";
		model="\ShadowLegion_Weapons\data\DC15\DC15C\model\DC15_C.p3d";
		picture="\ShadowLegion_Weapons\data\DC15\DC15C\UI\DC15C_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\DC15\DC15C\UI\DC15C_UI.paa";
		handAnim[] = {"OFP2_ManSkeleton","\A3\Weapons_F_Mark\LongRangeRifles\DMR_05\data\Anim\DMR_05.rtm"};
		ace_clearJamAction = "";
		reloadAction = "3AS_GestureReloadDC15S";
		magazineReloadSwitchPhase=0.40000001;
		discreteDistanceInitIndex=0;
		canShootInWater=1;
		maxRecoilSway=0.0125;
		swayDecaySpeed=1.25;
		inertia=0.40000001;
		dexterity=1.6;
		initSpeed=-1;
		reloadMagazineSound[] = {"\ShadowLegion_Weapons\data\reloads\sounds\Reload_1.ogg", 2, 1,30};
		recoil = "recoil_sw";
		magazineWell[] = {};
		magazineReloadTime = 0;
		fireLightDiffuse[] = {0.1, 0.25, 1};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		selectionFireAnim="zasleh";
		flash="gunfire";
		flashSize=3;
		magazines[] = {"885th_DC15CMKII_cell_blue_apex"};
		modes[]={"Single","FullAuto"};
		muzzles[]={"this"};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.1;
			dispersion=0.00066000002;
			minRange=2;
			minRangeProbab=0.30000001;
			midRange=150;
			midRangeProbab=0.69999999;
			maxRange=350;
			maxRangeProbab=0.1;
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
				begin1[] = {"885_Sounds\DC15CMKII_Fire.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\DC15CMKII_Fire.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\DC15CMKII_Fire.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\DC15CMKII_Fire.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\DC15CMKII_Fire.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\DC15CMKII_Fire.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class FullAuto: Mode_FullAuto
		{
			reloadTime=0.090000004;
			dispersion=0.00066000002;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
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
				begin1[] = {"885_Sounds\DC15CMKII_Fire.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\DC15CMKII_Fire.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\DC15CMKII_Fire.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\DC15CMKII_Fire.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\DC15CMKII_Fire.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\DC15CMKII_Fire.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 75;
			class CowsSlot: CowsSlot
			{	
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]={"ShdwCmpny_Optic_LEScope_DC15A","ShadwCmpany_optic_Acog","ShadwCmpany_optic_Reflex_Mk1","ShadwCmpany_optic_Reflex_Mk1_Alt1","ShadwCmpany_optic_Reflex_Mk1_Alt2","ShadwCmpany_optic_e11","ShdwCmpny_Optic_Scope_WestarM5","ShadwCmpany_Hybrid_Magnifier_Holo","ShadwCmpany_773_Hybrid_Magnifier_Holo"};
			};
			class MuzzleSlot : MuzzleSlot
			{	
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[] = {"ShadwCmpany_Suppresor_Module_DC19"};
			};
			class PointerSlot : PointerSlot
			{	
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[] = {"acc_flashlight","acc_pointer_IR","ace_acc_pointer_red","ace_acc_pointer_green"};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {"ShdwCmpny_Bipod_Valken"};
			};
		};
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
	};
	class JLTS_DC15X;
	class 885th_DC15XS: JLTS_DC15X
	{
		baseWeapon = "885th_DC15XS";
		author = "885th Bloodpack Division";
		scope = 2;
		inertia = 0;
		displayName = "[885th] DC15X Sharpshooter Rifle";
		magazines[] = {"885th_dc_cell_blue_high","885th_dc_cell_blue_over"};
		ace_clearJamAction = "";
		reloadAction = "GestureReload_IDA_Reload_Blaster";
		recoil = "885_recoil_DC15X";
		magazineWell[] = {};
		fireLightDiffuse[] = {0.1,0.25,1};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg",5,1,10};
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\Blaster_reload_Vent.ogg",5,1,100};
		muzzles[] = {"this"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			sounds[]={"StandardSound","SilencedSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]={"885_Sounds\DC15XOG.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\DC15XOG.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\DC15XOG.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\DC15XOG.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\DC15XOG.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
			class SilencedSound: BaseSoundModeType
            {
                begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
                begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
                begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
                begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
                begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
                begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
                soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
                beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
                soundBeginWater[]={"beginwater1",0.5};
            };
			reloadTime = 0.40;
			dispersion = 0.0005;
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 10000;
			maxRangeProbab = 0.3;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 120;
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {"JLTS_DC15X_scope","ShadwCmpany_optic_Acog","ShdwCmpny_Optic_LEScope_DC15A"};
			};
			class MuzzleSlot : MuzzleSlot
			{	
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[] = {"ShadwCmpany_Suppresor_Module_DC15"};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {"acc_pointer_IR","3AS_Imp_Laser_E11"};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {"3AS_Bipod_VK38X_f"};
			};
		};
	};
	class 885th_DX23_F: Rifle_Base_F
	{
		scope=2;
		displayName="[885th] DX-23 Experimental Scattergun";
		canShootInWater=1;
		author="885th Bloodpack Division + SL Mod Dev Team";
		descriptionShort = "Modified DP-23,With Full Auto & Stun Fire Modes";
		picture="\ShadowLegion_Weapons\data\DP23\DP23_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\DP23\DP23_UI.paa";
		model="\ShadowLegion_Weapons\data\DP23\model\DP23.p3d";
		_generalMacro="ShdwCmpny_DP23_F";
		fireLightDiffuse[] = {0.1, 0.25, 1};
		magazines[] = {"885th_DX23_scattershot_mag", "885th_DX23_Doomsday_slug_Mag"};
		magazineWell[] = {};
		reloadAction="3AS_GestureReloadDC15S";
		recoil="recoil_ktb";
		maxZeroing=1000;
		handAnim[]={"OFP2_ManSkeleton","\A3\Weapons_F_Mark\LongRangeRifles\DMR_05\data\Anim\DMR_05.rtm"};
		modes[]={"Single","single_medium_optics1","single_far_optics2","FullAuto"};
		muzzles[] = {"this"};
		class FullAuto: Mode_FullAuto
		{
			reloadTime=0.2;
			dispersion=0.00092000002;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
			soundContinuous=0;
			soundBurst=0;
			sounds[]={"StandardSound","SilencedSound"};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				begin1[]={"885_Sounds\DX23.ogg",1.9952624,1,900};
				soundBegin[] = {"begin1", 0.2};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.2;
			dispersion=5.9999998e-005;
			minRange=2;
			minRangeProbab=0.5;
			midRange=200;
			midRangeProbab=0.69999999;
			maxRange=400;
			maxRangeProbab=0.30000001;
			sounds[]={"StandardSound","SilencedSound"};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				begin1[]={"885_Sounds\DX23.ogg",1.9952624,1,900};
				soundBegin[] = {"begin1", 0.2};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class single_medium_optics1: Single
		{
			requiredOpticType=1;
			showToPlayer=0;
			minRange=2;
			minRangeProbab=0.2;
			midRange=450;
			midRangeProbab=0.69999999;
			maxRange=600;
			maxRangeProbab=0.2;
			aiRateOfFire=6;
			aiRateOfFireDistance=600;
		};
		class single_far_optics2: single_medium_optics1
		{
			requiredOpticType=2;
			minRange=100;
			minRangeProbab=0.1;
			midRange=450;
			midRangeProbab=0.60000002;
			maxRange=800;
			maxRangeProbab=0.050000001;
			aiRateOfFire=8;
			aiRateOfFireDistance=800;
		};
		aiDispersionCoefY=6;
		aiDispersionCoefX=4;
		caseless[]=
		{
			"",
			1,
			1,
			1
		};
		soundBullet[]=
		{
			"caseless",
			1
		};
		drySound[]=
		{
			"\ShadowLegion_Weapons\data\reloads\sounds\Empty_1.ogg",
			5,
			1,
			20
		};
		reloadMagazineSound[]=
		{
			"\ShadowLegion_Weapons\data\reloads\sounds\Reload_1.ogg",
			2,
			1,
			30
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: MuzzleSlot_65
			{
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]=
				{
					"ShadwCmpany_Suppresor_Module_DC15"
				};
			};
			class CowsSlot: CowsSlot_Rail
			{
				iconPosition[]={0.44999999,0.28};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]=
				{
					"ShadwCmpany_optic_Reflex_Mk1",
					"ShadwCmpany_optic_Reflex_Mk1_Alt1",
					"ShadwCmpany_optic_Reflex_Mk1_Alt2",
					"ShadwCmpany_optic_Acog",
					"ShadwCmpany_optic_e11",
					"ShadwCmpany_optic_DH17Scope",
					"ShdwCmpny_Optic_A280Scope",
					"ShadwCmpany_Hybrid_Magnifier_Holo",
					"ShadwCmpany_Hybrid_Magnifier_Magnified"
				};
			};
			class PointerSlot: PointerSlot_Rail
			{
				iconPosition[]={0.34999999,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR",
					"ace_acc_pointer_red",
					"ace_acc_pointer_green"
				};
			};
		};
		distanceZoomMin=300;
		distanceZoomMax=300;
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
	};
	class 885th_DC23: arifle_MX_Base_F
	{
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		author="885th Bloodpack Division + Indecisive Armoury Team";
		scope=2;
		inertia=0;
		canShootInWater=1;
		fireSpreadAngle=2;
		discreteDistance[]={50,100,200,300};
		displayName="[885th] DC-23 Breaching Scattergun";
		descriptionShort="";
		picture="Indecisive_Armoury_Weapons_REPUBLIC\Data\DC23\DC23_ui.paa";
		model="Indecisive_Armoury_Weapons_REPUBLIC\Data\DC23\Model\IDA_DC23.p3d";
		handAnim[]={"OFP2_ManSkeleton","Indecisive_Armoury_Anims\Republic\DC23.rtm"};
		magazines[]={"885th_Breaching_Scatter_Cell_5Rnd_Blue"};
		magazineWell[]={};
		muzzles[]={"this"};
		modes[]={"Fire"};
		ace_clearJamAction="";
		reloadAction="GestureReload_IDA_Reload_Blaster";
		reloadMagazineSound[]={"\Indecisive_Armoury_Sounds\Blaster_reload_Vent.ogg",5,1,100};
		recoil = "3AS_recoil_DC15X";
		fireLightDiffuse[]={0.1,0.25,1};
		drySound[]={"\Indecisive_Armoury_Sounds\weapon_dry.ogg",5,1,10};
		class Fire: Mode_Burst
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"\Indecisive_Armoury_Sounds\Republic\DC23.ogg",
					1.25,
					1,
					1800
				};
				begin2[]=
				{
					"\Indecisive_Armoury_Sounds\Republic\DC23.ogg",
					1.25,
					1.025,
					1800
				};
				begin3[]=
				{
					"\Indecisive_Armoury_Sounds\Republic\DC23.ogg",
					1.25,
					0.94999999,
					1800
				};
				begin4[]=
				{
					"\Indecisive_Armoury_Sounds\Republic\DC23.ogg",
					1.25,
					1.05,
					1800
				};
				begin5[]=
				{
					"\Indecisive_Armoury_Sounds\Republic\DC23.ogg",
					1.25,
					0.89999998,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					0.2,
					"begin2",
					0.2,
					"begin3",
					0.2,
					"begin4",
					0.2,
					"begin5",
					0.2
				};
				beginwater1[]=
				{
					"\Indecisive_Armoury_Sounds\Republic\DC23.ogg",
					1,
					1,
					400
				};
				soundBeginWater[]=
				{
					"beginwater1",
					1
				};
			};
			reloadTime=0.35;
			Burst=1;
			soundBurst="true";
			dispersion=0;
			minRange=1;
			minRangeProbab=0.5;
			midRange=25;
			midRangeProbab=0.075000003;
			maxRange=50;
			maxRangeProbab=0.30000001;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=50;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]={};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]=
				{
					"acc_flashLight"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName="Konec hlavne";
				effectName="RifleAssaultCloud";
				positionName="Usti hlavne";
			};
		};
	};
	class IDA_M41;
	class 885th_M41 : IDA_M41
	{
		ace_barrelLength = 650;
		baseWeapon = "885th_M41";
		author = "885th Bloodapack Divison + IDA Dev Team";
		displayName = "[885th] M-41 Heavy Repeating Blaster";
		descriptionShort = "Heavy Repeating Blaster, Mid to Long Range";
		magazines[] = {"885th_battery_ampm41_green"};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\885_Weapons\textures\M41_Grey.co.paa"};
		modes[]={"FullAutoSlow","FullAutoFast","close","short","medium","far_optic1","far_optic2"};
		class FullAutoSlow: Mode_FullAuto
		{
			sounds[]={"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]={"\Indecisive_Armoury_Sounds\INDEP\M41.ogg",1.25,1,1800};
				begin2[]={"\Indecisive_Armoury_Sounds\INDEP\M41.ogg",1.25,1.025,1800};
				begin3[]={"\Indecisive_Armoury_Sounds\INDEP\M41.ogg",1.25,0.94999999,1800};
				begin4[]={"\Indecisive_Armoury_Sounds\INDEP\M41.ogg",1.25,1.05,1800};
				begin5[]={"\Indecisive_Armoury_Sounds\INDEP\M41.ogg",1.25,0.89999998,1800};
				soundBegin[]={"begin1",0.2,"begin2",0.2,"begin3",0.2,"begin4",0.2,"begin5",0.2};
				beginwater1[]={"\Indecisive_Armoury_Sounds\INDEP\M41.ogg",1,1,400};
				soundBeginWater[]={"beginwater1",1};
			};
			reloadTime=0.15000001;
			dispersion=0.00073000003;
			soundContinuous=0;
			soundBurst=0;
			minRange=0;
			minRangeProbab=0.30000001;
			midRange=5;
			midRangeProbab=0.69999999;
			maxRange=10;
			maxRangeProbab=0.039999999;
			showToPlayer=1;
		};
		class FullAutoFast: FullAutoSlow
		{
			reloadTime=0.075000003;
			textureType="fastAuto";
		};
		class close: FullAutoFast
		{
			burst=10;
			aiRateOfFire=0.5;
			aiRateOfFireDistance=50;
			minRange=10;
			minRangeProbab=0.050000001;
			midRange=20;
			midRangeProbab=0.69999999;
			maxRange=50;
			maxRangeProbab=0.039999999;
			showToPlayer=0;
		};
		class short: close
		{
			burst=8;
			aiRateOfFire=2;
			aiRateOfFireDistance=300;
			minRange=50;
			minRangeProbab=0.050000001;
			midRange=150;
			midRangeProbab=0.69999999;
			maxRange=300;
			maxRangeProbab=0.039999999;
		};
		class medium: FullAutoSlow
		{
			burst=7;
			aiRateOfFire=4;
			aiRateOfFireDistance=600;
			minRange=200;
			minRangeProbab=0.050000001;
			midRange=300;
			midRangeProbab=0.69999999;
			maxRange=500;
			maxRangeProbab=0.1;
			showToPlayer=0;
		};
		class far_optic1: medium
		{
			requiredOpticType=1;
			showToPlayer=0;
			burst=3;
			aiRateOfFire=10;
			aiRateOfFireDistance=1000;
			minRange=300;
			minRangeProbab=0.050000001;
			midRange=500;
			midRangeProbab=0.40000001;
			maxRange=650;
			maxRangeProbab=0.0099999998;
		};
		class far_optic2: far_optic1
		{
			burst=3;
			requiredOpticType=2;
			minRange=400;
			minRangeProbab=0.050000001;
			midRange=750;
			midRangeProbab=0.69999999;
			maxRange=900;
			maxRangeProbab=0.0099999998;
			aiRateOfFire=10;
			aiRateOfFireDistance=900;
		};
		aiDispersionCoefY=24;
		aiDispersionCoefX=21;
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 75;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"IDA_TargetingScope","ShdwCmpny_Optic_LEScope_DC15A_mk2","ShadwCmpany_optic_Acog","ACE_optic_Hamr_2D"};
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
				compatibleItems[] = {"3AS_Bipod_VK38X_f"};
			};
		};
	};
	class 885th_Z8_Experimental_Base_F: Rifle_Long_Base_F
    {
		scope=0;
		author="885th Bloodapack Division";
		descriptionShort="";
		picture="\ShadowLegion_Weapons\data\Z_7_Hellfire\Z7_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\Z_7_Hellfire\Z7_UI.paa";
		inertia=0.8;
		dexterity=0.9;
		cursor = "arifle";
		cursoraim = "CursorAim";
		cursorAimOn = "";
		cursorSize = 1;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"885_Weapons\textures\Z8_co.paa"};
		handAnim[]={"OFP2_ManSkeleton","\ShadowLegion_Weapons\data\Z_7_Hellfire\anim\Z_7_Hellfire_HandAnim.rtm"};
		reloadAction="GestureReload_JLTS_DC15A";
		modes[]={"SlowAuto"};
		fireLightDiffuse[] = {0.1, 0.25, 1};
		caseless[]={"",1,1,1};
		soundBullet[]={"caseless",1};
		drySound[]={"885_Sounds\Z8dryfire.ogg",5,1,20};
		reloadMagazineSound[]={"885_Sounds\z8reload.ogg",2,1,30};
		muzzles[]={"this"};
		class SlowAuto: Mode_FullAuto
		{
			sounds[]={"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]={"885_Sounds\Z8Blastercannon.ogg",1.9952624,1,900};
				soundBegin[] = {"begin1", 0.2};
			};
			reloadTime=0.1225;
			recoil="recoil_auto_mx";
			recoilProne="recoil_auto_prone_mx";
			dispersion=0.00026000002;
			minRange=2;
			minRangeProbab=0.5;
			midRange=250;
			midRangeProbab=0.69999999;
			maxRange=450;
			maxRangeProbab=0.30000001;
			aiRateOfFire=1e-006;
		};
		modelOptics = "\Indecisive_Armoury_Weapons_REPUBLIC\Data\LowPower_Scope\IDA_LowPower_Scope_Blue.p3d";
		weaponInfoType = "RscWeaponZeroing";
		class OpticsModes
		{
			class Iron
			{
				opticsID=1;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"",
					""
				};
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=200;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
			};
			class IDA_DC15S_Scope
			{
				opticsID=2;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsZoomMin=0.125;
				opticsZoomMax=0.125;
				opticsZoomInit=0.125;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=100;
				distanceZoomMax=1000;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
				cameraDir="";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=97;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]=
				{};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]=
				{};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]=
				{};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName="Konec hlavne";
				effectName="RifleAssaultCloud";
				positionName="Usti hlavne";
			};
		};
	};
    class 885th_Z8_Experimental_F: 885th_Z8_Experimental_Base_F
    {
        scope=2;
        displayName="[885th] Z8 Experimental Blaster Cannon";
		model="\ShadowLegion_Weapons\data\Z_7_Hellfire\Model\Z_7_Hellfire.p3d";
		_generalMacro="885th_Z8_Experimental_F";
        descriptionShort="";
		magazines[]={"885th_Z8_Experimental_200rnd_battery_blue","885th_Z8_Experimental_50rnd_HE_battery_blue"};
    };
	class 885th_T15LIR : arifle_MX_Base_F
	{
		access = 0;
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 560;
		author = "885th Bloodapack Divison + 3AS Dev Team";
		scope = 2;
		inertia = 0.4;
		canShootInWater = 1;
		displayName = "[885th] T-15 Light Infantry Repeater";
		descriptionShort = ", Mid to Long Range";
		picture="Indecisive_Armoury_Weapons_REPUBLIC\Data\T15\T15_ui.paa";
		model="Indecisive_Armoury_Weapons_REPUBLIC\Data\T15\Model\IDA_T15.p3d";
		handAnim[]={"OFP2_ManSkeleton","\MRC\JLTS\weapons\EPL2\anims\EPL2_handanim.rtm"};
		ace_clearJamAction = "";
		reloadAction="GestureReload_IDA_Reload_Blaster";
		reloadMagazineSound[]={"\Indecisive_Armoury_Sounds\Blaster_reload_Vent.ogg",5,1,100};
		recoil="IDA_recoil_HeavyRepeatingBlaster";
		magazines[] = {"885th_battery_high_blue"};
		magazineWell[] = {};
		magazineReloadTime = 0.55;
		fireLightDiffuse[] = {0.1, 0.25, 1};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		muzzles[] = {"this"};
		modes[] = {"FullAuto"};
		class FullAuto: Mode_FullAuto
		{
			sounds[]={"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]={"\Indecisive_Armoury_Sounds\Republic\T15.ogg",1.25,1,1800};
				begin2[]={"\Indecisive_Armoury_Sounds\Republic\T15.ogg",1.25,1.025,1800};
				begin3[]={"\Indecisive_Armoury_Sounds\Republic\T15.ogg",1.25,0.94999999,1800};
				begin4[]={"\Indecisive_Armoury_Sounds\Republic\T15.ogg",1.25,1.05,1800};
				begin5[]={"\Indecisive_Armoury_Sounds\Republic\T15.ogg",1.25,0.89999998,1800};
				soundBegin[]={"begin1",0.2,"begin2",0.2,"begin3",0.2,"begin4",0.2,"begin5",0.2};
				beginwater1[]={"\Indecisive_Armoury_Sounds\Republic\T15.ogg",1,1,400};
				soundBeginWater[]={"beginwater1",1};
			};
			reloadTime=0.15000001;
			dispersion=0.00050000002;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 75;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"IDA_TargetingScope","ShadwCmpany_optic_Acog","ShdwCmpny_Optic_LEScope_DC15A","ACE_optic_Hamr_2D","ShdwCmpny_Optic_A280Scope"};
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
				compatibleItems[] = {"3AS_Bipod_VK38X_f"};
			};
		};
	};
	class 885th_T15 : arifle_MX_Base_F
	{
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 300;
		author = "Indecisive Armoury Team";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[885th] T-15 Blaster Cannon";
		descriptionShort = "Dedicated anti-material blaster, Light Anti Tank";
		picture = "Indecisive_Armoury_Weapons_REPUBLIC\Data\T15\T15_ui.paa";
		model = "Indecisive_Armoury_Weapons_REPUBLIC\Data\T15\Model\IDA_T15.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "\MRC\JLTS\weapons\EPL2\anims\EPL2_handanim.rtm"};
		ace_clearJamAction = "";
		reloadAction = "GestureReload_IDA_Reload_Blaster";
		recoil = "885_recoil_T15";
		magazines[] = {"885th_coil_blue", "885th_coil_blue_high"};
		magazineWell[] = {};
		fireLightDiffuse[] = {0.1, 0.25, 1};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		muzzles[] = {"this"};
		modes[] = {"Single"};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\T15.ogg", 1, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\T15.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\T15.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\T15.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\T15.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\T15.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.55;
			dispersion = 0.00100;
			minRange = 25;
			minRangeProbab = 0.8;
			midRange = 500;
			midRangeProbab = 1.0;
			maxRange = 1000;
			maxRangeProbab = 0.6;
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 85;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"885th_Optic_Scope_WestarM5", "3AS_optic_reflex_DC15C", "3AS_optic_acog_DC15C", "3AS_Imp_Optic_2","ShadwCmpany_optic_Acog","ShdwCmpny_Optic_LEScope_DC15A_mk2",};
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
				compatibleItems[] = {"3AS_Bipod_VK38X_f"};
			};
		};
	};
	class 885th_Z6 : arifle_MX_Base_F
	{
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0.2;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		access = 0;
		ace_barrelLength = 228;
		aiDispersionCoefX = 21;
		aiDispersionCoefY = 24;
		aimTransitionSpeed = 1;
		aiRateOfFire = 0.5;
		aiRateOfFireDispersion = 0;
		aiRateOfFireDistance = 500;
		author = "885th Bloodpack Divison";
		scope = 2;
		inertia = 0.8;
		canShootInWater = 1;
		displayName = "[885th] Z-6 Rotary Cannon";
		descriptionShort = "Do we take Prisoners? I don't.";
		deployedPivot = "bipod";
		picture = "Indecisive_Armoury_Weapons_REPUBLIC\Data\Z6\Z6_ui.paa";
		model = "Indecisive_Armoury_Weapons_REPUBLIC\Data\Z6\Model\IDA_Z6.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "\MRC\JLTS\weapons\Z6\anims\Z6_handanim.rtm"};
		ace_clearJamAction = "";
		reloadAction = "GestureReload_IDA_Reload_Blaster";
		reloadTime = 0.15;
		recoil = "885_recoil_Z6";
		recoilProne = "assaultRifleBase";
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\Blaster_reload_Vent.ogg", 1.5, 1, 100};
		magazines[] = {"885th_battery_high_blue", "885th_battery_amp_blue"};
		magazineWell[] = {};
		magazineReloadTime = 0.0;
		magazineReloadSwitchPhase = 0.5;
		fireLightDiffuse[] = {0.1, 0.25, 1};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		muzzles[] = {"this","885th_Z6_HE"};
		modes[] = {"FullAuto"};
		class FullAuto : Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\Z6.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\Z6.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\Z6.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\Z6.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\Z6.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\Z6.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.08;
			dispersion = 0.0065;
			burst = 1;
			soundContinuous = "false";
			soundBurst = "true";
			minRange = 0;
			minRangeProbab = 1.0;
			midRange = 500;
			midRangeProbab = 1.0;
			maxRange = 1000;
			maxRangeProbab = 0.6;
		};
		class 885th_Z6_HE: Rifle_Long_Base_F
		{
			displayName="Explosive Charge";
			descriptionShort="Z6 Explosive Charge";
			useModelOptics=1;
			useExternalOptic=1;
			maxZeroing=1800;
			maxRecoilSway=0.029999999;
			swayDecaySpeed=1.25;
			discreteDistance[]={200,300,400,500,600};
			discreteDistanceInitIndex=1;
			distanceZoomMin=100;
			distanceZoomMax=350;
			cursor="srifle";
			inertia=1.2;
			aimTransitionSpeed=0.5;
			dexterity=1;
			magazines[]={"885th_Z6_he_battery_Blue"};
			magazineWell[]={};
			class GunParticles: GunParticles
			{
				class SecondEffect
				{
					positionName="Nabojnicestart";
					directionName="Nabojniceend";
					effectName="CaselessAmmoCloud";
				};
			};
			selectionFireAnim="zasleh";
			flash="gunfire";
			flashSize=3;
			modes[]=
			{
				"Single"
			};
			reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\Blaster_reload_Vent.ogg", 1.5, 1, 100};
			drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
			class Single: Mode_SemiAuto
			{
				sounds[]=
				{
					"StandardSound"
				};
				class BaseSoundModeType
				{
					begin1[]=
				{
					"885_Sounds\Z6HE.ogg",
					1.9952624,
					1,
					900
				};
				soundBegin[] = {"begin1", 0.2};
				};
				class StandardSound: BaseSoundModeType
				{
					closure1[]=
					{
						"885_Sounds\Z6HECooldown.ogg",
						2.2,
						1,
						40
					};
					soundClosure[]=
					{
						"closure1",
						0.1
					};
				};
				class SoundTails
				{
					class TailInterior
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_interior",
							1,
							1,
							300
						};
						frequency=1;
						volume="interior";
					};
					class TailTrees
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_trees",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_forest",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*forest";
					};
					class TailMeadows
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_meadows",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_houses",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*houses";
					};
				};
				reloadTime=2.3;
				dispersion=0.00015000001;
				recoil="recoil_single_gm6";
				recoilProne="recoil_single_prone_gm6";
				minRange=2;
				minRangeProbab=0.5;
				midRange=150;
				midRangeProbab=0.69999999;
				maxRange=450;
				maxRangeProbab=0.30000001;
				aiRateOfFire=3;
				aiRateOfFireDistance=500;
			};
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 100;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
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
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
	};
	class 885th_MuzzleSlot_Z6;
	class 885th_CowsSlot_Z6;
	class 885th_UnderBarrelSlot_Z6;
	class 885th_Z6Para_Base_F: Rifle_Base_F
	{
		author="885th Bloodpack Division";
		magazines[] = {"885th_battery_low_blue"};
		magazineWell[] = {};
		magazineReloadSwitchPhase=0.5;
		reloadAction="GestureReloadMX";
		recoil="3AS_recoil_z6";
		maxZeroing=1000;
		discreteDistanceInitIndex=0;
		maxRecoilSway=0.0125;
		swayDecaySpeed=1.25;
		inertia=1.1;
		aimTransitionSpeed=0.60000002;
		dexterity=1.4;
		initSpeed=-1;
		deployedPivot="bipod";
		hasBipod=1;
		soundBipodDown[]=
		{
			"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_down",
			0.70794576,
			1,
			20
		};
		soundBipodUp[]=
		{
			"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_up",
			0.70794576,
			1,
			20
		};
		class GunParticles: GunParticles
		{
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=350;
			class MuzzleSlot: 885th_MuzzleSlot_Z6
			{
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
			};
			class CowsSlot: 885th_CowsSlot_Z6
			{
				iconPosition[]={0.5,0.34999999};
				iconScale=0.2;
			};
			class UnderBarrelSlot: 885th_UnderBarrelSlot_Z6
			{
				iconPosition[]={0.23999999,0.69999999};
				iconScale=0.30000001;
			};
		};
		distanceZoomMin=300;
		distanceZoomMax=300;
		descriptionShort="Lightweight Para Z6 meant for small team tactics.";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\3AS\3AS_Weapons\Republic\Z6\Data\Anim\Z6_handanim.rtm"
		};
		modes[]=
		{
			"manual",
			"close",
			"short",
			"medium",
			"far_optic1",
			"far_optic2"
		};
		class manual: Mode_FullAuto
		{
			reloadTime="60 / 1200";
			dispersion=0.00147;
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_Z6_SoundSet"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
			};
			soundContinuous=0;
			soundBurst=0;
		};
		class close: manual
		{
			burst=10;
			aiRateOfFire=0.5;
			aiRateOfFireDistance=50;
			minRange=0;
			minRangeProbab=0.050000001;
			midRange=25;
			midRangeProbab=0.69999999;
			maxRange=50;
			maxRangeProbab=0.039999999;
			showToPlayer=0;
		};
		class short: close
		{
			burst=5;
			aiRateOfFire=2;
			aiRateOfFireDistance=200;
			minRange=50;
			minRangeProbab=0.050000001;
			midRange=200;
			midRangeProbab=0.69999999;
			maxRange=400;
			maxRangeProbab=0.039999999;
		};
		class medium: close
		{
			burst=3;
			aiRateOfFire=4;
			aiRateOfFireDistance=600;
			aiRateOfFireDispersion=2;
			minRange=400;
			minRangeProbab=0.050000001;
			midRange=600;
			midRangeProbab=0.60000002;
			maxRange=800;
			maxRangeProbab=0.1;
		};
		class far_optic1: close
		{
			requiredOpticType=1;
			burst=3;
			aiRateOfFire=9;
			aiRateOfFireDistance=1000;
			aiRateOfFireDispersion=3;
			minRange=800;
			minRangeProbab=0.039999999;
			midRange=1000;
			midRangeProbab=0.5;
			maxRange=1200;
			maxRangeProbab=0.0099999998;
		};
		class far_optic2: far_optic1
		{
			requiredOpticType=2;
			autoFire=0;
			burst=1;
			aiRateOfFire=12;
			aiRateOfFireDistance=1600;
			aiRateOfFireDispersion=4;
			minRange=1200;
			minRangeProbab=0.050000001;
			midRange=1600;
			midRangeProbab=0.5;
			maxRange=2000;
			maxRangeProbab=0.0099999998;
		};
		aiDispersionCoefY=20;
		aiDispersionCoefX=15;
		caseless[]=
		{
			"",
			1,
			1,
			1
		};
		soundBullet[]=
		{
			"caseless",
			1
		};
		drySound[]=
		{
			"\3AS\3AS_Main\Sounds\Blaster_empty",
			2,
			1,
			20
		};
		reloadMagazineSound[]=
		{
			"\3AS\3AS_Main\Sounds\DC15A\DC15aReload",
			1,
			1,
			30
		};
		ace_overheating_mrbs=300000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=0.75;
	};
	class 885th_Z6Para_F: 885th_Z6Para_Base_F
	{
		author="885th Bloodpack Division";
		baseWeapon="885th_Z6Para_F";
		scope=2;
		displayName="[885th] Z-6 Para";
		model="\3AS\3AS_Weapons\Republic\Z6\3AS_Z6_F.p3d";
		picture="\3AS\3AS_Weapons\Republic\Z6\Data\UI\3as_z6.paa";
		UiPicture="\A3\weapons_f\data\UI\icon_regular_CA.paa";
	};
	class 885th_EPL2: arifle_MX_Base_F
	{
		JLTS_hasElectronics=1;
		JLTS_hasEMPProtection=1;
		JLTS_friedItem="";
		author="885th Bloodpack Division";
		scope=2;
		displayName="[885th] EPL2";
		descriptionShort="$STR_JLTS_descs_EMPL";
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\EPL2\data\EPL2_co.paa",
			"\MRC\JLTS\weapons\EPL2\data\EPL2_mag_co.paa"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\MRC\JLTS\weapons\EPL2\anims\EPL2_handanim.rtm"
		};
		magazines[]=
		{
			"885th_EPL2_mag"
		};
		magazineWell[]={};
		fireLightDiffuse[]={0,0,1};
		drySound[]=
		{
			"MRC\JLTS\weapons\Core\sounds\weapon_dry.wss",
			5,
			1,
			10
		};
		modes[]=
		{
			"Single"
		};
		memoryPointCamera="eye";
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"MRC\JLTS\weapons\EPL2\sounds\EPL2_fire",
					1,
					1,
					3000
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			reloadTime=1;
			recoil="recoil_single_mx";
			recoilProne="recoil_single_prone_mx";
			dispersion=0.00086999999;
			minRange=2;
			minRangeProbab=0.5;
			midRange=200;
			midRangeProbab=0.69999999;
			maxRange=400;
			maxRangeProbab=0.30000001;
		};
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"MRC\JLTS\weapons\EPL2\sounds\EPL2_fire",
					1,
					1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			reloadTime=0.096000001;
			dispersion=0.00086999999;
			recoil="recoil_auto_mx";
			recoilProne="recoil_auto_prone_mx";
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
			aiRateOfFire=1e-006;
		};
		class fullauto_medium: FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"MRC\JLTS\weapons\EPL2\sounds\EPL2_fire",
					1,
					1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			showToPlayer=0;
			burst=3;
			aiBurstTerminable=1;
			minRange=2;
			minRangeProbab=0.5;
			midRange=75;
			midRangeProbab=0.69999999;
			maxRange=150;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=200;
		};
		class single_medium_optics1: Single
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"MRC\JLTS\weapons\EPL2\sounds\EPL2_fire",
					1,
					1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			requiredOpticType=1;
			showToPlayer=0;
			minRange=2;
			minRangeProbab=0.2;
			midRange=450;
			midRangeProbab=0.69999999;
			maxRange=600;
			maxRangeProbab=0.2;
			aiRateOfFire=6;
			aiRateOfFireDistance=600;
		};
		class single_far_optics2: single_medium_optics1
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"MRC\JLTS\weapons\EPL2\sounds\EPL2_fire",
					1,
					1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			requiredOpticType=2;
			showToPlayer=0;
			minRange=100;
			minRangeProbab=0.1;
			midRange=500;
			midRangeProbab=0.60000002;
			maxRange=700;
			maxRangeProbab=0.050000001;
			aiRateOfFire=8;
			aiRateOfFireDistance=700;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=110;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]={"ShadwCmpany_optic_Reflex_Mk1"};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]={};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
			};
		};
		class GunParticles: GunParticles
		{
			delete SecondEffect;
		};
	};
	class 885th_MPL_Base_F: Rifle_Base_F
	{
		author="885th Bloodpack Division";
		magazines[]={"885th_MPL_3rnd_HE_Grenade","885th_Mpl_3rnd_Cluster_Grenade","885th_Mpl_3rnd_AP_Micro_Rocket"};
		magazineWell[]={"885th_MPL_MagWell"};
		reloadAction="3AS_GestureReloadMPL";
		magazineReloadSwitchPhase=0.40000001;
		recoil="3as_recoil_heavy";
		maxRecoilSway=0.0125;
		swayDecaySpeed=1.25;
		inertia=0.40000001;
		dexterity=1.6;
		initSpeed=-1;
		maxZeroing=1000;
		cameraDir="OP_look";
		discreteDistance[]={50,75,100,150,200,250,300};
		discreteDistanceCameraPoint[]=
		{
			"OP_eye_50",
			"OP_eye_75",
			"OP_eye_100",
			"OP_eye_150",
			"OP_eye_200",
			"OP_eye_250",
			"OP_eye_300"
		};
		discreteDistanceInitIndex=1;
		weaponInfoType="RscWeaponZeroing";
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: MuzzleSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]={};
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
			};
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]={};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]={};
			};
		};
		opticsZoomMin=0.25;
		opticsZoomMax=1.25;
		opticsZoomInit=0.75;
		distanceZoomMin=400;
		distanceZoomMax=400;
		descriptionShort="Multi Purpose Grenade Launcher";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\3AS\3AS_Weapons\MPL\data\anims\MPLhand.rtm"
		};
		selectionFireAnim="zasleh";
		flash="gunfire";
		flashSize=3;
		modes[]=
		{
			"Single",
			"Burst"
		};
		class Burst: Mode_Burst
		{
			reloadTime=0.25;
			dispersion=0.0057899999;
			minRange=30;
			minRangeProbab=0.89999998;
			midRange=65;
			midRangeProbab=0.69999999;
			maxRange=100;
			maxRangeProbab=0.1;
			soundContinuous=0;
			soundBurst=0;
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
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
		class Single: Mode_SemiAuto
		{
			reloadTime=0.75;
			dispersion=0.0057899999;
			minRange=75;
			minRangeProbab=0.89999998;
			midRange=250;
			midRangeProbab=0.69999999;
			maxRange=400;
			maxRangeProbab=0.1;
			soundContinuous=0;
			soundBurst=0;
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
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
		aiDispersionCoefY=6;
		aiDispersionCoefX=4;
		caseless[]=
		{
			"",
			1,
			1,
			1
		};
		soundBullet[]=
		{
			"caseless",
			1
		};
		changeFiremodeSound[]=
		{
			"A3\Sounds_F\arsenal\weapons\UGL\Firemode_ugl",
			0.316228,
			1,
			5
		};
		reloadMagazineSound[]=
		{
			"A3\Sounds_F\arsenal\weapons\UGL\Reload_UGL",
			0.56234097,
			1,
			10
		};
		drySound[]=
		{
			"A3\Sounds_F\arsenal\weapons\UGL\Dry_ugl",
			0.56234097,
			1,
			10
		};
	};
	class 885th_MPL_F: 885th_MPL_Base_F
	{
		author="885th Bloodpack Division";
		scope=2;
		displayName="[885th] MPL";
		model="3as\3AS_Weapons\MPL\3AS_MPL.p3d";
		picture="\3AS\3AS_Weapons\MPL\Data\UI\3as_mpl.paa";
		weaponInfoType="RscWeaponZeroing";
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=60;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"885th_reflex_Optic"};
			};
		};
	};
	class 885th_773_base: Rifle_Base_F
	{
		author="885th Bloodpack Division + Antauri";
		scope=0;
		canShootInWater=1;
		_generalMacro="885th_773_base";
		maxZeroing=2200;
		maxRecoilSway=0.029999999;
		swayDecaySpeed=1.25;
		distanceZoomMin=100;
		distanceZoomMax=350;
		cursor="srifle";
		discreteDistance[]={200,300,400,500,600};
		discreteDistanceInitIndex=1;
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\A3\Weapons_F_beta\Rifles\MK20\Data\Anim\mk20G.rtm"
		};
		opticsPPEffects[]={};
		opticsFlare=1;
		opticsDisablePeripherialVision=1;
		reloadAction="GestureReloadDMR05";
		reloadMagazineSound[]=
		{
			"\ShadowLegion_Weapons\data\reloads\sounds\Reload_1.ogg",
			2,
			1,
			30
		};
		soundBipodDeploy[]=
		{
			"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_deploy",
			0.70794576,
			1,
			20
		};
		soundBipodFold[]=
		{
			"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_fold",
			0.70794576,
			1,
			20
		};
		soundBipodDown[]=
		{
			"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_down",
			0.70794576,
			1,
			20
		};
		soundBipodUp[]=
		{
			"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_up",
			0.70794576,
			1,
			20
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=100;
			class MuzzleSlot: MuzzleSlot
			{
				compatibleitems[]=
				{
					"ShadwCmpany_Suppresor_773_DMR_1",
					"ShadwCmpany_Suppresor_773_DMR_2",
					"ShadwCmpany_Suppresor_773_DMR_3"
				};
			};
			class CowsSlot: CowsSlot
			{
				compatibleitems[]=
				{
					"ShadwCmpany_optic_Reflex_Mk1",
					"ShadwCmpany_optic_Reflex_Mk1_Alt1",
					"ShadwCmpany_optic_Reflex_Mk1_Alt2",
					"ShadwCmpany_Hybrid_Magnifier_Holo",
					
					"ShadwCmpany_773_Hybrid_Magnifier_Holo",
					"ShadwCmpany_773_Hybrid_Magnifier_Magnified",
					"ShadwCmpany_Electroscope",
					"ShadwCmpany_Electroscope_Standalone",
					"ShadwCmpany_optic_e11",
					"ShdwCmpny_Optic_Scope_WestarM5",
					"ShdwCmpny_Optic_LEScope_DC15A_mk2"
				};
			};
			class PointerSlot: PointerSlot
			{
				iconPosition[]={0.22,0.43000001};
				iconScale=0.25;
				compatibleitems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR",
					"ace_acc_pointer_red",
					"ace_acc_pointer_green",
					"ShdwCmpny_Light_MPD",
					"ShdwCmpny_IR_MPD"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot_rail
			{
				iconPosition[]={0.2,0.80000001};
				iconScale=0.30000001;
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]=
				{
					"ShdwCmpny_Bipod_Valken"
				};
			};
		};
		modes[]=
		{
			"Single",
			"far_optic1",
			"medium_optic2",
			"far_optic2"
		};
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType
			{
				closure1[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]={"885_Sounds\773_Fire.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\773_Fire.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"885_Sounds\773_Fire.ogg",1, 1, 200};
				soundBegin[]=
				{
					"begin1",
					0.33000001
				};
				class SoundTails
				{
					class TailInterior
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_interior",
							1,
							1,
							300
						};
						frequency=1;
						volume="interior";
					};
					class TailTrees
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_trees",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_forest",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*forest";
					};
					class TailMeadows
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_meadows",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_houses",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*houses";
					};
				};
			};
			reloadTime=0.55000001;
			dispersion=0.00015000001;
			recoil="recoil_single_gm6";
			recoilProne="recoil_single_prone_gm6";
			minRange=2;
			minRangeProbab=0.5;
			midRange=150;
			midRangeProbab=0.69999999;
			maxRange=450;
			maxRangeProbab=0.30000001;
			aiRateOfFire=3;
			aiRateOfFireDistance=500;
		};
		class far_optic1: Single
		{
			showToPlayer=0;
			minRange=150;
			minRangeProbab=0.2;
			midRange=500;
			midRangeProbab=0.69999999;
			maxRange=1500;
			maxRangeProbab=0.40000001;
			aiRateOfFire=3;
			aiRateOfFireDistance=500;
			requiredOpticType=1;
		};
		class medium_optic2: Single
		{
			showToPlayer=0;
			minRange=250;
			minRangeProbab=0.2;
			midRange=750;
			midRangeProbab=0.69999999;
			maxRange=1000;
			maxRangeProbab=0.40000001;
			aiRateOfFire=5;
			aiRateOfFireDistance=1000;
			requiredOpticType=2;
		};
		class far_optic2: far_optic1
		{
			minRange=500;
			minRangeProbab=0.2;
			midRange=1200;
			midRangeProbab=0.69999999;
			maxRange=2100;
			maxRangeProbab=0.30000001;
			aiRateOfFire=7;
			aiRateOfFireDistance=1000;
			requiredOpticType=2;
		};
		drySound[]=
		{
			"\ShadowLegion_Weapons\data\reloads\sounds\Empty_1.ogg",
			5,
			1,
			20
		};
	};
	class 885th_773_BR: 885th_773_base
	{
		author="885th Bloodpack Division + Antauri";
		scope=2;
		_generalMacro="885th_773_BR";
		displayName = "[885th] 773BR Firepuncher";
		descriptionShort = "Mid to Long Range Battle Rifle.";
		model="\ShadowLegion_Weapons\data\773\model\773Shroud_Rifle.p3d";
		picture="\ShadowLegion_Weapons\data\773\UI\773Shroud_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\773\UI\773Shroud_UI.paa";
		recoil="885_recoil_dc15a";
		inertia=1.2;
		aimTransitionSpeed=0.5;
		dexterity=1;
		modes[] = {"Single","Burst"}; 
		magazines[] = {"885th_dc_cell_blue_high","885th_dc_cell_blue_over","885th_25Rnd_Tracerless_Cell"};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[]={"885_Sounds\773_Fire.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\773_Fire.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.18;
			dispersion = 0.00030;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 200;
			midRangeProbab = 1.0;
			maxRange = 900;
			maxRangeProbab = 0.8;
		};
		class Burst: Mode_Burst
		{
			burst = 3;
			rate = 0.10;
			textureType = "burst";
			reloadTime = 0.08;
			dispersion = 0.00002;
			flash = "gunfire";
			flashSize = 0.1;
			soundBurst = 0;
			soundContinuous = 0;
			maxRange = 2000;
			maxRangeProbab = 0.3;
			midRange = 1000;
			midRangeProbab = 0.7;
			minRange = 200;
			minRangeProbab = 0.5;
			aiDispersionCoefX = 1.4;
			aiDispersionCoefY = 1.7;
			aiRateOfFire = 2;
			aiRateOfFireDispersion = 1;
			aiRateOfFireDistance = 500;
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[]={"885_Sounds\773_Fire.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\773_Fire.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
		};
	};
	class 885th_773_Firepuncher: 885th_773_base
	{
		author="885th Bloodpack Division + Antauri";
		scope=2;
		_generalMacro="885th_773_Firepuncher";
		displayName="[885th] 773 Fire Puncher";
		descriptionShort="Dedicated Marksman Blaster variant of the 773 platform, Popular between specialized units after the rise of the empire";
		model="\ShadowLegion_Weapons\data\773\model\773Shroud_Rifle2.p3d";
		picture="\ShadowLegion_Weapons\data\773\UI\773FirePuncher_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\773\UI\773FirePuncher_UI.paa";
		inertia=0.80000001;
		aimTransitionSpeed=0.80000001;
		dexterity=1;
		recoil="recoil_spar_dmr";
		magazines[]=
		{
			"885th_dc_cell_blue_high",
			"885th_25Rnd_Tracerless_Cell"
		};
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType
			{
				closure1[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]={"885_Sounds\773_Fire.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\773_Fire.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]=
				{
					"885_Sounds\773_Fire.ogg",
					1,
					1,
					200
				};
				soundBegin[]=
				{
					"begin1",
					0.33000001
				};
				class SoundTails
				{
					class TailInterior
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_interior",
							1,
							1,
							300
						};
						frequency=1;
						volume="interior";
					};
					class TailTrees
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_trees",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_forest",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*forest";
					};
					class TailMeadows
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_meadows",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_houses",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*houses";
					};
				};
			};
			reloadTime=0.17141999;
			dispersion=0.00025000001;
			recoilProne="IDA_recoil_HeavyBlasterRifle";
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=3;
			aiRateOfFireDistance=500;
		};
	};
	class 885th_773_Firepuncher_MKII: 885th_773_base
	{
		author="885th Bloodpack Division + Antauri";
		scope=2;
		_generalMacro="885th_773_Firepuncher_MKII";
		displayName="[885th] 773 Fire Puncher MK II";
		descriptionShort="Modified Version of the 773";
		model="\ShadowLegion_Weapons\data\773\model\773Shroud_Rifle2.p3d";
		picture="\ShadowLegion_Weapons\data\773\UI\773FirePuncher_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\773\UI\773FirePuncher_UI.paa";
		inertia=0.80000001;
		aimTransitionSpeed=0.80000001;
		dexterity=1;
		recoil="recoil_spar_dmr";
		magazines[]=
		{
			"885th_dc_cell_blue_high",
			"885th_dc_cell_blue_over",
			"885th_25Rnd_Tracerless_Cell"
		};
		muzzles[] = {"this","885th_773_Firepuncher_MKII_Flame"};
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType
			{
				closure1[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]={"885_Sounds\773_Fire.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\773_Fire.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]=
				{
					"885_Sounds\773_Fire.ogg",
					1,
					1,
					200
				};
				soundBegin[]=
				{
					"begin1",
					0.33000001
				};
				class SoundTails
				{
					class TailInterior
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_interior",
							1,
							1,
							300
						};
						frequency=1;
						volume="interior";
					};
					class TailTrees
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_trees",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_forest",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*forest";
					};
					class TailMeadows
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_meadows",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_houses",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*houses";
					};
				};
			};
			reloadTime=0.17141999;
			dispersion=0.00025000001;
			recoilProne="IDA_recoil_HeavyBlasterRifle";
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=3;
			aiRateOfFireDistance=500;
		};
		class 885th_773_Firepuncher_MKII_Flame: Rifle_Long_Base_F
		{
			displayName="Flame Shot";
			descriptionShort="773 Flame Shot";
			useModelOptics=1;
			useExternalOptic=1;
			maxZeroing=1800;
			maxRecoilSway=0.029999999;
			swayDecaySpeed=1.25;
			discreteDistance[]={200,300,400,500,600};
			discreteDistanceInitIndex=1;
			distanceZoomMin=100;
			distanceZoomMax=350;
			cursor="srifle";
			inertia=1.2;
			aimTransitionSpeed=0.5;
			dexterity=1;
			magazines[]={"885th_773_Flame_Cell"};
			magazineWell[]={};
			class GunParticles: GunParticles
			{
				class SecondEffect
				{
					positionName="Nabojnicestart";
					directionName="Nabojniceend";
					effectName="CaselessAmmoCloud";
				};
			};
			selectionFireAnim="zasleh";
			flash="gunfire";
			flashSize=3;
			modes[]=
			{
				"Single"
			};
			reloadMagazineSound[]=
			{
				"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\DMR_05_reload",
				0.25118864,
				4,
				10
			};
			class Single: Mode_SemiAuto
			{
				sounds[]=
				{
					"StandardSound"
				};
				class BaseSoundModeType
				{
					closure1[]=
					{
						"\ShadowLegion_Weapons\data\NT241\Cooldown_beep.ogg",
						2.2,
						1,
						40
					};
					soundClosure[]=
					{
						"closure1",
						0.1
					};
				};
				class StandardSound: BaseSoundModeType
				{
					begin1[]=
					{
						"885_Sounds\774_Flame_Shot.ogg",
						1,
						1,
						900
					};
					soundBegin[]=
					{
						"begin1",
						1.33
					};
				};
				class SoundTails
				{
					class TailInterior
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_interior",
							1,
							1,
							300
						};
						frequency=1;
						volume="interior";
					};
					class TailTrees
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_trees",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_forest",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*forest";
					};
					class TailMeadows
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_meadows",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[]=
						{
							"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_houses",
							1,
							1,
							300
						};
						frequency=1;
						volume="(1-interior/1.4)*houses";
					};
				};
				reloadTime=3.5;
				dispersion=0.00015000001;
				recoil="recoil_single_gm6";
				recoilProne="recoil_single_prone_gm6";
				minRange=2;
				minRangeProbab=0.5;
				midRange=150;
				midRangeProbab=0.69999999;
				maxRange=450;
				maxRangeProbab=0.30000001;
				aiRateOfFire=3;
				aiRateOfFireDistance=500;
			};
		};
		aiDispersionCoefY=6;
		aiDispersionCoefX=4;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=100;
			class MuzzleSlot: MuzzleSlot
			{
				compatibleitems[]=
				{
					"ShadwCmpany_Suppresor_773_DMR_3"
				};
			};
			class CowsSlot: CowsSlot
			{
				compatibleitems[]=
				{
					"ShadwCmpany_optic_Reflex_Mk1",
					"ShadwCmpany_optic_Reflex_Mk1_Alt1",
					"ShadwCmpany_optic_Reflex_Mk1_Alt2",
					"ShadwCmpany_Hybrid_Magnifier_Holo",
					
					"ShadwCmpany_773_Hybrid_Magnifier_Holo",
					"ShadwCmpany_773_Hybrid_Magnifier_Magnified",
					"ShadwCmpany_Electroscope",
					"ShadwCmpany_Electroscope_Standalone",
					"ShadwCmpany_optic_e11",
					"ShdwCmpny_Optic_Scope_WestarM5",
					"ShdwCmpny_Optic_LEScope_DC15A_mk2"
				};
			};
			class PointerSlot: PointerSlot
			{
				iconPosition[]={0.22,0.43000001};
				iconScale=0.25;
				compatibleitems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR",
					"ace_acc_pointer_red",
					"ace_acc_pointer_green",
					"ShdwCmpny_Light_MPD",
					"ShdwCmpny_IR_MPD"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot_rail
			{
				iconPosition[]={0.2,0.80000001};
				iconScale=0.30000001;
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]=
				{
					"ShdwCmpny_Bipod_Valken"
				};
			};
		};
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ShadwCmpany_Electroscope_Standalone";
			};
			class LinkedItemsAcc
			{
				slot="PointerSlot";
				item="acc_pointer_IR";
			};
			class LinkedItemsMuzzle
			{
				slot="MuzzleSlot";
				item="ShadwCmpany_Suppresor_773_DMR_3";
			};
		};
	};
	class 885th_773_FireSpitter: 885th_773_base
	{
		author="885th Bloodpack Division + Antauri";
		scope=2;
		_generalMacro="885th_773_FireSpitter";
		displayName="[885th] 773 FireSpitter";
		descriptionShort="an experimental Heavy Assault Carbine variant of the 773 platform, provides the operator to switch between specialized barrels for mission variety, but lacks of stopping power at expense of modularity";
		model="\ShadowLegion_Weapons\data\773\model\773Shroud_Rifle3.p3d";
		picture="\ShadowLegion_Weapons\data\773\UI\773FireSpitter_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\773\UI\773FireSpitter_UI.paa";
		recoil="recoil_mx";
		inertia=0.5;
		aimTransitionSpeed=1;
		dexterity=1;
		magazines[]=
		{
			"885th_dc_cell_blue",
			"885th_25Rnd_Tracerless_Cell"
		};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		modes[]=
		{
			"Single",
			"Burst",
			"FullAuto",
			"fullauto_medium",
			"single_medium_optics1",
			"single_far_optics2"
		};
		class Burst: Mode_Burst
		{
			reloadTime=0.050000001;
			dispersion=0.00026000003;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
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
				begin1[]={"885_Sounds\773_Fire.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\773_Fire.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.1;
			dispersion=0.00026000003;
			minRange=2;
			minRangeProbab=0.5;
			midRange=200;
			midRangeProbab=0.69999999;
			maxRange=400;
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
				begin1[]={"885_Sounds\773_Fire.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\773_Fire.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class FullAuto: Mode_FullAuto
		{
			reloadTime=0.079999998;
			dispersion=0.00036000001;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
			aiRateOfFire=1e-006;
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				begin1[]={"885_Sounds\773_Fire.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\773_Fire.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class fullauto_medium: FullAuto
		{
			showToPlayer=0;
			burst=3;
			aiBurstTerminable=1;
			minRange=2;
			minRangeProbab=0.5;
			midRange=75;
			midRangeProbab=0.69999999;
			maxRange=150;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=200;
		};
		class single_medium_optics1: Single
		{
			requiredOpticType=1;
			showToPlayer=0;
			minRange=2;
			minRangeProbab=0.2;
			midRange=450;
			midRangeProbab=0.69999999;
			maxRange=600;
			maxRangeProbab=0.2;
			aiRateOfFire=6;
			aiRateOfFireDistance=600;
		};
		class single_far_optics2: single_medium_optics1
		{
			requiredOpticType=2;
			showToPlayer=0;
			minRange=100;
			minRangeProbab=0.1;
			midRange=500;
			midRangeProbab=0.60000002;
			maxRange=700;
			maxRangeProbab=0.050000001;
			aiRateOfFire=8;
			aiRateOfFireDistance=700;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=100;
			class MuzzleSlot: MuzzleSlot
			{
				compatibleitems[]=
				{
					"ShadwCmpany_Barrel_773_1",
					"ShadwCmpany_Barrel_773_2",
					"ShadwCmpany_Barrel_773_3",
					"ShadwCmpany_Suppresor_Module_DC19"
				};
			};
		};
	};
	class 885th_773_FireSpitter_MKII: 885th_773_base
	{
		author="885th Bloodpack Division + Antauri";
		scope=2;
		_generalMacro="885th_773_FireSpitter";
		displayName="[885th] 773 FireSpitter MKII";
		descriptionShort="an experimental Heavy Assault Carbine variant of the 773 platform, provides the operator to switch between specialized barrels for mission variety, but lacks of stopping power at expense of modularity";
		model="\ShadowLegion_Weapons\data\773\model\773Shroud_Rifle4.p3d";
		picture="\ShadowLegion_Weapons\data\773\UI\773FireSpitter2_UI.paa";
		UiPicture="\ShadowLegion_Weapons\data\773\UI\773FireSpitter2_UI.paa";
		recoil="recoil_mx";
		inertia=0.5;
		aimTransitionSpeed=1;
		dexterity=1;
		magazines[]=
		{
			"885th_dc_cell_blue",
			"885th_25Rnd_Tracerless_Cell"
		};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		modes[]={"Burst"};
		class Burst: Mode_Burst
		{
			reloadTime=0.050000001;
			dispersion=0.00026000003;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
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
				begin1[]={"885_Sounds\773_Fire.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\773_Fire.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.1;
			dispersion=0.00026000003;
			minRange=2;
			minRangeProbab=0.5;
			midRange=200;
			midRangeProbab=0.69999999;
			maxRange=400;
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
				begin1[]={"885_Sounds\773_Fire.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\773_Fire.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class FullAuto: Mode_FullAuto
		{
			reloadTime=0.079999998;
			dispersion=0.00036000001;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
			aiRateOfFire=1e-006;
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				begin1[]={"885_Sounds\773_Fire.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\773_Fire.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\773_Fire.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\773_Fire.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin2[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin3[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin4[]={"ShadowLegion_Weapons\data\surpressed_2.ogg",1,1,100};
				begin5[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				begin6[]={"ShadowLegion_Weapons\data\surpressed_1.ogg",1,1,100};
				soundBegin[]={"begin1",0.5,"begin2",0.5,"begin3",0.5,"begin4",0.5,"begin5",0.5,"begin6",0.5};
				beginwater1[]={"\ShadowLegion_Weapons\data\Underwater_Firing.ogg",1,1,200};
				soundBeginWater[]={"beginwater1",0.5};
			};
		};
		class fullauto_medium: FullAuto
		{
			showToPlayer=0;
			burst=3;
			aiBurstTerminable=1;
			minRange=2;
			minRangeProbab=0.5;
			midRange=75;
			midRangeProbab=0.69999999;
			maxRange=150;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=200;
		};
		class single_medium_optics1: Single
		{
			requiredOpticType=1;
			showToPlayer=0;
			minRange=2;
			minRangeProbab=0.2;
			midRange=450;
			midRangeProbab=0.69999999;
			maxRange=600;
			maxRangeProbab=0.2;
			aiRateOfFire=6;
			aiRateOfFireDistance=600;
		};
		class single_far_optics2: single_medium_optics1
		{
			requiredOpticType=2;
			showToPlayer=0;
			minRange=100;
			minRangeProbab=0.1;
			midRange=500;
			midRangeProbab=0.60000002;
			maxRange=700;
			maxRangeProbab=0.050000001;
			aiRateOfFire=8;
			aiRateOfFireDistance=700;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=100;
			class MuzzleSlot: MuzzleSlot
			{
				compatibleitems[]=
				{
					"ShadwCmpany_Barrel_773_1",
					"ShadwCmpany_Barrel_773_2",
					"ShadwCmpany_Barrel_773_3",
					"ShadwCmpany_Suppresor_Module_DC19"
				};
			};
		};
	};
	
	// CIS
	class 885th_A180 : 3AS_A180_F
	{
		ace_overheating_mrbs = 5000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 127;
		access = 0;
		model = "3as\3AS_Weapons\A180\model\3AS_A180_F.p3d";
		picture = "3as\3AS_Weapons\A180\data\ui\3as_a180p_ca.paa";
		displayName = "[885th] A180 Sidearm";
		magazines[] = {"885th_e_cell_red_pistol"};
		magazineWell[] = {};
		nameSound = "Pistol";
		optics = 1;
		primary = 10;
		reloadAction = "3AS_Vent_Reload_Pistol";
		reloadMagazineSound[] = {"\3as\3AS_Main\Sounds\Reload\Venting_Sound.ogg", 2, 1, 30};
		reloadSound[] = {"", 1, 1};
		modes[] = {"Single"};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_pistol
		{
		};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\3as\3AS_Main\Sounds\A180\A180_Shot_1.ogg", 0.56, 1, 1800};
				begin2[] = {"\3as\3AS_Main\Sounds\A180\A180_Shot_2.ogg", 0.56, 1, 1800};
				begin3[] = {"\3as\3AS_Main\Sounds\A180\A180_Shot_3.ogg", 0.56, 1, 1800};
				begin4[] = {"\3as\3AS_Main\Sounds\A180\A180_Shot_4.ogg", 0.56, 1, 1800};
				begin5[] = {"\3as\3AS_Main\Sounds\A180\A180_Shot_5.ogg", 0.56, 1, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\MRC\JLTS\weapons\DC15X\sounds\dc15x_fire.wss", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.1;
			dispersion = 0.00040;
			minRange = 0;
			minRangeProbab = 1.0;
			midRange = 100;
			midRangeProbab = 0.9;
			maxRange = 500;
			maxRangeProbab = 0.4;
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 35;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
	};
	class 885th_E5 : arifle_MX_Base_F
	{
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 228;
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[885th] E-5 Carbine";
		descriptionShort = "Close range, Cheap and Efficient.";
		picture = "\Indecisive_Armoury_Weapons_CIS\Data\E5\E5_ui.paa";
		model = "Indecisive_Armoury_Weapons_CIS\Data\E5\Model\IDA_E5.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "Indecisive_Armoury_Anims\CIS\E5.rtm"};
		ace_clearJamAction = "";
		magazines[] = {"885th_e_cell_red"};
		magazineWell[] = {};
		fireLightDiffuse[]={1,0,0};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		modes[] = {"Single"};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\CIS\E5.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\CIS\E5.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\CIS\E5.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\CIS\E5.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\CIS\E5.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\CIS\E5.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.2;
			dispersion = 0.00200;
			minRange = 0;
			minRangeProbab = 1.0;
			midRange = 500;
			midRangeProbab = 0.7;
			maxRange = 1000;
			maxRangeProbab = 0.3;
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 65;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};
	class 885th_E5C : arifle_MX_Base_F
	{
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 228;
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[885th] E-5C Repeater";
		descriptionShort = "Close range, fast rate of fire.";
		picture = "\MRC\JLTS\weapons\e5c\data\ui\e5c_Stock_ui_ca.paa";
		model = "\MRC\JLTS\weapons\e5c\e5c_Stock.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "Indecisive_Armoury_Anims\CIS\E5.rtm"};
		ace_clearJamAction = "";
		magazines[] = {"885th_e_cell_red"};
		magazineWell[] = {};
		fireLightDiffuse[]={1,0,0};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		modes[] = {"FullAuto"};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		class FullAuto : Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\CIS\E5C.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\CIS\E5C.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\CIS\E5C.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\CIS\E5C.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\CIS\E5C.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\CIS\E5C.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.10;
			dispersion = 0.00106;
			minRange = 0;
			minRangeProbab = 1.0;
			midRange = 500;
			midRangeProbab = 0.8;
			maxRange = 1000;
			maxRangeProbab = 0.2;
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 65;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
		class OpticsModes
		{
			class Iron
			{
				opticsID = 1;
				useModelOptics = 0;
				opticsPPEffects[] = {"", ""};
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.25;
				opticsZoomInit = 0.75;
				discreteDistance[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
				discreteDistanceInitIndex = 1;
				distanceZoomMin = 200;
				distanceZoomMax = 200;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
			};
			class DC15S_Scope
			{
				opticsID = 2;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsRadialBlur1", "OpticsBlur1"};
				opticsZoomMin = 0.125;
				opticsZoomMax = 0.125;
				opticsZoomInit = 0.125;
				discreteDistance[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
				discreteDistanceInitIndex = 1;
				distanceZoomMin = 100;
				distanceZoomMax = 1000;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				cameraDir = "";
			};
		};
	};
	class 885th_E5S : arifle_MX_Base_F
	{
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 609;
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[885th] E-5S Sniper Rifle";
		descriptionShort = "Long Range, Cheap and Efficient.";
		picture = "\MRC\JLTS\weapons\E5S\data\ui\E5S_ui_ca.paa";
		model = "\MRC\JLTS\weapons\E5S\E5S.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "\MRC\JLTS\weapons\E5S\anims\E5S_handanim.rtm"};
		ace_clearJamAction = "";
		magazines[] = {"885th_e_cell_red_amp"};
		magazineWell[] = {};
		modes[] = {"Single"};
		fireLightDiffuse[]={1,0,0};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		modelOptics = "\MRC\JLTS\weapons\E5S\E5S_reticle.p3d";
		opticsZoomMin = 0.125;
		opticsZoomMax = 1.1;
		opticsZoomInit = 0.75;
		muzzles[] = {"this"};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\CIS\E5.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\CIS\E5.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\CIS\E5.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\CIS\E5.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\CIS\E5.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\CIS\E5.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.5;
			dispersion = 0.00200;
			minRange = 0;
			minRangeProbab = 0.4;
			midRange = 500;
			midRangeProbab = 1.0;
			maxRange = 2000;
			maxRangeProbab = 0.7;
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 65;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
	};
	class 885th_WristBlaster : 885th_E5C
	{
		access = 0;
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 228;
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[885th] Wrist Blaster";
		descriptionShort = "Close range, fast rate of fire.";
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_plastic_ui_ca.paa";
		model = "3AS\3AS_Weapons\DWBlaster\3AS_DWBlaster_F.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "3AS\3AS_Weapons\DWBlaster\Data\Anim\DualWrist_handanim.rtm"};
		ace_clearJamAction = "";
		magazines[] = {"885th_e_battery_red_high", "885th_mando_battery_yellow_high"};
		magazineWell[] = {};
		modes[] = {"FullAuto"};
		fireLightDiffuse[]={1,0,0};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		muzzles[] = {"this", "WristRocket"};
		class FullAuto : Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\CIS\WristBlaster.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\CIS\WristBlaster.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\CIS\WristBlaster.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\CIS\WristBlaster.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\CIS\WristBlaster.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\CIS\WristBlaster.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.15;
			dispersion = 0.00300;
			burst = 1;
			soundContinuous = "false";
			soundBurst = "true";
			minRange = 0;
			minRangeProbab = 1.0;
			midRange = 750;
			midRangeProbab = 0.7;
			maxRange = 1500;
			maxRangeProbab = 0.1;
		};
		class WristRocket : UGL_F
		{
			displayName = "Wrist Rocket";
			descriptionShort = "Watch those wrist rockets!";
			useModelOptics = 0;
			useExternalOptic = 0;
			cameraDir = "OP_look";
			fireLightDiffuse[] = {1, 0, 0};
			discreteDistance[] = {100, 200, 300, 400};
			discreteDistanceCameraPoint[] =
				{
					"OP_eye",
					"OP_eye2",
					"OP_eye3",
					"OP_eye4"
				};
			discreteDistanceInitIndex = 0;
			magazines[] =
				{
					"IDA_wrist_rocket"};
			modes[] =
				{
					"Fire"};
			magazineWell[] = {};
			class Fire : Mode_SemiAuto
			{
				sounds[] =
					{
						"StandardSound"};
				class BaseSoundModeType
				{
					weaponSoundEffect = "";
					closure1[] = {};
					closure2[] = {};
					soundClosure[] = {};
				};
				class StandardSound : BaseSoundModeType
				{
					weaponSoundEffect = "";
					begin1[] =
						{
							"\Indecisive_Armoury_Sounds\CIS\WristRocket.ogg",
							4,
							1,
							3000};
					soundBegin[] =
						{
							"begin1",
							1};
				};
				reloadTime = 0.1;
				dispersion = 0;
				minRange = 2;
				minRangeProbab = 0.01;
				midRange = 300;
				midRangeProbab = 0.75;
				maxRange = 800;
				maxRangeProbab = 0.8;
			};
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 65;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};\
	};
	// Mandalorian
	
	class 885th_Westar35 : IDA_Westar35
	{
		ace_overheating_mrbs = 5000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 127;
		access = 0;
		baseWeapon = "885th_Westar35";
		model = "Indecisive_Armoury_Weapons_INDEP\Data\Westar35\Model\IDA_Westar35.p3d";
		picture = "Indecisive_Armoury_Weapons_INDEP\Data\Westar35\Westar35_ui.paa";
		displayName = "[885th] Westar-35 Blaster Pistol";
		descriptionShort = "MandalTech Blaster Pistol";
		magazines[] = {"885th_mando_cell_yellow_pistol"};
		magazineWell[] = {};
		nameSound = "Pistol";
		optics = 1;
		primary = 10;
		reloadAction = "GestureReload_IDA_Reload_BlasterPistol";
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\Blaster_reload_Vent.ogg", 1.5, 1, 100};
		reloadSound[] = {"", 1, 1};
		fireLightDiffuse[]={1,1,0};
		modes[] = {"Single"};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_pistol
		{
		};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\INDEP\Westar35.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\INDEP\Westar35.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\INDEP\Westar35.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\INDEP\Westar35.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\INDEP\Westar35.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\INDEP\Westar35.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.1;
			dispersion = 0.00040;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 35;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
	}
	class 885th_Galaar15 : arifle_MX_Base_F
	{
		ace_overheating_mrbs = 5000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 264;
		author = "885th Bloodpack Division + IDA Dev Team";
		scope = 2;
		inertia = 0.25;
		primary = 10;
		canShootInWater = 1;
		displayName = "[885th] Galaar-15 Carbine";
		descriptionShort = "Mandalorian Blaster Carbine.";
		picture = "Indecisive_Armoury_Weapons_INDEP\Data\Galaar15\Galaar15_ui.paa";
		model = "Indecisive_Armoury_Weapons_INDEP\Data\Galaar15\Model\IDA_Galaar15.p3d";
		modelOptics = "\Indecisive_Armoury_Weapons_Imperial\Data\LowPower_Scope\IDA_LowPower_Scope_Red.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "Indecisive_Armoury_Anims\Republic\DC15S.rtm"};
		ace_clearJamAction = "";
		reloadAction = "GestureReload_IDA_Reload_Blaster";
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\blaster_reload_1.ogg", 1.5, 1, 100};
		recoil = "885_recoil_dc15s";
		magazines[] = {"885th_mando_cell_yellow"};
		magazineWell[] = {};
		fireLightDiffuse[]={1,1,0};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		modes[] = {"Single", "FullAuto"};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\INDEP\Galaar15.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\INDEP\Galaar15.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\INDEP\Galaar15.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\INDEP\Galaar15.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\INDEP\Galaar15.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\INDEP\Galaar15.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.2;
			dispersion = 0.00200;
			minRange = 0;
			minRangeProbab = 1.0;
			midRange = 500;
			midRangeProbab = 0.8;
			maxRange = 1000;
			maxRangeProbab = 0.3;
		};
		class FullAuto : Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\INDEP\Galaar15.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\INDEP\Galaar15.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\INDEP\Galaar15.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\INDEP\Galaar15.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\INDEP\Galaar15.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\INDEP\Galaar15.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.15;
			dispersion = 0.00300;
			minRange = 0;
			minRangeProbab = 1.0;
			midRange = 500;
			midRangeProbab = 0.8;
			maxRange = 1000;
			maxRangeProbab = 0.3;
		};
		distanceZoomMin = 400;
		distanceZoomMax = 400;
		weaponInfoType = "RscOptics_nightstalker";
		class OpticsModes
		{
			class Iron
			{
				opticsID = 1;
				useModelOptics = 0;
				opticsPPEffects[] = {"", ""};
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.25;
				opticsZoomInit = 0.75;
				discreteDistance[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
				discreteDistanceInitIndex = 1;
				distanceZoomMin = 200;
				distanceZoomMax = 200;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
			};
			class DC15S_Scope
			{
				opticsID = 2;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsRadialBlur1", "OpticsBlur1"};
				opticsZoomMin = 0.125;
				opticsZoomMax = 0.125;
				opticsZoomInit = 0.125;
				discreteDistance[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
				discreteDistanceInitIndex = 1;
				distanceZoomMin = 100;
				distanceZoomMax = 1000;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				cameraDir = "";
			};
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 65;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"IDA_TargetingScope", "3AS_optic_acog_DC15C", "3AS_optic_reflex_DC15C", "885th_Optic_Scope_WestarM5"};
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
	class 885th_Galaar90 : arifle_MX_Base_F
	{
		ace_overheating_mrbs = 5000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 650;
		author = "885th Bloodpack Division + IDA Dev Team";
		scope = 2;
		inertia = 0.25;
		primary = 10;
		canShootInWater = 1;
		displayName = "[885th] Galaar-90 Sniper Rifle";
		descriptionShort = "Mandalorian Sniper Rifle.";
		picture = "Indecisive_Armoury_Weapons_INDEP\Data\Galaar90\Galaar90_ui.paa";
		model = "Indecisive_Armoury_Weapons_INDEP\Data\Galaar90\Model\IDA_Galaar90.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "\MRC\JLTS\weapons\DC15X\anims\DC15X_handanim.rtm"};
		ace_clearJamAction = "";
		reloadAction = "GestureReload_IDA_Reload_Blaster";
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\blaster_reload_1.ogg", 1.5, 1, 100};
		recoil = "885_recoil_dc15x";
		magazines[] = {"885th_mando_cell_yellow_high", "885th_mando_cell_yellow_amp"};
		magazineWell[] = {};
		modes[] = {"Single"};
		fireLightDiffuse[]={1,1,0};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		muzzles[] = {"this"};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\Republic\773Firepuncher.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\Republic\773Firepuncher.ogg", 1.45, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\Republic\773Firepuncher.ogg", 1.35, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\Republic\773Firepuncher.ogg", 1.15, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\Republic\773Firepuncher.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\Republic\773Firepuncher.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.2;
			dispersion = 0.00200;
			minRange = 10;
			minRangeProbab = 0.8;
			midRange = 800;
			midRangeProbab = 1.0;
			maxRange = 1500;
			maxRangeProbab = 0.6;
		};
		class FullAuto : Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\REPUBLIC\DC15A.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.15;
			dispersion = 0.00300;
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 300;
			maxRangeProbab = 0.3;
		};
		distanceZoomMin = 400;
		distanceZoomMax = 400;
		weaponInfoType = "RscOptics_nightstalker";
		modelOptics = "\Indecisive_Armoury_Weapons_REPUBLIC\Data\LowPower_Scope\IDA_LowPower_Scope_Blue.p3d";
		class OpticsModes
		{
			class Iron
			{
				opticsID = 1;
				useModelOptics = 0;
				opticsPPEffects[] = {"", ""};
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.25;
				opticsZoomInit = 0.75;
				discreteDistance[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
				discreteDistanceInitIndex = 1;
				distanceZoomMin = 200;
				distanceZoomMax = 200;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
			};
			class DC15S_Scope
			{
				opticsID = 2;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsRadialBlur1", "OpticsBlur1"};
				opticsZoomMin = 0.125;
				opticsZoomMax = 0.125;
				opticsZoomInit = 0.125;
				discreteDistance[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
				discreteDistanceInitIndex = 1;
				distanceZoomMin = 100;
				distanceZoomMax = 1000;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				cameraDir = "";
			};
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 65;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"IDA_TargetingScope", "3AS_optic_acog_DC15C", "3AS_optic_reflex_DC15C", "885th_Optic_Scope_WestarM5"};
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
	// Black Sun
	class 885th_S5Security : 3AS_S5_F
	{
		ace_overheating_mrbs = 5000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 114.3;
		access = 0;
		model = "3as\3as_weapons\S5\3AS_S5_f.p3d";
		picture = "\3AS\3AS_Weapons\S5\Data\UI\3as_s5.paa";
		displayName = "[885th] S-5 Security Pistol";
		descriptionShort = "Naboo 'climbing pistol' - heavy blaster.";
		magazines[] = {"885th_cell_green_pistol"};
		magazineWell[] = {};
		nameSound = "Pistol";
		optics = 1;
		primary = 10;
		reloadAction = "GestureReloadPistol";
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\blaster_reload_1.ogg", 1.5, 1, 100};
		reloadSound[] = {"", 1, 1};
		modes[] = {"Single"};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_pistol
		{
		};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\INDEP\Westar35.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\INDEP\Westar35.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\INDEP\Westar35.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\INDEP\Westar35.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\INDEP\Westar35.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\INDEP\Westar35.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.1;
			dispersion = 0.00040;
			minRange = 0;
			minRangeProbab = 1.0;
			midRange = 100;
			midRangeProbab = 0.8;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 35;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot : PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot : UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName = "Konec hlavne";
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
			};
		};
	}
	class 885th_FA11 : arifle_MX_Base_F
	{
		ace_overheating_mrbs = 5000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 228;
		author = "885th Bloodpack Division + IDA Dev Team";
		scope = 2;
		inertia = 0.25;
		primary = 10;
		canShootInWater = 1;
		displayName = "[885th] FA-11 Blaster Rifle";
		descriptionShort = "I think someone lost some experimental E-11 parts in a Geonosian Workshop.";
		picture = "Indecisive_Armoury_Weapons_INDEP\Data\FA11\FA11_ui.paa";
		model = "Indecisive_Armoury_Weapons_INDEP\Data\FA11\Models\IDA_FA11.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "\A3\Weapons_F_Exp\Rifles\SPAR_01\Data\Anim\SPAR_01.rtm"};
		ace_clearJamAction = "";
		reloadAction = "GestureReload_IDA_Reload_Blaster";
		reloadMagazineSound[] = {"\Indecisive_Armoury_Sounds\Blaster_reload_Vent.ogg", 1.5, 1, 100};
		recoil = "recoil_ak12";
		recoilProne = "assaultRifleBase";
		magazines[] = {"885th_cell_green_high"};
		magazineWell[] = {};
		modes[] = {"Single", "FullAuto"};
		fireLightDiffuse[]={0,1,0};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		class Single : Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\INDEP\FA11.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\INDEP\FA11.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\INDEP\FA11.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\INDEP\FA11.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\INDEP\FA11.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\INDEP\FA11.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.2;
			dispersion = 0.00200;
			minRange = 0;
			minRangeProbab = 1.0;
			midRange = 500;
			midRangeProbab = 0.7;
			maxRange = 1000;
			maxRangeProbab = 0.3;
		};
		class FullAuto : Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\INDEP\FA11.ogg", 1.25, 1, 1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\INDEP\FA11.ogg", 1.25, 1.015, 1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\INDEP\FA11.ogg", 1.25, 0.985, 1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\INDEP\FA11.ogg", 1.25, 1.01, 1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\INDEP\FA11.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\INDEP\FA11.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime = 0.15;
			dispersion = 0.01;
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 300;
			maxRangeProbab = 0.3;
		};
		distanceZoomMin = 400;
		distanceZoomMax = 400;
		weaponInfoType = "RscOptics_nightstalker";
		modelOptics = "\Indecisive_Armoury_Weapons_REPUBLIC\Data\LowPower_Scope\IDA_LowPower_Scope_Blue.p3d";
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 65;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"IDA_TargetingScope", "3AS_optic_acog_DC15C", "3AS_optic_reflex_DC15C", "885th_Optic_Scope_WestarM5", "optic_MRCO"};
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
	class IDA_SPK12;
	class 885th_SPAK15 : IDA_SPK12
	{
		ace_overheating_mrbs = 5000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 0;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 609;
		author = "885th Bloodpack Division + IDA Dev Team";
		scope = 2;
		inertia = 0.25;
		primary = 10;
		canShootInWater = 1;
		displayName = "[885th] SPA-K12 Blaster Rifle";
		descriptionShort = "Aldahni Militia really spittin' with this one.";
		reloadAction = "GestureReloadAKM";
		magazines[] = {"885th_cell_green_high"};
		magazineWell[] = {};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg", 5, 1, 10};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_rifle
		{
		};
		distanceZoomMin = 400;
		distanceZoomMax = 400;
		weaponInfoType = "RscOptics_nightstalker";
		modelOptics = "\Indecisive_Armoury_Weapons_REPUBLIC\Data\LowPower_Scope\IDA_LowPower_Scope_Blue.p3d";
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 65;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"3AS_Imp_Optic_1"};
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
	class 885th_DC17M: arifle_MX_Base_F
	{
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		author="885th Bloodpack Division + Indecisive Armoury Team";
		scope=2;
		inertia=0;
		canShootInWater=1;
		baseWeapon="885th_DC17M";
		displayName="[885th] DC-17M Interchangeable Weapon System";
		descriptionShort="";
		picture="\3AS\3AS_Weapons\DC17M\data\UI\3as_dc17m.paa";
		model="3AS\3AS_Weapons\DC17M\3AS_DC17M_f.p3d";
		handAnim[]={"OFP2_ManSkeleton","\A3\Weapons_F_beta\Rifles\MK20\Data\Anim\mk20G.rtm"};
		ace_clearJamAction="";
		reloadAction="3AS_GestureReload_DC17M";
		reloadMagazineSound[]={"885_Sounds\DC17MReload.ogg",2,1,30};
		recoil="IDA_recoil_BlasterCarbine";
		magazines[] = {"885_dc_cell_AP", "885_dc_cell_sniper", "885th_RC_AAD"};
		magazineWell[]={};
		muzzles[] = {"this", "Stun"};
		modes[]={"FullAuto","Single"};
		fireLightDiffuse[]={0.1,0.25,1};
		drySound[]={"\Indecisive_Armoury_Sounds\weapon_dry.ogg",5,1,10};
		class Stun : 885th_Stun_rifle
		{
		};
		class Single: Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"885_Sounds\DC17MFire.V2.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\DC17MFire.V2.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\DC17MFire.V2.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\DC17MFire.V2.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\DC17MFire.V2.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\DC17MFire.V2.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime=0.30000001;
			dispersion=0.001;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class FullAuto: Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound : BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[]={"885_Sounds\DC17MFire.V2.ogg",1.25, 1, 1800};
				begin2[] = {"885_Sounds\DC17MFire.V2.ogg", 1.25, 1.015, 1800};
				begin3[] = {"885_Sounds\DC17MFire.V2.ogg", 1.25, 0.985, 1800};
				begin4[] = {"885_Sounds\DC17MFire.V2.ogg", 1.25, 1.01, 1800};
				begin5[] = {"885_Sounds\DC17MFire.V2.ogg", 1.25, 0.995, 1800};
				soundBegin[] = {"begin1", 0.2, "begin2", 0.2, "begin3", 0.2, "begin4", 0.2, "begin5", 0.2};
				beginwater1[] = {"885_Sounds\DC17MFire.V2.ogg", 1, 1, 400};
				soundBeginWater[] = {"beginwater1", 1};
			};
			reloadTime=0.1;
			dispersion=0.00130;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		modelOptics="\ShadowLegion_Weapons\data\Acc\Reticles\model\Scope_Blue_1";
		weaponInfoType="RscWeaponZeroing";
		class OpticsModes
		{
			class Ironsights
			{
				opticsID=1;
				useModelOptics=0;
				opticsFlare="false";
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticsBlur5"
				};
				opticsDisablePeripherialVision=0;
				opticsZoomMin=0.40000001;
				opticsZoomMax=1.1;
				opticsZoomInit=0.75;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=300;
				distanceZoomMax=300;
			};
			class Scope: Ironsights
			{
				opticsID=2;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticsBlur5"
				};
				opticsFlare=0;
				opticsDisablePeripherialVision=1;
				opticsZoomMin=0.015;
				opticsZoomMax=0.1;
				opticsZoomInit=0.1;
				memoryPointCamera="opticView";
				visionMode[]={};
				distanceZoomMin=300;
				distanceZoomMax=300;
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=90;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]={};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]={};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName="Konec hlavne";
				effectName="RifleAssaultCloud";
				positionName="Usti hlavne";
			};
		};
	};
	//Attachments
	class InventoryMuzzleItem_Base_F;
	class 885th_Barrel_Module_DC21: ItemCore
	{
		author="SL Mod Dev Team + 885th Bloodapack Division";
		_generalMacro="885th_Barrel_Module_DC21";
		htMin=1;
		htMax=600;
		afMax=0;
		mfMax=0;
		mFact=1;
		tBody=100;
		scope=2;
		displayName="[885th] DC21 Barrel Extension Module";
		picture="\a3\Weapons_F\acc\Data\UI\icon_muzzle_snds_H_ca.paa";
		model="\ShadowLegion_Weapons\data\DC21\Model\DC21_Barrel.p3d";
		class ItemInfo: InventoryMuzzleItem_Base_F
		{
			mass=6;
			soundTypeIndex=0;
			muzzleEnd="zaslehPoint";
			alternativeFire="Zasleh2";
			bulletSpeedCoef = 1.25;
			class MagazineCoef
			{
				initSpeed=1;
			};
			class AmmoCoef
			{
				hit=1;
				typicalSpeed=1.5;
				airFriction=0;
				visibleFire=0.80000001;
				audibleFire=1;
				visibleFireTime=0.80000001;
				audibleFireTime=0.5;
				cost=1;
			};
			class MuzzleCoef
			{
				dispersionCoef=0.00013000003;
				artilleryDispersionCoef=1;
				fireLightCoef=1;
				recoilCoef=0.69999999;
				recoilProneCoef=0.40000001;
				minRangeCoef=1;
				minRangeProbabCoef=1;
				midRangeCoef=1;
				midRangeProbabCoef=1;
				maxRangeCoef=1;
				maxRangeProbabCoef=1;
			};
		};
		inertia=1.2;
	};
	class 885th_Muzzle_Module_Westarm5MKII: ItemCore
	{
		author="885th Bloodpack Division";
		_generalMacro="885th_Muzzle_Module_Westarm5MKII";
		htMin=1;
		htMax=600;
		afMax=0;
		mfMax=0;
		mFact=1;
		tBody=100;
		scope=2;
		displayName="[885th] WestarM5MKII Barrel Extension Module";
		picture="\a3\Weapons_F\acc\Data\UI\icon_muzzle_snds_H_ca.paa";
		model="\ShadowLegion_Weapons\data\DC15\DC19\models\DC19_S_Supressor.p3d";
		class ItemInfo: InventoryMuzzleItem_Base_F
		{
			mass=10;
			muzzleEnd="zaslehPoint";
			alternativeFire="Zasleh2";
			soundTypeIndex=0;
			bulletSpeedCoef = 1.25;
			class MagazineCoef
			{
				initSpeed = 2.1;
			};
			class AmmoCoef
			{
				hit=1.25;
				visibleFire=0.5;
				audibleFire=1;
				visibleFireTime=0.5;
				audibleFireTime=1;
				cost=1;
				typicalSpeed=2.1;
				airFriction=1;
			};
			class MuzzleCoef
			{
				dispersionCoef="0.75";
				artilleryDispersionCoef="1.0f";
				fireLightCoef="0.5f";
				recoilCoef="1.0f";
				recoilProneCoef="1.0f";
				minRangeCoef="1.0f";
				minRangeProbabCoef="1.0f";
				midRangeCoef="1.0f";
				midRangeProbabCoef="1.0f";
				maxRangeCoef="1.0f";
				maxRangeProbabCoef="1.0f";
			};
		};	
	};
	class 885th_Scope_Optics;
	class 885th_OverSights_Optic;
	class 885th_Optic_Scope_WestarM5: ItemCore
	{
		scope=2;
		displayName="885th Long Optic";
		picture="\3AS\3AS_Weapons\Data\Textures\Energy_Cell_Arsenal.paa";
		model="\3AS\3AS_Weapons\WestarM5\3AS_Westar_Scope_F.p3d";
		weaponInfoType="RscOptics_nightstalker";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=7;
			modelOptics="\ShadowLegion_Weapons\data\Acc\Reticles\model\Scope_Green_1";
			class OpticsModes
			{
				class 885th_Scope_Optics
				{
					opticsID=1;
					useModelOptics=1;
					opticsPPEffects[]=
					{
						"OpticsCHAbera1",
						"OpticsBlur1"
					};
					opticsZoomMin=0.0138;
					opticsZoomMax=0.0416;
					opticsZoomInit=0.0416;
					discreteDistance[]={100,300,400,500,600,700,800,900,1000};
					discreteDistanceInitIndex=1;
					distanceZoomMin=100;
					distanceZoomMax=1000;
					nFovLimit=0.07;
					discreteFov[]={0.0416,0.0138};
					discreteInitIndex=0;
					modelOptics[]={"\ShadowLegion_Weapons\data\Acc\Reticles\model\Scope_Green_1.p3d"};
					memoryPointCamera="opticView";
					visionMode[]={"Normal","NVG","TI"};
					opticsFlare=1;
					opticsDisablePeripherialVision=1;
					cameraDir="";
				};
				class 885th_OverSights_Optic: 885th_Scope_Optics
				{
					opticsID=2;
					useModelOptics=0;
					opticsFlare=0;
					opticsDisablePeripherialVision=0;
					opticsZoomMin=0.375;
					opticsZoomMax=1.1;
					opticsZoomInit=0.75;
					memoryPointCamera="eye";
					visionMode[]={};
					discretefov[]={};
				};
			};
		};
	};
	//Melee
	class ShdwCmpny_VibroLaserknife_Base;
	class 885th_Vibroblade_r: ShdwCmpny_VibroLaserknife_Base
	{
		scope=2;
		author="Antauri + 885th Bloodapack Division";
		model="\ShadowLegion_Weapons\data\knife\models\Vibroblade_up.p3d";
		displayName="[885th] Vibroblade";
		picture="\ShadowLegion_Weapons\data\knife\UI\Vibroblade.paa";
		UiPicture="\ShadowLegion_Weapons\data\knife\UI\Vibroblade.paa";
		IMS_WeaponEventHandler_Special="[player, 'WBK_survival_weapon_3_r'] spawn WBK_IMS_WeaponAbility_Rotate;";
		IMS_Melee_Param_Damage=0.34999999;
	};
	class 885th_Vibroblade_rotated_r: ShdwCmpny_VibroLaserknife_Base
	{
		scope=2;
		author="Antauri + 885th Bloodapack Division";
		model="\ShadowLegion_Weapons\data\knife\models\Vibroblade_reversed.p3d";
		displayName="[885th] Vibroblade (Reversed grip)";
		picture="\ShadowLegion_Weapons\data\knife\UI\Vibroblade_reverse.paa";
		UiPicture="\ShadowLegion_Weapons\data\knife\UI\Vibroblade_reverse.paa";
		IMS_ExecutionType="ReversedKnife";
		IMS_WeaponEventHandler_Special="[player, 'WBK_survival_weapon_3'] spawn WBK_IMS_WeaponAbility_Rotate;";
		IMS_Melee_Param_Damage=0.34999999;
	};
};