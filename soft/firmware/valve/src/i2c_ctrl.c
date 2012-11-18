
#include <stdlib.h>

#include "i2c_ctrl.h"
#include "hal.h"
#include "chprintf.h"

#include "read_ctrl.h"
#include "write_ctrl.h"
#include "led_ctrl.h"
#include "hdw_config.h"



static Mutex    mutex;
static uint8_t  addr[ I2C_SLAVES_CNT ];
static uint32_t outs[ I2C_SLAVES_CNT ];
static uint32_t ins[ I2C_SLAVES_CNT ];
static uint8_t  isMaster = 1;

#define TEST_BUFFER_SIZE 16
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
        chThdSleepMilliseconds( 500 );
        // Read ADDRESS pins.
        uint16_t a = palReadPad( ADDR_PORT, ADDR_0_PIN ) |
                   ( palReadPad( ADDR_PORT, ADDR_1_PIN ) << 1 ) |
                   ( palReadPad( ADDR_PORT, ADDR_2_PIN ) << 2 );
        setLeds( a );

    	static uint8_t master;
    	static msg_t status;
        static systime_t tmo;
        tmo = MS2ST( 1000 );
    	chMtxLock( &mutex );
    	master = isMaster;
    	chMtxUnlock();
    	// I/O with other boards.
        /*if ( ( master ) || ( a != 0b00000111 ) )
    	{
            static int16_t i;
            // Excluding itself. That's why beginning from 1.
            for ( i=1; i<I2C_SLAVES_CNT; i++ )
    	    {
    	    	status = RDY_OK;
                status = i2cMasterTransmitTimeout( &I2CD1, addr[i],
    	    			                           (uint8_t *)&(outs[ i ]), sizeof(uint32_t),
    	    			                           (uint8_t *)&(ins[ i ]),  sizeof(uint32_t),
    	    			                           tmo );
            }
    	}
    	else
    	{
    		static uint32_t out, in;
    		in = valueRead();
	    	status = i2cSlaveReceiveTimeout( &I2CD1, addr[0],
	    			                         (uint8_t *)&in,  sizeof( in ),
	    			                         (uint8_t *)&out, sizeof( out ),
	    			                         tmo );
	    	write( out );
        }*/
        if ( a == 0b00000111 )
        {
            static uint32_t out = 0x12345678;
            status = RDY_OK;
            status = i2cMasterTransmitTimeout( &I2CD1, testAddr,
                                               (uint8_t *)(&out), sizeof(out),
                                               0,  0,
                                               tmo );
        }

    }

    return 0;
}

static const I2CConfig i2cfg1 =
{
    OPMODE_I2C,
    10000,
    STD_DUTY_CYCLE,
};

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

    // tune ports for I2C1
    int16_t i;
    for ( i=0; i<I2C_SLAVES_CNT; i++ )
        addr[i] = I2C_BASE_ADDR + i;
    outs[0] = 0;
    ins[0]  = 0;
    outs[1] = 0;
    ins[1]  = 0;

	// Initializing mutex.
    chMtxInit( &mutex );
	// Creating thread.
    chThdCreateStatic( waI2c, sizeof(waI2c), NORMALPRIO, i2cThread, NULL );
}

void state( uint8_t index, uint32_t * val )
{
	// It should be mutex here.
    *val = ins[index];
}

void setOutput( uint8_t index, uint32_t * val )
{
	// It should be mutex here.
    outs[index] = *val;
}

void cmd_state( BaseChannel *chp, int argc, char * argv [] )
{
	(void)chp;
	(void)argc;
	(void)argv;
    uint32_t v;
    state( 0, &v );
    chprintf( chp, "%d", v );
    state( 1, &v );
    chprintf( chp, "%d", v );
    state( 2, &v );
    chprintf( chp, "%d", v );
    chprintf( chp, "ok:st\r\n" );
}

void cmd_set_output( BaseChannel *chp, int argc, char * argv [] )
{
    if ( argc < 3 )
    {
    	chprintf( chp, "er:3 args expected\r\n" );
    }
    else
    {
    	uint32_t v;
    	v = atoi( argv[0] );
    	setOutput( 0, &v );
    	v = atoi( argv[1] );
    	setOutput( 1, &v );
    	v = atoi( argv[2] );
    	setOutput( 2, &v );
    }
}

void testSetAddr( uint8_t val )
{
    addr[0] = val;
}

void testSetMaster( uint8_t set )
{
    isMaster = set;
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
	status = RDY_OK;
	status = i2cSlaveReceiveTimeout( &I2CD1, addr,
			                         (uint8_t *)val,  sizeof( uint32_t ),
			                         0, 0,
			                         tmo );
    return ( status = RDY_OK ) ? 0 : 1;
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
    	testSetAddr( v );
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
	if ( isMaster )
	{
		static msg_t status;
	    static systime_t tmo;
	    tmo = MS2ST( 1000 );
		status = RDY_OK;
		status = i2cMasterTransmitTimeout( &I2CD1, testAddr,
				                           testBuffer, testCnt,
				                           0,  0,
				                           tmo );
	    chprintf( chp, "ok:%d", status );

	}
	else
	{
		static msg_t status;
	    static systime_t tmo;
	    tmo = MS2ST( 1000 );
		status = RDY_OK;
		status = i2cSlaveReceiveTimeout( &I2CD1, testAddr,
				                         0,  0,
				                         testBuffer, testCnt,
				                         tmo );
		chprintf( chp, "ok:%d", status );
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










