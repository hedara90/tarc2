#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Dread has a 30% chance to paralyze when attacking with Psychic moves")
{
    PASSES_RANDOMLY(3, 10, RNG_STATIC);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_DREAD); }
        OPPONENT(SPECIES_SLAKING);
    } WHEN {
        TURN { MOVE(player, MOVE_PSYSHOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYSHOCK, player);
        ABILITY_POPUP(player, ABILITY_DREAD);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
        MESSAGE("Wobbuffet's Dread paralyzed the opposing Slaking, so it may be unable to move!");
        STATUS_ICON(opponent, paralysis: TRUE);
    }
}

SINGLE_BATTLE_TEST("Dread doesn't trigger if the target is already statused")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_DREAD); }
        OPPONENT(SPECIES_SLAKING) { Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYSHOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYSHOCK, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_DREAD);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
            MESSAGE("Wobbuffet's Dread paralyzed the opposing Slaking, so it may be unable to move!");
            STATUS_ICON(opponent, paralysis: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Dread doesn't trigger if the target has Limber")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_DREAD); }
        OPPONENT(SPECIES_LOPUNNY) { Ability(ABILITY_LIMBER); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYSHOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYSHOCK, player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_DREAD);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
            MESSAGE("Wobbuffet's Dread paralyzed the opposing Lopunny, so it may be unable to move!");
            STATUS_ICON(opponent, paralysis: TRUE);
        }
    }
}
