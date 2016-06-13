/* Define shift register pins used for seven segment display */
int   latch = 4;
int   clk   = 7;
int   data  = 8;
 
/* bytes which id one of the 4 7 segment displays */
const byte segmentIds[] = {0xF1,0xF2,0xF4,0xF8};
 
void setup ()
{
/* Set DIO pins to outputs */
pinMode(latch,OUTPUT);
pinMode(clk,OUTPUT);
pinMode(data,OUTPUT);
}

void drive7Segment(byte segment, int id){
  digitalWrite(latch,LOW);
  shiftOut(data, clk, MSBFIRST, segment);
  shiftOut(data, clk, MSBFIRST, segmentIds[id] );
  digitalWrite(latch,HIGH);
}
 
/* Main program */
void loop()
{
 /*write a number to each 7 segment*/
 drive7Segment(~0x06, 0);
 drive7Segment(~0x5B, 1);
 drive7Segment(~0x4F, 2);
 drive7Segment(~0x66, 3);
}
 

