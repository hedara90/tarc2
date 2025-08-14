const struct BossMoveList sIronLeaves1 =
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

const struct BossMoveList sIronBoulder1 =
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

const struct BossMoveList sIronCrown1 =
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

const struct BossAi sIronLeavesAi =
{
    .phaseMoves =
    {
        &sIronLeaves1,
        &sIronLeaves1,
        &sIronLeaves1,
        &sIronLeaves1,
    },
};

const struct BossAi sIronBoulderAi =
{
    .phaseMoves =
    {
        &sIronBoulder1,
        &sIronBoulder1,
        &sIronBoulder1,
        &sIronBoulder1,
    },
};

const struct BossAi sIronCrownAi =
{
    .phaseMoves =
    {
        &sIronCrown1,
        &sIronCrown1,
        &sIronCrown1,
        &sIronCrown1,
    },
};
