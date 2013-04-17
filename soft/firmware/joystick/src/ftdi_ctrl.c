
#include "ftdi_ctrl.h"
#include "hal.h"
#include "shell.h"
#include "chprintf.h"

#define RXD0 (1)
#define RXD0_MSK (3)
#define TXD0 (1<<2)
#define TXD0_MSK (3<<3)




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
    &SD1,
    commands
};

static Thread * shellTp = 0;


void processShellFtdi( void )
{
    if ( !shellTp )
        shellTp = shellCreate( &shellConfig, SHELL_SZ, NORMALPRIO );
    else if ( chThdTerminated( shellTp ) )
    {
        chThdRelease( shellTp );
	shellTp = 0;
    }
}




void initFtdi( void )
{
    // Configure appropriate pins as UART0.
    PINSEL0 &= ~( RXD0_MSK | TXD0_MSK );
    PINSEL0 |= (RXD0 | TXD0);
    // Initialize UART with default parameters.
    sdStart( &SD1, NULL );          /* Default is 38400-8-N-1.*/
}








