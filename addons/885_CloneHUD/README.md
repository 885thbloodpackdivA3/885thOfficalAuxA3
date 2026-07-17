# 885th_CloneHUD

Restyled after a reference HUD PBO you provided (a Star Wars-themed
"visor + crack overlay + directional damage + target recognition" HUD).
Armor removed per your request; all existing CBA settings kept and
extended.

## What changed from the previous build
- **Armor removed** - health monitor now shows BODY / BLEED / PAIN only.
- **Visor overlay + crack overlay** - full-screen picture controls (idc
  9070/9071), same pattern as the reference: opacity-controlled overlay,
  damage-threshold-triggered crack. Both are **hidden until you set a
  texture path** in CBA settings - no art is bundled with this addon.
  Point them at your own PAA (e.g. a 3AS clone visor texture) to activate.
- **Directional damage corners** (idc 9080-9083) - a `HandleDamage` event
  handler figures out which side a hit came from (front/back/left/right)
  relative to your facing and flashes the matching screen corners red,
  fading out over the configured duration. Same approach as the reference
  PBO's `HandleDamage` handler, adapted to your `BPD_` naming.
- **Target Recognition** - a `Draw3D` handler shows a text-only name tag
  over whatever you're looking at within range: `▲ <name>` in green for
  friendlies, `HOSTILE` in red for enemies, both with distance. This uses
  a fully transparent 1x1 procedural texture (`#(argb,8,8,3)color(1,1,1,0)`)
  as the `drawIcon3D` icon argument, so it renders text with **zero
  bundled art** - unlike the reference PBO, which ships real icon/Aurebesh
  textures. You can swap in real icons later by pointing `drawIcon3D` at a
  proper texture in `fn_initHUD.sqf`.

## CBA Settings
Under Configure > Addon Options > "885th Clone HUD" (all client-side):

**General**
- Enable Clone HUD (master on/off)
- HUD Refresh Rate (s)
- Scroll-Wheel Toggle
- Boot Sequence Animation

**Visor**
- Visor overlay texture (path, blank = disabled)
- Visor overlay opacity
- Crack overlay texture (path, blank = disabled)
- Crack damage threshold

**Damage**
- Damage indicator duration (s)

**Target Recognition**
- Target Recognition (on/off)
- Target Recognition max distance (m)

## Build steps (unchanged)
1. Copy this folder to `P:\885th_CloneHUD`.
2. Addon Builder, source `P:\885th_CloneHUD`, output to your mod's
   `addons` folder.
3. Sign the PBO.
4. `config.cpp` explicitly registers `XEH_preInit.sqf`/`XEH_postInit.sqf`
   under `Extended_PreInit_EventHandlers`/`Extended_PostInit_EventHandlers`
   rather than relying on CBA auto-detection.

## Activating the HUD
- **Scroll wheel**: "Toggle Clone HUD" action (5m range), toggleable via
  the Scroll-Wheel Toggle setting.
- **Keybind**: Shift+H by default, set in `XEH_postInit.sqf`.

## Known idc numbers
9070/9071 overlay/crack · 9010/9011 callsign+link · 9020/9021 time+timer ·
9032-9034 health block (armor removed) · 9040-9043 weapon block ·
9050/9051 squad block · 9060/9061 compass block · 9080-9083 damage
corners (TL/TR/BR/BL) · 9001 boot text.

## Multiplayer note
`fn_updateHUD.sqf` reads only local `player` state - no network
round-trips. The `HandleDamage` and `Draw3D` handlers are registered once
per unit (guarded with `getVariable`/`isNil` checks) and only ever act on
`player`/`cursorTarget`, so they stay client-local too.
