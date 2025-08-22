#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TAILWIND) == EFFECT_TAILWIND);
    ASSUME(IsWindMove(MOVE_TAILWIND));
}

SINGLE_BATTLE_TEST("Maelstrom raises Special Attack by one stage if it sets up Tailwind")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_THUNDURUS) { Ability(ABILITY_MAELSTROM); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponent);
        ABILITY_POPUP(opponent, ABILITY_MAELSTROM);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Thundurus's Special Attack rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

DOUBLE_BATTLE_TEST("Maelstrom raises Special Attack by one stage if Tailwind is setup by its partner")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_THUNDURUS) { Ability(ABILITY_MAELSTROM); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponentLeft);
        ABILITY_POPUP(opponentRight, ABILITY_MAELSTROM);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Thundurus's Special Attack rose!");
    } THEN {
        EXPECT_EQ(opponentRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Maelstrom doesn't raise Special Attack if opponent sets up Tailwind")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_THUNDURUS) { Ability(ABILITY_MAELSTROM); }
    } WHEN {
        TURN { MOVE(player, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_MAELSTROM);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Thundurus's Special Attack rose!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Maelstrom raises Special Attack by one stage if switched into Tailwind on its side of the field")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_THUNDURUS) { Ability(ABILITY_MAELSTROM); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAILWIND); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponent);
        ABILITY_POPUP(opponent, ABILITY_MAELSTROM);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Thundurus's Maelstrom raised its Special Attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Maelstrom activates when it's no longer effected by Neutralizing Gas")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_THUNDURUS) { Ability(ABILITY_MAELSTROM); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAILWIND); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponent);
        SWITCH_OUT_MESSAGE("Weezing");
        MESSAGE("The effects of the neutralizing gas wore off!");
        ABILITY_POPUP(opponent, ABILITY_MAELSTROM);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Thundurus's Maelstrom raised its Special Attack!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Maelstrom absorbs Wind moves and raises Special Attack by one stage")
{
    GIVEN {
        ASSUME(IsWindMove(MOVE_GUST));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_THUNDURUS) { Ability(ABILITY_MAELSTROM); }
    } WHEN {
        TURN { MOVE(player, MOVE_GUST); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, player);
            HP_BAR(opponent);
        }
        ABILITY_POPUP(opponent, ABILITY_MAELSTROM);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Thundurus's Special Attack rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("INNATE: Maelstrom raises Special Attack by one stage if it sets up Tailwind")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_THUNDURUS) { Ability(ABILITY_INFILTRATOR); Innates(ABILITY_MAELSTROM); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponent);
        ABILITY_POPUP(opponent, ABILITY_MAELSTROM);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Thundurus's Special Attack rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

DOUBLE_BATTLE_TEST("INNATE: Maelstrom raises Special Attack by one stage if Tailwind is setup by its partner")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_THUNDURUS) { Ability(ABILITY_INFILTRATOR); Innates(ABILITY_MAELSTROM); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponentLeft);
        ABILITY_POPUP(opponentRight, ABILITY_MAELSTROM);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Thundurus's Special Attack rose!");
    } THEN {
        EXPECT_EQ(opponentRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("INNATE: Maelstrom doesn't raise Special Attack if opponent sets up Tailwind")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_THUNDURUS) { Ability(ABILITY_INFILTRATOR); Innates(ABILITY_MAELSTROM); }
    } WHEN {
        TURN { MOVE(player, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_MAELSTROM);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Thundurus's Special Attack rose!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("INNATE: Maelstrom raises Special Attack by one stage if switched into Tailwind on its side of the field")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_THUNDURUS) { Ability(ABILITY_INFILTRATOR); Innates(ABILITY_MAELSTROM); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAILWIND); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponent);
        ABILITY_POPUP(opponent, ABILITY_MAELSTROM);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Thundurus's Maelstrom raised its Special Attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("INNATE: Maelstrom activates when it's no longer effected by Neutralizing Gas")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_LEVITATE); Innates(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_THUNDURUS) { Ability(ABILITY_MAELSTROM); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAILWIND); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, opponent);
        SWITCH_OUT_MESSAGE("Weezing");
        MESSAGE("The effects of the neutralizing gas wore off!");
        ABILITY_POPUP(opponent, ABILITY_MAELSTROM);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Thundurus's Maelstrom raised its Special Attack!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Maelstrom absorbs Wind moves and raises Special Attack by one stage")
{
    GIVEN {
        ASSUME(IsWindMove(MOVE_GUST));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_THUNDURUS) { Ability(ABILITY_INFILTRATOR); Innates(ABILITY_MAELSTROM); }
    } WHEN {
        TURN { MOVE(player, MOVE_GUST); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, player);
            HP_BAR(opponent);
        }
        ABILITY_POPUP(opponent, ABILITY_MAELSTROM);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Thundurus's Special Attack rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}
