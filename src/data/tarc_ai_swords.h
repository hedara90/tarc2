const struct BossMoveList sCobalion1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SECRET_SWORD,
        MOVE_SACRED_SWORD,
        MOVE_SWORDS_DANCE,
        MOVE_BEHEMOTH_BLADE,
        MOVE_AIR_SLASH
    },
};

const struct BossMoveList sCobalion2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SCREECH,
        MOVE_WORK_UP,
        MOVE_SECRET_SWORD,
        MOVE_BITTER_BLADE,
    },
};

const struct BossMoveList sCobalion3 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_SECRET_SWORD,
        MOVE_BEHEMOTH_BLADE,
        MOVE_BITTER_BLADE,
    },
};

const struct BossMoveList sTerrakion1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_STONE_EDGE,
        MOVE_DOUBLE_KICK,
        MOVE_SWORDS_DANCE,
        MOVE_EARTHQUAKE,
        MOVE_TRAILBLAZE,
        MOVE_CLOSE_COMBAT,
    },
};

const struct BossMoveList sTerrakion2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_MIGHTY_CLEAVE,
        MOVE_DOUBLE_KICK,
        MOVE_ROCK_SLIDE,
        MOVE_SECRET_SWORD,
    },
};

const struct BossMoveList sTerrakion3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SUPERPOWER,
        MOVE_STONE_EDGE,
        MOVE_CLOSE_COMBAT,
        MOVE_MIGHTY_CLEAVE,
    },
};

const struct BossMoveList sVirizion1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_LEAF_BLADE,
        MOVE_RAZOR_SHELL,
        MOVE_SACRED_SWORD,
        MOVE_SYNTHESIS,
    },
};

const struct BossMoveList sVirizion2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_LEAF_BLADE,
        MOVE_ENERGY_BALL,
        MOVE_GRASSY_TERRAIN,
        MOVE_GRASSY_GLIDE
    },
};

const struct BossMoveList sVirizion3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_LEAF_BLADE,
        MOVE_SECRET_SWORD,
        MOVE_LEAF_BLADE,
        MOVE_SACRED_SWORD,
    },
};

const struct BossMoveList sKeldeo1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_AQUA_CUTTER,
        MOVE_SECRET_SWORD,
        MOVE_CALM_MIND,
        MOVE_AQUA_RING,
    },
};

const struct BossMoveList sKeldeo2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_AQUA_CUTTER,
        MOVE_AIR_SLASH,
        MOVE_PSYCHO_CUT,
        MOVE_CHILLING_WATER,
    },
};

const struct BossMoveList sKeldeo3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_HYDRO_PUMP,
        MOVE_SECRET_SWORD,
        MOVE_AQUA_CUTTER,
        MOVE_SACRED_SWORD,
    },
};

const struct BossAi sCobalionAi =
{
    .phaseMoves =
    {
        &sCobalion1,
        &sCobalion2,
        &sCobalion3,
    },
};

const struct BossAi sTerrakionAi =
{
    .phaseMoves =
    {
        &sTerrakion1,
        &sTerrakion2,
        &sTerrakion3,
    },
};

const struct BossAi sVirizionAi =
{
    .phaseMoves =
    {
        &sVirizion1,
        &sVirizion2,
        &sVirizion3,
    },
};

const struct BossAi sKeldeoAi =
{
    .phaseMoves =
    {
        &sKeldeo1,
        &sKeldeo2,
        &sKeldeo3,
    },
};
