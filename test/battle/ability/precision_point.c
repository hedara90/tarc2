#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Precision Point grants increased crit to slicing moves.")
{
    PASSES_RANDOMLY(1, 8, RNG_CRITICAL_HIT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PRECISION_POINT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AERIAL_ACE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, player);
        MESSAGE("A critical hit!");
    }
}
