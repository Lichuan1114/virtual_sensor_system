#ifndef TRIGGER_MANAGER_H
#define TRIGGER_MANAGER_H

#include "../Utils/TimeUtils.h"
#include <utility> 

/**
 * @class TriggerManager
 *
 * This class provides methods to handle different events such as motion detection,
 * temperature alarms, brightness adjustments, lighting control, and air conditioning control.
 */

class TriggerManager {

public:
    std::string checkForIntrusion(bool currentMotion, Time currentTime, 
                            std::pair<Time, Time> activeTimeRange = {Time(8, 0, 0), Time(18, 0, 0)}) const;
    std::string handleTemperatureAlarm(float currentTemperature, float temperatureThreshold = 35.0f) const;
    std::string adjustBrightness(bool currentMotion, Time currentTime, float currentLux, 
                            std::pair<Time, Time> dayTimeRange = {Time(8, 0, 0), Time(18, 0, 0)}, 
                            float luxThreshold = 400.0f) const;
    std::string controlLighting(bool currentMotion, float currentLux, float luxThreshold = 300.0f) const;
    std::string controlAC(bool currentMotion, float currentTemperature, float temperatureThreshold = 35.0f) const;
};

#endif