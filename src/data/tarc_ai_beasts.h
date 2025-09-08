const struct BossMoveList sRaikou1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_WILDBOLT_STORM,
        MOVE_CHARGE_BEAM,
        MOVE_TAILWIND,
        MOVE_ELECTRO_BALL,
    },
};

const struct BossMoveList sRaikou2 =
{
    .numMoves = 2,
    .moves =
    {
        MOVE_WILDBOLT_STORM,
        MOVE_WEATHER_BALL,
    },
};

const struct BossMoveList sRaikou3 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_WILDBOLT_STORM,
        MOVE_SCALD,
        MOVE_BLEAKWIND_STORM,
        MOVE_WEATHER_BALL,
    },
};

const struct BossMoveList sEntei1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SACRED_FIRE,
        MOVE_SCORCHING_SANDS,
        MOVE_EXTREME_SPEED,
        MOVE_FLAME_CHARGE
    },
};

const struct BossMoveList sEntei2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_FLARE_BLITZ,
        MOVE_BULLDOZE,
        MOVE_FLAME_CHARGE,
        MOVE_ACCELEROCK,
    },
};

const struct BossMoveList sEntei3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SACRED_FIRE,
        MOVE_CRUNCH,
        MOVE_EXTREME_SPEED,
        MOVE_FLAME_CHARGE,
    },
};

const struct BossMoveList sSuicune1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_AURORA_VEIL,
        MOVE_AURORA_BEAM,
        MOVE_CHILLING_WATER,
        MOVE_CALM_MIND,
        MOVE_AQUA_RING,
    },
};
const struct BossMoveList sSuicune2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_BLIZZARD,
        MOVE_CHILLING_WATER,
        MOVE_BLIZZARD,
        MOVE_LIFE_DEW
    },
};
const struct BossMoveList sSuicune3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SURF,
        MOVE_BLIZZARD,
        MOVE_AIR_SLASH,
        MOVE_EXTRASENSORY,
    },
};

const struct BossAi sRaikouAi =
{
    .phaseMoves =
    {
        &sRaikou1,
        &sRaikou2,
        &sRaikou3,
    },
};

const struct BossAi sEnteiAi =
{
    .phaseMoves =
    {
        &sEntei1,
        &sEntei2,
        &sEntei3,
    },
};

const struct BossAi sSuicuneAi =
{
    .phaseMoves =
    {
        &sSuicune1,
        &sSuicune2,
        &sSuicune3,
    },
};
