
#include "encabs_ctrl.h"
#include "ch.h"
#include "hal.h"
#include "hdw_config.h"

static int encabsBits;
static int delayTicks;
static int delayFrontTicks;
static int delayBackTicks;

static void delay( void )
{
    static volatile int32_t i;
    for ( i=0; i<delayTicks; i++ );
        //volatile asm( "nop;" );
}

static uint32_t encabsQuery( void )
{
    static uint32_t val;
    val = 0;
    static int16_t i;
    palClearPad( ENCABS_CLK_PORT, ENCABS_CLK_PIN );
    for ( i=0; i<delayFrontTicks; i++ )
        delay();
    for ( i=(encabsBits-1); i>=0; i-- )
    {
        palSetPad( ENCABS_CLK_PORT, ENCABS_CLK_PIN );
        delay();
        if ( palReadPad( ENCABS_DATA_PORT, ENCABS_DATA_PIN ) )
            val += (1<<i);
        palClearPad( ENCABS_CLK_PORT, ENCABS_CLK_PIN );
        delay();
    }
    for ( i=0; i<delayBackTicks; i++ )
        delay();
    palSetPad( ENCABS_CLK_PORT, ENCABS_CLK_PIN );
    return val;
}


static Mutex    mutex;
static uint32_t value = 0;


static WORKING_AREA( waEncabs, 512 );
static msg_t encabsThread( void *arg )
{
    (void)arg;
    chRegSetThreadName( "ea" );
    while ( 1 )
    {
        static uint32_t v;
        v = encabsQuery();
        chMtxLock( &mutex );
            value = v;
        chMtxUnlock();
        chThdSleepMilliseconds( 50 );
    }

    return 0;
}

void encabsInit( void )
{
    palSetPadMode( ENCABS_CLK_PORT,  ENCABS_CLK_PIN, PAL_MODE_OUTPUT_PUSHPULL );
    palSetPad(     ENCABS_CLK_PORT,  ENCABS_CLK_PIN );
    palSetPadMode( ENCABS_DATA_PORT, ENCABS_DATA_PIN, PAL_MODE_INPUT );

    encabsBits      = ENCABS_BITS;
    delayTicks      = 4096;
    delayFrontTicks = 1;
    delayBackTicks  = 1;

    // Initializing mutex.
    chMtxInit( &mutex );
    // Creating thread.
    chThdCreateStatic( waEncabs, sizeof(waEncabs), NORMALPRIO, encabsThread, NULL );
}

uint32_t encabs( void )
{
    uint32_t v;
    chMtxLock( &mutex );
        v = value;
    chMtxUnlock();
    return v;
}

void encabsSetBits( int bits )
{
    encabsBits = bits;
}

void encabsSetDelay( int cnt )
{
    delayTicks = cnt;
}

void encabsSetDelayFront( int cnt )
{
    delayFrontTicks = cnt;
}

void encabsSetDelayBack( int cnt )
{
    delayBackTicks = cnt;
}
