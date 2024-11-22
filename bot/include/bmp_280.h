#ifndef BMP_280_H
#define BMP_280_H

#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>
#include "constants.h"

struct BmpData
{
    float temperature;
    float pressure;
    float altitude;
};

bool setup_bmp280();
BmpData *read_bmp280();
void print_bmp_data(BmpData *data);

#endif