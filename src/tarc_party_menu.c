#include "gba/types.h"
#include "bg.h"
#include "decompress.h"
#include "global.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "task.h"
#include "window.h"
#include "tarc_party_menu.h"

#include "constants/characters.h"
#include "constants/rgb.h"

struct Tarc_Mon
{
    u16 species;
    u16 hp;
    u16 maxHP;
    u16 atk;
    u16 def;
    u16 spa;
    u16 spd;
    u16 spe;
    u16 moves[4];
    u16 abilities[4];
};

struct Tarc_PartyMenuState
{
    MainCallback savedCallback;
    u8 loadState;
    bool8 listIsInitialized;
    u8 listTaskid;
    struct ListMenuItem listBuffer[36];
    struct ListMenuTemplate list;
    bool8 switchedMode;
    u8 mode;
    struct Tarc_Mon mons[3];
};

enum WindowIds
{
    WIN_MODE,
    WIN_LIST,
    WIN_SELECT1,
    WIN_SELECT2,
    WIN_SELECT3,
    WIN_SELECT4,
    WIN_INFO,
    WIN_SUB,
    WIN_CONTROLLS,
    WIN_HP,
    WIN_ATK,
    WIN_DEF,
    WIN_SPA,
    WIN_SPD,
    WIN_SPE,
    WIN_COUNT
};

static EWRAM_DATA struct Tarc_PartyMenuState *sTarcUiState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

enum ViewMode
{
    MODE_MOVES,
    MODE_ABILITIES,
};

static const u32 sTarcTiles[] = INCBIN_U32("graphics/tarc_party/tarc_party_tiles.4bpp.lz");
static const u32 sTarcTilemap[] = INCBIN_U32("graphics/tarc_party/tarc_party_tiles.bin.lz");
static const u16 sTarcPalette[] = INCBIN_U16("graphics/tarc_party/tarc_party_tiles.gbapal");

static const u8 sTextMoves[] = _("Moves");
static const u8 sTextAbilities[] = _("Abilities");
static const u8 *const sModeNames[3] = {
    [MODE_MOVES]   = sTextMoves,
    [MODE_ABILITIES]  = sTextAbilities,
};

static const struct BgTemplate sTarcUiBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    },
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 20,
        .priority = 2
    }
};

#define MODE_WIDTH  10
#define MODE_HEIGHT 2
#define LIST_WIDTH  10
#define LIST_HEIGHT 10
#define SELECT_WIDTH      8
#define SELECT_HEIGHT     2
#define INFO_WIDTH  20
#define INFO_HEIGHT 8
#define SUB_WIDTH   20
#define SUB_HEIGHT  2
#define CONTROLLS_WIDTH  21
#define CONTROLLS_HEIGHT 2
#define HP_WIDTH  9
#define HP_HEIGHT 2
#define STAT_WIDTH  6
#define STAT_HEIGHT 2

#define MODE_SIZE MODE_WIDTH * MODE_HEIGHT
#define LIST_SIZE LIST_WIDTH * LIST_HEIGHT
#define SELECT1_SIZE SELECT_WIDTH * SELECT_HEIGHT
#define SELECT2_SIZE SELECT1_SIZE
#define SELECT3_SIZE SELECT1_SIZE
#define SELECT4_SIZE SELECT1_SIZE
#define INFO_SIZE INFO_WIDTH * INFO_HEIGHT
#define SUB_SIZE SUB_WIDTH * SUB_HEIGHT
#define CONTROLLS_SIZE CONTROLLS_WIDTH * CONTROLLS_HEIGHT
#define HP_SIZE HP_WIDTH * HP_HEIGHT
#define ATK_SIZE STAT_WIDTH * STAT_HEIGHT
#define DEF_SIZE ATK_SIZE
#define SPA_SIZE ATK_SIZE
#define SPD_SIZE ATK_SIZE
#define SPE_SIZE ATK_SIZE

