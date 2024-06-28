#include "ExEEPROM.h"
#include <Arduino.h>  
#include <Wire.h>

#define EEPROM_ADDR 0x50

ExEEPROM::ExEEPROM(int addr) : addr_e(EEPROM_ADDR) {}

void ExEEPROM::init(){
  Wire.begin();
  Serial.println("EEPROM Is Ready!");
  delay(100);
}

int ExEEPROM::write(int addr, int val){
    Wire.beginTransmission(EEPROM_ADDR);
    Wire.write((int)(addr >> 8));   // MSB
    Wire.write((int)(addr & 0xFF)); // LSB
    Wire.write(val);
    Wire.endTransmission();
    delay(5);
    return 0;
}

int ExEEPROM::read(int addr){
    int readData = 0;
    Wire.beginTransmission(EEPROM_ADDR);
    Wire.write((int)(addr >> 8));   // MSB
    Wire.write((int)(addr & 0xFF)); // LSB
    Wire.endTransmission();

    delay(5);
    Wire.requestFrom(EEPROM_ADDR, 1);
    if (Wire.available()) {
        readData =  Wire.read();
    }

    return readData;
}