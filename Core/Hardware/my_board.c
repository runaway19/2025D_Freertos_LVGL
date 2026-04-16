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
	
	//微秒延时初始化
	delay_us_init(); 

	USART1_Printf("%.3f\n", adc_buffer[0] * 3.3 / 4095);
	
	//DDS
	AD9834_Init();
	AD9834_Select_Wave(Sine_Wave);
	AD9834_Set_Freq(FREQ_0, 30000000);
	
	while(AT24CXX_Check())  //检测AT24C02是否正常
	{
		delay_us(50000);
	}
//	extern_flash_test();
	
}


