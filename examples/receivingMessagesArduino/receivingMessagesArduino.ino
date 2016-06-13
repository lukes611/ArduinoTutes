
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()){ //Serial.available() returns true if there is some data to read
    String input = Serial.readString(); //readString reads the line of input the user typed
    Serial.println("got a message: " + input);
    if (input.length() >= 7){
      if(input.substring(0, 5) == "print"){
        int count = input.substring(6, input.length()).toInt();
        for(int i = 0; i < count; i++)
          Serial.println(i);
        Serial.println("executed counting operation");
      }  
    }
  }
  delay(10);
}
