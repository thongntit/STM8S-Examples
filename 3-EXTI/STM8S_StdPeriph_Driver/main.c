/*
    In this example. I use GPIOC Pin 3 to generate clock pulse.
    GPIOD Pin 3 will capture that pulse and Reverse a Led.
Todo: connect PC3 to PD3

*/
/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

void main(void)
{
  /*Clock Config */
  CLK_DeInit();
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
  while(CLK_GetFlagStatus(CLK_FLAG_HSIRDY)!=SET);
  /* GPIO Config*/
  GPIO_Init(GPIOB,GPIO_PIN_5,GPIO_MODE_OUT_PP_LOW_FAST); //Led Pin
  GPIO_Init(GPIOC,GPIO_PIN_3,GPIO_MODE_OUT_PP_LOW_FAST); // Output mode for GPIOC Pin3
  GPIO_Init(GPIOD,GPIO_PIN_3,GPIO_MODE_IN_FL_IT); // Input mode with EXTI for GPIOD Pin3
  /* External Interrupt Config */
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_FALL_ONLY);
  EXTI_SetTLISensitivity(EXTI_TLISENSITIVITY_FALL_ONLY);
  enableInterrupts();
  /* Infinite loop */
  while (1)
  {
    /* Generate pulses */
    GPIO_WriteReverse(GPIOC,GPIO_PIN_3);
    for(u32 i=0; i<0xFFFF;i++)
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