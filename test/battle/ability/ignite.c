#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Ignite turn a Normal-type move into Fire-type move")
{
    GIVEN {
        PLAYER(SPECIES_MEGANIUM);
        OPPONENT(SPECIES_FLAREON) { Ability(ABILITY_IGNITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("It's super effective!");
    }
}
