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
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern float gyro[3], accel[3], temp;
extern float INS_quat[4] ;
extern float INS_angle[3] ;
extern float INS_degree[3] ;

extern int16_t MOTOR_11_GIVEN_CURRENT ;
extern int16_t MOTOR_12_GIVEN_CURRENT ;
extern int16_t MOTOR_13_GIVEN_CURRENT ;
extern int16_t MOTOR_14_GIVEN_CURRENT ;
extern int16_t MOTOR_21_GIVEN_CURRENT ;
extern int16_t MOTOR_22_GIVEN_CURRENT ;
extern int16_t MOTOR_23_GIVEN_CURRENT ;
extern int16_t MOTOR_24_GIVEN_CURRENT ;

extern float MOTOR_11_GIVEN_SPEED ;
extern float MOTOR_12_GIVEN_SPEED ;
extern float MOTOR_13_GIVEN_SPEED ;
extern float MOTOR_14_GIVEN_SPEED ;
extern float MOTOR_21_GIVEN_SPEED ;
extern float MOTOR_22_GIVEN_SPEED ;
extern float MOTOR_23_GIVEN_SPEED ;
extern float MOTOR_24_GIVEN_SPEED ;

extern float MOTOR_11_GIVEN_ANGLE ;
extern float MOTOR_12_GIVEN_ANGLE ;
extern float MOTOR_13_GIVEN_ANGLE ;
extern float MOTOR_14_GIVEN_ANGLE ;
extern float MOTOR_21_GIVEN_ANGLE ;
extern float MOTOR_22_GIVEN_ANGLE ;
extern float MOTOR_23_GIVEN_ANGLE ;
extern float MOTOR_24_GIVEN_ANGLE ;


// ʵʱ�Ƕ�
extern float MOTOR_11_REAL_ABSC ;
extern float MOTOR_12_REAL_ABSC ;
extern float MOTOR_13_REAL_ABSC ;
extern float MOTOR_14_REAL_ABSC ;
extern float MOTOR_21_REAL_ABSC ;
extern float MOTOR_22_REAL_ABSC ;
extern float MOTOR_23_REAL_ABSC ;
extern float MOTOR_24_REAL_ABSC ;

extern float MOTOR_11_LAPS ;
extern float MOTOR_12_LAPS ;
extern float MOTOR_13_LAPS ;
extern float MOTOR_14_LAPS ;
extern float MOTOR_21_LAPS ;
extern float MOTOR_22_LAPS ;
extern float MOTOR_23_LAPS ;
extern float MOTOR_24_LAPS ;

extern float MOTOR_11_INIT_ANGLE ;
extern float MOTOR_12_INIT_ANGLE ;
extern float MOTOR_13_INIT_ANGLE ;
extern float MOTOR_14_INIT_ANGLE ;
extern float MOTOR_21_INIT_ANGLE ;
extern float MOTOR_22_INIT_ANGLE ;
extern float MOTOR_23_INIT_ANGLE ;
extern float MOTOR_24_INIT_ANGLE ;


extern float MOTOR_11_LAST_ECD ;
extern float MOTOR_12_LAST_ECD ;
extern float MOTOR_13_LAST_ECD ;
extern float MOTOR_14_LAST_ECD ;
extern float MOTOR_21_LAST_ECD ;
extern float MOTOR_22_LAST_ECD ;
extern float MOTOR_23_LAST_ECD ;
extern float MOTOR_24_LAST_ECD ;

//Ŀ�������Ƕ�
extern float MOTOR_11_TARGET_OUTPUT_SHAFT ;
extern float MOTOR_12_TARGET_OUTPUT_SHAFT ;
extern float MOTOR_13_TARGET_OUTPUT_SHAFT ;
extern float MOTOR_14_TARGET_OUTPUT_SHAFT ;
extern float MOTOR_21_TARGET_OUTPUT_SHAFT ;
extern float MOTOR_22_TARGET_OUTPUT_SHAFT ;
extern float MOTOR_23_TARGET_OUTPUT_SHAFT ;
extern float MOTOR_24_TARGET_OUTPUT_SHAFT ;

// Ŀ��Ƕ�
extern float MOTOR_11_TARGET_ABSC ;
extern float MOTOR_12_TARGET_ABSC ;
extern float MOTOR_13_TARGET_ABSC ;
extern float MOTOR_14_TARGET_ABSC ;
extern float MOTOR_21_TARGET_ABSC ;
extern float MOTOR_22_TARGET_ABSC ;
extern float MOTOR_23_TARGET_ABSC ;
extern float MOTOR_24_TARGET_ABSC ;

extern float LEFT_BEHIND_X ;
extern float LEFT_BEHIND_Z ;
extern float LEFT_BEHIND_VIRTUAL_LEG_LEARNTH ;
extern float LEFT_BEHIND_VIRTUAL_LEG_ANGLE_047 ;
extern float LEFT_BEHIND_VIRTUAL_LEG_ANGLE_04 ;
extern float LEFT_BEHIND_VIRTUAL_LEG_ANGLE_07 ;
extern float LEFT_BEHIND_VIRTUAL_LEG_ANGLE_0474 ;


extern float LEFT_FRONT_X ;
extern float LEFT_FRONT_Z ;
extern float LEFT_FRONT_VIRTUAL_LEG_LEARNTH ;
extern float LEFT_FRONT_VIRTUAL_LEG_ANGLE_047 ;
extern float LEFT_FRONT_VIRTUAL_LEG_ANGLE_04 ;
extern float LEFT_FRONT_VIRTUAL_LEG_ANGLE_07 ;
extern float LEFT_FRONT_VIRTUAL_LEG_ANGLE_0474 ;


extern float RIGHT_BEHIND_X ;
extern float RIGHT_BEHIND_Z ;
extern float RIGHT_BEHIND_VIRTUAL_LEG_LEARNTH ;
extern float RIGHT_BEHIND_VIRTUAL_LEG_ANGLE_047 ;
extern float RIGHT_BEHIND_VIRTUAL_LEG_ANGLE_04 ;
extern float RIGHT_BEHIND_VIRTUAL_LEG_ANGLE_07 ;
extern float RIGHT_BEHIND_VIRTUAL_LEG_ANGLE_0474 ;

extern float RIGHT_FRONT_X ;
extern float RIGHT_FRONT_Z ;
extern float RIGHT_FRONT_VIRTUAL_LEG_LEARNTH ;
extern float RIGHT_FRONT_VIRTUAL_LEG_ANGLE_047 ;
extern float RIGHT_FRONT_VIRTUAL_LEG_ANGLE_04 ;
extern float RIGHT_FRONT_VIRTUAL_LEG_ANGLE_07 ;
extern float RIGHT_FRONT_VIRTUAL_LEG_ANGLE_0474 ;





/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define POWER_OUT2_Pin GPIO_PIN_13
#define POWER_OUT2_GPIO_Port GPIOC
#define POWER_OUT1_Pin GPIO_PIN_14
#define POWER_OUT1_GPIO_Port GPIOC
#define POWER_OUT5V_Pin GPIO_PIN_15
#define POWER_OUT5V_GPIO_Port GPIOC
#define ACC_CS_Pin GPIO_PIN_0
#define ACC_CS_GPIO_Port GPIOC
#define GYRO_CS_Pin GPIO_PIN_3
#define GYRO_CS_GPIO_Port GPIOC
#define ACC_INT_Pin GPIO_PIN_10
#define ACC_INT_GPIO_Port GPIOE
#define GYRO_INT_Pin GPIO_PIN_12
#define GYRO_INT_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
