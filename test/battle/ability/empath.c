#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Empath heals", s16 damage)
{
    u32 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_AGILITY; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_EMPATH); HP(120); MaxHP(240); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AGILITY); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AGILITY, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        if (move == MOVE_AGILITY)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_AGILITY, opponent);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
        HP_BAR(player, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_LT(results[i].damage, 0);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}
