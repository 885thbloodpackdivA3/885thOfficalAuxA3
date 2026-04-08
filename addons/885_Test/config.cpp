class CfgPatches
{
    class TCP_Bacta
    {
        requiredAddons[]=
        {
            "A3_Weapons_F", "ace_medical", "cba_main", "cba_xeh"
        };
        requiredVersion=0.1;
        units[]={};
        weapons[]={};
        magazines[] = {"bacta_nade"};
        ammo[] = {"bacta_nade_ammo"};
    };
};

class CfgAmmo
{
    class smokeshell;
    class bacta_nade_ammo: smokeshell
    {
        displayName = "Bacta Grenade";
		displayNameShort = "Bacta Grenade";
        descriptionShort = "Bacta Grenade";
        model = "885_Test\bacta grenade.p3d";
        hit=0;
		indirectHit=0;
		indirectHitRange=0.2;
		dangerRadiusHit=-1;
		suppressionRadiusHit=-1;
		typicalspeed=22;
		cost=100;
		simulation="shotSmokeX";
		explosive=0;
		deflecting=30;
		explosionTime=2;
		timeToLive=60;
		fuseDistance=0;
		soundHit[]=
		{
			"",
			0,
			1
		};
		SmokeShellSoundHit1[]=
		{
			"A3\Sounds_F\weapons\smokeshell\smoke_1",
			1.2589254,
			1,
			100
		};
		SmokeShellSoundHit2[]=
		{
			"A3\Sounds_F\weapons\smokeshell\smoke_2",
			1.2589254,
			1,
			100
		};
		SmokeShellSoundHit3[]=
		{
			"A3\Sounds_F\weapons\smokeshell\smoke_3",
			1.2589254,
			1,
			100
		};
		SmokeShellSoundLoop1[]=
		{
			"A3\Sounds_F\weapons\smokeshell\smoke_loop1",
			0.12589253,
			1,
			70
		};
		SmokeShellSoundLoop2[]=
		{
			"A3\Sounds_F\weapons\smokeshell\smoke_loop2",
			0.12589253,
			1,
			70
		};
		grenadeFireSound[]=
		{
			"SmokeShellSoundHit1",
			0.25,
			"SmokeShellSoundHit2",
			0.25,
			"SmokeShellSoundHit3",
			0.5
		};
		grenadeBurningSound[]=
		{
			"SmokeShellSoundLoop1",
			0.5,
			"SmokeShellSoundLoop2",
			0.5
		};
		aiAmmoUsageFlags="4 + 2";
		smokeColor[]={1,1,1,1};
		effectsSmoke="particle_effect_Bacta";
		whistleDist=0;
    };

};
class CfgMagazines
{
    class smokeshell;
    class bacta_nade: smokeshell
    {
        author = "115th + 885th Blood Pack Division";
        scope = 2;
        displayName = "Bacta Grenade";
		displayNameShort = "Bacta Grenade";
        descriptionShort = "Bacta Grenade";
        picture = "885_Test\data\icon_bacta_1rnd_CA.paa";
        pictureWire = "885_Test\data\icon_grenade_bacta_F_W_ca.paa";
        model = "885_Test\bacta grenade.p3d";
        ammo = "bacta_nade_ammo";
		smokeColor[]={0.1183,0.1867,1,1};
		effectsSmoke="particle_effect_Bacta";
		mass=4;
		initSpeed=22;
    };

};
class CfgWeapons
{
    class GrenadeLauncher;
    class Throw: GrenadeLauncher
    {
        class ThrowMuzzle;
        muzzles[] += {"bactanadeMuzzle"};
        class bactanadeMuzzle: ThrowMuzzle
        {
            magazines[] = {"bacta_nade"};
        };
    };
};
class CfgVehicles
{
    class Item_Base_F;
    class Weapon_throw_bacta: Item_Base_F
    {
        author = "115th + 885th Blood Pack Division";
        scope = 2;
        scopeCurator = 2;
        displayName = "[885th] Bacta Grenade";
        descriptionShort = "Bacta Grenade";
        picture = "885_Test\data\icon_bacta_1rnd_CA.paa";
        pictureWire = "885_Test\data\icon_grenade_bacta_F_W_ca.paa";
        editorCategory = "";
        editorSubcategory = "";
        vehicleClass = "Explosives";
        class TransportItems
        {
            class _xx_bacta_nade
            {
                name = "bacta_nade";
                count = 1;
            };
        };
    };
};

class CfgFunctions {
  class bacta {
    tag = "bacta";
    class main {
      file = "885_Test\functions";
      class isAllowedGrenade {};
      class bactaHealArea {};
      class bactaProjectileLoop {};
    };
  };
};

class Extended_PreInit_EventHandlers {
  class bacta_preinit {
    init = "call compile preprocessFileLineNumbers '885_Test\XEH_preInit.sqf'";
  };
};

class Extended_PostInit_EventHandlers {
  class bacta_postinit {
    init = "call compile preprocessFileLineNumbers '885_Test\XEH_postInit.sqf'";
  };
};

class particle_effect_Bacta
{
    class SmokeShell
    {
        intensity = 20;
        interval = 10;
        position[] = {0,0,0};
        simulation = "particles";
        type = "cloudlet_smokeshell_bacta";
    };
    class SmokeShell2: SmokeShell
    {
        type = "cloudlet_smokeshell_bacta2";
    };
    class SmokeShell2UW: SmokeShell
    {
        type = "cloudlet_SmokeShell_bacta2UW";
    };
    class SmokeShellUW: SmokeShell
    {
        type = "cloudlet_SmokeShell_bactaUW";
    };
};
class particle_effect_BactaWater
{
    colorCoef[] = {0,0,0,1};
    interval = 0.25;
};


class CfgCloudlets
{
    class SmokeShellWhite;
    class SmokeShellWhiteWater;
    class SmokeShellWhite2;
    class SmokeShellWhiteUW;
    class SmokeShellWhite2UW;

	class cloudlet_smokeshell_bacta: SmokeShellWhite
    {
		colorCoef[] = {"colorR","colorG","colorB","colorA"};
        blockAIVisibility = 1;
        color[] = {{0.1183,0.1867,1,0.2},{0.1183,0.1867,1,0.05},{0.1183,0.1867,1,0}};
		moveVelocity[] = {0.2,0.5,0.1};
        size[] = {0.46,4.5,18};
        MoveVelocityVar[] = {0.7,0.4,0.7};
    };
	class cloudlet_smokeshell_bacta2: cloudlet_smokeshell_bacta
    {
		particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 4;
        particleFSLoop = 0;
        color[] = {{0.1183,0.1867,1,0.2},{0.1183,0.1867,1,0.05},{0.1183,0.1867,1,0}};
    };
	class cloudlet_smokeshell_bactaUW: SmokeShellWhiteUW
    {
        color[] = {{0.1183,0.1867,1,1}};
		randomDirectionIntensity = 0.2;
        MoveVelocityVar[] = {0.5,0.5,0.5};
    };
	class cloudlet_smokeshell_bacta2UW: SmokeShellWhite2UW
    {
        postEffects = "particle_effect_BactaWater";
    };
};