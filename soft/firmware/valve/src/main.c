
#include "ch.h"
#include "hal.h"

#include "iwdg.h"

#include "usb_ctrl.h"
#include "led_ctrl.h"
#include "read_ctrl.h"
#include "write_ctrl.h"
#include "i2c_ctrl.h"

int main(void)
{
    halInit();
    chSysInit();

    initLed();
    setLeds( 7 );
    initRead();
    initWrite();
    initI2c();
    initUsb();


    /*IWDGConfig cfg;
    cfg.div = IWDG_DIV_256;
    cfg.counter = (40000 / 256 / 2 );
    iwdgInit();
    iwdgStart( &IWDGD, &cfg );
    iwdgReset( &IWDGD );*/

    while (TRUE)
    {
        //iwdgReset( &IWDGD );
        processShell();
        chThdSleepMilliseconds( 250 );
    }
    return 0;
}
