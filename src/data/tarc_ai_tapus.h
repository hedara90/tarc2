const struct BossMoveList sKoko1 =
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

const struct BossMoveList sLele1 =
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

const struct BossMoveList sBulu1 =
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

const struct BossMoveList sFini1 =
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

const struct BossAi sKokoAi =
{
    .phaseMoves =
    {
        &sKoko1,
        &sKoko1,
        &sKoko1,
        &sKoko1,
    },
};

const struct BossAi sLeleAi =
{
    .phaseMoves =
    {
        &sLele1,
        &sLele1,
        &sLele1,
        &sLele1,
    },
};

const struct BossAi sBuluAi =
{
    .phaseMoves =
    {
        &sBulu1,
        &sBulu1,
        &sBulu1,
        &sBulu1,
    },
};

const struct BossAi sFiniAi =
{
    .phaseMoves =
    {
        &sFini1,
        &sFini1,
        &sFini1,
        &sFini1,
    },
};
