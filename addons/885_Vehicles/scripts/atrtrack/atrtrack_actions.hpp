// 885th - LAAT AT-RT rack actions. Drop BPD_ATRTRACK_ACTIONS inside a LAAT/i's
// class UserActions and set BPD_atrtRackMax on the vehicle class.
// Racked units are kept in the public variable "BPD_atrtRack" on the LAAT.
#define BPD_ATRTRACK_ACTIONS \
	class BPD_ATRTRack_Load \
	{ \
		displayName = "<t color='#4aa3ff'>Clamp AT-RTs into Bay</t>"; \
		position = "pilotview"; \
		radius = 5; \
		onlyForPlayer = 0; \
		showWindow = 0; \
		hideOnUse = 1; \
		priority = 3; \
		condition = "[this, 'load'] call BPD_fnc_atrtRackCan"; \
		statement = "[this] spawn BPD_fnc_atrtRackLoad"; \
	}; \
	class BPD_ATRTRack_Drop: BPD_ATRTRack_Load \
	{ \
		displayName = "<t color='#4aa3ff'>Release AT-RTs</t>"; \
		condition = "[this, 'drop'] call BPD_fnc_atrtRackCan"; \
		statement = "[this] spawn BPD_fnc_atrtRackDrop"; \
	}; \
	class BPD_ATRTRack_Self: BPD_ATRTRack_Load \
	{ \
		displayName = "<t color='#4aa3ff'>Unclamp from LAAT</t>"; \
		radius = 20; \
		priority = 6; \
		condition = "[this, 'self'] call BPD_fnc_atrtRackCan"; \
		statement = "[missionNamespace getVariable ['bis_fnc_moduleRemoteControl_unit', player]] call BPD_fnc_atrtRackRelease"; \
	};
