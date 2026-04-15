class CfgPatches
{
    class atrt_embark
    {
        name = "AT-RT Embark System";
        author = "Drexl";
        requiredVersion = 2.10;
        requiredAddons[] = 
    	{
    		"A3_Characters_F",
			"cba_main",  
    		"Extended_EventHandlers",
    		"3AS_ATRT"
    	};
        units[] = 
		{
			"885th_ATRT"
		};
        weapons[] = {};
    };
};

class CfgMoves885thWalker
{
	skeletonName="3AS_ATRT_skeleton";
	gestures="CfgGesturesWalker";
	extended="CfgExtendedAnimation";
	collisionVertexPattern[]=
	{
		"1a",
		"2a",
		"3a",
		"4a",
		"5a",
		"6a",
		"7a",
		"8a",
		"9a",
		"10a",
		"11a",
		"12a",
		"13a",
		"14a",
		"15a",
		"16a",
		"17a",
		"18a",
		"19a",
		"20a",
		"21a",
		"22a",
		"23a",
		"24a",
		"25a",
		"26a",
		"27a",
		"28a",
		"29a",
		"30a",
		"31a",
		"32a",
		"33a",
		"34a",
		"1c",
		"2c",
		"3c",
		"4c",
		"5c",
		"6c",
		"7c",
		"8c"
	};
	collisionGeomCompPattern[]={1,3};
	class Default
	{
		useIdles="false";
		GetOutPara="";
		weaponLowered=0;
		weaponObstructed=0;
		canBlendStep=0;
		idle="idleDefault";
		actions="NoActions";
		file="";
		looped=1;
		speed=0.5;
		disableWeapons=0;
		enableOptics=0;
		disableWeaponsLong=0;
		showWeaponAim=1;
		enableMissile=0;
		enableBinocular=0;
		showItemInHand=0;
		showItemInRightHand=0;
		showHandGun=0;
		onLandBeg=0;
		onLandEnd=0;
		onLadder=0;
		canPullTrigger=1;
		canReload=1;
		duty=-0.5;
		visibleSize=0.60000002;
		aimPrecision=1;
		camShakeFire=1;
		static=0;
		relSpeedMin=1;
		relSpeedMax=1;
		soundEnabled=1;
		soundOverride="";
		soundEdge[]={};
		terminal=0;
		ragdoll=0;
		limitGunMovement=1;
		variantsPlayer[]={};
		variantsAI[]=
		{
			""
		};
		equivalentTo="";
		connectAs="";
		variantAfter[]={5,10,20};
		connectFrom[]={};
		connectTo[]={};
		interpolateWith[]={};
		interpolateTo[]={};
		interpolateFrom[]={};
		ignoreMinPlayTime[]=
		{
			"Unconscious"
		};
		aiming="empty";
		aimingBody="empty";
		leaning="leaning";
		legs="empty";
		head="Turret";
		leaningFactorBeg=0;
		leaningFactorEnd=0;
		leaningFactorZeroPoint=-1;
		interpolationSpeed=6;
		interpolationRestart=0;
		enableDirectControl=1;
		headBobMode=0;
		headBobStrength=0;
		collisionShape="A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		hasCollShapeSafe=0;
		collisionShapeSafe="";
		boundingSphere=3;
		enableAutoActions=0;
		leftHandIKEnd=0;
		leftHandIKBeg=0;
		rightHandIKBeg=0;
		rightHandIKEnd=0;
		leftHandIKCurve[]={};
		rightHandIKCurve[]={};
		weaponIK=0;
		preload=0;
		Walkcycles=1;
		forceAim=0;
		adjstance="m";
	};
	class StandBase: Default
	{
		disableWeapons=1;
		leaningFactorBeg=1;
		leaningFactorEnd=1;
		headBobMode=0;
		headBobStrength=0;
		InterpolateWith[]=
		{
			"Unconscious",
			20
		};
	};
	class DefaultDie: Default
	{
		aiming="empty";
		aimingBody="empty";
		legs="empty";
		head="empty";
		disableWeapons=1;
		interpolationRestart=1;
		soundEdge[]={0.44999999};
		boundingSphere=3;
		enableDirectControl=0;
		showWeaponAim=0;
		canPullTrigger=0;
		headBobMode=1;
		headBobStrength=-1;
	};
	class States
	{
		class DeadState: Default
		{
			actions="DeadActions";
			file="3AS\ATRT\3as_atrt_fold.rtm";
			collisionShape="3AS\ATRT\3AS_ATRT_Collision.p3d";
			speed=100;
			looped=0;
			onLandBeg=1;
			onLandEnd=1;
			soundEnabled=0;
			terminal=1;
			ragdoll=1;
			headBobMode=4;
			headBobStrength=-1;
			disableWeapons=1;
			disableWeaponsLong=1;
		};
		class Unconscious: DeadState
		{
			terminal=0;
		};
		class TransAnimBase: Default
		{
			idle="";
			mask="headTorso";
			stamina=0;
			relSpeedMin=0.5;
			static=1;
			looped=0;
			leaningFactorBeg=1;
			leaningFactorEnd=1;
			leftHandIKBeg=1;
			leftHandIKCurve[]={1};
			leftHandIKEnd=1;
			rightHandIKBeg=1;
			rightHandIKCurve[]={1};
			rightHandIKEnd=1;
			soundEnabled=1;
			soundEdge[]={0.0099999998};
			headBobStrength=0.164179;
			headBobMode=2;
			interpolationSpeed=3;
			InterpolateTo[]=
			{
				"Unconscious",
				0.1
			};
		};
		class ATRT_Noweapon: StandBase
		{
			stamina=0;
			canPullTrigger=1;
			blockMobileSwitching=0;
			aimPrecision=7;
			turnSpeed=2;
			actions="Walker_default_actions";
			file="\3AS\ATRT\3AS_ATRT_Move";
			speed="50/100";
			soundOverride="sprint";
			duty=0;
			showWeaponAim=1;
			collisionShape="A3\anims_f\Data\Geom\Sdr\Perc_Mrun_Slow_Wrfl.p3d";
			leaningFactorBeg=0;
			leaningFactorEnd=0;
			limitGunMovement=0.2;
			soundEdge[]={0.5,1};
			static=1;
			relSpeedMin=0.69999999;
			relSpeedMax=1.1;
			visibleSize=0.89999998;
			head="Turret";
			aiming="Turret";
			aimingBody="Turret";
			interpolationSpeed=2.5;
			rightHandIKCurve[]={1};
			leftHandIKCurve[]={1};
			InterpolateTo[]=
			{
				"Walker_Idle",
				0.02,
				"Unconscious",
				0.02
			};
			disableWeaponsLong=0;
			disableWeapons=1;
			headBobMode=0;
			headBobStrength=0;
		};
		class Walker_move: StandBase
		{
			stamina=0;
			canPullTrigger=1;
			aimPrecision=7;
			turnSpeed=0.5;
			actions="Walker_default_actions";
			file="\3AS\ATRT\3AS_ATRT_Move";
			speed=0.60000002;
			soundOverride="sprint";
			duty=0;
			showWeaponAim=1;
			collisionShape="3AS\ATRT\3AS_ATRT_Collision.p3d";
			leaningFactorBeg=0;
			leaningFactorEnd=0;
			limitGunMovement=1;
			soundEdge[]={0.2,0.69999999};
			static=1;
			relSpeedMin=0;
			relSpeedMax=0;
			visibleSize=0.89999998;
			head="Turret";
			aiming="Turret";
			aimingBody="Turret";
			headBobStrength=0;
			interpolationSpeed=2.5;
			rightHandIKCurve[]={0};
			leftHandIKCurve[]={0};
			InterpolateTo[]=
			{
				"Walker_run",
				1,
				"Walker_idle",
				1
			};
			InterpolateFrom[]=
			{
				"Walker_run",
				1,
				"Walker_idle",
				1
			};
			disableWeaponsLong=0;
			disableWeapons=0;
		};
		class Walker_move_back: Walker_move
		{
			file="\3AS\ATRT\3AS_ATRT_Move_Back";
			InterpolateTo[]=
			{
				"Walker_idle",
				0.02
			};
			InterpolateFrom[]=
			{
				"Walker_idle",
				0.02
			};
		};
		class Walker_run: Walker_move
		{
			file="\3AS\ATRT\3AS_ATRT_Run";
			speed=1;
			InterpolateTo[]=
			{
				"Walker_move",
				1
			};
			InterpolateFrom[]=
			{
				"Walker_move",
				1
			};
		};
		class Walker_StrafeL: Walker_move
		{
			file="\3AS\ATRT\3AS_ATRT_StrafeL";
			speed=1;
			soundEdge[]={};
			InterpolateTo[]=
			{
				"Walker_idle",
				1
			};
			InterpolateFrom[]=
			{
				"Walker_idle",
				1
			};
		};
		class Walker_StrafeR: Walker_move
		{
			file="\3AS\ATRT\3AS_ATRT_StrafeR";
			speed=1;
			soundEdge[]={};
			InterpolateTo[]=
			{
				"Walker_idle",
				1
			};
			InterpolateFrom[]=
			{
				"Walker_idle",
				1
			};
		};
		class Walker_TurnL: Walker_move
		{
			file="\3AS\ATRT\3AS_ATRT_TurnL";
			speed=1;
			soundEdge[]={};
			InterpolateTo[]=
			{
				"Walker_idle",
				1
			};
			InterpolateFrom[]=
			{
				"Walker_idle",
				1
			};
		};
		class Walker_TurnR: Walker_move
		{
			file="\3AS\ATRT\3AS_ATRT_TurnR";
			speed=1;
			soundEdge[]={};
			InterpolateTo[]=
			{
				"Walker_idle",
				1
			};
			InterpolateFrom[]=
			{
				"Walker_idle",
				1
			};
		};
		class Walker_idle: Walker_move
		{
			file="\3AS\ATRT\3AS_ATRT_Idle";
			speed="30/250";
			soundEdge[]={};
			InterpolateTo[]=
			{
				"Walker_move",
				1,
				"Walker_move_back",
				1,
				"Walker_StrafeL",
				1,
				"Walker_StrafeR",
				1
			};
			InterpolateFrom[]=
			{
				"Walker_move",
				1,
				"Walker_move_back",
				1,
				"Walker_StrafeL",
				1,
				"Walker_StrafeR",
				1
			};
		};	
		class Walker_Vault: Walker_move
		{
			file="\3AS\ATRT\3as_atrt_vault.rtm";
			speed="30/250";
			soundEdge[]={};
			InterpolateTo[]=
			{
				"Walker_move",
				1,
				"Walker_move_back",
				1,
				"Walker_StrafeL",
				1,
				"Walker_StrafeR",
				1
			};
			InterpolateFrom[]=
			{
				"Walker_move",
				1,
				"Walker_move_back",
				1,
				"Walker_StrafeL",
				1,
				"Walker_StrafeR",
				1
			};
		};	
		class Walker_crouched_deadpose: StandBase
		{
            file="3AS\ATRT\3as_atrt_fold.rtm";
            looped=1;
            speed=1;
            terminal=0;
            ragdoll=0;
            actions="RifleKneelLowActions";
			collisionShape="A3\anims_f\data\geom\sdr\Pknl_Wrfl_Low.p3d";
            static=1;
            relSpeedMin=0;
            relSpeedMax=0;
            disableWeapons=0;
            disableWeaponsLong=0;
            enableDirectControl=1;
            headBobMode=0;
            headBobStrength=0;
            soundEnabled=1;
			interpolationSpeed=4;
			ConnectTo[]=
			{
				"Walker_crouch_in",
				1
			};
			InterpolateTo[]=
			{
				"Walker_crouch_in",
				1
			};
        };
		class Walker_crouch_in: TransAnimBase
        {
            actions="RifleKneelLowActions";
            file="3AS\ATRT\3as_atrt_fold.rtm";
			collisionShape="A3\anims_f\data\geom\sdr\Pknl_Wrfl_Low.p3d";
            looped=0;
            speed=1;
            enableDirectControl=0;
            static=1;
            InterpolateTo[] =
            {
                "Walker_crouched_deadpose", 0.05,
                "Unconscious", 0.02
            };
        };
	};
	class ManActions
	{
		LimpF="";
		LimpLF="";
		LimpRF="";
		LimpL="";
		LimpR="";
		LimpB="";
		LimpLB="";
		LimpRB="";
		AdjustF="";
		AdjustB="";
		AdjustL="";
		AdjustR="";
		AdjustLF="";
		AdjustLB="";
		AdjustRB="";
		AdjustRF="";
		dooraction="";
		GestureLegPush="";
		agonyStart="";
		agonyStop="";
		medicStop="";
		medicStart="";
		medicStartUp="";
		medicStartRightSide="";
		GestureAgonyCargo="";
		grabCarry="";
		grabCarried="";
		grabDrag="";
		grabDragged="";
		carriedStill="";
		released="";
		releasedBad="";
		Stop="";
		StopRelaxed="";
		TurnL="";
		TurnR="";
		TurnLRelaxed="";
		TurnRRelaxed="";
		ReloadMa885thine="";
		reloadGM6="";
		ReloadMGun="";
		ReloadRPG="";
		ReloadMortar="";
		ThrowPrepare="";
		ThrowGrenade="";
		WalkF="";
		WalkLF="";
		WalkRF="";
		WalkL="";
		WalkR="";
		WalkLB="";
		WalkRB="";
		WalkB="";
		PlayerWalkF="";
		PlayerWalkLF="";
		PlayerWalkRF="";
		PlayerWalkL="";
		PlayerWalkR="";
		PlayerWalkLB="";
		PlayerWalkRB="";
		PlayerWalkB="";
		SlowF="";
		SlowLF="";
		SlowRF="";
		SlowL="";
		SlowR="";
		SlowLB="";
		SlowRB="";
		SlowB="";
		PlayerSlowF="";
		PlayerSlowLF="";
		PlayerSlowRF="";
		PlayerSlowL="";
		PlayerSlowR="";
		PlayerSlowLB="";
		PlayerSlowRB="";
		PlayerSlowB="";
		FastF="";
		FastLF="";
		FastRF="";
		FastL="";
		FastR="";
		FastLB="";
		FastRB="";
		FastB="";
		TactF="";
		TactLF="";
		TactRF="";
		TactL="";
		TactR="";
		TactLB="";
		TactRB="";
		TactB="";
		PlayerTactF="";
		PlayerTactLF="";
		PlayerTactRF="";
		PlayerTactL="";
		PlayerTactR="";
		PlayerTactLB="";
		PlayerTactRB="";
		PlayerTactB="";
		EvasiveLeft="";
		EvasiveRight="";
		startSwim="";
		surfaceSwim="";
		bottomSwim="";
		StopSwim="";
		startDive="";
		SurfaceDive="";
		BottomDive="";
		StopDive="";
		Down="";
		Up="";
		PlayerStand="";
		PlayerCrouch="";
		PlayerProne="";
		Lying="";
		Stand="";
		Combat="";
		Crouch="";
		CanNotMove="";
		Civil="";
		CivilLying="";
		FireNotPossible="";
		Die="";
		Unconscious="";
		WeaponOn="";
		WeaponOff="";
		Default="";
		JumpOff="";
		StrokeFist="";
		StrokeGun="";
		SitDown="";
		Salute="";
		saluteOff="";
		GetOver="";
		Diary="";
		Surrender="";
		Gear="";
		BinocOn="";
		BinocOff="";
		PutDown="";
		PutDownEnd="";
		Medic="";
		MedicOther="";
		Treated="";
		LadderOnDown="";
		LadderOnUp="";
		LadderOff="";
		LadderOffTop="";
		LadderOffBottom="";
		GetInLow="";
		GetInMedium="";
		GetInHigh="";
		GetInVertical="";
		GetInSDV="";
		GetInHeli_Attack_01Pilot="";
		GetInHeli_Attack_01Gunner="";
		GetInHelicopterCargo="";
		GetInMRAP_01="";
		GetInMRAP_01_cargo="";
		GetOutMRAP_01="";
		GetOutMRAP_01_cargo="";
		GetOutHelicopterCargo="";
		GetOutLow="";
		GetOutMedium="";
		GetOutHigh="";
		GetOutHighZamak="";
		GetOutHighHemtt="";
		GetOutSDV="";
		GetOutHeli_Attack_01Pilot="";
		GetOutHeli_Attack_01Gunner="";
		GetInBoat="";
		GetOutBoat="";
		TakeFlag="";
		HandGunOn="";
		gestureAttack="";
		gestureGo="";
		gestureGoB="";
		gestureFreeze="";
		gesturePoint="";
		gestureCeaseFire="";
		gestureCover="";
		gestureUp="";
		gestureNo="";
		gestureYes="";
		gestureFollow="";
		gestureAdvance="";
		gestureHi="";
		gestureHiB="";
		gestureHiC="";
		gestureNod="";
		GestureSpasm0="";
		GestureSpasm1="";
		GestureSpasm2="";
		GestureSpasm3="";
		GestureSpasm4="";
		GestureSpasm5="";
		GestureSpasm6="";
		GestureSpasm0weak="";
		GestureSpasm1weak="";
		GestureSpasm2weak="";
		GestureSpasm3weak="";
		GestureSpasm4weak="";
		GestureSpasm5weak="";
		GestureSpasm6weak="";
		GestureReloadMX="";
		GestureReloadMXCompact="";
		GestureReloadMXSniper="";
		GestureReloadMk20="";
		GestureReloadMk20UGL="";
		GestureReloadMXUGL="";
		GestureReloadTRG="";
		GestureReloadTRGUGL="";
		GestureReloadKatiba="";
		GestureReloadKatibaUGL="";
		GestureReloadM200="";
		GestureReloadLRR="";
		GestureReloadEBR="";
		GestureReloadM4SSAS="";
		GestureReloadSMG_02="";
		GestureReloadSMG_03="";
		GestureReloadPistol="";
		GestureReloadPistolHeavy02="";
		GestureReloadFlaregun="";
		GestureReloadSMG_01="";
		GestureReloadSDAR="";
		GestureReloadDMR="";
		GestureReloadDMR02="";
		GestureReloadDMR03="";
		GestureReloadDMR04="";
		GestureReloadDMR05="";
		GestureReloadDMR06="";
		GestureReloadMMG01="";
		GestureReloadMMG02="";
		MountOptic="";
		DismountOptic="";
		MountSide="";
		DismountSide="";
		GestureMountMuzzle="";
		GestureDismountMuzzle="";
		healedStart="";
		healedStop="";
		TestDriver="";
		TestDriverOut="";
		TestGunner="";
		Relax="";
		swimUp="";
		swimDown="";
		StartFreefall="";
		PrimaryWeapon="";
		SecondaryWeapon="";
		Binoculars="";
		FDStart="";
		Obstructed="";
	};
	class Actions
	{
		class NoActions: ManActions
		{
			turnSpeed=1;
			upDegree=-1;
			stance="ManStanceUndefined";
			limitFast=5;
			leanRRot=0;
			leanRShift=0;
			leanLRot=0;
			leanLShift=0;
			useFastMove=0;
		};
		class DeadActions: NoActions
		{
			upDegree="ManPosDead";
			stance="ManStanceProne";
			LadderOnDown="";
			LadderOnUp="";
			TestDriver="";
			TestDriverOut="";
			startSwim="";
			surfaceSwim="";
			bottomSwim="";
			TestGunner="";
			Die="DeadState";
		};
		class Walker_default_actions: NoActions
		{
			upDegree="ManPosStand";
			stance="ManStanceStand";
			turnSpeed=1;
			limitFast=4;
			leanRRot=0.56999999;
			leanRShift=0.1;
			leanLRot=0.56999999;
			leanLShift=0.07;
			default="Walker_idle";
			stop="Walker_idle";
			playerstop="Walker_idle";
			Die="Unconscious";
			Unconscious="Unconscious";
			PrimaryWeapon="Walker_idle";
			Combat="Walker_idle";
			Crouch="Walker_crouch_in";
            PlayerCrouch="Walker_crouch_in";
            Stand="Walker_idle";
            PlayerStand="Walker_idle";
			Vault="Walker_Vault";
			Civil="Walker_idle";
			TactF="Walker_move";
			TurnL="Walker_TurnL";
			TurnR="Walker_TurnR";
			TurnLRelaxed="Walker_TurnL";
			TurnRRelaxed="Walker_TurnR";
			WalkL="Walker_StrafeL";
			WalkR="Walker_StrafeR";
			SlowL="Walker_StrafeL";
			SlowR="Walker_StrafeR";
			PlayerSlowL="Walker_StrafeL";
			PlayerSlowR="Walker_StrafeR";
			FastL="Walker_StrafeL";
			FastR="Walker_StrafeR";
			TactL="Walker_StrafeL";
			TactR="Walker_StrafeR";
			PlayerTactF="Walker_move";
			WalkF="Walker_move";
			PlayerWalkF="Walker_move";
			SlowF="Walker_move";
			PlayerSlowF="Walker_move";
			FastF="Walker_run";
			TactB="Walker_move_back";
			PlayerTactB="Walker_move_back";
			WalkB="Walker_move_back";
			PlayerWalkB="Walker_move_back";
			SlowB="Walker_move_back";
			PlayerSlowB="Walker_move_back";
			FastB="Walker_move_back";
		};
	};
	
