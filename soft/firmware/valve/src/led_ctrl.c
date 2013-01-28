
#include "led_ctrl.h"
#include "hal.h"

#include "iwdg.h"
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
        static uint32_t arg;
    	chMtxLock( &mutex );
            arg = value;
            if ( arg & 1 )
                palTogglePad( LED_PORT, LED_0_PIN );
            if ( arg & 2 )
                palTogglePad( LED_PORT, LED_1_PIN );
            if ( arg & 4 )
                palTogglePad( LED_PORT, LED_2_PIN );
        chMtxUnlock();
        chThdSleepMilliseconds( 250 );
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

void setLeds( uint32_t arg )
{
    chMtxLock( &mutex );
        value = arg;
    chMtxUnlock();
}

void toggleLeds( uint32_t arg )
{
    chMtxLock( &mutex );
        value = ( value & ( ~arg ) ) |
                ( (value ^ arg ) & (arg & 0x07) );
    chMtxUnlock();
}

void toggleLedsImmediate( uint32_t val )
{
    if ( val & 1 )
        palTogglePad( LED_PORT, LED_0_PIN );
    if ( val & 2 )
        palTogglePad( LED_PORT, LED_1_PIN );
    if ( val & 4 )
        palTogglePad( LED_PORT, LED_2_PIN );
}

void toggleLedsI( uint32_t arg )
{
    if ( arg & 1 )
        palTogglePad( LED_PORT, LED_0_PIN );
    if ( arg & 2 )
        palTogglePad( LED_PORT, LED_1_PIN );
    if ( arg & 4 )
        palTogglePad( LED_PORT, LED_2_PIN );
}









