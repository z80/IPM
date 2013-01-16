
#include "ch.h"
#include "hal.h"

#include "iwdg.h"

#include "led_ctrl.h"
#include "i2c_ctrl.h"
#include "dac_ctrl.h"
#include "bmsd_ctrl.h"

int main(void)
{
    halInit();
    chSysInit();

    /*IWDGConfig cfg;
    cfg.div = IWDG_DIV_256;
    cfg.counter = (40000 / 256 / 2 );
    iwdgInit();
    iwdgStart( &IWDGD, &cfg );
    iwdgReset( &IWDGD );*/

    initLed();
    setLeds( 3 );
    dacInit();
    bmsdInit();
    //initI2c();


    while (TRUE)
    {
        //bmsdSetEn();
        chThdSleepSeconds( 1 );
        /*int16_t i;
        for ( i=0; i<256; i++ )
        {
            dacSet( 0, i );
            dacSet( 1, i );
            dacSet( 2, i );
            iwdgReset( &IWDGD );
            chThdSleepMilliseconds( 1 );
        }
        for ( i=255; i>=0; i-- )
        {
            dacSet( 0, i );
            dacSet( 1, i );
            dacSet( 2, i );
            iwdgReset( &IWDGD );
            chThdSleepMilliseconds( 1 );
        }*/
    }
    return 0;
}
