#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sanctuary")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(120); MaxHP(240); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(120); MaxHP(240); }
    } WHEN {
        TURN { MOVE(player, MOVE_SANCTUARY); MOVE(opponent, MOVE_GLARE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SANCTUARY, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GLARE, opponent);
            STATUS_ICON(player, paralysis: TRUE);
        }
        HP_BAR(player);
        HP_BAR(opponent);
    }
}
