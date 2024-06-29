#include "ExEEPROM.h"
#include <Adafruit_AHT10.h>
#include <BMP180.h>
#include "XBMP10.h"
#include "AHT10.h"
#include "ADDR.h"
#include <Wire.h>

// #define EEPROM_ADDR 0x50

ExEEPROM data;
XBMP10 bmp10;
AHT10 aht10;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();

  data.init();
  bmp10.init();
  aht10.init();

  int read_temp = data.read(ADDR_TEMP);
  aht10.read_temp(read_temp);
  int read_press = data.read(ADDR_PRESS);
  bmp10.read_press(read_press);
  
}

void loop()
{

  int val_temp = aht10.write_temp();
  data.write(ADDR_TEMP, val_temp);
  int val_press = bmp10.write_press();
  data.write(ADDR_PRESS, val_press);
  delay(5000);
}