#define MODE_BASEBLOCK 1
#define LIST_BASEBLOCK MODE_BASEBLOCK + MODE_SIZE
#define SELECT1_BASEBLOCK LIST_BASEBLOCK + LIST_SIZE
#define SELECT2_BASEBLOCK SELECT1_BASEBLOCK + SELECT1_SIZE
#define SELECT3_BASEBLOCK SELECT2_BASEBLOCK + SELECT1_SIZE
#define SELECT4_BASEBLOCK SELECT3_BASEBLOCK + SELECT1_SIZE
#define INFO_BASEBLOCK SELECT4_BASEBLOCK + SELECT1_SIZE
#define SUB_BASEBLOCK INFO_BASEBLOCK + INFO_SIZE
#define CONTROLLS_BASEBLOCK SUB_BASEBLOCK + SUB_SIZE
#define HP_BASEBLOCK CONTROLLS_BASEBLOCK + CONTROLLS_SIZE
#define ATK_BASEBLOCK HP_BASEBLOCK + HP_SIZE
#define DEF_BASEBLOCK ATK_BASEBLOCK + ATK_SIZE
#define SPA_BASEBLOCK DEF_BASEBLOCK + DEF_SIZE
#define SPD_BASEBLOCK SPA_BASEBLOCK + SPA_SIZE
#define SPE_BASEBLOCK SPD_BASEBLOCK + SPD_SIZE

static const struct WindowTemplate sTarcUiWindowTemplates[] =
{
    [WIN_MODE] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = MODE_WIDTH,
        .height = MODE_HEIGHT,
        .paletteNum = 15,
        .baseBlock = MODE_BASEBLOCK,
    },
    [WIN_LIST] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 2,
        .width = LIST_WIDTH,
        .height = LIST_HEIGHT,
        .paletteNum = 15,
        .baseBlock = LIST_BASEBLOCK
    },
    [WIN_SELECT1] =
    {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 0,
        .width = SELECT_WIDTH,
        .height = SELECT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SELECT1_BASEBLOCK
    },
    [WIN_SELECT2] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 21,
        .width = SELECT_WIDTH,
        .height = SELECT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SELECT2_BASEBLOCK
    },
    [WIN_SELECT3] =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 11,
        .width = SELECT_WIDTH,
        .height = SELECT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SELECT3_BASEBLOCK
    },
    [WIN_SELECT4] =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 21,
        .width = SELECT_WIDTH,
        .height = SELECT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SELECT4_BASEBLOCK
    },
    [WIN_INFO] =
    {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 4,
        .width = INFO_WIDTH,
        .height = INFO_HEIGHT,
        .paletteNum = 15,
        .baseBlock = INFO_BASEBLOCK
    },
    [WIN_SUB] =
    {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 12,
        .width = SUB_WIDTH,
        .height = SUB_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SUB_BASEBLOCK
    },
    [WIN_CONTROLLS] =
    {
        .bg = 0,
        .tilemapLeft = 9,
        .tilemapTop = 18,
        .width = CONTROLLS_WIDTH,
        .height = CONTROLLS_HEIGHT,
        .paletteNum = 15,
        .baseBlock = CONTROLLS_BASEBLOCK
    },
    [WIN_HP] =
    {
        .bg = 0,
        .tilemapLeft = 9,
        .tilemapTop = 14,
        .width = HP_WIDTH,
        .height = HP_HEIGHT,
        .paletteNum = 15,
        .baseBlock = HP_BASEBLOCK
    },
    [WIN_ATK] =
    {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 14,
        .width = STAT_WIDTH,
        .height = STAT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = ATK_BASEBLOCK
    },
    [WIN_DEF] =
    {
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 14,
        .width = STAT_WIDTH,
        .height = STAT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = DEF_BASEBLOCK
    },
    [WIN_SPA] =
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 16,
        .width = STAT_WIDTH,
        .height = STAT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SPA_BASEBLOCK
    },
    [WIN_SPD] =
    {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 16,
        .width = STAT_WIDTH,
        .height = STAT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SPD_BASEBLOCK
    },
    [WIN_SPE] =
    {
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 16,
        .width = STAT_WIDTH,
        .height = STAT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SPE_BASEBLOCK
    },
    DUMMY_WIN_TEMPLATE
};

enum FontColor
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};

static const u8 sTarcUiWindowFontColors[][3] =
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
    [FONT_BLUE]   = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_GRAY},
};

static void TarcUi_SetupCB(void);
static void TarcUi_ResetGpuRegsAndBgs(void);
static bool8 TarcUi_InitBgs(void);
static void TarcUi_FadeAndBail(void);
static void Task_TarcUiWaitFadeAndBail(u8 taskId);
static void TarcUi_VBlankCB(void);
static void TarcUi_FreeResources(void);
static void TarcUi_MainCB(void);
static bool8 TarcUi_LoadGraphics(void);
static void TarcUi_InitWindows(void);
static void Task_TarcUiWaitFadeIn(u8 taskId);
static void Task_TarcUiMainInput(u8 taskId);
static void TarcUi_LoadMons(void);
static void TarcUi_InitScrollList(void);
static void TarcUi_BuildListMoves(void);
static void TarcUi_BuildListAbilities(void);

