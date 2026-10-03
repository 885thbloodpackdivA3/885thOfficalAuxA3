class CfgPatches
{
    class 885th_Medical_Core
    {
        name = "885th_ACE_TCW";
        units[] = {"885th_ClothBandage_Item", "885th_BactaBandage_Item", "885th_BactaSpray_Item", "885th_BactaPatch_Item", "885th_Stim_Perigen_Item", "885th_Stim_Enkephalin_Item", "885th_Stim_Kyrprax_Item", "885th_Stim_Myocaine_Item", "885th_Stim_Reedug_Item", "885th_Injector_Myoplexaril_Item", "885th_Injector_Polybiotics_Item", "885th_Injector_Nyex_Item", "885th_Vasko250_Item", "885th_Vasko500_Item", "885th_Vasko1000_Item", "885th_BactaPack_Item", "885th_Cauterizer_Item"};
        weapons[] = {"885th_ClothBandage", "885th_BactaBandage", "885th_BactaSpray", "885th_BactaPatch", "885th_Stim_Perigen", "885th_Stim_Enkephalin", "885th_Stim_Kyrprax", "885th_Stim_Myocaine", "885th_Stim_Reedug", "885th_Injector_Myoplexaril", "885th_Injector_Polybiotics", "885th_Injector_Nyex", "885th_Vasko1000", "885th_Vasko500", "885th_Vasko250", "885th_BactaPack", "885th_Cauterizer"};
        requiredVersion = 0.1;
        requiredAddons[] = {"ace_medical_treatment", "ace_interaction", "ace_medical_gui", "ace_medical_status", "ace_medical_damage", "ace_apl"};
        authors[] = {"Krinix"};
    };
};

