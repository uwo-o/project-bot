#include <servos_controller.h>

TwoWire I2ConeServo = TwoWire(SERVO_BUS);
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(SERVO_DIR, I2ConeServo);

bool setup_servos_controller()
{
    bool status = true;

    I2ConeServo.begin(SERVO_SDA, SERVO_SCL);

    Serial.begin(115200);

    if (!pwm.begin())
        status = false;

    pwm.setPWMFreq(SERVO_FREQ);

    return status;
}

void servos_controller_step()
{

    for (int angle = 0; angle <= 180; angle += 10)
    {
        for (int i = 0; i < 4; i++)
        {
            pwm.setPWM(i, 0, angleToPulse(angle));
            delay(500);
        }
    }

    delay(100);
}

int angleToPulse(int ang)
{
    int pulse = map(ang, 0, 180, SERVO_MIN, SERVO_MAX); // map angle of 0 to 180 to Servo min and Servo max
    Serial.print("Angle: ");
    Serial.print(ang);
    Serial.print(" pulse: ");
    Serial.println(pulse);
    return pulse;
}