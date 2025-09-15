#ifndef GUARD_TARC_HELP_SYSTEM
#define GUARD_TARC_HELP_SYSTEM

#include "gba/types.h"
#include "global.h"
#include "constants/flags.h"

#define MAX_HELP_QUEUE 10

enum HelpTriggers
{
    TRIGGER_ROTATION,
    TRIGGER_PHASE,
    TRIGGER_COOLDOWN,
    TRIGGER_HEAL,
    TRIGGER_BOSS_MOVE,
    TRIGGER_CHOOSE_BOSS,
    TRIGGER_MOVES,
    TRIGGER_ABILITIES,
};

struct HelpData
{
    u16 x;
    u16 y;
    const u32 *spritePtr;
    const u16 *palettePtr;
    u16 flag;
    u16 numSprites;
};

struct HelpStruct
{
    u8 numInQueue;
    bool8 isShowingHelp;
    u16 numSprites;
    u16 queue[MAX_HELP_QUEUE];
    u32 spriteIds[2];

};

extern struct HelpStruct gHelpStruct;

bool32 HelpSystem_Process(void);
void HelpSystem_AddTrigger(u32 trigger);

#endif
