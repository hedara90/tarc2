#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Hoarfrost triggers when Snow is set")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HOARFROST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SNOWSCAPE); }
    } WHEN {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, opponent);
        STATUS_ICON(opponent, frostbite: TRUE);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Hoarfrost doesn't trigger at end of turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HOARFROST); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SNOWSCAPE); }
        TURN { SWITCH(opponent, 1); }
    } WHEN {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, opponent);
        STATUS_ICON(opponent, frostbite: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        NONE_OF {
            STATUS_ICON(opponent, frostbite: TRUE);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Hoarfrost guarantees crits vs frostbitten targets", s16 damage)
{
    u32 status;
    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HOARFROST); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(status); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
        if (status == STATUS1_FROSTBITE)
            MESSAGE("A critical hit!");
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
