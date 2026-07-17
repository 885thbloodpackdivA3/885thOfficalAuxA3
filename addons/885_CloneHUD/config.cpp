class CfgPatches
{
    class 885th_CloneHUD
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"cba_main"};
        author = "885th Bloodpack Division";
        authorUrl = "";
        version = "0.1";
    };
};

// NOTE: CfgFunctions tag uses "BPD_HUD" (not "885th_HUD") to avoid the
// digit-leading identifier tokenizer bug you've hit on other 885th addons.
class CfgFunctions
{
    class BPD_CloneHUD
    {
        tag = "BPD_HUD";
        class Functions
        {
            file = "885_CloneHUD\functions";
            class initHUD {};
            class updateHUD {};
            class toggleHUD {};
            class bootSequence {};
        };
    };
};

// Explicit XEH registration - auto-detection has been unreliable on this
// modset (per the IonDisruptor / Bacta lessons), so we register both
// explicitly rather than relying on CBA to find the files on its own.
class Extended_PreInit_EventHandlers
{
    class 885th_CloneHUD
    {
        init = "call compile preprocessFileLineNumbers '\885_CloneHUD\XEH_preInit.sqf'";
    };
};

class Extended_PostInit_EventHandlers
{
    class 885th_CloneHUD
    {
        init = "call compile preprocessFileLineNumbers '\885_CloneHUD\XEH_postInit.sqf'";
    };
};

#include "RscTitles.hpp"
