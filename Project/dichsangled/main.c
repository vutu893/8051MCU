#include <REGX52.H>

#include "../../Lib/delay.h"

#define LED_PORT P2
void mode_led_1();
int main()
{		
		LED_PORT = 0x00;
		while(1)
		{
			mode_led_1();
		}
}
void mode_led_1()
{
	LED_PORT = ~LED_PORT;
	delay_ms(500);
}
