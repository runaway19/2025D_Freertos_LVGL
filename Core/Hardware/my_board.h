#ifndef __MY_BOARD_H
#define __MY_BOARD_H

#include "main.h"
#include <stdio.h> 
#include <stdarg.h>
#include "usart.h"
#include "AD9959.H"
#include "AD9834.h" 
#include "flash.h"


#define ADC_BUFFER_SIZE 1024

//硬件句柄声明
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern ADC_HandleTypeDef hadc1;


//变量声明
extern __IO uint8_t AdcConvEnd; 
extern uint16_t adc_buffer[];

//函数声明
void init_board(void);


#endif

