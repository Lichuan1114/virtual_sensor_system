#ifndef MOTION_SENSOR_H
#define MOTION_SENSOR_H
#include "Sensor.h"
#include <chrono>

// Forward declaration
class Controller;

class MotionSensor : public Sensor {
private:
    std::string name;
    bool motionDetected;         // Flag to indicate if motion is detected
    float sensitivity;           // Sensitivity of the sensor (0.0 to 1.0)
    float noiseLevel;            // Probability of generating false motion data
    std::chrono::steady_clock::time_point lastMotionTime;
    int cooldownPeriod;

public:
    MotionSensor(const std::string& name, bool motionDetected = false, float sensitivity = 0.9, 
                float noiseLevel = 0.1, std::chrono::steady_clock::time_point lastMotionTime = std::chrono::steady_clock::now(), 
                int cooldownPeriod = 2);

    // Override method to read data and name
    float readData() const override;
    std::string getName() const override;

    // Generate and update new value
    void updateMotionDetected(bool newMotionDetected);
    void generateRandomMotion();

    // Methods to send packets to the controller
    void sendToController(Controller& controller) const override;
    std::vector<uint8_t> generatePacket() const;
};

#endif