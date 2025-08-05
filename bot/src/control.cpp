#include "control.h"

void execute_move_forward()
{
    forward();
}

void execute_move_backward()
{
    backward();
}

void execute_turn_left()
{
    turn_left();
}

void execute_turn_right()
{
    turn_right();
}

void execute_stop_motors()
{
    stop_motors();
}

void control_setup()
{
}

void control_loop()
{
}

void control_handle_message(uint8_t num, WStype_t type, uint8_t *payload, size_t length)
{
    String message = String((char *)payload);
    if (message == "forward")
    {
        execute_move_forward();
    }
    else if (message == "backward")
    {
        execute_move_backward();
    }
    else if (message == "left")
    {
        execute_turn_left();
    }
    else if (message == "right")
    {
        execute_turn_right();
    }
    else if (message == "stop")
    {
        execute_stop_motors();
    }
    else
    {
        Serial.printf("Unknown command: %s\n", message.c_str());
    }
}