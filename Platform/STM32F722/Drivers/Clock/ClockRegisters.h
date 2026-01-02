#ifndef CLOCKREGISTERS_H
#define CLOCKREGISTERS_H

#include "MemoryMap.h"
#include "Utilities.h"

/* Chapter 5.3.27 of user manual : RCC register map */

#define RCC_CR        (volatile unsigned int*)RCC_BASE
#define RCC_PLLCFGR   (volatile unsigned int*)(RCC_BASE + 0x04U)
#define RCC_CFGR      (volatile unsigned int*)(RCC_BASE + 0x08U)
#define RCC_CIR       (volatile unsigned int*)(RCC_BASE + 0x0C)
#define RCC_AHB1RSTR  (volatile unsigned int*)(RCC_BASE + 0x10)
#define RCC_AHB2RSTR  (volatile unsigned int*)(RCC_BASE + 0x14)
#define RCC_AHB3RSTR  (volatile unsigned int*)(RCC_BASE + 0x18)

/* Offset 0x1C reserved */

#define RCC_APB1RSTR  (volatile unsigned int*)(RCC_BASE + 0x20U)
#define RCC_APB2RSTR  (volatile unsigned int*)(RCC_BASE + 0x24)

/* Offset 0x28 reserved */
/* Offset 0x2C reserved */

#define RCC_AHB1ENR   (volatile unsigned int*)(RCC_BASE + 0x30U)
#define RCC_AHB2ENR   (volatile unsigned int*)(RCC_BASE + 0x34)
#define RCC_AHB3ENR   (volatile unsigned int*)(RCC_BASE + 0x38)

/* Offset 0x3C reserved */

#define RCC_APB1ENR   (volatile unsigned int*)(RCC_BASE + 0x40)
#define RCC_APB2ENR   (volatile unsigned int*)(RCC_BASE + 0x44)

/* Offset 0x48 reserved */
/* Offset 0x4C reserved */

#define RCC_AHB1LPENR (volatile unsigned int*)(RCC_BASE + 0x50)
#define RCC_AHB2LPENR (volatile unsigned int*)(RCC_BASE + 0x54)
#define RCC_AHB3LPENR (volatile unsigned int*)(RCC_BASE + 0x58)

/* Offset 0x5C reserved */

#define RCC_APB1LPENR (volatile unsigned int*)(RCC_BASE + 0x60)
#define RCC_APB2LPENR (volatile unsigned int*)(RCC_BASE + 0x64)

/* Offset 0x68 reserved */
/* Offset 0x6C reserved */

typedef enum {
    GPIOA_CLOCK = 0,
    GPIOB_CLOCK,
    GPIOC_CLOCK,
    GPIOD_CLOCK,
    GPIOE_CLOCK,
    GPIOF_CLOCK,
    GPIOG_CLOCK,
    GPIOH_CLOCK,
    GPIOI_CLOCK
} GPIOx_CLOCK;

/* CR */
#define HSI_ON     (0U)
#define HSI_RDY    (1U)

#define HSE_ON     (16U)
#define HSE_RDY    (17U)

#define PLL_ON     (24U)

#define PLLSAI_ON  (28U)

#define HSI_TRIM_5 (7U)

/* CFGR */
#define HSI_CLK_0  (0U)
#define HSI_CLK_1  (1U)

#define MCO        (21U)

#define MCO_PRE    (24U)

#endif
