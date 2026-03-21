#include "my_fun.h"

//检测线是否是is_SFTP  返回1则是 返回0则不是
uint8_t is_SFTP(void)
{
	uint8_t result = 0;
	ctrl_tx_pin(GPIOE,TX_9_Pin,1);
	
	osDelay(5);
	
	if(read_gpio_level(GPIOC, RX_9_Pin))
	{
			result = 1;
	}
	else
	{
			result = 0;
	}
	ctrl_tx_pin(GPIOE, TX_9_Pin, 0);

  return result;
}

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

/**
 * @brief  读取指定 GPIO 引脚的电平状态
 * @param  GPIOx: 端口 (如 GPIOA, GPIOB)
 * @param  GPIO_Pin: 引脚号 (如 GPIO_PIN_0)
 * @return uint8_t: 1 为高电平, 0 为低电平
 */
uint8_t read_gpio_level(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    if (HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == GPIO_PIN_SET)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

