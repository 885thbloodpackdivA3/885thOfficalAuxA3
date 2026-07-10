#define QUOTE(x) #x

class CfgPatches
{
    class 885th_ion_ammo
    {
        units[]={};
        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]=
        {
            "A3_Weapons_F",
            "3AS_Weapons",
            "cba_main"
        };
        author="885th Bloodpack Div";
        url="";
        version="1.0";
        versionStr="1.0";
        versionAr[]={1,0};
    };
};

class CfgFunctions
{
    class 885th_ion_ammo
    {
        tag = "885th_ion_ammo";
        class Ammo
        {
            class ionFx
            {
                file="885th_ion_ammo\scripts\fn_ionFx.sqf";
            };
            class ionSettings
            {
                file="885th_ion_ammo\scripts\fn_settings.sqf";
                preInit=1;
            };
            class ionDisable
            {
                file="885th_ion_ammo\scripts\fn_ionDisable.sqf";
            };

        };
    };
};

class CfgCloudlets
{
    class IonDisruptorCore
    {
        interval=0.01;
        circleRadius=0;
        circleVelocity=0;
        particleShape="\A3\data_f\ParticleEffects\Universal\Universal";
        particleType="Billboard";
        timerPeriod=0.08;
        lifeTime=0.35;
        position[]={0,0,0};
        moveVelocity[]={0,0,0};
        rotationVelocity=0;
        weight=1e-010;
        volume=1e-010;
        rubbing=0.1;
        size[]={0.4,0.9,1.6,2.4,3.0,2.0,0.8};
        color[]={
            {0.6,0.85,1.0,0.9},
            {0.4,0.75,1.0,0.8},
            {0.2,0.6,1.0,0.6},
            {0.1,0.45,0.9,0.3},
            {0.0,0.3,0.8,0.0}
        };
        angleVar=180;
        sizeVar=0.3;
        colorVar[]={0.05,0.05,0.1,0.0};
        randomDirectionPeriod=0.1;
        randomDirectionIntensity=0.2;
        onTimerScript="";
        beforeDestroyScript="";
    };

    class IonDisruptorArc
    {
        interval=0.015;
        circleRadius=0.5;
        circleVelocity=0;
        particleShape="\A3\data_f\ParticleEffects\Universal\Universal";
        particleType="Billboard";
        timerPeriod=0.06;
        lifeTime=0.25;
        position[]={0,0,0};
        moveVelocity[]={0.8,0.0,0.8};
        rotationVelocity=45;
        weight=1e-010;
        volume=1e-010;
        rubbing=0.05;
        size[]={0.1,0.3,0.5,0.3,0.1};
        color[]={
            {0.7,0.92,1.0,1.0},
            {0.5,0.82,1.0,0.9},
            {0.3,0.7,1.0,0.5},
            {0.1,0.5,0.9,0.0}
        };
        angleVar=360;
        sizeVar=0.15;
        colorVar[]={0.05,0.05,0.1,0.0};
        randomDirectionPeriod=0.05;
        randomDirectionIntensity=1.8;
        onTimerScript="";
        beforeDestroyScript="";
    };

    class IonDisruptorPulse
    {
        interval=0.02;
        circleRadius=1.5;
        circleVelocity=0;
        particleShape="\A3\data_f\ParticleEffects\Universal\Universal";
        particleType="Billboard";
        timerPeriod=0.12;
        lifeTime=0.5;
        position[]={0,0,0};
        moveVelocity[]={0,0,0};
        rotationVelocity=15;
        weight=1e-010;
        volume=1e-010;
        rubbing=0.02;
        size[]={0.2,0.8,1.8,3.5,4.5,3.0,1.0,0.0};
        color[]={
            {0.5,0.8,1.0,0.5},
            {0.3,0.65,1.0,0.35},
            {0.15,0.5,0.95,0.2},
            {0.05,0.35,0.85,0.08},
            {0.0,0.2,0.75,0.0}
        };
        angleVar=180;
        sizeVar=0.5;
        colorVar[]={0.05,0.05,0.1,0.0};
        randomDirectionPeriod=0.2;
        randomDirectionIntensity=0.1;
        onTimerScript="";
        beforeDestroyScript="";
    };

    class IonDisruptorSmoke
    {
        interval=0.03;
        circleRadius=0.3;
        circleVelocity=0;
        particleShape="\A3\data_f\ParticleEffects\Universal\Universal";
        particleType="Billboard";
        timerPeriod=0.4;
        lifeTime=2.5;
        position[]={0,0,0};
        moveVelocity[]={0,0.4,0};
        rotationVelocity=8;
        weight=0.08;
        volume=0.05;
        rubbing=0.3;
        size[]={0.3,0.6,1.0,1.4,1.6,1.5,1.2,0.6,0.0};
        color[]={
            {0.3,0.5,0.7,0.4},
            {0.2,0.4,0.6,0.25},
            {0.15,0.3,0.5,0.15},
            {0.1,0.2,0.35,0.05},
            {0.05,0.1,0.2,0.0}
        };
        angleVar=90;
        sizeVar=0.4;
        colorVar[]={0.05,0.05,0.1,0.0};
        randomDirectionPeriod=0.5;
        randomDirectionIntensity=0.3;
        onTimerScript="";
        beforeDestroyScript="";
    };
};

