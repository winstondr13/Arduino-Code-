#include <Arduino.h>

// put function declarations here:

int papPin = A0;
int papVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int oldpapVal = papVal;
papVal = analogRead(papPin);


int variance = abs(papVal - oldpapVal);
Serial.println(papVal);
if(variance < 8){
  digitalWrite(LED_BUILTIN, HIGH);
} else {
  digitalWrite(LED_BUILTIN, LOW);
}
delay(500);



}