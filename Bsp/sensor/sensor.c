#include "sensor.h"

uint8_t Sensor_Data[7]={0};
void Sensor_Gpio_Init(void)
{
		GPIO_InitTypeDef Sensor;
		__HAL_RCC_GPIOA_CLK_ENABLE();
		Sensor.Mode = GPIO_MODE_INPUT;
		Sensor.Pin = S1_PIN|S2_PIN|S3_PIN|S4_PIN|S5_PIN|S6_PIN|S7_PIN;
		Sensor.Pull =GPIO_NOPULL;
		HAL_GPIO_Init(SENSOR_GPIO,&Sensor);
}


int32_t CarPosition = 0;

void Calculate_Car_Position(void)
{
    // 传感器位置权重 (根据实际传感器间距调整)
    const int16_t sensor_weights[SENSOR_NUM] = {-300, -200, -100, 0, 100, 200, 300};
    
    uint32_t sum = 0;
    uint8_t active_sensors = 0;
    
    // 计算加权平均值
    for(uint8_t i = 0; i < SENSOR_NUM; i++) {
        if(Sensor_Data[i] == 0) {  // 假设0表示检测到黑线
            sum += sensor_weights[i];
            active_sensors++;
        }
    }
    
    if(active_sensors > 0) {
        CarPosition = (int32_t)(sum / active_sensors);
    } else {
        // 没有检测到任何传感器，保持上次位置或特殊处理
        CarPosition = 0;
    }
}

void Get_Sensor_Data(void)
{
		Sensor_Data[0]=_S1Pin;
		Sensor_Data[1]=_S2Pin;
		Sensor_Data[2]=_S3Pin;
		Sensor_Data[3]=_S4Pin;
		Sensor_Data[4]=_S5Pin;
		Sensor_Data[5]=_S6Pin;
		Sensor_Data[6]=_S7Pin;
}
