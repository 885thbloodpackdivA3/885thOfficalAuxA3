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
  under *885th Clone HUD (Server & Advanced) > 1. Server*. Set it off and the addon does nothing
  at all: `init.sqf` exits on line one, no controls are created, no
  event handlers are added, zero runtime cost. It's a forced/global
  CBA setting (like the old `HUD_ONLY` toggle), so a mission or
  server admin can push it to everyone; takes effect on next mission
  load / respawn cycle.
- **Vanilla HUD replacement** (*885th Clone HUD > 3. Vanilla HUD*, per-player).
  While the Clone HUD is booted, hides the vanilla elements you tick —
  weapon/ammo/stance info, compass, radar, squad bar (on by default),
  vehicle panels and kill messages (off by default) — plus DUI Squad
  Radar if it's loaded. With ACE the hide goes through
  `ace_common_fnc_showHud`, so ACE can't silently undo it any more (the
  1.0 build called `showHUD` once and ACE overwrote it); every tick also
  re-hides anything another mod turned back on. Death, helmet off, Zeus
  or *Deactivate HUD* restores everything. Mission scripts can call
  `BPD_CloneHUD_fnc_hideVanillaHud` / `BPD_CloneHUD_fnc_restoreVanillaHud`.
- **Layout** (*885th Clone HUD > 2. Layout*, per-player, live). Trooper
  status, squad list, radar and tactical link panel each get a position
  preset (corners / edges / Custom X-Y) and a scale. Defaults: trooper
  bottom-left, squad list middle-left, radar bottom-center, link panel
  top-right. The trooper is placed by the measured bounds of its art
  (`BPD_CloneHUD_fnc_artBox` in `scripts/layout.sqf`), not by its
  full-screen canvas, so all three armor tiers land on the same spot.
- **cTab link** (*885th Clone HUD > 5. cTab Link* and *Server & Advanced > 1. Server*, needs the 885th cTab):
  - Clone HUD helmets are registered as cTab helmet cams.
  - Tactical link panel shows TAB / ANDR / DAGR / HCAM status and the
    active link mode.
  - `Shift+H` cycles cTab → MicroDAGR → Helm Cam → off (skips devices you
    don't carry). cTab / DAGR open the real cTab interfaces.
  - `Shift+J` cycles helm cam feeds — a live picture-in-picture view
    from a squadmate's helmet inside the HUD panel (needs PiP on in
    Video options).

## 1.2.0 - Squad medical

