// the setup function runs once when you press reset or power the board
int outPin = 3, f = 400;

void setup() {
  Serial.begin(9600);
  outPin = 3;
  pinMode(outPin, OUTPUT);
}

void loop() {
  if(Serial.available()){
    f = Serial.readString().toInt();
  }
  digitalWrite(outPin, LOW);
  delay(1000 / f);
  digitalWrite(outPin, HIGH);
  delay(1000 / f);
}
