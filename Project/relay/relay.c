#include <REGX52.H>
#include "../../Lib/delay.h"

sbit BTN = P1^0;

sbit RELAY = P2^0;
int main()
{	
	RELAY = 0;
	while(1)
	{
		if(BTN == 0)
		{
			delay_ms(20);
			if(BTN == 0)
			{
				RELAY = !RELAY;
				while(BTN == 0);
			}
		}
	}
}
