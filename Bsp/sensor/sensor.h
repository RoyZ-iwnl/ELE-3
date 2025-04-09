#ifndef __SENSOR_H
#define __SENSOR_H

#include "main.h"  // 修改路径

#define SENSOR_NUM 7
#define POSITION_RANGE 1000  // 位置计算的范围值

#define SENSOR_GPIO GPIOA

#define S1_PIN GPIO_PIN_1
#define S2_PIN GPIO_PIN_2
#define S3_PIN GPIO_PIN_3
#define S4_PIN GPIO_PIN_4
#define S5_PIN GPIO_PIN_5
#define S6_PIN GPIO_PIN_6
#define S7_PIN GPIO_PIN_7

#define _S1Pin HAL_GPIO_ReadPin(SENSOR_GPIO,S1_PIN)
#define _S2Pin HAL_GPIO_ReadPin(SENSOR_GPIO,S2_PIN)
#define _S3Pin HAL_GPIO_ReadPin(SENSOR_GPIO,S3_PIN)
#define _S4Pin HAL_GPIO_ReadPin(SENSOR_GPIO,S4_PIN)
#define _S5Pin HAL_GPIO_ReadPin(SENSOR_GPIO,S5_PIN)
#define _S6Pin HAL_GPIO_ReadPin(SENSOR_GPIO,S6_PIN)
#define _S7Pin HAL_GPIO_ReadPin(SENSOR_GPIO,S7_PIN)

extern uint8_t Sensor_Data[7];
extern int32_t CarPosition;

void Sensor_Gpio_Init(void);
void Get_Sensor_Data(void);
void Calculate_Car_Position(void);

#endif
