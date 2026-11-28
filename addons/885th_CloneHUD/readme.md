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
  full-screen canvas, so all three armor tiers land on the same spot
  at the same size (the slimmer RC trooper is widened to match).
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

## 1.4.0 - Jamming, Tac Map, Intel Log panel, comms wording

- **Jamming** (`scripts/jamming.sqf`, *8. Intel & Jamming*). Sources:
  Crows EW jammers (`crowsew_main_jamMap`), 885th HUD jammers placed by
  Zeus (ZEN *885th Clone HUD > Add / Remove HUD Jammer*, falloff +
  effective radius; they also cut TFAR range like Crows EW), and any
  other TFAR jamming read back from `tf_sending/receivingDistance-
  Multiplicator`. Tiers: 20 % COMMS DEGRADED (warning), 50 % COMMS
  LOST (datalink down: radio rows, squad list data -> "DATALINK LOST",
  pings / intel, medic pings, helm cam), 85 % SENSORS JAMMED (scanner
  markers + radar off). Warning shows in the comms list area even with
  the comms display off; optional visor film-grain static.
- **Tac Map** link mode (*Shift+H* cycle / ACE *Clone HUD > Tac Map*):
  BFT mini-map in the tactical link panel, centered on you, drawn with
  cTab's own `cTab_fnc_drawBftMarkers` / `drawUserMarkers` plus HUD
  pings / intel markers; grid + heading under it. Needs a cTab device
  (server setting). Zoom / height in *5. Helm Cam & cTab*. Jammed:
  own position only, DATALINK LOST.
- **Intel Log** is now a HUD panel (*2. Layout - Intel Log*), open from
  the ACE menu or the *Show / Hide Intel Log* keybind (unbound by
  default), stays up *Intel Log Time* seconds (0 = toggle).
- **Comms rows** read "Sending... <your radio>" / "Receiving... <your
  radio it came in on>  <who>  <channel>", then "Sent" / "Received"
  dimmed after release.
- **Jammer devices** (ZEN *885th Clone HUD > Place Jammer Device*): a
  physical jammer troopers must find and kill to get their HUD back.
  Pick a prop (data terminal, assembled device, antenna, server, computer,
  generator, radio mast, the object you dropped it on, or any custom
  classname), falloff / effective radius, hits to destroy, disable time,
  and who can disable it (anyone / engineers + EOD). Killed by direct hits
  (explosive rounds kill outright), grenades / launchers / placed charges
  within their blast, the prop itself being destroyed, or *Disable Jammer*
  (ACE interaction, hold action without ACE). Smoke + flash, "JAMMER
  DESTROYED / DISABLED by <name>" for everyone it affected, then COMMS
  RESTORED. Eden: in the object's init,
  `this setVariable ["BPD_CloneHUD_jammer", [600, 200]]; this setVariable ["BPD_CloneHUD_jamDevice", [10, 8, 0]];`
  ([falloff, effective], [hits, disable seconds, 0 anyone / 1 engineers]).
- **Scanner line of sight** (Server & Advanced > 4. Scanner Icons):
  scanner icons need real visibility (`checkVisibility` - smoke, foliage,
  buildings), not just a clear geometry line. When sight is lost a faded
  "?" icon stays at the last known position for *Last Known Position
  Time* (default 10 s) and fades out. *Visibility Needed* (0.3) sets how
  thick the smoke has to be. Turn *Scanner Needs Line of Sight* off for
  the old walls/terrain-only check.
- **Mine Detector** (10. Mine Detector, `scripts/minedetect.sqf`): an
  engineer role function like medic pings. Only an engineer / EOD carrying
  a mine detector (vanilla MineDetector, ACE VMM3 / VMH3, or Extra Detector
  Classes) gets it, unless the server loosens *Who Gets It*. Scans
  *Detection Range* around the trooper without holding the detector:
  "MINE DETECTED - 8m NE" message + tone, the mine is revealed, a
  "MINE 6m" marker (red + pulsing inside *Danger Distance*), proximity
  beeps, and found mines shared to the squad's HUDs. Jamming tier 3
  knocks it out; tier 2+ stops squad sharing. *Toggle Mine Detector*
  keybind is unbound by default.
- **Tac Map Device Frame** (5. Helm Cam & cTab): the Tac Map sits inside
  the 885th cTab device art (`\cTab\img\*_background_ca.paa`) - Auto
  picks the device carried (Tablet > Holo-pad > DAGR), or force DAGR /
  Holo-pad / Tablet / None. The device is scaled to the panel width and
  the map fills its screen opening; Tac Map Height only applies to None.
