#include <Arduino.h>
#include "ArduinoGraphics.h" 
#include "Arduino_LED_Matrix.h" 

ArduinoLEDMatrix matrix;

int input;
void printNum(int num);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  matrix.begin();
  Serial.println("Type a number to see it on the screen.");
}

void loop() {
if(Serial.available() > 0){
  char firstChar = Serial.peek();
  if(isdigit(firstChar) || firstChar == '-' || firstChar == '+'){
    input = Serial.parseInt();
  
  while(Serial.available() > 0 && Serial.peek() == '\n' && Serial.peek() == '\r'){
    Serial.read();
  }printNum(input);
  }else{
    Serial.read();
  }
  
  }
}

  


void printNum(int num){
 matrix.beginDraw();
matrix.clear();
  matrix.stroke(0xFFFFFFFF);
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 0xFFFFFFFF);
  matrix.print(num);
  matrix.endText();
  matrix.endDraw();
  Serial.println(num);
  Serial.println();
  Serial.println("Type another number to see it on the screen.");
}

