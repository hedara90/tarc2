const struct BossMoveList sRaikou1 =
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

const struct BossMoveList sEntei1 =
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

const struct BossMoveList sSuicune1 =
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

const struct BossAi sRaikouAi =
{
    .phaseMoves =
    {
        &sRaikou1,
        &sRaikou1,
        &sRaikou1,
        &sRaikou1,
    },
};

const struct BossAi sEnteiAi =
{
    .phaseMoves =
    {
        &sEntei1,
        &sEntei1,
        &sEntei1,
        &sEntei1,
    },
};

const struct BossAi sSuicuneAi =
{
    .phaseMoves =
    {
        &sSuicune1,
        &sSuicune1,
        &sSuicune1,
        &sSuicune1,
    },
};
