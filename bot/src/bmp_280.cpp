#include "bmp_280.h"

TwoWire I2ConeBMP = TwoWire(BMP_280_BUS);
Adafruit_BMP280 bmp(&I2ConeBMP);

float reference_pressure = 0.0;
bool setup_bmp280()
{
    I2ConeBMP.begin(BMP_280_SDA, BMP_280_SCL);

    bool status = true;

    if (!bmp.begin(BMP_280_DIR))
        status = false;

    if (!status)
        return status;

    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                    Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                    Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                    Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                    Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

    reference_pressure = bmp.readPressure() / 100.0F;

    delay(10);

    return status;
}

BmpData *read_bmp280()
{
    BmpData *data = new BmpData();

    data->temperature = bmp.readTemperature();
    data->pressure = bmp.readPressure() / 100.0F;
    data->altitude = bmp.readAltitude(reference_pressure);

    return data;
}

void print_bmp_data(BmpData *data)
{
    Serial.print("\nTemp: ");
    Serial.print(data->temperature);
    Serial.print(" | Pres: ");
    Serial.print(data->pressure);
    Serial.print(" | Alt: ");
    Serial.println(data->altitude);
}