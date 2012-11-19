
/**  
  ******************************************************************************  
  * @file DMAUseExample/src/Driver.c   
  * @author  MCD Application Team  
  * @version  V3.0.0  
  * @date  04/27/2009  
  * @brief  Contains the I2C read and write routines and I2C  
  *                      DMA Channels configurations.  
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
   
/* Includes ------------------------------------------------------------------*/   
#include "driver.h"   
   
   
/** @addtogroup DMAUseExample  
  * @{  
  */    
   
   
/* Private typedef -----------------------------------------------------------*/   
/* Private define ------------------------------------------------------------*/   
/* Private macro -------------------------------------------------------------*/   
/* Private variables ---------------------------------------------------------*/   
DMA_InitTypeDef    DMA_InitStructure;   
/* Private function prototypes -----------------------------------------------*/   
/* Private functions ---------------------------------------------------------*/   
   
   
/**  
  * @brief  Reads buffer of bytes  from the slave.  
  * @param pBuffer: Buffer of bytes to read from the slave.  
  * @param NumByteToRead: Number of bytes to be read by the Master.  
  * @retval : None.  
  */   
void I2C_Master_BufferRead(uint8_t* pBuffer,  uint16_t NumByteToRead)   
   
{   
   
#ifdef DMA_Master_Receive   
   
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)pBuffer;   
    DMA_InitStructure.DMA_BufferSize = NumByteToRead;   
    DMA_Init(DMA1_Channel7, &DMA_InitStructure);   
    I2C_ITConfig(I2C1, I2C_IT_EVT, ENABLE);   
    /* Set Last bit to have a NACK on the last received byte */   
    I2C_DMALastTransferCmd(I2C1, ENABLE);   
    I2C_DMACmd(I2C1, ENABLE);   
    /* Enable the DMA Channel7 Transfer Complete IT */   
    DMA_ITConfig(DMA1_Channel7, DMA_IT_TC, ENABLE);   
    /* Generate the START */   
    I2C_GenerateSTART(I2C1, ENABLE);   
   
#endif   
   
#ifdef  Polling_Master_Receive   
   
    /* Send START condition */   
    I2C_GenerateSTART(I2C1, ENABLE);   
    /* Test on EV5 and clear it */   
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));   
    /* Send slave address for read */   
    I2C_Send7bitAddress(I2C1,  SLAVE_ADDRESS, I2C_Direction_Receiver);   
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));   
    /* While there is data to be read; here the safe procedure is implemented */   
    while (NumByteToRead)   
    {   
   
        if (NumByteToRead != 3) /* Receive bytes from first byte until byte N-3 */   
        {   
            while ((I2C_GetLastEvent(I2C1) & 0x00004) != 0x000004); /* Poll on BTF */   
            /* Read data */   
            *pBuffer = I2C_ReceiveData(I2C1);   
            pBuffer++;   
            /* Decrement the read bytes counter */   
            NumByteToRead--;   
        }   
   
        if (NumByteToRead == 3)  /* it remains to read three data: data N-2, data N-1, Data N */   
        {   
   
            /* Data N-2 in DR and data N -1 in shift register */   
            while ((I2C_GetLastEvent(I2C1) & 0x000004) != 0x0000004); /* Poll on BTF */   
            /* Clear ACK */   
            I2C_AcknowledgeConfig(I2C1, DISABLE);   
            __disable_irq();   
            /* Read Data N-2 */   
            *pBuffer = I2C_ReceiveData(I2C1);   
            pBuffer++;   
            /* Program the STOP */   
            I2C_GenerateSTOP(I2C1, ENABLE);   
            /* Read DataN-1 */   
            *pBuffer = I2C_ReceiveData(I2C1);   
             __enable_irq();   
            pBuffer++;   
            while ((I2C_GetLastEvent(I2C1) & 0x00000040) != 0x0000040); /* Poll on RxNE */   
            /* Read DataN */   
            *pBuffer = I2C1->DR;   
            /* Reset the number of bytes to be read by master */   
            NumByteToRead = 0;   
   
        }   
    }   
    /* Make sure that the STOP bit is cleared by Hardware before CR1 write access */   
    while ((I2C1->CR1&0x200) == 0x200);   
    /* Enable Acknowledgement to be ready for another reception */   
    I2C_AcknowledgeConfig(I2C1, ENABLE);   
   
   
#endif   
   
}   
   
   
   
/**  
  * @brief  Send a buffer of bytes to the slave.  
  * @param pBuffer: Buffer of bytes to be sent to the slave.  
  * @param NumByteToRead: Number of bytes to be sent to the slave.  
  * @retval : None.  
  */   
