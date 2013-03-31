
#include "ch.h"
#include "hal.h"

#include "ftdi_ctrl.h"

int main(void)
{

    halInit();
    chSysInit();

    initFtdi();
    while (TRUE)
    {
        processShellFtdi(); 
        chThdSleepMilliseconds(500);
    }
    return 0;
}
