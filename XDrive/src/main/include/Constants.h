// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>


namespace constant
{
    //motors
    static constexpr int TITAN_ID       = 42;
    static constexpr int FRONT_LEFT     = 2;
    static constexpr int BACK_LEFT      = 3;
    static constexpr int FRONT_RIGHT    = 0;
    static constexpr int BACK_RIGHT     = 1;


    //encoder 
    static constexpr double WHEEL_RADIUS    = 51;
    static constexpr double PLUSE_PER_REV   = 1464;
    static constexpr double GEAR_RATIO      = 1/1;
    static constexpr double ENCODER_PLUS_RATIO = PLUSE_PER_REV * GEAR_RATIO;
    static constexpr double DIST_PER_TICK       = ( M_1_PI * WHEEL_RADIUS ) / ENCODER_PLUS_RATIO;

    //input
    static constexpr int START_BUTTON       = 9;
    static constexpr int STOP_BUTTON        = 11;


    //outputs
    static constexpr int RUNNING_LED        = 20;
    static constexpr int STOPPED_LED        = 21;

}
