
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

// Generic I2C functions declaration.
void i2cSetAddr( uint8_t val );
void i2cSetBuf( uint8_t at, uint8_t val );
void i2cIo( void );
void i2cSetStatus( uint8_t val );
uint8_t i2cStatus( void );
uint8_t i2cBuf( uint8_t index );

static void i2cRxCb( I2CDriver * i2cp )
{
    (void)i2cp;
    toggleLedsI( 2 );
}

static void i2cTxCb( I2CDriver * i2cp )
{
    (void)i2cp;
    toggleLedsI( 4 );
}


static WORKING_AREA( waI2c, 256 );
static msg_t i2cThread( void *arg )
{
    (void)arg;
    chRegSetThreadName( "i" );
    // To all LOW/HIGH levels on address pins to reach their levels.
    chThdSleepMilliseconds( I2C_IO_TIMEOUT_MS );
    while ( 1 )
    {
        // Read ADDRESS pins.
        uint16_t ind = palReadPad( ADDR_PORT, ADDR_0_PIN ) |
                     ( palReadPad( ADDR_PORT, ADDR_1_PIN ) << 1 ) |
                     ( palReadPad( ADDR_PORT, ADDR_2_PIN ) << 2 );
        ind = (~ind) & 0x0007;

        static uint8_t master;
        static msg_t status;
        static systime_t tmo;
        tmo = MS2ST( I2C_IO_TIMEOUT_MS );
        master = ( ind == 0 ) ? 1 : 0;
        // I/O with other boards.
        static uint32_t dataOut = 0;
        static uint32_t pendDataOut = 0;
        static uint32_t dataIn = 0;
        setLeds( master ? 1 : 0 );
        if ( master )
        {
            // First the board itself.
            chMtxLock( &mutex );
                ins[0] = valueRead();
                write( pendOuts[0] );
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
                // Write only if data to write differs from already written.
                if ( pendDataOut != dataOut )
                {
                    // IO itself.
                    status = i2cMasterTransmitTimeout( &I2CD1, I2C_BASE_ADDR+i,
                                                       (uint8_t *)(&pendDataOut), sizeof(pendDataOut),
                                                       0,  0,
                                                       tmo );
                    if ( status == RDY_OK )
                    {
                        chMtxLock( &mutex );
                            outs[i+1] = pendDataOut;
                        chMtxUnlock();
                        toggleLedsImmediate( 2 );
                    }
                    else
                    {
                        setLeds( 7 );
                        i2cStop( &I2CD1 );
                        chThdSleepMilliseconds( 10 );
                        i2cStart( &I2CD1, &i2cfg1 );
                        continue;
                    }
                }
                status = i2cMasterReceiveTimeout( &I2CD1, I2C_BASE_ADDR+i,
                                                  (uint8_t *)(&dataIn),  sizeof(dataIn),
                                                  tmo );
                if ( status == RDY_OK )
                {
                    toggleLedsImmediate( 4 );
                }
                else
                {
                    setLeds( 7 );
                    i2cStop( &I2CD1 );
                    chThdSleepMilliseconds( 10 );
                    i2cStart( &I2CD1, &i2cfg1 );
                    continue;
                }
                // Get back input.
                chMtxLock( &mutex );
                //ins[i+1] = (dataIn & 0x0000FFFF);
                ins[i+1] = dataIn;
                chMtxUnlock();
            }

            // Here is generic I2C io.
            i2cIo();

            chThdSleepMilliseconds( I2C_QUERY_PERIOD_MS );

        }
        else
        {
            static uint8_t addr;
            addr = I2C_BASE_ADDR + ind - 1;
            //setLeds( addr );

            dataIn = valueRead();
            do {
                //dataIn = 0x12345678;
                status = i2cSlaveIoTimeout( &I2CD1, addr,
                                            (uint8_t *)&dataOut,  sizeof( dataOut ),
                                            (uint8_t *)&dataIn, sizeof( dataIn ),
                                            i2cRxCb, i2cTxCb, tmo );
                if ( status != RDY_OK )
                {
                    i2cStart( &I2CD1, &i2cfg1 );
                    setLeds( 7 );
                }
            } while ( status != RDY_OK );

            // Managed to initialize I2C slave IO.
            setLeds( 0 );
            while ( 1 )
            {
                /*
                status = i2cSlaveIoTimeout( &I2CD1, addr,
                                            (uint8_t *)&dataOut,  sizeof( dataOut ),
                                            (uint8_t *)&dataIn, sizeof( dataIn ),
                                            i2cRxCb, i2cTxCb, tmo );
                */
                chThdSleepMilliseconds( I2C_QUERY_PERIOD_MS );
                pendDataOut = valueRead();
                chSysLock();
                    dataIn = pendDataOut;
                chSysUnlock();
                write( dataOut );
            }
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
    for ( i=0; i<I2C_SLAVES_CNT; i++ )
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
    pendOuts[index] = *val;
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
    chprintf( chp, "ok:st<\r\n" );
}

void cmd_set_output( BaseChannel *chp, int argc, char * argv [] )
{
    if ( argc < (I2C_SLAVES_CNT+1) )
    {
        chprintf( chp, "err:args expected<\r\n" );
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
        chprintf( chp, "ok:out<\r\n" );
    }
}













static uint8_t g_i2cAddr = 64;
static uint8_t g_i2cOutBuffer[ I2C_OUT_BUF_SZ ];
static uint8_t g_i2cInBuffer[ I2C_IN_BUF_SZ ];
static uint8_t g_i2cTxSz = 0,
               g_i2cRxSz = 0;
static uint8_t g_i2cStatus = 0;

void i2cSetAddr( uint8_t val )
{
    g_i2cAddr = val;
}

void i2cSetBuf( uint8_t at, uint8_t val )
{
    g_i2cOutBuffer[ at ] = val;
}

void i2cIo( void )
{
    static msg_t status;
    static uint8_t st;
         // Debug code.
            /*
          static uint16_t nnn = 0;
            if ( nnn++ > 50 )
                nnn = 0;
            else
                return;
            g_i2cAddr = 64;
            g_i2cStatus = 1;
            g_i2cTxSz = 4;
            g_i2cRxSz = 0;
            g_i2cOutBuffer[0] = 6;
            g_i2cOutBuffer[1] = 1;
            g_i2cOutBuffer[2] = 0x0F;
            g_i2cOutBuffer[3] = 0x70;
          */
        // / Debug code.
    chMtxLock( &mutex );
        st = g_i2cStatus;
    chMtxUnlock();
    if ( st == 1 )
    {
        static systime_t tmo;
        tmo = MS2ST( 300 );
        if ( g_i2cTxSz > 0 )
        {
            status = i2cMasterTransmitTimeout( &I2CD1, g_i2cAddr,
                                               g_i2cOutBuffer, g_i2cTxSz,
                                               0,  0,
                                               tmo );
            if ( status == RDY_OK )
                toggleLedsImmediate( 2 );
            else
                setLeds( 7 );
            if ( status != RDY_OK )
            {
                chMtxLock( &mutex );
                    g_i2cStatus = 2;
                chMtxUnlock();
                i2cStart( &I2CD1, &i2cfg1 );
                return;
            }
        }
        if ( g_i2cRxSz > 0 )
        {
            status = i2cMasterReceiveTimeout( &I2CD1, g_i2cAddr,
                                              g_i2cInBuffer, g_i2cRxSz,
                                              tmo );
            if ( status == RDY_OK )
                toggleLedsImmediate( 4 );
            else
                setLeds( 7 );
            if ( status != RDY_OK )
            {
                chMtxLock( &mutex );
                    g_i2cStatus = 3;
                chMtxUnlock();
                i2cStart( &I2CD1, &i2cfg1 );
                return;
            }
        }
        chMtxLock( &mutex );
            g_i2cStatus = 0;
        chMtxUnlock();
    }
}

void i2cSetStatus( uint8_t val )
{
  chMtxLock( &mutex );
      g_i2cStatus = val;
  chMtxUnlock();
}

uint8_t i2cStatus( void )
{
    chMtxLock( &mutex );
        static uint8_t res;
        res = g_i2cStatus;
    chMtxUnlock();
    return res;
}

uint8_t i2cBuf( uint8_t index )
{
    return g_i2cInBuffer[ index ];
}



void i2c_set_addr( BaseChannel *chp, int argc, char * argv[] )
{
    if ( argc > 0 )
    {
        static int8_t v;
        v = (uint8_t)atoi( argv[0] );
        i2cSetAddr( v );
        chprintf( chp, "ok:set_addr<\r\n" );
    }
    else
        chprintf( chp, "err:arg expected<\r\n" );
}

void i2c_set_buf( BaseChannel *chp, int argc, char * argv[] )
{
    if ( argc > 0 )
    {
        static uint8_t at;
        at = atoi( argv[0] );
        static uint8_t i;
        for ( i=0; i<(argc-1); i++ )
        {
            static uint8_t v;
            v = (uint8_t)atoi( argv[i+1] );
            i2cSetBuf( at+i, v );
        }
        chprintf( chp, "ok:set_buf<\r\n" );
    }
    else
        chprintf( chp, "err:args expected<\r\n" );
}

void i2c_io( BaseChannel *chp, int argc, char * argv[] )
{
    if ( argc > 1 )
    {
        g_i2cTxSz = (uint8_t)atoi( argv[0] );
        g_i2cRxSz = (uint8_t)atoi( argv[1] );
        // Initiate IO.
        // IO itself will be executed in a separate thread.
        i2cSetStatus( 1 );
        chprintf( chp, "ok:io %d %d<\r\n", g_i2cTxSz, g_i2cRxSz );
    }
    else
        chprintf( chp, "err:args expected<\r\n" );
}

void i2c_status( BaseChannel *chp, int argc, char * argv[] )
{
    (void)argc;
    (void)argv;
    static uint8_t res;
    res = i2cStatus();
    chprintf( chp, "ok:{%d}<\r\n", res );
}

void i2c_buffer( BaseChannel *chp, int argc, char * argv[] )
{
    if ( argc > 0 )
    {
        static uint8_t cnt;
        cnt = atoi( argv[0] );
        static uint8_t i;
        chprintf( chp, "ok:{" );
        for ( i=0; i<cnt; i++ )
            chprintf( chp, "%d ", g_i2cInBuffer[i] );
        chprintf( chp, "}<\r\n" );
    }
    else
        chprintf( chp, "err: arg expected<\r\n" );
}










