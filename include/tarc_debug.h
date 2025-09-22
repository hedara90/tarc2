#ifndef GUARD_TARC_DEBUG
#define GUARD_TARC_DEBUG

#include "global.h"
#include "gba/types.h"

extern u32 gDebugInfoSprite[128];
extern u8 gDebugInfoSpriteId;
extern bool8 gShouldShowDebugInfo;

u32 RomXor(void);
void BuildDebugInfoSprite(void);
void DisplayDebugInfoSprite(void);

#endif
