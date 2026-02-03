#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Scorching Voltage has a 30% chance to paralyze when attacking with Electric moves")
{
    PASSES_RANDOMLY(3, 10, RNG_STATIC);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SCORCHING_VOLTAGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRO_BALL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_BALL, player);
        ABILITY_POPUP(player, ABILITY_SCORCHING_VOLTAGE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponent);
        MESSAGE("Wobbuffet's Scorching Voltage burned the opposing Wobbuffet!");
        STATUS_ICON(opponent, burn: TRUE);
    }
}

SINGLE_BATTLE_TEST("Scorching Voltage doesn't burn if the target is already statused")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SCORCHING_VOLTAGE); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_FROSTBITE); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRO_BALL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_BALL, player);
        NOT ABILITY_POPUP(player, ABILITY_SCORCHING_VOLTAGE);
    }
}
