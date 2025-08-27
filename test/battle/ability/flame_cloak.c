#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Flame Cloak raises Def after using a fire move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FLAME_CLOAK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_INCINERATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INCINERATE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}
