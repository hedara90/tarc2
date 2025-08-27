#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Terras Blessing triggers on status Wind moves")
{
    s16 damage;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TERRAS_BLESSING); HP(120); MaxHP(240); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, player);
        ABILITY_POPUP(player, ABILITY_TERRAS_BLESSING);
        HP_BAR(player, captureDamage: &damage);
    } THEN {
        EXPECT_LT(damage, 0);
    }
}

SINGLE_BATTLE_TEST("Terras Blessing triggers on attacking Wind moves")
{
    s16 damage;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TERRAS_BLESSING); HP(120); MaxHP(240); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GUST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, player);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_TERRAS_BLESSING);
        HP_BAR(player, captureDamage: &damage);
    } THEN {
        EXPECT_LT(damage, 0);
    }
}

SINGLE_BATTLE_TEST("Terras Blessing doesn't trigger on blocked Wind attacks")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TERRAS_BLESSING); HP(120); MaxHP(240); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_GUST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, player);
            HP_BAR(opponent);
            ABILITY_POPUP(player, ABILITY_TERRAS_BLESSING);
            HP_BAR(player);
        }
    }
}
