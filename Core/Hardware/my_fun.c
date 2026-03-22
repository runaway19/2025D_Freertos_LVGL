#include "my_fun.h"

//  TX 端
GPIO_TypeDef* TX_PORTS[] = {GPIOE, GPIOE, GPIOE, GPIOE, GPIOE, GPIOE, GPIOE, GPIOE};
uint16_t TX_PINS[] = {TX_1_Pin, TX_2_Pin, TX_3_Pin, TX_4_Pin, TX_5_Pin, TX_6_Pin, TX_7_Pin, TX_8_Pin};

//  RX 端
GPIO_TypeDef* RX_PORTS[] = {GPIOD, GPIOD, GPIOD, GPIOD, GPIOD, GPIOD, GPIOD, GPIOD}; 
uint16_t RX_PINS[] = {RX_1_Pin, RX_2_Pin, RX_3_Pin, RX_4_Pin, RX_5_Pin, RX_6_Pin, RX_7_Pin, RX_8_Pin};

//记录短路情况
uint8_t short_matrix[8][8] = {0};  


/**
 * @brief  检测 1-8 号线是否存在短路
 * @return uint8_t: 0-正常, 1-存在短路
 */
uint16_t detect_short(void)
{
		uint8_t is_short = 0;
	
		//清空记录数据
		for (int i = 0; i < 8; i++) 
		{
					for (int j = 0; j < 8; j++) 
					{
							short_matrix[i][j] = 0;
					}
		}
	
    // TX 引脚都拉低
    for (int i = 0; i < 8; i++) 
	  {
        ctrl_tx_pin(TX_PORTS[i], TX_PINS[i], 0);
    }
    osDelay(5);

    // 扫描
    for (int i = 0; i < 8; i++) 
    {
        ctrl_tx_pin(TX_PORTS[i], TX_PINS[i], 1);
        osDelay(10); 
        // 读RX
        for (int j = 0; j < 8; j++) 
        {
            if (i == j) continue; // 跳过自己

            if (read_gpio_level(RX_PORTS[j], RX_PINS[j]) == 1) 
            {
								is_short = 1;
								short_matrix[i][j] = 1;
            }
        }
        // TX拉低
        ctrl_tx_pin(TX_PORTS[i], TX_PINS[i], 0);
    }
		
    return is_short;
}


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

