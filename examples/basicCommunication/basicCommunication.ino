int loopCounter; //counts the number of loop() function calls
void setup() {
  Serial.begin(9600); //setup our Serial i/o @ 9600 bits per second
  loopCounter = 0;
}

void loop() {
  Serial.print("hello"); //prints hello with no new line character
  String arduinoString = " world"; //an Ardiono string
  Serial.println(arduinoString); //prints the ardiono string with a new line character

  //C way to print-out loopCounter
  Serial.print("counter: ");
  char buffer[100];
  char * ptr = itoa(loopCounter, buffer, 10);
  char buffer2[100] = "C count: ";
  strcat(buffer2, ptr);
  Serial.println(buffer2);

  //Simpler C++/Arduino way
  Serial.println("C++/Arduino count: " + String(loopCounter));
  
  Serial.print(4);
  loopCounter++;
  delay(2000);
}
