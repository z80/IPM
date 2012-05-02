
#include "factory_ice.h"
#include "thread_ice.h"
#include "actuator_ice.h"
#include "manipulator_ice.h"
#include "turn_motor_ice.h"
#include "pneumo_ice.h"

FactoryIce::FactoryIce( ThreadIce * parent )
: ::Factory::DeviceFactory()
{
    //m_hum    = new HumidityIce();
    //m_humPrx = ::Factory::DevicePrx::uncheckedCast( parent->adapter()->addWithUUID( m_hum ) );
    m_pneumo         = new Pneumo();
    m_turnMoto       = new TurnMoto();
    m_actuator       = new Actuator();
    m_manipulator    = new Manipulator();
    m_pneumoPrx      = ::Factory::DevicePrx::uncheckedCast( parent->adapter()->addWithUUID( m_pneumo ) );
    m_turnMotoPrx    = ::Factory::DevicePrx::uncheckedCast( parent->adapter()->addWithUUID( m_turnMoto ) );
    m_actuatorPrx    = ::Factory::DevicePrx::uncheckedCast( parent->adapter()->addWithUUID( m_actuator ) );
    m_manipulatorPrx = ::Factory::DevicePrx::uncheckedCast( parent->adapter()->addWithUUID( m_manipulator ) );
}

FactoryIce::FactoryIce()
{
}

::Factory::TStringArray FactoryIce::interfaces(const ::Ice::Current & c )
{
    ::Factory::TStringArray types;
    types.push_back( "pneumo" );
    types.push_back( "turn_moto" );
    types.push_back( "actuator" );
    types.push_back( "manipulator" );
    return types;
}

::Factory::DevicePrx FactoryIce::query(const ::std::string & interfaceName, const ::Ice::Current & c )
{
    if ( interfaceName == "pneumo" )
        return m_pneumoPrx;
    else if ( interfaceName == "turn_moto" )
        return m_turnMotoPrx;
    else if ( interfaceName == "actuator" )
        return m_actuatorPrx;
    if ( interfaceName == "manipulator" )
        return m_manipulatorPrx;
    return 0;
}


