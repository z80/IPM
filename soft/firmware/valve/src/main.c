
#include "ch.h"
#include "hal.h"

#include "read_ctrl.h"
#include "write_ctrl.h"

int main(void)
{

  halInit();
  chSysInit();

  initRead();
  initWrite();
  while ( 1 )
  {
    chThdSleepSeconds( 1 );
  }
  return 0;
}
