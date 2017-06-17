
/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

void main(void)
{
  GPIO_DeInit(GPIOB);        //DeInitialize GPIO
  /*
    Init GPIO Pin 5 of PORTB with push-pull,Low logic,10MHz
  */
  GPIO_Init(GPIOB,GPIO_PIN_5,GPIO_MODE_OUT_PP_LOW_FAST);
  /* Infinite loop */
  while (1)
  {
    /*
      OUTPUT Reverse state of GPIOB Pin5
    */
    GPIO_WriteReverse(GPIOB,GPIO_PIN_5);
    //Delay
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
