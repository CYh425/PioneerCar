//
// Created by 电脑 on 2024/1/16.
//

#ifndef __CAR_H__
#define __CAR_H__

#define PI 3.14159265358979323846

#include "stm32f1xx_hal.h"
#include "PCA9685.h"
#include <math.h>

#define KP 0.5
#define KI 0
#define KD 0

//#define MotorLeftFrontForward_Pin   15
//#define MotorLeftFrontBackward_Pin  14
//#define MotorLeftRearForward_Pin    12
//#define MotorLeftRearBackward_Pin   13
//#define MotorRightRearForward_Pin   4
//#define MotorRightRearBackward_Pin  3
//#define MotorRightFrontForward_Pin  2
//#define MotorRightFrontBackward_Pin 1

#define MotorLeftFrontForward_Pin   14
#define MotorLeftFrontBackward_Pin  15
#define MotorLeftRearForward_Pin    12
#define MotorLeftRearBackward_Pin   13
#define MotorRightRearForward_Pin   3
#define MotorRightRearBackward_Pin  4
#define MotorRightFrontForward_Pin  2
#define MotorRightFrontBackward_Pin 1


#define REDUCE 45
#define PULSES 52
#define INTERVAL 0.5f

#include "stm32f1xx_hal_tim.h"

typedef struct {
	TIM_HandleTypeDef *Timer;
	float RadVelocity, RadPosition;
	uint16_t NPulse, NRound;
	int8_t Direction;
} EncoderType;

typedef struct {
	uint8_t ForwardPin, BackwardPin;
	float RadVelocity;
} MotorType;

typedef struct {
	float kp, ki, kd;
	float bias, integral;
	float PID;
} ParameterType;

typedef struct {
	MotorType Motor;
	EncoderType Encoder;
	ParameterType Parameter;
} WheelType;

typedef struct {
	WheelType LeftFront, RightFront, LeftRear, RightRear;
	float Velocity;
	float Position;

} CarType;

extern I2C_HandleTypeDef hi2c2;

HAL_StatusTypeDef
CarInit(CarType *_Car,
           TIM_HandleTypeDef *LeFr,
           TIM_HandleTypeDef *LeRe,
           TIM_HandleTypeDef *RiFr,
           TIM_HandleTypeDef *RiRe);
void CarMoveRad(CarType *Car, float Direction, float Velocity);
void CarMoveInt(CarType *_Car, int X_intensity, int Y_intensity);
HAL_StatusTypeDef
CarUpdate(CarType *_Car);

#endif //PROJECT_MOTION_H
