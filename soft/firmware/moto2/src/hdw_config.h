
#ifndef __HDW_CONFIG_H_
#define __HDW_CONFIG_H_

// LEDs
#define LED_PORT        GPIOB
#define LED_0           11
#define LED_1           10

// Address pins.
#define ADDR_PORT       GPIOB
#define ADDR_0          12
#define ADDR_1          13
#define ADDR_2          14

// I2C params
#define I2C_BASE_ADDR   64
#define I2C_PORT        GPIOC
#define I2C_SCL_PAD     6
#define I2C_SDA_PAD     7

// DAC params
#define DAC_PORT       GPIOA
#define DAC_SCLK       0
#define DAC_DIN        1
#define DAC_CS_PORT_0  GPIOC
#define DAC_CS_PAD_0   14
#define DAC_CS_PORT_1  GPIOC
#define DAC_CS_PAD_1   15
#define DAC_CS_PORT_2  GPIOC
#define DAC_CS_PAD_2   13

// BMSD params
#define BMSD_DIR_PORT   GPIOB
#define BMSD_DIR_PIN    15
#define BMSD_UART       UARTD2
#define BMSD_RX_TIMEOUT 128   // Timeout to wait for BMSD reply. If there is no reply continue without it.
#define BMSD_BAUD       9600

#endif


