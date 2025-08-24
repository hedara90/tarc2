#include "global.h"
#include "test/battle.h"

#define RESILIENCE_STAT_RAISE(target, msg)                         \
{                                                               \
    ABILITY_POPUP(target, ABILITY_RESILIENCE);                     \
    ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, target);  \
    MESSAGE(msg);                                               \
}

#define RESILIENCE_HIT(attacker, target, move, msg, dmgVar)        \
{                                                               \
    ANIMATION(ANIM_TYPE_MOVE, move, attacker);                  \
    HP_BAR(target, captureDamage: &dmgVar);                     \
    RESILIENCE_STAT_RAISE(target, msg);                            \
}

SINGLE_BATTLE_TEST("Resilience raises Sp. Def by 1 when hit by a move")
{
    s16 turnOneHit, turnTwoHit;
    u16 move;

    PARAMETRIZE {move = MOVE_GUST; }
    PARAMETRIZE {move = MOVE_SCRATCH; }

    GIVEN {
        ASSUME(!IsBattleMoveStatus(MOVE_SCRATCH));
        ASSUME(!IsBattleMoveStatus(MOVE_GUST));
        ASSUME(GetMoveCategory(MOVE_GUST) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_RESILIENCE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(opponent, move); }
    } SCENE {
        RESILIENCE_HIT(opponent, player, move, "Wobbuffet's Sp. Def rose!", turnOneHit);
        RESILIENCE_HIT(opponent, player, move, "Wobbuffet's Sp. Def rose!", turnTwoHit);
    }
    THEN {
        if (move == MOVE_GUST) {
            EXPECT_MUL_EQ(turnTwoHit, Q_4_12(1.5), turnOneHit);
        }
        else {
            EXPECT_EQ(turnTwoHit, turnOneHit);
        }
    }
}

DOUBLE_BATTLE_TEST("Resilience activates correctly for every battler with the ability when hit by a multi target move")
{
    u16 abilityLeft, abilityRight;

    PARAMETRIZE {abilityLeft = ABILITY_NONE, abilityRight = ABILITY_RESILIENCE; }
    PARAMETRIZE {abilityLeft = ABILITY_RESILIENCE, abilityRight = ABILITY_NONE; }
    PARAMETRIZE {abilityLeft = ABILITY_RESILIENCE, abilityRight = ABILITY_RESILIENCE; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == MOVE_TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET) { Ability(abilityLeft); Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(abilityRight); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) {Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) {Speed(15); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_EARTHQUAKE);}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentLeft);

        HP_BAR(playerLeft);
        HP_BAR(playerRight);
        NOT HP_BAR(opponentLeft); // We need to check the attacker itself does NOT get damaged. There was an issue when the targets would get overwritten by the Resilience's stat raise.
        HP_BAR(opponentRight);

        if (abilityLeft == ABILITY_RESILIENCE) {
            RESILIENCE_STAT_RAISE(playerLeft, "Wobbuffet's Sp. Def rose!");
        }

        if (abilityRight == ABILITY_RESILIENCE) {
            RESILIENCE_STAT_RAISE(playerRight, "Wobbuffet's Sp. Def rose!");
        }

        NOT HP_BAR(opponentLeft); // We need to check the attacker itself does NOT get damaged. There was an issue when the targets would get overwritten by the Resilience's stat raise.
    }
    THEN {
        EXPECT_NE(playerLeft->hp, playerLeft->maxHP);
        EXPECT_NE(playerRight->hp, playerRight->maxHP);
        EXPECT_NE(opponentRight->hp, opponentRight->maxHP);
        EXPECT_EQ(opponentLeft->hp, opponentLeft->maxHP);
    }
}