void I2C_Master_BufferWrite(uint8_t* pBuffer,  uint16_t NumByteToWrite)   
   
{   
   
#ifdef DMA_Master_Transmit   
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)pBuffer;   
    DMA_InitStructure.DMA_BufferSize = NumByteToWrite;   
    DMA_Init(DMA1_Channel6, &DMA_InitStructure);   
    I2C_ITConfig(I2C1, I2C_IT_EVT, ENABLE);   
    I2C_DMACmd(I2C1, ENABLE);   
    I2C_GenerateSTART(I2C1, ENABLE);   
    DMA_ITConfig(DMA1_Channel6, DMA_IT_TC, ENABLE);   
#endif   
   
   
#ifdef Polling_Master_Transmit   
   
    /* Send START condition */   
    I2C_GenerateSTART(I2C1, ENABLE);   
    /* Test on EV5 and clear it */   
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));   
    /* Send slave address for write */   
    I2C_Send7bitAddress(I2C1,SLAVE_ADDRESS, I2C_Direction_Transmitter);   
    /* Test on EV6 and clear it */   
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));   
    I2C_SendData(I2C1, *pBuffer);   
    pBuffer++;   
    NumByteToWrite--;   
    /* While there is data to be written */   
    while (NumByteToWrite--)   
    {   
        while ((I2C_GetLastEvent(I2C1) & 0x04) != 0x04);  /* Poll on BTF */   
        /* Send the current byte */   
        I2C_SendData(I2C1, *pBuffer);   
        /* Point to the next byte to be written */   
        pBuffer++;   
   
    }   
   
    /* Test on EV8_2 and clear it, BTF = TxE = 1, DR and shift registers are  
     empty */   
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));   
    /* Send STOP condition */   
    I2C_GenerateSTOP(I2C1, ENABLE);   
   
#endif   
   
}   
   
   
   
/**  
  * @brief  Read a byte from the slave.  
  * @param ne.  
  * @retval : The read data byte.  
  */   
uint8_t I2C_Master_BufferRead1Byte(void)   
{   
    uint8_t Data;   
    __IO uint32_t temp;   
    /* Send START condition */   
    I2C_GenerateSTART(I2C1, ENABLE);   
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));   
    /* Send EEPROM address for read */   
    I2C_Send7bitAddress(I2C1, SLAVE_ADDRESS, I2C_Direction_Receiver);   
    /* Wait until ADDR is set */   
    while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_ADDR));   
    /* Clear ACK */   
    I2C_AcknowledgeConfig(I2C1, DISABLE);   
    __disable_irq();   
    /* Clear ADDR flag */   
    temp = I2C1->SR2;   
    /* Program the STOP */   
    I2C_GenerateSTOP(I2C1, ENABLE);   
    __enable_irq();   
    while ((I2C_GetLastEvent(I2C1) & 0x0040) != 0x000040); /* Poll on RxNE */   
    /* Read the data */   
    Data = I2C_ReceiveData(I2C1);   
    /* Make sure that the STOP bit is cleared by Hardware before CR1 write access */   
    while ((I2C1->CR1&0x200) == 0x200);   
    /* Enable Acknowledgement to be ready for another reception */   
    I2C_AcknowledgeConfig(I2C1, ENABLE);   
   
    return(Data);   
   
}   
   
   
   
/**  
  * @brief  Read 2 data from the slave using Polling.  
  * @param pBuffer : Buffer of bytes read from the slave.  
  * @retval : None  
  */   
void I2C_Master_BufferRead2Byte(uint8_t* pBuffer)   
{   
   
    __IO uint32_t temp;   
    /* Send START condition */   
    I2C_GenerateSTART(I2C1, ENABLE);   
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));   
    /* Send EEPROM address for read */   
    I2C_Send7bitAddress(I2C1, SLAVE_ADDRESS, I2C_Direction_Receiver);   
    I2C1->CR1 = 0xC01; /* ACK=1; POS =1 */   
    while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_ADDR));   
    __disable_irq();   
    /* Clear ADDR */   
    temp = I2C1->SR2;   
    /* Disable ACK */   
    I2C_AcknowledgeConfig(I2C1, DISABLE);   
    __enable_irq();   
    while ((I2C_GetLastEvent(I2C1) & 0x0004) != 0x00004); /* Poll on BTF */   
     __disable_irq();   
    /* Program the STOP */   
    I2C_GenerateSTOP(I2C1, ENABLE);   
    /* Read first data */   
    *pBuffer = I2C1->DR;   
    pBuffer++;   
    /* Read second data */   
    *pBuffer = I2C1->DR;   
    __enable_irq();   
    I2C1->CR1 = 0x0401; /* POS = 0, ACK = 1, PE = 1 */   
}   
   
   
   
