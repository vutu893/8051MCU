//bai5: dong ho dem 
#include <REGX52.H>
#include "../../Lib/delay.h"


#define LED_PORT P2

sbit led_hour1 = P3^0;
sbit led_hour2 = P3^1;
sbit led_min1 = P3^2;
sbit led_min2 = P3^3;
sbit led_sec1 = P3^4;
sbit led_sec2 = P3^5;

unsigned char code led_code[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
void main()
{	
	unsigned int i;
	unsigned char hours = 0;
	unsigned char seconds = 0;
	unsigned char minutes = 0;
	unsigned char chuc, dvi;
	while(1)
	{
			for(i = 0; i < 167; i++)
			{
					//hien thi gio
				chuc = hours / 10;
				dvi = hours % 10;
				LED_PORT = led_code[chuc];
				led_hour1 = 0;
				delay_ms(1);
				led_hour1 = 1;
				
				LED_PORT = led_code[dvi];
				led_hour2 = 0;
				delay_ms(1);
				led_hour2 = 1;
				
				//hien thi phut
				chuc = minutes / 10;
				dvi = minutes % 10;
				LED_PORT = led_code[chuc];
				led_min1 = 0;
				delay_ms(1);
				led_min1 = 1;
				
				LED_PORT = led_code[dvi];
				led_min2 = 0;
				delay_ms(1);
				led_min2 = 1;
				
				//hien thi giay
				chuc = seconds / 10;
				dvi = seconds % 10;
				LED_PORT = led_code[chuc];
				led_sec1 = 0;
				delay_ms(1);
				led_sec1 = 1;
				
				LED_PORT = led_code[dvi];
				led_sec2 = 0;
				delay_ms(1);
				led_sec2 = 1;
			}
			//tang giay, phut va gio
			seconds++;
			if(seconds = 60)
			{
				minutes ++;
				seconds = 0;
				if(minutes == 60)
				{
					hours ++;
					minutes = 0;
					if(hours = 20)
					{
						seconds = 0;
						minutes = 0;
						hours = 0;
					}
				}
			}
	}
	
}
