#ifndef GUARD_HUNT_SETUP_H
#define GUARD_HUNT_SETUP_H

#include "global.h"
#include "constants/hunt_setup.h"

struct BossGroup
{
    u32 numMembers;
    u16 members[];
};


struct StarterMon
{
    u16 species;
    u16 moves[4];
};

void SetupHuntTargets(enum FinalBossList finalBoss);
void SetupPlayerMons(enum PlayerMonList monList);

#endif //GUARD_HUNT_SETUP_H
