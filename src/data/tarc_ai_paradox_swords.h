const struct BossMoveList sIronLeaves1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_LEECH_SEED,
        MOVE_PSYBLADE,
        MOVE_TRAILBLAZE,
        MOVE_SCREECH,
    },
};

const struct BossMoveList sIronLeaves2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_TRAILBLAZE,
        MOVE_PSYBLADE,
        MOVE_SCREECH,
        MOVE_LEAF_BLADE,
    },
};

const struct BossMoveList sIronLeaves3 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_PSYBLADE,
        MOVE_LEECH_SEED,
        MOVE_LEAF_BLADE,
    },
};

const struct BossMoveList sIronBoulder1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_MIGHTY_CLEAVE,
        MOVE_PSYCHO_CUT,
        MOVE_ROCK_SLIDE,
        MOVE_ZEN_HEADBUTT
    },
};

const struct BossMoveList sIronBoulder2 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_IRON_HEAD,
        MOVE_MIGHTY_CLEAVE,
        MOVE_PSYCHO_CUT,
    },
};

const struct BossMoveList sIronBoulder3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_STONE_EDGE,
        MOVE_DOUBLE_KICK,
        MOVE_MIGHTY_CLEAVE,
        MOVE_PSYCHO_CUT
    },
};

const struct BossMoveList sIronCrown1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_TACHYON_CUTTER,
        MOVE_PSYSHOCK,
        MOVE_DISCHARGE,
        MOVE_TACHYON_CUTTER
    },
};

const struct BossMoveList sIronCrown2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_TACHYON_CUTTER,
        MOVE_FLASH_CANNON,
        MOVE_PSYCHIC_NOISE,
        MOVE_AIR_SLASH
    },
};

const struct BossMoveList sIronCrown3 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_TACHYON_CUTTER,
        MOVE_PSYCHIC,
        MOVE_FLASH_CANNON,
    },
};

const struct BossAi sIronLeavesAi =
{
    .phaseMoves =
    {
        &sIronLeaves1,
        &sIronLeaves2,
        &sIronLeaves3,
    },
};

const struct BossAi sIronBoulderAi =
{
    .phaseMoves =
    {
        &sIronBoulder1,
        &sIronBoulder2,
        &sIronBoulder3,
    },
};

const struct BossAi sIronCrownAi =
{
    .phaseMoves =
    {
        &sIronCrown1,
        &sIronCrown2,
        &sIronCrown3,
    },
};
