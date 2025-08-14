const struct BossMoveList sTornadus1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_TACKLE,
        MOVE_ICE_BEAM,
        MOVE_HAZE,
        MOVE_ROOST
    },
};

const struct BossMoveList sThundurus1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_TACKLE,
        MOVE_ICE_BEAM,
        MOVE_HAZE,
        MOVE_ROOST
    },
};

const struct BossMoveList sLandorus1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_EMBER,
        MOVE_FIRE_SPIN,
        MOVE_FIRE_BLAST,
        MOVE_ROOST
    },
};

const struct BossMoveList sEnamorus1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_EMBER,
        MOVE_FIRE_SPIN,
        MOVE_FIRE_BLAST,
        MOVE_ROOST
    },
};

const struct BossAi sTornadusAi =
{
    .phaseMoves =
    {
        &sTornadus1,
        &sTornadus1,
        &sTornadus1,
        &sTornadus1,
    },
};

const struct BossAi sThundurusAi =
{
    .phaseMoves =
    {
        &sThundurus1,
        &sThundurus1,
        &sThundurus1,
        &sThundurus1,
    },
};

const struct BossAi sLandorusAi =
{
    .phaseMoves =
    {
        &sLandorus1,
        &sLandorus1,
        &sLandorus1,
        &sLandorus1,
    },
};

const struct BossAi sEnamorusAi =
{
    .phaseMoves =
    {
        &sEnamorus1,
        &sEnamorus1,
        &sEnamorus1,
        &sEnamorus1,
    },
};
