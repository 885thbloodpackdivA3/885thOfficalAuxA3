/*
    Author: 885th Bloodpack Division
    ARC-170 deflector shields + power routing - postInit.

    Two loops:
      1. Owner loop (every machine, 10 Hz): for each ARC-170 that is LOCAL
         here, recharges the shield per the power mode and broadcasts the
         value at most ~every 0.5s (or right away on a big change), so the
         network only carries a number now and then, not every frame.
      2. Client loop (players only, every frame): HUD for whoever is aboard,
         plus the engine boost for the pilot. The pilot always owns the jet,
         so the boost's velocity change happens on the machine that simulates
         it - no network traffic and no fighting the physics owner.
*/

if (!isNil "BPD_arc_ownerPFH") then { [BPD_arc_ownerPFH] call CBA_fnc_removePerFrameHandler; };
if (!isNil "BPD_arc_clientPFH") then { [BPD_arc_clientPFH] call CBA_fnc_removePerFrameHandler; };

BPD_arc_lastOwnerTick = diag_tickTime;

BPD_arc_ownerPFH = [{
    private _now = diag_tickTime;
    private _dt = (_now - BPD_arc_lastOwnerTick) min 1;
    BPD_arc_lastOwnerTick = _now;

    BPD_arc_vehicles = BPD_arc_vehicles select { !isNull _x };
    if !(missionNamespace getVariable ["AUX_885th_ARC_Enabled", true]) exitWith {};

    private _max      = missionNamespace getVariable ["AUX_885th_ARC_ShieldMax", 1];
    private _rate     = missionNamespace getVariable ["AUX_885th_ARC_RegenRate", 0.05];
    private _delay    = missionNamespace getVariable ["AUX_885th_ARC_RegenDelay", 5];

    {
        private _veh = _x;
        if (local _veh && {alive _veh}) then {
            private _shield = (_veh getVariable ["BPD_arc_shield", _max]) min _max;
            private _mode   = _veh getVariable ["BPD_arc_power", 0];
            private _broken = _veh getVariable ["BPD_arc_broken", false];
            private _last   = _veh getVariable ["BPD_arc_lastHit", 0];

            private _repairing = _veh getVariable ["BPD_arc_repairing", false];

            // --- emergency repair (power diverted: no shield recharge meanwhile) ---
            if (_repairing) then { [_veh, _dt] call BPD_fnc_repairTick; };
            // repair charges are reloaded only by the AMS refuel (fn_arcAMSRefuel.sqf)

            // --- engine strain: Max Engines on a damaged jet (fn_arcStrain.sqf) ---
            ([_veh] call BPD_fnc_arcStrainCheck) params ["_strained", "_damagedIdx"];
            if (_strained != (_veh getVariable ["BPD_arc_strain", false])) then {
                _veh setVariable ["BPD_arc_strain", _strained, true]; // crew HUDs + alarm read this
            };
            if (_strained) then {
                _shield = (_shield - ((missionNamespace getVariable ["AUX_885th_ARC_StrainShieldDrain", 0.05]) * _max * _dt)) max 0;

                private _fuelDrain = missionNamespace getVariable ["AUX_885th_ARC_StrainFuelDrain", 0.005];
                if (_fuelDrain > 0) then { _veh setFuel (((fuel _veh) - (_fuelDrain * _dt)) max 0); };

                private _wear = (missionNamespace getVariable ["AUX_885th_ARC_StrainWear", 0.01]) * _dt;
                if (_wear > 0) then {
                    private _vals = (getAllHitPointsDamage _veh) param [2, []];
                    {
                        private _d = _vals param [_x, 0];
                        if (_d < 0.9) then { _veh setHitIndex [_x, (_d + _wear) min 0.9, false]; };
                    } forEach _damagedIdx;
                };
            };

            private _mult = [1, 2, 0] select (_mode min 2 max 0);
            if (_repairing) then { _mult = 0; };
            if (_mult > 0 && {isEngineOn _veh} && {_shield < _max} && {_now - _last > _delay}) then {
                _shield = (_shield + (_rate * _mult * _max * _dt)) min _max;
            };
            _veh setVariable ["BPD_arc_shield", _shield];

            if (_broken && {_shield >= _max * 0.1}) then {
                _veh setVariable ["BPD_arc_broken", false, true];
            };

            // throttled broadcast
            private _synced   = _veh getVariable ["BPD_arc_synced", -1];
            private _syncTime = _veh getVariable ["BPD_arc_syncTime", 0];
            if (abs (_shield - _synced) > (_max * 0.1) || {abs (_shield - _synced) > 0.0001 && {_now - _syncTime > 0.5}}) then {
                _veh setVariable ["BPD_arc_shield", _shield, true];
                _veh setVariable ["BPD_arc_synced", _shield];
                _veh setVariable ["BPD_arc_syncTime", _now];
            };
        };
    } forEach BPD_arc_vehicles;
}, 0.1, []] call CBA_fnc_addPerFrameHandler;

