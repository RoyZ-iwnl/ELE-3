#include "key.h"

uint8_t AddKey,SubKey,ModKey,NulKey;//键值
uint8_t Mode=0;
void Key_Gpio_Init()
{
		GPIO_InitTypeDef Keys;
		__HAL_RCC_GPIOA_CLK_ENABLE();
		Keys.Mode = GPIO_MODE_INPUT;
		Keys.Pin = ADD_KEY_PIN|SUB_KEY_PIN|MOD_KEY_PIN|NUL_KEY_PIN ;
		Keys.Pull =GPIO_PULLUP;
		HAL_GPIO_Init(KEY_GPIO,&Keys);

}

void Keyscan(void)
{
		static uint8_t subflag = 0,addflag = 0,modflag = 0,nulflag = 0;
		if(_ModKeyPin==0)modflag = 1;   //模式键
		if(modflag && _ModKeyPin) { modflag = 0;ModKey = 1;}
		
		if(_AddKeyPin==0)addflag = 1;    //累加键
		if(addflag && _AddKeyPin) { addflag = 0;AddKey = 1;}
		
		if(_SubKeyPin==0)subflag = 1;   //递减键
		if(subflag && _SubKeyPin) { subflag = 0;SubKey = 1;}
				
		if(_NulKeyPin==0)nulflag = 1;   //空键
		if(nulflag && _NulKeyPin) { nulflag = 0;NulKey = 1;}
}

void KeyFun(void)
{
		if(ModKey)                
		{
				Mode++;
				if(Mode > MODEMAX-1) Mode = 0;
		}
    
		if(AddKey)                
		{
			switch(Mode)
			{
				case 0:Speed += 3;	if(Speed > 100) 	Speed = 100;	break;
				case 1:Turn_Kp += 3;if(Turn_Kp > 200) Turn_Kp = 200;break;
			}
		}
		if(SubKey)            
		{
			switch(Mode)
			{
				case 0:Speed -= 2;	if(Speed < 0  ) 	Speed = 0;	break;
				case 1:Turn_Kp -= 2;if(Turn_Kp < 0  ) Turn_Kp = 0;break;
			}
		}
		AddKey = SubKey = ModKey = NulKey = 0; // 清除标志位
}
