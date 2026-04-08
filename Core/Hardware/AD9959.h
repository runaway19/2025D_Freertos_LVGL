#ifndef _AD9959_H_
#define _AD9959_H_
#include "main.h"
#include "stdint.h"
//AD9959寄存器地址定义
#define CSR_ADD   0x00   //CSR 通道选择寄存器
#define FR1_ADD   0x01   //FR1 功能寄存器1
#define FR2_ADD   0x02   //FR2 功能寄存器2
#define CFR_ADD   0x03   //CFR 通道功能寄存器
#define CFTW0_ADD 0x04   //CTW0 通道频率转换字寄存器
#define CPOW0_ADD 0x05   //CPW0 通道相位转换字寄存器
#define ACR_ADD   0x06   //ACR 幅度控制寄存器
#define LSRR_ADD  0x07   //LSR 通道线性扫描寄存器
#define RDW_ADD   0x08   //RDW 通道线性向上扫描寄存器
#define FDW_ADD   0x09   //FDW 通道线性向下扫描寄存器
//AD9959管脚宏定义
#define SDIO0_0						HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET)
#define SDIO1_0						HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET)
#define SDIO2_0						HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET)
#define SDIO3_0						HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET)
#define PS0_0							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET)
#define PS1_0							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET)
#define PS2_0							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET)
#define PS3_0							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET)

#define SCLK_0				    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_RESET)
#define CS_0							HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET)
#define UPDATE_0					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET)
#define Reset_0						HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET)
#define AD9959_PWR_0			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET)



#define SDIO0_1						HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET)
#define SDIO1_1						HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET)
#define SDIO2_1						HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET)
#define SDIO3_1						HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET)
#define PS0_1							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET)
#define PS1_1							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET)
#define PS2_1							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET)
#define PS3_1							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET)

#define SCLK_1				    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_SET)
#define CS_1							HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET)
#define UPDATE_1					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_SET)
#define Reset_1						HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET)
#define AD9959_PWR_1			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET)

void delay1 (uint32_t length);
void IntReset(void);	  //AD9959复位
void IO_Update(void);   //AD9959更新数据
void Intserve(void);		   //IO口初始化
void WriteData_AD9959(uint8_t RegisterAddress, uint8_t NumberofRegisters, uint8_t *RegisterData,uint8_t temp);
void Init_AD9959(void);
void Write_frequence(uint8_t Channel,uint32_t Freq);
void Write_Amplitude(uint8_t Channel, uint16_t Ampli);
void Write_Phase(uint8_t Channel,uint16_t Phase);

#endif


