#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Frigid Body inflicts frostbite on contact")
{
    u32 move;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MAGMAR) { Ability(ABILITY_FRIGID_BODY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        if (MoveMakesContact(move)) {
            ABILITY_POPUP(opponent, ABILITY_FRIGID_BODY);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRZ, player);
            MESSAGE("The opposing Magmar's Frigid Body froze Wobbuffet!");
            STATUS_ICON(player, frostbite: TRUE);
        } else {
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_FRIGID_BODY);
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRZ, player);
                MESSAGE("The opposing Magmar's Frigid Body froze Wobbuffet!");
                STATUS_ICON(player, frostbite: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Frigid Body triggers 30% of the time")
{
    PASSES_RANDOMLY(3, 10, RNG_FRIGID_BODY);
    GIVEN {
        ASSUME(B_ABILITY_TRIGGER_CHANCE >= GEN_4);
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MAGMAR) { Ability(ABILITY_FRIGID_BODY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_FRIGID_BODY);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRZ, player);
        MESSAGE("The opposing Magmar's Frigid Body froze Wobbuffet!");
        STATUS_ICON(player, frostbite: TRUE);
    }
}

SINGLE_BATTLE_TEST("INNATE: Frigid Body inflicts frostbite on contact")
{
    u32 move;
    PARAMETRIZE { move = MOVE_TACKLE; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_TACKLE));
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MAGMAR) { Ability(ABILITY_VITAL_SPIRIT); Innates(ABILITY_FRIGID_BODY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        if (MoveMakesContact(move)) {
            ABILITY_POPUP(opponent, ABILITY_FRIGID_BODY);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRZ, player);
            MESSAGE("The opposing Magmar's Frigid Body froze Wobbuffet!");
            STATUS_ICON(player, frostbite: TRUE);
        } else {
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_FRIGID_BODY);
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRZ, player);
                MESSAGE("The opposing Magmar's Frigid Body froze Wobbuffet!");
                STATUS_ICON(player, frostbite: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("INNATE: Frigid Body triggers 30% of the time")
{
    PASSES_RANDOMLY(3, 10, RNG_FRIGID_BODY);
    GIVEN {
        ASSUME(B_ABILITY_TRIGGER_CHANCE >= GEN_4);
        ASSUME(MoveMakesContact(MOVE_TACKLE));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MAGMAR) { Ability(ABILITY_VITAL_SPIRIT); Innates(ABILITY_FRIGID_BODY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_FRIGID_BODY);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRZ, player);
        MESSAGE("The opposing Magmar's Frigid Body froze Wobbuffet!");
        STATUS_ICON(player, frostbite: TRUE);
    }
}
