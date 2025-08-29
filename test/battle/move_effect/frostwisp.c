#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Frostwisp test")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN  {
        TURN { MOVE(player, MOVE_FROSTWISP); }
    } SCENE {
        STATUS_ICON(opponent, frostbite: TRUE);
    }
}
