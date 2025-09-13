const struct BossMoveList sXerneas1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_SANCTUARY,
        MOVE_DAZZLING_GLEAM,
        MOVE_HEALING_SPIRIT,
        MOVE_MYSTICAL_FIRE,
        MOVE_STORED_POWER,
        MOVE_INGRAIN
    },
};

const struct BossMoveList sXerneas2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_HEALING_SPIRIT,
        MOVE_FLEUR_CANNON,
        MOVE_SOLAR_BEAM,
        MOVE_STORED_POWER,
    },
};

const struct BossMoveList sXerneas3 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SANCTUARY,
        MOVE_GEOMANCY,
        MOVE_EARTH_POWER,
        MOVE_DRAINING_KISS,
        MOVE_STORED_POWER,
    },
};

const struct BossMoveList sXerneas4 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_GEOMANCY,
        MOVE_EARTH_POWER,
        MOVE_FLEUR_CANNON,
        MOVE_ANCIENT_POWER,
        MOVE_STORED_POWER,
    },
};

const struct BossAi sXerneasAi =
{
    .phaseMoves =
    {
        &sXerneas1,
        &sXerneas2,
        &sXerneas3,
        &sXerneas4,
    },
};
