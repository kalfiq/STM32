#ifndef GPIO_H
#define GPIO_H

#include "Gpio/GpioRegisters.h"

void GPIO_SetAlternateMode();
void GPIO_SetToPushPull();
void GPIO_SetHighSpeed();
void GPIO_SetNoPullUpPullDown();
void GPIO_SetPA8();

#endif
