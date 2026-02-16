#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Essence of Snow doesn't boost defense of Ice types", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_ESSENCE_OF_SNOW; }
    PARAMETRIZE { ability = ABILITY_TELEPATHY; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
