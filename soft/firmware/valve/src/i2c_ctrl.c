
#include "i2c_ctrl.h"
#include "hal.h"
#include "read_ctrl.h"
#include "write_ctrl.h"
#include "hdw_config.h"

static Mutex    mutex;
static uint8_t  addr[ I2C_SLAVES_CNT ];
static uint32_t outs[ I2C_SLAVES_CNT ];
static uint32_t ins[ I2C_SLAVES_CNT ];
static uint8_t  isMaster = 1;

static WORKING_AREA( waI2c, 256 );
static msg_t i2cThread( void *arg )
{
    (void)arg;
    chRegSetThreadName( "i" );
    while ( 1 )
    {
    	chThdSleepMilliseconds( 1 );
    	static uint8_t master;
    	static msg_t status;
        static systime_t tmo;
        tmo = MS2ST( 1000 );
    	chMtxLock( &mutex );
    	master = isMaster;
    	chMtxUnlock();
    	// I/O with other boards.
    	if ( master )
    	{
    	    static int16_t i;
    	    for ( i=0; i<2; i++ )
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
    	}
    }

    return 0;
}

static const I2CConfig i2cfg1 =
{
    OPMODE_I2C,
    1000, //400000,
    FAST_DUTY_CYCLE_2,
};

void initI2c( void )
{
    i2cInit();
    i2cStart(&I2CD1, &i2cfg1);
    // tune ports for I2C1
    palSetPadMode(IOPORT2, 6, PAL_MODE_STM32_ALTERNATE_OPENDRAIN );
    palSetPadMode(IOPORT2, 7, PAL_MODE_STM32_ALTERNATE_OPENDRAIN );
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








