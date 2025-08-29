#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Giant Slayer grants increased crit vs targets with 2+ stat boosts")
{
    PASSES_RANDOMLY(1, 8, RNG_CRITICAL_HIT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GIANT_SLAYER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("A critical hit!");
    }
}
