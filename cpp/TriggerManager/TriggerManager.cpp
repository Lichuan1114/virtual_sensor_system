#include "TriggerManager.h"
#include "../Utils/TimeUtils.h"

#include <iostream>

// Checks for intrusion alarm based on motion detection and active time range.
std::string TriggerManager::checkForIntrusion(bool currentMotion, Time currentTime, std::pair<Time, Time> activeTimeRange) const {
    if (currentTime.hour >= activeTimeRange.first.hour && currentTime.hour < activeTimeRange.second.hour && currentMotion) {
        return "Set off Intrusion Alarm!";
    }
    return "";
}

// Triggers temperature alarm if current temperature exceeds the threshold.
std::string TriggerManager::handleTemperatureAlarm(float currentTemperature, float temperatureThreshold) const {
    if (currentTemperature >= temperatureThreshold) {
        return "Too hot! Turn on cooler!";
    }
    return "";
}

// Adjusts brightness based on motion detection, time of day, and current lux levels.
std::string TriggerManager::adjustBrightness(bool currentMotion, Time currentTime, float currentLux,
                                        std::pair<Time, Time> dayTimeRange, float luxThreshold) const {
    if (currentMotion && currentTime.hour >= dayTimeRange.first.hour && currentTime.hour < dayTimeRange.second.hour && 
        currentLux >= luxThreshold) {
            return "Bright Enough! Dim the light!";
    }
    return "";
}

// Controls lighting by turning it on when motion is detected and lux levels are low.
std::string TriggerManager::controlLighting(bool currentMotion, float currentLux, float luxThreshold) const {
    if (currentMotion && currentLux <= luxThreshold) {
        return "Motion detected & Too dark! Turn on Light!";
    }
    return "";
}

// Controls AC by turning it on when motion is detected and temperature is high.
std::string TriggerManager::controlAC(bool currentMotion, float currentTemperature, float temperatureThreshold) const {
    if (currentMotion && currentTemperature >= temperatureThreshold) {
        return "Motion detected & Too hot! Turn on AC!";
    }
    return "";
}
