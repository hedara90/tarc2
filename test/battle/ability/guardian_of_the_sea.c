#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Guardian of the Sea increases damage done by water moves by 50%", s16 damage)
{
    u32 move;
    u16 ability;

    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { move = MOVE_SCRATCH; ability = ABILITY_GUARDIAN_OF_THE_SEA; }
    PARAMETRIZE { move = MOVE_WATERFALL; ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { move = MOVE_WATERFALL; ability = ABILITY_GUARDIAN_OF_THE_SEA; }
    PARAMETRIZE { move = MOVE_SURF; ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { move = MOVE_SURF; ability = ABILITY_GUARDIAN_OF_THE_SEA; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) != TYPE_WATER);
        ASSUME(GetMoveType(MOVE_WATERFALL) == TYPE_WATER);
        ASSUME(GetMoveType(MOVE_SURF) == TYPE_WATER);
        ASSUME(GetMoveCategory(MOVE_WATERFALL) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SURF) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_BOMBIRDIER) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage); // Scratch should be unaffected
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage); // Waterfall should be affected
        EXPECT_MUL_EQ(results[4].damage, Q_4_12(1.5), results[5].damage); // Surf should be affected
    }
}

SINGLE_BATTLE_TEST("Guardian of the Sea applies submerged which deals damage to the mon at end of turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GUARDIAN_OF_THE_SEA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Guardian of the Sea, submerged lasts only 1 turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GUARDIAN_OF_THE_SEA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
        TURN { }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        NOT HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}
