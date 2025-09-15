#include "tarc_pulse.h"
#include "task.h"
#include "gba/defines.h"
#include "palette.h"

#define COLOUR_TO_PULSE 54

struct PulseData
{
    u32 colorIndex;
    u32 upperLimit;
    u32 lowerLimit;
    u32 stepChange;
};

enum PulseColors
{
    PULSE_ONE,
    PULSE_TWO,
    PULSE_COUNT,
};

const struct PulseData sPulseDatas[PULSE_COUNT] =
{
    [PULSE_ONE] =
    {
        .colorIndex = 54,
        .upperLimit = 0x05 + (0x0d << 5) + (30 << 10),
        .lowerLimit = 0x05 + (0x0d << 5) + (19 << 10),
        .stepChange = 1 << 10,
    },
    [PULSE_TWO] =
    {
        .colorIndex = 20,
        .upperLimit = 0x05 + (0x0d << 5) + (30 << 10),
        .lowerLimit = 0x05 + (0x0d << 5) + (19 << 10),
        .stepChange = 1 << 10,
    },
};

EWRAM_DATA u32 gPulseState;
EWRAM_DATA s8 sPulseDirections[PULSE_COUNT];

void Init_PulseNeonLights(void)
{
    gPulseState = 0;
    for (u32 i = 0; i < PULSE_COUNT; i++)
        sPulseDirections[i] = 1;
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
        for (u32 i = 0; i < PULSE_COUNT; i++)
        {
            u16 *palAddress = (u16 *)(BG_PLTT + sPulseDatas[i].colorIndex * 2);
            u32 currColor = *palAddress;
            if (currColor >= sPulseDatas[i].upperLimit)
                sPulseDirections[i] = -1;
            else if (currColor <= sPulseDatas[i].lowerLimit)
                sPulseDirections[i] = 1;

            if (sPulseDirections[i] == 1)
                currColor += sPulseDatas[i].stepChange;
            else
                currColor -= sPulseDatas[i].stepChange;

            *palAddress = currColor;
            gPlttBufferUnfaded[sPulseDatas[i].colorIndex] = currColor;
            gPlttBufferFaded[sPulseDatas[i].colorIndex] = currColor;
        }
    }
    gPulseState++;
}
