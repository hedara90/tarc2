#include "tarc_debug.h"
#include "even_sprite.h"
#include "main.h"

EWRAM_DATA u32 gDebugInfoSprite[128] = { 0 };
EWRAM_DATA u8 gDebugInfoSpriteId;
EWRAM_DATA bool8 gShouldShowDebugInfo = FALSE;
//EWRAM_DATA u8 sMyBoyDetector = 0;

const u32 sNumberDotsGfx[] = INCBIN_U32("graphics/tarc_debug/number_dots.4bpp");
const u16 sNumberDotsPal[] = INCBIN_U16("graphics/tarc_debug/number_dots.gbapal");

u32 DetectEmulator(void)
{
    //  Detect mGBA
    #define REG_DEBUG_ENABLE ((vu16*) (0x4FFF780))
    *REG_DEBUG_ENABLE = 0xC0DE;
    u32 isMGBA = (*REG_DEBUG_ENABLE) == 0x1DEA;

    u32 emulatorValue = 0;
    if (isMGBA)
    {
        emulatorValue = 1;
        return emulatorValue;
    }

    //  This should crash MyBoy from what I know
    //u32 someValue = 5 / sMyBoyDetector;
    return emulatorValue;
}

void BuildDebugInfoSprite(void)
{
    //  Calculate ROM hash
    for (u32 i = 0; i < 128; i++)
        gDebugInfoSprite[i] = 17 + (17 << 8) + (17 << 16) + (17 << 24);

    u32 romHash = RomXor();
    for (u32 i = 0; i < 8; i++)
    {
        u32 currValue = (romHash >> (4 * i)) & 0xf;
        for (u32 j = 0; j < 8; j++)
        {
            gDebugInfoSprite[i * 8 + j] = sNumberDotsGfx[8 * currValue + j];
        }
    }

    //  Detect which emulator is used
    u32 emulatorValue = DetectEmulator();

    for (u32 i = 0; i < 8; i++)
    {
        gDebugInfoSprite[64 + i] = sNumberDotsGfx[8 * emulatorValue + i];
    }

    gShouldShowDebugInfo = TRUE;
}

void ModifyDebugInfoSpriteForBattle(void)
{
    u32 subBossNumber = gSaveBlock1Ptr->huntTargets.numBossesDefeated;
    for (u32 i = 0; i < 8; i++)
    {
        gDebugInfoSprite[72 + i] = sNumberDotsGfx[8 * subBossNumber + i];
    }
}
void ModifyDebugInfoSpriteForEntrance(void)
{
    for (u32 i = 0; i < 8; i++)
    {
        gDebugInfoSprite[72 + i] = 17 + (17 << 8) + (17 << 16) + (17 << 24);
    }
}

void DisplayDebugInfoSprite(void)
{
    if (!gShouldShowDebugInfo)
        return;

    if (gSaveBlock1Ptr->location.mapNum != MAP_NUM(MAP_ENTRANCE))
        ModifyDebugInfoSpriteForBattle();
    else
        ModifyDebugInfoSpriteForEntrance();


    struct Even_CreateSpriteStruct cs = {0};
    cs.sprite = gDebugInfoSprite;
    cs.tileTag = 0xFBE1;
    cs.palette = sNumberDotsPal;
    cs.palTag = 0xFBE1;
    cs.spriteSize = SPRITE_SIZE(32x32);
    cs.spriteShape = SPRITE_SHAPE(32x32);
    cs.posX = 240 - 16;
    cs.posY = 16;
    gDebugInfoSpriteId = Even_CreateSprite(&cs);
    gSprites[gDebugInfoSpriteId].oam.priority = 0;
}
