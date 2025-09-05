#include "tarc_ai.h"
#include "battle.h"
#include "constants/moves.h"

#include "data/tarc_ai_moves.h"

void SetNextBossMove(void)
{
    if (TESTING)
        return;
    if (gBattleStruct->aiTurnCounter >= sAiLists[gBattleStruct->currentBoss].phaseMoves[gBattleStruct->currentPhase]->numMoves)
        gBattleStruct->aiTurnCounter = 0;

    u32 move = sAiLists[gBattleStruct->currentBoss].phaseMoves[gBattleStruct->currentPhase - 1]->moves[gBattleStruct->aiTurnCounter];

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
    gBattleStruct->currentBoss = sSpeciesToBossTable[GetMonData(&gEnemyParty[0], MON_DATA_SPECIES)];
    if (TESTING)
        return;
    u32 value = 0;
    SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &value);
    SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &value);
    SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &value);
    SetMonData(&gEnemyParty[0], MON_DATA_PP2, &value);
    SetMonData(&gEnemyParty[0], MON_DATA_PP3, &value);
    SetMonData(&gEnemyParty[0], MON_DATA_PP4, &value);
    gBattleMons[1].moves[1] = 0;
    gBattleMons[1].moves[2] = 0;
    gBattleMons[1].moves[3] = 0;
    gBattleMons[1].pp[1] = 0;
    gBattleMons[1].pp[2] = 0;
    gBattleMons[1].pp[3] = 0;
}
