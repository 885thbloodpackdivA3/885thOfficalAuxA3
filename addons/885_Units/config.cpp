/// Magazines macros definition ///

#define MAG_2(a) a, a
#define MAG_3(a) a, a, a
#define MAG_4(a) a, a, a, a
#define MAG_5(a) a, a, a, a, a
#define MAG_6(a) a, a, a, a, a, a
#define MAG_7(a) a, a, a, a, a, a, a
#define MAG_8(a) a, a, a, a, a, a, a, a
#define MAG_9(a) a, a, a, a, a, a, a, a, a
#define MAG_10(a) a, a, a, a, a, a, a, a, a, a
#define MAG_11(a) a, a, a, a, a, a, a, a, a, a, a
#define MAG_12(a) a, a, a, a, a, a, a, a, a, a, a, a
class CfgPatches
{
    class 885th_Units
    {
        author = "885th Bloodpack Div";
        requiredAddons[] = {"A3_Data_F","A3_Weapons_F","A3_Characters_F",};
        requiredVersion = 0.1;
        units[] = {
			"885th_Clone_F",
			"885th_Recruit",
			"885th_Trooper",
			"885th_Marksman",
			"885th_AT",
			"885th_Heavy",
			"885th_Medic",
			"885th_ARF",
			"885th_Pilot"
		};
		weapons[] = {""};
    };
};
class cfgFactionClasses
{
	class 885th_Faction;
};
class CFgEditorSubcategories
{
	class Sub885thTroopers
	{
		side = 1;
		displayName = "885th Clone Troopers (P2)";
        scope = 2;
        scopeCurator = 2;
	};
};

class CfgGroups {
    class West {

        class 885_Clones {
            name = "[885th] Bloodpack Division";

            class Infantry {
                name = "Infantry";

                class 885_Team {
                    name = "Fireteam";
                    side = 1;
                    faction = "885th_Faction";
                    icon = "\data\icons\n_inf.paa";
                    rarityGroup = 0.5;

                    class Unit0 {
                        position[] = {0,0,0};
                        rank = "CORPORAL";
                        side = 1;
                        vehicle = "885th_Trooper";
                    };
                    class Unit1 {
                        position[] = {5,-5,0};
                        rank = "PRIVATE";
                        side = 1;
                        vehicle = "885th_Medic";
                    };
                    class Unit2 {
                        position[] = {-5,-5,0};
                        rank = "PRIVATE";
                        side = 1;
                        vehicle = "885th_AT";
                    };
					class Unit3 {
						position[] = {5,0,0};
                        rank = "PRIVATE";
                        side = 1;
                        vehicle = "885th_Marksman";
					};
                };

                class 885_infantry_squad {
                    name = "Infantry Squad";
                    side = 1;
                    faction = "885th_Faction";
                    icon = "\data\icons\n_inf.paa";
                    rarityGroup = 0.5;

                    class Unit0 {
                        position[] = {0,0,0};
                        rank = "CORPORAL";
                        side = 1;
                        vehicle = "885th_Trooper";
                    };
                    class Unit1 {
                        position[] = {5,-5,0};
                        rank = "PRIVATE";
                        side = 1;
                        vehicle = "885th_Heavy";
                    };
                    class Unit2 {
                        position[] = {-5,-5,0};
                        rank = "SERGEANT";
                        side = 1;
                        vehicle = "885th_Medic";
                    };
                    class Unit3 {
                        position[] = {10,-10,0};
                        rank = "PRIVATE";
                        side = 1;
                        vehicle = "885th_AT";
                    };
                    class Unit4 {
                        position[] = {-10,-10,0};
                        rank = "PRIVATE";
                        side = 1;
                        vehicle = "885th_Marksman";
                    };
                    class Unit5 {
                        position[] = {15,-15,0};
                        rank = "PRIVATE";
                        side = 1;
                        vehicle = "885th_Recruit";
                    };
                    class Unit6 {
                        position[] = {-15,-15,0};
                        rank = "PRIVATE";
                        side = 1;
                        vehicle = "885th_Recruit";
                    };
                    class Unit7 {
                        position[] = {20,-20,0};
                        rank = "PRIVATE";
                        side = 1;
                        vehicle = "885th_Recruit";
                    };
                };

                class 885_infantry_patrol {
                    name = "Patrol";
                    side = 1;
                    faction = "885th_Faction";
                    icon = "\data\icons\n_inf.paa";
                    rarityGroup = 0.5;

