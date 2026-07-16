# 885th_CloneHUD — Basic Build

A minimal, working helmet HUD covering the core layout you sketched:
callsign/link (top left), time/mission timer (top right), health monitor
(left), weapon data (right), squad tracker (bottom left), compass (bottom
center). Boot sequence plays on spawn/respawn. Toggle with Shift+H.

## What's included
- `config.cpp` — CfgPatches + CfgFunctions (tag `BPD_HUD`, per your convention)
- `RscTitles.hpp` — the two dialogs (`BPD_CloneHUD_Boot`, `BPD_CloneHUD_Main`)
- `XEH_postInit.sqf` — spawn hook, PlayerChanged hook, keybind
- `functions/fn_bootSequence.sqf` — scripted boot text (spawned, uses `sleep`)
- `functions/fn_initHUD.sqf` — opens the main HUD, starts the per-frame updater
- `functions/fn_updateHUD.sqf` — refreshes all fields every 0.2s
- `functions/fn_toggleHUD.sqf` — show/hide via keybind

No `$PBOPREFIX$` file is included, per your existing lesson — folder name
`885th_CloneHUD` becomes the PBO prefix via Addon Builder's P: drive setup.

## Build steps (matches your existing workflow)
1. Copy this folder to `P:\885th_CloneHUD`.
2. Open Arma 3 Tools → Addon Builder, point Source at `P:\885th_CloneHUD`,
   output to your mod's `addons` folder.
3. Sign the PBO (unsigned PBOs silently skip CBA `preInit`/`postInit` on
   your setup, per your earlier IonDisruptor findings).
4. Add `requiredAddons[] = {"cba_main"}` is already set — make sure CBA is
   above this addon in your mod's load order / keys.

## Notes on scope (this is deliberately "basic")
Left out of this pass, on purpose, so it stays simple to test first:
- Armor is currently a flat placeholder (`_armorPct = 100` band via
  `_bodyPct`) since vanilla doesn't expose a separate armor value the way
  ACE's hitpoints/plate system does. If you want real armor %, tell me
  which system you're using (ACE hitpoints, a custom vest class, 3AS) and
  I'll wire `fn_updateHUD.sqf` to read from it directly.
- `TEMP` reads a `BPD_weaponTemp` unit variable that doesn't exist yet —
  it's a hook point for your custom blaster heat system (mentioned in your
  Star Wars weapon list) rather than something guessed at.
- `OBJ: ---m` distance is static. Hooking it to a marker is a one-line
  addition once you tell me which marker/waypoint convention your missions
  use.
- No damage-flash effects (helmet cracks, static, blood on visor), no NVG/
  thermal palette swap, no LAAT vehicle mode, no target recognition markers
  (friendly/Jedi/droid). All straightforward additions on top of this base
  once the core HUD is confirmed working in a test mission.

## Known idc numbers (for future edits)
9010/9011 callsign+link · 9020/9021 time+timer · 9030-9034 health block ·
9040-9043 weapon block · 9050/9051 squad block · 9060/9061 compass block ·
9001 boot text.

## Activating the HUD
Two ways to toggle it:
- **Scroll wheel**: a "Toggle Clone HUD" action appears in your action menu
  (self-interaction, 5m range, always available). Added/re-added in
  `fn_initHUD.sqf`, so it survives respawn without stacking duplicate entries.
- **Keybind**: Shift+H by default (set in `XEH_postInit.sqf`), if you'd
  rather keep a hotkey too. Delete the `CBA_fnc_addKeybind` block there if
  you only want the scroll-wheel option.

## Multiplayer note
Everything in `fn_updateHUD.sqf` reads only local `player` state — no
network round-trips — consistent with the locality issues you've hit
before on the dedicated server. `fn_bootSequence.sqf` and `fn_initHUD.sqf`
both guard with `if (_unit != player) exitWith {}` so a PlayerChanged event
firing for someone else's unit won't touch your own HUD.
