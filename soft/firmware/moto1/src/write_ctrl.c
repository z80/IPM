
#include "write_ctrl.h"
#include "hal.h"
#include "hdw_config.h"
#include "led_ctrl.h"

static Mutex    mutex;
static uint32_t curValue  = 0;
static uint32_t pendValue = 0;

static void writeInternal( void )
{
    static uint32_t val;
    chMtxLock( &mutex );
    val = pendValue;
    chMtxUnlock();
    if ( val == curValue )
        return;

    curValue = val;

    if ( curValue & 0x0001 )
        palSetPad( MOTO_PORT, MOTO_INPUT_1 );
    else
        palClearPad( MOTO_PORT, MOTO_INPUT_1 );
    if ( curValue & 0x0002 )
        palSetPad( MOTO_PORT, MOTO_INPUT_2 );
    else
        palClearPad( MOTO_PORT, MOTO_INPUT_2 );
}

static WORKING_AREA( waWrite, 256 );
static msg_t writeThread( void *arg )
{
    (void)arg;
    chRegSetThreadName( "wr" );
    while ( 1 )
    {
        chThdSleepMilliseconds( 1 );
        writeInternal();
    }

    return 0;
}

void initWrite( void )
{
    // By default all outputs are zeros.
    palClearPad( MOTO_PORT,     MOTO_INPUT_1 );
    palClearPad( MOTO_PORT,     MOTO_INPUT_2 );
    palSetPadMode( MOTO_PORT, MOTO_INPUT_1, PAL_MODE_OUTPUT_PUSHPULL );
    palSetPadMode( MOTO_PORT, MOTO_INPUT_1, PAL_MODE_OUTPUT_PUSHPULL );

    // Initializing mutex.
    chMtxInit( &mutex );
    // Creating thread.
    chThdCreateStatic( waWrite, sizeof(waWrite), NORMALPRIO, writeThread, NULL );
}

void valueWrite( uint32_t val )
{
    chMtxLock( &mutex );
    pendValue = val;
    chMtxUnlock();
}








