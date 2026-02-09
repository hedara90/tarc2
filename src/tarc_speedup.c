#include "global.h"
#include "gba/types.h"
#include "main.h"
#include "tarc_speedup.h"
#include "even_sprite.h"
#include "tarc_debug.h"
#include "palette.h"
#include "battle.h"

EWRAM_DATA u32 sSkipCounter = 0;
EWRAM_DATA bool32 sDoSpeedup = FALSE;
EWRAM_DATA u32 sNumSkips = 0;
EWRAM_DATA bool32 sPause = FALSE;

EWRAM_INIT u32 sSpeedupSpriteId = SPRITE_NONE;
EWRAM_DATA u32 *sSpeedupSpriteStart;

const u32 sSpeedupGfx[] = INCBIN_U32("graphics/tarc_speedup/speedup.4bpp");
const u16 sSpeedupPal[] = INCBIN_U16("graphics/tarc_speedup/speedup.gbapal");

void StartSpeedup(void)
{
    if (gSaveBlock2Ptr->speedup != 0 && !sDoSpeedup)
    {
        sDoSpeedup = TRUE;
        if (gBattleStruct->currentSpeedup != 0)
            sNumSkips = gBattleStruct->currentSpeedup;
        else
            sNumSkips = gSaveBlock2Ptr->speedup;
        //  Create speedup sprite
        struct Even_CreateSpriteStruct cs = {0};
        cs.sprite = &sSpeedupGfx[(TILE_SIZE_4BPP / 4) * (sNumSkips + 1)];
        cs.tileTag = 0xFBE2;
        cs.palette = sSpeedupPal;
        cs.palTag = 0xFBE1;
        cs.spriteSize = SPRITE_SIZE(16x8);
        cs.spriteShape = SPRITE_SHAPE(16x8);
        cs.posX = 8;
        cs.posY = 4;
        sSpeedupSpriteId = Even_CreateSprite(&cs);
        sSpeedupSpriteStart = (u32 *)(OBJ_VRAM0 + GetSpriteTileStartByTag(0xFBE2) * TILE_SIZE_4BPP);
        for (u32 i = 0; i < 8; i++)
            sSpeedupSpriteStart[8 + i] = sSpeedupGfx[8 + i];
    }
}

void StopSpeedup(void)
{
    gBattleStruct->currentSpeedup = sNumSkips;
    sDoSpeedup = FALSE;
    sNumSkips = 0;
    //  Remove speedup sprite
    if (sSpeedupSpriteId != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sSpeedupSpriteId]);
        FreeSpriteTilesByTag(0xFBE2);
        if (!gShouldShowDebugInfo)
            FreeSpritePaletteByTag(0xFBE1);
        sSpeedupSpriteId = SPRITE_NONE;
    }
}

void CheckSpeedupControls(void)
{
    if (sDoSpeedup)
    {
        if (JOY_NEW(L_BUTTON))
        {
            if (sNumSkips > 1)
                sNumSkips--;
            //  Change speedup number in sprite
            for (u32 i = 0; i < 8; i++)
                sSpeedupSpriteStart[i] = sSpeedupGfx[8 * (1 + sNumSkips) + i];

            //  If 0, hide sprite
        }
        else if (JOY_NEW(R_BUTTON))
        {
            if (sNumSkips < MAX_SPEEDUP)
                sNumSkips++;
            //  Change speedup number in sprite
            for (u32 i = 0; i < 8; i++)
                sSpeedupSpriteStart[i] = sSpeedupGfx[8 * (1 + sNumSkips) + i];
        }
        else if (JOY_NEW(B_BUTTON))
        {
            if (sPause)
            {
                sPause = FALSE;
                for (u32 i = 0; i < 8; i++)
                    sSpeedupSpriteStart[8 + i] = sSpeedupGfx[8 + i];
            }
            else
            {
                sPause = TRUE;
                for (u32 i = 0; i < 8; i++)
                    sSpeedupSpriteStart[8 + i] = sSpeedupGfx[i];
            }
        }
    }
}

bool32 SpeedupShouldSkip(void)
{
    if (!sDoSpeedup)
        return FALSE;

    if (sSkipCounter + 1 >= sNumSkips)
    {
        sSkipCounter = 0;
        return FALSE;
    }
    else
    {
        UpdatePaletteFade();
        sSkipCounter++;
        return TRUE;
    }
}

bool32 SpeedupIsPaused(void)
{
    return sPause;
}
