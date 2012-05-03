
#include "pneumo_ice.h"

PneumoIce::PneumoIce()
: ::Device::Pneumo()
{
}

PneumoIce::~PneumoIce()
{
}

std::string PneumoIce::status( const ::Ice::Current & c )
{
    return std::string( "pneumo status" );
}

