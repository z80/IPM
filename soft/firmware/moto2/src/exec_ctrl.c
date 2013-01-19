
#include "exec_ctrl.h"
#include "ch.h"
#include "hal.h"
#include "hdw_config.h"
#include "encrel_ctrl.h"
#include "encabs_ctrl.h"
#include "bmsd_ctrl.h"
#include "dac_ctrl.h"

static Mutex   mutex;
static Mailbox mailbox;
static uint8_t pendingIndex = 0;
static msg_t   msgs[ EXEC_QUEUE_SIZE ];
static uint8_t queue[ I2C_IN_BUFFER_SZ * EXEC_QUEUE_SIZE ];

static WORKING_AREA( waExec, 256 );
static msg_t execThread( void *arg )
{
    (void)arg;
    chRegSetThreadName( "e" );
    while ( 1 )
    {

        static msg_t res, msg;
        static uint8_t buffer[ I2C_IN_BUFFER_SZ ];
        chMtxLock( &mutex );
            res = chMBFetch( &mailbox, &msg, TIME_IMMEDIATE );
        chMtxUnlock();
        if ( res == RDY_OK )
        {
            static uint8_t i;
            for ( i=0; i<I2C_IN_BUFFER_SZ; i++ )
                buffer[i] = queue[ msg * I2C_IN_BUFFER_SZ + i ];
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
            }
        }
        else
            chThdSleepMilliseconds( 1 );
    }
    return 0;
}

void execInit( void )
{
    // Initialize mutex.
    chMtxInit( &mutex );
    // Initialize mailbox.
    chMBInit( &mailbox, msgs, EXEC_QUEUE_SIZE );
    // Creating thread.
    chThdCreateStatic( waExec, sizeof(waExec), NORMALPRIO, execThread, NULL );
}

void execPostCmd( uint8_t * cmd )
{
    chMtxLock( &mutex );
        static uint8_t i;
        for ( i=0; i<I2C_IN_BUFFER_SZ; i++ )
            queue[ pendingIndex * I2C_IN_BUFFER_SZ + i ] = cmd[i];
        chMBPost( &mailbox, (msg_t)pendingIndex, TIME_IMMEDIATE );
        pendingIndex = (pendingIndex + 1) % EXEC_QUEUE_SIZE;
    chMtxUnlock();
}






