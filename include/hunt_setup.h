#ifndef GUARD_HUNT_SETUP_H
#define GUARD_HUNT_SETUP_H

#include "global.h"
#include "random.h"
#include "script.h"
#include "constants/hunt_setup.h"

struct BossGroup
{
    u32 numMembers;
    u16 members[];
};


struct StarterMon
{
    u16 species;
    u16 moves[2];
};

struct StarterPool
{
    u32 numMons;
    const struct StarterMon mons[];
};

void SetupHuntTargets(enum FinalBossList finalBoss);
void SetupPlayerMons(enum PlayerMonList monList, rng_value_t *localRngState);
void SetAffinityFromScript(struct ScriptContext *ctx);
void ChooseCurrentBossFromScript(struct ScriptContext *ctx);
void SetPostBattleData(void);
void SetLossData(void);
void SetWinData(void);

#endif //GUARD_HUNT_SETUP_H
