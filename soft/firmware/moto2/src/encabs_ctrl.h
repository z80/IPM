
#ifndef __ENCABS_CTRL_H_
#define __ENCABS_CTRL_H_

#include "ch.h"


void encabsInit( void );
uint32_t encabs( void );
void encabsSetBits( int bits );
void encabsSetDelay( int cnt );
void encabsSetDelayFront( int cnt );
void encabsSetDelayBack( int cnt );


#endif
