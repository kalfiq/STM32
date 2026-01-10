#include "clock/clock_config.h"

void clock_set_hse_source() {
    SET_BIT(RCC_CR, HSE_ON);
    while (!CHECK_BIT(RCC_CR, HSE_RDY));
}

void clock_set_hsi_source() {

}

void clock_set_pll_source() {

}

void clock_set_mco1_output() {
    WRITE_VALUE(RCC_CFGR, MCO, 0x2);
}

void clock_set_mco2_output() {

}

void clock_set_prescaler() {
    CLEAR_VALUE(RCC_CFGR, MCO_PRE, 0x7);
}

void clock_enable_portx_clock(GPIOx_CLOCK port_clock) {
    switch (port_clock) {
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

    SET_BIT(RCC_AHB1ENR, port_clock);
}

void clock_disable_portx_clock(GPIOx_CLOCK port_clock) {

}
