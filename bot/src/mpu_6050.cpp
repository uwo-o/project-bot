#include "mpu_6050.h"

Adafruit_MPU6050 mpu;

TwoWire I2ConeMPU = TwoWire(MPU_6050_BUS);

bool setup_mpu6050()
{
    bool status = true;

    I2ConeMPU.begin(MPU_6050_SDA, MPU_6050_SCL);

    if (!mpu.begin(MPU_6050_DIR, &I2ConeMPU))
        status = false;

    if (!status)
        return status;

    mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
    mpu.setGyroRange(MPU6050_RANGE_250_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    delay(10);

    return status;
}

MpuData *read_mpu6050()
{
    sensors_event_t a, g, temp;
    MpuData *data = new MpuData();

    mpu.getEvent(&a, &g, &temp);

    data->acc_x = a.acceleration.x;
    data->acc_y = a.acceleration.y;
    data->acc_z = a.acceleration.z;
    data->gyro_x = g.gyro.x;
    data->gyro_y = g.gyro.y;
    data->gyro_z = g.gyro.z;
    data->temp = temp.temperature;

    return data;
}

void print_mpu_data(MpuData *data)
{
    Serial.print("Acc: ");
    Serial.print(data->acc_x);
    Serial.print(" ");
    Serial.print(data->acc_y);
    Serial.print(" ");
    Serial.print(data->acc_z);
    Serial.print(" | Gyro: ");
    Serial.print(data->gyro_x);
    Serial.print(" ");
    Serial.print(data->gyro_y);
    Serial.print(" ");
    Serial.print(data->gyro_z);
    Serial.print(" | Temp: ");
    Serial.println(data->temp);
}