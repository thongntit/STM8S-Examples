
#include "stm8s.h"

uint16_t CCR1_Val=300;

static void TIM2_PWMConfig(void)
{
  /* Time base configuration */
  TIM2_TimeBaseInit(TIM2_PRESCALER_1, 999);

  /* PWM1 Mode configuration: Channel1 */ 
  TIM2_OC1Init(TIM2_OCMODE_PWM1, TIM2_OUTPUTSTATE_ENABLE,CCR1_Val, TIM2_OCPOLARITY_HIGH);
  TIM2_OC1PreloadConfig(ENABLE);
  
  TIM2_ARRPreloadConfig(ENABLE);

  /* TIM2 enable counter */
  TIM2_Cmd(ENABLE);
}

void main(void)
{
  TIM2_PWMConfig();
  while (1)
  {
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