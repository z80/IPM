
#include "mcu_ctrl.h"

#include <iostream>
#include <sstream>
#include <boost/regex.hpp>

int main( int argc, char * argv[] )
{
    McuCtrl c;
    bool res = c.open();
    if ( !res )
        return 1;

    res = c.i2cSetAddr( 64 );
    res = c.i2cSetAddr( 64 );
    unsigned char data[6];
    data[0] = 6;
    data[1] = 1;
    res = c.i2cSetBuf( 0, data, 2 );
    int status = -1;
    res = c.i2cStatus( status );
    res = c.i2cStatus( status );
    res = c.i2cStatus( status );

    status = -1;
    res = c.i2cIo( 2, 0 );
    res = c.i2cStatus( status );
    res = c.i2cIo( 2, 0 );
    res = c.i2cStatus( status );
    res = c.i2cIo( 2, 0 );
    res = c.i2cStatus( status );

    return 0;
}

