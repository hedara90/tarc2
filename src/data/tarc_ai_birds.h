const struct BossMoveList sArticuno1 =
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

const struct BossMoveList sZapdos1 =
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

const struct BossMoveList sMoltres1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_EMBER,
        MOVE_FIRE_SPIN,
        MOVE_FIRE_BLAST,
        MOVE_ROOST
    },
};

const struct BossAi sArticunoAi =
{
    .phaseMoves =
    {
        &sArticuno1,
        &sArticuno1,
        &sArticuno1,
        &sArticuno1,
    },
};

const struct BossAi sZapdosAi =
{
    .phaseMoves =
    {
        &sZapdos1,
        &sZapdos1,
        &sZapdos1,
        &sZapdos1,
    },
};

const struct BossAi sMoltresAi =
{
    .phaseMoves =
    {
        &sMoltres1,
        &sMoltres1,
        &sMoltres1,
        &sMoltres1,
    },
};
