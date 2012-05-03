
#include "actuator_ice.h"

ActuatorIce::ActuatorIce()
: ::Device::Actuator()
{
}

ActuatorIce::~ActuatorIce()
{
}

std::string ActuatorIce::status( const ::Ice::Current & c )
{
    return std::string( "actuator status" );
}

