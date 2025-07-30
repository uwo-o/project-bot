#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>
#include "constants.h"

bool setup_motors();
void turn_right();
void turn_left();
void upward();
void backward();

#endif
