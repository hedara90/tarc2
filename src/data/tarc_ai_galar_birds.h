const struct BossMoveList sArticunoGalar1 =
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

const struct BossMoveList sZapdosGalar1 =
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

const struct BossMoveList sMoltresGalar1 =
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

const struct BossAi sArticunoGalarAi =
{
    .phaseMoves =
    {
        &sArticunoGalar1,
        &sArticunoGalar1,
        &sArticunoGalar1,
        &sArticunoGalar1,
    },
};

const struct BossAi sZapdosGalarAi =
{
    .phaseMoves =
    {
        &sZapdosGalar1,
        &sZapdosGalar1,
        &sZapdosGalar1,
        &sZapdosGalar1,
    },
};

const struct BossAi sMoltresGalarAi =
{
    .phaseMoves =
    {
        &sMoltresGalar1,
        &sMoltresGalar1,
        &sMoltresGalar1,
        &sMoltresGalar1,
    },
};
