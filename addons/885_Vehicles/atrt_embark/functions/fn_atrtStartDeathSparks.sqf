params ["_unit"];
if (isNull _unit) exitWith {};

// ---- emitter (move it higher on the body) ----
private _ps = "#particlesource" createVehicleLocal (getPosWorld _unit);
_ps attachTo [_unit, [0, 0.05, 1.35]];   // higher + slightly forward (tweak Y/Z if needed)

// ---- Sparks: brighter, bigger, more upward ----
_ps setParticleParams [
  ["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8, 0],
  "", "Billboard",
  1, 0.45,                          // lifetime (longer)
  [0,0,0],                          // position (attached)
  [0,0,2.2],                        // base velocity UP (higher)
  1, 1.1, 0.9, 0.05,                // rotation/weight/volume/rubbing
  [0.08,0.03],                      // size (bigger)
  [[1,0.75,0.25,1],[1,0.65,0.15,0]], // color (brighter orange)
  [0.2],                            // animation speed
  1, 0, "", "", _unit
];

_ps setParticleRandom [
  0.20,                             // lifetime random
  [0.08,0.08,0.05],                 // position random
  [2.8,2.8,1.8],                    // velocity random (more spray)
  0, 0.35,                          // rotation random
  [0,0,0,0], 0, 0
];

// MORE particles (smaller interval = denser)
_ps setDropInterval 0.004;

// ---- Optional: faint smoke trail to sell “sparking wreck” ----
private _smoke = "#particlesource" createVehicleLocal (getPosWorld _unit);
_smoke attachTo [_unit, [0, 0.05, 1.35]];
_smoke setParticleParams [
  ["\A3\data_f\ParticleEffects\Universal\Universal", 16, 7, 1, 0],
  "", "Billboard",
  1, 2.5,
  [0,0,0],
  [0,0,0.35],
  1, 1.2, 1, 0.1,
  [0.25,0.8,1.3],
  [[0.2,0.2,0.2,0.35],[0.2,0.2,0.2,0]],
  [1], 1, 0, "", "", _unit
];
_smoke setParticleRandom [0.4,[0.08,0.08,0.05],[0.2,0.2,0.2],0,0.2,[0,0,0,0],0,0];
_smoke setDropInterval 0.06;

// ---- Light: stronger + a bit flickery ----
private _light = "#lightpoint" createVehicleLocal (getPosWorld _unit);
_light attachTo [_unit, [0, 0.05, 1.35]];
_light setLightAmbient [1,0.6,0.2];
_light setLightColor [1,0.6,0.2];
_light setLightBrightness 1.5;
_light setLightAttenuation [0,0,0,2.5];

private _tEnd = time + 14;

while { !isNull _unit && time < _tEnd } do {
  // flicker
  _light setLightBrightness (1.0 + random 1.2);
  uiSleep 0.06;
};

deleteVehicle _ps;
deleteVehicle _smoke;
deleteVehicle _light;