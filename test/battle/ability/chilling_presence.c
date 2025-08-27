#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Chilling Presence increases damage of Ice moves by 50\% in snow", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_TELEPATHY; }
    PARAMETRIZE { ability = ABILITY_CHILLING_PRESENCE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SNOWSCAPE); MOVE(player, MOVE_PSYCHIC); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
