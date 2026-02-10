const struct BossMoveList sXerneas1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_SANCTUARY,
        MOVE_DAZZLING_GLEAM,
        MOVE_HEALING_SPIRIT,
        MOVE_RAY_OF_LIFE,
        MOVE_MYSTICAL_FIRE,
        MOVE_INGRAIN
    },
};

const struct BossMoveList sXerneas2 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_GEOMANCY,
        MOVE_SOLAR_BEAM,
        MOVE_HEALING_SPIRIT,
        MOVE_FLEUR_CANNON,
        MOVE_STORED_POWER,
        MOVE_INGRAIN,
    },
};

const struct BossMoveList sXerneas3 =
{
    .numMoves = 7,
    .moves =
    {
        MOVE_SANCTUARY,
        MOVE_EARTH_POWER,
        MOVE_DRAINING_KISS,
        MOVE_RAY_OF_LIFE,
        MOVE_HEALING_SPIRIT,
        MOVE_GEOMANCY,
        MOVE_STORED_POWER,
    },
};

const struct BossMoveList sXerneas4 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_GEOMANCY,
        MOVE_STORED_POWER,
        MOVE_FLEUR_CANNON,
        MOVE_REFLECT,
        MOVE_HEALING_SPIRIT,
        MOVE_RAY_OF_LIFE,
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

const struct BossMoveList sGiratina1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_TRICK_OR_TREAT,
        MOVE_PHANTOM_FORCE,
        MOVE_AURA_SPHERE,
        MOVE_BANISH,
        MOVE_DIMENSION_BREAK,
        MOVE_PAIN_SPLIT,
    },
};

const struct BossMoveList sGiratina2 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_SPIRIT_SHACKLE,
        MOVE_TRICK_OR_TREAT,
        MOVE_SHADOW_BALL,
        MOVE_BANISH,
        MOVE_EARTH_POWER,
        MOVE_DRAGON_PULSE,
    },
};

const struct BossMoveList sGiratina3 =
{
    .numMoves = 7,
    .moves =
    {
        MOVE_PLANAR_IMPRISONMENT,
        MOVE_PHANTOM_FORCE,
        MOVE_DRAGON_DANCE,
        MOVE_SHADOW_BALL,
        MOVE_DRAGON_PULSE,
        MOVE_AURA_SPHERE,
        MOVE_SPECTRAL_THIEF,
    },
};

const struct BossMoveList sGiratina4 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_DIMENSION_BREAK,
        MOVE_AURA_SPHERE,
        MOVE_BANISH,
        MOVE_SHADOW_BALL,
        MOVE_CURSE,
    },
};

const struct BossAi sGiratinaAi =
{
    .phaseMoves =
    {
        &sGiratina1,
        &sGiratina2,
        &sGiratina3,
        &sGiratina4,
    },
};

const struct BossMoveList sDelibird1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_BLUE_PRESENT,
        MOVE_CHARM,
        MOVE_RED_PRESENT,
        MOVE_EERIE_IMPULSE,
    },
};

const struct BossMoveList sDelibird2 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_RED_PRESENT,
        MOVE_METAL_SOUND,
        MOVE_YELLOW_PRESENT,
    },
};

const struct BossMoveList sDelibird3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SOAK,
        MOVE_YELLOW_PRESENT,
        MOVE_STOMPING_TANTRUM,
        MOVE_BLUE_PRESENT,
    },
};

const struct BossMoveList sDelibird4 =
{
    .numMoves = 2,
    .moves =
    {
        MOVE_BLIZZARD,
        MOVE_HEX,
    },
};

const struct BossAi sDelibirdAi =
{
    .phaseMoves =
    {
        &sDelibird1,
        &sDelibird2,
        &sDelibird3,
        &sDelibird4,
    },
};
