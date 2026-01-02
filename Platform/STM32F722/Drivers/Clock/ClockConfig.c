#include "Clock/ClockConfig.h"

void Clock_SetHSESource() {
    SET_BIT(RCC_CR, HSE_ON);
    while (!CHECK_BIT(RCC_CR, HSE_RDY));
}

void Clock_SetHSISource() {

}

void Clock_SetPLLSource() {

}

void Clock_SetMCO1Output() {
    WRITE_VALUE(RCC_CFGR, MCO, 0x2);
}

void Clock_SetMCO2Output() {

}

void Clock_SetPrescaler() {
    CLEAR_VALUE(RCC_CFGR, MCO_PRE, 0x7);
}

void Clock_EnablePortxClock(GPIOx_CLOCK portClock) {
    switch (portClock) {
        case GPIOA_CLOCK:
        case GPIOB_CLOCK:
        case GPIOC_CLOCK:
        case GPIOD_CLOCK:
        case GPIOE_CLOCK:
        case GPIOF_CLOCK:
        case GPIOG_CLOCK:
        case GPIOH_CLOCK:
        case GPIOI_CLOCK:
            break;
        default:
            return;
    }

    SET_BIT(RCC_AHB1ENR, portClock);
}

void Clock_DisablePortxClock(GPIOx_CLOCK portClock) {

}
