#include "clock/clock_config.h"
#include "gpio/gpio.h"

/* Reference link: https://www.linkedin.com/pulse/stm32-clock-configuration-bare-metal-deep-dive-gheorghe-prelipcean-9jivf */

static inline void reset_rcc() {
    /* HSI on and default trim */
    SET_BIT(RCC_CR, HSI_ON);
    while (!CHECK_BIT(RCC_CR, HSI_RDY));
    SET_BIT(RCC_CR, HSI_TRIM_5);

    /* Select HSI as SYSCLK */
    SET_BIT(RCC_CFGR, HSI_CLK_0);
    SET_BIT(RCC_CFGR, HSI_CLK_1);

    /* HSE, PLL, PLLSAI off */
    CLEAR_BIT(RCC_CR, HSE_ON);
    CLEAR_BIT(RCC_CR, PLL_ON);
    CLEAR_BIT(RCC_CR, PLLSAI_ON);

    /* Reset all pre-scalers and clock selection */
    REG_WRITE(RCC_CFGR, (0x00000000U));

}

static inline void set_voltage() {

}

static inline void set_flash_latency() {
    /* 1. Insert wait states to allow sufficient time for FLASH to fetch next instruction
     * 2. Enable instuction cache, data cache, and pre-fetch buffer for optimizing performance */

}

static inline void start_hse() {

}

static inline void configure_pll() {

}

static inline void switch_to_sysclk() {

}

static inline void configure_mco1() {
    clock_set_hse_source();

    clock_enable_portx_clock(GPIOA_CLOCK);
    gpio_set_alternade_mode();

    /* Set to push-pull */
    gpio_set_to_push_pull();

    /* Set pin to very high speed */
    gpio_set_high_speed();

    gpio_set_no_pull_up_pull_down();

    /* Configure MCO1 output source */
    gpio_set_pa8();

    clock_set_mco1_output();
}

void system_init() {
   /* This is the general sequence for setting up the clock */
    //reset_rcc();
//    set_voltage();
//    set_flash_latency();
//    start_hse();
//    configure_pll();
//    switch_to_sysclk();

    configure_mco1();
}
