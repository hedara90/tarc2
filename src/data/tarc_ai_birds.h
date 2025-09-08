const struct BossMoveList sArticuno1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SNOWSCAPE,
        MOVE_BLIZZARD,
        MOVE_AIR_CUTTER,
        MOVE_DUAL_WINGBEAT,
        MOVE_FREEZE_DRY,
    },
};

const struct BossMoveList sArticuno2 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_ICE_BEAM,
        MOVE_ANCIENT_POWER,
        MOVE_AIR_CUTTER,
        MOVE_DUAL_WINGBEAT,
        MOVE_FREEZE_DRY,
    },
};
const struct BossMoveList sArticuno3 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SNOWSCAPE,
        MOVE_BLIZZARD,
        MOVE_AIR_CUTTER,
        MOVE_DUAL_WINGBEAT,
        MOVE_FREEZE_DRY,
    },
};

const struct BossMoveList sZapdos1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_THUNDERBOLT,
        MOVE_ACROBATICS,
        MOVE_ROOST,
        MOVE_DISCHARGE
    },
};
const struct BossMoveList sZapdos2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_THUNDER,
        MOVE_ANCIENT_POWER,
        MOVE_DUAL_WINGBEAT,
        MOVE_ELECTRO_BALL,
    },
};
const struct BossMoveList sZapdos3 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_ELECTRIC_TERRAIN,
        MOVE_THUNDERBOLT,
        MOVE_THUNDERBOLT,
        MOVE_ROOST,
        MOVE_THUNDERBOLT
    },
};

const struct BossMoveList sMoltres1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SUNNY_DAY,
        MOVE_FLAMETHROWER,
        MOVE_FIRE_SPIN,
        MOVE_ROOST,
        MOVE_BRAVE_BIRD,
    },
};

const struct BossMoveList sMoltres2 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_BRAVE_BIRD,
        MOVE_FLARE_BLITZ,
        MOVE_ROOST,
    },
};

const struct BossMoveList sMoltres3 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_FIRE_SPIN,
        MOVE_SUNNY_DAY,
        MOVE_OVERHEAT,
        MOVE_FIRE_BLAST,
        MOVE_ROOST
    },
};

const struct BossAi sArticunoAi =
{
    .phaseMoves =
    {
        &sArticuno1,
        &sArticuno2,
        &sArticuno3,
    },
};

const struct BossAi sZapdosAi =
{
    .phaseMoves =
    {
        &sZapdos1,
        &sZapdos2,
        &sZapdos3,
    },
};

const struct BossAi sMoltresAi =
{
    .phaseMoves =
    {
        &sMoltres1,
        &sMoltres2,
        &sMoltres3,
    },
};
