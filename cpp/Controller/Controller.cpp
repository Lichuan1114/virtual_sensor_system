#include "Controller.h"
#include "../Sensors/Sensor.h"
#include "../Sensors/MotionSensor.h"
#include "../Sensors/LightSensor.h"
#include "../Sensors/TemperatureSensor.h"
#include <iostream>
#include <sstream> 
#include <cstring>
#include <fstream>

// Constructor implementation
Controller::Controller(const DateTime& currentTime, const Time& startTime, const Time& endTime,
                       float tempThreshold, float lightThreshold, float luxAdjustThreshold)
    : currentTime(currentTime), startTime(startTime), endTime(endTime), temperatureThreshold(tempThreshold), 
      lightThreshold(lightThreshold), luxAdjustmentThreshold(luxAdjustThreshold) {
    // Initialize sensors
    lightSensor = std::make_unique<LightSensor>("LightSensor");
    motionSensor = std::make_unique<MotionSensor>("MotionSensor");
    temperatureSensor = std::make_unique<TemperatureSensor>("TemperatureSensor");
}

// Run the simulation for the specified duration
void Controller::runSimulation(int durationSeconds) {
    for (int i = 0; i < durationSeconds; i++) {

        // check if current time is within the time range. If yes, generate motion data every second
        if (currentTime.time >= startTime && currentTime.time < endTime) {
            motionSensor->generateRandomMotion();
            motionSensor->sendToController(*this);
        }

        // light sensor generates data every 5 seconds
        if (currentTime.time.second % 5 == 0) {
            int currentMinutes = currentTime.time.hour * 60 + currentTime.time.minute;
            lightSensor->generateRandomLux(currentMinutes); 
            lightSensor->sendToController(*this);

            // if lux level exceeds the threshold, generate and read new motion data
            currentLux = lightSensor->readData();
            if (currentLux >= lightThreshold) {
                motionSensor->generateRandomMotion();
                motionSensor->sendToController(*this);
            }
        }

        // temperature sensor generates data every 10 seconds
        if (currentTime.time.second % 10 == 0) {
            int currentMinutes = currentTime.time.hour * 60 + currentTime.time.minute;
            temperatureSensor->generateRandomTemperature(currentMinutes); 
            temperatureSensor->sendToController(*this);

            // if temperature exceeds the threshold, generate and read new motion data
            currentTemperature = temperatureSensor->readData();
            if (currentTemperature >= temperatureThreshold) {
                motionSensor->generateRandomMotion();
                motionSensor->sendToController(*this);
            }
        }
        currentTime.incrementDateTime();
    }
}

// Receive a packet of sensor data
void Controller::receivePacket(const std::vector<uint8_t>& packet) {
    if (packet.size() < 7 || packet.front() != 0xAA || packet.back() != 0xFF) {
        std::cerr << "Invalid packet" << std::endl;
        return;
    }
    processPacket(packet);
}

// Process incoming data packets
void Controller::processPacket(const std::vector<uint8_t>& packet) {
    // Packet Structure:  | START (1 byte) | Sensor Type (1 byte) | Sensor Data (4 bytes) | STOP (1 byte) |
    uint8_t sensorType = packet[1];
    float sensorData;

    // extract the data
    memcpy(&sensorData, &packet[2], sizeof(float));

    std::ostringstream log;
    SensorEvent event(static_cast<SensorType>(sensorType), sensorData);
    std::string eventTriggered = checkTriggerEvent(event);

    log << currentTime.toString() << ", " 
        << static_cast<int>(sensorType) << ", " 
        << sensorData << ", " 
        << eventTriggered;

    // Check if recentLogs exceeds the maximum number, remove oldest one if yes
    if (recentLogs.size() >= MAX_LOGS) {
        recentLogs.pop_front();
    }

    // push the sensor type and data to recentLogs
    recentLogs.push_back(log.str());

    // write to "cpp/output/sensor_logs.csv"
    writeToCSV(log.str());
}

// Print data in recentLogs
void Controller::printReceivedData() {
    std::cout << "All Received Logs:" << std::endl;
    for (const auto& log : recentLogs) {
        std::cout << log << std::endl;
    }
}

// Write the log to the CSV file
void Controller::writeToCSV(std::string currentEntry) {
    std::ofstream file("../output/sensor_logs.csv", std::ios::app); 
    if (!file.is_open()) {
        throw std::ios_base::failure("Failed to open file.");
    }

    file << currentEntry << "\n";
    file.close();
}

// Check if a sensor event triggers a response
std::string Controller::checkTriggerEvent(SensorEvent& event) {
    // record all the events triggered
    std::string triggeredEvents;

    switch (event.type) {
        case SensorType::MotionSensor:
            currentMotion = event.data;
            triggeredEvents += triggerManager.checkForIntrusion(currentMotion, currentTime.time) + " ";
            triggeredEvents += triggerManager.controlAC(currentMotion, currentTemperature) + " ";

            // Adjusted brightness if lux level is high enough
            if (!triggerManager.adjustBrightness(currentMotion, currentTime.time, currentLux).empty()) {
                currentLux = 300.0f;
                triggeredEvents += "Adjusted brightness to 300.0 lux. ";
            }
            break;

        case SensorType::TemperatureSensor:
            currentTemperature = event.data;
            triggeredEvents += triggerManager.handleTemperatureAlarm(currentTemperature) + " ";
            triggeredEvents += triggerManager.controlAC(currentMotion, currentTemperature) + " ";
            break;

        case SensorType::LightSensor:
            currentLux = event.data;
            triggeredEvents += triggerManager.controlLighting(currentMotion, currentLux) + " ";
            
            // Adjusted brightness if lux level is high enough
            if (!triggerManager.adjustBrightness(currentMotion, currentTime.time, currentLux).empty()) {
                currentLux = 300.0f;
                triggeredEvents += "Adjusted brightness to 300.0 lux. ";
            }
            break;

        default:
            break;
    }

    // remove the blank at the end
    if (!triggeredEvents.empty() && triggeredEvents.back() == ' ') {
        triggeredEvents.pop_back();
    }

    return triggeredEvents;
}

