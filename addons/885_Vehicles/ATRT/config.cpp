
class CfgPatches
{
	class 885th_ATRT
	{
		author = "885th Bloodpack Division";
		requiredAddons[] = {"A3_Weapons_F", "ls_animations", "ls_weapons_atrt", "ls_vehicles_atrt", "3AS_Weapons"};
		requiredVersion = 0.1;
		units[] = {"885th_ATRT"};
		weapons[] = {"885th_ATRT_Cannon"};
		magazines[] = {"885th_ATRT_Cannon_Mag", "885th_ATRT_Launcher_Mag"};
		ammo[] = {"885th_ATRT_Laser_Bolt", "885th_ATRT_Mortar_HE"};
	};
};

class CfgMovesAtrt_ls
{
	class States
	{
		class atrt_walkF;
		class atrt_runF : atrt_walkF	// parent must be restated or the reopen drops it
		{
			speed = -0.447;	// 90 km/h. Raise toward -0.65 (LS default) if it is too fast on rough terrain.
		};
	};
};

class CfgAmmo
{
	class G_40mm_HE;
	class ls_ammo_atrt_30mm_AP_blue;

	class 885th_ATRT_Laser_Bolt : ls_ammo_atrt_30mm_AP_blue
	{
		hit = 65;
		indirectHit = 8;
		indirectHitRange = 1;
		explosive = 0.2;				
		caliber = 4;					
		typicalSpeed = 800;
		airFriction = -0.0007;			
		warheadName = "AP";
		explosionEffects = "ExploAmmoExplosion";
		craterEffects = "ExploAmmoCrater";
		aiAmmoUsageFlags = "64 + 128 + 256";	
	};

	class 885th_ATRT_Mortar_HE : G_40mm_HE
	{
		hit = 80;
		indirectHit = 30;
		indirectHitRange = 6;
		explosive = 1;
		warheadName = "HE";
		effectFly = "3AS_PlasmaBolt_Yellow_Fly";
		timeToLive = 30;
		aiAmmoUsageFlags = "64 + 128";
	};
};

class CfgMagazines
{
	class ls_magazine_atrt_laserCannon;
	class 1Rnd_HE_Grenade_shell;

	class 885th_ATRT_Cannon_Mag : ls_magazine_atrt_laserCannon
	{
		author = "885th Bloodpack Division";
		scope = 2;
		displayName = "[885th] ATRT Cannon Cell";
		displayNameShort = "ATRT Cannon";
		descriptionShort = "200 heavy blaster bolts for the ATRT Cannon.";
		ammo = "885th_ATRT_Laser_Bolt";
		count = 200;
		initSpeed = 800;
		tracersEvery = 1;
		mass = 15;
	};

	class 885th_ATRT_Launcher_Mag : 1Rnd_HE_Grenade_shell
	{
		author = "885th Bloodpack Division";
		scope = 2;
		displayName = "[885th] AT-RT Mortar Rounds";
		displayNameShort = "HE Mortar";
		descriptionShort = "6 HE mortar rounds for the AT-RT mortar launcher.";
		ammo = "885th_ATRT_Mortar_HE";
		count = 6;
		initSpeed = 90;		// ~825 m max range at 45 degrees
		mass = 12;
	};
};

class CfgWeapons
{
	class UGL_F;
	class ls_weapon_atrt_base;
	class ls_weapon_atrt_laserCannon_base : ls_weapon_atrt_base
	{
		class FullAuto;
		class close;
		class short;
	};

	class 885th_ATRT_Cannon : ls_weapon_atrt_laserCannon_base
	{
		scope = 1;
		author = "885th Bloodpack Division";
		displayName = "[885th] ATRT Cannon";
		baseWeapon = "885th_ATRT_Cannon";
		magazines[] = {"885th_ATRT_Cannon_Mag"};
		muzzles[] = {"this", "885th_ATRT_Launcher"};

		class FullAuto : FullAuto
		{
			reloadTime = 0.2;
			dispersion = 0.004;
		};
		class close : close
		{
			reloadTime = 0.2;
			dispersion = 0.004;
			burst = 8;
		};
		class short : short
		{
			reloadTime = 0.2;
			dispersion = 0.004;
			burst = 12;
		};

		class 885th_ATRT_Launcher : UGL_F
		{
			displayName = "AT-RT Mortar Launcher";
			descriptionShort = "Lobbed HE mortar rounds";
			magazines[] = {"885th_ATRT_Launcher_Mag"};
			magazineWell[] = {};
			muzzlePos = "usti hlavne";
			muzzleEnd = "konec hlavne";
			useModelOptics = 1;
			modelOptics = "\A3\weapons_f\reticle\Optics_Gunner_02_F.p3d";
			cameraDir = "";
			discreteDistance[] = {50, 100, 150, 200, 250, 300, 400, 500, 600, 800};
			discreteDistanceCameraPoint[] = {};
			discreteDistanceInitIndex = 1;
			reloadTime = 1;				// 1 round per second
			magazineReloadTime = 6;
		};
	};
};

class CfgVehicles
{
	class ls_vehicle_atrt;
	class 885th_ATRT : ls_vehicle_atrt
	{
		scope = 2;
		scopeCurator = 2;
		author = "Legion Studios + 885th BPD";
		displayName = "[885th] AT-RT";
		side = 1;
		faction = "885th_Faction";
		editorSubcategory = "Sub885thRecon";
		ls_crew = "885th_Trooper";	

		
		hiddenSelections[] = {"camo1", "camo2", "camo3", "camo4"};
		hiddenSelectionsTextures[] = {
			"\ls\core\addons\vehicles_atrt\data\camo1_co.paa",
			"\ls\core\addons\vehicles_atrt\data\camo2_co.paa",
			"\ls\core\addons\vehicles_atrt\data\camo3_co.paa",
			"\ls\core\addons\vehicles_atrt\data\camo4_co.paa"
		};

		weapons[] = {"885th_ATRT_Cannon"};
		respawnWeapons[] = {"885th_ATRT_Cannon"};
		magazines[] = {
			"885th_ATRT_Cannon_Mag", "885th_ATRT_Cannon_Mag", "885th_ATRT_Cannon_Mag", "885th_ATRT_Cannon_Mag",
			"885th_ATRT_Launcher_Mag", "885th_ATRT_Launcher_Mag", "885th_ATRT_Launcher_Mag"
		};
		respawnMagazines[] = {
			"885th_ATRT_Cannon_Mag", "885th_ATRT_Cannon_Mag", "885th_ATRT_Cannon_Mag", "885th_ATRT_Cannon_Mag",
			"885th_ATRT_Launcher_Mag", "885th_ATRT_Launcher_Mag", "885th_ATRT_Launcher_Mag"
		};
	};
};