- **Comms List Style** (9. Radio Comms): *Default* (one row per
  transmission) or *Grouped* - one vertical block with a **Sending**
  heading over your transmissions and a **Receiving** heading over
  incoming ones. Jamming shows on the headings: RANGE REDUCED / DEGRADED
  at tier 1, JAMMED / COMMS LOST + "No signal" at tier 2+, and both
  headings stay up while jammed. Rows setting counts per heading.
- **Role life indicators** (Server & Advanced > 8. Helmet Lists): ARF,
  Scout, BARC, Pilot, Airborne and Engineer troopers get their own trooper
  figure (`textures\<Role>`) while keeping their Phase 1 / Phase 2 visor
  frame. Six lists pick the helmets (an unlisted helmet whose classname
  says pilot / BARC / scout / _ARF / engineer / _AB_ falls back to that
  role); a helmet still has to be in a P1 / P2 list to get the HUD. The
  figure refreshes on any helmet swap, ACE Arsenal included. All six are the P2 figure with a helmet traced from a reference
  image (Pilot also has the chest life-support box), so they use the P2
  art box and come out the same size.
- **Fire mode and zeroing** (1. What's On Screen): SEMI / BURST / AUTO
  under the weapon picture and the zeroing (e.g. 300 m) above it on
  Style A / B; fire mode under the box on the Default info display.
- **Haywire When Down** (`scripts\downed.sqf`): while you're unconscious
  the HUD glitches; on waking it does a fast reboot (layers back one by
  one, "SUIT SYSTEMS RESTORED"). **Vital Signs Lost**: on KIA, full-screen
  static (`textures\hcam\kia_static_*`) with a low flatline
  (`sounds\hud_flatline.wav`), then SIGNAL LOST, then fade out.
- **Helm cam signal loss**: when the trooper you're watching goes down,
  the feed breaks up into static, shows SIGNAL LOST and moves to the
  next trooper; downed troopers are skipped when cycling.
- **HUD crosshair** (`scripts\crosshair.sqf`, 1. What's On Screen): Off /
  Segmented Ring / Broken Ring / Plain Ring (`textures\crosshair`), with
  size and opacity. First person with a weapon up, hidden when aiming
  down sights, on the map, in Zeus or when the HUD isn't booted.
- **EMP** (`scripts\emp.sqf`, settings 12. EMP): caught in an EMP blast
  (via 885_Armor's EMP detector) with the HUD up - static burst, then the
  HUD goes haywire with an offline countdown while every suit system is
  down (radar, scanner, low light, mine detector, squad list, pings, Tac
  Map, cTab link, helm cam), then the fast reboot. RC helmets are
  hardened (x0.5), Phase 1 takes longer (x1.25). ACE "Emergency Suit
  Reboot" (self, 3 s) and engineer "Reboot Suit" (4 s) cut it short.
  Small chance of an electric burn on the visor (`textures\emp`).
  Test: `[player] call BPD_CloneHUD_fnc_empHit;`
- **Flashing Effects** (Off / Reduced / Full, default Reduced, per player)
  controls how much those glitch / static effects flicker.
- **System messages** all stay 30 s. Mine detector messages no longer
  fall back to side chat.
- **885th helmets only**: every helmet list ships with 885th helmets
  only (3AS stock helmets were removed). Add a 3AS classname to a list
  in Addon Options to give it the HUD again.
- **Cracked Visor** (11. Cracked Visor, `scripts/visorcrack.sqf`), Republic
  Commando style: a critical headshot (one head hit at or over *Headshot
  Threshold*) or an explosion that does at least *Blast Threshold* to your
  body cracks your clone helmet's visor, with an armored-glass hit sound.
  Cracks are random - 19 textures in `textures/crack/` (3 bullet
  spiderwebs, 2 small chips, 2 long stress fractures, 2 rim impacts,
  2 star bursts, 2 full shatters, 2 blaster-volley clusters, 2 glancing
  grazes, 2 edge-to-edge splits) at a random spot, size and rotation.
  Headshots favour webs / stars / grazes near the middle, blasts favour
  rim impacts, clusters, shatters and splits (1-2 at once). They stack up to
  *Max Cracks*, sit above every HUD element on their own layer
  (`BPD_CloneHUD_CRACK_BASE`), and hide in third person / map / Zeus.
  Only **Republic Commando helmets** (the RC helmet list) can wipe: the
  *Wipe Visor (RC helmets)* keybind (unbound), ACE self-interaction >
  Equipment > Wipe Visor, or the scroll action without ACE - and on their
  own *RC Auto Wipe After* seconds (default 20) after the last crack. A
  wiper sweeps across (at 0.8x speed, `_speed` in `crackWipe`) and clears
  it; *Wipe Cooldown* (default 5 s) spaces wipes. Phase 1 / 2 cracks stay until a helmet swap or
  respawn, or *Non-RC Cracks Last* seconds. **Engineers can repair any
  tier's visor**: ACE interact with the trooper > *Repair Visor* (or self
  > Equipment > Repair Visor), with a progress bar of *Repair Time*
  (default 8 s); without ACE it's a hold action while looking at them.
  *Who Can Repair* (Nobody / Engineers / Anyone) and *Repair Needs
  Toolkit* are server settings. The trooper's machine shares a public
  `BPD_CloneHUD_cracked` flag so the action only shows when there's
  something to fix. Damage comes from the ACE
  `ace_medical_woundReceived` event (old and 3.16+ formats), or a
  `Dammaged` handler without ACE medical. Debug console test:
  `["head"] call BPD_CloneHUD_fnc_crackAdd;` / `["blast"] call ...`.
- **Cover** (*Cover Blocks Blast Cracks*, on): a blast with walls,
  floors or terrain between your eyes and where it went off doesn't crack
  the visor, so a mortar outside your building no longer does. Blast spot
  unknown + under a building roof = double *Blast Threshold*.
- **Visor dirt** (*Visor Dirt*, on): every explosive that goes off near
  you in the open (2x its blast radius, max 35 m, no cover between) throws
  1-2 of 10 random dirt overlays (`textures/dirt/`: mud splatter, dust,
  smear, water spots, corner grime, sand spray, mud drip, soot, clumps,
  dust film), hurt or not. *Max Dirt* (3), *Dirt Lasts* (90 s, any
  helmet), *Dirt Opacity*. RC wipes and repairs clear it with the cracks;
  dirt alone doesn't offer a repair. Detection: `ProjectileCreated`
  mission event + projectile `Explode` handler, with the player's
  `Explosion` handler as a fallback. Test: `[2] call BPD_CloneHUD_fnc_dirtAdd;`.
- **Repair Visor** now plays the same wiper sweep as the RC wipe.

## 1.4.0 - Kill Counter

- Counts the enemies you kill this mission, per enemy type (vehicle
  turret kills count; friendlies, civilians and your own death don't).
  Totals survive respawns and reset with a new mission.
- Press **Show / Hide Kill Counter** (unbound by default) or ACE self >
  Clone HUD > Kill Counter. It types in "> READING COMBAT LOG..." /
  "> CONFIRMED KILLS", an INFANTRY / VEHICLES total line, then your
  top 4 as name and total, in Orbitron. Vehicle crew killed inside
  count as infantry, the vehicle itself as a vehicle.
- Fades after **Kill Counter Time** (default 15 s, 0 = until the key
  is pressed again). Press the key again to hide it early. **Kill
  Counter** checkbox turns the feature off.
- Survives leaving and rejoining the same mission: totals are saved
  as a public mission variable per player UID (every 5 s after a new
  kill), which Arma re-sends to joining players. No server script.
- Everything (on/off, time, position, scale) is on one page:
  **2. Layout - Kill Counter**.
- Font: Orbitron by Matt McInerney, SIL Open Font License 1.1,
  converted with Arma 3 Tools FontToTGA and registered as `BPD_Orbitron`.

## 1.4.0 - Intel: spotting pings + broadcasts

See the header of `scripts/intel.sqf`. Settings: *885th Clone HUD > 8.
Intel*.

- **Spot / Ping Target** (keybind, default Shift+T, needs a booted
  HUD): marks what you aim at. Own squad (or friendlies in range) gets
  a HUD line - CONTACT / FRIENDLY / CIVILIAN / MARK, what it is ("3x
  Infantry", vehicle name), distance + bearing from *their* position,
  and who called it (fireteam label for own squad) - plus a 3D marker
  where it was spotted, fading after 20 s. The marker stays at the
  spotted position (callout, not a tracker). One ping per sender.
- **Send Intel...** (ACE self-interaction *Clone HUD*; squad leaders +
  Zeus by default): typed message as INTEL / PRIORITY / OBJECTIVE to
  own squad or all friendlies, optional marker at your aim point.
  Zeus gets the ZEN module *885th Clone HUD > Send HUD Intel* (targets
  a side, everyone, or the squad of the unit it's placed on; marker at
  the module position). Players without a booted HUD get chat + hint.
- **Intel Log** (same ACE menu): last 10 pings / intel received.
- Sent with remoteExec to the clients in scope only, data only.
- **Radio comms strip** (TFAR; `scripts/comms.sqf`): up to 4 rows -
  RX/TX, who (fireteam label for own squad), the SR/LR channel number
  it came in on *for you* (ALT = additional channel), frequency name
  (from *Frequency Names*, e.g. `31=Platoon, 40=Air`) and frequency.
  Only shown to players with a radio on that frequency + encryption
  code and within the sender's radio range (straight-line, no terrain).
  Rows dim and drop a few seconds after release. Hooks TFAR's
  `OnTangent` event on the sender; nothing happens without TFAR.
  Every trooper picks their own displays in *9. Radio Comms*: Comms
  List (default on, *2. Layout - Radio Comms*, 1-6 rows), One-Line
  Ticker (*2. Layout - Radio Ticker*), Speaker Tag over the
  transmitter's head (range-limited), Radio Icon in the Squad List;
  plus Channel Label format (name + channel + freq / name only /
  channel + freq), show own TX, linger time. Only Frequency Names is a
  server setting. Hiding comms on your own HUD never stops others
  seeing your transmissions.

## 1.3.0 - Ammo counter styles, medic pings, movable trooper stand

**Ammo Counter Style** (*885th Clone HUD > 1. What's On Screen*, per
player): Default (the helmet's own info box), Style A (BF2 Classic - wide
panel: weapon icon, rounds, spare mags, grenade icon + how many of the
selected throwable you carry) or Style B
(Classic Inspired - compact: grenade badge, weapon plate). Placed with
*2. Layout - Ammo Counter* (default Bottom Right). With A or B the helmet
info box swaps to a version without its ammo column
(`textures\ammo\*_ammoDisplay_noAmmo.paa`) and keeps heading/range.

**Ammo Counter Vitals** (A/B only, default on): no generic health or
stamina bars - the bar and status line use the same ACE / KAT reading
as the squad list (`BPD_CloneHUD_fnc_medStatus`). Bar fill = worst of
blood volume (full 6 L, empty 3 L) and SpO2 (full 100 %, empty 70 %;
KAT's value when loaded); bar color + status word follow the medical
state (OK / TREATED / WOUNDED / BLEEDING / CRITICAL / DOWN / ARREST +
rhythm), followed by up to three tags (BLD %, AIRWAY, TENSION PTX, INT
BLEED, SpO2, TQ, FRACTURE, PAIN). No ACE: 1 - damage. Off = a smaller
panel without the bar (`*_panel_noBars.paa`). Panel art is
original, drawn for this mod.

**Medic pings** (*885th Clone HUD > 7. Medic Pings*). If you're a medic
(ACE medic class / `attendant`, vanilla medic trait, or Green Team when
that option is on) you get a **MEDIC NEEDED: name - state - 230m NE**
message, a sound, and a pulsing medical marker over the casualty when a
trooper reaches the ping threshold (default: down / cardiac arrest;
optionally "serious or worse"). A reminder repeats every 60 s while they
stay there, and the marker clears once they're stabilized. Scope: own
squad, all friendly players in range (default, 1000 m), or all friendlies
including AI. Each client reads the broadcast ACE/KAT variables itself,
so nothing extra goes over the network. Falls back to systemChat when
the HUD isn't up.

**Trooper stand moves with the trooper.** The faint silhouette + base
ring under the limb indicator was painted into the interior overlay
textures, so it stayed in the corner when the trooper was moved. It's
now split into its own textures (`P1/P2/RC_trooperBase.paa`, settings
under *Server & Advanced > 7. Textures*) and drawn in the same rect as
the limb art. The interior overlays no longer contain it.

The trooper is placed under *885th Clone HUD > 2. Layout - Trooper
Status* (Position presets or Custom + X/Y sliders, Scale).

## Squad marker team labels

Your own squadmates' 3D scanner markers carry their fireteam label above
their head, in the team's color: `Red Team 1`, `Blue Team 2`, `Medic 1`...
(*885th Clone HUD > 6. Squad Markers*).

- Numbered within each team color, in squad order, from `assignedTeam`
  (the same team colors ACE's team menu and DUI use).
- Names per color are server settings (defaults: Red Team, Blue Team,
  Medic for green, Yellow Team, Squad for unassigned) so the whole unit
  shares callsigns. The squad leader shows as `Lead` (blank = numbered in
  their team like everyone else).
- Only your squad gets labels; other friendlies keep a plain marker.
  Labels follow the scanner: they show for squadmates the scanner can see
  (in range and line of sight) while scanner icons are on (Alt+T).

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
    killCounter.sqf        (per-mission kill counter panel)
  fonts/Orbitron/         (Orbitron 12-46, FontToTGA output, font BPD_Orbitron)
  textures/               (helmet overlays, indicator icons, scanner icons)
  sounds/                 (typing, glitch, glitch_short, threat_detector)
```

## Building

Same as your usual workflow: point Addon Builder at this folder on
your P: drive, build `885th_CloneHUD.pbo`, sign as normal for your
dedicated server key set. Add `cba_main` to your mod list/mission
dependency if it isn't already there — no ACE required.
