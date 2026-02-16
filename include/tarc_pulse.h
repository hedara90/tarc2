#ifndef GUARD_TARC_PULSE_H
#define GUARD_TARC_PULSE_H

#include "gba/types.h"
#include "global.h"

extern u32 gPulseState;

void Init_PulseNeonLights(void);
void Task_WaitForFade(u8 taskId);
void Task_PulseNeonLights(u8 taskId);
void PauseNeonPulse(void);
void UnpauseNeonPulse(void);

#endif
