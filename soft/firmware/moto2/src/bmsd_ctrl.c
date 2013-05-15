
#include "bmsd_ctrl.h"
#include "ch.h"
#include "hal.h"
#include "hdw_config.h"

static uint8_t status = 0;
static uint8_t ioBuffer[5];
static SerialConfig config =
{
    9600,
    0,
    0,
    0
};


static uint8_t crc8( uint8_t data, uint8_t seed )
{
    uint8_t bitsLeft;
    uint8_t temp;

    for ( bitsLeft=8; bitsLeft>0; bitsLeft-- )
    {
        temp = ( ( seed ^ data ) & 0x01 );
        if ( temp == 0 )
            seed >>= 1;
        else
        {
            seed ^= 0x18;
            seed >>= 1;
            seed |= 0x80;
        }
        data >>= 1;
    }
    return seed;
}

static void uartIo( void )
{
    static systime_t tmo;
    tmo = MS2ST( BMSD_TIMEOUT );
    // Set dir to output.
    palSetPad( BMSD_DIR_PORT, BMSD_DIR_PIN );
    chThdSleepMilliseconds( 5 );
    // Write.
    sdWriteTimeout( &SD2, ioBuffer, sizeof( ioBuffer ), tmo );
    // This is 5 bytes per 9 bits duration as 9600bps is 4.6875.
    // But OS task switch doesn't allow to make it perfectly.
    // So I do that with enough overcover.
    chThdSleepMilliseconds( 7 );
    // Set dir to input.
    palClearPad( BMSD_DIR_PORT, BMSD_DIR_PIN );
    // Read.
    sdReadTimeout( &SD2, ioBuffer, sizeof( ioBuffer ), tmo );
    status = 0;
}


void bmsdInit( void )
{
    palSetPadMode( BMSD_DIR_PORT, BMSD_DIR_PIN, PAL_MODE_OUTPUT_PUSHPULL );
    palClearPad( BMSD_DIR_PORT, BMSD_DIR_PIN );

    //uartStart( &BMSD_UART, &uart_cfg );
    //uartStart( &UARTD2, &uart_cfg_1 );
    sdStart( &SD2, &config );
}

uint8_t bmsdReady( void )
{
    chSysLock();
        uint8_t res = status;
    chSysUnlock();
    return res;
}

void bmsdRawCmd( uint8_t * cmd )
{
    status = 1;
    ioBuffer[0] = cmd[0];
    ioBuffer[1] = cmd[1];
    ioBuffer[2] = cmd[2];
    ioBuffer[3] = cmd[3];
    ioBuffer[4] = cmd[4];
    uartIo();
}

void bmsdSetEn( void )
{
    ioBuffer[0] = 0xE6;
    ioBuffer[1] = 0xFF;
    ioBuffer[2] = 0x51;
    ioBuffer[3] = 0x00;
    ioBuffer[4] = 0x00;
    uartIo();
}

void bmsdSetSpeed( int16_t speed )
{
    // First set dir.
    uint8_t dir = ( speed > 0 ) ? 1 : 0;
    ioBuffer[0] = 0xE6;
    ioBuffer[1] = 0xFF;
    ioBuffer[2] = 0xA7;
    ioBuffer[3] = dir;
    ioBuffer[4] = 0x00;
    uartIo();

    // Set speed afterwards.
    uint16_t s16 = ( speed > 0 ) ? speed : -speed;
    uint8_t  s8  = (uint8_t)( s16 & 0x00FF );
    s8 = ( s8 <= 250 ) ? s8 : 250;
    ioBuffer[0] = 0xE6;
    ioBuffer[1] = 0xFF;
    ioBuffer[2] = 0xA3;
    ioBuffer[3] = s8;
    ioBuffer[4] = 0x00;
    uartIo();
}




