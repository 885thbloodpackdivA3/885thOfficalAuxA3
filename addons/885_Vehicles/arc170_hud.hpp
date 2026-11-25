/*
    885th ARC-170 cockpit HUD (in-world MFD), included inside 885th_ARC170_Base.

    Built ON TOP of the 3AS HUD (Bohemia's A-149 Gryphon template) by config
    inheritance - the stock projection, bones, pitch ladder, heading tape,
    gun pipper, targeting and ILS all stay exactly as 3AS made them. This file:
      - hides the cluttered stock pieces (dive slider, G-meter, RPM gauge,
        vertical-speed boxes, radar-alt bar, grid/time line)
      - boxes speed (left) and altitude (right) with tape ticks
      - moves the weapon / ammo / countermeasure text into tidy corner blocks
      - adds the 885th layer: deflector arc, power, repair, fuel, throttle,
        boost / repair / shields-down banners and an engine-start boot screen
    The whole stock Draw is already gated on "on" (engine running), so the
    HUD appears when the engine starts; fn_arcMFD.sqf fades it in.

    HUD space is a 0..1 square, x right / y down, centre 0.5,0.5 (helmet-
    mounted, so it stays in front of the pilot's eyes). In MFD text,
    align="left" puts the text to the LEFT of pos (right-aligned) and
    align="right" puts it to the RIGHT (left-aligned). Text size comes from
    right[] (glyph width) and down[] (height) relative to pos[].

    Driven by scripts\arc170\fn_arcMFD.sqf via setUserMFDValue / setUserMFDText:
      user0-2  colour (the stock 3AS HUD already reads these)
      user3    alpha (boot fade)          user4  shield 0..1
      user5    shields down               user6  boot screen
      user7    repairing                  user8  boosting
      user9    engine strain
      text 0 power, 1 DEF %, 2 REP, 3 FUEL, 4 THR
*/

#define BPD_HIDE_LINE(N) class N { type = "line"; width = 0; points[] = {}; }
#define BPD_HIDE_TEXT(N) class N { type = "text"; source = "static"; sourceScale = 1; text = ""; align = "center"; scale = 1; pos[] = {{0,0},1}; right[] = {{0.01,0},1}; down[] = {{0,0.01},1}; }
#define BPD_HIDE_GROUP(N) class N { condition = "0"; }
// text box: anchor X,Y - glyph right edge XR - bottom YD
#define BPD_TXT(X,Y,XR,YD) pos[] = {{X,Y},1}; right[] = {{XR,Y},1}; down[] = {{X,YD},1}

class MFD: MFD
{
    class AirplaneHUD: AirplaneHUD
    {
        // Stock 3AS font ("" = the engine's default HUD font). LS Core's ls_republic was
        // tried in-game: its glyphs come out ~2x wide and rough on the canopy, even at
        // half width - unreadable. MFD fonts are per HUD layer, not per element.
        font = "";

        class Draw: Draw
        {
            // Stated here, not inherited: in-game the inherited colour came out as
            // the stock dark green instead of the user0-2 colour.
            alpha = "user3";
            color[] = {"user0", "user1", "user2"};
            condition = "(1 - (cameraHeadingDiffY<=-28) + (abs(cameraHeadingDiffX)>=37))*on";

            // ---------- stock elements kept ----------
            // The MFD reader skips INHERITED child classes, so every stock
            // element we keep is re-stated (empty body = all stock values).
            class VelocityLine: VelocityLine {};
            class HeadingNumber: HeadingNumber {};
            class HeadingScale: HeadingScale {};
            class HorizonBanking: HorizonBanking {};
            class RadarBoxes: RadarBoxes {};
            class ThrustVectoring: ThrustVectoring { class VectorigNumber: VectorigNumber {}; class VectoringArrow: VectoringArrow {}; };
            class ThrustVectoringAuto: ThrustVectoringAuto { class VectorigNumber: VectorigNumber {}; };
            class HeadingRotationArrow: HeadingRotationArrow { class HeadingArrow: HeadingArrow {}; };
            class HeadingRotation: HeadingRotation { class HeadingHeadNumber: HeadingHeadNumber {}; class HeadingArrow: HeadingArrow {}; };
            class LightsGroup: LightsGroup { class LightsText: LightsText {}; };
            class CollisionLights: CollisionLights { class CollisionLightsText: CollisionLightsText {}; };
            class WeaponsLocking: WeaponsLocking { class Text: Text {}; };
            class TargetInfo: TargetInfo
            {
                class TargetLockedText: TargetLockedText {};
                class TimeOfFlightText: TimeOfFlightText {};
                class DistanceText: DistanceText {};
                class TOF_source: TOF_source {};
                class TargetDistance: TargetDistance {};
            };
            class IncomingMissile: IncomingMissile { class Text: Text {}; };
            // stock GEAR sat at 0.5,0.889 - right on the DEF % readout; moved under KM/H
            class GearGroup: GearGroup
            {
                class GearText: GearText
                {
                    align = "center";
                    BPD_TXT(0.12,0.575,0.16,0.61);
                };
            };
            class ILS: ILS { class Glideslope: Glideslope { class ILS: ILS {}; class airport: airport {}; }; };
            // gun / rocket impact pippers
            class MGun: MGun { class Cross: Cross {}; class Circle: Circle {}; class Circle_Min_Range: Circle_Min_Range {}; class Distance: Distance {}; };
            class Rockets: Rockets { class Cross: Cross {}; class Circle: Circle {}; class Circle_Min_Range: Circle_Min_Range {}; class Distance: Distance {}; };
            class BombCrosshairGroup: BombCrosshairGroup { class BombCrosshair: BombCrosshair {}; class Distance: Distance {}; };
            class WP: WP { class WPdist: WPdist {}; class WPstatic: WPstatic {}; class WPIndex: WPIndex {}; class WP: WP {}; };
            class TargetDiamond: TargetDiamond { class shape: shape {}; };
            class TargetLocked: TargetLocked { class shape: shape {}; };

