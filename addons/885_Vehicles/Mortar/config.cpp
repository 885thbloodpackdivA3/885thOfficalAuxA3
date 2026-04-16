class CfgPatches
{
	class 885_Mortar
	{
		requiredAddons[]=
		{
			"A3_Data_F_Tank_Loadorder"
		};
		units[]=
		{
			"885th_Republic_Mortar",
			"885th_Republic_Mortar_Bag"
		};
		weapons[]={};
		skipWhenMissingDependencies=1;
		author="885th bloodpack division";
	};
};
class CfgVehicles
{
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
	};
	class StaticMortar: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
			};
		};
	};
	class Mortar_01_base_F: StaticMortar
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics: ViewOptics
				{
				};
				class Hitpoints;
			};
		};
		class assembleInfo;
	};
	class B_Mortar_01_F: Mortar_01_base_F
	{
		class SimpleObject;
	};
	class 885th_Republic_Mortar: B_Mortar_01_F
	{
		author="885th bloodpack division";
		displayname="[885th] Republic Mortar";
		model="\3as\3as_static\Mortar\model\republicmortar.p3d";
		editorPreview="\885th\885th_static\images\885th_Republic_Mortar.jpg";
		crew="JLTS_Clone_P2_DC15S";
		icon="\3as\3as_static\Mortar\data\ui\Mortar_top_ca.paa";
		tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=40000;
		tf_subtype="digital_lr";
		picture="\3as\3as_static\Mortar\data\ui\Mortar_side_ca.paa";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				initelev=0;
				maxelev=40;
				minelev=-15;
				initturn=0;
				maxturn=360;
				minturn=-360;
				weapons[]=
				{
					"3AS_mortar_82mm"
				};
				magazines[]=
				{
					"3AS_8Rnd_82mm_Mo_shells",
					"3AS_8Rnd_82mm_Mo_shells",
					"3AS_8Rnd_82mm_Mo_shells",
					"3AS_8Rnd_82mm_Mo_shells",
					"3AS_8Rnd_82mm_Mo_Flare_white",
					"3AS_8Rnd_82mm_Mo_Flare_white",
					"3AS_8Rnd_82mm_Mo_Flare_white",
					"3AS_8Rnd_82mm_Mo_Flare_Red",
					"3AS_8Rnd_82mm_Mo_Flare_Red",
					"3AS_8Rnd_82mm_Mo_Smoke_white",
					"3AS_8Rnd_82mm_Mo_Smoke_white",
					"3AS_8Rnd_82mm_Mo_guided",
					"3AS_8Rnd_82mm_Mo_LG"
				};
				elevationMode=3;
				gunnerforceoptics=1;
				class Hitpoints: Hitpoints
				{
				};
			};
		};
		class assembleInfo: assembleInfo
		{
			dissasembleTo[]=
			{
				"885th_Republic_Mortar_Bag"
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3as_static\mortar\data\base.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_01_damage.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_01_destruct.rvmat",
				"3as\3as_static\mortar\data\tube.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_02_damage.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_02_destruct.rvmat"
			};
		};
		hiddenSelections[]=
		{
			"Camo_1",
			"Camo_2"
		};
		hiddenSelectionsTextures[]=
		{
			"\3as\3as_static\Mortar\data\base_co.paa",
			"\3as\3as_static\Mortar\data\tube_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"\3as\3as_static\Mortar\data\base.rvmat",
			"\3as\3as_static\Mortar\data\tube.rvmat"
		};
		faction="3AS_REP";
		scopeCurator=2;
		class TextureSources
		{
			class Republic
			{
				displayName="Republic";
				author="885th bloodpack division";
				textures[]=
				{
					"\3as\3as_static\Mortar\data\base_co.paa",
					"\3as\3as_static\Mortar\data\tube_co.paa"
				};
				factions[]=
				{
					"885th_REP"
				};
			};
		};
	};
	class Bag_Base;
	class Weapon_Bag_Base: Bag_Base
	{
		class assembleInfo
		{
		};
	};
	class 885th_Republic_Mortar_Bag: Weapon_Bag_Base
	{
		faction="3AS_REP";
		model="\3as\3as_static\Mortar\model\mortarpack.p3d";
		author="885th Bloodpack Division";
		_generalMacro="B_Mortar_01_weapon_F";
		scope=2;
		editorCategory="EdCat_Equipment";
		tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=40000;
		tf_subtype="digital_lr";
		editorSubcategory="EdSubcat_DismantledWeapons";
		displayName="[885th] Folded Republic Mortar";
		hiddenSelections[]=
		{
			"Camo_1",
			"Camo_2"
		};
		hiddenSelectionsTextures[]=
		{
			"\3as\3as_static\Mortar\data\base_co.paa",
			"\3as\3as_static\Mortar\data\tube_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"\3as\3as_static\Mortar\data\base.rvmat",
			"\3as\3as_static\Mortar\data\tube.rvmat"
		};
		picture="\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Small_mcamo.paa";
		mass=450;
		class assembleInfo: assembleInfo
		{
			base[]=
			{
				""
			};
			displayName="Build Mortar";
			assembleTo="885th_Republic_Mortar";
		};
	};
};
