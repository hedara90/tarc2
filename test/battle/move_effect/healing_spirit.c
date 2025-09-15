#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Healing Spirit heals all battlers for 50%")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(120); MaxHP(240); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(120); MaxHP(240); }
    } WHEN {
        TURN { MOVE(player, MOVE_HEALING_SPIRIT); }
    } SCENE {
        HP_BAR(player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(opponent->hp, opponent->maxHP);
    }
}
