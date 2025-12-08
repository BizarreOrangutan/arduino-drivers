/**
 * @file SSD1306.h
 * @brief Arduino library for SSD1306 monochrome display
 * @author Jamie Hunt
 * @date 2025-12-08
 * @version 1.0
 */

#pragma once

#ifndef SSD1306_H
#define SSD1306_H

#include <stdint.h>

/**
 * @class SSD1306
 * @brief Interface for BH1750 digital ambient light sensor
 * 
 * 
 */
class SSD1306 {
    private:

    public:
        SSD1306();

        bool begin();

        bool draw_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
        ~SSD1306();
};


#endif /* SSD1306_H */