class CfgEditorCategories
{
    class 885th_Med
    {
        displayname = "[885th] Medical Extension";
    };
};
class CfgEditorSubcategories
{
    class 885th_Med_Assets
    {
        displayName = "[885th] Medical Assets";
    };
};
class ace_medical_treatment
{
    class Bandaging
    {
        class BasicBandage
        {
            effectiveness = 5;
            reopeningChance = 0;
            reopeningMinDelay = 0;
            reopeningMaxDelay = 0;
        };
        class FieldDressing
        {
            effectiveness = 1;
            reopeningChance = 0.10000000149011612;
            reopeningMinDelay = 120;
            reopeningMaxDelay = 200;
            class Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 200;
                reopeningMaxDelay = 1000;
            };
            class AbrasionMinor : Abrasion
            {
                effectiveness = 3;
            };
            class AbrasionMedium : Abrasion
            {
                effectiveness = 2.5;
                reopeningChance = 0.699999988079071;
            };
            class AbrasionLarge : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.8999999761581421;
            };
            class Avulsion : Abrasion
            {
                effectiveness = 1;
                reopeningChance = 0.5;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class AvulsionMinor : Avulsion
            {
                effectiveness = 1;
            };
            class AvulsionMedium : Avulsion
            {
                effectiveness = 0.8999999761581421;
            };
            class AvulsionLarge : Avulsion
            {
                effectiveness = 0.75;
            };
            class Contusion : Abrasion
            {
                effectiveness = 1;
                reopeningChance = 0;
                reopeningMinDelay = 0;
                reopeningMaxDelay = 0;
            };
            class ContusionMinor : Contusion
            {
            };
            class ContusionMedium : Contusion
            {
            };
            class ContusionLarge : Contusion
            {
            };
            class Crush : Abrasion
            {
                effectiveness = 1;
                reopeningChance = 0.20000000298023224;
                reopeningMinDelay = 200;
                reopeningMaxDelay = 1000;
            };
            class CrushMinor : Crush
            {
                effectiveness = 1;
                reopeningChance = 0.20000000298023224;
            };
            class CrushMedium : Crush
            {
                effectiveness = 0.699999988079071;
                reopeningChance = 0.30000001192092896;
            };
            class CrushLarge : Crush
            {
                effectiveness = 0.6000000238418579;
                reopeningChance = 0.4000000059604645;
            };
            class Cut : Abrasion
            {
                effectiveness = 4;
                reopeningChance = 0.10000000149011612;
                reopeningMinDelay = 300;
                reopeningMaxDelay = 1000;
            };
            class CutMinor : Cut
            {
                effectiveness = 4;
                reopeningChance = 0.10000000149011612;
            };
            class CutMedium : Cut
            {
                effectiveness = 3;
                reopeningChance = 0.30000001192092896;
            };
            class CutLarge : Cut
            {
                effectiveness = 1;
                reopeningChance = 0.5;
            };
            class Laceration : Abrasion
            {
                effectiveness = 0.949999988079071;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 100;
                reopeningMaxDelay = 800;
            };
            class LacerationMinor : Laceration
            {
                effectiveness = 0.949999988079071;
                reopeningChance = 0.30000001192092896;
            };
            class LacerationMedium : Laceration
            {
                effectiveness = 0.699999988079071;
                reopeningChance = 0.5;
            };
            class LacerationLarge : Laceration
            {
                effectiveness = 0.5;
                reopeningChance = 0.6000000238418579;
            };
            class VelocityWound : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.699999988079071;
                reopeningMinDelay = 100;
                reopeningMaxDelay = 500;
            };
            class VelocityWoundMinor : VelocityWound
            {
                effectiveness = 2;
            };
            class VelocityWoundMedium : VelocityWound
            {
                effectiveness = 1.5;
            };
            class VelocityWoundLarge : VelocityWound
            {
                effectiveness = 1;
            };
            class PunctureWound : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.5;
                reopeningMinDelay = 200;
                reopeningMaxDelay = 850;
            };
            class PunctureWoundMinor : PunctureWound
            {
                effectiveness = 2;
            };
            class PunctureWoundMedium : PunctureWound
            {
                effectiveness = 1.2999999523162842;
            };
            class PunctureWoundLarge : PunctureWound
            {
                effectiveness = 0.8999999761581421;
            };
        };
        class PackingBandage : fieldDressing
        {
            class Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.6000000238418579;
                reopeningMinDelay = 800;
                reopeningMaxDelay = 1500;
            };
            class AbrasionMinor : Abrasion
            {
                effectiveness = 3;
            };
            class AbrasionMedium : Abrasion
            {
                effectiveness = 2.5;
                reopeningChance = 0.8999999761581421;
            };
            class AbrasionLarge : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 1;
            };
            class Avulsion : Abrasion
            {
                effectiveness = 1;
                reopeningChance = 0.699999988079071;
                reopeningMinDelay = 1000;
                reopeningMaxDelay = 1600;
            };
            class AvulsionMinor : Avulsion
            {
                effectiveness = 1;
            };
            class AvulsionMedium : Avulsion
            {
                effectiveness = 0.8999999761581421;
            };
            class AvulsionLarge : Avulsion
            {
                effectiveness = 0.75;
            };
            class Contusion : Abrasion
            {
                effectiveness = 1;
                reopeningChance = 0;
                reopeningMinDelay = 0;
                reopeningMaxDelay = 0;
            };
            class ContusionMinor : Contusion
            {
            };
            class ContusionMedium : Contusion
            {
            };
            class ContusionLarge : Contusion
            {
            };
            class Crush : Abrasion
            {
                effectiveness = 1;
                reopeningChance = 0.5;
                reopeningMinDelay = 600;
                reopeningMaxDelay = 1000;
            };
            class CrushMinor : Crush
            {
                effectiveness = 1;
                reopeningChance = 0.6000000238418579;
            };
            class CrushMedium : Crush
            {
                effectiveness = 0.699999988079071;
                reopeningChance = 0.699999988079071;
            };
            class CrushLarge : Crush
            {
                effectiveness = 0.6000000238418579;
                reopeningChance = 0.800000011920929;
            };
            class Cut : Abrasion
            {
                effectiveness = 4;
                reopeningChance = 0.4000000059604645;
                reopeningMinDelay = 700;
                reopeningMaxDelay = 1000;
            };
            class CutMinor : Cut
            {
                effectiveness = 4;
                reopeningChance = 0.6000000238418579;
            };
            class CutMedium : Cut
            {
                effectiveness = 3;
                reopeningChance = 0.699999988079071;
            };
            class CutLarge : Cut
            {
                effectiveness = 1;
                reopeningChance = 0.800000011920929;
            };
            class Laceration : Abrasion
            {
                effectiveness = 0.949999988079071;
                reopeningChance = 0.6499999761581421;
                reopeningMinDelay = 500;
                reopeningMaxDelay = 2000;
            };
            class LacerationMinor : Laceration
            {
                effectiveness = 0.949999988079071;
                reopeningChance = 0.6499999761581421;
            };
            class LacerationMedium : Laceration
            {
                effectiveness = 0.699999988079071;
                reopeningChance = 0.800000011920929;
            };
            class LacerationLarge : Laceration
            {
                effectiveness = 0.5;
                reopeningChance = 0.8999999761581421;
            };
            class VelocityWound : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 1;
                reopeningMinDelay = 800;
                reopeningMaxDelay = 2000;
            };
            class VelocityWoundMinor : VelocityWound
            {
                effectiveness = 2;
            };
            class VelocityWoundMedium : VelocityWound
            {
                effectiveness = 1.5;
            };
            class VelocityWoundLarge : VelocityWound
            {
                effectiveness = 1;
            };
            class PunctureWound : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 1;
                reopeningMinDelay = 1000;
                reopeningMaxDelay = 3000;
            };
            class PunctureWoundMinor : PunctureWound
            {
                effectiveness = 2;
            };
            class PunctureWoundMedium : PunctureWound
            {
                effectiveness = 1.2999999523162842;
            };
            class PunctureWoundLarge : PunctureWound
            {
                effectiveness = 0.8999999761581421;
            };
        };
        class ElasticBandage : fieldDressing
        {
            class Abrasion
            {
                effectiveness = 4;
                reopeningChance = 0.6000000238418579;
                reopeningMinDelay = 80;
                reopeningMaxDelay = 150;
            };
            class AbrasionMinor : Abrasion
            {
                effectiveness = 4;
            };
            class AbrasionMedium : Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.8999999761581421;
            };
            class AbrasionLarge : Abrasion
            {
                effectiveness = 2.5;
                reopeningChance = 1;
            };
            class Avulsion : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.699999988079071;
                reopeningMinDelay = 100;
                reopeningMaxDelay = 160;
            };
            class AvulsionMinor : Avulsion
            {
                effectiveness = 2;
            };
            class AvulsionMedium : Avulsion
            {
                effectiveness = 1.399999976158142;
            };
            class AvulsionLarge : Avulsion
            {
                effectiveness = 1;
            };
            class Contusion : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0;
                reopeningMinDelay = 0;
                reopeningMaxDelay = 0;
            };
            class ContusionMinor : Contusion
            {
            };
            class ContusionMedium : Contusion
            {
            };
            class ContusionLarge : Contusion
            {
            };
            class Crush : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.5;
                reopeningMinDelay = 60;
                reopeningMaxDelay = 100;
            };
            class CrushMinor : Crush
            {
                effectiveness = 2;
                reopeningChance = 0.6000000238418579;
            };
            class CrushMedium : Crush
            {
                effectiveness = 1.7000000476837158;
                reopeningChance = 0.699999988079071;
            };
            class CrushLarge : Crush
            {
                effectiveness = 1.600000023841858;
                reopeningChance = 0.800000011920929;
            };
            class Cut : Abrasion
            {
                effectiveness = 5;
                reopeningChance = 0.4000000059604645;
                reopeningMinDelay = 70;
                reopeningMaxDelay = 100;
            };
            class CutMinor : Cut
            {
                effectiveness = 5;
                reopeningChance = 0.6000000238418579;
            };
            class CutMedium : Cut
            {
                effectiveness = 3.5;
                reopeningChance = 0.699999988079071;
            };
            class CutLarge : Cut
            {
                effectiveness = 2;
                reopeningChance = 0.800000011920929;
            };
            class Laceration : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.6499999761581421;
                reopeningMinDelay = 50;
                reopeningMaxDelay = 200;
            };
            class LacerationMinor : Laceration
            {
                effectiveness = 2;
                reopeningChance = 0.6499999761581421;
            };
            class LacerationMedium : Laceration
            {
                effectiveness = 1.5;
                reopeningChance = 0.800000011920929;
            };
            class LacerationLarge : Laceration
            {
                effectiveness = 1;
                reopeningChance = 0.8999999761581421;
            };
            class VelocityWound : Abrasion
            {
                effectiveness = 2.200000047683716;
                reopeningChance = 1;
                reopeningMinDelay = 80;
                reopeningMaxDelay = 200;
            };
            class VelocityWoundMinor : VelocityWound
            {
                effectiveness = 2.200000047683716;
            };
            class VelocityWoundMedium : VelocityWound
            {
                effectiveness = 1.75;
            };
            class VelocityWoundLarge : VelocityWound
            {
                effectiveness = 1.5;
            };
            class PunctureWound : Abrasion
            {
                effectiveness = 2.5;
                reopeningChance = 1;
                reopeningMinDelay = 100;
                reopeningMaxDelay = 300;
            };
            class PunctureWoundMinor : PunctureWound
            {
                effectiveness = 2.5;
            };
            class PunctureWoundMedium : PunctureWound
            {
                effectiveness = 2;
            };
            class PunctureWoundLarge : PunctureWound
            {
                effectiveness = 1.5;
            };
        };
        class QuikClot : fieldDressing
        {
            class Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 800;
                reopeningMaxDelay = 1500;
            };
            class AbrasionMinor : Abrasion
            {
                effectiveness = 2;
            };
            class AbrasionMedium : Abrasion
            {
                effectiveness = 1;
                reopeningChance = 0.4000000059604645;
            };
            class AbrasionLarge : Abrasion
            {
                effectiveness = 0.699999988079071;
                reopeningChance = 0.5;
            };
            class Avulsion : Abrasion
            {
                effectiveness = 0.699999988079071;
                reopeningChance = 0.20000000298023224;
                reopeningMinDelay = 1000;
                reopeningMaxDelay = 1600;
            };
            class AvulsionMinor : Avulsion
            {
                effectiveness = 0.699999988079071;
            };
            class AvulsionMedium : Avulsion
            {
                effectiveness = 0.6499999761581421;
            };
            class AvulsionLarge : Avulsion
            {
                effectiveness = 0.5;
            };
            class Contusion : Abrasion
            {
                effectiveness = 1;
                reopeningChance = 0;
                reopeningMinDelay = 0;
                reopeningMaxDelay = 0;
            };
            class ContusionMinor : Contusion
            {
            };
            class ContusionMedium : Contusion
            {
            };
            class ContusionLarge : Contusion
            {
            };
            class Crush : Abrasion
            {
                effectiveness = 0.6000000238418579;
                reopeningChance = 0.5;
                reopeningMinDelay = 600;
                reopeningMaxDelay = 1000;
            };
            class CrushMinor : Crush
            {
                effectiveness = 0.6000000238418579;
                reopeningChance = 0.30000001192092896;
            };
            class CrushMedium : Crush
            {
                effectiveness = 0.5;
            };
            class CrushLarge : Crush
            {
                effectiveness = 0.4000000059604645;
            };
            class Cut : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.20000000298023224;
                reopeningMinDelay = 700;
                reopeningMaxDelay = 1000;
            };
            class CutMinor : Cut
            {
                effectiveness = 2;
            };
            class CutMedium : Cut
            {
                effectiveness = 1;
            };
            class CutLarge : Cut
            {
                effectiveness = 0.6000000238418579;
            };
            class Laceration : Abrasion
            {
                effectiveness = 0.699999988079071;
                reopeningChance = 0.4000000059604645;
                reopeningMinDelay = 500;
                reopeningMaxDelay = 2000;
            };
            class LacerationMinor : Laceration
            {
                effectiveness = 0.699999988079071;
                reopeningChance = 0.4000000059604645;
            };
            class LacerationMedium : Laceration
            {
                effectiveness = 0.699999988079071;
            };
            class LacerationLarge : Laceration
            {
                effectiveness = 0.5;
            };
            class VelocityWound : Abrasion
            {
                effectiveness = 1;
                reopeningChance = 0.5;
                reopeningMinDelay = 800;
                reopeningMaxDelay = 2000;
            };
            class VelocityWoundMinor : VelocityWound
            {
                effectiveness = 1;
            };
            class VelocityWoundMedium : VelocityWound
            {
                effectiveness = 0.75;
            };
            class VelocityWoundLarge : VelocityWound
            {
                effectiveness = 0.5;
            };
            class PunctureWound : Abrasion
            {
                effectiveness = 1;
                reopeningChance = 0.5;
                reopeningMinDelay = 1000;
                reopeningMaxDelay = 3000;
            };
            class PunctureWoundMinor : PunctureWound
            {
                effectiveness = 1;
            };
            class PunctureWoundMedium : PunctureWound
            {
                effectiveness = 0.699999988079071;
            };
            class PunctureWoundLarge : PunctureWound
            {
                effectiveness = 0.4000000059604645;
            };
        };
        class ClothBandage : FieldDressing
        {
            class Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class AbrasionMinor : Abrasion
            {
                effectiveness = 3.5;
                reopeningChance = 0.15000000596046448;
            };
            class AbrasionMedium : Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.30000001192092896;
            };
            class AbrasionLarge : Abrasion
            {
                effectiveness = 2.5;
                reopeningChance = 0.44999998807907104;
            };
            class Avulsion : Abrasion
            {
                effectiveness = 5;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class AvulsionMinor : Avulsion
            {
                effectiveness = 6;
            };
            class AvulsionMedium : Avulsion
            {
                effectiveness = 5;
            };
            class AvulsionLarge : Avulsion
            {
                effectiveness = 4;
            };
            class Contusion : Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0;
                reopeningMinDelay = 0;
                reopeningMaxDelay = 0;
            };
            class ContusionMinor : Contusion
            {
            };
            class ContusionMedium : Contusion
            {
            };
            class ContusionLarge : Contusion
            {
            };
            class Crush : Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class CrushMinor : Crush
            {
                effectiveness = 3.5;
                reopeningChance = 0.15000000596046448;
            };
            class CrushMedium : Crush
            {
                effectiveness = 3;
                reopeningChance = 0.30000001192092896;
            };
            class CrushLarge : Crush
            {
                effectiveness = 2.5;
                reopeningChance = 0.44999998807907104;
            };
            class Cut : Abrasion
            {
                effectiveness = 5;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class CutMinor : Cut
            {
                effectiveness = 6;
                reopeningChance = 0.15000000596046448;
            };
            class CutMedium : Cut
            {
                effectiveness = 5;
                reopeningChance = 0.30000001192092896;
            };
            class CutLarge : Cut
            {
                effectiveness = 4.5;
                reopeningChance = 0.44999998807907104;
            };
            class Laceration : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class LacerationMinor : Laceration
            {
                effectiveness = 2;
                reopeningChance = 0.15000000596046448;
            };
            class LacerationMedium : Laceration
            {
                effectiveness = 1.5;
                reopeningChance = 0.30000001192092896;
            };
            class LacerationLarge : Laceration
            {
                effectiveness = 1;
                reopeningChance = 0.44999998807907104;
            };
            class VelocityWound : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 100;
                reopeningMaxDelay = 200;
            };
            class VelocityWoundMinor : VelocityWound
            {
                effectiveness = 2;
                reopeningChance = 0.15000000596046448;
            };
            class VelocityWoundMedium : VelocityWound
            {
                effectiveness = 1.5;
                reopeningChance = 0.30000001192092896;
            };
            class VelocityWoundLarge : VelocityWound
            {
                effectiveness = 1;
                reopeningChance = 0.44999998807907104;
            };
            class PunctureWound : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 100;
                reopeningMaxDelay = 300;
            };
            class PunctureWoundMinor : PunctureWound
            {
                effectiveness = 2;
                reopeningChance = 0.15000000596046448;
            };
            class PunctureWoundMedium : PunctureWound
            {
                effectiveness = 1.5;
                reopeningChance = 0.30000001192092896;
            };
            class PunctureWoundLarge : PunctureWound
            {
                effectiveness = 1;
                reopeningChance = 0.44999998807907104;
            };
        };
        class BactaBandage : FieldDressing
        {
            class Abrasion
            {
                effectiveness = 5;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class AbrasionMinor : Abrasion
            {
                effectiveness = 6;
                reopeningChance = 0.15000000596046448;
            };
            class AbrasionMedium : Abrasion
            {
                effectiveness = 5;
                reopeningChance = 0.30000001192092896;
            };
            class AbrasionLarge : Abrasion
            {
                effectiveness = 4.5;
                reopeningChance = 0.44999998807907104;
            };
            class Avulsion : Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class AvulsionMinor : Avulsion
            {
                effectiveness = 3.5;
                reopeningChance = 0.15000000596046448;
            };
            class AvulsionMedium : Avulsion
            {
                effectiveness = 3;
                reopeningChance = 0.30000001192092896;
            };
            class AvulsionLarge : Avulsion
            {
                effectiveness = 2.5;
                reopeningChance = 0.44999998807907104;
            };
            class Contusion : Abrasion
            {
                effectiveness = 5;
                reopeningChance = 0;
                reopeningMinDelay = 0;
                reopeningMaxDelay = 0;
            };
            class ContusionMinor : Contusion
            {
            };
            class ContusionMedium : Contusion
            {
            };
            class ContusionLarge : Contusion
            {
            };
            class Crush : Abrasion
            {
                effectiveness = 5;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class CrushMinor : Crush
            {
                effectiveness = 6;
                reopeningChance = 0.15000000596046448;
            };
            class CrushMedium : Crush
            {
                effectiveness = 5;
                reopeningChance = 0.30000001192092896;
            };
            class CrushLarge : Crush
            {
                effectiveness = 4.5;
                reopeningChance = 0.44999998807907104;
            };
            class Cut : Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class CutMinor : Cut
            {
                effectiveness = 3.5;
                reopeningChance = 0.15000000596046448;
            };
            class CutMedium : Cut
            {
                effectiveness = 3;
                reopeningChance = 0.30000001192092896;
            };
            class CutLarge : Cut
            {
                effectiveness = 2.5;
                reopeningChance = 0.44999998807907104;
            };
            class Laceration : Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.3499999940395355;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class LacerationMinor : Laceration
            {
                effectiveness = 3.5;
                reopeningChance = 0.15000000596046448;
            };
            class LacerationMedium : Laceration
            {
                effectiveness = 3;
                reopeningChance = 0.30000001192092896;
            };
            class LacerationLarge : Laceration
            {
                effectiveness = 2.5;
                reopeningChance = 0.44999998807907104;
            };
            class VelocityWound : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 100;
                reopeningMaxDelay = 200;
            };
            class VelocityWoundMinor : VelocityWound
            {
                effectiveness = 2;
                reopeningChance = 0.15000000596046448;
            };
            class VelocityWoundMedium : VelocityWound
            {
                effectiveness = 1.5;
                reopeningChance = 0.30000001192092896;
            };
            class VelocityWoundLarge : VelocityWound
            {
                effectiveness = 1;
                reopeningChance = 0.44999998807907104;
            };
            class PunctureWound : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 100;
                reopeningMaxDelay = 300;
            };
            class PunctureWoundMinor : PunctureWound
            {
                effectiveness = 2;
                reopeningChance = 0.15000000596046448;
            };
            class PunctureWoundMedium : PunctureWound
            {
                effectiveness = 1.5;
                reopeningChance = 0.30000001192092896;
            };
            class PunctureWoundLarge : PunctureWound
            {
                effectiveness = 1;
                reopeningChance = 0.44999998807907104;
            };
        };
        class BactaPatch : FieldDressing
        {
            class Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.5;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class AbrasionMinor : Abrasion
            {
                effectiveness = 3.5;
                reopeningChance = 0.3499999940395355;
            };
            class AbrasionMedium : Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.5;
            };
            class AbrasionLarge : Abrasion
            {
                effectiveness = 2.5;
                reopeningChance = 0.6499999761581421;
            };
            class Avulsion : Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.5;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class AvulsionMinor : Avulsion
            {
                effectiveness = 3.5;
                reopeningChance = 0.3499999940395355;
            };
            class AvulsionMedium : Avulsion
            {
                effectiveness = 3;
                reopeningChance = 0.5;
            };
            class AvulsionLarge : Avulsion
            {
                effectiveness = 2.5;
                reopeningChance = 0.6499999761581421;
            };
            class Contusion : Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0;
                reopeningMinDelay = 0;
                reopeningMaxDelay = 0;
            };
            class ContusionMinor : Contusion
            {
            };
            class ContusionMedium : Contusion
            {
            };
            class ContusionLarge : Contusion
            {
            };
            class Crush : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.5;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class CrushMinor : Crush
            {
                effectiveness = 2;
                reopeningChance = 0.3499999940395355;
            };
            class CrushMedium : Crush
            {
                effectiveness = 1.5;
                reopeningChance = 0.5;
            };
            class CrushLarge : Crush
            {
                effectiveness = 1;
                reopeningChance = 0.6499999761581421;
            };
            class Cut : Abrasion
            {
                effectiveness = 5;
                reopeningChance = 0.30000001192092896;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class CutMinor : Cut
            {
                effectiveness = 6;
                reopeningChance = 0.3499999940395355;
            };
            class CutMedium : Cut
            {
                effectiveness = 5;
                reopeningChance = 0.5;
            };
            class CutLarge : Cut
            {
                effectiveness = 4.5;
                reopeningChance = 0.6499999761581421;
            };
            class Laceration : Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.5;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class LacerationMinor : Laceration
            {
                effectiveness = 3.5;
                reopeningChance = 0.3499999940395355;
            };
            class LacerationMedium : Laceration
            {
                effectiveness = 3;
                reopeningChance = 0.5;
            };
            class LacerationLarge : Laceration
            {
                effectiveness = 2.5;
                reopeningChance = 0.6499999761581421;
            };
            class VelocityWound : Abrasion
            {
                effectiveness = 5;
                reopeningChance = 0.5;
                reopeningMinDelay = 100;
                reopeningMaxDelay = 200;
            };
            class VelocityWoundMinor : VelocityWound
            {
                effectiveness = 6;
                reopeningChance = 0.3499999940395355;
            };
            class VelocityWoundMedium : VelocityWound
            {
                effectiveness = 5;
                reopeningChance = 0.5;
            };
            class VelocityWoundLarge : VelocityWound
            {
                effectiveness = 4.5;
                reopeningChance = 0.6499999761581421;
            };
            class PunctureWound : Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.5;
                reopeningMinDelay = 100;
                reopeningMaxDelay = 300;
            };
            class PunctureWoundMinor : PunctureWound
            {
                effectiveness = 3.5;
                reopeningChance = 0.3499999940395355;
            };
            class PunctureWoundMedium : PunctureWound
            {
                effectiveness = 3;
                reopeningChance = 0.5;
            };
            class PunctureWoundLarge : PunctureWound
            {
                effectiveness = 2.5;
                reopeningChance = 0.6499999761581421;
            };
        };
        class BactaSpray : FieldDressing
        {
            class Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.25;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class AbrasionMinor : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.10000000149011612;
            };
            class AbrasionMedium : Abrasion
            {
                effectiveness = 1.5;
                reopeningChance = 0.25;
            };
            class AbrasionLarge : Abrasion
            {
                effectiveness = 1;
                reopeningChance = 0.4000000059604645;
            };
            class Avulsion : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.25;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class AvulsionMinor : Avulsion
            {
                effectiveness = 2;
                reopeningChance = 0.10000000149011612;
            };
            class AvulsionMedium : Avulsion
            {
                effectiveness = 1.5;
                reopeningChance = 0.25;
            };
            class AvulsionLarge : Avulsion
            {
                effectiveness = 1;
                reopeningChance = 0.4000000059604645;
            };
            class Contusion : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0;
                reopeningMinDelay = 0;
                reopeningMaxDelay = 0;
            };
            class ContusionMinor : Contusion
            {
            };
            class ContusionMedium : Contusion
            {
            };
            class ContusionLarge : Contusion
            {
            };
            class Crush : Abrasion
            {
                effectiveness = 2;
                reopeningChance = 0.25;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class CrushMinor : Crush
            {
                effectiveness = 2;
                reopeningChance = 0.10000000149011612;
            };
            class CrushMedium : Crush
            {
                effectiveness = 1.5;
                reopeningChance = 0.25;
            };
            class CrushLarge : Crush
            {
                effectiveness = 1;
                reopeningChance = 0.4000000059604645;
            };
            class Cut : Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.25;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class CutMinor : Cut
            {
                effectiveness = 3.5;
                reopeningChance = 0.10000000149011612;
            };
            class CutMedium : Cut
            {
                effectiveness = 3;
                reopeningChance = 0.25;
            };
            class CutLarge : Cut
            {
                effectiveness = 2.5;
                reopeningChance = 0.4000000059604645;
            };
            class Laceration : Abrasion
            {
                effectiveness = 5;
                reopeningChance = 0.25;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;
            };
            class LacerationMinor : Laceration
            {
                effectiveness = 6;
                reopeningChance = 0.10000000149011612;
            };
            class LacerationMedium : Laceration
            {
                effectiveness = 5;
                reopeningChance = 0.25;
            };
            class LacerationLarge : Laceration
            {
                effectiveness = 4.5;
                reopeningChance = 0.4000000059604645;
            };
            class VelocityWound : Abrasion
            {
                effectiveness = 3;
                reopeningChance = 0.25;
                reopeningMinDelay = 100;
                reopeningMaxDelay = 200;
            };
            class VelocityWoundMinor : VelocityWound
            {
                effectiveness = 3.5;
                reopeningChance = 0.10000000149011612;
            };
            class VelocityWoundMedium : VelocityWound
            {
                effectiveness = 3;
                reopeningChance = 0.25;
            };
            class VelocityWoundLarge : VelocityWound
            {
                effectiveness = 2.5;
                reopeningChance = 0.4000000059604645;
            };
            class PunctureWound : Abrasion
            {
                effectiveness = 5;
                reopeningChance = 0.25;
                reopeningMinDelay = 100;
                reopeningMaxDelay = 300;
            };
            class PunctureWoundMinor : PunctureWound
            {
                effectiveness = 6;
                reopeningChance = 0.10000000149011612;
            };
            class PunctureWoundMedium : PunctureWound
            {
                effectiveness = 5;
                reopeningChance = 0.25;
            };
            class PunctureWoundLarge : PunctureWound
            {
                effectiveness = 4.5;
                reopeningChance = 0.4000000059604645;
            };
        };
    };
    class Medication
    {
        painReduce = 0;
        hrIncreaseLow[] = {0, 0};
        hrIncreaseNormal[] = {0, 0};
        hrIncreaseHigh[] = {0, 0};
        timeInSystem = 120;
        timeTillMaxEffect = 30;
        maxDose = 4;
        onOverDose = "";
        viscosityChange = 0;
        class Morphine
        {
            painReduce = 0.800000011920929;
            hrIncreaseLow[] = {-10, -20};
            hrIncreaseNormal[] = {-10, -30};
            hrIncreaseHigh[] = {-10, -35};
            timeInSystem = 1800;
            timeTillMaxEffect = 30;
            maxDose = 4;
            incompatibleMedication[] = {};
            viscosityChange = -10;
        };
        class Epinephrine
        {
            painReduce = 0;
            hrIncreaseLow[] = {10, 20};
            hrIncreaseNormal[] = {10, 50};
            hrIncreaseHigh[] = {10, 40};
            timeInSystem = 120;
            timeTillMaxEffect = 10;
            maxDose = 10;
            incompatibleMedication[] = {};
        };
        class Adenosine
        {
            painReduce = 0;
            hrIncreaseLow[] = {-7, -10};
            hrIncreaseNormal[] = {-15, -30};
            hrIncreaseHigh[] = {-15, -35};
            timeInSystem = 120;
            timeTillMaxEffect = 15;
            maxDose = 6;
            incompatibleMedication[] = {};
        };
        class PainKillers
        {
            painReduce = 0.10000000149011612;
            timeInSystem = 600;
            timeTillMaxEffect = 60;
            maxDose = 10;
            incompatibleMedication[] = {};
            viscosityChange = 5;
        };
        class Perigen
        {
            painReduce = 0.8500000238418579;
            hrIncreaseLow[] = {0, 0};
            hrIncreaseNormal[] = {0, 0};
            hrIncreaseHigh[] = {0, 0};
            timeInSystem = 300;
            timeTillMaxEffect = 30;
            maxDose = 10;
            incompatibleMedication[] = {};
            viscosityChange = 5;
        };
        class Enkephalin
        {
            painReduce = 0.6499999761581421;
            hrIncreaseLow[] = {-10, -15};
            hrIncreaseNormal[] = {-10, -20};
            hrIncreaseHigh[] = {-10, -25};
            timeInSystem = 300;
            timeTillMaxEffect = 20;
            maxDose = 4;
            incompatibleMedication[] = {};
        };
        class Nyex
        {
            painReduce = 1;
            hrIncreaseLow[] = {-10, -25};
            hrIncreaseNormal[] = {-10, -30};
            hrIncreaseHigh[] = {-10, -35};
            timeInSystem = 600;
            timeTillMaxEffect = 10;
            maxDose = 2;
            incompatibleMedication[] = {};
        };
        class Kyrprax
        {
            painReduce = 0;
            hrIncreaseLow[] = {10, 30};
            hrIncreaseNormal[] = {10, 35};
            hrIncreaseHigh[] = {10, 40};
            timeInSystem = 300;
            timeTillMaxEffect = 20;
            maxDose = 4;
            incompatibleMedication[] = {};
        };
        class Polybiotics
        {
            painReduce = 0;
            hrIncreaseLow[] = {10, 40};
            hrIncreaseNormal[] = {10, 55};
            hrIncreaseHigh[] = {10, 45};
            timeInSystem = 600;
            timeTillMaxEffect = 10;
            maxDose = 2;
            incompatibleMedication[] = {};
        };
        class Myocaine
        {
            painReduce = 0;
            hrIncreaseLow[] = {-10, -20};
            hrIncreaseNormal[] = {-15, -30};
            hrIncreaseHigh[] = {-15, -35};
            timeInSystem = 300;
            timeTillMaxEffect = 20;
            maxDose = 4;
            incompatibleMedication[] = {};
        };
        class Myoplexaril
        {
            painReduce = 0;
            hrIncreaseLow[] = {-15, -30};
            hrIncreaseNormal[] = {-15, -35};
            hrIncreaseHigh[] = {-15, -40};
            timeInSystem = 600;
            timeTillMaxEffect = 10;
            maxDose = 2;
            incompatibleMedication[] = {};
        };
        class Reedug
        {
            painReduce = 1;
            hrIncreaseLow[] = {-40, -50};
            hrIncreaseNormal[] = {-50, -70};
            hrIncreaseHigh[] = {-80, -90};
            timeInSystem = 300;
            timeTillMaxEffect = 10;
            maxDose = 5;
            incompatibleMedication[] = {};
        };
    };
    class IV
    {
        volume = 1000;
        ratio[] = {};
        type = "Blood";
        class BloodIV
        {
            volume = 1000;
            ratio[] = {"Plasma", 1};
        };
        class BloodIV_500 : BloodIV
        {
            volume = 500;
        };
        class BloodIV_250 : BloodIV
        {
            volume = 250;
        };
        class PlasmaIV : BloodIV
        {
            volume = 1000;
            ratio[] = {"Blood", 1};
            type = "Plasma";
        };
        class PlasmaIV_500 : PlasmaIV
        {
            volume = 500;
        };
        class PlasmaIV_250 : PlasmaIV
        {
            volume = 250;
        };
        class SalineIV : BloodIV
        {
            volume = 1000;
            type = "Saline";
            ratio[] = {};
        };
        class SalineIV_500 : SalineIV
        {
            volume = 500;
        };
        class SalineIV_250 : SalineIV
        {
            volume = 250;
        };
        class Vasko_1000 : BloodIV
        {
            volume = 1000;
            ratio[] = {"Blood", 1};
            type = "Plasma";
        };
        class Vasko_500 : Vasko_1000
        {
            volume = 500;
        };
        class Vasko_250 : Vasko_1000
        {
            volume = 250;
        };
    };
};
class ace_medical_treatment_actions
{
    class BasicBandage;
    class Morphine;
    class BloodIV;
    class SurgicalKit;
    class PersonalAidKit;
    class ClothBandage : BasicBandage
    {
        displayName = "$STR_885th_Medical_Display_ClothBandage";
        displayNameProgress = "$STR_885th_Medical_Using_Bandage";
        items[] = {"885th_ClothBandage"};
        litter[] = {};
    };
    class BactaBandage : BasicBandage
    {
        displayName = "$STR_885th_Medical_Display_BactaBandage";
        displayNameProgress = "$STR_885th_Medical_Using_Bandage";
        items[] = {"885th_BactaBandage"};
        litter[] = {};
    };
    class BactaSpray : BasicBandage
    {
        displayName = "$STR_885th_Medical_Display_BactaSpray";
        displayNameProgress = "$STR_885th_Medical_Using_BactaSpray";
        items[] = {"885th_BactaSpray"};
        litter[] = {};
    };
    class BactaPatch : BasicBandage
    {
        displayName = "$STR_885th_Medical_Display_BactaPatch";
        displayNameProgress = "$STR_885th_Medical_Using_BactaPatch";
        items[] = {"885th_BactaPatch"};
        litter[] = {};
    };
    class Perigen : Morphine
    {
        displayName = "$STR_885th_Medical_Display_Stim_Perigen";
        displayNameProgress = "$STR_885th_Medical_Using_Perigen";
        items[] = {"885th_Stim_Perigen"};
        litter[] = {};
    };
    class Enkephalin : Morphine
    {
        displayName = "$STR_885th_Medical_Display_Stim_Enkephalin";
        displayNameProgress = "$STR_885th_Medical_Using_Enkephalin";
        items[] = {"885th_Stim_Enkephalin"};
        litter[] = {};
    };
    class Nyex : Morphine
    {
        displayName = "$STR_885th_Medical_Display_Injector_Nyex";
        displayNameProgress = "$STR_885th_Medical_Using_Nyex";
        items[] = {"885th_Injector_Nyex"};
        litter[] = {};
    };
    class Kyrprax : Morphine
    {
        displayName = "$STR_885th_Medical_Display_Stim_Kyrprax";
        displayNameProgress = "$STR_885th_Medical_Using_Kyrprax";
        medicRequired = "ace_medical_treatment_medicEpinephrine";
        items[] = {"885th_Stim_Kyrprax"};
        treatmentLocations = "ace_medical_treatment_locationEpinephrine";
        litter[] = {};
    };
    class Polybiotics : Morphine
    {
        displayName = "$STR_885th_Medical_Display_Injector_Polybiotics";
        displayNameProgress = "$STR_885th_Medical_Using_Polybiotics";
        medicRequired = "ace_medical_treatment_medicEpinephrine";
        items[] = {"885th_Injector_Polybiotics"};
        treatmentLocations = "ace_medical_treatment_locationEpinephrine";
        litter[] = {};
    };
    class Myocaine : Morphine
    {
        displayName = "$STR_885th_Medical_Display_Stim_Myocaine";
        displayNameProgress = "$STR_885th_Medical_Using_Myocaine";
        condition = "ace_medical_treatment_advancedMedication";
        items[] = {"885th_Stim_Myocaine"};
        litter[] = {};
    };
    class Myoplexaril : Morphine
    {
        displayName = "$STR_885th_Medical_Display_Injector_Myoplexaril";
        displayNameProgress = "$STR_885th_Medical_Using_Myoplexaril";
        condition = "ace_medical_treatment_advancedMedication";
        items[] = {"885th_Injector_Myoplexaril"};
        litter[] = {};
    };
    class Reedug : Morphine
    {
        displayName = "$STR_885th_Medical_Display_Stim_Reedug";
        displayNameProgress = "$STR_885th_Medical_Using_Reedug";
        condition = "ace_medical_treatment_advancedMedication";
        items[] = {"885th_Stim_Reedug"};
        litter[] = {};
    };
    class Vasko_1000 : BloodIV
    {
        displayName = "$STR_885th_Medical_Display_Vasko1000";
        displayNameProgress = "$STR_885th_Medical_Using_Vasko";
        items[] = {"885th_Vasko1000"};
        animationMedic = "AinvPknlMstpSnonWnonDnon_medic1";
    };
    class Vasko_500 : Vasko_1000
    {
        displayName = "$STR_885th_Medical_Display_Vasko500";
        items[] = {"885th_Vasko500"};
    };
    class Vasko_250 : Vasko_1000
    {
        displayName = "$STR_885th_Medical_Display_Vasko250";
        items[] = {"885th_Vasko250"};
    };
    class Cauterizer : SurgicalKit
    {
        displayName = "$STR_885th_Medical_Display_Cauterizer";
        displayNameProgress = "$STR_885th_Medical_Using_Cauterizer";
        items[] = {"885th_Cauterizer"};
        litter[] = {};
    };
    class BactaPack : PersonalAidKit
    {
        displayName = "$STR_885th_Medical_Display_BactaPack";
        displayNameProgress = "$STR_885th_Medical_Using_BactaPack";
        items[] = {"885th_BactaPack"};
        litter[] = {};
    };
};
class CBA_Extended_EventHandlers;
class CfgVehicles
{
    class MapBoard_altis_F;
    class Item_Base_F;
    class 885th_ClothBandage_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_ClothBandage";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\BandageCloth.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_ClothBandage
            {
                name = "885th_ClothBandage";
                count = 1;
            };
        };
    };
    class 885th_BactaBandage_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_BactaBandage";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\BandageBacta.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_BactaBandage
            {
                name = "885th_BactaBandage";
                count = 1;
            };
        };
    };
    class 885th_BactaSpray_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_BactaSpray";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\BactaSpray.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_BactaSpray
            {
                name = "885th_BactaSpray";
                count = 1;
            };
        };
    };
    class 885th_BactaPatch_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_BactaPatch";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\BactaPatch.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_BactaPatch
            {
                name = "885th_BactaPatch";
                count = 1;
            };
        };
    };
    class 885th_Stim_Perigen_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_Stim_Perigen";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\StimGreen.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_Stim_Perigen
            {
                name = "885th_Stim_Perigen";
                count = 1;
            };
        };
    };
    class 885th_Stim_Enkephalin_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_Stim_Enkephalin";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\StimRed.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_Stim_Enkephalin
            {
                name = "885th_Stim_Enkephalin";
                count = 1;
            };
        };
    };
    class 885th_Stim_Kyrprax_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_Stim_Kyrprax";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\StimYellow.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_Stim_Kyrprax
            {
                name = "885th_Stim_Kyrprax";
                count = 1;
            };
        };
    };
    class 885th_Stim_Myocaine_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_Stim_Myocaine";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\StimBlue.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_Stim_Myocaine
            {
                name = "885th_Stim_Myocaine";
                count = 1;
            };
        };
    };
    class 885th_Stim_Reedug_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_Stim_Reedug";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\StimBlack.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_Stim_Reedug
            {
                name = "885th_Stim_Reedug";
                count = 1;
            };
        };
    };
    class 885th_Injector_Myoplexaril_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_Injector_Myoplexaril";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\InjectorBlue.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_Injector_Myoplexaril
            {
                name = "885th_Injector_Myoplexaril";
                count = 1;
            };
        };
    };
    class 885th_Injector_Polybiotics_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_Injector_Polybiotics";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\InjectorYellow.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_Injector_Polybiotics
            {
                name = "885th_Injector_Polybiotics";
                count = 1;
            };
        };
    };
    class 885th_Injector_Nyex_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_Injector_Nyex";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\InjectorRed.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_Injector_Nyex
            {
                name = "885th_Injector_Nyex";
                count = 1;
            };
        };
    };
    class 885th_Vasko250_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_Vasko250";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\Vasko250ml.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_Vasko250
            {
                name = "885th_Vasko250";
                count = 1;
            };
        };
    };
    class 885th_Vasko500_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_Vasko500";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\Vasko500ml.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_Vasko500
            {
                name = "885th_Vasko500";
                count = 1;
            };
        };
    };
    class 885th_Vasko1000_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_Vasko1000";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\Vasko1000ml.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_Vasko1000
            {
                name = "885th_Vasko1000";
                count = 1;
            };
        };
    };
    class 885th_BactaPack_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_BactaPack";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\BactaCanister.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_BactaPack
            {
                name = "885th_BactaPack";
                count = 1;
            };
        };
    };
    class 885th_Cauterizer_Item : Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        editorcategory = "885th_Med";
        editorsubcategory = "885th_Med_Assets";
        displayName = "$STR_885th_Medical_Display_Cauterizer";
        author = "Krinix";
        model = "\TK\GW\GW_Medical_Assets\Cauterizer.p3d";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_885th_Cauterizer
            {
                name = "885th_Cauterizer";
                count = 1;
            };
        };
    };
};
class CfgWeapons
{
    class ItemCore;
    class ACE_ItemCore;
    class CBA_MiscItem_ItemInfo;
    class InventoryFirstAidKitItem_Base_F;
    class MedikitItem;
    class FirstAidKit : ItemCore
    {
        type = 0;
        class ItemInfo : InventoryFirstAidKitItem_Base_F
        {
            mass = 4;
        };
    };
    class Medikit : ItemCore
    {
        type = 0;
        class ItemInfo : MedikitItem
        {
            mass = 60;
        };
    };
    class 885th_ClothBandage : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_ClothBandage";
        model = "\TK\GW\GW_Medical_Assets\BandageCloth.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\bandage_cloth_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 1;
        };
    };
    class 885th_BactaBandage : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_BactaBandage";
        model = "\TK\GW\GW_Medical_Assets\BandageBacta.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\bandage_bacta_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 1;
        };
    };
    class 885th_BactaSpray : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_BactaSpray";
        model = "\TK\GW\GW_Medical_Assets\BactaSpray.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\bacta_spray_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 1;
        };
    };
    class 885th_BactaPatch : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_BactaPatch";
        model = "\TK\GW\GW_Medical_Assets\BactaPatch.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\bacta_patch_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 1;
        };
    };
    class 885th_Stim_Perigen : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_Stim_Perigen";
        model = "\TK\GW\GW_Medical_Assets\StimGreen.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\stim_green_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 1;
        };
    };
    class 885th_Stim_Enkephalin : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_Stim_Enkephalin";
        model = "\TK\GW\GW_Medical_Assets\StimRed.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\stim_red_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 1;
        };
    };
    class 885th_Stim_Kyrprax : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_Stim_Kyrprax";
        model = "\TK\GW\GW_Medical_Assets\StimYellow.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\stim_yellow_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 1;
        };
    };
    class 885th_Stim_Myocaine : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_Stim_Myocaine";
        model = "\TK\GW\GW_Medical_Assets\StimBlue.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\stim_blue_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 1;
        };
    };
    class 885th_Stim_Reedug : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_Stim_Reedug";
        model = "\TK\GW\GW_Medical_Assets\StimBlack.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\stim_black_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 1;
        };
    };
    class 885th_Injector_Myoplexaril : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_Injector_Myoplexaril";
        model = "\TK\GW\GW_Medical_Assets\InjectorBlue.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\injector_Blue_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 1;
        };
    };
    class 885th_Injector_Polybiotics : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_Injector_Polybiotics";
        model = "\TK\GW\GW_Medical_Assets\InjectorYellow.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\injector_yellow_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 1;
        };
    };
    class 885th_Injector_Nyex : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_Injector_Nyex";
        model = "\TK\GW\GW_Medical_Assets\InjectorRed.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\injector_red_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 1;
        };
    };
    class 885th_Vasko1000 : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_Vasko1000";
        model = "\TK\GW\GW_Medical_Assets\Vasko1000ml.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\vasko_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 10;
        };
    };
    class 885th_Vasko500 : 885th_Vasko1000
    {
        displayName = "$STR_885th_Medical_Display_Vasko500";
        model = "\TK\GW\GW_Medical_Assets\Vasko500ml.p3d";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 5;
        };
    };
    class 885th_Vasko250 : 885th_Vasko1000
    {
        displayName = "$STR_885th_Medical_Display_Vasko250";
        model = "\TK\GW\GW_Medical_Assets\Vasko250ml.p3d";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 5;
        };
    };
    class 885th_BactaPack : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_BactaPack";
        model = "\TK\GW\GW_Medical_Assets\BactaCanister.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\bacta_canister_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 10;
        };
    };
    class 885th_Cauterizer : ACE_ItemCore
    {
        scope = 2;
        author = "Krinix";
        displayName = "$STR_885th_Medical_Display_Cauterizer";
        model = "\TK\GW\GW_Medical_Assets\Cauterizer.p3d";
        picture = "\TK\GW\GW_Medical_Assets\ui\cauterizer_ui_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo
        {
            mass = 15;
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
