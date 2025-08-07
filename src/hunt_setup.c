#include "global.h"
#include "hunt_setup.h"
#include "random.h"
#include "move.h"
#include "script.h"
#include "constants/hunt_setup.h"

#include "data/hunt_setup_data.h"

void SetupHuntFromScript(struct ScriptContext *ctx)
{
    enum FinalBossList boss = ScriptReadByte(ctx);
    SetupHuntTargets(boss);
}

void SetupHuntTargets(enum FinalBossList finalBoss)
{
    u32 randomSeed = Random32();
    rng_value_t localRngState = LocalRandomSeed(randomSeed);
    if (finalBoss != FINAL_BOSS_RANDOM)
    {
        gSaveBlock1Ptr->huntTargets.finalBoss = sFinalBossToSpecies[LocalRandom32(&localRngState) % BOSS_COUNT];
    }
    else
    {
        gSaveBlock1Ptr->huntTargets.finalBoss = finalBoss;
    }

    gSaveBlock1Ptr->huntTargets.bosses[0] = BOSS_PSEUDOS;

    enum BossGroupList bosses[BOSS_COUNT] =
    {
        BOSS_BIRDS,
        BOSS_BEASTS,
        BOSS_GOLEMS,
        BOSS_LAKES,
        BOSS_SWORDS,
        BOSS_GENIES,
        BOSS_TAPUS,
        BOSS_TREASURES,
        BOSS_LOYAL,
        BOSS_GALAR_BIRDS,
        BOSS_PARADOX_BEASTS,
        BOSS_PARADOX_SWORDS,
    };

    for (u32 i = 0; i < BOSS_COUNT - 1; i++)
    {
        u32 rnd = LocalRandom32(&localRngState);
        u32 currIndex = rnd % (BOSS_COUNT - i);
        enum BossGroupList tempValue = bosses[BOSS_COUNT - 1 - i];
        bosses[BOSS_COUNT - 1 - i] = bosses[currIndex];
        bosses[currIndex] = tempValue;
    }

    for (u32 i = 0; i < 8 - 1; i++)
    {
        gSaveBlock1Ptr->huntTargets.bosses[1 + i] = bosses[i];
    }

    //  TODO: Randomize the minibosses when they've been decided
}

void SetupPlayerMons(enum PlayerMonList monList)
{
    //  Clear current mons for player
    //  Give player all the mons from the current list
    switch (gSaveBlock1Ptr->playerAffinity)
    {
        case MON_LIST_RANDOM:
        case MON_LIST_RAIN_DIRECT:
        case MON_LIST_RAIN_CONDITIONAL:
        case MON_LIST_RAIN_MANUAL:
        case MON_LIST_SUN_DIRECT:
        case MON_LIST_SUN_CONDITIONAL:
        case MON_LIST_SUN_MANUAL:
        case MON_LIST_SNOW_DIRECT:
        case MON_LIST_SNOW_CONDITIONAL:
        case MON_LIST_SNOW_MANUAL:
        case MON_LIST_SAND_DIRECT:
        case MON_LIST_SAND_CONDITIONAL:
        case MON_LIST_SAND_MANUAL:
    }
}
