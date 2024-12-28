#include "TemperatureSensor.h"
#include "../Controller/Controller.h"
#include <random>

// Constructor
TemperatureSensor::TemperatureSensor(const std::string& sensorName, float initialTemperature, float minTemperature, float maxTemperature)
    : name(sensorName), temperature(initialTemperature), minTemperature(minTemperature), maxTemperature(maxTemperature) {}

float TemperatureSensor::readData() const {
    return temperature;
}

std::string TemperatureSensor::getName() const {
    return name;
}

void TemperatureSensor::updateTemperature(float newTemperature) {
    temperature = newTemperature;
}

// Generate a random temperature value based on a day-night cycle
void TemperatureSensor::generateRandomTemperature(float minutes) {
    // Calculate the position in a 24-hour cycle (hottest at night)
    float cyclePosition = (2 * M_PI * minutes) / 1440.0 - M_PI / 2;

    // Base temperature cycle: -1 to 1
    float baseCycle = std::sin(cyclePosition);
    float normalizedCycle = (baseCycle + 1.0) / 2.0;

    // Map the cycle to the temperature range [minTemperature, maxTemperature]
    float cycleTemperature = minTemperature + normalizedCycle * (maxTemperature - minTemperature);

    static std::default_random_engine generator(std::random_device{}());
    // Mean = 0, Std Dev = 0.5
    std::normal_distribution<float> variation(0, 0.5);

    float randomVariation = variation(generator);
    float finalTemperature = std::max(minTemperature, std::min(cycleTemperature + randomVariation, maxTemperature));

    updateTemperature(finalTemperature);
}

// Send the data packet to the controller
void TemperatureSensor::sendToController(Controller& controller) const {
    std::vector<uint8_t> packet = generatePacket();
    controller.receivePacket(packet);
}

// Generate a data packet for UART communication
std::vector<uint8_t> TemperatureSensor::generatePacket() const {
    std::vector<uint8_t> newPacket;
    newPacket.push_back(0xAA);

    newPacket.push_back(static_cast<uint8_t>(SensorType::TemperatureSensor));

    float data = readData();
    uint8_t* dataBytes = reinterpret_cast<uint8_t*>(&data);

    for (size_t i = 0; i < sizeof(float); ++i) {
        newPacket.push_back(dataBytes[i]);
    }

    newPacket.push_back(0xFF);
    return newPacket;
}