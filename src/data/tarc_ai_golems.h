const struct BossMoveList sRegirock1 =
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

const struct BossMoveList sRegice1 =
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

const struct BossMoveList sRegisteel1 =
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

const struct BossMoveList sRegieleki1 =
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

const struct BossMoveList sRegidrago1 =
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

const struct BossAi sRegirockAi =
{
    .phaseMoves =
    {
        &sRegirock1,
        &sRegirock1,
        &sRegirock1,
        &sRegirock1,
    },
};

const struct BossAi sRegiceAi =
{
    .phaseMoves =
    {
        &sRegice1,
        &sRegice1,
        &sRegice1,
        &sRegice1,
    },
};

const struct BossAi sRegisteelAi =
{
    .phaseMoves =
    {
        &sRegisteel1,
        &sRegisteel1,
        &sRegisteel1,
        &sRegisteel1,
    },
};

const struct BossAi sRegielekiAi =
{
    .phaseMoves =
    {
        &sRegieleki1,
        &sRegieleki1,
        &sRegieleki1,
        &sRegieleki1,
    },
};

const struct BossAi sRegidragoAi =
{
    .phaseMoves =
    {
        &sRegidrago1,
        &sRegidrago1,
        &sRegidrago1,
        &sRegidrago1,
    },
};
