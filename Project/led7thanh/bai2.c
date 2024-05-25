#include <REGX52.H>
#include "../../Lib/delay.h"

//bai2: lam den dieu khien giao thong bang led 7 doan dem trong 19s
#define LED7SEQ1 P2
#define LED7SEQ2 P3
//led giao thong
sbit LED_RED = P0^0;
sbit LED_YELLOW = P0^1;
sbit LED_GREEN = P0^2;
//chung anot
unsigned char code_led[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0x8F, 0x80, 0x90};

void led_red_on();
void led_green_on();
void led_yellow_on();

void main()
{	
	unsigned char count = 0;
	LED_RED = 0;
	LED_GREEN = 0;
	LED_YELLOW = 0;
	while(1)
	{
		unsigned char i,j;
		led_red_on();
		
		for(i = 0; i < 2; i++)
		{
			LED7SEQ1 = code_led[i];
			for(j = 0; j < 10; j++)
			{
				LED7SEQ2 = code_led[j];
				count++;
				delay_ms(500);
				if(count == 15)
				{
					led_yellow_on();
				}
			}
		}
		
		led_green_on();
		
		for(i = 0; i < 2; i++)
		{
			LED7SEQ1 = code_led[i];
			for(j = 0; j < 10; j++)
			{
				LED7SEQ2 = code_led[j];
				count++;
				delay_ms(500);
			}
		}
	}
	
}
void led_red_on()
{
	LED_RED = 1;
	LED_GREEN = 0;
	LED_YELLOW = 0;
}

void led_green_on()
{
	LED_RED = 0;
	LED_YELLOW = 0;
	LED_GREEN = 1;
}

void led_yellow_on()
{
	LED_RED = 0;
	LED_GREEN = 0;
	LED_YELLOW = 1;
}

