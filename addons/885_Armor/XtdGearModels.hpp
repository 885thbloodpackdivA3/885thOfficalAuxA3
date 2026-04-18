class XtdGearModels
{
	class CfgWeapons
	{
		class Trooper_Ranked_Helmets
		{
			options[]=
			{
				"rank"
			};
			label="Phase II Trooper Helmets";
			class rank
			{
				label="Rank";
				values[]=
				{
					"CR",
					"CT",
					"VCT",
                    "Officer",
					"Medic"
				};
			};
		};
		class Trooper_RTO_Helmets
		{
			options[]=
			{
				"rank"
			};
			label="Phase I RTO Trooper Helmets";
			class rank
			{
				label="Rank";
				values[]=
				{
					"RTO",
					"Advisor"
				};
			};
		};
        class Trooper_BARC_Helmets
		{
			options[]=
			{
				"rank"
			};
			label="BARC Trooper Helmets";
			class rank
			{
				label="Rank";
				values[]=
				{
					"BARC"
				};
			};
		};
        class Trooper_ARF_Helmets
		{
			options[]=
			{
				"rank"
			};
			label="ARF Trooper Helmets";
			class rank
			{
				label="Rank";
				values[]=
				{
					"Cadet",
					"ARF",
                    "Spec Ops",
					"Scout"
				};
			};
		};
        class Trooper_Special_Helmets
		{
			options[]=
			{
				"rank",
				"camo"
			};
			label="Specialized Trooper Helmets";
			class rank
			{
				label="Rank";
				values[]=
				{
					"Engineer",
					"EngineerV2",
					"EOD",
                    "MG",
					"Armored",
                    "QRF",
					"QRF Medic",
                    "Hazard",
					"Hazard Vet",
					"Hazard CO"
				};
			};
            class variant
			{
				label="Variant";
				values[]=
				{
					"EOD",
                    "Heavy",
                    "QRF",
                    "Hazard"
				};
			};
            	class camo
            {
				label="Variant";
                values[] = {"EOD","Heavy","QRF","Hazard"}; // Always computed, do not acebi
                alwaysSelectable=1;
            };
		};
        class Trooper_Pilot_Helmets
        {
            options[]=
            {
                "rank"
            };
            label="Nightsingers Pilot Helmets";
            class rank
            {
                label="Rank";
                values[]=
                {
                    "Pilot",
					"Pilot V2",
                    "Sen.Pilot",
                    "Officer"
                };
            };
		};
		class Trooper_RC_Helmets
		{
            options[]=
            {
                "rank"
            };
            label="Kusak Commandos Helmets";
            class rank
            {
                label="Rank";
                values[]=
                {
                    "Standard"
                };
            };
        };
		class Trooper_Custom_Helmets
		{
            options[]=
            {
                "rank",
                "camo"
            };
            label="Custom Trooper Helmets";
            class rank
            {
                label="Customs";
                values[]=
                {
                    "Bandit",
					"Bleach",
					"Charge",
					"Crimz",
					"Crow",
					"Gooner",
					"Kit",
					"Lotho",
					"Nightfall",
					"Nightmare",
					"Mayday",
					"ONI",
					"Outcast",
					"Owl",
					"Phantom",
					"Rios",
					"Screwball",
					"Syxer",
					"Smith",
					"Sunshine",
					"Strawberry",
					"Stormer",
					"Sushi",
					"Teal",
					"Thunder",
					"Titan",
					"Top Snipe",
					"Warden",
					"Wyrm",
					"Wrath"
                };
            };
            class variant
            {
                label="Variant";
                values[]=
                {
                    "P1";
					"P2",
					"BARC",
					"Pilot",
					"Engineer",
					"ARF",
					"RC"
                };
            };
            class camo
            {
                label="Variant";
                values[]= {"P1","P2","BARC","Pilot","Engineer","ARF","RC"};
                alwaysSelectable=1;
            };
        };
		class Trooper_Squad_Helmets
		{
            options[]=
            {
                "rank",
                "camo"
            };
            label="Squad Trooper Helmets";
            class rank
            {
                label="Rank";
                values[]=
                {
                    "Standard",
                    "VCT",
                    "Officer",
					"Medic"
                };
            };
            class variant
            {
                label="Squad";
                values[]=
                {
                    "1-1",
					"1-2"
                };
            };
            class camo
            {
                label="Variant";
                values[]= {"1-1", "1-2"};
                alwaysSelectable=1;
            };
        };
        class Ranked_Uniforms
		{
			options[]=
			{
				"rank",
			};
			label="Ranked Uniforms";
			class rank
			{
				label="Rank";
				values[]=
				{
					"CR",
					"CT",
					"VCT",
					"Officer",
					"Medic"
				};
			};
		};
		class Squad_Uniforms
		{
			options[]=
			{
				"rank",
				"camo"
			};
			label="Squad Uniforms";
			class rank
			{
				label="Rank";
				values[]=
				{
					"Standard",
					"CT",
					"VCT",
					"Officer",
					"Medic"
				};
			};
			 class variant
            {
                label="Variant";
                values[]=
                {
                    "1-1",
					"1-2"
                };
            };
            class camo
            {
                label="Squad";
                values[]= {"1-1", "1-2"};
                alwaysSelectable=1;
            };
		};
		class Pilot_Uniforms
		{
			options[]=
			{
				"rank"
			};
			label="Ranked Uniforms";
			class rank
			{
				label="Rank";
				values[]=
				{
					"Pilot",
                    "Sen.Pilot",
                    "Officer"
				};
			};
		};
		class Kusak_Uniforms
		{
			options[]=
			{
				"rank"
			};
			label="Kusak Uniform";
			class rank
			{
				label="Rank";
				values[]=
				{
					"Standard"
				};
			};
		};
		class Najax_Uniforms
		{
			options[]=
			{
				"rank"
			};
			label="Ranked Uniforms";
			class rank
			{
				label="Rank";
				values[]=
				{
					"Cadet",
					"ARF",
                    "Spec Ops",
					"Scout"
				};
			};
		};
		class Specialized_Uniforms
		{
			options[]=
			{
				"rank"
			};
			label="Specialized Uniforms";
			class rank
			{
				label="Type";
				values[]=
				{
					"EOD",
					"Hazard",
					"Hazard Vet",
					"Hazard CO",
					"Adv.Recon"
				};
			};
			class variant
			{
				label="Variant";
				values[]=
				{
					"EOD",
                    "Hazard",
					"Adv.Recon"
				};
			};
            	class camo
            {
				label="Variant";
                values[] = {"EOD","Hazard","Adv.Recon"}; // Always computed, do not acebi
                alwaysSelectable=1;
            };
		};
		class Custom_Uniforms
		{
			options[]=
			{
				"rank"
			};
			label="Custom Uniforms";
			class rank
			{
				label="Custom";
				values[]=
				{
					"Bandit",
					"Crimz",
					"Crow",
					"Nightfall",
					"ONI",
					"Outcast",
					"Phantom",
					"Rios",
					"Screwball",
					"Smith",
					"Syxer",
					"Thunder",
					"Titan",
					"Teal"
				};
			};
		};
		class Trooper_Vest
		{
			options[]=
			{
				"vest"
			};
			label="Trooper Vests";
			class vest
			{
				label="Vest";
				values[]=
				{
					"Standard",
					"Engineer",
					"Medic",
					"Heavy Gunner",
					"Holster A",
					"Holster B",
					"Holster C",
					"Holster v2 A",
					"Holster v2 B",
					"Hazard"
				};
			};
		};
		class Detachment_Vest
		{
			options[]=
			{
				"vest"
			};
			label="Detachment Vests";
			class vest
			{
				label="Vest";
				values[]=
				{
					"RC Plates",
					"RC Tech",
					"RC EOD",
					"RC Sniper",
					"Scout Pouch",
					"ARC Vest"
				};
			};
		};
		class Leadership_Vest
		{
			options[]=
			{
				"vest"
			};
			label="Leadership Vests";
			class vest
			{
				label="Vest";
				values[]=
				{
					"JNCO",
					"NCO",
					"Vornskr CO",
					"Surgeon",
					"Najax",
					"Nightsingers",
					"Hazard CO",
					"RC Lead",
					"Wyrwulf A",
					"Wyrwulf B"
				};
			};
		};
		class WO_Vest
		{
			options[]=
			{
				"vest"
			};
			label="WO Vests";
			class vest
			{
				label="Vest";
				values[]=
				{
					"WO1",
					"WO2",
					"WO3",
					"WO4",
					"WO5"
				};
			};
		};
		class Custom_Vest
		{
			options[]=
			{
				"vest"
			};
			label="Custom Vests";
			class vest
			{
				label="Vest";
				values[]=
				{
					"Bandit",
					"Crimz",
					"Outcast",
					"ONI",
					"Rios",
					"Screwball",
					"Syxer",
					"Thunder",
					"Teal"
				};
			};
		};
	};
    class CfgVehicles
	{
		class Vornskr_Backpacks
		{
			options[]=
			{
				"backpack"
			};
			label="Vornskr Backpacks";
			class backpack
			{
				label="Backpack";
				values[]=
				{
					"Backpack",
					"Invis",
					"AT",
					"Explosives",
					"Ammobearer",
					"Medic",
					"RTO",
					"JTAC",
					"Officer",
					"Command",
					"Hazard",
					"Hazard CO",
					"Mortar"
				};
			};
		};
		class Detachment_Backpacks
		{
			options[]=
			{
				"backpack"
			};
			label="Detachment Backpacks";
			class backpack
			{
				label="Backpack";
				values[]=
				{
					"NS Pack",
					"Scout A",
					"Scout B",
					"Katarn Pack",
					"Jump CO",
					"Light Jump",
					"Med Jump",
					"ARC Pack"
				};
			};
		};
		class Custom_Backpacks
		{
			options[]=
			{
				"backpack"
			};
			label="Custom Backpacks";
			class backpack
			{
				label="Backpack";
				values[]=
				{
					"Bandit",
					"Outcast",
					"Rios",
					"Thunder"
				};
			};
		};
	};
};
class XtdGearInfos
{
	class CfgWeapons
	{	
		// Phase II Helmets
		class 885th_Recruit_P2_Helm
		{
			model="Trooper_Ranked_Helmets";
			rank="CR";
		};
		class 885th_P2_V2_Helmet
		{
			model="Trooper_Ranked_Helmets";
			rank="CT";
		};
		class 885th_P2_VCT_Helmet
        {
            model="Trooper_Ranked_Helmets";
			rank="VCT";
        };
        class 885th_P2_Officer_Helmet
        {
            model="Trooper_Ranked_Helmets";
			rank="Officer";
        };
		class 885th_Medic_P2_Helm
        {
            model="Trooper_Ranked_Helmets";
			rank="Medic";
        };
		//Pilot Helmets
        class 885th_Nightsingers_P2_Pilot_Helm
        { 
            model="Trooper_Pilot_Helmets";
			rank="Pilot";
        };
        class 885th_Nightsingers_P2_Pilot_Senior_Helm
        {
            model="Trooper_Pilot_Helmets";
			rank="Sen.Pilot";
        };
        class 885th_Nightsingers_P2_Pilot_Officer_Helm
        {
            model="Trooper_Pilot_Helmets";
			rank="Officer";
        };
		//RTO Helmets
        class 885th_Vornskr_P1_RTO_Helm
        {
            model="Trooper_RTO_Helmets";
			rank="RTO";
        };
        class 885th_Vornskr_P1_Advisor_Helm
        {
            model="Trooper_RTO_Helmets";
			rank="Advisor";
        };
		//Najax ARF Helmets
		class 885th_Najax_ARF_P2_Recruit_Helm
		{
			model="Trooper_ARF_Helmets";
			rank="Cadet";
		};
		class 885th_Najax_P1_ARF_Helm
		{
			model="Trooper_ARF_Helmets";
			rank="ARF";
		};
		class 885th_Najax_ARF_P2_Helm
		{
			model="Trooper_ARF_Helmets";
			rank="ARF";
		};
		class 885th_Najax_ARF_P2_Camo_Helm
		{
			model="Trooper_ARF_Helmets";
			rank="Spec Ops";
		};
		class 885th_Najax_Scout_P2_Helm
		{
			model="Trooper_ARF_Helmets";
			rank="Scout";
		};
		//BARC Helmets
		class 885th_BARC_Helm
		{
			model="Trooper_BARC_Helmets";
			rank="BARC";
		};
		//Specialized Helmets
		class 885th_Vornskr_Engineer_Helm
		{
			model="Trooper_Special_Helmets";
			rank="Engineer";
			variant="EOD";
			camo="EOD";
		};
		class 885th_Vornskr_EngineerV2_Helm
		{
			model="Trooper_Special_Helmets";
			rank="EngineerV2";
			variant="EOD";
			camo="EOD";
		};
		class 885th_EOD_Helm
		{
			model="Trooper_Special_Helmets";
			rank="EOD";
			variant="EOD";
			camo="EOD";
		};
		class 885th_P2_MG_Helmet
		{
			model="Trooper_Special_Helmets";
			rank="MG";
			variant="Heavy";
			camo="Heavy";
		};
		class 885th_Nightsingers_Armor_Crew_Helmet
		{
			model="Trooper_Special_Helmets";
			rank="Armored";
			variant="Heavy";
			camo="Heavy";
		};
		class 885th_AB_Helm
		{
			model="Trooper_Special_Helmets";
			rank="QRF";
			variant="QRF";
			camo="QRF";
		};
		class 885th_Medic_AB_Helm
		{
			model="Trooper_Special_Helmets";
			rank="QRF Medic";
			variant="QRF";
			camo="QRF";
		};
		class 885th_Vornskr_Hazard_Helm_Base
		{
			model="Trooper_Special_Helmets";
			rank="Hazard";
			variant="Hazard";
			camo="Hazard";
		};
		class 885th_Vornskr_Hazard_Helm_Vet
		{
			model="Trooper_Special_Helmets";
			rank="Hazard Vet";
			variant="Hazard";
			camo="Hazard";
		};
		class 885th_Vornskr_Hazard_Helm_COM
		{
			model="Trooper_Special_Helmets";
			rank="Hazard CO";
			variant="Hazard";
			camo="Hazard";
		};
		//Kusak RC Helmets
		class 885th_Kusak_Katarn_Helmet
		{
			model="Trooper_RC_Helmets";
			rank="Standard";
		};
		//Squad Helmets
		class 885th_Charhound_Helm
		{
			model="Trooper_Squad_Helmets";
			rank="Standard";
			variant="1-1";
			camo="1-1";
		};
		class 885th_Charhound_VCT_Helm
		{
			model="Trooper_Squad_Helmets";
			rank="VCT";
			variant="1-1";
			camo="1-1";
		};
		class 885th_Charhound_Officer_Helm
		{
			model="Trooper_Squad_Helmets";
			rank="Officer";
			variant="1-1";
			camo="1-1";
		};
		class 885th_Charhound_Medic_Helm
		{
			model="Trooper_Squad_Helmets";
			rank="Medic";
			variant="1-1";
			camo="1-1";
		};
		class 885th_Nexu_P2_Helm
		{
			model="Trooper_Squad_Helmets";
			rank="Standard";
			variant="1-2";
			camo="1-2";
		};
		class 885th_Nexu_Vct_P2_Helm
		{
			model="Trooper_Squad_Helmets";
			rank="VCT";
			variant="1-2";
			camo="1-2";
		};
		class 885th_Nexu_Officer_P2_Helm
		{
			model="Trooper_Squad_Helmets";
			rank="Officer";
			variant="1-2";
			camo="1-2";
		};
		class 885th_Nexu_Medic_P2_Helm
		{
			model="Trooper_Squad_Helmets";
			rank="Medic";
			variant="1-2";
			camo="1-2";
		};
		//Custom Helmets
		class 885th_Bandit_BARC_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Bandit";
			variant="BARC";
			camo="BARC";
		};
		class  885th_Bleach_P2_Helmet
		{
			model="Trooper_Custom_Helmets";
			rank="Bleach";
			variant="P2";
			camo="P2";
		};
		class  885th_Charge_BARC_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Charge";
			variant="BARC";
			camo="BARC";
		};
		class 885th_Crimz_ARF_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Crimz";
			variant="ARF";
			camo="ARF";
		};
		class 885th_Gooner_P2_Helmet
		{
			model="Trooper_Custom_Helmets";
			rank="Gooner";
			variant="P2";
			camo="P2";
		};
		class Crow_Kusak_Katarn_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Crow";
			variant="RC";
			camo="RC";
		};
		class 885th_Kit_P2_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Kit";
			variant="P2";
			camo="P2";
		};
		class 885th_Lotho_P2_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Lotho";
			variant="P2";
			camo="P2";
		};
		class 885th_Nightfall_P2_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Nightfall";
			variant="P2";
			camo="P2";
		};
		class 885th_Nightmare_Engineer_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Nightmare";
			variant="Engineer";
			camo="Engineer";
		};
		class 885th_Mayday_P2_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Mayday";
			variant="P2";
			camo="P2";
		};
		class 885th_ONI_P2_Helmet
		{
			model="Trooper_Custom_Helmets";
			rank="ONI";
			variant="P2";
			camo="P2";
		};
		class 885th_Outcast_RTO_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Outcast";
			variant="P1";
			camo="P1";
		};
		class 885th_Owl_Pilot_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Owl";
			variant="Pilot";
			camo="Pilot";
		};
		class Phantom_Kusak_Katarn_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Phantom";
			variant="RC";
			camo="RC";
		};
		class 885th_Rios_P2_Helmet
		{
			model="Trooper_Custom_Helmets";
			rank="Rios";
			variant="P2";
			camo="P2";
		};
		class 885th_Screwball_P1_ARF_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Screwball";
			variant="ARF";
			camo="ARF";
		};
		class 885th_Syxer_BARC_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Syxer";
			variant="BARC";
			camo="BARC";
		};
		class 885th_Smith_Pilot_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Smith";
			variant="Pilot";
			camo="Pilot";
		};
		class 885th_Sunshine_P2_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Sunshine";
			variant="P2";
			camo="P2";
		};
		class 885th_Strawberry_P2_Helmet
		{
			model="Trooper_Custom_Helmets";
			rank="Strawberry";
			variant="P2";
			camo="P2";
		};
		class 885th_Stormer_P2_Helmet
		{
			model="Trooper_Custom_Helmets";
			rank="Stormer";
			variant="P2";
			camo="P2";
		};
		class 885th_Sushi_P2_ARF_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Sushi";
			variant="ARF";
			camo="ARF";
		};
		class 885th_Teal_P1_Advisor_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Teal";
			variant="P1";
			camo="P1";
		};
		class 885th_Thunder_P1_ARF_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Thunder";
			variant="ARF";
			camo="ARF";
		};
		class Titan_Kusak_Katarn_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Titan";
			variant="RC";
			camo="RC";
		};
		class 885th_TopSnipe_Pilot_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Top Snipe";
			variant="Pilot";
			camo="Pilot";
		};
		class 885th_Warden_Pilot_Helm 
		{
			model="Trooper_Custom_Helmets";
			rank="Warden";
			variant="Pilot";
			camo="Pilot";
		};
		class 885th_Wyrm_P2_Helm
		{
			model="Trooper_Custom_Helmets";
			rank="Wyrm";
			variant="P2";
			camo="P2";
		};
		class 885th_Wrath_P2_Helmet
		{
			model="Trooper_Custom_Helmets";
			rank="Wrath";
			variant="P2";
			camo="P2";
		};

		//Uniforms
		class 885th_Recruit_Uniform
		{
			model="Ranked_Uniforms";
			rank="CR";
		};
		class 885th_Vornskr_Uniform
		{
			model="Ranked_Uniforms";
			rank="CT";
		};
		class 885th_Vornskr_VCT_Uniform
		{
			model="Ranked_Uniforms";
			rank="VCT";
		};
		class 885th_Vornskr_Officer_Uniform
		{
			model="Ranked_Uniforms";
			rank="Officer";
		};
		class 885th_Medic_Uniform
		{
			model="Ranked_Uniforms";
			rank="Medic";
		};
		//Squad Uniforms
		class 885th_Charhound_Uniform
		{
			model="Squad_Uniforms";
			rank="CT";
			variant="1-1";
			camo="1-1";
		};
		class 885th_Charhound_VCT_Uniform
		{
			model="Squad_Uniforms";
			rank="VCT";
			variant="1-1";
			camo="1-1";
		};
		class 885th_Charhound_Officer_Uniform
		{
			model="Squad_Uniforms";
			rank="Officer";
			variant="1-1";
			camo="1-1";
		};
		class 885th_Charhound_Medic_Uniform
		{
			model="Squad_Uniforms";
			rank="Medic";
			variant="1-1";
			camo="1-1";
		};
		class 885th_Nexu_Uniform
		{
			model="Squad_Uniforms";
			rank="CT";
			variant="1-2";
			camo="1-2";
		};
		class 885th_Nexu_Vct_Uniform
		{
			model="Squad_Uniforms";
			rank="VCT";
			variant="1-2";
			camo="1-2";
		};
		class 885th_Nexu_Officer_Uniform
		{
			model="Squad_Uniforms";
			rank="Officer";
			variant="1-2";
			camo="1-2";
		};
		class 885th_Nexu_Medic_Uniform
		{
			model="Squad_Uniforms";
			rank="Medic";
			variant="1-2";
			camo="1-2";
		};
		//Pilot Uniforms
		class 885th_Nightsingers_Uniform
		{
			model="Pilot_Uniforms";
			rank="Pilot";
		};
		class 885th_Nightsingers_Senior_Uniform
		{
			model="Pilot_Uniforms";
			rank="Sen.Pilot";
		};
		class 885th_Nightsingers_Officer_Uniform
		{
			model="Pilot_Uniforms";
			rank="Officer";
		};
		//Kusak Uniforms
		class 885th_Kusak_Katarn_Uniform
		{
			model="Kusak_Uniforms";
			rank="Standard";
		};
		//Najax Uniforms
		class 885th_Najax_Recruit_Uniform
		{
			model="Najax_Uniforms";
			rank="Cadet";
		};
		class 885th_Najax_Uniform
		{
			model="Najax_Uniforms";
			rank="ARF";
		};
		class 885th_Najax_Camo_Uniform
		{
			model="Najax_Uniforms";
			rank="Spec Ops";
		};
		class 885th_Najax_Scout_Uniform
		{
			model="Najax_Uniforms";
			rank="Scout";
		};
		//Specialized Uniforms
		class 885th_Vornskr_EOD_Uniform
		{
			model="Specialized_Uniforms";
			rank="EOD";
			variant="EOD";
			camo="EOD";
		};
		class 885th_Hazard_Trooper_Uniform
		{
			model="Specialized_Uniforms";
			rank="Hazard";
			variant="Hazard";
			camo="Hazard";
		};
		class 885th_Hazard_Veteran_Uniform
		{
			model="Specialized_Uniforms";
			rank="Hazard Vet";
			variant="Hazard";
			camo="Hazard";
		};
		class 885th_Hazard_COM_Uniform
		{
			model="Specialized_Uniforms";
			rank="Hazard CO";
			variant="Hazard";
			camo="Hazard";
		};
		class 885th_AdvRecon_Uniform
		{
			model="Specialized_Uniforms";
			rank="Adv.Recon";
			variant="Adv.Recon";
			camo="Adv.Recon";
		};
		//Customs Uniforms
		class 885th_Bandit_Uniform
		{
			model="Custom_Uniforms";
			rank="Bandit";
		};
		class 885th_Crimz_Uniform
		{
			model="Custom_Uniforms";
			rank="Crimz";
		};
		class 885th_Crow_Katarn_Uniform 
		{
			model="Custom_Uniforms";
			rank="Crow";
		};
		class 885th_Lotho_Uniform
		{
			model="Custom_Uniforms";
			rank="Lotho";
		};
		class 885th_Nightfall_Uniform
		{
			model="Custom_Uniforms";
			rank="Nightfall";
		};
		class 885th_ONI_Uniform
		{
			model="Custom_Uniforms";
			rank="ONI";
		};
		class 885th_Outcast_Uniform
		{
			model="Custom_Uniforms";
			rank="Outcast";
		};
		class 885th_Phantom_Katarn_Uniform
		{
			model="Custom_Uniforms";
			rank="Phantom";
		};
		class 885th_Rios_Uniform
		{
			model="Custom_Uniforms";
			rank="Rios";
		};
		class 885th_Screwball_Uniform
		{
			model="Custom_Uniforms";
			rank="Screwball";
		};
		class 885th_Smith_Uniform
		{
			model="Custom_Uniforms";
			rank="Smith";
		};
		class 885th_Syxer_Uniform
		{
			model="Custom_Uniforms";
			rank="Syxer";
		};
		class 885th_Thunder_Uniform
		{
			model="Custom_Uniforms";
			rank="Thunder";
		};
		class 885th_Teal_Uniform
		{
			model="Custom_Uniforms";
			rank="Teal";
		};
		class 885th_Titan_Katarn_Uniform
		{
			model="Custom_Uniforms";
			rank="Titan";
		};

		//Trooper Vests
		class 885th_vest_base
		{
			model="Trooper_Vest";
			vest="Standard";
		};
		class 885th_vest_EOD_base
		{
			model="Trooper_Vest";
			vest="Engineer";
		};
		class 885th_vest_medic_base
		{
			model="Trooper_Vest";
			vest="Medic";
		};
		class 885th_IDA_VestV4_Heavygunner_Rig
		{
			model="Trooper_Vest";
			vest="Heavy Gunner";
		};
		class 885th_Clone_Holster
		{
			model="Trooper_Vest";
			vest="Holster A";
		};
		class 885th_Clone_Holster2
		{
			model="Trooper_Vest";
			vest="Holster B";
		};
		class 885th_Clone_Holster3
		{
			model="Trooper_Vest";
			vest="Holster C";
		};
		class 885th_IDA_VestV4_Holster
		{
			model="Trooper_Vest";
			vest="Holster v2 A";
		};
		class 885th_IDA_VestV4_HolsterDouble
		{
			model="Trooper_Vest";
			vest="Holster v2 B";
		};
		class 885th_Vornskr_Hazard_Vest_Base
		{
			model="Trooper_Vest";
			vest="Hazard";
		};
		//Detachment Vests
		class 885th_Katarn_base
		{
			model="Detachment_Vest";
			vest="RC Plates";
		};
		class 885th_Kusak_Medic
		{
			model="Detachment_Vest";
			vest="RC Tech";
		};
		class 885th_Kusak_Katarn_Demo
		{
			model="Detachment_Vest";
			vest="RC EOD";
		};
		class 885th_Kusak_Sniper
		{
			model="Detachment_Vest";
			vest="RC Sniper";
		};
		class 885th_Najax_Vest_scout
		{
			model="Detachment_Vest";
			vest="Scout Pouch";
		};
		class 885th_IDA_VestV4_ARC_Rig
		{
			model="Detachment_Vest";
			vest="ARC Vest";
		};
		//Leadership Vests
		class 885th_IDA_VestV4_JNCO_Pauldron
		{
			model="Leadership_Vest";
			vest="JNCO";
		};
		class 885th_IDA_VestV4_NCO_Pauldron
		{
			model="Leadership_Vest";
			vest="NCO";
		};
		class 885th_IDA_VestV4_Vornskr_Pauldron
		{
			model="Leadership_Vest";
			vest="Vornskr CO";
		};
		class 885th_IDA_VestV4_Surgeon_Pauldron
		{
			model="Leadership_Vest";
			vest="Surgeon";
		};
		class 885th_IDA_VestV4_Najax_Pauldron
		{
			model="Leadership_Vest";
			vest="Najax";
		};
		class 885th_IDA_VestV4_Nightsingers_Pauldron
		{
			model="Leadership_Vest";
			vest="Nightsingers";
		};
		class 885th_Vornskr_Hazard_Vest_COM
		{
			model="Leadership_Vest";
			vest="Hazard CO";
		};
		class 885th_Kusak_Squad_Leader
		{
			model="Leadership_Vest";
			vest="RC Lead";
		};
		class 885th_IDA_VestV4_Command_Pauldron
		{
			model="Leadership_Vest";
			vest="Wyrwulf A";
		};
		class 885th_IDA_VestV4_Command_Pauldron_Antenna
		{
			model="Leadership_Vest";
			vest="Wyrwulf B";
		};
		// WO Vests
		class 885th_IDA_VestV4_WO1_Rig
		{
			model="WO_Vest";
			vest="WO1";
		};
		class 885th_IDA_VestV4_WO2_Rig
		{
			model="WO_Vest";
			vest="WO2";
		};
		class 885th_IDA_VestV4_WO3_Rig
		{
			model="WO_Vest";
			vest="WO3";
		};
		class 885th_IDA_VestV4_WO4_Rig
		{
			model="WO_Vest";
			vest="WO4";
		};
		class 885th_IDA_VestV4_WO5_Rig
		{
			model="WO_Vest";
			vest="WO5";
		};
		//Custom Vests
		class 885th_Cust_VestV4_Rig_Bandit
		{
			model="Custom_Vest";
			vest="Bandit";
		};
		class 885th_Cust_VestV4_Rig_Crimz
		{
			model="Custom_Vest";
			vest="Crimz";
		};
		class 885th_Cust_VestV4_Rig_Outcast
		{
			model="Custom_Vest";
			vest="Outcast";
		};
		class 885th_Cust_VestV4_Rig_ONI
		{
			model="Custom_Vest";
			vest="ONI";
		};
		class 885th_Cust_VestV4_Rig_Rios
		{
			model="Custom_Vest";
			vest="Rios";
		};
		class 885th_Cust_VestV4_Rig_Screwball
		{
			model="Custom_Vest";
			vest="Screwball";
		};
		class 885th_Cust_VestV4_Rig_Syxer
		{
			model="Custom_Vest";
			vest="Syxer";
		};
		class 885th_Cust_VestV4_Rig_Thunder
		{
			model="Custom_Vest";
			vest="Thunder";
		};
		class 885th_Cust_VestV4_Rig_Teal
		{
			model="Custom_Vest";
			vest="Teal";
		};
	};
	class CfgVehicles
	{	
		//Vornskr Backpacks
		class 885th_Vornskr_Backpack
		{
			model="Vornskr_Backpacks";
			backpack="Backpack";
		};
		class 885th_Vornskr_Backpack_invis
		{
			model="Vornskr_Backpacks";
			backpack="Invis";
		};
		class 885th_LS_Rocket_Backpack
		{
			model="Vornskr_Backpacks";
			backpack="AT";
		};
		class 885th_LS_Explosives_Backpack
		{
			model="Vornskr_Backpacks";
			backpack="Explosives";
		};
		class 885th_Ammo_Backpack
		{
			model="Vornskr_Backpacks";
			backpack="Ammobearer";
		};
		class 885th_Medic_Backpack
		{
			model="Vornskr_Backpacks";
			backpack="Medic";
		};
		class 885th_RTO_Backpack
		{
			model="Vornskr_Backpacks";
			backpack="RTO";
		};
		class 885th_JTAC_Backpack
		{
			model="Vornskr_Backpacks";
			backpack="JTAC";
		};
		class 885th_LR_Attachment_Antenna
		{
			model="Vornskr_Backpacks";
			backpack="Officer";
		};
		class 885th_Wyrwulf_Clone_Radiopack
		{
			model="Vornskr_Backpacks";
			backpack="Command";
		};
		class 885th_Vornskr_Hazard_Backpack
		{
			model="Vornskr_Backpacks";
			backpack="Hazard";
		};
		class 885th_Vornskr_Hazard_RTO_Backpack
		{
			model="Vornskr_Backpacks";
			backpack="Hazard CO";
		};
		class 885th_Republic_Mortar_Bag
		{
			model="Vornskr_Backpacks";
			backpack="Mortar";
		};
		//Detachment Backpacks
		class 885th_Nightsingers_Clone_Radiopack
		{
			model="Detachment_Backpacks";
			backpack="NS Pack";
		};
		class 885th_Najax_ScoutPack
		{
			model="Detachment_Backpacks";
			backpack="Scout A";
		};
		class 885th_Najax_Scout_Backpack_invis
		{
			model="Detachment_Backpacks";
			backpack="Scout B";
		};
		class 885th_RC_Kusak_Backpack
		{
			model="Detachment_Backpacks";
			backpack="Katarn Pack";
		};
		class 885th_company_Jumppack
		{
			model="Detachment_Backpacks";
			backpack="Jump CO";
		};
		class 885th_Jumppack
		{
			model="Detachment_Backpacks";
			backpack="Light Jump";
		};
		class 885th_medic_Jumppack
		{
			model="Detachment_Backpacks";
			backpack="Med Jump";
		};
		class 885th_Arc_Pack
		{
			model="Detachment_Backpacks";
			backpack="ARC Pack";
		};
		//Custom Backpacks
		class 885th_Cust_RTO_Buttbag2_Bandit
		{
			model="Custom_Backpacks";
			backpack="Bandit";
		};
		class 885th_Cust_RTO_Buttbag2_Outcast
		{
			model="Custom_Backpacks";
			backpack="Outcast";
		};
		class 885th_Cust_RTO_Buttbag2_Rios
		{
			model="Custom_Backpacks";
			backpack="Rios";
		};
		class 885th_Cust_RTO_Buttbag2_Thunder
		{
			model="Custom_Backpacks";
			backpack="Thunder";
		};
    };
};
