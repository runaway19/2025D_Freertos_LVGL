#ifndef __MY_FUN_H
#define __MY_FUN_H

#include "gpio.h"
#include "tim.h"
#include "cmsis_os.h"
#include "usart.h"

//变量声明
extern GPIO_TypeDef* TX_PORTS[];
extern uint16_t TX_PINS[];
extern GPIO_TypeDef* RX_PORTS[];
extern uint16_t RX_PINS[];
extern uint8_t short_matrix[8][8];


//函数声明
uint16_t detect_short(void);
uint8_t is_SFTP(void);
void ctrl_tx_pin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t level);
uint8_t read_gpio_level(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void delay_us(uint32_t us);
void delay_us_init(void); 

#endif

