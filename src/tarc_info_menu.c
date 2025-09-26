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
#include "new_game.h"
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

#include "tarc_debug.h"

struct Tarc_InfoMenuState
{
    MainCallback savedCallback;
    u8 loadState;
    u8 hubSpriteIds[9];
    u8 finalBossSelector;
    u8 mode;
    u8 speciesSpriteId;
    u8 monIconSpriteIds[3];
};

enum DisplayModes
{
    MODE_TOTAL,
    MODE_WINS,
    MODE_LOSSES,
};

enum WindowIds
{
    WIN_NAME,
    WIN_RUNS,
    WIN_BESTRUN,
    WIN_MYTH_NAME,
    WIN_RAIN_STATS,
    WIN_SUN_STATS,
    WIN_SNOW_STATS,
    WIN_SAND_STATS,
    WIN_STAT_TITLE,
    WIN_STAT_NUMBER,
    WIN_COUNT
};

enum OtherWindowIds
{
    WIN_BOSS_TEXT,
    WIN_MINI1_TEXT,
    WIN_MINI2_TEXT,
    WIN_MINI3_TEXT,
    WIN_COUNT_OTHER
};

struct BossIcon
{
    const u32 *sprite;
    const u16 *palette;
};

static EWRAM_DATA struct Tarc_InfoMenuState *sTarcUiState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

static const u32 sTarcInfoTiles[] = INCBIN_U32("graphics/tarc_info/info_bg_tiles.4bpp.lz");
static const u32 sTarcInfoTilemap[] = INCBIN_U32("graphics/tarc_info/info_bg_tiles.bin.lz");
static const u16 sTarcInfoPalette[] = INCBIN_U16("graphics/tarc_info/info_bg_tiles.gbapal");

static const u16 sTarcTextPal[] = INCBIN_U16("graphics/tarc_party/text.gbapal");

static const u32 sMythHubMapTiles[] = INCBIN_U32("graphics/tarc_info/myth_hub_map_tiles.4bpp.lz");
static const u32 sMythHubMapTilemap[] = INCBIN_U32("graphics/tarc_info/myth_hub_map_tiles.bin.lz");
static const u16 sMythHubMapPalette[] = INCBIN_U16("graphics/tarc_info/myth_hub_map_tiles.gbapal");

static const u32 sSubAreaMapTiles[] = INCBIN_U32("graphics/tarc_info/sub_area_tiles.4bpp.lz");
static const u32 sSubAreaMapTilemap[] = INCBIN_U32("graphics/tarc_info/sub_area_tiles.bin.lz");
static const u16 sSubAreaMapPalette[] = INCBIN_U16("graphics/tarc_info/sub_area_tiles.gbapal");

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
    {224, 64},
    {192, 54},
    {96, 55},
    {80, 27},
    {40, 22},
    {80, 104},
    {40, 96},
    {112, 120},
    {56, 127},
};

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

#define NAME_WIDTH 8
#define NAME_HEIGHT 2
#define RUNS_WIDTH 8
#define RUNS_HEIGHT 2
#define BESTRUN_WIDTH 4
#define BESTRUN_HEIGHT 2
#define MYTH_NAME_WIDTH 20
#define MYTH_NAME_HEIGHT 2
#define RAIN_STATS_WIDTH 3
#define RAIN_STATS_HEIGHT 6
#define SUN_STATS_WIDTH 3
#define SUN_STATS_HEIGHT 6
#define SNOW_STATS_WIDTH 3
#define SNOW_STATS_HEIGHT 6
#define SAND_STATS_WIDTH 3
#define SAND_STATS_HEIGHT 6
#define STAT_TITLE_WIDTH 6
#define STAT_TITLE_HEIGHT 2
#define STAT_NUMBER_WIDTH 6
#define STAT_NUMBER_HEIGHT 2

