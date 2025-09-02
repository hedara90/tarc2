#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "pokemon.h"
#include "test/overworld_script.h"
#include "test/test.h"

TEST("Print Player mons")
{
    for (u32 i = 0; i < SPECIES_EGG; i++)
    {
        if (gSpeciesInfo[i].isPlayer)
        {
            Test_MgbaPrintf("%S", gSpeciesInfo[i].speciesName);
        }
    }
}

TEST("Print Minibosses")
{
    for (u32 i = 0; i < SPECIES_EGG; i++)
    {
        if (gSpeciesInfo[i].maxPhases == 2)
        {
            Test_MgbaPrintf("%S", gSpeciesInfo[i].speciesName);
        }
    }
}

TEST("Print Bosses")
{
    for (u32 i = 0; i < SPECIES_EGG; i++)
    {
        if (gSpeciesInfo[i].maxPhases == 3)
        {
            Test_MgbaPrintf("%S: %S", gSpeciesInfo[i].speciesName, gAbilitiesInfo[gSpeciesInfo[i].abilityReward].name);
        }
    }
}
