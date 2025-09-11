const u16 sFinalBossToSpecies[] =
{
    [FINAL_BOSS_HO_OH] = SPECIES_HO_OH,
    [FINAL_BOSS_LUGIA] = SPECIES_LUGIA,
    [FINAL_BOSS_XERNEAS] = SPECIES_XERNEAS,
    [FINAL_BOSS_YVELTAL] = SPECIES_YVELTAL,
    [FINAL_BOSS_GIRATINA] = SPECIES_GIRATINA,
    [FINAL_BOSS_ARCEUS] = SPECIES_ARCEUS,
};

const struct BossGroup sBirds =
{
    .numMembers = 3,
    .members =
    {
        SPECIES_ARTICUNO,
        SPECIES_ZAPDOS,
        SPECIES_MOLTRES,
    }
};

const struct BossGroup sBeasts =
{
    .numMembers = 3,
    .members =
    {
        SPECIES_RAIKOU,
        SPECIES_ENTEI,
        SPECIES_SUICUNE,
    }
};

const struct BossGroup sGolems =
{
    .numMembers = 5,
    .members =
    {
        SPECIES_REGIROCK,
        SPECIES_REGICE,
        SPECIES_REGISTEEL,
        SPECIES_REGIELEKI,
        SPECIES_REGIDRAGO,
    }
};

const struct BossGroup sLakes =
{
    .numMembers = 3,
    .members =
    {
        SPECIES_UXIE,
        SPECIES_MESPRIT,
        SPECIES_AZELF,
    }
};

const struct BossGroup sSwords =
{
    .numMembers = 4,
    .members =
    {
        SPECIES_COBALION,
        SPECIES_TERRAKION,
        SPECIES_VIRIZION,
        SPECIES_KELDEO,
    }
};

const struct BossGroup sGenies =
{
    .numMembers = 4,
    .members =
    {
        SPECIES_TORNADUS_THERIAN,
        SPECIES_THUNDURUS_THERIAN,
        SPECIES_LANDORUS_THERIAN,
        SPECIES_ENAMORUS_THERIAN,
    }
};

const struct BossGroup sTapus =
{
    .numMembers = 4,
    .members =
    {
        SPECIES_TAPU_KOKO,
        SPECIES_TAPU_LELE,
        SPECIES_TAPU_BULU,
        SPECIES_TAPU_FINI,
    }
};

const struct BossGroup sTreasures =
{
    .numMembers = 4,
    .members =
    {
        SPECIES_WO_CHIEN,
        SPECIES_CHIEN_PAO,
        SPECIES_TING_LU,
        SPECIES_CHI_YU,
    }
};

const struct BossGroup sLoyal =
{
    .numMembers = 3,
    .members =
    {
        SPECIES_OKIDOGI,
        SPECIES_MUNKIDORI,
        SPECIES_FEZANDIPITI,
    }
};

const struct BossGroup sGalarBirds =
{
    .numMembers = 3,
    .members =
    {
        SPECIES_ARTICUNO_GALAR,
        SPECIES_ZAPDOS_GALAR,
        SPECIES_MOLTRES_GALAR,
    }
};

const struct BossGroup sParadoxBeasts =
{
    .numMembers = 3,
    .members =
    {
        SPECIES_WALKING_WAKE,
        SPECIES_GOUGING_FIRE,
        SPECIES_RAGING_BOLT,
    }
};

const struct BossGroup sParadoxSwords =
{
    .numMembers = 3,
    .members =
    {
        SPECIES_IRON_LEAVES,
        SPECIES_IRON_BOULDER,
        SPECIES_IRON_CROWN,
    }
};

const struct BossGroup sPseudos =
{
    .numMembers = 10,
    .members =
    {
        SPECIES_DRAGONITE,
        SPECIES_TYRANITAR,
        SPECIES_METAGROSS,
        SPECIES_SALAMENCE,
        SPECIES_GARCHOMP,
        SPECIES_HYDREIGON,
        SPECIES_GOODRA,
        SPECIES_KOMMO_O,
        SPECIES_DRAGAPULT,
        SPECIES_BAXCALIBUR,
    }
};

