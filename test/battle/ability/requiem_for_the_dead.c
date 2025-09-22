#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Requiem for the Dead increases damage by 20% for each missing opponent, 1 mon", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_TELEPATHY; }
    PARAMETRIZE { ability = ABILITY_REQUIEM_FOR_THE_DEAD; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEALING_WISH); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_DARK_PULSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEALING_WISH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DARK_PULSE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.2), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Requiem for the Dead increases damage by 20% for each missing opponent, 5 mons", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_TELEPATHY; }
    PARAMETRIZE { ability = ABILITY_REQUIEM_FOR_THE_DEAD; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEALING_WISH); SEND_OUT(opponent, 1); }
        TURN { MOVE(opponent, MOVE_HEALING_WISH); SEND_OUT(opponent, 2); }
        TURN { MOVE(opponent, MOVE_HEALING_WISH); SEND_OUT(opponent, 3); }
        TURN { MOVE(opponent, MOVE_HEALING_WISH); SEND_OUT(opponent, 4); }
        TURN { MOVE(opponent, MOVE_HEALING_WISH); SEND_OUT(opponent, 5); }
        TURN { MOVE(player, MOVE_DARK_PULSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEALING_WISH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEALING_WISH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEALING_WISH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEALING_WISH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEALING_WISH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DARK_PULSE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}