SINGLE_BATTLE_TEST("Resilience activates for every hit of a multi hit move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MUDBRAY) { Ability(ABILITY_RESILIENCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_KICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_KICK, player);
        HP_BAR(opponent);
        RESILIENCE_STAT_RAISE(opponent, "The opposing Mudbray's Sp. Def rose!");
        RESILIENCE_STAT_RAISE(opponent, "The opposing Mudbray's Sp. Def rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Resilience is not activated by users own Substitute")
{
    GIVEN {
        PLAYER(SPECIES_MUDBRAY) { Ability(ABILITY_RESILIENCE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        MESSAGE("Mudbray put in a substitute!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_RESILIENCE);
            MESSAGE("Mudbray's Sp. Def rose!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("INNATE: Resilience raises Sp. Def by 1 when hit by a move")
{
    s16 turnOneHit, turnTwoHit;
    u16 move;

    PARAMETRIZE {move = MOVE_GUST; }
    PARAMETRIZE {move = MOVE_TACKLE; }

    GIVEN {
        ASSUME(!IsBattleMoveStatus(MOVE_TACKLE));
        ASSUME(!IsBattleMoveStatus(MOVE_GUST));
        ASSUME(GetMoveCategory(MOVE_GUST) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_TACKLE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_RESILIENCE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(opponent, move); }
    } SCENE {
        RESILIENCE_HIT(opponent, player, move, "Wobbuffet's Sp. Def rose!", turnOneHit);
        RESILIENCE_HIT(opponent, player, move, "Wobbuffet's Sp. Def rose!", turnTwoHit);
    }
    THEN {
        if (move == MOVE_GUST) {
            EXPECT_MUL_EQ(turnTwoHit, Q_4_12(1.5), turnOneHit);
        }
        else {
            EXPECT_EQ(turnTwoHit, turnOneHit);
        }
    }
}

DOUBLE_BATTLE_TEST("INNATE: Resilience activates correctly for every battler with the ability when hit by a multi target move")
{
    u16 abilityLeft, abilityRight;

    PARAMETRIZE {abilityLeft = ABILITY_NONE, abilityRight = ABILITY_RESILIENCE; }
    PARAMETRIZE {abilityLeft = ABILITY_RESILIENCE, abilityRight = ABILITY_NONE; }
    PARAMETRIZE {abilityLeft = ABILITY_RESILIENCE, abilityRight = ABILITY_RESILIENCE; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == MOVE_TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(abilityLeft); Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(abilityRight); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) {Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) {Speed(15); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_EARTHQUAKE);}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentLeft);

        HP_BAR(playerLeft);
        HP_BAR(playerRight);
        NOT HP_BAR(opponentLeft); // We need to check the attacker itself does NOT get damaged. There was an issue when the targets would get overwritten by the Resilience's stat raise.
        HP_BAR(opponentRight);

        if (abilityLeft == ABILITY_RESILIENCE) {
            RESILIENCE_STAT_RAISE(playerLeft, "Wobbuffet's Sp. Def rose!");
        }

        if (abilityRight == ABILITY_RESILIENCE) {
            RESILIENCE_STAT_RAISE(playerRight, "Wobbuffet's Sp. Def rose!");
        }

        NOT HP_BAR(opponentLeft); // We need to check the attacker itself does NOT get damaged. There was an issue when the targets would get overwritten by the Resilience's stat raise.
    }
    THEN {
        EXPECT_NE(playerLeft->hp, playerLeft->maxHP);
        EXPECT_NE(playerRight->hp, playerRight->maxHP);
        EXPECT_NE(opponentRight->hp, opponentRight->maxHP);
        EXPECT_EQ(opponentLeft->hp, opponentLeft->maxHP);
    }
}

SINGLE_BATTLE_TEST("INNATE: Resilience activates for every hit of a multi hit move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MUDBRAY) { Ability(ABILITY_OWN_TEMPO); Innates(ABILITY_RESILIENCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_KICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_KICK, player);
        HP_BAR(opponent);
        RESILIENCE_STAT_RAISE(opponent, "The opposing Mudbray's Sp. Def rose!");
        RESILIENCE_STAT_RAISE(opponent, "The opposing Mudbray's Sp. Def rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("INNATE: Resilience is not activated by users own Substitute")
{
    GIVEN {
        PLAYER(SPECIES_MUDBRAY) { Ability(ABILITY_OWN_TEMPO); Innates(ABILITY_RESILIENCE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        MESSAGE("Mudbray put in a substitute!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_RESILIENCE);
            MESSAGE("Mudbray's Sp. Def rose!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}
