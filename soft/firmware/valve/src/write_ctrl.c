
#include "write_ctrl.h"
#include "hal.h"
#include "hdw_config.h"

static Mutex    mutex;
static uint32_t curValue  = 0;
static uint32_t pendValue = 0;

static void writeInternal( void )
{
	static uint32_t val;
    chMtxLock( &mutex );
    val = pendValue;
    chMtxUnlock();
    if ( pendValue == curValue )
    	return;

    static int16_t i;
    static uint32_t bitVal = (1 << 31);
    for ( i=31; i>=0; i-- )
    {
    	palClearPad( OUT_PORT, OUT_CP_PIN );
        if ( curValue & bitVal )
        	palSetPad( OUT_PORT, OUT_DSA_PIN );
        else
        	palClearPad( OUT_PORT, OUT_DSA_PIN );
        palSetPad( OUT_PORT, OUT_CP_PIN );
    	bitVal >>= 1;
    }
}

static WORKING_AREA( waWrite, 256 );
static msg_t writeThread( void *arg )
{
    (void)arg;
    chRegSetThreadName( "wr" );
    while ( 1 )
    {
    	chThdSleepSeconds( 1 );
    	writeInternal();
    }

    return 0;
}

void initWrite( void )
{
	palSetPad( OUT_PORT,     OUT_EN_PIN );
	palSetPad( OUT_PORT,     OUT_MR_PIN );
	palSetPad( OUT_PORT,     OUT_CP_PIN );
	palSetPad( OUT_PORT,     OUT_DSA_PIN );
	palSetPadMode( IN_PORT, OUT_EN_PIN, PAL_MODE_OUTPUT_PUSHPULL );
	palSetPadMode( IN_PORT, OUT_MR_PIN, PAL_MODE_OUTPUT_PUSHPULL );
	palSetPadMode( IN_PORT, OUT_CP_PIN, PAL_MODE_OUTPUT_PUSHPULL );
	palSetPadMode( IN_PORT, OUT_DSA_PIN, PAL_MODE_OUTPUT_PUSHPULL );

	// Initializing mutex.
	chMtxInit( &mutex );
	// Creating thread.
	chThdCreateStatic( waWrite, sizeof(waWrite), NORMALPRIO, writeThread, NULL );
}

void write( uint32_t val )
{
    chMtxLock( &mutex );
    pendValue = val;
    chMtxUnlock();
}








