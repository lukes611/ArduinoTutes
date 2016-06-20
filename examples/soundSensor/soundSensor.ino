
int inputPin = 3; //connect the output on the sensor to pin 3, gnd to gnd and vc5v to 5v
int noiseCount = 0;

void setup() {
  Serial.begin(9600); //we will write when we hear noise
  pinMode(inputPin, INPUT); //setup the pin
}

void loop() {
  int hasNoise = !digitalRead(inputPin); //read pin value
  if(hasNoise){ //if there is noise, alert
      Serial.println(String("noise made...") + String(noiseCount)); //count the number of noises made
      noiseCount++;
      delay(1000);
  }
  delay(10);
}
