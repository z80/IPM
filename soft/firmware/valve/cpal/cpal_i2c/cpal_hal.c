
#define STM32F10X_MD
#define USE_STDPERIPH_DRIVER
#include "stm32f10x_n.h"

#include "misc.h"
#include "cpal.h"

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/


/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Configure NVIC Priority Group.
  * @param  None.
  * @retval None. 
  */
void CPAL_HAL_NVICInit(void)
{
 /* Set NVIC Group Priority */
  NVIC_PriorityGroupConfig (CPAL_NVIC_PRIOGROUP);
}


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/


