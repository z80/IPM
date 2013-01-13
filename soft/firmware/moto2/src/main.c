
#include "ch.h"
#include "hal.h"

#include "iwdg.h"

#include "led_ctrl.h"
#include "i2c_ctrl.h"

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
    initI2c();


    while (TRUE)
    {
        chThdSleepMilliseconds( 1000 );
    }
    return 0;
}