void OpenFromScript(void)
{
    Tarc_InitSummaryScreen(CB2_ReturnToFieldWithOpenMenu);
}

void Tarc_InitSummaryScreen(MainCallback callback)
{
    sTarcUiState = AllocZeroed(sizeof(struct Tarc_PartyMenuState));
    if (sTarcUiState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sTarcUiState->savedCallback = callback;
    sTarcUiState->loadState = 0;

    SetMainCallback2(TarcUi_SetupCB);
}

static void TarcUi_SetupCB(void)
{
    switch (gMain.state)
    {
    case 0:
        TarcUi_ResetGpuRegsAndBgs();
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (TarcUi_InitBgs())
        {
            sTarcUiState->loadState = 0;
            gMain.state++;
        }
        else
        {
            TarcUi_FadeAndBail();
            return;
        }
        break;
    case 3:
        if (TarcUi_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        TarcUi_InitWindows();
        gMain.state++;
        break;
    case 5:
        TarcUi_LoadMons();
        TarcUi_InitScrollList();

        /*
        EvenCraftingUi_PrintFixedUiButtonHints();

        EvenCraftingUi_PrintDynamicUiButtonHints();

        EvenCraftingUi_PrintListHeader();

        EvenCraftingUi_PrintListCategory();

        EvenCraftingUi_PrintList();
        */

        CreateTask(Task_TarcUiWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(TarcUi_VBlankCB);
        SetMainCallback2(TarcUi_MainCB);
        break;
    }
}

static void TarcUi_ResetGpuRegsAndBgs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);

    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    CpuFill16(0, (void *)VRAM, VRAM_SIZE);
    CpuFill32(0, (void *)OAM, OAM_SIZE);
}

static bool8 TarcUi_InitBgs(void)
{
    const u32 TILEMAP_BUFFER_SIZE = (1024 * 2);

    ResetAllBgsCoordinates();

    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;

    ResetBgsAndClearDma3BusyFlags(0);

    InitBgsFromTemplates(0, sTarcUiBgTemplates, NELEMS(sTarcUiBgTemplates));

    SetBgTilemapBuffer(1, sBg1TilemapBuffer);

    ScheduleBgCopyTilemapToVram(1);

    ShowBg(0);
    ShowBg(1);

    return TRUE;
}

static void TarcUi_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_TarcUiWaitFadeAndBail, 0);

    SetVBlankCallback(TarcUi_VBlankCB);
    SetMainCallback2(TarcUi_MainCB);
}

static void Task_TarcUiWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sTarcUiState->savedCallback);
        TarcUi_FreeResources();
        DestroyTask(taskId);
    }
}

static void TarcUi_VBlankCB(void)
{

    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void TarcUi_FreeResources(void)
{
    if (sTarcUiState != NULL)
    {
        Free(sTarcUiState);
    }
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
    }
    FreeAllWindowBuffers();
    ResetSpriteData();
}

