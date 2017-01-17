#include <OneWire.h>
#include <DallasTemperature.h>

//connect I to VCC
//connect S to GND
//connect the middle pin to digital 2
 
//setup onewire
OneWire oneWire(2);
 
//pass the onewire struct/object to
//the Dallas Temperature initializer
DallasTemperature sensor(&oneWire);
 
void setup(void)
{
  //setup serial output
  Serial.begin(9600);
  // Start up the sensor
  sensor.begin();
}
 
 
void loop(void)
{
//request temperature
sensor.requestTemperatures();

Serial.print("Temperature := ");
Serial.println(sensor.getTempCByIndex(0)); //index 0 because we only 
//have one sensor
delay(100); //delay
}


