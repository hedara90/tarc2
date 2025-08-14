const struct BossMoveList sCobalion1 =
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

const struct BossMoveList sTerrakion1 =
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

const struct BossMoveList sVirizion1 =
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

const struct BossMoveList sKeldeo1 =
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

const struct BossAi sCobalionAi =
{
    .phaseMoves =
    {
        &sCobalion1,
        &sCobalion1,
        &sCobalion1,
        &sCobalion1,
    },
};

const struct BossAi sTerrakionAi =
{
    .phaseMoves =
    {
        &sTerrakion1,
        &sTerrakion1,
        &sTerrakion1,
        &sTerrakion1,
    },
};

const struct BossAi sVirizionAi =
{
    .phaseMoves =
    {
        &sVirizion1,
        &sVirizion1,
        &sVirizion1,
        &sVirizion1,
    },
};

const struct BossAi sKeldeoAi =
{
    .phaseMoves =
    {
        &sKeldeo1,
        &sKeldeo1,
        &sKeldeo1,
        &sKeldeo1,
    },
};
