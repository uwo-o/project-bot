#include <arduino.h>
#include "motors.h"

bool setup()
{
	pinMode(TOP_RIGHT_PIN, OUPUT);
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
	digitalWrite(WBR,BACK, HIGH);
	analogWrite(BOTTOM_RIGHT_PIN, TURN_SPEED);
}

void turn_left()
{

	digitalWrite(WTl_FOR, HIGH);
	digitalWrite(WTl_BACK, LOW);	
	analogWrite(TOP_LEFT_PIN, TURN_SPEED);

	analogWrite(TOP_LEFT_PIN, 0);

	digitalWrite(WBR_FOR, LOW);
	digitalWrite(WBR,BACK, HIGH);
	analogWrite(BOTTOM_LEFT_PIN, TURN_SPEED);

	analogWrite(BOTTOM_RIGHT_PIN, LOW);
}

void forward()
{

	digitalWrite(WTl_FOR, HIGH);
	digitalWrite(WTl_BCK, LOW);	
	analogWrite(TOP_LEFT_PIN, MOVEMENT_SPEED);

	digitalWrite(WTR_FOR, HIGH);
	digitalWrite(WTR,BACK, LOW);
	analogWrite(TOP_LEFT_PIN, MOVEMENT_SPEED);

	digitalWrite(WBL_FOR, LOW);
	digitalWrite(WBL,BACK, LOW);
	analogWrite(BOTTOM_LEFT_PIN, 0);

	digitalWrite(WBR_FOR, LOW);
	digitalWrite(WBR,BACK, LOW);
	analogWrite(BOTTOM_RIGHT_PIN, 0);
}

void backward()
{

	digitalWrite(WTl_FOR, LOW);
	digitalWrite(WTl_BACK, LOW);	
	analogWrite(TOP_LEFT_PIN, 0);

	digitalWrite(WTR_FOR, LOW);
	digitalWrite(WTR,BACK, LOW);
	analogWrite(TOP_LEFT_PIN, 0);

	digitalWrite(WBL_FOR, LOW);
	digitalWrite(WBL,BACK, HIGH);
	analogWrite(BOTTOM_LEFT_PIN, MOVEMENT_SPEED);

	digitalWrite(WBR_FOR, LOW);
	digitalWrite(WBR,BACK, HIGH);
	analogWrite(BOTTOM_RIGHT_PIN, MOVEMENT_SPEED);
}
