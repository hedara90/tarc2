#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Brute Force increases the power of Fighting moves", s16 damage)
{
    u32 move;
    u16 ability;
    PARAMETRIZE { move = MOVE_MACH_PUNCH; ability = ABILITY_BRUTE_FORCE; }
    PARAMETRIZE { move = MOVE_MACH_PUNCH; ability = ABILITY_STEADFAST; }
    PARAMETRIZE { move = MOVE_QUICK_ATTACK; ability = ABILITY_BRUTE_FORCE; }
    PARAMETRIZE { move = MOVE_QUICK_ATTACK; ability = ABILITY_STEADFAST; }

    GIVEN {
        PLAYER(SPECIES_HAXORUS) { Ability(ability); }
        OPPONENT(SPECIES_VAPOREON);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(TARC_BRUTE_FORCE_MODIFIER), results[0].damage); // Sharpness affects slicing moves
        EXPECT_EQ(results[2].damage, results[3].damage); // Sharpness does not affect non-slicing moves
    }
}
