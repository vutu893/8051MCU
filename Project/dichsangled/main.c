#include <REGX52.H>

#include "../../Lib/delay.h"

#define LED_PORT P2

void mode_led_1();
void mode_led_2();
void mode_led_3();
void mode_led_4();

int main()
{		
		delay_ms(1000);
		LED_PORT = 0x00;
		delay_ms(1000);
		while(1)
		{
			mode_led_4();
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

//che do sang thu tu
void mode_led_4()
{
	unsigned char i,j;
	delay_ms(200);
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8 - i;j++)
		{
			LED_PORT = LED_PORT|1 << j;
			delay_ms(250);
		}
		//temp = 0x01;
		LED_PORT = LED_PORT^(LED_PORT >> (i+1));
		delay_ms(250);
	}
	LED_PORT = ~LED_PORT;
	delay_ms(300);
} 

//che do sang thu 5

