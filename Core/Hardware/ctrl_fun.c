#include "ctrl_fun.h"
#include "gpio.h"

/**
 * @brief  通用 GPIO 电平切换函数
 * @param  GPIOx: 端口 (如 GPIOA, GPIOC, GPIOE)
 * @param  GPIO_Pin: 引脚号 (如 TX_1)
 * @param  level: 1 为高电平，0 为低电平
 */
void ctrl_tx_pin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t level)
{
	if (level) 
	{
		HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
	} 
	else 
	{
		HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
	}
}