const struct BossGroup *const sBossGroups[] =
{
    [BOSS_BIRDS] = &sBirds,
    [BOSS_BEASTS] = &sBeasts,
    [BOSS_GOLEMS] = &sGolems,
    [BOSS_LAKES] = &sLakes,
    [BOSS_SWORDS] = &sSwords,
    [BOSS_GENIES] = &sGenies,
    [BOSS_TAPUS] = &sTapus,
    [BOSS_TREASURES] = &sTreasures,
    [BOSS_LOYAL] = &sLoyal,
    [BOSS_GALAR_BIRDS] = &sGalarBirds,
    [BOSS_PARADOX_BEASTS] = &sParadoxBeasts,
    [BOSS_PARADOX_SWORDS] = &sParadoxSwords,
    [BOSS_PSEUDOS] = &sPseudos,
};

const struct StarterMon sStarterSetters[MON_LIST_RANDOM] =
{
    [MON_LIST_RAIN_DIRECT] =
    {
        .species = SPECIES_POLITOED,
        .moves = {MOVE_SURF, MOVE_AMNESIA},
    },
    [MON_LIST_RAIN_CONDITIONAL] =
    {
        .species = SPECIES_BRONZONG,
        .moves = {MOVE_METAL_BURST, MOVE_RECOVER},
    },
    [MON_LIST_RAIN_MANUAL] =
    {
        .species = SPECIES_MARACTUS,
        .moves = {MOVE_RAIN_DANCE, MOVE_PETAL_BLIZZARD},
    },
    [MON_LIST_SUN_DIRECT] =
    {
        .species = SPECIES_TORKOAL,
        .moves = {MOVE_YAWN, MOVE_LAVA_PLUME},
    },
    [MON_LIST_SUN_CONDITIONAL] =
    {
        .species = SPECIES_SOLROCK,
        .moves = {MOVE_FLARE_BLITZ, MOVE_ROCK_SLIDE},
    },
    [MON_LIST_SUN_MANUAL] =
    {
        .species = SPECIES_SUNFLORA,
        .moves = {MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM},
    },
    [MON_LIST_SNOW_DIRECT] =
    {
        .species = SPECIES_ABOMASNOW,
        .moves = {MOVE_AVALANCHE, MOVE_HORN_LEECH},
    },
    [MON_LIST_SNOW_CONDITIONAL] =
    {
        .species = SPECIES_LUNATONE,
        .moves = {MOVE_MOONBLAST, MOVE_METEOR_BEAM},
    },
    [MON_LIST_SNOW_MANUAL] =
    {
        .species = SPECIES_FROSLASS,
        .moves = {MOVE_SNOWSCAPE, MOVE_GLACIATE},
    },
    [MON_LIST_SAND_DIRECT] =
    {
        .species = SPECIES_GIGALITH,
        .moves = {MOVE_COUNTER, MOVE_ROCK_SLIDE},
    },
    [MON_LIST_SAND_CONDITIONAL] =
    {
        .species = SPECIES_SANDACONDA,
        .moves = {MOVE_GLARE, MOVE_BULLDOZE},
    },
    [MON_LIST_SAND_MANUAL] =
    {
        .species = SPECIES_SANDY_SHOCKS,
        .moves = {MOVE_SANDSTORM, MOVE_VOLT_SWITCH},
    },
};

const struct StarterPool sRainPool =
{
    .numMons = 6,
    .mons =
    {
        {
            .species = SPECIES_KINGDRA,
            .moves = {MOVE_SURF, MOVE_HURRICANE},
        },
        {
            .species = SPECIES_BASCULEGION,
            .moves = {MOVE_WATERFALL, MOVE_SHADOW_BALL},
        },
        {
            .species = SPECIES_OVERQWIL,
            .moves = {MOVE_BARB_BARRAGE, MOVE_FLIP_TURN},
        },
        {
            .species = SPECIES_ARCHALUDON,
            .moves = {MOVE_ELECTRO_SHOT, MOVE_IRON_DEFENSE},
        },
        {
            .species = SPECIES_WHISCASH,
            .moves = {MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE},
        },
        {
            .species = SPECIES_KILOWATTREL,
            .moves = {MOVE_WEATHER_BALL, MOVE_THUNDER},
        },
    },
};

