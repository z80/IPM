
#ifndef __HDW_CONFIG_H_
#define __HDW_CONFIG_H_

// LEDs
#define LED_PORT   GPIOB
#define LED_0_PIN  14
#define LED_1_PIN  13
#define LED_2_PIN  12

// ADDRs - pins for identifying board index. It is defined by external physical switches.
#define ADDR_PORT  GPIOC
#define ADDR_0_PIN 15
#define ADDR_1_PIN 14
#define ADDR_2_PIN 13

// OUTs
#define OUT_PORT    GPIOA
#define OUT_EN_PIN  4
#define OUT_MR_PIN  6
#define OUT_CP_PIN  5
#define OUT_DSA_PIN 7

// INs
#define IN_PORT     GPIOA
#define IN_PL_PIN   0
#define IN_CE_PIN   1
#define IN_CP_PIN   2
#define IN_Q7_PIN   3

// I2C
#define I2C_BASE_ADDR       1
#define I2C_SLAVES_CNT      2
#define I2C_PORT            GPIOC
#define I2C_SCL_PAD         6
#define I2C_SDA_PAD         7
// Generic I2C io
#define I2C_OUT_BUF_SZ      13
#define I2C_IN_BUF_SZ       13
// Timeouts
#define I2C_QUERY_PERIOD_MS 10
#define I2C_IO_TIMEOUT_MS   20

#endif


