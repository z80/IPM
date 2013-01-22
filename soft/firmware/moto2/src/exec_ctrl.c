
#include "exec_ctrl.h"
#include "ch.h"
#include "hal.h"
#include "hdw_config.h"
#include "encrel_ctrl.h"
#include "encabs_ctrl.h"
#include "bmsd_ctrl.h"
#include "dac_ctrl.h"
#include "led_ctrl.h"

static InputQueue inputQueue;
#define QUEUE_SZ (I2C_IN_BUFFER_SZ * EXEC_QUEUE_SIZE)
static uint8_t queue[ I2C_IN_BUFFER_SZ * EXEC_QUEUE_SIZE ];

static WORKING_AREA( waExec, 1024 );
static msg_t execThread( void *arg )
{
    (void)arg;
    chRegSetThreadName( "e" );
    while ( 1 )
    {

        static size_t sz;
        static uint8_t buffer[ I2C_IN_BUFFER_SZ ];
        sz = chIQReadTimeout( &inputQueue, buffer, I2C_IN_BUFFER_SZ, TIME_INFINITE );

        static int32_t value32;
        // Parse inBuffer
        switch ( buffer[0] )
        {
        case I2C_CMD_DAC1:
            dacSet( 0, buffer[1] );
            break;
        case I2C_CMD_DAC2:
            dacSet( 1, buffer[1] );
            break;
        case I2C_CMD_ENC1:
            value32 = *(int32_t *)(&(buffer[1]));
            encrelSet( 0, value32 );
            break;
        case I2C_CMD_ENC2:
            value32 = *(int32_t *)(&(buffer[1]));
            encrelSet( 1, value32 );
            break;
        case I2C_CMD_BMSD:
            bmsdRawCmd( &buffer[1] );
            break;
        case I2C_CMD_LEDS:
            setLeds( (uint32_t)buffer[1] );
            break;
        }
    }
    return 0;
}

void execInit( void )
{
    // Initialize mailbox.
    chIQInit( &inputQueue, queue, I2C_IN_BUFFER_SZ * EXEC_QUEUE_SIZE, NULL );
    // Creating thread.
    chThdCreateStatic( waExec, sizeof(waExec), NORMALPRIO, execThread, NULL );
}

void execPostCmd( uint8_t * cmd )
{
    /*
    static uint8_t i = 0;
    static msg_t res;
    for ( ; i<I2C_IN_BUFFER_SZ; i++ )
    {
        res = chIQPutI( &inputQueue, cmd[i] );
        if ( res != Q_OK )
            return;
    }
    // Reset byte counter.
    i = 0;
    */
    chSysLockFromIsr();
    static uint32_t i;
    static msg_t res;
    for ( i=0; i<I2C_IN_BUFFER_SZ; i++ )
    {
        res = chIQPutI( &inputQueue, cmd[i] );
        if ( res != Q_OK )
            return;
    }
    chSysUnlockFromIsr();
}






