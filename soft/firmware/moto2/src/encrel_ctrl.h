
#ifndef __ENCREL_CTRL_H_
#define __ENCREL_CTRL_H_

#include "ch.h"

void encrelInit( void );
void encrelSet( uint8_t index, int32_t value );
int32_t encrel( uint8_t index );

#endif









