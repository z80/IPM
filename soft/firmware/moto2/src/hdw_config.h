
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
#define I2C_TIMEOUT     250   // Timeout for I2C to admit there was no transaction from BUS master.
#define I2C_BASE_ADDR   10
#define I2C_PORT        GPIOC
#define I2C_SCL_PAD     6
#define I2C_SDA_PAD     7
// Commands
#define I2C_CMD_IDLE    0
#define I2C_CMD_DAC1    1  // Set ESCON DAC
#define I2C_CMD_DAC2    2  // The same
#define I2C_CMD_ENC1    3  // Set inc. encoder's value
#define I2C_CMD_ENC2    4  // The same
#define I2C_CMD_BMSD    5  // BMSD 5 bytes command
#define I2C_CMD_LEDS    6  // Just debug LEDs control.
#define I2C_OUT_BUFFER_SZ   (4*3+1) // 3 encoders and one status byte.
#define I2C_IN_BUFFER_SZ    6       // 1 byte - command Id. Up to 5 bytes per command. Max command - BMSD command.

// Exec thread
#define EXEC_QUEUE_SIZE     5 // 3 encoders and one status byte.

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
#define BMSD_TIMEOUT    500

// Encoder absolute
#define ENCABS_BITS      13
#define ENCABS_CLK_PORT  GPIOA
#define ENCABS_CLK_PIN   6
#define ENCABS_DATA_PORT GPIOA
#define ENCABS_DATA_PIN  7

// Encoder relative
#define ENCREL_A1_PORT  GPIOB
#define ENCREL_A1_PIN   0
#define ENCREL_B1_PORT  GPIOB
#define ENCREL_B1_PIN   1
#define ENCREL_A2_PORT  GPIOB
#define ENCREL_A2_PIN   8
#define ENCREL_B2_PORT  GPIOB
#define ENCREL_B2_PIN   9

#endif


