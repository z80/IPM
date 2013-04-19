
#include "joystick_ctrl.h"
#include "lpc2148.h"

#define JOY_PORT1    IOPORT1
#define JOY_PORT2    IOPORT2

#define AXIS_X_1    28
#define AXIS_Y_1    29
#define NULL_X_1    16
#define NULL_Y_1    17
#define TOTMANN_1   4

#define AXIS_X_2    30
#define AXIS_Y_2    25
#define NULL_X_2    18
#define NULL_Y_2    19
#define TOTMANN_2   5

#define AXIS_X_3    12
#define AXIS_Y_3    13
#define NULL_X_3    20
#define NULL_Y_3    21
#define TOTMANN_3   6

#define AXIS_X_4    15
#define AXIS_Y_4    21
#define NULL_X_4    22
#define NULL_Y_4    23
#define TOTMANN_4   7

#define STOP_BTN    16

// PINSELs for joysticks.
#define P0_4_MSK    (3<<8)
#define P0_5_MSK    (3<<10)
#define P0_6_MSK    (3<<12)
#define P0_7_MSK    (3<<14)

#define P0_12_MSK   (3<<24)
#define P0_12_ADC   (3<<24)
#define P0_13_MSK   (3<<26)
#define P0_13_ADC   (3<<26)
#define P0_15_MSK   (3<<30)
#define P0_15_ADC   (3<<30)

#define P0_16_MSK   (3)

#define P0_21_MSK   (3<<10)
#define P0_21_ADC   (2<<10)
#define P0_25_MSK   (3<<18)
#define P0_25_ADC   (1<<18)
#define P0_28_MSK   (3<<24)
#define P0_28_ADC   (1<<24)
#define P0_29_MSK   (3<<26)
#define P0_29_ADC   (1<<26)
#define P0_30_MSK   (3<<28)
#define P0_30_ADC   (1<<28)

#define P1_16_MSK
#define P1_17_MSK
#define P1_18_MSK
#define P1_19_MSK
#define P1_20_MSK
#define P1_21_MSK
#define P1_22_MSK
#define P1_23_MSK





#define JOY_CNT             4

static void adcInit( void );
static void adcRead( TJoy * j );

void initJoy( void )
{
    PINSEL0 &= ~( P0_4_MSK |
                  P0_5_MSK |
                  P0_6_MSK |
                  P0_7_MSK |
                  P0_12_MSK |
                  P0_13_MSK |
                  P0_15_MSK );

    PINSEL1 &= ~( P0_21_MSK |
                  P0_25_MSK |
                  P0_28_MSK |
                  P0_29_MSK |
                  P0_30_MSK );

    PINSEL0 |= ( P0_12_ADC |
                 P0_13_ADC |
                 P0_15_ADC );

    PINSEL1 |= ( P0_21_ADC |
                 P0_25_ADC |
                 P0_28_ADC |
                 P0_29_ADC |
                 P0_30_ADC );

    IODIR0 &= ~( (1<<4) | (1<<5) |
                 (1<<6) | (1<<7) |
                 (1<<16) );
    IODIR1 &= ~( (1<<16) | (1<<17) |
                 (1<<18) | (1<<19) |
                 (1<<20) | (1<<21) |
                 (1<<22) | (1<<23) );

    adcInit();
}

