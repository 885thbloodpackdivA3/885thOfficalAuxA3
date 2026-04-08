params ["_user","_item"];

closeDialog 602;

private _vehicletype = nil;
switch (side _unit) do {
    default {_vehicletype = "Rev_Prowler_b"};
};




private _uav = _vehicletype createVehicle position player;
createVehicleCrew _uav;
player connectTerminalToUAV _uav;

_playername = name player;
_rdm = str round(random 100);
_namestr = "(" + _rdm + ")" + _playername + "'s";
group _uav setGroupidGlobal [_namestr];



false;
