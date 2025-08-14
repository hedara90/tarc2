const struct BossMoveList sOkidogi1 =
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

const struct BossMoveList sMunkidori1 =
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

const struct BossMoveList sFezandipiti1 =
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

const struct BossAi sOkidogiAi =
{
    .phaseMoves =
    {
        &sOkidogi1,
        &sOkidogi1,
        &sOkidogi1,
        &sOkidogi1,
    },
};

const struct BossAi sMunkidoriAi =
{
    .phaseMoves =
    {
        &sMunkidori1,
        &sMunkidori1,
        &sMunkidori1,
        &sMunkidori1,
    },
};

const struct BossAi sFezandipitiAi =
{
    .phaseMoves =
    {
        &sFezandipiti1,
        &sFezandipiti1,
        &sFezandipiti1,
        &sFezandipiti1,
    },
};
