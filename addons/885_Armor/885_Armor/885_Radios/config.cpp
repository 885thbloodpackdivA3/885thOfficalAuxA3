class CfgPatches
{
	class 885th_radios
	{
		author="885th Bloodpack Div";
		name="885th nightsingers SR";
		requiredAddons[]=
		{
			"A3_data_f",
			"A3_weapons_f"
		};
		units[]={};
		weapons[]=
		{
			"885th_clone_comlink",
			"885th_operator_comlink"
		};
	};
};

class CfgWeapons
{
	class itemradio;
	class 885th_clone_comlink: itemradio
	{
		author="885th Bloodpack Div";
		displayName="Nightsingers CWP-8";
		descriptionShort="$STR_JLTS_descs_RadioCWP8";
		scope=2;
		scopeArsenal=2;
		scopeCurator=2;
		picture="\MRC\JLTS\radios\data\ui\clone_comlink_item_ui_ca.paa";
		model="\A3\weapons_F\ammo\mag_univ.p3d";
		tf_prototype=1;
		tf_range=25000;
		tf_dialog="JLTS_clone_comlink_dialog";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialogUpdate="call TFAR_fnc_updateSWDialogToChannel;";
		tf_subtype="digital";
		tf_parent="885th_clone_comlink";
		tf_additional_channel=1;
	};
	class 885th_operator_comlink: itemradio
	{
		author="885th Bloodpack Div";
		displayName="Operator CWP-8";
		descriptionShort="$STR_JLTS_descs_RadioCWP8";
		scope=2;
		scopeArsenal=2;
		scopeCurator=2;
		picture="\MRC\JLTS\radios\data\ui\clone_comlink_item_ui_ca.paa";
		model="\A3\weapons_F\ammo\mag_univ.p3d";
		tf_prototype=1;
		tf_range=20000;
		tf_dialog="JLTS_clone_comlink_dialog";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialogUpdate="call TFAR_fnc_updateSWDialogToChannel;";
		tf_subtype="digital";
		tf_parent="885th_operator_comlink";
		tf_additional_channel=1;
	};
    class 885th_clone_comlink_1: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 1";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_2: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 2";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_3: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 3";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_4: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 4";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_5: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 5";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_6: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 6";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_7: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 7";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_8: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 8";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_9: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 9";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_10: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 10";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_11: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 11";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_12: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 12";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_13: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 13";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_14: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 14";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_15: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 15";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_16: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 16";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_17: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 17";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_18: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 18";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_19: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 19";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_20: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 20";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_21: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 21";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_22: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 22";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_23: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 23";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_24: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 24";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_25: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 25";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_26: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 26";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_27: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 27";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_28: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 28";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_29: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 29";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_30: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 30";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_31: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 31";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_32: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 32";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_33: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 33";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_34: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 34";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_35: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 35";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_36: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 36";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_37: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 37";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_38: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 38";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_39: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 39";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_40: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 40";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_41: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 41";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_42: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 42";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_43: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 43";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_44: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 44";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_45: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 45";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_46: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 46";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_47: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 47";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_48: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 48";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_49: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 49";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_50: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 50";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_51: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 51";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_52: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 52";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_53: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 53";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_54: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 54";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_55: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 55";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_56: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 56";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_57: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 57";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_58: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 58";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_59: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 59";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_60: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 60";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_61: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 61";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_62: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 62";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_63: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 63";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_64: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 64";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_65: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 65";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_66: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 66";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_67: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 67";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_68: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 68";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_69: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 69";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_70: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 70";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_71: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 71";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_72: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 72";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_73: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 73";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_74: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 74";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_75: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 75";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_76: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 76";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_77: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 77";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_78: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 78";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_79: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 79";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_80: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 80";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_81: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 81";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_82: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 82";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_83: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 83";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_84: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 84";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_85: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 85";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_86: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 86";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_87: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 87";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_88: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 88";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_89: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 89";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_90: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 90";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_91: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 91";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_92: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 92";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_93: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 93";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_94: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 94";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_95: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 95";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_96: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 96";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_97: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 97";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_98: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 98";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_99: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 99";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_100: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 100";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_101: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 101";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_102: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 102";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_103: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 103";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_104: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 104";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_105: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 105";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_106: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 106";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_107: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 107";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_108: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 108";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_109: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 109";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_110: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 110";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_111: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 111";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_112: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 112";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_113: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 113";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_114: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 114";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_115: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 115";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_116: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 116";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_117: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 117";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_118: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 118";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_119: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 119";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_120: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 120";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_121: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 121";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_122: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 122";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_123: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 123";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_124: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 124";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_125: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 125";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_126: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 126";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_127: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 127";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_128: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 128";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_129: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 129";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_130: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 130";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_131: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 131";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_132: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 132";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_133: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 133";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_134: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 134";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_135: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 135";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_136: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 136";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_137: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 137";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_138: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 138";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_139: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 139";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_140: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 140";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_141: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 141";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_142: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 142";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_143: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 143";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_144: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 144";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_145: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 145";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_146: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 146";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_147: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 147";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_148: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 148";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_149: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 149";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_150: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 150";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_151: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 151";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_152: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 152";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_153: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 153";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_154: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 154";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_155: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 155";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_156: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 156";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_157: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 157";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_158: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 158";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_159: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 159";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_160: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 160";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_161: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 161";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_162: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 162";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_163: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 163";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_164: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 164";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_165: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 165";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_166: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 166";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_167: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 167";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_168: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 168";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_169: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 169";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_170: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 170";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_171: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 171";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_172: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 172";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_173: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 173";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_174: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 174";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_175: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 175";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_176: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 176";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_177: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 177";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_178: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 178";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_179: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 179";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_180: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 180";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_181: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 181";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_182: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 182";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_183: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 183";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_184: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 184";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_185: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 185";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_186: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 186";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_187: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 187";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_188: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 188";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_189: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 189";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_190: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 190";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_191: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 191";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_192: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 192";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_193: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 193";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_194: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 194";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_195: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 195";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_196: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 196";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_197: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 197";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_198: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 198";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_199: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 199";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_200: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 200";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_201: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 201";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_202: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 202";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_203: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 203";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_204: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 204";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_205: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 205";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_206: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 206";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_207: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 207";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_208: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 208";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_209: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 209";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_210: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 210";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_211: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 211";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_212: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 212";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_213: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 213";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_214: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 214";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_215: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 215";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_216: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 216";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_217: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 217";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_218: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 218";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_219: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 219";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_220: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 220";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_221: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 221";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_222: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 222";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_223: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 223";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_224: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 224";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_225: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 225";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_226: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 226";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_227: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 227";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_228: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 228";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_229: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 229";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_230: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 230";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_231: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 231";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_232: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 232";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_233: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 233";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_234: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 234";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_235: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 235";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_236: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 236";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_237: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 237";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_238: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 238";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_239: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 239";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_240: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 240";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_241: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 241";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_242: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 242";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_243: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 243";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_244: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 244";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_245: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 245";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_246: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 246";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_247: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 247";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_248: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 248";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_249: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 249";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_250: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 250";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_251: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 251";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_252: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 252";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_253: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 253";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_254: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 254";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_255: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 255";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_256: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 256";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_257: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 257";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_258: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 258";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_259: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 259";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_260: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 260";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_261: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 261";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_262: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 262";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_263: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 263";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_264: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 264";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_265: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 265";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_266: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 266";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_267: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 267";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_268: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 268";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_269: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 269";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_270: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 270";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_271: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 271";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_272: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 272";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_273: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 273";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_274: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 274";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_275: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 275";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_276: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 276";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_277: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 277";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_278: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 278";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_279: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 279";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_280: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 280";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_281: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 281";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_282: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 282";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_283: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 283";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_284: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 284";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_285: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 285";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_286: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 286";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_287: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 287";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_288: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 288";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_289: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 289";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_290: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 290";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_291: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 291";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_292: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 292";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_293: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 293";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_294: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 294";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_295: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 295";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_296: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 296";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_297: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 297";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_298: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 298";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_299: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 299";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_300: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 300";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_301: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 301";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_302: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 302";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_303: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 303";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_304: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 304";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_305: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 305";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_306: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 306";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_307: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 307";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_308: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 308";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_309: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 309";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_310: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 310";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_311: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 311";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_312: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 312";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_313: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 313";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_314: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 314";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_315: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 315";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_316: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 316";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_317: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 317";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_318: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 318";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_319: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 319";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_320: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 320";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_321: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 321";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_322: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 322";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_323: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 323";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_324: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 324";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_325: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 325";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_326: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 326";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_327: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 327";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_328: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 328";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_329: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 329";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_330: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 330";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_331: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 331";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_332: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 332";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_333: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 333";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_334: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 334";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_335: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 335";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_336: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 336";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_337: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 337";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_338: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 338";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_339: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 339";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_340: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 340";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_341: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 341";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_342: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 342";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_343: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 343";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_344: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 344";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_345: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 345";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_346: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 346";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_347: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 347";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_348: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 348";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_349: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 349";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_350: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 350";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_351: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 351";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_352: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 352";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_353: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 353";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_354: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 354";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_355: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 355";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_356: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 356";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_357: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 357";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_358: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 358";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_359: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 359";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_360: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 360";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_361: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 361";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_362: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 362";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_363: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 363";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_364: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 364";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_365: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 365";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_366: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 366";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_367: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 367";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_368: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 368";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_369: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 369";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_370: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 370";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_371: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 371";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_372: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 372";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_373: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 373";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_374: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 374";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_375: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 375";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_376: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 376";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_377: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 377";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_378: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 378";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_379: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 379";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_380: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 380";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_381: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 381";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_382: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 382";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_383: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 383";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_384: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 384";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_385: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 385";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_386: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 386";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_387: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 387";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_388: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 388";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_389: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 389";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_390: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 390";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_391: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 391";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_392: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 392";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_393: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 393";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_394: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 394";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_395: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 395";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_396: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 396";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_397: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 397";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_398: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 398";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_399: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 399";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_400: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 400";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_401: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 401";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_402: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 402";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_403: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 403";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_404: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 404";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_405: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 405";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_406: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 406";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_407: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 407";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_408: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 408";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_409: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 409";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_410: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 410";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_411: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 411";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_412: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 412";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_413: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 413";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_414: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 414";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_415: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 415";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_416: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 416";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_417: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 417";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_418: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 418";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_419: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 419";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_420: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 420";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_421: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 421";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_422: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 422";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_423: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 423";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_424: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 424";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_425: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 425";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_426: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 426";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_427: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 427";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_428: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 428";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_429: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 429";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_430: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 430";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_431: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 431";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_432: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 432";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_433: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 433";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_434: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 434";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_435: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 435";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_436: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 436";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_437: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 437";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_438: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 438";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_439: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 439";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_440: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 440";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_441: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 441";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_442: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 442";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_443: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 443";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_444: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 444";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_445: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 445";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_446: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 446";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_447: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 447";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_448: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 448";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_449: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 449";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_450: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 450";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_451: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 451";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_452: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 452";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_453: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 453";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_454: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 454";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_455: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 455";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_456: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 456";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_457: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 457";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_458: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 458";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_459: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 459";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_460: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 460";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_461: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 461";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_462: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 462";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_463: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 463";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_464: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 464";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_465: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 465";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_466: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 466";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_467: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 467";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_468: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 468";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_469: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 469";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_470: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 470";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_471: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 471";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_472: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 472";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_473: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 473";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_474: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 474";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_475: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 475";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_476: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 476";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_477: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 477";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_478: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 478";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_479: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 479";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_480: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 480";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_481: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 481";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_482: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 482";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_483: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 483";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_484: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 484";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_485: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 485";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_486: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 486";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_487: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 487";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_488: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 488";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_489: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 489";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_490: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 490";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_491: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 491";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_492: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 492";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_493: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 493";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_494: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 494";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_495: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 495";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_496: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 496";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_497: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 497";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_498: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 498";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_499: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 499";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_500: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 500";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_501: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 501";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_502: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 502";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_503: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 503";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_504: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 504";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_505: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 505";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_506: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 506";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_507: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 507";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_508: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 508";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_509: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 509";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_510: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 510";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_511: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 511";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_512: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 512";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_513: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 513";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_514: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 514";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_515: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 515";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_516: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 516";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_517: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 517";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_518: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 518";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_519: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 519";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_520: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 520";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_521: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 521";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_522: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 522";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_523: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 523";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_524: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 524";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_525: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 525";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_526: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 526";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_527: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 527";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_528: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 528";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_529: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 529";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_530: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 530";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_531: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 531";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_532: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 532";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_533: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 533";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_534: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 534";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_535: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 535";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_536: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 536";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_537: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 537";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_538: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 538";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_539: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 539";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_540: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 540";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_541: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 541";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_542: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 542";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_543: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 543";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_544: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 544";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_545: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 545";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_546: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 546";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_547: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 547";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_548: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 548";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_549: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 549";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_550: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 550";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_551: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 551";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_552: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 552";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_553: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 553";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_554: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 554";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_555: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 555";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_556: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 556";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_557: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 557";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_558: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 558";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_559: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 559";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_560: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 560";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_561: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 561";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_562: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 562";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_563: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 563";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_564: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 564";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_565: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 565";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_566: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 566";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_567: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 567";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_568: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 568";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_569: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 569";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_570: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 570";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_571: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 571";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_572: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 572";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_573: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 573";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_574: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 574";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_575: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 575";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_576: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 576";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_577: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 577";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_578: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 578";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_579: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 579";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_580: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 580";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_581: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 581";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_582: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 582";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_583: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 583";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_584: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 584";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_585: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 585";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_586: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 586";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_587: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 587";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_588: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 588";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_589: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 589";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_590: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 590";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_591: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 591";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_592: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 592";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_593: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 593";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_594: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 594";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_595: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 595";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_596: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 596";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_597: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 597";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_598: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 598";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_599: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 599";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_600: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 600";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_601: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 601";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_602: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 602";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_603: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 603";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_604: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 604";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_605: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 605";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_606: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 606";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_607: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 607";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_608: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 608";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_609: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 609";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_610: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 610";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_611: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 611";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_612: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 612";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_613: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 613";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_614: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 614";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_615: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 615";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_616: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 616";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_617: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 617";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_618: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 618";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_619: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 619";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_620: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 620";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_621: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 621";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_622: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 622";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_623: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 623";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_624: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 624";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_625: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 625";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_626: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 626";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_627: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 627";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_628: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 628";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_629: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 629";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_630: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 630";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_631: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 631";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_632: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 632";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_633: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 633";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_634: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 634";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_635: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 635";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_636: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 636";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_637: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 637";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_638: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 638";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_639: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 639";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_640: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 640";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_641: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 641";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_642: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 642";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_643: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 643";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_644: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 644";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_645: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 645";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_646: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 646";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_647: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 647";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_648: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 648";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_649: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 649";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_650: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 650";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_651: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 651";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_652: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 652";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_653: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 653";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_654: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 654";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_655: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 655";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_656: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 656";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_657: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 657";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_658: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 658";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_659: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 659";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_660: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 660";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_661: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 661";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_662: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 662";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_663: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 663";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_664: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 664";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_665: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 665";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_666: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 666";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_667: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 667";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_668: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 668";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_669: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 669";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_670: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 670";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_671: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 671";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_672: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 672";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_673: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 673";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_674: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 674";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_675: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 675";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_676: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 676";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_677: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 677";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_678: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 678";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_679: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 679";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_680: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 680";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_681: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 681";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_682: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 682";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_683: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 683";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_684: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 684";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_685: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 685";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_686: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 686";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_687: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 687";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_688: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 688";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_689: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 689";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_690: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 690";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_691: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 691";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_692: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 692";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_693: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 693";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_694: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 694";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_695: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 695";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_696: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 696";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_697: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 697";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_698: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 698";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_699: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 699";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_700: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 700";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_701: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 701";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_702: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 702";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_703: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 703";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_704: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 704";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_705: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 705";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_706: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 706";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_707: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 707";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_708: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 708";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_709: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 709";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_710: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 710";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_711: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 711";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_712: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 712";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_713: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 713";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_714: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 714";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_715: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 715";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_716: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 716";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_717: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 717";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_718: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 718";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_719: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 719";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_720: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 720";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_721: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 721";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_722: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 722";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_723: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 723";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_724: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 724";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_725: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 725";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_726: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 726";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_727: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 727";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_728: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 728";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_729: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 729";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_730: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 730";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_731: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 731";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_732: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 732";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_733: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 733";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_734: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 734";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_735: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 735";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_736: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 736";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_737: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 737";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_738: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 738";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_739: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 739";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_740: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 740";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_741: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 741";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_742: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 742";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_743: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 743";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_744: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 744";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_745: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 745";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_746: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 746";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_747: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 747";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_748: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 748";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_749: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 749";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_750: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 750";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_751: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 751";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_752: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 752";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_753: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 753";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_754: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 754";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_755: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 755";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_756: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 756";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_757: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 757";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_758: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 758";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_759: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 759";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_760: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 760";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_761: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 761";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_762: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 762";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_763: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 763";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_764: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 764";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_765: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 765";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_766: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 766";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_767: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 767";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_768: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 768";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_769: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 769";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_770: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 770";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_771: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 771";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_772: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 772";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_773: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 773";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_774: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 774";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_775: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 775";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_776: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 776";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_777: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 777";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_778: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 778";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_779: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 779";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_780: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 780";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_781: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 781";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_782: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 782";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_783: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 783";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_784: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 784";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_785: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 785";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_786: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 786";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_787: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 787";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_788: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 788";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_789: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 789";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_790: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 790";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_791: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 791";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_792: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 792";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_793: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 793";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_794: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 794";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_795: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 795";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_796: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 796";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_797: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 797";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_798: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 798";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_799: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 799";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_800: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 800";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_801: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 801";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_802: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 802";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_803: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 803";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_804: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 804";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_805: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 805";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_806: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 806";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_807: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 807";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_808: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 808";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_809: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 809";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_810: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 810";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_811: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 811";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_812: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 812";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_813: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 813";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_814: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 814";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_815: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 815";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_816: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 816";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_817: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 817";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_818: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 818";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_819: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 819";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_820: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 820";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_821: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 821";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_822: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 822";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_823: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 823";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_824: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 824";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_825: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 825";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_826: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 826";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_827: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 827";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_828: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 828";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_829: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 829";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_830: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 830";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_831: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 831";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_832: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 832";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_833: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 833";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_834: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 834";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_835: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 835";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_836: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 836";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_837: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 837";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_838: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 838";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_839: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 839";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_840: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 840";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_841: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 841";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_842: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 842";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_843: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 843";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_844: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 844";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_845: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 845";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_846: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 846";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_847: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 847";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_848: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 848";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_849: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 849";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_850: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 850";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_851: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 851";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_852: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 852";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_853: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 853";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_854: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 854";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_855: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 855";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_856: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 856";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_857: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 857";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_858: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 858";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_859: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 859";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_860: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 860";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_861: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 861";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_862: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 862";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_863: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 863";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_864: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 864";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_865: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 865";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_866: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 866";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_867: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 867";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_868: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 868";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_869: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 869";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_870: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 870";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_871: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 871";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_872: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 872";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_873: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 873";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_874: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 874";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_875: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 875";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_876: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 876";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_877: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 877";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_878: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 878";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_879: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 879";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_880: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 880";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_881: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 881";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_882: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 882";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_883: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 883";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_884: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 884";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_885: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 885";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_886: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 886";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_887: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 887";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_888: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 888";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_889: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 889";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_890: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 890";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_891: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 891";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_892: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 892";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_893: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 893";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_894: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 894";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_895: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 895";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_896: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 896";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_897: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 897";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_898: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 898";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_899: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 899";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_900: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 900";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_901: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 901";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_902: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 902";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_903: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 903";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_904: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 904";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_905: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 905";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_906: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 906";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_907: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 907";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_908: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 908";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_909: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 909";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_910: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 910";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_911: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 911";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_912: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 912";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_913: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 913";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_914: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 914";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_915: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 915";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_916: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 916";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_917: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 917";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_918: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 918";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_919: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 919";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_920: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 920";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_921: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 921";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_922: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 922";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_923: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 923";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_924: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 924";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_925: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 925";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_926: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 926";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_927: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 927";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_928: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 928";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_929: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 929";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_930: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 930";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_931: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 931";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_932: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 932";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_933: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 933";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_934: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 934";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_935: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 935";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_936: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 936";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_937: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 937";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_938: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 938";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_939: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 939";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_940: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 940";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_941: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 941";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_942: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 942";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_943: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 943";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_944: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 944";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_945: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 945";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_946: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 946";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_947: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 947";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_948: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 948";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_949: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 949";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_950: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 950";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_951: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 951";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_952: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 952";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_953: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 953";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_954: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 954";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_955: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 955";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_956: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 956";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_957: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 957";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_958: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 958";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_959: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 959";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_960: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 960";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_961: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 961";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_962: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 962";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_963: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 963";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_964: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 964";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_965: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 965";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_966: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 966";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_967: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 967";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_968: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 968";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_969: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 969";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_970: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 970";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_971: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 971";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_972: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 972";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_973: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 973";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_974: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 974";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_975: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 975";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_976: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 976";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_977: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 977";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_978: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 978";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_979: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 979";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_980: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 980";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_981: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 981";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_982: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 982";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_983: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 983";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_984: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 984";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_985: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 985";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_986: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 986";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_987: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 987";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_988: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 988";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_989: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 989";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_990: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 990";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_991: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 991";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_992: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 992";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_993: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 993";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_994: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 994";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_995: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 995";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_996: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 996";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_997: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 997";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_998: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 998";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_999: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 999";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_clone_comlink_1000: 885th_clone_comlink
	{
		displayName="Nightsingers CWP-8 1000";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_1: 885th_operator_comlink
	{
		displayName="Operator CWP-8 1";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_2: 885th_operator_comlink
	{
		displayName="Operator CWP-8 2";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_3: 885th_operator_comlink
	{
		displayName="Operator CWP-8 3";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_4: 885th_operator_comlink
	{
		displayName="Operator CWP-8 4";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_5: 885th_operator_comlink
	{
		displayName="Operator CWP-8 5";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_6: 885th_operator_comlink
	{
		displayName="Operator CWP-8 6";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_7: 885th_operator_comlink
	{
		displayName="Operator CWP-8 7";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_8: 885th_operator_comlink
	{
		displayName="Operator CWP-8 8";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_9: 885th_operator_comlink
	{
		displayName="Operator CWP-8 9";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_10: 885th_operator_comlink
	{
		displayName="Operator CWP-8 10";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_11: 885th_operator_comlink
	{
		displayName="Operator CWP-8 11";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_12: 885th_operator_comlink
	{
		displayName="Operator CWP-8 12";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_13: 885th_operator_comlink
	{
		displayName="Operator CWP-8 13";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_14: 885th_operator_comlink
	{
		displayName="Operator CWP-8 14";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_15: 885th_operator_comlink
	{
		displayName="Operator CWP-8 15";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_16: 885th_operator_comlink
	{
		displayName="Operator CWP-8 16";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_17: 885th_operator_comlink
	{
		displayName="Operator CWP-8 17";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_18: 885th_operator_comlink
	{
		displayName="Operator CWP-8 18";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_19: 885th_operator_comlink
	{
		displayName="Operator CWP-8 19";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_20: 885th_operator_comlink
	{
		displayName="Operator CWP-8 20";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_21: 885th_operator_comlink
	{
		displayName="Operator CWP-8 21";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_22: 885th_operator_comlink
	{
		displayName="Operator CWP-8 22";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_23: 885th_operator_comlink
	{
		displayName="Operator CWP-8 23";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_24: 885th_operator_comlink
	{
		displayName="Operator CWP-8 24";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_25: 885th_operator_comlink
	{
		displayName="Operator CWP-8 25";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_26: 885th_operator_comlink
	{
		displayName="Operator CWP-8 26";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_27: 885th_operator_comlink
	{
		displayName="Operator CWP-8 27";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_28: 885th_operator_comlink
	{
		displayName="Operator CWP-8 28";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_29: 885th_operator_comlink
	{
		displayName="Operator CWP-8 29";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_30: 885th_operator_comlink
	{
		displayName="Operator CWP-8 30";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_31: 885th_operator_comlink
	{
		displayName="Operator CWP-8 31";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_32: 885th_operator_comlink
	{
		displayName="Operator CWP-8 32";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_33: 885th_operator_comlink
	{
		displayName="Operator CWP-8 33";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_34: 885th_operator_comlink
	{
		displayName="Operator CWP-8 34";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_35: 885th_operator_comlink
	{
		displayName="Operator CWP-8 35";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_36: 885th_operator_comlink
	{
		displayName="Operator CWP-8 36";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_37: 885th_operator_comlink
	{
		displayName="Operator CWP-8 37";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_38: 885th_operator_comlink
	{
		displayName="Operator CWP-8 38";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_39: 885th_operator_comlink
	{
		displayName="Operator CWP-8 39";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_40: 885th_operator_comlink
	{
		displayName="Operator CWP-8 40";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_41: 885th_operator_comlink
	{
		displayName="Operator CWP-8 41";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_42: 885th_operator_comlink
	{
		displayName="Operator CWP-8 42";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_43: 885th_operator_comlink
	{
		displayName="Operator CWP-8 43";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_44: 885th_operator_comlink
	{
		displayName="Operator CWP-8 44";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_45: 885th_operator_comlink
	{
		displayName="Operator CWP-8 45";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_46: 885th_operator_comlink
	{
		displayName="Operator CWP-8 46";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_47: 885th_operator_comlink
	{
		displayName="Operator CWP-8 47";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_48: 885th_operator_comlink
	{
		displayName="Operator CWP-8 48";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_49: 885th_operator_comlink
	{
		displayName="Operator CWP-8 49";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_50: 885th_operator_comlink
	{
		displayName="Operator CWP-8 50";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_51: 885th_operator_comlink
	{
		displayName="Operator CWP-8 51";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_52: 885th_operator_comlink
	{
		displayName="Operator CWP-8 52";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_53: 885th_operator_comlink
	{
		displayName="Operator CWP-8 53";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_54: 885th_operator_comlink
	{
		displayName="Operator CWP-8 54";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_55: 885th_operator_comlink
	{
		displayName="Operator CWP-8 55";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_56: 885th_operator_comlink
	{
		displayName="Operator CWP-8 56";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_57: 885th_operator_comlink
	{
		displayName="Operator CWP-8 57";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_58: 885th_operator_comlink
	{
		displayName="Operator CWP-8 58";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_59: 885th_operator_comlink
	{
		displayName="Operator CWP-8 59";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_60: 885th_operator_comlink
	{
		displayName="Operator CWP-8 60";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_61: 885th_operator_comlink
	{
		displayName="Operator CWP-8 61";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_62: 885th_operator_comlink
	{
		displayName="Operator CWP-8 62";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_63: 885th_operator_comlink
	{
		displayName="Operator CWP-8 63";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_64: 885th_operator_comlink
	{
		displayName="Operator CWP-8 64";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_65: 885th_operator_comlink
	{
		displayName="Operator CWP-8 65";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_66: 885th_operator_comlink
	{
		displayName="Operator CWP-8 66";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_67: 885th_operator_comlink
	{
		displayName="Operator CWP-8 67";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_68: 885th_operator_comlink
	{
		displayName="Operator CWP-8 68";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_69: 885th_operator_comlink
	{
		displayName="Operator CWP-8 69";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_70: 885th_operator_comlink
	{
		displayName="Operator CWP-8 70";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_71: 885th_operator_comlink
	{
		displayName="Operator CWP-8 71";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_72: 885th_operator_comlink
	{
		displayName="Operator CWP-8 72";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_73: 885th_operator_comlink
	{
		displayName="Operator CWP-8 73";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_74: 885th_operator_comlink
	{
		displayName="Operator CWP-8 74";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_75: 885th_operator_comlink
	{
		displayName="Operator CWP-8 75";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_76: 885th_operator_comlink
	{
		displayName="Operator CWP-8 76";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_77: 885th_operator_comlink
	{
		displayName="Operator CWP-8 77";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_78: 885th_operator_comlink
	{
		displayName="Operator CWP-8 78";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_79: 885th_operator_comlink
	{
		displayName="Operator CWP-8 79";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_80: 885th_operator_comlink
	{
		displayName="Operator CWP-8 80";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_81: 885th_operator_comlink
	{
		displayName="Operator CWP-8 81";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_82: 885th_operator_comlink
	{
		displayName="Operator CWP-8 82";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_83: 885th_operator_comlink
	{
		displayName="Operator CWP-8 83";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_84: 885th_operator_comlink
	{
		displayName="Operator CWP-8 84";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_85: 885th_operator_comlink
	{
		displayName="Operator CWP-8 85";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_86: 885th_operator_comlink
	{
		displayName="Operator CWP-8 86";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_87: 885th_operator_comlink
	{
		displayName="Operator CWP-8 87";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_88: 885th_operator_comlink
	{
		displayName="Operator CWP-8 88";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_89: 885th_operator_comlink
	{
		displayName="Operator CWP-8 89";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_90: 885th_operator_comlink
	{
		displayName="Operator CWP-8 90";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_91: 885th_operator_comlink
	{
		displayName="Operator CWP-8 91";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_92: 885th_operator_comlink
	{
		displayName="Operator CWP-8 92";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_93: 885th_operator_comlink
	{
		displayName="Operator CWP-8 93";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_94: 885th_operator_comlink
	{
		displayName="Operator CWP-8 94";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_95: 885th_operator_comlink
	{
		displayName="Operator CWP-8 95";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_96: 885th_operator_comlink
	{
		displayName="Operator CWP-8 96";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_97: 885th_operator_comlink
	{
		displayName="Operator CWP-8 97";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_98: 885th_operator_comlink
	{
		displayName="Operator CWP-8 98";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_99: 885th_operator_comlink
	{
		displayName="Operator CWP-8 99";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_100: 885th_operator_comlink
	{
		displayName="Operator CWP-8 100";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_101: 885th_operator_comlink
	{
		displayName="Operator CWP-8 101";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_102: 885th_operator_comlink
	{
		displayName="Operator CWP-8 102";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_103: 885th_operator_comlink
	{
		displayName="Operator CWP-8 103";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_104: 885th_operator_comlink
	{
		displayName="Operator CWP-8 104";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_105: 885th_operator_comlink
	{
		displayName="Operator CWP-8 105";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_106: 885th_operator_comlink
	{
		displayName="Operator CWP-8 106";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_107: 885th_operator_comlink
	{
		displayName="Operator CWP-8 107";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_108: 885th_operator_comlink
	{
		displayName="Operator CWP-8 108";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_109: 885th_operator_comlink
	{
		displayName="Operator CWP-8 109";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_110: 885th_operator_comlink
	{
		displayName="Operator CWP-8 110";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_111: 885th_operator_comlink
	{
		displayName="Operator CWP-8 111";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_112: 885th_operator_comlink
	{
		displayName="Operator CWP-8 112";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_113: 885th_operator_comlink
	{
		displayName="Operator CWP-8 113";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_114: 885th_operator_comlink
	{
		displayName="Operator CWP-8 114";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_115: 885th_operator_comlink
	{
		displayName="Operator CWP-8 115";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_116: 885th_operator_comlink
	{
		displayName="Operator CWP-8 116";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_117: 885th_operator_comlink
	{
		displayName="Operator CWP-8 117";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_118: 885th_operator_comlink
	{
		displayName="Operator CWP-8 118";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_119: 885th_operator_comlink
	{
		displayName="Operator CWP-8 119";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_120: 885th_operator_comlink
	{
		displayName="Operator CWP-8 120";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_121: 885th_operator_comlink
	{
		displayName="Operator CWP-8 121";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_122: 885th_operator_comlink
	{
		displayName="Operator CWP-8 122";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_123: 885th_operator_comlink
	{
		displayName="Operator CWP-8 123";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_124: 885th_operator_comlink
	{
		displayName="Operator CWP-8 124";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_125: 885th_operator_comlink
	{
		displayName="Operator CWP-8 125";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_126: 885th_operator_comlink
	{
		displayName="Operator CWP-8 126";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_127: 885th_operator_comlink
	{
		displayName="Operator CWP-8 127";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_128: 885th_operator_comlink
	{
		displayName="Operator CWP-8 128";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_129: 885th_operator_comlink
	{
		displayName="Operator CWP-8 129";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_130: 885th_operator_comlink
	{
		displayName="Operator CWP-8 130";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_131: 885th_operator_comlink
	{
		displayName="Operator CWP-8 131";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_132: 885th_operator_comlink
	{
		displayName="Operator CWP-8 132";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_133: 885th_operator_comlink
	{
		displayName="Operator CWP-8 133";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_134: 885th_operator_comlink
	{
		displayName="Operator CWP-8 134";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_135: 885th_operator_comlink
	{
		displayName="Operator CWP-8 135";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_136: 885th_operator_comlink
	{
		displayName="Operator CWP-8 136";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_137: 885th_operator_comlink
	{
		displayName="Operator CWP-8 137";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_138: 885th_operator_comlink
	{
		displayName="Operator CWP-8 138";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_139: 885th_operator_comlink
	{
		displayName="Operator CWP-8 139";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_140: 885th_operator_comlink
	{
		displayName="Operator CWP-8 140";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_141: 885th_operator_comlink
	{
		displayName="Operator CWP-8 141";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_142: 885th_operator_comlink
	{
		displayName="Operator CWP-8 142";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_143: 885th_operator_comlink
	{
		displayName="Operator CWP-8 143";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_144: 885th_operator_comlink
	{
		displayName="Operator CWP-8 144";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_145: 885th_operator_comlink
	{
		displayName="Operator CWP-8 145";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_146: 885th_operator_comlink
	{
		displayName="Operator CWP-8 146";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_147: 885th_operator_comlink
	{
		displayName="Operator CWP-8 147";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_148: 885th_operator_comlink
	{
		displayName="Operator CWP-8 148";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_149: 885th_operator_comlink
	{
		displayName="Operator CWP-8 149";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_150: 885th_operator_comlink
	{
		displayName="Operator CWP-8 150";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_151: 885th_operator_comlink
	{
		displayName="Operator CWP-8 151";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_152: 885th_operator_comlink
	{
		displayName="Operator CWP-8 152";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_153: 885th_operator_comlink
	{
		displayName="Operator CWP-8 153";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_154: 885th_operator_comlink
	{
		displayName="Operator CWP-8 154";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_155: 885th_operator_comlink
	{
		displayName="Operator CWP-8 155";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_156: 885th_operator_comlink
	{
		displayName="Operator CWP-8 156";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_157: 885th_operator_comlink
	{
		displayName="Operator CWP-8 157";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_158: 885th_operator_comlink
	{
		displayName="Operator CWP-8 158";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_159: 885th_operator_comlink
	{
		displayName="Operator CWP-8 159";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_160: 885th_operator_comlink
	{
		displayName="Operator CWP-8 160";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_161: 885th_operator_comlink
	{
		displayName="Operator CWP-8 161";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_162: 885th_operator_comlink
	{
		displayName="Operator CWP-8 162";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_163: 885th_operator_comlink
	{
		displayName="Operator CWP-8 163";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_164: 885th_operator_comlink
	{
		displayName="Operator CWP-8 164";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_165: 885th_operator_comlink
	{
		displayName="Operator CWP-8 165";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_166: 885th_operator_comlink
	{
		displayName="Operator CWP-8 166";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_167: 885th_operator_comlink
	{
		displayName="Operator CWP-8 167";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_168: 885th_operator_comlink
	{
		displayName="Operator CWP-8 168";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_169: 885th_operator_comlink
	{
		displayName="Operator CWP-8 169";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_170: 885th_operator_comlink
	{
		displayName="Operator CWP-8 170";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_171: 885th_operator_comlink
	{
		displayName="Operator CWP-8 171";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_172: 885th_operator_comlink
	{
		displayName="Operator CWP-8 172";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_173: 885th_operator_comlink
	{
		displayName="Operator CWP-8 173";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_174: 885th_operator_comlink
	{
		displayName="Operator CWP-8 174";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_175: 885th_operator_comlink
	{
		displayName="Operator CWP-8 175";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_176: 885th_operator_comlink
	{
		displayName="Operator CWP-8 176";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_177: 885th_operator_comlink
	{
		displayName="Operator CWP-8 177";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_178: 885th_operator_comlink
	{
		displayName="Operator CWP-8 178";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_179: 885th_operator_comlink
	{
		displayName="Operator CWP-8 179";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_180: 885th_operator_comlink
	{
		displayName="Operator CWP-8 180";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_181: 885th_operator_comlink
	{
		displayName="Operator CWP-8 181";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_182: 885th_operator_comlink
	{
		displayName="Operator CWP-8 182";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_183: 885th_operator_comlink
	{
		displayName="Operator CWP-8 183";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_184: 885th_operator_comlink
	{
		displayName="Operator CWP-8 184";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_185: 885th_operator_comlink
	{
		displayName="Operator CWP-8 185";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_186: 885th_operator_comlink
	{
		displayName="Operator CWP-8 186";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_187: 885th_operator_comlink
	{
		displayName="Operator CWP-8 187";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_188: 885th_operator_comlink
	{
		displayName="Operator CWP-8 188";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_189: 885th_operator_comlink
	{
		displayName="Operator CWP-8 189";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_190: 885th_operator_comlink
	{
		displayName="Operator CWP-8 190";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_191: 885th_operator_comlink
	{
		displayName="Operator CWP-8 191";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_192: 885th_operator_comlink
	{
		displayName="Operator CWP-8 192";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_193: 885th_operator_comlink
	{
		displayName="Operator CWP-8 193";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_194: 885th_operator_comlink
	{
		displayName="Operator CWP-8 194";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_195: 885th_operator_comlink
	{
		displayName="Operator CWP-8 195";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_196: 885th_operator_comlink
	{
		displayName="Operator CWP-8 196";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_197: 885th_operator_comlink
	{
		displayName="Operator CWP-8 197";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_198: 885th_operator_comlink
	{
		displayName="Operator CWP-8 198";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_199: 885th_operator_comlink
	{
		displayName="Operator CWP-8 199";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_200: 885th_operator_comlink
	{
		displayName="Operator CWP-8 200";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_201: 885th_operator_comlink
	{
		displayName="Operator CWP-8 201";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_202: 885th_operator_comlink
	{
		displayName="Operator CWP-8 202";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_203: 885th_operator_comlink
	{
		displayName="Operator CWP-8 203";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_204: 885th_operator_comlink
	{
		displayName="Operator CWP-8 204";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_205: 885th_operator_comlink
	{
		displayName="Operator CWP-8 205";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_206: 885th_operator_comlink
	{
		displayName="Operator CWP-8 206";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_207: 885th_operator_comlink
	{
		displayName="Operator CWP-8 207";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_208: 885th_operator_comlink
	{
		displayName="Operator CWP-8 208";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_209: 885th_operator_comlink
	{
		displayName="Operator CWP-8 209";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_210: 885th_operator_comlink
	{
		displayName="Operator CWP-8 210";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_211: 885th_operator_comlink
	{
		displayName="Operator CWP-8 211";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_212: 885th_operator_comlink
	{
		displayName="Operator CWP-8 212";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_213: 885th_operator_comlink
	{
		displayName="Operator CWP-8 213";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_214: 885th_operator_comlink
	{
		displayName="Operator CWP-8 214";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_215: 885th_operator_comlink
	{
		displayName="Operator CWP-8 215";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_216: 885th_operator_comlink
	{
		displayName="Operator CWP-8 216";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_217: 885th_operator_comlink
	{
		displayName="Operator CWP-8 217";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_218: 885th_operator_comlink
	{
		displayName="Operator CWP-8 218";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_219: 885th_operator_comlink
	{
		displayName="Operator CWP-8 219";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_220: 885th_operator_comlink
	{
		displayName="Operator CWP-8 220";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_221: 885th_operator_comlink
	{
		displayName="Operator CWP-8 221";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_222: 885th_operator_comlink
	{
		displayName="Operator CWP-8 222";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_223: 885th_operator_comlink
	{
		displayName="Operator CWP-8 223";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_224: 885th_operator_comlink
	{
		displayName="Operator CWP-8 224";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_225: 885th_operator_comlink
	{
		displayName="Operator CWP-8 225";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_226: 885th_operator_comlink
	{
		displayName="Operator CWP-8 226";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_227: 885th_operator_comlink
	{
		displayName="Operator CWP-8 227";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_228: 885th_operator_comlink
	{
		displayName="Operator CWP-8 228";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_229: 885th_operator_comlink
	{
		displayName="Operator CWP-8 229";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_230: 885th_operator_comlink
	{
		displayName="Operator CWP-8 230";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_231: 885th_operator_comlink
	{
		displayName="Operator CWP-8 231";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_232: 885th_operator_comlink
	{
		displayName="Operator CWP-8 232";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_233: 885th_operator_comlink
	{
		displayName="Operator CWP-8 233";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_234: 885th_operator_comlink
	{
		displayName="Operator CWP-8 234";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_235: 885th_operator_comlink
	{
		displayName="Operator CWP-8 235";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_236: 885th_operator_comlink
	{
		displayName="Operator CWP-8 236";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_237: 885th_operator_comlink
	{
		displayName="Operator CWP-8 237";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_238: 885th_operator_comlink
	{
		displayName="Operator CWP-8 238";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_239: 885th_operator_comlink
	{
		displayName="Operator CWP-8 239";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_240: 885th_operator_comlink
	{
		displayName="Operator CWP-8 240";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_241: 885th_operator_comlink
	{
		displayName="Operator CWP-8 241";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_242: 885th_operator_comlink
	{
		displayName="Operator CWP-8 242";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_243: 885th_operator_comlink
	{
		displayName="Operator CWP-8 243";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_244: 885th_operator_comlink
	{
		displayName="Operator CWP-8 244";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_245: 885th_operator_comlink
	{
		displayName="Operator CWP-8 245";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_246: 885th_operator_comlink
	{
		displayName="Operator CWP-8 246";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_247: 885th_operator_comlink
	{
		displayName="Operator CWP-8 247";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_248: 885th_operator_comlink
	{
		displayName="Operator CWP-8 248";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_249: 885th_operator_comlink
	{
		displayName="Operator CWP-8 249";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_250: 885th_operator_comlink
	{
		displayName="Operator CWP-8 250";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_251: 885th_operator_comlink
	{
		displayName="Operator CWP-8 251";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_252: 885th_operator_comlink
	{
		displayName="Operator CWP-8 252";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_253: 885th_operator_comlink
	{
		displayName="Operator CWP-8 253";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_254: 885th_operator_comlink
	{
		displayName="Operator CWP-8 254";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_255: 885th_operator_comlink
	{
		displayName="Operator CWP-8 255";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_256: 885th_operator_comlink
	{
		displayName="Operator CWP-8 256";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_257: 885th_operator_comlink
	{
		displayName="Operator CWP-8 257";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_258: 885th_operator_comlink
	{
		displayName="Operator CWP-8 258";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_259: 885th_operator_comlink
	{
		displayName="Operator CWP-8 259";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_260: 885th_operator_comlink
	{
		displayName="Operator CWP-8 260";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_261: 885th_operator_comlink
	{
		displayName="Operator CWP-8 261";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_262: 885th_operator_comlink
	{
		displayName="Operator CWP-8 262";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_263: 885th_operator_comlink
	{
		displayName="Operator CWP-8 263";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_264: 885th_operator_comlink
	{
		displayName="Operator CWP-8 264";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_265: 885th_operator_comlink
	{
		displayName="Operator CWP-8 265";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_266: 885th_operator_comlink
	{
		displayName="Operator CWP-8 266";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_267: 885th_operator_comlink
	{
		displayName="Operator CWP-8 267";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_268: 885th_operator_comlink
	{
		displayName="Operator CWP-8 268";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_269: 885th_operator_comlink
	{
		displayName="Operator CWP-8 269";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_270: 885th_operator_comlink
	{
		displayName="Operator CWP-8 270";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_271: 885th_operator_comlink
	{
		displayName="Operator CWP-8 271";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_272: 885th_operator_comlink
	{
		displayName="Operator CWP-8 272";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_273: 885th_operator_comlink
	{
		displayName="Operator CWP-8 273";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_274: 885th_operator_comlink
	{
		displayName="Operator CWP-8 274";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_275: 885th_operator_comlink
	{
		displayName="Operator CWP-8 275";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_276: 885th_operator_comlink
	{
		displayName="Operator CWP-8 276";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_277: 885th_operator_comlink
	{
		displayName="Operator CWP-8 277";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_278: 885th_operator_comlink
	{
		displayName="Operator CWP-8 278";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_279: 885th_operator_comlink
	{
		displayName="Operator CWP-8 279";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_280: 885th_operator_comlink
	{
		displayName="Operator CWP-8 280";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_281: 885th_operator_comlink
	{
		displayName="Operator CWP-8 281";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_282: 885th_operator_comlink
	{
		displayName="Operator CWP-8 282";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_283: 885th_operator_comlink
	{
		displayName="Operator CWP-8 283";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_284: 885th_operator_comlink
	{
		displayName="Operator CWP-8 284";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_285: 885th_operator_comlink
	{
		displayName="Operator CWP-8 285";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_286: 885th_operator_comlink
	{
		displayName="Operator CWP-8 286";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_287: 885th_operator_comlink
	{
		displayName="Operator CWP-8 287";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_288: 885th_operator_comlink
	{
		displayName="Operator CWP-8 288";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_289: 885th_operator_comlink
	{
		displayName="Operator CWP-8 289";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_290: 885th_operator_comlink
	{
		displayName="Operator CWP-8 290";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_291: 885th_operator_comlink
	{
		displayName="Operator CWP-8 291";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_292: 885th_operator_comlink
	{
		displayName="Operator CWP-8 292";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_293: 885th_operator_comlink
	{
		displayName="Operator CWP-8 293";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_294: 885th_operator_comlink
	{
		displayName="Operator CWP-8 294";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_295: 885th_operator_comlink
	{
		displayName="Operator CWP-8 295";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_296: 885th_operator_comlink
	{
		displayName="Operator CWP-8 296";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_297: 885th_operator_comlink
	{
		displayName="Operator CWP-8 297";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_298: 885th_operator_comlink
	{
		displayName="Operator CWP-8 298";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_299: 885th_operator_comlink
	{
		displayName="Operator CWP-8 299";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_300: 885th_operator_comlink
	{
		displayName="Operator CWP-8 300";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_301: 885th_operator_comlink
	{
		displayName="Operator CWP-8 301";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_302: 885th_operator_comlink
	{
		displayName="Operator CWP-8 302";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_303: 885th_operator_comlink
	{
		displayName="Operator CWP-8 303";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_304: 885th_operator_comlink
	{
		displayName="Operator CWP-8 304";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_305: 885th_operator_comlink
	{
		displayName="Operator CWP-8 305";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_306: 885th_operator_comlink
	{
		displayName="Operator CWP-8 306";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_307: 885th_operator_comlink
	{
		displayName="Operator CWP-8 307";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_308: 885th_operator_comlink
	{
		displayName="Operator CWP-8 308";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_309: 885th_operator_comlink
	{
		displayName="Operator CWP-8 309";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_310: 885th_operator_comlink
	{
		displayName="Operator CWP-8 310";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_311: 885th_operator_comlink
	{
		displayName="Operator CWP-8 311";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_312: 885th_operator_comlink
	{
		displayName="Operator CWP-8 312";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_313: 885th_operator_comlink
	{
		displayName="Operator CWP-8 313";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_314: 885th_operator_comlink
	{
		displayName="Operator CWP-8 314";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_315: 885th_operator_comlink
	{
		displayName="Operator CWP-8 315";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_316: 885th_operator_comlink
	{
		displayName="Operator CWP-8 316";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_317: 885th_operator_comlink
	{
		displayName="Operator CWP-8 317";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_318: 885th_operator_comlink
	{
		displayName="Operator CWP-8 318";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_319: 885th_operator_comlink
	{
		displayName="Operator CWP-8 319";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_320: 885th_operator_comlink
	{
		displayName="Operator CWP-8 320";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_321: 885th_operator_comlink
	{
		displayName="Operator CWP-8 321";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_322: 885th_operator_comlink
	{
		displayName="Operator CWP-8 322";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_323: 885th_operator_comlink
	{
		displayName="Operator CWP-8 323";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_324: 885th_operator_comlink
	{
		displayName="Operator CWP-8 324";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_325: 885th_operator_comlink
	{
		displayName="Operator CWP-8 325";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_326: 885th_operator_comlink
	{
		displayName="Operator CWP-8 326";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_327: 885th_operator_comlink
	{
		displayName="Operator CWP-8 327";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_328: 885th_operator_comlink
	{
		displayName="Operator CWP-8 328";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_329: 885th_operator_comlink
	{
		displayName="Operator CWP-8 329";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_330: 885th_operator_comlink
	{
		displayName="Operator CWP-8 330";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_331: 885th_operator_comlink
	{
		displayName="Operator CWP-8 331";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_332: 885th_operator_comlink
	{
		displayName="Operator CWP-8 332";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_333: 885th_operator_comlink
	{
		displayName="Operator CWP-8 333";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_334: 885th_operator_comlink
	{
		displayName="Operator CWP-8 334";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_335: 885th_operator_comlink
	{
		displayName="Operator CWP-8 335";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_336: 885th_operator_comlink
	{
		displayName="Operator CWP-8 336";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_337: 885th_operator_comlink
	{
		displayName="Operator CWP-8 337";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_338: 885th_operator_comlink
	{
		displayName="Operator CWP-8 338";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_339: 885th_operator_comlink
	{
		displayName="Operator CWP-8 339";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_340: 885th_operator_comlink
	{
		displayName="Operator CWP-8 340";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_341: 885th_operator_comlink
	{
		displayName="Operator CWP-8 341";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_342: 885th_operator_comlink
	{
		displayName="Operator CWP-8 342";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_343: 885th_operator_comlink
	{
		displayName="Operator CWP-8 343";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_344: 885th_operator_comlink
	{
		displayName="Operator CWP-8 344";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_345: 885th_operator_comlink
	{
		displayName="Operator CWP-8 345";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_346: 885th_operator_comlink
	{
		displayName="Operator CWP-8 346";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_347: 885th_operator_comlink
	{
		displayName="Operator CWP-8 347";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_348: 885th_operator_comlink
	{
		displayName="Operator CWP-8 348";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_349: 885th_operator_comlink
	{
		displayName="Operator CWP-8 349";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_350: 885th_operator_comlink
	{
		displayName="Operator CWP-8 350";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_351: 885th_operator_comlink
	{
		displayName="Operator CWP-8 351";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_352: 885th_operator_comlink
	{
		displayName="Operator CWP-8 352";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_353: 885th_operator_comlink
	{
		displayName="Operator CWP-8 353";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_354: 885th_operator_comlink
	{
		displayName="Operator CWP-8 354";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_355: 885th_operator_comlink
	{
		displayName="Operator CWP-8 355";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_356: 885th_operator_comlink
	{
		displayName="Operator CWP-8 356";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_357: 885th_operator_comlink
	{
		displayName="Operator CWP-8 357";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_358: 885th_operator_comlink
	{
		displayName="Operator CWP-8 358";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_359: 885th_operator_comlink
	{
		displayName="Operator CWP-8 359";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_360: 885th_operator_comlink
	{
		displayName="Operator CWP-8 360";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_361: 885th_operator_comlink
	{
		displayName="Operator CWP-8 361";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_362: 885th_operator_comlink
	{
		displayName="Operator CWP-8 362";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_363: 885th_operator_comlink
	{
		displayName="Operator CWP-8 363";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_364: 885th_operator_comlink
	{
		displayName="Operator CWP-8 364";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_365: 885th_operator_comlink
	{
		displayName="Operator CWP-8 365";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_366: 885th_operator_comlink
	{
		displayName="Operator CWP-8 366";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_367: 885th_operator_comlink
	{
		displayName="Operator CWP-8 367";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_368: 885th_operator_comlink
	{
		displayName="Operator CWP-8 368";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_369: 885th_operator_comlink
	{
		displayName="Operator CWP-8 369";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_370: 885th_operator_comlink
	{
		displayName="Operator CWP-8 370";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_371: 885th_operator_comlink
	{
		displayName="Operator CWP-8 371";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_372: 885th_operator_comlink
	{
		displayName="Operator CWP-8 372";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_373: 885th_operator_comlink
	{
		displayName="Operator CWP-8 373";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_374: 885th_operator_comlink
	{
		displayName="Operator CWP-8 374";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_375: 885th_operator_comlink
	{
		displayName="Operator CWP-8 375";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_376: 885th_operator_comlink
	{
		displayName="Operator CWP-8 376";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_377: 885th_operator_comlink
	{
		displayName="Operator CWP-8 377";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_378: 885th_operator_comlink
	{
		displayName="Operator CWP-8 378";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_379: 885th_operator_comlink
	{
		displayName="Operator CWP-8 379";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_380: 885th_operator_comlink
	{
		displayName="Operator CWP-8 380";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_381: 885th_operator_comlink
	{
		displayName="Operator CWP-8 381";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_382: 885th_operator_comlink
	{
		displayName="Operator CWP-8 382";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_383: 885th_operator_comlink
	{
		displayName="Operator CWP-8 383";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_384: 885th_operator_comlink
	{
		displayName="Operator CWP-8 384";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_385: 885th_operator_comlink
	{
		displayName="Operator CWP-8 385";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_386: 885th_operator_comlink
	{
		displayName="Operator CWP-8 386";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_387: 885th_operator_comlink
	{
		displayName="Operator CWP-8 387";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_388: 885th_operator_comlink
	{
		displayName="Operator CWP-8 388";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_389: 885th_operator_comlink
	{
		displayName="Operator CWP-8 389";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_390: 885th_operator_comlink
	{
		displayName="Operator CWP-8 390";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_391: 885th_operator_comlink
	{
		displayName="Operator CWP-8 391";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_392: 885th_operator_comlink
	{
		displayName="Operator CWP-8 392";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_393: 885th_operator_comlink
	{
		displayName="Operator CWP-8 393";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_394: 885th_operator_comlink
	{
		displayName="Operator CWP-8 394";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_395: 885th_operator_comlink
	{
		displayName="Operator CWP-8 395";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_396: 885th_operator_comlink
	{
		displayName="Operator CWP-8 396";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_397: 885th_operator_comlink
	{
		displayName="Operator CWP-8 397";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_398: 885th_operator_comlink
	{
		displayName="Operator CWP-8 398";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_399: 885th_operator_comlink
	{
		displayName="Operator CWP-8 399";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_400: 885th_operator_comlink
	{
		displayName="Operator CWP-8 400";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_401: 885th_operator_comlink
	{
		displayName="Operator CWP-8 401";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_402: 885th_operator_comlink
	{
		displayName="Operator CWP-8 402";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_403: 885th_operator_comlink
	{
		displayName="Operator CWP-8 403";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_404: 885th_operator_comlink
	{
		displayName="Operator CWP-8 404";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_405: 885th_operator_comlink
	{
		displayName="Operator CWP-8 405";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_406: 885th_operator_comlink
	{
		displayName="Operator CWP-8 406";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_407: 885th_operator_comlink
	{
		displayName="Operator CWP-8 407";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_408: 885th_operator_comlink
	{
		displayName="Operator CWP-8 408";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_409: 885th_operator_comlink
	{
		displayName="Operator CWP-8 409";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_410: 885th_operator_comlink
	{
		displayName="Operator CWP-8 410";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_411: 885th_operator_comlink
	{
		displayName="Operator CWP-8 411";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_412: 885th_operator_comlink
	{
		displayName="Operator CWP-8 412";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_413: 885th_operator_comlink
	{
		displayName="Operator CWP-8 413";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_414: 885th_operator_comlink
	{
		displayName="Operator CWP-8 414";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_415: 885th_operator_comlink
	{
		displayName="Operator CWP-8 415";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_416: 885th_operator_comlink
	{
		displayName="Operator CWP-8 416";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_417: 885th_operator_comlink
	{
		displayName="Operator CWP-8 417";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_418: 885th_operator_comlink
	{
		displayName="Operator CWP-8 418";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_419: 885th_operator_comlink
	{
		displayName="Operator CWP-8 419";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_420: 885th_operator_comlink
	{
		displayName="Operator CWP-8 420";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_421: 885th_operator_comlink
	{
		displayName="Operator CWP-8 421";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_422: 885th_operator_comlink
	{
		displayName="Operator CWP-8 422";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_423: 885th_operator_comlink
	{
		displayName="Operator CWP-8 423";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_424: 885th_operator_comlink
	{
		displayName="Operator CWP-8 424";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_425: 885th_operator_comlink
	{
		displayName="Operator CWP-8 425";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_426: 885th_operator_comlink
	{
		displayName="Operator CWP-8 426";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_427: 885th_operator_comlink
	{
		displayName="Operator CWP-8 427";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_428: 885th_operator_comlink
	{
		displayName="Operator CWP-8 428";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_429: 885th_operator_comlink
	{
		displayName="Operator CWP-8 429";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_430: 885th_operator_comlink
	{
		displayName="Operator CWP-8 430";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_431: 885th_operator_comlink
	{
		displayName="Operator CWP-8 431";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_432: 885th_operator_comlink
	{
		displayName="Operator CWP-8 432";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_433: 885th_operator_comlink
	{
		displayName="Operator CWP-8 433";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_434: 885th_operator_comlink
	{
		displayName="Operator CWP-8 434";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_435: 885th_operator_comlink
	{
		displayName="Operator CWP-8 435";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_436: 885th_operator_comlink
	{
		displayName="Operator CWP-8 436";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_437: 885th_operator_comlink
	{
		displayName="Operator CWP-8 437";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_438: 885th_operator_comlink
	{
		displayName="Operator CWP-8 438";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_439: 885th_operator_comlink
	{
		displayName="Operator CWP-8 439";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_440: 885th_operator_comlink
	{
		displayName="Operator CWP-8 440";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_441: 885th_operator_comlink
	{
		displayName="Operator CWP-8 441";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_442: 885th_operator_comlink
	{
		displayName="Operator CWP-8 442";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_443: 885th_operator_comlink
	{
		displayName="Operator CWP-8 443";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_444: 885th_operator_comlink
	{
		displayName="Operator CWP-8 444";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_445: 885th_operator_comlink
	{
		displayName="Operator CWP-8 445";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_446: 885th_operator_comlink
	{
		displayName="Operator CWP-8 446";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_447: 885th_operator_comlink
	{
		displayName="Operator CWP-8 447";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_448: 885th_operator_comlink
	{
		displayName="Operator CWP-8 448";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_449: 885th_operator_comlink
	{
		displayName="Operator CWP-8 449";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_450: 885th_operator_comlink
	{
		displayName="Operator CWP-8 450";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_451: 885th_operator_comlink
	{
		displayName="Operator CWP-8 451";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_452: 885th_operator_comlink
	{
		displayName="Operator CWP-8 452";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_453: 885th_operator_comlink
	{
		displayName="Operator CWP-8 453";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_454: 885th_operator_comlink
	{
		displayName="Operator CWP-8 454";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_455: 885th_operator_comlink
	{
		displayName="Operator CWP-8 455";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_456: 885th_operator_comlink
	{
		displayName="Operator CWP-8 456";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_457: 885th_operator_comlink
	{
		displayName="Operator CWP-8 457";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_458: 885th_operator_comlink
	{
		displayName="Operator CWP-8 458";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_459: 885th_operator_comlink
	{
		displayName="Operator CWP-8 459";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_460: 885th_operator_comlink
	{
		displayName="Operator CWP-8 460";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_461: 885th_operator_comlink
	{
		displayName="Operator CWP-8 461";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_462: 885th_operator_comlink
	{
		displayName="Operator CWP-8 462";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_463: 885th_operator_comlink
	{
		displayName="Operator CWP-8 463";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_464: 885th_operator_comlink
	{
		displayName="Operator CWP-8 464";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_465: 885th_operator_comlink
	{
		displayName="Operator CWP-8 465";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_466: 885th_operator_comlink
	{
		displayName="Operator CWP-8 466";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_467: 885th_operator_comlink
	{
		displayName="Operator CWP-8 467";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_468: 885th_operator_comlink
	{
		displayName="Operator CWP-8 468";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_469: 885th_operator_comlink
	{
		displayName="Operator CWP-8 469";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_470: 885th_operator_comlink
	{
		displayName="Operator CWP-8 470";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_471: 885th_operator_comlink
	{
		displayName="Operator CWP-8 471";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_472: 885th_operator_comlink
	{
		displayName="Operator CWP-8 472";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_473: 885th_operator_comlink
	{
		displayName="Operator CWP-8 473";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_474: 885th_operator_comlink
	{
		displayName="Operator CWP-8 474";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_475: 885th_operator_comlink
	{
		displayName="Operator CWP-8 475";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_476: 885th_operator_comlink
	{
		displayName="Operator CWP-8 476";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_477: 885th_operator_comlink
	{
		displayName="Operator CWP-8 477";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_478: 885th_operator_comlink
	{
		displayName="Operator CWP-8 478";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_479: 885th_operator_comlink
	{
		displayName="Operator CWP-8 479";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_480: 885th_operator_comlink
	{
		displayName="Operator CWP-8 480";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_481: 885th_operator_comlink
	{
		displayName="Operator CWP-8 481";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_482: 885th_operator_comlink
	{
		displayName="Operator CWP-8 482";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_483: 885th_operator_comlink
	{
		displayName="Operator CWP-8 483";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_484: 885th_operator_comlink
	{
		displayName="Operator CWP-8 484";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_485: 885th_operator_comlink
	{
		displayName="Operator CWP-8 485";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_486: 885th_operator_comlink
	{
		displayName="Operator CWP-8 486";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_487: 885th_operator_comlink
	{
		displayName="Operator CWP-8 487";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_488: 885th_operator_comlink
	{
		displayName="Operator CWP-8 488";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_489: 885th_operator_comlink
	{
		displayName="Operator CWP-8 489";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_490: 885th_operator_comlink
	{
		displayName="Operator CWP-8 490";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_491: 885th_operator_comlink
	{
		displayName="Operator CWP-8 491";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_492: 885th_operator_comlink
	{
		displayName="Operator CWP-8 492";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_493: 885th_operator_comlink
	{
		displayName="Operator CWP-8 493";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_494: 885th_operator_comlink
	{
		displayName="Operator CWP-8 494";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_495: 885th_operator_comlink
	{
		displayName="Operator CWP-8 495";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_496: 885th_operator_comlink
	{
		displayName="Operator CWP-8 496";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_497: 885th_operator_comlink
	{
		displayName="Operator CWP-8 497";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_498: 885th_operator_comlink
	{
		displayName="Operator CWP-8 498";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_499: 885th_operator_comlink
	{
		displayName="Operator CWP-8 499";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_500: 885th_operator_comlink
	{
		displayName="Operator CWP-8 500";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_501: 885th_operator_comlink
	{
		displayName="Operator CWP-8 501";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_502: 885th_operator_comlink
	{
		displayName="Operator CWP-8 502";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_503: 885th_operator_comlink
	{
		displayName="Operator CWP-8 503";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_504: 885th_operator_comlink
	{
		displayName="Operator CWP-8 504";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_505: 885th_operator_comlink
	{
		displayName="Operator CWP-8 505";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_506: 885th_operator_comlink
	{
		displayName="Operator CWP-8 506";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_507: 885th_operator_comlink
	{
		displayName="Operator CWP-8 507";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_508: 885th_operator_comlink
	{
		displayName="Operator CWP-8 508";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_509: 885th_operator_comlink
	{
		displayName="Operator CWP-8 509";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_510: 885th_operator_comlink
	{
		displayName="Operator CWP-8 510";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_511: 885th_operator_comlink
	{
		displayName="Operator CWP-8 511";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_512: 885th_operator_comlink
	{
		displayName="Operator CWP-8 512";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_513: 885th_operator_comlink
	{
		displayName="Operator CWP-8 513";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_514: 885th_operator_comlink
	{
		displayName="Operator CWP-8 514";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_515: 885th_operator_comlink
	{
		displayName="Operator CWP-8 515";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_516: 885th_operator_comlink
	{
		displayName="Operator CWP-8 516";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_517: 885th_operator_comlink
	{
		displayName="Operator CWP-8 517";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_518: 885th_operator_comlink
	{
		displayName="Operator CWP-8 518";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_519: 885th_operator_comlink
	{
		displayName="Operator CWP-8 519";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_520: 885th_operator_comlink
	{
		displayName="Operator CWP-8 520";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_521: 885th_operator_comlink
	{
		displayName="Operator CWP-8 521";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_522: 885th_operator_comlink
	{
		displayName="Operator CWP-8 522";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_523: 885th_operator_comlink
	{
		displayName="Operator CWP-8 523";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_524: 885th_operator_comlink
	{
		displayName="Operator CWP-8 524";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_525: 885th_operator_comlink
	{
		displayName="Operator CWP-8 525";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_526: 885th_operator_comlink
	{
		displayName="Operator CWP-8 526";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_527: 885th_operator_comlink
	{
		displayName="Operator CWP-8 527";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_528: 885th_operator_comlink
	{
		displayName="Operator CWP-8 528";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_529: 885th_operator_comlink
	{
		displayName="Operator CWP-8 529";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_530: 885th_operator_comlink
	{
		displayName="Operator CWP-8 530";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_531: 885th_operator_comlink
	{
		displayName="Operator CWP-8 531";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_532: 885th_operator_comlink
	{
		displayName="Operator CWP-8 532";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_533: 885th_operator_comlink
	{
		displayName="Operator CWP-8 533";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_534: 885th_operator_comlink
	{
		displayName="Operator CWP-8 534";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_535: 885th_operator_comlink
	{
		displayName="Operator CWP-8 535";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_536: 885th_operator_comlink
	{
		displayName="Operator CWP-8 536";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_537: 885th_operator_comlink
	{
		displayName="Operator CWP-8 537";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_538: 885th_operator_comlink
	{
		displayName="Operator CWP-8 538";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_539: 885th_operator_comlink
	{
		displayName="Operator CWP-8 539";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_540: 885th_operator_comlink
	{
		displayName="Operator CWP-8 540";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_541: 885th_operator_comlink
	{
		displayName="Operator CWP-8 541";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_542: 885th_operator_comlink
	{
		displayName="Operator CWP-8 542";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_543: 885th_operator_comlink
	{
		displayName="Operator CWP-8 543";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_544: 885th_operator_comlink
	{
		displayName="Operator CWP-8 544";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_545: 885th_operator_comlink
	{
		displayName="Operator CWP-8 545";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_546: 885th_operator_comlink
	{
		displayName="Operator CWP-8 546";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_547: 885th_operator_comlink
	{
		displayName="Operator CWP-8 547";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_548: 885th_operator_comlink
	{
		displayName="Operator CWP-8 548";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_549: 885th_operator_comlink
	{
		displayName="Operator CWP-8 549";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_550: 885th_operator_comlink
	{
		displayName="Operator CWP-8 550";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_551: 885th_operator_comlink
	{
		displayName="Operator CWP-8 551";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_552: 885th_operator_comlink
	{
		displayName="Operator CWP-8 552";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_553: 885th_operator_comlink
	{
		displayName="Operator CWP-8 553";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_554: 885th_operator_comlink
	{
		displayName="Operator CWP-8 554";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_555: 885th_operator_comlink
	{
		displayName="Operator CWP-8 555";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_556: 885th_operator_comlink
	{
		displayName="Operator CWP-8 556";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_557: 885th_operator_comlink
	{
		displayName="Operator CWP-8 557";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_558: 885th_operator_comlink
	{
		displayName="Operator CWP-8 558";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_559: 885th_operator_comlink
	{
		displayName="Operator CWP-8 559";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_560: 885th_operator_comlink
	{
		displayName="Operator CWP-8 560";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_561: 885th_operator_comlink
	{
		displayName="Operator CWP-8 561";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_562: 885th_operator_comlink
	{
		displayName="Operator CWP-8 562";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_563: 885th_operator_comlink
	{
		displayName="Operator CWP-8 563";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_564: 885th_operator_comlink
	{
		displayName="Operator CWP-8 564";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_565: 885th_operator_comlink
	{
		displayName="Operator CWP-8 565";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_566: 885th_operator_comlink
	{
		displayName="Operator CWP-8 566";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_567: 885th_operator_comlink
	{
		displayName="Operator CWP-8 567";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_568: 885th_operator_comlink
	{
		displayName="Operator CWP-8 568";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_569: 885th_operator_comlink
	{
		displayName="Operator CWP-8 569";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_570: 885th_operator_comlink
	{
		displayName="Operator CWP-8 570";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_571: 885th_operator_comlink
	{
		displayName="Operator CWP-8 571";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_572: 885th_operator_comlink
	{
		displayName="Operator CWP-8 572";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_573: 885th_operator_comlink
	{
		displayName="Operator CWP-8 573";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_574: 885th_operator_comlink
	{
		displayName="Operator CWP-8 574";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_575: 885th_operator_comlink
	{
		displayName="Operator CWP-8 575";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_576: 885th_operator_comlink
	{
		displayName="Operator CWP-8 576";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_577: 885th_operator_comlink
	{
		displayName="Operator CWP-8 577";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_578: 885th_operator_comlink
	{
		displayName="Operator CWP-8 578";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_579: 885th_operator_comlink
	{
		displayName="Operator CWP-8 579";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_580: 885th_operator_comlink
	{
		displayName="Operator CWP-8 580";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_581: 885th_operator_comlink
	{
		displayName="Operator CWP-8 581";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_582: 885th_operator_comlink
	{
		displayName="Operator CWP-8 582";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_583: 885th_operator_comlink
	{
		displayName="Operator CWP-8 583";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_584: 885th_operator_comlink
	{
		displayName="Operator CWP-8 584";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_585: 885th_operator_comlink
	{
		displayName="Operator CWP-8 585";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_586: 885th_operator_comlink
	{
		displayName="Operator CWP-8 586";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_587: 885th_operator_comlink
	{
		displayName="Operator CWP-8 587";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_588: 885th_operator_comlink
	{
		displayName="Operator CWP-8 588";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_589: 885th_operator_comlink
	{
		displayName="Operator CWP-8 589";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_590: 885th_operator_comlink
	{
		displayName="Operator CWP-8 590";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_591: 885th_operator_comlink
	{
		displayName="Operator CWP-8 591";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_592: 885th_operator_comlink
	{
		displayName="Operator CWP-8 592";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_593: 885th_operator_comlink
	{
		displayName="Operator CWP-8 593";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_594: 885th_operator_comlink
	{
		displayName="Operator CWP-8 594";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_595: 885th_operator_comlink
	{
		displayName="Operator CWP-8 595";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_596: 885th_operator_comlink
	{
		displayName="Operator CWP-8 596";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_597: 885th_operator_comlink
	{
		displayName="Operator CWP-8 597";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_598: 885th_operator_comlink
	{
		displayName="Operator CWP-8 598";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_599: 885th_operator_comlink
	{
		displayName="Operator CWP-8 599";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_600: 885th_operator_comlink
	{
		displayName="Operator CWP-8 600";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_601: 885th_operator_comlink
	{
		displayName="Operator CWP-8 601";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_602: 885th_operator_comlink
	{
		displayName="Operator CWP-8 602";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_603: 885th_operator_comlink
	{
		displayName="Operator CWP-8 603";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_604: 885th_operator_comlink
	{
		displayName="Operator CWP-8 604";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_605: 885th_operator_comlink
	{
		displayName="Operator CWP-8 605";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_606: 885th_operator_comlink
	{
		displayName="Operator CWP-8 606";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_607: 885th_operator_comlink
	{
		displayName="Operator CWP-8 607";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_608: 885th_operator_comlink
	{
		displayName="Operator CWP-8 608";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_609: 885th_operator_comlink
	{
		displayName="Operator CWP-8 609";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_610: 885th_operator_comlink
	{
		displayName="Operator CWP-8 610";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_611: 885th_operator_comlink
	{
		displayName="Operator CWP-8 611";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_612: 885th_operator_comlink
	{
		displayName="Operator CWP-8 612";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_613: 885th_operator_comlink
	{
		displayName="Operator CWP-8 613";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_614: 885th_operator_comlink
	{
		displayName="Operator CWP-8 614";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_615: 885th_operator_comlink
	{
		displayName="Operator CWP-8 615";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_616: 885th_operator_comlink
	{
		displayName="Operator CWP-8 616";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_617: 885th_operator_comlink
	{
		displayName="Operator CWP-8 617";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_618: 885th_operator_comlink
	{
		displayName="Operator CWP-8 618";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_619: 885th_operator_comlink
	{
		displayName="Operator CWP-8 619";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_620: 885th_operator_comlink
	{
		displayName="Operator CWP-8 620";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_621: 885th_operator_comlink
	{
		displayName="Operator CWP-8 621";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_622: 885th_operator_comlink
	{
		displayName="Operator CWP-8 622";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_623: 885th_operator_comlink
	{
		displayName="Operator CWP-8 623";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_624: 885th_operator_comlink
	{
		displayName="Operator CWP-8 624";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_625: 885th_operator_comlink
	{
		displayName="Operator CWP-8 625";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_626: 885th_operator_comlink
	{
		displayName="Operator CWP-8 626";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_627: 885th_operator_comlink
	{
		displayName="Operator CWP-8 627";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_628: 885th_operator_comlink
	{
		displayName="Operator CWP-8 628";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_629: 885th_operator_comlink
	{
		displayName="Operator CWP-8 629";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_630: 885th_operator_comlink
	{
		displayName="Operator CWP-8 630";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_631: 885th_operator_comlink
	{
		displayName="Operator CWP-8 631";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_632: 885th_operator_comlink
	{
		displayName="Operator CWP-8 632";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_633: 885th_operator_comlink
	{
		displayName="Operator CWP-8 633";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_634: 885th_operator_comlink
	{
		displayName="Operator CWP-8 634";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_635: 885th_operator_comlink
	{
		displayName="Operator CWP-8 635";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_636: 885th_operator_comlink
	{
		displayName="Operator CWP-8 636";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_637: 885th_operator_comlink
	{
		displayName="Operator CWP-8 637";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_638: 885th_operator_comlink
	{
		displayName="Operator CWP-8 638";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_639: 885th_operator_comlink
	{
		displayName="Operator CWP-8 639";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_640: 885th_operator_comlink
	{
		displayName="Operator CWP-8 640";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_641: 885th_operator_comlink
	{
		displayName="Operator CWP-8 641";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_642: 885th_operator_comlink
	{
		displayName="Operator CWP-8 642";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_643: 885th_operator_comlink
	{
		displayName="Operator CWP-8 643";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_644: 885th_operator_comlink
	{
		displayName="Operator CWP-8 644";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_645: 885th_operator_comlink
	{
		displayName="Operator CWP-8 645";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_646: 885th_operator_comlink
	{
		displayName="Operator CWP-8 646";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_647: 885th_operator_comlink
	{
		displayName="Operator CWP-8 647";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_648: 885th_operator_comlink
	{
		displayName="Operator CWP-8 648";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_649: 885th_operator_comlink
	{
		displayName="Operator CWP-8 649";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_650: 885th_operator_comlink
	{
		displayName="Operator CWP-8 650";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_651: 885th_operator_comlink
	{
		displayName="Operator CWP-8 651";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_652: 885th_operator_comlink
	{
		displayName="Operator CWP-8 652";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_653: 885th_operator_comlink
	{
		displayName="Operator CWP-8 653";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_654: 885th_operator_comlink
	{
		displayName="Operator CWP-8 654";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_655: 885th_operator_comlink
	{
		displayName="Operator CWP-8 655";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_656: 885th_operator_comlink
	{
		displayName="Operator CWP-8 656";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_657: 885th_operator_comlink
	{
		displayName="Operator CWP-8 657";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_658: 885th_operator_comlink
	{
		displayName="Operator CWP-8 658";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_659: 885th_operator_comlink
	{
		displayName="Operator CWP-8 659";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_660: 885th_operator_comlink
	{
		displayName="Operator CWP-8 660";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_661: 885th_operator_comlink
	{
		displayName="Operator CWP-8 661";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_662: 885th_operator_comlink
	{
		displayName="Operator CWP-8 662";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_663: 885th_operator_comlink
	{
		displayName="Operator CWP-8 663";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_664: 885th_operator_comlink
	{
		displayName="Operator CWP-8 664";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_665: 885th_operator_comlink
	{
		displayName="Operator CWP-8 665";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_666: 885th_operator_comlink
	{
		displayName="Operator CWP-8 666";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_667: 885th_operator_comlink
	{
		displayName="Operator CWP-8 667";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_668: 885th_operator_comlink
	{
		displayName="Operator CWP-8 668";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_669: 885th_operator_comlink
	{
		displayName="Operator CWP-8 669";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_670: 885th_operator_comlink
	{
		displayName="Operator CWP-8 670";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_671: 885th_operator_comlink
	{
		displayName="Operator CWP-8 671";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_672: 885th_operator_comlink
	{
		displayName="Operator CWP-8 672";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_673: 885th_operator_comlink
	{
		displayName="Operator CWP-8 673";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_674: 885th_operator_comlink
	{
		displayName="Operator CWP-8 674";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_675: 885th_operator_comlink
	{
		displayName="Operator CWP-8 675";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_676: 885th_operator_comlink
	{
		displayName="Operator CWP-8 676";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_677: 885th_operator_comlink
	{
		displayName="Operator CWP-8 677";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_678: 885th_operator_comlink
	{
		displayName="Operator CWP-8 678";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_679: 885th_operator_comlink
	{
		displayName="Operator CWP-8 679";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_680: 885th_operator_comlink
	{
		displayName="Operator CWP-8 680";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_681: 885th_operator_comlink
	{
		displayName="Operator CWP-8 681";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_682: 885th_operator_comlink
	{
		displayName="Operator CWP-8 682";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_683: 885th_operator_comlink
	{
		displayName="Operator CWP-8 683";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_684: 885th_operator_comlink
	{
		displayName="Operator CWP-8 684";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_685: 885th_operator_comlink
	{
		displayName="Operator CWP-8 685";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_686: 885th_operator_comlink
	{
		displayName="Operator CWP-8 686";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_687: 885th_operator_comlink
	{
		displayName="Operator CWP-8 687";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_688: 885th_operator_comlink
	{
		displayName="Operator CWP-8 688";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_689: 885th_operator_comlink
	{
		displayName="Operator CWP-8 689";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_690: 885th_operator_comlink
	{
		displayName="Operator CWP-8 690";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_691: 885th_operator_comlink
	{
		displayName="Operator CWP-8 691";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_692: 885th_operator_comlink
	{
		displayName="Operator CWP-8 692";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_693: 885th_operator_comlink
	{
		displayName="Operator CWP-8 693";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_694: 885th_operator_comlink
	{
		displayName="Operator CWP-8 694";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_695: 885th_operator_comlink
	{
		displayName="Operator CWP-8 695";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_696: 885th_operator_comlink
	{
		displayName="Operator CWP-8 696";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_697: 885th_operator_comlink
	{
		displayName="Operator CWP-8 697";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_698: 885th_operator_comlink
	{
		displayName="Operator CWP-8 698";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_699: 885th_operator_comlink
	{
		displayName="Operator CWP-8 699";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_700: 885th_operator_comlink
	{
		displayName="Operator CWP-8 700";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_701: 885th_operator_comlink
	{
		displayName="Operator CWP-8 701";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_702: 885th_operator_comlink
	{
		displayName="Operator CWP-8 702";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_703: 885th_operator_comlink
	{
		displayName="Operator CWP-8 703";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_704: 885th_operator_comlink
	{
		displayName="Operator CWP-8 704";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_705: 885th_operator_comlink
	{
		displayName="Operator CWP-8 705";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_706: 885th_operator_comlink
	{
		displayName="Operator CWP-8 706";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_707: 885th_operator_comlink
	{
		displayName="Operator CWP-8 707";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_708: 885th_operator_comlink
	{
		displayName="Operator CWP-8 708";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_709: 885th_operator_comlink
	{
		displayName="Operator CWP-8 709";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_710: 885th_operator_comlink
	{
		displayName="Operator CWP-8 710";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_711: 885th_operator_comlink
	{
		displayName="Operator CWP-8 711";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_712: 885th_operator_comlink
	{
		displayName="Operator CWP-8 712";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_713: 885th_operator_comlink
	{
		displayName="Operator CWP-8 713";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_714: 885th_operator_comlink
	{
		displayName="Operator CWP-8 714";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_715: 885th_operator_comlink
	{
		displayName="Operator CWP-8 715";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_716: 885th_operator_comlink
	{
		displayName="Operator CWP-8 716";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_717: 885th_operator_comlink
	{
		displayName="Operator CWP-8 717";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_718: 885th_operator_comlink
	{
		displayName="Operator CWP-8 718";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_719: 885th_operator_comlink
	{
		displayName="Operator CWP-8 719";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_720: 885th_operator_comlink
	{
		displayName="Operator CWP-8 720";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_721: 885th_operator_comlink
	{
		displayName="Operator CWP-8 721";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_722: 885th_operator_comlink
	{
		displayName="Operator CWP-8 722";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_723: 885th_operator_comlink
	{
		displayName="Operator CWP-8 723";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_724: 885th_operator_comlink
	{
		displayName="Operator CWP-8 724";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_725: 885th_operator_comlink
	{
		displayName="Operator CWP-8 725";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_726: 885th_operator_comlink
	{
		displayName="Operator CWP-8 726";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_727: 885th_operator_comlink
	{
		displayName="Operator CWP-8 727";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_728: 885th_operator_comlink
	{
		displayName="Operator CWP-8 728";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_729: 885th_operator_comlink
	{
		displayName="Operator CWP-8 729";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_730: 885th_operator_comlink
	{
		displayName="Operator CWP-8 730";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_731: 885th_operator_comlink
	{
		displayName="Operator CWP-8 731";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_732: 885th_operator_comlink
	{
		displayName="Operator CWP-8 732";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_733: 885th_operator_comlink
	{
		displayName="Operator CWP-8 733";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_734: 885th_operator_comlink
	{
		displayName="Operator CWP-8 734";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_735: 885th_operator_comlink
	{
		displayName="Operator CWP-8 735";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_736: 885th_operator_comlink
	{
		displayName="Operator CWP-8 736";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_737: 885th_operator_comlink
	{
		displayName="Operator CWP-8 737";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_738: 885th_operator_comlink
	{
		displayName="Operator CWP-8 738";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_739: 885th_operator_comlink
	{
		displayName="Operator CWP-8 739";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_740: 885th_operator_comlink
	{
		displayName="Operator CWP-8 740";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_741: 885th_operator_comlink
	{
		displayName="Operator CWP-8 741";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_742: 885th_operator_comlink
	{
		displayName="Operator CWP-8 742";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_743: 885th_operator_comlink
	{
		displayName="Operator CWP-8 743";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_744: 885th_operator_comlink
	{
		displayName="Operator CWP-8 744";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_745: 885th_operator_comlink
	{
		displayName="Operator CWP-8 745";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_746: 885th_operator_comlink
	{
		displayName="Operator CWP-8 746";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_747: 885th_operator_comlink
	{
		displayName="Operator CWP-8 747";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_748: 885th_operator_comlink
	{
		displayName="Operator CWP-8 748";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_749: 885th_operator_comlink
	{
		displayName="Operator CWP-8 749";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_750: 885th_operator_comlink
	{
		displayName="Operator CWP-8 750";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_751: 885th_operator_comlink
	{
		displayName="Operator CWP-8 751";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_752: 885th_operator_comlink
	{
		displayName="Operator CWP-8 752";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_753: 885th_operator_comlink
	{
		displayName="Operator CWP-8 753";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_754: 885th_operator_comlink
	{
		displayName="Operator CWP-8 754";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_755: 885th_operator_comlink
	{
		displayName="Operator CWP-8 755";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_756: 885th_operator_comlink
	{
		displayName="Operator CWP-8 756";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_757: 885th_operator_comlink
	{
		displayName="Operator CWP-8 757";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_758: 885th_operator_comlink
	{
		displayName="Operator CWP-8 758";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_759: 885th_operator_comlink
	{
		displayName="Operator CWP-8 759";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_760: 885th_operator_comlink
	{
		displayName="Operator CWP-8 760";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_761: 885th_operator_comlink
	{
		displayName="Operator CWP-8 761";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_762: 885th_operator_comlink
	{
		displayName="Operator CWP-8 762";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_763: 885th_operator_comlink
	{
		displayName="Operator CWP-8 763";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_764: 885th_operator_comlink
	{
		displayName="Operator CWP-8 764";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_765: 885th_operator_comlink
	{
		displayName="Operator CWP-8 765";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_766: 885th_operator_comlink
	{
		displayName="Operator CWP-8 766";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_767: 885th_operator_comlink
	{
		displayName="Operator CWP-8 767";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_768: 885th_operator_comlink
	{
		displayName="Operator CWP-8 768";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_769: 885th_operator_comlink
	{
		displayName="Operator CWP-8 769";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_770: 885th_operator_comlink
	{
		displayName="Operator CWP-8 770";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_771: 885th_operator_comlink
	{
		displayName="Operator CWP-8 771";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_772: 885th_operator_comlink
	{
		displayName="Operator CWP-8 772";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_773: 885th_operator_comlink
	{
		displayName="Operator CWP-8 773";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_774: 885th_operator_comlink
	{
		displayName="Operator CWP-8 774";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_775: 885th_operator_comlink
	{
		displayName="Operator CWP-8 775";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_776: 885th_operator_comlink
	{
		displayName="Operator CWP-8 776";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_777: 885th_operator_comlink
	{
		displayName="Operator CWP-8 777";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_778: 885th_operator_comlink
	{
		displayName="Operator CWP-8 778";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_779: 885th_operator_comlink
	{
		displayName="Operator CWP-8 779";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_780: 885th_operator_comlink
	{
		displayName="Operator CWP-8 780";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_781: 885th_operator_comlink
	{
		displayName="Operator CWP-8 781";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_782: 885th_operator_comlink
	{
		displayName="Operator CWP-8 782";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_783: 885th_operator_comlink
	{
		displayName="Operator CWP-8 783";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_784: 885th_operator_comlink
	{
		displayName="Operator CWP-8 784";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_785: 885th_operator_comlink
	{
		displayName="Operator CWP-8 785";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_786: 885th_operator_comlink
	{
		displayName="Operator CWP-8 786";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_787: 885th_operator_comlink
	{
		displayName="Operator CWP-8 787";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_788: 885th_operator_comlink
	{
		displayName="Operator CWP-8 788";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_789: 885th_operator_comlink
	{
		displayName="Operator CWP-8 789";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_790: 885th_operator_comlink
	{
		displayName="Operator CWP-8 790";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_791: 885th_operator_comlink
	{
		displayName="Operator CWP-8 791";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_792: 885th_operator_comlink
	{
		displayName="Operator CWP-8 792";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_793: 885th_operator_comlink
	{
		displayName="Operator CWP-8 793";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_794: 885th_operator_comlink
	{
		displayName="Operator CWP-8 794";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_795: 885th_operator_comlink
	{
		displayName="Operator CWP-8 795";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_796: 885th_operator_comlink
	{
		displayName="Operator CWP-8 796";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_797: 885th_operator_comlink
	{
		displayName="Operator CWP-8 797";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_798: 885th_operator_comlink
	{
		displayName="Operator CWP-8 798";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_799: 885th_operator_comlink
	{
		displayName="Operator CWP-8 799";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_800: 885th_operator_comlink
	{
		displayName="Operator CWP-8 800";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_801: 885th_operator_comlink
	{
		displayName="Operator CWP-8 801";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_802: 885th_operator_comlink
	{
		displayName="Operator CWP-8 802";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_803: 885th_operator_comlink
	{
		displayName="Operator CWP-8 803";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_804: 885th_operator_comlink
	{
		displayName="Operator CWP-8 804";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_805: 885th_operator_comlink
	{
		displayName="Operator CWP-8 805";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_806: 885th_operator_comlink
	{
		displayName="Operator CWP-8 806";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_807: 885th_operator_comlink
	{
		displayName="Operator CWP-8 807";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_808: 885th_operator_comlink
	{
		displayName="Operator CWP-8 808";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_809: 885th_operator_comlink
	{
		displayName="Operator CWP-8 809";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_810: 885th_operator_comlink
	{
		displayName="Operator CWP-8 810";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_811: 885th_operator_comlink
	{
		displayName="Operator CWP-8 811";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_812: 885th_operator_comlink
	{
		displayName="Operator CWP-8 812";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_813: 885th_operator_comlink
	{
		displayName="Operator CWP-8 813";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_814: 885th_operator_comlink
	{
		displayName="Operator CWP-8 814";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_815: 885th_operator_comlink
	{
		displayName="Operator CWP-8 815";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_816: 885th_operator_comlink
	{
		displayName="Operator CWP-8 816";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_817: 885th_operator_comlink
	{
		displayName="Operator CWP-8 817";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_818: 885th_operator_comlink
	{
		displayName="Operator CWP-8 818";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_819: 885th_operator_comlink
	{
		displayName="Operator CWP-8 819";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_820: 885th_operator_comlink
	{
		displayName="Operator CWP-8 820";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_821: 885th_operator_comlink
	{
		displayName="Operator CWP-8 821";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_822: 885th_operator_comlink
	{
		displayName="Operator CWP-8 822";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_823: 885th_operator_comlink
	{
		displayName="Operator CWP-8 823";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_824: 885th_operator_comlink
	{
		displayName="Operator CWP-8 824";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_825: 885th_operator_comlink
	{
		displayName="Operator CWP-8 825";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_826: 885th_operator_comlink
	{
		displayName="Operator CWP-8 826";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_827: 885th_operator_comlink
	{
		displayName="Operator CWP-8 827";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_828: 885th_operator_comlink
	{
		displayName="Operator CWP-8 828";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_829: 885th_operator_comlink
	{
		displayName="Operator CWP-8 829";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_830: 885th_operator_comlink
	{
		displayName="Operator CWP-8 830";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_831: 885th_operator_comlink
	{
		displayName="Operator CWP-8 831";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_832: 885th_operator_comlink
	{
		displayName="Operator CWP-8 832";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_833: 885th_operator_comlink
	{
		displayName="Operator CWP-8 833";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_834: 885th_operator_comlink
	{
		displayName="Operator CWP-8 834";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_835: 885th_operator_comlink
	{
		displayName="Operator CWP-8 835";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_836: 885th_operator_comlink
	{
		displayName="Operator CWP-8 836";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_837: 885th_operator_comlink
	{
		displayName="Operator CWP-8 837";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_838: 885th_operator_comlink
	{
		displayName="Operator CWP-8 838";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_839: 885th_operator_comlink
	{
		displayName="Operator CWP-8 839";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_840: 885th_operator_comlink
	{
		displayName="Operator CWP-8 840";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_841: 885th_operator_comlink
	{
		displayName="Operator CWP-8 841";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_842: 885th_operator_comlink
	{
		displayName="Operator CWP-8 842";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_843: 885th_operator_comlink
	{
		displayName="Operator CWP-8 843";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_844: 885th_operator_comlink
	{
		displayName="Operator CWP-8 844";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_845: 885th_operator_comlink
	{
		displayName="Operator CWP-8 845";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_846: 885th_operator_comlink
	{
		displayName="Operator CWP-8 846";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_847: 885th_operator_comlink
	{
		displayName="Operator CWP-8 847";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_848: 885th_operator_comlink
	{
		displayName="Operator CWP-8 848";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_849: 885th_operator_comlink
	{
		displayName="Operator CWP-8 849";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_850: 885th_operator_comlink
	{
		displayName="Operator CWP-8 850";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_851: 885th_operator_comlink
	{
		displayName="Operator CWP-8 851";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_852: 885th_operator_comlink
	{
		displayName="Operator CWP-8 852";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_853: 885th_operator_comlink
	{
		displayName="Operator CWP-8 853";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_854: 885th_operator_comlink
	{
		displayName="Operator CWP-8 854";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_855: 885th_operator_comlink
	{
		displayName="Operator CWP-8 855";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_856: 885th_operator_comlink
	{
		displayName="Operator CWP-8 856";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_857: 885th_operator_comlink
	{
		displayName="Operator CWP-8 857";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_858: 885th_operator_comlink
	{
		displayName="Operator CWP-8 858";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_859: 885th_operator_comlink
	{
		displayName="Operator CWP-8 859";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_860: 885th_operator_comlink
	{
		displayName="Operator CWP-8 860";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_861: 885th_operator_comlink
	{
		displayName="Operator CWP-8 861";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_862: 885th_operator_comlink
	{
		displayName="Operator CWP-8 862";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_863: 885th_operator_comlink
	{
		displayName="Operator CWP-8 863";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_864: 885th_operator_comlink
	{
		displayName="Operator CWP-8 864";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_865: 885th_operator_comlink
	{
		displayName="Operator CWP-8 865";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_866: 885th_operator_comlink
	{
		displayName="Operator CWP-8 866";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_867: 885th_operator_comlink
	{
		displayName="Operator CWP-8 867";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_868: 885th_operator_comlink
	{
		displayName="Operator CWP-8 868";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_869: 885th_operator_comlink
	{
		displayName="Operator CWP-8 869";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_870: 885th_operator_comlink
	{
		displayName="Operator CWP-8 870";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_871: 885th_operator_comlink
	{
		displayName="Operator CWP-8 871";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_872: 885th_operator_comlink
	{
		displayName="Operator CWP-8 872";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_873: 885th_operator_comlink
	{
		displayName="Operator CWP-8 873";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_874: 885th_operator_comlink
	{
		displayName="Operator CWP-8 874";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_875: 885th_operator_comlink
	{
		displayName="Operator CWP-8 875";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_876: 885th_operator_comlink
	{
		displayName="Operator CWP-8 876";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_877: 885th_operator_comlink
	{
		displayName="Operator CWP-8 877";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_878: 885th_operator_comlink
	{
		displayName="Operator CWP-8 878";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_879: 885th_operator_comlink
	{
		displayName="Operator CWP-8 879";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_880: 885th_operator_comlink
	{
		displayName="Operator CWP-8 880";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_881: 885th_operator_comlink
	{
		displayName="Operator CWP-8 881";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_882: 885th_operator_comlink
	{
		displayName="Operator CWP-8 882";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_883: 885th_operator_comlink
	{
		displayName="Operator CWP-8 883";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_884: 885th_operator_comlink
	{
		displayName="Operator CWP-8 884";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_885: 885th_operator_comlink
	{
		displayName="Operator CWP-8 885";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_886: 885th_operator_comlink
	{
		displayName="Operator CWP-8 886";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_887: 885th_operator_comlink
	{
		displayName="Operator CWP-8 887";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_888: 885th_operator_comlink
	{
		displayName="Operator CWP-8 888";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_889: 885th_operator_comlink
	{
		displayName="Operator CWP-8 889";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_890: 885th_operator_comlink
	{
		displayName="Operator CWP-8 890";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_891: 885th_operator_comlink
	{
		displayName="Operator CWP-8 891";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_892: 885th_operator_comlink
	{
		displayName="Operator CWP-8 892";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_893: 885th_operator_comlink
	{
		displayName="Operator CWP-8 893";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_894: 885th_operator_comlink
	{
		displayName="Operator CWP-8 894";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_895: 885th_operator_comlink
	{
		displayName="Operator CWP-8 895";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_896: 885th_operator_comlink
	{
		displayName="Operator CWP-8 896";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_897: 885th_operator_comlink
	{
		displayName="Operator CWP-8 897";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_898: 885th_operator_comlink
	{
		displayName="Operator CWP-8 898";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_899: 885th_operator_comlink
	{
		displayName="Operator CWP-8 899";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_900: 885th_operator_comlink
	{
		displayName="Operator CWP-8 900";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_901: 885th_operator_comlink
	{
		displayName="Operator CWP-8 901";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_902: 885th_operator_comlink
	{
		displayName="Operator CWP-8 902";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_903: 885th_operator_comlink
	{
		displayName="Operator CWP-8 903";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_904: 885th_operator_comlink
	{
		displayName="Operator CWP-8 904";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_905: 885th_operator_comlink
	{
		displayName="Operator CWP-8 905";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_906: 885th_operator_comlink
	{
		displayName="Operator CWP-8 906";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_907: 885th_operator_comlink
	{
		displayName="Operator CWP-8 907";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_908: 885th_operator_comlink
	{
		displayName="Operator CWP-8 908";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_909: 885th_operator_comlink
	{
		displayName="Operator CWP-8 909";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_910: 885th_operator_comlink
	{
		displayName="Operator CWP-8 910";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_911: 885th_operator_comlink
	{
		displayName="Operator CWP-8 911";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_912: 885th_operator_comlink
	{
		displayName="Operator CWP-8 912";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_913: 885th_operator_comlink
	{
		displayName="Operator CWP-8 913";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_914: 885th_operator_comlink
	{
		displayName="Operator CWP-8 914";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_915: 885th_operator_comlink
	{
		displayName="Operator CWP-8 915";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_916: 885th_operator_comlink
	{
		displayName="Operator CWP-8 916";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_917: 885th_operator_comlink
	{
		displayName="Operator CWP-8 917";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_918: 885th_operator_comlink
	{
		displayName="Operator CWP-8 918";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_919: 885th_operator_comlink
	{
		displayName="Operator CWP-8 919";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_920: 885th_operator_comlink
	{
		displayName="Operator CWP-8 920";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_921: 885th_operator_comlink
	{
		displayName="Operator CWP-8 921";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_922: 885th_operator_comlink
	{
		displayName="Operator CWP-8 922";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_923: 885th_operator_comlink
	{
		displayName="Operator CWP-8 923";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_924: 885th_operator_comlink
	{
		displayName="Operator CWP-8 924";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_925: 885th_operator_comlink
	{
		displayName="Operator CWP-8 925";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_926: 885th_operator_comlink
	{
		displayName="Operator CWP-8 926";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_927: 885th_operator_comlink
	{
		displayName="Operator CWP-8 927";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_928: 885th_operator_comlink
	{
		displayName="Operator CWP-8 928";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_929: 885th_operator_comlink
	{
		displayName="Operator CWP-8 929";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_930: 885th_operator_comlink
	{
		displayName="Operator CWP-8 930";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_931: 885th_operator_comlink
	{
		displayName="Operator CWP-8 931";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_932: 885th_operator_comlink
	{
		displayName="Operator CWP-8 932";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_933: 885th_operator_comlink
	{
		displayName="Operator CWP-8 933";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_934: 885th_operator_comlink
	{
		displayName="Operator CWP-8 934";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_935: 885th_operator_comlink
	{
		displayName="Operator CWP-8 935";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_936: 885th_operator_comlink
	{
		displayName="Operator CWP-8 936";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_937: 885th_operator_comlink
	{
		displayName="Operator CWP-8 937";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_938: 885th_operator_comlink
	{
		displayName="Operator CWP-8 938";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_939: 885th_operator_comlink
	{
		displayName="Operator CWP-8 939";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_940: 885th_operator_comlink
	{
		displayName="Operator CWP-8 940";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_941: 885th_operator_comlink
	{
		displayName="Operator CWP-8 941";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_942: 885th_operator_comlink
	{
		displayName="Operator CWP-8 942";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_943: 885th_operator_comlink
	{
		displayName="Operator CWP-8 943";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_944: 885th_operator_comlink
	{
		displayName="Operator CWP-8 944";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_945: 885th_operator_comlink
	{
		displayName="Operator CWP-8 945";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_946: 885th_operator_comlink
	{
		displayName="Operator CWP-8 946";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_947: 885th_operator_comlink
	{
		displayName="Operator CWP-8 947";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_948: 885th_operator_comlink
	{
		displayName="Operator CWP-8 948";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_949: 885th_operator_comlink
	{
		displayName="Operator CWP-8 949";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_950: 885th_operator_comlink
	{
		displayName="Operator CWP-8 950";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_951: 885th_operator_comlink
	{
		displayName="Operator CWP-8 951";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_952: 885th_operator_comlink
	{
		displayName="Operator CWP-8 952";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_953: 885th_operator_comlink
	{
		displayName="Operator CWP-8 953";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_954: 885th_operator_comlink
	{
		displayName="Operator CWP-8 954";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_955: 885th_operator_comlink
	{
		displayName="Operator CWP-8 955";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_956: 885th_operator_comlink
	{
		displayName="Operator CWP-8 956";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_957: 885th_operator_comlink
	{
		displayName="Operator CWP-8 957";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_958: 885th_operator_comlink
	{
		displayName="Operator CWP-8 958";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_959: 885th_operator_comlink
	{
		displayName="Operator CWP-8 959";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_960: 885th_operator_comlink
	{
		displayName="Operator CWP-8 960";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_961: 885th_operator_comlink
	{
		displayName="Operator CWP-8 961";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_962: 885th_operator_comlink
	{
		displayName="Operator CWP-8 962";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_963: 885th_operator_comlink
	{
		displayName="Operator CWP-8 963";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_964: 885th_operator_comlink
	{
		displayName="Operator CWP-8 964";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_965: 885th_operator_comlink
	{
		displayName="Operator CWP-8 965";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_966: 885th_operator_comlink
	{
		displayName="Operator CWP-8 966";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_967: 885th_operator_comlink
	{
		displayName="Operator CWP-8 967";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_968: 885th_operator_comlink
	{
		displayName="Operator CWP-8 968";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_969: 885th_operator_comlink
	{
		displayName="Operator CWP-8 969";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_970: 885th_operator_comlink
	{
		displayName="Operator CWP-8 970";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_971: 885th_operator_comlink
	{
		displayName="Operator CWP-8 971";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_972: 885th_operator_comlink
	{
		displayName="Operator CWP-8 972";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_973: 885th_operator_comlink
	{
		displayName="Operator CWP-8 973";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_974: 885th_operator_comlink
	{
		displayName="Operator CWP-8 974";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_975: 885th_operator_comlink
	{
		displayName="Operator CWP-8 975";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_976: 885th_operator_comlink
	{
		displayName="Operator CWP-8 976";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_977: 885th_operator_comlink
	{
		displayName="Operator CWP-8 977";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_978: 885th_operator_comlink
	{
		displayName="Operator CWP-8 978";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_979: 885th_operator_comlink
	{
		displayName="Operator CWP-8 979";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_980: 885th_operator_comlink
	{
		displayName="Operator CWP-8 980";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_981: 885th_operator_comlink
	{
		displayName="Operator CWP-8 981";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_982: 885th_operator_comlink
	{
		displayName="Operator CWP-8 982";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_983: 885th_operator_comlink
	{
		displayName="Operator CWP-8 983";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_984: 885th_operator_comlink
	{
		displayName="Operator CWP-8 984";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_985: 885th_operator_comlink
	{
		displayName="Operator CWP-8 985";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_986: 885th_operator_comlink
	{
		displayName="Operator CWP-8 986";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_987: 885th_operator_comlink
	{
		displayName="Operator CWP-8 987";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_988: 885th_operator_comlink
	{
		displayName="Operator CWP-8 988";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_989: 885th_operator_comlink
	{
		displayName="Operator CWP-8 989";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_990: 885th_operator_comlink
	{
		displayName="Operator CWP-8 990";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_991: 885th_operator_comlink
	{
		displayName="Operator CWP-8 991";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_992: 885th_operator_comlink
	{
		displayName="Operator CWP-8 992";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_993: 885th_operator_comlink
	{
		displayName="Operator CWP-8 993";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_994: 885th_operator_comlink
	{
		displayName="Operator CWP-8 994";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_995: 885th_operator_comlink
	{
		displayName="Operator CWP-8 995";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_996: 885th_operator_comlink
	{
		displayName="Operator CWP-8 996";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_997: 885th_operator_comlink
	{
		displayName="Operator CWP-8 997";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_998: 885th_operator_comlink
	{
		displayName="Operator CWP-8 998";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_999: 885th_operator_comlink
	{
		displayName="Operator CWP-8 999";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
	class 885th_operator_comlink_1000: 885th_operator_comlink
	{
		displayName="Operator CWP-8 1000";
		scope=1;
		scopeArsenal=1;
		scopeCurator=1;
		tf_prototype=0;
		tf_radio=1;
	};
};

