#ifndef __OLED_H__
#define __OLED_H__

#include "main.h"
#include "stdlib.h"
#include "math.h" 	 

#define OLED_MODE 0
#define SIZE 8
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    				

#define OLED_GPIO   	GPIOA
#define OLED_CLK_PIN  GPIO_PIN_8
#define OLED_DIN_PIN  GPIO_PIN_9

#define OLED_SCLK_Clr() HAL_GPIO_WritePin(OLED_GPIO,OLED_CLK_PIN,GPIO_PIN_RESET)//CLK  
#define OLED_SCLK_Set() HAL_GPIO_WritePin(OLED_GPIO,OLED_CLK_PIN,GPIO_PIN_SET)

#define OLED_SDIN_Clr() HAL_GPIO_WritePin(OLED_GPIO,OLED_DIN_PIN,GPIO_PIN_RESET)//DIN
#define OLED_SDIN_Set() HAL_GPIO_WritePin(OLED_GPIO,OLED_DIN_PIN,GPIO_PIN_SET)


#define OLED_CMD  0	
#define OLED_DATA 1	

void OLED_WR_Byte(unsigned dat,unsigned cmd);  
void OLED_Display_On(void);
void OLED_Display_Off(void);	   							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(uint8_t x,uint8_t y,uint8_t t);
void OLED_Fill(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t dot);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size);
void OLED_ShowString(uint8_t x,uint8_t y, uint8_t *p,uint8_t Char_Size);	 
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
void OLED_Num(uint8_t x,uint8_t y,int32_t num,uint8_t Char_Size);
void fill_picture(unsigned char fill_Data);
void Picture(void);
void IIC_Start(void);
void IIC_Stop(void);
void Write_IIC_Command(unsigned char IIC_Command);
void Write_IIC_Data(unsigned char IIC_Data);
void Write_IIC_Byte(unsigned char IIC_Byte);
void IIC_Wait_Ack(void);


#endif

