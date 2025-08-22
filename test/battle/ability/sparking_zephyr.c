#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sparking Zephyr triggers on electric moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SPARKING_ZEPHYR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRO_BALL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_BALL, player);
        ABILITY_POPUP(player, ABILITY_SPARKING_ZEPHYR);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, player);
    }
}

SINGLE_BATTLE_TEST("Sparking Zephyr triggers Wind Rider")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SPARKING_ZEPHYR); Innates(ABILITY_WIND_RIDER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRO_BALL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_BALL, player);
        ABILITY_POPUP(player, ABILITY_SPARKING_ZEPHYR);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, player);
        ABILITY_POPUP(player, ABILITY_WIND_RIDER);
    }
}

DOUBLE_BATTLE_TEST("Sparking Zephyr doesn't trigger if Tailwind is already up")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SPARKING_ZEPHYR); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_TAILWIND); MOVE(playerLeft, MOVE_ELECTRO_BALL, target: opponentLeft); MOVE(opponentLeft, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_BALL, playerLeft);
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_SPARKING_ZEPHYR);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, playerLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
    }
}
