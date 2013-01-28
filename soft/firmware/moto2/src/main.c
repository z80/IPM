
#include "ch.h"
#include "hal.h"

#include "iwdg.h"

#include "led_ctrl.h"
#include "exec_ctrl.h"
#include "i2c_ctrl.h"
#include "dac_ctrl.h"
#include "bmsd_ctrl.h"
#include "encabs_ctrl.h"
#include "encrel_ctrl.h"


/*static WORKING_AREA( waUart, 1024 );
static msg_t uartThread( void *arg )
{
    (void)arg;
    chRegSetThreadName( "ua" );
    while ( 1 )
    {
        bmsdSetEn();
        chThdSleepSeconds( 1 );
    }

    return 0;
}*/



int main(void)
{
    halInit();
    chSysInit();

    IWDGConfig cfg;
    cfg.div = IWDG_DIV_256;
    cfg.counter = (40000 / 256 / 2 );
    iwdgInit();
    iwdgStart( &IWDGD, &cfg );
    iwdgReset( &IWDGD );

    initLed();
    setLeds( 3 );
    encabsInit();
    encrelInit();
    dacInit();
    bmsdInit();
    execInit();
    //chThdSleepSeconds( 2 );
    initI2c();

    //iwdgReset( &IWDGD );

	//chThdCreateStatic( waUart, sizeof(waUart), NORMALPRIO, uartThread, NULL );

    while (TRUE)
    {
        iwdgReset( &IWDGD );
        chThdSleepMilliseconds( 250 );
    }
    return 0;
}
