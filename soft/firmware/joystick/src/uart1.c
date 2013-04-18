
#include "uart1.h"
#include "lpc2148.h"

void initUart1( uint32_t osc, uint32_t baud )
{
    uint32_t ulDivisor;
    uint32_t ulWantedClock;

    #define PINSEL0_P08_MASK (3<<16)
    #define PINSEL0_P09_MASK (3<<18)
    #define PINSEL0_P08_TXD1 (1<<16)
    #define PINSEL0_P09_RXD1 (1<<18)

    PINSEL0 = (PINSEL0 & ~(PINSEL0_P08_MASK | PINSEL0_P09_MASK)) | (PINSEL0_P08_TXD1 | PINSEL0_P09_RXD1);

    #define PCONP_PCUART1 (1<<4)
    PCONP |= PCONP_PCUART1;

    //
    //  Setup the baud rate:  Calculate the divisor value
    //
    #define serWANTED_CLOCK_SCALING   ((uint32_t) 16)
    ulWantedClock = baud * serWANTED_CLOCK_SCALING;
    ulDivisor = osc / ulWantedClock;

    //
    //  Set the DLAB bit so we can access the divisor
    //
    #define LCR_DLAB (1<<7)
    U1LCR |= LCR_DLAB;

    //
    //  Setup the divisor
    //
    U1DLL = (uint8_t) (ulDivisor & (uint32_t) 0xff);
    ulDivisor >>= 8;
    U1DLM = (uint8_t) (ulDivisor & (uint32_t) 0xff);

    U1LCR &= (~LCR_DLAB);
    //
    //  Turn on the FIFO's and clear the buffers
    //
    #define FCR_EN  (1)
    #define FCR_CLR (2 | 4)
    U1FCR = FCR_EN | FCR_CLR;

    //
    //  Setup transmission format
    //
    #define LCR_NOPAR (0)
    #define LCR_1STOP (0)
    #define LCR_8BITS (3)
    U1LCR = LCR_NOPAR | LCR_1STOP | LCR_8BITS;

    //
    //  Setup the VIC for the UART
    //
    //VIC_IntSelect &= ~VIC_IntSelect_UART1;
    //VIC_VectAddr3 = (portLONG) uart1ISR;
    //VIC_VectCntl3 = VIC_VectCntl_ENABLE | VIC_Channel_UART1;
    //VIC_IntEnable = VIC_IntEnable_UART1;

    //
    //  Enable UART0 interrupts//
    //
    //U1IER |= UART_IER_EI;
    U1IER = 0;
}

int32_t sendUart1( uint8_t * data, int sz )
{
    int i;
    for ( i=0; i<sz; i++ )
        U1THR = data[i];
    return sz;
}

int32_t receiveUart1( uint8_t * data, int sz )
{
    #define LSR_RDR (1)
    int i=0;
    while ( U1LSR & LSR_RDR )
    {
        data[i++] = U1RBR;
        if ( i >= sz )
            break;
    }
    return i;
}



