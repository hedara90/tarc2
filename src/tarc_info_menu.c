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
#include "tarc_info_menu.h"

#include "constants/abilities.h"
#include "constants/characters.h"
#include "constants/moves.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#include "constants/hunt_setup.h"

struct Tarc_InfoMenuState
{
    MainCallback savedCallback;
    u8 loadState;
    u8 hubSpriteIds[9];
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

struct BossIcon
{
    const u32 *sprite;
    const u16 *palette;
};

static EWRAM_DATA struct Tarc_InfoMenuState *sTarcUiState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

static const u32 sTarcTiles[] = INCBIN_U32("graphics/tarc_party/tarc_party_tiles.4bpp.lz");
static const u32 sTarcTilemap[] = INCBIN_U32("graphics/tarc_party/tarc_party_tiles.bin.lz");
static const u16 sTarcPalette[] = INCBIN_U16("graphics/tarc_party/tarc_party_tiles.gbapal");

static const u16 sTarcTextPal[] = INCBIN_U16("graphics/tarc_party/text.gbapal");

static const u32 sMythHubMapTiles[] = INCBIN_U32("graphics/tarc_info/myth_hub_map_tiles.4bpp.lz");
static const u32 sMythHubMapTilemap[] = INCBIN_U32("graphics/tarc_info/myth_hub_map_tiles.bin.lz");
static const u16 sMythHubMapPalette[] = INCBIN_U16("graphics/tarc_info/myth_hub_map_tiles.gbapal");

static const u32 sIconGfxPseudo[] = INCBIN_U32("graphics/tarc_info/icon_pseudo.4bpp");
static const u16 sIconPalPseudo[] = INCBIN_U16("graphics/tarc_info/icon_pseudo.gbapal");
static const u32 sIconGfxBirds[] = INCBIN_U32("graphics/tarc_info/icon_birds.4bpp");
static const u16 sIconPalBirds[] = INCBIN_U16("graphics/tarc_info/icon_birds.gbapal");
static const u32 sIconGfxBeasts[] = INCBIN_U32("graphics/tarc_info/icon_beasts.4bpp");
static const u16 sIconPalBeasts[] = INCBIN_U16("graphics/tarc_info/icon_beasts.gbapal");
static const u32 sIconGfxGolems[] = INCBIN_U32("graphics/tarc_info/icon_golems.4bpp");
static const u16 sIconPalGolems[] = INCBIN_U16("graphics/tarc_info/icon_golems.gbapal");
static const u32 sIconGfxLakes[] = INCBIN_U32("graphics/tarc_info/icon_lakes.4bpp");
static const u16 sIconPalLakes[] = INCBIN_U16("graphics/tarc_info/icon_lakes.gbapal");
static const u32 sIconGfxSwords[] = INCBIN_U32("graphics/tarc_info/icon_swords.4bpp");
static const u16 sIconPalSwords[] = INCBIN_U16("graphics/tarc_info/icon_swords.gbapal");
static const u32 sIconGfxGenies[] = INCBIN_U32("graphics/tarc_info/icon_genies.4bpp");
static const u16 sIconPalGenies[] = INCBIN_U16("graphics/tarc_info/icon_genies.gbapal");
static const u32 sIconGfxTapus[] = INCBIN_U32("graphics/tarc_info/icon_tapus.4bpp");
static const u16 sIconPalTapus[] = INCBIN_U16("graphics/tarc_info/icon_tapus.gbapal");
static const u32 sIconGfxTreasures[] = INCBIN_U32("graphics/tarc_info/icon_treasures.4bpp");
static const u16 sIconPalTreasures[] = INCBIN_U16("graphics/tarc_info/icon_treasures.gbapal");
static const u32 sIconGfxLoyal[] = INCBIN_U32("graphics/tarc_info/icon_loyal.4bpp");
static const u16 sIconPalLoyal[] = INCBIN_U16("graphics/tarc_info/icon_loyal.gbapal");
static const u32 sIconGfxGalarBirds[] = INCBIN_U32("graphics/tarc_info/icon_galar_birds.4bpp");
static const u16 sIconPalGalarBirds[] = INCBIN_U16("graphics/tarc_info/icon_galar_birds.gbapal");
static const u32 sIconGfxPast[] = INCBIN_U32("graphics/tarc_info/icon_paradox_past.4bpp");
static const u16 sIconPalPast[] = INCBIN_U16("graphics/tarc_info/icon_paradox_past.gbapal");
static const u32 sIconGfxFuture[] = INCBIN_U32("graphics/tarc_info/icon_paradox_future.4bpp");
static const u16 sIconPalFuture[] = INCBIN_U16("graphics/tarc_info/icon_paradox_future.gbapal");

static const struct BossIcon sBossIcons[] =
{
    [BOSS_BIRDS] = {sIconGfxBirds, sIconPalBirds},
    [BOSS_BEASTS] = {sIconGfxBeasts, sIconPalBeasts},
    [BOSS_GOLEMS] = {sIconGfxGolems, sIconPalGolems},
    [BOSS_LAKES] = {sIconGfxLakes, sIconPalLakes},
    [BOSS_SWORDS] = {sIconGfxSwords, sIconPalSwords},
    [BOSS_GENIES] = {sIconGfxGenies, sIconPalGenies},
    [BOSS_TAPUS] = {sIconGfxTapus, sIconPalTapus},
    [BOSS_TREASURES] = {sIconGfxTreasures, sIconPalTreasures},
    [BOSS_LOYAL] = {sIconGfxLoyal, sIconPalLoyal},
    [BOSS_GALAR_BIRDS] = {sIconGfxGalarBirds, sIconPalGalarBirds},
    [BOSS_PARADOX_BEASTS] = {sIconGfxPast, sIconPalPast},
    [BOSS_PARADOX_SWORDS] = {sIconGfxFuture, sIconPalFuture},
    [BOSS_PSEUDOS] = {sIconGfxPseudo, sIconPalPseudo},
};

static const u32 sBossIconCoords[9][2] =
{
    {203, 65},
    {184, 54},
    {100, 57},
    {80, 23},
    {49, 23},
    {79, 116},
    {50, 129},
    {109, 132},
    {73, 144},
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
#define INFO_HEIGHT 6
#define SUB_WIDTH   20
#define SUB_HEIGHT  4
#define CONTROLLS_WIDTH  22
#define CONTROLLS_HEIGHT 2
#define HP_WIDTH  8
#define HP_HEIGHT 2
#define STAT_WIDTH  5
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
        .tilemapLeft = 10,
        .tilemapTop = 8,
        .width = INFO_WIDTH,
        .height = INFO_HEIGHT,
        .paletteNum = 15,
        .baseBlock = INFO_BASEBLOCK
    },
    [WIN_SUB] =
    {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 4,
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
        .tilemapLeft = 10,
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
        .tilemapLeft = 23,
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
        .tilemapLeft = 23,
        .tilemapTop = 16,
        .width = STAT_WIDTH,
        .height = STAT_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SPD_BASEBLOCK
    },
    [WIN_SPE] =
    {
        .bg = 0,
        .tilemapLeft = 13,
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

static void Task_TarcUiWaitFadeAndExitGracefully(u8 taskId);

void Tarc_InitInfoScreen(MainCallback callback)
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

static void DrawHubStuff(void)
{
    for (u32 i = 0; i < 9; i++)
    {
        if (gSaveBlock1Ptr->huntTargets.bossesDefeated[i])
        {
            sTarcUiState->hubSpriteIds[i] = SPRITE_NONE;
        }
        else
        {
            struct Even_CreateSpriteStruct cs = {0};
            if (i == 0)
                cs.sprite = sBossIcons[BOSS_PSEUDOS].sprite;
            else
                cs.sprite = sBossIcons[gSaveBlock1Ptr->huntTargets.bosses[i]].sprite;
            cs.tileTag = 0xCEC1 + i;
            if (i == 0)
                cs.palette = sBossIcons[BOSS_PSEUDOS].palette;
            else
                cs.palette = sBossIcons[gSaveBlock1Ptr->huntTargets.bosses[i]].palette;
            cs.palTag = 0xCEC1 + i;
            cs.spriteSize = SPRITE_SIZE(16x16);
            cs.spriteShape = SPRITE_SHAPE(16x16);
            cs.posX = sBossIconCoords[i][0];
            cs.posY = sBossIconCoords[i][1];
            sTarcUiState->hubSpriteIds[i] = Even_CreateSprite(&cs);
        }
    }
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
        if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_ENTRANCE))
            TarcUi_InitWindows();
        gMain.state++;
        break;
    case 5:
        if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_MYTH_HUB))
            DrawHubStuff();
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

        switch (gSaveBlock1Ptr->location.mapNum)
        {
        case MAP_NUM(MAP_ENTRANCE):
            //  Info screen
            break;
        //  Maps
        case MAP_NUM(MAP_MYTH_HUB):
            DecompressAndCopyTileDataToVram(1, sMythHubMapTiles, 0, 0, 0);
            break;
        case MAP_NUM(MAP_AREA1):
            break;
        case MAP_NUM(MAP_AREA2):
            break;
        case MAP_NUM(MAP_AREA3):
            break;
        case MAP_NUM(MAP_AREA4):
            break;
        case MAP_NUM(MAP_AREA5):
            break;
        case MAP_NUM(MAP_AREA6):
            break;
        case MAP_NUM(MAP_AREA7):
            break;
        case MAP_NUM(MAP_AREA8):
            break;
        case MAP_NUM(MAP_AREA9):
            break;
        case MAP_NUM(MAP_BOSS):
            break;
        }
        sTarcUiState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            switch (gSaveBlock1Ptr->location.mapNum)
            {
            case MAP_NUM(MAP_ENTRANCE):
                //  Info screen
                break;
            //  Maps
            case MAP_NUM(MAP_MYTH_HUB):
                LZDecompressWram(sMythHubMapTilemap, sBg1TilemapBuffer);
                break;
            case MAP_NUM(MAP_AREA1):
                break;
            case MAP_NUM(MAP_AREA2):
                break;
            case MAP_NUM(MAP_AREA3):
                break;
            case MAP_NUM(MAP_AREA4):
                break;
            case MAP_NUM(MAP_AREA5):
                break;
            case MAP_NUM(MAP_AREA6):
                break;
            case MAP_NUM(MAP_AREA7):
                break;
            case MAP_NUM(MAP_AREA8):
                break;
            case MAP_NUM(MAP_AREA9):
                break;
            case MAP_NUM(MAP_BOSS):
                break;
            }
            sTarcUiState->loadState++;
        }
        break;
    case 2:
        switch (gSaveBlock1Ptr->location.mapNum)
        {
        case MAP_NUM(MAP_ENTRANCE):
            //  Info screen
            break;
        //  Maps
        case MAP_NUM(MAP_MYTH_HUB):
            LoadPalette(sMythHubMapPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
            break;
        case MAP_NUM(MAP_AREA1):
            break;
        case MAP_NUM(MAP_AREA2):
            break;
        case MAP_NUM(MAP_AREA3):
            break;
        case MAP_NUM(MAP_AREA4):
            break;
        case MAP_NUM(MAP_AREA5):
            break;
        case MAP_NUM(MAP_AREA6):
            break;
        case MAP_NUM(MAP_AREA7):
            break;
        case MAP_NUM(MAP_AREA8):
            break;
        case MAP_NUM(MAP_AREA9):
            break;
        case MAP_NUM(MAP_BOSS):
            break;
        }
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
        SetMainCallback2(sTarcUiState->savedCallback);
        TarcUi_FreeResources();
        DestroyTask(taskId);
    }
}

void CB2_InfoScreenFromStartMenu(void)
{
    Tarc_InitInfoScreen(CB2_ReturnToFieldWithOpenMenu);
}
