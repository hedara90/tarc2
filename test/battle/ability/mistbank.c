#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mistbank sets Misty Terrain after using a water move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MISTBANK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        ABILITY_POPUP(player, ABILITY_MISTBANK);
        MESSAGE("Mist swirled around the battlefield!");
    }
}
