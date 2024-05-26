//BAI6: lam voi cac loai led khac nhau: mpx2, mpx4, mpx6, mpx8 voi tung loai chan chung khac nhau: CA, CC
#include <REGX52.H>
#include "../../Lib/delay.h"
//test1: led mpx2 cc: dem tu 00 - 99
//test2: led mpx6 ca: dong ho dem
//chung anot
unsigned char code_led_ca[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

//chung cathot
unsigned char code_led[] = {0x3F, 0x06, 0x5B, 0xCF, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

#define LED_PORT P2
sbit led_hour1 = P3^0;
sbit led_hour2 = P3^1;
sbit led_min1 = P3^2;
sbit led_min2 = P3^3;
sbit led_sec1 = P3^4;
sbit led_sec2 = P3^5;

void main()
{
	unsigned char i, chuc, dvi, hours, minutes, seconds;
	hours = minutes = seconds = 0;
	while(1)
	{
		for(i = 0; i < 167; i++)
		{
			//hien thi gio
			chuc = hours /10;
			LED_PORT = code_led_ca[chuc];
			led_hour1 = 0;
			delay_ms(1);
			led_hour1 = 1;
			
			dvi = hours % 10;
			LED_PORT = code_led_ca[dvi];
			led_hour2 = 0;
			delay_ms(1);
			led_hour2 = 1;
			
			//hien thi phut
			chuc = minutes /10;
			LED_PORT = code_led_ca[chuc];
			led_min1 = 0;
			delay_ms(1);
			led_min1 = 1;
			
			dvi = minutes % 10;
			LED_PORT = code_led_ca[dvi];
			led_min2 = 0;
			delay_ms(1);
			led_min2 = 1;
			
			// hien thi giay
			chuc = seconds /10;
			LED_PORT = code_led_ca[chuc];
			led_sec1 = 0;
			delay_ms(1);
			led_sec1 = 1;
			
			dvi = seconds % 10;
			LED_PORT = code_led_ca[dvi];
			led_sec2 = 0;
			delay_ms(1);
			led_sec2 = 1;
		}
		//tang giay
		seconds++;
		if(seconds == 60)
		{
			minutes ++;
			seconds = 0;
			if(minutes == 60)
			{
				minutes = 0;
				hours ++;
				if(hours == 24)
				{
					hours = minutes = seconds = 0;
				}
			}
		}
	}
}