class CfgSoundEffects
{
    class IonDisruptorBlastSound
    {
        sounds[]={"IonDisruptorCrack","IonDisruptorHum"};

        class IonDisruptorCrack
        {
            frequency=1.0;
            volume=1.0;
            sound[]=
            {
                "\A3\Sounds_F\weapons\Explosion\explosion_ord_small",
                1.0,
                1.0,
                1600
            };
        };
        class IonDisruptorHum
        {
            frequency=0.95;
            volume=0.75;
            sound[]=
            {
                "\A3\Sounds_F\weapons\Explosion\explosion_ord_small",
                0.75,
                1.0,
                800
            };
        };
    };
};

class CfgExplosionEffects
{
    class IonDisruptorBlast
    {
        class Particles
        {
            class IonCore
            {
                particleEffect="IonDisruptorCore";
                delay=0;
                interval=0.01;
                lifeTime=0.4;
                position[]={0,0,0};
                velocity[]={0,0,0};
                volume=1;
            };
            class IonArcs
            {
                particleEffect="IonDisruptorArc";
                delay=0;
                interval=0.015;
                lifeTime=0.3;
                position[]={0,0,0};
                velocity[]={0,0,0};
                volume=1;
            };
            class IonPulse
            {
                particleEffect="IonDisruptorPulse";
                delay=0.02;
                interval=0.02;
                lifeTime=0.6;
                position[]={0,0,0};
                velocity[]={0,0,0};
                volume=1;
            };
            class IonSmoke
            {
                particleEffect="IonDisruptorSmoke";
                delay=0.05;
                interval=0.03;
                lifeTime=2.8;
                position[]={0,0,0};
                velocity[]={0,0,0};
                volume=1;
            };
        };
        soundEffect="IonDisruptorBlastSound";
        light=1;
        lightColor[]={0.4,0.75,1.0,1.0};
        lightAmbient[]={0.1,0.3,0.6,1.0};
        lightRadius=12;
        lightBrightness=0.8;
        lightDuration=0.35;
    };
};

class Extended_PreInit_EventHandlers
{
    class 885th_ion_ammo_preInit
    {
        init = "call compile preprocessFileLineNumbers '885th_ion_ammo\XEH_preInit.sqf';";
    };
};

class Extended_PostInit_EventHandlers
{
    class 885th_ion_ammo_postInit
    {
        init = "call compile preprocessFileLineNumbers '885th_ion_ammo\XEH_postInit.sqf';";
    };
};

class CfgAmmo
{
    class 885th_blasterbolt;
    class 885th_blasterbolt_r_b: 885th_blasterbolt
    {
        hit=15;
        indirectHit=0;
        indirectHitRange=0;
        cartridge="";
        visibleFire=3;
        audibleFire=45;
        dangerRadiusBulletClose=8;
        dangerRadiusHit=12;
        suppressionRadiusBulletClose=6;
        suppressionRadiusHit=8;
        cost=1.2;
        airLock=1;
        typicalSpeed=472;
        caliber=2.0;
        model="\3AS\3AS_Weapons\Data\tracer_blue.p3d";
        tracerScale=0.97500002;
        airFriction=-0.00018;
        effectFly="3AS_PlasmaBolt_Blue_Fly";
        class CamShakeExplode
        {
            power=2.8284299;
            duration=0.60000002;
            frequency=20;
            distance=8.48528;
        };
        class CamShakeHit
        {
            power=5;
            duration=0.2;
            frequency=20;
            distance=1;
        };
    };

    class 885th_blasterbolt_r_b_ION: 885th_blasterbolt_r_b
    {
        hit=10;
        indirectHit=18;
        indirectHitRange=4.0;
        explosive=1;
        explosionEffects="IonDisruptorBlast";
        cartridge="";
        visibleFire=6;
        audibleFire=65;
        dangerRadiusBulletClose=22;
        dangerRadiusHit=35;
        suppressionRadiusBulletClose=16;
        suppressionRadiusHit=22;
        cost=3.0;
        airLock=1;
        typicalSpeed=420;
        caliber=0.8;
        model="\3AS\3AS_Weapons\Data\tracer_blue.p3d";
        tracerScale=1.35;
        airFriction=-0.00022;
        effectFly="3AS_PlasmaBolt_Blue_Fly";

        class CamShakeExplode
        {
            power=6.7082;
            duration=0.95;
            frequency=32;
            distance=20;
        };
        class CamShakeHit
        {
            power=7;
            duration=0.45;
            frequency=32;
            distance=3.5;
        };
    };
};
