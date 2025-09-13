#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Fractal Shards triggers on hit in snow")
{
    GIVEN {
        PLAYER(SPECIES_DIANCIE) { Ability(ABILITY_FRACTAL_SHARDS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SNOWSCAPE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        ABILITY_POPUP(player, ABILITY_FRACTAL_SHARDS);
    }
}

SINGLE_BATTLE_TEST("Fractal Shards doesn't trigger outside of snow")
{
    u32 move;
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_SUNNY_DAY; }
    PARAMETRIZE { move = MOVE_SANDSTORM; }
    PARAMETRIZE { move = MOVE_RAIN_DANCE; }
    GIVEN {
        PLAYER(SPECIES_DIANCIE) { Ability(ABILITY_FRACTAL_SHARDS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        NOT ABILITY_POPUP(player, ABILITY_FRACTAL_SHARDS);
    }
}

SINGLE_BATTLE_TEST("Fractal Shards boosts the next move after usage")
{
    s16 damage[2];
    GIVEN {
        PLAYER(SPECIES_DIANCIE) { Ability(ABILITY_FRACTAL_SHARDS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SNOWSCAPE); MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_POWER_GEM); }
        TURN { MOVE(player, MOVE_POWER_GEM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        ABILITY_POPUP(player, ABILITY_FRACTAL_SHARDS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWER_GEM, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWER_GEM, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(1.2), damage[0]);
    }
}
