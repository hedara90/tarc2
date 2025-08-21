#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Blizzard bypasses accuracy checks in Hail and Snow")
{
    u32 move;
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_BLIZZARD) == 70);
        ASSUME(MoveAlwaysHitsInHailSnow(MOVE_BLIZZARD));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_BLIZZARD); }
    } SCENE {
        NOT MESSAGE("Wobbuffet's attack missed!");
    }
}

SINGLE_BATTLE_TEST("Blizzard bypasses accuracy with Essence of Snow")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LIGHT_METAL); Innates(ABILITY_ESSENCE_OF_SNOW); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BLIZZARD); }
    } SCENE {
        NOT MESSAGE("Wobbuffet's attack missed!");
    }
}
