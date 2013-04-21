
#include "joy_ctrl.h"
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/ioctl.h>

class JoyCtrl::PD
{
public:
    PD() {}
    ~PD() {}

    int ftdi;
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
    pd->ftdi = ::open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY );
    if ( pd->ftdi < 0 )
        return false;
    struct termios options;
    tcgetattr( pd->ftdi, &options );
    cfsetispeed( &options, B38400 );
    cfsetospeed( &options, B38400 );
    options.c_cflag &= ~( HUPCL | CSTOPB | CSIZE );
    options.c_cflag |= (CLOCAL | CREAD | CS8 );

    options.c_iflag &= ~( IXON | IXOFF | IXANY );

    options.c_oflag &= ~OPOST;


    tcsetattr( pd->ftdi, TCSANOW, &options );

    return true;
}

bool JoyCtrl::isOpen()
{
    bool res = (pd->ftdi >= 0);
    return res;
}


void JoyCtrl::close()
{
    ::close( pd->ftdi );
}

bool JoyCtrl::query()
{
    const int SZ = 12;
    unsigned char buffer[SZ];
    int cnt = ::write( pd->ftdi, buffer, 1 );
    if ( cnt < 1 )
        return false;
    int tries = 500;
    while ( true )
    {
        int bytes;
        ioctl( pd->ftdi, FIONREAD, &bytes );
        if ( bytes >= SZ )
            break;
        tries--;
        if ( tries <= 0 )
            return false;
        usleep( 1000 );
    }
    cnt = ::read( pd->ftdi, buffer, SZ );
    if ( cnt < SZ )
        return false;
    return true;
}







