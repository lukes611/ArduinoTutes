
int inputPin = 3; //connect the input to pin 3
int noiseCount = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //we will write when we hear noise
  pinMode(inputPin, INPUT); //setup the pin
}

void loop() {
  // put your main code here, to run repeatedly:
  int hasNoise = !digitalRead(inputPin); //read pin value
  if(hasNoise){ //if there is noise, alert
      Serial.println(String("noise made...") + String(noiseCount));
      noiseCount++;
      delay(1000);
  }
  delay(10);
}
