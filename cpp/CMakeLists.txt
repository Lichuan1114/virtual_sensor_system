cmake_minimum_required(VERSION 3.10)

# Project name
project(virtual_sensor_system)

# C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    main.cpp
    Sensors/TemperatureSensor.cpp
    Sensors/LightSensor.cpp
    Sensors/MotionSensor.cpp
    Controller/Controller.cpp
    TriggerManager/TriggerManager.cpp
)

# Add executable
add_executable(sensor_simulation ${SOURCES})
