#ifndef SERVOS_CONTROLLER_H
#define SERVOS_CONTROLLER_H

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#include "constants.h"

bool setup_servos_controller();
void servos_controller_step();
int angleToPulse(int);
void set_servo_angle(int, int);
int get_servo_angle(int);
void step_forward();
void step_back();
void step_left();
void step_right();

#endif