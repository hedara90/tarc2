#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Herald of Currents increases damage for each stat below default stage that the target has", s16 damage)
{
    u32 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_GROWL; }
    PARAMETRIZE { move = MOVE_NOBLE_ROAR; }
    GIVEN {
        PLAYER(SPECIES_AUDINO) { Ability(ABILITY_HERALD_OF_CURRENTS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(player, MOVE_HYPER_BEAM); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        //  The multiplier is set manually here, it needs to be adjusted if TARC_HERALD_OF_CURRENTS_PERCENT_INCREASE
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.1), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.2), results[2].damage);
    }
}
