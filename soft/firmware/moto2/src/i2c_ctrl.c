
#include <stdlib.h>

#include "i2c_ctrl.h"
#include "hal.h"
#include "chprintf.h"
#include "iwdg.h"

#include "led_ctrl.h"
#include "exec_ctrl.h"
#include "encrel_ctrl.h"
#include "encabs_ctrl.h"
#include "bmsd_ctrl.h"
#include "hdw_config.h"

static uint8_t outBuffer[ I2C_OUT_BUFFER_SZ ];
static uint8_t inBuffer[ I2C_IN_BUFFER_SZ ];

static const I2CConfig i2cfg1 =
{
    OPMODE_I2C,
    100000,
    STD_DUTY_CYCLE,
};

static Mutex    mutex;

static WORKING_AREA( waI2c, 256 );
static msg_t i2cThread( void *arg )
{
    (void)arg;
    chRegSetThreadName( "i" );
    while ( 1 )
    {
        // Read ADDRESS pins.
        uint16_t ind = palReadPad( ADDR_PORT, ADDR_0 ) |
                     ( palReadPad( ADDR_PORT, ADDR_1 ) << 1 ) |
                     ( palReadPad( ADDR_PORT, ADDR_2 ) << 2 );
        ind = (~ind) & 0x0007;

        iwdgReset( &IWDGD );

        static msg_t status;
        static systime_t tmo;
        tmo = MS2ST( I2C_TIMEOUT );
        // I/O with other boards.
        int32_t * pienc = (int32_t *)outBuffer;
        pienc[0] = encrel( 0 );
        pienc[1] = encrel( 1 );
        uint32_t * paenc = ( uint32_t * )outBuffer;
        paenc[2] = encabs();
        outBuffer[8] = bmsdReady();

        // Watchdog reset.
        iwdgReset( &IWDGD );

        // To make sure we've got something.
        inBuffer[0] = I2C_CMD_IDLE;
        static uint8_t addr;
        addr = I2C_BASE_ADDR + ind;
        // IO routine itself.
        status = i2cSlaveIoTimeout( &I2CD1, addr,
                                    (uint8_t *)&outBuffer,  sizeof( outBuffer ),
                                    (uint8_t *)&inBuffer,   sizeof( inBuffer ), tmo );
        if ( status != RDY_OK )
        {
            // Watchdog reset.
            iwdgReset( &IWDGD );
            // Restart I2c bus.
            i2cStop( &I2CD1 );
            //chThdSleepMilliseconds( 100 );
            i2cStart( &I2CD1, &i2cfg1 );
            continue;
        }
        // Watchdog reset.
        iwdgReset( &IWDGD );
        // If we are here IO routine succeeded.
        execPostCmd( inBuffer );
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
    chThdSleepMilliseconds( 100 );

    i2cInit();
    //chThdSleepMilliseconds( 100 );
    i2cStart( &I2CD1, &i2cfg1 );
    //chThdSleepMilliseconds( 200 );

    // Initializing mutex.
    chMtxInit( &mutex );
    // Creating thread.
    chThdCreateStatic( waI2c, sizeof(waI2c), NORMALPRIO, i2cThread, NULL );
}












