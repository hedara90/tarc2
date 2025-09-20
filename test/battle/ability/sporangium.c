#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sporangium inflicts Leech Seed on targets hit by grass attacks")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SPORANGIUM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LEAFAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEAFAGE, player);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_SPORANGIUM);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, player);
    }
}

SINGLE_BATTLE_TEST("Sporangium doesn't inflict Leech Seed on Grass-type pokemon")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SPORANGIUM); }
        OPPONENT(SPECIES_TANGELA);
    } WHEN {
        TURN { MOVE(player, MOVE_LEAFAGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEAFAGE, player);
        HP_BAR(opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_SPORANGIUM);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, player);
        }
    }
}

SINGLE_BATTLE_TEST("Sporangium doesn't trigger if the target faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SPORANGIUM); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LEAFAGE); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEAFAGE, player);
        HP_BAR(opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_SPORANGIUM);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, player);
        }
    }
}
