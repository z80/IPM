
#include "manipulator_ice.h"

ManipulatorIce::ManipulatorIce()
: ::Device::Manipulator()
{
}

ManipulatorIce::~ManipulatorIce()
{
}

std::string ManipulatorIce::status( const ::Ice::Current & c )
{
    return std::string( "manipulator status" );
}

