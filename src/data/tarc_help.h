#include "tarc_help_system.h"

const u32 sHelpRotationGfx[] = INCBIN_U32("graphics/help_messages/help_rotation.4bpp");
const u16 sHelpRotationPal[] = INCBIN_U16("graphics/help_messages/help_rotation.gbapal");

const u32 sHelpPhaseGfx[] = INCBIN_U32("graphics/help_messages/help_phase.4bpp");
const u16 sHelpPhasePal[] = INCBIN_U16("graphics/help_messages/help_phase.gbapal");

const u32 sHelpCooldownGfx[] = INCBIN_U32("graphics/help_messages/help_cooldown.4bpp");
const u16 sHelpCooldownPal[] = INCBIN_U16("graphics/help_messages/help_cooldown.gbapal");

const u32 sHelpHealGfx[] = INCBIN_U32("graphics/help_messages/help_heal.4bpp");
const u16 sHelpHealPal[] = INCBIN_U16("graphics/help_messages/help_heal.gbapal");

const u32 sHelpBossMoveGfx[] = INCBIN_U32("graphics/help_messages/help_boss_move.4bpp");
const u16 sHelpBossMovePal[] = INCBIN_U16("graphics/help_messages/help_boss_move.gbapal");

const u32 sHelpChooseBossGfx[] = INCBIN_U32("graphics/help_messages/help_choose_boss.4bpp");
const u16 sHelpChooseBossPal[] = INCBIN_U16("graphics/help_messages/help_choose_boss.gbapal");

const struct HelpData sHelpDatas[] =
{
    [TRIGGER_ROTATION] = {
        .x = 120,
        .y = 88,
        .spritePtr = sHelpRotationGfx,
        .palettePtr = sHelpRotationPal,
        .flag = FLAG_HELP_ROTATION,
        .numSprites = 1,
    },
    [TRIGGER_PHASE] = {
        .x = 80,
        .y = 72,
        .spritePtr = sHelpPhaseGfx,
        .palettePtr = sHelpPhasePal,
        .flag = FLAG_HELP_PHASE,
        .numSprites = 1,
    },
    [TRIGGER_COOLDOWN] = {
        .x = 90,
        .y = 80,
        .spritePtr = sHelpCooldownGfx,
        .palettePtr = sHelpCooldownPal,
        .flag = FLAG_HELP_COOLDOWN,
        .numSprites = 2,
    },
    [TRIGGER_HEAL] = {
        .x = 120,
        .y = 92,
        .spritePtr = sHelpHealGfx,
        .palettePtr = sHelpHealPal,
        .flag = FLAG_HELP_HEAL,
        .numSprites = 2,
    },
    [TRIGGER_BOSS_MOVE] = {
        .x = 120,
        .y = 92,
        .spritePtr = sHelpBossMoveGfx,
        .palettePtr = sHelpBossMovePal,
        .flag = FLAG_HELP_BOSS_MOVE,
        .numSprites = 1,
    },
    [TRIGGER_CHOOSE_BOSS] = {
        .x = 130,
        .y = 112,
        .spritePtr = sHelpChooseBossGfx,
        .palettePtr = sHelpChooseBossPal,
        .flag = FLAG_HELP_CHOOSE_BOSS,
        .numSprites = 1,
    },
    [TRIGGER_MOVES] = {
    },
    [TRIGGER_ABILITIES] = {
    },
};