	primaryActionMaps[]=
	{
		"Walker_default_actions"
	};
	class Interpolations
	{
	};
	transitionsInterpolated[]={};
	transitionsSimple[]={};
	transitionsDisabled[]={};
	class BlendAnims
	{
		empty[]={};
		Turret[]=
		{
			"Weapon",
			1
		};
		headTorso[]=
		{
			"Camera",
			1,
			"Body",
			1
		};
	};
};
class CfgGestures885thWalker
{
	skeletonName="3AS_ATRT_skeleton";
	class ManActions
	{
	};
	class Actions
	{
		class NoActions
		{
			turnSpeed=0;
			upDegree=0;
			limitFast=1;
			useFastMove=0;
			stance="ManStanceUndefined";
		};
	};
	class Default
	{
		actions="NoActions";
		file="";
		looped=1;
		speed=0.5;
		static=0;
		relSpeedMin=1;
		relSpeedMax=1;
		soundEnabled=0;
		soundOverride="";
		soundEdge[]={0.5,1};
		terminal=0;
		ragdoll=0;
		equivalentTo="";
		connectAs="";
		connectFrom[]={};
		connectTo[]={};
		interpolateWith[]={};
		interpolateTo[]={};
		interpolateFrom[]={};
		mask="empty";
		interpolationSpeed=6;
		interpolationRestart=0;
		preload=0;
		disableWeapons=1;
		enableOptics=0;
		showWeaponAim=1;
		enableMissile=1;
		enableBinocular=1;
		showItemInHand=0;
		showItemInRightHand=0;
		showHandGun=0;
		canPullTrigger=1;
		Walkcycles=1;
		headBobMode=0;
		headBobStrength=0;
		leftHandIKBeg=0;
		leftHandIKEnd=0;
		rightHandIKBeg=0;
		rightHandIKEnd=0;
		leftHandIKCurve[]={1};
		rightHandIKCurve[]={1};
		forceAim=0;
	};
	class States
	{
	};
	class BlendAnims
	{
		class MaskStart
		{
			weight=0.85000002;
		};
		class MaskStartDecreased
		{
			weight=0.34999999;
		};
		empty[]={};
	};
	class Interpolations
	{
	};
	transitionsInterpolated[]={};
	transitionsSimple[]={};
	transitionsDisabled[]={};
};

