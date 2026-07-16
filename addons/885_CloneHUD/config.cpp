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

#include "RscTitles.hpp"
