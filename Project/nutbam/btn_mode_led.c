#include <REGX52.H>
#include "../../Lib/delay.h"

sbit BTN_PIN = P1^0;

#define LED_PORT P2

bit pressedFlag = 0;

unsigned char delay500msvaQuetphim()
{
	unsigned char i;
	for(i = 0; i < 50; i++)
	{
		delay_ms(10);
		if(BTN_PIN == 0)
		{
			if(pressedFlag == 0)
			{
				pressedFlag == 1;
				return 1;
			}
		}else 
		{
			pressedFlag == 0;
		}
	}
	return 0;
}
void main()
{	
	unsigned char i;
	while(1)
	{
		LED_PORT = 0x00;
		//che do led thu nhat
		while(1)
		{
			if(delay500msvaQuetphim()) break;
			LED_PORT = ~LED_PORT;
		}
		//che do led thu hai
		while(1)
		{
			LED_PORT = 0xAA;
			if(delay500msvaQuetphim()) break;
			LED_PORT = ~ LED_PORT;
		}
		//che do led thu ba
		while(1)
		{	
			LED_PORT = 0x00;
			for(i = 0; i < 8; i++)
			{	
				LED_PORT = LED_PORT | 1 << i;
			}
			if(delay500msvaQuetphim()) break;
			for(i = 0;i < 8; i++)
			{
				LED_PORT = LED_PORT | 1 >> i;
			}
		}
	}
}


