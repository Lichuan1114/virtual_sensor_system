# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chuansmac/Desktop/virtual_sensor_system/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chuansmac/Desktop/virtual_sensor_system/cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/sensor_simulation.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sensor_simulation.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sensor_simulation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sensor_simulation.dir/flags.make

CMakeFiles/sensor_simulation.dir/main.cpp.o: CMakeFiles/sensor_simulation.dir/flags.make
CMakeFiles/sensor_simulation.dir/main.cpp.o: /Users/chuansmac/Desktop/virtual_sensor_system/cpp/main.cpp
CMakeFiles/sensor_simulation.dir/main.cpp.o: CMakeFiles/sensor_simulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuansmac/Desktop/virtual_sensor_system/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sensor_simulation.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sensor_simulation.dir/main.cpp.o -MF CMakeFiles/sensor_simulation.dir/main.cpp.o.d -o CMakeFiles/sensor_simulation.dir/main.cpp.o -c /Users/chuansmac/Desktop/virtual_sensor_system/cpp/main.cpp

CMakeFiles/sensor_simulation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sensor_simulation.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chuansmac/Desktop/virtual_sensor_system/cpp/main.cpp > CMakeFiles/sensor_simulation.dir/main.cpp.i

CMakeFiles/sensor_simulation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sensor_simulation.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chuansmac/Desktop/virtual_sensor_system/cpp/main.cpp -o CMakeFiles/sensor_simulation.dir/main.cpp.s

CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.o: CMakeFiles/sensor_simulation.dir/flags.make
CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.o: /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/Sensor.cpp
CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.o: CMakeFiles/sensor_simulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuansmac/Desktop/virtual_sensor_system/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.o -MF CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.o.d -o CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.o -c /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/Sensor.cpp

CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/Sensor.cpp > CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.i

CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/Sensor.cpp -o CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.s

CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.o: CMakeFiles/sensor_simulation.dir/flags.make
CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.o: /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/TemperatureSensor.cpp
CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.o: CMakeFiles/sensor_simulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuansmac/Desktop/virtual_sensor_system/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.o -MF CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.o.d -o CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.o -c /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/TemperatureSensor.cpp

CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/TemperatureSensor.cpp > CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.i

CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/TemperatureSensor.cpp -o CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.s

CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.o: CMakeFiles/sensor_simulation.dir/flags.make
CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.o: /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/LightSensor.cpp
CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.o: CMakeFiles/sensor_simulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuansmac/Desktop/virtual_sensor_system/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.o -MF CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.o.d -o CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.o -c /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/LightSensor.cpp

CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/LightSensor.cpp > CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.i

CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/LightSensor.cpp -o CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.s

CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.o: CMakeFiles/sensor_simulation.dir/flags.make
CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.o: /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/MotionSensor.cpp
CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.o: CMakeFiles/sensor_simulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuansmac/Desktop/virtual_sensor_system/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.o -MF CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.o.d -o CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.o -c /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/MotionSensor.cpp

CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/MotionSensor.cpp > CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.i

CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Sensors/MotionSensor.cpp -o CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.s

CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.o: CMakeFiles/sensor_simulation.dir/flags.make
CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.o: /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Controller/Controller.cpp
CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.o: CMakeFiles/sensor_simulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuansmac/Desktop/virtual_sensor_system/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.o -MF CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.o.d -o CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.o -c /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Controller/Controller.cpp

CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Controller/Controller.cpp > CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.i

CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chuansmac/Desktop/virtual_sensor_system/cpp/Controller/Controller.cpp -o CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.s

CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.o: CMakeFiles/sensor_simulation.dir/flags.make
CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.o: /Users/chuansmac/Desktop/virtual_sensor_system/cpp/TriggerManager/TriggerManager.cpp
CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.o: CMakeFiles/sensor_simulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuansmac/Desktop/virtual_sensor_system/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.o -MF CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.o.d -o CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.o -c /Users/chuansmac/Desktop/virtual_sensor_system/cpp/TriggerManager/TriggerManager.cpp

CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chuansmac/Desktop/virtual_sensor_system/cpp/TriggerManager/TriggerManager.cpp > CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.i

CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chuansmac/Desktop/virtual_sensor_system/cpp/TriggerManager/TriggerManager.cpp -o CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.s

# Object files for target sensor_simulation
sensor_simulation_OBJECTS = \
"CMakeFiles/sensor_simulation.dir/main.cpp.o" \
"CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.o" \
"CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.o" \
"CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.o" \
"CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.o" \
"CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.o" \
"CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.o"

# External object files for target sensor_simulation
sensor_simulation_EXTERNAL_OBJECTS =

sensor_simulation: CMakeFiles/sensor_simulation.dir/main.cpp.o
sensor_simulation: CMakeFiles/sensor_simulation.dir/Sensors/Sensor.cpp.o
sensor_simulation: CMakeFiles/sensor_simulation.dir/Sensors/TemperatureSensor.cpp.o
sensor_simulation: CMakeFiles/sensor_simulation.dir/Sensors/LightSensor.cpp.o
sensor_simulation: CMakeFiles/sensor_simulation.dir/Sensors/MotionSensor.cpp.o
sensor_simulation: CMakeFiles/sensor_simulation.dir/Controller/Controller.cpp.o
sensor_simulation: CMakeFiles/sensor_simulation.dir/TriggerManager/TriggerManager.cpp.o
sensor_simulation: CMakeFiles/sensor_simulation.dir/build.make
sensor_simulation: CMakeFiles/sensor_simulation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/chuansmac/Desktop/virtual_sensor_system/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable sensor_simulation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sensor_simulation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sensor_simulation.dir/build: sensor_simulation
.PHONY : CMakeFiles/sensor_simulation.dir/build

CMakeFiles/sensor_simulation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sensor_simulation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sensor_simulation.dir/clean

CMakeFiles/sensor_simulation.dir/depend:
	cd /Users/chuansmac/Desktop/virtual_sensor_system/cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chuansmac/Desktop/virtual_sensor_system/cpp /Users/chuansmac/Desktop/virtual_sensor_system/cpp /Users/chuansmac/Desktop/virtual_sensor_system/cpp/build /Users/chuansmac/Desktop/virtual_sensor_system/cpp/build /Users/chuansmac/Desktop/virtual_sensor_system/cpp/build/CMakeFiles/sensor_simulation.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sensor_simulation.dir/depend
