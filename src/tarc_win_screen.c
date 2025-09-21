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
#include "tarc_win_screen.h"
#include "pokemon_icon.h"

#include "constants/abilities.h"
#include "constants/characters.h"
#include "constants/moves.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#include "constants/hunt_setup.h"
#include "hunt_setup.h"
#include "data/hunt_setup_data.h"

#include "palette.h"
#include "constants/map_event_ids.h"
#include "constants/event_object_movement.h"
#include "overworld.h"
#include "random.h"


struct Tarc_InfoMenuState
{
    MainCallback savedCallback;
    u8 loadState;
};

struct Tarc_BossWinBackground
{
    const u32 *tiles;
    const u32 *tilemap;
    const u16 *palette;
};

enum WindowIds
{
    WIN_TITLE,
    WIN_MOVE1,
    WIN_ABI1,
    WIN_MOVE2,
    WIN_ABI2,
    WIN_MOVE3,
    WIN_ABI3,
    WIN_COUNT
};

static EWRAM_DATA struct Tarc_InfoMenuState *sTarcUiState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

static const u32 sTarcInfoTiles[] = INCBIN_U32("graphics/tarc_win/tarc_win_tiles.4bpp.lz");
static const u32 sTarcInfoTilemap[] = INCBIN_U32("graphics/tarc_win/tarc_win_tiles.bin.lz");
static const u16 sTarcInfoPalette[] = INCBIN_U16("graphics/tarc_win/tarc_win_tiles.gbapal");

static const u32 sTarcTiles_Xerneas[] = INCBIN_U32("graphics/tarc_win/win_xerneas_tiles.4bpp.lz");
static const u32 sTarcTilemap_Xerneas[] = INCBIN_U32("graphics/tarc_win/win_xerneas_tiles.bin.lz");
static const u16 sTarcPalette_Xerneas[] = INCBIN_U16("graphics/tarc_win/win_xerneas_tiles.gbapal");

static const struct Tarc_BossWinBackground sBossBG[] =
{
    [FINAL_BOSS_XERNEAS] =
    {
        .tiles = sTarcTiles_Xerneas,
        .tilemap = sTarcTilemap_Xerneas,
        .palette = sTarcPalette_Xerneas,
    }
};

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

#define TITLE_WIDTH 30
#define TITLE_HEIGHT 2
#define INFO_WIDTH 9
#define INFO_HEIGHT 6

#define TITLE_SIZE TITLE_WIDTH * TITLE_HEIGHT
#define INFO_SIZE INFO_WIDTH * INFO_HEIGHT

#define TITLE_BASEBLOCK 1
#define MOVE1_BASEBLOCK     TITLE_BASEBLOCK + TITLE_SIZE
#define ABI1_BASEBLOCK      MOVE1_BASEBLOCK + INFO_SIZE
#define MOVE2_BASEBLOCK     ABI1_BASEBLOCK + INFO_SIZE
#define ABI2_BASEBLOCK      MOVE2_BASEBLOCK + INFO_SIZE
#define MOVE3_BASEBLOCK     ABI2_BASEBLOCK + INFO_SIZE
#define ABI3_BASEBLOCK      MOVE3_BASEBLOCK + INFO_SIZE

static const struct WindowTemplate sTarcUiWindowTemplates[] =
{
    [WIN_TITLE] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = TITLE_WIDTH,
        .height = TITLE_HEIGHT,
        .paletteNum = 15,
        .baseBlock = TITLE_BASEBLOCK
    },    
    [WIN_MOVE1] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 10,
        .width = INFO_WIDTH,
        .height = INFO_HEIGHT,
        .paletteNum = 15,
        .baseBlock = MOVE1_BASEBLOCK
    },
    [WIN_ABI1] =
    {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 10,
        .width = INFO_WIDTH,
        .height = INFO_HEIGHT,
        .paletteNum = 15,
        .baseBlock = ABI1_BASEBLOCK
    },
    [WIN_MOVE2] =
    {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 10,
        .width = INFO_WIDTH,
        .height = INFO_HEIGHT,
        .paletteNum = 15,
        .baseBlock = MOVE2_BASEBLOCK
    },
    [WIN_ABI2] =
    {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 10,
        .width = INFO_WIDTH,
        .height = INFO_HEIGHT,
        .paletteNum = 15,
        .baseBlock = ABI2_BASEBLOCK
    },
    [WIN_MOVE3] =
    {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 10,
        .width = INFO_WIDTH,
        .height = INFO_HEIGHT,
        .paletteNum = 15,
        .baseBlock = MOVE3_BASEBLOCK
    },
    [WIN_ABI3] =
    {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 10,
        .width = INFO_WIDTH,
        .height = INFO_HEIGHT,
        .paletteNum = 15,
        .baseBlock = ABI3_BASEBLOCK
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
static void DrawSprites(void);
static void DrawText(void);

static void Task_TarcUiWaitFadeAndExitGracefully(u8 taskId);

void Tarc_InitWinScreen(MainCallback callback)
{
    sTarcUiState = AllocZeroed(sizeof(struct Tarc_InfoMenuState));
    if (sTarcUiState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sTarcUiState->savedCallback = callback;
    sTarcUiState->loadState = 0;

    SetMainCallback2(TarcUi_SetupCB);
}

void Tarc_InitWinScreenFromScript(void)
{
    Tarc_InitWinScreen(CB2_ReturnToFieldContinueScriptPlayMapMusic);
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
        DrawText();
        gMain.state++;
        break;
    case 5:
        //  Draw stuff
        DrawSprites();
        CreateTask(Task_TarcUiWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITE);
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
    u32 bossId = gSaveBlock1Ptr->huntTargets.finalBoss;
    switch (sTarcUiState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sBossBG[bossId].tiles, 0, 0, 0);
        sTarcUiState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sBossBG[bossId].tilemap, sBg1TilemapBuffer);
            sTarcUiState->loadState++;
        }
        break;
    case 2:
        LoadPalette(sBossBG[bossId].palette, BG_PLTT_ID(0), PLTT_SIZE_4BPP * 4);
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
        TarcUi_FreeResources();
        DestroyTask(taskId);
        ResetInitialPlayerAvatarState();
        WarpIntoMap();
        SetMainCallback2(CB2_LoadMap);
    }
}

