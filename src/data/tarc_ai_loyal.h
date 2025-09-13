const struct BossMoveList sOkidogi1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_POWER_UP_PUNCH,
        MOVE_POISON_JAB,
        MOVE_TAUNT,
        MOVE_HAMMER_ARM,
    },
};

const struct BossMoveList sOkidogi2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_POWER_UP_PUNCH,
        MOVE_HAMMER_ARM,
        MOVE_GUNK_SHOT,
        MOVE_DRAIN_PUNCH,
    },
};

const struct BossMoveList sOkidogi3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_POWER_UP_PUNCH,
        MOVE_HAMMER_ARM,
        MOVE_POISON_JAB,
        MOVE_DRAIN_PUNCH,
    },
};

const struct BossMoveList sMunkidori1 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_NASTY_PLOT,
        MOVE_PSYCHIC,
        MOVE_ACID_SPRAY,
    },
};

const struct BossMoveList sMunkidori2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_TAUNT,
        MOVE_JAB_MIND,
        MOVE_POISON_DROPLETS,
        MOVE_PSYBEAM,
    },
};

const struct BossMoveList sMunkidori3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_JAB_MIND,
        MOVE_VENOSHOCK,
        MOVE_LASH_OUT,
        MOVE_POISON_DROPLETS
    },
};

const struct BossMoveList sFezandipiti1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_DUAL_WINGBEAT,
        MOVE_PLAY_ROUGH,
        MOVE_DUAL_CHOP,
        MOVE_BARB_BARRAGE,
        MOVE_ROOST
    },
};

const struct BossMoveList sFezandipiti2 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_BARB_BARRAGE,
        MOVE_DUAL_WINGBEAT,
        MOVE_DRAINING_KISS,
        MOVE_TORMENT,
        MOVE_ROOST
    },
};

const struct BossMoveList sFezandipiti3 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_BARB_BARRAGE,
        MOVE_PLAY_ROUGH,
        MOVE_DUAL_WINGBEAT,
    },
};

const struct BossAi sOkidogiAi =
{
    .phaseMoves =
    {
        &sOkidogi1,
        &sOkidogi2,
        &sOkidogi3,
    },
};

const struct BossAi sMunkidoriAi =
{
    .phaseMoves =
    {
        &sMunkidori1,
        &sMunkidori2,
        &sMunkidori3,
    },
};

const struct BossAi sFezandipitiAi =
{
    .phaseMoves =
    {
        &sFezandipiti1,
        &sFezandipiti2,
        &sFezandipiti3,
    },
};
