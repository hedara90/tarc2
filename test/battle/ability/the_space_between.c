#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("The Space Between boosts 2 random stats at end of turn if semi-invulnerable")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_THE_SPACE_BETWEEN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLY); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_THE_SPACE_BETWEEN);
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
