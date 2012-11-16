
#include "ch.h"
#include "hal.h"

#include "hdw_config.h"
#include "led_ctrl.h"
#include "read_ctrl.h"
#include "write_ctrl.h"
#include "i2c_ctrl.h"
#include "usb_ctrl.h"

int main(void)
{

  halInit();
  chSysInit();

  initLed();
  //initRead();
  //initWrite();
  //initI2c();
  initUsb();
  setLeds( 1 );
  while ( 1 )
  {
      //write( 0xFFFFFFFF );
      //setLeds( 3 );
      //chThdSleepSeconds( 3 );
      //write( 0x00000000 );
      //setLeds( 1 );
      chThdSleepSeconds( 1 );
      processShell();
  }
  return 0;
}








