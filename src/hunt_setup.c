#include "global.h"
#include "decompress.h"
#include "even_sprite.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "hunt_setup.h"
#include "random.h"
#include "main.h"
#include "malloc.h"
#include "move.h"
#include "palette.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "constants/hunt_setup.h"
#include "constants/abilities.h"
#include "constants/vars.h"

#include "start_menu.h"

#include "data/hunt_setup_data.h"

const u32 sLeftFrame[] = INCBIN_U32("graphics/tarc_choose_boss/frame_left.4bpp");
const u32 sRightFrame[] = INCBIN_U32("graphics/tarc_choose_boss/frame_right.4bpp");
const u16 sLeftFramePal[] = INCBIN_U16("graphics/tarc_choose_boss/frame_left.gbapal");
const u16 sRightFramePal[] = INCBIN_U16("graphics/tarc_choose_boss/frame_right.gbapal");

static void Task_SelectorTask(u8 taskId);
static void ReplaceShownSprite(void);
static void DestroyCurrentShownSprite(void);
static void DestroySideSprites(void);
void SetHuntFlags(void);

void SetupHuntFromScript(struct ScriptContext *ctx)
{
    enum FinalBossList boss = ScriptReadByte(ctx);
    SetupHuntTargets(boss);
}

void SetupHuntTargets(enum FinalBossList finalBoss)
{
    SetHuntFlags();
    u32 randomSeed = Random32();
    rng_value_t localRngState = LocalRandomSeed(randomSeed);
    if (finalBoss == FINAL_BOSS_RANDOM)
    {
        gSaveBlock1Ptr->huntTargets.finalBoss = sFinalBossToSpecies[LocalRandom32(&localRngState) % BOSS_COUNT];
    }
    else
    {
        gSaveBlock1Ptr->huntTargets.finalBoss = finalBoss;
    }
    gSaveBlock1Ptr->huntTargets.finalBossDefeated = FALSE;

    gSaveBlock1Ptr->huntTargets.bosses[0] = BOSS_PSEUDOS;
    gSaveBlock1Ptr->huntTargets.bossesDefeated[0] = FALSE;

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

    gSaveBlock1Ptr->huntTargets.bosses[0] = 12;
    gSaveBlock1Ptr->huntTargets.bossesDefeated[0] = FALSE;
    for (u32 i = 0; i < 8; i++)
    {
        gSaveBlock1Ptr->huntTargets.bosses[1 + i] = bosses[i];
        gSaveBlock1Ptr->huntTargets.bossesDefeated[1 + i] = FALSE;
    }

    //  Setup player mons
    enum PlayerMonList monList;
    if (gSaveBlock1Ptr->playerAffinity == MON_LIST_RANDOM)
        monList = LocalRandom32(&localRngState) % MON_LIST_RANDOM;
    else
        monList = gSaveBlock1Ptr->playerAffinity;
    SetupPlayerMons(monList, &localRngState);

    //  Randomize minibosses
    u32 numMinibosses = 0;
    const u16 *miniBossList;
    switch (monList)
    {
    case MON_LIST_RAIN_DIRECT:
    case MON_LIST_RAIN_CONDITIONAL:
    case MON_LIST_RAIN_MANUAL:
        miniBossList = sRainMiniBosses;
        numMinibosses = ARRAY_COUNT(sRainMiniBosses);
        break;
    case MON_LIST_SUN_DIRECT:
    case MON_LIST_SUN_CONDITIONAL:
    case MON_LIST_SUN_MANUAL:
        miniBossList = sSunMiniBosses;
        numMinibosses = ARRAY_COUNT(sSunMiniBosses);
        break;
    case MON_LIST_SNOW_DIRECT:
    case MON_LIST_SNOW_CONDITIONAL:
    case MON_LIST_SNOW_MANUAL:
        miniBossList = sSnowMiniBosses;
        numMinibosses = ARRAY_COUNT(sSnowMiniBosses);
        break;
    case MON_LIST_SAND_DIRECT:
    case MON_LIST_SAND_CONDITIONAL:
    case MON_LIST_SAND_MANUAL:
        miniBossList = sRainMiniBosses;
        numMinibosses = ARRAY_COUNT(sRainMiniBosses);
        break;
    case MON_LIST_RANDOM:
        //  Shouldn't be reached
        miniBossList = sSandMiniBosses;
        numMinibosses = ARRAY_COUNT(sSandMiniBosses);
    }

    u16 *shuffleList = Alloc(2*numMinibosses);
    for (u32 i = 0; i < numMinibosses; i++)
    {
        shuffleList[i] = miniBossList[i];
    }

    for (u32 i = 0; i < numMinibosses - 1; i++)
    {
        u32 rnd = LocalRandom32(&localRngState);
        u32 currIndex = rnd % (numMinibosses - i);
        u16 tempValue = shuffleList[numMinibosses - 1 - i];
        shuffleList[numMinibosses - 1 - i] = shuffleList[currIndex];
        shuffleList[currIndex] = tempValue;
    }

    for (u32 i = 0; i < 27; i++)
    {
        gSaveBlock1Ptr->huntTargets.miniBosses[i] = shuffleList[i];
        gSaveBlock1Ptr->huntTargets.miniBossesDefeated[i] = FALSE;
    }

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
        //  Shouldn't be reached
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

struct BossSelect
{
    u8 currIndex;
    u8 spriteId;
    u8 frameId1;
    u8 frameId2;
    const struct BossGroup *group;
};

EWRAM_DATA struct BossSelect sBossSelect;

void Task_ShortWait(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        gTasks[taskId].data[0]++;
    }
    else
    {
        gSpecialVar_Result = FALSE;
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

void ChooseCurrentBossFromScript(struct ScriptContext *ctx)
{
    u32 area = ScriptReadByte(ctx) - 1;

    if (gSaveBlock1Ptr->huntTargets.bossesDefeated[area])
    {
        //  This is apparently needed
        StringCopy(gStringVar1, gSpeciesInfo[gSaveBlock1Ptr->huntTargets.bossesDefeated[area]].speciesName);
        u32 tempId = CreateTask(Task_ShortWait, 0);
        gTasks[tempId].data[0] = 0;
        return;
    }

    sBossSelect.group = sBossGroups[gSaveBlock1Ptr->huntTargets.bosses[area]];
    gSaveBlock1Ptr->huntTargets.currentArea = area;
    sBossSelect.currIndex = 0;

    LockPlayerFieldControls();

    struct Even_CreateSpriteStruct cs = {0};
    cs.sprite = gSpeciesInfo[sBossSelect.group->members[0]].frontPic;
    cs.spriteCompressed = TRUE;
    cs.tileTag = 0xCEC1;
    cs.palette = gSpeciesInfo[sBossSelect.group->members[0]].palette;
    cs.palTag = 0xCEC1;
    cs.spriteSize = SPRITE_SIZE(64x64);
    cs.spriteShape = SPRITE_SHAPE(64x64);
    cs.posX = 120;
    cs.posY = 80;
    cs.subpriority = 0;
    sBossSelect.spriteId = Even_CreateSprite(&cs);

    //  Load frames
    cs.sprite = sLeftFrame;
    cs.spriteCompressed = FALSE;
    cs.tileTag = 0xCEC2;
    cs.palette = sLeftFramePal;
    cs.palTag = 0xCEC2;
    cs.posX = 88;
    cs.subpriority = 1;
    sBossSelect.frameId1 = Even_CreateSprite(&cs);

    cs.sprite = sRightFrame;
    cs.tileTag = 0xCEC3;
    cs.palette = sRightFramePal;
    cs.palTag = 0xCEC3;
    cs.posX = 152;
    sBossSelect.frameId2 = Even_CreateSprite(&cs);

    u8 taskId = CreateTask(Task_SelectorTask, 0);
    gTasks[taskId].data[0] = 1;
}

static void Task_SelectorTask(u8 taskId)
{
    if (gTasks[taskId].data[0])
    {
        gTasks[taskId].data[0] = 0;
        return;
    }

    if (JOY_NEW(DPAD_LEFT))
    {
        if (sBossSelect.currIndex == 0)
            sBossSelect.currIndex = sBossSelect.group->numMembers - 1;
        else
            sBossSelect.currIndex--;
        ReplaceShownSprite();
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (sBossSelect.currIndex == sBossSelect.group->numMembers - 1)
            sBossSelect.currIndex = 0;
        else
            sBossSelect.currIndex++;
        ReplaceShownSprite();
    }
    else if (JOY_NEW(A_BUTTON))
    {
        gSaveBlock1Ptr->huntTargets.currentBoss = sBossSelect.group->members[sBossSelect.currIndex];
        DestroyCurrentShownSprite();
        DestroySideSprites();
        DestroyTask(taskId);
        gSpecialVar_Result = TRUE;
        ScriptContext_Enable();
    }
    else if (JOY_NEW(B_BUTTON))
    {
        DestroyCurrentShownSprite();
        DestroySideSprites();
        DestroyTask(taskId);
        gSpecialVar_Result = FALSE;
        ScriptContext_Enable();
    }
}

static void DestroyCurrentShownSprite(void)
{
    DestroySprite(&gSprites[sBossSelect.spriteId]);
    FreeSpriteTilesByTag(0xCEC1);
    FreeSpritePaletteByTag(0xCEC1);
}

static void DestroySideSprites(void)
{
    DestroySprite(&gSprites[sBossSelect.frameId1]);
    FreeSpriteTilesByTag(0xCEC2);
    FreeSpritePaletteByTag(0xCEC2);

    DestroySprite(&gSprites[sBossSelect.frameId2]);
    FreeSpriteTilesByTag(0xCEC3);
    FreeSpritePaletteByTag(0xCEC3);
}

static void ReplaceShownSprite(void)
{
    DestroyCurrentShownSprite();

    struct Even_CreateSpriteStruct cs = {0};
    cs.sprite = gSpeciesInfo[sBossSelect.group->members[sBossSelect.currIndex]].frontPic;
    cs.spriteCompressed = TRUE;
    cs.tileTag = 0xCEC1;
    cs.palette = gSpeciesInfo[sBossSelect.group->members[sBossSelect.currIndex]].palette;
    cs.palTag = 0xCEC1;
    cs.spriteSize = SPRITE_SIZE(64x64);
    cs.spriteShape = SPRITE_SHAPE(64x64);
    cs.posX = 120;
    cs.posY = 80;
    sBossSelect.spriteId = Even_CreateSprite(&cs);
}

void SetBossForBattle(void)
{
    gSpecialVar_Result = gSaveBlock1Ptr->huntTargets.currentBoss;
    VarSet(VAR_CURRENT_ENEMY, gSpecialVar_Result);
}

void SetMiniboss(struct ScriptContext *ctx)
{
    u32 area = ScriptReadByte(ctx);
    u32 index = ScriptReadByte(ctx);
    gSpecialVar_Result = gSaveBlock1Ptr->huntTargets.miniBosses[3 * (area - 1) + index];
    VarSet(VAR_CURRENT_ENEMY, gSpecialVar_Result);
}

void SetFinalBoss(void)
{
    gSpecialVar_Result = sFinalBossToSpecies[gSaveBlock1Ptr->huntTargets.finalBoss];
    VarSet(VAR_CURRENT_ENEMY, gSpecialVar_Result);
    gSaveBlock1Ptr->huntTargets.currentBoss = gSpecialVar_Result;
}

void SetMoveReward(void)
{
    u32 species = VarGet(VAR_CURRENT_ENEMY);
    StringCopy(gStringVar2, gMovesInfo[gSpeciesInfo[species].moveReward].name);
    u32 index = 0;
    while (gSaveBlock1Ptr->moveStorage[index] != MOVE_NONE)
        index++;
    gSaveBlock1Ptr->moveStorage[index] = gSpeciesInfo[species].moveReward;
}

void SetAbilityReward(void)
{
    u32 species = VarGet(VAR_CURRENT_ENEMY);
    StringCopy(gStringVar2, gAbilitiesInfo[gSpeciesInfo[species].abilityReward].name);
    u32 index = 0;
    while (gSaveBlock1Ptr->abilityStorage[index] != ABILITY_NONE)
        index++;
    gSaveBlock1Ptr->abilityStorage[index] = gSpeciesInfo[species].abilityReward;
}

void SetHuntFlags(void)
{
    for (u32 i = 0; i < 27; i++)
    {
        FlagClear(FLAG_AREA1_MINIBOSS1 + i);
    }
}

void SetPostBattleData(void)
{
    u32 species = gSaveBlock1Ptr->huntTargets.currentEnemy;
    switch (gSpeciesInfo[species].maxPhases)
    {
    case 2: //  Miniboss
        for (u32 i = 0; i < 27; i++)
        {
            if (gSaveBlock1Ptr->huntTargets.miniBosses[i] == species)
            {
                gSaveBlock1Ptr->huntTargets.miniBossesDefeated[i] = TRUE;
                break;
            }
        }
        break;
    case 3: //  Boss
        gSaveBlock1Ptr->huntTargets.bossesDefeated[gSaveBlock1Ptr->huntTargets.currentArea] = species;
        MgbaPrintf(MGBA_LOG_WARN, "Value: %u", gSaveBlock1Ptr->huntTargets.bossesDefeated[0]);
        break;
    case 4: //  Final Boss
        gSaveBlock1Ptr->huntTargets.finalBossDefeated = TRUE;
        SetWinData();
        break;
    }
}

void SetLossData(void)
{
    FlagClear(FLAG_WON_LAST_RUN);
    FlagSet(FLAG_LOST_LAST_RUN);
}

void SetWinData(void)
{
    FlagSet(FLAG_WON_LAST_RUN);
    FlagClear(FLAG_LOST_LAST_RUN);
}
