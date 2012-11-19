
/**  
  ******************************************************************************  
  * @file DMAUseExample/src/main.c   
  * @author   MCD Application Team  
  * @version  V3.0.0  
  * @date     04/27/2009  
  * @brief    Main program body  
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
#include "main.h"   
   
   
/** @addtogroup DMAUseExample  
  * @{  
  */    
   
   
/* Private typedef -----------------------------------------------------------*/   
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;   
   
/* Private define ------------------------------------------------------------*/   
#define ADC1_DR_Address    ((uint32_t)0x4001244C)   
/* Private macro -------------------------------------------------------------*/   
/* Private variables ---------------------------------------------------------*/   
I2C_InitTypeDef  I2C_InitStructure;   
uint8_t Master_Buffer_Rx[BufferSize];   
uint8_t Slave_Buffer_Tx[255];   
uint16_t Buffer[BufferSize];   
ErrorStatus HSEStartUpStatus;   
/* Private function prototypes -----------------------------------------------*/   
void RCC_Configuration(void);   
void GPIO_Configuration(void);   
void NVIC_Configuration(void);   
void Master_Configuration(void);   
void Slave_Configuration(void);   
void TIM2_Configuration(void);   
void ADC1_Configuration(void);   
void DMA_Channel1_Configuration(void);   
   
/* Private functions ---------------------------------------------------------*/   
   
   
/**  
  * @brief  Main program  
  * @param   None.  
  * @retval : None.  
  */   
int main(void)   
{   
    /* System clocks configuration */   
    RCC_Configuration();   
    /* NVIC configuration*/   
    NVIC_Configuration();   
    /* GPIO configuration ----------------------------------------------------*/   
    GPIO_Configuration();   
#ifdef master   
    /* Master configuration --------------------------------------------------*/   
    Master_Configuration();   
#endif   
#if defined(slave1) || defined(slave2)   
    /* Slave configuration ---------------------------------------------------*/   
    Slave_Configuration();   
   
    /* ADC1 configuration ----------------------------------------------------*/   
    ADC1_Configuration();   
   
    /* ADC DMA Channel1 configuration */   
    DMA_Channel1_Configuration();   
#endif   
   
#ifdef  DMA_Master_Receive   
    DMA_Channel7_Configuration();   
#endif   
   
#ifdef  DMA_Slave_Transmit   
    DMA_Channel4_Configuration();   
#endif   
   
#ifdef  master   
    /* TIM2 configuration ----------------------------------------------------*/   
    TIM2_Configuration();   
#endif   
   
    while (1)   
    {   
#if defined(slave1) || defined(slave2)   
        I2C_Slave_BufferWrite(Slave_Buffer_Tx,  255);   
#endif   
    }   
   
}   
   
   
/**  
  * @brief  Configures the different system clocks.  
  * @param  None  
  * @retval : None  
  */   
void RCC_Configuration(void)   
{   
    /* RCC system reset(for debug purpose) */   
    RCC_DeInit();   
   
    /* Enable HSE */   
    RCC_HSEConfig(RCC_HSE_ON);   
   
    /* Wait till HSE is ready */   
    HSEStartUpStatus = RCC_WaitForHSEStartUp();   
   
    if (HSEStartUpStatus == SUCCESS)   
    {   
        /* Enable Prefetch Buffer */   
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);   
   
        /* Flash 2 wait state */   
        FLASH_SetLatency(FLASH_Latency_2);   
   
        /* HCLK = SYSCLK */   
        RCC_HCLKConfig(RCC_SYSCLK_Div1);   
   
        /* PCLK2 = HCLK */   
        RCC_PCLK2Config(RCC_HCLK_Div1);   
   
        /* PCLK1 = HCLK/2 */   
        RCC_PCLK1Config(RCC_HCLK_Div2);   
   
        /* PLLCLK = 8MHz * 7 = 56 MHz */   
        RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_7);   
   
        /* ADC Clock Config */   
        RCC_ADCCLKConfig(RCC_PCLK2_Div4);   
   
        /* Enable PLL */   
        RCC_PLLCmd(ENABLE);   
   
        /* Wait till PLL is ready */   
        while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)   
        {   
        }   
   
        /* Select PLL as system clock source */   
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);   
   
        /* Wait till PLL is used as system clock source */   
        while (RCC_GetSYSCLKSource() != 0x08)   
        {   
        }   
    }   
   
    /* Enable peripherals clocks ---------------------------------------------*/   
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);   
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);   
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);   
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);   
   
}   
   
   
   
