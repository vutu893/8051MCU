#include <REGX52.H>
#include "../../Lib/delay.h"

#define LED7SEQ  P2

//CHUNG ANOT
unsigned char led7seq[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0x8F, 0x80, 0x90};
void bai1();
	
void main()
{
	while(1)
	{
		bai1();
	}
}

//bai 1: sang den tu 0 den 9 roi quay lai
void bai1()
{
	unsigned char i;
	for(i = 0; i < 10; i++)
	{
		LED7SEQ = led7seq[i];
		delay_ms(1000);
	}
}