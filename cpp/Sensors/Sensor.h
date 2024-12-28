#ifndef SENSOR_H
#define SENSOR_H
#include <string>
#include "SensorEvent.h"

// Forward declaration
class Controller;

// Abstract base class for sensors
class Sensor {
public:
    // Virtual destructor
    virtual ~Sensor() = default;

    // Pure virtual method to read data
    virtual float readData() const = 0;

    // Pure virtual method to return sensor name
    virtual std::string getName() const = 0;

    // Pure virtual method to send data to the controller
    virtual void sendToController(Controller& controller) const = 0;
};

#endif 
