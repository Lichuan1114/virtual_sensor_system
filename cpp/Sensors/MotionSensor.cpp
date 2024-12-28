#include "MotionSensor.h"
#include "../Controller/Controller.h"
#include <iostream>
#include <random>

// Constructor
MotionSensor::MotionSensor(const std::string& name, bool motionDetected, float sensitivity, float noiseLevel, 
    std::chrono::steady_clock::time_point lastMotionTime, int cooldownPeriod)
    : name(name), motionDetected(motionDetected), sensitivity(sensitivity), noiseLevel(noiseLevel), 
    lastMotionTime(lastMotionTime), cooldownPeriod(cooldownPeriod) {}

// Read the motion data (1 for motion detected, 0 for no motion)
float MotionSensor::readData() const {
    return motionDetected ? 1.0f : 0.0f;
}

std::string MotionSensor::getName() const {
    return name;
}

void MotionSensor::updateMotionDetected(bool newMotionDetected) {
    motionDetected = newMotionDetected;
}

// Generate random motion based on sensor's sensitivity and noise level
void MotionSensor::generateRandomMotion() {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_real_distribution<float> motionProbability(0.0, 1.0);
    std::uniform_real_distribution<float> noiseProbability(0.0, 1.0);

    // Get current time and compute elapsed time since last detected motion
    auto currentTime = std::chrono::steady_clock::now();
    auto timeSinceLastMotion = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastMotionTime);

    // Skip processing if still in cooldown period
    // if (timeSinceLastMotion.count() < cooldownPeriod) { 
    //     return; 
    // }

    bool realMotion = motionProbability(generator) < (1.0f - sensitivity);

    // Add noise to simulate real-world conditions
    if (noiseProbability(generator) < noiseLevel) { 
        realMotion = !realMotion; 
    }

    updateMotionDetected(realMotion);

    // Update last motion time if motion is detected
    if (motionDetected) {
        lastMotionTime = currentTime;
    }
}

// Send motion data packet to controller
void MotionSensor::sendToController(Controller& controller) const {
    std::vector<uint8_t> packet = generatePacket();
    controller.receivePacket(packet);
}

// Generate packet for UART transmission
std::vector<uint8_t> MotionSensor::generatePacket() const {
    std::vector<uint8_t> newPacket;
    newPacket.push_back(0xAA);

    newPacket.push_back(static_cast<uint8_t>(SensorType::MotionSensor));

    float data = readData();
    uint8_t* dataBytes = reinterpret_cast<uint8_t*>(&data);

    for (size_t i = 0; i < sizeof(float); ++i) {
        newPacket.push_back(dataBytes[i]);
    }

    newPacket.push_back(0xFF);
    return newPacket;
}
