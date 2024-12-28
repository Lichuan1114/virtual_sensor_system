#include "LightSensor.h"
#include "../Controller/Controller.h"
#include <random>

// Constructor to initialize the sensor
LightSensor::LightSensor(const std::string& sensorName, float initialLux, float minLux, float maxLux) 
    : name(sensorName), lux(initialLux), minLux(minLux), maxLux(maxLux) {}

float LightSensor::readData() const {
    return lux;
}

std::string LightSensor::getName() const {
    return name;
}

void LightSensor::updateLux(float newLux) {
    lux = newLux;
}

// Generate random lux based on the time of day (minutes since midnight)
void LightSensor::generateRandomLux(float minutes) {
    // Calculate position in the day cycle: high -> low -> high
    float cyclePosition = (2 * M_PI * minutes) / 1440.0 - M_PI/2;
    float baseCycle = std::sin(cyclePosition);

    // normalize to 0 - 1
    float normalizedCycle = (baseCycle + 1.0) / 2.0;
    float cycleLux = minLux + normalizedCycle * (maxLux - minLux);

    static std::default_random_engine generator(std::random_device{}());

    // Random variation with mean 0 and std deviation 20
    std::normal_distribution<float> variation(0, 20);

    float randomVariation = variation(generator);
    float finalLux = std::max(minLux, std::min(cycleLux + randomVariation, maxLux));
    updateLux(finalLux);
}

// Send data packet to controller
void LightSensor::sendToController(Controller& controller) const {
    std::vector<uint8_t> packet = generatePacket();
    controller.receivePacket(packet);
}

// Generate packet for UART transmission
std::vector<uint8_t> LightSensor::generatePacket() const {
    std::vector<uint8_t> newPacket;
    newPacket.push_back(0xAA);

    newPacket.push_back(static_cast<uint8_t>(SensorType::LightSensor));

    float data = readData();
    uint8_t* dataBytes = reinterpret_cast<uint8_t*>(&data);

    for (size_t i = 0; i < sizeof(float); ++i) {
        newPacket.push_back(dataBytes[i]);
    }

    newPacket.push_back(0xFF);
    return newPacket;
}