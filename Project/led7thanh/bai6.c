//BAI6: lam voi cac loai led khac nhau: mpx2, mpx4, mpx6, mpx8 voi tung loai chan chung khac nhau: CA, CC
#include <REGX52.H>
#include "../../Lib/delay.h"
//test1: led mpx2 cc: dem tu 00 - 99
//chung anot
unsigned char code_led_ca[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0x8F, 0x80, 0x90};

//chung cathot
unsigned char code_led[] = {0x3F, 0x06, 0x5B, 0xCF, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

#define LED_PORT P2
sbit led1 = P3^0;
sbit led2 = P3^1;

void main()
{
	unsigned char  chuc, dvi, dem;
	unsigned int i;
	while(1)
	{
		for(dem = 0; dem < 100; dem++)
		{
			for(i = 0; i < 500; i++)
			{
				//sang led hang chuc
				chuc = dem /10;
				LED_PORT = code_led[chuc];
				led1 = 0;
				delay_ms(1);
				led1 = 1;
				
				//sang led hanh don vi
				dvi = dem % 10;
				LED_PORT = code_led[dvi];
				led2 = 0;
				delay_ms(1);
				led2 = 1;
			}
		}
	}
}
