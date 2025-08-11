#include "gba/types.h"
#include "bg.h"
#include "decompress.h"
#include "even_sprite.h"
#include "global.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "move.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "window.h"
#include "tarc_party_menu.h"

#include "constants/abilities.h"
#include "constants/characters.h"
#include "constants/moves.h"
#include "constants/rgb.h"
#include "constants/songs.h"

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
    u8 monSpriteId;
    bool8 hasMonSprite;
    u8 activeMon;
    bool8 rightSelected;
    u8 selectPos;
    u8 listPosition;
    u8 selectorSpriteId;
    u8 scrollOffset;
    u8 selectedRow;
    u8 prevListPos;
    struct ListMenuItem listBuffer[36];
    struct ListMenuTemplate list;
    u8 listNames[36][20];
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

static const struct ListMenuTemplate sItemListMenu =
{
    .items = NULL,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = 0,
    .maxShowed = 5,
    .windowId = WIN_LIST,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 15,
    .fillValue = 0,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NARROW,
    .cursorKind = CURSOR_RED_ARROW,
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

static const u32 sTarcSelectorGfx[] = INCBIN_U32("graphics/tarc_party/selector.4bpp");
static const u16 sTarcSelectorPal[] = INCBIN_U16("graphics/tarc_party/selector.gbapal");

static const u8 sTextMoves[] = _("Moves");
static const u8 sTextAbilities[] = _("Abilities");

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
#define INFO_WIDTH  19
#define INFO_HEIGHT 8
#define SUB_WIDTH   19
#define SUB_HEIGHT  2
#define CONTROLLS_WIDTH  22
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
        .tilemapLeft = 12,
        .tilemapTop = 0,
        .width = SELECT_WIDTH,
        .height = SELECT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SELECT1_BASEBLOCK
    },
    [WIN_SELECT2] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 0,
        .width = SELECT_WIDTH,
        .height = SELECT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SELECT2_BASEBLOCK
    },
    [WIN_SELECT3] =
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 2,
        .width = SELECT_WIDTH,
        .height = SELECT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SELECT3_BASEBLOCK
    },
    [WIN_SELECT4] =
    {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 2,
        .width = SELECT_WIDTH,
        .height = SELECT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SELECT4_BASEBLOCK
    },
    [WIN_INFO] =
    {
        .bg = 0,
        .tilemapLeft = 11,
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
        .tilemapLeft = 8,
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
        .tilemapLeft = 18,
        .tilemapTop = 16,
        .width = STAT_WIDTH,
        .height = STAT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SPA_BASEBLOCK
    },
    [WIN_SPD] =
    {
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 16,
        .width = STAT_WIDTH,
        .height = STAT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SPD_BASEBLOCK
    },
    [WIN_SPE] =
    {
        .bg = 0,
        .tilemapLeft = 12,
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
static void TarcUi_PrintListHeader();
static u32 TarcUi_JustifyCenter(const u8 *input, u32 width, u8 fontId);
static void TarcUi_PrintMon(void);
static void TarcUi_PrintButtonHints(void);
static void TarcUi_PrintSelection(void);
static void TarcUi_UpdateSelector(void);
static void TarcUi_InitSelector(void);
static void TryMoveSelection(void);
static u32 CompactMoveStorage(void);
static u32 CompactAbilityStorage(void);
static void TarcUi_WriteMonData(void);

static void Task_TarcUiWaitFadeAndExitGracefully(u8 taskId);

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
        TarcUi_PrintListHeader();
        TarcUi_PrintButtonHints();

        TarcUi_PrintMon();

        TarcUi_PrintSelection();

        TarcUi_InitSelector();

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

static bool32 TarcUi_ListChanged(void)
{
    u32 newListPos = sTarcUiState->scrollOffset + sTarcUiState->selectedRow;
    if (sTarcUiState->prevListPos != newListPos)
    {
        sTarcUiState->prevListPos = newListPos;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void Task_TarcUiMainInput(u8 taskId)
{
    if (!sTarcUiState->rightSelected)
    {
        ListMenu_ProcessInput(sTarcUiState->listTaskid);
        struct ListMenu *list = (void *)gTasks[sTarcUiState->listTaskid].data;
        sTarcUiState->scrollOffset = list->scrollOffset;
        sTarcUiState->selectedRow = list->selectedRow;
        if (TarcUi_ListChanged())
            TarcUi_PrintSelection();
    }

    if (JOY_NEW(DPAD_LEFT))
    {
        if (sTarcUiState->rightSelected && (sTarcUiState->selectPos == 0 || sTarcUiState->selectPos == 2))
        {
            sTarcUiState->rightSelected = FALSE;
            TarcUi_InitScrollList();
        }
        else if (sTarcUiState->rightSelected)
        {
            sTarcUiState->selectPos -= 1;
            TarcUi_PrintSelection();
        }
        else
        {
            PlaySE(SE_PC_OFF);
        }

        TarcUi_UpdateSelector();
    }

    if (JOY_NEW(DPAD_RIGHT))
    {
        if (!sTarcUiState->rightSelected)
        {
            //  Remove selector from list menu
            sTarcUiState->rightSelected = TRUE;
            TarcUi_InitScrollList();
            TarcUi_PrintSelection();
        }
        else if (sTarcUiState->selectPos == 0 || sTarcUiState->selectPos == 2)
        {
            sTarcUiState->selectPos += 1;
            TarcUi_PrintSelection();
        }
        else
        {
            //  Play error sound
            PlaySE(SE_PC_OFF);
        }

        TarcUi_UpdateSelector();
    }

    if (sTarcUiState->rightSelected && JOY_NEW(DPAD_UP))
    {
        if (sTarcUiState->selectPos > 1)
        {
            sTarcUiState->selectPos -= 2;
            TarcUi_PrintSelection();
        }
        else
        {
            PlaySE(SE_PC_OFF);
        }

        TarcUi_UpdateSelector();
    }

    if (sTarcUiState->rightSelected && JOY_NEW(DPAD_DOWN))
    {
        if (sTarcUiState->selectPos < 2)
        {
            sTarcUiState->selectPos += 2;
            TarcUi_PrintSelection();
        }
        else
        {
            PlaySE(SE_PC_OFF);
        }

        TarcUi_UpdateSelector();
    }

    if (JOY_NEW(L_BUTTON))
    {
        if (sTarcUiState->activeMon == 0)
            sTarcUiState->activeMon = 2;
        else
            sTarcUiState->activeMon--;

        TarcUi_PrintMon();
        TarcUi_PrintSelection();
    }

    if (JOY_NEW(R_BUTTON))
    {
        if (sTarcUiState->activeMon == 2)
            sTarcUiState->activeMon = 0;
        else
            sTarcUiState->activeMon++;

        TarcUi_PrintMon();
        TarcUi_PrintSelection();
    }

    if (JOY_NEW(START_BUTTON))
    {
        sTarcUiState->scrollOffset = 0;
        sTarcUiState->selectedRow = 0;
        switch (sTarcUiState->mode)
        {
        case MODE_MOVES:
            sTarcUiState->scrollOffset = 0;
            sTarcUiState->selectedRow = 0;
            sTarcUiState->mode = MODE_ABILITIES;
            break;
        case MODE_ABILITIES:
            sTarcUiState->mode = MODE_MOVES;
            break;
        }
        TarcUi_PrintListHeader();
        TarcUi_PrintMon();
        TarcUi_InitScrollList();
    }

    if (JOY_NEW(A_BUTTON))
    {
        TryMoveSelection();
    }

    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_TarcUiWaitFadeAndExitGracefully;
    }
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
        sTarcUiState->mons[i].abilities[0] = gSpeciesInfo[sTarcUiState->mons[i].species].abilities[GetMonData(mon, MON_DATA_ABILITY_NUM)];
        for (u32 j = 0; j < 3; j++)
        {
            sTarcUiState->mons[i].abilities[j + 1] = gSaveBlock1Ptr->extraAbilities[i][j];
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
    u16 scrollPos = sTarcUiState->listPosition;
    if (sTarcUiState->listIsInitialized)
    {
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
    if (sTarcUiState->rightSelected)
    {
        sTarcUiState->list.cursorKind = CURSOR_INVISIBLE;
    }
    sTarcUiState->listTaskid = ListMenuInit(&sTarcUiState->list, sTarcUiState->scrollOffset, sTarcUiState->selectedRow);
    sTarcUiState->listIsInitialized = TRUE;
    CopyWindowToVram(WIN_LIST, COPYWIN_FULL);
    sTarcUiState->switchedMode = FALSE;
    TarcUi_PrintSelection();
}

static void TarcUi_BuildListMoves(void)
{
    u32 itemCount = 0;
    for (u32 i = 0; i < 36; i++)
    {
        if (gSaveBlock1Ptr->moveStorage[i] == MOVE_NONE)
            break;

        u8 *end;
        end = StringCopy(sTarcUiState->listNames[i], gMovesInfo[gSaveBlock1Ptr->moveStorage[i]].name);
        PrependFontIdToFit(sTarcUiState->listNames[i], end, FONT_NORMAL, 72);
        sTarcUiState->listBuffer[i].name = sTarcUiState->listNames[i];
        sTarcUiState->listBuffer[i].id = gSaveBlock1Ptr->moveStorage[i];
        itemCount++;
    }
    sTarcUiState->list = sItemListMenu;
    sTarcUiState->list.items = sTarcUiState->listBuffer;
    sTarcUiState->list.totalItems = itemCount;
}

static void TarcUi_BuildListAbilities(void)
{
    u32 itemCount = 0;
    for (u32 i = 0; i < 9; i++)
    {
        if (gSaveBlock1Ptr->abilityStorage[i] == ABILITY_NONE)
            break;

        u8 *end;
        end = StringCopy(sTarcUiState->listNames[i], gAbilitiesInfo[gSaveBlock1Ptr->abilityStorage[i]].name);
        PrependFontIdToFit(sTarcUiState->listNames[i], end, FONT_NORMAL, 72);
        sTarcUiState->listBuffer[i].name = sTarcUiState->listNames[i];
        sTarcUiState->listBuffer[i].id = gSaveBlock1Ptr->abilityStorage[i];
        itemCount++;
    }
    sTarcUiState->list = sItemListMenu;
    sTarcUiState->list.items = sTarcUiState->listBuffer;
    sTarcUiState->list.totalItems = itemCount;
}

void SetupSomeStuff(void)
{
    gSaveBlock1Ptr->moveStorage[0] = MOVE_STOMPING_TANTRUM;
    gSaveBlock1Ptr->moveStorage[1] = MOVE_HYPER_BEAM;
    gSaveBlock1Ptr->moveStorage[2] = MOVE_EARTHQUAKE;
    for (u32 i = 3; i < 18; i++)
        gSaveBlock1Ptr->moveStorage[i] = MOVE_LEECH_SEED + i;

    gSaveBlock1Ptr->abilityStorage[0] = ABILITY_SIMPLE;
    gSaveBlock1Ptr->abilityStorage[1] = ABILITY_BATTLE_ARMOR;
    gSaveBlock1Ptr->abilityStorage[2] = ABILITY_INTIMIDATE;
}

static u32 TarcUi_JustifyCenter(const u8 *input, u32 width, u8 fontId)
{
    u32 currWidth = GetStringWidth(fontId, input, 0);
    if (currWidth < width)
        return (width - currWidth) >> 1;
    else
        return 0;
}

static void TarcUi_PrintListHeader()
{
    FillWindowPixelBuffer(WIN_MODE, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    switch (sTarcUiState->mode)
    {
    case MODE_MOVES:
        AddTextPrinterParameterized4(WIN_MODE,
                                     FONT_NORMAL,
                                     TarcUi_JustifyCenter(sTextMoves, 80, FONT_NORMAL), 0, 0 ,0,
                                     sTarcUiWindowFontColors[FONT_BLACK],
                                     TEXT_SKIP_DRAW,
                                     sTextMoves);
        break;
    case MODE_ABILITIES:
        AddTextPrinterParameterized4(WIN_MODE,
                                     FONT_NORMAL,
                                     TarcUi_JustifyCenter(sTextAbilities, 80, FONT_NORMAL), 0, 0 ,0,
                                     sTarcUiWindowFontColors[FONT_BLACK],
                                     TEXT_SKIP_DRAW,
                                     sTextAbilities);
        break;
    }
    CopyWindowToVram(WIN_MODE, COPYWIN_GFX);
}

static void PrintMove(u32 window, u32 move)
{
    FillWindowPixelBuffer(window, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    if (move == MOVE_NONE)
    {
        CopyWindowToVram(window, COPYWIN_GFX);
        return;
    }

    const u8 *str = gMovesInfo[move].name;
    AddTextPrinterParameterized4(window,
                                 GetFontIdToFit(str, FONT_NORMAL, 0, 64),
                                 0, 0, 0 ,0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 str);
    CopyWindowToVram(window, COPYWIN_GFX);
}

static void PrintAbility(u32 window, u32 ability)
{
    FillWindowPixelBuffer(window, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    if (ability == ABILITY_NONE)
    {
        CopyWindowToVram(window, COPYWIN_GFX);
        return;
    }

    const u8 *str = gAbilitiesInfo[ability].name;
    AddTextPrinterParameterized4(window,
                                 GetFontIdToFit(str, FONT_NORMAL, 0, 64),
                                 0, 0, 0 ,0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 str);
    CopyWindowToVram(window, COPYWIN_GFX);
}

static void TarcUi_PrintMon(void)
{
    u32 activeMon = sTarcUiState->activeMon;
    //  Print mon
    if (sTarcUiState->hasMonSprite)
    {
        //  Remove existing sprite
        DestroySprite(&gSprites[sTarcUiState->monSpriteId]);
        FreeSpriteTilesByTag(0xCEC1);
        FreeSpritePaletteByTag(0xCEC1);
    }
    sTarcUiState->hasMonSprite = TRUE;

    //  Show new mon sprite
    struct Even_CreateSpriteStruct cs = {0};
    u32 species = GetMonData(&gPlayerParty[sTarcUiState->activeMon], MON_DATA_SPECIES);
    cs.sprite = gSpeciesInfo[species].frontPic;
    cs.tileTag = 0xCEC1;
    cs.spriteCompressed = TRUE;
    if (GetMonData(&gPlayerParty[sTarcUiState->activeMon], MON_DATA_IS_SHINY))
        cs.palette = gSpeciesInfo[species].shinyPalette;
    else
        cs.palette = gSpeciesInfo[species].palette;
    cs.palTag = 0xCEC1;
    cs.spriteSize = SPRITE_SIZE(64x64);
    cs.spriteShape = SPRITE_SHAPE(64x64);
    cs.posX = 32;
    cs.posY = 128;
    sTarcUiState->monSpriteId = Even_CreateSprite(&cs);

    //  Print mon stats
    FillWindowPixelBuffer(WIN_HP, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WIN_ATK, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WIN_DEF, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WIN_SPA, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WIN_SPD, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WIN_SPE, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    u8 tempStr[10];
    ConvertIntToDecimalStringN(tempStr, sTarcUiState->mons[sTarcUiState->activeMon].hp, STR_CONV_MODE_LEFT_ALIGN, 3);
    u32 currChar = 0;
    while (tempStr[currChar] != EOS)
        currChar++;
    tempStr[currChar++] = CHAR_SLASH;
    ConvertIntToDecimalStringN(&tempStr[currChar], sTarcUiState->mons[sTarcUiState->activeMon].maxHP, STR_CONV_MODE_LEFT_ALIGN, 3);

    AddTextPrinterParameterized4(WIN_HP,
                                 FONT_NORMAL,
                                 GetStringRightAlignXOffset(FONT_NORMAL, tempStr, 71), 0, 0 ,0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 tempStr);
    CopyWindowToVram(WIN_HP, COPYWIN_GFX);

    ConvertIntToDecimalStringN(tempStr, sTarcUiState->mons[sTarcUiState->activeMon].atk, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(WIN_ATK,
                                 FONT_NORMAL,
                                 GetStringRightAlignXOffset(FONT_NORMAL, tempStr, 47), 0, 0 ,0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 tempStr);
    CopyWindowToVram(WIN_ATK, COPYWIN_GFX);

    ConvertIntToDecimalStringN(tempStr, sTarcUiState->mons[sTarcUiState->activeMon].def, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(WIN_DEF,
                                 FONT_NORMAL,
                                 GetStringRightAlignXOffset(FONT_NORMAL, tempStr, 47), 0, 0 ,0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 tempStr);
    CopyWindowToVram(WIN_DEF, COPYWIN_GFX);

    ConvertIntToDecimalStringN(tempStr, sTarcUiState->mons[sTarcUiState->activeMon].spa, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(WIN_SPA,
                                 FONT_NORMAL,
                                 GetStringRightAlignXOffset(FONT_NORMAL, tempStr, 47), 0, 0 ,0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 tempStr);
    CopyWindowToVram(WIN_SPA, COPYWIN_GFX);

    ConvertIntToDecimalStringN(tempStr, sTarcUiState->mons[sTarcUiState->activeMon].spd, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(WIN_SPD,
                                 FONT_NORMAL,
                                 GetStringRightAlignXOffset(FONT_NORMAL, tempStr, 47), 0, 0 ,0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 tempStr);
    CopyWindowToVram(WIN_SPD, COPYWIN_GFX);

    ConvertIntToDecimalStringN(tempStr, sTarcUiState->mons[sTarcUiState->activeMon].spe, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized4(WIN_SPE,
                                 FONT_NORMAL,
                                 GetStringRightAlignXOffset(FONT_NORMAL, tempStr, 47), 0, 0 ,0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 tempStr);
    CopyWindowToVram(WIN_SPE, COPYWIN_GFX);

    //  Print mon moves/abilities
    switch (sTarcUiState->mode)
    {
    case MODE_MOVES:
        for (u32 i = 0; i < 4; i++)
            PrintMove(WIN_SELECT1 + i, sTarcUiState->mons[activeMon].moves[i]);
        break;
    case MODE_ABILITIES:
        for (u32 i = 0; i < 4; i++)
            PrintAbility(WIN_SELECT1 + i, sTarcUiState->mons[activeMon].abilities[i]);
        break;
    }
}

static const u8 sButtonHints[] = _("L/R Change mon : {DPAD_NONE} Cursor : {A_BUTTON} Move Selection");

static void TarcUi_PrintButtonHints(void)
{
    FillWindowPixelBuffer(WIN_CONTROLLS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_CONTROLLS,
                                 FONT_SHORT_NARROWER,
                                 TarcUi_JustifyCenter(sButtonHints, 176, FONT_SHORT_NARROWER), 0, 0 ,0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 sButtonHints);
    CopyWindowToVram(WIN_CONTROLLS, COPYWIN_GFX);
}

static void TarcUi_PrintSelection(void)
{
    u32 currSelection;
    const u8 *origStr = gMovesInfo[MOVE_NONE].description;
    u32 listPos = sTarcUiState->scrollOffset + sTarcUiState->selectedRow;
    FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    switch (sTarcUiState->mode)
    {
    case MODE_MOVES:
        if (sTarcUiState->rightSelected)
            currSelection = sTarcUiState->mons[sTarcUiState->activeMon].moves[sTarcUiState->selectPos];
        else
            currSelection = gSaveBlock1Ptr->moveStorage[listPos];
        origStr = gMovesInfo[currSelection].description;
        break;
    case MODE_ABILITIES:
        if (sTarcUiState->rightSelected)
            currSelection = sTarcUiState->mons[sTarcUiState->activeMon].abilities[sTarcUiState->selectPos];
        else
            currSelection = gSaveBlock1Ptr->abilityStorage[listPos];
        origStr = gAbilitiesInfo[currSelection].description;
        break;
    }
    u32 currChar = 0;
    while (origStr[currChar] != EOS)
        currChar++;

    AddTextPrinterParameterized4(WIN_INFO,
                                 FONT_NORMAL,
                                 0, 0, 0 ,0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 origStr);
    CopyWindowToVram(WIN_INFO, COPYWIN_GFX);
}

static void TarcUi_UpdateSelector(void)
{
    u32 spriteId = sTarcUiState->selectorSpriteId;
    if (sTarcUiState->rightSelected)
    {
        u32 pos = sTarcUiState->selectPos;
        u32 posX = 92;
        u32 posY = 8;
        if (pos == 1 || pos == 3)
            posX += 72;
        if (pos > 1)
            posY += 16;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].x = posX;
        gSprites[spriteId].y = posY;
    }
    else
    {
        gSprites[spriteId].invisible = TRUE;
    }
}

static void TarcUi_InitSelector(void)
{
    struct Even_CreateSpriteStruct cs = {0};
    cs.sprite = sTarcSelectorGfx;
    cs.tileTag = 0xCEC2;
    cs.palette = sTarcSelectorPal;
    cs.palTag = 0xCEC2;
    cs.spriteSize = SPRITE_SIZE(8x16);
    cs.spriteShape = SPRITE_SHAPE(8x16);
    cs.posX = 92;
    cs.posY = 8;
    sTarcUiState->selectorSpriteId = Even_CreateSprite(&cs);
    gSprites[sTarcUiState->selectorSpriteId].invisible = TRUE;
}

static void TryMoveSelection(void)
{
    u32 activeMon = sTarcUiState->activeMon;
    u32 pos = sTarcUiState->selectPos;
    if (sTarcUiState->rightSelected)
    {
        if (sTarcUiState->mode == MODE_MOVES)
        {
            u32 numItems = 0;
            for (u32 i = 0; i < 4; i++)
            {
                if (sTarcUiState->mons[activeMon].moves[i] != MOVE_NONE)
                    numItems++;
            }

            if (numItems == 1)
            {
                PlaySE(SE_PC_OFF);
                return;
            }

            u32 storageIndex = 0;
            while (gSaveBlock1Ptr->moveStorage[storageIndex] != MOVE_NONE)
                storageIndex++;
            gSaveBlock1Ptr->moveStorage[storageIndex] = sTarcUiState->mons[activeMon].moves[pos];
            sTarcUiState->mons[activeMon].moves[pos] = MOVE_NONE;
        }
        else
        {
            if (pos == 0 || sTarcUiState->mons[activeMon].abilities[pos] == ABILITY_NONE)
            {
                PlaySE(SE_PC_OFF);
                return;
            }
            u32 storageIndex = 0;
            while (gSaveBlock1Ptr->abilityStorage[storageIndex] != MOVE_NONE)
                storageIndex++;
            gSaveBlock1Ptr->abilityStorage[storageIndex] = sTarcUiState->mons[activeMon].abilities[pos];
            sTarcUiState->mons[activeMon].abilities[pos] = MOVE_NONE;
        }
    }
    else
    {
        u32 listPos = sTarcUiState->scrollOffset + sTarcUiState->selectedRow;
        u32 numItems = 0;
        if (sTarcUiState->mode == MODE_MOVES)
        {
            for (u32 i = 0; i < 4; i++)
            {
                if (sTarcUiState->mons[activeMon].moves[i] != MOVE_NONE)
                    numItems++;
            }
            if (numItems == 4)
            {
                PlaySE(SE_PC_OFF);
                return;
            }
            u32 putIndex = 0;
            while (sTarcUiState->mons[activeMon].moves[putIndex] != MOVE_NONE)
                putIndex++;

            sTarcUiState->mons[activeMon].moves[putIndex] = gSaveBlock1Ptr->moveStorage[listPos];
            gSaveBlock1Ptr->moveStorage[listPos] = MOVE_NONE;
            numItems = CompactMoveStorage();
        }
        else
        {
            for (u32 i = 0; i < 4; i++)
            {
                if (sTarcUiState->mons[activeMon].abilities[i] != ABILITY_NONE)
                    numItems++;
            }
            if (numItems == 4)
            {
                PlaySE(SE_PC_OFF);
                return;
            }
            u32 putIndex = 0;
            while (sTarcUiState->mons[activeMon].abilities[putIndex] != ABILITY_NONE)
                putIndex++;

            sTarcUiState->mons[activeMon].abilities[putIndex] = gSaveBlock1Ptr->abilityStorage[listPos];
            gSaveBlock1Ptr->abilityStorage[listPos] = ABILITY_NONE;
            numItems = CompactAbilityStorage();
        }
        if (listPos == numItems && numItems != 0)
        {
            if (sTarcUiState->scrollOffset > 0)
                sTarcUiState->scrollOffset--;
            else
            {
                sTarcUiState->selectedRow--;
            }
        }
    }
    TarcUi_PrintMon();
    TarcUi_InitScrollList();
}

//  This can be improved, but I can't be arsed right now
static u32 CompactMoveStorage(void)
{
    u16 moves[36];
    u32 moveCount = 0;
    for (u32 i = 0; i < 36; i++)
    {
        if (gSaveBlock1Ptr->moveStorage[i] != MOVE_NONE)
        {
            moves[moveCount++] = gSaveBlock1Ptr->moveStorage[i];
            gSaveBlock1Ptr->moveStorage[i] = MOVE_NONE;
        }
    }

    for (u32 i = 0; i < moveCount; i++)
    {
        gSaveBlock1Ptr->moveStorage[i] = moves[i];
    }
    return moveCount;
}

static u32 CompactAbilityStorage(void)
{
    u16 abilities[9];
    u32 abilityCount = 0;
    for (u32 i = 0; i < 9; i++)
    {
        if (gSaveBlock1Ptr->abilityStorage[i] != ABILITY_NONE)
        {
            abilities[abilityCount++] = gSaveBlock1Ptr->abilityStorage[i];
            gSaveBlock1Ptr->abilityStorage[i] = ABILITY_NONE;
        }
    }

    for (u32 i = 0; i < abilityCount; i++)
    {
        gSaveBlock1Ptr->abilityStorage[i] = abilities[i];
    }
    return abilityCount;
}

static void Task_TarcUiWaitFadeAndExitGracefully(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sTarcUiState->savedCallback);
        TarcUi_WriteMonData();
        TarcUi_FreeResources();
        DestroyTask(taskId);
    }
}

static void TarcUi_WriteMonData(void)
{
    for (u32 monIndex = 0; monIndex < 3; monIndex++)
    {
        for (u32 moveIndex = 0; moveIndex < 4; moveIndex++)
        {
            SetMonData(&gPlayerParty[monIndex], MON_DATA_MOVE1 + moveIndex, &sTarcUiState->mons[monIndex].moves[moveIndex]);
        }
        for (u32 abilityIndex = 1; abilityIndex < 4; abilityIndex++)
        {
            gSaveBlock1Ptr->extraAbilities[monIndex][abilityIndex - 1] = sTarcUiState->mons[monIndex].abilities[abilityIndex];
        }
    }
}
