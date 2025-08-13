#include "global.h"
#include "hunt_setup.h"
#include "random.h"
#include "move.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "constants/hunt_setup.h"
#include "constants/abilities.h"

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
    SetupPlayerMons(gSaveBlock1Ptr->playerAffinity, &localRngState);

    //  Clear out saveblock data
    for (u32 i = 0; i < 36; i++)
        gSaveBlock1Ptr->moveStorage[i] = MOVE_NONE;

    for (u32 i = 0; i < 9; i++)
        gSaveBlock1Ptr->abilityStorage[i] = ABILITY_NONE;
}

static void GiveHuntMons(enum PlayerMonList monList, rng_value_t *localRngState)
{
    u8 stats[6] = {0, 0, 0, 0, 0, 0};

    u16 moves[4] = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_NONE};

    //  Give the fixed setter
    for (u32 i = 0; i < 2; i++)
    {
        moves[i] = sStarterSetters[monList].moves[i];
    }

    bool8 isShiny = (LocalRandom32(localRngState) % 0xFFF) == 0;

    ScriptGiveMonParameterized(0, 0, sStarterSetters[monList].species, 100, ITEM_NONE, 0, NATURE_HARDY, 0, MON_GENDERLESS, stats, stats, moves, isShiny, FALSE, TYPE_NONE, 0);

    gSaveBlock1Ptr->playerSpecies[0] = sStarterSetters[monList].species;

    //  Give random mons from pool
    const struct StarterPool *pool = &sRainPool;
    switch (monList)
    {
    case MON_LIST_RAIN_DIRECT:
    case MON_LIST_RAIN_CONDITIONAL:
    case MON_LIST_RAIN_MANUAL:
        pool = &sRainPool;
        break;
    case MON_LIST_SUN_DIRECT:
    case MON_LIST_SUN_CONDITIONAL:
    case MON_LIST_SUN_MANUAL:
        pool = &sSunPool;
        break;
    case MON_LIST_SNOW_DIRECT:
    case MON_LIST_SNOW_CONDITIONAL:
    case MON_LIST_SNOW_MANUAL:
        pool = &sSnowPool;
        break;
    case MON_LIST_SAND_DIRECT:
    case MON_LIST_SAND_CONDITIONAL:
    case MON_LIST_SAND_MANUAL:
        pool = &sSandPool;
        break;
    case MON_LIST_RANDOM:
        pool = &sRainPool;
        break;
    }

    u32 index1 = LocalRandom32(localRngState) % pool->numMons;
    u32 index2 = LocalRandom32(localRngState) % pool->numMons;
    while (index1 == index2)
        index2 = LocalRandom32(localRngState) % pool->numMons;


    isShiny = (LocalRandom32(localRngState) % 0xFFF) == 0;
    for (u32 i = 0; i < 2; i++)
    {
        moves[i] = pool->mons[index1].moves[i];
    }
    ScriptGiveMonParameterized(0, 1, pool->mons[index1].species, 100, ITEM_NONE, 0, NATURE_HARDY, 0, MON_GENDERLESS, stats, stats, moves, isShiny, FALSE, TYPE_NONE, 0);

    isShiny = (LocalRandom32(localRngState) % 0xFFF) == 0;
    for (u32 i = 0; i < 2; i++)
    {
        moves[i] = pool->mons[index2].moves[i];
    }
    ScriptGiveMonParameterized(0, 2, pool->mons[index2].species, 100, ITEM_NONE, 0, NATURE_HARDY, 0, MON_GENDERLESS, stats, stats, moves, isShiny, FALSE, TYPE_NONE, 0);
}

void SetupPlayerMons(enum PlayerMonList monList, rng_value_t *localRngState)
{
    //  Clear current mons for player
    for (u32 i = 0; i < 6; i++)
    {
        memset(&gSaveBlock1Ptr->playerParty[i], 0, sizeof(struct Pokemon));
        memset(&gPlayerParty[i], 0, sizeof(struct Pokemon));
    }

    //  Give player all the mons from the current list
    switch (monList)
    {
        case MON_LIST_RANDOM:
        default:
            GiveHuntMons(monList, localRngState);
            break;
    }
}

void SetAffinityFromScript(struct ScriptContext *ctx)
{
    gSaveBlock1Ptr->playerAffinity = ScriptReadByte(ctx);
}
