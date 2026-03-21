/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#define CCMRAM __attribute__((section("ccmram")))
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_CS_Pin GPIO_PIN_6
#define LCD_CS_GPIO_Port GPIOE
#define LCD_RS_Pin GPIO_PIN_0
#define LCD_RS_GPIO_Port GPIOC
#define LCD_RST_Pin GPIO_PIN_1
#define LCD_RST_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_6
#define LED2_GPIO_Port GPIOA
#define LED3_Pin GPIO_PIN_7
#define LED3_GPIO_Port GPIOA
#define TX_1_Pin GPIO_PIN_7
#define TX_1_GPIO_Port GPIOE
#define TX_2_Pin GPIO_PIN_8
#define TX_2_GPIO_Port GPIOE
#define TX_3_Pin GPIO_PIN_9
#define TX_3_GPIO_Port GPIOE
#define TX_4_Pin GPIO_PIN_10
#define TX_4_GPIO_Port GPIOE
#define TX_5_Pin GPIO_PIN_11
#define TX_5_GPIO_Port GPIOE
#define TX_6_Pin GPIO_PIN_12
#define TX_6_GPIO_Port GPIOE
#define TX_7_Pin GPIO_PIN_13
#define TX_7_GPIO_Port GPIOE
#define TX_8_Pin GPIO_PIN_14
#define TX_8_GPIO_Port GPIOE
#define TX_9_Pin GPIO_PIN_15
#define TX_9_GPIO_Port GPIOE
#define RX_9_Pin GPIO_PIN_12
#define RX_9_GPIO_Port GPIOC
#define RX_1_Pin GPIO_PIN_0
#define RX_1_GPIO_Port GPIOD
#define RX_2_Pin GPIO_PIN_1
#define RX_2_GPIO_Port GPIOD
#define RX_3_Pin GPIO_PIN_2
#define RX_3_GPIO_Port GPIOD
#define RX_4_Pin GPIO_PIN_3
#define RX_4_GPIO_Port GPIOD
#define RX_5_Pin GPIO_PIN_4
#define RX_5_GPIO_Port GPIOD
#define RX_6_Pin GPIO_PIN_5
#define RX_6_GPIO_Port GPIOD
#define RX_7_Pin GPIO_PIN_6
#define RX_7_GPIO_Port GPIOD
#define RX_8_Pin GPIO_PIN_7
#define RX_8_GPIO_Port GPIOD
#define CTP_INT_Pin GPIO_PIN_6
#define CTP_INT_GPIO_Port GPIOB
#define CTP_INT_EXTI_IRQn EXTI9_5_IRQn
#define CTP_RST_Pin GPIO_PIN_7
#define CTP_RST_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
