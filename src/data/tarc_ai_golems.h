const struct BossMoveList sRegirock1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_CURSE,
        MOVE_ANCIENT_POWER,
        MOVE_ROCK_SLIDE,
        MOVE_STONE_EDGE,
        MOVE_HEAD_SMASH
    },
};

const struct BossMoveList sRegirock2 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_CURSE,
        MOVE_HAMMER_ARM,
        MOVE_DRAIN_PUNCH,
        MOVE_BULLDOZE,
        MOVE_HEAD_SMASH
    },
};

const struct BossMoveList sRegirock3 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_ROCK_SLIDE,
        MOVE_DOUBLE_EDGE,
        MOVE_ACCELEROCK,
        MOVE_BODY_PRESS,
        MOVE_HEAD_SMASH
    },
};

const struct BossMoveList sRegice1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_FROSTWISP,
        MOVE_ICE_BEAM,
        MOVE_FLASH_CANNON,
        MOVE_SNOWSCAPE,
        MOVE_BLIZZARD,
    },
};

const struct BossMoveList sRegice2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_FREEZE_DRY,
        MOVE_ANCIENT_POWER,
        MOVE_CHARGE_BEAM,
        MOVE_CHILLING_WATER,
    },
};

const struct BossMoveList sRegice3 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SNOWSCAPE,
        MOVE_BLIZZARD,
        MOVE_ICE_BEAM,
        MOVE_FREEZE_DRY,
        MOVE_CHILLING_WATER,
    },
};

const struct BossMoveList sRegisteel1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_IRON_DEFENSE,
        MOVE_AMNESIA,
        MOVE_HARD_PRESS,
        MOVE_HEAVY_SLAM,
        MOVE_FLASH_CANNON,
    },
};

const struct BossMoveList sRegisteel2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_IRON_HEAD,
        MOVE_EARTHQUAKE,
        MOVE_FLASH_CANNON,
        MOVE_BODY_PRESS,
    },
};

const struct BossMoveList sRegisteel3 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_IRON_HEAD,
        MOVE_FLASH_CANNON,
        MOVE_BODY_PRESS,
    },
};

const struct BossMoveList sRegieleki1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_THUNDER_CAGE,
        MOVE_ELECTRIFY,
        MOVE_ELECTROWEB,
        MOVE_CHARGE_BEAM,
        MOVE_ELECTROWEB
    },
};

const struct BossMoveList sRegieleki2 =
{
    .numMoves = 2,
    .moves =
    {
        MOVE_ELECTROWEB,
        MOVE_ELECTRO_BALL,
    },
};

const struct BossMoveList sRegieleki3 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_THUNDER_CAGE,
        MOVE_ELECTRIFY,
        MOVE_ELECTROWEB,
        MOVE_THUNDERBOLT,
        MOVE_ZAP_CANNON
    },
};

const struct BossMoveList sRegidrago1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SUBSTITUTE,
        MOVE_DRAGON_ENERGY,
        MOVE_DRAGON_CLAW,
        MOVE_SCALE_SHOT,
    },
};

const struct BossMoveList sRegidrago2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_FIRE_FANG,
        MOVE_THUNDER_FANG,
        MOVE_ICE_FANG,
        MOVE_CRUNCH,
    },
};

const struct BossMoveList sRegidrago3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SUBSTITUTE,
        MOVE_DRAGON_ENERGY,
        MOVE_EARTH_POWER,
        MOVE_DRACO_METEOR
    },
};

const struct BossAi sRegirockAi =
{
    .phaseMoves =
    {
        &sRegirock1,
        &sRegirock2,
        &sRegirock3,
    },
};

const struct BossAi sRegiceAi =
{
    .phaseMoves =
    {
        &sRegice1,
        &sRegice2,
        &sRegice3,
    },
};

const struct BossAi sRegisteelAi =
{
    .phaseMoves =
    {
        &sRegisteel1,
        &sRegisteel2,
        &sRegisteel3,
    },
};

const struct BossAi sRegielekiAi =
{
    .phaseMoves =
    {
        &sRegieleki1,
        &sRegieleki2,
        &sRegieleki3,
    },
};

const struct BossAi sRegidragoAi =
{
    .phaseMoves =
    {
        &sRegidrago1,
        &sRegidrago2,
        &sRegidrago3,
    },
};
