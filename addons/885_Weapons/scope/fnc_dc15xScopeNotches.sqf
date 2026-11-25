/*
 * BPD_fnc_dc15xScopeNotches
 * Runs from the onLoad of 885th_RscOptics_DC15X_BF2 (the DC15X BF2-style scope overlay).
 * Shows one bezel notch per round the loaded cell holds (max 5) and dims the spent ones, plus the loaded
 * cell type (HEAVY / AM / AP / OVR / STD) above the range readout; AM tints the text and lit notches blue.
 * The whole overlay (reticle, notches, readouts) only shows while looking through the scope;
 * the display itself stays loaded while the rifle is in hand, so it is faded out otherwise.
 * The loop ends on its own when the optics display closes.
 *
 * Arguments: 0: Display <DISPLAY>
 */
params ["_display"];

[_display] spawn {
    params ["_display"];
    private _baseIdc = 1885100;
    private _maxNotches = 5;
    private _lit = "\885_Weapons\scope\data\dc15x_bf2_notch_lit_ca.paa";
    private _spent = "\885_Weapons\scope\data\dc15x_bf2_notch_spent_ca.paa";
    private _lastState = [];
    private _lastInScope = -1;
    // reticle, 5 notches, vision mode, range, ammo type, zoom
    private _rangeIdc = 1885110;
    private _ammoTypeIdc = 1885111;
    private _maxRange = 3000;
    private _allIdcs = [1885099, 1885100, 1885101, 1885102, 1885103, 1885104, 179, _rangeIdc, _ammoTypeIdc, 180];
    // Loaded cell -> [label, colour]; the colour also tints the lit ammo notches
    private _white = [1, 1, 1, 1];
    private _ammoTypes = createHashMapFromArray [
        ["885th_dc15x_heavy_cell",       ["HEAVY", _white]],
        ["885th_dc15x_am_cell",          ["AM",    [0.35, 0.7, 1, 1]]],
        ["885th_dc15xsniper_ap_cell",    ["AP",    _white]],
        ["885th_dc15xsniper_over_cell",  ["OVR",   [1, 0.6, 0.25, 1]]],
        ["885th_dc15xsniper_cell",       ["STD",   _white]]
    ];
    private _lastMag = "#";

    while {!isNull _display} do {
        private _unit = call CBA_fnc_currentUnit;

        // In the scope = optics view on the unit we control
        private _inScope = [0, 1] select (cameraView == "GUNNER" && {cameraOn == _unit});
        if (_inScope != _lastInScope) then {
            _lastInScope = _inScope;
            {
                private _ctrl = _display displayCtrl _x;
                _ctrl ctrlSetFade (1 - _inScope);
                _ctrl ctrlCommit 0;
            } forEach _allIdcs;
        };

        // Rangefinder: distance from the scope camera to the first surface (object or terrain) under the crosshair
        if (_inScope == 1) then {
            private _from = AGLToASL (positionCameraToWorld [0, 0, 0]);
            private _to = AGLToASL (positionCameraToWorld [0, 0, _maxRange]);
            private _hits = lineIntersectsSurfaces [_from, _to, _unit, vehicle _unit, true, 1, "VIEW", "FIRE"];
            private _text = if (_hits isEqualTo []) then {"----"} else {
                str (round (_from vectorDistance ((_hits select 0) select 0)))
            };
            (_display displayCtrl _rangeIdc) ctrlSetText _text;
        };

        private _mag = currentMagazine _unit;
        private _cap = if (_mag isEqualTo "") then {0} else {
            getNumber (configFile >> "CfgMagazines" >> _mag >> "count")
        };
        _cap = _cap min _maxNotches;
        private _ammo = _unit ammo currentMuzzle _unit;

        // Ammo type readout: updates when the cell is swapped (unknown cells fall back to their short name)
        private _type = _ammoTypes getOrDefault [_mag, [
            if (_mag isEqualTo "") then {"----"} else {
                private _short = getText (configFile >> "CfgMagazines" >> _mag >> "displayNameShort");
                if ((_short select [0, 6]) == "DC15X ") then { _short = _short select [6] };
                toUpper _short
            },
            _white
        ]];
        _type params ["_typeText", "_typeColour"];
        if (_mag != _lastMag) then {
            _lastMag = _mag;
            private _ctrl = _display displayCtrl _ammoTypeIdc;
            _ctrl ctrlSetText _typeText;
            _ctrl ctrlSetTextColor ([_typeColour, [0.85, 0.87, 0.9, 0.85]] select (_typeColour isEqualTo _white));
            _lastState = [];   // re-tint the notches for the new cell
        };

        if !([_cap, _ammo] isEqualTo _lastState) then {
            _lastState = [_cap, _ammo];
            for "_i" from 0 to (_maxNotches - 1) do {
                private _ctrl = _display displayCtrl (_baseIdc + _i);
                if (_i < _cap) then {
                    private _isLit = _i < _ammo;
                    _ctrl ctrlSetText ([_spent, _lit] select _isLit);
                    _ctrl ctrlSetTextColor ([_white, _typeColour] select _isLit);
                    _ctrl ctrlSetAngle [_i * 360 / _cap, 0.5, 0.5];
                    _ctrl ctrlShow true;
                } else {
                    _ctrl ctrlShow false;
                };
            };
        };
        sleep 0.05;
    };
};
