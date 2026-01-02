#include "Clock/ClockConfig.h"
#include "Gpio/Gpio.h"

/* Reference link: https://www.linkedin.com/pulse/stm32-clock-configuration-bare-metal-deep-dive-gheorghe-prelipcean-9jivf */

static inline void ResetRcc() {
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

static inline void SetVoltage() {

}

static inline void SetFlashLatency() {
    /* 1. Insert wait states to allow sufficient time for FLASH to fetch next instruction
     * 2. Enable instuction cache, data cache, and pre-fetch buffer for optimizing performance */

}

static inline void StartHSE() {

}

static inline void ConfigurePLL() {

}

static inline void SwitchToSysclk() {

}

static inline void ConfigureMCO1() {
    Clock_SetHSESource();

    Clock_EnablePortxClock(GPIOA_CLOCK);
    GPIO_SetAlternateMode();

    /* Set to push-pull */
    GPIO_SetToPushPull();

    /* Set pin to very high speed */
    GPIO_SetHighSpeed();

    GPIO_SetNoPullUpPullDown();

    /* Configure MCO1 output source */
    GPIO_SetPA8();

    Clock_SetMCO1Output();
}

void SystemInit() {
   /* This is the general sequence for setting up the clock */
    //ResetRcc();
//    SetVoltage();
//    SetFlashLatency();
//    StartHSE();
//    ConfigurePLL();
//    SwitchToSysclk();

    ConfigureMCO1();
}
