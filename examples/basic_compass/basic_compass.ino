/*
 * uses 3.3v or 5v, connect either the 3.3v to the 3.3v on the arduino,
 * or the corresponding 5v pins on the compass and arduino
 * 
 * connect ground to ground
 * 
 * connect the SDA (data) pin to the arduino's A4 pin (analoge 4, the I2C data pin) 
 * connect the SCL (click) pin to the arduino's A5 pin (analogue 5, the I2C clock pin)
 * 
 */
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

void setup(void) 
{
  Serial.begin(9600);
  /* Initialise the sensor */
  if(!mag.begin())
  {
     Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
     while(1);
  }
}

void loop(void) 
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  mag.getEvent(&event);
  /* Display the results (magnetic vector values are in micro-Tesla (uT)) */
  Serial.print("X: "); Serial.print(event.magnetic.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.magnetic.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.magnetic.z); Serial.print("  ");Serial.println("uT");

  // Hold the module so that Z is pointing 'up' and you can measure the heading with x&y
  // Calculate heading when the magnetometer is level, then correct for signs of axis.
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 
  Serial.print("Heading (degrees): "); Serial.println(headingDegrees);
  delay(500);
}
