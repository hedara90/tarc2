#include "global.h"
#include "test/battle.h"

#if B_SNOW_WARNING < GEN_9
SINGLE_BATTLE_TEST("Snow Warning summons hail")
#elif B_SNOW_WARNING >= GEN_9
SINGLE_BATTLE_TEST("Snow Warning summons snow")
#endif
{
    GIVEN {
        PLAYER(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        #if B_SNOW_WARNING < GEN_9
        MESSAGE("It started to hail!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HAIL_CONTINUES);
        #elif B_SNOW_WARNING >= GEN_9
        MESSAGE("It started to snow!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SNOW_CONTINUES);
        #endif
    }
}

#if B_SNOW_WARNING < GEN_9
SINGLE_BATTLE_TEST("Snow Warning summons hail (Trait)")
#elif B_SNOW_WARNING >= GEN_9
SINGLE_BATTLE_TEST("Snow Warning summons snow (Trait)")
#endif
{
    GIVEN {
        PLAYER(SPECIES_ABOMASNOW) { Ability(ABILITY_SOUNDPROOF); Innates(ABILITY_SNOW_WARNING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        #if B_SNOW_WARNING < GEN_9
        MESSAGE("It started to hail!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HAIL_CONTINUES);
        #elif B_SNOW_WARNING >= GEN_9
        MESSAGE("It started to snow!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SNOW_CONTINUES);
        #endif
    }
}
