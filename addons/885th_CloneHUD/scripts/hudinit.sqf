HUD_fnc_hudInit = {

	call HUD_fnc_getHelmetOverlay;

	"HUD_OVERLAY_LAYER" cutRsc ["BPD_CloneHUD_OVERLAY_BASE", "PLAIN", -1, false];
	"HUD_INFO_LAYER" cutRsc ["HUD_INFO","PLAIN", 1, false];
	"HUD_BOOTUP" cutRsc ["HUD_BOOTUP", "PLAIN", -1, false];
	"HUD_INDICATOR_LAYER" cutRsc ["BPD_CloneHUD_INDICATOR_BASE", "PLAIN", -1, false];
	with uiNamespace do {
		_displayHelmet = uiNamespace getVariable "BPD_CloneHUD_OVERLAY_BASE";
		_displayMessage = uiNamespace getVariable "HUD_BOOTUP";
		_displayHUD = uiNamespace getVariable "BPD_CloneHUD_INDICATOR_BASE";
		_displayINFO = uiNamespace getVariable "HUD_INFO";

		HUD_hudOverlay = _displayHelmet ctrlCreate ["RscPicture", 28636];
		HUD_hudOverlay ctrlCommit 0;
		HUD_hudOverlayColor = _displayHelmet ctrlCreate ["RscPicture", 28637];
		HUD_hudOverlayColor ctrlCommit 0;

		HUD_bootUpControlGroup = _displayMessage displayCtrl 110863;
		HUD_bootUpTextField = _displayMessage displayCtrl 10863;

		HUD_infoAmmo = _displayINFO displayCtrl 40860;
		HUD_infoMags = _displayINFO displayCtrl 40861;
		HUD_infoDir = _displayINFO displayCtrl 40862;
		HUD_infoRange = _displayINFO displayCtrl 40863;

		P2_infoAmmo = _displayINFO displayCtrl 40864;
		P2_infoMags = _displayINFO displayCtrl 40865;
		P2_infoDir = _displayINFO displayCtrl 40866;
		P2_infoRange = _displayINFO displayCtrl 40867;

		RC_infoAmmo = _displayINFO displayCtrl 40868;
		RC_infoMags = _displayINFO displayCtrl 40869;
		RC_infoDir = _displayINFO displayCtrl 40870;
		RC_infoRange = _displayINFO displayCtrl 40871;

		HUD_startUpImage = _displayMessage ctrlCreate ["RscPicture", 10864];
		HUD_interiorOverlay = _displayHelmet ctrlCreate ["RscPicture", 27637];
		// The stand/silhouette the trooper sits on. Used to be baked into
		// the interior overlay, so it stayed put when the trooper moved.
		HUD_trooperBase = _displayHelmet ctrlCreate ["RscPicture", 27638];
		HUD_pa_head = _displayHUD ctrlCreate ["RscPicture", 27639];
		HUD_pa_torso = _displayHUD ctrlCreate ["RscPicture", 27640];
		HUD_pa_armR = _displayHUD ctrlCreate ["RscPicture", 27641];
		HUD_pa_armL = _displayHUD ctrlCreate ["RscPicture", 27642];
		HUD_pa_legR = _displayHUD ctrlCreate ["RscPicture", 27643];
		HUD_pa_legL = _displayHUD ctrlCreate ["RscPicture", 27644];
		HUD_infoDisplay = _displayHUD ctrlCreate ["RscPicture", 27645];
		P2_infoDisplay = _displayHUD ctrlCreate ["RscPicture", 27645];
		RC_infoDisplay = _displayHUD ctrlCreate ["RscPicture", 27645];
		HUD_visorEffect = _displayHUD ctrlCreate ["RscPicture", 27646];
		HUD_teamList = _displayHUD ctrlCreate ["RscStructuredText", 27650];

		// creation order = draw order: disc, rings, blips, own marker, labels
		HUD_radarDisc = _displayHUD ctrlCreate ["RscPicture", 27675];
		HUD_radarBackground = _displayHUD ctrlCreate ["RscPicture", 27651];
		private _radarBlipPool = [];
		for "_i" from 0 to 19 do {
			_radarBlipPool pushBack (_displayHUD ctrlCreate ["RscPicture", 27652 + _i]);
		};
		uiNamespace setVariable ["HUD_radarBlips", _radarBlipPool];
		HUD_radarSelf = _displayHUD ctrlCreate ["RscPicture", 27676];
		HUD_radarNorth = _displayHUD ctrlCreate ["RscStructuredText", 27677];
		HUD_radarRange = _displayHUD ctrlCreate ["RscStructuredText", 27678];

		// Tactical link panel (cTab device strip + helm cam feed) - see ctab.sqf
		HUD_feedBack = _displayHUD ctrlCreate ["RscText", 27680];
		HUD_feedPicture = _displayHUD ctrlCreate ["RscPicture", 27681];
		HUD_feedHeader = _displayHUD ctrlCreate ["RscStructuredText", 27682];
		HUD_feedLabel = _displayHUD ctrlCreate ["RscStructuredText", 27683];
		// Tac Map link mode (ctab.sqf) - BFT mini-map in the same panel.
		// The 885th cTab device frame is created first so the map draws
		// on top of it, inside the frame's screen opening.
		HUD_feedFrame = _displayHUD ctrlCreate ["RscPicture", 27686];
		HUD_feedMap = _displayHUD ctrlCreate ["RscMapControl", 27685];
	};

	HUD_hudOverlay = [uiNamespace getVariable "HUD_hudOverlay"];
	HUD_hudOverlayColor = [uiNamespace getVariable "HUD_hudOverlayColor"];
	HUD_helmetOverlayShown = true;

	HUD_startUpImage = [uiNamespace getVariable "HUD_startUpImage"];
	HUD_bootUpControlGroup = [uiNamespace getVariable "HUD_bootUpControlGroup"];
	HUD_bootUpTextField = [uiNamespace getVariable "HUD_bootUpTextField"];

	HUD_infoAmmo = [uiNamespace getVariable "HUD_infoAmmo"];
	HUD_infoMags = [uiNamespace getVariable "HUD_infoMags"];
	HUD_infoDir = [uiNamespace getVariable "HUD_infoDir"];
	HUD_infoRange = [uiNamespace getVariable "HUD_infoRange"];

	P2_infoAmmo = [uiNamespace getVariable "P2_infoAmmo"];
	P2_infoMags = [uiNamespace getVariable "P2_infoMags"];
	P2_infoDir = [uiNamespace getVariable "P2_infoDir"];
	P2_infoRange = [uiNamespace getVariable "P2_infoRange"];

	RC_infoAmmo = [uiNamespace getVariable "RC_infoAmmo"];
	RC_infoMags = [uiNamespace getVariable "RC_infoMags"];
	RC_infoDir = [uiNamespace getVariable "RC_infoDir"];
	RC_infoRange = [uiNamespace getVariable "RC_infoRange"];

	HUD_interiorOverlay = [uiNamespace getVariable "HUD_interiorOverlay"];
	HUD_trooperBase = [uiNamespace getVariable "HUD_trooperBase"];
	(HUD_trooperBase#0) ctrlSetTextColor [0,0,0,0];
	(HUD_trooperBase#0) ctrlCommit 0;
	HUD_pa_head = [uiNamespace getVariable "HUD_pa_head"];
	HUD_pa_torso = [uiNamespace getVariable "HUD_pa_torso"];
	HUD_pa_armL = [uiNamespace getVariable "HUD_pa_armL"];
	HUD_pa_armR = [uiNamespace getVariable "HUD_pa_armR"];
	HUD_pa_legL = [uiNamespace getVariable "HUD_pa_legL"];
	HUD_pa_legR = [uiNamespace getVariable "HUD_pa_legR"];
	HUD_infoDisplay = [uiNamespace getVariable "HUD_infoDisplay"];
	P2_infoDisplay = [uiNamespace getVariable "P2_infoDisplay"];
	RC_infoDisplay = [uiNamespace getVariable "RC_infoDisplay"];

	HUD_visorEffect = [uiNamespace getVariable "HUD_visorEffect"];
	HUD_teamList = [uiNamespace getVariable "HUD_teamList"];
	HUD_radarBackground = [uiNamespace getVariable "HUD_radarBackground"];
	HUD_radarBlips = uiNamespace getVariable "HUD_radarBlips";
	HUD_radarDisc = [uiNamespace getVariable "HUD_radarDisc"];
	HUD_radarSelf = [uiNamespace getVariable "HUD_radarSelf"];
	HUD_radarNorth = [uiNamespace getVariable "HUD_radarNorth"];
	HUD_radarRange = [uiNamespace getVariable "HUD_radarRange"];

	HUD_feedBack = [uiNamespace getVariable "HUD_feedBack"];
	HUD_feedPicture = [uiNamespace getVariable "HUD_feedPicture"];
	HUD_feedHeader = [uiNamespace getVariable "HUD_feedHeader"];
	HUD_feedLabel = [uiNamespace getVariable "HUD_feedLabel"];
	(HUD_feedBack#0) ctrlSetBackgroundColor [0,0,0,0.45];
	(HUD_feedPicture#0) ctrlSetText "#(argb,512,512,1)r2t(bpd_clonehud_rt,1.7778)";
	(HUD_feedHeader#0) ctrlSetBackgroundColor [0,0,0,0];
	(HUD_feedLabel#0) ctrlSetBackgroundColor [0,0,0,0.4];
	{ (_x#0) ctrlShow false; (_x#0) ctrlCommit 0; } forEach [HUD_feedBack, HUD_feedPicture, HUD_feedHeader, HUD_feedLabel];
	HUD_feedFrame = [uiNamespace getVariable ["HUD_feedFrame", controlNull]];
	if (!isNull (HUD_feedFrame#0)) then { (HUD_feedFrame#0) ctrlShow false; (HUD_feedFrame#0) ctrlCommit 0; };
	HUD_feedMap = [uiNamespace getVariable ["HUD_feedMap", controlNull]];
	if (!isNull (HUD_feedMap#0)) then {
		(HUD_feedMap#0) ctrlShow false;
		(HUD_feedMap#0) ctrlCommit 0;
		if (!isNil "BPD_CloneHUD_fnc_tacmapDraw") then {
			(HUD_feedMap#0) ctrlAddEventHandler ["Draw", { with missionNamespace do { _this call BPD_CloneHUD_fnc_tacmapDraw; }; }];
		};
	};

	(HUD_startUpImage#0) ctrlSetPosition [safezoneX,safezoneY,safezoneW,safezoneH];
	(HUD_startUpImage#0) ctrlSetText HUD_START_IMAGE;
	(HUD_startUpImage#0) ctrlSetTextColor [0,0,0,0];
	(HUD_startUpImage#0) ctrlCommit 0;

	(HUD_interiorOverlay#0) ctrlSetPosition [safezoneX,safezoneY,safezoneW,safezoneH];
	(HUD_interiorOverlay#0) ctrlSetText HUD_TEXTURE_INTERIOR_OVERLAY;
	(HUD_interiorOverlay#0) ctrlSetTextColor [0,0,0,0];
	(HUD_interiorOverlay#0) ctrlCommit 0;

	// Limb indicator, team list, radar and tactical link panel are all
	// positioned by BPD_CloneHUD_fnc_applyLayout (layout.sqf) from the
	// per-player Layout settings - this just starts them hidden.
	{
		(_x#0) ctrlSetTextColor [0,0,0,0];
		(_x#0) ctrlCommit 0;
	} forEach [HUD_pa_head, HUD_pa_torso, HUD_pa_armR, HUD_pa_armL, HUD_pa_legR, HUD_pa_legL];

	(HUD_teamList#0) ctrlSetStructuredText parseText "";

	// Radar dial, built from vanilla UI textures (ui_f_data). The 1.0
	// build used an RscPicture with NO texture and only a background
	// color - pictures don't draw a background, so the dial never showed
	// at all, only blips (and only with a scanned unit in line of sight).
	private _radarCustomTexture = missionnamespace getVariable ["RADAR_BACKGROUND_TEXTURE", ""];
	(HUD_radarDisc#0) ctrlSetText "\A3\ui_f\data\IGUI\RscCustomInfo\Sensors\SENSCircles_ca.paa";
	(HUD_radarBackground#0) ctrlSetText (if (_radarCustomTexture != "") then {_radarCustomTexture} else {"\A3\ui_f\data\IGUI\Cfg\SquadRadar\SquadRadarBackgroundTexture_ca.paa"});
	(HUD_radarSelf#0) ctrlSetText "\A3\ui_f\data\map\markers\military\triangle_CA.paa";
	{
		(_x#0) ctrlSetTextColor [0,0,0,0];
		(_x#0) ctrlSetBackgroundColor [0,0,0,0];
		(_x#0) ctrlCommit 0;
	} forEach [HUD_radarDisc, HUD_radarBackground, HUD_radarSelf, HUD_radarNorth, HUD_radarRange];
	(HUD_radarNorth#0) ctrlSetStructuredText parseText "";
	(HUD_radarRange#0) ctrlSetStructuredText parseText "";
	{
		_x ctrlSetTextColor [0,0,0,0];
		_x ctrlCommit 0;
	} forEach HUD_radarBlips;

	call BPD_CloneHUD_fnc_applyLayout;
	if (!isNil "BPD_CloneHUD_fnc_ammoCreate") then { call BPD_CloneHUD_fnc_ammoCreate; };
	if (!isNil "BPD_CloneHUD_fnc_commsCreate") then { call BPD_CloneHUD_fnc_commsCreate; };
	if (!isNil "BPD_CloneHUD_fnc_intelLogCreate") then { call BPD_CloneHUD_fnc_intelLogCreate; };
	if (!isNil "BPD_CloneHUD_fnc_killCreate") then { call BPD_CloneHUD_fnc_killCreate; };

	(HUD_infoDisplay#0) ctrlSetPosition [safezoneX,safezoneY,safezoneW,safezoneH];
	(HUD_infoDisplay#0) ctrlSetText TEXTURE_DATAOUTPUT;
	(HUD_infoDisplay#0) ctrlSetTextColor [0,0,0,0];
	(HUD_infoDisplay#0) ctrlCommit 0;

	(P2_infoDisplay#0) ctrlSetPosition [safezoneX,safezoneY,safezoneW,safezoneH];
	(P2_infoDisplay#0) ctrlSetText TEXTURE_DATAOUTPUT;
	(P2_infoDisplay#0) ctrlSetTextColor [0,0,0,0];
	(P2_infoDisplay#0) ctrlCommit 0;

	(RC_infoDisplay#0) ctrlSetPosition [safezoneX,safezoneY,safezoneW,safezoneH];
	(RC_infoDisplay#0) ctrlSetText TEXTURE_DATAOUTPUT;
	(RC_infoDisplay#0) ctrlSetTextColor [0,0,0,0];
	(RC_infoDisplay#0) ctrlCommit 0;

	(HUD_visorEffect#0) ctrlSetPosition [safezoneX,safezoneY,safezoneW,safezoneH];
	(HUD_visorEffect#0) ctrlSetText HUD_VISOR_EFFECT;
	(HUD_visorEffect#0) ctrlSetTextColor [0,0,0,0];
	(HUD_visorEffect#0) ctrlCommit 0;

	call HUD_fnc_addHudEventhandler;
};
