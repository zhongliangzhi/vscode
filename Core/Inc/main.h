/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include "task.h"
#include "i2c_hal.h"
#include "stdio.h"
#include "led.h"
#include "tim.h"
#include "key.h"
extern char text[30];
extern int jiemian;  //数据 参数 记录
extern int fre_A,fre_B;
extern int Fre_A,Fre_B; 
extern int f_LCD,f_led,f_key;
extern int PH,PD,PX;
extern int NDA,NDB,NHA,NHB;
extern char jiemian_f;
extern int key_time;
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

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
#define Led_Pin GPIO_PIN_13
#define Led_GPIO_Port GPIOC
#define LedC14_Pin GPIO_PIN_14
#define LedC14_GPIO_Port GPIOC
#define LedC15_Pin GPIO_PIN_15
#define LedC15_GPIO_Port GPIOC
#define LCD_Pin GPIO_PIN_0
#define LCD_GPIO_Port GPIOC
#define LCDC1_Pin GPIO_PIN_1
#define LCDC1_GPIO_Port GPIOC
#define LCDC2_Pin GPIO_PIN_2
#define LCDC2_GPIO_Port GPIOC
#define LCDC3_Pin GPIO_PIN_3
#define LCDC3_GPIO_Port GPIOC
#define LCDC4_Pin GPIO_PIN_4
#define LCDC4_GPIO_Port GPIOC
#define LCDC5_Pin GPIO_PIN_5
#define LCDC5_GPIO_Port GPIOC
#define LCDC6_Pin GPIO_PIN_6
#define LCDC6_GPIO_Port GPIOC
#define LCDC7_Pin GPIO_PIN_7
#define LCDC7_GPIO_Port GPIOC
#define LedC8_Pin GPIO_PIN_8
#define LedC8_GPIO_Port GPIOC
#define LedC9_Pin GPIO_PIN_9
#define LedC9_GPIO_Port GPIOC
#define LedC10_Pin GPIO_PIN_10
#define LedC10_GPIO_Port GPIOC
#define LedC11_Pin GPIO_PIN_11
#define LedC11_GPIO_Port GPIOC
#define LedC12_Pin GPIO_PIN_12
#define LedC12_GPIO_Port GPIOC
#define LCDB5_Pin GPIO_PIN_5
#define LCDB5_GPIO_Port GPIOB
#define LCDB8_Pin GPIO_PIN_8
#define LCDB8_GPIO_Port GPIOB
#define LCDB9_Pin GPIO_PIN_9
#define LCDB9_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