const struct StarterPool sSunPool =
{
    .numMons = 6,
    .mons =
    {
        {
            .species = SPECIES_TAUROS_PALDEA_BLAZE,
            .moves = {MOVE_RAGING_BULL, MOVE_DOUBLE_KICK},
        },
        {
            .species = SPECIES_HELIOLISK,
            .moves = {MOVE_HYPER_VOICE, MOVE_THUNDERBOLT},
        },
        {
            .species = SPECIES_TROPIUS,
            .moves = {MOVE_LEECH_SEED, MOVE_TAILWIND},
        },
        {
            .species = SPECIES_CHANDELURE,
            .moves = {MOVE_OVERHEAT, MOVE_SHADOW_BALL},
        },
        {
            .species = SPECIES_LEAFEON,
            .moves = {MOVE_SWORDS_DANCE, MOVE_SOLAR_BLADE},
        },
        {
            .species = SPECIES_FLORGES,
            .moves = {MOVE_CALM_MIND, MOVE_MOONBLAST},
        },
    },
};

const struct StarterPool sSnowPool =
{
    .numMons = 6,
    .mons =
    {
        {
            .species = SPECIES_ESCAVALIER,
            .moves = {MOVE_MEGAHORN, MOVE_SHELTER},
        },
        {
            .species = SPECIES_GLACEON,
            .moves = {MOVE_BLIZZARD, MOVE_FREEZE_DRY},
        },
        {
            .species = SPECIES_DIANCIE,
            .moves = {MOVE_WISH, MOVE_DIAMOND_STORM},
        },
        {
            .species = SPECIES_WALREIN,
            .moves = {MOVE_PROTECT, MOVE_ICY_WIND},
        },
        {
            .species = SPECIES_EMPOLEON,
            .moves = {MOVE_METAL_SOUND, MOVE_BRINE},
        },
        {
            .species = SPECIES_SNEASLER,
            .moves = {MOVE_FIRE_PUNCH, MOVE_DIRE_CLAW},
        },
    },
};

const struct StarterPool sSandPool =
{
    .numMons = 6,
    .mons =
    {
        {
            .species = SPECIES_OMASTAR,
            .moves = {MOVE_SHELL_SMASH, MOVE_POWER_GEM},
        },
        {
            .species = SPECIES_DRACOZOLT,
            .moves = {MOVE_BOLT_BEAK, MOVE_DRAGON_RUSH},
        },
        {
            .species = SPECIES_STEELIX,
            .moves = {MOVE_COIL, MOVE_EARTHQUAKE},
        },
        {
            .species = SPECIES_GASTRODON,
            .moves = {MOVE_CHILLING_WATER, MOVE_RECOVER},
        },
        {
            .species = SPECIES_MANDIBUZZ,
            .moves = {MOVE_PARTING_SHOT, MOVE_TAILWIND},
        },
        {
            .species = SPECIES_PALOSSAND,
            .moves = {MOVE_SHORE_UP, MOVE_SHADOW_BALL},
        },
    },
};

const u16 sRainMiniBosses[] =
{
    SPECIES_BLASTOISE,
    SPECIES_BUTTERFREE,
    SPECIES_PIDGEOT,
    SPECIES_ARBOK,
    SPECIES_PIKACHU,
    SPECIES_NIDOKING,
    SPECIES_VILEPLUME,
    SPECIES_PARASECT,
    SPECIES_VENOMOTH,
    SPECIES_DUGTRIO,
    SPECIES_ARCANINE,
    SPECIES_ALAKAZAM,
    SPECIES_RAPIDASH,
    SPECIES_SLOWBRO,
    SPECIES_DEWGONG,
    SPECIES_CLOYSTER,
    SPECIES_GENGAR,
    SPECIES_EXEGGUTOR,
    SPECIES_MAROWAK,
    SPECIES_HITMONLEE,
    SPECIES_WEEZING,
    SPECIES_STARMIE,
    SPECIES_MR_MIME,
    SPECIES_MR_MIME_GALAR,
    SPECIES_SCYTHER,
    SPECIES_LAPRAS,
    SPECIES_VAPOREON,
    SPECIES_JOLTEON,
    SPECIES_AERODACTYL,
    SPECIES_MEGANIUM,
    SPECIES_FERALIGATR,
    SPECIES_CROBAT,
    SPECIES_LANTURN,
};