static const u8 *const sMythNames[] =
{
    COMPOUND_STRING("Life of Xerneas"),
    COMPOUND_STRING("Storm of Lugia"),
    COMPOUND_STRING("Shadow of Giratina"),
};

static void PrintMythName(u32 bossId)
{
    const u8 *currString = sMythNames[bossId];
    FillWindowPixelBuffer(WIN_TITLE, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_TITLE,
                                 FONT_NORMAL,
                                 TarcUi_JustifyCenter(currString, TITLE_WIDTH * 8, FONT_NORMAL), 0, 0, 0,
                                 sTarcUiWindowFontColors[FONT_WHITE],
                                 TEXT_SKIP_DRAW,
                                 currString);
    CopyWindowToVram(WIN_TITLE, COPYWIN_GFX);
}

static void DrawSprites(void)
{
    u32 bossId = gSaveBlock1Ptr->huntTargets.finalBoss;
    PrintMythName(bossId);
    for (u32 i = 0; i  < 3; i++)
    {
        u32 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        struct Even_CreateSpriteStruct cs = {0};
        cs.spriteCompressed = FALSE;
        cs.tileTag = 0xCEC1 + i;
        cs.palTag = 0xCEC1 + i;
        cs.sprite = gSpeciesInfo[species].portraitPic;
        cs.palette = gSpeciesInfo[species].portraitPal;
        cs.spriteSize = SPRITE_SIZE(64x64);
        cs.spriteShape = SPRITE_SHAPE(64x64);
        cs.posX = 40 + i * 80;
        cs.posY = 48;
        Even_CreateSprite(&cs);
    }
}

static void DrawText()
{
    for (u32 i = 0; i < 3; i++)
    {
        u32 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        u8 text[200];
        u32 currChar = 0;
        for (u32 j = 0; j < 4; j++)
        {
            u32 move = GetMonData(&gPlayerParty[j], MON_DATA_MOVE1 + j);
            if (move == MOVE_NONE)
            {
                text[currChar++] = CHAR_NEWLINE;
                continue;
            }
            u32 tempChar = 0;
            while (gMovesInfo[move].name[tempChar] != EOS)
                text[currChar++] = gMovesInfo[move].name[tempChar++];
            text[currChar++] = CHAR_NEWLINE;
        }
        u32 ability = gSpeciesInfo[species].abilities[GetMonData(&gPlayerParty[i], MON_DATA_ABILITY_NUM)];
        u32 tempChar = 0;
        while (gAbilitiesInfo[ability].name[tempChar] != EOS)
            text[currChar++] = gAbilitiesInfo[ability].name[tempChar++];
        text[currChar++] = CHAR_NEWLINE;

        for (u32 j = 0; j < 3; j++)
        {
            ability = gSaveBlock1Ptr->extraAbilities[i][j];
            if (ability == ABILITY_NONE)
                break;
            tempChar = 0;
            while (gAbilitiesInfo[ability].name[tempChar] != EOS)
                text[currChar++] = gAbilitiesInfo[ability].name[tempChar++];
            text[currChar++] = CHAR_NEWLINE;
        }
        text[currChar - 1] = EOS;
        AddTextPrinterParameterized4(WIN_INFO1 + i,
                                     FONT_SPECIAL_SMALL,
                                     8, 0, 0, 0,
                                     sTarcUiWindowFontColors[FONT_BLACK],
                                     TEXT_SKIP_DRAW,
                                     text);
        CopyWindowToVram(WIN_INFO1 + i, COPYWIN_FULL);
    }
}

static void DrawAll()
{
    DrawSprites();
    DrawText();
}

#include "data/tarc_fade_ids.h"

static void Task_FadeBoss(u8 taskId)
{
    //  Offset might have to be adjusted if the debug sprite is added
    u16 *tileStart = (u16 *)(OBJ_VRAM0 + 20 * TILE_SIZE_4BPP);

    for (u32 i = 0; i < 32; i++)
    {
        u32 currId = sFadeIds[gTasks[taskId].data[1] + i];
        u16 pixelMask = 0;
        switch (currId & 0x3)
        {
        case 0:
            pixelMask = 0xfff0;
            break;
        case 1:
            pixelMask = 0xff0f;
            break;
        case 2:
            pixelMask = 0xf0ff;
            break;
        case 3:
            pixelMask = 0x0fff;
            break;
        }
        tileStart[currId >> 2] = tileStart[currId >> 2] & pixelMask;
    }
    gTasks[taskId].data[1] += 32;

    gTasks[taskId].data[0]++;
    if (gTasks[taskId].data[0] == 128)
        DestroyTask(taskId);
}

void FadeBoss()
{
    u32 taskId = CreateTask(Task_FadeBoss, 0);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
}
