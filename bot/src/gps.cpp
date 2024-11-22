#include "gps.h"

TinyGPSPlus gps;

boolean setup_gps()
{
    bool status = true;

    Serial2.begin(GPS_BAUDRATE);

    if (!gps.location.isValid())
        status = false;

    if (!gps.altitude.isValid())
        status = false;

    if (!gps.speed.isValid())
        status = false;

    if (!gps.date.isValid())
        status = false;

    if (!status)
        return status;

    delay(10);

    return status;
}

GpsData *read_gps()
{
    GpsData *data = new GpsData();

    while (Serial2.available() > 0)
    {
        gps.encode(Serial2.read());
    }

    data->latitude = gps.location.lat();
    data->longitude = gps.location.lng();
    data->altitude = gps.altitude.meters();
    data->speed = gps.speed.kmph();
    data->course = gps.course.deg();
    data->age = gps.location.age();
    data->satellites = gps.satellites.value();

    return data;
}

void print_gps_data(GpsData *data)
{
    Serial.printf("\nLatitude: %f", data->latitude);
    Serial.printf("\nLongitude: %f", data->longitude);
    Serial.printf("\nAltitude: %f", data->altitude);
    Serial.printf("\nSpeed: %f", data->speed);
    Serial.printf("\nCourse: %f", data->course);
    Serial.printf("\nAge: %f", data->age);
    Serial.printf("\nSatellites: %f", data->satellites);
}