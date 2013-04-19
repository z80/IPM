
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
        return 1;
    c.query();
    return 0;
}

