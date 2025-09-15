#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Abundance makes 2 turn moves instant at full HP, Geomancy")
{
    GIVEN {
        PLAYER(SPECIES_XERNEAS) { Ability(ABILITY_ABUNDANCE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GEOMANCY); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ABUNDANCE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    }
}

SINGLE_BATTLE_TEST("Abundance makes 2 turn moves instant at full HP, Solar Beam")
{
    GIVEN {
        PLAYER(SPECIES_XERNEAS) { Ability(ABILITY_ABUNDANCE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SOLAR_BEAM); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ABUNDANCE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Abundance doesn't work below max HP, Geomancy")
{
    GIVEN {
        PLAYER(SPECIES_XERNEAS) { Ability(ABILITY_ABUNDANCE); HP(100); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GEOMANCY); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_ABUNDANCE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Abundance makes 2 turn moves instant at full HP, Solar Beam")
{
    GIVEN {
        PLAYER(SPECIES_XERNEAS) { Ability(ABILITY_ABUNDANCE); HP(100); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SOLAR_BEAM); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_ABUNDANCE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}
