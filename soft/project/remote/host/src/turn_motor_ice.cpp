
#include "turn_motor_ice.h"

TurnMotorIce::TurnMotorIce()
: ::Device::TurnMotor()
{
}

TurnMotorIce::~TurnMotorIce()
{
}

std::string TurnMotorIce::status( const ::Ice::Current & c )
{
    return std::string( "turn motor status" );
}

