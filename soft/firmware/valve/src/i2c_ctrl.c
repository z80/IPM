
#include <stdlib.h>

#include "i2c_ctrl.h"
#include "hal.h"
#include "chprintf.h"

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
static uint32_t outs[ I2C_SLAVES_CNT+1 ]; // +1 because including master board itself.
static uint32_t pendOuts[ I2C_SLAVES_CNT+1 ];
static uint32_t ins[ I2C_SLAVES_CNT+1 ];

#define TEST_BUFFER_SIZE 16
static uint8_t testMaster = 1;
static uint8_t testAddr = 9;
static uint8_t testCnt = 0;
static uint8_t testBuffer[ TEST_BUFFER_SIZE ];

static WORKING_AREA( waI2c, 256 );
static msg_t i2cThread( void *arg )
{
    (void)arg;
    chRegSetThreadName( "i" );
    while ( 1 )
    {
        //chThdSleepMilliseconds( 1 );
        //chThdSleepMilliseconds( 100 );
        // Read ADDRESS pins.
        uint16_t ind = palReadPad( ADDR_PORT, ADDR_0_PIN ) |
                     ( palReadPad( ADDR_PORT, ADDR_1_PIN ) << 1 ) |
                     ( palReadPad( ADDR_PORT, ADDR_2_PIN ) << 2 );
        ind = (~ind) & 0x0007;
        //setLeds( a );

        static uint8_t master;
        static msg_t status;
        static systime_t tmo;
        tmo = MS2ST( 100 );
        master = ( ind == 0 ) ? 1 : 0;
        // I/O with other boards.
        static uint32_t dataOut;
        static uint32_t pendDataOut;
        static uint32_t dataIn = 0;
        static uint32_t pendDataIn = 0;
        static uint8_t  slaveFirstTime = 1;
        if ( master )
        {
            // First the board itself.
            chMtxLock( &mutex );
            ins[0] = valueRead();
            write( outs[0] );
            chMtxUnlock();
            // After all slave boards.
            static int8_t i;
            for ( i=0; i<I2C_SLAVES_CNT; i++ )
            {
                // To make IO thread safe IO itself takes place in separate variables.
                // But storage arrays are filled within locked mutex.
                // Get output.
                chMtxLock( &mutex );
                    pendDataOut = pendOuts[i+1];
                    dataOut     = outs[i+1];
                chMtxUnlock();
                if ( pendDataOut != dataOut )
                {
                    // IO itself.
                    status = RDY_OK;
                    status = i2cMasterTransmitTimeout( &I2CD1, I2C_BASE_ADDR+i,
                                                       (uint8_t *)(&pendDataOut), sizeof(pendDataOut),
                                                       0,  0,
                                                       tmo );
                    if ( status == RDY_OK )
                    {
                        chMtxLock( &mutex );
                        outs[i+1] = pendDataOut;
                        chMtxUnlock();
                    }
                    else
                    {
                        i2cStop( &I2CD1 );
                        chThdSleepMilliseconds( 100 );
                        i2cStart( &I2CD1, &i2cfg1 );
                        continue;
                    }
                }
                status = i2cMasterReceiveTimeout( &I2CD1, I2C_BASE_ADDR+i,
                                                  (uint8_t *)(&dataIn),  sizeof(dataIn),
                                                  tmo );
                if ( status == RDY_OK )
                {
                    // Get back input.
                    chMtxLock( &mutex );
                        //ins[i+1] = (dataIn & 0x0000FFFF);
                        ins[i+1] = dataIn;
                    chMtxUnlock();
                }
                else
                {
                    i2cStop( &I2CD1 );
                    chThdSleepMilliseconds( 100 );
                    i2cStart( &I2CD1, &i2cfg1 );
                    continue;
                }
            }
            // Here should be IO with moto controller boards and accelerometer.
            // .....
            chThdSleepMilliseconds( 50 );
        }
        else
        {
            static uint8_t addr;
            addr = I2C_BASE_ADDR + ind - 1;
            pendDataIn = valueRead();
            if ( slaveFirstTime )
            {
                status = i2cSlaveIoTimeout( &I2CD1, addr,
                                            (uint8_t *)&dataOut,  sizeof( dataOut ),
                                            (uint8_t *)&dataIn, sizeof( dataIn ),
                                            tmo );
                if ( status == RDY_OK )
                {
                    dataIn = pendDataIn;
                    slaveFirstTime = 0;
                }
                else
                {
                    i2cStart( &I2CD1, &i2cfg1 );
                    continue;
                }
            }
            else if ( pendDataIn != dataIn )
            {
                // Just refresh data without
                // bus interruption.
                status = i2cSlaveDataTimeout( &I2CD1,
                                       (uint8_t *)&dataOut,  sizeof( dataOut ),
                                       (uint8_t *)&dataIn, sizeof( dataIn ),
                                       tmo );
                if ( status == RDY_OK )
                    dataIn = pendDataIn;
                else
                    i2cStart( &I2CD1, &i2cfg1 );
            }
            // Here it should be some type of delay
            // because i2cSlaveIo returns immediately.
            chThdSleepMilliseconds( 50 );
            write( dataOut );
        }
        /*if ( a == 0b00000111 )
        {
            setLeds( 1 );
            static uint32_t out = 0x12345678;
            status = RDY_OK;
            status = i2cMasterTransmitTimeout( &I2CD1, testAddr,
                                               (uint8_t *)(&out), sizeof(out),
                                               0,  0,
                                               tmo );
        }
        else
            setLeds( 2 );
        */
    }

    return 0;
}

