
#include "bmsd_ctrl.h"
#include "ch.h"
#include "hal.h"
#include "hdw_config.h"

static uint8_t bytesReceived = 5;
static uint8_t ioBuffer[5];
static VirtualTimer vt, readVt;
static Thread * thread = 0;

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

static void txLast( UARTDriver * uartp )
{
    (void)uartp;
}

static void timeout( void * args )
{
    (void)args;
    // Stop reading.
    uartStopReceiveI( &BMSD_UART );
    // Resume thread.
    //chSysLockFromIsr();
    chSchReadyI( thread );
    //chSysUnlockFromIsr();
}

static void startRead( void * args )
{
    (void)args;
    // First setup timeout timer.
    if ( chVTIsArmedI( &vt ) )
        chVTResetI( &vt );
    chVTSetI( &vt, MS2ST( BMSD_RX_TIMEOUT ), timeout, NULL );
    // Start receive.
    uartStartReceiveI( &BMSD_UART, 5, ioBuffer );
    //timeout( NULL );
}

static void txCompleted( UARTDriver *uartp )
{
  (void)uartp;
  // Switch direction to read.
  palClearPad( BMSD_DIR_PORT, BMSD_DIR_PIN );

  chSysLockFromIsr();
  bytesReceived = 0;

  if (chVTIsArmedI(&readVt))
    chVTResetI(&readVt);
  chVTSetI(&readVt, MS2ST(1), startRead, NULL);
  //chVTSetI(&readVt, MS2ST(1), timeout,   NULL);

  chSysUnlockFromIsr(); 

  //timeout( NULL );
}

static void rxEnd( UARTDriver *uartp )
{
    (void)uartp;
}

static void rxChar( UARTDriver *uartp, uint16_t c )
{
    (void)uartp;
    (void)c;
    chSysLockFromIsr();
    bytesReceived++;
    if ( bytesReceived >= 5 )
    {
        if (chVTIsArmedI(&vt))
          chVTResetI(&vt);
        chSchReadyI( thread );
    }
    chSysUnlockFromIsr();
}

static void rxErr( UARTDriver *uartp, uartflags_t e )
{
    (void)uartp;
    (void)e;
}


static void uartIo( void )
{
    ioBuffer[4] = crc8( ioBuffer[0], ioBuffer[4] );
    ioBuffer[4] = crc8( ioBuffer[1], ioBuffer[4] );
    ioBuffer[4] = crc8( ioBuffer[2], ioBuffer[4] );
    ioBuffer[4] = crc8( ioBuffer[3], ioBuffer[4] );
    palSetPad( BMSD_DIR_PORT, BMSD_DIR_PIN );
    uartStartSend( &BMSD_UART, 5, ioBuffer );

    chSysLock();
    thread = chThdSelf();
    chSchGoSleepS( THD_STATE_SUSPENDED );
    chSysUnlock();
}

static UARTConfig uart_cfg =
{
  txLast,      // TX written to hardware.
  txCompleted, // TX physically completed.
  rxEnd,       // RX buffer ended.
  rxChar,      // Received char.
  rxErr,       // Error.
  BMSD_BAUD,
  0,
  USART_CR2_LINEN,
  0
};














static VirtualTimer vt1, vt2;

static void restart(void *p) {

  (void)p;
  uartStartSendI(&UARTD2, 14, "Hello World!\r\n");
}

static void ledoff(void *p) {

  (void)p;
  //palSetPad(IOPORT3, GPIOC_LED);
}

/*
 * This callback is invoked when a transmission buffer has been completely
 * read by the driver.
 */
static void txend1(UARTDriver *uartp) {

  (void)uartp;
  //palClearPad(IOPORT3, GPIOC_LED);
}

/*
 * This callback is invoked when a transmission has physically completed.
 */
static void txend2(UARTDriver *uartp) {

  (void)uartp;
  //palSetPad(IOPORT3, GPIOC_LED);
  chSysLockFromIsr();
  if (chVTIsArmedI(&vt1))
    chVTResetI(&vt1);
  chVTSetI(&vt1, MS2ST(5000), restart, NULL);
  chSysUnlockFromIsr();
}

/*
 * This callback is invoked on a receive error, the errors mask is passed
 * as parameter.
 */
static void rxerr(UARTDriver *uartp, uartflags_t e) {

  (void)uartp;
  (void)e;
}

/*
 * This callback is invoked when a character is received but the application
 * was not ready to receive it, the character is passed as parameter.
 */
static void rxchar(UARTDriver *uartp, uint16_t c) {

  (void)uartp;
  (void)c;
  /* Flashing the LED each time a character is received.*/
  //palClearPad(IOPORT3, GPIOC_LED);
  chSysLockFromIsr();
  if (chVTIsArmedI(&vt2))
    chVTResetI(&vt2);
  chVTSetI(&vt2, MS2ST(200), ledoff, NULL);
  chSysUnlockFromIsr();
}

/*
 * This callback is invoked when a receive buffer has been completely written.
 */
static void rxend(UARTDriver *uartp) {

  (void)uartp;
}

/*
 * UART driver configuration structure.
 */
static UARTConfig uart_cfg_1 = {
  txend1,
  txend2,
  rxend,
  rxchar,
  rxerr,
  38400,
  0,
  USART_CR2_LINEN,
  0
};
























void bmsdInit( void )
{
    palSetPadMode( BMSD_DIR_PORT, BMSD_DIR_PIN, PAL_MODE_OUTPUT_PUSHPULL );
    palClearPad( BMSD_DIR_PORT, BMSD_DIR_PIN );

    //uartStart( &BMSD_UART, &uart_cfg );
    uartStart( &UARTD2, &uart_cfg_1 );
}

uint8_t bmsdReady( void )
{
    chSysLock();
        uint8_t res = ( bytesReceived >= 5 ) ? 1 : 0;
    chSysUnlock();
    return res;
}

void bmsdRawCmd( uint8_t * cmd )
{
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