#define NAME_SIZE NAME_WIDTH * NAME_HEIGHT
#define RUNS_SIZE RUNS_WIDTH * RUNS_HEIGHT
#define BESTRUN_SIZE BESTRUN_WIDTH * BESTRUN_HEIGHT
#define MYTH_NAME_SIZE MYTH_NAME_WIDTH * MYTH_NAME_HEIGHT
#define RAIN_STATS_SIZE RAIN_STATS_WIDTH * RAIN_STATS_HEIGHT
#define SUN_STATS_SIZE RAIN_STATS_WIDTH * RAIN_STATS_HEIGHT
#define SNOW_STATS_SIZE SNOW_STATS_WIDTH * RAIN_STATS_HEIGHT
#define SAND_STATS_SIZE SAND_STATS_WIDTH * SAND_STATS_HEIGHT
#define STAT_TITLE_SIZE STAT_TITLE_WIDTH * STAT_TITLE_HEIGHT
#define STAT_NUMBER_SIZE STAT_NUMBER_WIDTH * STAT_NUMBER_HEIGHT

#define NAME_BASEBLOCK 1
#define RUNS_BASEBLOCK NAME_BASEBLOCK + NAME_SIZE
#define BESTRUN_BASEBLOCK RUNS_BASEBLOCK + RUNS_SIZE
#define MYTH_NAME_BASEBLOCK BESTRUN_BASEBLOCK + BESTRUN_SIZE
#define RAIN_STATS_BASEBLOCK MYTH_NAME_BASEBLOCK + MYTH_NAME_SIZE
#define SUN_STATS_BASEBLOCK RAIN_STATS_BASEBLOCK + RAIN_STATS_SIZE
#define SNOW_STATS_BASEBLOCK SUN_STATS_BASEBLOCK + SUN_STATS_SIZE
#define SAND_STATS_BASEBLOCK SNOW_STATS_BASEBLOCK + SNOW_STATS_SIZE
#define STAT_TITLE_BASEBLOCK SAND_STATS_BASEBLOCK + SAND_STATS_SIZE
#define STAT_NUMBER_BASEBLOCK STAT_TITLE_BASEBLOCK + STAT_TITLE_SIZE

static const struct WindowTemplate sTarcUiWindowTemplates[] =
{
    [WIN_NAME] =
    {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 1,
        .width = NAME_WIDTH,
        .height = NAME_HEIGHT,
        .paletteNum = 15,
        .baseBlock = NAME_BASEBLOCK,
    },
    [WIN_RUNS] =
    {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 3,
        .width = RUNS_WIDTH,
        .height = RUNS_HEIGHT,
        .paletteNum = 15,
        .baseBlock = RUNS_BASEBLOCK
    },
    [WIN_BESTRUN] =
    {
        .bg = 0,
        .tilemapLeft = 25,
        .tilemapTop = 11,
        .width = BESTRUN_WIDTH,
        .height = BESTRUN_HEIGHT,
        .paletteNum = 15,
        .baseBlock = BESTRUN_BASEBLOCK
    },
    [WIN_MYTH_NAME] =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = MYTH_NAME_WIDTH,
        .height = MYTH_NAME_HEIGHT,
        .paletteNum = 15,
        .baseBlock = MYTH_NAME_BASEBLOCK
    },
    [WIN_RAIN_STATS] =
    {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 14,
        .width = RAIN_STATS_WIDTH,
        .height = RAIN_STATS_HEIGHT,
        .paletteNum = 15,
        .baseBlock = RAIN_STATS_BASEBLOCK
    },
    [WIN_SUN_STATS] =
    {
        .bg = 0,
        .tilemapLeft = 5,
        .tilemapTop = 14,
        .width = SUN_STATS_WIDTH,
        .height = SUN_STATS_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SUN_STATS_BASEBLOCK
    },
    [WIN_SNOW_STATS] =
    {
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 14,
        .width = SNOW_STATS_WIDTH,
        .height = SNOW_STATS_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SNOW_STATS_BASEBLOCK
    },
    [WIN_SAND_STATS] =
    {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 14,
        .width = SAND_STATS_WIDTH,
        .height = SAND_STATS_HEIGHT,
        .paletteNum = 15,
        .baseBlock = SAND_STATS_BASEBLOCK
    },
    [WIN_STAT_TITLE] =
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 9,
        .width = STAT_TITLE_WIDTH,
        .height = STAT_TITLE_HEIGHT,
        .paletteNum = 15,
        .baseBlock = STAT_TITLE_BASEBLOCK
    },
    [WIN_STAT_NUMBER] =
    {
        .bg = 0,
        .tilemapLeft = 9,
        .tilemapTop = 9,
        .width = STAT_NUMBER_WIDTH,
        .height = STAT_NUMBER_HEIGHT,
        .paletteNum = 15,
        .baseBlock = STAT_NUMBER_BASEBLOCK
    },
    DUMMY_WIN_TEMPLATE
};

