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

bool BH1750::begin(uint8_t address, Mode mode) {
    BH1750::address = address;
    BH1750::mode = mode;
    // Power on
    // Set continuous mode of choice
    // Wait 
};

bool BH1750::read_light(uint16_t* buffer) {
    // Send start
    // Send ADDR L/H
    // Wait for ack
    // Receive high byte and store in buffer
    // Send ack
    // Receive low byte and store in buffer
    // Send ack and stop
};

BH1750::~BH1750() {

};