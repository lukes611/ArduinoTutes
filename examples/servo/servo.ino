
int signalPin = 9;

/*
 * connect Red to 5v, Brown to gnd
 * connect Yellow to pin signalPin (9)
 */

#include <Servo.h>

Servo s;  //create a servo object

int index;
int positions[6] = {0, 45, 90, 180, 50, 120};    //6 positions to go-to

void setup() {
  s.attach(signalPin);  //attach to the signal pin
  index = 0;
}

void loop() {
  s.write(positions[index]); //set servo to point to an angle in positions
  delay(1000); //wait for 1 second
  
  index = (index+1) % 6; //iterate index over the range [0,5] inclusive
}
