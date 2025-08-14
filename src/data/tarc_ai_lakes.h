const struct BossMoveList sUxie1 =
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

const struct BossMoveList sMesprit1 =
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

const struct BossMoveList sAzelf1 =
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

const struct BossAi sUxieAi =
{
    .phaseMoves =
    {
        &sUxie1,
        &sUxie1,
        &sUxie1,
        &sUxie1,
    },
};

const struct BossAi sMespritAi =
{
    .phaseMoves =
    {
        &sMesprit1,
        &sMesprit1,
        &sMesprit1,
        &sMesprit1,
    },
};

const struct BossAi sAzelfAi =
{
    .phaseMoves =
    {
        &sAzelf1,
        &sAzelf1,
        &sAzelf1,
        &sAzelf1,
    },
};
