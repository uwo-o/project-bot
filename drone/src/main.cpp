#include <Arduino.h>
#include "socket.h"
#include "buzzer.h"
#include "constants.h"
#include "mpu_6050.h"
#include "gps.h"

void setup()
{
    Serial.begin(115200);
    setup_buzzer();
    buzzer_accept();

    if (DEVELOPMENT)
        delay(10000);

    buzzer_accept();

    if (DEVELOPMENT)
        Serial.println("Setting up all components.");

    bool socket_status = setup_socket();
    bool mpu_status = setup_mpu6050();
    bool gps_status = setup_gps();

    if (DEVELOPMENT)
        Serial.printf("\n%s Wifi and socket.", socket_status ? "[OK]" : "[ERROR]");

    if (DEVELOPMENT)
        Serial.printf("\n%s MPU6050.", mpu_status ? "[OK]" : "[ERROR]");

    if (DEVELOPMENT)
        Serial.printf("\n%s GPS.", gps_status ? "[OK]" : "[ERROR]");

    if (!socket_status || !mpu_status || !gps_status)
    {
        if (DEVELOPMENT)
            Serial.println("\nError setting components.");
        buzzer_error();
        while (true)
            ;
    }

    if (DEVELOPMENT)
        Serial.println("\nAll components are ready.");

    buzzer_accept();
}

void loop()
{
    loop_socket();
    MpuData *data = read_mpu6050();
    GpsData *gps_data = read_gps();

    if (DEVELOPMENT)
        print_mpu_data(data);

    if (DEVELOPMENT)
        print_gps_data(gps_data);

    delay(1000);
}