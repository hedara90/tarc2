#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("One with the Wind changes the users type to match wind moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ONE_WITH_THE_WIND); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GUST); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ONE_WITH_THE_WIND);
        MESSAGE("Wobbuffet transformed into the Flying type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, player);
    } THEN {
        EXPECT_EQ(player->types[0], TYPE_FLYING);
        EXPECT_EQ(player->types[1], TYPE_FLYING);
    }
}

SINGLE_BATTLE_TEST("One with the Wind changes the users type to match wind moves, multiple times")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ONE_WITH_THE_WIND); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GUST); }
        TURN { MOVE(player, MOVE_HEAT_WAVE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ONE_WITH_THE_WIND);
        MESSAGE("Wobbuffet transformed into the Flying type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, player);
        ABILITY_POPUP(player, ABILITY_ONE_WITH_THE_WIND);
        MESSAGE("Wobbuffet transformed into the Fire type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAT_WAVE, player);
    } THEN {
        EXPECT_EQ(player->types[0], TYPE_FIRE);
        EXPECT_EQ(player->types[1], TYPE_FIRE);
    }
}
