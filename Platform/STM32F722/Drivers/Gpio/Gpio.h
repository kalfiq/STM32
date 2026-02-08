#ifndef GPIO_H
#define GPIO_H

#include "Gpio/GpioRegisters.h"

void GpioSetAlternateMode();
void GpioSetToPushPull();
void GpioSetHighSpeed();
void GpioSetNoPullUpPullDown();
void GpioSetPA08();

#endif