void joystick( TJoy * j )
{
    j[0].flags = ( ( IOPIN1 & (1<<16) ) ? NULL_X_BIT : 0 ) +
                 ( ( IOPIN1 & (1<<17) ) ? NULL_Y_BIT : 0 ) +
                 ( ( IOPIN0 & (1<<4) )  ? TOTMANN_BIT : 0 );
    j[1].flags = ( ( IOPIN1 & (1<<18) ) ? NULL_X_BIT : 0 ) +
                 ( ( IOPIN1 & (1<<19) ) ? NULL_Y_BIT : 0 ) +
                 ( ( IOPIN0 & (1<<5) )  ? TOTMANN_BIT : 0 );
    j[2].flags = ( ( IOPIN1 & (1<<20) ) ? NULL_X_BIT : 0 ) +
                 ( ( IOPIN1 & (1<<21) ) ? NULL_Y_BIT : 0 ) +
                 ( ( IOPIN0 & (1<<6) )  ? TOTMANN_BIT : 0 );
    j[3].flags = ( ( IOPIN1 & (1<<22) ) ? NULL_X_BIT : 0 ) +
                 ( ( IOPIN1 & (1<<23) ) ? NULL_Y_BIT : 0 ) +
                 ( ( IOPIN0 & (1<<7) )  ? TOTMANN_BIT : 0 );

    adcRead( j );
}




















#define PCAD0   (1<<12)
#define PCAD1   (1<<20)

// PINSEL1
#define MSK0_1  ( 3 << 24 )
#define AD0_1   ( 1 << 24 )

#define MSK0_2  ( 3 << 26 )
#define AD0_2   ( 1 << 26 )

#define MSK0_3  ( 3 << 28 )
#define AD0_3   ( 1 << 28 )

#define MSK0_4  ( 3 << 18 )
#define AD0_4   ( 1 << 18 )

// PINSEL0
#define MSK1_3  ( 3 << 24 )
#define AD1_3   ( 3 << 24 )

#define MSK1_4  ( 3 << 26 )
#define AD1_4   ( 3 << 26 )

#define MSK1_5  ( 3 << 30 )
#define AD1_5   ( 3 << 30 )
// PINSEL1
#define MSK1_6  ( 3 << 10 )
#define AD1_6   ( 2 << 10 )

// ADC bits
// ADxCR register
// SEL      7:0
#define     AD_CR_SEL0   (1<<0)
#define     AD_CR_SEL1   (1<<1)
#define     AD_CR_SEL2   (1<<2)
#define     AD_CR_SEL3   (1<<3)
#define     AD_CR_SEL4   (1<<4)
#define     AD_CR_SEL5   (1<<5)
#define     AD_CR_SEL6   (1<<6)
#define     AD_CR_SEL7   (1<<7)
// CLKDIV   15:8
#define     AD_CR_CLKDIV 8
// BURST    16
// CLKS     19:17
#define     AD_CR_CLKS   17
// PDN      21
#define     AD_CR_PDN    (1<<21)
// START    26:24
#define     AD_CR_START  24
#define     AD_CR_START_NOW (1<<24)
// EDGE     27

// ADxDRx
// RESULT   15:6
#define     AD_DR_RESULTSHIFT 6
#define     AD_DR_RESULTMASK  (1023<<6)
// OVERRUN  30
// DONE     31
#define     AD_DR_DONE   (1<<31)

static void adcInit( void )
{
  // Enable power for ADC1
  PCONP |= ( PCAD0 | PCAD1 );

  // Make sure P0.28 and 0.29 are set to GPIO (just in case)
  // They are used to toggle between GND and 'floating'
  PINSEL1 &= ~( MSK0_1 | MSK0_2 | MSK0_3 | MSK0_4 | MSK1_6 );
  PINSEL1 |= AD0_1 | AD0_2 | AD0_3 | AD0_4 | AD1_6;

  PINSEL0 &= ~( MSK1_3 | MSK1_4 | MSK1_5 );
  PINSEL0 |= AD1_3 | AD1_4 | AD1_5;

  // Initialise ADC converters (using 12MHz PCLK)
  AD0CR = AD_CR_PDN                    // Exit power-down mode
          | ((3 - 1) << AD_CR_CLKS)    // 4.0MHz Clock (12.0MHz / 3)
          | AD_CR_SEL1 | AD_CR_SEL2 |
            AD_CR_SEL3 | AD_CR_SEL4;   // Use channel 6 and 7

  AD1CR = AD_CR_PDN                    // Exit power-down mode
          | ((3 - 1) << AD_CR_CLKS)    // 4.0MHz Clock (12.0MHz / 3)
          | AD_CR_SEL3 | AD_CR_SEL4 |
            AD_CR_SEL5 | AD_CR_SEL6;   // Use channel 6 and 7
}

