
#ifndef __TURN_MOTOR_ICE_H_
#define __TURN_MOTOR_ICE_H_

#include "turn_motor.h"

class TurnMotorIce: public Device::TurnMotor
{
public:
    TurnMotorIce();
    ~TurnMotorIce();

    std::string status( const ::Ice::Current& = ::Ice::Current() );
};


#endif


