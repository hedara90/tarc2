#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Aura of Vitality increases healing by 50%")
{
    s16 healing[2];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(200); Ability(ABILITY_AURA_OF_VITALITY); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(50); MaxHP(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_RECOVER); MOVE(opponent, MOVE_RECOVER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECOVER, player);
        HP_BAR(player, captureDamage: &healing[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECOVER, opponent);
        HP_BAR(opponent, captureDamage: &healing[1]);
    } THEN {
        EXPECT_MUL_EQ(healing[1], Q_4_12(1.2), healing[0]);
    }
}

SINGLE_BATTLE_TEST("Aura of Vitality doesn't affect damage", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_TELEPATHY; }
    PARAMETRIZE { ability = ABILITY_AURA_OF_VITALITY; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HYPER_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_BEAM, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
