#include "BH1750.h"

#define ADDR_H 0x5C
#define ADDR_L 0x23
#define POWER_DOWN 0x00
#define POWER_ON 0x01
#define RESET 0x03
#define CONT_H_RES_MODE 0x10
#define CONT_H_RES_MODE_2 0x11
#define CONT_L_RES_MODE 0x13

#define H_RES_TIME 120
#define L_RES_TIME 16

BH1750::BH1750() {

};

bool BH1750::begin(Mode m) {
    Wire.begin();
    
    // Setting address, initialisation time and mode code
    switch(m) {
        case CONTINUOUS_HIGH_RES:
            address = ADDR_L;
            init_time = H_RES_TIME;
            mode = CONT_H_RES_MODE;
            break;

        case CONTINUOUS_HIGH_RES_2:
            address = ADDR_L;
            init_time = H_RES_TIME;
            mode = CONT_H_RES_MODE_2;
            break;

        case CONTINUOUS_LOW_RES:
            address = ADDR_H;
            init_time = L_RES_TIME;
            mode = CONT_L_RES_MODE;
            break;

        default:
            return false;

    } 
    
    // Power on
    Wire.beginTransmission(address);
    Wire.write(POWER_ON);
    Wire.endTransmission();

    // Set continuous mode
    Wire.beginTransmission(address);
    Wire.write(mode);
    Wire.endTransmission();

    // Wait for sensor to get its first readings
    delay(BH1750::init_time);

    return true;
};

bool BH1750::read_light(uint16_t* buffer) {
    // Request the sensor for the high and low bytes of reading
    Wire.requestFrom(address, 2, true);
    if (Wire.available() == 0)
        return false;

    // Save the bytes into given buffer
    *buffer = ((uint16_t)(Wire.read()) << 8);
    *buffer |= ((uint16_t)Wire.read());
    return true;
};

BH1750::~BH1750() {

};