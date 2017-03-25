
int ioPin;

void playFrequency(double F, double M)
{
	//complete this function based on the pseudo code provided
}

void setup() {
	ioPin = 8;
	pinMode(ioPin, OUTPUT);
}
void loop() {
	playFrequency(523.25, 500);
	delay(400);
	playFrequency(1000.0, 500);
	delay(400);
}
