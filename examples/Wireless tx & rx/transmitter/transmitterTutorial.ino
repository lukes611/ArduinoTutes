//Connect Tx on digital pin 12
#include <VirtualWire.h>

void setup()
{
pinMode(13,OUTPUT);
vw_set_ptt_inverted(true); //
vw_set_tx_pin(12);
vw_setup(4000);// speed of data transfer Kbps
}

void loop()
{
char msg = "hello there";
vw_send((uint8_t*)msg, strlen(msg));
vw_wait_tx(); // wait until the message is sent
delay(2000);
}
