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

#include <factory.h>
#include <IceE/LocalException.h>
#include <IceE/ObjectFactory.h>
#include <IceE/BasicStream.h>
#include <IceE/Iterator.h>

#ifndef ICEE_IGNORE_VERSION
#   if ICEE_INT_VERSION / 100 != 103
#       error IceE version mismatch!
#   endif
#   if ICEE_INT_VERSION % 100 < 0
#       error IceE patch level mismatch!
#   endif
#endif

static const ::std::string __Factory__Device__status_name = "status";

static const ::std::string __Factory__DeviceFactory__interfaces_name = "interfaces";

static const ::std::string __Factory__DeviceFactory__query_name = "query";

::Ice::Object* IceInternal::upCast(::Factory::Device* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::Factory::Device* p) { return p; }

::Ice::Object* IceInternal::upCast(::Factory::DeviceFactory* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::Factory::DeviceFactory* p) { return p; }

void
Factory::__read(::IceInternal::BasicStream* __is, ::Factory::DevicePrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Factory::Device;
        v->__copyFrom(proxy);
    }
}

void
Factory::__read(::IceInternal::BasicStream* __is, ::Factory::DeviceFactoryPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Factory::DeviceFactory;
        v->__copyFrom(proxy);
    }
}

static const ::std::string __Factory__Device_ids[2] =
{
    "::Factory::Device",
    "::Ice::Object"
};

bool
Factory::Device::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Factory__Device_ids, __Factory__Device_ids + 2, _s);
}

::std::vector< ::std::string>
Factory::Device::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Factory__Device_ids[0], &__Factory__Device_ids[2]);
}

const ::std::string&
Factory::Device::ice_id(const ::Ice::Current&) const
{
    return __Factory__Device_ids[0];
}

const ::std::string&
Factory::Device::ice_staticId()
{
    return __Factory__Device_ids[0];
}

#ifndef ICEE_PURE_CLIENT
::Ice::DispatchStatus
Factory::Device::___status(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string __ret = status(__current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}
#endif // ICEE_PURE_CLIENT

#ifndef ICEE_PURE_CLIENT
static ::std::string __Factory__Device_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "status"
};

::Ice::DispatchStatus
Factory::Device::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Factory__Device_all, __Factory__Device_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Factory__Device_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___status(in, current);
        }
    }

    assert(false);
    throw Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}
#endif // ICEE_PURE_CLIENT

void
Factory::Device::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
    ::Ice::Object::__write(__os);
}

void
Factory::Device::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
    ::Ice::Object::__read(__is, true);
}


bool
Factory::operator==(const ::Factory::Device& l, const ::Factory::Device& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Factory::operator<(const ::Factory::Device& l, const ::Factory::Device& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

void 
Factory::__patch__DevicePtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Factory::DevicePtr* p = static_cast< ::Factory::DevicePtr*>(__addr);
    assert(p);
    *p = ::Factory::DevicePtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::Factory::Device::ice_staticId(), v->ice_id());
    }
}

static const ::std::string __Factory__DeviceFactory_ids[2] =
{
    "::Factory::DeviceFactory",
    "::Ice::Object"
};

bool
Factory::DeviceFactory::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Factory__DeviceFactory_ids, __Factory__DeviceFactory_ids + 2, _s);
}

::std::vector< ::std::string>
Factory::DeviceFactory::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Factory__DeviceFactory_ids[0], &__Factory__DeviceFactory_ids[2]);
}

const ::std::string&
Factory::DeviceFactory::ice_id(const ::Ice::Current&) const
{
    return __Factory__DeviceFactory_ids[0];
}

const ::std::string&
Factory::DeviceFactory::ice_staticId()
{
    return __Factory__DeviceFactory_ids[0];
}

#ifndef ICEE_PURE_CLIENT
::Ice::DispatchStatus
Factory::DeviceFactory::___interfaces(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Factory::TStringArray __ret = interfaces(__current);
    if(__ret.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        __os->write(&__ret[0], &__ret[0] + __ret.size());
    }
    return ::Ice::DispatchOK;
}
#endif // ICEE_PURE_CLIENT

#ifndef ICEE_PURE_CLIENT
::Ice::DispatchStatus
Factory::DeviceFactory::___query(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string interfaceName;
    __is->read(interfaceName);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Factory::DevicePrx __ret = query(interfaceName, __current);
    __os->write(::Ice::ObjectPrx(::IceInternal::upCast(__ret.get())));
    return ::Ice::DispatchOK;
}
#endif // ICEE_PURE_CLIENT

#ifndef ICEE_PURE_CLIENT
static ::std::string __Factory__DeviceFactory_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "interfaces",
    "query"
};

