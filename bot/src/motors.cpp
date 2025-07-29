int speed_tr;
int speed_tl;
int speed_dl;
int speed_dr;

const int TOP_RIGHT_PIN = 32;
const int TOP_LEFT_PIN = 33;
const int BOTTOM_RIGHT_PIN = 34;
const int BOTTOM_LEFT_PIN = 35;
conts int TURN_SPEED = 173;
const int MOVEMENT_SPEED = 255;


struct motors {
	int top_right;
	int top_left;
	int bottom_left;
	int bottom_right;
} motors;

void setup()
{
	pinMode(TOP_RIGHT_PIN, OUPUT);
	pinMode(TOP_LEFT_PIN, OUTPUT);
	pinMode(BOTTOM_RIGHT_PIN, OUTPUT);
	pinMode(BOTTOM_LEFT_PIN, OUTPUT);
}

void turn_right()
{
	analogWrite(TOP_RIGHT_PIN, 0);
	analogWrite(TOP_LEFT_PIN, TURN_SPEED);
	analogWrite(BOTTOM_LEFT_PIN, 0);
	analogWrite(BOTTOM_RIGHT_PIN, TURN_SPEED);
}
