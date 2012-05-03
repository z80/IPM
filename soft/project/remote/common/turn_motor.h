// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice-E is licensed to you under the terms described in the
// ICEE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice-E version 1.3.0
// Generated from file `turn_motor.ice'

#ifndef __turn_motor_h__
#define __turn_motor_h__

#include <IceE/ProxyF.h>
#include <IceE/ObjectF.h>
#include <IceE/Exception.h>
#include <IceE/ScopedArray.h>
#include <IceE/Proxy.h>
#include <IceE/Object.h>
#ifndef ICEE_PURE_CLIENT
#  include <IceE/Incoming.h>
#endif
#include <IceE/Outgoing.h>
#include <C:/projects/ipm/soft/project/remote/common/factory.h>
#include <IceE/UndefSysMacros.h>

#ifndef ICEE_IGNORE_VERSION
#   if ICEE_INT_VERSION / 100 != 103
#       error IceE version mismatch!
#   endif
#   if ICEE_INT_VERSION % 100 < 0
#       error IceE patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace Device
{

class TurnMotor;

}

}

namespace Device
{

class TurnMotor;
bool operator==(const TurnMotor&, const TurnMotor&);
bool operator<(const TurnMotor&, const TurnMotor&);

}

namespace IceInternal
{

::Ice::Object* upCast(::Device::TurnMotor*);
::IceProxy::Ice::Object* upCast(::IceProxy::Device::TurnMotor*);

}

namespace Device
{

typedef ::IceInternal::Handle< ::Device::TurnMotor> TurnMotorPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Device::TurnMotor> TurnMotorPrx;

void __read(::IceInternal::BasicStream*, TurnMotorPrx&);
void __patch__TurnMotorPtr(void*, ::Ice::ObjectPtr&);

}

namespace Device
{

}

namespace Device
{

class TurnMotor : virtual public ::Factory::Device
{
public:

    typedef TurnMotorPrx ProxyType;
    typedef TurnMotorPtr PointerType;
    

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

#ifndef ICEE_PURE_CLIENT
    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);
#endif // ICEE_PURE_CLIENT

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
};

}

namespace IceProxy
{

namespace Device
{

class TurnMotor : virtual public ::IceProxy::Factory::Device
{
public:
    
    ::IceInternal::ProxyHandle<TurnMotor> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<TurnMotor*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<TurnMotor> ice_secure(bool __secure) const
    {
        return dynamic_cast<TurnMotor*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
#ifdef ICEE_HAS_ROUTER
    ::IceInternal::ProxyHandle<TurnMotor> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<TurnMotor*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
#endif // ICEE_HAS_ROUTER
    
#ifdef ICEE_HAS_LOCATOR
    ::IceInternal::ProxyHandle<TurnMotor> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<TurnMotor*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<TurnMotor> ice_adapterId(const std::string& __id) const
    {
        return dynamic_cast<TurnMotor*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
#endif // ICEE_HAS_LOCATOR
    
    ::IceInternal::ProxyHandle<TurnMotor> ice_twoway() const
    {
        return dynamic_cast<TurnMotor*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<TurnMotor> ice_oneway() const
    {
        return dynamic_cast<TurnMotor*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<TurnMotor> ice_batchOneway() const
    {
        return dynamic_cast<TurnMotor*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<TurnMotor> ice_datagram() const
    {
        return dynamic_cast<TurnMotor*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<TurnMotor> ice_batchDatagram() const
    {
        return dynamic_cast<TurnMotor*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<TurnMotor> ice_timeout(int __timeout) const
    {
        return dynamic_cast<TurnMotor*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    static const ::std::string& ice_staticId();
    
private:
    
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

#endif
