
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

// Generic I2C commands.
void i2c_set_addr( BaseChannel *chp, int argc, char * argv[] );
void i2c_set_buf( BaseChannel *chp, int argc, char * argv[] );
void i2c_io( BaseChannel *chp, int argc, char * argv[] );
void i2c_status( BaseChannel *chp, int argc, char * argv[] );
void i2c_buffer( BaseChannel *chp, int argc, char * argv[] );

#endif



