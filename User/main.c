#include "main.h"

void SystemClock_Config(void);

int16_t Speed = 25;
int16_t Turn_Kp = 50;  // 初始化Turn_Kp

int main(void)
{
    // 初始化 HAL 库和其他外设
    HAL_Init();
    SystemClock_Config();
    Key_Gpio_Init();
    Sensor_Gpio_Init();  // 添加传感器初始化
    OLED_Init();
    HAL_InitTick(25);

    while (1)
    {
        Keyscan();
        KeyFun();
        Get_Sensor_Data();         // 获取传感器数据
        Calculate_Car_Position();  // 计算小车位置
        Display();                 // 更新显示
        HAL_Delay(100);            // 延时
        
        // 显示速度信息
        OLED_ShowString(0,0,(uint8_t *)"Speed:",16);     
        OLED_ShowNum(56,0,Speed,3,16);
        OLED_ShowString(0,2,(uint8_t *)"Kp:",16);
        OLED_ShowNum(56,2,Turn_Kp,3,16);
    }
}

void SystemClock_Config(void)
{
    // 保持原有时钟配置
    RCC_ClkInitTypeDef clkinitstruct = {0};
    RCC_OscInitTypeDef oscinitstruct = {0};
    
    oscinitstruct.OscillatorType  = RCC_OSCILLATORTYPE_HSE;
    oscinitstruct.HSEState        = RCC_HSE_ON;
    oscinitstruct.LSEState        = RCC_LSE_OFF;
    oscinitstruct.HSIState        = RCC_HSI_ON;
    oscinitstruct.HSEPredivValue  = RCC_HSE_PREDIV_DIV1;
    oscinitstruct.PLL.PLLState    = RCC_PLL_ON;
    oscinitstruct.PLL.PLLSource   = RCC_PLLSOURCE_HSE;
    oscinitstruct.PLL.PLLMUL      = RCC_PLL_MUL9;
    if (HAL_RCC_OscConfig(&oscinitstruct)!= HAL_OK)
    {
        while(1); 
    }
    clkinitstruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    clkinitstruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    clkinitstruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    clkinitstruct.APB2CLKDivider = RCC_HCLK_DIV1;
    clkinitstruct.APB1CLKDivider = RCC_HCLK_DIV2;  
    if (HAL_RCC_ClockConfig(&clkinitstruct, FLASH_LATENCY_2)!= HAL_OK)
    {
        while(1); 
    }
}
