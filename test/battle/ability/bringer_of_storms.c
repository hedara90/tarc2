#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Bringer of Storms sets rain after using a flying move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BRINGER_OF_STORMS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GUST); }
    } SCENE {
        MESSAGE("Rain started pouring down!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RAIN_CONTINUES);
    }
}

SINGLE_BATTLE_TEST("Bringer of Storms doesn't set rain after using a flying move if flinched")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BRINGER_OF_STORMS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FAKE_OUT); MOVE(player, MOVE_GUST); }
    } SCENE {
        NONE_OF {
            MESSAGE("Rain started pouring down!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RAIN_CONTINUES);
        }
    }
}

SINGLE_BATTLE_TEST("Bringer of Storms doesn't set rain after using a flying move if sleeping")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BRINGER_OF_STORMS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPORE); MOVE(player, MOVE_GUST); }
    } SCENE {
        NONE_OF {
            MESSAGE("Rain started pouring down!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RAIN_CONTINUES);
        }
    }
}
