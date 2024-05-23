#include <REGX52.H>

#include "../../Lib/delay.h"

#define LED_PORT P2

void mode_led_1();
void mode_led_2();
void mode_led_3();

int main()
{		
		delay_ms(1000);
		LED_PORT = 0x00;
		delay_ms(1000);
		while(1)
		{
			mode_led_3();
		}
}
//che do sang thu nhat
void mode_led_1()
{
	LED_PORT = ~LED_PORT;
	delay_ms(500);
}

// che do sang thu hai
void mode_led_2()
{
	int i;
	for(i = 0; i < 8; i++)
	{
		LED_PORT = LED_PORT | 1 << i;
		delay_ms(500);
	}
	for(i = 0; i < 8; i++)
	{
		LED_PORT = LED_PORT ^ (0x80 >> i);
		delay_ms(500);
	}
}
//che do sang thu ba
void mode_led_3()
{
	int i;
	for(i = 0; i < 8; i++)
	{
		LED_PORT = 0x01 << i;
		delay_ms(500);
	}
	for(i = 0; i < 8; i++)
	{
		LED_PORT = 0x80 >> i;
		delay_ms(500);
	}
	
}
