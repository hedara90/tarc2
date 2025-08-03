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

const struct BossGroup *sBossGroups[] =
{
    &sBirds,
    &sBeasts,
    &sGolems,
    &sLakes,
    &sSwords,
    &sGenies,
    &sTapus,
    &sTreasures,
    &sLoyal,
    &sGalarBirds,
    &sParadoxBeasts,
    &sParadoxSwords,
    &sPseudos,
};

const struct StarterMon sStarterMons[MON_LIST_RANDOM][3] =
{
    [MON_LIST_RAIN_DIRECT] =
    {
        {
            .species = SPECIES_POLITOED,
            .moves =
            {
                MOVE_TACKLE,
                MOVE_TACKLE,
                MOVE_TACKLE,
                MOVE_TACKLE
            }
        },
        {
            .species = SPECIES_KILOWATTREL,
            .moves =
            {
                MOVE_HURRICANE,
                MOVE_THUNDER,
                MOVE_TACKLE,
                MOVE_TACKLE
            }
        },
        {
            .species = SPECIES_ARMALDO,
            .moves =
            {
                MOVE_TACKLE,
                MOVE_TACKLE,
                MOVE_TACKLE,
                MOVE_TACKLE
            },
        },
    },
};
