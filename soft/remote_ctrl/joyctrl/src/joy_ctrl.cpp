
#include "joy_ctrl.h"
#include "qextserialport.h"

class JoyCtrl::PD
{
public:
    PD() {}
    ~PD() {}

    QextSerialPort * ftdi;
};

JoyCtrl::JoyCtrl()
{
    pd = new PD();
    pd->ftdi = 0;
}

JoyCtrl::~JoyCtrl()
{
    delete pd;
}

bool JoyCtrl::open()
{
    if ( pd->ftdi )
    {
        pd->ftdi->deleteLater();
    }
    QextSerialPort * port;
    port = new QextSerialPort("/dev/ttyUSB0");
    port->setBaudRate(BAUD38400);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);
    pd->ftdi = port;
    bool res = port->open( QIODevice::ReadWrite );
    if ( !res )
    {
        port->deleteLater();
        pd->ftdi = 0;
    }
    return res;
}

bool JoyCtrl::isOpen()
{
    if ( !pd->ftdi )
        return false;
    bool res = pd->ftdi->isOpen();
    return res;
}


void JoyCtrl::close()
{
    if ( pd->ftdi )
    {
        pd->ftdi->close();
        pd->ftdi->deleteLater();
    }
    pd->ftdi = 0;
}

bool JoyCtrl::query( unsigned char * buffer, int & sz )
{
    const int SZ = 32;
    int tries = 500;
    int bytes;
    unsigned char arg = 0;
    int cnt = pd->ftdi->write( reinterpret_cast<char *>( &arg ), 1 );
    if ( cnt < 1 )
        return false;
    while ( true )
    {
        int bytes;
        bytes = pd->ftdi->bytesAvailable();
        if ( bytes >= SZ )
            break;
        tries--;
        if ( tries <= 0 )
            return false;
        usleep( 1000 );
    }
    sz = pd->ftdi->read( reinterpret_cast<char *>( buffer ), SZ );
    if ( sz < SZ )
        return false;
    return true;
}







