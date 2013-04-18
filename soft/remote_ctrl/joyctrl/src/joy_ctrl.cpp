
#include "joy_ctrl.h"
#include "ftdi.hpp"

class JoyCtrl::PD
{
public:
    PD() {}
    ~PD() {}

    Ftdi::Context ftdi;
};

JoyCtrl::JoyCtrl()
{
    pd = new PD();
}

JoyCtrl::~JoyCtrl()
{
    delete pd;
}

bool JoyCtrl::open()
{
    Ftdi::Context & c = pd->ftdi;
    bool res = c.open( 1234, 5678 );
    return res;
}

bool JoyCtrl::isOpen()
{
    Ftdi::Context & c = pd->ftdi;
    bool res = c.is_open();
    return res;
}


void JoyCtrl::close()
{
    Ftdi::Context & c = pd->ftdi;
    c.close();
}

bool JoyCtrl::query()
{
    const int sz = 12;
    unsigned char buffer[sz];
    Ftdi::Context & c = pd->ftdi;
    int cnt = c.write( buffer, 1 );
    if ( cnt < 1 )
        return false;
    cnt = c.read( buffer, sz );
    if ( cnt < sz )
        return false;
    return true;
}







