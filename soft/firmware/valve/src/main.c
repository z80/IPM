
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

    IWDGConfig cfg;
    cfg.div = IWDG_DIV_256;
    cfg.counter = (40000 / 256 * 5);
    iwdgStart( &IWDGD, &cfg );
    chThdSleepMilliseconds(1000);
    iwdgReset( &IWDGD );

    initLed();
    initRead();
    initWrite();
    initI2c();
    initUsb();

    setLeds( 2 );

    while (TRUE)
    {
        processShell();
        chThdSleepMilliseconds(1000);
        iwdgReset( &IWDGD );
    }
    return 0;
}
