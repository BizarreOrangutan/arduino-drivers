/**
 * @file BH1750.h
 * @brief Arduino library for BH1750 ambient light sensor
 * @author Jamie
 * @date 2025-12-07
 * @version 1.0
 */

#pragma once

#ifndef BH1750_H
#define BH1750_H

#include <stdint.h>
#include <Wire.h>

enum Mode {
    CONTINUOUS_HIGH_RES,
    CONTINUOUS_HIGH_RES_2,
    CONTINUOUS_LOW_RES
};

/**
 * @class BH1750
 * @brief Interface for BH1750 digital ambient light sensor
 * 
 * Supports continuous and one-time measurement modes.
 * Communicates via I2C protocol.
 */

class BH1750 {
    private:
        uint8_t address;
        Mode mode;
    
    public:
        BH1750();
        bool begin(uint8_t pin, Mode mode);
        bool read_light(uint16_t* buffer);
        ~BH1750();
};

#endif /* BH1750_H */