// --- V-wing: emergency repair only (no shields / power routing / HUD) ---
// Runs the repair on whichever machine owns the jet, and reloads the charges
// when the V-wing is refueled on the ground (fuel truck, ACE refuel, etc.).
if (!isNil "BPD_vwing_ownerPFH") then { [BPD_vwing_ownerPFH] call CBA_fnc_removePerFrameHandler; };
BPD_vwing_lastTick = diag_tickTime;

BPD_vwing_ownerPFH = [{
    private _now = diag_tickTime;
    private _dt = (_now - BPD_vwing_lastTick) min 1;
    BPD_vwing_lastTick = _now;

    BPD_vwing_vehicles = BPD_vwing_vehicles select { !isNull _x };
    if !(missionNamespace getVariable ["AUX_885th_ARC_RepairEnabled", true]) exitWith {};

    {
        private _veh = _x;
        if (local _veh && {alive _veh}) then {
            if (_veh getVariable ["BPD_arc_repairing", false]) then { [_veh, _dt] call BPD_fnc_repairTick; };

            // Refuel detection: the reference follows fuel down (burn) and in the
            // air; a rise of 5%+ while landed and stopped counts as a refuel.
            private _fuel = fuel _veh;
            private _ref = _veh getVariable ["BPD_vwing_fuelRef", _fuel];
            private _landed = isTouchingGround _veh && {speed _veh < 5};
            if (!_landed || {_fuel < _ref}) then {
                _ref = _fuel;
            } else {
                if (_fuel > _ref + 0.05) then {
                    _ref = _fuel;
                    private _max = round (missionNamespace getVariable ["AUX_885th_VWING_RepairCharges", 1]);
                    if ((_veh getVariable ["BPD_arc_repairCharges", 0]) < _max) then {
                        _veh setVariable ["BPD_arc_repairCharges", _max, true];
                        private _targets = (crew _veh) select { isPlayer _x };
                        if (_targets isNotEqualTo []) then {
                            [format ["Emergency repair reloaded (%1/%1).", _max]] remoteExecCall ["systemChat", _targets];
                        };
                    };
                };
            };
            _veh setVariable ["BPD_vwing_fuelRef", _ref];
        };
    } forEach BPD_vwing_vehicles;
}, 0.1, []] call CBA_fnc_addPerFrameHandler;

if (!hasInterface) exitWith {};

BPD_arcHUD_veh = objNull;
BPD_arc_boosting = false;
BPD_arc_strainWarned = false;
BPD_arc_strainNextAlarm = 0;

