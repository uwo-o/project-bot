#include <servos_controller.h>

TwoWire I2ConeServo = TwoWire(SERVO_BUS);
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(SERVO_DIR, I2ConeServo);

// First 4 are for the servos to move the paws back and forward, the last 4 are for the servos to move the paws left and right
int angles[8] = {90, 90, 90, 90, 90, 90, 90, 90};

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
        for (int i = 0; i < 8; i++)
        {
            pwm.setPWM(i, 0, angleToPulse(angles[i]));
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

void set_servo_angle(int servo, int angle)
{
    angles[servo] = angle;
}

int get_servo_angle(int servo)
{
    return angles[servo];
}

void step_forward()
{
    set_servo_angle(0, 0);
    set_servo_angle(1, 180);
    set_servo_angle(2, 0);
    set_servo_angle(3, 180);
    servos_controller_step();
}

void step_back()
{
    set_servo_angle(0, 180);
    set_servo_angle(1, 0);
    set_servo_angle(2, 180);
    set_servo_angle(3, 0);
    servos_controller_step();
}

void step_left()
{
    set_servo_angle(4, 0);
    set_servo_angle(5, 180);
    set_servo_angle(6, 0);
    set_servo_angle(7, 180);
    servos_controller_step();
}

void step_right()
{
    set_servo_angle(4, 180);
    set_servo_angle(5, 0);
    set_servo_angle(6, 180);
    set_servo_angle(7, 0);
    servos_controller_step();
}