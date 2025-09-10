const struct BossMoveList sWalkingWake1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_HYDRO_STEAM,
        MOVE_DRAGON_PULSE,
        MOVE_SCALD,
        MOVE_FLAMETHROWER,
    },
};

const struct BossMoveList sWalkingWake2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_CHILLING_WATER,
        MOVE_HYDRO_STEAM,
        MOVE_BRINE,
        MOVE_DRACO_METEOR
    },
};

const struct BossMoveList sWalkingWake3 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_HYDRO_PUMP,
        MOVE_DRAGON_PULSE,
        MOVE_FLAMETHROWER,
        MOVE_HYDRO_STEAM
    },
};

const struct BossMoveList sGougingFire1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_NOBLE_ROAR,
        MOVE_FLAME_CHARGE,
        MOVE_HONE_CLAWS,
        MOVE_FLAME_CHARGE,
    },
};

const struct BossMoveList sGougingFire2 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_STONE_EDGE,
        MOVE_FLARE_BLITZ,
        MOVE_DRAGON_CLAW,
    },
};

const struct BossMoveList sGougingFire3 =
{
    .numMoves = 2,
    .moves =
    {
        MOVE_FLARE_BLITZ,
        MOVE_DUAL_CHOP,
    },
};

const struct BossMoveList sRagingBolt1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_CHARGE_BEAM,
        MOVE_CHARGE_BEAM,
        MOVE_THUNDERBOLT,
        MOVE_DRAGON_PULSE,
    },
};

const struct BossMoveList sRagingBolt2 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_THUNDER,
        MOVE_HURRICANE,
        MOVE_THUNDERCLAP,
    },
};

const struct BossMoveList sRagingBolt3 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_DISCHARGE,
        MOVE_ZAP_CANNON,
        MOVE_DRACO_METEOR,
        MOVE_HYPER_VOICE,
        MOVE_THUNDER,
        MOVE_HURRICANE,
    },
};

const struct BossAi sWalkingWakeAi =
{
    .phaseMoves =
    {
        &sWalkingWake1,
        &sWalkingWake2,
        &sWalkingWake3,
    },
};

const struct BossAi sGougingFireAi =
{
    .phaseMoves =
    {
        &sGougingFire1,
        &sGougingFire2,
        &sGougingFire3,
    },
};

const struct BossAi sRagingBoltAi =
{
    .phaseMoves =
    {
        &sRagingBolt1,
        &sRagingBolt2,
        &sRagingBolt3,
    },
};
