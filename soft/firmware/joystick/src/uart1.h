
#ifndef __UART_1_H_
#define __UART_1_H_

#include "ch.h"

void    initUart1( uint32_t osc, uint32_t baud );
int32_t sendUart1( uint8_t * data, int sz );
int32_t receiveUart1( uint8_t * data, int sz );




#endif



