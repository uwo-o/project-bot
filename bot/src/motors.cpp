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

	digitalWrite(WTR_FOR, HIGH);
	digitalWrite(WTR_BACK, LOW);
	analogWrite(TOP_LEFT_PIN, TURN_SPEED);

	analogWrite(BOTTOM_LEFT_PIN, 0);

	digitalWrite(WBR_FOR, LOW);
	digitalWrite(WBR_BACK, HIGH);
	analogWrite(BOTTOM_RIGHT_PIN, TURN_SPEED);
}

void turn_left()
{

	digitalWrite(WTL_FOR, HIGH);
	digitalWrite(WTL_BACK, LOW);
	analogWrite(TOP_LEFT_PIN, TURN_SPEED);

	analogWrite(TOP_LEFT_PIN, 0);

	digitalWrite(WBR_FOR, LOW);
	digitalWrite(WBR_BACK, HIGH);
	analogWrite(BOTTOM_LEFT_PIN, TURN_SPEED);

	analogWrite(BOTTOM_RIGHT_PIN, LOW);
}

void forward()
{

	digitalWrite(WTL_FOR, HIGH);
	digitalWrite(WTL_BACK, LOW);
	analogWrite(TOP_LEFT_PIN, MOVEMENT_SPEED);

	digitalWrite(WTR_FOR, HIGH);
	digitalWrite(WTR_BACK, LOW);
	analogWrite(TOP_LEFT_PIN, MOVEMENT_SPEED);

	digitalWrite(WBL_FOR, LOW);
	digitalWrite(WBL_BACK, LOW);
	analogWrite(BOTTOM_LEFT_PIN, 0);

	digitalWrite(WBR_FOR, LOW);
	digitalWrite(WBR_BACK, LOW);
	analogWrite(BOTTOM_RIGHT_PIN, 0);
}

void backward()
{

	digitalWrite(WTL_FOR, LOW);
	digitalWrite(WTL_BACK, LOW);
	analogWrite(TOP_LEFT_PIN, 0);

	digitalWrite(WTR_FOR, LOW);
	digitalWrite(WTR_BACK, LOW);
	analogWrite(TOP_LEFT_PIN, 0);

	digitalWrite(WBL_FOR, LOW);
	digitalWrite(WBL_BACK, HIGH);
	analogWrite(BOTTOM_LEFT_PIN, MOVEMENT_SPEED);

	digitalWrite(WBR_FOR, LOW);
	digitalWrite(WBR_BACK, HIGH);
	analogWrite(BOTTOM_RIGHT_PIN, MOVEMENT_SPEED);
}
