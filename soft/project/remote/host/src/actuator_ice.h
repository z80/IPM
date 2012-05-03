
#ifndef __ACTUATOR_ICE_H_
#define __ACTUATOR_ICE_H_

#include "actuator.h"

class ActuatorIce: public Device::Actuator
{
public:
    ActuatorIce();
    ~ActuatorIce();

    std::string status( const ::Ice::Current& = ::Ice::Current() );
};


#endif


