#include "stm8s.h"

static void SoftwarePriority(void)
{
  /*
  Interrupt with higher priority level will execute first.
  */
  ITC_SetSoftwarePriority(ITC_IRQ_PORTD, ITC_PRIORITYLEVEL_2); 
  ITC_SetSoftwarePriority(ITC_IRQ_PORTA, ITC_PRIORITYLEVEL_1); 
}

void main(void)
{
  /*Clock Config */
  CLK_DeInit();
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
  while(CLK_GetFlagStatus(CLK_FLAG_HSIRDY)!=SET);
  /* GPIO Config*/
  GPIO_Init(GPIOB,GPIO_PIN_5,GPIO_MODE_OUT_PP_LOW_FAST); //Led Pin
  GPIO_Init(GPIOC,GPIO_PIN_3,GPIO_MODE_OUT_PP_LOW_FAST); // Output mode for GPIOC Pin3
  GPIO_Init(GPIOD,GPIO_PIN_3,GPIO_MODE_IN_PU_IT); // Input mode with EXTI for GPIOD Pin3
  GPIO_Init(GPIOA,GPIO_PIN_3,GPIO_MODE_IN_PU_IT); // Input mode with EXTI for GPIOD Pin3
  /* External Interrupt Config */
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_FALL_ONLY);
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOA, EXTI_SENSITIVITY_FALL_ONLY);
  SoftwarePriority(); // ITC 
  enableInterrupts();
  while (1)
  {
    GPIO_WriteReverse(GPIOC,GPIO_PIN_3);
    for(u32 i=0; i<0xFFFF;i++)
    {}
  }
  
}


#ifdef USE_FULL_ASSERT

void assert_failed(u8* file, u32 line)
{ 
  while (1)
  {
  }
}
#endif