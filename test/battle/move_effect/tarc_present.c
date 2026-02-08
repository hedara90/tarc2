#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Red Present inclicts burn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RED_PRESENT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RED_PRESENT, player);
        HP_BAR(opponent);
        STATUS_ICON(opponent, STATUS1_BURN);
    }
}

SINGLE_BATTLE_TEST("Blue Present inclicts frostbite")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BLUE_PRESENT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BLUE_PRESENT, player);
        HP_BAR(opponent);
        STATUS_ICON(opponent, STATUS1_FROSTBITE);
    }
}

SINGLE_BATTLE_TEST("Yellow Present inclicts paralysis")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_YELLOW_PRESENT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_YELLOW_PRESENT, player);
        HP_BAR(opponent);
        STATUS_ICON(opponent, STATUS1_PARALYSIS);
    }
}

SINGLE_BATTLE_TEST("Red Present deal more damage to statused opponents", s16 damage)
{
    u32 status;
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = 0; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(status); }
    } WHEN {
        TURN { MOVE(player, MOVE_RED_PRESENT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RED_PRESENT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Blue Present deal more damage to statused opponents", s16 damage)
{
    u32 status;
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    PARAMETRIZE { status = 0; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(status); }
    } WHEN {
        TURN { MOVE(player, MOVE_BLUE_PRESENT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BLUE_PRESENT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Yellow Present deal more damage to statused opponents", s16 damage)
{
    u32 status;
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = 0; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(status); }
    } WHEN {
        TURN { MOVE(player, MOVE_YELLOW_PRESENT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_YELLOW_PRESENT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.5), results[0].damage);
    }
}
