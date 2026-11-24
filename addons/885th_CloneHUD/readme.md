# 885th Bloodpack Division — Clone HUD

A from-scratch rebuild of the reference CloneHUD mod, stripped down to
just the HUD. Client-side only — every script here reads or writes
the **local player's own** variables and controls, never anything
global or server-synced, so it behaves identically in the Eden
editor, singleplayer, hosted MP, and on a dedicated server with no
mission setup required.

**Requires CBA (`cba_main`) only** — no ACE.

## What's different from the reference mod

**Removed:**
- The entire repair system (repair.sqf, Field/Full Repair Kit items,
  all `REPAIR_*`/`SHOW_REPAIR`/`CONSUME_*_REPAIR_ITEM` settings, and
  the two repair sounds).
- The entire per-limb armor pool (armor.sqf, setArmorValues.sqf,
  restDamageArmor.sqf, the `FULL_*_ARMOR` variables, `HUD_fnc_calcDamage`,
  the `HUD_ONLY` toggle, and the dormant "Iron Halo" void-shield stub
  that hooked into it). Nothing here changes how much damage a unit
  takes anymore — that's fully back in the engine's hands.
- The **ACE3** dependency: `ace_medical` damage routing and the
  `ace_arsenal_displayClosed` ACE event hook.
- The AI-wide `CAManBase` event handlers (`HitPart`/`init`/`Local`)
  that let the reference mod run on AI units — this build only ever
  targets the local player, which is both simpler and far cheaper.
- `A3_Characters_F` from `requiredAddons[]` — it was never a real
  dependency (vanilla core content), just leftover from the repair
  items' class inheritance, which is gone now.

**Kept (and re-grounded on real data instead of a fake pool):**
- Full visor/helmet HUD overlay with lighting-aware tinting (day,
  NVG, thermal) and head-tracking sway.
- The boot-up terminal sequence and typing/glitch effects.
- The ammo/mag/heading/range info readout for all three suit tiers.
- The six-light damage indicator — now driven by the unit's **real**
  `getHitPointDamage` per vanilla hitpoint (`HitHead`/`HitBody`/
  `HitHands`/`HitLegs`), not a custom armor value. Arms share a
  hitpoint and so do legs in the stock Arma 3 damage model, so the
  left/right icons for those will always show the same color — only
  the on-hit flash differs by side, since we still know which
  selection was actually hit.
- The 3D target-recognition scanner (human/vehicle/static/grenade
  icons, IFF coloring, adjustable range).
- Low-light vision mode with adjustable sensitivity.
- The scrolling system-message log.
- CBA in-game settings menu and CBA keybinds, same default keys as
  the reference mod:
  - `Alt+T` — toggle scanner icons
  - `Shift+Up` / `Shift+Down` — scanner range +/-
  - `Shift+L` — toggle low-light vision
  - `Shift+Numpad+` / `Shift+Numpad-` — low-light sensitivity +/-

**Added:**
- **Kill switch** — `HUD_ENABLED`, the first setting in the CBA menu
  under *885th BPD Clone HUD - General*. Set it off and the addon does nothing
  at all: `init.sqf` exits on line one, no controls are created, no
  event handlers are added, zero runtime cost. It's a forced/global
  CBA setting (like the old `HUD_ONLY` toggle), so a mission or
  server admin can push it to everyone; takes effect on next mission
  load / respawn cycle.
- **Vanilla HUD replacement** (*General > IV. Vanilla HUD*, per-player).
  While the Clone HUD is booted, hides the vanilla elements you tick —
  weapon/ammo/stance info, compass, radar, squad bar (on by default),
  vehicle panels and kill messages (off by default) — plus DUI Squad
  Radar if it's loaded. With ACE the hide goes through
  `ace_common_fnc_showHud`, so ACE can't silently undo it any more (the
  1.0 build called `showHUD` once and ACE overwrote it); every tick also
  re-hides anything another mod turned back on. Death, helmet off, Zeus
  or *Deactivate HUD* restores everything. Mission scripts can call
  `BPD_CloneHUD_fnc_hideVanillaHud` / `BPD_CloneHUD_fnc_restoreVanillaHud`.
- **Layout** (*885th BPD Clone HUD - Layout*, per-player, live). Trooper
  status, squad list, radar and tactical link panel each get a position
  preset (corners / edges / Custom X-Y) and a scale. Defaults: trooper
  bottom-left, squad list middle-left, radar bottom-center, link panel
  top-right. The trooper is placed by the measured bounds of its art
  (`BPD_CloneHUD_fnc_artBox` in `scripts/layout.sqf`), not by its
  full-screen canvas, so all three armor tiers land on the same spot.
- **cTab link** (*885th BPD Clone HUD - cTab Link*, needs the 885th cTab):
  - Clone HUD helmets are registered as cTab helmet cams.
  - Tactical link panel shows TAB / ANDR / DAGR / HCAM status and the
    active link mode.
  - `Shift+H` cycles cTab → MicroDAGR → Helm Cam → off (skips devices you
    don't carry). cTab / DAGR open the real cTab interfaces.
  - `Shift+J` cycles helm cam feeds — a live picture-in-picture view
    from a squadmate's helmet inside the HUD panel (needs PiP on in
    Video options).

## Settings

Everything's in the CBA settings menu (*Configure > Addon Options >
885th BPD Clone HUD*) — no editing script files needed for day-to-day tuning.
The three helmet-tier lists (`BPD_CloneHUD_P1_HELMETS`,
`BPD_CloneHUD_P2_HELMETS`, `BPD_CloneHUD_RC_HELMETS` - namespaced on
purpose, see note below) are comma-separated classname EDITBOX
settings that
get split into arrays automatically whenever they're changed.

**Why the odd `BPD_CloneHUD_` prefix on the helmet settings:** a
plain `P1_HELMETS` collided with an identically-named global from
another PBO already in this repo (confirmed via RPT - something
else already owned that name as an array, not a comma-separated
string), which silently broke helmet detection addon-wide with no
visible error unless you were reading the RPT. Don't rename these
back to the generic form.

## Folder layout

```
885th_CloneHUD/
  config.cpp
  scripts/
    settings.sqf        (Preinit - CBA settings incl. kill switch)
    init.sqf             (Postinit - keybinds, hit handling, suit state)
    hudInit.sqf           (creates all HUD controls)
    hudBootUp.sqf          (boot terminal sequence + clearHud)
    hudEventhandler.sqf    (visor overlay per-frame + target scanner)
    system.sqf             (ammo/mag/dir/range readout loop)
    updateDamageIndicator.sqf (six-light HP-based indicator)
    systemMessages.sqf     (scrolling message log)
    teamList.sqf           (squad member list under the indicator)
    radar.sqf              (top-center radar)
    vanillaHud.sqf         (hides/restores the vanilla HUD it replaces)
    layout.sqf             (per-player element placement)
    ctab.sqf               (cTab link: helmet cams, link cycling, PiP feed)
  textures/               (helmet overlays, indicator icons, scanner icons)
  sounds/                 (typing, glitch, glitch_short, threat_detector)
```

## Building

Same as your usual workflow: point Addon Builder at this folder on
your P: drive, build `885th_CloneHUD.pbo`, sign as normal for your
dedicated server key set. Add `cba_main` to your mod list/mission
dependency if it isn't already there — no ACE required.
