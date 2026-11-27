HUD_fnc_parseText = {
	if (!HUD_systemMessageAllowed) exitWith {};
	private _textScale = safezoneH / 1.81818;
	private _structuredText = "<t align='left'" + format [" size='%1'>",_textScale] + "%1</t>";
	private _textToShow = "";
	if (count HUD_systemMessages == 0) exitWith {
		(HUD_bootUpTextField#0) ctrlSetStructuredText parseText format [_structuredText, _textToShow];
	};
    {
        _textToShow = _textToShow + (_x select 0) + "<br/>";
    } forEach HUD_systemMessages;

	playsound "typing_1";
    (HUD_bootUpTextField#0) ctrlSetStructuredText parseText format [_structuredText, _textToShow];
};

HUD_fnc_addSystemMessage = {
	params ["_text","_messageID","_lifeTime"];
	_lifeTime = 30; // every HUD message fades after 30 s

	if (!SYSTEM_MESSAGES OR !HUD_systemMessageAllowed OR !HUD_hasHelmet) exitWith {};

	if (_messageID == "") then {
		_messageID = "ID_NOT_FOUND:" + str time;
	};

	private _foundIndex = -1;
	{
		if (_messageID in _x) then {
			_foundIndex = _forEachIndex;
			breakOut "";
		};
	} forEach HUD_systemMessages;

	if (_foundIndex > -1) exitWith {
		HUD_systemMessages set [_foundIndex,[_text, _messageID, _lifeTime, time]];
		call HUD_fnc_parseText;
	};

	HUD_systemMessages pushBack [_text, _messageID, _lifeTime, time];
	
	if (count HUD_systemMessages > 15) then {
		HUD_systemMessages deleteAt 0;
	};

	call HUD_fnc_parseText;
};

HUD_fnc_checkAndDeleteOldestLine = {
	
    _lastLineTime = HUD_systemMessages select 0 select 3;
	_lastLineLifeTime = HUD_systemMessages select 0 select 2;
   
   
    if (time - _lastLineTime >= _lastLineLifeTime) then {
        HUD_systemMessages deleteAt 0;     
        call HUD_fnc_parseText;
    };
};

HUD_fnc_SystemMessageLoop = {
	// Spawned at mission start (via HUD_suit_activation), well before
	// boot completes and sets HUD_systemMessageAllowed = true - so a
	// plain `while` here checks its condition once, finds it false,
	// and exits forever without ever running system messages this
	// session. Wait for boot to actually finish first.
	waitUntil {sleep 0.5; HUD_systemMessageAllowed && SYSTEM_MESSAGES};
	while {HUD_systemMessageAllowed && SYSTEM_MESSAGES} do  {
		while {count HUD_systemMessages > 0} do {
			call HUD_fnc_checkAndDeleteOldestLine;	
			sleep 1;
		};
		sleep 1;
	};
};