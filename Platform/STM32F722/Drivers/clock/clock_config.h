#ifndef CLOCKCONFIG_H
#define CLOCKCONFIG_H

#include "clock/clock_registers.h"

void clock_set_hse_source();
void clock_set_hsi_source();
void clock_set_pll_source();
void clock_set_mco1_output();
void clock_set_mco2_output();
void clock_set_prescaler();
void clock_enable_portx_clock(GPIOx_CLOCK port_clock);
void clock_disable_portx_clock(GPIOx_CLOCK port_clock);

#endif
