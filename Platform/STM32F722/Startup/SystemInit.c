#include "RccMap.h"
#include "Gpio.h"

/* Reference link: https://www.linkedin.com/pulse/stm32-clock-configuration-bare-metal-deep-dive-gheorghe-prelipcean-9jivf */

#define REG_WRITE(reg, value)       (*reg = value)
#define SET_BIT(reg, bitPos)        (*reg |= (1U << bitPos))
#define CLEAR_BIT(reg, bitPos)      (*reg &= ~(1U << bitPos))
#define CHECK_BIT(reg, bitPos)      (*reg & (1U << bitPos))
 
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
    /* Turn HSE on */
    SET_BIT(RCC_CR, HSE_ON);
    while (!CHECK_BIT(RCC_CR, HSE_RDY));

    /* Enable GPIOA clock */
    SET_BIT(RCC_AHB1ENR, GPIOA_EN);

    /* Configure PA8 as MCO1 */
    CLEAR_BIT(GPIO_GPIOA_MODER, PA08_0);
    CLEAR_BIT(GPIO_GPIOA_MODER, PA08_1);

    SET_BIT(GPIO_GPIOA_MODER, PA08_1);

    /* Set to push-pull */
    CLEAR_BIT(GPIO_GPIOA_OTYPER, 8);

    /* Set pin to very high speed */
    SET_BIT(GPIO_GPIOA_OSPEEDR, 16);
    SET_BIT(GPIO_GPIOA_OSPEEDR, 17);

    CLEAR_BIT(GPIO_GPIOA_PUPDR, 16);
    CLEAR_BIT(GPIO_GPIOA_PUPDR, 17);

    /* Configure MCO1 output source */
    CLEAR_BIT(GPIO_GPIOx_AFRH(GPIOA_BASE), 0);
    CLEAR_BIT(GPIO_GPIOx_AFRH(GPIOA_BASE), 1);
    CLEAR_BIT(GPIO_GPIOx_AFRH(GPIOA_BASE), 2);
    CLEAR_BIT(GPIO_GPIOx_AFRH(GPIOA_BASE), 3);

    /* Set MCO1 as the clock output with HSE */
    CLEAR_BIT(RCC_CFGR, MCO_0);
    SET_BIT(RCC_CFGR, MCO_1);

    /* Adjust pre-scalers for MCO1 */
    CLEAR_BIT(RCC_CFGR, MCO_PRE_0);
    CLEAR_BIT(RCC_CFGR, MCO_PRE_1);
    CLEAR_BIT(RCC_CFGR, MCO_PRE_2);

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
