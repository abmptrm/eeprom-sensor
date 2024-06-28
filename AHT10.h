#ifndef _AHT10_H_
#define _AHT10_H_

#include <Arduino.h>
#include <Adafruit_AHT10.h>

class AHT10 {
    public:
        
        // Constructor
        AHT10(void);
        void init();
        void read_temp();
        void write_temp();

    private:
        // Data members if needed

        

};

#endif