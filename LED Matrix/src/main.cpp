#include <Arduino.h>
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
matrix.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
int potValue = analogRead(A0);
int printValue = map(potValue, 0, 1023, 0, 10);
Serial.println(potValue);
String text = String(printValue);
matrix.beginDraw();
matrix.clear();
  matrix.stroke(0xFFFFFFFF);
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 0xFFFFFFFF);
  
  matrix.print(text);
  matrix.endText();
  matrix.endDraw();
delay(50);

}
