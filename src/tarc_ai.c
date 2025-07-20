#include "tarc_ai.h"
#include "battle.h"
#include "constants/moves.h"

#include "data/tarc_ai_moves.h"

void SetNextBossMove(void)
{
    if (gBattleStruct->aiTurnCounter >= sAiLists[gBattleStruct->currentBoss].phaseMoves[gBattleStruct->currentPhase]->numMoves)
        gBattleStruct->aiTurnCounter = 0;

    u32 move = sAiLists[gBattleStruct->currentBoss].phaseMoves[gBattleStruct->currentPhase]->moves[gBattleStruct->aiTurnCounter];

    SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move);
    gBattleMons[1].moves[0] = move;
}

void ResetTurnCounter(void)
{
    gBattleStruct->aiTurnCounter = 0;
}
//  Add which boss is being fought

void SetBossInBattle(void)
{
    gBattleStruct->currentBoss = BOSS_MOLTRES;
}
