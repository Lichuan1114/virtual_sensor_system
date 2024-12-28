#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../TriggerManager/TriggerManager.h"
#include "../Sensors/SensorEvent.h"
#include "../Utils/TimeUtils.h"
#include "../Sensors/MotionSensor.h"
#include "../Sensors/LightSensor.h"
#include "../Sensors/TemperatureSensor.h"
#include <string>
#include <vector>
#include <memory>
#include <deque>

// Forward declarations for sensor classes to avoid circular dependencies
class MotionSensor;
class LightSensor;
class TemperatureSensor;

// Controller class manages the simulation, data processing, and triggering logic
class Controller {
private:
    std::deque<std::string> recentLogs;
    TriggerManager triggerManager;
    DateTime currentTime;

    // Motion Sensor active time range (e.g., start and end time)
    Time startTime;
    Time endTime;

    // Iniitialize all sensors
    std::unique_ptr<LightSensor> lightSensor;
    std::unique_ptr<MotionSensor> motionSensor;
    std::unique_ptr<TemperatureSensor> temperatureSensor;

    // Maximum number of logs to maintain
    static constexpr size_t MAX_LOGS = 100;

    // Track current sensor states
    bool currentMotion = false;
    float currentTemperature = 0.0;
    float currentLux = 0.0;

    // Threshold variables - for trigger manager
    float temperatureThreshold = 35.0f;
    float lightThreshold = 300.0f;
    float luxAdjustmentThreshold = 400.0f;


public: 
    // constructor for the controller
    Controller(const DateTime& currentTime, const Time& startTime, const Time& endTime, 
                float tempThreshold = 35.0f, float lightThreshold = 300.0f, float luxAdjustThreshold = 400.0f);

    // Starts the simulation (the unit is seconds)
    void runSimulation(int durationSeconds);

    // receive and process packets
    void receivePacket(const std::vector<uint8_t>& packet);
    void processPacket(const std::vector<uint8_t>& packet);

    // check the triggered events from received data
    std::string checkTriggerEvent(SensorEvent& event);

    // write to "cpp/output/sensor_logs.csv"
    void writeToCSV(std::string currentEntry);

    // print data in recentLogs
    void printReceivedData();
};

#endif