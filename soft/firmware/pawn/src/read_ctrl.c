
#include "read_ctrl.h"
#include "hal.h"
#include "hdw_config.h"
#include "led_ctrl.h"

static Mutex    mutex;
static uint32_t value = 0;

static void delay( void )
{
    static volatile uint16_t i;
    for ( i=0; i<32; i++ )
        asm volatile ( "nop;" );
}

static void read( uint32_t * val )
{
    // Enable parallel load.
    palClearPad( IN_PORT, IN_PL_PIN );
    delay();

    // Disable parallel load.
    palSetPad( IN_PORT, IN_PL_PIN );
    delay();

    // Clock enable.
    palClearPad( IN_PORT, IN_CE_PIN );
    delay();

    static uint32_t result;
    result = 0;
    static uint32_t bitVal;
    bitVal = 1;
    static int16_t i;

    for ( i=0; i<16; i++ )
    {
        // Set clock.
        palSetPad( IN_PORT, IN_CP_PIN );
        delay();

        // Check for value;
        static uint16_t b;
        b = palReadPad( IN_PORT, IN_Q7_PIN );
        result += (b != 0) ? bitVal : 0;
        bitVal <<= 1;
        delay();

        // Clear clock.
        palClearPad( IN_PORT, IN_CP_PIN );
        delay();
    }
    // Set clock.
    palSetPad( IN_PORT, IN_CP_PIN );
    delay();

    // Clock disable.
    palSetPad( IN_PORT, IN_CE_PIN );
    delay();

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
        chThdSleepMilliseconds( 10 );
        read( &value );

        //uint8_t v = 0;
        //uint8_t i;
        //for ( i=0; i<16; i++ )
        //    v += ( value & (1<<i) ) ? 1 : 0;
        //setLeds( v | 4 );
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
    return result;
}






