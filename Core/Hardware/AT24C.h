#ifndef _AT24C_H
#define _AT24C_H

#include "main.h"
#include <stdio.h> 
#include <stdint.h>
#include "my_fun.h"

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;

//IO方向设置
//#define SDA_IN() 1
//#define SDA_OUT() 2
#define SDA_IN()  { \
    GPIOB->MODER &= ~(3U << (11 * 2)); \
    GPIOB->MODER |= (0U << (11 * 2));  \
}
#define SDA_OUT() { \
    GPIOB->MODER &= ~(3U << (11 * 2)); \
    GPIOB->MODER |= (1U << (11 * 2));  \
}

//IO操作函数	 
#define IIC_SCL_PORT  GPIOB
#define IIC_SCL_PIN   GPIO_PIN_10

#define IIC_SDA_PORT  GPIOB
#define IIC_SDA_PIN   GPIO_PIN_11
//#define IIC_SDA_PIN_NUM    11

#define IIC_SCL_H  HAL_GPIO_WritePin(IIC_SCL_PORT, IIC_SCL_PIN, GPIO_PIN_SET)
#define IIC_SCL_L  HAL_GPIO_WritePin(IIC_SCL_PORT, IIC_SCL_PIN, GPIO_PIN_RESET)

#define IIC_SDA_H  HAL_GPIO_WritePin(IIC_SDA_PORT, IIC_SDA_PIN, GPIO_PIN_SET)
#define IIC_SDA_L  HAL_GPIO_WritePin(IIC_SDA_PORT, IIC_SDA_PIN, GPIO_PIN_RESET)

#define IIC_READ_SDA  HAL_GPIO_ReadPin(IIC_SDA_PORT, IIC_SDA_PIN)


#define AT24C01		127
#define AT24C02		255
#define AT24C04		511
#define AT24C08		1023
#define AT24C16		2047
#define AT24C32		4095
#define AT24C64	    8191
#define AT24C128	16383
#define AT24C256	32767  

//开发板使用的是24c02，所以定义EE_TYPE为AT24C02
#define EE_TYPE AT24C08

u8 AT24CXX_ReadOneByte(u16 ReadAddr);							//指定地址读取一个字节
void AT24CXX_WriteOneByte(u16 WriteAddr,u8 DataToWrite);		//指定地址写入一个字节
void AT24CXX_WriteLenByte(u16 WriteAddr,u32 DataToWrite,u8 Len);//指定地址开始写入指定长度的数据
u32 AT24CXX_ReadLenByte(u16 ReadAddr,u8 Len);					//指定地址开始读取指定长度数据
void AT24CXX_Write(u16 WriteAddr,u8 *pBuffer,u16 NumToWrite);	//从指定地址开始写入指定长度的数据
void AT24CXX_Read(u16 ReadAddr,u8 *pBuffer,u16 NumToRead);   	//从指定地址开始读出指定长度的数据

u8 AT24CXX_Check(void);  //检查器件

#endif
