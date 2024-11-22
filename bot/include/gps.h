#ifndef GPS_H
#define GPS_H

#include "Arduino.h"
#include "constants.h"
#include <TinyGPS++.h>

struct GpsData
{
    double latitude;
    double longitude;
    double altitude;
    double speed;
    double course;
    double age;
    double satellites;
};

bool setup_gps();
GpsData *read_gps();
void print_gps_data(GpsData *data);

#endif