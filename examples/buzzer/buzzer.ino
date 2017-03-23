/*
 * Connect I/O to digital pin 3
 * Connect VCC to 5v
 * Connect GND to gnd
 */
int ioPin, frequency = 400;

void setup() {
  ioPin = 3;
  pinMode(ioPin, OUTPUT);
}

void loop() {
  digitalWrite(ioPin, LOW);
  delay(500 / (double)frequency);
  digitalWrite(ioPin, HIGH);
  delay(500 / (double)frequency);
}

