#include "global.h"

enum AiMoveLists
{
    AI_LIST_ARTICUNO_1,
    AI_LIST_ARTICUNO_2,
    AI_LIST_ARTICUNO_3,
    AI_LIST_ARTICUNO_4,
    AI_LIST_ZAPDOS_1,
    AI_LIST_ZAPDOS_2,
    AI_LIST_ZAPDOS_3,
    AI_LIST_ZAPDOS_4,
    AI_LIST_MOLTRES_1,
    AI_LIST_MOLTRES_2,
    AI_LIST_MOLTRES_3,
    AI_LIST_MOLTRES_4,
};

enum Bosses
{
    BOSS_ARTICUNO,
    BOSS_ZAPDOS,
    BOSS_MOLTRES,
};

struct BossMoveList
{
    u32 numMoves;
    u16 moves[];
};

struct BossAi
{
    const struct BossMoveList *phaseMoves[6];
};

void SetNextBossMove(void);
