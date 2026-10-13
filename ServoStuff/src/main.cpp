#include <Arduino.h>
#include <Servo.h>
Servo servo1;
// put function declarations here:
int pos =0;

void setup() {
 servo1.attach(9);
 pos = 0;
 servo1.write(pos);
 delay(1000);
 pinMode(7, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(8, OUTPUT);
 digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
   digitalWrite(8, HIGH);


}

void loop() {
 pos = 30; 
 servo1.write(0);
 delay(1000);
 servo1.write(180);
 delay(3000);

}
