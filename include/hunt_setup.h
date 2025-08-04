#ifndef GUARD_HUNT_SETUP_H
#define GUARD_HUNT_SETUP_H

#include "global.h"

//  Add bosses before BOSS_COUNT
enum FinalBossList
{
    FINAL_BOSS_HO_OH,
    FINAL_BOSS_LUGIA,
    FINAL_BOSS_XERNEAS,
    FINAL_BOSS_YVELTAL,
    FINAL_BOSS_GIRATINA,
    FINAL_BOSS_COUNT,
    FINAL_BOSS_RANDOM,
    FINAL_BOSS_ARCEUS
};

enum BossGroupList
{
    BOSS_BIRDS,
    BOSS_BEASTS,
    BOSS_GOLEMS,
    BOSS_LAKES,
    BOSS_SWORDS,
    BOSS_GENIES,
    BOSS_TAPUS,
    BOSS_TREASURES,
    BOSS_LOYAL,
    BOSS_GALAR_BIRDS,
    BOSS_PARADOX_BEASTS,
    BOSS_PARADOX_SWORDS,
    BOSS_COUNT,
    BOSS_PSEUDOS,
};

enum MiniBossList
{
    MINI_BOSS_LAPRAS,
    MINI_BOSS_COUNT
};

struct BossGroup
{
    u32 numMembers;
    u16 members[];
};

enum PlayerMonList
{
    MON_LIST_RAIN_DIRECT,
    MON_LIST_RAIN_CONDITIONAL,
    MON_LIST_RAIN_MANUAL,
    MON_LIST_SUN_DIRECT,
    MON_LIST_SUN_CONDITIONAL,
    MON_LIST_SUN_MANUAL,
    MON_LIST_SNOW_DIRECT,
    MON_LIST_SNOW_CONDITIONAL,
    MON_LIST_SNOW_MANUAL,
    MON_LIST_SAND_DIRECT,
    MON_LIST_SAND_CONDITIONAL,
    MON_LIST_SAND_MANUAL,
    MON_LIST_RANDOM
};

struct StarterMon
{
    u16 species;
    u16 moves[4];
};

void SetupHuntTargets(enum FinalBossList finalBoss);
void SetupPlayerMons(enum PlayerMonList monList);

#endif //GUARD_HUNT_SETUP_H
