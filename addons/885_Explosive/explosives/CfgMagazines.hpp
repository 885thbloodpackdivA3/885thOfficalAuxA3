// 885th Explosives - CfgMagazines (included inside class CfgMagazines in config.cpp)
//
// Placement and triggers go through ACE Explosives (LS and 3AS parents already set
// ace_explosives_placeable / ace_explosives_setupObject). Detonate with any ACE clacker
// (Command) or set a timer.

class EC01_RemoteMagazine;
class 3AS_DetPack;
class RTX_RemoteMagazine;
class ls_explosive_demoCharge_magazine;
class ls_explosive_detpack_magazine;
class ls_explosive_breachCharge_magazine;
class APERSMineDispenser_Mag;

// 3AS magazines list a "3AS_Transmitter" trigger that 3AS never defines, so the 3AS-based
// charges get a plain Timer + Command trigger set instead.
#define BPD_ACE_TRIGGERS(FUSE) \
	class ACE_Triggers \
	{ \
		SupportedTriggers[]={"Timer","Command"}; \
		class Timer \
		{ \
			FuseTime=FUSE; \
		}; \
		class Command \
		{ \
			FuseTime=FUSE; \
		}; \
	}

// ---------------------------------------------------------------- Republic Commando (Kusak)

class 885th_explosive_lowYield_mag: EC01_RemoteMagazine
{
	scope=2;
	scopeArsenal=2;
	author="885th Bloodpack Division";
	displayName="[885th] RC Low-Yield Demo Charge";
	displayNameShort="Low-Yield Charge";
	descriptionShort="Compact detonite charge carried by Republic Commandos for sabotage work: consoles, shield generators, droid emplacements and light doors.<br/>Small blast. Clear 10 m.";
	ammo="885th_explosive_lowYield_ammo";
	mass=10;
	BPD_ACE_TRIGGERS(0.5);
};

class 885th_explosive_highYield_mag: ls_explosive_demoCharge_magazine
{
	scope=2;
	scopeArsenal=2;
	author="885th Bloodpack Division";
	displayName="[885th] RC High-Yield Demo Pack";
	displayNameShort="High-Yield Pack";
	descriptionShort="Heavy detonite demolition pack used by commando squads to bring down bunkers, bridges, blast doors and starship systems.<br/>Very large blast. Clear 40 m.";
	ammo="885th_explosive_highYield_ammo";
	mass=80;
};

class 885th_explosive_atDetpack_mag: 3AS_DetPack
{
	scope=2;
	scopeArsenal=2;
	author="885th Bloodpack Division";
	displayName="[885th] RC AT Det Pack";
	displayNameShort="AT Det Pack";
	descriptionShort="Anti-armour detpack. Stick it to a tank, AAT or walker leg and fire it remotely or on a timer; the blast is concentrated on whatever it is attached to.<br/>Clear 15 m.";
	ammo="885th_explosive_atDetpack_ammo";
	mass=40;
	BPD_ACE_TRIGGERS(0.5);
};

class 885th_explosive_seismic_mag: RTX_RemoteMagazine
{
	scope=2;
	scopeArsenal=2;
	author="885th Bloodpack Division";
	displayName="[885th] RC Seismic Charge";
	displayNameShort="Seismic Charge";
	descriptionShort="Baradium-collapsium seismic charge. When fired it draws in all sound around it for a moment, then releases a concussive shockwave that throws anyone nearby off their feet.<br/>2 s fuse. Clear 50 m.";
	ammo="885th_explosive_seismic_ammo";
	mass=60;
	BPD_ACE_TRIGGERS(2);
};

// ---------------------------------------------------------------- Shared (Kusak + Engineers)

class 885th_explosive_breach_mag: ls_explosive_breachCharge_magazine
{
	scope=2;
	scopeArsenal=2;
	author="885th Bloodpack Division";
	displayName="[885th] Breaching Charge";
	displayNameShort="Breaching Charge";
	descriptionShort="Low-yield directional charge for forced entry. Place it on a door, fence or light wall: it blows the door open and jams it, or knocks the wall/fence down.<br/>Stand to the side of the door.";
	ammo="885th_explosive_breach_ammo";
	mass=10;
};

// ---------------------------------------------------------------- Engineers (Specialized Clone Troopers)

class 885th_explosive_demoPack_mag: ls_explosive_detpack_magazine
{
	scope=2;
	scopeArsenal=2;
	author="885th Bloodpack Division";
	displayName="[885th] Clone Demo Pack";
	displayNameShort="Demo Pack";
	descriptionShort="Standard-issue detonation pack for clone combat engineers. Clears obstacles and destroys structures, equipment and droid emplacements.<br/>Medium blast. Clear 25 m.";
	ammo="885th_explosive_demoPack_ammo";
	mass=40;
};

class 885th_explosive_mineDispenser_mag: APERSMineDispenser_Mag
{
	scope=2;
	scopeArsenal=2;
	author="885th Bloodpack Division";
	displayName="[885th] Clone Mine Dispenser";
	displayNameShort="Mine Dispenser";
	descriptionShort="Area-denial dispenser for clone combat engineers. When triggered it throws 10 laser-tripped anti-personnel mines around itself.<br/>The mines can't tell friend from foe; mark the field.";
	ammo="885th_explosive_mineDispenser_ammo";
	mass=60;
};

#undef BPD_ACE_TRIGGERS
