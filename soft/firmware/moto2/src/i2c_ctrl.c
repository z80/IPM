
#include <stdlib.h>

#include "i2c_ctrl.h"
#include "hal.h"
#include "chprintf.h"

#include "led_ctrl.h"
#include "exec_ctrl.h"
#include "encrel_ctrl.h"
#include "encabs_ctrl.h"
#include "bmsd_ctrl.h"
#include "hdw_config.h"

static uint8_t outBuffer[ I2C_OUT_BUFFER_SZ ];
static uint8_t inBuffer[ I2C_IN_BUFFER_SZ ];
static Mutex   mutex;

static const I2CConfig i2cfg1 =
{
    OPMODE_I2C,
    100000,
    STD_DUTY_CYCLE,
};

static void delay( void )
{
    volatile uint32_t i;
    for ( i=0; i<512; i++ )
        asm volatile ( "nop;" );
}

static void i2cRxCb( I2CDriver * i2cp )
{
    (void)i2cp;
    // Command processing.
    // If we are here IO routine succeeded.
    execPostCmd( inBuffer );

    //palTogglePad( GPIOB, 10 );
}

static void i2cTxCb( I2CDriver * i2cp )
{
    (void)i2cp;
    // Refresh buffer if necessary.
    //palTogglePad( GPIOB, 11 );
}


static WORKING_AREA( waI2c, 512 );
static msg_t i2cThread( void *arg )
{
    (void)arg;
    chRegSetThreadName( "i" );

    static msg_t status;
    static systime_t tmo;
    tmo = MS2ST( I2C_TIMEOUT );

    // To make sure we've got something.
    inBuffer[0] = I2C_CMD_IDLE;
    do {
        // Read ADDRESS pins.
        uint16_t ind = palReadPad( ADDR_PORT, ADDR_0 ) |
                     ( palReadPad( ADDR_PORT, ADDR_1 ) << 1 ) |
                     ( palReadPad( ADDR_PORT, ADDR_2 ) << 2 );
        ind = (~ind) & 0x0007;

        static uint8_t addr;
        addr = I2C_BASE_ADDR + 2 * ind; // For moto_1 it is (2 * ind + 1)
        // IO routine itself.
        //palClearPad( GPIOB, 11 );
        status = i2cSlaveIoTimeout( &I2CD1, addr,
                                    inBuffer,  13,
                                    outBuffer, 13,
                                    i2cRxCb,
                                    i2cTxCb,
                                    tmo );

        if ( status != RDY_OK )
            i2cStart( &I2CD1, &i2cfg1 );
    } while ( status != RDY_OK );

    while ( 1 )
    {
        // I/O with other boards.
        int32_t * pienc = (int32_t *)outBuffer;
        pienc[0] = encrel( 0 );
        pienc[1] = encrel( 1 );     
        uint32_t * paenc = ( uint32_t * )outBuffer;
        paenc[2] = encabs();      
        outBuffer[12] = bmsdReady();

        chThdSleepMilliseconds( 10 );
    }

    return 0;
}

void initI2c( void )
{
    uint8_t i;
    for ( i=0; i<I2C_OUT_BUFFER_SZ; i++ )
        outBuffer[i] = 0;
    for ( i=0; i<I2C_IN_BUFFER_SZ; i++ )
        inBuffer[i] = 0;
    // Address pins
    palSetPadMode( ADDR_PORT, ADDR_0, PAL_MODE_INPUT );
    palSetPadMode( ADDR_PORT, ADDR_1, PAL_MODE_INPUT );
    palSetPadMode( ADDR_PORT, ADDR_2, PAL_MODE_INPUT );
    palSetPadMode( GPIOB, 6, PAL_MODE_STM32_ALTERNATE_OPENDRAIN );
    palSetPadMode( GPIOB, 7, PAL_MODE_STM32_ALTERNATE_OPENDRAIN );

    i2cStart( &I2CD1, &i2cfg1 );

    // Initializing mutex.
    chMtxInit( &mutex );
    // Creating thread.
    chThdCreateStatic( waI2c, sizeof(waI2c), NORMALPRIO, i2cThread, NULL );
}












