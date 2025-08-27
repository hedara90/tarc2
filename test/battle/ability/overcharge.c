#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Overcharge sets Electric Terrain after using an electric move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_OVERCHARGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        ABILITY_POPUP(player, ABILITY_OVERCHARGE);
        MESSAGE("An electric current ran across the battlefield!");
    }
}
