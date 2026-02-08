#include "Gpio/Gpio.h"

void GpioSetAlternateMode() 
{
    WRITE_VALUE(GPIO_GPIOA_MODER, PA08, 0x2);
}

void GpioSetToPushPull() 
{
    CLEAR_BIT(GPIO_GPIOA_OTYPER, 8);
}

void GpioSetHighSpeed() 
{
    WRITE_VALUE(GPIO_GPIOA_OSPEEDR, 16, 0x3);
}

void GpioSetNoPullUpPullDown() 
{
    CLEAR_VALUE(GPIO_GPIOA_PUPDR, 16, 0x3); 
}

void GpioSetPA08() 
{
    CLEAR_VALUE(GPIO_GPIOx_AFRH(GPIOA_BASE), 0, 0xF);
}
