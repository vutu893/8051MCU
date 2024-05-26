#include <REGX52.H>
#include  "../../Lib/delay.h"
#include "../../Lib/IC74595.h"

unsigned char led7seq[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
void main()
{
	unsigned char i,j;
	unsigned char buffer[2];
	while(1)
	{	
		for(j = 0; j < 2; j++)
		{
			buffer[j] = led7seq[i];
		}
		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 2; j++)
			{
				buffer[j] = led7seq[i];
			}
			IC74595_out(buffer, 9);
			delay_ms(1000);
		}
		
	}
}
