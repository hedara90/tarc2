#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sunrise makes the user float")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SUNRISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Earthquake!");
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Sunrise sets sun after using a fire move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SUNRISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLAMETHROWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLAMETHROWER, player);
        ABILITY_POPUP(player, ABILITY_SUNRISE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
    }
}

SINGLE_BATTLE_TEST("Sunrise + Cloudburst doesn't cause an infinite loop")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SUNRISE); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_CLOUDBURST); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_CLOUDBURST);
        ABILITY_POPUP(player, ABILITY_SUNRISE);
    }
}
