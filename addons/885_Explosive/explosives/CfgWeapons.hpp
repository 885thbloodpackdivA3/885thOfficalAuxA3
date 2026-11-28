// 885th Explosives - Put muzzles (included inside class CfgWeapons in config.cpp)
// Each placeable magazine needs a Put muzzle so the engine knows how to place / touch it off.

class Default;
class Put: Default
{
	muzzles[]+=
	{
		"885th_explosive_lowYield_muzzle",
		"885th_explosive_highYield_muzzle",
		"885th_explosive_atDetpack_muzzle",
		"885th_explosive_seismic_muzzle",
		"885th_explosive_breach_muzzle",
		"885th_explosive_demoPack_muzzle",
		"885th_explosive_mineDispenser_muzzle"
	};
	class PutMuzzle;
	class 885th_explosive_muzzle_base: PutMuzzle
	{
		autoReload=0;
		enableAttack=1;
		showToPlayer=0;
		magazines[]={};
	};
	class 885th_explosive_lowYield_muzzle: 885th_explosive_muzzle_base
	{
		magazines[]={"885th_explosive_lowYield_mag"};
	};
	class 885th_explosive_highYield_muzzle: 885th_explosive_muzzle_base
	{
		magazines[]={"885th_explosive_highYield_mag"};
	};
	class 885th_explosive_atDetpack_muzzle: 885th_explosive_muzzle_base
	{
		magazines[]={"885th_explosive_atDetpack_mag"};
	};
	class 885th_explosive_seismic_muzzle: 885th_explosive_muzzle_base
	{
		magazines[]={"885th_explosive_seismic_mag"};
	};
	class 885th_explosive_breach_muzzle: 885th_explosive_muzzle_base
	{
		magazines[]={"885th_explosive_breach_mag"};
	};
	class 885th_explosive_demoPack_muzzle: 885th_explosive_muzzle_base
	{
		magazines[]={"885th_explosive_demoPack_mag"};
	};
	class 885th_explosive_mineDispenser_muzzle: 885th_explosive_muzzle_base
	{
		magazines[]={"885th_explosive_mineDispenser_mag"};
	};
};
