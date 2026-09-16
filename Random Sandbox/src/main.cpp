#include <Arduino.h>
int button = 2;
String buttonState = "LOW";

// put function declarations here:
void setup(){
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  delay(1000);
  Serial.println("Reading Button State");
}
void loop(){
  int breakCheck = 0;
  int makeCheck = 0;
  
  int butState = digitalRead(button);
  Serial.println("Starting While Loop - Checking If Button Is HIGH");
  while(butState == HIGH){
    if(butState == HIGH){
    buttonState = "HIGH";
  }else if(butState == LOW){
    buttonState = "LOW";
  }else{
  }
    Serial.println("Button " + buttonState + " : Break Check Loop # " + String(breakCheck)); 
    delay(100);
    breakCheck++;
    butState = digitalRead(button);
  }
  Serial.println("Starting While Loop - Checking If Button Is LOW");
   while(butState == LOW){
    
    if(butState == HIGH){
    buttonState = "HIGH";
  }else if(butState == LOW){
    buttonState = "LOW";
  }else{
  }
    Serial.println("Button " + buttonState + " : Make Check Loop # " + String(makeCheck)); 
    delay(100);
    makeCheck++;
    butState = digitalRead(button);
  }

}


