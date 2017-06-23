
/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
u32 clock;
void CLKHSIConfig()
  {
  CLK_DeInit();
  /* Set the Prescale as division 1. So HSI clock is 16MHz/1=16Mhz */
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
  /* Wait for the HSI Clock is stable */
  while(CLK_GetFlagStatus(CLK_FLAG_HSIRDY)!=SET);
  clock=CLK_GetClockFreq();// Set a breakpoint here to monitor the clock value
  }
void CLKLSIConfig() //enable LSI_EN in option byte to use this function.
  {
  CLK_DeInit();
  CLK_LSICmd(ENABLE);
  CLK_ClockSwitchConfig(CLK_SWITCHMODE_MANUAL,CLK_SOURCE_LSI,DISABLE,CLK_CURRENTCLOCKSTATE_DISABLE);
  while(CLK_GetFlagStatus(CLK_FLAG_LSIRDY)!=SET);
  clock=CLK_GetClockFreq();// Set a breakpoint here to monitor the clock value
  }
  
void main(void)
{
  CLKLSIConfig();
  /* GPIO Config*/
  GPIO_DeInit(GPIOB);
  GPIO_Init(GPIOB,GPIO_PIN_5,GPIO_MODE_OUT_PP_LOW_FAST);
  
  
  /* Infinite loop */
  while (1)
  {
    GPIO_WriteReverse(GPIOB,GPIO_PIN_5);
    for(u16 i=0;i<0xFFFF;i++)
    {}
  }
  
}


#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif