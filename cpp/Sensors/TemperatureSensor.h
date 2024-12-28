#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H
#include "Sensor.h"

class Controller;

class TemperatureSensor : public Sensor {
private:
    std::string name;
    float temperature;                      // current temperature
    float minTemperature;                   // min temperature of a day
    float maxTemperature;                   // max temperature of a day

public:
    // Constructor to initialize the sensor
    TemperatureSensor(const std::string& name, float initialTemperature = 22.0f, 
                    float minTemperature = 15.0f, float maxTemperature = 30.0f);

    // Override method to get data and name
    float readData() const override;
    std::string getName() const override;

    // Generate and update new value
    void updateTemperature(float newTemperature);
    void generateRandomTemperature(float minutes);

    // Methods to send packets to the controller
    void sendToController(Controller& controller) const override;
    std::vector<uint8_t> generatePacket() const;
};

#endif