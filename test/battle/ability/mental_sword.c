#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mental Sword turn slicing moves into special moves")
{
    s16 damage1, damage2;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MENTAL_SWORD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AERIAL_ACE); MOVE(opponent, MOVE_MIRROR_COAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, player);
        HP_BAR(opponent, captureDamage: &damage1);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, opponent);
        HP_BAR(player, captureDamage: &damage2);
    } THEN {
        EXPECT_MUL_EQ(damage1, UQ_4_12(2.0), damage2);
    }
}

SINGLE_BATTLE_TEST("Mental Sword doesn't turn non-slicing moves into special moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MENTAL_SWORD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_MIRROR_COAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, opponent);
    }
}
