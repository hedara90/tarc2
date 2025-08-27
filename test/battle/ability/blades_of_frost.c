#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Blades of Frost turns ice moves into slicing moves", s16 damage)
{
    u32 innate;
    PARAMETRIZE { innate = ABILITY_BLADES_OF_FROST; }
    PARAMETRIZE { innate = ABILITY_TELEPATHY; }
    GIVEN {
        PLAYER(SPECIES_GALLADE) { Ability(ABILITY_SHARPNESS); Innates(innate); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ICE_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICE_BEAM, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage);
    }
}
