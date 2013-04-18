
#include "ch.h"

#include "ftdi_ctrl.h"

#include "lpc2148.h"
static void initTest( void );
static void processTest( void );

int main( void )
{
    //halInit();
    //chSysInit();

    initTest();
    //initFtdi();
    while ( TRUE )
    {
        processTest();
        //processFtdi();
    }
    return 0;
}

static void initTest( void )
{
    //IODIR0 = 0;
    // Only one output.
    IODIR0 = (1<<7);

    #define P0_7     (0<<14)
    #define P0_7_MSK (3<<14)

    // Set P0_7 as GPIO.
    PINSEL0 &= (~P0_7_MSK);
    PINSEL0 |= P0_7;
    //palSetPadMode( IOPORT1, PAL_PORT_BIT(7), PAL_MODE_OUTPUT_PUSHPULL );
    //palClearPad( IOPORT1, PAL_PORT_BIT(7) );
}

static void delay( void )
{
    volatile int i;
    for ( i=0; i<1024; i++ )
        ;
}

static void processTest( void )
{
    IOSET0 = (1<<7);
    delay();
    IOCLR0 = (1<<7);
    delay();
    //palClearPad( IOPORT1, PAL_PORT_BIT(7) );
    //chThdSleepMilliseconds( 500 );
    //palSetPad( IOPORT1, PAL_PORT_BIT(7) );
    //chThdSleepMilliseconds( 500 );

}




