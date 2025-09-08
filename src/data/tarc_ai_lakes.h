const struct BossMoveList sUxie1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_FUTURE_SIGHT,
        MOVE_MYSTICAL_POWER,
        MOVE_MIND_LOCK,
        MOVE_ICE_BEAM
    },
};

const struct BossMoveList sUxie2 =
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

const struct BossMoveList sUxie3 =
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
        MOVE_MYSTICAL_POWER,
        MOVE_FIERY_WRATH,
        MOVE_PSYCHIC,
        MOVE_WISH
    },
};

const struct BossMoveList sMesprit2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_MIND_SCRAMBLE,
        MOVE_STOMPING_TANTRUM,
        MOVE_BURNING_JEALOUSY,
        MOVE_LASH_OUT,
    },
};

const struct BossMoveList sMesprit3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_STORED_POWER,
        MOVE_POWER_TRIP,
        MOVE_HEADBUTT,
        MOVE_CELEBRATE,
    },
};

const struct BossMoveList sAzelf1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_PSYCHIC,
        MOVE_PSYCHO_CUT,
        MOVE_PSYSHOCK,
        MOVE_ZEN_HEADBUTT,
    },
};

const struct BossMoveList sAzelf2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_MIND_STEAL,
        MOVE_EXTRASENSORY,
        MOVE_MYSTICAL_POWER,
        MOVE_PSYSHIELD_BASH,
    },
};

const struct BossMoveList sAzelf3 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_TWIN_BEAM,
        MOVE_PSYCHIC,
        MOVE_PSYCHIC_FANGS,
    },
};

const struct BossAi sUxieAi =
{
    .phaseMoves =
    {
        &sUxie1,
        &sUxie2,
        &sUxie3,
    },
};

const struct BossAi sMespritAi =
{
    .phaseMoves =
    {
        &sMesprit1,
        &sMesprit2,
        &sMesprit3,
    },
};

const struct BossAi sAzelfAi =
{
    .phaseMoves =
    {
        &sAzelf1,
        &sAzelf2,
        &sAzelf3,
    },
};
