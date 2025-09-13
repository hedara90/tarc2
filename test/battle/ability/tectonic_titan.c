#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Tectonic Titan increases Rock-type move damage", s16 damage)
{
    u32 move;
    u16 ability;

    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_TECTONIC_TITAN; }
    PARAMETRIZE { move = MOVE_EARTHQUAKE; ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { move = MOVE_EARTHQUAKE; ability = ABILITY_TECTONIC_TITAN; }
    PARAMETRIZE { move = MOVE_EARTH_POWER; ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { move = MOVE_EARTH_POWER; ability = ABILITY_TECTONIC_TITAN; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) != TYPE_GROUND);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        ASSUME(GetMoveType(MOVE_EARTH_POWER) == TYPE_GROUND);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_EARTH_POWER) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_BOMBIRDIER) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage); // Scratch should be unaffected
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage); // Rock Throw should be affected
        EXPECT_MUL_EQ(results[4].damage, Q_4_12(1.5), results[5].damage); // Power Gem should be affected
    }
}

SINGLE_BATTLE_TEST("Tectonic Titan increases Rock-type move damage (Trait)", s16 damage)
{
    u32 move;
    u16 ability;

    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_TECTONIC_TITAN; }
    PARAMETRIZE { move = MOVE_EARTHQUAKE; ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { move = MOVE_EARTHQUAKE; ability = ABILITY_TECTONIC_TITAN; }
    PARAMETRIZE { move = MOVE_EARTH_POWER; ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { move = MOVE_EARTH_POWER; ability = ABILITY_TECTONIC_TITAN; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) != TYPE_GROUND);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        ASSUME(GetMoveType(MOVE_EARTH_POWER) == TYPE_GROUND);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_EARTH_POWER) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_BOMBIRDIER) { Ability(ABILITY_KEEN_EYE); Innates(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage); // Scratch should be unaffected
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage); // Rock Throw should be affected
        EXPECT_MUL_EQ(results[4].damage, Q_4_12(1.5), results[5].damage); // Power Gem should be affected
    }
}
