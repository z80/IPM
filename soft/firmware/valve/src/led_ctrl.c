
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
    	palClearPad( LED_PORT, LED_0_PIN );
    	palClearPad( LED_PORT, LED_1_PIN );
    	palClearPad( LED_PORT, LED_2_PIN );
    	chThdSleepMilliseconds( 500 );

    	static uint32_t arg;
    	chMtxLock( &mutex );
    	arg = value;
    	chMtxUnlock();
    	if ( arg & 1 )
    		palSetPad( LED_PORT, LED_0_PIN );
    	else
    		palClearPad( LED_PORT, LED_0_PIN );
    	if ( arg & 2 )
    		palSetPad( LED_PORT, LED_1_PIN );
    	else
    		palClearPad( LED_PORT, LED_1_PIN );
    	if ( arg & 4 )
    		palSetPad( LED_PORT, LED_2_PIN );
    	else
    		palClearPad( LED_PORT, LED_2_PIN );
    	chThdSleepMilliseconds( 500 );
    }

    return 0;
}

void initLed( void )
{
	palSetPad( LED_PORT,     LED_0_PIN );
	palSetPad( LED_PORT,     LED_1_PIN );
	palSetPad( LED_PORT,     LED_2_PIN );
	palSetPadMode( LED_PORT, LED_0_PIN, PAL_MODE_OUTPUT_PUSHPULL );
	palSetPadMode( LED_PORT, LED_1_PIN, PAL_MODE_OUTPUT_PUSHPULL );
	palSetPadMode( LED_PORT, LED_2_PIN, PAL_MODE_OUTPUT_PUSHPULL );

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









