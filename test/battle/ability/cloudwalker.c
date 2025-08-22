#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Updraft makes the user ungrounded for a time after using a Wind move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CLOUDWALKER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GUST); }
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
    }
}
