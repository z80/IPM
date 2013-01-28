
#include "led_ctrl.h"
#include "hal.h"

#include "hdw_config.h"

static Mutex    mutex;
static uint32_t value = 0;


static WORKING_AREA( waLeds, 256 );
static msg_t ledsThread( void *arg )
{
    (void)arg;
    chRegSetThreadName( "ld" );
    while ( 1 )
    {
        palClearPad( LED_PORT, LED_0 );
    	palClearPad( LED_PORT, LED_1 );
        chThdSleepMilliseconds( 250 );

        static uint32_t arg;
    	chMtxLock( &mutex );
    	arg = value;
    	chMtxUnlock();

    	if ( arg & 1 )
    		palSetPad( LED_PORT, LED_0 );
    	else
    		palClearPad( LED_PORT, LED_0 );
    	if ( arg & 2 )
    		palSetPad( LED_PORT, LED_1 );
    	else
    		palClearPad( LED_PORT, LED_1 );
        chThdSleepMilliseconds( 250 );
    }

    return 0;
}

void initLed( void )
{
	palSetPad( LED_PORT,     LED_0 );
	palSetPad( LED_PORT,     LED_1 );
	palSetPadMode( LED_PORT, LED_0, PAL_MODE_OUTPUT_PUSHPULL );
	palSetPadMode( LED_PORT, LED_1, PAL_MODE_OUTPUT_PUSHPULL );

	// Initializing mutex.
	chMtxInit( &mutex );
	// Creating thread.
	chThdCreateStatic( waLeds, sizeof(waLeds), NORMALPRIO, ledsThread, NULL );
}

void setLeds( uint32_t val )
{
    chMtxLock( &mutex );
    value = val;
    chMtxUnlock();
}









