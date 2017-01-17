//Connect Tx on digital pin 12
#include <VirtualWire.h>
void setup()
{
vw_set_ptt_inverted(true); //required for receiver
vw_set_rx_pin(12);
vw_setup(4000);  //set bits per second
pinMode(13, OUTPUT);
vw_rx_start(); //start the receiver

//setup serial output
Serial.begin(9600);
}

void loop()
{
uint8_t str[VW_MAX_MESSAGE_LEN];
uint8_t len;

//if message available: put it in str and set stringLength to the 
//length of the string

if (vw_get_message(str, &len)) Serial.println(str);
	
}
