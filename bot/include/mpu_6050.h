#ifndef MPU_050_H
#define MPU_050_H

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#include "constants.h"

typedef struct
{
    float acc_x;
    float acc_y;
    float acc_z;
    float gyro_x;
    float gyro_y;
    float gyro_z;
    float temp;
} MpuData;

bool setup_mpu6050();
MpuData *read_mpu6050();
void print_mpu_data(MpuData *data);

#endif