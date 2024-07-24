#include <REGX52.H>
#include "../../Lib/delay.h"
unsigned char i = 0;
void main()
{
	P2 = 0;
	while(1)
	{
		for(i = 0; i < 256; i++)
		{
			P2 = i;
			delay_ms(8);
		}
		for(i = 255; i >= 0; i--)
		{
			P2 = i;
			delay_ms(8);
		}
	}
}
