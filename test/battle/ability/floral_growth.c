#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Floral Growth recovers 1/16th of Max HP in Rain")
{
    GIVEN {
        PLAYER(SPECIES_LUDICOLO) { Ability(ABILITY_FLORAL_GROWTH); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_FLORAL_GROWTH);
        MESSAGE("Ludicolo's Floral Growth restored its HP a little!");
        HP_BAR(player, damage:  -(100 / 16));
    }
}

SINGLE_BATTLE_TEST("Floral Growth doesn't recover HP if Cloud Nine/Air Lock is on the field")
{
    GIVEN {
        PLAYER(SPECIES_LUDICOLO) { Ability(ABILITY_FLORAL_GROWTH); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_GOLDUCK) { Ability(ABILITY_CLOUD_NINE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_FLORAL_GROWTH);
    }
}

SINGLE_BATTLE_TEST("INNATE: Floral Growth recovers 1/16th of Max HP in Rain")
{
    GIVEN {
        PLAYER(SPECIES_LUDICOLO) { Ability(ABILITY_SWIFT_SWIM); Innates(ABILITY_FLORAL_GROWTH); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_FLORAL_GROWTH);
        MESSAGE("Ludicolo's Floral Growth restored its HP a little!");
        HP_BAR(player, damage:  -(100 / 16));
    }
}

SINGLE_BATTLE_TEST("INNATE: Floral Growth doesn't recover HP if Cloud Nine/Air Lock is on the field")
{
    GIVEN {
        PLAYER(SPECIES_LUDICOLO) { Ability(ABILITY_SWIFT_SWIM); Innates(ABILITY_FLORAL_GROWTH); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_GOLDUCK) { Ability(ABILITY_DAMP); Innates(ABILITY_CLOUD_NINE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_FLORAL_GROWTH);
    }
}
