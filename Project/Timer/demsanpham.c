#include <REGX52.H>
#include "../../Lib/delay.h"
unsigned char code_led_ca[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

#define LED_PORT P0
sbit LED1 = P2^0;
sbit LED2 = P2^1;
sbit LED3 = P2^2;
sbit LED4 = P2^3;
sbit LED5 = P2^4;

void display(unsigned int number)
{
	unsigned char chucnghin, nghin, tram, chuc, donvi;
	
	chucnghin = number / 10000;
	nghin = (number / 1000) % 10;
	tram = (number / 100) % 10;
	chuc = (number / 10) % 10;
	donvi = number % 10;
	
	LED_PORT = code_led_ca[donvi];
	LED1 = 0;
	delay_ms(1);
	LED1 = 1;
	
	LED_PORT = code_led_ca[chuc];
	LED2 = 0;
	delay_ms(1);
	LED2 = 1;
	
	LED_PORT = code_led_ca[tram];
	LED3 = 0;
	delay_ms(1);
	LED3 = 1;
	
	LED_PORT = code_led_ca[nghin];
	LED4 = 0;
	delay_ms(1);
	LED4 = 1;
	
	LED_PORT = code_led_ca[chucnghin];
	LED5 = 0;
	delay_ms(1);
	LED5 = 1;
}

void main()
{	
	//setup che do
	unsigned char high, low;
	unsigned int number;
	TMOD &= 0xF0;
	TMOD |= 0x05;
	
	//bat dau dem
	TR0 = 1;
	while(1)
	{
		do{
			high = TH0;
			low = TL0;
		}while(high != TH0);
		
		number = high;
		number <<= 8;
		number |= low;
		display(number);
	}
}
