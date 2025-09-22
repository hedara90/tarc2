#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Cloudwalker makes the user ungrounded for a time after using a Wind move")
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
        ABILITY_POPUP(player, ABILITY_CLOUDWALKER);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
    }
}

SINGLE_BATTLE_TEST("Cloudwalker doesn't work if the user is prevented from moving")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CLOUDWALKER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPORE); MOVE(player, MOVE_GUST); }
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, player);
            ABILITY_POPUP(player, ABILITY_CLOUDWALKER);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
    }
}
