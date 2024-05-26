//bai2: ghep noi nhieu IC
#include <REGX52.H>
#include "../../Lib/delay.h"
#include "../../Lib/IC74595.h"

void main()
{
	unsigned char buffer[2];
	unsigned char i;
	while(1)
	{
		for(i = 0; i < 2; i++)
		{
			buffer[i] = 0;
		}
		IC74595_out(buffer, 2);
		delay_ms(250);
		
		for(i = 0; i < 2; i++)
		{
			buffer[i] = 0xFF;
		}
		IC74595_out(buffer, 2);
		delay_ms(200);
	}
}