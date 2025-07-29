#ifndef MOTORS_HPP
#define MOTORS_HPP

#include <Arduino.h>

const int TOP_RIGHT_PIN = 32;
const int TOP_LEFT_PIN = 33;
const int BOTTOM_RIGHT_PIN = 34;
const int BOTTOM_LEFT_PIN = 35;
conts int TURN_SPEED = 173;
const int MOVEMENT_SPEED = 255;

const int WTR_FOR = 5;
const int WTL_FOR = 6;
const int WBL_FOR = 7;
const int WBR_FOR = 8;

const int WTR_BACK = 9;
const int WTL_BACK = 10;
const int WBL_BACK = 11;
const int WBR_BACK = 12;

bool setup_motors();
void turn_right();
void turn_left();
void upward();
void backward();

#endif
