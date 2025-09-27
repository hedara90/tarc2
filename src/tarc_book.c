#include "gba/types.h"
#include "bg.h"
#include "decompress.h"
#include "even_sprite.h"
#include "global.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "line_break.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "move.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "window.h"
#include "tarc_book.h"
#include "pokemon_icon.h"

#include "constants/abilities.h"
#include "constants/characters.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#include "palette.h"

#include "tarc_debug.h"

#include "data/tarc_book.h"

struct Tarc_BookState
{
    MainCallback savedCallback;
    u8 loadState;
    u8 spriteId;
    enum BookPages currentPage;
};

enum WindowIds
{
    WIN_TITLE,
    WIN_LEFT_PAGE,
    WIN_RIGHT_PAGE,
    WIN_COUNT
};

static EWRAM_DATA struct Tarc_BookState *sTarcUiState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

static const u32 sTarcBookTiles[] = INCBIN_U32("graphics/book/book_bg_tiles.4bpp.lz");
static const u32 sTarcBookTilemap[] = INCBIN_U32("graphics/book/book_bg_tiles.bin.lz");
static const u16 sTarcBookPalette[] = INCBIN_U16("graphics/book/book_bg_tiles.gbapal");

static const u16 sTarcTextPal[] = INCBIN_U16("graphics/tarc_party/text.gbapal");

static const struct BgTemplate sTarcUiBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 22,
        .priority = 1
    },
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 20,
        .priority = 2
    }
};

#define TITLE_WIDTH 12
#define TITLE_HEIGHT 2
#define LEFT_WIDTH 12
#define LEFT_HEIGHT 17
#define RIGHT_WIDTH 12
#define RIGHT_HEIGHT 19

#define TITLE_SIZE TITLE_WIDTH * TITLE_HEIGHT
#define LEFT_SIZE LEFT_WIDTH * LEFT_HEIGHT
#define RIGHT_SIZE RIGHT_WIDTH * RIGHT_HEIGHT

#define TITLE_BASEBLOCK 1
#define LEFT_BASEBLOCK TITLE_BASEBLOCK + TITLE_SIZE
#define RIGHT_BASEBLOCK LEFT_BASEBLOCK + LEFT_SIZE

static const struct WindowTemplate sTarcUiWindowTemplates[] =
{
    [WIN_TITLE] =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = TITLE_WIDTH,
        .height = TITLE_HEIGHT,
        .paletteNum = 15,
        .baseBlock = TITLE_BASEBLOCK
    },
    [WIN_LEFT_PAGE] =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = LEFT_WIDTH,
        .height = LEFT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = LEFT_BASEBLOCK
    },
    [WIN_RIGHT_PAGE] =
    {
        .bg = 0,
        .tilemapLeft = 16,
        .tilemapTop = 1,
        .width = RIGHT_WIDTH,
        .height = RIGHT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = RIGHT_BASEBLOCK
    },
};

enum FontColor
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_FADED,
    FONT_BLUE,
};

static const u8 sTarcUiWindowFontColors[][3] =
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT, 3,  4},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT, 1,  2},
    [FONT_FADED]    = {TEXT_COLOR_TRANSPARENT, 5,  6},
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
static u32 TarcUi_JustifyCenter(const u8 *input, u32 width, u8 fontId);

static void DrawAll(void);
//static void DrawSprite(void);
static void DrawLeftText(void);
static void DrawRightText(void);
static void RemoveSprite(void);

static void Task_TarcUiWaitFadeAndExitGracefully(u8 taskId);

void Tarc_InitBookScreen(MainCallback callback, enum BookPages page)
{
    sTarcUiState = AllocZeroed(sizeof(struct Tarc_BookState));
    if (sTarcUiState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sTarcUiState->savedCallback = callback;
    sTarcUiState->loadState = 0;
    sTarcUiState->currentPage = page;
    sTarcUiState->spriteId = SPRITE_NONE;

    SetMainCallback2(TarcUi_SetupCB);
}

void Tarc_InitBookScreenFromScript(struct ScriptContext *ctx)
{
    enum BookPages page = ScriptReadWord(ctx);
    Tarc_InitBookScreen(CB2_ReturnToFieldContinueScriptPlayMapMusic, page);
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
        DrawLeftText();
        gMain.state++;
        break;
    case 6:
        DrawRightText();
        gMain.state++;
        break;
    case 7:
        CreateTask(Task_TarcUiWaitFadeIn, 0);
        //DrawSprite();
        gMain.state++;
        break;
    case 8:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 9:
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
        DecompressAndCopyTileDataToVram(1, sTarcBookTiles, 0, 0, 0);
        sTarcUiState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sTarcBookTilemap, sBg1TilemapBuffer);
            sTarcUiState->loadState++;
        }
        break;
    case 2:
        LoadPalette(sTarcBookPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP * 4);
        LoadPalette(sTarcTextPal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
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
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_TarcUiWaitFadeAndExitGracefully;
    }
    else if (JOY_NEW(L_BUTTON))
    {
        //  Load .goLeft
        if (sAllPages[sTarcUiState->currentPage].goLeft != PAGE_NONE)
        {
            //RemoveSprite();
            sTarcUiState->currentPage = sAllPages[sTarcUiState->currentPage].goLeft;
            DrawAll();
        }
        else
        {
            PlaySE(SE_WALL_HIT);
        }
    }
    else if (JOY_NEW(R_BUTTON))
    {
        //  Load .goRighRight
        if (sAllPages[sTarcUiState->currentPage].goRight != PAGE_NONE)
        {
            //RemoveSprite();
            sTarcUiState->currentPage = sAllPages[sTarcUiState->currentPage].goRight;
            DrawAll();
        }
        else
        {
            PlaySE(SE_WALL_HIT);
        }
    }
}