                    class Unit0 {
                        position[] = {0,0,0};
                        rank = "SERGEANT";
                        side = 1;
                        vehicle = "885th_Trooper";
                    };
                    class Unit1 {
                        position[] = {5,-5,0};
                        rank = "PRIVATE";
                        side = 1;
                        vehicle = "885th_Recruit";
                    };
                };

                class 885_infantry_sniper_team {
                    name = "Marksman Team";
                    side = 1;
                    faction = "885th_Faction";
                    icon = "\data\icons\n_recon.paa";
                    rarityGroup = 0.5;

                    class Unit0 {
                        position[] = {0,0,0};
                        rank = "SERGEANT";
                        side = 1;
                        vehicle = "885th_Marksman";
                    };
                    class Unit1 {
                        position[] = {5,-5,0};
                        rank = "PRIVATE";
                        side = 1;
                        vehicle = "885th_Trooper";
                    };
                };

                class bss_infantry_anti_tank_team {
                    name = "Anti-Tank Team";
                    side = 1;
                    faction = "885th_Faction";
                    icon = "\data\icons\n_inf.paa";
                    rarityGroup = 0.5;

                    class Unit0 {
                        position[] = {0,0,0};
                        rank = "SERGEANT";
                        side = 1;
                        vehicle = "885th_Trooper";
                    };
                    class Unit1 {
                        position[] = {10,-10,0};
                        rank = "PRIVATE";
                        side = 1;
                        vehicle = "885th_AT";
                    };
                };

				class 885_recon_patrol {
                    name = "Recon Patrol";
                    side = 1;
                    faction = "885th_Faction";
                    icon = "\data\icons\n_inf.paa";
                    rarityGroup = 0.5;

