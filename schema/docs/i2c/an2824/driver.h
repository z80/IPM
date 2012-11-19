/** 
  ****************************************************************************** 
  * @file DMAUseExample/inc/Driver.h  
  * @author  MCD Application Team 
  * @version  V3.0.0 
  * @date  04/27/2009 
  * @brief  Header for Driver.c 
  ****************************************************************************** 
  * @copy 
  * 
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS 
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE 
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY 
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING 
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE 
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS. 
  * 
  * <h2><center>© COPYRIGHT 2009 STMicroelectronics</center></h2> 
  */  
 
/* Define to prevent recursive inclusion -------------------------------------*/ 
#ifndef __DRIVER_H 
#define __DRIVER_H 
 
//#define DMA_Master_Transmit 
#define DMA_Master_Receive 
//#define DMA_Slave_Transmit                                                                                                                                                                      #define DMA_Slave_Receive 
//#define IT_Master_Transmit 
//#define IT_Master_Receive 
//#define IT_Slave_Receive 
//#define IT_Slave_Transmit 
//#define Polling_Master_Transmit 
//#define Polling_Master_Receive 
 
/* Includes ------------------------------------------------------------------*/ 
#include "stm32f10x.h" 
 
/* Exported types ------------------------------------------------------------*/ 
/* Exported constants --------------------------------------------------------*/ 
#define SLAVE_ADDRESS     0x28 
#define BufferSize            6 
#define ClockSpeed            400000 
#define I2C1_DR_Address    0x40005410 
#define I2C2_DR_Address    0x40005810 
/* Exported macro ------------------------------------------------------------*/ 
/* Exported functions ------------------------------------------------------- */ 
void I2C_Master_BufferRead(uint8_t* pBuffer,  uint16_t NumByteToRead); 
void I2C_Master_BufferWrite(uint8_t* pBuffer,  uint16_t NumByteToWrite); 
uint8_t I2C_Master_BufferRead1Byte(void); 
void I2C_Master_BufferRead2Byte(uint8_t* pBuffer); 
void I2C_Slave_BufferRead(uint8_t* pBuffer,  uint16_t NumByteToRead); 
void I2C_Slave_BufferWrite(uint8_t* pBuffer,  uint16_t NumByteToWrite); 
void DMA_Channel7_Configuration (void); 
void DMA_Channel6_Configuration (void); 
void DMA_Channel5_Configuration (void); 
void DMA_Channel4_Configuration (void); 
 
#endif 
 
/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/ 