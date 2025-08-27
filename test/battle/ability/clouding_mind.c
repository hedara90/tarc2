#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Clouding Mind inflicts Torment on hit")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CLOUDING_MIND); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SPLASH); }
        TURN { MOVE(opponent, MOVE_SPLASH, allowed: FALSE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("The opposing Wobbuffet was subjected to torment!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}
