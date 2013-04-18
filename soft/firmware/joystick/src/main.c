
#include "ch.h"
#include "hal.h"

#include "ftdi_ctrl.h"
#include "joystick_ctrl.h"

#include "lpc2148.h"
static void initTest( void );
static void processTest( void );

int main( void )
{
    halInit();
    chSysInit();

    initTest();
    //initFtdi();
    while ( TRUE )
    {
        processTest();
        //processShellFtdi();
        //chThdSleepMilliseconds( 500 );
    }
    return 0;
}

static void initTest( void )
{
    //#define P0_7     (0<<14)
    //#define P0_7_MSK (3<<14)

    // Set P0_7 as GPIO.
    //PINSEL0 &= (~P0_7_MSK);
    //PINSEL0 |= P0_7;
    palSetPadMode( IOPORT1, PAL_PORT_BIT(7), PAL_MODE_OUTPUT_PUSHPULL );
    palClearPad( IOPORT1, PAL_PORT_BIT(7) );
}

static void processTest( void )
{
    palClearPad( IOPORT1, PAL_PORT_BIT(7) );
    chThdSleepMilliseconds( 500 );
    palSetPad( IOPORT1, PAL_PORT_BIT(7) );
    chThdSleepMilliseconds( 500 );

}