/**  
  * @brief  Configures the different GPIO ports.  
  * @param  None  
  * @retval : None  
  */   
void GPIO_Configuration(void)   
{   
    GPIO_InitTypeDef GPIO_InitStructure;   
   
#ifdef master   
    /* Configure I2C1 pins: SCL and SDA --------------------------------------*/   
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;   
    GPIO_Init(GPIOB, &GPIO_InitStructure);   
#endif   
   
#if defined(slave1) || defined(slave2)   
    /* Configure I2C2 pins: SCL and SDA --------------------------------------*/   
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10 | GPIO_Pin_11;   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;   
    GPIO_Init(GPIOB, &GPIO_InitStructure);   
#endif   
   
#ifdef slave1   
    /* Configure PC.04 (ADC Channel14) as analog input -----------------------*/   
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;   
    GPIO_Init(GPIOC, &GPIO_InitStructure);   
#endif   
   
#ifdef slave2   
    /* Configure PC.06 (ADC Channel16) as analog input -----------------------*/   
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;   
    GPIO_Init(GPIOC, &GPIO_InitStructure);   
#endif   
   
   
}   
   
   
   
/**  
  * @brief  Configures I2C1  
  * @param  None  
  * @retval : None  
  */   
void Master_Configuration(void)   
{   
    I2C_DeInit(I2C1);   
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;   
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;   
    I2C_InitStructure.I2C_OwnAddress1 = 0x30;   
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;   
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;   
    I2C_InitStructure.I2C_ClockSpeed = ClockSpeed;   
    I2C_Init(I2C1, &I2C_InitStructure);   
    I2C_ITConfig(I2C1, I2C_IT_ERR , ENABLE);   
   
}   
   
   
   
   
/**  
  * @brief  Configures I2C2.  
  * @param  None  
  * @retval : None  
  */   
void Slave_Configuration(void)   
{   
   
    I2C_DeInit(I2C2);   
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;   
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;   
    I2C_InitStructure.I2C_OwnAddress1 = SLAVE_ADDRESS;   
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;   
    I2C_InitStructure.I2C_ClockSpeed = ClockSpeed;   
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;   
    I2C_Init(I2C2, &I2C_InitStructure);   
    I2C_ITConfig(I2C2, I2C_IT_ERR, ENABLE);   
}   
   
   
   
/**  
  * @brief  Configures the Timer2 settings.  
  * @param  None  
  * @retval : None  
  */   
void TIM2_Configuration(void)   
{   
   
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   
   
    TIM_TimeBaseStructure.TIM_Period = 56000;   
    TIM_TimeBaseStructure.TIM_Prescaler = 0;   
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;   
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;   
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;   
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);   
    /* Prescaler configuration */   
    TIM_PrescalerConfig(TIM2, 2 , TIM_PSCReloadMode_Immediate);   
    /* TIM IT enable */   
    TIM_ITConfig(TIM2,TIM_IT_Update , ENABLE);   
    /* TIM2 enable counter */   
    TIM_Cmd(TIM2, ENABLE);   
}   
   
   
   
   
/**  
  * @brief  Configures NVIC and Vector Table base location.  
  * @param  None  
  * @retval : None  
  */   
