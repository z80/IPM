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

#include <turn_motor.h>
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

::Ice::Object* IceInternal::upCast(::Device::TurnMotor* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::Device::TurnMotor* p) { return p; }

void
Device::__read(::IceInternal::BasicStream* __is, ::Device::TurnMotorPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Device::TurnMotor;
        v->__copyFrom(proxy);
    }
}

static const ::std::string __Device__TurnMotor_ids[3] =
{
    "::Device::TurnMotor",
    "::Factory::Device",
    "::Ice::Object"
};

bool
Device::TurnMotor::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Device__TurnMotor_ids, __Device__TurnMotor_ids + 3, _s);
}

::std::vector< ::std::string>
Device::TurnMotor::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Device__TurnMotor_ids[0], &__Device__TurnMotor_ids[3]);
}

const ::std::string&
Device::TurnMotor::ice_id(const ::Ice::Current&) const
{
    return __Device__TurnMotor_ids[0];
}

const ::std::string&
Device::TurnMotor::ice_staticId()
{
    return __Device__TurnMotor_ids[0];
}

#ifndef ICEE_PURE_CLIENT
static ::std::string __Device__TurnMotor_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "status"
};

::Ice::DispatchStatus
Device::TurnMotor::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Device__TurnMotor_all, __Device__TurnMotor_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Device__TurnMotor_all)
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
Device::TurnMotor::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
    ::Ice::Object::__write(__os);
}

void
Device::TurnMotor::__read(::IceInternal::BasicStream* __is, bool __rid)
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
Device::operator==(const ::Device::TurnMotor& l, const ::Device::TurnMotor& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Device::operator<(const ::Device::TurnMotor& l, const ::Device::TurnMotor& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

void 
Device::__patch__TurnMotorPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Device::TurnMotorPtr* p = static_cast< ::Device::TurnMotorPtr*>(__addr);
    assert(p);
    *p = ::Device::TurnMotorPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::Device::TurnMotor::ice_staticId(), v->ice_id());
    }
}

const ::std::string&
IceProxy::Device::TurnMotor::ice_staticId()
{
    return __Device__TurnMotor_ids[0];
}

::IceProxy::Ice::Object*
IceProxy::Device::TurnMotor::__newInstance() const
{
    return new TurnMotor;
}
