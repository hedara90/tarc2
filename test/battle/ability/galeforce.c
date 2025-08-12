#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Galeforce powers up wind moves", s16 damage)
{
    u32 move;
    u16 ability;
    PARAMETRIZE { move = MOVE_HEAT_WAVE; ability = ABILITY_GALEFORCE; }
    PARAMETRIZE { move = MOVE_HEAT_WAVE; ability = ABILITY_REGENERATOR; }
    PARAMETRIZE { move = MOVE_U_TURN; ability = ABILITY_GALEFORCE; }
    PARAMETRIZE { move = MOVE_U_TURN; ability = ABILITY_REGENERATOR; }

    GIVEN {
        ASSUME(IsWindMove(MOVE_HEAT_WAVE));
        ASSUME(!IsWindMove(MOVE_U_TURN));
        PLAYER(SPECIES_TORNADUS_THERIAN) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage); // Sharpness affects Wind moves
        EXPECT_EQ(results[2].damage, results[3].damage); // Sharpness does not affect non-Wind moves
    }
}

SINGLE_BATTLE_TEST("INNATE: Sharpness increases the power of Wind moves", s16 damage)
{
    u32 move;
    u16 ability;
    PARAMETRIZE { move = MOVE_HEAT_WAVE; ability = ABILITY_GALEFORCE; }
    PARAMETRIZE { move = MOVE_HEAT_WAVE; ability = ABILITY_REGENERATOR; }
    PARAMETRIZE { move = MOVE_U_TURN; ability = ABILITY_GALEFORCE; }
    PARAMETRIZE { move = MOVE_U_TURN; ability = ABILITY_REGENERATOR; }

    GIVEN {
        ASSUME(IsWindMove(MOVE_HEAT_WAVE));
        ASSUME(!IsWindMove(MOVE_U_TURN));
        PLAYER(SPECIES_TORNADUS_THERIAN) { Ability(ABILITY_REGENERATOR); Innates(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage); // Sharpness affects Wind moves
        EXPECT_EQ(results[2].damage, results[3].damage); // Sharpness does not affect non-Wind moves
    }
}
