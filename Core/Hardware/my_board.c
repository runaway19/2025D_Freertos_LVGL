#include "my_board.h"

//放置初始化文件

uint16_t adc_buffer[ADC_BUFFER_SIZE]; 
__IO uint8_t AdcConvEnd = 0;



void init_board()
{
  HAL_TIM_Base_Start_IT(&htim3); // 启动定时器和定时器中 1Hz
  HAL_TIM_Base_Start(&htim2);
	
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_buffer, ADC_BUFFER_SIZE);
	while (!AdcConvEnd)                                   //等待转换完毕
    ;
	
	USART1_Printf("%.3f\n", adc_buffer[0] * 3.3 / 4095);
	
	
	Init_AD9959();
	
	Write_frequence(3,100000);
	Write_frequence(2,100000);

	Write_Phase(3, 0);
	Write_Phase(2, 0);

	Write_Amplitude(3, 1023);
	Write_Amplitude(2, 1023);
}