void initI2c( void )
{
    // Address pins
    palSetPadMode( ADDR_PORT, ADDR_0_PIN, PAL_MODE_INPUT );
    palSetPadMode( ADDR_PORT, ADDR_1_PIN, PAL_MODE_INPUT );
    palSetPadMode( ADDR_PORT, ADDR_2_PIN, PAL_MODE_INPUT );
    palSetPadMode( GPIOB, 6, PAL_MODE_STM32_ALTERNATE_OPENDRAIN );
    palSetPadMode( GPIOB, 7, PAL_MODE_STM32_ALTERNATE_OPENDRAIN );
    chThdSleepMilliseconds( 100 );

    i2cInit();
    //chThdSleepMilliseconds( 100 );
    i2cStart( &I2CD1, &i2cfg1 );
    //chThdSleepMilliseconds( 200 );

    // Initial values for IOs.
    int16_t i;
    for ( i=0; i<(I2C_SLAVES_CNT+1); i++ )
    {
        outs[i]     = 0;
        pendOuts[i] = 0;
        ins[i]      = 0;
    }

    // Initializing mutex.
    chMtxInit( &mutex );
    // Creating thread.
    chThdCreateStatic( waI2c, sizeof(waI2c), NORMALPRIO, i2cThread, NULL );
}

void state( uint8_t index, uint32_t * val )
{
    // Mutex protected.
    chMtxLock( &mutex );
    *val = ins[index];
    chMtxUnlock();
}

void setOutput( uint8_t index, uint32_t * val )
{
    // Mutex protected.
    chMtxLock( &mutex );
    outs[index] = *val;
    chMtxUnlock();
}

void cmd_state( BaseChannel *chp, int argc, char * argv [] )
{
    (void)chp;
    (void)argc;
    (void)argv;
    uint32_t v;
    int8_t i;
    for ( i=0; i<(I2C_SLAVES_CNT+1); i++ )
    {
        state( i, &v );
        if ( i == 0 )
            chprintf( chp, "{%d ", v );
        else if ( i == I2C_SLAVES_CNT )
            chprintf( chp, "%d}", v );
        else
            chprintf( chp, "%d ", v );
    }
    chprintf( chp, "ok:st\r\n" );
}

void cmd_set_output( BaseChannel *chp, int argc, char * argv [] )
{
    if ( argc < (I2C_SLAVES_CNT+1) )
    {
        chprintf( chp, "er:n args expected\r\n" );
    }
    else
    {
        uint32_t v;
        int8_t i;
        for ( i=0; i<(I2C_SLAVES_CNT+1); i++ )
        {
            v = atoi( argv[i] );
            setOutput( i, &v );
        }
    }
}

void testSetAddr( uint8_t val )
{
    testAddr = val;
}

void testSetMaster( uint8_t set )
{
    testMaster = set;
}

uint8_t testSend( uint8_t addr, uint32_t * val )
{
    static msg_t status;
    static systime_t tmo;
    tmo = MS2ST( 1000 );
    status = RDY_OK;
    status = i2cMasterTransmitTimeout( &I2CD1, addr,
                                       (uint8_t *)&(val), sizeof(uint32_t),
                                       0,  0,
                                       tmo );
    return ( status = RDY_OK ) ? 0 : 1;
}

uint8_t testReceive( uint8_t addr, uint32_t * val )
{
    static msg_t status;
    static systime_t tmo;
    tmo = MS2ST( 1000 );
    status = i2cSlaveIoTimeout( &I2CD1, addr,
                         (uint8_t *)val,  sizeof( uint32_t ),
                         0, 0, tmo );
    return status;
}





void tst_i2c_set_addr( BaseChannel *chp, int argc, char * argv[] )
{
    if ( argc > 0 )
    {
        int32_t v = atoi( argv[0] );
        //testSetAddr( (uint8_t)v );
        testAddr = (uint8_t)v;
        chprintf( chp, "ok:addr\r\n" );
    }
    else
        chprintf( chp, "err:arg expected\r\n" );
}

void tst_i2c_set_master( BaseChannel *chp, int argc, char * argv[] )
{
    if ( argc > 0 )
    {
        uint8_t v = ( argv[0][0] != '0' ) ? 1 : 0;
        testSetMaster( v );
    }
    else
        testSetMaster( 0 );
    chprintf( chp, "ok:mr\r\n" );
}

void tst_i2c_set_buffer( BaseChannel *chp, int argc, char * argv[] )
{
    testCnt = argc;
    uint8_t i;
    for ( i=0; i<argc; i++ )
    {
        testBuffer[i] = (uint8_t)atoi( argv[i] );
    }
    chprintf( chp, "ok:buf\r\n" );
}

void tst_i2c_io( BaseChannel *chp, int argc, char * argv[] )
{
    (void)argc;
    (void)argv;
    static msg_t status;
    static systime_t tmo;
    tmo = MS2ST( 1000 );
    if ( testMaster )
    {
        status = RDY_OK;
        status = i2cMasterTransmitTimeout( &I2CD1, testAddr,
                                           testBuffer, /*testCnt*/ 4,
                                           0,  0,
                                           tmo );
        chprintf( chp, "master ok:%d", status );

    }
    else
    {
        status = RDY_OK;
        status = i2cSlaveIoTimeout( &I2CD1, testAddr,
                                    testBuffer, /*testCnt*/ 4,
                                    0,  0, tmo );
        chThdSleepSeconds( 2 );
        chprintf( chp, "slave ok:%d", I2CD1.state );
    }
}

void tst_i2c_buffer( BaseChannel *chp, int argc, char * argv[] )
{
    if ( argc > 0 )
    {
        uint8_t cnt = atoi( argv[0] );
        uint8_t i;
        for ( i=0; i<cnt; i++ )
        {
            chprintf( chp, "%d ", testBuffer[i] );
        }
        chprintf( chp, "ok\r\n" );
    }
}










