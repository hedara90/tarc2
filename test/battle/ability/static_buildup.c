#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Static Buildup", s16 damage)
{
    u32 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SANDSTORM; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_STATIC_BUILDUP); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SAFETY_GOGGLES); }
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}
