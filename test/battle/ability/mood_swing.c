#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mood Swing")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_MOOD_SWING); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MOOD_SWING);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        u32 statsUp = 0;
        u32 statsDown = 0;
        for (u32 j = 1; j < 6; j++)
        {
            if (player->statStages[j] > DEFAULT_STAT_STAGE)
                statsUp += player->statStages[j] - DEFAULT_STAT_STAGE;
            if (opponent->statStages[j] > DEFAULT_STAT_STAGE)
                statsUp += opponent->statStages[j] - DEFAULT_STAT_STAGE;
            if (player->statStages[j] < DEFAULT_STAT_STAGE)
                statsDown += DEFAULT_STAT_STAGE - player->statStages[j];
            if (opponent->statStages[j] < DEFAULT_STAT_STAGE)
                statsDown += DEFAULT_STAT_STAGE - opponent->statStages[j];
        }
        EXPECT_EQ(statsUp, 4);
        EXPECT_EQ(statsDown, 2);
    }
}
