
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

    /*palClearPad( OUT_PORT, OUT_CP_PIN );
    chThdSleepMilliseconds( 1 );
    palSetPad( OUT_PORT, OUT_MR_PIN );
    chThdSleepMilliseconds( 1 );
    uint8_t v = 0x0F;
    uint8_t i;
    for ( i=0; i<8; i++ )
    {
        palClearPad( OUT_PORT, OUT_CP_PIN );
        chThdSleepMilliseconds( 1 );

        if ( v & (1<<i) )
            palSetPad( OUT_PORT, OUT_DSA_PIN );
        else
            palClearPad( OUT_PORT, OUT_DSA_PIN );
        chThdSleepMilliseconds( 1 );

        palSetPad( OUT_PORT, OUT_CP_PIN );
        chThdSleepMilliseconds( 1 );
    }
    setLeds( 1 );
    chThdSleepSeconds( 1 );

    v = 0xF0;
    for ( i=0; i<8; i++ )
    {
        palClearPad( OUT_PORT, OUT_CP_PIN );
        chThdSleepMilliseconds( 1 );

        if ( v & (1<<i) )
            palSetPad( OUT_PORT, OUT_DSA_PIN );
        else
            palClearPad( OUT_PORT, OUT_DSA_PIN );
        chThdSleepMilliseconds( 1 );

        palSetPad( OUT_PORT, OUT_CP_PIN );
        chThdSleepMilliseconds( 1 );
    }
    setLeds( 2 );*/
      write( 0xFFFFFFFF );
      chThdSleepSeconds( 1 );
      write( 0x00000000 );
      chThdSleepSeconds( 1 );
  }
  return 0;
}
