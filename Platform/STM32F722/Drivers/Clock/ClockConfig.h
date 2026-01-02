#ifndef CLOCKCONFIG_H
#define CLOCKCONFIG_H

#include "Clock/ClockRegisters.h"

void Clock_SetHSESource();
void Clock_SetHSISource();
void Clock_SetPLLSource();
void Clock_SetMCO1Output();
void Clock_SetMCO2Output();
void Clock_SetPrescaler();
void Clock_EnablePortxClock(GPIOx_CLOCK portClock);
void Clock_DisablePortxClock(GPIOx_CLOCK portClock);

#endif
