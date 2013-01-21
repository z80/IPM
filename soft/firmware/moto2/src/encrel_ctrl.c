
#include "encrel_ctrl.h"

#include "ch.h"
#include "hal.h"
#include "hdw_config.h"

static int32_t value1 = 0;
static int32_t value2 = 0;

//     -> value increase direction
// A: 0110
// B: 0011

static void extcb1( EXTDriver *extp, expchannel_t channel )
{
    (void)extp;
    (void)channel;
    static uint8_t a, b;
    a = palReadPad( ENCREL_A1_PORT, ENCREL_A1_PIN );
    b = palReadPad( ENCREL_B1_PORT, ENCREL_B1_PIN );
    if ( a )
    {
        if ( b )
            value1 -= 1;
        else
            value1 += 1;
    }
    else
    {
        if ( b )
            value1 += 1;
        else
            value1 -= 1;
    }
}

static void extcb2( EXTDriver *extp, expchannel_t channel )
{
    (void)extp;
    (void)channel;
    static uint8_t a, b;
    a = palReadPad( ENCREL_A2_PORT, ENCREL_A2_PIN );
    b = palReadPad( ENCREL_B2_PORT, ENCREL_B2_PIN );
    if ( a )
    {
        if ( b )
            value2 -= 1;
        else
            value2 += 1;
    }
    else
    {
        if ( b )
            value2 += 1;
        else
            value2 -= 1;
    }
}

static const EXTConfig extcfg = {
  {
   {EXT_CH_MODE_BOTH_EDGES | EXT_CH_MODE_AUTOSTART, extcb1},
   {EXT_CH_MODE_BOTH_EDGES | EXT_CH_MODE_AUTOSTART, extcb1},
   {EXT_CH_MODE_DISABLED, NULL},
   {EXT_CH_MODE_DISABLED, NULL},
   {EXT_CH_MODE_DISABLED, NULL},
   {EXT_CH_MODE_DISABLED, NULL},
   {EXT_CH_MODE_DISABLED, NULL},
   {EXT_CH_MODE_DISABLED, NULL},
   {EXT_CH_MODE_BOTH_EDGES | EXT_CH_MODE_AUTOSTART, extcb2},
   {EXT_CH_MODE_BOTH_EDGES | EXT_CH_MODE_AUTOSTART, extcb2},
   {EXT_CH_MODE_DISABLED, NULL},
   {EXT_CH_MODE_DISABLED, NULL},
   {EXT_CH_MODE_DISABLED, NULL},
   {EXT_CH_MODE_DISABLED, NULL},
   {EXT_CH_MODE_DISABLED, NULL},
   {EXT_CH_MODE_DISABLED, NULL},
  },
  EXT_MODE_EXTI(EXT_MODE_GPIOB,
                EXT_MODE_GPIOB,
                0,
                0,
                0,
                0,
                0,
                0,
                EXT_MODE_GPIOB,
                EXT_MODE_GPIOB,
                0,
                0,
                0,
                0,
                0,
                0)
};


void encrelInit( void )
{
    extStart( &EXTD1, &extcfg );
}

void encrelSet( uint8_t index, int32_t value )
{
    if ( index == 0 )
    {
        chSysLock();
            value1 = value;
        chSysUnlock();
    }
    else
    {
        chSysLock();
            value2 = value;
        chSysUnlock();
    }
}

int32_t encrel( uint8_t index )
{
    static int32_t v;
    if ( index == 0 )
    {
        chSysLock();
            v = value1;
        chSysUnlock();
    }
    else
    {
        chSysLock();
            v = value2;
        chSysUnlock();
    }
    return v;
}




