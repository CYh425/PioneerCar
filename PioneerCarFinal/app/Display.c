//
// Created by 李唐 on 2023/11/13.
//

#include "Display.h"
HAL_StatusTypeDef DisplayNum(float num)
{
    LCD_ShowNum(0, 0, num*10000, 6, 32);
    return HAL_OK;
}

HAL_StatusTypeDef ShowWheelStatus(CarType *_Car)
{
    LCD_ShowNum(10,10,_Car->LeftFront.Encoder.RadVelocity*100,6,24);
    LCD_ShowNum(10,40,_Car->LeftFront.Motor.RadVelocity*100,6,24);
    LCD_ShowNum(10,70,_Car->LeftFront.Parameter.PID*100,6,24);

    LCD_ShowNum(140,10,_Car->RightFront.Encoder.RadVelocity*100,6,24);
    LCD_ShowNum(140,40,_Car->RightFront.Motor.RadVelocity*100,6,24);
    LCD_ShowNum(140,70,_Car->RightFront.Parameter.PID*100,6,24);

    LCD_ShowNum(10,150,_Car->LeftRear.Encoder.RadVelocity*100,6,24);
    LCD_ShowNum(10,180,_Car->LeftRear.Motor.RadVelocity*100,6,24);
    LCD_ShowNum(10,210,_Car->LeftRear.Parameter.PID*100,6,24);

    LCD_ShowNum(140,150,_Car->RightRear.Encoder.RadVelocity*100,6,24);
    LCD_ShowNum(140,180,_Car->RightRear.Motor.RadVelocity*100,6,24);
    LCD_ShowNum(140,210,_Car->RightRear.Parameter.PID*100,6,24);
}