            // ---------- gun boresight cross ----------
            // Was part of the stock "Static" line (hidden below with the clutter),
            // which is why the crosshair vanished. Re-drawn on its own on the
            // WeaponAim bone (where the guns point), a little larger than stock.
            class BPD_GunCross
            {
                type = "line";
                width = 2;
                points[] =
                {
                    {"WeaponAim", 1, {-0.03,0}, 1}, {"WeaponAim", 1, {-0.01,0}, 1}, {},
                    {"WeaponAim", 1, {0.01,0}, 1},  {"WeaponAim", 1, {0.03,0}, 1},  {},
                    {"WeaponAim", 1, {0,-0.03}, 1}, {"WeaponAim", 1, {0,-0.01}, 1}, {},
                    {"WeaponAim", 1, {0,0.01}, 1},  {"WeaponAim", 1, {0,0.03}, 1},  {},
                    {"WeaponAim", 1, {-0.002,-0.002}, 1}, {"WeaponAim", 1, {0.002,-0.002}, 1}, {"WeaponAim", 1, {0.002,0.002}, 1}, {"WeaponAim", 1, {-0.002,0.002}, 1}, {"WeaponAim", 1, {-0.002,-0.002}, 1}
                };
            };

            // ---------- stock clutter, hidden ----------
            BPD_HIDE_LINE(Static);
            BPD_HIDE_TEXT(DiveNumber);
            BPD_HIDE_GROUP(VSpeedGroup);
            BPD_HIDE_GROUP(VSpeedGroupUp);
            BPD_HIDE_GROUP(VSpeedGroupDown);
            BPD_HIDE_GROUP(AltGroup);
            BPD_HIDE_TEXT(Angle_90);
            BPD_HIDE_TEXT(Angle_30);
            BPD_HIDE_TEXT(Angle_10);
            BPD_HIDE_TEXT(Angle_0);
            BPD_HIDE_TEXT(Angle_10m);
            BPD_HIDE_TEXT(Angle_30m);
            BPD_HIDE_TEXT(Angle_90m);
            BPD_HIDE_TEXT(GMeterStatic3);
            BPD_HIDE_TEXT(GMeterStatic2);
            BPD_HIDE_TEXT(GMeterStatic1);
            BPD_HIDE_TEXT(GMeterStatic0);
            BPD_HIDE_TEXT(CollectiveNumber);
            BPD_HIDE_TEXT(CollectiveText);
            BPD_HIDE_LINE(EngineRPM);
            BPD_HIDE_LINE(EngineRPMLines);
            BPD_HIDE_TEXT(RPM60Text);
            BPD_HIDE_TEXT(RPM80Text);
            BPD_HIDE_TEXT(RPM100Text);
            BPD_HIDE_TEXT(RPM120Text);
            BPD_HIDE_TEXT(CoordXNumber);
            BPD_HIDE_TEXT(CoordYNumber);
            BPD_HIDE_TEXT(Time);
            BPD_HIDE_TEXT(CoordXText);
            BPD_HIDE_TEXT(CoordYText);

            // ---------- stock pieces, repositioned ----------
            class SpeedNumber: SpeedNumber
            {
                sourceLength = 3;
                align = "left";
                BPD_TXT(0.175,0.482,0.225,0.518);
            };
            class CurrentWeapon: CurrentWeapon
            {
                align = "right";
                BPD_TXT(0.07,0.838,0.113,0.868);
            };
            class CurrentAmmo: CurrentAmmo
            {
                align = "right";
                BPD_TXT(0.07,0.872,0.113,0.902);
            };

