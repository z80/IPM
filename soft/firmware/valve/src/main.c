
#include "ch.h"
#include "hal.h"


int main(void)
{

  halInit();
  chSysInit();

  while ( 1 )
  {
    chThdSleepSeconds( 1 );
  }
  return 0;
}
