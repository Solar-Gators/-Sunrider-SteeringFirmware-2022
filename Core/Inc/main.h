/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RT_Button_Pin GPIO_PIN_13
#define RT_Button_GPIO_Port GPIOC
#define RT_Button_EXTI_IRQn EXTI4_15_IRQn
#define RT_Led_Pin GPIO_PIN_14
#define RT_Led_GPIO_Port GPIOC
#define Cruise_P_Pin GPIO_PIN_15
#define Cruise_P_GPIO_Port GPIOC
#define Cruise_P_EXTI_IRQn EXTI4_15_IRQn
#define Horn_Button_Pin GPIO_PIN_0
#define Horn_Button_GPIO_Port GPIOC
#define Horn_Button_EXTI_IRQn EXTI0_1_IRQn
#define Cruise_Button_Pin GPIO_PIN_1
#define Cruise_Button_GPIO_Port GPIOC
#define Cruise_Button_EXTI_IRQn EXTI0_1_IRQn
#define Cruise_Led_Pin GPIO_PIN_2
#define Cruise_Led_GPIO_Port GPIOC
#define Reverse_Button_Pin GPIO_PIN_3
#define Reverse_Button_GPIO_Port GPIOC
#define Reverse_Button_EXTI_IRQn EXTI2_3_IRQn
#define Reverse_Led_Pin GPIO_PIN_0
#define Reverse_Led_GPIO_Port GPIOA
#define User_LED_Pin GPIO_PIN_5
#define User_LED_GPIO_Port GPIOC
#define ERROR_LED_Pin GPIO_PIN_0
#define ERROR_LED_GPIO_Port GPIOB
#define Haz_Button_Pin GPIO_PIN_12
#define Haz_Button_GPIO_Port GPIOB
#define Haz_Button_EXTI_IRQn EXTI4_15_IRQn
#define LCD_RST_Pin GPIO_PIN_14
#define LCD_RST_GPIO_Port GPIOB
#define HL_Led_Pin GPIO_PIN_6
#define HL_Led_GPIO_Port GPIOC
#define HL_Button_Pin GPIO_PIN_7
#define HL_Button_GPIO_Port GPIOC
#define HL_Button_EXTI_IRQn EXTI4_15_IRQn
#define Eco_Led_Pin GPIO_PIN_8
#define Eco_Led_GPIO_Port GPIOC
#define Eco_Button_Pin GPIO_PIN_9
#define Eco_Button_GPIO_Port GPIOC
#define Eco_Button_EXTI_IRQn EXTI4_15_IRQn
#define Cruise_M_Pin GPIO_PIN_8
#define Cruise_M_GPIO_Port GPIOA
#define Cruise_M_EXTI_IRQn EXTI4_15_IRQn
#define LT_Led_Pin GPIO_PIN_9
#define LT_Led_GPIO_Port GPIOA
#define LT_Button_Pin GPIO_PIN_10
#define LT_Button_GPIO_Port GPIOC
#define LT_Button_EXTI_IRQn EXTI4_15_IRQn
#define LCD_CS_Pin GPIO_PIN_2
#define LCD_CS_GPIO_Port GPIOD
#define TP_IRQ_Pin GPIO_PIN_4
#define TP_IRQ_GPIO_Port GPIOB
#define TP_IRQ_EXTI_IRQn EXTI4_15_IRQn
#define TP_CS_Pin GPIO_PIN_6
#define TP_CS_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