static void TarcUi_MainCB(void)
{
    AnimateSprites();
    RunTasks();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static bool8 TarcUi_LoadGraphics(void)
{
    switch (sTarcUiState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();

        DecompressAndCopyTileDataToVram(1, sTarcTiles, 0, 0, 0);
        sTarcUiState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sTarcTilemap, sBg1TilemapBuffer);
            sTarcUiState->loadState++;
        }
        break;
    case 2:
        LoadPalette(sTarcPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        LoadPalette(gMessageBox_Pal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        sTarcUiState->loadState++;
    default:
        sTarcUiState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void TarcUi_InitWindows(void)
{
    InitWindows(sTarcUiWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);

    for (u32 i = 0; i < WIN_COUNT; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
        PutWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_FULL);
    }
}

static void Task_TarcUiWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_TarcUiMainInput;
}

static void Task_TarcUiMainInput(u8 taskId)
{
}

static void TarcUi_LoadMons(void)
{
    for (u32 i = 0; i < 3; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        sTarcUiState->mons[i].species = GetMonData(mon, MON_DATA_SPECIES);
        for (u32 j = 0; j < 4; j++)
        {
            sTarcUiState->mons[i].moves[j] = GetMonData(mon, MON_DATA_MOVE1 + j);
        }
        sTarcUiState->mons[i].hp = GetMonData(mon, MON_DATA_HP);
        sTarcUiState->mons[i].maxHP = GetMonData(mon, MON_DATA_MAX_HP);
        sTarcUiState->mons[i].atk = GetMonData(mon, MON_DATA_ATK);
        sTarcUiState->mons[i].def = GetMonData(mon, MON_DATA_DEF);
        sTarcUiState->mons[i].spa = GetMonData(mon, MON_DATA_SPATK);
        sTarcUiState->mons[i].spd = GetMonData(mon, MON_DATA_SPDEF);
        sTarcUiState->mons[i].spe = GetMonData(mon, MON_DATA_SPEED);
    }
}

static void TarcUi_InitScrollList(void)
{
    u16 scrollPos = 0;
    if (sTarcUiState->listIsInitialized)
    {
        if (sTarcUiState->switchedMode)
            DestroyListMenuTask(sTarcUiState->listTaskid, NULL, NULL);
        else
            DestroyListMenuTask(sTarcUiState->listTaskid, NULL, &scrollPos);
    }
    switch (sTarcUiState->mode)
    {
    case MODE_MOVES:
        TarcUi_BuildListMoves();
        break;
    case MODE_ABILITIES:
        TarcUi_BuildListAbilities();
        break;
    }
    sTarcUiState->listTaskid = ListMenuInit(&sTarcUiState->list, 0, scrollPos);
    sTarcUiState->listIsInitialized = TRUE;
    CopyWindowToVram(WIN_LIST, COPYWIN_FULL);
    sTarcUiState->switchedMode = FALSE;
}

static void TarcUi_BuildListMoves(void)
{
    /*
    u32 itemCount = 0;
    struct ListIngredients ingredients[40];
    u32 totalBagSlots = EvenCraftingUi_GetTotalBagSlots();

    struct ItemSlot *pCurrSlot = &gSaveBlock1Ptr->bagPocket_Items[0];
    enum IngredientCategories category = sEvenCraftingUiState->currIngredientCategory;
    for (u32 i = 0; i < totalBagSlots; i++)
    {
        u16 currItem = pCurrSlot->itemId;
        if (currItem == ITEM_NONE)
        {
            pCurrSlot++;
            continue;
        }
        if(IsItemInCurrentCategory(category, currItem))
        {
            struct ListIngredients currIngredient;
            currIngredient.item = currItem;
            currIngredient.count = pCurrSlot->quantity;
            ingredients[itemCount] = currIngredient;
            itemCount++;
        }
        pCurrSlot++;
    }
    for (u32 i = 0; i < itemCount; i++)
    {
        sEvenCraftingUiState->listBuffer[i].name = gItemsInfo[ingredients[i].item].name;
        sEvenCraftingUiState->listBuffer[i].id = ingredients[i].item;
    }
    sEvenCraftingUiState->list = sItemListMenu;
    sEvenCraftingUiState->list.items = sEvenCraftingUiState->listBuffer;
    sEvenCraftingUiState->list.totalItems = itemCount;
    if (itemCount > 0)
        sEvenCraftingUiState->currentIngredient = ingredients[0].item;
    else
        sEvenCraftingUiState->currentIngredient = ITEM_NONE;
    */
}

static void TarcUi_BuildListAbilities(void)
{
    /*
    u32 itemCount = 0;
    struct ListIngredients ingredients[40];
    u32 totalBagSlots = EvenCraftingUi_GetTotalBagSlots();

    struct ItemSlot *pCurrSlot = &gSaveBlock1Ptr->bagPocket_Items[0];
    enum IngredientCategories category = sEvenCraftingUiState->currIngredientCategory;
    for (u32 i = 0; i < totalBagSlots; i++)
    {
        u16 currItem = pCurrSlot->itemId;
        if (currItem == ITEM_NONE)
        {
            pCurrSlot++;
            continue;
        }
        if(IsItemInCurrentCategory(category, currItem))
        {
            struct ListIngredients currIngredient;
            currIngredient.item = currItem;
            currIngredient.count = pCurrSlot->quantity;
            ingredients[itemCount] = currIngredient;
            itemCount++;
        }
        pCurrSlot++;
    }
    for (u32 i = 0; i < itemCount; i++)
    {
        sEvenCraftingUiState->listBuffer[i].name = gItemsInfo[ingredients[i].item].name;
        sEvenCraftingUiState->listBuffer[i].id = ingredients[i].item;
    }
    sEvenCraftingUiState->list = sItemListMenu;
    sEvenCraftingUiState->list.items = sEvenCraftingUiState->listBuffer;
    sEvenCraftingUiState->list.totalItems = itemCount;
    if (itemCount > 0)
        sEvenCraftingUiState->currentIngredient = ingredients[0].item;
    else
        sEvenCraftingUiState->currentIngredient = ITEM_NONE;
    */
}
