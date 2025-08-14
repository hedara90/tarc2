const struct BossMoveList sWoChien1 =
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

const struct BossMoveList sChienPao1 =
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

const struct BossMoveList sTingLu1 =
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

const struct BossMoveList sChiYu1 =
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

const struct BossAi sWoChienAi =
{
    .phaseMoves =
    {
        &sWoChien1,
        &sWoChien1,
        &sWoChien1,
        &sWoChien1,
    },
};

const struct BossAi sChienPaoAi =
{
    .phaseMoves =
    {
        &sChienPao1,
        &sChienPao1,
        &sChienPao1,
        &sChienPao1,
    },
};

const struct BossAi sTingLuAi =
{
    .phaseMoves =
    {
        &sTingLu1,
        &sTingLu1,
        &sTingLu1,
        &sTingLu1,
    },
};

const struct BossAi sChiYuAi =
{
    .phaseMoves =
    {
        &sChiYu1,
        &sChiYu1,
        &sChiYu1,
        &sChiYu1,
    },
};
