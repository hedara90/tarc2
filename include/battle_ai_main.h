#ifndef GUARD_BATTLE_AI_MAIN_H
#define GUARD_BATTLE_AI_MAIN_H


typedef s32 (*AiScoreFunc)(u32, u32, u32, s32);

#define UNKNOWN_NO_OF_HITS UINT32_MAX

// for AI_WhoStrikesFirst
#define AI_IS_FASTER   1
#define AI_IS_SLOWER   -1

// for stat increasing / decreasing scores
enum StatChange
{
    STAT_CHANGE_ATK,
    STAT_CHANGE_DEF,
    STAT_CHANGE_SPEED,
    STAT_CHANGE_SPATK,
    STAT_CHANGE_SPDEF,
    STAT_CHANGE_ATK_2,
    STAT_CHANGE_DEF_2,
    STAT_CHANGE_SPEED_2,
    STAT_CHANGE_SPATK_2,
    STAT_CHANGE_SPDEF_2,
    STAT_CHANGE_ACC,
    STAT_CHANGE_EVASION
};

#define BEST_DAMAGE_MOVE         1  // Move with the most amount of hits with the best accuracy/effect
#define POWERFUL_STATUS_MOVE     10 // Moves with this score will be chosen over a move that faints target
#define NO_DAMAGE_OR_FAILS      -20 // Move fails or does no damage

// Scores given in AI_CalcMoveEffectScore and AI_CalcHoldEffectMoveScore
enum AIScore
{
    NO_INCREASE = 0,
    WEAK_EFFECT = 1,
    DECENT_EFFECT = 2,
    GOOD_EFFECT = 3,
    BEST_EFFECT = 4
};

// AI_TryToFaint
#define FAST_KILL      6 // AI is faster and faints target
#define SLOW_KILL      4 // AI is slower and faints target
#define LAST_CHANCE    2 // AI faints to target. It should try and do damage with a priority move

// AI_Risky
#define STRONG_RISKY_EFFECT     3
#define AVERAGE_RISKY_EFFECT    2

#include "test_runner.h"

// Logs for debugging AI tests.
#define SET_SCORE(battler, movesetIndex, val) \
    do \
    { \
        if (TESTING) \
        { \
            TestRunner_Battle_AISetScore(__FILE__, __LINE__, battler, movesetIndex, val); \
        } \
        gAiThinkingStruct->score[movesetIndex] = val; \
    } while (0) \

#define ADJUST_SCORE(val) \
    do \
    { \
        if (TESTING) \
        { \
            TestRunner_Battle_AIAdjustScore(__FILE__, __LINE__, battlerAtk, gAiThinkingStruct->movesetIndex, val); \
        } \
        score += val; \
    } while (0) \

#define ADJUST_AND_RETURN_SCORE(val) \
    do \
    { \
    if (TESTING) \
        { \
            TestRunner_Battle_AIAdjustScore(__FILE__, __LINE__, battlerAtk, gAiThinkingStruct->movesetIndex, val); \
        } \
        score += val; \
        return score; \
    } while (0) \

#define ADJUST_SCORE_PTR(val) \
    do \
    { \
        if (TESTING) \
        { \
            TestRunner_Battle_AIAdjustScore(__FILE__, __LINE__, battlerAtk, gAiThinkingStruct->movesetIndex, val); \
        } \
        (*score) += val; \
    } while (0) \

#define RETURN_SCORE_PLUS(val)      \
{                                   \
    ADJUST_SCORE(val);              \
    return score;                   \
}

#define RETURN_SCORE_MINUS(val)     \
{                                   \
    ADJUST_SCORE(-val);             \
    return score;                   \
}

#define AI_BATTLER_HAS_TRAIT(battlerID, abilityToCheck) (gAiLogicData->abilities[battlerID] == abilityToCheck || BattlerHasInnate(battlerID, abilityToCheck)) //Useful to make calculations faster, used only for AI stuff

#define AI_STORE_BATTLER_TRAITS(battlerID) \
({for (int traitLoop = 0; traitLoop < MAX_MON_TRAITS; traitLoop++)\
{if(traitLoop == 0){AIBattlerTraits[traitLoop] = gAiLogicData->abilities[battlerID];}else{AIBattlerTraits[traitLoop] = GetBattlerTrait(battlerID, traitLoop);}}})

static inline u32 AISearchTraits(u16 *AIBattlerTraits, u32 abilityToCheck)
{
  for (u32 i = 0; i < MAX_MON_TRAITS; i++)
  {
    if (AIBattlerTraits[i] == abilityToCheck)
      return i + 1;
  }
  return 0;
}

void BattleAI_SetupItems(void);
void BattleAI_SetupFlags(void);
void BattleAI_SetupAIData(u8 defaultScoreMoves, u32 battler);
void ComputeBattlerDecisions(u32 battler);
u32 BattleAI_ChooseMoveIndex(u32 battler);
void Ai_InitPartyStruct(void);
void Ai_UpdateSwitchInData(u32 battler);
void Ai_UpdateFaintData(u32 battler);
void SetAiLogicDataForTurn(struct AiLogicData *aiData);
void ResetDynamicAiFunc(void);

bool8 BattlerHasInnate(u8 battlerId, u16 ability);
u8 BattlerHasTrait(u8 battlerId, u16 ability); //Returns the trait slot number of the given ability. Starts at 1 for the primary Ability and returns 0 if the ability is not found. 
u8 BattlerHasTraitPlain(u8 battlerId, u16 ability); //BattlerHasTrait for functions already under GetBattlerAbility to avoid infinite loops.
void PushTraitStack(u8 battlerId, u16 ability); //Pushes an ability to the trait stack
u8 PullTraitStackBattler(void); //Pulls a battler from the trait stack
u16 PullTraitStackAbility(void); //Pulls a battler from the trait stack
void PopTraitStack(void); //Pops an ability from the trait stack and clears the slot

#endif // GUARD_BATTLE_AI_MAIN_H
