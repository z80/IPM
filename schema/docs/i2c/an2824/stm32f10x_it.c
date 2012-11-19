
/**  
  ******************************************************************************  
  * @file DMAUseExample/src/stm32f10x_it.c   
  * @author  MCD Application Team  
  * @version  V3.0.0  
  * @date  04/27/2009  
  * @brief  Main Interrupt Service Routines.  
  *         This file provides template for all exceptions handler and   
  *         peripherals interrupt service routine.  
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
#include "stm32f10x_it.h"   
#include "main.h"   
   
   
/** @addtogroup DMAUseExample  
  * @{  
  */    
   
   
/* Private typedef -----------------------------------------------------------*/   
/* Private define ------------------------------------------------------------*/   
/* Private macro -------------------------------------------------------------*/   
/* Private macro -------------------------------------------------------------*/   
/* Private variables ---------------------------------------------------------*/   
extern uint8_t Slave_Buffer_Tx[];   
extern uint8_t Master_Buffer_Rx[];   
uint8_t slave = 0;   
extern uint16_t Buffer[];   
/* Private function prototypes -----------------------------------------------*/   
/* Private functions ---------------------------------------------------------*/   
   
/******************************************************************************/   
/*            Cortex-M3 Processor Exceptions Handlers                         */   
/******************************************************************************/   
   
/**  
  * @brief  This function handles NMI exception.  
  * @param  None  
  * @retval : None  
  */   
void NMI_Handler(void)   
{   
}   
   
/**  
  * @brief  This function handles Hard Fault exception.  
  * @param  None  
  * @retval : None  
  */   
void HardFault_Handler(void)   
{   
  /* Go to infinite loop when Hard Fault exception occurs */   
  while (1)   
  {   
  }   
}   
   
/**  
  * @brief  This function handles Memory Manage exception.  
  * @param  None  
  * @retval : None  
  */   
void MemManage_Handler(void)   
{   
  /* Go to infinite loop when Memory Manage exception occurs */   
  while (1)   
  {   
  }   
}   
   
/**  
  * @brief  This function handles Bus Fault exception.  
  * @param  None  
  * @retval : None  
  */   
void BusFault_Handler(void)   
{   
  /* Go to infinite loop when Bus Fault exception occurs */   
  while (1)   
  {   
  }   
}   
   
/**  
  * @brief  This function handles Usage Fault exception.  
  * @param  None  
  * @retval : None  
  */   
void UsageFault_Handler(void)   
{   
  /* Go to infinite loop when Usage Fault exception occurs */   
  while (1)   
  {   
  }   
}   
   
/**  
  * @brief  This function handles SVCall exception.  
  * @param  None  
  * @retval : None  
  */   
void SVC_Handler(void)   
{   
}   
   
/**  
  * @brief  This function handles Debug Monitor exception.  
  * @param  None  
  * @retval : None  
  */   
void DebugMon_Handler(void)   
{   
}   
   
/**  
  * @brief  This function handles PendSVC exception.  
  * @param  None  
  * @retval : None  
  */   
void PendSV_Handler(void)   
{   
}   
   
/**  
  * @brief  This function handles SysTick Handler.  
  * @param  None  
  * @retval : None  
  */   
void SysTick_Handler(void)   
{   
}   
   
/******************************************************************************/   
/*                 STM32F10x Peripherals Interrupt Handlers                   */   
/*  Add here the Interrupt Handler for the used peripheral(s) (I2C), for the  */   
/*  available peripheral interrupt handler's name please refer to the startup */   
/*  file (startup_stm32f10x_xx.s).                                            */   
/******************************************************************************/   
   
/**  
  * @brief  This function handles TIM2 interrupt request.  
  * @param  None  
  * @retval : None  
  */   
void TIM2_IRQHandler(void)   
{   
   
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);   
    I2C_Master_BufferRead(Master_Buffer_Rx, 6);   
   
}   
   
/**  
  * @}  
  */    
   
/**  
  * @}  
  */    
   
   
/**  
  * @brief  This function handles DMA1_Channel7 interrupt request.  
  * @param  None  
  * @retval : None  
  */   
void DMA1_Channel7_IRQHandler(void)   
{   
   
    DMA_Cmd(DMA1_Channel7, DISABLE);   
    DMA_ClearFlag(DMA1_FLAG_TC7);   
    I2C_GenerateSTOP(I2C1, ENABLE);   
}   
   
   
   
/**  
  * @}  
  */    
   
/**  
  * @}  
  */    
   
   
/**  
  * @brief  This function handles I2C1 Event interrupt request.  
  * @param  None  
  * @retval : None  
  */   
