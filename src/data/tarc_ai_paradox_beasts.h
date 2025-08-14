const struct BossMoveList sWalkingWake1 =
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

const struct BossMoveList sGougingFire1 =
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

const struct BossMoveList sRagingBolt1 =
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

const struct BossAi sWalkingWakeAi =
{
    .phaseMoves =
    {
        &sWalkingWake1,
        &sWalkingWake1,
        &sWalkingWake1,
        &sWalkingWake1,
    },
};

const struct BossAi sGougingFireAi =
{
    .phaseMoves =
    {
        &sGougingFire1,
        &sGougingFire1,
        &sGougingFire1,
        &sGougingFire1,
    },
};

const struct BossAi sRagingBoltAi =
{
    .phaseMoves =
    {
        &sRagingBolt1,
        &sRagingBolt1,
        &sRagingBolt1,
        &sRagingBolt1,
    },
};
