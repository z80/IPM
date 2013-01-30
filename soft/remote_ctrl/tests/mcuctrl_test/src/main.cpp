
#include "mcu_ctrl.h"

#include <iostream>
#include <sstream>
#include <boost/regex.hpp>

int main( int argc, char * argv[] )
{
    std::string stri = "ok:{0 34 54}<\r\n";
    std::string::const_iterator start = stri.begin();
    std::string::const_iterator end   = stri.end();
    boost::regex patt( "\\{([\\d\\s]{1,})\\}" );
    boost::smatch match;
    while ( boost::regex_search( start, end, match, patt ) )
    {
        // Entire match.
        std::string all = match[0];
        std::cout << match[0] << "\n";
        // First result.
        std::string first = match[1];
        std::cout << match[1] << "\n";
        // Second result ...
        // Third  result ...
    }


    /*
    McuCtrl c;
    bool res = c.open();
    if ( !res )
        return 1;

    unsigned char addr = 10;

    res = c.i2cSetAddr( addr );
    res = c.i2cSetAddr( addr );
    unsigned char data[6];
    data[0] = 6;
    data[1] = 1;
    data[2] = 0;
    data[3] = 0;
    res = c.i2cSetBuf( 0, data, 2 );
    int status = -1;
    res = c.i2cStatus( status );
    //res = c.i2cStatus( status );
    //res = c.i2cStatus( status );

    //for ( int i=0; i<32; i++ )
    //{
        status = -1;
        res = c.i2cIo( 4, 0 );
        res = c.i2cStatus( status );

        res = c.i2cIo( 0, 4 );
        res = c.i2cStatus( status );
        res = c.i2cBuffer( 4, data );

        res = c.i2cIo( 4, 4 );
        res = c.i2cStatus( status );
        res = c.i2cBuffer( 4, data );


        res = c.i2cBuffer( 4, data );
        std::cout << data[0] << " " << data[1] << " " << data[2] << " " << data [3] << "\n";
    //}
    */

    return 0;
}

