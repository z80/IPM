
#include "ch.h"
#include "hal.h"

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
    initRead();
    initWrite();
    //initUsb();

    setLeds( 1 );
    initI2c();

    while (TRUE)
    {
        //processShell();
        chThdSleepMilliseconds(1000);
    }
    return 0;
}