::Ice::DispatchStatus
Factory::DeviceFactory::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Factory__DeviceFactory_all, __Factory__DeviceFactory_all + 6, current.operation);
    if(r.first == r.second)
    {
        throw Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Factory__DeviceFactory_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___interfaces(in, current);
        }
        case 5:
        {
            return ___query(in, current);
        }
    }

    assert(false);
    throw Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}
#endif // ICEE_PURE_CLIENT

void
Factory::DeviceFactory::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
    ::Ice::Object::__write(__os);
}

void
Factory::DeviceFactory::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
    ::Ice::Object::__read(__is, true);
}


bool
Factory::operator==(const ::Factory::DeviceFactory& l, const ::Factory::DeviceFactory& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Factory::operator<(const ::Factory::DeviceFactory& l, const ::Factory::DeviceFactory& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

void 
Factory::__patch__DeviceFactoryPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Factory::DeviceFactoryPtr* p = static_cast< ::Factory::DeviceFactoryPtr*>(__addr);
    assert(p);
    *p = ::Factory::DeviceFactoryPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::Factory::DeviceFactory::ice_staticId(), v->ice_id());
    }
}

::std::string
IceProxy::Factory::Device::status(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::RequestHandlerPtr __handler;
        try
        {
            __checkTwowayOnly(__Factory__Device__status_name);
            __handler = __getRequestHandler();
            ::IceInternal::Outgoing __outS(__handler.get(), _reference.get(), __Factory__Device__status_name, ::Ice::Normal, __ctx);
            bool __ok = __outS.invoke();
            try
            {
                if(!__ok)
                {
                    __outS.is()->throwUnknownUserException();
                }
                ::std::string __ret;
                ::IceInternal::BasicStream* __is = __outS.is();
                __is->read(__ret);
                return __ret;
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
#if defined(_MSC_VER) && defined(_M_ARM) // ARM bug.
            catch(...)
            {
                throw;
            }
#endif
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__handler, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__handler, __ex, __cnt);
        }
#if defined(_MSC_VER) && defined(_M_ARM) // ARM bug.
        catch(...)
        {
            throw;
        }
#endif
    }
}

const ::std::string&
IceProxy::Factory::Device::ice_staticId()
{
    return __Factory__Device_ids[0];
}

::IceProxy::Ice::Object*
IceProxy::Factory::Device::__newInstance() const
{
    return new Device;
}

::Factory::TStringArray
IceProxy::Factory::DeviceFactory::interfaces(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::RequestHandlerPtr __handler;
        try
        {
            __checkTwowayOnly(__Factory__DeviceFactory__interfaces_name);
            __handler = __getRequestHandler();
            ::IceInternal::Outgoing __outS(__handler.get(), _reference.get(), __Factory__DeviceFactory__interfaces_name, ::Ice::Idempotent, __ctx);
            bool __ok = __outS.invoke();
            try
            {
                if(!__ok)
                {
                    __outS.is()->throwUnknownUserException();
                }
                ::Factory::TStringArray __ret;
                ::IceInternal::BasicStream* __is = __outS.is();
                __is->read(__ret);
                return __ret;
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
#if defined(_MSC_VER) && defined(_M_ARM) // ARM bug.
            catch(...)
            {
                throw;
            }
#endif
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__handler, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__handler, __ex, __cnt);
        }
#if defined(_MSC_VER) && defined(_M_ARM) // ARM bug.
        catch(...)
        {
            throw;
        }
#endif
    }
}

::Factory::DevicePrx
IceProxy::Factory::DeviceFactory::query(const ::std::string& interfaceName, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::RequestHandlerPtr __handler;
        try
        {
            __checkTwowayOnly(__Factory__DeviceFactory__query_name);
            __handler = __getRequestHandler();
            ::IceInternal::Outgoing __outS(__handler.get(), _reference.get(), __Factory__DeviceFactory__query_name, ::Ice::Normal, __ctx);
            try
            {
                ::IceInternal::BasicStream* __os = __outS.os();
                __os->write(interfaceName);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                __outS.abort(__ex);
            }
            bool __ok = __outS.invoke();
            try
            {
                if(!__ok)
                {
                    __outS.is()->throwUnknownUserException();
                }
                ::Factory::DevicePrx __ret;
                ::IceInternal::BasicStream* __is = __outS.is();
                ::Factory::__read(__is, __ret);
                return __ret;
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
#if defined(_MSC_VER) && defined(_M_ARM) // ARM bug.
            catch(...)
            {
                throw;
            }
#endif
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__handler, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__handler, __ex, __cnt);
        }
#if defined(_MSC_VER) && defined(_M_ARM) // ARM bug.
        catch(...)
        {
            throw;
        }
#endif
    }
}

const ::std::string&
IceProxy::Factory::DeviceFactory::ice_staticId()
{
    return __Factory__DeviceFactory_ids[0];
}

::IceProxy::Ice::Object*
IceProxy::Factory::DeviceFactory::__newInstance() const
{
    return new DeviceFactory;
}
