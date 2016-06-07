const byte LED[] = {13,12,11,10};
int highlightedPin = 0; 
 
void setup()
{
// initialize the digital pin as an output.
/* Set each pin to outputs */
pinMode(LED[0], OUTPUT);
pinMode(LED[1], OUTPUT);
pinMode(LED[2], OUTPUT);
pinMode(LED[3], OUTPUT);
}
 
void loop()
{
  for(int i = 0; i < 4; i++)
    if(i == highlightedPin) digitalWrite(LED[i], LOW);
    else                    digitalWrite(LED[i], HIGH);
  highlightedPin = (highlightedPin + 1) % 4;
  delay(500);
}
