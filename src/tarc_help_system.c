#include "tarc_help_system.h"
#include "main.h"
#include "global.h"
#include "sound.h"
#include "constants/songs.h"
#include "event_data.h"
#include "even_sprite.h"
#include "battle.h"
#include "pokemon.h"

#include "data/tarc_help.h"

EWRAM_DATA struct HelpStruct gHelpStruct;

static void CalcCoordinates(s32 *x, s32 *y, u32 trigger)
{
    if (trigger == TRIGGER_COOLDOWN)
    {
        u32 moveIndex = 0;
        for (u32 i = 0; i < 4; i++)
        {
            if (gBattleMons[0].moveCD[i] > 0)
            {
                moveIndex = i;
                break;
            }
        }
        *x = (moveIndex & 0x1) * 72 + 93;
        *y = ((moveIndex & 0x2) >> 1) * 16 + 98;
    }
    else
    {
        *x = sHelpDatas[trigger].x;
        *y = sHelpDatas[trigger].y;
    }
}

static void DisplayHelp(void)
{
    s32 x, y;
    u32 help = gHelpStruct.queue[0];
    CalcCoordinates(&x, &y, help);
    struct Even_CreateSpriteStruct cs = {0};
    cs.sprite = sHelpDatas[help].spritePtr;
    cs.tileTag = 0xAEAE;
    cs.palette = sHelpDatas[help].palettePtr;
    cs.palTag = 0xAEAE;
    cs.spriteSize = SPRITE_SIZE(64x64);
    cs.spriteShape = SPRITE_SHAPE(64x64);
    cs.posY = y;
    if (sHelpDatas[help].numSprites > 1)
    {
        gHelpStruct.numSprites = 2;
        cs.posX = x - 32;
        gHelpStruct.spriteIds[0] = Even_CreateSprite(&cs);
        cs.posX = x + 32;
        cs.tileTag = 0xAEAF;
        cs.sprite = &sHelpDatas[help].spritePtr[64*64/8];
        gHelpStruct.spriteIds[1] = Even_CreateSprite(&cs);

        gSprites[gHelpStruct.spriteIds[0]].oam.priority = 0;
        gSprites[gHelpStruct.spriteIds[1]].oam.priority = 0;
    }
    else
    {
        gHelpStruct.numSprites = 1;
        cs.posX = x;
        gHelpStruct.spriteIds[0] = Even_CreateSprite(&cs);
        gSprites[gHelpStruct.spriteIds[0]].oam.priority = 0;
    }


    for (u32 i = 1; i < gHelpStruct.numInQueue; i++)
        gHelpStruct.queue[i - 1] = gHelpStruct.queue[i];

    gHelpStruct.numInQueue--;
    gHelpStruct.isShowingHelp = TRUE;
}

static void RemoveHelp(void)
{
    DestroySprite(&gSprites[gHelpStruct.spriteIds[0]]);
    FreeSpriteTilesByTag(0xAEAE);
    if (gHelpStruct.numSprites == 2)
    {
        DestroySprite(&gSprites[gHelpStruct.spriteIds[1]]);
        FreeSpriteTilesByTag(0xAEAF);
    }
    FreeSpritePaletteByTag(0xAEAE);
    gHelpStruct.isShowingHelp = FALSE;
}

bool32 HelpSystem_Process(void)
{
    if (TESTING)
        return FALSE;
    if (gHelpStruct.isShowingHelp)
    {
        if (JOY_NEW(A_BUTTON))
        {
            //  Remove current help thing
            PlaySE(SE_PC_OFF);
            gHelpStruct.isShowingHelp = FALSE;
            RemoveHelp();
            return TRUE;
        }
        else
        {
            return TRUE;
        }
    }

    if (gHelpStruct.numInQueue > 0)
    {
        gHelpStruct.isShowingHelp = TRUE;
        DisplayHelp();
        return TRUE;
    }
    return FALSE;
}

void HelpSystem_AddTrigger(u32 trigger)
{
    if (TESTING)
        return;

    if (FlagGet(sHelpDatas[trigger].flag))
        return;

    FlagSet(sHelpDatas[trigger].flag);
    gHelpStruct.queue[gHelpStruct.numInQueue] = trigger;
    gHelpStruct.numInQueue++;
}
