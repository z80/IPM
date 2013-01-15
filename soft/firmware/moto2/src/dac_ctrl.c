
#include "dac_ctrl.h"
#include "ch.h"
#include "hal.h"
#include "hdw_config.h"

static void delay( void )
{
    static volatile uint16_t i;
    for ( i=0; i<256; i++ );
        //volatile asm( "nop;" );
}

void dacInit( void )
{
    palSetPadMode( DAC_PORT, DAC_SCLK, PAL_MODE_OUTPUT_PUSHPULL );
    palSetPadMode( DAC_PORT, DAC_DIN,  PAL_MODE_OUTPUT_PUSHPULL );
    palSetPadMode( DAC_CS_PORT_0, DAC_CS_PAD_0, PAL_MODE_OUTPUT_PUSHPULL );
    palSetPadMode( DAC_CS_PORT_1, DAC_CS_PAD_1, PAL_MODE_OUTPUT_PUSHPULL );
    palSetPadMode( DAC_CS_PORT_2, DAC_CS_PAD_2, PAL_MODE_OUTPUT_PUSHPULL );
    palClearPad( DAC_PORT, DAC_SCLK );
    palClearPad( DAC_PORT, DAC_DIN  );
    palSetPad( DAC_CS_PORT_0, DAC_CS_PAD_0 );
    palSetPad( DAC_CS_PORT_1, DAC_CS_PAD_1 );
    palSetPad( DAC_CS_PORT_2, DAC_CS_PAD_2 );
}

void dacSet( uint8_t index, uint8_t value )
{
    GPIO_TypeDef * port;
    uint16_t pad;
    switch ( index )
    {
    case 0:
        port = DAC_CS_PORT_0;
        pad  = DAC_CS_PAD_0;
        break;
    case 1:
        port = DAC_CS_PORT_1;
        pad  = DAC_CS_PAD_1;
        break;
    default:
        port = DAC_CS_PORT_2;
        pad  = DAC_CS_PAD_2;
        break;
    }
    // CS low.
    palClearPad( port, pad );
    static int8_t i;
    static uint16_t v;
    v = ( ( (uint16_t)value ) << 4 );
    delay();
    for ( i = 15; i>=0; i-- )
    {
        // CLK high.
        palSetPad( DAC_PORT, DAC_SCLK );
        // Set DIN.
        if ( (1<<i) & v )
            palSetPad( DAC_PORT, DAC_DIN );
        else
            palClearPad( DAC_PORT, DAC_DIN );
        delay();
        // CLK low.
        palClearPad( DAC_PORT, DAC_SCLK );
        delay();
    }
    delay();
    // CS high.
    palSetPad( port, pad );
}





