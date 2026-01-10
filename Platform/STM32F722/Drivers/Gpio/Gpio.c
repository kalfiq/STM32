#include "gpio/gpio.h"

void gpio_set_alternade_mode() {
    WRITE_VALUE(GPIO_GPIOA_MODER, PA08, 0x2);
}

void gpio_set_to_push_pull() {
    CLEAR_BIT(GPIO_GPIOA_OTYPER, 8);
}

void gpio_set_high_speed() {
    WRITE_VALUE(GPIO_GPIOA_OSPEEDR, 16, 0x3);
}

void gpio_set_no_pull_up_pull_down() {
    CLEAR_VALUE(GPIO_GPIOA_PUPDR, 16, 0x3); 
}

void gpio_set_pa8() {
    CLEAR_VALUE(GPIO_GPIOx_AFRH(GPIOA_BASE), 0, 0xF);
}
