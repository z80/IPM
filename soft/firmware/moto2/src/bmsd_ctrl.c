
#include "bmsd_ctrl.h"
#include "ch.h"
#include "hal.h"
#include "hdw_config.h"

static uint8_t bytesReceived = 5;
static uint8_t ioBuffer[5];
static VirtualTimer vt;

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

static void txCompleted( UARTDriver *uartp )
{
  (void)uartp;
  palClearPad( BMSD_DIR_PORT, BMSD_DIR_PIN );
  uartStartReceiveI( &BMSD_UART, 5, ioBuffer );
  bytesReceived = 0;
}

static void rxchar( UARTDriver *uartp, uint16_t c )
{
    (void)uartp;
    (void)c;
    bytesReceived++;
    if ( bytesReceived >= 5 )
    {
        if (chVTIsArmedI(&vt))
          chVTResetI(&vt);
    }
}

static void uartIo( void )
{
    ioBuffer[4] = crc8( ioBuffer[0], ioBuffer[4] );
    ioBuffer[4] = crc8( ioBuffer[1], ioBuffer[4] );
    ioBuffer[4] = crc8( ioBuffer[2], ioBuffer[4] );
    ioBuffer[4] = crc8( ioBuffer[3], ioBuffer[4] );
    palSetPad( BMSD_DIR_PORT, BMSD_DIR_PIN );
    uartStartSend( &BMSD_UART, 5, ioBuffer );
    chVTSetI( &vt, MS2ST(BMSD_RX_TIMEOUT), NULL, NULL );

    // Wait till timeout or reset from ISR.
    while ( chVTIsArmedI( &vt ) )
        chThdSleepMicroseconds( BMSD_RX_TIMEOUT );
}

static UARTConfig uart_cfg =
{
  NULL,        // TX written to hardware.
  txCompleted, // TX physically completed.
  NULL,        // RX buffer ended.
  rxchar,      // Received char.
  NULL,        // Error.
  BMSD_BAUD,
  0,
  USART_CR2_LINEN,
  0
};

void bmsdInit( void )
{
    palSetPadMode( BMSD_DIR_PORT, BMSD_DIR_PIN, PAL_MODE_OUTPUT_PUSHPULL );
    palClearPad( BMSD_DIR_PORT, BMSD_DIR_PIN );

    //uartStart( &BMSD_UART, &uart_cfg );
}

uint8_t bmsdReady( void )
{
    // Here it also should be lock unlock.
    uint8_t res = ( bytesReceived >= 5 ) ? 1 : 0;
    return res;
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




