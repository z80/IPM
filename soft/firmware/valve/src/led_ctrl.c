
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
    	/*chMtxLock( &mutex );
            arg = value;
            if ( arg & 1 )
                palTogglePad( LED_PORT, LED_0_PIN );
            if ( arg & 2 )
                palTogglePad( LED_PORT, LED_1_PIN );
            if ( arg & 4 )
                palTogglePad( LED_PORT, LED_2_PIN );
        chMtxUnlock();*/
        chThdSleepMilliseconds( 250 );
    }

    return 0;
}

void initLed( void )
{
	palClearPad( LED_PORT,     LED_0_PIN );
	palClearPad( LED_PORT,     LED_1_PIN );
	palClearPad( LED_PORT,     LED_2_PIN );
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
        /*if ( value & 1 )
            palSetPad( LED_PORT, LED_0_PIN );
        else
            palClearPad( LED_PORT, LED_0_PIN );
        if ( value & 2 )
            palSetPad( LED_PORT, LED_1_PIN );
        else
            palClearPad( LED_PORT, LED_1_PIN );
        if ( value & 4 )
            palSetPad( LED_PORT, LED_2_PIN );
        else
            palClearPad( LED_PORT, LED_2_PIN );*/
    chMtxUnlock();
}

void toggleLeds( uint32_t arg )
{
    chMtxLock( &mutex );
        value ^= (arg & 0x07);
        /*if ( arg & 1 )
            palTogglePad( LED_PORT, LED_0_PIN );
        if ( arg & 2 )
            palTogglePad( LED_PORT, LED_1_PIN );
        if ( arg & 4 )
            palTogglePad( LED_PORT, LED_2_PIN );*/
    chMtxUnlock();
}

void toggleLedsI( uint32_t arg )
{
    value ^= (arg & 0x07);
    /*if ( arg & 1 )
        palTogglePad( LED_PORT, LED_0_PIN );
    if ( arg & 2 )
        palTogglePad( LED_PORT, LED_1_PIN );
    if ( arg & 4 )
        palTogglePad( LED_PORT, LED_2_PIN );*/
}









