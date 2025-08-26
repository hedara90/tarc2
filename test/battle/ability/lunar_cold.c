#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Lunar Cold removes charge turns when no weather is up")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LUNAR_COLD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_METEOR_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METEOR_BEAM, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Lunar Cold doesn't remove charge turns when weather is up")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LUNAR_COLD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAIN_DANCE); MOVE(player, MOVE_METEOR_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METEOR_BEAM, player);
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Lunar Cold makes the user float")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LUNAR_COLD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Earthquake!");
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Lunar Cold sets Snow after using a two-turn move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LUNAR_COLD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_METEOR_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METEOR_BEAM, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, player);
    }
}
