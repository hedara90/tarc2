const struct BossMoveList sKoko1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_DISCHARGE,
        MOVE_THUNDERBOLT,
        MOVE_DAZZLING_GLEAM,
        MOVE_SHOCK_WAVE,
        MOVE_ROOST
    },
};

const struct BossMoveList sKoko2 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_WILD_CHARGE,
        MOVE_IRON_HEAD,
        MOVE_ACROBATICS,
        MOVE_PLAY_ROUGH,
        MOVE_ROOST
    },
};

const struct BossMoveList sKoko3 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_THUNDERBOLT,
        MOVE_ELECTRO_BALL,
        MOVE_WILD_CHARGE,
        MOVE_BRAVE_BIRD,
        MOVE_ROOST,
    },
};

const struct BossMoveList sLele1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_PSYCHIC,
        MOVE_SHADOW_BALL,
        MOVE_ENERGY_BALL,
        MOVE_MOONBLAST
    },
};

const struct BossMoveList sLele2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_EXTRASENSORY,
        MOVE_PSYBEAM,
        MOVE_DRAINING_KISS,
        MOVE_NATURES_MADNESS,
    },
};

const struct BossMoveList sLele3 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_MOONBLAST,
        MOVE_PSYCHIC,
        MOVE_SHADOW_BALL,
    },
};

const struct BossMoveList sBulu1 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_TRAILBLAZE,
        MOVE_WOOD_HAMMER,
        MOVE_HORN_LEECH,
    },
};

const struct BossMoveList sBulu2 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_MEGAHORN,
        MOVE_BULLET_SEED,
        MOVE_PLAY_ROUGH,
        MOVE_HORN_LEECH,
        MOVE_LEECH_SEED,
    },
};

const struct BossMoveList sBulu3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_WOOD_HAMMER,
        MOVE_HORN_LEECH,
        MOVE_PLAY_ROUGH,
        MOVE_SUPERPOWER,
    },
};

const struct BossMoveList sFini1 =
{
    .numMoves = 10,
    .moves =
    {
        MOVE_AQUA_RING,
        MOVE_CALM_MIND,
        MOVE_PROTECT,
        MOVE_CALM_MIND,
        MOVE_IRON_DEFENSE,
        MOVE_DRAINING_KISS,
        MOVE_NATURES_MADNESS,
        MOVE_SCALD,
        MOVE_SUBSTITUTE,
        MOVE_ICE_BEAM,
    },
};

const struct BossMoveList sFini2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_NATURES_MADNESS,
        MOVE_BRINE,
        MOVE_DRAINING_KISS,
        MOVE_MOONBLAST,
    },
};

const struct BossMoveList sFini3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SCALD,
        MOVE_MOONBLAST,
        MOVE_BRINE,
        MOVE_DRAINING_KISS,
    },
};

const struct BossAi sKokoAi =
{
    .phaseMoves =
    {
        &sKoko1,
        &sKoko2,
        &sKoko3,
    },
};

const struct BossAi sLeleAi =
{
    .phaseMoves =
    {
        &sLele1,
        &sLele2,
        &sLele3,
    },
};

const struct BossAi sBuluAi =
{
    .phaseMoves =
    {
        &sBulu1,
        &sBulu2,
        &sBulu3,
    },
};

const struct BossAi sFiniAi =
{
    .phaseMoves =
    {
        &sFini1,
        &sFini2,
        &sFini3,
    },
};
