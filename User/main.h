#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f1xx_hal.h"
#include "stdio.h"
#include "oled.h"
#include "key.h"
#include "sensor.h"  // 修改路径

extern int16_t Speed;      // 统一使用int16_t
extern int16_t Turn_Kp;    // 添加Turn_Kp声明
extern uint8_t Sensor_Data[7];
extern int32_t CarPosition;

void Get_Sensor_Data(void);
void Calculate_Car_Position(void);
void Display(void);

#endif
