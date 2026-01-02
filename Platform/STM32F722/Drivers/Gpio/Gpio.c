#include "Gpio/Gpio.h"

void GPIO_SetAlternateMode() {
    WRITE_VALUE(GPIO_GPIOA_MODER, PA08, 0x2);
}

void GPIO_SetToPushPull() {
    CLEAR_BIT(GPIO_GPIOA_OTYPER, 8);
}

void GPIO_SetHighSpeed() {
    WRITE_VALUE(GPIO_GPIOA_OSPEEDR, 16, 0x3);
}

void GPIO_SetNoPullUpPullDown() {
    CLEAR_VALUE(GPIO_GPIOA_PUPDR, 16, 0x3); 
}

void GPIO_SetPA8() {
    CLEAR_VALUE(GPIO_GPIOx_AFRH(GPIOA_BASE), 0, 0xF);
}
