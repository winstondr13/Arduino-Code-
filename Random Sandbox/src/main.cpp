#include <Arduino.h>
#include <IRremote.hpp>

const int RECV_PIN = 11;
unsigned long previousMillis = 0;
const long interval = 2000;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
   IrSender.begin(5); 
   pinMode(2, INPUT_PULLUP);
}

void loop() {
  int button = digitalRead(2);
  if (IrReceiver.decode()) {
    //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
   // IrReceiver.printIRSendUsage(&Serial);
    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.resume();
  }
  uint16_t address = 0x03;
    uint8_t command = 0x54;
    long currentMillis = millis();
    // Send the NEC IR frame
    if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if(button == HIGH){
    
    IrSender.sendNEC(address, command, 1);
    
    Serial.println(F("Signal sent!"));
    //delay(2000); // Wait 2 seconds before sending again
    }

}
}