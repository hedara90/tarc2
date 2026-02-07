#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Generosity triggers at end of turn if target is burned")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_DELIBIRD) { Ability(ABILITY_GENEROSITY); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_GENEROSITY);
    }
}

SINGLE_BATTLE_TEST("Generosity triggers at end of turn if target is frostbitten")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_DELIBIRD) { Ability(ABILITY_GENEROSITY); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_GENEROSITY);
    }
}

SINGLE_BATTLE_TEST("Generosity triggers at end of turn if target is paralyzed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_DELIBIRD) { Ability(ABILITY_GENEROSITY); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_GENEROSITY);
    }
}

SINGLE_BATTLE_TEST("Generosity triggers at end of turn if target doesn't have a status")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DELIBIRD) { Ability(ABILITY_GENEROSITY); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_GENEROSITY);
    }
}
