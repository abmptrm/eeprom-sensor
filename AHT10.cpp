#include "AHT10.h"
#include "ExEEPROM.h"
#include "ADDR.h"
#include <Adafruit_AHT10.h>
#include <Arduino.h>  
// #include <lvgl.h>
// #include "ui.h"

ExEEPROM data;
Adafruit_AHT10 aht;
Adafruit_Sensor *aht_temp;
// lv_obj_t *ui_LabelTemp;


AHT10::AHT10(void){}

AHT10::init(aht, aht_temp){
    if (!aht.begin()) {
        Serial.println("Failed to find AHT10 chip");
        while (1) {
            delay(10);
        }
    }

    aht_temp = aht.getTemperatureSensor(); // Correctly initialize aht_temp
    aht_temp->printSensorDetails();
    Serial.println("AHT10 Found!");
    delay(100);
}

void AHT10::read_temp(){
    int val_temp = data.read(ADDR_TEMP);
    if (val_temp > 0) {
        char my_temp[10];
        sprintf(my_temp, "%d°C", val_temp);
        Serial.print("r Temperature: ");
        Serial.println(my_temp);
        // _ui_label_set_property(ui_LabelTemp, _UI_LABEL_PROPERTY_TEXT, my_temp);
    }
}

void AHT10::write_temp(){
    sensors_event_t temp, humidity;
    aht.getEvent(&humidity, &temp);
    int cs_temp = (int)temp.temperature;

    data.write(ADDR_TEMP, cs_temp);

    char my_temp[10];
    sprintf(my_temp, "%d°C", cs_temp);
    Serial.print("w Temperature :");
    Serial.println(my_temp);
    // _ui_label_set_property(ui_LabelTemp, _UI_LABEL_PROPERTY_TEXT, my_temp);
}