#include <iostream>
#include "Controller/Controller.h"

// Main function: entry point of the application
int main() {
    // Define the time at which the motion sensor will be active (start and stop times)
    Time sensorOnTime(8, 0, 0);
    Time sensorOffTime(18, 0, 0);

    // Set the initial simulation date and time
    DateTime currentTime(2024, 12, 23, Time(10, 30, 00));

    // Define the simulation duration in seconds (24 hours in this case)
    int simulationDurationSeconds = 86400;

    // Create the central controller
    Controller centralController(currentTime, sensorOnTime, sensorOffTime);
    centralController.runSimulation(simulationDurationSeconds);

    return 0;
}