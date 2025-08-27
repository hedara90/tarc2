#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Resorption absorbs HP from when attacking poisoned foes")
{
    s16 damage, healing;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_RESORPTION); HP(120); MaxHP(240); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH);
        HP_BAR(opponent, captureDamage: &damage);
        ABILITY_POPUP(player, ABILITY_RESORPTION);
        HP_BAR(player, captureDamage: &healing);
    } THEN {
        EXPECT_MUL_EQ(healing, Q_4_12(-TARC_RESORPTION_FRACTION), damage);
    }
}