            // ---------- 885th frame ----------
            class BPD_Frame
            {
                type = "line";
                width = 2;
                points[] =
                {
                    {{0.455,0.032},1}, {{0.545,0.032},1}, {{0.545,0.08},1}, {{0.455,0.08},1}, {{0.455,0.032},1}, {},

                    {{0.05,0.47},1}, {{0.19,0.47},1}, {{0.19,0.53},1}, {{0.05,0.53},1}, {{0.05,0.47},1}, {},
                    {{0.205,0.30},1}, {{0.205,0.70},1}, {},
                    {{0.205,0.34},1}, {{0.225,0.34},1}, {},
                    {{0.205,0.42},1}, {{0.22,0.42},1}, {},
                    {{0.19,0.50},1}, {{0.205,0.50},1}, {},
                    {{0.205,0.58},1}, {{0.22,0.58},1}, {},
                    {{0.205,0.66},1}, {{0.225,0.66},1}, {},

                    {{0.81,0.47},1}, {{0.95,0.47},1}, {{0.95,0.53},1}, {{0.81,0.53},1}, {{0.81,0.47},1}, {},
                    {{0.795,0.30},1}, {{0.795,0.70},1}, {},
                    {{0.775,0.34},1}, {{0.795,0.34},1}, {},
                    {{0.78,0.42},1}, {{0.795,0.42},1}, {},
                    {{0.795,0.50},1}, {{0.81,0.50},1}, {},
                    {{0.78,0.58},1}, {{0.795,0.58},1}, {},
                    {{0.775,0.66},1}, {{0.795,0.66},1}, {},

                    {{0.06,0.785},1}, {{0.06,0.905},1}, {},
                    {{0.94,0.785},1}, {{0.94,0.905},1}
                };
            };
            class BPD_SpeedLabel
            {
                type = "text"; source = "static"; sourceScale = 1; text = "KM/H"; align = "center"; scale = 1;
                BPD_TXT(0.12,0.538,0.155,0.563);
            };
            class BPD_AltNumber
            {
                type = "text"; source = "altitudeASL"; sourceScale = 1; align = "left"; scale = 1;
                BPD_TXT(0.935,0.482,0.985,0.518);
            };
            class BPD_AltLabel
            {
                type = "text"; source = "static"; sourceScale = 1; text = "ALT M"; align = "center"; scale = 1;
                BPD_TXT(0.88,0.538,0.915,0.563);
            };

            // ---------- deflector arc: thin track + 10 thick segments filling left -> right ----------
            class BPD_ShieldTrack
            {
                type = "line";
                width = 1;
                points[] =
                {
                    {{0.3961,0.915},1},{{0.4081,0.8979},1},{{0.4229,0.8831},1},{{0.44,0.8711},1},{{0.459,0.8622},1},{{0.4792,0.8568},1},{{0.5,0.855},1},
                    {{0.5208,0.8568},1},{{0.541,0.8622},1},{{0.56,0.8711},1},{{0.5771,0.8831},1},{{0.5919,0.8979},1},{{0.6039,0.915},1}
                };
            };
            class BPD_ShieldSeg0 { condition = "user4 - 0.05"; class Arc { type = "line"; width = 6; points[] = {{{0.3961,0.915},1},{{0.4029,0.9045},1},{{0.4108,0.8947},1}}; }; };
            class BPD_ShieldSeg1 { condition = "user4 - 0.15"; class Arc { type = "line"; width = 6; points[] = {{{0.4108,0.8947},1},{{0.4197,0.8858},1},{{0.4295,0.8779},1}}; }; };
            class BPD_ShieldSeg2 { condition = "user4 - 0.25"; class Arc { type = "line"; width = 6; points[] = {{{0.4295,0.8779},1},{{0.44,0.8711},1},{{0.4512,0.8654},1}}; }; };
            class BPD_ShieldSeg3 { condition = "user4 - 0.35"; class Arc { type = "line"; width = 6; points[] = {{{0.4512,0.8654},1},{{0.4629,0.8609},1},{{0.4751,0.8576},1}}; }; };
            class BPD_ShieldSeg4 { condition = "user4 - 0.45"; class Arc { type = "line"; width = 6; points[] = {{{0.4751,0.8576},1},{{0.4875,0.8557},1},{{0.5,0.855},1}}; }; };
            class BPD_ShieldSeg5 { condition = "user4 - 0.55"; class Arc { type = "line"; width = 6; points[] = {{{0.5,0.855},1},{{0.5125,0.8557},1},{{0.5249,0.8576},1}}; }; };
            class BPD_ShieldSeg6 { condition = "user4 - 0.65"; class Arc { type = "line"; width = 6; points[] = {{{0.5249,0.8576},1},{{0.5371,0.8609},1},{{0.5488,0.8654},1}}; }; };
            class BPD_ShieldSeg7 { condition = "user4 - 0.75"; class Arc { type = "line"; width = 6; points[] = {{{0.5488,0.8654},1},{{0.56,0.8711},1},{{0.5705,0.8779},1}}; }; };
            class BPD_ShieldSeg8 { condition = "user4 - 0.85"; class Arc { type = "line"; width = 6; points[] = {{{0.5705,0.8779},1},{{0.5803,0.8858},1},{{0.5892,0.8947},1}}; }; };
            class BPD_ShieldSeg9 { condition = "user4 - 0.95"; class Arc { type = "line"; width = 6; points[] = {{{0.5892,0.8947},1},{{0.5971,0.9045},1},{{0.6039,0.915},1}}; }; };

