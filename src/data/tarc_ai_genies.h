const struct BossMoveList sTornadus1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_TWISTER,
        MOVE_HURRICANE,
        MOVE_HEAT_WAVE,
        MOVE_ICY_WIND,
        MOVE_ROOST
    },
};

const struct BossMoveList sTornadus2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_BLEAKWIND_STORM,
        MOVE_WILDBOLT_STORM,
        MOVE_SANDSEAR_STORM,
        MOVE_SPRINGTIDE_STORM,
    },
};

const struct BossMoveList sTornadus3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_TAILWIND,
        MOVE_AEROBLAST,
        MOVE_HURRICANE,
        MOVE_BLEAKWIND_STORM,
    },
};

const struct BossMoveList sThundurus1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_CHARGE,
        MOVE_WILDBOLT_STORM,
        MOVE_THUNDER_WAVE,
        MOVE_EERIE_IMPULSE,
    },
};

const struct BossMoveList sThundurus2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_VOLT_TACKLE,
        MOVE_ELECTRO_BALL,
        MOVE_CHARGE,
        MOVE_PARABOLIC_CHARGE,
    },
};

const struct BossMoveList sThundurus3 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_WILDBOLT_STORM,
        MOVE_BRAVE_BIRD,
        MOVE_PARABOLIC_CHARGE,
    },
};

const struct BossMoveList sLandorus1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_TAILWIND,
        MOVE_EARTHQUAKE,
        MOVE_FLOATY_FALL,
        MOVE_ROCK_SLIDE
    },
};

const struct BossMoveList sLandorus2 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_SANDSEAR_STORM,
        MOVE_SLUDGE_WAVE,
        MOVE_PSYCHIC,
    },
};

const struct BossMoveList sLandorus3 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_EARTHQUAKE,
        MOVE_SANDSEAR_STORM,
        MOVE_FLY,
        MOVE_SANDSTORM,
        MOVE_ROCK_SLIDE,
    },
};

const struct BossMoveList sEnamorus1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SPRINGTIDE_STORM,
        MOVE_TAILWIND,
        MOVE_PETAL_BLIZZARD,
        MOVE_HURRICANE,
    },
};

const struct BossMoveList sEnamorus2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SPRINGTIDE_STORM,
        MOVE_DRAINING_KISS,
        MOVE_AIR_SLASH,
        MOVE_ICY_WIND,
    },
};

const struct BossMoveList sEnamorus3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_TAILWIND,
        MOVE_SPRINGTIDE_STORM,
        MOVE_HURRICANE,
        MOVE_SPRINGTIDE_STORM,
    },
};

const struct BossAi sTornadusAi =
{
    .phaseMoves =
    {
        &sTornadus1,
        &sTornadus2,
        &sTornadus3,
    },
};

const struct BossAi sThundurusAi =
{
    .phaseMoves =
    {
        &sThundurus1,
        &sThundurus2,
        &sThundurus3,
    },
};

const struct BossAi sLandorusAi =
{
    .phaseMoves =
    {
        &sLandorus1,
        &sLandorus2,
        &sLandorus3,
    },
};

const struct BossAi sEnamorusAi =
{
    .phaseMoves =
    {
        &sEnamorus1,
        &sEnamorus2,
        &sEnamorus3,
    },
};
