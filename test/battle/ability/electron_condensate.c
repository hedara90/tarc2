#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Electron Condensate sets up Electric Terrain when hit by an attack")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ELECTRON_RELESE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Scratch!");
        HP_BAR(player);
        ABILITY_POPUP(player);
        MESSAGE("An electric current ran across the battlefield!");
    }
}
