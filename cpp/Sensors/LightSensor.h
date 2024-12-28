#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H
#include "Sensor.h"

// Forward declaration
class Controller;

class LightSensor : public Sensor {
private:
    std::string name;
    float lux;               // current light level
    float minLux;            // minimum light level of a day
    float maxLux;            // maximum light level of a day

public:
    // Constructor to initialize the sensor
    LightSensor(const std::string& name, float initialLux = 100.0, float minLux = 50.0, float maxLux = 500.0);

    // Override method to get data and name
    float readData() const override;
    std::string getName() const override;

    // Generate and update new value
    void updateLux(float newLux);
    void generateRandomLux(float minutes);

    // Methods to send packets to the controller
    void sendToController(Controller& controller) const override;
    std::vector<uint8_t> generatePacket() const;
};

#endif