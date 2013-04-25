
#ifndef __JOYSTICK_CTRL_H_
#define __JOYSTICK_CTRL_H_

#include "ch.h"

#define JOY_CNT             4

#define NULL_X_BIT      1
#define NULL_Y_BIT      2
#define TOTMANN_BIT     4
#define STOP_BTN_BIT    8

#pragma pack( push )
#pragma pack( 1 )
struct SJoy
{
	uint8_t  flags;
	uint16_t value[2];
};
#pragma pack( pop )

typedef struct SJoy TJoy;

void initJoy( void );
void joystick( TJoy * joy );

#endif





