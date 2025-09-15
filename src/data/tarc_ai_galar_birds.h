const struct BossMoveList sArticunoGalar1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_FREEZING_GLARE,
        MOVE_AIR_SLASH,
        MOVE_ICE_BEAM,
        MOVE_PSYCHIC,
        MOVE_ROOST
    },
};

const struct BossMoveList sArticunoGalar2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_FREEZING_GLARE,
        MOVE_ICE_BEAM,
        MOVE_PSYSHOCK,
        MOVE_HURRICANE,
    },
};

const struct BossMoveList sArticunoGalar3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_PSYCHIC_NOISE,
        MOVE_FREEZING_GLARE,
        MOVE_HURRICANE,
        MOVE_AIR_SLASH
    },
};

const struct BossMoveList sZapdosGalar1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_BULK_UP,
        MOVE_THUNDEROUS_KICK,
        MOVE_DRILL_PECK,
        MOVE_WILD_CHARGE,
    },
};

const struct BossMoveList sZapdosGalar2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_DRILL_PECK,
        MOVE_THUNDEROUS_KICK,
        MOVE_BRAVE_BIRD,
        MOVE_ROOST
    },
};

const struct BossMoveList sZapdosGalar3 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_THUNDEROUS_KICK,
        MOVE_DUAL_WINGBEAT,
        MOVE_STOMPING_TANTRUM,
    },
};

const struct BossMoveList sMoltresGalar1 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_NASTY_PLOT,
        MOVE_FIERY_WRATH,
        MOVE_AIR_SLASH,
    },
};

const struct BossMoveList sMoltresGalar2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_FLAMETHROWER,
        MOVE_TAILWIND,
        MOVE_FIERY_WRATH,
        MOVE_AIR_SLASH
    },
};

const struct BossMoveList sMoltresGalar3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_FIERY_WRATH,
        MOVE_HURRICANE,
        MOVE_ROOST,
        MOVE_TAILWIND
    },
};

const struct BossAi sArticunoGalarAi =
{
    .phaseMoves =
    {
        &sArticunoGalar1,
        &sArticunoGalar2,
        &sArticunoGalar3,
    },
};

const struct BossAi sZapdosGalarAi =
{
    .phaseMoves =
    {
        &sZapdosGalar1,
        &sZapdosGalar2,
        &sZapdosGalar3,
    },
};

const struct BossAi sMoltresGalarAi =
{
    .phaseMoves =
    {
        &sMoltresGalar1,
        &sMoltresGalar2,
        &sMoltresGalar3,
    },
};
