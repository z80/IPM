
#ifndef __MANIPULATOR_ICE_H_
#define __MANIPULATOR_ICE_H_

#include "manipulator.h"

class ManipulatorIce: public Device::Manipulator
{
public:
    ManipulatorIce();
    ~ManipulatorIce();

    std::string status( const ::Ice::Current& = ::Ice::Current() );
};


#endif


