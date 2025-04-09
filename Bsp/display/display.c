#include "display.h"


void Display(void)
{
    // 原有模式选择显示
    if(Mode==0) OLED_ShowString(0,0,(uint8_t *)"->",16);
    else        OLED_ShowString(0,0,(uint8_t *)"  ",16);
    if(Mode==1) OLED_ShowString(0,2,(uint8_t *)"->",16);
    else        OLED_ShowString(0,2,(uint8_t *)"  ",16);
    
    // 显示速度和转向参数
    OLED_ShowString(16,0,(uint8_t *)"Speed:",16);     
    OLED_ShowNum(80,0,Speed,3,16);
    OLED_ShowString(16,2,(uint8_t *)"Turn_Kp:",16);     
    OLED_ShowNum(80,2,Turn_Kp,3,16);
    
    // 新增传感器数据显示 (第4行)
    char sensorStr[20];
    sprintf(sensorStr, "S:%d%d%d%d%d%d%d", 
            Sensor_Data[0], Sensor_Data[1], Sensor_Data[2], 
            Sensor_Data[3], Sensor_Data[4], Sensor_Data[5], 
            Sensor_Data[6]);
    OLED_ShowString(0,4,(uint8_t *)sensorStr,16);
    
    // 新增位置显示 (第6行)
    char posStr[20];
    sprintf(posStr, "Pos:%4d", CarPosition);
    OLED_ShowString(0,6,(uint8_t *)posStr,16);
}
