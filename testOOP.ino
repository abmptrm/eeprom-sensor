#include "ExEEPROM.h"
#include "AHT10.h"
#include <Wire.h>

#define EEPROM_ADDR 0x50

ExEEPROM data(EEPROM_ADDR);
AHT10 aht10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  data.init();

  aht10.init();
  aht10.read_temp();


  


  
}

void loop() {
  aht10.write_temp();
  delay(2);
}
