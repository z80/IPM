
#ifndef __LED_CTRL_H_
#define __LED_CTRL_H_

#include "ch.h"

void initLed( void );
void setLeds( uint32_t val );
void toggleLedI( uint32_t ind );

#endif



