#ifndef GPIO_H
#define GPIO_H

#include "gpio/gpio_registers.h"

void gpio_set_alternade_mode();
void gpio_set_to_push_pull();
void gpio_set_high_speed();
void gpio_set_no_pull_up_pull_down();
void gpio_set_pa8();

#endif