BPD_arc_clientPFH = [{
    private _veh = objectParent player;
    private _enabled = missionNamespace getVariable ["AUX_885th_ARC_Enabled", true];

    if (isNull _veh || {!_enabled} || {!(_veh getVariable ["BPD_arc_registered", false])} || {!alive _veh}) exitWith {
        if (!isNull BPD_arcHUD_veh || {BPD_arcHUD_ctrls isNotEqualTo []}) then {
            [] call BPD_fnc_arcHUD_destroy;
            BPD_arcHUD_veh = objNull;
        };
        BPD_arc_boosting = false;
        BPD_arcMFD_veh = objNull; // next time aboard, the cockpit HUD boots again
    };

    if (_veh != BPD_arcHUD_veh) then {
        BPD_arcHUD_veh = _veh;
        [] call BPD_fnc_arcHUD_build;
    };

    private _max    = missionNamespace getVariable ["AUX_885th_ARC_ShieldMax", 1];
    private _shield = _veh getVariable ["BPD_arc_shield", 0];
    private _mode   = (_veh getVariable ["BPD_arc_power", 0]) min 2 max 0;
    private _broken = _veh getVariable ["BPD_arc_broken", false];
    private _repairing = _veh getVariable ["BPD_arc_repairing", false];
    private _charges = _veh getVariable ["BPD_arc_repairCharges", 0];

    // --- engine boost (pilot only, Engines mode, full throttle, airborne, not repairing) ---
    private _boost = _mode == 2
        && {!_repairing}
        && {driver _veh == player}
        && {local _veh}
        && {isEngineOn _veh}
        && {airplaneThrottle _veh >= 0.95}
        && {!isTouchingGround _veh}
        && {_shield > 0}
        && {speed _veh < (missionNamespace getVariable ["AUX_885th_ARC_BoostMaxSpeed", 950])};

    if (_boost) then {
        private _dt = diag_deltaTime min 0.1;
        private _accel = missionNamespace getVariable ["AUX_885th_ARC_BoostAccel", 12];
        private _v = velocityModelSpace _veh;
        _veh setVelocityModelSpace [_v select 0, (_v select 1) + (_accel * _dt), _v select 2];

        _shield = (_shield - ((missionNamespace getVariable ["AUX_885th_ARC_BoostDrain", 0.08]) * _max * _dt)) max 0;
        _veh setVariable ["BPD_arc_shield", _shield]; // owner loop broadcasts it

        if (_shield <= 0) then {
            [_veh, 0] call BPD_fnc_arcSetPower;
            hintSilent parseText "<t color='#ffb030'>REACTOR RESERVE DEPLETED</t><br/><t size='0.8'>Power rerouted to balanced</t>";
            _boost = false;
        };
    };
    BPD_arc_boosting = _boost;

    // --- engine strain warning (flag decided by the owner loop) ---
    private _strain = _veh getVariable ["BPD_arc_strain", false];
    if (_strain) then {
        if (!BPD_arc_strainWarned) then {
            BPD_arc_strainWarned = true;
            if (driver _veh == player) then {
                hintSilent parseText "<t color='#ff4040' size='1.2'>ENGINE STRAIN</t><br/><t size='0.8'>Damaged systems are overloading on Max Engines.<br/>Shields, fuel and damaged systems draining - reroute power.</t>";
            };
        };
        private _vol = missionNamespace getVariable ["AUX_885th_ARC_StrainAlarmVolume", 0.35];
        if (_vol > 0 && {diag_tickTime >= BPD_arc_strainNextAlarm}) then {
            BPD_arc_strainNextAlarm = diag_tickTime + 2.5;
            playSoundUI ["\ls\core\addons\sounds\vehicles\z95\alarm.ogg", _vol];
        };
    } else {
        BPD_arc_strainWarned = false;
    };

    // cockpit HUD (arc170_hud.hpp)
    [_veh, _shield, _max, _broken, _mode, _boost, _repairing, _charges, _strain] call BPD_fnc_arcMFD_update;

    // screen bar: Always / Third person only (default - the cockpit HUD covers first person) / Never
    private _screenMode = missionNamespace getVariable ["AUX_885th_ARC_ScreenHUD", 1];
    private _showScreen = switch (_screenMode) do {
        case 0: { true };
        case 2: { false };
        default { cameraView in ["EXTERNAL", "GROUP"] };
    };
    if (_showScreen != BPD_arcHUD_visible) then {
        BPD_arcHUD_visible = _showScreen;
        { _x ctrlShow _showScreen; } forEach BPD_arcHUD_ctrls;
    };
    if (_showScreen) then {
        [_shield, _max, _broken, _mode, _boost, _repairing, _charges, _strain] call BPD_fnc_arcHUD_update;
    };
}, 0, []] call CBA_fnc_addPerFrameHandler;
