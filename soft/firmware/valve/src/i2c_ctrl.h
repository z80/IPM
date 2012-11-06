
#ifndef __I2C_CTRL_H_
#define __I2C_CTRL_H_

#include "ch.h"

void initI2c( void );
// These are master commands.
void state( uint8_t index, uint32_t * val );
void setOutput( uint8_t index, uint32_t * val );
// Test routines.
void testSetAddr( uint8_t ind );
void testSetMaster( uint8_t set );
uint8_t testSend( uint8_t ind, uint32_t * val );
uint8_t testReceive( uint8_t ind, uint32_t * val );


#endif



