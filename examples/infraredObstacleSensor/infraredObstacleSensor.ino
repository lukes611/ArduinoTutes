//connect OUT pin to digital 7, gnd to gnd and vcc to 5v
int isObstaclePin = 7;
void setup() {
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
 }
void loop() {
  if (!digitalRead(isObstaclePin))
    Serial.println("obstacle detected");
  delay(200);
}