/**  
  * @brief  Reads a buffer byte from the master.  
  * @param pBuffer: buffer where data will be read.  
  * @param NumByteToRead: number of bytes to be read from master.  
  * @retval : None.  
  */   
void I2C_Slave_BufferRead(uint8_t* pBuffer,  uint16_t NumByteToRead)   
{   
#ifdef DMA_Slave_Receive   
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)pBuffer;   
    DMA_InitStructure.DMA_BufferSize = NumByteToRead;   
    DMA_Init(DMA1_Channel5, &DMA_InitStructure);   
    I2C_ITConfig(I2C2, I2C_IT_EVT , ENABLE); /* Needed for the ADDR event IT */   
#endif   
}   
   
   
   
/**  
  * @brief  Writes a buffer of bytes into the master.  
  * @param pBuffer: buffer of data to be written.  
  * @param NumByteToRead: number of bytes to be written.  
  * @retval : None.  
  */   
void I2C_Slave_BufferWrite(uint8_t* pBuffer,  uint16_t NumByteToWrite)   
   
{   
#ifdef DMA_Slave_Transmit   
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)pBuffer;   
    DMA_InitStructure.DMA_BufferSize = NumByteToWrite;   
    DMA_Init(DMA1_Channel4, &DMA_InitStructure);   
    I2C_ITConfig(I2C2, I2C_IT_EVT , ENABLE); /* Needed for the ADDR event IT */   
#endif   
   
}   
   
   
   
   
/**  
  * @brief  Configures the DMA1 Channel7 for I2C1 Reception.  
  * @param ne.  
  * @retval : None.  
  */   
void DMA_Channel7_Configuration (void)   
{   
    DMA_DeInit(DMA1_Channel7);   
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)I2C1_DR_Address;   
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;   
    DMA_InitStructure.DMA_BufferSize = 255; /* Just for initialization */   
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;   
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;   
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_MemoryDataSize_Byte;   
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;   
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;   
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;   
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;   
    DMA_Init(DMA1_Channel7, &DMA_InitStructure);   
   
}   
   
   
   
/**  
  * @brief  Configures the DMA1 Channel6 for I2C1 Transmission.  
  * @param  None  
  * @retval : None  
  */   
   
void DMA_Channel6_Configuration (void)   
{   
    DMA_DeInit(DMA1_Channel6);   
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)I2C1_DR_Address;   
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;   
    DMA_InitStructure.DMA_BufferSize = 255; /* Just for initialization */   
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;   
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;   
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_MemoryDataSize_Byte;   
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;   
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;   
    DMA_InitStructure.DMA_Priority =  DMA_Priority_VeryHigh;   
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;   
    DMA_Init(DMA1_Channel6, &DMA_InitStructure);   
   
}   
   
   
   
   
/**  
  * @brief  Configures the DMA1 Channel4 for I2C2 Transmission.  
  * @param  None  
  * @retval : None  
  */   
void DMA_Channel4_Configuration (void)   
{   
    DMA_DeInit(DMA1_Channel4);   
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)I2C2_DR_Address;   
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;     
    DMA_InitStructure.DMA_BufferSize = 255;  /* Just for initialization */   
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;   
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;   
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_MemoryDataSize_Byte;   
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;   
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;   
    DMA_InitStructure.DMA_Priority =  DMA_Priority_VeryHigh ;   
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;   
    DMA_Init(DMA1_Channel4, &DMA_InitStructure);   
}   
   
   
   
/**  
  * @brief  Configures the DMA1 Channel5 for I2C2 Reception.  
  * @param  None  
  * @retval : None  
  */   
   
void DMA_Channel5_Configuration (void)   
{   
    DMA_DeInit(DMA1_Channel5);   
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)I2C2_DR_Address;   
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;   
    DMA_InitStructure.DMA_BufferSize = 255;   /* Just for initialization */   
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;   
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;   
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_MemoryDataSize_Byte;   
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;   
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;   
    DMA_InitStructure.DMA_Priority =  DMA_Priority_VeryHigh;   
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;   
    DMA_Init(DMA1_Channel5, &DMA_InitStructure);   
   
}   
   
   
   
   
   
   
   
   
/**  
  * @}  
  */    
   
   
/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/  
