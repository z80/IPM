
#include "joyctrl_top.h"

#define JOY_CNT     4

class JoyCtrlTop::PD
{
public:
    PD() {}
    ~PD() {}

    int  adcX[ JOY_CNT ];
    int  adcY[ JOY_CNT ];
    bool nullX[ JOY_CNT ];
    bool nullY[ JOY_CNT ];
    bool stop;
};

JoyCtrlTop::JoyCtrlTop()
: JoyCtrl()
{
    pd = new PD();
}

JoyCtrlTop::~JoyCtrlTop()
{
    delete pd;
}

bool JoyCtrlTop::queryState()
{
    const int SZ = 20;
    unsigned char buffer[ SZ ];
    int sz;
    bool res = query( buffer, sz );
    if ( !res )
        return false;
    for ( int i=0; i<4; i++ )
    {
        pd->adcX[i] = static_cast<int>( buffer[5*i+1] ) + ( static_cast<int>( buffer[5*i+2] ) << 8);
        pd->adcY[i] = static_cast<int>( buffer[5*i+3] ) + ( static_cast<int>( buffer[5*i+4] ) << 8);
        pd->nullX[i] = ( (buffer[5*i] & 1) == 0 );
        pd->nullY[i] = ( (buffer[5*i] & 2) == 0 );
    }
    pd->stop = ( ( buffer[0] & 8 ) == 0 );
    return true;
}

int  JoyCtrlTop::adcX( int index )
{
    if ( index < 0 )
        return 0;
    if ( index >= JOY_CNT )
        return 0;
    return pd->adcX[ index ];
}

int  JoyCtrlTop::adcY( int index )
{
    if ( index < 0 )
        return 0;
    if ( index >= JOY_CNT )
        return 0;
    return pd->adcX[ index ];
}

bool JoyCtrlTop::nullX( int index )
{
    if ( index < 0 )
        return 0;
    if ( index >= JOY_CNT )
        return 0;
    return pd->nullX[ index ];
}

bool JoyCtrlTop::nullY( int index )
{
    if ( index < 0 )
        return 0;
    if ( index >= JOY_CNT )
        return 0;
    return pd->nullY[ index ];
}

bool JoyCtrlTop::stopBtn()
{
    return pd->stop;
}



