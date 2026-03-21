#ifndef __CTRL_FUN_H
#define __CTRL_FUN_H

#include "gpio.h"

void ctrl_tx_pin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t level);
uint8_t read_gpio_level(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);


#endif

