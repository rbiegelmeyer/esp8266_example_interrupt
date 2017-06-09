#include <EEPROM.h>

void setup() {
  Serial.begin(115200);
  delay(100);
  EEPROM.begin(4096);
  delay(100);
  
  pinMode(14, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(14), handleInterrupt, FALLING);
}

void clearEEPROM(){
  for (int i = 0; i<4096; ++i)
    EEPROM.write(i,'O');
  EEPROM.commit();
  delayMicroseconds(1000);
  
  ESP.restart();
}
 
void handleInterrupt() {
  Serial.println("Interrupt");
  clearEEPROM();
}
 
void loop() {
  Serial.println(char(EEPROM.read(2000)));
  delay(100);
}
