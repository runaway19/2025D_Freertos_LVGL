#ifndef __MY_FUN_H
#define __MY_FUN_H

#include "gpio.h"
#include "tim.h"
#include "cmsis_os.h"
#include "usart.h"

uint16_t detect_short(void);
uint8_t is_SFTP(void);
void ctrl_tx_pin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t level);
uint8_t read_gpio_level(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);


#endif

