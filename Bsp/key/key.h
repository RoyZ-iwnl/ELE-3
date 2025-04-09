#ifndef __KEY_H
#define __KEY_H

#include "main.h"

#define 	KEY_GPIO     	GPIOA

#define   MOD_KEY_PIN		GPIO_PIN_10
#define   ADD_KEY_PIN		GPIO_PIN_11
#define   SUB_KEY_PIN		GPIO_PIN_12
#define   NUL_KEY_PIN		GPIO_PIN_13

#define _AddKeyPin     	HAL_GPIO_ReadPin(KEY_GPIO,ADD_KEY_PIN)
#define _SubKeyPin     	HAL_GPIO_ReadPin(KEY_GPIO,SUB_KEY_PIN)
#define _ModKeyPin     	HAL_GPIO_ReadPin(KEY_GPIO,MOD_KEY_PIN)
#define _NulKeyPin     	HAL_GPIO_ReadPin(KEY_GPIO,NUL_KEY_PIN)

#define MODEMAX 2

extern uint8_t AddKey,SubKey,ModKey,NulKey,Mode;

void Key_Gpio_Init(void);
void KeyFun(void);
void Keyscan(void);
#endif



