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
        MOVE_MOONBLAST,
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
        MOVE_MOONBLAST,
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

const struct BossMoveList sLugia1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_BLEAKWIND_STORM,
        MOVE_ROOST,
        MOVE_TSUNAMI,
        MOVE_WHIRLPOOL,
        MOVE_FEATHER_DANCE,
        MOVE_CHILLING_WATER,
    },
};

const struct BossMoveList sLugia2 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_TSUNAMI,
        MOVE_ELECTRO_SHOT,
        MOVE_EARTH_POWER,
        MOVE_OBLIVION_WING,
        MOVE_ANCIENT_POWER,
        MOVE_NOBLE_ROAR,
    },
};

const struct BossMoveList sLugia3 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_LUMINA_CRASH,
        MOVE_GLACIATE,
        MOVE_TSUNAMI,
        MOVE_BLEAKWIND_STORM,
        MOVE_ELECTRO_SHOT,
    },
};

const struct BossMoveList sLugia4 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_WATER_SPOUT,
        MOVE_BLEAKWIND_STORM,
        MOVE_ELECTRO_SHOT,
        MOVE_WHIRLPOOL,
        MOVE_PSYCHIC,
        MOVE_OBLIVION_WING,
    },
};

const struct BossAi sLugiaAi =
{
    .phaseMoves =
    {
        &sLugia1,
        &sLugia2,
        &sLugia3,
        &sLugia4,
    },
};
