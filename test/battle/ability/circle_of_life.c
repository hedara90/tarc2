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

SINGLE_BATTLE_TEST("Circle of Life 2 ignores resistances and immunities when target is above 50%, resistance", s16 damage)
{
    u32 hp;
    PARAMETRIZE { hp = 200; }
    PARAMETRIZE { hp = 100; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CIRCLE_OF_LIFE2); }
        OPPONENT(SPECIES_REGISTEEL) { HP(hp); MaxHP(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Circle of Life 2 ignores resistances and immunities when target is above 50%, ability immunity")
{
    u32 hp;
    PARAMETRIZE { hp = 200; }
    PARAMETRIZE { hp = 100; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CIRCLE_OF_LIFE2); }
        OPPONENT(SPECIES_GOODRA) { Ability(ABILITY_SAP_SIPPER); HP(hp); MaxHP(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_VINE_WHIP); }
    } SCENE {
        if (hp == 200) {
            NOT ABILITY_POPUP(opponent, ABILITY_SAP_SIPPER);
        } else {
            ABILITY_POPUP(opponent, ABILITY_SAP_SIPPER);
        }
    }
}
