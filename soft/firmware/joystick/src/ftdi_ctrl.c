
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
        unsigned char buffer[20];
        int i;
        joystick( joys );
        for ( i=0; i<JOY_CNT; i++ )
        {
            buffer[ i*5 ]   = joys[i].flags;
            buffer[ i*5+1 ] = (unsigned char)( joys[i].value[0] & 0x00FF );
            buffer[ i*5+2 ] = (unsigned char)( ( joys[i].value[0] >> 8 ) & 0x00FF );
            buffer[ i*5+3 ] = (unsigned char)( joys[i].value[1] & 0x00FF );
            buffer[ i*5+4 ] = (unsigned char)( ( joys[i].value[1] >> 8 ) & 0x00FF );
        }
        sz = sendUart1( (uint8_t *)buffer, sizeof( buffer ) );
    }
}








