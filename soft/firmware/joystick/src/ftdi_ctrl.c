
#include "ftdi_ctrl.h"
#include "hal.h"
#include "shell.h"
#include "chprintf.h"

#define WR_PAD      1
#define WR_PORT     IOPORT1

#define RD_PAD      2
#define RD_PORT     IOPORT1

#define RXN_PAD     3
#define RXN_PORT    IOPORT1

#define TXE_PAD     4
#define TXE_PORT    IOPORT1

#define DATA_PAD    5
#define DATA_PORT   IOPORT1

static void delay( void )
{
    volatile int i;
    for ( i=0; i<4096; i++ )
        ;
}

static void    setDataInput( void );
static void    setDataOutput( void );

static bool_t  ftdiPutWouldBlock( void * inst );
static bool_t  ftdiGetWouldBlock( void * inst );
static msg_t   ftdiPutT( void * inst, uint8_t chr, systime_t time );
static msg_t   ftdiGetT( void * inst, systime_t chr );
static size_t  ftdiReadT( void * inst, uint8_t * bp, size_t n, systime_t time );
static size_t  ftdiWriteT( void * inst, const uint8_t * bp, size_t n, systime_t time );


// Virtual methods table.
static struct BaseChannelVMT vmt; 
static BaseChannel channel;




static void cmd_mem( BaseChannel * chp, int argc, char * argv[] )
{
    (void)argc;
    (void)argv;
    chprintf( chp, "Hi!\r\n" );
}

#define SHELL_SZ    THD_WA_SIZE( 1024 * 3 )
static const ShellCommand commands[] = 
{
    { "mem",   cmd_mem }, 
    { NULL,    NULL }
};

static const ShellConfig shellConfig = 
{
    &channel, 
    commands
};

static Thread * shellTp = 0;


void processShellFtdi( void )
{
    if ( !shellTp )
        shellTp = shellCreate( &shellConfig,  SHELL_SZ, NORMALPRIO );
    else if ( chThdTerminated( shellTp ) )
    {
        chThdRelease( shellTp );
	shellTp = 0;
    }
}




void initFtdi( void )
{
    palSetPadMode( WR_PORT,   WR_PAD,     PAL_MODE_OUTPUT_PUSHPULL );
    palSetPadMode( RD_PORT,   RD_PAD,     PAL_MODE_OUTPUT_PUSHPULL );
    palSetPadMode( RXN_PORT,  RXN_PAD,    PAL_MODE_INPUT );
    palSetPadMode( TXE_PORT,  TXE_PAD,    PAL_MODE_INPUT );
    setDataInput();

    vmt.putwouldblock = ftdiPutWouldBlock;
    vmt.getwouldblock = ftdiGetWouldBlock;
    vmt.put           = ftdiPutT;
    vmt.get           = ftdiGetT;
    vmt.writet        = ftdiWriteT;
    vmt.readt         = ftdiReadT;
    
    channel.vmt = &vmt;
}

static void setDataInput( void )
{
    palSetPadMode( DATA_PORT, DATA_PAD,   PAL_MODE_INPUT );
    palSetPadMode( DATA_PORT, DATA_PAD+1, PAL_MODE_INPUT );
    palSetPadMode( DATA_PORT, DATA_PAD+2, PAL_MODE_INPUT );
    palSetPadMode( DATA_PORT, DATA_PAD+3, PAL_MODE_INPUT );
    palSetPadMode( DATA_PORT, DATA_PAD+4, PAL_MODE_INPUT );
    palSetPadMode( DATA_PORT, DATA_PAD+5, PAL_MODE_INPUT );
    palSetPadMode( DATA_PORT, DATA_PAD+6, PAL_MODE_INPUT );
    palSetPadMode( DATA_PORT, DATA_PAD+7, PAL_MODE_INPUT );
}


static void setDataOutput( void )
{
    palSetPadMode( DATA_PORT, DATA_PAD,   PAL_MODE_OUTPUT_PUSHPULL );
    palSetPadMode( DATA_PORT, DATA_PAD+1, PAL_MODE_OUTPUT_PUSHPULL );
    palSetPadMode( DATA_PORT, DATA_PAD+2, PAL_MODE_OUTPUT_PUSHPULL );
    palSetPadMode( DATA_PORT, DATA_PAD+3, PAL_MODE_OUTPUT_PUSHPULL );
    palSetPadMode( DATA_PORT, DATA_PAD+4, PAL_MODE_OUTPUT_PUSHPULL );
    palSetPadMode( DATA_PORT, DATA_PAD+5, PAL_MODE_OUTPUT_PUSHPULL );
    palSetPadMode( DATA_PORT, DATA_PAD+6, PAL_MODE_OUTPUT_PUSHPULL );
    palSetPadMode( DATA_PORT, DATA_PAD+7, PAL_MODE_OUTPUT_PUSHPULL );
}


static bool_t  ftdiPutWouldBlock( void * inst )
{
    (void)inst;
    return FALSE;
}

static bool_t  ftdiGetWouldBlock( void * inst )
{
    (void)inst;
    return FALSE;
}

static msg_t ftdiGetT( void * inst, systime_t time )
{
    (void)inst;
    (void)time;
    if ( palReadPad( RXN_PORT, RXN_PAD ) )
        return -1;
    // RD goes down.
    palClearPad( RD_PORT, RD_PAD );
    delay();
    static msg_t val;
    val = ( palReadPort( DATA_PORT ) >> DATA_PAD ) & 0xFF;
    palSetPad( RD_PORT, RD_PAD );
    return val;
}

static msg_t ftdiPutT( void * inst, uint8_t chr, systime_t time )
{
    (void)inst;
    (void)time;
    if ( palReadPad( TXE_PORT, TXE_PAD ) )
        return 1;
    // Make sure data is input.
    setDataOutput();
    palClearPad( TXE_PORT, TXE_PAD );
    delay();
    uint8_t i;
    for ( i=0; i<8; i++ )
    {
        if ( chr & ( 1 << i ) )
            palSetPad( DATA_PORT, DATA_PAD+i );
	else
	    palClearPad( DATA_PORT, DATA_PAD+i );
    }
    delay();
    palSetPad( TXE_PORT, TXE_PAD );
    delay();
    return 0;
}

static size_t  ftdiReadT( void * inst, uint8_t * bp, size_t n, systime_t time )
{
    size_t cnt = 0;
    msg_t  res;
    while ( ( res = ftdiGetT( inst, time ) ) >= 0 )
    {
        bp[cnt++] = res;
        if ( cnt >= n )
	    break;
    }
    return cnt;
}


static size_t  ftdiWriteT( void * inst, const uint8_t * bp, size_t n, systime_t time )
{
    size_t cnt = 0;
    while ( ftdiPutT( inst, bp[cnt++], time ) == 0 )
    {
        if ( cnt >= n )
	    break;
    }
    return cnt;
}







