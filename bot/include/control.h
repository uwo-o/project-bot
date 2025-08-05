#ifndef CONTROL_H
#define CONTROL_H

#include <Arduino.h>
#include "socket.h"
#include "motors.h"

void control_setup();
void control_loop();
void control_handle_message(uint8_t num, WStype_t type, uint8_t *payload, size_t length);

#endif