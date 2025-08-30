#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mind Palace sets Psychic Terrain after using a status move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MIND_PALACE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ABILITY_POPUP(player, ABILITY_MIND_PALACE);
        MESSAGE("The battlefield got weird!");
    }
}
