
#ifndef __FACTORY_ICE_H_
#define __FACTORY_ICE_H_

#include "factory.h"
class ThreadIce;

class FactoryIce: public Factory::DeviceFactory
{
public:
    FactoryIce( ThreadIce * parent );
    FactoryIce();

    ::Factory::TStringArray interfaces(const ::Ice::Current& = ::Ice::Current() );
    ::Factory::DevicePrx query(const ::std::string&, const ::Ice::Current& = ::Ice::Current() );
private:
    ::Factory::DevicePtr m_pneumo, 
                         m_turnMotor, 
                         m_actuator, 
                         m_manipulator;
    ::Factory::DevicePrx m_pneumoPrx, 
                         m_turnMotorPrx, 
                         m_actuatorPrx, 
                         m_manipulatorPrx;
};




#endif


