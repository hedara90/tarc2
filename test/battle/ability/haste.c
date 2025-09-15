#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Haste increases damage done by moves with increased priority", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_TELEPATHY; }
    PARAMETRIZE { ability = ABILITY_HASTE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Innates(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EXTREME_SPEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXTREME_SPEED, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(TARC_HASTE_MULTIPLIER), results[1].damage);
    }
}
