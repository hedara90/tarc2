#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Essence of Rain changes the type of Weather Ball", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_TELEPATHY; }
    PARAMETRIZE { ability = ABILITY_ESSENCE_OF_RAIN; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Innates(ability); }
        OPPONENT(SPECIES_RAMPARDOS);
    } WHEN {
        TURN { MOVE(player, MOVE_WEATHER_BALL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WEATHER_BALL, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(4.0), results[1].damage);
    }
}
