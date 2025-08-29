#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Pyroclasm test")
{
    GIVEN {
        PLAYER(SPECIES_RAPIDASH);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PYROCLASM); }
    }
}
