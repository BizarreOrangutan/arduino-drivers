/**
 * @file BH1750.h
 * @brief Arduino library for BH1750 ambient light sensor
 * @author Jamie Hunt
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
 * Supports multiple resolutions of continuous measurement modes.
 * Communicates via I2C protocol.
 */

class BH1750 {
    private:
        uint8_t address;
        uint8_t init_time;
        uint8_t mode;
    
    public:
        BH1750();
        
        /**
         * @brief Initialize the BH1750 sensor
         * @param mode Measurement mode (continuous high/low resolution)
         * @return true if initialization successful, false otherwise
         * @note Requires Wire.begin() to be called first
         */
        bool begin(Mode mode);

        /**
         * @brief Retrieves the current light reading
         * @param buffer Two byte buffer to store the reading
         * @return true if reading was stored successful, false otherwise
         */
        bool read_light(uint16_t* buffer);

        ~BH1750();
};

#endif /* BH1750_H */