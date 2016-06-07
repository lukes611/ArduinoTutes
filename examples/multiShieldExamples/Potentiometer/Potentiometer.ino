#define Pot1 0
 
void setup()
{
Serial.begin(9600);
}
 
/* Main Program */
void loop()
{
 
Serial.print("Potentiometer reading: ");
Serial.println(analogRead(Pot1));
/* Wait 0.5 seconds before reading again */
delay(500);
}