                    class Unit0 {
                        position[] = {0,0,0};
                        rank = "CORPORAL";
                        side = 1;
                        vehicle = "885th_ARF";
                    };
                    class Unit1 {
                        position[] = {5,-5,0};
                        rank = "SERGEANT";
                        side = 1;
                        vehicle = "885th_ARF";
                    };
                };
            };
        };
    };
};
class CfgVehicles
{
	class B_Soldier_base_F;
	class 885th_Clone_F : B_Soldier_base_F {
		author = "AifeSupport";
		access = 0;
		scope = 1;
		isMan = 1;
		side = 1;
		faction = "885th_Faction";
		editorSubcategory = "Sub885thTroopers";
		identityTypes[] = {"CloneTrooperENG","Head_LSD_CLONE"};
		genericNames = "JLTS_Clones"; 
		displayName = "Clone";
		cost = 1;
		camouflage = 1.0;
		sensitivity = 1.5;
		threat[] = {1, 0.8, 0.6};
		model = "\Indecisive_Armoury_units\REPUBLIC\Clone_Uniform\IDA_Clone_Uniform.p3d";
		nakedUniform = "IDA_Clone_Undersuit";
		uniformClass = "885th_Vornskr_Trooper";
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsMaterials[] = {"\Indecisive_Armoury_Units\REPUBLIC\Clone_Uniform\Upper\IDA_BodyUpper.rvmat","\Indecisive_Armoury_Units\REPUBLIC\Clone_Uniform\Lower\IDA_BodyLower.rvmat"};
		hiddenSelectionsTextures[] = {"\Indecisive_Armoury_Units\REPUBLIC\Clone_Uniform\Upper\IDA_BodyUpper_co.paa","\Indecisive_Armoury_Units\REPUBLIC\Clone_Uniform\Lower\IDA_BodyLower_co.paa"};
		canDeactivateMines = 0;
		engineer = 0;
		attendant = 0;
		icon = "iconMan";
		picture = "";
		backpack = "885th_Vornskr_Backpack_invis";
		weapons[] = {"885th_DC17","Throw","Put"};
		respawnWeapons[] = {"885th_DC17","Throw","Put"};
		Items[] = {"ACE_EntrenchingTool",MAG_10("IDA_BactaBandage"),MAG_5("ACE_tourniquet"),MAG_4("ACE_Splint"),"ACE_PlasmaIV_500",MAG_2("IDA_BattleStim"),MAG_4("ACE_CableTie"),"acc_flashlight"};
		RespawnItems[] = {"ACE_EntrenchingTool",MAG_10("IDA_BactaBandage"),MAG_5("ACE_tourniquet"),MAG_4("ACE_Splint"),"ACE_PlasmaIV_500",MAG_2("IDA_BattleStim"),MAG_4("ACE_CableTie"),"acc_flashlight"};
		magazines[] = {MAG_4("885th_dc_cell_blue_pistol"),MAG_3("IDA_grenade_Smoke_mag"),"IDA_grenade_Detonator_mag"};
		respawnMagazines[] = {MAG_10("885th_dc_cell_blue_low"),MAG_10("885th_dc_cell_blue"),MAG_4("885th_dc_cell_blue_pistol"),MAG_3("IDA_grenade_Smoke_mag"),"IDA_grenade_Detonator_mag"};
		linkedItems[] = {"ItemMap","ItemGPS","ItemCompass","ItemWatch","JLTS_clone_comlink","JLTS_CloneBinocular"};
		respawnLinkedItems[] = {"ItemMap","ItemGPS","ItemCompass","ItemWatch","JLTS_clone_comlink","JLTS_CloneBinocular"};
	};
	class 885th_Recruit : 885th_Clone_F {
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayName = "Clone Recruit";
		cost = 1;
		sensitivity = 0.8;
		uniformClass = "885th_Recruit_Uniform";
		hiddenSelectionsTextures[] = {"\885_Armor\885_Armor\CR\885th_Recruit_Upper_co.paa","\885_Armor\885_Armor\CR\885th_Recruit_Lower_co.paa"};
		weapons[] += {"885th_DC15S_F"};
		magazines[] += {MAG_10("885th_dc_cell_blue_low"),MAG_10("885th_dc_cell_blue")};
		respawnMagazines[] += {MAG_10("885th_dc_cell_blue_low"),MAG_10("885th_dc_cell_blue")};
		linkedItems[] += {"885th_Recruit_P2_Helm","885th_vest_base"};
		respawnLinkedItems[] += {"885th_Recruit_P2_Helm","885th_vest_base"};
	};
	class 885th_Trooper : 885th_Clone_F {
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayName = "Clone Trooper";
		genericNames = "ls_clone_p2_ct";
		cost = 1;
		sensitivity = 1.1;
		uniformClass = "885th_Vornskr_Uniform";
		hiddenSelectionsTextures[] = {"\885_Armor\885_Armor\Vornskr\Vornskr_Upper_co.paa","\885_Armor\885_Armor\Vornskr\Vornskr_Lower_co.paa"};
		weapons[] += {"885th_DC15A_F"};
		magazines[] += {MAG_10("885th_dc_cell_blue_low"),MAG_10("885th_dc_cell_blue")};
		respawnMagazines[] += {MAG_10("885th_dc_cell_blue_low"),MAG_10("885th_dc_cell_blue")};
		linkedItems[] += {"885th_P2_V2_Helmet","885th_vest_base"};
		respawnLinkedItems[] += {"885th_P2_V2_Helmet","885th_vest_base"};
	};
	class 885th_Marksman : 885th_Clone_F {
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayName = "Clone Marksman";
		genericNames = "ls_clone_p2_ct";
		cost = 2;
		sensitivity = 1.8;
		camouflage = 0.6;
		uniformClass = "885th_Vornskr_Uniform";
		hiddenSelectionsTextures[] = {"\885_Armor\885_Armor\Vornskr\Vornskr_Upper_co.paa","\885_Armor\885_Armor\Vornskr\Vornskr_Lower_co.paa"};
		weapons[] += {"885th_Valken38x_F"};
		magazines[] += {MAG_10("885th_dc_cell_blue_low"),MAG_10("885th_dc_cell_blue")};
		respawnMagazines[] += {MAG_10("885th_dc_cell_blue_low"),MAG_10("885th_dc_cell_blue")};
		linkedItems[] += {"885th_P2_V2_Helmet","885th_vest_base"};
		respawnLinkedItems[] += {"885th_P2_V2_Helmet","885th_vest_base"};
	};
	class 885th_AT : 885th_Clone_F {
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayName = "Clone Anti-Tank";
		genericNames = "ls_clone_p2_ct";
		cost = 3;
		sensitivity = 1.3;
		uniformClass = "885th_Vornskr_Uniform";
		hiddenSelectionsTextures[] = {"\885_Armor\885_Armor\Vornskr\Vornskr_Upper_co.paa","\885_Armor\885_Armor\Vornskr\Vornskr_Lower_co.paa"};
		weapons[] += {"885th_DC15S_GL", "IDA_PLX1"};
		magazines[] += {MAG_10("885th_dc_cell_blue_low"),MAG_4("885th_PLX1_AT_Rocket")};
		respawnMagazines[] += {MAG_10("885th_dc_cell_blue_low"),MAG_4("885th_PLX1_AT_Rocket")};
		linkedItems[] += {"885th_P2_V2_Helmet","885th_vest_base"};
		respawnLinkedItems[] += {"885th_P2_V2_Helmet","885th_vest_base"};
	};
	class 885th_Heavy : 885th_Clone_F {
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayName = "Clone Heavy Trooper";
		genericNames = "ls_clone_p2_ct";
		cost = 3;
		sensitivity = 1.3;
		uniformClass = "885th_Vornskr_Uniform";
		hiddenSelectionsTextures[] = {"\885_Armor\885_Armor\Vornskr\Vornskr_Upper_co.paa","\885_Armor\885_Armor\Vornskr\Vornskr_Lower_co.paa"};
		weapons[] += {"885th_DC15L_F"};
		magazines[] += {MAG_3("885th_battery_low_blue"),MAG_2("885th_battery_high_blue")};
		respawnMagazines[] += {MAG_3("885th_battery_low_blue"),MAG_2("885th_battery_high_blue")};
		linkedItems[] += {"885th_P2_V2_Helmet","885th_vest_base"};
		respawnLinkedItems[] += {"885th_P2_V2_Helmet","885th_vest_base"};
	};
	class 885th_Medic : 885th_Clone_F {
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayName = "Clone Medic";
		cost = 2;
		sensitivity = 1.0;
		uniformClass = "885th_Medic_Uniform";
		hiddenSelectionsTextures[] = {"\885_Armor\885_Armor\Medic\885th_MedicV2_Upper_co.paa","\885_Armor\885_Armor\Medic\885th_MedicV2_Lower_co.paa"};
		weapons[] += {"885th_DC15S_F"};
		items[] += {MAG_5("GW_Vasko500"),MAG_5("GW_Vasko250"),"IDA_Cauterizer","ACE_painkillers_item"};
		respawnItems[] += {MAG_5("GW_Vasko500"),MAG_5("GW_Vasko250"),"IDA_Cauterizer","ACE_painkillers_item"};
		magazines[] += {MAG_10("885th_dc_cell_blue_low"),MAG_10("885th_dc_cell_blue")};
		respawnMagazines[] += {MAG_10("885th_dc_cell_blue_low"),MAG_10("885th_dc_cell_blue")};
		linkedItems[] += {"885th_Recruit_P2_Helm","885th_vest_base","885th_Medic_Vest"};
		respawnLinkedItems[] += {"885th_Recruit_P2_Helm","885th_vest_base","885th_Medic_Vest"};
	};
	class 885th_ARF : 885th_Clone_F {
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayName = "Clone Recon";
		genericNames = "ls_clone_p2_cl";
		cost = 3;
		sensitivity = 2.3;
		camouflage = 0.4;
		uniformClass = "885th_Najax_Uniform";
		hiddenSelectionsTextures[] = {"\885_Armor\885_Armor\Najax\885th_Najax_P2_Upper_co.paa","\885_Armor\885_Armor\Najax\885th_Najax_P2_Lower_co.paa"};
		weapons[] += {"885th_DC15X_F"};
		magazines[] += {MAG_10("885th_dc_cell_blue_low"),MAG_10("885th_dc_cell_blue")};
		respawnMagazines[] += {MAG_10("885th_dc_cell_blue_low"),MAG_10("885th_dc_cell_blue")};
		linkedItems[] += {"885th_Najax_P1_ARF_Helm","885th_vest_base"};
		respawnLinkedItems[] += {"885th_Najax_P1_ARF_Helm","885th_vest_base"};
	};
	class 885th_Pilot : 885th_Clone_F {
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayName = "Clone Pilot";
		cost = 1;
		sensitivity = 1.7;
		uniformClass = "885th_Nightsingers_Uniform";
		hiddenSelectionsTextures[] = {"\885_Armor\885_Armor\Nightsingers\Nightsingers_P2_Upper_co.paa","\885_Armor\885_Armor\Nightsingers\Nightsingers_P2_Lower_co.paa"};
		weapons[] += {"885th_DC17S_F"};
		magazines[] += {MAG_10("885th_dc_cell_blue_pistol")};
		respawnMagazines[] += {MAG_10("885th_dc_cell_blue_pistol")};
		linkedItems[] += {"885th_Nightsingers_P1_Pilot_Helm","885th_vest_base"};
		respawnLinkedItems[] += {"885th_Nightsingers_P1_Pilot_Helm","885th_vest_base"};
	};
};