The squad list now shows each member's real medical state
(*885th Clone HUD > 1. What's On Screen*, logic in `scripts/squadMed.sqf`):

- **Status word**, worst first: `KIA`, `ARREST` (with the KAT rhythm:
  VT / VF / PEA / ASYS), `DOWN`, `BLEEDING`, `CRITICAL`, `WOUNDED`,
  `TREATED`, `OK`. **TREATED** (green) = nothing needs a medic any more
  (no bleeding / open wounds / unsplinted fracture / airway or chest
  problem / strong pain, blood above 85 %) but they're still patched up:
  bandaged wounds, tourniquet or splint on, some blood loss or mild pain.
  Once wounds are stitched and everything recovers it goes back to `OK`.
- **Name color** follows the status (red / orange / yellow while they need
  a medic, green once treated); healthy members keep their normal color.
  An alert fires when someone goes from hurt to treated.
- **Detail flags** on a line under the member: blood volume % (coloured by
  ACE's hemorrhage classes), `AIRWAY`, `TENSION PTX` / `HEMO PTX` / `PTX`,
  `INT BLEED`, `SpO2`, `TQ`, `FRACTURE`, `PAIN`. KAT flags need KAT loaded.
  Can be limited to medics only (server setting).
- **Alerts**: a HUD message when a squadmate gets worse (down, arrest,
  bleeding, airway / tension / hemo pneumothorax / internal bleeding).
- Only variables ACE / KAT broadcast are read, so it works for other
  players and AI. ACE syncs blood volume, pain and SpO2 for other people
  only every 10-20 s, so those numbers lag slightly for squadmates;
  unconscious, arrest, bleeding, wounds, tourniquets and fractures update
  immediately. Without ACE it falls back to vanilla damage.

## cTab and helm cam notes

- **`885_SW_cTab` must be packed with prefix `cTab`.** Its config loads
  everything from `\cTab\...`, but the folder is named `885_SW_cTab`.
  Arma's Addon Builder ignores the folder's `pbo.json`, so local builds
  came out with no prefix, and the game then ran another mod's cTab scripts
  (cTab / cTab Star Wars Edit) or none. The folder now has a `$PBOPREFIX$`
  (`cTab`) so builds come out right. The HUD checks this at mission start
  and says so in chat if cTab's config is loaded but its scripts aren't,
  or if more than one cTab mod is loaded.
- **Helm cam settings** are all under *885th Clone HUD > 5. Helm Cam &
  cTab*. The HUD builds its own list of who you can view (friendly clones
  in Clone HUD helmets + anyone cTab knows has a helmet cam), so it no
  longer depends on cTab's scripts running. When nobody is available it
  says why (setting off, own-squad filter, device required, nobody else in
  the mission, PiP disabled).

## 1.1.1 fixes (from first in-game test)

- **Vanilla HUD flicker.** With ACE UI loaded, the weapon / ammo / stance
  panel is now hidden per-control through `ace_ui_fnc_setElementVisibility`
  (a fade on the IGUI controls), which another mod's `showHUD` call can't
  undo. The `showHUD` re-check is throttled to once every 2 s and logs
  `another script turned the vanilla HUD back on` to the RPT when it
  catches one. The flicker in testing came from **Shadow Legion Armory**:
  `ShadowLegion_fnc_updateHUD` re-applies `showHUD` on every frame. With
  ACE UI loaded the Clone HUD no longer toggles showHUD "info" at all
  (the per-control fade covers it), and if another mod reverses the hide
  3 times in 15 s the Clone HUD backs off instead of strobing and logs
  which elements are contested. Other direct `showHUD` callers in the
  workshop set: DUI (group-bar setting), StarForge Armory gadget HUD,
  Misriah Armory HUD, OPTRE HUD, Speshal Core.
- **Radar never drew.** The dial was an RscPicture with no texture and a
  background colour (pictures don't draw backgrounds), so only blips ever
  showed. Now a real dial from vanilla textures: sensor disc, HUD-tinted
  rings, own marker, a north tick that turns with heading, and the scanner
  range. Hostile crewed vehicles show as blips too.
- **Placement.** Edge presets keep clear of the visor's blue bands (top
  5 %, bottom 9.5 %), so the bottom-left trooper no longer sits on them.
- **cTab link.** Every Shift+H press now reports what it tried; if cTab
  doesn't open within 2 s the HUD says so and the RPT says why. New ACE
  self-interaction menu *Clone HUD* (Open cTab / Open MicroDAGR / Helm Cam /
  Next Helm Cam / Close Link) as a second way in.

## Settings

Everything's in the CBA settings menu (*Configure > Addon Options*), split
into two pages so players only see what they'd actually change:

**885th Clone HUD** (per player)
1. *What's On Screen* - visor, readout, system messages, squad list, radar,
   squad medical (+ alerts), tactical link panel, trooper ACE data.
2. *Layout - Trooper Status / Squad List / Radar / Tactical Link Panel* -
   position preset or custom X/Y, plus scale. Changes apply live.
3. *Vanilla HUD* - which vanilla / DUI elements the Clone HUD hides.
4. *Look & Colors* - HUD color, visor opacity and NV / thermal tint,
   readout colors.
5. *cTab Link* - helm cam squad-only filter.

**885th Clone HUD (Server & Advanced)** - kill switch, auto-start, medic-only
details, helmet cam rules, scanner / low light limits, indicator and scanner
colors, scanner icons, radar texture, boot-up text, textures, helmet lists.

Setting variable names didn't change in the regroup, so saved values carry
over.

**Clean defaults** - a new player gets: trooper bottom-left (0.8x), squad
list middle-left (0.85x) with medical *status only*, radar bottom-center
(0.8x), tactical link panel hidden until a link is in use (Shift+H / Shift+J
or the ACE *Clone HUD* menu), vanilla weapon info / compass / radar / squad
bar and DUI hidden while the HUD is up. Everything else is opt-in.
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
