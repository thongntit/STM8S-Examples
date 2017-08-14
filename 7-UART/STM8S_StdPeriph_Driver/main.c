
#include "stm8s.h"
#include "string.h"

uint16_t po;
uint8_t pi;
INTERRUPT_HANDLER(UART1_RX_IRQHandler, 18)
{
	char ch;
	ch=UART1_ReceiveData8();
	if(ch=='A' || ch =='B' || ch =='C' || ch =='D'  )
	{
		switch(ch){
		case 'A':
			{
				po=0x5000;
				pi=0;
				break;
			}
		case 'B':
			{
				po=0x5005;
				pi=0;
				break;
			}
		case 'C':
			{
				po=0x500A;
				pi=0;
				break;
			}
		case 'D':
			{
				po=0x500F;
				pi=0;
				break;
			}
			
		}
	}
	if(ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='5' || ch=='6' || ch=='7')
	{
		switch (ch)
		{
		case '0':
			{
				pi=0x01;
				break;
			}
		case '1':
			{
				pi=0x02;
				break;
			}
		case '2':
			{
				pi=0x04;
				break;
			}
		case '3':
			{
				pi=0x08;
				break;
			}
		case '4':
			{
				pi=0x10;
				break;
			}
		case '5':
			{
				pi=0x20;
				break;
			}
		case '6':
			{
				pi=0x40;
				break;
			}
		case '7':
			{
				pi=0x80;
				break;
			}
		}
	}
	if(ch=='b' || ch=='t')
	{
		switch(ch)
		{
		case 'b':
			{
				GPIO_Init((GPIO_TypeDef *)po,pi,GPIO_MODE_OUT_PP_HIGH_FAST);
				GPIO_WriteLow((GPIO_TypeDef *)po,pi);
				break;
			}
		case 't':
			{
				GPIO_Init((GPIO_TypeDef *)po,pi,GPIO_MODE_OUT_PP_HIGH_FAST);
				GPIO_WriteHigh((GPIO_TypeDef *)po,pi);
				break;
			}
		}
	}


}
void main(void)
{
	//  GPIO_Init(GPIOB,GPIO_PIN_5,GPIO_MODE_OUT_PP_HIGH_FAST);
	UART1_Init((uint32_t)9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
	UART1_ITConfig(UART1_IT_RXNE_OR , ENABLE);
	UART1_Cmd(ENABLE);
	enableInterrupts();
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