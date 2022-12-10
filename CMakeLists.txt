cmake_minimum_required(VERSION 3.23)
project(training2)

set(CMAKE_CXX_STANDARD 14)

include_directories(XDrive/src/main/include)
include_directories(XDrive/src/main/include/commands)
include_directories(XDrive/src/main/include/subsystems)

add_executable(training2
        XDrive/src/main/cpp/commands/ExampleCommand.cpp
        XDrive/src/main/cpp/subsystems/ExampleSubsystem.cpp
        XDrive/src/main/cpp/subsystems/Training.cpp
        XDrive/src/main/cpp/Robot.cpp
        XDrive/src/main/cpp/RobotContainer.cpp
        XDrive/src/main/include/commands/ExampleCommand.h
        XDrive/src/main/include/subsystems/ExampleSubsystem.h
        XDrive/src/main/include/subsystems/Training.h
        XDrive/src/main/include/subsystems/TrainingTest.cpp
        XDrive/src/main/include/Constants.h
        XDrive/src/main/include/Robot.h
        XDrive/src/main/include/RobotContainer.h
        XDrive/src/test/cpp/main.cpp)
