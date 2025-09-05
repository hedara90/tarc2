#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Circle of Life heals all battlers at end of turn (singles)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(120); MaxHP(240); Ability(ABILITY_CIRCLE_OF_LIFE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(120); MaxHP(240); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_CIRCLE_OF_LIFE);
        HP_BAR(player);
        HP_BAR(opponent);
    }
}
DOUBLE_BATTLE_TEST("Circle of Life heals all battlers at end of turn (doubles)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(120); MaxHP(240); Ability(ABILITY_CIRCLE_OF_LIFE); }
        PLAYER(SPECIES_WYNAUT) { HP(120); MaxHP(240); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(120); MaxHP(240); }
        OPPONENT(SPECIES_WYNAUT) { HP(120); MaxHP(240); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_CIRCLE_OF_LIFE);
        HP_BAR(playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(playerRight);
        HP_BAR(opponentRight);
    }
}
