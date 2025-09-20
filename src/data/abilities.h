const struct Ability gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING(""),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("Stench"),
        .description = COMPOUND_STRING("May cause a foe to flinch."),
        .aiRating = 1,
        .category = AC_ON_ATTACK,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("Drizzle"),
        .description = COMPOUND_STRING("Summons rain in battle."),
        .aiRating = 9,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("Speed Boost"),
        .description = COMPOUND_STRING("Gradually boosts Speed."),
        .aiRating = 9,
        .category = AC_EOT,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("Battle Armor"),
        .description = COMPOUND_STRING("Blocks critical hits."),
        .aiRating = 2,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("Sturdy"),
        .description = COMPOUND_STRING("Negates 1-hit KO attacks."),
        .aiRating = 6,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("Damp"),
        .description = COMPOUND_STRING("Prevents self-destruction."),
        .aiRating = 2,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("Limber"),
        .description = COMPOUND_STRING("Prevents paralysis."),
        .aiRating = 3,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("Sand Veil"),
        .description = COMPOUND_STRING("Ups evasion in a sandstorm."),
        .aiRating = 3,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("Static"),
        .description = COMPOUND_STRING("Paralyzes on contact."),
        .aiRating = 4,
        .category = AC_ON_HIT,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("Volt Absorb"),
        .description = COMPOUND_STRING("Turns electricity into HP."),
        .aiRating = 7,
        .breakable = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("Water Absorb"),
        .description = COMPOUND_STRING("Changes water into HP."),
        .aiRating = 7,
        .breakable = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("Oblivious"),
        .description = COMPOUND_STRING("Prevents attraction."),
        .aiRating = 2,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("Cloud Nine"),
        .description = COMPOUND_STRING("Negates weather effects."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },

    [ABILITY_COMPOUND_EYES] =
    {
        .name = _("Compound Eyes"),
        .description = COMPOUND_STRING("Raises accuracy."),
        .aiRating = 7,
        .category = AC_PASSIVE,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("Insomnia"),
        .description = COMPOUND_STRING("Prevents sleep."),
        .aiRating = 4,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("Color Change"),
        .description = COMPOUND_STRING("Changes type to foe's move."),
        .aiRating = 2,
        .category = AC_ON_HIT,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("Immunity"),
        .description = COMPOUND_STRING("Prevents poisoning."),
        .aiRating = 4,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("Flash Fire"),
        .description = COMPOUND_STRING("Powers up if hit by fire."),
        .aiRating = 6,
        .breakable = TRUE,
        .category = AC_ON_HIT,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("Shield Dust"),
        .description = COMPOUND_STRING("Prevents added effects."),
        .aiRating = 5,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("Own Tempo"),
        .description = COMPOUND_STRING("Prevents confusion."),
        .aiRating = 3,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("Suction Cups"),
        .description = COMPOUND_STRING("Firmly anchors the body."),
        .aiRating = 2,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("Intimidate"),
        .description = COMPOUND_STRING("Lowers the foe's Attack."),
        .aiRating = 7,
        .category = AC_SWITCH_IN,
        .cd = TARC_INTIMIDATE_CD,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("Shadow Tag"),
        .description = COMPOUND_STRING("Prevents the foe's escape."),
        .aiRating = 10,
        .category = AC_PASSIVE,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("Rough Skin"),
        .description = COMPOUND_STRING("Hurts to touch."),
        .aiRating = 6,
        .category = AC_ON_HIT,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("Wonder Guard"),
        .description = COMPOUND_STRING("Only “Supereffective” hits."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("Levitate"),
        .description = COMPOUND_STRING("Not hit by Ground attacks."),
        .aiRating = 7,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("Effect Spore"),
        .description = COMPOUND_STRING("Leaves spores on contact."),
        .aiRating = 4,
        .category = AC_ON_HIT,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("Synchronize"),
        .description = COMPOUND_STRING("Passes on status problems."),
        .aiRating = 4,
        .category = AC_TRIGGERED,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("Clear Body"),
        .description = COMPOUND_STRING("Prevents ability reduction."),
        .aiRating = 4,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("Natural Cure"),
        .description = COMPOUND_STRING("Heals upon switching out."),
        .aiRating = 7,
        .category = AC_SWITCH_OUT,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("Lightning Rod"),
        .description = COMPOUND_STRING("Draws electrical moves."),
        .aiRating = 7,
        .breakable = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("Serene Grace"),
        .description = COMPOUND_STRING("Promotes added effects."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("Swift Swim"),
        .description = COMPOUND_STRING("Raises Speed in rain."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("Chlorophyll"),
        .description = COMPOUND_STRING("Raises Speed in sunshine."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("Illuminate"),
        .description = COMPOUND_STRING("Encounter rate increases."),
        .aiRating = 0,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("Trace"),
        .description = COMPOUND_STRING("Copies special ability."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("Huge Power"),
        .description = COMPOUND_STRING("Raises Attack."),
        .aiRating = 10,
        .category = AC_PASSIVE,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("Poison Point"),
        .description = COMPOUND_STRING("Poisons foe on contact."),
        .aiRating = 4,
        .category = AC_ON_HIT,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("Inner Focus"),
        .description = COMPOUND_STRING("Prevents flinching."),
        .aiRating = 2,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("Magma Armor"),
        .description = COMPOUND_STRING("Prevents freezing."),
        .aiRating = 1,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("Water Veil"),
        .description = COMPOUND_STRING("Prevents burns."),
        .aiRating = 4,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("Magnet Pull"),
        .description = COMPOUND_STRING("Traps Steel-type Pokémon."),
        .aiRating = 9,
        .category = AC_PASSIVE,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("Soundproof"),
        .description = COMPOUND_STRING("Avoids sound-based moves."),
        .aiRating = 4,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("Rain Dish"),
        .description = COMPOUND_STRING("Slight HP recovery in rain."),
        .aiRating = 3,
        .category = AC_EOT,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("Sand Stream"),
        .description = COMPOUND_STRING("Summons a sandstorm."),
        .aiRating = 9,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("Pressure"),
        .description = COMPOUND_STRING("Raises foe's PP usage."),
        .aiRating = 5,
        .category = AC_ON_HIT,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("Thick Fat"),
        .description = COMPOUND_STRING("Heat-and-cold protection."),
        .aiRating = 7,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("Early Bird"),
        .description = COMPOUND_STRING("Awakens quickly from sleep."),
        .aiRating = 4,
        .category = AC_PASSIVE,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("Flame Body"),
        .description = COMPOUND_STRING("Burns the foe on contact."),
        .aiRating = 4,
        .category = AC_ON_HIT,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("Run Away"),
        .description = COMPOUND_STRING("Makes escaping easier."),
        .aiRating = 0,
        .category = AC_PASSIVE,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("Keen Eye"),
        .description = COMPOUND_STRING("Prevents loss of accuracy."),
        .aiRating = 1,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("Hyper Cutter"),
        .description = COMPOUND_STRING("Prevents Attack reduction."),
        .aiRating = 3,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("Pickup"),
        .description = COMPOUND_STRING("May pick up items."),
        .aiRating = 1,
        .category = AC_TRIGGERED,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("Truant"),
        .description = COMPOUND_STRING("Moves only every two turns."),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("Hustle"),
        .description = COMPOUND_STRING("Trades accuracy for power."),
        .aiRating = 7,
        .category = AC_PASSIVE,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("Cute Charm"),
        .description = COMPOUND_STRING("Infatuates on contact."),
        .aiRating = 2,
        .category = AC_ON_HIT,
    },

    [ABILITY_PLUS] =
    {
        .name = _("Plus"),
        .description = COMPOUND_STRING("Powers up with Minus."),
        .aiRating = 0,
        .category = AC_PASSIVE,
    },

    [ABILITY_MINUS] =
    {
        .name = _("Minus"),
        .description = COMPOUND_STRING("Powers up with Plus."),
        .aiRating = 0,
        .category = AC_PASSIVE,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("Forecast"),
        .description = COMPOUND_STRING("Changes with the weather."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("Sticky Hold"),
        .description = COMPOUND_STRING("Prevents item theft."),
        .aiRating = 3,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("Shed Skin"),
        .description = COMPOUND_STRING("Heals the body by shedding."),
        .aiRating = 7,
        .category = AC_EOT,
    },

    [ABILITY_GUTS] =
    {
        .name = _("Guts"),
        .description = COMPOUND_STRING("Ups Attack if suffering."),
        .aiRating = 6,
        .category = AC_TRIGGERED,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("Marvel Scale"),
        .description = COMPOUND_STRING("Ups Defense if suffering."),
        .aiRating = 5,
        .breakable = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("Liquid Ooze"),
        .description = COMPOUND_STRING("Draining causes injury."),
        .aiRating = 3,
        .category = AC_TRIGGERED,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("Overgrow"),
        .description = COMPOUND_STRING("Ups Grass moves in a pinch."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("Blaze"),
        .description = COMPOUND_STRING("Ups Fire moves in a pinch."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("Torrent"),
        .description = COMPOUND_STRING("Ups Water moves in a pinch."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },

    [ABILITY_SWARM] =
    {
        .name = _("Swarm"),
        .description = COMPOUND_STRING("Ups Bug moves in a pinch."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("Rock Head"),
        .description = COMPOUND_STRING("Prevents recoil damage."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("Drought"),
        .description = COMPOUND_STRING("Summons sunlight in battle."),
        .aiRating = 9,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("Arena Trap"),
        .description = COMPOUND_STRING("Prevents fleeing."),
        .aiRating = 9,
        .category = AC_PASSIVE,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("Vital Spirit"),
        .description = COMPOUND_STRING("Prevents sleep."),
        .aiRating = 4,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("White Smoke"),
        .description = COMPOUND_STRING("Prevents ability reduction."),
        .aiRating = 4,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("Pure Power"),
        .description = COMPOUND_STRING("Raises Attack."),
        .aiRating = 10,
        .category = AC_PASSIVE,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("Shell Armor"),
        .description = COMPOUND_STRING("Blocks critical hits."),
        .aiRating = 2,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("Air Lock"),
        .description = COMPOUND_STRING("Negates weather effects."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("Tangled Feet"),
        .description = COMPOUND_STRING("Ups evasion if confused."),
        .aiRating = 2,
        .breakable = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("Motor Drive"),
        .description = COMPOUND_STRING("Electricity raises Speed."),
        .aiRating = 6,
        .breakable = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("Rivalry"),
        .description = COMPOUND_STRING("Powers up against rivals."),
        .aiRating = 1,
        .category = AC_PASSIVE,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("Steadfast"),
        .description = COMPOUND_STRING("Flinching raises Speed."),
        .aiRating = 2,
        .category = AC_TRIGGERED,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("Snow Cloak"),
        .description = COMPOUND_STRING("Ups evasion in Hail or Snow."),
        .aiRating = 3,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("Gluttony"),
        .description = COMPOUND_STRING("Eats Berries early."),
        .aiRating = 3,
        .category = AC_PASSIVE,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("Anger Point"),
        .description = COMPOUND_STRING("Critical hits raise Attack."),
        .aiRating = 4,
        .category = AC_TRIGGERED,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("Unburden"),
        .description = COMPOUND_STRING("Using a hold item ups Speed."),
        .aiRating = 7,
        .category = AC_TRIGGERED,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("Heatproof"),
        .description = COMPOUND_STRING("Heat and burn protection."),
        .aiRating = 5,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("Simple"),
        .description = COMPOUND_STRING("Prone to wild stat changes."),
        .aiRating = 8,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("Dry Skin"),
        .description = COMPOUND_STRING("Prefers moisture to heat."),
        .aiRating = 6,
        .breakable = TRUE,
        .category = AC_EOT,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("Download"),
        .description = COMPOUND_STRING("Adjusts power favorably."),
        .aiRating = 7,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("Iron Fist"),
        .description = COMPOUND_STRING("Boosts punching moves."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("Poison Heal"),
        .description = COMPOUND_STRING("Restores HP if poisoned."),
        .aiRating = 8,
        .category = AC_EOT,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("Adaptability"),
        .description = COMPOUND_STRING("Boosts same type attacks."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("Skill Link"),
        .description = COMPOUND_STRING("Multi-hit moves hit 5 times."),
        .aiRating = 7,
        .category = AC_PASSIVE,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("Hydration"),
        .description = COMPOUND_STRING("Cures status in rain."),
        .aiRating = 4,
        .category = AC_EOT,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("Solar Power"),
        .description = COMPOUND_STRING("Powers up in sunshine."),
        .aiRating = 3,
        .category = AC_PASSIVE,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("Quick Feet"),
        .description = COMPOUND_STRING("Ups Speed if suffering."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("Normalize"),
        .description = COMPOUND_STRING("Moves become Normal-type."),
        .aiRating = -1,
        .category = AC_PASSIVE,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("Sniper"),
        .description = COMPOUND_STRING("Boosts critical hits."),
        .aiRating = 3,
        .category = AC_PASSIVE,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("Magic Guard"),
        .description = COMPOUND_STRING("Only damaged by attacks."),
        .aiRating = 9,
        .category = AC_PASSIVE,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("No Guard"),
        .description = COMPOUND_STRING("Ensures that all moves hit."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },

    [ABILITY_STALL] =
    {
        .name = _("Stall"),
        .description = COMPOUND_STRING("Always moves last."),
        .aiRating = -1,
        .category = AC_PASSIVE,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("Technician"),
        .description = COMPOUND_STRING("Boosts weaker moves."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("Leaf Guard"),
        .description = COMPOUND_STRING("Blocks status in sunshine."),
        .aiRating = 2,
        .breakable = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("Klutz"),
        .description = COMPOUND_STRING("Can't use hold items."),
        .aiRating = -1,
        .category = AC_PASSIVE,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("Mold Breaker"),
        .description = COMPOUND_STRING("Moves hit through abilities."),
        .aiRating = 7,
        .category = AC_PASSIVE,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("Super Luck"),
        .description = COMPOUND_STRING("Critical hits land often."),
        .aiRating = 3,
        .category = AC_PASSIVE,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("Aftermath"),
        .description = COMPOUND_STRING("Fainting damages the foe."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("Anticipation"),
        .description = COMPOUND_STRING("Senses dangerous moves."),
        .aiRating = 2,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("Forewarn"),
        .description = COMPOUND_STRING("Determines a foe's move."),
        .aiRating = 2,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("Unaware"),
        .description = COMPOUND_STRING("Ignores stat changes."),
        .aiRating = 6,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("Tinted Lens"),
        .description = COMPOUND_STRING("Ups “not very effective”."),
        .aiRating = 7,
        .category = AC_PASSIVE,
    },

    [ABILITY_FILTER] =
    {
        .name = _("Filter"),
        .description = COMPOUND_STRING("Weakens “supereffective”."),
        .aiRating = 6,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("Slow Start"),
        .description = COMPOUND_STRING("Takes a while to get going."),
        .aiRating = -2,
        .category = AC_TRIGGERED,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("Scrappy"),
        .description = COMPOUND_STRING("Hits Ghost-type Pokémon."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("Storm Drain"),
        .description = COMPOUND_STRING("Draws in Water moves."),
        .aiRating = 7,
        .breakable = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("Ice Body"),
        .description = COMPOUND_STRING("HP recovery in Hail or Snow."),
        .aiRating = 3,
        .category = AC_EOT,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("Solid Rock"),
        .description = COMPOUND_STRING("Weakens “supereffective”."),
        .aiRating = 6,
        .breakable = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("Snow Warning"),
    #if B_SNOW_WARNING >= GEN_9
        .description = COMPOUND_STRING("Summons snow in battle."),
    #else
        .description = COMPOUND_STRING("Summons hail in battle."),
    #endif
        .aiRating = 8,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("Honey Gather"),
        .description = COMPOUND_STRING("May gather Honey."),
        .aiRating = 0,
        .category = AC_TRIGGERED,
    },

    [ABILITY_FRISK] =
    {
        .name = _("Frisk"),
        .description = COMPOUND_STRING("Checks a foe's item."),
        .aiRating = 3,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("Reckless"),
        .description = COMPOUND_STRING("Boosts moves with recoil."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("Multitype"),
        .description = COMPOUND_STRING("Changes type to its Plate."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_FLOWER_GIFT] =
    {
        .name = _("Flower Gift"),
        .description = COMPOUND_STRING("Allies power up in sunshine."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("Bad Dreams"),
        .description = COMPOUND_STRING("Damages sleeping Pokémon."),
        .aiRating = 4,
        .category = AC_EOT,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("Pickpocket"),
        .description = COMPOUND_STRING("Steals the foe's held item."),
        .aiRating = 3,
        .category = AC_ON_ATTACK,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("Sheer Force"),
        .description = COMPOUND_STRING("Trades effects for power."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("Contrary"),
        .description = COMPOUND_STRING("Inverts stat changes."),
        .aiRating = 8,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("Unnerve"),
        .description = COMPOUND_STRING("Foes can't eat Berries."),
        .aiRating = 3,
        .category = AC_PASSIVE,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("Defiant"),
        .description = COMPOUND_STRING("Lowered stats up Attack."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("Defeatist"),
        .description = COMPOUND_STRING("Gives up at half HP."),
        .aiRating = -1,
        .category = AC_TRIGGERED,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("Cursed Body"),
        .description = COMPOUND_STRING("Disables moves on contact."),
        .aiRating = 4,
        .category = AC_ON_HIT,
    },

    [ABILITY_HEALER] =
    {
        .name = _("Healer"),
        .description = COMPOUND_STRING("Heals partner Pokémon."),
        .aiRating = 0,
        .category = AC_EOT,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("Friend Guard"),
        .description = COMPOUND_STRING("Lowers damage to partner."),
        .aiRating = 0,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("Weak Armor"),
        .description = COMPOUND_STRING("Its stats change when hit."),
        .aiRating = 2,
        .category = AC_ON_HIT,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("Heavy Metal"),
        .description = COMPOUND_STRING("Doubles weight."),
        .aiRating = -1,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("Light Metal"),
        .description = COMPOUND_STRING("Halves weight."),
        .aiRating = 2,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("Multiscale"),
        .description = COMPOUND_STRING("Halves damage at full HP."),
        .aiRating = 8,
        .breakable = TRUE,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("Toxic Boost"),
        .description = COMPOUND_STRING("Ups Attack if poisoned."),
        .aiRating = 6,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("Flare Boost"),
        .description = COMPOUND_STRING("Ups Sp. Atk if burned."),
        .aiRating = 5,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("Harvest"),
        .description = COMPOUND_STRING("May recycle a used Berry."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("Telepathy"),
        .description = COMPOUND_STRING("Can't be damaged by an ally."),
        .aiRating = 0,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("Moody"),
        .description = COMPOUND_STRING("Stats change gradually."),
        .aiRating = 10,
        .category = AC_EOT,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("Overcoat"),
        .description = COMPOUND_STRING("Blocks weather and powder."),
        .aiRating = 5,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("Poison Touch"),
        .description = COMPOUND_STRING("Poisons foe on contact."),
        .aiRating = 4,
        .category = AC_ON_ATTACK,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("Regenerator"),
        .description = COMPOUND_STRING("Heals upon switching out."),
        .aiRating = 8,
        .category = AC_SWITCH_OUT,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("Big Pecks"),
        .description = COMPOUND_STRING("Prevents Defense loss."),
        .aiRating = 1,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("Sand Rush"),
        .description = COMPOUND_STRING("Ups Speed in a sandstorm."),
        .aiRating = 6,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("Wonder Skin"),
        .description = COMPOUND_STRING("May avoid status problems."),
        .aiRating = 4,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("Analytic"),
        .description = COMPOUND_STRING("Moving last boosts power."),
        .aiRating = 5,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("Illusion"),
        .description = COMPOUND_STRING("Appears as a partner."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .category = AC_SWITCH_IN
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("Imposter"),
        .description = COMPOUND_STRING("Transforms into the foe."),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
        .category = AC_SWITCH_IN
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("Infiltrator"),
        .description = COMPOUND_STRING("Passes through barriers."),
        .aiRating = 6,
        .category = AC_PASSIVE
    },

    [ABILITY_MUMMY] =
    {
        .name = _("Mummy"),
        .description = COMPOUND_STRING("Spreads with contact."),
        .aiRating = 5,
        .category = AC_ON_HIT
    },

    [ABILITY_MOXIE] =
    {
        .name = _("Moxie"),
        .description = COMPOUND_STRING("KOs raise Attack."),
        .aiRating = 7,
        .category = AC_TRIGGERED
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("Justified"),
        .description = COMPOUND_STRING("Dark hits raise Attack."),
        .aiRating = 4,
        .category = AC_TRIGGERED
    },

    [ABILITY_RATTLED] =
    {
        .name = _("Rattled"),
        .description = COMPOUND_STRING("Raises Speed when scared."),
        .aiRating = 3,
        .category = AC_TRIGGERED
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("Magic Bounce"),
        .description = COMPOUND_STRING("Reflects status moves."),
        .aiRating = 9,
        .breakable = TRUE,
        .category = AC_PASSIVE
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("Sap Sipper"),
        .description = COMPOUND_STRING("Grass increases Attack."),
        .aiRating = 7,
        .breakable = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("Prankster"),
        .description = COMPOUND_STRING("Status moves go first."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("Sand Force"),
        .description = COMPOUND_STRING("Powers up in a sandstorm."),
        .aiRating = 4,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("Iron Barbs"),
        .description = COMPOUND_STRING("Hurts to touch."),
        .aiRating = 6,
        .category = AC_ON_HIT,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("Zen Mode"),
        .description = COMPOUND_STRING("Transforms at half HP."),
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
        .category = AC_TRIGGERED,
    },

    [ABILITY_VICTORY_STAR] =
    {
        .name = _("Victory Star"),
        .description = COMPOUND_STRING("Raises party accuracy."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("Turboblaze"),
        .description = COMPOUND_STRING("Moves hit through abilities."),
        .aiRating = 7,
        .category = AC_PASSIVE,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("Teravolt"),
        .description = COMPOUND_STRING("Moves hit through abilities."),
        .aiRating = 7,
        .category = AC_PASSIVE,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("Aroma Veil"),
        .description = COMPOUND_STRING("Prevents limiting of moves."),
        .aiRating = 3,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("Flower Veil"),
        .description = COMPOUND_STRING("Protects Grass-types."),
        .aiRating = 0,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("Cheek Pouch"),
        .description = COMPOUND_STRING("Eating Berries restores HP."),
        .aiRating = 4,
        .category = AC_TRIGGERED,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("Protean"),
        .description = COMPOUND_STRING("Changes type to used move."),
        .aiRating = 8,
        .category = AC_TRIGGERED,
    },

    [ABILITY_FUR_COAT] =
    {
        .name = _("Fur Coat"),
        .description = COMPOUND_STRING("Raises Defense."),
        .aiRating = 7,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("Magician"),
        .description = COMPOUND_STRING("Steals the foe's held item."),
        .aiRating = 3,
        .category = AC_ON_ATTACK,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("Bulletproof"),
        .description = COMPOUND_STRING("Avoids some projectiles."),
        .aiRating = 7,
        .category = AC_PASSIVE,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("Competitive"),
        .description = COMPOUND_STRING("Lowered stats up Sp. Atk."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("Strong Jaw"),
        .description = COMPOUND_STRING("Boosts biting moves."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("Refrigerate"),
        .description = COMPOUND_STRING("Normal moves become Ice."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("Sweet Veil"),
        .description = COMPOUND_STRING("Prevents party from sleep."),
        .aiRating = 4,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
        .name = _("Stance Change"),
        .description = COMPOUND_STRING("Transforms as it battles."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_GALE_WINGS] =
    {
        .name = _("Gale Wings"),
        .description = COMPOUND_STRING("Flying moves go first."),
        .aiRating = 6,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
        .name = _("Mega Launcher"),
        .description = COMPOUND_STRING("Boosts pulse moves."),
        .aiRating = 7,
        .category = AC_PASSIVE,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("Grass Pelt"),
        .description = COMPOUND_STRING("Ups Defense in grass."),
        .aiRating = 2,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("Symbiosis"),
        .description = COMPOUND_STRING("Passes its item to an ally."),
        .aiRating = 0,
        .category = AC_TRIGGERED,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("Tough Claws"),
        .description = COMPOUND_STRING("Boosts contact moves."),
        .aiRating = 7,
        .category = AC_PASSIVE,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("Pixilate"),
        .description = COMPOUND_STRING("Normal moves become Fairy."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("Gooey"),
        .description = COMPOUND_STRING("Lowers Speed on contact."),
        .aiRating = 5,
        .category = AC_ON_HIT,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("Aerilate"),
        .description = COMPOUND_STRING("Normal moves become Flying."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("Parental Bond"),
        .description = COMPOUND_STRING("Moves hit twice."),
        .aiRating = 10,
        .category = AC_PASSIVE,
    },

    [ABILITY_DARK_AURA] =
    {
        .name = _("Dark Aura"),
        .description = COMPOUND_STRING("Boosts Dark moves."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_FAIRY_AURA] =
    {
        .name = _("Fairy Aura"),
        .description = COMPOUND_STRING("Boosts Fairy moves."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("Aura Break"),
        .description = COMPOUND_STRING("Reverse aura abilities."),
        .aiRating = 3,
        .category = AC_PASSIVE,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
        .name = _("Primordial Sea"),
        .description = COMPOUND_STRING("Summons heavy rain."),
        .aiRating = 10,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_DESOLATE_LAND] =
    {
        .name = _("Desolate Land"),
        .description = COMPOUND_STRING("Summons intense sunlight."),
        .aiRating = 10,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("Delta Stream"),
        .description = COMPOUND_STRING("Summons strong winds."),
        .aiRating = 10,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("Stamina"),
        .description = COMPOUND_STRING("Boosts Defense when hit."),
        .aiRating = 6,
        .category = AC_ON_HIT,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("Wimp Out"),
        .description = COMPOUND_STRING("Flees at half HP."),
        .aiRating = 3,
        .category = AC_TRIGGERED,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
        .name = _("Emergency Exit"),
        .description = COMPOUND_STRING("Flees at half HP."),
        .aiRating = 3,
        .category = AC_TRIGGERED,
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("Water Compaction"),
        .description = COMPOUND_STRING("Water boosts Defense."),
        .aiRating = 4,
        .category = AC_ON_HIT,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("Merciless"),
        .description = COMPOUND_STRING("Criticals poisoned or\nparalysed foes."),
        .aiRating = 4,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("Shields Down"),
        .description = COMPOUND_STRING("Shell breaks at half HP."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_STAKEOUT] =
    {
        .name = _("Stakeout"),
        .description = COMPOUND_STRING("Stronger as foes switch in."),
        .aiRating = 6,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("Water Bubble"),
        .description = COMPOUND_STRING("Guards from fire and burns."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("Steelworker"),
        .description = COMPOUND_STRING("Powers up Steel moves."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("Berserk"),
        .description = COMPOUND_STRING("Boosts Sp. Atk at low HP."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("Slush Rush"),
        .description = COMPOUND_STRING("Raises Speed in Hail/Snow."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("Long Reach"),
        .description = COMPOUND_STRING("Never makes contact."),
        .aiRating = 3,
        .category = AC_PASSIVE,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("Liquid Voice"),
        .description = COMPOUND_STRING("Makes sound moves Water."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("Triage"),
        .description = COMPOUND_STRING("Healing moves go first."),
        .aiRating = 7,
        .category = AC_PASSIVE,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("Galvanize"),
        .description = COMPOUND_STRING("Normal moves turn Electric."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("Surge Surfer"),
        .description = COMPOUND_STRING("Faster on electricity."),
        .aiRating = 4,
        .category = AC_PASSIVE,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("Schooling"),
        .description = COMPOUND_STRING("Forms a school when strong."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_DISGUISE] =
    {
        .name = _("Disguise"),
        .description = COMPOUND_STRING("Decoy protects it once."),
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
        .category = AC_ON_HIT,
    },

    [ABILITY_BATTLE_BOND] =
    {
        .name = _("Battle Bond"),
        .description = COMPOUND_STRING("Changes form after a KO."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
        .name = _("Power Construct"),
        .description = COMPOUND_STRING("Cells aid it when weakened."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_CORROSION] =
    {
        .name = _("Corrosion"),
        .description = COMPOUND_STRING("Poisons any type."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("Comatose"),
        .description = COMPOUND_STRING("Always drowsing."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
        .name = _("Queenly Majesty"),
        .description = COMPOUND_STRING("Protects from priority."),
        .aiRating = 6,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        .name = _("Innards Out"),
        .description = COMPOUND_STRING("Hurts foe when defeated."),
        .aiRating = 5,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_DANCER] =
    {
        .name = _("Dancer"),
        .description = COMPOUND_STRING("Dances along with others."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("Battery"),
        .description = COMPOUND_STRING("Boosts ally's Sp. Atk."),
        .aiRating = 0,
        .category = AC_PASSIVE,
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("Fluffy"),
        .description = COMPOUND_STRING("Tougher but flammable."),
        .aiRating = 5,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("Dazzling"),
        .description = COMPOUND_STRING("Protects from priority."),
        .aiRating = 5,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("Soul-Heart"),
        .description = COMPOUND_STRING("KOs raise Sp. Atk."),
        .aiRating = 7,
        .category = AC_TRIGGERED,
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("Tangling Hair"),
        .description = COMPOUND_STRING("Lowers Speed on contact."),
        .aiRating = 5,
        .category = AC_ON_HIT,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("Receiver"),
        .description = COMPOUND_STRING("Copies ally's ability."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("Power Of Alchemy"),
        .description = COMPOUND_STRING("Copies ally's ability."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("Beast Boost"),
        .description = COMPOUND_STRING("KOs boost best stat."),
        .aiRating = 7,
        .category = AC_TRIGGERED,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("RKS System"),
        .description = COMPOUND_STRING("Memories change its type."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
        .name = _("Electric Surge"),
        .description = COMPOUND_STRING("Field becomes Electric."),
        .aiRating = 8,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
        .name = _("Psychic Surge"),
        .description = COMPOUND_STRING("Field becomes weird."),
        .aiRating = 8,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("Misty Surge"),
        .description = COMPOUND_STRING("Field becomes misty."),
        .aiRating = 8,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("Grassy Surge"),
        .description = COMPOUND_STRING("Field becomes grassy."),
        .aiRating = 8,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
        .name = _("Full Metal Body"),
        .description = COMPOUND_STRING("Prevents stat reduction."),
        .aiRating = 4,
        .category = AC_PASSIVE,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
        .name = _("Shadow Shield"),
        .description = COMPOUND_STRING("Halves damage at full HP."),
        .aiRating = 8,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("Prism Armor"),
        .description = COMPOUND_STRING("Weakens “supereffective”."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("Neuroforce"),
        .description = COMPOUND_STRING("Ups “supereffective”."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_INTREPID_SWORD] =
    {
        .name = _("Intrepid Sword"),
        .description = COMPOUND_STRING("Ups Attack on entry."),
        .aiRating = 3,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
        .name = _("Dauntless Shield"),
        .description = COMPOUND_STRING("Ups Defense on entry."),
        .aiRating = 3,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("Libero"),
        .description = COMPOUND_STRING("Changes type to move's."),
        .category = AC_SWITCH_IN,
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("Ball Fetch"),
        .description = COMPOUND_STRING("Fetches failed Poké Ball."),
        .aiRating = 0,
        .category = AC_TRIGGERED,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("Cotton Down"),
        .description = COMPOUND_STRING("Lower Speed of all when hit."),
        .aiRating = 3,
        .category = AC_ON_HIT,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("Propeller Tail"),
        .description = COMPOUND_STRING("Ignores foe's redirection."),
        .aiRating = 2,
        .category = AC_PASSIVE,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("Mirror Armor"),
        .description = COMPOUND_STRING("Reflect stat decreases."),
        .aiRating = 6,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("Gulp Missile"),
        .description = COMPOUND_STRING("If hit, spits prey from sea."),
        .aiRating = 3,
        .cantBeCopied = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_STALWART] =
    {
        .name = _("Stalwart"),
        .description = COMPOUND_STRING("Ignores foe's redirection."),
        .aiRating = 2,
        .category = AC_PASSIVE,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("Steam Engine"),
        .description = COMPOUND_STRING("Fire or Water hits up Speed."),
        .aiRating = 3,
        .category = AC_TRIGGERED,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("Punk Rock"),
        .description = COMPOUND_STRING("Ups and resists sound."),
        .aiRating = 2,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("Sand Spit"),
        .description = COMPOUND_STRING("Creates a sandstorm if hit."),
        .aiRating = 5,
        .category = AC_ON_HIT,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("Ice Scales"),
        .description = COMPOUND_STRING("Halves special damage."),
        .aiRating = 7,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("Ripen"),
        .description = COMPOUND_STRING("Doubles effect of Berries."),
        .aiRating = 4,
        .category = AC_PASSIVE,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("Ice Face"),
        .description = COMPOUND_STRING("Hail or Snow renew free hit."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("Power Spot"),
        .description = COMPOUND_STRING("Powers up ally moves."),
        .aiRating = 2,
        .category = AC_PASSIVE,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("Mimicry"),
        .description = COMPOUND_STRING("Changes type on terrain."),
        .aiRating = 2,
        .category = AC_TRIGGERED,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("Screen Cleaner"),
        .description = COMPOUND_STRING("Removes walls of light."),
        .aiRating = 3,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("Steely Spirit"),
        .description = COMPOUND_STRING("Boosts ally's Steel moves."),
        .aiRating = 2,
        .category = AC_PASSIVE,
    },

    [ABILITY_PERISH_BODY] =
    {
        .name = _("Perish Body"),
        .description = COMPOUND_STRING("Foe faints in 3 turns if hit."),
        .aiRating = -1,
        .category = AC_ON_HIT,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
        .name = _("Wandering Spirit"),
        .description = COMPOUND_STRING("Trade abilities on contact."),
        .aiRating = 2,
        .category = AC_ON_HIT,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("Gorilla Tactics"),
        .description = COMPOUND_STRING("Ups Attack and locks move."),
        .aiRating = 4,
        .category = AC_PASSIVE,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("Neutralizing Gas"),
        .description = COMPOUND_STRING("All Abilities are nullified."),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("Pastel Veil"),
        .description = COMPOUND_STRING("Protects team from poison."),
        .aiRating = 4,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
        .name = _("Hunger Switch"),
        .description = COMPOUND_STRING("Changes form each turn."),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
        .category = AC_EOT,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("Quick Draw"),
        .description = COMPOUND_STRING("Moves first occasionally."),
        .aiRating = 4,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("Unseen Fist"),
        .description = COMPOUND_STRING("Contact evades protection."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
        .name = _("Curious Medicine"),
        .description = COMPOUND_STRING("Remove ally's stat changes."),
        .aiRating = 3,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("Transistor"),
        .description = COMPOUND_STRING("Ups Electric-type moves."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("Dragon's Maw"),
        .description = COMPOUND_STRING("Ups Dragon-type moves."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
        .name = _("Chilling Neigh"),
        .description = COMPOUND_STRING("KOs boost Attack stat."),
        .aiRating = 7,
        .category = AC_TRIGGERED,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("Grim Neigh"),
        .description = COMPOUND_STRING("KOs boost Sp. Atk stat."),
        .aiRating = 7,
        .category = AC_TRIGGERED,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("As One"),
        .description = COMPOUND_STRING("Unnerve and Chilling Neigh."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
        .name = _("As One"),
        .description = COMPOUND_STRING("Unnerve and Grim Neigh."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_LINGERING_AROMA] =
    {
        .name = _("Lingering Aroma"),
        .description = COMPOUND_STRING("Spreads with contact."),
        .aiRating = 5,
        .category = AC_ON_HIT,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("Seed Sower"),
        .description = COMPOUND_STRING("Affects terrain when hit."),
        .aiRating = 5,
        .category = AC_ON_HIT,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
        .name = _("Thermal Exchange"),
        .description = COMPOUND_STRING("Fire hits up Attack."),
        .aiRating = 4,
        .breakable = TRUE,
        .category = AC_ON_HIT,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("Anger Shell"),
        .description = COMPOUND_STRING("Gets angry at half HP."),
        .aiRating = 3,
        .category = AC_TRIGGERED,
    },

    [ABILITY_PURIFYING_SALT] =
    {
        .name = _("Purifying Salt"),
        .description = COMPOUND_STRING("Protected by pure salts."),
        .aiRating = 6,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
        .name = _("Well-Baked Body"),
        .description = COMPOUND_STRING("Strengthened by Fire."),
        .aiRating = 5,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("Wind Rider"),
        .description = COMPOUND_STRING("Ups Attack if hit by wind."),
        .aiRating = 4,
        .breakable = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("Guard Dog"),
        .description = COMPOUND_STRING("Cannot be intimidated."),
        .aiRating = 5,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
        .name = _("Rocky Payload"),
        .description = COMPOUND_STRING("Powers up Rock moves."),
        .aiRating = 6,
        .category = AC_PASSIVE,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("Wind Power"),
        .description = COMPOUND_STRING("Gets charged by wind."),
        .aiRating = 4,
        .category = AC_TRIGGERED,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("Zero to Hero"),
        .description = COMPOUND_STRING("Changes form on switch out."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
        .category = AC_SWITCH_OUT,
    },

    [ABILITY_COMMANDER] =
    {
        .name = _("Commander"),
        .description = COMPOUND_STRING("Commands from Dondozo."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
        .name = _("Electromorphosis"),
        .description = COMPOUND_STRING("Gets Charged when hit."),
        .aiRating = 5,
        .category = AC_ON_HIT,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
        .name = _("Protosynthesis"),
        .description = COMPOUND_STRING("Sun boosts best stat."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("Quark Drive"),
        .description = COMPOUND_STRING("Elec. field ups best stat."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("Good as Gold"),
        .description = COMPOUND_STRING("Avoids status moves."),
        .aiRating = 8,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
        .name = _("Vessel of Ruin"),
        .description = COMPOUND_STRING("Lowers foes' sp. damage."),
        .aiRating = 5,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
        .name = _("Sword of Ruin"),
        .description = COMPOUND_STRING("Lowers foes' Defense."),
        .aiRating = 5,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
        .name = _("Tablets of Ruin"),
        .description = COMPOUND_STRING("Lowers foes' damage."),
        .aiRating = 5,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
        .name = _("Beads of Ruin"),
        .description = COMPOUND_STRING("Lowers foes' Sp. Defense."),
        .aiRating = 5,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
        .name = _("Orichalcum Pulse"),
        .description = COMPOUND_STRING("Summons sunlight in battle."),
        .aiRating = 8,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_HADRON_ENGINE] =
    {
        .name = _("Hadron Engine"),
        .description = COMPOUND_STRING("Field becomes Electric."),
        .aiRating = 8,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("Opportunist"),
        .description = COMPOUND_STRING("Copies foe's stat change."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("Cud Chew"),
        .description = COMPOUND_STRING("Eats a used berry again."),
        .aiRating = 4,
        .category = AC_TRIGGERED,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("Sharpness"),
        .description = COMPOUND_STRING("Strengthens slicing moves."),
        .aiRating = 7,
        .category = AC_PASSIVE,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
        .name = _("Supreme Overlord"),
        .description = COMPOUND_STRING("Inherits fallen's strength."),
        .aiRating = 6,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("Costar"),
        .description = COMPOUND_STRING("Copies ally's stat changes."),
        .aiRating = 5,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
        .name = _("Toxic Debris"),
        .description = COMPOUND_STRING("Throws poison spikes if hit."),
        .aiRating = 4,
        .category = AC_ON_HIT,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("Armor Tail"),
        .description = COMPOUND_STRING("Protects from priority."),
        .aiRating = 5,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_EARTH_EATER] =
    {
        .name = _("Earth Eater"),
        .description = COMPOUND_STRING("Eats ground to heal HP."),
        .aiRating = 7,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
        .name = _("Mycelium Might"),
        .description = COMPOUND_STRING("Status moves never fail."),
        .aiRating = 2,
        .category = AC_PASSIVE,
    },

    [ABILITY_HOSPITALITY] =
    {
        .name = _("Hospitality"),
        .description = COMPOUND_STRING("Restores ally's HP."),
        .aiRating = 5,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("Mind's Eye"),
        .description = COMPOUND_STRING("Keen Eye and Scrappy."),
        .aiRating = 8,
        .breakable = TRUE,
        .category = AC_PASSIVE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
        .name = _("Embody Aspect"),
        .description = COMPOUND_STRING("Raises Speed."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
        .name = _("Embody Aspect"),
        .description = COMPOUND_STRING("Raises Attack."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
        .name = _("Embody Aspect"),
        .description = COMPOUND_STRING("Raises Sp. Def."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
        .name = _("Embody Aspect"),
        .description = COMPOUND_STRING("Raises Defense."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("Toxic Chain"),
        .description = COMPOUND_STRING("Moves can poison."),
        .aiRating = 8,
        .category = AC_ON_ATTACK,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
        .name = _("Supersweet Syrup"),
        .description = COMPOUND_STRING("Lowers the foe's Evasion."),
        .aiRating = 5,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("Tera Shift"),
        .description = COMPOUND_STRING("Terastallizes upon entry."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
        .category = AC_SWITCH_IN,
    },

    [ABILITY_TERA_SHELL] =
    {
        .name = _("Tera Shell"),
        .description = COMPOUND_STRING("Resists all at full HP."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
        .category = AC_CONDITIONAL,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
        .name = _("Teraform Zero"),
        .description = COMPOUND_STRING("Zeroes weather and terrain."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .category = AC_TRIGGERED,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
        .name = _("Poison Puppeteer"),
        .description = COMPOUND_STRING("Confuses poisoned foes."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .category = AC_TRIGGERED,
    },
    [ABILITY_SHAPE_OF_STONE] =
    {
        .name = _("Shape of Stone"),
        .description = COMPOUND_STRING("Converts rocks to HP."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },
    [ABILITY_SHAPE_OF_ICE] =
    {
        .name = _("Shape of Ice"),
        .description = COMPOUND_STRING("Converts ice to HP."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },
    [ABILITY_SHAPE_OF_STEEL] =
    {
        .name = _("Shape of Steel"),
        .description = COMPOUND_STRING("Converts steel to HP."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },
    [ABILITY_SHAPE_OF_CURRENT] =
    {
        .name = _("Shape of Current"),
        .description = COMPOUND_STRING("Converts electricity to HP."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },
    [ABILITY_SHAPE_OF_ENERGY] =
    {
        .name = _("Shape of Energy"),
        .description = COMPOUND_STRING("Turns draconic energy into HP."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },
    [ABILITY_CLOUDBURST] =
    {
        .name = _("Cloudburst"),
        .description = COMPOUND_STRING("Summons rain when hit."),
        .aiRating = 8,
        .category = AC_ON_HIT,
    },
    [ABILITY_GALEFORCE] =
    {
        .name = _("Galeforce"),
        .description = COMPOUND_STRING("Powers up wind moves."),
        .aiRating = 7,
        .category = AC_PASSIVE,
    },
    [ABILITY_HEAT_EROSION] =
    {
        .name = _("Heat Erosion"),
        .description = COMPOUND_STRING("Fire hits Ground and Rock\nsuper effective."),
        .aiRating = 8,
        .category = AC_PASSIVE,
    },
    [ABILITY_SLEET_STORM] =
    {
        .name = _("Sleet Storm"),
        .description = COMPOUND_STRING("Hail damages player side."),
        .aiRating = 9,
        .category = AC_EOT,
    },
    [ABILITY_THUNDERSTRIKE] =
    {
        .name = _("Thunderstrike"),
        .description = COMPOUND_STRING("Thunder randomly strikes\nplayer."),
        .aiRating = 9,
        .category = AC_EOT,
    },
    [ABILITY_INFERNO] =
    {
        .name = _("Inferno"),
        .description = COMPOUND_STRING("Flames harm the player"),
        .aiRating = 9,
        .category = AC_EOT,
    },
    [ABILITY_RISING_THUNDER] =
    {
        .name = _("Rising Thunder"),
        .description = COMPOUND_STRING("Revives after 4 turns with\nhalf hp as Fire type."),
        .aiRating = 9,
        .category = AC_EOT,
    },
    [ABILITY_RISING_FLAMES] =
    {
        .name = _("Rising Flames"),
        .description = COMPOUND_STRING("Revives after 4 turns with\nhalf hp as Fire type."),
        .aiRating = 9,
        .category = AC_EOT,
    },
    [ABILITY_RISING_TIDE] =
    {
        .name = _("Rising Ride"),
        .description = COMPOUND_STRING("Revives after 4 turns with\nhalf hp as Fire type."),
        .aiRating = 9,
        .category = AC_EOT,
    },
    [ABILITY_ESSENCE_OF_RAIN] =
    {
        .name = _("Essence of Rain"),
        .description = COMPOUND_STRING("Treats the user's actions\nas if Rain is active."),
        .aiRating = 9,
        .category = AC_PASSIVE,
    },
    [ABILITY_ESSENCE_OF_SUN] =
    {
        .name = _("Essence of Sun"),
        .description = COMPOUND_STRING("Treats the user's actions\nas if Sun is active."),
        .aiRating = 9,
        .category = AC_PASSIVE,
    },
    [ABILITY_ESSENCE_OF_SNOW] =
    {
        .name = _("Essence of Snow"),
        .description = COMPOUND_STRING("Treats the user's actions\nas if Snow is active."),
        .aiRating = 9,
        .category = AC_PASSIVE,
    },
    [ABILITY_ESSENCE_OF_SAND] =
    {
        .name = _("Essence of Sand"),
        .description = COMPOUND_STRING("Treats the user's actions\nas if Sand is active."),
        .aiRating = 9,
        .category = AC_PASSIVE,
    },
    [ABILITY_CLOUDWALKER] =
    {
        .name = _("Cloudwalker"),
        .description = COMPOUND_STRING("Using a wind move grants\nlevitate for 2 turns."),
        .aiRating = 9,
        .category = AC_TRIGGERED,
    },
    [ABILITY_SPARKING_ZEPHYR] =
    {
        .name = _("Sparking Zephyr"),
        .description = COMPOUND_STRING("Using an electric move sets\nTailwind."),
        .aiRating = 9,
        .category = AC_TRIGGERED,
    },
    [ABILITY_UNCONTAINED_BLAZE] =
    {
        .name = _("Uncontained Blaze"),
        .description = COMPOUND_STRING("Fire moves also hurt inactive\nbattlers."),
        .aiRating = 9,
        .category = AC_ON_ATTACK,
    },
    [ABILITY_WINDS_OF_CHANGE] =
    {
        .name = _("Winds of Change"),
        .description = COMPOUND_STRING("Using a wind move also raises\na random stat."),
        .aiRating = 9,
        .category = AC_TRIGGERED,
    },
    [ABILITY_MAELSTROM] =
    {
        .name = _("Maelstrom"),
        .description = COMPOUND_STRING("Ups Special Attack\nif hit by wind."),
        .aiRating = 9,
        .category = AC_TRIGGERED,
    },
    [ABILITY_SAND_REPAIR] =
    {
        .name = _("Sand Repair"),
        .description = COMPOUND_STRING("Recovers HP during\nsandstorms."),
        .aiRating = 9,
        .category = AC_EOT,
    },
    [ABILITY_DISHEARTEN] =
    {
        .name = _("Dishearten"),
        .description = COMPOUND_STRING("Lowers the foe's Sp.Attack."),
        .aiRating = 7,
        .category = AC_SWITCH_IN,
        .cd = TARC_DISHEARTEN_CD
    },
    [ABILITY_FRIGID_BODY] =
    {
        .name = _("Frigid Body"),
        .description = COMPOUND_STRING("Inflicts frostbite on\ncontact."),
        .aiRating = 4,
        .category = AC_ON_HIT,
    },
    [ABILITY_RESILIENCE] =
    {
        .name = _("Resilience"),
        .description = COMPOUND_STRING("Boosts Special Defense\nwhen hit."),
        .aiRating = 7,
        .category = AC_ON_HIT,
    },
    [ABILITY_WHITEOUT] =
    {
        .name = _("Whiteout"),
        .description = COMPOUND_STRING("Ice moves deal 50% more\ndamage in Snow."),
        .aiRating = 7,
        .category = AC_CONDITIONAL,
    },
    [ABILITY_MENTAL_RESET] =
    {
        .name = _("Mental Reset"),
        .description = COMPOUND_STRING("Rotating out resets regative\nstat changes."),
        .aiRating = 7,
        .category = AC_SWITCH_OUT,
    },
    [ABILITY_SENTINEL] =
    {
        .name = _("Sentinel"),
        .description = COMPOUND_STRING("Can intercept incoming hits."),
        .aiRating = 7,
        .category = AC_TRIGGERED,
        .cd = TARC_SENTINEL_CD,
    },
    [ABILITY_STATIC_BUILDUP] =
    {
        .name = _("Static Buildup"),
        .description = COMPOUND_STRING("Gains Charge at end of turn\nin Sandstorm."),
        .aiRating = 7,
        .category = AC_EOT,
        .cd = TARC_STATIC_BUILDUP_CD,
    },
    [ABILITY_HOARFROST] =
    {
        .name = _("Hoarfrost"),
        .description = COMPOUND_STRING("Inflicts frostbite on the foe\nwhen it starts snowing."),
        .aiRating = 7,
        .category = AC_TRIGGERED,
    },
    [ABILITY_PHOTOSYNTHESIS] =
    {
        .name = _("Photosynthesis"),
        .description = COMPOUND_STRING("Grass moves deal 50% more\ndamage in sun."),
        .aiRating = 7,
        .category = AC_PASSIVE,
    },
    [ABILITY_SUNRISE] =
    {
        .name = _("Sunrise"),
        .description = COMPOUND_STRING("Using a fire-type move sets\nsun. User floats."),
        .aiRating = 7,
        .category = AC_TRIGGERED,
    },
    [ABILITY_LUNAR_COLD] =
    {
        .name = _("Lunar Cold"),
        .description = COMPOUND_STRING("Skips charge turns in clear\nskies. Sets snow after\ntwo-turn moves. User floats."),
        .aiRating = 7,
        .category = AC_TRIGGERED,
    },
    [ABILITY_ICY_VEINS] =
    {
        .name = _("Icy Veins"),
        .description = COMPOUND_STRING("Powers up in snow"),
        .aiRating = 7,
        .category = AC_CONDITIONAL,
    },
    [ABILITY_PHALANX] =
    {
        .name = _("Phalanx"),
        .description = COMPOUND_STRING("Reduces damage for allies."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },
    [ABILITY_FLORAL_GROWTH] =
    {
        .name = _("Floral Growth"),
        .description = COMPOUND_STRING("Recovers HP in Sun."),
        .aiRating = 5,
        .category = AC_EOT,
    },
    [ABILITY_SHARED_BURDENS] =
    {
        .name = _("Shared Burdens"),
        .description = COMPOUND_STRING("Damage taken is split\nbetween entire party."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },
    [ABILITY_TANGO] =
    {
        .name = _("Tango"),
        .description = COMPOUND_STRING("Attacks twice after using\na dance move."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_DREAD] =
    {
        .name = _("Dread"),
        .description = COMPOUND_STRING("Psychic moves has a\nchance to paralyse."),
        .aiRating = 5,
        .category = AC_CONDITIONAL,
    },
    [ABILITY_WILLPOWER] =
    {
        .name = _("Willpower"),
        .description = COMPOUND_STRING("Physical attacks raise\nSpAtk, special attacks\nraise Attack."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_EMPATH] =
    {
        .name = _("Empath"),
        .description = COMPOUND_STRING("Heals at end of turn for\nech stat boost on turn."),
        .aiRating = 5,
        .category = AC_EOT,
    },
    [ABILITY_MENTAL_BLOCK] =
    {
        .name = _("Mental Block"),
        .description = COMPOUND_STRING("Raises Sp.Def after\nusing a status move."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_TERRAS_BLESSING] =
    {
        .name = _("Terra's Blessing"),
        .description = COMPOUND_STRING("Using a wind move\n heals the user."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_ONE_WITH_THE_WIND] =
    {
        .name = _("One with the Wind"),
        .description = COMPOUND_STRING("Using a wind move changes\nthe type to match."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_BRUTE_FORCE] =
    {
        .name = _("Brute Force"),
        .description = COMPOUND_STRING("Increases power of\nfighting moves."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },
    [ABILITY_GIANT_SLAYER] =
    {
        .name = _("Giant Slayer"),
        .description = COMPOUND_STRING("Increases crit rate vs\nopponents with 2+ stat\nboosts."),
        .aiRating = 5,
        .category = AC_CONDITIONAL,
    },
    [ABILITY_PRECISION_POINT] =
    {
        .name = _("Precision Point"),
        .description = COMPOUND_STRING("Increases crit rate of\nslicing moves."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },
    [ABILITY_FLOURISH] =
    {
        .name = _("Flourish"),
        .description = COMPOUND_STRING("Using a slicing move\nboosts speed."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_MENTAL_SWORD] =
    {
        .name = _("Mental Sword"),
        .description = COMPOUND_STRING("Slicing moves turn into\nspecial moves."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_MIND_PALACE] =
    {
        .name = _("Mind Palace"),
        .description = COMPOUND_STRING("Using a status move\nsets Psychic Terrain."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_OVERCHARGE] =
    {
        .name = _("Overcharge"),
        .description = COMPOUND_STRING("Using an electric move\n sets Electric Terrain."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_MISTBANK] =
    {
        .name = _("Mistbank"),
        .description = COMPOUND_STRING("Using a water move sets\n Misty Terrain."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_BLADES_OF_FROST] =
    {
        .name = _("Blades of Frost"),
        .description = COMPOUND_STRING("Ice type attacks become\nslicing moves."),
        .aiRating = 5,
        .category = AC_CONDITIONAL,
    },
    [ABILITY_CHILLING_PRESENCE] =
    {
        .name = _("Chilling Presence"),
        .description = COMPOUND_STRING("Boosts Psychic moves in\nsnow."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },
    [ABILITY_CLOUDING_MIND] =
    {
        .name = _("Clouding Mind"),
        .description = COMPOUND_STRING("Inflicts Torment on hit."),
        .aiRating = 5,
        .category = AC_ON_ATTACK,
    },
    [ABILITY_SCORCHING_VOLTAGE] =
    {
        .name = _("Scorching Voltage"),
        .description = COMPOUND_STRING("Electric attacks can also\ninflict burn on targets."),
        .aiRating = 5,
        .category = AC_CONDITIONAL,
    },
    [ABILITY_FLAME_CLOAK] =
    {
        .name = _("Flame Cloak"),
        .description = COMPOUND_STRING("Using a fire move also\nboosts defense."),
        .aiRating = 5,
        .category = AC_CONDITIONAL,
    },
    [ABILITY_GEYSER] =
    {
        .name = _("Geyser"),
        .description = COMPOUND_STRING("Fire moves are boosted\nin rain. Water moves\nare boosted in sun."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },
    [ABILITY_SPORANGIUM] =
    {
        .name = _("Sporangium"),
        .description = COMPOUND_STRING("Grass attacks also\ninflict Leech Seed."),
        .aiRating = 5,
        .category = AC_ON_ATTACK,
    },
    [ABILITY_RESORPTION] =
    {
        .name = _("Resorption"),
        .description = COMPOUND_STRING("Hitting poisoned targets\nabsorbs HP."),
        .aiRating = 5,
        .category = AC_ON_ATTACK,
    },
    [ABILITY_CRIPPLING_VENOM] =
    {
        .name = _("Crippling Venom"),
        .description = COMPOUND_STRING("Inflicting poison also\nlowers Atk and Sp.Atk."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_ROYAL_GUARD] =
    {
        .name = _("Royal Guard"),
        .description = COMPOUND_STRING("Boosts defense of allies\nin Snow."),
        .aiRating = 5,
        .category = AC_CONDITIONAL,
    },
    [ABILITY_FATED_CHANGE] =
    {
        .name = _("Fated Change"),
        .description = COMPOUND_STRING("Foresees used status moves\nif no move is not already\nforeseen."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_FATED_STRIKE] =
    {
        .name = _("Fated Strike"),
        .description = COMPOUND_STRING("Foresees used physical moves\nif no move is not already\nforeseen."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_FATED_SIGHT] =
    {
        .name = _("Fated Sight"),
        .description = COMPOUND_STRING("Foresees used special moves\nif no move is not already\nforeseen."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_TECTONIC_TITAN] =
    {
        .name = _("Tectonic Titan"),
        .description = COMPOUND_STRING("Powers up Ground moves."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },
    [ABILITY_FRACTAL_SHARDS] =
    {
        .name = _("Fractal Shards"),
        .description = COMPOUND_STRING("When hit in snow, gain\ncrystals that boosts the\nteam's attacks."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_CIRCLE_OF_LIFE] =
    {
        .name = _("Circle of Light"),
        .description = COMPOUND_STRING("Heal all battlers at\nend of turn for 1/6."),
        .aiRating = 5,
        .category = AC_EOT,
    },
    [ABILITY_YGGDRASILS_GIFT] =
    {
        .name = _("Yggdrasil's Gift"),
        .description = COMPOUND_STRING("At end of turn, raise\na random stat for each\nmon at full HP."),
        .aiRating = 5,
        .category = AC_EOT,
    },
    [ABILITY_AURA_OF_VITALITY] =
    {
        .name = _("Aura of Vitality"),
        .description = COMPOUND_STRING("Increase healing effects\non self by 50%."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },
    [ABILITY_ABUNDANCE] =
    {
        .name = _("Abundance"),
        .description = COMPOUND_STRING("At full HP, moves don't\nhave charge turns and\nstats can't be lowered."),
        .aiRating = 5,
        .category = AC_CONDITIONAL,
    },
    [ABILITY_HASTE] =
    {
        .name = _("Haste"),
        .description = COMPOUND_STRING("Moves with increased\npriority deal more damage."),
        .aiRating = 5,
        .category = AC_CONDITIONAL,
    },
    [ABILITY_PURIFYING_WATER] =
    {
        .name = _("Purifying Water"),
        .description = COMPOUND_STRING("Turns poison type attacks\ninto water. Immune to status\nconditions."),
        .aiRating = 5,
        .category = AC_PASSIVE,
    },
    [ABILITY_MOOD_SWING] =
    {
        .name = _("Mood Swing"),
        .description = COMPOUND_STRING("Moves with increased\npriority deal more damage."),
        .aiRating = 5,
        .category = AC_CONDITIONAL,
    },
    [ABILITY_ELECTRON_RELESE] =
    {
        .name = _("Electron Release"),
        .description = COMPOUND_STRING("Sets Electric Terrain\non getting hit."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_GUARDIAN_OF_THE_SEA] =
    {
        .name = _("Guardian of the Sea"),
        .description = COMPOUND_STRING("Water moves do increased\ndamage and apply the\nSubmerged status."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_GRACE_OF_THE_WINDS] =
    {
        .name = _("Grace of the Winds"),
        .description = COMPOUND_STRING("Promotes added effects."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_BRINGER_OF_STORMS] =
    {
        .name = _("Bringer of Storms"),
        .description = COMPOUND_STRING("Flying moves sets rain."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
    [ABILITY_HERALD_OF_CURRENTS] =
    {
        .name = _("Herald of Currents"),
        .description = COMPOUND_STRING("Damage is increased for\neach reduced stat the\ntarget has."),
        .aiRating = 5,
        .category = AC_TRIGGERED,
    },
};
