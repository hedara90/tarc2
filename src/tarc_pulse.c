#include "tarc_pulse.h"
#include "task.h"
#include "gba/defines.h"
#include "palette.h"

EWRAM_DATA u32 gPulseState;
EWRAM_DATA s32 gPulseDirection;

void Init_PulseNeonLights(void)
{
    gPulseState = 0;
    gPulseDirection = 1;
    CreateTask(Task_WaitForFade, 0);
}

void Task_WaitForFade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_PulseNeonLights;
    }
}

void Task_PulseNeonLights(u8 taskId)
{
    if ((gPulseState & 0x3) == 0)
    {
        u16 *palAddress = (u16 *)(BG_PLTT + 106*2);
        u32 currColor = palAddress[0];
        if (((currColor >> 10) & 0x1F) == 21)
        {
            gPulseDirection = -1;
        }
        else if (((currColor >> 10) & 0x1F) == 10)
        {
            gPulseDirection = 1;
        }
        if (gPulseDirection == 1)
        {
            currColor += 1 << 10;
        }
        else
        {
            currColor -= 1 << 10;
        }

        palAddress[0] = currColor;
        gPlttBufferUnfaded[106] = currColor;
        gPlttBufferFaded[106] = currColor;
    }
    gPulseState++;
}
