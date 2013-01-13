
#include <stdlib.h>

#include "i2c_ctrl.h"
#include "hal.h"
#include "chprintf.h"
#include "iwdg.h"

#include "read_ctrl.h"
#include "write_ctrl.h"
#include "led_ctrl.h"
#include "hdw_config.h"

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
        //setLeds( a );

        static uint8_t master;
        static msg_t status;
        static systime_t tmo;
        tmo = MS2ST( 100 );
        master = ( ind == 0 ) ? 1 : 0;
        // I/O with other boards.
        static uint16_t dataOut;
        static uint16_t dataIn;

        iwdgReset( &IWDGD );

        static uint8_t addr;
        addr = I2C_BASE_ADDR + ind;
        dataIn = valueRead();
            //dataIn = 0x12345678;
        status = i2cSlaveIoTimeout( &I2CD1, addr,
                                    (uint8_t *)&dataOut,  sizeof( dataOut ),
                                    (uint8_t *)&dataIn,   sizeof( dataIn ), tmo );
        if ( status != RDY_OK )
        {
            i2cStop( &I2CD1 );
            chThdSleepMilliseconds( 100 );
            i2cStart( &I2CD1, &i2cfg1 );
            continue;
        }
        // Here it should be some type of delay
        // because i2cSlaveIo returns immediately.
        chThdSleepMilliseconds( 20 );
        valueWrite( dataOut );
    }

    return 0;
}

void initI2c( void )
{
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












