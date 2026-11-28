// 885th Explosives - CfgAmmo (included inside class CfgAmmo in config.cpp)
//
// Models come from Legion Studios Core (ls_weapons_explosives) and 3AS (3AS_Equipment).
// The mine dispenser uses the vanilla APERS dispenser model because neither LS nor 3AS
// ships an anti-personnel mine or dispenser (LS's own caltrop dispenser uses the same one).

class EC_Charge;
class 3AS_Detpack;
class RTX_Remote_Ammo;
class ls_explosive_demoCharge_ammo;
class ls_explosive_detpack_ammo;
class ls_explosive_breachCharge_ammo;
class APERSMineDispenser_Ammo;
class APERSMineDispenser_Deploy;
class APERSMineDispenser_Mine_Ammo;

// ---------------------------------------------------------------- Republic Commando (Kusak)

// Low Yield Demo Charge - 3AS EC-01 commando charge model
class 885th_explosive_lowYield_ammo: EC_Charge
{
	author="885th Bloodpack Division";
	defaultMagazine="885th_explosive_lowYield_mag";
	hit=800;
	indirectHit=600;
	indirectHitRange=2.5;
	explosionEffects="MineNondirectionalExplosionSmall";
	craterEffects="MineNondirectionalCraterSmall";
	whistleDist=16;
	ace_frag_skip=1;
};

// High Yield Demo Pack - LS demolitions pack model
class 885th_explosive_highYield_ammo: ls_explosive_demoCharge_ammo
{
	author="885th Bloodpack Division";
	defaultMagazine="885th_explosive_highYield_mag";
	hit=8000;
	indirectHit=6000;
	indirectHitRange=8;
	explosionEffects="HeavyBombExplosion";
	craterEffects="HeavyBombCrater";
	whistleDist=40;
	ace_frag_skip=1;
};

// AT Det Pack - 3AS detpack model. Concentrated blast for sticking to armour.
class 885th_explosive_atDetpack_ammo: 3AS_Detpack
{
	author="885th Bloodpack Division";
	defaultMagazine="885th_explosive_atDetpack_mag";
	hit=12000;
	indirectHit=4500;
	indirectHitRange=3.5;
	explosionEffects="ATMineExplosion";
	craterEffects="ATMineCrater";
	whistleDist=20;
	ace_frag_skip=1;
};

// Seismic Charge - 3AS RTX bomb model. Wide concussive shockwave; the sound drain and the
// knock-back are scripted in scripts\seismic_postInit.sqf.
class 885th_explosive_seismic_ammo: RTX_Remote_Ammo
{
	author="885th Bloodpack Division";
	defaultMagazine="885th_explosive_seismic_mag";
	hit=4000;
	indirectHit=2800;
	indirectHitRange=16;
	explosionEffects="HeavyBombExplosion";
	craterEffects="HeavyBombCrater";
	whistleDist=60;
	soundSetExplosion[]=
	{
		"BombsHeavy_Exp_SoundSet",
		"BombsHeavy_Tail_SoundSet",
		"Explosion_Debris_SoundSet"
	};
	ace_frag_skip=1;
	class CamShakeExplode
	{
		power=16;
		duration=2.5;
		frequency=20;
		distance=180;
	};
};

// ---------------------------------------------------------------- Shared

// Breaching Charge - LS breaching charge. Keeps LS's door-breach behaviour
// (ls_explosives_isBreachCharge and the directional submunition are inherited).
class 885th_explosive_breach_ammo: ls_explosive_breachCharge_ammo
{
	author="885th Bloodpack Division";
	defaultMagazine="885th_explosive_breach_mag";
};

// ---------------------------------------------------------------- Engineers

// Demo Pack - LS detpack model, general-purpose demolition
class 885th_explosive_demoPack_ammo: ls_explosive_detpack_ammo
{
	author="885th Bloodpack Division";
	defaultMagazine="885th_explosive_demoPack_mag";
	hit=3000;
	indirectHit=2500;
	indirectHitRange=5;
	explosionEffects="MineNondirectionalExplosion";
	craterEffects="MineNondirectionalCrater";
	ace_frag_skip=1;
};

// Clone Mine Dispenser - throws out 10 anti-personnel mines when triggered
class 885th_explosive_mineDispenser_ammo: APERSMineDispenser_Ammo
{
	author="885th Bloodpack Division";
	defaultMagazine="885th_explosive_mineDispenser_mag";
	submunitionAmmo[]=
	{
		"885th_explosive_mineDispenser_deploy",
		1
	};
	submunitionConeType[]=
	{
		"randomupcone",
		10
	};
};
class 885th_explosive_mineDispenser_deploy: APERSMineDispenser_Deploy
{
	author="885th Bloodpack Division";
	submunitionAmmo="885th_explosive_mineDispenser_mine_ammo";
};
class 885th_explosive_mineDispenser_mine_ammo: APERSMineDispenser_Mine_Ammo
{
	author="885th Bloodpack Division";
	hit=10;
	indirectHit=10;
	indirectHitRange=3.5;
};
