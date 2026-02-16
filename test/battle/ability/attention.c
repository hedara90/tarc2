#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Attention traps after using a status move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_ATTENTION); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCREECH); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ATTENTION);
    } THEN {
        EXPECT(player->status2 & STATUS2_ESCAPE_PREVENTION);
    }
}
