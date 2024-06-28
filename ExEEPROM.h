#ifndef _ExEEPROM_H_
#define _ExEEPROM_H_

#include <Arduino.h>
#include <Wire.h>

class ExEEPROM {
  public:
    ExEEPROM(int addr_e); 
    ExEEPROM();
    void init();
    int write(int addr, int val);
    int read(int addr);  
  private:
    int addr_e;
    int addr;
    int val;
    
};
#endif // ExEEPROM_H