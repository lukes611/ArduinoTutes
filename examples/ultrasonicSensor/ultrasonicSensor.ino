/*
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 7 
 Trig to Arduino pin 8
 */


#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
float duration, distance; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

void loop() {
 //initialize communication protocol, using the trigger pin
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);

 //bring the pin low
 digitalWrite(trigPin, LOW);
 //pulse in records how long the echoPin remains high to obtain the input
 duration = (float)pulseIn(echoPin, HIGH);
 
 //Compute the distance based on the duration
 distance = duration/58.2;
 
 if (distance <= maximumRange && distance > minimumRange) //if not in range
    Serial.println("object detected at: " + String(distance) + " cm.");
 delay(100);
}
