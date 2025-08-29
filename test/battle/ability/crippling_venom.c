#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Crippling Venom lowers Atk and Sp.Atk when inflicting poison")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CRIPPLING_VENOM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POISON_POWDER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_POWDER, player);
        STATUS_ICON(opponent, poison: TRUE);
        ABILITY_POPUP(player, ABILITY_CRIPPLING_VENOM);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Attack harshly fell!");
        MESSAGE("The opposing Wobbuffet's Sp. Atk harshly fell!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 2);
    }
}

SINGLE_BATTLE_TEST("Crippling Venom works when Atk can't go lower")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CRIPPLING_VENOM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_POISON_POWDER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_POWDER, player);
        STATUS_ICON(opponent, poison: TRUE);
        ABILITY_POPUP(player, ABILITY_CRIPPLING_VENOM);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        NOT MESSAGE("The opposing Wobbuffet's Attack harshly fell!");
        MESSAGE("The opposing Wobbuffet's Sp. Atk harshly fell!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 6);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 2);
    }
}

SINGLE_BATTLE_TEST("Crippling Venom works when Sp.Atk can't go lower")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CRIPPLING_VENOM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EERIE_IMPULSE); }
        TURN { MOVE(player, MOVE_EERIE_IMPULSE); }
        TURN { MOVE(player, MOVE_EERIE_IMPULSE); }
        TURN { MOVE(player, MOVE_POISON_POWDER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_POWDER, player);
        STATUS_ICON(opponent, poison: TRUE);
        ABILITY_POPUP(player, ABILITY_CRIPPLING_VENOM);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Attack harshly fell!");
        NOT MESSAGE("The opposing Wobbuffet's Sp. Atk harshly fell!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 6);
    }
}

SINGLE_BATTLE_TEST("Crippling Venom doesn't trigger if both Attack and Sp.Atk are minimized")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CRIPPLING_VENOM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EERIE_IMPULSE); }
        TURN { MOVE(player, MOVE_EERIE_IMPULSE); }
        TURN { MOVE(player, MOVE_EERIE_IMPULSE); }
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_POISON_POWDER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_POWDER, player);
        STATUS_ICON(opponent, poison: TRUE);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_CRIPPLING_VENOM);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Wobbuffet's Attack harshly fell!");
            MESSAGE("The opposing Wobbuffet's Sp. Atk harshly fell!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 6);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 6);
    }
}
