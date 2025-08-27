#include "global.h"
#include "battle.h"
#include "battle_ai_main.h"
#include "main.h"
#include "move.h"
#include "constants/abilities.h"

#include "data/moves_info.h"

bool32 IsSlicingMove(u32 moveId, u32 battler)
{
    if (gMovesInfo[moveId].type == TYPE_ICE && BattlerHasTrait(battler, ABILITY_BLADES_OF_FROST))
    {
        return TRUE;
    }
    return gMovesInfo[SanitizeMoveId(moveId)].slicingMove;
}
