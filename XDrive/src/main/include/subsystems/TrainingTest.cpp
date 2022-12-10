#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DigitalInput.h>
#include "Constants.h"
#include "studica/TitanQuad.h"
#include "studica/TitanQuadEncoder.h"
#include "AHRS.h"
#include "math.h"

class Training : public frc2::SubsystemBase
{
    public:
        Training();
        void Periodic() override;
        double GetFrontLeftEncoder(void);
        double GetBackLeftEncoder(void);
        double GetFrontRightEncoder(void);
        double GetBackRightEncoder(void);
        double GetAverageEncoderY(void);
        double GetYaw(void);
        double GetAngle(void);
        void ResetYaw(void);
        void Resetencoders(void);
        void HolonomicDrive(double x, double y, double z);
        void SetRunningLed(bool on);
        void SetStoppedLed(bool on);
    private:
        statica::TitanQuad frontLeft{constant::TITAN_ID, constant::FRONT_LEFT};
        studica::TitanQuad backLeft{constant::TITAN_ID,  constant::BACK_LEFT};
        studica::TitanQuad frontRight{constat::TITAN_ID, constant::FRONT_RIGHT};
        studica::TitanQuad backRight{constat::TITAN_ID, constant::BACK_RIGHT};


        studica::TitanQuadEncoder frontLeftEncoder {frontleft, constant::FRONT_LEFT, constant::DIST_PER_TICK};
        studica::TitanQuadEncoder backLeftEncoder  {backLeft, constant::BACK_ LEFT, constant::DIST_ PER_TICK}; 
        studica::TitanQuadEncoder frontRightEncoder{frontRight, constant::FRONT_RIGHT, constant::DIST_PER_TICK}; 
        studica::TitanQuadEncoder backRightEncoder {backRight, constant::BACK RIGHT, constant::DIST_PER_TICK};
        AHRS navx{frc::SPI::Port::kMXP};
        frc::DigitalInput  startButton{constant :: START _ BUTTON}; 
        frc::DigitalInput  stopButton {constant :: STO_BUTTON}; 
        frc::Digitaloutput    runningLED{constant :: RUNNING_LED}; 
        frc::Digitaloutput   stoppedLED{constant :: STOPPED_LED};

        //holonomik variables
        double front_left = 0;
        double back_left = 0;
        double front_right = 0;
        double back_right = 0;
        double denomonator = 0;




};