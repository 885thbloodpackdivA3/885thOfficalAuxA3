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
			"885th_Valken38x_F",
			"885th_DC17S_F",
			"885th_RPS6",
			"885th_PLX1",
			"885th_Chaingun",
			"885th_RPS6_Dispo_Base",
			"885th_RPS6_Dispo",
			"885th_RPS6_Dispo_Used",
			"885th_RPS6_G_Dispo_Base",
			"885th_RPS6_G_Dispo",
			"885th_RPS6_G_Dispo_Used",
			"885th_DC17S_Dual_F",
			"885th_DC17S_Dual_W",
			"885th_DP23_F",
			"885th_DC15SA_F"
		};
		ammo[] = {
			"885th_Chaingun_Ammo_Y",
			"885th_ammo_40mm_HE_Base",
			"885th_3AS_EC20_BluePlasma",
			"885th_3AS_EC20_BluePlasma_dual",
			"885th_scattershot_blasterbolt_blue",
			"885th_slug_blasterbolt_blue",
			"885th_Doomsday_slug_blasterbolt_blue",
			"885th_dc15sa_blasterbolt_blue"
		};
		magazines[] = {
			"885th_Chaingun_Drum_Mag",
			"885th_Dc17s_Dual_Pistol_Mag",
			"885th_dp23_scattershot_mag",
			"885th_dp23_slug_mag",
			"885th_Doomsday_slug_Mag",
			"885th_dc15sa_pistol_mag_blue",
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

class CfgMagazineWells
{	
	class Dp23_energycells
	{
		885th_Magazines[]=
		{
			"885th_dp23_scattershot_mag",
			"885th_dp23_slug_mag"
		};
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
	
	class 3AS_PlasmaBase;
	class 885th_3AS_EC20_BluePlasma: 3AS_PlasmaBase
	{
		hit = 20;
		caliber = 5.7;
		coefGravity = 0;
		indirectHit=0;
		indirectHitRange=0;
		cartridge="";
		audibleFire=50;
		dangerRadiusBulletClose=4;
		dangerRadiusHit=8;
		suppressionRadiusBulletClose=2;
		suppressionRadiusHit=4;
		visibleFireTime=3;
		cost=50;
		airLock=1;
		typicalSpeed=306;
		model="\3AS\3AS_Weapons\Data\tracer_blue.p3d";
		tracerScale=0.58999997;
		airFriction=-0.00026999999;
		effectFly="3AS_PlasmaBolt_Blue_Fly";
	};
	class 885th_3AS_EC20_BluePlasma_dual: 885th_3AS_EC20_BluePlasma
	{
		model="\3AS\3AS_Weapons\Data\tracer_blue_dual.p3d";
	};
	
	class 885th_scattershot_blasterbolt_blue: 885th_blasterbolt
	{	
		hit=25;
		model="\3AS\3AS_Weapons\Data\tracer_blue.p3d";
		effectFly="3AS_PlasmaBolt_blue_Fly";
		submunitionAmmo="885th_blasterbolt_blue";
		submunitionConeType[]=
		{
			"random",
			8
		};
		submunitionConeAngle=0.34999999;
		triggerTime=9.9999997e-010;
	};
	
	class 885th_slug_blasterbolt_blue: 885th_blasterbolt
	{
		hit=45;
		cost=5;
		typicalSpeed=600;
		caliber=5;
		model="\3AS\3AS_Weapons\Data\tracer_blue.p3d";
		effectFly="3AS_PlasmaBolt_Blue_Fly";
	};
	
	class 885th_Doomsday_slug_blasterbolt_blue: 885th_blasterbolt
	{
		hit=900;
		indirectHit=0;
		indirectHitRange=0;
		cartridge="";
		cost=15;
		typicalSpeed=1500;
		airFriction=-0.00033000001;
		caliber=3;
		airLock=1;
		tracerScale=0.5;
		nvgOnly=1;
		audibleFire=30;
		aiAmmoUsageFlags=64;
		dangerRadiusBulletClose=4;
		dangerRadiusHit=8;
		suppressionRadiusBulletClose=2;
		suppressionRadiusHit=4;
		deflecting=2;
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
	// Base Mags
	class 885th_dc_cell_blue;
	class 885th_Dc17s_Dual_Pistol_Mag: 885th_dc_cell_blue
	{
		scope=2;
		count = 32;
		author="885th";
		displayName = "[885th] Dual Pistol Energy Cell";
		displayNameShort = "Std. Pistol Cell";
		descriptionShort = "32 round capacity, standard blaster bolts.";
		ammo = "885th_3AS_EC20_BluePlasma_dual";
		tracersEvery = 1;
		mass = 6;
	};
	class 885th_cell;
	class 885th_dp23_scattershot_mag: 885th_cell
	{
		scope=2;
		author="885th";
		displayName="[885th] DP-23 25rnd Scattershot Battery";
		displayNameShort="Scattershot";
		descriptionShort="25 round capacity, Scattershot blaster bolts";
		ammo="885th_scattershot_blasterbolt_blue";
		initSpeed=400;
		mass=7;
		count=25;
	};
	class 885th_dp23_slug_mag: 885th_cell
	{
		scope=2;
		author="885th";
		displayName="[885th] DP-23 25rnd Slug Battery";
		displayNameShort="Slug";
		descriptionShort="25 round capacity, Slug blaster bolts";
		ammo="885th_slug_blasterbolt_blue";
		initSpeed=900;
		mass=7;
		count=25;
	};
	class 885th_dc15sa_pistol_mag_blue : 885th_dc_cell_blue
	{	
		scope=2;
		count = 15;
		author="885th";
		displayName = "[885th] DC-15SA Energy Cell";
		displayNameShort = "DC-15SA Pistol Cell";
		descriptionShort = "15 round capacity, DC-15SA blaster bolts.";
		ammo = "885th_blasterbolt_blue";
		initSpeed=800;
		tracersEvery = 1;
		mass = 4;
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
		magazines[] = {"885th_dc_cell_blue"};
		magazineWell[] = {"DC_energycells"};
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
		magazines[] = {"885th_dc_cell_blue"};
		magazineWell[]=
		{
			"DC_energycells",
		};
		fireLightDiffuse[]={0.1,0.25,1};
		muzzles[] = {"this","GL_3GL_F"};
		class GL_3GL_F : GL_3GL_F {};
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
			"885th_battery_low_blue",
			"885th_battery_high_blue",
			"885th_battery_amp_blue"};
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
		magazines[] = {"885th_dc_cell_blue_amp","885th_dc_cell_blue_Omega"};
		magazineWell[] = {};
		muzzles[] = {"this"};
		fireLightDiffuse[]={0.1,0.25,1};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			reloadTime=1.2;
			dispersion = 0.0001;
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
				compatibleItems[] = {"3AS_optic_DC15X_F","3AS_optic_DC15LE_F"};
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
	class IDA_DC15LE;
	class 885th_DLT15LE : IDA_DC15LE
	{
		baseWeapon = "885th_DLT15LE";
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 650;
		ace_barrelTwist = 0;
		scope = 2;
		model = "Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15LE\Model\IDA_DC15LE.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "Indecisive_Armoury_Anims\Republic\DC15A.rtm"};
		displayName = "[885th] DC15LE Heavy Blaster";
		magazines[] = {
			"885th_battery_low_blue",
			"885th_battery_high_blue",
			"885th_battery_amp_blue"};
		magazineWell[] = {};
		muzzles[] = {"this"};
		modes[] = {"FullAuto"};
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
				begin1[] = {"\Indecisive_Armoury_Sounds\Republic\DC15LE.ogg",1.25,1,1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\Republic\DC15LE.ogg",1.25,1.025,1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\Republic\DC15LE.ogg",1.25,0.95,1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\Republic\DC15LE.ogg",1.25,1.05,1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\Republic\DC15LE.ogg",1.25,0.9,1800};
				soundBegin[] = {"begin1",0.2,"begin2",0.2,"begin3",0.2,"begin4",0.2,"begin5",0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\Republic\DC15LE.ogg",1,1,400};
				soundBeginWater[] = {"beginwater1",1};
			};
			reloadTime = 0.08;
			dispersion = 0.0020;
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
			class MuzzleSlot: MuzzleSlot_65
			{
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]={"3AS_muzzle_DC15LE_F"};
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

	class 3AS_Valken38x_F;
	class 885th_Valken38x_F : 3AS_Valken38x_F 
	{
		baseWeapon = "885th_Valken38x_F";
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 620;
		ace_barrelTwist = 0;
		scope = 2;
		displayName = "[885th] Valken-38X Sniper Rifle";
		magazines[] = {"885th_dc_cell_blue_amp","885th_dc_cell_blue_Omega"};
		magazineWell[] = {};
		muzzles[] = {"this"};
		fireLightDiffuse[]={0.1,0.25,1};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			reloadTime=1.0;
			dispersion = 0.0001;
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
				soundSetShot[]=
				{
					"3AS_Sniper_SoundSet"
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
				iconPosition[]={0.44999999,0.28};
				iconScale=0.2;
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]={"ShadwCmpany_optic_Acog","3AS_optic_DC15X_F","ShdwCmpny_Optic_LEScope_DC15A","3AS_optic_DC15L_F","optic_MRCO","ShdwCmpny_Optic_Valken"};
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
	class 3AS_DC17S_F;
	class 885th_DC17S_F : 3AS_DC17S_F 
	{
		baseWeapon = "885th_DC17S_F";
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 114.3;
		ace_barrelTwist = 0;
		scope = 2;
		displayName = "[885th] DC-17S Blaster Pistol";
		magazines[] = {"885th_dc_cell_blue_pistol","885th_dc_cell_blue_pistol_extended"};
		magazineWell[] = {};
		modes[] = {"Single","Burst"};
		muzzles[] = {"this", "Stun"};
		class Stun : 885th_Stun_pistol {};
		class Single: Mode_SemiAuto
		{
			sounds[]={"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_SE14R_Shot_SoundSet"
				};
			};
			reloadTime=0.050000001;
			dispersion=0.00131;
			minRange=2;
			minRangeProbab=0.30000001;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=150;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=300;
		};
		class Burst: Mode_Burst
		{
			sounds[]={"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_SE14R_Shot_SoundSet"
				};
			};
			soundBurst=0;
			textureType="dual";
			burst=2;
			reloadTime=0.050000001;
			dispersion=0.00131;
			minRange=2;
			minRangeProbab=0.30000001;
			midRange=50;
			midRangeProbab=0.69999999;
			maxRange=100;
			maxRangeProbab=0.050000001;
			aiRateOfFire=1;
			aiRateOfFireDistance=250;
		};
		fireLightDiffuse[]={7,36,190,1};
		fireLightIntensity=0.02;
		flashSize=0.1;
		class WeaponSlotsInfo : WeaponSlotsInfo {
			mass = 25;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"885th_reflex_Optic"};
			};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = {"3AS_muzzle_DC17S_F"};
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
	
	class 3AS_DC17S_Dual_F;
	class 885th_DC17S_Dual_F : 3AS_DC17S_Dual_F 
	{
		baseWeapon = "885th_DC17S_Dual_F";
		ace_overheating_mrbs = 40000;
		ace_overheating_slowdownFactor = 0;
		ace_overheating_allowSwapBarrel = 0;
		ace_overheating_dispersion = 1;
		ace_overheating_closedBolt = 0;
		ace_overheating_barrelMass = 1;
		ace_barrelLength = 114.3;
		ace_barrelTwist = 0;
		scope = 2;
		displayName = "[885th] DC-17S Dual Blaster Pistols";
		magazines[] = {"885th_Dc17s_Dual_Pistol_Mag"};
		magazineWell[] = {};
		modes[] = {"Single","Burst"};
		muzzles[] = {"this"};
		class Single: Mode_SemiAuto
		{
			sounds[]={"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_SE14R_Shot_SoundSet"
				};
			};
			reloadTime=0.050000001;
			dispersion=0.00131;
			minRange=2;
			minRangeProbab=0.30000001;
			midRange=50;
			midRangeProbab=0.69999999;
			maxRange=100;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=300;
		};
		class Burst: Mode_Burst
		{
			sounds[]={"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_SE14R_Shot_SoundSet"
				};
			};
			soundBurst=0;
			textureType="dual";
			burst=2;
			reloadTime=0.050000001;
			dispersion=0.00131;
			minRange=2;
			minRangeProbab=0.30000001;
			midRange=50;
			midRangeProbab=0.69999999;
			maxRange=100;
			maxRangeProbab=0.050000001;
			aiRateOfFire=1;
			aiRateOfFireDistance=250;
		};
		fireLightDiffuse[]={7,36,190,1};
		fireLightIntensity=0.02;
		flashSize=0.1;
	};
	
	class 885th_DC17S_Dual_W: 885th_DC17S_Dual_F
	{
		displayName="$STR_3AS_Weapons_Republic_DC17S_Dual_Wrap_Display";
		hiddenSelectionsTextures[]=
		{
			"\3AS\3AS_Weapons\Republic\DC17S\Data\DC17S_Wrap_co.paa"
		};
	};
	
	class 3AS_DP23_F;
	class 885th_DP23_F : 3AS_DP23_F
	{
		baseWeapon = "885th_DP23_F";
		scope = 2;
		displayName = "[885th] DP-23 Scattergun";
		magazines[] = {"885th_dp23_scattershot_mag" , "885th_dp23_slug_mag"};
		magazineWell[] = {"Dp23_energycells"};
		muzzles[] = {"this"};
		class WeaponSlotsInfo : WeaponSlotsInfo {
			mass = 65;
			class CowsSlot : CowsSlot
			{
				compatibleItems[] = {"3AS_optic_DC15C_F"};
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
				compatibleItems[] = {""};
			};
		};
		fireLightDiffuse[]={0.1,0.25,1};
	};
	
	class 3AS_pistol_DC15SA_F;
	class 885th_DC15SA_F : 3AS_pistol_DC15SA_F
	{	
		baseWeapon = "885th_DC15SA_F";
		scope=2;
		author="";
		displayName="[885th] DC-15SA";
		model="3AS\3AS_Weapons\DC15SA\3AS_DC15SA_F.p3d";
		picture="\3AS\3AS_Weapons\DC15SA\data\UI\3as_dc15sa.paa";
		weaponInfoType="RscWeaponZeroing";
		recoil = "recoil_pistol_zubr";
		magazines[]= {"885th_dc15sa_pistol_mag_blue"};
		modes[] = {"Single"};
		muzzles[] = {"this"};
		class Single: Mode_SemiAuto
		{
			sounds[]={"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_DC15SA_Shot_SoundSet"
				};
			};
			reloadTime=0.15;
			dispersion=0.00131;
			minRange=2;
			minRangeProbab=0.30000001;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=150;
			maxRangeProbab=0.050000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=300;
		};
		class OpticsModes
		{
			class Ironsights
			{
				opticsID=2;
				useModelOptics=0;
				opticsFlare="true";
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticsBlur5"
				};
				opticsDisablePeripherialVision=0.67000002;
				opticsZoomMin=0.5;
				opticsZoomMax=1;
				opticsZoomInit=1;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=100;
				distanceZoomMax=100;
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=40;
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
	
	class 3AS_PLX1_F;
	class 885th_PLX1 : 3AS_PLX1_F {
		baseWeapon = "885th_PLX1";
		displayName = "[885th] PLX-1 Missile launcher";
		magazines[] = {"3AS_JLTS_MK43_AT", "3AS_JLTS_MK44_HE", "3AS_JLTS_MK39_AA"};
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
	
	// Weapon Attachments
	
	class 3AS_Imp_Optic_1;
	class 885th_reflex_Optic: 3AS_Imp_Optic_1
	{
		scope=2;
		displayName="885th Reflex Optic";
		weaponInfoType="RscWeaponZeroing";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=7;
			modelOptics="\3AS\3AS_Weapons\Data\3AS_2D_Optic.p3d";
			class OpticsModes
			{
				class HoloSights
				{
					opticsID=1;
					useModelOptics=0;
					opticsFlare="false";
					opticsPPEffects[]=
					{
						"OpticsCHAbera1",
						"OpticsBlur1"
					};
					opticsDisablePeripherialVision=0.0;
					opticsZoomMin="0.25/1.8";
					opticsZoomMax=0.25;
					opticsZoomInit=0.75;
					memoryPointCamera="eye";
					visionMode[]={};
					discreteDistance[]={50,100};
					discreteDistanceInitIndex=0;
					distanceZoomMin=50;
					distanceZoomMax=100;
				};
			};
		};
	};	
};
