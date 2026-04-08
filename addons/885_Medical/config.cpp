class CfgPatches
{
    class Clone_medical_icon
    {
        units[]={};
        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]=
        {
            "ace_medical_treatment",
            "ace_interaction",
            "ace_medical_gui"
        };
    };
};
class RscControlsGroupNoScrollbars;
class RscPicture;
class ace_medical_gui_BodyImage: RscControlsGroupNoScrollbars
{
    class controls
    {
        class Background: RscPicture
        {
            text="\885_Medical\data\body_image\background.paa";
        };
        class Head: Background
        {
            text="\885_Medical\data\body_image\head.paa";
        };
        class Torso: Background
        {
            text="\885_Medical\data\body_image\torso.paa";
        };
        class ArmLeft: Background
        {
            text="\885_Medical\data\body_image\arm_left.paa";
        };
        class ArmRight: Background
        {
            text="\885_Medical\data\body_image\arm_right.paa";
        };
        class LegLeft: Background
        {
            text="\885_Medical\data\body_image\leg_left.paa";
        };
        class LegRight: Background
        {
            text="\885_Medical\data\body_image\leg_right.paa";
        };
        class ArmLeftB: Background
        {
            text="\885_Medical\data\body_image\arm_left_b.paa";
        };
        class ArmRightB: ArmLeftB
        {
            text="\885_Medical\data\body_image\arm_right_b.paa";
        };
        class LegLeftB: ArmLeftB
        {
            text="\885_Medical\data\body_image\leg_left_b.paa";
        };
        class LegRightB: ArmLeftB
        {
            text="\885_Medical\data\body_image\leg_right_b.paa";
        };
        class ArmLeftT: Background
        {
            text="\885_Medical\data\body_image\arm_left_t.paa";
            colorText[] = {};
        };
        class ArmRightT: ArmLeftT
        {
            text="\885_Medical\data\body_image\arm_right_t.paa";
            colorText[] = {};
        };
        class LegLeftT: ArmLeftT
        {
            text="\885_Medical\data\body_image\leg_left_t.paa";
            colorText[] = {};
        };
        class LegRightT: ArmLeftT
        {
            text="\885_Medical\data\body_image\leg_right_t.paa";
            colorText[] = {};
        };
        class HeadS: Background
        {
            text="\885_Medical\data\body_image\head_s.paa";
        };
        class TorsoS: HeadS
        {
            text="\885_Medical\data\body_image\torso_s.paa";
        };
        class ArmLeftS: HeadS
        {
            text="\885_Medical\data\body_image\arm_left_s.paa";
        };
        class ArmRightS: HeadS
        {
            text="\885_Medical\data\body_image\arm_right_s.paa";
        };
        class LegLeftS: HeadS
        {
            text="\885_Medical\data\body_image\leg_left_s.paa";
        };
        class LegRightS: HeadS
        {
            text="\885_Medical\data\body_image\leg_right_s.paa";
        };
    };
};