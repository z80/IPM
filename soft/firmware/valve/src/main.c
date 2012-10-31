
#include "ch.h"
#include "hal.h"

#include "read_ctrl.h"

int main(void)
{

  halInit();
  chSysInit();

  initRead();
  while ( 1 )
  {
    chThdSleepSeconds( 1 );
  }
  return 0;
}
