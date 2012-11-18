
#include "ch.h"
#include "hal.h"

#include "usb_ctrl.h"
#include "led_ctrl.h"
#include "read_ctrl.h"
#include "write_ctrl.h"

int main(void)
{
    halInit();
    chSysInit();

    initLed();
    initRead();
    initWrite();
    initUsb();

    setLeds( 1 );

    while (TRUE)
    {
        processShell();
        chThdSleepMilliseconds(1000);
    }
    return 0;
}
