#ifndef GPIO_H
#define GPIO_H

#include "MemoryMap.h"

/* GPIO base addresses (absolute) */
#define GPIOA_BASE 0x40020000U
#define GPIOB_BASE 0x40020400U
#define GPIOC_BASE 0x40020800U
#define GPIOD_BASE 0x40020C00U
#define GPIOE_BASE 0x40021000U
#define GPIOF_BASE 0x40021400U
#define GPIOG_BASE 0x40021800U
#define GPIOH_BASE 0x40021C00U
#define GPIOI_BASE 0x40022000U

/* MODER registers */
#define GPIO_GPIOA_MODER  ((volatile unsigned int*)(GPIOA_BASE + 0x00))
#define GPIO_GPIOB_MODER  ((volatile unsigned int*)(GPIOB_BASE + 0x00))
#define GPIO_GPIOC_MODER  ((volatile unsigned int*)(GPIOC_BASE + 0x00))
#define GPIO_GPIOx_MODER(base) ((volatile unsigned int*)((base) + 0x00))

/* OTYPER registers */
#define GPIO_GPIOA_OTYPER ((volatile unsigned int*)(GPIOA_BASE + 0x04))
#define GPIO_GPIOB_OTYPER ((volatile unsigned int*)(GPIOB_BASE + 0x04))
#define GPIO_GPIOC_OTYPER ((volatile unsigned int*)(GPIOC_BASE + 0x04))
#define GPIO_GPIOx_OTYPER(base) ((volatile unsigned int*)((base) + 0x04))

/* OSPEEDR registers */
#define GPIO_GPIOA_OSPEEDR ((volatile unsigned int*)(GPIOA_BASE + 0x08))
#define GPIO_GPIOB_OSPEEDR ((volatile unsigned int*)(GPIOB_BASE + 0x08))
#define GPIO_GPIOC_OSPEEDR ((volatile unsigned int*)(GPIOC_BASE + 0x08))
#define GPIO_GPIOx_OSPEEDR(base) ((volatile unsigned int*)((base) + 0x08))

/* PUPDR registers */
#define GPIO_GPIOA_PUPDR   ((volatile unsigned int*)(GPIOA_BASE + 0x0C))
#define GPIO_GPIOB_PUPDR   ((volatile unsigned int*)(GPIOB_BASE + 0x0C))
#define GPIO_GPIOC_PUPDR   ((volatile unsigned int*)(GPIOC_BASE + 0x0C))
#define GPIO_GPIOx_PUPDR(base) ((volatile unsigned int*)((base) + 0x0C))

/* IDR / ODR / BSRR / LCKR */
#define GPIO_GPIOx_IDR(base)  ((volatile unsigned int*)((base) + 0x10))
#define GPIO_GPIOx_ODR(base)  ((volatile unsigned int*)((base) + 0x14))
#define GPIO_GPIOx_BSRR(base) ((volatile unsigned int*)((base) + 0x18))
#define GPIO_GPIOx_LCKR(base) ((volatile unsigned int*)((base) + 0x1C))

/* AFRL / AFRH */
#define GPIO_GPIOx_AFRL(base) ((volatile unsigned int*)((base) + 0x20))
#define GPIO_GPIOx_AFRH(base) ((volatile unsigned int*)((base) + 0x24))

#define PA08_PIN (3U)
#define PA08_0   (16U)
#define PA08_1   (17U)

#endif
