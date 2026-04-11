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
	
	AD9834_Init();
	AD9834_Select_Wave(Sine_Wave);
	AD9834_Set_Freq(FREQ_0, 30000000);
	
	USART1_Printf(" before_flash \n");
	InternalFlash_Test();
	USART1_Printf(" after_flash \n");
	
//	uint32_t test_data[2] = {0x12345678, 0x87654321};
//	uint32_t read_buf[2];

//	// 1. 擦除扇区 5 到 7
//	if (Flash_EraseSectors(ADDR_FLASH_SECTOR_5, ADDR_FLASH_SECTOR_7) == HAL_OK) 
//	{
//			// 2. 写入数据
//			if (Flash_WriteWords(ADDR_FLASH_SECTOR_5, test_data, 2) == HAL_OK) 
//			{
//					// 3. 读取数据
//					Flash_ReadWords(ADDR_FLASH_SECTOR_5, read_buf, 2);
//					
//					// 校验读取到的 read_buf[0] 是否等于 0x12345678
//			}
//	}
}
