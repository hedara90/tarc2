#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Flourish raises speed after using a slicing move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FLOURISH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AERIAL_ACE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}