class CfgFunctions
{
    class ATRT
    {
        tag = "ATRT";
        class Embark
        {
            file = "885_Test\atrt_embark\functions";
            class postInit { postInit = 1; };
            class isATRT {};
            class addActions {};
            class embark {};
            class disembark {};
            class serverTransferOwner {};
            class findNearbyATRT {};
			class atrtOnInit {};
			class atrtOnKilled {};
			class atrtStartDeathSparks {};
        };
    };
};

class ATRT_Embark
{
    atrtClasses[] =
    {
        "885th_ATRT"
    };

    seatMemoryPoint = "seat";

    dismountOffset[] = { 0, 2.0, 0 };
};

class CfgVehicles
{
	class UniformInfo;
	class UniformSlotInfo;
	class SlotsInfo;
	class CAManBase;
	class SoldierWB: CAManBase
	{
		class HeadLimits;
	};
	class 885th_ATRT_Base: SoldierWB
	{
		author="Drexl";
		extCameraPosition[]={0,0,-2};
		identityTypes[]={};
		faceType="3AS_ATRT_Face";
		side=1;
		faction="885th_Faction";
		genericNames="885thATRTNames";
		editorSubcategory="Sub885thRecon";
		portrait="";
		picture="";
		icon="iconMan";
		accuracy=2.3;
		threat[]={1,0.1,0.1};
		camouflage=1.4;
		minFireTime=7;
		cost=100000;
		canCarryBackPack=1;
		scope=0;
		triggerAnim="";
		moves="CfgMoves885thWalker";
		gestures="CfgGestures885thWalker";
		movesFatigue="CfgMovesFatigue";
		memoryPointPilot="internalCamPos";
		canBleed=0;
		boneHead="";
		boneHeadCutScene="";
		boneLEye="";
		boneREye="";
		boneLEyelidUp="";
		boneREyelidUp="";
		boneLEyelidDown="";
		boneREyelidDown="";
		boneLPupil="";
		boneRPupil="";
		selectionHeadWound="";
		selectionBodyWound="";
		selectionLArmWound="";
		selectionRArmWound="";
		selectionLLegWound="";
		selectionRLegWound="";
		selectionLArmWound1="";
		selectionRArmWound1="";
		selectionLLegWound1="";
		selectionRLegWound1="";
		selectionLArmWound2="";
		selectionRArmWound2="";
		selectionLLegWound2="";
		selectionRLegWound2="";
		selectionHeadHide="";
		selectionNeckHide="";
		memoryPointLStep="footstepL";
		memoryPointRStep="footstepR";
		memoryPointAim="aimPoint";
		memoryPointCameraTarget="camera";
		memoryPointCommonDamage="l_femur_hit";
		memoryPointLeanin885this="leaning_axis";
		memoryPointAimin885this="aiming_axis";
		memoryPointHeadAxis="head_axis";
		memoryPointWaterSurface="water_surface";
		selectionLBrow="";
		selectionMBrow="";
		selectionRBrow="";
		selectionLMouth="";
		selectionMMouth="";
		selectionRMouth="";
		selectionEyelid="";
		selectionLip="";
		leftArmToElbow[]={};
		leftArmFromElbow[]={};
		leftWrist="LeftHand";
		leftShoulder="LeftShoulder";
		leftHand[]={};
		leftArmPoints[]=
		{
			"",
			"",
			"",
			""
		};
		rightArmToElbow[]={};
		rightArmFromElbow[]={};
		rightWrist="RightHand";
		rightShoulder="RightShoulder";
		rightHand[]={};
		rightArmPoints[]=
		{
			"",
			"",
			"",
			""
		};
		leftLegToKnee[]=
		{
			"LeftUpLeg",
			0.5
		};
		leftLegFromKnee[]={};
		leftHeel="LeftFoot";
		leftHip="Pelvis";
		leftFoot[]={};
		leftLegPoints[]=
		{
			"",
			"",
			"",
			""
		};
		rightLegToKnee[]=
		{
			"RightLeg",
			0.5
		};
		rightLegFromKnee[]={};
		rightHeel="RightFoot";
		rightHip="Pelvis";
		rightFoot[]={};
		rightLegPoints[]=
		{
			"",
			"",
			"",
			""
		};
		minGunElev=0;
		maxGunElev=0;
		minGunTurn=-90;
		maxGunTurn=90;
		minGunTurnAI=-90;
		maxGunTurnAI=90;
		class HeadLimits: HeadLimits
		{
			initAngleX=0;
			minAngleX=-30;
			maxAngleX=100;
			minAngleZ=-100;
			maxAngleZ=100;
			rotZRadius=0;
			initAngleY=0;
			minAngleY=-100;
			maxAngleY=100;
		};
		class Wounds
		{
			tex[]={};
			mat[]={};
		};
		model="\3AS\ATRT\3AS_ATRT.p3d";
		modelSides[]={3,1};
		hiddenSelections[]=
		{
			"Camo"
		};
		hiddenSelectionsTextures[]=
		{
			"885_Test\atrt_embark\data\atrt_co.paa"
		};
		nakedUniform="885th_ATRT_Uniform";
		uniformClass="885th_ATRT_Uniform";
		backpack="885th_ATRT_SaddleBags";
		class UniformInfo
		{
			class SlotsInfo
			{
				class NVG: UniformSlotInfo
				{
					slotType=602;
				};
				class Scuba: UniformSlotInfo
				{
					slotType=604;
				};
				class Googles: UniformSlotInfo
				{
					slotType=603;
				};
				class Headgear: UniformSlotInfo
				{
					slotType=605;
				};
			};
		};
		armor=35;
		armorStructural=20;
		explosionShielding=20;
		class EventHandlers;
		weapons[]=
		{
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"Throw",
			"Put"
		};
		Items[]={};
		RespawnItems[]={};
		magazines[]={};
		respawnMagazines[]={};
		linkedItems[]=
		{
			"ItemMap",
			"ItemCompass",
			"ItemGPS",
			"ItemWatch",
			"ItemRadio"
		};
		respawnLinkedItems[]=
		{
			"ItemMap",
			"ItemCompass",
			"ItemGPS",
			"ItemWatch",
			"ItemRadio"
		};
		uniformAccessories[]={};
		class SoundEnvironExt
		{
			rock[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			normal[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			gravel2[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			road[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			normalExt[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			tarmac[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			stony[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			water[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			lepenka[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			wave_plate[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			parkety[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			hallway[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			steel[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			concrete_ext[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			carpet[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			mud[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			forest[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			gravel[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			roof_tiles[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			sand[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			drygrass[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			grass[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			debris[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			wood[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			wood_int[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			concrete_int[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			concrete[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			metal[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			metal_int[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			tiles_int[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			dirt[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			roof_tin[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
			virtual[]=
			{
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"run",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"walk",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_A3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_B3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_C3.ogg",
						1.5,
						1,
						250
					}
				},
				
				{
					"sprint",
					
					{
						"3AS\ATRT\Sounds\ATRT_FS_D3.ogg",
						1.5,
						1,
						250
					}
				}
			};
		};
    };

	class 885th_ATRT: 885th_ATRT_Base
	{
		author="Drexl";
		model="\3AS\ATRT\3AS_ATRT.p3d";
		scope=2;
		scopeCurator=2;
		class EventHandlers: EventHandlers
        {
            init = "_this spawn ATRT_fnc_atrtOnInit;";
            killed = "_this spawn ATRT_fnc_atrtOnKilled;";
        };
		displayName="[885th] ATRT";
		hiddenSelectionsTextures[]=
		{
			"885_Test\atrt_embark\data\atrt_co.paa"
		};
		uniformClass="885th_ATRT_Uniform";
		nakedUniform="885th_ATRT_Uniform";
		backpack="885th_ATRT_SaddleBags";
		weapons[]=
		{
			"3AS_ATRT_Weapon_F"
		};
		magazines[]=
		{
			"3AS_9999Rnd_ATRT_Mag"
		};
		linkedItems[]=
		{
			"ItemMap",
			"ItemCompass",
			"ItemGPS",
			"ItemWatch",
			"ItemRadio"
		};
		modelSides[]={3,1,0,2};
		respawnWeapons[]={};
		tas_canBlift=1; 
		tas_liftVars="[[[[0,-4,-5]]], [0], [0]]";
		respawnMagazines[]={};
		class Wounds
		{
			tex[]={};
			mat[]={};
		};
	};

    class B_Carryall_blk;
 
    class 885th_ATRT_SaddleBags: B_Carryall_blk
    {
        scope = 1;
        scopeCurator = 1;
        displayName = "AT-RT Saddlebag";
        author = "Drexl";
        model = "";
        picture = "";
        icon = "iconBackpack";
        maximumLoad = 200;
        mass = 40;
        hiddenSelections[] = {};
        hiddenSelectionsTextures[] = {};
    };
};
class CfgWeapons
{
	class ItemCore;
	class ItemInfo;
	class UniformItem;
	class HeadgearItem;
	class VestItem;
	class 885th_ATRT_Base: ItemCore
	{
		scope=0;
		allowedSlots[]={901};
		model="\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
		picture="";
		tas_canBlift=1; 
		tas_liftVars="[[[[0,-4,-5]]], [0], [0]]";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="885th_ATRT_Base";
			containerClass="Supply10";
			mass=5;
		};
	};
	class 885th_ATRT_Uniform: 885th_ATRT_Base
	{
		author="Drexl";
		scope=1;
		displayName="ATRT Uniform";
		picture="";
		tas_canBlift=1; 
		tas_liftVars="[[[[0,-4,-5]]], [0], [0]]";
		subItems[]=
		{
			"Integrated_NVG_F"
		};
		class ItemInfo: ItemInfo
		{
			uniformClass="885th_ATRT";
		};
	};
};

class CfgWorlds
{
	class GenericNames
	{
		class 885thATRTNames
		{
			class FirstNames
			{
				AT="AT";
			};
			class LastNames
			{
				RT="-RT";
			};
		};
	};
};
