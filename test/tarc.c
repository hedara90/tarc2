#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "pokemon.h"
#include "test/overworld_script.h"
#include "test/test.h"

TEST("Print Bosses")
{
    for (u32 i = 0; i < SPECIES_EGG; i++)
    {
        if (gSpeciesInfo[i].isPlayer)
        {
            Test_MgbaPrintf("%S", gSpeciesInfo[i].speciesName);
        }
    }
}
