#include "motors.h"

bool setup_motors()
{
	pinMode(TOP_RIGHT_PIN, OUTPUT);
	pinMode(TOP_LEFT_PIN, OUTPUT);
	pinMode(BOTTOM_RIGHT_PIN, OUTPUT);
	pinMode(BOTTOM_LEFT_PIN, OUTPUT);

	return true;
}

void turn_right()
{
	analogWrite(TOP_RIGHT_PIN, 0);

	digitalWrite(TOP_LEFT_DIR, LOW);
	analogWrite(TOP_LEFT_PIN, TURN_SPEED);

	analogWrite(BOTTOM_LEFT_PIN, 0);

	digitalWrite(BOTTOM_RIGHT_DIR, HIGH);
	analogWrite(BOTTOM_RIGHT_PIN, TURN_SPEED);
}

void turn_left()
{
	digitalWrite(TOP_RIGHT_DIR, LOW);
	analogWrite(TOP_LEFT_PIN, TURN_SPEED);

	analogWrite(TOP_LEFT_PIN, 0);

	digitalWrite(BOTTOM_LEFT_DIR, HIGH);
	analogWrite(BOTTOM_LEFT_PIN, TURN_SPEED);
}

void forward()
{

	digitalWrite(TOP_LEFT_DIR, LOW);
	digitalWrite(TOP_RIGHT_DIR, LOW);
	digitalWrite(BOTTOM_LEFT_DIR, LOW);
	digitalWrite(BOTTOM_RIGHT_DIR, LOW);

	analogWrite(TOP_LEFT_PIN, MOVEMENT_SPEED);
	analogWrite(TOP_RIGHT_PIN, MOVEMENT_SPEED);
	analogWrite(BOTTOM_LEFT_PIN, MOVEMENT_SPEED);
	analogWrite(BOTTOM_RIGHT_PIN, MOVEMENT_SPEED);
}

void backward()
{

	digitalWrite(TOP_LEFT_DIR, HIGH);
	digitalWrite(TOP_RIGHT_DIR, HIGH);
	digitalWrite(BOTTOM_LEFT_DIR, HIGH);
	digitalWrite(BOTTOM_RIGHT_DIR, HIGH);

	analogWrite(TOP_LEFT_PIN, MOVEMENT_SPEED);
	analogWrite(TOP_RIGHT_PIN, MOVEMENT_SPEED);
	analogWrite(BOTTOM_LEFT_PIN, MOVEMENT_SPEED);
	analogWrite(BOTTOM_RIGHT_PIN, MOVEMENT_SPEED);
}

void stop_motors()
{
	digitalWrite(TOP_LEFT_DIR, LOW);
	digitalWrite(TOP_RIGHT_DIR, LOW);
	digitalWrite(BOTTOM_LEFT_DIR, LOW);
	digitalWrite(BOTTOM_RIGHT_DIR, LOW);
	analogWrite(TOP_LEFT_PIN, 0);
	analogWrite(TOP_RIGHT_PIN, 0);
	analogWrite(BOTTOM_LEFT_PIN, 0);
	analogWrite(BOTTOM_RIGHT_PIN, 0);
}