            class BPD_DefText
            {
                type = "text"; source = "userText"; sourceScale = 1; sourceIndex = 1; align = "center"; scale = 1;
                BPD_TXT(0.5,0.878,0.543,0.908);
            };

            // ---------- left block: power (weapon / ammo are the stock texts above) ----------
            class BPD_PowerText
            {
                type = "text"; source = "userText"; sourceScale = 1; sourceIndex = 0; align = "right"; scale = 1;
                BPD_TXT(0.07,0.792,0.113,0.822);
            };

            // ---------- right block: repair, fuel, throttle ----------
            class BPD_RepText
            {
                type = "text"; source = "userText"; sourceScale = 1; sourceIndex = 2; align = "left"; scale = 1;
                BPD_TXT(0.93,0.792,0.973,0.822);
            };
            class BPD_FuelText: BPD_RepText
            {
                sourceIndex = 3;
                BPD_TXT(0.93,0.838,0.973,0.868);
            };
            class BPD_ThrText: BPD_RepText
            {
                sourceIndex = 4;
                BPD_TXT(0.93,0.872,0.973,0.902);
            };

            // ---------- banners ----------
            class BPD_BootGroup
            {
                condition = "user6";
                class Line1 { type = "text"; source = "static"; sourceScale = 1; text = "885TH BLOODPACK DIVISION"; align = "center"; scale = 1; BPD_TXT(0.5,0.27,0.543,0.30); };
                class Line2 { type = "text"; source = "static"; sourceScale = 1; text = "ARC-170 SYSTEMS ONLINE"; align = "center"; scale = 1; BPD_TXT(0.5,0.31,0.55,0.346); };
            };
            class BPD_BoostGroup
            {
                condition = "user8";
                class Text { type = "text"; source = "static"; sourceScale = 1; text = ">> BOOST <<"; align = "center"; scale = 1; BPD_TXT(0.5,0.69,0.55,0.726); };
            };
            class BPD_RepairGroup
            {
                condition = "user7";
                blinkingPattern[] = {0.5, 0.25};
                blinkingStartsOn = 1;
                class Text { type = "text"; source = "static"; sourceScale = 1; text = "EMERGENCY REPAIR"; align = "center"; scale = 1; BPD_TXT(0.5,0.73,0.543,0.76); };
            };
            class BPD_ShieldsDownGroup
            {
                condition = "user5";
                blinkingPattern[] = {0.3, 0.3};
                blinkingStartsOn = 1;
                class Text { type = "text"; source = "static"; sourceScale = 1; text = "DEFLECTORS DOWN"; align = "center"; scale = 1; BPD_TXT(0.5,0.77,0.55,0.806); };
            };
            // Max Engines on a damaged jet (fn_arcStrain.sqf) - fast blink, above the boost line
            class BPD_StrainGroup
            {
                condition = "user9";
                blinkingPattern[] = {0.25, 0.25};
                blinkingStartsOn = 1;
                class Text { type = "text"; source = "static"; sourceScale = 1; text = "ENGINE STRAIN - REROUTE POWER"; align = "center"; scale = 1; BPD_TXT(0.5,0.645,0.55,0.681); };
            };
        };
    };

    // countermeasures moved under the right block so they don't sit on the weapon text
    class HMD_CMPilot: HMD_CMPilot
    {
        font = ""; // stock 3AS font - matches the main HUD layer

        class Draw: Draw
        {
            alpha = "user3";
            color[] = {"user0", "user1", "user2"};
            condition = "on - (cameraHeadingDiffY<=-28) + (abs(cameraHeadingDiffX)>=37)";
            class CMName: CMName
            {
                align = "left";
                BPD_TXT(0.85,0.906,0.893,0.936);
            };
            class CMCount: CMCount
            {
                align = "left";
                BPD_TXT(0.93,0.906,0.973,0.936);
            };
        };
    };
};

#undef BPD_HIDE_LINE
#undef BPD_HIDE_TEXT
#undef BPD_HIDE_GROUP
#undef BPD_TXT
