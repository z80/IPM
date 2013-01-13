
#include "read_ctrl.h"
#include "hal.h"
#include "hdw_config.h"
#include "led_ctrl.h"

static Mutex    mutex;
static uint16_t value = 0;

static void read( uint16_t * val )
{
    // Check for value;
    static uint16_t b;
    b = palReadPad( SEN_PORT, SEN_1 ) | ( palReadPad( SEN_PORT, SEN_2 ) << 1 );
    chMtxLock( &mutex );
    *val = b;
    chMtxUnlock();
}

static WORKING_AREA( waRead, 256 );
static msg_t readThread( void *arg )
{
    (void)arg;
    chRegSetThreadName( "read" );
    while ( 1 )
    {
        chThdSleepMilliseconds( 10 );
        read( &value );
    }

    return 0;
}

void initRead( void )
{
    palSetPadMode( SEN_PORT, SEN_1, PAL_MODE_INPUT );
    palSetPadMode( SEN_PORT, SEN_2, PAL_MODE_INPUT );
    // Initializing mutex.
    chMtxInit( &mutex );
    // Creating thread.
    chThdCreateStatic( waRead, sizeof(waRead), NORMALPRIO, readThread, NULL );
}

uint16_t valueRead( void )
{
    static uint32_t result;
    chMtxLock( &mutex );
    result = value;
    chMtxUnlock();
    return result;
}






