#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Plus (Ability) test titles")
SINGLE_BATTLE_TEST("Plus-Minus on one mon", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_LEVITATE; }
    PARAMETRIZE { ability = ABILITY_MINUS; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PLUS); Innates(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
