// 885th - LAAT jump light switch (pilot / co-pilot scroll actions).
// Drop BPD_JUMPLIGHT_ACTIONS inside any aircraft's class UserActions.
// State lives in the public variable "BPD_jumpLight" (0 off / 1 red / 2 green);
// BPD_fnc_jumpLightClient draws the cabin lights and passenger HUD from it.
#define BPD_JUMPLIGHT_ACTIONS \
	class BPD_JumpLight_Red \
	{ \
		displayName = "<t color='#ff3b30'>Jump Light: RED (Stand By)</t>"; \
		position = "pilotview"; \
		radius = 5; \
		onlyForPlayer = 0; \
		showWindow = 0; \
		hideOnUse = 1; \
		priority = 5; \
		condition = "(this getVariable ['BPD_jumpLight', 0]) != 1 && {[this] call BPD_fnc_jumpLightCanUse}"; \
		statement = "[this, 1] call BPD_fnc_jumpLightSet"; \
	}; \
	class BPD_JumpLight_Green: BPD_JumpLight_Red \
	{ \
		displayName = "<t color='#34c759'>Jump Light: GREEN (Dismount)</t>"; \
		condition = "(this getVariable ['BPD_jumpLight', 0]) != 2 && {[this] call BPD_fnc_jumpLightCanUse}"; \
		statement = "[this, 2] call BPD_fnc_jumpLightSet"; \
	}; \
	class BPD_JumpLight_Off: BPD_JumpLight_Red \
	{ \
		displayName = "<t color='#aaaaaa'>Jump Light: OFF</t>"; \
		priority = 4.9; \
		condition = "(this getVariable ['BPD_jumpLight', 0]) != 0 && {[this] call BPD_fnc_jumpLightCanUse}"; \
		statement = "[this, 0] call BPD_fnc_jumpLightSet"; \
	};
