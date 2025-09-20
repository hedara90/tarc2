const struct BossMoveList sWoChien1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_ENERGY_BALL,
        MOVE_LASH_OUT,
        MOVE_SEED_BOMB,
        MOVE_DARK_PULSE,
        MOVE_FOUL_PLAY
    },
};

const struct BossMoveList sWoChien2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_POWER_WHIP,
        MOVE_RUINATION,
        MOVE_FOUL_PLAY,
        MOVE_GIGA_DRAIN,
    },
};

const struct BossMoveList sWoChien3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_PUNISHMENT,
        MOVE_FOUL_PLAY,
        MOVE_GRASS_KNOT,
        MOVE_GIGA_DRAIN
    },
};

const struct BossMoveList sChienPao1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_NIGHT_SLASH,
        MOVE_ICE_SPINNER,
        MOVE_THROAT_CHOP,
        MOVE_AERIAL_ACE,
    },
};

const struct BossMoveList sChienPao2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SWORDS_DANCE,
        MOVE_ICE_FANG,
        MOVE_RUINATION,
        MOVE_ICICLE_CRASH,
    },
};

const struct BossMoveList sChienPao3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_RUINATION,
        MOVE_SACRED_SWORD,
        MOVE_NIGHT_SLASH,
        MOVE_ICE_FANG
    },
};

const struct BossMoveList sTingLu1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_RUINATION,
        MOVE_BULLDOZE,
        MOVE_STOMPING_TANTRUM,
        MOVE_THROAT_CHOP,
    },
};

const struct BossMoveList sTingLu2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_ROCK_SLIDE,
        MOVE_HEAVY_SLAM,
        MOVE_EARTHQUAKE,
        MOVE_BODY_PRESS,
    },
};

const struct BossMoveList sTingLu3 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_RUINATION,
        MOVE_EARTHQUAKE,
        MOVE_DIG,
        MOVE_PAYBACK,
        MOVE_EARTHQUAKE
    },
};

const struct BossMoveList sChiYu1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_NASTY_PLOT,
        MOVE_INCINERATE,
        MOVE_BURNING_JEALOUSY,
        MOVE_FLAMETHROWER,
        MOVE_OVERHEAT,
    },
};

const struct BossMoveList sChiYu2 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_RUINATION,
        MOVE_FLAMETHROWER,
        MOVE_DARK_PULSE,
    },
};

const struct BossMoveList sChiYu3 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_NASTY_PLOT,
        MOVE_FLAMETHROWER,
        MOVE_OVERHEAT,
    },
};

const struct BossAi sWoChienAi =
{
    .phaseMoves =
    {
        &sWoChien1,
        &sWoChien2,
        &sWoChien3,
    },
};

const struct BossAi sChienPaoAi =
{
    .phaseMoves =
    {
        &sChienPao1,
        &sChienPao2,
        &sChienPao3,
    },
};

const struct BossAi sTingLuAi =
{
    .phaseMoves =
    {
        &sTingLu1,
        &sTingLu2,
        &sTingLu3,
    },
};

const struct BossAi sChiYuAi =
{
    .phaseMoves =
    {
        &sChiYu1,
        &sChiYu2,
        &sChiYu3,
    },
};
