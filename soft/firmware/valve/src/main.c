
#include "ch.h"
#include "hal.h"

#include "hdw_config.h"
#include "led_ctrl.h"
#include "read_ctrl.h"
#include "write_ctrl.h"

int main(void)
{

  halInit();
  chSysInit();

  initLed();
  //initRead();
  initWrite();
  while ( 1 )
  {
    //setLeds( 1 );
    palSetPad( OUT_PORT, OUT_CP_PIN );
    chThdSleepSeconds( 2 );
    palClearPad( OUT_PORT, OUT_CP_PIN );
    chThdSleepSeconds( 2 );
    //setLeds( 2 );
    //chThdSleepSeconds( 1 );
    //setLeds( 4 );
    //chThdSleepSeconds( 2 );
    //setLeds( 2 );
    //chThdSleepSeconds( 1 );
  }
  return 0;
}
