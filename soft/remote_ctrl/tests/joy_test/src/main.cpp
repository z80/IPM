
#include "joy_ctrl.h"

#include <iostream>
#include <sstream>

#ifndef WIN32
    #include <unistd.h>
    
#else
    #include <windows.h>
#endif


int main( int argc, char * argv[] )
{
    JoyCtrl c;
    bool res = c.open();
    if ( !res )
    {
        std::cout << "Failed to open device :(\r\n";
        return 1;
    }
    std::cout << "Managed to open device!!!\r\n";
    unsigned char buffer[512];
    int sz;
    c.query( buffer, sz );
    return 0;
}

