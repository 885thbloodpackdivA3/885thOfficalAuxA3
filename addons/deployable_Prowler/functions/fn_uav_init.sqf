["Rev_Prowler_item", ["CONTAINER","CLOTHES"], ["Deploy UAV"], [], "", [{true},{params ["_unit", "_container", "_item", "_slot", "_params"];_unit == vehicle _unit}], {
    params ["_unit", "_container", "_item", "_slot", "_params"];
    [_unit,_item] call Rev_fnc_deploy_uav;
},true] call CBA_fnc_addItemContextMenuOption;

private _statement = {
	if (player canAdd "Rev_Prowler_item") then {
		deleteVehicle _target;
		systemChat "Drone added to inventory";
    player addItemToBackpack "Rev_Prowler_item";
	} else {
		playSound "FD_Start_F";
		systemChat "No room in backpack, If you know you have room take your backpack off and put it back on, then try to dissasemble again";
	};
};

private _pack_uav =
[
	"UAV_action", "Disassemble UAV",
	"",
	_statement,
	{alive _target}
] call ace_interact_menu_fnc_createAction;

["Rev_Prowler_b", 0, ["ACE_MainActions"], _pack_uav,true] call ace_interact_menu_fnc_addActionToClass;
