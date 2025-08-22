#include "global.h"
#include "test/battle.h"

ASSUMPTIONS {
    ASSUME(GetMoveEffect(MOVE_SANDSTORM) == EFFECT_SANDSTORM);
}

SINGLE_BATTLE_TEST("Sand repair recovers 1/16th of Max HP in Sand")
{
    GIVEN {
        PLAYER(SPECIES_PALOSSAND) { Ability(ABILITY_SAND_REPAIR); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SANDSTORM); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SAND_REPAIR);
        MESSAGE("Palossand's Sand Repair restored its HP a little!");
        HP_BAR(player, damage:  -(100 / 16));
    }
}