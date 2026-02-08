#ifndef CLOCKCONFIG_H
#define CLOCKCONFIG_H

#include "Clock/ClockRegisters.h"

void ClockSetHSESource();
void ClockSetHSISource();
void ClockSetPLLSource();
void ClockSetMCO1Output();
void ClockSetMCO2Output();
void ClockSetPrescaler();
void ClockEnablePortxClock(GPIOx_CLOCK portClock);
void ClockDisablePortxClock(GPIOx_CLOCK portClock);

#endif
