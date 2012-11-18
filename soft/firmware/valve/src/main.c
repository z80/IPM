
#include "ch.h"
#include "hal.h"

#include "usb_ctrl.h"

int main(void)
{
    halInit();
    chSysInit();

    initUsb();

    while (TRUE)
    {
        processShell();
        chThdSleepMilliseconds(1000);
    }
    return 0;
}