// Read the current X position using ADC1.6
static void adcRead( TJoy * j )
{
    // Start AD conversion
    AD0CR |= AD_CR_START_NOW;
    AD1CR |= AD_CR_START_NOW;

    /*
    // Wait for the conversion to complete
    while ( (!( AD0DR4 & AD_DR_DONE )) ||
            (!( AD0DR3 & AD_DR_DONE )) ||
            (!( AD0DR2 & AD_DR_DONE )) ||
            (!( AD0DR1 & AD_DR_DONE )) ||
            (!( AD1DR6 & AD_DR_DONE )) ||
            (!( AD1DR5 & AD_DR_DONE )) ||
            (!( AD1DR4 & AD_DR_DONE )) ||
            (!( AD1DR3 & AD_DR_DONE )) )
        continue;
    */

    // Return the processed results
    j[0].value[0] = (AD0DR1 & AD_DR_RESULTMASK) >> AD_DR_RESULTSHIFT;
    j[0].value[1] = (AD0DR2 & AD_DR_RESULTMASK) >> AD_DR_RESULTSHIFT;

    j[1].value[0] = (AD0DR3 & AD_DR_RESULTMASK) >> AD_DR_RESULTSHIFT;
    j[1].value[1] = (AD0DR4 & AD_DR_RESULTMASK) >> AD_DR_RESULTSHIFT;

    j[2].value[0] = (AD1DR3 & AD_DR_RESULTMASK) >> AD_DR_RESULTSHIFT;
    j[2].value[1] = (AD1DR4 & AD_DR_RESULTMASK) >> AD_DR_RESULTSHIFT;

    j[3].value[0] = (AD1DR5 & AD_DR_RESULTMASK) >> AD_DR_RESULTSHIFT;
    j[3].value[1] = (AD1DR5 & AD_DR_RESULTMASK) >> AD_DR_RESULTSHIFT;
}


/*
// Initialise ADC Converter 0, Channel 3
void adcInit0_3(void)
{
    // Force pin 0.30 to function as AD0.3
    PCB_PINSEL1 = (PCB_PINSEL1 & ~( PCB_PINSEL1_P012_MASK |
                                    PCB_PINSEL1_P013_MASK |
                                    PCB_PINSEL1_P015_MASK |
                                    PCB_PINSEL1_P021_MASK |
                                    PCB_PINSEL1_P025_MASK |
                                    PCB_PINSEL1_P028_MASK |
                                    PCB_PINSEL1_P029_MASK |
                                    PCB_PINSEL1_P030_MASK  ) ) | PCB_PINSEL1_P030_AD03;

    // Enable power for ADC0
    SCB_PCONP |= SCB_PCONP_PCAD0 | SCB_PCONP_PCAD1;

    // Initialise ADC converter
    AD0_CR = AD_CR_CLKS10                   // 10-bit precision
           | AD_CR_PDN                      // Exit power-down mode
           | ((3 - 1) << AD_CR_CLKDIVSHIFT) // 4.0MHz Clock (12.0MHz / 3)
           | AD_CR_SEL3;                    // Use channel 3
}

// Read the current value of ADC0.3
int adcRead0_3(void)
{
    // Deselect all channels and stop all conversions
    AD0_CR &= ~(AD_CR_START_MASK | AD_CR_SELMASK);
    // Select channel 3
    AD0_CR |=  (AD_CR_START_NONE | AD_CR_SEL3);
    // Manually start conversions (rather than waiting on an external input)
    AD0_CR |=   AD_CR_START_NOW;

    // Wait for the conversion to complete
    while (!(AD0_DR3 & AD_DR_DONE))
    ;

    // Return the processed results
    return ( ( AD0_DR3 & AD_DR_RESULTMASK) >> AD_DR_RESULTSHIFT );
}
*/


