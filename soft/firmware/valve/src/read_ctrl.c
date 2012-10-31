
#include "read_ctrl.h"
#include "hal.h"
#include "hdw_config.h"

static Mutex    mutex;
static uint32_t value = 0;

static void read( uint32_t * val )
{
	// Enable parallel load.
    palClearPad( IN_PORT, IN_PL_PIN );
    // One clock.
    palClearPad( IN_PORT, IN_CP_PIN );
    palSetPad( IN_PORT, IN_CP_PIN );
    // Disable parallel load.
    palSetPad( IN_PORT, IN_PL_PIN );

    // Clock enable.
    palClearPad( IN_PORT, IN_CE_PIN );

    static uint32_t result;
    result = 0;
    static uint32_t bitVal;
    bitVal = (1 << 15);
    static int16_t i;
    for ( i=15; i>=0; i-- )
    {
        // One clock.
        palClearPad( IN_PORT, IN_CP_PIN );
        palSetPad( IN_PORT, IN_CP_PIN );
        // Check for value;
        static uint16_t b;
        b = 1;
        result += (b != 0) ? bitVal : 0;
        bitVal >>= 1;
    }
    // Clock disable.
    palSetPad( IN_PORT, IN_CE_PIN );

    chMtxLock( &mutex );
    *val = result;
    chMtxUnlock();
}

static WORKING_AREA( waRead, 256 );
static msg_t readThread( void *arg )
{
    (void)arg;
    chRegSetThreadName( "read" );
    while ( 1 )
    {
    	chThdSleepSeconds( 1 );
    	read( &value );
    }

    return 0;
}

void initRead( void )
{
	palSetPadMode( IN_PORT, IN_Q7_PIN, PAL_MODE_INPUT );
	palSetPad( IN_PORT,     IN_PL_PIN );
	palSetPad( IN_PORT,     IN_CE_PIN );
	palSetPad( IN_PORT,     IN_CP_PIN );
	palSetPadMode( IN_PORT, IN_PL_PIN, PAL_MODE_OUTPUT_PUSHPULL );
	palSetPadMode( IN_PORT, IN_CE_PIN, PAL_MODE_OUTPUT_PUSHPULL );
	palSetPadMode( IN_PORT, IN_CP_PIN, PAL_MODE_OUTPUT_PUSHPULL );

	// Initializing mutex.
	chMtxInit( &mutex );
	// Creating thread.
	chThdCreateStatic( waRead, sizeof(waRead), NORMALPRIO, readThread, NULL );
}

uint32_t valueRead( void )
{
    static uint32_t result;
    chMtxLock( &mutex );
    result = value;
    chMtxUnlock();
    return value;
}