const u16 sSunMiniBosses[] =
{
    SPECIES_BLASTOISE,
    SPECIES_BUTTERFREE,
    SPECIES_PIDGEOT,
    SPECIES_ARBOK,
    SPECIES_PIKACHU,
    SPECIES_NIDOKING,
    SPECIES_VILEPLUME,
    SPECIES_PARASECT,
    SPECIES_VENOMOTH,
    SPECIES_DUGTRIO,
    SPECIES_ARCANINE,
    SPECIES_ALAKAZAM,
    SPECIES_RAPIDASH,
    SPECIES_SLOWBRO,
    SPECIES_DEWGONG,
    SPECIES_CLOYSTER,
    SPECIES_GENGAR,
    SPECIES_EXEGGUTOR,
    SPECIES_MAROWAK,
    SPECIES_HITMONLEE,
    SPECIES_WEEZING,
    SPECIES_STARMIE,
    SPECIES_MR_MIME,
    SPECIES_MR_MIME_GALAR,
    SPECIES_SCYTHER,
    SPECIES_LAPRAS,
    SPECIES_VAPOREON,
    SPECIES_JOLTEON,
    SPECIES_AERODACTYL,
    SPECIES_MEGANIUM,
    SPECIES_FERALIGATR,
    SPECIES_CROBAT,
    SPECIES_LANTURN,
};

const u16 sSnowMiniBosses[] =
{
    SPECIES_BLASTOISE,
    SPECIES_BUTTERFREE,
    SPECIES_PIDGEOT,
    SPECIES_ARBOK,
    SPECIES_PIKACHU,
    SPECIES_NIDOKING,
    SPECIES_VILEPLUME,
    SPECIES_PARASECT,
    SPECIES_VENOMOTH,
    SPECIES_DUGTRIO,
    SPECIES_ARCANINE,
    SPECIES_ALAKAZAM,
    SPECIES_RAPIDASH,
    SPECIES_SLOWBRO,
    SPECIES_DEWGONG,
    SPECIES_CLOYSTER,
    SPECIES_GENGAR,
    SPECIES_EXEGGUTOR,
    SPECIES_MAROWAK,
    SPECIES_HITMONLEE,
    SPECIES_WEEZING,
    SPECIES_STARMIE,
    SPECIES_MR_MIME,
    SPECIES_MR_MIME_GALAR,
    SPECIES_SCYTHER,
    SPECIES_LAPRAS,
    SPECIES_VAPOREON,
    SPECIES_JOLTEON,
    SPECIES_AERODACTYL,
    SPECIES_MEGANIUM,
    SPECIES_FERALIGATR,
    SPECIES_CROBAT,
    SPECIES_LANTURN,
};

const u16 sSandMiniBosses[] =
{
    SPECIES_BLASTOISE,
    SPECIES_BUTTERFREE,
    SPECIES_PIDGEOT,
    SPECIES_ARBOK,
    SPECIES_PIKACHU,
    SPECIES_NIDOKING,
    SPECIES_VILEPLUME,
    SPECIES_PARASECT,
    SPECIES_VENOMOTH,
    SPECIES_DUGTRIO,
    SPECIES_ARCANINE,
    SPECIES_ALAKAZAM,
    SPECIES_RAPIDASH,
    SPECIES_SLOWBRO,
    SPECIES_DEWGONG,
    SPECIES_CLOYSTER,
    SPECIES_GENGAR,
    SPECIES_EXEGGUTOR,
    SPECIES_MAROWAK,
    SPECIES_HITMONLEE,
    SPECIES_WEEZING,
    SPECIES_STARMIE,
    SPECIES_MR_MIME,
    SPECIES_MR_MIME_GALAR,
    SPECIES_SCYTHER,
    SPECIES_LAPRAS,
    SPECIES_VAPOREON,
    SPECIES_JOLTEON,
    SPECIES_AERODACTYL,
    SPECIES_MEGANIUM,
    SPECIES_FERALIGATR,
    SPECIES_CROBAT,
    SPECIES_LANTURN,
};
