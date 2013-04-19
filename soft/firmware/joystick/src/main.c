
#include "ch.h"

#include "ftdi_ctrl.h"

#include "lpc2148.h"
#include "uart1.h"
#include "joystick_ctrl.h"
static void initTest( void );
static void processTest( void );

int main( void )
{
    //halInit();
    //chSysInit();

    initTest();
    //initFtdi( );
    while ( TRUE )
    {
        processTest();
        //processFtdi();
    }
    return 0;
}

static void initTest( void )
{
    initUart1( 20000000, 38400 );
    initJoy();

    // Direction output.
    IODIR0 |= (1<<7);

    #define P0_7     (0<<14)
    #define P0_7_MSK (3<<14)

    // Set P0_7 as GPIO.
    PINSEL0 &= (~P0_7_MSK);
    PINSEL0 |= P0_7;
}

static void delay( void )
{
    volatile int i;
    for ( i=0; i<10240; i++ )
        ;
}

static void processTest( void )
{

    IOSET0 = (1<<7);
    delay();
    IOCLR0 = (1<<7);
    delay();

    char stri[] = "Hello, Putty!\r\n";

    //stri[0] = 0;
    sendUart1( (uint8_t *)stri, 15 );
    delay();

    TJoy joys[4];
    joystick( joys );
    delay();
}




