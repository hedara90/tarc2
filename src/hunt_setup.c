#include "global.h"
#include "hunt_setup.h"
#include "random.h"
#include "move.h"
#include "script.h"
#include "script_pokemon_util.h"
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

    //  Setup player mons
    SetupPlayerMons(gSaveBlock1Ptr->playerAffinity);
}

static void GiveHuntMon(enum PlayerMonList monList, u32 index)
{
    u8 stats[6] = {0, 0, 0, 0, 0, 0};

    u16 moves[4];
    for (u32 i = 0; i < 4; i++)
    {
        moves[i] = sStarterMons[monList][index].moves[i];
    }

    bool8 isShiny = (Random32() % 0xFFF) == 0;

    ScriptGiveMonParameterized(0, index, sStarterMons[monList][index].species, 100, ITEM_NONE, 0, NATURE_HARDY, 0, MON_GENDERLESS, stats, stats, moves, isShiny, FALSE, TYPE_NONE, 0);

    gSaveBlock1Ptr->playerSpecies[index] = sStarterMons[monList][index].species;
}

void SetupPlayerMons(enum PlayerMonList monList)
{
    //  Clear current mons for player
    for (u32 i = 0; i < 6; i++)
    {
        memset(&gSaveBlock1Ptr->playerParty[i], 0, sizeof(struct Pokemon));
        memset(&gPlayerParty[i], 0, sizeof(struct Pokemon));
    }

    //  REMOVE THIS WHEN ALL THE LISTS ARE SET UP
    if (monList != MON_LIST_RAIN_DIRECT)
        monList = MON_LIST_RAIN_DIRECT;

    //  Give player all the mons from the current list
    switch (monList)
    {
        case MON_LIST_RANDOM:
        default:
            GiveHuntMon(monList, 0);
            GiveHuntMon(monList, 1);
            GiveHuntMon(monList, 2);
            break;
    }
}

void SetAffinityFromScript(struct ScriptContext *ctx)
{
    gSaveBlock1Ptr->playerAffinity = ScriptReadByte(ctx);
}
