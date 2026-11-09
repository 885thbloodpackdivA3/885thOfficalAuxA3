class XtdGearModels
{
	class CfgWeapons
	{
		// ---------------- Primary weapons ----------------
		class 885th_Carbines
		{
			options[]=
			{
				"weapon",
				"variant"
			};
			label="885th Carbines";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"DC-15S",
					"DC-15S MKII",
					"DC-15SE",
					"DC-15S Elite",
					"DC-15C",
					"DC-15C MKII",
					"DC-19"
				};
			};
			class variant
			{
				label="Variant";
				values[]=
				{
					"Standard",
					"GL",
					"FS"
				};
				alwaysSelectable=1;
			};
		};
		class 885th_Rifles
		{
			options[]=
			{
				"weapon",
				"variant"
			};
			label="885th Rifles";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"DC-15A",
					"DC-15A MKII",
					"DC-15BR",
					"DX36C",
					"Valken-38A"
				};
			};
			class variant
			{
				label="Variant";
				values[]=
				{
					"Standard",
					"GL"
				};
				alwaysSelectable=1;
			};
		};
		class 885th_ARC
		{
			options[]=
			{
				"weapon",
				"variant"
			};
			label="885th Westar Platforms";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"Westar-M5",
					"Westar-M5 MKII"
				};
			};
			class variant
			{
				label="Variant";
				values[]=
				{
					"Standard",
					"GL"
				};
				alwaysSelectable=1;
			};
		};
		class 885th_Marksman
		{
			options[]=
			{
				"weapon"
			};
			label="885th Marksman Rifles";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"DC-15LE",
					"DW-32S",
					"Valken-38R"
				};
			};
		};
		class 885th_Republic_Snipers
		{
			options[]=
			{
				"weapon"
			};
			label="885th Republic Snipers";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"DC-15X Sharpshooter",
					"DC-15X"
				};
			};
		};
		class 885th_DC17M
		{
			options[]=
			{
				"weapon"
			};
			label="885th DC-17M";
			class weapon
			{
				label="Configuration";
				values[]=
				{
					"Blaster"
				};
			};
		};
		class 885th_773_Platform
		{
			options[]=
			{
				"weapon",
				"variant"
			};
			label="885th 773 Platform";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"773BR",
					"Fire Puncher",
					"FireSpitter"
				};
			};
			class variant
			{
				label="Mark";
				values[]=
				{
					"MKI",
					"MKII"
				};
				alwaysSelectable=1;
			};
		};
		class 885th_Scatterguns
		{
			options[]=
			{
				"weapon"
			};
			label="885th Scatterguns";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"DP-23",
					"DX-23",
					"DC-23"
				};
			};
		};
		class 885th_Heavy_Weapons
		{
			options[]=
			{
				"weapon"
			};
			label="885th Heavy Weapons";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"T-15 LIR",
					"T-15",
					"Z-6",
					"Z-6 Para",
					"Z8",
					"M-41",
					"DC-15L MKII",
					"DC-15L LMG",
					"DC-15LE Heavy",
					"Valken-38X"
				};
			};
		};
		class 885th_Explosive_Weapons
		{
			options[]=
			{
				"weapon"
			};
			label="885th Explosive Weapons";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"MPL",
					"EPL2"
				};
			};
		};
		class 885th_NonRepublic_Weapons
		{
			options[]=
			{
				"weapon"
			};
			label="885th Non-Republic Weapons";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"E-5",
					"E-5C",
					"E-5S",
					"Wrist Blaster",
					"Galaar-15",
					"Galaar-90",
					"FA-11",
					"SPA-K12"
				};
			};
		};

		// ---------------- Launchers ----------------
		class 885th_Launchers
		{
			options[]=
			{
				"weapon",
				"variant"
			};
			label="885th Launchers";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"RPS-6"
				};
			};
			class variant
			{
				label="Type";
				values[]=
				{
					"Standard",
					"Disposable",
					"Disposable Guided"
				};
				alwaysSelectable=1;
			};
		};
		class 885th_ADV_AT
		{
			options[]=
			{
				"weapon"
			};
			label="885th ADV AT";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"PLX"
				};
			};
		};

		// ---------------- Handguns ----------------
		class 885th_Pistols
		{
			options[]=
			{
				"weapon",
				"variant"
			};
			label="885th Blaster Pistols";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"DC-17",
					"DC-17A",
					"DC-17S",
					"DC-15P",
					"DC-15SA",
					"DC-21",
					"DC-FG"
				};
			};
			class variant
			{
				label="Variant";
				values[]=
				{
					"Single",
					"Dual"
				};
				alwaysSelectable=1;
			};
		};
		class 885th_NonRepublic_Pistols
		{
			options[]=
			{
				"weapon"
			};
			label="885th Non-Republic Pistols";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"Westar-35",
					"A180",
					"S-5"
				};
			};
		};

		// ---------------- Melee ----------------
		class 885th_Melee
		{
			options[]=
			{
				"weapon"
			};
			label="885th Melee";
			class weapon
			{
				label="Weapon";
				values[]=
				{
					"Vibroblade",
					"Vibroblade Reversed"
				};
			};
		};
	};
};
class XtdGearInfos
{
	class CfgWeapons
	{
		//Carbines
		class 885th_DC15S
		{
			model="885th_Carbines";
			weapon="DC-15S";
			variant="Standard";
		};
		class 885th_DC15SMKII_F
		{
			model="885th_Carbines";
			weapon="DC-15S MKII";
			variant="Standard";
		};
		class 885th_DC15SMKII_GL
		{
			model="885th_Carbines";
			weapon="DC-15S MKII";
			variant="GL";
		};
		class 885th_DC15SE
		{
			model="885th_Carbines";
			weapon="DC-15SE";
			variant="Standard";
		};
		class 885th_DC15SE_GL
		{
			model="885th_Carbines";
			weapon="DC-15SE";
			variant="GL";
		};
		class 885th_Modified_DC15S
		{
			model="885th_Carbines";
			weapon="DC-15S Elite";
			variant="Standard";
		};
		class 885th_DC15C_F
		{
			model="885th_Carbines";
			weapon="DC-15C";
			variant="Standard";
		};
		class 885th_DC15C_GL
		{
			model="885th_Carbines";
			weapon="DC-15C";
			variant="GL";
		};
		class 885th_DC15CMK2
		{
			model="885th_Carbines";
			weapon="DC-15C MKII";
			variant="Standard";
		};
		class 885th_DC15CMK2_GL
		{
			model="885th_Carbines";
			weapon="DC-15C MKII";
			variant="GL";
		};
		class 885th_DC19
		{
			model="885th_Carbines";
			weapon="DC-19";
			variant="Standard";
		};
		class 885th_DC19FS
		{
			model="885th_Carbines";
			weapon="DC-19";
			variant="FS";
		};
		//Westar Platforms
		class 885th_WestarM5_F
		{
			model="885th_ARC";
			weapon="Westar-M5";
			variant="Standard";
		};
		class 885th_WestarM5_GL
		{
			model="885th_ARC";
			weapon="Westar-M5";
			variant="GL";
		};
		class 885th_WestarM5MKII_F
		{
			model="885th_ARC";
			weapon="Westar-M5 MKII";
			variant="Standard";
		};
		//Rifles
		class 885th_DC15A
		{
			model="885th_Rifles";
			weapon="DC-15A";
			variant="Standard";
		};
		class 885th_DC15AMKII_F
		{
			model="885th_Rifles";
			weapon="DC-15A MKII";
			variant="Standard";
		};
		class 885th_DC15AMKII_GL
		{
			model="885th_Rifles";
			weapon="DC-15A MKII";
			variant="GL";
		};
		class 885th_DC15BR
		{
			model="885th_Rifles";
			weapon="DC-15BR";
			variant="Standard";
		};
		class 885th_DX36C_F
		{
			model="885th_Rifles";
			weapon="DX36C";
			variant="Standard";
		};
		class 885th_DC15LEHB_F
		{
			model="885th_Heavy_Weapons";
			weapon="DC-15LE Heavy";
		};
		class 885th_Valken38A_F
		{
			model="885th_Rifles";
			weapon="Valken-38A";
			variant="Standard";
		};
		//Marksman Rifles
		class 885th_DC15LMKII_F
		{
			model="885th_Heavy_Weapons";
			weapon="DC-15L MKII";
		};
		// defined in 885_3AS_Experimental
		class 885th_DC15L_F
		{
			model="885th_Heavy_Weapons";
			weapon="DC-15L LMG";
		};
		class 885th_DC15LEMKII
		{
			model="885th_Marksman";
			weapon="DC-15LE";
		};
		//Republic Snipers
		class 885th_DC15XS
		{
			model="885th_Republic_Snipers";
			weapon="DC-15X Sharpshooter";
		};
		// defined in 885_3AS_Experimental
		class 885th_DC15X_F
		{
			model="885th_Republic_Snipers";
			weapon="DC-15X";
		};
		//DC-17M (Sniper/Launcher configs are scope=1, reached via the in-game switch)
		class 885th_DC17M_F
		{
			model="885th_DC17M";
			weapon="Blaster";
		};
		//Marksman Rifles
		class 885th_DW32S
		{
			model="885th_Marksman";
			weapon="DW-32S";
		};
		class 885th_DC15HR
		{
			model="885th_Heavy_Weapons";
			weapon="Valken-38X";
		};
		class 885th_Valken38XMKII
		{
			model="885th_Marksman";
			weapon="Valken-38R";
		};
		//773 Platform
		class 885th_773_BR
		{
			model="885th_773_Platform";
			weapon="773BR";
			variant="MKI";
		};
		class 885th_773_Firepuncher
		{
			model="885th_773_Platform";
			weapon="Fire Puncher";
			variant="MKI";
		};
		class 885th_773_Firepuncher_MKII
		{
			model="885th_773_Platform";
			weapon="Fire Puncher";
			variant="MKII";
		};
		class 885th_773_FireSpitter
		{
			model="885th_773_Platform";
			weapon="FireSpitter";
			variant="MKI";
		};
		class 885th_773_FireSpitter_MKII
		{
			model="885th_773_Platform";
			weapon="FireSpitter";
			variant="MKII";
		};
		//Scatterguns
		class 885th_DP23_F
		{
			model="885th_Scatterguns";
			weapon="DP-23";
		};
		class 885th_DX23_F
		{
			model="885th_Scatterguns";
			weapon="DX-23";
		};
		class 885th_DC23
		{
			model="885th_Scatterguns";
			weapon="DC-23";
		};
		//Heavy Weapons
		class 885th_T15LIR
		{
			model="885th_Heavy_Weapons";
			weapon="T-15 LIR";
		};
		class 885th_T15
		{
			model="885th_Heavy_Weapons";
			weapon="T-15";
		};
		class 885th_Z6
		{
			model="885th_Heavy_Weapons";
			weapon="Z-6";
		};
		class 885th_Z6Para_F
		{
			model="885th_Heavy_Weapons";
			weapon="Z-6 Para";
		};
		class 885th_Z8_Experimental_F
		{
			model="885th_Heavy_Weapons";
			weapon="Z8";
		};
		class 885th_M41
		{
			model="885th_Heavy_Weapons";
			weapon="M-41";
		};
		//Explosive Weapons
		class 885th_EPL2
		{
			model="885th_Explosive_Weapons";
			weapon="EPL2";
		};
		class 885th_MPL_F
		{
			model="885th_Explosive_Weapons";
			weapon="MPL";
		};
		//Non-Republic Weapons
		class 885th_E5
		{
			model="885th_NonRepublic_Weapons";
			weapon="E-5";
		};
		class 885th_E5C
		{
			model="885th_NonRepublic_Weapons";
			weapon="E-5C";
		};
		class 885th_E5S
		{
			model="885th_NonRepublic_Weapons";
			weapon="E-5S";
		};
		class 885th_WristBlaster
		{
			model="885th_NonRepublic_Weapons";
			weapon="Wrist Blaster";
		};
		class 885th_Galaar15
		{
			model="885th_NonRepublic_Weapons";
			weapon="Galaar-15";
		};
		class 885th_Galaar90
		{
			model="885th_NonRepublic_Weapons";
			weapon="Galaar-90";
		};
		class 885th_FA11
		{
			model="885th_NonRepublic_Weapons";
			weapon="FA-11";
		};
		class 885th_SPAK15
		{
			model="885th_NonRepublic_Weapons";
			weapon="SPA-K12";
		};
		//Blaster Pistols
		class 885th_DC17
		{
			model="885th_Pistols";
			weapon="DC-17";
			variant="Single";
		};
		class 885th_DC17A
		{
			model="885th_Pistols";
			weapon="DC-17A";
			variant="Single";
		};
		class 885th_DC17S_F
		{
			model="885th_Pistols";
			weapon="DC-17S";
			variant="Single";
		};
		class 885th_DC17S_Dual_F
		{
			model="885th_Pistols";
			weapon="DC-17S";
			variant="Dual";
		};
		class 885th_DC15P
		{
			model="885th_Pistols";
			weapon="DC-15P";
			variant="Single";
		};
		class 885th_DC15SA_F
		{
			model="885th_Pistols";
			weapon="DC-15SA";
			variant="Single";
		};
		class 885th_DC21
		{
			model="885th_Pistols";
			weapon="DC-21";
			variant="Single";
		};
		class 885th_DCFG
		{
			model="885th_Pistols";
			weapon="DC-FG";
			variant="Single";
		};
		//Non-Republic Pistols
		class 885th_Westar35
		{
			model="885th_NonRepublic_Pistols";
			weapon="Westar-35";
		};
		class 885th_A180
		{
			model="885th_NonRepublic_Pistols";
			weapon="A180";
		};
		class 885th_S5Security
		{
			model="885th_NonRepublic_Pistols";
			weapon="S-5";
		};
		//Melee
		class 885th_Vibroblade_r
		{
			model="885th_Melee";
			weapon="Vibroblade";
		};
		class 885th_Vibroblade_rotated_r
		{
			model="885th_Melee";
			weapon="Vibroblade Reversed";
		};
		//ADV AT
		class 885th_launch_PLX_F
		{
			model="885th_ADV_AT";
			weapon="PLX";
		};
		//Launchers (RPS-6 classes are defined in 885_3AS_Experimental)
		class 885th_RPS6
		{
			model="885th_Launchers";
			weapon="RPS-6";
			variant="Standard";
		};
		class 885th_RPS6_Dispo
		{
			model="885th_Launchers";
			weapon="RPS-6";
			variant="Disposable";
		};
		class 885th_RPS6_G_Dispo
		{
			model="885th_Launchers";
			weapon="RPS-6";
			variant="Disposable Guided";
		};
	};
};
