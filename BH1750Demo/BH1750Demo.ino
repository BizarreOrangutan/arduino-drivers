#include "BH1750.h"

BH1750 sensor;

void setup() {
    Serial.begin(9600);
    
    if (sensor.begin(CONTINUOUS_HIGH_RES)) {
        Serial.println("BH1750 initialized!");
    } else {
        Serial.println("Failed to initialize BH1750");
    }
}

void loop() {
    uint16_t light_value;
    
    if (sensor.read_light(&light_value)) {
        Serial.print("Light: ");
        Serial.print(light_value);
        Serial.println(" lux");
    } else {
        Serial.println("Read failed");
    }
    
    delay(1000);
}