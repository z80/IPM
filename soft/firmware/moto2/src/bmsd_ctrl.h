
#ifndef __BMSD_CTRL_H_
#define __BMSD_CTRL_H_

#include "ch.h"

void bmsdInit( void );
uint8_t bmsdReady( void );
void bmsdRawCmd( uint8_t * cmd );
void bmsdSetEn( void );
void bmsdSetSpeed( int16_t speed );

#endif



