#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Yggdrasil's Gift boosts stats at end of turn")
{
    GIVEN {
        PLAYER(SPECIES_XERNEAS) { Ability(ABILITY_YGGDRASILS_GIFT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_YGGDRASILS_GIFT);
    } THEN {
        u32 numBoosts = 0;
        for (u32 i = 1; i < 6; i++)
        {
            if (player->statStages[i] == DEFAULT_STAT_STAGE + 1)
                numBoosts++;
        }
        EXPECT_EQ(numBoosts, 2);
    }
}

SINGLE_BATTLE_TEST("Yggdrasil's Gift only boosts for ech battler at max HP")
{
    GIVEN {
        PLAYER(SPECIES_XERNEAS) { Ability(ABILITY_YGGDRASILS_GIFT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_YGGDRASILS_GIFT);
    } THEN {
        u32 numBoosts = 0;
        for (u32 i = 1; i < 6; i++)
        {
            if (player->statStages[i] == DEFAULT_STAT_STAGE + 1)
                numBoosts++;
        }
        EXPECT_EQ(numBoosts, 1);
    }
}

SINGLE_BATTLE_TEST("Yggdrasil's Gift doesn't trigger if no battler is at full HP")
{
    GIVEN {
        PLAYER(SPECIES_XERNEAS) { Ability(ABILITY_YGGDRASILS_GIFT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        NOT ABILITY_POPUP(player, ABILITY_YGGDRASILS_GIFT);
    } THEN {
        u32 numBoosts = 0;
        for (u32 i = 1; i < 6; i++)
        {
            if (player->statStages[i] == DEFAULT_STAT_STAGE + 1)
                numBoosts++;
        }
        EXPECT_EQ(numBoosts, 0);
    }
}
