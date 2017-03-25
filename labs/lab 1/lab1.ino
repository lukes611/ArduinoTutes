
/*Servo:
 * connect Red to 5v, Brown to gnd
 * connect Yellow to pin signalPin (9)
 */

#include <Servo.h> //includes for servo

Servo s; //create a servo object

//includes for compass 
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);



void setup()
{
	Serial.begin(9600); //intialize our communication module
	s.attach(9);  //attach to the signal pin (pin 9 in our case)
	if(!mag.begin()) //if cannot setup our compass
	{
		//print error message
		Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
		while(1) ; //loop forever doing nothing (never reaching  our loop() function)
	}
}

void setServo(int angle, int mapType)
{
	//complete this function to set the servo to point to "angle" degrees
	//if mapType is 1 then angle should be mapped from 0 to 360 to 0 to 180
	//otherwise set the servo to point to the unchanged "angle" amount of degrees
}

int getHeading()
{
	//complete this function
	return 0; //should return the angle retrieved by the compass
}

void loop()
{
	setServo(getHeading(), MapType);
	delay(1000);
}
