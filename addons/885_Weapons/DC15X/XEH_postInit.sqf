/*
 * 885th DC-15X Heavy Sniper - XEH_postInit.sqf
 * Runs on every machine (server and clients): whoever owns a vehicle applies the anti-materiel disable to it.
 */
["BPD_dc15xAMVehicleHit", {
    _this call BPD_fnc_dc15xAMVehicleHit;
}] call CBA_fnc_addEventHandler;
