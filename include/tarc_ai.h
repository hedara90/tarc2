#ifndef GUARD_TARC_AI
#define GUARD_TARC_AI

#include "global.h"
#include "constants/tarc_ai.h"


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
void ResetTurnCounter(void);
void SetBossInBattle(void);

#endif
