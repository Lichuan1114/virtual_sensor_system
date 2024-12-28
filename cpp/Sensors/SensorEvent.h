#ifndef SENSOR_EVENT_H
#define SENSOR_EVENT_H

#include "stdint.h"

// Enum to define the types of sensors
enum class SensorType : uint8_t {
    MotionSensor = 1,
    TemperatureSensor = 2,
    LightSensor = 3
};

// Struct to hold sensor event data
struct SensorEvent {
    SensorType type;
    float data;

    SensorEvent(SensorType t, float d) : type(t), data(d) {}
};

#endif