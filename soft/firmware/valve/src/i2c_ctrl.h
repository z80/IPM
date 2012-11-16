
#ifndef __I2C_CTRL_H_
#define __I2C_CTRL_H_

#include "ch.h"
#include "shell.h"

void initI2c( void );
// These are master commands.
void state( uint8_t index, uint32_t * val );
void setOutput( uint8_t index, uint32_t * val );
// Commands for console.
void cmd_state( BaseChannel *chp, int argc, char * argv[] );
void cmd_set_output( BaseChannel *chp, int argc, char * argv[] );
// Test routines.
void testSetAddr( uint8_t ind );
void testSetMaster( uint8_t set );
uint8_t testSend( uint8_t ind, uint32_t * val );
uint8_t testReceive( uint8_t ind, uint32_t * val );
// Test USB commands.
void tst_i2c_set_addr( BaseChannel *chp, int argc, char * argv[] );
void tst_i2c_set_master( BaseChannel *chp, int argc, char * argv[] );
void tst_i2c_set_buffer( BaseChannel *chp, int argc, char * argv[] );
void tst_i2c_io( BaseChannel *chp, int argc, char * argv[] );

#endif



