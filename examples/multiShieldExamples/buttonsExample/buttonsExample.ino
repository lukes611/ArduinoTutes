const byte LED[] = {13,12,11,10};
 
#define BUTTON1 A1
#define BUTTON2 A2
#define BUTTON3 A3
 
void setup()
{
// initialize the digital pin as an output.
/* Set each pin to outputs */
for(int i = 0; i < 4; i++) pinMode(LED[i], OUTPUT);
pinMode(BUTTON1, INPUT);
pinMode(BUTTON2, INPUT);
pinMode(BUTTON3, INPUT);
}
 
void loop()
{
if(!digitalRead(BUTTON1))
  for(int i = 0; i < 4; i++) digitalWrite(LED[i], HIGH);
 
if(!digitalRead(BUTTON2))
  for(int i = 0; i < 4; i++) digitalWrite(LED[i], LOW);
}
