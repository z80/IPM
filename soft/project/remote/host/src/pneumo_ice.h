
#ifndef __PNEUMO_ICE_H_
#define __PNEUMO_ICE_H_

#include "pneumo.h"

class PneumoIce: public ::Device::Pneumo
{
public:
    PneumoIce();
    ~PneumoIce();

    std::string status( const ::Ice::Current& = ::Ice::Current() );
};


#endif


