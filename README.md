# Arduino Drivers

This repository demonstrates my ability to read datasheets and create sensor drivers for Arduino boards.

## Completed Drivers

### BH1750 Digital Light Sensor
- **Description**: I2C ambient light sensor with 16-bit resolution
- **Features**:
  - Continuous high/low resolution modes
  - Dual I2C addresses (0x23, 0x5C) based on ADDR pin
  - Automatic measurement conversion to lux units
- **Files**: `BH1750.h`, `BH1750.cpp`
- **Target Board**: Arduino Uno R4 (ARM Cortex-M4)

## Usage Example

```cpp
#include "BH1750.h"

BH1750 lightSensor;

void setup() {
    Serial.begin(9600);
    
    if (lightSensor.begin(CONTINUOUS_HIGH_RES)) {
        Serial.println("BH1750 initialized successfully!");
    }
}

void loop() {
    uint16_t lightLevel;
    
    if (lightSensor.read_light(&lightLevel)) {
        Serial.print("Light intensity: ");
        Serial.print(lightLevel);
        Serial.println(" lux");
    }
    
    delay(1000);
}
```

## Development Process

- Read and analyzed BH1750 datasheet
- Implemented I2C communication protocol
- Created clean C++ class interface
- Configured VS Code for Arduino R4 development with proper include paths
- Applied embedded C++ best practices (RAII, error handling, buffer management)