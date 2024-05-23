#include <REGX52.H>
#include "../../Lib/delay.h"

sbit START_BTN = P1^0;
sbit STOP_BTN = P1^1;

#define LED_PORT P2


unsigned char delay1000msvaQuetphim()
{
	unsigned char i;
	for(i = 0; i < 10; i++)
	{
		delay_ms(100);
		
		if(STOP_BTN == 0)
		{
			LED_PORT = 0x00;
			return 1;
		}
	}
	return 0;
}
void main()
{
	
	LED_PORT = 0x00;
	
	while(1)
	{
		if(START_BTN == 0)
		{
			while(1)
			{
				LED_PORT = ~LED_PORT;
				if(delay1000msvaQuetphim())
				{
					break;
				}
			}
		}
	}
}