void NVIC_Configuration(void)   
{   
   
    /* 1 bit for pre-emption priority, 3 bits for subpriority */   
    NVIC_SetPriorityGrouping(6);    
#ifdef master   
   
    NVIC_SetPriority(I2C1_EV_IRQn, 0x00); /* 0x01 = 0x0 << 3 | (0x0 & 0x7*/   
    NVIC_EnableIRQ(I2C1_EV_IRQn);   
   
   
    NVIC_SetPriority(DMA1_Channel7_IRQn, 0x01); /* 0x01 = 0x0 << 3 | (0x1 & 0x7*/   
    NVIC_EnableIRQ(DMA1_Channel7_IRQn);   
   
   
   
    NVIC_SetPriority(I2C1_ER_IRQn, 0x01); /* 0x01 = 0x0 << 3 | (0x1 & 0x7*/   
    NVIC_EnableIRQ(I2C1_ER_IRQn);   
   
   
    /* Enable the TIM2 global Interrupt */   
    NVIC_SetPriority(TIM2_IRQn, 0x10); /* 0x10 = 0x2 << 3 | (0x0 & 0x7*/   
    NVIC_EnableIRQ(TIM2_IRQn);   
#endif   
   
#if defined(slave1) || defined(slave2)   
   
    NVIC_SetPriority(I2C2_EV_IRQn, 0x00); /* 0x01 = 0x0 << 3 | (0x0 & 0x7*/   
    NVIC_EnableIRQ(I2C2_EV_IRQn);   
   
   
   
      NVIC_SetPriority(I2C2_ER_IRQn, 0x01); /* 0x01 = 0x0 << 3 | (0x1 & 0x7*/   
    NVIC_EnableIRQ(I2C2_ER_IRQn);   
   
#endif   
   
}   
   
   
   
   
/**  
  * @brief  Configures DMA1 channel1  
  * @param  None  
  * @retval : None  
  */   
void DMA_Channel1_Configuration(void)   
{   
   
    DMA_InitTypeDef DMA_InitStructure;   
   
    DMA_DeInit(DMA1_Channel1);   
    DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;   
#ifdef slave1   
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)Slave_Buffer_Tx;   
#endif   
#ifdef slave2   
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)Buffer;   
#endif   
   
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;   
    DMA_InitStructure.DMA_BufferSize = BufferSize;   
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;   
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;   
#ifdef slave1   
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;   
    DMA_InitStructure.DMA_MemoryDataSize =  DMA_MemoryDataSize_Byte;   
#endif   
   
#ifdef slave2   
    DMA_InitStructure.DMA_PeripheralDataSize =  DMA_PeripheralDataSize_HalfWord;   
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;   
#endif   
    DMA_InitStructure.DMA_Mode =  DMA_Mode_Normal;   
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;   
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;   
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);   
   
}   
   
   
/**  
  * @brief   
  * @param  None  
  * @retval : None  
  */   
void ADC1_Configuration(void)   
{   
    ADC_InitTypeDef ADC_InitStructure;   
   
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;   
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;   
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;   
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;   
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;   
    ADC_InitStructure.ADC_NbrOfChannel = 1;   
    ADC_Init(ADC1, &ADC_InitStructure);   
#ifdef slave1   
    /* ADC1 regular channel15 configuration*/   
    ADC_RegularChannelConfig(ADC1, ADC_Channel_14, 1, ADC_SampleTime_55Cycles5);   
#endif   
   
#ifdef slave2   
    ADC_RegularChannelConfig(ADC1, ADC_Channel_16, 1, ADC_SampleTime_239Cycles5);   
    ADC_TempSensorVrefintCmd(ENABLE);   
#endif   
    /* Enable ADC1 DMA */   
    ADC_DMACmd(ADC1, ENABLE);   
   
    /* Enable ADC1 */   
    ADC_Cmd(ADC1, ENABLE);   
   
    /* Enable ADC1 reset calibaration register */   
    ADC_ResetCalibration(ADC1);   
    /* Check the end of ADC1 reset calibration register */   
    while (ADC_GetResetCalibrationStatus(ADC1));   
   
    /* Start ADC1 calibaration */   
    ADC_StartCalibration(ADC1);   
    /* Check the end of ADC1 calibration */   
    while (ADC_GetCalibrationStatus(ADC1));   
}   
   
#ifdef  USE_FULL_ASSERT   
   
   
/**  
  * @brief  Reports the name of the source file and the source line number  
  * where the assert_param error has occurred.  
  * @param file: pointer to the source file name  
  * @param line: assert_param error line source number  
  * @retval : None  
  */   
void assert_failed(uint8_t* file, uint32_t line)   
{   
    /* User can add his own implementation to report the file name and line number,  
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */   
   
    /* Infinite loop */   
    while (1)   
    {   
    }   
}   
#endif   
/**  
  * @}  
  */    
   
   
   
/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/  
