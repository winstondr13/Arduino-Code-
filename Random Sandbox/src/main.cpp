#include <Arduino.h>
// defines pins numbers
const int trigPin = 11;
const int echoPin = 12;
const int powerPin = 9;

// defines variables
long duration;
int distance;

void setup() {
  // UltraSonoc Pins
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(powerPin, OUTPUT); // Sets the powerPin as an Output
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(powerPin, HIGH); // Turns on the power to the sensor

  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;
  
 
  
  if(distance > 4){
    Serial.println("Stop!!!");
    delay(100);
  }else{
    Serial.print("Distance: ");
  Serial.println(distance);
  delay(50);
  }
  
}