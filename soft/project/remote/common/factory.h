// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice-E is licensed to you under the terms described in the
// ICEE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice-E version 1.3.0
// Generated from file `factory.ice'

#ifndef __factory_h__
#define __factory_h__

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

namespace Factory
{

class Device;

class DeviceFactory;

}

}

namespace Factory
{

class Device;
bool operator==(const Device&, const Device&);
bool operator<(const Device&, const Device&);

class DeviceFactory;
bool operator==(const DeviceFactory&, const DeviceFactory&);
bool operator<(const DeviceFactory&, const DeviceFactory&);

}

namespace IceInternal
{

::Ice::Object* upCast(::Factory::Device*);
::IceProxy::Ice::Object* upCast(::IceProxy::Factory::Device*);

::Ice::Object* upCast(::Factory::DeviceFactory*);
::IceProxy::Ice::Object* upCast(::IceProxy::Factory::DeviceFactory*);

}

namespace Factory
{

typedef ::IceInternal::Handle< ::Factory::Device> DevicePtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Factory::Device> DevicePrx;

void __read(::IceInternal::BasicStream*, DevicePrx&);
void __patch__DevicePtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::Factory::DeviceFactory> DeviceFactoryPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Factory::DeviceFactory> DeviceFactoryPrx;

void __read(::IceInternal::BasicStream*, DeviceFactoryPrx&);
void __patch__DeviceFactoryPtr(void*, ::Ice::ObjectPtr&);

}

namespace Factory
{

typedef ::std::vector< ::std::string> TStringArray;

}

namespace Factory
{

class Device : virtual public ::Ice::Object
{
public:

    typedef DevicePrx ProxyType;
    typedef DevicePtr PointerType;
    

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::std::string status(const ::Ice::Current& = ::Ice::Current()) = 0;
#ifndef ICEE_PURE_CLIENT
    ::Ice::DispatchStatus ___status(::IceInternal::Incoming&, const ::Ice::Current&);
#endif // ICEE_PURE_CLIENT

#ifndef ICEE_PURE_CLIENT
    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);
#endif // ICEE_PURE_CLIENT

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
};

class DeviceFactory : virtual public ::Ice::Object
{
public:

    typedef DeviceFactoryPrx ProxyType;
    typedef DeviceFactoryPtr PointerType;
    

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::Factory::TStringArray interfaces(const ::Ice::Current& = ::Ice::Current()) = 0;
#ifndef ICEE_PURE_CLIENT
    ::Ice::DispatchStatus ___interfaces(::IceInternal::Incoming&, const ::Ice::Current&);
#endif // ICEE_PURE_CLIENT

    virtual ::Factory::DevicePrx query(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
#ifndef ICEE_PURE_CLIENT
    ::Ice::DispatchStatus ___query(::IceInternal::Incoming&, const ::Ice::Current&);
#endif // ICEE_PURE_CLIENT

#ifndef ICEE_PURE_CLIENT
    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);
#endif // ICEE_PURE_CLIENT

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
};

}

namespace IceProxy
{

namespace Factory
{

class Device : virtual public ::IceProxy::Ice::Object
{
public:

    ::std::string status()
    {
        return status(0);
    }
    ::std::string status(const ::Ice::Context& __ctx)
    {
        return status(&__ctx);
    }
    
private:

    ::std::string status(const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<Device> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<Device> ice_secure(bool __secure) const
    {
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
#ifdef ICEE_HAS_ROUTER
    ::IceInternal::ProxyHandle<Device> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
#endif // ICEE_HAS_ROUTER
    
#ifdef ICEE_HAS_LOCATOR
    ::IceInternal::ProxyHandle<Device> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<Device> ice_adapterId(const std::string& __id) const
    {
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
#endif // ICEE_HAS_LOCATOR
    
    ::IceInternal::ProxyHandle<Device> ice_twoway() const
    {
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<Device> ice_oneway() const
    {
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<Device> ice_batchOneway() const
    {
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<Device> ice_datagram() const
    {
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<Device> ice_batchDatagram() const
    {
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<Device> ice_timeout(int __timeout) const
    {
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    static const ::std::string& ice_staticId();
    
private:
    
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class DeviceFactory : virtual public ::IceProxy::Ice::Object
{
public:

    ::Factory::TStringArray interfaces()
    {
        return interfaces(0);
    }
    ::Factory::TStringArray interfaces(const ::Ice::Context& __ctx)
    {
        return interfaces(&__ctx);
    }
    
private:

    ::Factory::TStringArray interfaces(const ::Ice::Context*);
    
public:

    ::Factory::DevicePrx query(const ::std::string& interfaceName)
    {
        return query(interfaceName, 0);
    }
    ::Factory::DevicePrx query(const ::std::string& interfaceName, const ::Ice::Context& __ctx)
    {
        return query(interfaceName, &__ctx);
    }
    
private:

    ::Factory::DevicePrx query(const ::std::string&, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<DeviceFactory> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<DeviceFactory*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<DeviceFactory> ice_secure(bool __secure) const
    {
        return dynamic_cast<DeviceFactory*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
#ifdef ICEE_HAS_ROUTER
    ::IceInternal::ProxyHandle<DeviceFactory> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<DeviceFactory*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
#endif // ICEE_HAS_ROUTER
    
#ifdef ICEE_HAS_LOCATOR
    ::IceInternal::ProxyHandle<DeviceFactory> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<DeviceFactory*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<DeviceFactory> ice_adapterId(const std::string& __id) const
    {
        return dynamic_cast<DeviceFactory*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
#endif // ICEE_HAS_LOCATOR
    
    ::IceInternal::ProxyHandle<DeviceFactory> ice_twoway() const
    {
        return dynamic_cast<DeviceFactory*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<DeviceFactory> ice_oneway() const
    {
        return dynamic_cast<DeviceFactory*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<DeviceFactory> ice_batchOneway() const
    {
        return dynamic_cast<DeviceFactory*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<DeviceFactory> ice_datagram() const
    {
        return dynamic_cast<DeviceFactory*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<DeviceFactory> ice_batchDatagram() const
    {
        return dynamic_cast<DeviceFactory*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<DeviceFactory> ice_timeout(int __timeout) const
    {
        return dynamic_cast<DeviceFactory*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    static const ::std::string& ice_staticId();
    
private:
    
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

#endif
