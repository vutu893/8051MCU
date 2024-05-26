//IC75HC573 la IC chot 
//chan LE muc 1 thì ngõ vào giong ngo ra, muc 0 thi chot lai du lieu 
//chan OE o muc thap de xuat du lieu
//cac chan du lieu D0-D7 co the mach song song giua nhieu IC
//ton nhieu chan hon nhung toc do cao hon
#include <REGX52.H>
#include "../../Lib/delay.h"

unsigned char led7seq[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
#define LED_PORT P0
sbit led1 = P2^0;
sbit led2 = P2^1;
void main()
{	
	unsigned char i;
	led1 = led2 = 0;
	while(1)
	{
		for(i = 0; i < 100; i++)
		{
			LED_PORT = led7seq[i/10];
			led1 = 1;
			led1 = 0;
			
			LED_PORT = led7seq[i % 10];
			led2 = 1;
			led2 = 0;
			delay_ms(500);
		}
	}
}