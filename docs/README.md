# Virtual Sensor System

## Overview
The Virtual Sensor System is a simulation-based project designed to emulate the functionality of a smart system that integrates multiple sensors. It demonstrates data collection, event triggering, and logging for visualization and analysis.

This project includes:
- Three types of sensors: **Motion Sensor**, **Temperature Sensor**, and **Light Sensor**.
- Sensors send data using packets, simulating UART communication.
- A central controller to process sensor data.
- A trigger manager to evaluate events based on predefined rules.
- Data logging for visualization.
- Visualization for each sensor type.

## Features
- Simulates real-time sensor data generation.
- Event-driven responses based on sensor readings, including:
  - Intrusion Alarm
  - Temperature Alarm
  - Adjusting Brightness
  - Controlling Lighting
  - Controlling AC
- Logs all data and events to a CSV file for later analysis.
- Visualizes logged data using Python.

## System Architecture
The system's architecture includes the following components:

![System Architecture](./system_architecture.png)

## Getting Started

### Prerequisites
To build and run the project, you will need:
- **C++ Compiler** supporting C++14
- **CMake** (version 3.10 or higher)
- **Python 3.x** with the following libraries:
  - `pandas`
  - `matplotlib`

### Building the Project
1. Clone the repository:
   ```bash
   git clone https://github.com/Lichuan1114/virtual_sensor_system.git
   cd virtual_sensor_system/cpp

2. Create a build directory:
   ```bash
   mkdir build
   cd build

3. Run CMake to generate build files:
   ```bash
   cmake ..

4. Build the project:
   ```bash
   make

5. Run the executable:
   ```bash
   ./sensor_simulation

6. The program will generate a log file sensor_logs.csv in the output directory.

### Visualizing the Data

1. Navigate to the Python visualization script directory:
   ```bash
   cd python

2. Run the script:
   ```bash
   python visualize_data.py

3. The generated plots will be saved in the plots directory.

### Directory Structure

virtual_sensor_system/  
├── cpp/  
│   ├── Controller/  
│   │   ├── Controller.h  
│   │   └── Controller.cpp  
│   ├── Sensors/  
│   │   ├── Sensor.h  
│   │   ├── Sensor.cpp  
│   │   ├── SensorEvent.h  
│   │   ├── TemperatureSensor.h  
│   │   ├── TemperatureSensor.cpp  
│   │   ├── LightSensor.h  
│   │   ├── LightSensor.cpp  
│   │   ├── MotionSensor.h  
│   │   └── MotionSensor.cpp  
│   ├── TriggerManager/  
│   │   ├── TriggerManager.h  
│   │   └── TriggerManager.cpp  
│   ├── Utils/  
│   │   └── TimeUtils.h  
│   ├── output/  
│   │   └── sensor_logs.csv  
│   ├── main.cpp  
│   └── CMakeLists.txt  
├── python/  
│   ├── visualize_data.py   
│   └── requirements.txt  
└── docs/  
    ├── README.md   
    └── DESIGN.md  