void I2C1_EV_IRQHandler(void)   
{   
   
    switch (I2C_GetLastEvent(I2C1))   
    {   
    case I2C_EVENT_MASTER_MODE_SELECT:                 /* EV5 */   
#if defined (DMA_Master_Transmit) || defined (IT_Master_Transmit)   
        /* Master Transmitter ----------------------------------------------*/   
        /* Send slave Address for write */   
        I2C_Send7bitAddress(I2C1, SLAVE_ADDRESS, I2C_Direction_Transmitter);   
#endif   
#if defined(DMA_Master_Receive) || defined(IT_Master_Receive)   
        if (slave == 0)   
        {   
            /* Send slave Address for read */   
            I2C_Send7bitAddress(I2C1,0x28, I2C_Direction_Receiver);   
            slave = 1;   
        }   
   
        else if (slave ==1)   
        {   
            /* Send slave Address for read */   
            I2C_Send7bitAddress(I2C1, 0x30, I2C_Direction_Receiver);   
            slave = 0;   
        }   
#endif   
   
        break;   
   
   
   
        /* Master Receiver -------------------------------------------------------*/   
    case I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED:   
#ifdef DMA_Master_Receive   
        DMA_Cmd(DMA1_Channel7, ENABLE);   
#endif   
        break;   
   
    default:   
        break;   
    }   
   
   
   
   
   
}   
   
   
/**  
  * @}  
  */    
   
/**  
  * @}  
  */    
   
   
   
   
/**  
  * @brief  This function handles I2C1 Error interrupt request.  
  * @param  None  
  * @retval : None  
  */   
void I2C1_ER_IRQHandler(void)   
{   
    if (I2C_GetFlagStatus(I2C1, I2C_FLAG_AF))   
    {   
        I2C_ClearFlag(I2C1, I2C_FLAG_AF);   
   
    }   
   
    if (I2C_GetFlagStatus(I2C1, I2C_FLAG_BERR))   
    {   
        I2C_ClearFlag(I2C1, I2C_FLAG_BERR);   
   
    }   
    if (I2C_GetFlagStatus(I2C1, I2C_FLAG_OVR))   
    {   
        I2C_ClearFlag(I2C1, I2C_FLAG_OVR);   
   
    }   
   
    if (I2C_GetFlagStatus(I2C1, I2C_FLAG_ARLO))   
    {   
        I2C_ClearFlag(I2C1,I2C_FLAG_ARLO);   
   
    }   
   
}   
   
   
   
/**  
  * @}  
  */    
   
/**  
  * @}  
  */    
   
/**  
  * @brief  This function handles I2C2 Event interrupt request.  
  * @param  None  
  * @retval : None  
  */   
void I2C2_EV_IRQHandler(void)   
{   
#ifdef slave2   
    uint8_t  j=0;   
#endif   
   
#if defined(DMA_Slave_Transmit) || defined(DMA_Slave_Receive)   
    __IO uint32_t temp;   
    __IO int32_t temp1;   
   
    if (I2C_GetFlagStatus(I2C2, I2C_FLAG_ADDR))   
    {   
        DMA_Cmd(DMA1_Channel1, ENABLE);   
        ADC_SoftwareStartConvCmd(ADC1, ENABLE);   
        if (DMA1_Channel1->CNDTR == 0)   
        {   
            DMA_Cmd(DMA1_Channel4, DISABLE);   
            DMA_Cmd(DMA1_Channel1, DISABLE);   
#ifdef slave2   
            /* Calculate the Temperature values */   
            for (j=0; j<BufferSize; j++)   
            {   
                temp1 =   Buffer[j];   
                temp1 = ( temp1 * 3300 ) / 0x1000;  /* Finds mV */   
                temp1 = ((((1430-temp1)*100000)/430)+25000)/1000;   
                Slave_Buffer_Tx[j] = temp1;   
            }   
   
#endif   
            DMA1_Channel4->CNDTR = 255;   
            DMA1_Channel1->CNDTR = BufferSize;   
            I2C_DMACmd(I2C2, ENABLE);   
            DMA_Cmd(DMA1_Channel4, ENABLE);   
            /* clear ADDR by reading SR2 */   
            temp = I2C2->SR2 ;   
        }   
   
   
    }   
   
    if (I2C_GetFlagStatus(I2C2, I2C_FLAG_STOPF))   
    {   
        I2C_Cmd(I2C2, ENABLE);   
    }   
   
#endif   
   
}   
   
/**  
  * @}  
  */    
   
/**  
  * @}  
  */    
/**  
  * @brief  This function handles I2C2 Error interrupt request.  
  * @param  None  
  * @retval : None  
  */   
void I2C2_ER_IRQHandler(void)   
   
{   
   
    if (I2C_GetFlagStatus(I2C2, I2C_FLAG_AF))   
    {   
        I2C_ClearFlag(I2C2, I2C_FLAG_AF);   
    }   
   
    if (I2C_GetFlagStatus(I2C2, I2C_FLAG_BERR))   
    {   
        I2C_ClearFlag(I2C2, I2C_FLAG_BERR);   
   
    }   
    if (I2C_GetFlagStatus(I2C2, I2C_FLAG_OVR))   
    {   
        I2C_ClearFlag(I2C2, I2C_FLAG_OVR);   
   
    }   
   
    if (I2C_GetFlagStatus(I2C2, I2C_FLAG_ARLO))   
    {   
        I2C_ClearFlag(I2C2,I2C_FLAG_ARLO);   
   
    }   
   
   
   
   
}   
   
   
   
   
/**  
  * @}  
  */    
   
   
/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/ 
