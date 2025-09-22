#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Living Shadow makes the user immune to Ghost type moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LIVING_SHADOW); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SHADOW_BALL); }
    } SCENE {
        NOT HP_BAR(player);
    }
}
