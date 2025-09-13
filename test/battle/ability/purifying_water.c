#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Purifying Water makes poison attacks into water")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_ABSORB_BULB); Innates(ABILITY_PURIFYING_WATER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_VENOSHOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    }
}

SINGLE_BATTLE_TEST("Purifying Water prevents status")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Innates(ABILITY_PURIFYING_WATER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POISON_STING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_STING, opponent);
        NOT STATUS_ICON(player, poison: TRUE);
    }
}