#define REWARD_WIDTH 10
#define REWARD_HEIGHT 2

#define REWARD_BOX_SIZE REWARD_WIDTH * REWARD_HEIGHT

#define BOSS_TEXT_BASEBLOCK 1
#define MINI1_TEXT_BASEBLOCK BOSS_TEXT_BASEBLOCK + REWARD_BOX_SIZE
#define MINI2_TEXT_BASEBLOCK MINI1_TEXT_BASEBLOCK + REWARD_BOX_SIZE
#define MINI3_TEXT_BASEBLOCK MINI2_TEXT_BASEBLOCK + REWARD_BOX_SIZE

static const struct WindowTemplate sTarcUiOtherWindowTemplates[] =
{
    [WIN_BOSS_TEXT] =
    {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 8,
        .width = REWARD_WIDTH,
        .height = REWARD_HEIGHT,
        .paletteNum = 15,
        .baseBlock = BOSS_TEXT_BASEBLOCK
    },
    [WIN_MINI1_TEXT] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 18,
        .width = REWARD_WIDTH,
        .height = REWARD_HEIGHT,
        .paletteNum = 15,
        .baseBlock = MINI1_TEXT_BASEBLOCK
    },
    [WIN_MINI2_TEXT] =
    {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 18,
        .width = REWARD_WIDTH,
        .height = REWARD_HEIGHT,
        .paletteNum = 15,
        .baseBlock = MINI2_TEXT_BASEBLOCK
    },
    [WIN_MINI3_TEXT] =
    {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 18,
        .width = REWARD_WIDTH,
        .height = REWARD_HEIGHT,
        .paletteNum = 15,
        .baseBlock = MINI3_TEXT_BASEBLOCK
    }
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
static void TarcUi_InitOtherWindows(void);
static void Task_TarcUiWaitFadeIn(u8 taskId);
static void Task_TarcUiMainInput(u8 taskId);
static u32 TarcUi_JustifyCenter(const u8 *input, u32 width, u8 fontId);
static void PrintAllInfoText(void);
static void DrawSubAreaStuff(void);

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
        sTarcUiState->speciesSpriteId = SPRITE_NONE;
        if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_ENTRANCE))
            TarcUi_InitWindows();
        else if (gSaveBlock1Ptr->location.mapNum != MAP_NUM(MAP_MYTH_HUB))
            TarcUi_InitOtherWindows();
        gMain.state++;
        break;
    case 5:
        if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_MYTH_HUB))
        {
            DrawHubStuff();
        }
        else if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_ENTRANCE))
        {
            sTarcUiState->monIconSpriteIds[0] = SPRITE_NONE;
            sTarcUiState->monIconSpriteIds[1] = SPRITE_NONE;
            sTarcUiState->monIconSpriteIds[2] = SPRITE_NONE;
            LoadMonIconPalettes();
            PrintAllInfoText();
        }
        else
        {
            sTarcUiState->monIconSpriteIds[0] = SPRITE_NONE;
            sTarcUiState->monIconSpriteIds[1] = SPRITE_NONE;
            sTarcUiState->monIconSpriteIds[2] = SPRITE_NONE;
            DrawSubAreaStuff();
        }
        CreateTask(Task_TarcUiWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        DisplayDebugInfoSprite();
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
            DecompressAndCopyTileDataToVram(1, sTarcInfoTiles, 0, 0, 0);
            break;
        //  Maps
        case MAP_NUM(MAP_MYTH_HUB):
            DecompressAndCopyTileDataToVram(1, sMythHubMapTiles, 0, 0, 0);
            break;
        default:
            DecompressAndCopyTileDataToVram(1, sSubAreaMapTiles, 0, 0, 0);
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
                LZDecompressWram(sTarcInfoTilemap, sBg1TilemapBuffer);
                break;
            //  Maps
            case MAP_NUM(MAP_MYTH_HUB):
                LZDecompressWram(sMythHubMapTilemap, sBg1TilemapBuffer);
                break;
            default:
                LZDecompressWram(sSubAreaMapTilemap, sBg1TilemapBuffer);
            }
            sTarcUiState->loadState++;
        }
        break;
    case 2:
        switch (gSaveBlock1Ptr->location.mapNum)
        {
        case MAP_NUM(MAP_ENTRANCE):
            //  Info screen
            LoadPalette(sTarcInfoPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP * 4);
            break;
        //  Maps
        case MAP_NUM(MAP_MYTH_HUB):
            LoadPalette(sMythHubMapPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
            break;
        default:
            LoadPalette(sSubAreaMapPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        }
        LoadPalette(sTarcTextPal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        sTarcUiState->loadState++;
    default:
        sTarcUiState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void TarcUi_InitOtherWindows(void)
{
    InitWindows(sTarcUiOtherWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);

    for (u32 i = 0; i < WIN_COUNT_OTHER; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
        PutWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_FULL);
    }
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
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_ENTRANCE))
    {
        if (JOY_NEW(L_BUTTON))
        {
            //  Change boss left
            if (sTarcUiState->finalBossSelector == 0)
                sTarcUiState->finalBossSelector = FINAL_BOSS_COUNT - 1;
            else
                sTarcUiState->finalBossSelector--;
            PrintAllInfoText();
        }
        if (JOY_NEW(R_BUTTON))
        {
            //  Change boss right
            if (sTarcUiState->finalBossSelector == FINAL_BOSS_COUNT - 1)
                sTarcUiState->finalBossSelector = 0;
            else
                sTarcUiState->finalBossSelector++;
            PrintAllInfoText();
        }
        if (JOY_NEW(A_BUTTON))
        {
            //  Change mode
            if (sTarcUiState->mode == MODE_LOSSES)
                sTarcUiState->mode = MODE_TOTAL;
            else
                sTarcUiState->mode++;
            PrintAllInfoText();
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

void CB2_InfoScreenFromStartMenu(void)
{
    Tarc_InitInfoScreen(CB2_ReturnToFieldWithOpenMenu);
}

static void PrintNameText(void)
{
    FillWindowPixelBuffer(WIN_NAME, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_NAME,
                                 FONT_NORMAL,
                                 TarcUi_JustifyCenter(gSaveBlock2Ptr->playerName, NAME_WIDTH * 8, FONT_NORMAL), 0, 0, 0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 gSaveBlock2Ptr->playerName);
    CopyWindowToVram(WIN_NAME, COPYWIN_GFX);
}

static u32 ConvertToHex(u32 input)
{
    switch (input)
    {
    case 0:
        return CHAR_0;
    case 1:
        return CHAR_1;
    case 2:
        return CHAR_2;
    case 3:
        return CHAR_3;
    case 4:
        return CHAR_4;
    case 5:
        return CHAR_5;
    case 6:
        return CHAR_6;
    case 7:
        return CHAR_7;
    case 8:
        return CHAR_8;
    case 9:
        return CHAR_9;
    case 10:
        return CHAR_A;
    case 11:
        return CHAR_B;
    case 12:
        return CHAR_C;
    case 13:
        return CHAR_D;
    case 14:
        return CHAR_E;
    case 15:
        return CHAR_F;
    }
    return CHAR_0;
}

static void PrintRunsText(void)
{
    u8 tempStr[11];
    u32 trainerId = GetTrainerId(gSaveBlock2Ptr->playerTrainerId);
    tempStr[0] = CHAR_0;
    tempStr[1] = CHAR_x;
    for (u32 i = 0; i < 8; i++)
        tempStr[2 + i] = ConvertToHex((trainerId >> (28 - (i * 4))) & 0xF);
    tempStr[10] = EOS;
    FillWindowPixelBuffer(WIN_RUNS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_RUNS,
                                 FONT_NORMAL,
                                 TarcUi_JustifyCenter(tempStr, NAME_WIDTH * 8, FONT_NORMAL), 0, 0, 0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 tempStr);
    CopyWindowToVram(WIN_RUNS, COPYWIN_GFX);
}

static const u8 sNoRecord[] = COMPOUND_STRING("No Record");
static void PrintRecordText(u32 bossId)
{
    FillWindowPixelBuffer(WIN_BESTRUN, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    if (gSaveBlock1Ptr->bestBosses[0].teamMembers[0] == 0)
    {
        AddTextPrinterParameterized4(WIN_BESTRUN,
                                     FONT_NORMAL,
                                     0, 0, 0, 0,
                                     sTarcUiWindowFontColors[FONT_BLACK],
                                     TEXT_SKIP_DRAW,
                                     sNoRecord);
    }
    else
    {
        u8 subBossString[2];
        u8 miniBossString[3] = {0, 0, 0};
        ConvertIntToDecimalStringN(subBossString, gSaveBlock1Ptr->bestBosses[bossId].numSubBosses, STR_CONV_MODE_LEFT_ALIGN, 1);
        // ConvertIntToDecimalStringN(miniBossString, gSaveBlock1Ptr->bestBosses[bossId].numMiniBosses, STR_CONV_MODE_LEFT_ALIGN, 2);

        // u8 tempStr[5];
        // tempStr[0] = subBossString[0];
        // tempStr[1] = CHAR_PLUS;
        // tempStr[2] = miniBossString[0];
        // tempStr[3] = miniBossString[1];
        // tempStr[4] = miniBossString[2];

        AddTextPrinterParameterized4(WIN_BESTRUN,
                                     FONT_NORMAL,
                                     0, 2, 0, 0,
                                     sTarcUiWindowFontColors[FONT_BLACK],
                                     TEXT_SKIP_DRAW,
                                     subBossString);
    }

    CopyWindowToVram(WIN_BESTRUN, COPYWIN_GFX);
}

static const u8 *const sMythNames[] =
{
    COMPOUND_STRING("Life of Xerneas"),
    COMPOUND_STRING("Storm of Lugia"),
    COMPOUND_STRING("Shadow of Giratina"),
};


static void PrintMythName(u32 bossId)
{
    FillWindowPixelBuffer(WIN_MYTH_NAME, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_MYTH_NAME,
                                 FONT_NORMAL,
                                 4, 0, 0, 0,
                                 sTarcUiWindowFontColors[FONT_WHITE],
                                 TEXT_SKIP_DRAW,
                                 sMythNames[bossId]);
    CopyWindowToVram(WIN_MYTH_NAME, COPYWIN_GFX);
}

const u8 *const sStatTitles[] =
{
    COMPOUND_STRING("Attempts"),
    COMPOUND_STRING("Victories"),
    COMPOUND_STRING("Losses"),
};

static void PrintStatTitle()
{
    FillWindowPixelBuffer(WIN_STAT_TITLE, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_STAT_TITLE,
                                 FONT_NORMAL,
                                 TarcUi_JustifyCenter(sStatTitles[sTarcUiState->mode], STAT_TITLE_WIDTH * 8, FONT_NORMAL), 0, 0, 0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 sStatTitles[sTarcUiState->mode]);
    CopyWindowToVram(WIN_STAT_TITLE, COPYWIN_GFX);
}

static void PrintStatNumber(u32 bossId)
{
    u32 number = 0;
    for (u32 archetype = 0; archetype < 12; archetype++)
    {
        switch (sTarcUiState->mode)
        {
        case MODE_TOTAL:
            number += gSaveBlock1Ptr->victoryStats[bossId][archetype].attempts;
            break;
        case MODE_WINS:
            number += gSaveBlock1Ptr->victoryStats[bossId][archetype].wins;
            break;
        case MODE_LOSSES:
            number += gSaveBlock1Ptr->victoryStats[bossId][archetype].attempts - gSaveBlock1Ptr->victoryStats[bossId][archetype].wins;
            break;
        }
    }

    u8 tempStr[8];
    ConvertIntToDecimalStringN(tempStr, number, STR_CONV_MODE_LEFT_ALIGN, 7);
    FillWindowPixelBuffer(WIN_STAT_NUMBER, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_STAT_NUMBER,
                                 FONT_NORMAL,
                                 TarcUi_JustifyCenter(tempStr, STAT_NUMBER_WIDTH * 8, FONT_NORMAL), 0, 0, 0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 tempStr);
    CopyWindowToVram(WIN_STAT_NUMBER, COPYWIN_GFX);
}

static void PrintArchetypeStats(u32 bossId)
{
    FillWindowPixelBuffer(WIN_RAIN_STATS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WIN_SUN_STATS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WIN_SNOW_STATS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WIN_SAND_STATS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    for (u32 archetype = 0; archetype < 4; archetype++)
    {
        u8 tempStr[22];
        u32 tempChar = 0;
        for (u32 j = 0; j < 3; j++)
        {
            u8 numStr[8];
            u32 number = 0;
            switch (sTarcUiState->mode)
            {
            case MODE_TOTAL:
                number += gSaveBlock1Ptr->victoryStats[bossId][j + archetype * 3].attempts;
                break;
            case MODE_WINS:
                number += gSaveBlock1Ptr->victoryStats[bossId][j + archetype * 3].wins;
                break;
            case MODE_LOSSES:
                number += gSaveBlock1Ptr->victoryStats[bossId][j + archetype * 3].attempts - gSaveBlock1Ptr->victoryStats[bossId][j + archetype * 3].wins;
                break;
            }
            ConvertIntToDecimalStringN(numStr, number, STR_CONV_MODE_LEFT_ALIGN, 7);
            u32 numChar = 0;
            while (numStr[numChar] != EOS)
            {
                tempStr[tempChar] = numStr[numChar];
                tempChar++;
                numChar++;
            }
            tempStr[tempChar++] = CHAR_NEWLINE;
        }
        tempStr[tempChar - 1] = EOS;
        AddTextPrinterParameterized4(WIN_RAIN_STATS + archetype,
                                     FONT_NORMAL,
                                     TarcUi_JustifyCenter(tempStr, RAIN_STATS_WIDTH * 8, FONT_NORMAL), 0, 0, 0,
                                     sTarcUiWindowFontColors[FONT_BLACK],
                                     TEXT_SKIP_DRAW,
                                     tempStr);
    }

    CopyWindowToVram(WIN_RAIN_STATS, COPYWIN_GFX);
    CopyWindowToVram(WIN_SUN_STATS, COPYWIN_GFX);
    CopyWindowToVram(WIN_SNOW_STATS, COPYWIN_GFX);
    CopyWindowToVram(WIN_SAND_STATS, COPYWIN_GFX);
}

static void PrintBoss(u32 bossId)
{
    u32 species = sFinalBossToSpecies[bossId];
    if (species == SPECIES_XERNEAS)
        species = SPECIES_XERNEAS_ACTIVE;
    struct Even_CreateSpriteStruct cs = {0};
    cs.sprite = gSpeciesInfo[species].frontPic;
    cs.tileTag = 0xCEC1;
    cs.spriteCompressed = TRUE;
    u16 palette[16];
    for (u32 i = 0; i < 16; i++)
    {
        if (!gSpeciesInfo[species].excludeBlend[i])
            palette[i] = ConvertColorToDesaturatedNaive(gSpeciesInfo[species].palette[i]);
        else
            palette[i] = gSpeciesInfo[species].palette[i];
    }
    cs.palette = palette;
    cs.palTag = 0xCEC1;
    cs.spriteSize = SPRITE_SIZE(64x64);
    cs.spriteShape = SPRITE_SHAPE(64x64);
    cs.posX = 200;
    cs.posY = 52;
    cs.subpriority = 0;
    sTarcUiState->speciesSpriteId = Even_CreateSprite(&cs);
}

static void PrintMonIcons(u32 bossId)
{
    if (gSaveBlock1Ptr->bestBosses[bossId].teamMembers[0] != SPECIES_NONE)
    {
        for (u32 i = 0; i < 3; i++)
        {
            if (sTarcUiState->monIconSpriteIds[i] != SPRITE_NONE)
            {
                FreeAndDestroyMonIconSprite(&gSprites[sTarcUiState->monIconSpriteIds[i]]);
            }
            u32 posX = 0;
            u32 posY = 0;
            switch (i)
            {
            case 0:
                posX = 194;
                posY = 134;
                break;
            case 1:
                posX = 172;
                posY = 118;
                break;
            case 2:
                posX = 218;
                posY = 118;
                break;
            }
            sTarcUiState->monIconSpriteIds[i] = CreateMonIcon(gSaveBlock1Ptr->bestBosses[bossId].teamMembers[i], SpriteCB_MonIcon, posX, posY, 0, 0);
        }
    }
}

static void PrintAllInfoText(void)
{
    if (sTarcUiState->speciesSpriteId != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sTarcUiState->speciesSpriteId]);
        FreeSpriteTilesByTag(0xCEC1);
        FreeSpritePaletteByTag(0xCEC1);
    }
    PrintNameText();
    PrintRunsText();
    PrintRecordText(sTarcUiState->finalBossSelector);
    PrintMythName(sTarcUiState->finalBossSelector);
    PrintStatTitle();
    PrintStatNumber(sTarcUiState->finalBossSelector);
    PrintArchetypeStats(sTarcUiState->finalBossSelector);
    PrintBoss(sTarcUiState->finalBossSelector);
    PrintMonIcons(sTarcUiState->finalBossSelector);
}

static void DrawSubAreaStuff(void)
{
    u32 species = gSaveBlock1Ptr->huntTargets.currentBoss;
    FillWindowPixelBuffer(WIN_BOSS_TEXT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    const u8 *currString = gAbilitiesInfo[gSpeciesInfo[species].abilityReward].name;
    AddTextPrinterParameterized4(WIN_BOSS_TEXT,
                                 FONT_NORMAL,
                                 TarcUi_JustifyCenter(currString, REWARD_WIDTH * 8, FONT_NORMAL), 0, 0, 0,
                                 sTarcUiWindowFontColors[FONT_BLACK],
                                 TEXT_SKIP_DRAW,
                                 currString);
    CopyWindowToVram(WIN_BOSS_TEXT, COPYWIN_GFX);
    struct Even_CreateSpriteStruct cs = {0};
    cs.sprite = gSpeciesInfo[species].frontPic;
    cs.spriteCompressed = TRUE;
    u16 palette[16];
    DesaturateSpeciesPalette(gSpeciesInfo[species].palette, palette, gSpeciesInfo[species].excludeBlend);
    cs.palette = palette;
    cs.tileTag = 0xCEC1;
    cs.palTag = 0xCEC1;
    cs.spriteSize = SPRITE_SIZE(64x64);
    cs.spriteShape = SPRITE_SHAPE(64x64);
    cs.posX = 120;
    cs.posY = 32;
    Even_CreateSprite(&cs);
    u32 area = gSaveBlock1Ptr->huntTargets.currentArea;
    cs.posY = 112;
    for (u32 i = 0; i < 3; i++)
    {
        species = gSaveBlock1Ptr->huntTargets.miniBosses[3 * area + i];
        currString = gMovesInfo[gSpeciesInfo[species].moveReward].name;
        AddTextPrinterParameterized4(WIN_MINI1_TEXT + i,
                                     FONT_NORMAL,
                                     TarcUi_JustifyCenter(currString, REWARD_WIDTH * 8, FONT_NORMAL), 0, 0, 0,
                                     sTarcUiWindowFontColors[FONT_BLACK],
                                     TEXT_SKIP_DRAW,
                                     currString);
        CopyWindowToVram(WIN_MINI1_TEXT + i, COPYWIN_GFX);
        cs.sprite = gSpeciesInfo[species].frontPic;
        cs.spriteCompressed = TRUE;
        DesaturateSpeciesPalette(gSpeciesInfo[species].palette, palette, gSpeciesInfo[species].excludeBlend);
        cs.palette = palette;
        cs.tileTag = 0xCEC2 + i;
        cs.palTag = 0xCEC2 + i;
        cs.spriteSize = SPRITE_SIZE(64x64);
        cs.spriteShape = SPRITE_SHAPE(64x64);
        cs.posX = 40 + 80 * i;
        Even_CreateSprite(&cs);
    }
}
