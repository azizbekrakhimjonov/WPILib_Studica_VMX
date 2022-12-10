#include "subsystems/Training.h"

#define DEBUG true

Training::Training()
{
    ResetEncoders();
    ResetYaw();

    //Motor flags
    // frontLeft.SetInverted(true);
    frontLeft.InvertRPM();
    // frontLeftEncoder.SetReverseDirection();

    // backLeft.SetInverted(true);
    backLeft.InvertRPM();
    // backLeftEncoder.SetReverseDirection();

    frontRight.SetInverted(true);
    // frontRight.InvertRPM();
    frontRightEncoder.SetReverseDirection(); 

    backRight.SetInverted(true);
    // backRight.InvertRPM();
    backLeftEncoder.SetReverseDirection();
}

void Training::Periodic()
{
    
}

void Training::ResetEncoders()
{
    frontLeftEncoder.Reset();
    backLeftEncoder.Reset();
    frontRightEncoder.Reset();
    backRightEncoder.Reset();
}

void Training::ResetYaw()
{
    navX::ZeroYaw();
}


void Training::HolonomicDrive(double x, double y, double z)
{
    denomonator = fmax(fabs(y)+fabs(x), fabs(z), 1.0);
    fontLeft.Set(y + (x * 1.1) + z / denomonator);
    backLeft.set(y - (x * 1.1) + z / denomonator);
    fontRight.Set(y - (x * 1.1) - z / denomonator);
    backRight.Set(y + (x * 1.1) - z / denomonator);
}

void Training::SetRunningLed(bool on)
{
    runningLed.Set(on);
}

void Training::SetStoppedLed(bool on)
{
    stoppedLed.Set(on);
}

double Training::GetFrontLeftEncoder()
{
    return frontLeftEncoder.GetEncoderDistance();
}

double Training::GetBackLeftEncoder()
{
    return backLeftEncoder.GetEncoderDistance();
}

double Training::GetFrontRightEncoder()
{
    return frontRightEncoder.GetEncoderDistance();
}

double Training::GetBackRightEncoder()
{
    return backRightEncoder();
}

double Training::GetAverageEncoderY()
{
    return (((GetFrontLeftEncoder()+GetBackLeftEncoder()) / 2) + ((GetFrontRightEncoder()+GetBackRightEncoder() / 2)) / 2) / 2;
}


double Training::GetYaw()
{
    return navX.GetYaw();
}

double Training::GetAngle()
{
    return navX.GetAngle();
}