static u32 TarcUi_JustifyCenter(const u8 *input, u32 width, u8 fontId)
{
    u32 currWidth = GetStringWidth(fontId, input, 0);
    if (currWidth < width)
        return (width - currWidth) >> 1;
    else
        return 0;
}

static void Task_TarcUiWaitFadeAndExitGracefully(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sTarcUiState->savedCallback);
        TarcUi_FreeResources();
        DestroyTask(taskId);
    }
}

//  For some reason sprites are just broken
/*
static void DrawSprite()
{
    if (sAllPages[sTarcUiState->currentPage].spriteType != SPRITE_TYPE_NONE)
    {
        if (sAllPages[sTarcUiState->currentPage].spriteType == SPRITE_TYPE_MON)
        {
            struct Even_CreateSpriteStruct cs = {0};
            cs.sprite = gSpeciesInfo[sAllPages[sTarcUiState->currentPage].species].frontPic;
            cs.palette = gSpeciesInfo[sAllPages[sTarcUiState->currentPage].species].palette;
            cs.spriteCompressed = TRUE;
            cs.tileTag = 0xCEC1;
            cs.palTag = 0xCEC1;
            cs.spriteSize = SPRITE_SIZE(64x64);
            cs.spriteShape = SPRITE_SHAPE(64x64);
            cs.posX = 64;
            cs.posY = 54;
            sTarcUiState->spriteId = Even_CreateSprite(&cs);
            gSprites[sTarcUiState->spriteId].oam.priority = 0;
        }
        else if (sAllPages[sTarcUiState->currentPage].spriteType == SPRITE_TYPE_DIRECT)
        {
            struct Even_CreateSpriteStruct cs = {0};
            cs.sprite = sAllPages[sTarcUiState->currentPage].sprite;
            cs.palette = sAllPages[sTarcUiState->currentPage].palette;
            cs.spriteCompressed = sAllPages[sTarcUiState->currentPage].compressed;
            cs.tileTag = 0xCEC1;
            cs.palTag = 0xCEC1;
            cs.spriteSize = SPRITE_SIZE(64x64);
            cs.spriteShape = SPRITE_SHAPE(64x64);
            cs.posX = 64;
            cs.posY = 54;
            sTarcUiState->spriteId = Even_CreateSprite(&cs);
            gSprites[sTarcUiState->spriteId].oam.priority = 0;
        }
    }
}
*/

static void DrawLeftText()
{
    u8 pageText[500];
    //  Draw title
    const u8 *currString = sAllPages[sTarcUiState->currentPage].pageTitle;
    FillWindowPixelBuffer(WIN_TITLE, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_TITLE,
                                 FONT_NORMAL,
                                 TarcUi_JustifyCenter(currString, TITLE_WIDTH * 8, FONT_NORMAL), 0, 0, 0,
                                 sTarcUiWindowFontColors[FONT_WHITE],
                                 TEXT_SKIP_DRAW,
                                 currString);
    CopyWindowToVram(WIN_TITLE, COPYWIN_GFX);
    //  Draw left side
    u32 fontToUse = FONT_SMALL_NARROWER;
    u32 currChar = 0;
    u32 startOffset = 0;
    /*
    if (sAllPages[sTarcUiState->currentPage].spriteType != SPRITE_TYPE_NONE)
    {
        pageText[0] = CHAR_NEWLINE;
        pageText[1] = CHAR_NEWLINE;
        pageText[2] = CHAR_NEWLINE;
        pageText[3] = CHAR_NEWLINE;
        pageText[4] = CHAR_NEWLINE;
        pageText[5] = CHAR_NEWLINE;
        currChar = 6;
        startOffset = 6;
    }
    */
    u32 tempChar = 0;
    while (sAllPages[sTarcUiState->currentPage].leftPage[tempChar] != EOS)
    {
        pageText[currChar] = sAllPages[sTarcUiState->currentPage].leftPage[tempChar];
        currChar++;
        tempChar++;
    }
    pageText[currChar] = EOS;
    BreakStringAutomaticBook(&(pageText[startOffset]), 96, 30, fontToUse, HIDE_SCROLL_PROMPT);
    FillWindowPixelBuffer(WIN_LEFT_PAGE, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_LEFT_PAGE,
                                 fontToUse,
                                 0, 0, 0, 0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 pageText);
    CopyWindowToVram(WIN_LEFT_PAGE, COPYWIN_GFX);
}

static void DrawRightText(void)
{
    u32 fontToUse = FONT_SMALL_NARROWER;
    u8 pageText[500];
    //  Draw right side
    u32 currChar = 0;
    while (sAllPages[sTarcUiState->currentPage].rightPage[currChar] != EOS)
    {
        pageText[currChar] = sAllPages[sTarcUiState->currentPage].rightPage[currChar];
        currChar++;
    }
    pageText[currChar] = EOS;
    BreakStringAutomaticBook(pageText, 96, 30, fontToUse, HIDE_SCROLL_PROMPT);
    FillWindowPixelBuffer(WIN_RIGHT_PAGE, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_RIGHT_PAGE,
                                 fontToUse,
                                 0, 0, 0, 0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 pageText);
    CopyWindowToVram(WIN_RIGHT_PAGE, COPYWIN_GFX);
}

//  For some reason sprites are just broken
/*
static void RemoveSprite(void)
{
    if (sTarcUiState->spriteId != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sTarcUiState->spriteId]);
        FreeSpriteTilesByTag(0xCEC1);
        FreeSpritePaletteByTag(0xCEC1);

        sTarcUiState->spriteId = SPRITE_NONE;
    }
}
*/

static void DrawAll(void)
{
    DrawLeftText();
    DrawRightText();
    //DrawSprite();
}
