
#ifndef __JOYSTICK_CTRL_H_
#define __JOYSTICK_CTRL_H_

#include "ch.h"

#define NULL_X_BIT      1
#define NULL_Y_BIT      2
#define TOTMANN_BIT     4

struct SJoy
{
	uint8_t  flags;
	uint16_t value[2];
};

typedef struct SJoy TJoy;

void initJoy( void );
void joystick( TJoy * joy );

#endif





