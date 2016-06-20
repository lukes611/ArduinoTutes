/*
 * connect 5v to 5v, gnd to gnd
 * connect the SDA (data) pin to the arduino's A4 pin (analoge 4, the I2C data pin) 
 * connect the SCL (click) pin to the arduino's A5 pin (analogue 5, the I2C clock pin)
 */

#include<Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050

struct Vec3{
  int x, y, z;
  void init(int x, int y, int z){ this->x = x, this->y = y, this->z = z; }
  String toString(){ return String(x) + ", " + String(y) + ", " + String(z); }
};

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
}

int read16Bits(){
  return Wire.read()<<8|Wire.read();
}

void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers

  //initialize our vectors and temperature
  Vec3 _acceleration, _direction;
  float _temperature;
  
  _acceleration.init(read16Bits(), read16Bits(), read16Bits());
   _temperature = ((float)read16Bits())/340.00+36.53;
   _direction.init(read16Bits(), read16Bits(), read16Bits());

  Serial.print("direction: " + _direction.toString());
  Serial.print(",\tacceleration: " + _acceleration.toString());
  Serial.println(",\ttemperature: " + String(_temperature));
  
  delay(300);
}
