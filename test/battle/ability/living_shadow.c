#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Living Shadow makes the user immune to Ghost type moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LIVING_SHADOW); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SHADOW_BALL); }
    } SCENE {
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Living Shadow makes the user immune to EoT effects when using Phantom Force and similar moves")
{
    u32 move;
    PARAMETRIZE { move = MOVE_LEECH_SEED; }
    PARAMETRIZE { move = MOVE_WILL_O_WISP; }
    PARAMETRIZE { move = MOVE_FROSTWISP; }
    PARAMETRIZE { move = MOVE_SANDSTORM; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LIVING_SHADOW); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_DIMENSION_BREAK); }
    } SCENE {
        NOT HP_BAR(player);
    }
}
