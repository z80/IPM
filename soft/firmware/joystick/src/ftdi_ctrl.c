
#include "ftdi_ctrl.h"
#include "uart1.h"
#include "joystick_ctrl.h"

void initFtdi( void )
{
    initUart1( 20000000, 38400 );
    initJoy();
}

void processFtdi( void )
{
    uint8_t chr;
    uint32_t sz;
    sz = receiveUart1( &chr, 1 );
    if ( sz )
    {
        TJoy joys[4];
        joystick( joys );
        sz = sendUart1( (uint8_t *)joys, sizeof( joys ) );
    }
}








